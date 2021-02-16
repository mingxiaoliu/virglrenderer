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

typedef uint64_t vkr_object_id;

struct vkr_object {
   VkObjectType type;
   vkr_object_id id;

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

struct vkr_parser {
   bool *error;

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
vkr_parser_init(struct vkr_parser *parser, bool *error);

void
vkr_parser_reset(struct vkr_parser *parser);

static inline void
vkr_parser_set_error(struct vkr_parser *parser)
{
   *parser->error = true;
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

static inline vkr_object_id
vkr_parser_handle_load_id(const void *vk_handle, bool in_place)
{
   if (in_place) {
      const vkr_object_id *obj = vk_handle;
      return *obj;
   } else {
      const vkr_object_id *const *obj = vk_handle;
      return **obj;
   }
}

static inline void
vkr_parser_handle_store_id(void *vk_handle, vkr_object_id id, bool in_place)
{
   if (in_place) {
      vkr_object_id *dst = vk_handle;
      *dst = id;
   } else {
      vkr_object_id **dst = vk_handle;
      **dst = id;
   }
}

#endif /* VKR_PARSER_H */
