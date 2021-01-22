/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_TYPES_H
#define VN_PROTOCOL_RENDERER_TYPES_H

#include "vn_protocol_renderer_defines.h"

/* uint64_t */

static inline void
vn_encode_uint64_t(struct vn_cs *cs, const uint64_t *val)
{
    vn_encode(cs, 8, val, sizeof(*val));
}

static inline void
vn_decode_uint64_t(struct vn_cs *cs, uint64_t *val)
{
    vn_decode(cs, 8, val, sizeof(*val));
}

static inline void
vn_encode_uint64_t_array(struct vn_cs *cs, const uint64_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(cs, size, val, size);
}

static inline void
vn_decode_uint64_t_array(struct vn_cs *cs, uint64_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(cs, size, val, size);
}

/* int32_t */

static inline void
vn_encode_int32_t(struct vn_cs *cs, const int32_t *val)
{
    vn_encode(cs, 4, val, sizeof(*val));
}

static inline void
vn_decode_int32_t(struct vn_cs *cs, int32_t *val)
{
    vn_decode(cs, 4, val, sizeof(*val));
}

static inline void
vn_encode_int32_t_array(struct vn_cs *cs, const int32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(cs, size, val, size);
}

static inline void
vn_decode_int32_t_array(struct vn_cs *cs, int32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(cs, size, val, size);
}

/* enum VkStructureType */

