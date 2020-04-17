/**************************************************************************
 *
 * Copyright (C) 2020 Chromium.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

#ifndef VKR_RENDERER_H
#define VKR_RENDERER_H

#include "config.h"

#include <stddef.h>
#include <stdint.h>

#include "os/os_misc.h"

#define VKR_RENDERER_THREAD_SYNC               (1u << 0)
#define VKR_RENDERER_MULTI_PROCESS             (1u << 1)

struct virgl_context;

#ifdef ENABLE_VENUS

int
vkr_renderer_init(uint32_t flags);

void
vkr_renderer_fini(void);

void
vkr_renderer_reset(void);

size_t
vkr_get_capset(void *capset);

struct virgl_context *
vkr_context_create(size_t debug_len, const char *debug_name);

#else /* ENABLE_VENUS */

#include <stdio.h>

static inline int
vkr_renderer_init(UNUSED uint32_t flags)
{
   fprintf(stderr, "Vulkan is not supported on this platform\n");
   return -1;
}

static inline void
vkr_renderer_fini(void)
{
}

static inline void
vkr_renderer_reset(void)
{
}

static inline size_t
vkr_get_capset(void *capset)
{
   return 0;
}

static inline struct virgl_context *
vkr_context_create(UNUSED size_t debug_len,
                   UNUSED const char *debug_name)
{
   return NULL;
}

#endif /* ENABLE_VENUS */

#endif /* VKR_RENDERER_H */
