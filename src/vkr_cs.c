/*
 * Copyright 2021 Google LLC
 * SPDX-License-Identifier: MIT
 */

#include "vkr_cs.h"

void
vkr_cs_decoder_init(struct vkr_cs_decoder *dec,
                    const struct util_hash_table_u64 *object_table)
{
   memset(dec, 0, sizeof(*dec));
   dec->object_table = object_table;
}

void
vkr_cs_decoder_fini(struct vkr_cs_decoder *dec)
{
   struct vkr_cs_decoder_temp_pool *pool = &dec->temp_pool;
   for (uint32_t i = 0; i < pool->buffer_count; i++)
      free(pool->buffers[i]);
   if (pool->buffers)
      free(pool->buffers);
}

/**
 * Reset a decoder for reuse.
 */
void
vkr_cs_decoder_reset(struct vkr_cs_decoder *dec)
{
   /* dec->fatal_error is sticky */

   struct vkr_cs_decoder_temp_pool *pool = &dec->temp_pool;
   if (pool->buffer_count) {
      /* free all but the last buffer */
      for (uint32_t i = 0; i < pool->buffer_count - 1; i++)
         free(pool->buffers[i]);

      pool->buffers[0] = pool->buffers[pool->buffer_count - 1];
      pool->buffer_count = 1;

      assert(pool->cur >= pool->buffers[0]);
      pool->cur = pool->buffers[0];
   }

   dec->cur = NULL;
   dec->end = NULL;
}

static uint32_t
next_array_size(uint32_t cur_size, uint32_t min_size)
{
   const uint32_t next_size = cur_size ? cur_size * 2 : min_size;
   return next_size > cur_size ? next_size : 0;
}

static size_t
next_buffer_size(size_t cur_size, size_t min_size, size_t need)
{
   size_t next_size = cur_size ? cur_size * 2 : min_size;
   while (next_size < need) {
      next_size *= 2;
      if (!next_size)
         return 0;
   }
   return next_size;
}

static bool
vkr_cs_decoder_grow_temp_pool(struct vkr_cs_decoder *dec)
{
   struct vkr_cs_decoder_temp_pool *pool = &dec->temp_pool;
   const uint32_t buf_max = next_array_size(pool->buffer_max, 4);
   if (!buf_max)
      return false;

   uint8_t **bufs = realloc(pool->buffers, sizeof(*pool->buffers) * buf_max);
   if (!bufs)
      return false;

   pool->buffers = bufs;
   pool->buffer_max = buf_max;

   return true;
}

bool
vkr_cs_decoder_alloc_temp_internal(struct vkr_cs_decoder *dec, size_t size)
{
   struct vkr_cs_decoder_temp_pool *pool = &dec->temp_pool;

   if (pool->buffer_count >= pool->buffer_max) {
      if (!vkr_cs_decoder_grow_temp_pool(dec))
         return false;
      assert(pool->buffer_count < pool->buffer_max);
   }

   const size_t cur_buf_size =
      pool->buffer_count ? pool->end - pool->buffers[pool->buffer_count - 1]
                         : 0;
   const size_t buf_size = next_buffer_size(cur_buf_size, 4096, size);
   if (!buf_size)
      return false;

   uint8_t *buf = malloc(buf_size);
   if (!buf)
      return false;

   pool->buffers[pool->buffer_count++] = buf;
   pool->cur = buf;
   pool->end = buf + buf_size;

   return true;
}
