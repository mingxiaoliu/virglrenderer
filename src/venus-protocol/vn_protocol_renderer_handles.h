/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_HANDLES_H
#define VN_PROTOCOL_RENDERER_HANDLES_H

#include "vn_protocol_renderer_types.h"

/* VK_DEFINE_HANDLE(VkInstance) */

static inline void
vn_encode_VkInstance(struct vn_cs *cs, const VkInstance *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkInstance_temp(struct vn_cs *cs, VkInstance *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    if (!in_place) {
        *val = vn_cs_alloc_temp(cs, sizeof(vn_cs_object_id));
        if (!val)
            return;
    }
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkInstance_lookup(struct vn_cs *cs, VkInstance *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkInstance)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkInstance_handle(VkInstance *val)
{
    *val = (VkInstance)(uintptr_t)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_HANDLE(VkPhysicalDevice) */

static inline void
vn_encode_VkPhysicalDevice(struct vn_cs *cs, const VkPhysicalDevice *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkPhysicalDevice_temp(struct vn_cs *cs, VkPhysicalDevice *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    if (!in_place) {
        *val = vn_cs_alloc_temp(cs, sizeof(vn_cs_object_id));
        if (!val)
            return;
    }
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkPhysicalDevice_lookup(struct vn_cs *cs, VkPhysicalDevice *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkPhysicalDevice)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkPhysicalDevice_handle(VkPhysicalDevice *val)
{
    *val = (VkPhysicalDevice)(uintptr_t)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_HANDLE(VkDevice) */

static inline void
vn_encode_VkDevice(struct vn_cs *cs, const VkDevice *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkDevice_temp(struct vn_cs *cs, VkDevice *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    if (!in_place) {
        *val = vn_cs_alloc_temp(cs, sizeof(vn_cs_object_id));
        if (!val)
            return;
    }
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkDevice_lookup(struct vn_cs *cs, VkDevice *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkDevice)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkDevice_handle(VkDevice *val)
{
    *val = (VkDevice)(uintptr_t)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_HANDLE(VkQueue) */

static inline void
vn_encode_VkQueue(struct vn_cs *cs, const VkQueue *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkQueue_temp(struct vn_cs *cs, VkQueue *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    if (!in_place) {
        *val = vn_cs_alloc_temp(cs, sizeof(vn_cs_object_id));
        if (!val)
            return;
    }
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkQueue_lookup(struct vn_cs *cs, VkQueue *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkQueue)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkQueue_handle(VkQueue *val)
{
    *val = (VkQueue)(uintptr_t)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_HANDLE(VkCommandBuffer) */

static inline void
vn_encode_VkCommandBuffer(struct vn_cs *cs, const VkCommandBuffer *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkCommandBuffer_temp(struct vn_cs *cs, VkCommandBuffer *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    if (!in_place) {
        *val = vn_cs_alloc_temp(cs, sizeof(vn_cs_object_id));
        if (!val)
            return;
    }
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkCommandBuffer_lookup(struct vn_cs *cs, VkCommandBuffer *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkCommandBuffer)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkCommandBuffer_handle(VkCommandBuffer *val)
{
    *val = (VkCommandBuffer)(uintptr_t)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDeviceMemory) */

static inline void
vn_encode_VkDeviceMemory(struct vn_cs *cs, const VkDeviceMemory *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkDeviceMemory(struct vn_cs *cs, VkDeviceMemory *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkDeviceMemory_lookup(struct vn_cs *cs, VkDeviceMemory *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkDeviceMemory)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkDeviceMemory_handle(VkDeviceMemory *val)
{
    *val = (VkDeviceMemory)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkCommandPool) */

static inline void
vn_encode_VkCommandPool(struct vn_cs *cs, const VkCommandPool *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkCommandPool(struct vn_cs *cs, VkCommandPool *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkCommandPool_lookup(struct vn_cs *cs, VkCommandPool *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkCommandPool)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkCommandPool_handle(VkCommandPool *val)
{
    *val = (VkCommandPool)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkBuffer) */

static inline void
vn_encode_VkBuffer(struct vn_cs *cs, const VkBuffer *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkBuffer(struct vn_cs *cs, VkBuffer *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkBuffer_lookup(struct vn_cs *cs, VkBuffer *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkBuffer)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkBuffer_handle(VkBuffer *val)
{
    *val = (VkBuffer)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkBufferView) */

static inline void
vn_encode_VkBufferView(struct vn_cs *cs, const VkBufferView *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkBufferView(struct vn_cs *cs, VkBufferView *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkBufferView_lookup(struct vn_cs *cs, VkBufferView *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkBufferView)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkBufferView_handle(VkBufferView *val)
{
    *val = (VkBufferView)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkImage) */

static inline void
vn_encode_VkImage(struct vn_cs *cs, const VkImage *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkImage(struct vn_cs *cs, VkImage *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkImage_lookup(struct vn_cs *cs, VkImage *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkImage)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkImage_handle(VkImage *val)
{
    *val = (VkImage)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkImageView) */

static inline void
vn_encode_VkImageView(struct vn_cs *cs, const VkImageView *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkImageView(struct vn_cs *cs, VkImageView *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkImageView_lookup(struct vn_cs *cs, VkImageView *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkImageView)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkImageView_handle(VkImageView *val)
{
    *val = (VkImageView)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkShaderModule) */

static inline void
vn_encode_VkShaderModule(struct vn_cs *cs, const VkShaderModule *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkShaderModule(struct vn_cs *cs, VkShaderModule *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkShaderModule_lookup(struct vn_cs *cs, VkShaderModule *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkShaderModule)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkShaderModule_handle(VkShaderModule *val)
{
    *val = (VkShaderModule)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkPipeline) */

static inline void
vn_encode_VkPipeline(struct vn_cs *cs, const VkPipeline *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkPipeline(struct vn_cs *cs, VkPipeline *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkPipeline_lookup(struct vn_cs *cs, VkPipeline *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkPipeline)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkPipeline_handle(VkPipeline *val)
{
    *val = (VkPipeline)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkPipelineLayout) */

static inline void
vn_encode_VkPipelineLayout(struct vn_cs *cs, const VkPipelineLayout *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkPipelineLayout(struct vn_cs *cs, VkPipelineLayout *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkPipelineLayout_lookup(struct vn_cs *cs, VkPipelineLayout *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkPipelineLayout)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkPipelineLayout_handle(VkPipelineLayout *val)
{
    *val = (VkPipelineLayout)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkSampler) */

static inline void
vn_encode_VkSampler(struct vn_cs *cs, const VkSampler *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkSampler(struct vn_cs *cs, VkSampler *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkSampler_lookup(struct vn_cs *cs, VkSampler *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkSampler)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkSampler_handle(VkSampler *val)
{
    *val = (VkSampler)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDescriptorSet) */

static inline void
vn_encode_VkDescriptorSet(struct vn_cs *cs, const VkDescriptorSet *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkDescriptorSet(struct vn_cs *cs, VkDescriptorSet *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkDescriptorSet_lookup(struct vn_cs *cs, VkDescriptorSet *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkDescriptorSet)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkDescriptorSet_handle(VkDescriptorSet *val)
{
    *val = (VkDescriptorSet)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDescriptorSetLayout) */

static inline void
vn_encode_VkDescriptorSetLayout(struct vn_cs *cs, const VkDescriptorSetLayout *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkDescriptorSetLayout(struct vn_cs *cs, VkDescriptorSetLayout *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkDescriptorSetLayout_lookup(struct vn_cs *cs, VkDescriptorSetLayout *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkDescriptorSetLayout)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkDescriptorSetLayout_handle(VkDescriptorSetLayout *val)
{
    *val = (VkDescriptorSetLayout)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDescriptorPool) */

static inline void
vn_encode_VkDescriptorPool(struct vn_cs *cs, const VkDescriptorPool *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkDescriptorPool(struct vn_cs *cs, VkDescriptorPool *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkDescriptorPool_lookup(struct vn_cs *cs, VkDescriptorPool *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkDescriptorPool)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkDescriptorPool_handle(VkDescriptorPool *val)
{
    *val = (VkDescriptorPool)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkFence) */

static inline void
vn_encode_VkFence(struct vn_cs *cs, const VkFence *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkFence(struct vn_cs *cs, VkFence *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkFence_lookup(struct vn_cs *cs, VkFence *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkFence)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkFence_handle(VkFence *val)
{
    *val = (VkFence)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkSemaphore) */

static inline void
vn_encode_VkSemaphore(struct vn_cs *cs, const VkSemaphore *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkSemaphore(struct vn_cs *cs, VkSemaphore *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkSemaphore_lookup(struct vn_cs *cs, VkSemaphore *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkSemaphore)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkSemaphore_handle(VkSemaphore *val)
{
    *val = (VkSemaphore)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkEvent) */

static inline void
vn_encode_VkEvent(struct vn_cs *cs, const VkEvent *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkEvent(struct vn_cs *cs, VkEvent *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkEvent_lookup(struct vn_cs *cs, VkEvent *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkEvent)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkEvent_handle(VkEvent *val)
{
    *val = (VkEvent)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkQueryPool) */

static inline void
vn_encode_VkQueryPool(struct vn_cs *cs, const VkQueryPool *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkQueryPool(struct vn_cs *cs, VkQueryPool *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkQueryPool_lookup(struct vn_cs *cs, VkQueryPool *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkQueryPool)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkQueryPool_handle(VkQueryPool *val)
{
    *val = (VkQueryPool)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkFramebuffer) */

static inline void
vn_encode_VkFramebuffer(struct vn_cs *cs, const VkFramebuffer *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkFramebuffer(struct vn_cs *cs, VkFramebuffer *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkFramebuffer_lookup(struct vn_cs *cs, VkFramebuffer *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkFramebuffer)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkFramebuffer_handle(VkFramebuffer *val)
{
    *val = (VkFramebuffer)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkRenderPass) */

static inline void
vn_encode_VkRenderPass(struct vn_cs *cs, const VkRenderPass *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkRenderPass(struct vn_cs *cs, VkRenderPass *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkRenderPass_lookup(struct vn_cs *cs, VkRenderPass *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkRenderPass)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkRenderPass_handle(VkRenderPass *val)
{
    *val = (VkRenderPass)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkPipelineCache) */

static inline void
vn_encode_VkPipelineCache(struct vn_cs *cs, const VkPipelineCache *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkPipelineCache(struct vn_cs *cs, VkPipelineCache *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkPipelineCache_lookup(struct vn_cs *cs, VkPipelineCache *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkPipelineCache)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkPipelineCache_handle(VkPipelineCache *val)
{
    *val = (VkPipelineCache)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkDescriptorUpdateTemplate) */

static inline void
vn_encode_VkDescriptorUpdateTemplate(struct vn_cs *cs, const VkDescriptorUpdateTemplate *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkDescriptorUpdateTemplate(struct vn_cs *cs, VkDescriptorUpdateTemplate *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkDescriptorUpdateTemplate_lookup(struct vn_cs *cs, VkDescriptorUpdateTemplate *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkDescriptorUpdateTemplate)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkDescriptorUpdateTemplate_handle(VkDescriptorUpdateTemplate *val)
{
    *val = (VkDescriptorUpdateTemplate)vn_cs_get_object_handle(val);
}

/* VK_DEFINE_NON_DISPATCHABLE_HANDLE(VkSamplerYcbcrConversion) */

static inline void
vn_encode_VkSamplerYcbcrConversion(struct vn_cs *cs, const VkSamplerYcbcrConversion *val)
{
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    const uint64_t id = vn_cs_handle_load_id((const void *)val, in_place);
    vn_encode_uint64_t(cs, &id);
}

static inline void
vn_decode_VkSamplerYcbcrConversion(struct vn_cs *cs, VkSamplerYcbcrConversion *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    const bool in_place = sizeof(*val) >= sizeof(vn_cs_object_id);
    vn_cs_handle_store_id((void *)val, id, in_place);
}

static inline void
vn_decode_VkSamplerYcbcrConversion_lookup(struct vn_cs *cs, VkSamplerYcbcrConversion *val)
{
    uint64_t id;
    vn_decode_uint64_t(cs, &id);
    *val = (VkSamplerYcbcrConversion)(uintptr_t)vn_cs_lookup_object(cs, id);
}

static inline void
vn_replace_VkSamplerYcbcrConversion_handle(VkSamplerYcbcrConversion *val)
{
    *val = (VkSamplerYcbcrConversion)vn_cs_get_object_handle(val);
}

#endif /* VN_PROTOCOL_RENDERER_HANDLES_H */
