/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_TYPES_H
#define VN_PROTOCOL_RENDERER_TYPES_H

#include "vn_protocol_renderer_defines.h"

/* uint64_t */

static inline void
vn_encode_uint64_t(struct vn_cs_encoder *enc, const uint64_t *val)
{
    vn_encode(enc, 8, val, sizeof(*val));
}

static inline void
vn_decode_uint64_t(struct vn_cs_decoder *dec, uint64_t *val)
{
    vn_decode(dec, 8, val, sizeof(*val));
}

static inline void
vn_encode_uint64_t_array(struct vn_cs_encoder *enc, const uint64_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(enc, size, val, size);
}

static inline void
vn_decode_uint64_t_array(struct vn_cs_decoder *dec, uint64_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(dec, size, val, size);
}

/* int32_t */

static inline void
vn_encode_int32_t(struct vn_cs_encoder *enc, const int32_t *val)
{
    vn_encode(enc, 4, val, sizeof(*val));
}

static inline void
vn_decode_int32_t(struct vn_cs_decoder *dec, int32_t *val)
{
    vn_decode(dec, 4, val, sizeof(*val));
}

static inline void
vn_encode_int32_t_array(struct vn_cs_encoder *enc, const int32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(enc, size, val, size);
}

static inline void
vn_decode_int32_t_array(struct vn_cs_decoder *dec, int32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(dec, size, val, size);
}

/* enum VkStructureType */

