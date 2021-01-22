#!/bin/bash

# This script is to be run on the KVM host, inside the container

set -ex

export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
export PYTHONPATH=/usr/local/lib/python3.7/site-packages

benchmark_loops=0
perfetto_loops=10
wait_after_frame=

debug=no
trace=
command=""
prep_snapshot=
while [ -n "$1" ] ; do
    case "$1" in

        --trace|-t)
          trace="$2"
          shift
          ;;

        --benchmark|-b)
          command="$command benchmark=$2"
          benchmark_loops=$2
          shift
          ;;

        --perfetto|-p)
          command="$command perfetto=$2"
          perfetto_loops=$2
          shift
          ;;

  	--wait-after-frame|-w)
          command="$command wait-after-frame=1"
          wait_after_frame="--wait-after-frame"
	  ;;

        --snapshot|-s)
          command="$command record-frame=1"
          prep_snapshot=yes
          ;;

        --debug)
          debug=yes
          ;;
        *)
          echo "Unknown option '$1' given, run with option --help to see supported options"
          exit
          ;;
    esac
    shift
done

if [ "x$trace" = "x" ]; then
    echo "No trace given in run script, you must pass is as free parameter to the docker call"
    exit 1
fi

pushd /mesa
mkdir -p build

if [ ! -f build/build.ninja ]; then 
   meson build/ \
      -Dprefix=/usr/local \
      -Ddri-drivers=i965 \
      -Dgallium-drivers=swrast,virgl,radeonsi,iris \
      -Dbuildtype=debugoptimized \
      -Dllvm=true \
      -Dglx=dri \
      -Degl=true \
      -Dgbm=false \
      -Dgallium-vdpau=false \
      -Dgallium-va=false \
      -Dvulkan-drivers=[] \
      -Dvalgrind=false \
      -Dlibdir=lib
else    
   pushd build
   meson configure \
      -Dprefix=/usr/local \
      -Ddri-drivers=i965 \
      -Dgallium-drivers=swrast,virgl,radeonsi,iris \
      -Dbuildtype=debugoptimized \
      -Dllvm=true \
      -Dglx=dri \
      -Degl=true \
      -Dgbm=false \
      -Dgallium-vdpau=false \
      -Dgallium-va=false \
      -Dvulkan-drivers=[] \
      -Dvalgrind=false \
      -Dlibdir=lib
   popd
fi 
ninja -C build/ install
popd

pushd /virglrenderer
mkdir -p build

if [ ! -f build/build.ninja ]; then 
   meson build/ \
      -Dprefix=/usr/local \
      -Dlibdir=lib \
      -Dplatforms=glx,egl \
      -Dminigbm_allocation=true \
      -Dtracing=perfetto
else    
   pushd build
   meson configure \
      -Dprefix=/usr/local \
      -Dlibdir=lib \
      -Dplatforms=glx,egl \
      -Dminigbm_allocation=true \
      -Dtracing=perfetto
   popd
fi    
ninja -C build/ install
popd

# Crosvm needs to link with minigbm, due to incompatible ABI
export LD_PRELOAD=/usr/lib/libminigbm.so.1.0.0

export PATH="/apitrace/build:$PATH"
export PATH="/waffle/build/bin:$PATH"
export LD_LIBRARY_PATH="/waffle/build/lib:$LD_LIBRARY_PATH"
export LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"
export LD_LIBRARY_PATH="/usr/local/lib/x86_64-linux-gnu:$LD_LIBRARY_PATH"

trace_name=$(basename $trace)
trace_base=${trace_name%.*}
datadir="/traces-db/${trace_base}-out"

echo "Host:"
wflinfo --platform surfaceless_egl --api gles2

export EGL_PLATFORM="surfaceless"
export WAFFLE_PLATFORM="surfaceless_egl"
export DISPLAY=

if [ "x$benchmark_loops" != "x0" ]; then
   echo "Measuring rendering times:"
   eglretrace --benchmark --loop=$benchmark_loops --headless "/traces-db/${trace}"
fi

# To keep Perfetto happy
echo 0 > /sys/kernel/debug/tracing/tracing_on
echo nop > /sys/kernel/debug/tracing/current_tracer

/perfetto/out/dist/traced &
/perfetto/out/dist/traced_probes &
sleep 1
/gfx-pps/build/src/gpu/producer-gpu &
sleep 1
/perfetto/out/dist/perfetto --txt -c /usr/local/perfetto-host.cfg -o /tmp/perfetto-host.trace --detach=mykey
sleep 1

if [  "x$perfetto_loops" != "x" ] ; then
   echo "perfetto_loops parameter not given"
fi

echo "Replaying for Perfetto:"
LOOP=
if [ "x$perfetto_loops" != "x0" ]; then
    LOOP="--loop=$perfetto_loops"
fi

eglretrace --benchmark --singlethread $LOOP $wait_after_frame --headless "/traces-db/${trace}"

iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE
echo 1 > /proc/sys/net/ipv4/ip_forward


# store name of trace to be replayed so the guest can obtain the name 
echo $trace_base > /traces-db/current_trace
echo $command > /traces-db/command


guest_perf="$datadir/${trace_base}-guest.perfetto"
host_perf="$datadir/${trace_base}-host.perfetto"
summary_perf="$datadir/${trace_base}-summary.perfetto"

mkdir -p $datadir

# work around Crosvm crashing because of errors in context
# handling, could be a problem with the kernel and/or with virglrenderer
export MESA_EXTENSION_OVERRIDE="-GL_ARB_buffer_storage -GL_EXT_buffer_storage"

if [ "x$debug" = "xyes" ]; then
   export EGL_DEBUG=debug
fi

crosvm run \
   --gpu gles=false\
   -m 4096 \
   -c 4 \
   -i /rootfs.cpio.gz \
   --shared-dir "/usr/local:local:type=fs" \
   --shared-dir "/waffle:waffle-tag:type=fs" \
   --shared-dir "/apitrace:apitrace-tag:type=fs" \
   --shared-dir "/traces-db:traces-db-tag:type=fs" \
   --shared-dir "/perfetto:perfetto-tag:type=fs" \
   --host_ip 192.168.0.1 --netmask 255.255.255.0 --mac AA:BB:CC:00:00:12 \
   -p "root=/dev/ram0 rdinit=/init.sh ip=192.168.0.2::192.168.0.1:255.255.255.0:crosvm:eth0 nohz=off clocksource=kvm-clock" \
   /vmlinux

rm -f /traces-db/current_trace
rm -f /traces-db/command

/perfetto/out/dist/perfetto --attach=mykey --stop

mv /tmp/perfetto-host.trace "$host_perf"
chmod a+rw "$host_perf"

# sometimes one of these processes seems to crash or exit before, so
# check whether it is still
kill `pidof producer-gpu` || echo "producer-gpu was not running (anymore)"
kill `pidof traced_probes` || echo "traced_probes was not running (anymore)"
kill `pidof traced` || echo "traced was not running (anymore="

/usr/local/merge_traces.py "$host_perf" "$guest_perf" "$summary_perf"
sleep 1