static inline void
vn_encode_VkStructureType(struct vn_cs *cs, const VkStructureType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkStructureType(struct vn_cs *cs, VkStructureType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* size_t */

static inline void
vn_encode_size_t(struct vn_cs *cs, const size_t *val)
{
    const uint64_t tmp = *val;
    vn_encode_uint64_t(cs, &tmp);
}

static inline void
vn_decode_size_t(struct vn_cs *cs, size_t *val)
{
    uint64_t tmp;
    vn_decode_uint64_t(cs, &tmp);
    *val = tmp;
}

static inline void
vn_encode_size_t_array(struct vn_cs *cs, const size_t *val, uint32_t count)
{
    if (sizeof(size_t) == sizeof(uint64_t)) {
        vn_encode_uint64_t_array(cs, (const uint64_t *)val, count);
    } else {
        for (uint32_t i = 0; i < count; i++)
            vn_encode_size_t(cs, &val[i]);
    }
}

static inline void
vn_decode_size_t_array(struct vn_cs *cs, size_t *val, uint32_t count)
{
    if (sizeof(size_t) == sizeof(uint64_t)) {
        vn_decode_uint64_t_array(cs, (uint64_t *)val, count);
    } else {
        for (uint32_t i = 0; i < count; i++)
            vn_decode_size_t(cs, &val[i]);
    }
}

/* opaque blob */

static inline void
vn_encode_blob_array(struct vn_cs *cs, const void *val, size_t size)
{
    vn_encode(cs, (size + 3) & ~3, val, size);
}

static inline void
vn_decode_blob_array(struct vn_cs *cs, void *val, size_t size)
{
    vn_decode(cs, (size + 3) & ~3, val, size);
}

/* array size (uint64_t) */

static inline void
vn_encode_array_size(struct vn_cs *cs, uint64_t size)
{
    vn_encode_uint64_t(cs, &size);
}

static inline uint64_t
vn_decode_array_size(struct vn_cs *cs, uint64_t max_size)
{
    uint64_t size;
    vn_decode_uint64_t(cs, &size);
    if (size > max_size) {
        vn_cs_set_error(cs);
        size = 0;
    }
    return size;
}

static inline uint64_t
vn_peek_array_size(struct vn_cs *cs)
{
    uint64_t size;
    vn_cs_in_peek(cs, &size, sizeof(size));
    return size;
}

/* non-array pointer */

static inline bool
vn_encode_simple_pointer(struct vn_cs *cs, const void *val)
{
    vn_encode_array_size(cs, val ? 1 : 0);
    return val;
}

static inline bool
vn_decode_simple_pointer(struct vn_cs *cs)
{
    return vn_decode_array_size(cs, 1);
}

/* uint32_t */

static inline void
vn_encode_uint32_t(struct vn_cs *cs, const uint32_t *val)
{
    vn_encode(cs, 4, val, sizeof(*val));
}

static inline void
vn_decode_uint32_t(struct vn_cs *cs, uint32_t *val)
{
    vn_decode(cs, 4, val, sizeof(*val));
}

static inline void
vn_encode_uint32_t_array(struct vn_cs *cs, const uint32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(cs, size, val, size);
}

static inline void
vn_decode_uint32_t_array(struct vn_cs *cs, uint32_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(cs, size, val, size);
}

/* float */

static inline void
vn_encode_float(struct vn_cs *cs, const float *val)
{
    vn_encode(cs, 4, val, sizeof(*val));
}

static inline void
vn_decode_float(struct vn_cs *cs, float *val)
{
    vn_decode(cs, 4, val, sizeof(*val));
}

static inline void
vn_encode_float_array(struct vn_cs *cs, const float *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(cs, size, val, size);
}

static inline void
vn_decode_float_array(struct vn_cs *cs, float *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(cs, size, val, size);
}

/* uint8_t */

static inline void
vn_encode_uint8_t(struct vn_cs *cs, const uint8_t *val)
{
    vn_encode(cs, 4, val, sizeof(*val));
}

static inline void
vn_decode_uint8_t(struct vn_cs *cs, uint8_t *val)
{
    vn_decode(cs, 4, val, sizeof(*val));
}

static inline void
vn_encode_uint8_t_array(struct vn_cs *cs, const uint8_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_encode(cs, (size + 3) & ~3, val, size);
}

static inline void
vn_decode_uint8_t_array(struct vn_cs *cs, uint8_t *val, uint32_t count)
{
    const size_t size = sizeof(*val) * count;
    assert(size >= count);
    vn_decode(cs, (size + 3) & ~3, val, size);
}

/* typedef uint32_t VkSampleMask */

static inline void
vn_encode_VkSampleMask(struct vn_cs *cs, const VkSampleMask *val)
{
    vn_encode_uint32_t(cs, val);
}

static inline void
vn_decode_VkSampleMask(struct vn_cs *cs, VkSampleMask *val)
{
    vn_decode_uint32_t(cs, val);
}

static inline void
vn_encode_VkSampleMask_array(struct vn_cs *cs, const VkSampleMask *val, uint32_t count)
{
    vn_encode_uint32_t_array(cs, val, count);
}

static inline void
vn_decode_VkSampleMask_array(struct vn_cs *cs, VkSampleMask *val, uint32_t count)
{
    vn_decode_uint32_t_array(cs, val, count);
}

/* typedef uint32_t VkBool32 */

static inline void
vn_encode_VkBool32(struct vn_cs *cs, const VkBool32 *val)
{
    vn_encode_uint32_t(cs, val);
}

static inline void
vn_decode_VkBool32(struct vn_cs *cs, VkBool32 *val)
{
    vn_decode_uint32_t(cs, val);
}

static inline void
vn_encode_VkBool32_array(struct vn_cs *cs, const VkBool32 *val, uint32_t count)
{
    vn_encode_uint32_t_array(cs, val, count);
}

static inline void
vn_decode_VkBool32_array(struct vn_cs *cs, VkBool32 *val, uint32_t count)
{
    vn_decode_uint32_t_array(cs, val, count);
}

/* typedef uint32_t VkFlags */

static inline void
vn_encode_VkFlags(struct vn_cs *cs, const VkFlags *val)
{
    vn_encode_uint32_t(cs, val);
}

static inline void
vn_decode_VkFlags(struct vn_cs *cs, VkFlags *val)
{
    vn_decode_uint32_t(cs, val);
}

static inline void
vn_encode_VkFlags_array(struct vn_cs *cs, const VkFlags *val, uint32_t count)
{
    vn_encode_uint32_t_array(cs, val, count);
}

static inline void
vn_decode_VkFlags_array(struct vn_cs *cs, VkFlags *val, uint32_t count)
{
    vn_decode_uint32_t_array(cs, val, count);
}

/* typedef uint64_t VkDeviceSize */

static inline void
vn_encode_VkDeviceSize(struct vn_cs *cs, const VkDeviceSize *val)
{
    vn_encode_uint64_t(cs, val);
}

static inline void
vn_decode_VkDeviceSize(struct vn_cs *cs, VkDeviceSize *val)
{
    vn_decode_uint64_t(cs, val);
}

static inline void
vn_encode_VkDeviceSize_array(struct vn_cs *cs, const VkDeviceSize *val, uint32_t count)
{
    vn_encode_uint64_t_array(cs, val, count);
}

static inline void
vn_decode_VkDeviceSize_array(struct vn_cs *cs, VkDeviceSize *val, uint32_t count)
{
    vn_decode_uint64_t_array(cs, val, count);
}

/* typedef uint64_t VkDeviceAddress */

static inline void
vn_encode_VkDeviceAddress(struct vn_cs *cs, const VkDeviceAddress *val)
{
    vn_encode_uint64_t(cs, val);
}

static inline void
vn_decode_VkDeviceAddress(struct vn_cs *cs, VkDeviceAddress *val)
{
    vn_decode_uint64_t(cs, val);
}

static inline void
vn_encode_VkDeviceAddress_array(struct vn_cs *cs, const VkDeviceAddress *val, uint32_t count)
{
    vn_encode_uint64_t_array(cs, val, count);
}

static inline void
vn_decode_VkDeviceAddress_array(struct vn_cs *cs, VkDeviceAddress *val, uint32_t count)
{
    vn_decode_uint64_t_array(cs, val, count);
}

/* enum VkFramebufferCreateFlagBits */

static inline void
vn_encode_VkFramebufferCreateFlagBits(struct vn_cs *cs, const VkFramebufferCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkFramebufferCreateFlagBits(struct vn_cs *cs, VkFramebufferCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkRenderPassCreateFlagBits */

static inline void
vn_encode_VkRenderPassCreateFlagBits(struct vn_cs *cs, const VkRenderPassCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkRenderPassCreateFlagBits(struct vn_cs *cs, VkRenderPassCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSamplerCreateFlagBits */

static inline void
vn_encode_VkSamplerCreateFlagBits(struct vn_cs *cs, const VkSamplerCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerCreateFlagBits(struct vn_cs *cs, VkSamplerCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPipelineCacheCreateFlagBits */

static inline void
vn_encode_VkPipelineCacheCreateFlagBits(struct vn_cs *cs, const VkPipelineCacheCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineCacheCreateFlagBits(struct vn_cs *cs, VkPipelineCacheCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPipelineShaderStageCreateFlagBits */

static inline void
vn_encode_VkPipelineShaderStageCreateFlagBits(struct vn_cs *cs, const VkPipelineShaderStageCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineShaderStageCreateFlagBits(struct vn_cs *cs, VkPipelineShaderStageCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDescriptorSetLayoutCreateFlagBits */

static inline void
vn_encode_VkDescriptorSetLayoutCreateFlagBits(struct vn_cs *cs, const VkDescriptorSetLayoutCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorSetLayoutCreateFlagBits(struct vn_cs *cs, VkDescriptorSetLayoutCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDeviceQueueCreateFlagBits */

static inline void
vn_encode_VkDeviceQueueCreateFlagBits(struct vn_cs *cs, const VkDeviceQueueCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDeviceQueueCreateFlagBits(struct vn_cs *cs, VkDeviceQueueCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkQueueFlagBits */

static inline void
vn_encode_VkQueueFlagBits(struct vn_cs *cs, const VkQueueFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkQueueFlagBits(struct vn_cs *cs, VkQueueFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkMemoryPropertyFlagBits */

static inline void
vn_encode_VkMemoryPropertyFlagBits(struct vn_cs *cs, const VkMemoryPropertyFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkMemoryPropertyFlagBits(struct vn_cs *cs, VkMemoryPropertyFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkMemoryHeapFlagBits */

static inline void
vn_encode_VkMemoryHeapFlagBits(struct vn_cs *cs, const VkMemoryHeapFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkMemoryHeapFlagBits(struct vn_cs *cs, VkMemoryHeapFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkAccessFlagBits */

static inline void
vn_encode_VkAccessFlagBits(struct vn_cs *cs, const VkAccessFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkAccessFlagBits(struct vn_cs *cs, VkAccessFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkBufferUsageFlagBits */

static inline void
vn_encode_VkBufferUsageFlagBits(struct vn_cs *cs, const VkBufferUsageFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkBufferUsageFlagBits(struct vn_cs *cs, VkBufferUsageFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkBufferCreateFlagBits */

static inline void
vn_encode_VkBufferCreateFlagBits(struct vn_cs *cs, const VkBufferCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkBufferCreateFlagBits(struct vn_cs *cs, VkBufferCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkShaderStageFlagBits */

static inline void
vn_encode_VkShaderStageFlagBits(struct vn_cs *cs, const VkShaderStageFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkShaderStageFlagBits(struct vn_cs *cs, VkShaderStageFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageUsageFlagBits */

static inline void
vn_encode_VkImageUsageFlagBits(struct vn_cs *cs, const VkImageUsageFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageUsageFlagBits(struct vn_cs *cs, VkImageUsageFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageCreateFlagBits */

static inline void
vn_encode_VkImageCreateFlagBits(struct vn_cs *cs, const VkImageCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageCreateFlagBits(struct vn_cs *cs, VkImageCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageViewCreateFlagBits */

static inline void
vn_encode_VkImageViewCreateFlagBits(struct vn_cs *cs, const VkImageViewCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageViewCreateFlagBits(struct vn_cs *cs, VkImageViewCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPipelineCreateFlagBits */

static inline void
vn_encode_VkPipelineCreateFlagBits(struct vn_cs *cs, const VkPipelineCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineCreateFlagBits(struct vn_cs *cs, VkPipelineCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkColorComponentFlagBits */

static inline void
vn_encode_VkColorComponentFlagBits(struct vn_cs *cs, const VkColorComponentFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkColorComponentFlagBits(struct vn_cs *cs, VkColorComponentFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkFenceCreateFlagBits */

static inline void
vn_encode_VkFenceCreateFlagBits(struct vn_cs *cs, const VkFenceCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkFenceCreateFlagBits(struct vn_cs *cs, VkFenceCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkFormatFeatureFlagBits */

static inline void
vn_encode_VkFormatFeatureFlagBits(struct vn_cs *cs, const VkFormatFeatureFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkFormatFeatureFlagBits(struct vn_cs *cs, VkFormatFeatureFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkQueryControlFlagBits */

static inline void
vn_encode_VkQueryControlFlagBits(struct vn_cs *cs, const VkQueryControlFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryControlFlagBits(struct vn_cs *cs, VkQueryControlFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkQueryResultFlagBits */

static inline void
vn_encode_VkQueryResultFlagBits(struct vn_cs *cs, const VkQueryResultFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryResultFlagBits(struct vn_cs *cs, VkQueryResultFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCommandPoolCreateFlagBits */

static inline void
vn_encode_VkCommandPoolCreateFlagBits(struct vn_cs *cs, const VkCommandPoolCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandPoolCreateFlagBits(struct vn_cs *cs, VkCommandPoolCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCommandPoolResetFlagBits */

static inline void
vn_encode_VkCommandPoolResetFlagBits(struct vn_cs *cs, const VkCommandPoolResetFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandPoolResetFlagBits(struct vn_cs *cs, VkCommandPoolResetFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCommandBufferResetFlagBits */

static inline void
vn_encode_VkCommandBufferResetFlagBits(struct vn_cs *cs, const VkCommandBufferResetFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandBufferResetFlagBits(struct vn_cs *cs, VkCommandBufferResetFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCommandBufferUsageFlagBits */

static inline void
vn_encode_VkCommandBufferUsageFlagBits(struct vn_cs *cs, const VkCommandBufferUsageFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandBufferUsageFlagBits(struct vn_cs *cs, VkCommandBufferUsageFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkQueryPipelineStatisticFlagBits */

static inline void
vn_encode_VkQueryPipelineStatisticFlagBits(struct vn_cs *cs, const VkQueryPipelineStatisticFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryPipelineStatisticFlagBits(struct vn_cs *cs, VkQueryPipelineStatisticFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageAspectFlagBits */

static inline void
vn_encode_VkImageAspectFlagBits(struct vn_cs *cs, const VkImageAspectFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageAspectFlagBits(struct vn_cs *cs, VkImageAspectFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSparseMemoryBindFlagBits */

static inline void
vn_encode_VkSparseMemoryBindFlagBits(struct vn_cs *cs, const VkSparseMemoryBindFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSparseMemoryBindFlagBits(struct vn_cs *cs, VkSparseMemoryBindFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSparseImageFormatFlagBits */

static inline void
vn_encode_VkSparseImageFormatFlagBits(struct vn_cs *cs, const VkSparseImageFormatFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSparseImageFormatFlagBits(struct vn_cs *cs, VkSparseImageFormatFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSubpassDescriptionFlagBits */

static inline void
vn_encode_VkSubpassDescriptionFlagBits(struct vn_cs *cs, const VkSubpassDescriptionFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSubpassDescriptionFlagBits(struct vn_cs *cs, VkSubpassDescriptionFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPipelineStageFlagBits */

static inline void
vn_encode_VkPipelineStageFlagBits(struct vn_cs *cs, const VkPipelineStageFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineStageFlagBits(struct vn_cs *cs, VkPipelineStageFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSampleCountFlagBits */

static inline void
vn_encode_VkSampleCountFlagBits(struct vn_cs *cs, const VkSampleCountFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSampleCountFlagBits(struct vn_cs *cs, VkSampleCountFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkAttachmentDescriptionFlagBits */

static inline void
vn_encode_VkAttachmentDescriptionFlagBits(struct vn_cs *cs, const VkAttachmentDescriptionFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkAttachmentDescriptionFlagBits(struct vn_cs *cs, VkAttachmentDescriptionFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkStencilFaceFlagBits */

static inline void
vn_encode_VkStencilFaceFlagBits(struct vn_cs *cs, const VkStencilFaceFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkStencilFaceFlagBits(struct vn_cs *cs, VkStencilFaceFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCullModeFlagBits */

static inline void
vn_encode_VkCullModeFlagBits(struct vn_cs *cs, const VkCullModeFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCullModeFlagBits(struct vn_cs *cs, VkCullModeFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDescriptorPoolCreateFlagBits */

static inline void
vn_encode_VkDescriptorPoolCreateFlagBits(struct vn_cs *cs, const VkDescriptorPoolCreateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorPoolCreateFlagBits(struct vn_cs *cs, VkDescriptorPoolCreateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDependencyFlagBits */

static inline void
vn_encode_VkDependencyFlagBits(struct vn_cs *cs, const VkDependencyFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDependencyFlagBits(struct vn_cs *cs, VkDependencyFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSubgroupFeatureFlagBits */

static inline void
vn_encode_VkSubgroupFeatureFlagBits(struct vn_cs *cs, const VkSubgroupFeatureFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSubgroupFeatureFlagBits(struct vn_cs *cs, VkSubgroupFeatureFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSemaphoreWaitFlagBits */

static inline void
vn_encode_VkSemaphoreWaitFlagBits(struct vn_cs *cs, const VkSemaphoreWaitFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSemaphoreWaitFlagBits(struct vn_cs *cs, VkSemaphoreWaitFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPeerMemoryFeatureFlagBits */

static inline void
vn_encode_VkPeerMemoryFeatureFlagBits(struct vn_cs *cs, const VkPeerMemoryFeatureFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPeerMemoryFeatureFlagBits(struct vn_cs *cs, VkPeerMemoryFeatureFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkMemoryAllocateFlagBits */

static inline void
vn_encode_VkMemoryAllocateFlagBits(struct vn_cs *cs, const VkMemoryAllocateFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkMemoryAllocateFlagBits(struct vn_cs *cs, VkMemoryAllocateFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkExternalMemoryHandleTypeFlagBits */

static inline void
vn_encode_VkExternalMemoryHandleTypeFlagBits(struct vn_cs *cs, const VkExternalMemoryHandleTypeFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalMemoryHandleTypeFlagBits(struct vn_cs *cs, VkExternalMemoryHandleTypeFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkExternalMemoryFeatureFlagBits */

static inline void
vn_encode_VkExternalMemoryFeatureFlagBits(struct vn_cs *cs, const VkExternalMemoryFeatureFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalMemoryFeatureFlagBits(struct vn_cs *cs, VkExternalMemoryFeatureFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkExternalSemaphoreHandleTypeFlagBits */

static inline void
vn_encode_VkExternalSemaphoreHandleTypeFlagBits(struct vn_cs *cs, const VkExternalSemaphoreHandleTypeFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalSemaphoreHandleTypeFlagBits(struct vn_cs *cs, VkExternalSemaphoreHandleTypeFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkExternalSemaphoreFeatureFlagBits */

static inline void
vn_encode_VkExternalSemaphoreFeatureFlagBits(struct vn_cs *cs, const VkExternalSemaphoreFeatureFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalSemaphoreFeatureFlagBits(struct vn_cs *cs, VkExternalSemaphoreFeatureFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSemaphoreImportFlagBits */

static inline void
vn_encode_VkSemaphoreImportFlagBits(struct vn_cs *cs, const VkSemaphoreImportFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSemaphoreImportFlagBits(struct vn_cs *cs, VkSemaphoreImportFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkExternalFenceHandleTypeFlagBits */

static inline void
vn_encode_VkExternalFenceHandleTypeFlagBits(struct vn_cs *cs, const VkExternalFenceHandleTypeFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalFenceHandleTypeFlagBits(struct vn_cs *cs, VkExternalFenceHandleTypeFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkExternalFenceFeatureFlagBits */

static inline void
vn_encode_VkExternalFenceFeatureFlagBits(struct vn_cs *cs, const VkExternalFenceFeatureFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkExternalFenceFeatureFlagBits(struct vn_cs *cs, VkExternalFenceFeatureFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkFenceImportFlagBits */

static inline void
vn_encode_VkFenceImportFlagBits(struct vn_cs *cs, const VkFenceImportFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkFenceImportFlagBits(struct vn_cs *cs, VkFenceImportFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDescriptorBindingFlagBits */

static inline void
vn_encode_VkDescriptorBindingFlagBits(struct vn_cs *cs, const VkDescriptorBindingFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorBindingFlagBits(struct vn_cs *cs, VkDescriptorBindingFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkResolveModeFlagBits */

static inline void
vn_encode_VkResolveModeFlagBits(struct vn_cs *cs, const VkResolveModeFlagBits *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkResolveModeFlagBits(struct vn_cs *cs, VkResolveModeFlagBits *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkAttachmentLoadOp */

static inline void
vn_encode_VkAttachmentLoadOp(struct vn_cs *cs, const VkAttachmentLoadOp *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkAttachmentLoadOp(struct vn_cs *cs, VkAttachmentLoadOp *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkAttachmentStoreOp */

static inline void
vn_encode_VkAttachmentStoreOp(struct vn_cs *cs, const VkAttachmentStoreOp *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkAttachmentStoreOp(struct vn_cs *cs, VkAttachmentStoreOp *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkBlendFactor */

static inline void
vn_encode_VkBlendFactor(struct vn_cs *cs, const VkBlendFactor *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkBlendFactor(struct vn_cs *cs, VkBlendFactor *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkBlendOp */

static inline void
vn_encode_VkBlendOp(struct vn_cs *cs, const VkBlendOp *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkBlendOp(struct vn_cs *cs, VkBlendOp *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkBorderColor */

static inline void
vn_encode_VkBorderColor(struct vn_cs *cs, const VkBorderColor *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkBorderColor(struct vn_cs *cs, VkBorderColor *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPipelineCacheHeaderVersion */

static inline void
vn_encode_VkPipelineCacheHeaderVersion(struct vn_cs *cs, const VkPipelineCacheHeaderVersion *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineCacheHeaderVersion(struct vn_cs *cs, VkPipelineCacheHeaderVersion *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkComponentSwizzle */

static inline void
vn_encode_VkComponentSwizzle(struct vn_cs *cs, const VkComponentSwizzle *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkComponentSwizzle(struct vn_cs *cs, VkComponentSwizzle *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCommandBufferLevel */

static inline void
vn_encode_VkCommandBufferLevel(struct vn_cs *cs, const VkCommandBufferLevel *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandBufferLevel(struct vn_cs *cs, VkCommandBufferLevel *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCompareOp */

static inline void
vn_encode_VkCompareOp(struct vn_cs *cs, const VkCompareOp *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCompareOp(struct vn_cs *cs, VkCompareOp *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDescriptorType */

static inline void
vn_encode_VkDescriptorType(struct vn_cs *cs, const VkDescriptorType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorType(struct vn_cs *cs, VkDescriptorType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

static inline void
vn_encode_VkDescriptorType_array(struct vn_cs *cs, const VkDescriptorType *val, uint32_t count)
{
    vn_encode_int32_t_array(cs, (const int32_t *)val, count);
}

static inline void
vn_decode_VkDescriptorType_array(struct vn_cs *cs, VkDescriptorType *val, uint32_t count)
{
    vn_decode_int32_t_array(cs, (int32_t *)val, count);
}

/* enum VkDynamicState */

static inline void
vn_encode_VkDynamicState(struct vn_cs *cs, const VkDynamicState *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDynamicState(struct vn_cs *cs, VkDynamicState *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

static inline void
vn_encode_VkDynamicState_array(struct vn_cs *cs, const VkDynamicState *val, uint32_t count)
{
    vn_encode_int32_t_array(cs, (const int32_t *)val, count);
}

static inline void
vn_decode_VkDynamicState_array(struct vn_cs *cs, VkDynamicState *val, uint32_t count)
{
    vn_decode_int32_t_array(cs, (int32_t *)val, count);
}

/* enum VkPolygonMode */

static inline void
vn_encode_VkPolygonMode(struct vn_cs *cs, const VkPolygonMode *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPolygonMode(struct vn_cs *cs, VkPolygonMode *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkFormat */

static inline void
vn_encode_VkFormat(struct vn_cs *cs, const VkFormat *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkFormat(struct vn_cs *cs, VkFormat *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

static inline void
vn_encode_VkFormat_array(struct vn_cs *cs, const VkFormat *val, uint32_t count)
{
    vn_encode_int32_t_array(cs, (const int32_t *)val, count);
}

static inline void
vn_decode_VkFormat_array(struct vn_cs *cs, VkFormat *val, uint32_t count)
{
    vn_decode_int32_t_array(cs, (int32_t *)val, count);
}

/* enum VkFrontFace */

static inline void
vn_encode_VkFrontFace(struct vn_cs *cs, const VkFrontFace *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkFrontFace(struct vn_cs *cs, VkFrontFace *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageLayout */

static inline void
vn_encode_VkImageLayout(struct vn_cs *cs, const VkImageLayout *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageLayout(struct vn_cs *cs, VkImageLayout *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageTiling */

static inline void
vn_encode_VkImageTiling(struct vn_cs *cs, const VkImageTiling *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageTiling(struct vn_cs *cs, VkImageTiling *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageType */

static inline void
vn_encode_VkImageType(struct vn_cs *cs, const VkImageType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageType(struct vn_cs *cs, VkImageType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkImageViewType */

static inline void
vn_encode_VkImageViewType(struct vn_cs *cs, const VkImageViewType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkImageViewType(struct vn_cs *cs, VkImageViewType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSharingMode */

static inline void
vn_encode_VkSharingMode(struct vn_cs *cs, const VkSharingMode *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSharingMode(struct vn_cs *cs, VkSharingMode *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkIndexType */

static inline void
vn_encode_VkIndexType(struct vn_cs *cs, const VkIndexType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkIndexType(struct vn_cs *cs, VkIndexType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

static inline void
vn_encode_VkIndexType_array(struct vn_cs *cs, const VkIndexType *val, uint32_t count)
{
    vn_encode_int32_t_array(cs, (const int32_t *)val, count);
}

static inline void
vn_decode_VkIndexType_array(struct vn_cs *cs, VkIndexType *val, uint32_t count)
{
    vn_decode_int32_t_array(cs, (int32_t *)val, count);
}

/* enum VkLogicOp */

static inline void
vn_encode_VkLogicOp(struct vn_cs *cs, const VkLogicOp *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkLogicOp(struct vn_cs *cs, VkLogicOp *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPhysicalDeviceType */

static inline void
vn_encode_VkPhysicalDeviceType(struct vn_cs *cs, const VkPhysicalDeviceType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPhysicalDeviceType(struct vn_cs *cs, VkPhysicalDeviceType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPipelineBindPoint */

static inline void
vn_encode_VkPipelineBindPoint(struct vn_cs *cs, const VkPipelineBindPoint *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPipelineBindPoint(struct vn_cs *cs, VkPipelineBindPoint *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPrimitiveTopology */

static inline void
vn_encode_VkPrimitiveTopology(struct vn_cs *cs, const VkPrimitiveTopology *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPrimitiveTopology(struct vn_cs *cs, VkPrimitiveTopology *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkQueryType */

static inline void
vn_encode_VkQueryType(struct vn_cs *cs, const VkQueryType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkQueryType(struct vn_cs *cs, VkQueryType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSubpassContents */

static inline void
vn_encode_VkSubpassContents(struct vn_cs *cs, const VkSubpassContents *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSubpassContents(struct vn_cs *cs, VkSubpassContents *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkResult */

static inline void
vn_encode_VkResult(struct vn_cs *cs, const VkResult *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkResult(struct vn_cs *cs, VkResult *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

static inline void
vn_encode_VkResult_array(struct vn_cs *cs, const VkResult *val, uint32_t count)
{
    vn_encode_int32_t_array(cs, (const int32_t *)val, count);
}

static inline void
vn_decode_VkResult_array(struct vn_cs *cs, VkResult *val, uint32_t count)
{
    vn_decode_int32_t_array(cs, (int32_t *)val, count);
}

/* enum VkStencilOp */

static inline void
vn_encode_VkStencilOp(struct vn_cs *cs, const VkStencilOp *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkStencilOp(struct vn_cs *cs, VkStencilOp *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSystemAllocationScope */

static inline void
vn_encode_VkSystemAllocationScope(struct vn_cs *cs, const VkSystemAllocationScope *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSystemAllocationScope(struct vn_cs *cs, VkSystemAllocationScope *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkInternalAllocationType */

static inline void
vn_encode_VkInternalAllocationType(struct vn_cs *cs, const VkInternalAllocationType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkInternalAllocationType(struct vn_cs *cs, VkInternalAllocationType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSamplerAddressMode */

static inline void
vn_encode_VkSamplerAddressMode(struct vn_cs *cs, const VkSamplerAddressMode *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerAddressMode(struct vn_cs *cs, VkSamplerAddressMode *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkFilter */

static inline void
vn_encode_VkFilter(struct vn_cs *cs, const VkFilter *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkFilter(struct vn_cs *cs, VkFilter *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSamplerMipmapMode */

static inline void
vn_encode_VkSamplerMipmapMode(struct vn_cs *cs, const VkSamplerMipmapMode *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerMipmapMode(struct vn_cs *cs, VkSamplerMipmapMode *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkVertexInputRate */

static inline void
vn_encode_VkVertexInputRate(struct vn_cs *cs, const VkVertexInputRate *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkVertexInputRate(struct vn_cs *cs, VkVertexInputRate *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkObjectType */

static inline void
vn_encode_VkObjectType(struct vn_cs *cs, const VkObjectType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkObjectType(struct vn_cs *cs, VkObjectType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDescriptorUpdateTemplateType */

static inline void
vn_encode_VkDescriptorUpdateTemplateType(struct vn_cs *cs, const VkDescriptorUpdateTemplateType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDescriptorUpdateTemplateType(struct vn_cs *cs, VkDescriptorUpdateTemplateType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkPointClippingBehavior */

static inline void
vn_encode_VkPointClippingBehavior(struct vn_cs *cs, const VkPointClippingBehavior *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkPointClippingBehavior(struct vn_cs *cs, VkPointClippingBehavior *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSemaphoreType */

static inline void
vn_encode_VkSemaphoreType(struct vn_cs *cs, const VkSemaphoreType *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSemaphoreType(struct vn_cs *cs, VkSemaphoreType *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkTessellationDomainOrigin */

static inline void
vn_encode_VkTessellationDomainOrigin(struct vn_cs *cs, const VkTessellationDomainOrigin *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkTessellationDomainOrigin(struct vn_cs *cs, VkTessellationDomainOrigin *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSamplerYcbcrModelConversion */

static inline void
vn_encode_VkSamplerYcbcrModelConversion(struct vn_cs *cs, const VkSamplerYcbcrModelConversion *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerYcbcrModelConversion(struct vn_cs *cs, VkSamplerYcbcrModelConversion *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSamplerYcbcrRange */

static inline void
vn_encode_VkSamplerYcbcrRange(struct vn_cs *cs, const VkSamplerYcbcrRange *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerYcbcrRange(struct vn_cs *cs, VkSamplerYcbcrRange *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkChromaLocation */

static inline void
vn_encode_VkChromaLocation(struct vn_cs *cs, const VkChromaLocation *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkChromaLocation(struct vn_cs *cs, VkChromaLocation *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkSamplerReductionMode */

static inline void
vn_encode_VkSamplerReductionMode(struct vn_cs *cs, const VkSamplerReductionMode *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkSamplerReductionMode(struct vn_cs *cs, VkSamplerReductionMode *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkShaderFloatControlsIndependence */

static inline void
vn_encode_VkShaderFloatControlsIndependence(struct vn_cs *cs, const VkShaderFloatControlsIndependence *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkShaderFloatControlsIndependence(struct vn_cs *cs, VkShaderFloatControlsIndependence *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkVendorId */

static inline void
vn_encode_VkVendorId(struct vn_cs *cs, const VkVendorId *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkVendorId(struct vn_cs *cs, VkVendorId *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkDriverId */

static inline void
vn_encode_VkDriverId(struct vn_cs *cs, const VkDriverId *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkDriverId(struct vn_cs *cs, VkDriverId *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCommandFlagBitsEXT */

static inline void
vn_encode_VkCommandFlagBitsEXT(struct vn_cs *cs, const VkCommandFlagBitsEXT *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandFlagBitsEXT(struct vn_cs *cs, VkCommandFlagBitsEXT *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

/* enum VkCommandTypeEXT */

static inline void
vn_encode_VkCommandTypeEXT(struct vn_cs *cs, const VkCommandTypeEXT *val)
{
    vn_encode_int32_t(cs, (const int32_t *)val);
}

static inline void
vn_decode_VkCommandTypeEXT(struct vn_cs *cs, VkCommandTypeEXT *val)
{
    vn_decode_int32_t(cs, (int32_t *)val);
}

#endif /* VN_PROTOCOL_RENDERER_TYPES_H */