static inline void
vn_encode_VkStructureType(struct vn_cs_encoder *enc, const VkStructureType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkStructureType(struct vn_cs_decoder *dec, VkStructureType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* size_t */

static inline void
vn_encode_size_t(struct vn_cs_encoder *enc, const size_t *val)
{
    const uint64_t tmp = *val;
    vn_encode_uint64_t(enc, &tmp);
}

static inline void
vn_decode_size_t(struct vn_cs_decoder *dec, size_t *val)
{
    uint64_t tmp;
    vn_decode_uint64_t(dec, &tmp);
    *val = tmp;
}

static inline void
vn_encode_size_t_array(struct vn_cs_encoder *enc, const size_t *val, uint32_t count)
{
    if (sizeof(size_t) == sizeof(uint64_t)) {
        vn_encode_uint64_t_array(enc, (const uint64_t *)val, count);
    } else {
        for (uint32_t i = 0; i < count; i++)
            vn_encode_size_t(enc, &val[i]);
    }
}

static inline void
vn_decode_size_t_array(struct vn_cs_decoder *dec, size_t *val, uint32_t count)
{
    if (sizeof(size_t) == sizeof(uint64_t)) {
        vn_decode_uint64_t_array(dec, (uint64_t *)val, count);
    } else {
        for (uint32_t i = 0; i < count; i++)
            vn_decode_size_t(dec, &val[i]);
    }
}

/* opaque blob */

static inline void
vn_encode_blob_array(struct vn_cs_encoder *enc, const void *val, size_t size)
{
    vn_encode(enc, (size + 3) & ~3, val, size);
}

static inline void
vn_decode_blob_array(struct vn_cs_decoder *dec, void *val, size_t size)
{
    vn_decode(dec, (size + 3) & ~3, val, size);
}

/* array size (uint64_t) */

static inline void
vn_encode_array_size(struct vn_cs_encoder *enc, uint64_t size)
{
    vn_encode_uint64_t(enc, &size);
}

static inline uint64_t
vn_decode_array_size(struct vn_cs_decoder *dec, uint64_t max_size)
{
    uint64_t size;
    vn_decode_uint64_t(dec, &size);
    if (size > max_size) {
        vn_cs_decoder_set_fatal(dec);
        size = 0;
    }
    return size;
}

static inline uint64_t
vn_peek_array_size(struct vn_cs_decoder *dec)
{
    uint64_t size;
    vn_cs_decoder_peek(dec, &size, sizeof(size));
    return size;
}

/* non-array pointer */

static inline bool
vn_encode_simple_pointer(struct vn_cs_encoder *enc, const void *val)
{
    vn_encode_array_size(enc, val ? 1 : 0);
    return val;
}

static inline bool
vn_decode_simple_pointer(struct vn_cs_decoder *dec)
{
    return vn_decode_array_size(dec, 1);
}

/* uint32_t */

static inline void
vn_encode_uint32_t(struct vn_cs_encoder *enc, const uint32_t *val)
{
    vn_encode(enc, 4, val, sizeof(*val));
}

static inline void
vn_decode_uint32_t(struct vn_cs_decoder *dec, uint32_t *val)
{
    vn_decode(dec, 4, val, sizeof(*val));
}

static inline void
vn_encode_uint32_t_array(struct vn_cs_encoder *enc, const uint32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(enc, size, val, size);
}

static inline void
vn_decode_uint32_t_array(struct vn_cs_decoder *dec, uint32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(dec, size, val, size);
}

/* float */

static inline void
vn_encode_float(struct vn_cs_encoder *enc, const float *val)
{
    vn_encode(enc, 4, val, sizeof(*val));
}

static inline void
vn_decode_float(struct vn_cs_decoder *dec, float *val)
{
    vn_decode(dec, 4, val, sizeof(*val));
}

static inline void
vn_encode_float_array(struct vn_cs_encoder *enc, const float *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(enc, size, val, size);
}

static inline void
vn_decode_float_array(struct vn_cs_decoder *dec, float *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(dec, size, val, size);
}

/* uint8_t */

static inline void
vn_encode_uint8_t(struct vn_cs_encoder *enc, const uint8_t *val)
{
    vn_encode(enc, 4, val, sizeof(*val));
}

static inline void
vn_decode_uint8_t(struct vn_cs_decoder *dec, uint8_t *val)
{
    vn_decode(dec, 4, val, sizeof(*val));
}

static inline void
vn_encode_uint8_t_array(struct vn_cs_encoder *enc, const uint8_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(enc, (size + 3) & ~3, val, size);
}

static inline void
vn_decode_uint8_t_array(struct vn_cs_decoder *dec, uint8_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(dec, (size + 3) & ~3, val, size);
}

/* typedef uint32_t VkSampleMask */

static inline void
vn_encode_VkSampleMask(struct vn_cs_encoder *enc, const VkSampleMask *val)
{
    vn_encode_uint32_t(enc, val);
}

static inline void
vn_decode_VkSampleMask(struct vn_cs_decoder *dec, VkSampleMask *val)
{
    vn_decode_uint32_t(dec, val);
}

static inline void
vn_encode_VkSampleMask_array(struct vn_cs_encoder *enc, const VkSampleMask *val, uint32_t count)
{
    vn_encode_uint32_t_array(enc, val, count);
}

static inline void
vn_decode_VkSampleMask_array(struct vn_cs_decoder *dec, VkSampleMask *val, uint32_t count)
{
    vn_decode_uint32_t_array(dec, val, count);
}

/* typedef uint32_t VkBool32 */

static inline void
vn_encode_VkBool32(struct vn_cs_encoder *enc, const VkBool32 *val)
{
    vn_encode_uint32_t(enc, val);
}

static inline void
vn_decode_VkBool32(struct vn_cs_decoder *dec, VkBool32 *val)
{
    vn_decode_uint32_t(dec, val);
}

static inline void
vn_encode_VkBool32_array(struct vn_cs_encoder *enc, const VkBool32 *val, uint32_t count)
{
    vn_encode_uint32_t_array(enc, val, count);
}

static inline void
vn_decode_VkBool32_array(struct vn_cs_decoder *dec, VkBool32 *val, uint32_t count)
{
    vn_decode_uint32_t_array(dec, val, count);
}

/* typedef uint32_t VkFlags */

static inline void
vn_encode_VkFlags(struct vn_cs_encoder *enc, const VkFlags *val)
{
    vn_encode_uint32_t(enc, val);
}

static inline void
vn_decode_VkFlags(struct vn_cs_decoder *dec, VkFlags *val)
{
    vn_decode_uint32_t(dec, val);
}

static inline void
vn_encode_VkFlags_array(struct vn_cs_encoder *enc, const VkFlags *val, uint32_t count)
{
    vn_encode_uint32_t_array(enc, val, count);
}

static inline void
vn_decode_VkFlags_array(struct vn_cs_decoder *dec, VkFlags *val, uint32_t count)
{
    vn_decode_uint32_t_array(dec, val, count);
}

/* typedef uint64_t VkDeviceSize */

static inline void
vn_encode_VkDeviceSize(struct vn_cs_encoder *enc, const VkDeviceSize *val)
{
    vn_encode_uint64_t(enc, val);
}

static inline void
vn_decode_VkDeviceSize(struct vn_cs_decoder *dec, VkDeviceSize *val)
{
    vn_decode_uint64_t(dec, val);
}

static inline void
vn_encode_VkDeviceSize_array(struct vn_cs_encoder *enc, const VkDeviceSize *val, uint32_t count)
{
    vn_encode_uint64_t_array(enc, val, count);
}

static inline void
vn_decode_VkDeviceSize_array(struct vn_cs_decoder *dec, VkDeviceSize *val, uint32_t count)
{
    vn_decode_uint64_t_array(dec, val, count);
}

/* typedef uint64_t VkDeviceAddress */

static inline void
vn_encode_VkDeviceAddress(struct vn_cs_encoder *enc, const VkDeviceAddress *val)
{
    vn_encode_uint64_t(enc, val);
}

static inline void
vn_decode_VkDeviceAddress(struct vn_cs_decoder *dec, VkDeviceAddress *val)
{
    vn_decode_uint64_t(dec, val);
}

static inline void
vn_encode_VkDeviceAddress_array(struct vn_cs_encoder *enc, const VkDeviceAddress *val, uint32_t count)
{
    vn_encode_uint64_t_array(enc, val, count);
}

static inline void
vn_decode_VkDeviceAddress_array(struct vn_cs_decoder *dec, VkDeviceAddress *val, uint32_t count)
{
    vn_decode_uint64_t_array(dec, val, count);
}

/* enum VkFramebufferCreateFlagBits */

static inline void
vn_encode_VkFramebufferCreateFlagBits(struct vn_cs_encoder *enc, const VkFramebufferCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkFramebufferCreateFlagBits(struct vn_cs_decoder *dec, VkFramebufferCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkRenderPassCreateFlagBits */

static inline void
vn_encode_VkRenderPassCreateFlagBits(struct vn_cs_encoder *enc, const VkRenderPassCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkRenderPassCreateFlagBits(struct vn_cs_decoder *dec, VkRenderPassCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSamplerCreateFlagBits */

static inline void
vn_encode_VkSamplerCreateFlagBits(struct vn_cs_encoder *enc, const VkSamplerCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerCreateFlagBits(struct vn_cs_decoder *dec, VkSamplerCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPipelineCacheCreateFlagBits */

static inline void
vn_encode_VkPipelineCacheCreateFlagBits(struct vn_cs_encoder *enc, const VkPipelineCacheCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineCacheCreateFlagBits(struct vn_cs_decoder *dec, VkPipelineCacheCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPipelineShaderStageCreateFlagBits */

static inline void
vn_encode_VkPipelineShaderStageCreateFlagBits(struct vn_cs_encoder *enc, const VkPipelineShaderStageCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineShaderStageCreateFlagBits(struct vn_cs_decoder *dec, VkPipelineShaderStageCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDescriptorSetLayoutCreateFlagBits */

static inline void
vn_encode_VkDescriptorSetLayoutCreateFlagBits(struct vn_cs_encoder *enc, const VkDescriptorSetLayoutCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorSetLayoutCreateFlagBits(struct vn_cs_decoder *dec, VkDescriptorSetLayoutCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDeviceQueueCreateFlagBits */

static inline void
vn_encode_VkDeviceQueueCreateFlagBits(struct vn_cs_encoder *enc, const VkDeviceQueueCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDeviceQueueCreateFlagBits(struct vn_cs_decoder *dec, VkDeviceQueueCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkQueueFlagBits */

static inline void
vn_encode_VkQueueFlagBits(struct vn_cs_encoder *enc, const VkQueueFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkQueueFlagBits(struct vn_cs_decoder *dec, VkQueueFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkMemoryPropertyFlagBits */

static inline void
vn_encode_VkMemoryPropertyFlagBits(struct vn_cs_encoder *enc, const VkMemoryPropertyFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkMemoryPropertyFlagBits(struct vn_cs_decoder *dec, VkMemoryPropertyFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkMemoryHeapFlagBits */

static inline void
vn_encode_VkMemoryHeapFlagBits(struct vn_cs_encoder *enc, const VkMemoryHeapFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkMemoryHeapFlagBits(struct vn_cs_decoder *dec, VkMemoryHeapFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkAccessFlagBits */

static inline void
vn_encode_VkAccessFlagBits(struct vn_cs_encoder *enc, const VkAccessFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkAccessFlagBits(struct vn_cs_decoder *dec, VkAccessFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkBufferUsageFlagBits */

static inline void
vn_encode_VkBufferUsageFlagBits(struct vn_cs_encoder *enc, const VkBufferUsageFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkBufferUsageFlagBits(struct vn_cs_decoder *dec, VkBufferUsageFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkBufferCreateFlagBits */

static inline void
vn_encode_VkBufferCreateFlagBits(struct vn_cs_encoder *enc, const VkBufferCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkBufferCreateFlagBits(struct vn_cs_decoder *dec, VkBufferCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkShaderStageFlagBits */

static inline void
vn_encode_VkShaderStageFlagBits(struct vn_cs_encoder *enc, const VkShaderStageFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkShaderStageFlagBits(struct vn_cs_decoder *dec, VkShaderStageFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageUsageFlagBits */

static inline void
vn_encode_VkImageUsageFlagBits(struct vn_cs_encoder *enc, const VkImageUsageFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageUsageFlagBits(struct vn_cs_decoder *dec, VkImageUsageFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageCreateFlagBits */

static inline void
vn_encode_VkImageCreateFlagBits(struct vn_cs_encoder *enc, const VkImageCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageCreateFlagBits(struct vn_cs_decoder *dec, VkImageCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageViewCreateFlagBits */

static inline void
vn_encode_VkImageViewCreateFlagBits(struct vn_cs_encoder *enc, const VkImageViewCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageViewCreateFlagBits(struct vn_cs_decoder *dec, VkImageViewCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPipelineCreateFlagBits */

static inline void
vn_encode_VkPipelineCreateFlagBits(struct vn_cs_encoder *enc, const VkPipelineCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineCreateFlagBits(struct vn_cs_decoder *dec, VkPipelineCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkColorComponentFlagBits */

static inline void
vn_encode_VkColorComponentFlagBits(struct vn_cs_encoder *enc, const VkColorComponentFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkColorComponentFlagBits(struct vn_cs_decoder *dec, VkColorComponentFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkFenceCreateFlagBits */

static inline void
vn_encode_VkFenceCreateFlagBits(struct vn_cs_encoder *enc, const VkFenceCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkFenceCreateFlagBits(struct vn_cs_decoder *dec, VkFenceCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkFormatFeatureFlagBits */

static inline void
vn_encode_VkFormatFeatureFlagBits(struct vn_cs_encoder *enc, const VkFormatFeatureFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkFormatFeatureFlagBits(struct vn_cs_decoder *dec, VkFormatFeatureFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkQueryControlFlagBits */

static inline void
vn_encode_VkQueryControlFlagBits(struct vn_cs_encoder *enc, const VkQueryControlFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryControlFlagBits(struct vn_cs_decoder *dec, VkQueryControlFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkQueryResultFlagBits */

static inline void
vn_encode_VkQueryResultFlagBits(struct vn_cs_encoder *enc, const VkQueryResultFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryResultFlagBits(struct vn_cs_decoder *dec, VkQueryResultFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCommandPoolCreateFlagBits */

static inline void
vn_encode_VkCommandPoolCreateFlagBits(struct vn_cs_encoder *enc, const VkCommandPoolCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandPoolCreateFlagBits(struct vn_cs_decoder *dec, VkCommandPoolCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCommandPoolResetFlagBits */

static inline void
vn_encode_VkCommandPoolResetFlagBits(struct vn_cs_encoder *enc, const VkCommandPoolResetFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandPoolResetFlagBits(struct vn_cs_decoder *dec, VkCommandPoolResetFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCommandBufferResetFlagBits */

static inline void
vn_encode_VkCommandBufferResetFlagBits(struct vn_cs_encoder *enc, const VkCommandBufferResetFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandBufferResetFlagBits(struct vn_cs_decoder *dec, VkCommandBufferResetFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCommandBufferUsageFlagBits */

static inline void
vn_encode_VkCommandBufferUsageFlagBits(struct vn_cs_encoder *enc, const VkCommandBufferUsageFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandBufferUsageFlagBits(struct vn_cs_decoder *dec, VkCommandBufferUsageFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkQueryPipelineStatisticFlagBits */

static inline void
vn_encode_VkQueryPipelineStatisticFlagBits(struct vn_cs_encoder *enc, const VkQueryPipelineStatisticFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryPipelineStatisticFlagBits(struct vn_cs_decoder *dec, VkQueryPipelineStatisticFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageAspectFlagBits */

static inline void
vn_encode_VkImageAspectFlagBits(struct vn_cs_encoder *enc, const VkImageAspectFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageAspectFlagBits(struct vn_cs_decoder *dec, VkImageAspectFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSparseMemoryBindFlagBits */

static inline void
vn_encode_VkSparseMemoryBindFlagBits(struct vn_cs_encoder *enc, const VkSparseMemoryBindFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSparseMemoryBindFlagBits(struct vn_cs_decoder *dec, VkSparseMemoryBindFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSparseImageFormatFlagBits */

static inline void
vn_encode_VkSparseImageFormatFlagBits(struct vn_cs_encoder *enc, const VkSparseImageFormatFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSparseImageFormatFlagBits(struct vn_cs_decoder *dec, VkSparseImageFormatFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSubpassDescriptionFlagBits */

static inline void
vn_encode_VkSubpassDescriptionFlagBits(struct vn_cs_encoder *enc, const VkSubpassDescriptionFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSubpassDescriptionFlagBits(struct vn_cs_decoder *dec, VkSubpassDescriptionFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPipelineStageFlagBits */

static inline void
vn_encode_VkPipelineStageFlagBits(struct vn_cs_encoder *enc, const VkPipelineStageFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineStageFlagBits(struct vn_cs_decoder *dec, VkPipelineStageFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSampleCountFlagBits */

static inline void
vn_encode_VkSampleCountFlagBits(struct vn_cs_encoder *enc, const VkSampleCountFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSampleCountFlagBits(struct vn_cs_decoder *dec, VkSampleCountFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkAttachmentDescriptionFlagBits */

static inline void
vn_encode_VkAttachmentDescriptionFlagBits(struct vn_cs_encoder *enc, const VkAttachmentDescriptionFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkAttachmentDescriptionFlagBits(struct vn_cs_decoder *dec, VkAttachmentDescriptionFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkStencilFaceFlagBits */

static inline void
vn_encode_VkStencilFaceFlagBits(struct vn_cs_encoder *enc, const VkStencilFaceFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkStencilFaceFlagBits(struct vn_cs_decoder *dec, VkStencilFaceFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCullModeFlagBits */

static inline void
vn_encode_VkCullModeFlagBits(struct vn_cs_encoder *enc, const VkCullModeFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCullModeFlagBits(struct vn_cs_decoder *dec, VkCullModeFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDescriptorPoolCreateFlagBits */

static inline void
vn_encode_VkDescriptorPoolCreateFlagBits(struct vn_cs_encoder *enc, const VkDescriptorPoolCreateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorPoolCreateFlagBits(struct vn_cs_decoder *dec, VkDescriptorPoolCreateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDependencyFlagBits */

static inline void
vn_encode_VkDependencyFlagBits(struct vn_cs_encoder *enc, const VkDependencyFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDependencyFlagBits(struct vn_cs_decoder *dec, VkDependencyFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSubgroupFeatureFlagBits */

static inline void
vn_encode_VkSubgroupFeatureFlagBits(struct vn_cs_encoder *enc, const VkSubgroupFeatureFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSubgroupFeatureFlagBits(struct vn_cs_decoder *dec, VkSubgroupFeatureFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSemaphoreWaitFlagBits */

static inline void
vn_encode_VkSemaphoreWaitFlagBits(struct vn_cs_encoder *enc, const VkSemaphoreWaitFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSemaphoreWaitFlagBits(struct vn_cs_decoder *dec, VkSemaphoreWaitFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPeerMemoryFeatureFlagBits */

static inline void
vn_encode_VkPeerMemoryFeatureFlagBits(struct vn_cs_encoder *enc, const VkPeerMemoryFeatureFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPeerMemoryFeatureFlagBits(struct vn_cs_decoder *dec, VkPeerMemoryFeatureFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkMemoryAllocateFlagBits */

static inline void
vn_encode_VkMemoryAllocateFlagBits(struct vn_cs_encoder *enc, const VkMemoryAllocateFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkMemoryAllocateFlagBits(struct vn_cs_decoder *dec, VkMemoryAllocateFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkExternalMemoryHandleTypeFlagBits */

static inline void
vn_encode_VkExternalMemoryHandleTypeFlagBits(struct vn_cs_encoder *enc, const VkExternalMemoryHandleTypeFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalMemoryHandleTypeFlagBits(struct vn_cs_decoder *dec, VkExternalMemoryHandleTypeFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkExternalMemoryFeatureFlagBits */

static inline void
vn_encode_VkExternalMemoryFeatureFlagBits(struct vn_cs_encoder *enc, const VkExternalMemoryFeatureFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalMemoryFeatureFlagBits(struct vn_cs_decoder *dec, VkExternalMemoryFeatureFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkExternalSemaphoreHandleTypeFlagBits */

static inline void
vn_encode_VkExternalSemaphoreHandleTypeFlagBits(struct vn_cs_encoder *enc, const VkExternalSemaphoreHandleTypeFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalSemaphoreHandleTypeFlagBits(struct vn_cs_decoder *dec, VkExternalSemaphoreHandleTypeFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkExternalSemaphoreFeatureFlagBits */

static inline void
vn_encode_VkExternalSemaphoreFeatureFlagBits(struct vn_cs_encoder *enc, const VkExternalSemaphoreFeatureFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalSemaphoreFeatureFlagBits(struct vn_cs_decoder *dec, VkExternalSemaphoreFeatureFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSemaphoreImportFlagBits */

static inline void
vn_encode_VkSemaphoreImportFlagBits(struct vn_cs_encoder *enc, const VkSemaphoreImportFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSemaphoreImportFlagBits(struct vn_cs_decoder *dec, VkSemaphoreImportFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkExternalFenceHandleTypeFlagBits */

static inline void
vn_encode_VkExternalFenceHandleTypeFlagBits(struct vn_cs_encoder *enc, const VkExternalFenceHandleTypeFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalFenceHandleTypeFlagBits(struct vn_cs_decoder *dec, VkExternalFenceHandleTypeFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkExternalFenceFeatureFlagBits */

static inline void
vn_encode_VkExternalFenceFeatureFlagBits(struct vn_cs_encoder *enc, const VkExternalFenceFeatureFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalFenceFeatureFlagBits(struct vn_cs_decoder *dec, VkExternalFenceFeatureFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkFenceImportFlagBits */

static inline void
vn_encode_VkFenceImportFlagBits(struct vn_cs_encoder *enc, const VkFenceImportFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkFenceImportFlagBits(struct vn_cs_decoder *dec, VkFenceImportFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDescriptorBindingFlagBits */

static inline void
vn_encode_VkDescriptorBindingFlagBits(struct vn_cs_encoder *enc, const VkDescriptorBindingFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorBindingFlagBits(struct vn_cs_decoder *dec, VkDescriptorBindingFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkResolveModeFlagBits */

static inline void
vn_encode_VkResolveModeFlagBits(struct vn_cs_encoder *enc, const VkResolveModeFlagBits *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkResolveModeFlagBits(struct vn_cs_decoder *dec, VkResolveModeFlagBits *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkAttachmentLoadOp */

static inline void
vn_encode_VkAttachmentLoadOp(struct vn_cs_encoder *enc, const VkAttachmentLoadOp *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkAttachmentLoadOp(struct vn_cs_decoder *dec, VkAttachmentLoadOp *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkAttachmentStoreOp */

static inline void
vn_encode_VkAttachmentStoreOp(struct vn_cs_encoder *enc, const VkAttachmentStoreOp *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkAttachmentStoreOp(struct vn_cs_decoder *dec, VkAttachmentStoreOp *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkBlendFactor */

static inline void
vn_encode_VkBlendFactor(struct vn_cs_encoder *enc, const VkBlendFactor *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkBlendFactor(struct vn_cs_decoder *dec, VkBlendFactor *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkBlendOp */

static inline void
vn_encode_VkBlendOp(struct vn_cs_encoder *enc, const VkBlendOp *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkBlendOp(struct vn_cs_decoder *dec, VkBlendOp *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkBorderColor */

static inline void
vn_encode_VkBorderColor(struct vn_cs_encoder *enc, const VkBorderColor *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkBorderColor(struct vn_cs_decoder *dec, VkBorderColor *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPipelineCacheHeaderVersion */

static inline void
vn_encode_VkPipelineCacheHeaderVersion(struct vn_cs_encoder *enc, const VkPipelineCacheHeaderVersion *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineCacheHeaderVersion(struct vn_cs_decoder *dec, VkPipelineCacheHeaderVersion *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkComponentSwizzle */

static inline void
vn_encode_VkComponentSwizzle(struct vn_cs_encoder *enc, const VkComponentSwizzle *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkComponentSwizzle(struct vn_cs_decoder *dec, VkComponentSwizzle *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCommandBufferLevel */

static inline void
vn_encode_VkCommandBufferLevel(struct vn_cs_encoder *enc, const VkCommandBufferLevel *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandBufferLevel(struct vn_cs_decoder *dec, VkCommandBufferLevel *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCompareOp */

static inline void
vn_encode_VkCompareOp(struct vn_cs_encoder *enc, const VkCompareOp *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCompareOp(struct vn_cs_decoder *dec, VkCompareOp *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDescriptorType */

static inline void
vn_encode_VkDescriptorType(struct vn_cs_encoder *enc, const VkDescriptorType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorType(struct vn_cs_decoder *dec, VkDescriptorType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

static inline void
vn_encode_VkDescriptorType_array(struct vn_cs_encoder *enc, const VkDescriptorType *val, uint32_t count)
{
    vn_encode_int32_t_array(enc, (const int32_t *)val, count);
}

static inline void
vn_decode_VkDescriptorType_array(struct vn_cs_decoder *dec, VkDescriptorType *val, uint32_t count)
{
    vn_decode_int32_t_array(dec, (int32_t *)val, count);
}

/* enum VkDynamicState */

static inline void
vn_encode_VkDynamicState(struct vn_cs_encoder *enc, const VkDynamicState *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDynamicState(struct vn_cs_decoder *dec, VkDynamicState *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

static inline void
vn_encode_VkDynamicState_array(struct vn_cs_encoder *enc, const VkDynamicState *val, uint32_t count)
{
    vn_encode_int32_t_array(enc, (const int32_t *)val, count);
}

static inline void
vn_decode_VkDynamicState_array(struct vn_cs_decoder *dec, VkDynamicState *val, uint32_t count)
{
    vn_decode_int32_t_array(dec, (int32_t *)val, count);
}

/* enum VkPolygonMode */

static inline void
vn_encode_VkPolygonMode(struct vn_cs_encoder *enc, const VkPolygonMode *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPolygonMode(struct vn_cs_decoder *dec, VkPolygonMode *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkFormat */

static inline void
vn_encode_VkFormat(struct vn_cs_encoder *enc, const VkFormat *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkFormat(struct vn_cs_decoder *dec, VkFormat *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

static inline void
vn_encode_VkFormat_array(struct vn_cs_encoder *enc, const VkFormat *val, uint32_t count)
{
    vn_encode_int32_t_array(enc, (const int32_t *)val, count);
}

static inline void
vn_decode_VkFormat_array(struct vn_cs_decoder *dec, VkFormat *val, uint32_t count)
{
    vn_decode_int32_t_array(dec, (int32_t *)val, count);
}

/* enum VkFrontFace */

static inline void
vn_encode_VkFrontFace(struct vn_cs_encoder *enc, const VkFrontFace *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkFrontFace(struct vn_cs_decoder *dec, VkFrontFace *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageLayout */

static inline void
vn_encode_VkImageLayout(struct vn_cs_encoder *enc, const VkImageLayout *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageLayout(struct vn_cs_decoder *dec, VkImageLayout *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageTiling */

static inline void
vn_encode_VkImageTiling(struct vn_cs_encoder *enc, const VkImageTiling *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageTiling(struct vn_cs_decoder *dec, VkImageTiling *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageType */

static inline void
vn_encode_VkImageType(struct vn_cs_encoder *enc, const VkImageType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageType(struct vn_cs_decoder *dec, VkImageType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkImageViewType */

static inline void
vn_encode_VkImageViewType(struct vn_cs_encoder *enc, const VkImageViewType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkImageViewType(struct vn_cs_decoder *dec, VkImageViewType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSharingMode */

static inline void
vn_encode_VkSharingMode(struct vn_cs_encoder *enc, const VkSharingMode *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSharingMode(struct vn_cs_decoder *dec, VkSharingMode *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkIndexType */

static inline void
vn_encode_VkIndexType(struct vn_cs_encoder *enc, const VkIndexType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkIndexType(struct vn_cs_decoder *dec, VkIndexType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

static inline void
vn_encode_VkIndexType_array(struct vn_cs_encoder *enc, const VkIndexType *val, uint32_t count)
{
    vn_encode_int32_t_array(enc, (const int32_t *)val, count);
}

static inline void
vn_decode_VkIndexType_array(struct vn_cs_decoder *dec, VkIndexType *val, uint32_t count)
{
    vn_decode_int32_t_array(dec, (int32_t *)val, count);
}

/* enum VkLogicOp */

static inline void
vn_encode_VkLogicOp(struct vn_cs_encoder *enc, const VkLogicOp *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkLogicOp(struct vn_cs_decoder *dec, VkLogicOp *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPhysicalDeviceType */

static inline void
vn_encode_VkPhysicalDeviceType(struct vn_cs_encoder *enc, const VkPhysicalDeviceType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPhysicalDeviceType(struct vn_cs_decoder *dec, VkPhysicalDeviceType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPipelineBindPoint */

static inline void
vn_encode_VkPipelineBindPoint(struct vn_cs_encoder *enc, const VkPipelineBindPoint *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineBindPoint(struct vn_cs_decoder *dec, VkPipelineBindPoint *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPrimitiveTopology */

static inline void
vn_encode_VkPrimitiveTopology(struct vn_cs_encoder *enc, const VkPrimitiveTopology *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPrimitiveTopology(struct vn_cs_decoder *dec, VkPrimitiveTopology *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkQueryType */

static inline void
vn_encode_VkQueryType(struct vn_cs_encoder *enc, const VkQueryType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryType(struct vn_cs_decoder *dec, VkQueryType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSubpassContents */

static inline void
vn_encode_VkSubpassContents(struct vn_cs_encoder *enc, const VkSubpassContents *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSubpassContents(struct vn_cs_decoder *dec, VkSubpassContents *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkResult */

static inline void
vn_encode_VkResult(struct vn_cs_encoder *enc, const VkResult *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkResult(struct vn_cs_decoder *dec, VkResult *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

static inline void
vn_encode_VkResult_array(struct vn_cs_encoder *enc, const VkResult *val, uint32_t count)
{
    vn_encode_int32_t_array(enc, (const int32_t *)val, count);
}

static inline void
vn_decode_VkResult_array(struct vn_cs_decoder *dec, VkResult *val, uint32_t count)
{
    vn_decode_int32_t_array(dec, (int32_t *)val, count);
}

/* enum VkStencilOp */

static inline void
vn_encode_VkStencilOp(struct vn_cs_encoder *enc, const VkStencilOp *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkStencilOp(struct vn_cs_decoder *dec, VkStencilOp *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSystemAllocationScope */

static inline void
vn_encode_VkSystemAllocationScope(struct vn_cs_encoder *enc, const VkSystemAllocationScope *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSystemAllocationScope(struct vn_cs_decoder *dec, VkSystemAllocationScope *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkInternalAllocationType */

static inline void
vn_encode_VkInternalAllocationType(struct vn_cs_encoder *enc, const VkInternalAllocationType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkInternalAllocationType(struct vn_cs_decoder *dec, VkInternalAllocationType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSamplerAddressMode */

static inline void
vn_encode_VkSamplerAddressMode(struct vn_cs_encoder *enc, const VkSamplerAddressMode *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerAddressMode(struct vn_cs_decoder *dec, VkSamplerAddressMode *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkFilter */

static inline void
vn_encode_VkFilter(struct vn_cs_encoder *enc, const VkFilter *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkFilter(struct vn_cs_decoder *dec, VkFilter *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSamplerMipmapMode */

static inline void
vn_encode_VkSamplerMipmapMode(struct vn_cs_encoder *enc, const VkSamplerMipmapMode *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerMipmapMode(struct vn_cs_decoder *dec, VkSamplerMipmapMode *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkVertexInputRate */

static inline void
vn_encode_VkVertexInputRate(struct vn_cs_encoder *enc, const VkVertexInputRate *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkVertexInputRate(struct vn_cs_decoder *dec, VkVertexInputRate *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkObjectType */

static inline void
vn_encode_VkObjectType(struct vn_cs_encoder *enc, const VkObjectType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkObjectType(struct vn_cs_decoder *dec, VkObjectType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDescriptorUpdateTemplateType */

static inline void
vn_encode_VkDescriptorUpdateTemplateType(struct vn_cs_encoder *enc, const VkDescriptorUpdateTemplateType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorUpdateTemplateType(struct vn_cs_decoder *dec, VkDescriptorUpdateTemplateType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkPointClippingBehavior */

static inline void
vn_encode_VkPointClippingBehavior(struct vn_cs_encoder *enc, const VkPointClippingBehavior *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkPointClippingBehavior(struct vn_cs_decoder *dec, VkPointClippingBehavior *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSemaphoreType */

static inline void
vn_encode_VkSemaphoreType(struct vn_cs_encoder *enc, const VkSemaphoreType *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSemaphoreType(struct vn_cs_decoder *dec, VkSemaphoreType *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkTessellationDomainOrigin */

static inline void
vn_encode_VkTessellationDomainOrigin(struct vn_cs_encoder *enc, const VkTessellationDomainOrigin *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkTessellationDomainOrigin(struct vn_cs_decoder *dec, VkTessellationDomainOrigin *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSamplerYcbcrModelConversion */

static inline void
vn_encode_VkSamplerYcbcrModelConversion(struct vn_cs_encoder *enc, const VkSamplerYcbcrModelConversion *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerYcbcrModelConversion(struct vn_cs_decoder *dec, VkSamplerYcbcrModelConversion *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSamplerYcbcrRange */

static inline void
vn_encode_VkSamplerYcbcrRange(struct vn_cs_encoder *enc, const VkSamplerYcbcrRange *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerYcbcrRange(struct vn_cs_decoder *dec, VkSamplerYcbcrRange *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkChromaLocation */

static inline void
vn_encode_VkChromaLocation(struct vn_cs_encoder *enc, const VkChromaLocation *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkChromaLocation(struct vn_cs_decoder *dec, VkChromaLocation *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkSamplerReductionMode */

static inline void
vn_encode_VkSamplerReductionMode(struct vn_cs_encoder *enc, const VkSamplerReductionMode *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerReductionMode(struct vn_cs_decoder *dec, VkSamplerReductionMode *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkShaderFloatControlsIndependence */

static inline void
vn_encode_VkShaderFloatControlsIndependence(struct vn_cs_encoder *enc, const VkShaderFloatControlsIndependence *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkShaderFloatControlsIndependence(struct vn_cs_decoder *dec, VkShaderFloatControlsIndependence *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkVendorId */

static inline void
vn_encode_VkVendorId(struct vn_cs_encoder *enc, const VkVendorId *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkVendorId(struct vn_cs_decoder *dec, VkVendorId *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkDriverId */

static inline void
vn_encode_VkDriverId(struct vn_cs_encoder *enc, const VkDriverId *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkDriverId(struct vn_cs_decoder *dec, VkDriverId *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCommandFlagBitsEXT */

static inline void
vn_encode_VkCommandFlagBitsEXT(struct vn_cs_encoder *enc, const VkCommandFlagBitsEXT *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandFlagBitsEXT(struct vn_cs_decoder *dec, VkCommandFlagBitsEXT *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

/* enum VkCommandTypeEXT */

static inline void
vn_encode_VkCommandTypeEXT(struct vn_cs_encoder *enc, const VkCommandTypeEXT *val)
{
    vn_encode_int32_t(enc, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandTypeEXT(struct vn_cs_decoder *dec, VkCommandTypeEXT *val)
{
    vn_decode_int32_t(dec, (int32_t *)val);
}

#endif /* VN_PROTOCOL_RENDERER_TYPES_H */
