/*
 * Copyright 2021 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VKR_CS_H
#define VKR_CS_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "os/os_misc.h"
#include "util/u_hash_table.h"
#include "util/u_math.h"

#include "vkr_parser.h"

struct vkr_cs_decoder_temp_pool {
   uint8_t **buffers;
   uint32_t buffer_count;
   uint32_t buffer_max;

   uint8_t *cur;
   const uint8_t *end;
};

struct vkr_cs_decoder {
   const struct util_hash_table_u64 *object_table;

   bool fatal_error;
   struct vkr_cs_decoder_temp_pool temp_pool;

   const uint8_t *cur;
   const uint8_t *end;
};

void
vkr_cs_decoder_init(struct vkr_cs_decoder *dec,
                    const struct util_hash_table_u64 *object_table);

void
vkr_cs_decoder_fini(struct vkr_cs_decoder *dec);

void
vkr_cs_decoder_reset(struct vkr_cs_decoder *dec);

static inline void
vkr_cs_decoder_set_fatal(const struct vkr_cs_decoder *dec)
{
   ((struct vkr_cs_decoder *)dec)->fatal_error = true;
}

static inline bool
vkr_cs_decoder_get_fatal(const struct vkr_cs_decoder *dec)
{
   return dec->fatal_error;
}

static inline void
vkr_cs_decoder_set_stream(struct vkr_cs_decoder *dec,
                          const void *data,
                          size_t size)
{
   dec->cur = data;
   dec->end = dec->cur + size;
}

static inline bool
vkr_cs_decoder_has_command(const struct vkr_cs_decoder *dec)
{
   return dec->cur < dec->end;
}

static inline void
vkr_cs_decoder_read(struct vkr_cs_decoder *dec,
                    size_t size,
                    void *val,
                    size_t val_size)
{
   assert(val_size <= size);

   if (unlikely(size > (size_t)(dec->end - dec->cur))) {
      vkr_cs_decoder_set_fatal(dec);
      memset(val, 0, val_size);
      return;
   }

   /* we should not rely on the compiler to optimize away memcpy... */
   memcpy(val, dec->cur, val_size);
   dec->cur += size;
}

static inline void
vkr_cs_decoder_peek(const struct vkr_cs_decoder *dec,
                    void *val,
                    size_t val_size)
{
   if (unlikely(val_size > (size_t)(dec->end - dec->cur))) {
      vkr_cs_decoder_set_fatal(dec);
      memset(val, 0, val_size);
      return;
   }

   /* we should not rely on the compiler to optimize away memcpy... */
   memcpy(val, dec->cur, val_size);
}

static inline struct vkr_object *
vkr_cs_decoder_lookup_object(const struct vkr_cs_decoder *dec,
                             vkr_object_id id)
{
   struct vkr_object *obj;

   if (!id)
      return NULL;

   obj = util_hash_table_get_u64(
      (struct util_hash_table_u64 *)dec->object_table, id);
   if (!obj)
      vkr_cs_decoder_set_fatal(dec);

   return obj;
}

static inline void
vkr_cs_decoder_reset_temp_pool(struct vkr_cs_decoder *dec)
{
   struct vkr_cs_decoder_temp_pool *pool = &dec->temp_pool;
   if (pool->buffer_count)
      pool->cur = pool->buffers[pool->buffer_count - 1];
}

bool
vkr_cs_decoder_alloc_temp_internal(struct vkr_cs_decoder *dec, size_t size);

static inline void *
vkr_cs_decoder_alloc_temp(struct vkr_cs_decoder *dec, size_t size)
{
   struct vkr_cs_decoder_temp_pool *pool = &dec->temp_pool;

   /* align to 64-bit */
   size = align(size, 8);
   if (unlikely(size > (size_t)(pool->end - pool->cur))) {
      if (!vkr_cs_decoder_alloc_temp_internal(dec, size)) {
         vkr_cs_decoder_set_fatal(dec);
         return NULL;
      }
      assert(size <= (size_t)(pool->end - pool->cur));
   }

   void *ptr = pool->cur;
   pool->cur += size;
   return ptr;
}

#endif /* VKR_CS_H */
