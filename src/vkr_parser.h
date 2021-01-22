/*
 * Copyright 2019 Google LLC
 *
 * based in part on anv driver which is:
 * Copyright © 2015 Intel Corporation
 * Copyright © 2016 Red Hat.
 * Copyright © 2016 Bas Nieuwenhuizen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef VKR_PARSER_H
#define VKR_PARSER_H

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "os/os_misc.h"
#include "util/u_hash_table.h"

#include "venus-protocol/vulkan.h"
#include "vrend_iov.h"

typedef uint64_t vkr_parser_object_id;

struct vkr_parser_object {
   VkObjectType type;
   vkr_parser_object_id id;

   union {
      uint64_t handle;

      VkInstance instance;
      VkPhysicalDevice physical_device;
      VkDevice device;
      VkQueue queue;
      VkCommandBuffer command_buffer;

      VkBuffer buffer;
      VkImage image;
      VkSemaphore semaphore;
      VkFence fence;
      VkDeviceMemory device_memory;
      VkEvent event;
      VkQueryPool query_pool;
      VkBufferView buffer_view;
      VkImageView image_view;
      VkShaderModule shader_module;
      VkPipelineCache pipeline_cache;
      VkPipelineLayout pipeline_layout;
      VkPipeline pipeline;
      VkRenderPass render_pass;
      VkDescriptorSetLayout descriptor_set_layout;
      VkSampler sampler;
      VkDescriptorSet descriptor_set;
      VkDescriptorPool descriptor_pool;
      VkFramebuffer framebuffer;
      VkCommandPool command_pool;
      VkSamplerYcbcrConversion sampler_ycbcr_conversion;
      VkDescriptorUpdateTemplate descriptor_update_template;
   };
};

struct vkr_parser_temp_pool {
   uint8_t **buffers;
   uint32_t buffer_max;
   uint32_t buffer_count;

   uint8_t *cur;
   const uint8_t *end;
};

struct vkr_parser {
   bool error;

   struct util_hash_table_u64 *object_table;
   struct vkr_parser_temp_pool temp_pool;

   struct vkr_parser_command {
      const uint8_t *cur;
      const uint8_t *end;
   } command;

   struct vkr_parser_reply {
      const struct iovec *iov;
      int iov_count;
      size_t offset;
      size_t size;

      int cached_index;
      size_t cached_offset;

      size_t remaining_size;
      int next_iov;
      uint8_t *cur;
      const uint8_t *end;
   } reply;
};

void
vkr_parser_init(struct vkr_parser *parser,
                struct util_hash_table_u64 *object_table);

void
vkr_parser_fini(struct vkr_parser *parser);

void
vkr_parser_reset(struct vkr_parser *parser);

static inline void
vkr_parser_set_error(struct vkr_parser *parser)
{
   parser->error = true;
}

static inline bool
vkr_parser_has_error(const struct vkr_parser *parser)
{
   return parser->error;
}

static inline struct vkr_parser_object *
vkr_parser_lookup_object(struct vkr_parser *parser, vkr_parser_object_id id)
{
   struct vkr_parser_object *obj;

   if (!id)
      return NULL;

   obj = util_hash_table_get_u64(parser->object_table, id);
   if (!obj)
      vkr_parser_set_error(parser);

   return obj;
}

static inline void
vkr_parser_reset_temp_pool(struct vkr_parser *parser)
{
   struct vkr_parser_temp_pool *pool = &parser->temp_pool;
   if (pool->buffer_count)
      pool->cur = pool->buffers[pool->buffer_count - 1];
}

bool
vkr_parser_alloc_temp_internal(struct vkr_parser *parser, size_t size);

static inline void *
vkr_parser_alloc_temp(struct vkr_parser *parser, size_t size)
{
   struct vkr_parser_temp_pool *pool = &parser->temp_pool;

   /* align to 64-bit */
   size = (size + 7) & ~7;
   if (unlikely(size > (size_t)(pool->end - pool->cur))) {
      if (!vkr_parser_alloc_temp_internal(parser, size))
         return NULL;
      assert(size <= (size_t)(pool->end - pool->cur));
   }

   void *ptr = pool->cur;
   pool->cur += size;
   return ptr;
}

void
vkr_parser_set_command_stream(struct vkr_parser *parser,
                              const void *data,
                              size_t size);

static inline bool
vkr_parser_has_command(const struct vkr_parser *parser)
{
   return parser->command.cur < parser->command.end;
}

static inline void
vkr_parser_read(struct vkr_parser *parser,
                size_t size,
                void *val,
                size_t val_size)
{
   assert(val_size <= size);

   if (unlikely(size > (size_t)(parser->command.end - parser->command.cur))) {
      vkr_parser_set_error(parser);
      memset(val, 0, val_size);
      return;
   }

   /* we should not rely on the compiler to optimize away memcpy... */
   memcpy(val, parser->command.cur, val_size);
   parser->command.cur += size;
}

static inline void
vkr_parser_peek(struct vkr_parser *parser,
                void *val,
                size_t val_size)
{
   if (unlikely(val_size > (size_t)(parser->command.end - parser->command.cur))) {
      vkr_parser_set_error(parser);
      memset(val, 0, val_size);
      return;
   }

   /* we should not rely on the compiler to optimize away memcpy... */
   memcpy(val, parser->command.cur, val_size);
}

void
vkr_parser_set_reply_stream(struct vkr_parser *parser,
                            const struct iovec *iov,
                            int iov_count,
                            size_t offset,
                            size_t size);

void
vkr_parser_seek_reply_stream(struct vkr_parser *parser,
                             size_t pos);

void
vkr_parser_reply_internal(struct vkr_parser *parser,
                          size_t size,
                          const void *val,
                          size_t val_size);

static inline void
vkr_parser_reply(struct vkr_parser *parser,
                 size_t size,
                 const void *val,
                 size_t val_size)
{
   assert(val_size <= size);

   if (unlikely(size > (size_t)(parser->reply.end - parser->reply.cur))) {
      vkr_parser_reply_internal(parser, size, val, val_size);
      return;
   }

   /* we should not rely on the compiler to optimize away memcpy... */
   memcpy(parser->reply.cur, val, val_size);
   parser->reply.cur += size;
}

static inline vkr_parser_object_id
vkr_parser_handle_load_id(const void *vk_handle, bool in_place)
{
   if (in_place) {
      const vkr_parser_object_id *obj = vk_handle;
      return *obj;
   } else {
      const vkr_parser_object_id *const *obj = vk_handle;
      return **obj;
   }
}

static inline void
vkr_parser_handle_store_id(void *vk_handle, vkr_parser_object_id id, bool in_place)
{
   if (in_place) {
      vkr_parser_object_id *dst = vk_handle;
      *dst = id;
   } else {
      vkr_parser_object_id **dst = vk_handle;
      **dst = id;
   }
}

#endif /* VKR_PARSER_H */
