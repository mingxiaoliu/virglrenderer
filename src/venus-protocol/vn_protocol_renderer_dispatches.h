/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_DISPATCHES_H
#define VN_PROTOCOL_RENDERER_DISPATCHES_H

#include <stdarg.h>
#include <stdio.h>

#include "vn_protocol_renderer_commands.h"

static inline const char *vn_dispatch_command_name(VkCommandTypeEXT type)
{
    switch (type) {
    case VK_COMMAND_TYPE_vkCreateInstance_EXT: return "vkCreateInstance";
    case VK_COMMAND_TYPE_vkDestroyInstance_EXT: return "vkDestroyInstance";
    case VK_COMMAND_TYPE_vkEnumeratePhysicalDevices_EXT: return "vkEnumeratePhysicalDevices";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceProperties_EXT: return "vkGetPhysicalDeviceProperties";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceQueueFamilyProperties_EXT: return "vkGetPhysicalDeviceQueueFamilyProperties";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceMemoryProperties_EXT: return "vkGetPhysicalDeviceMemoryProperties";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceFeatures_EXT: return "vkGetPhysicalDeviceFeatures";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceFormatProperties_EXT: return "vkGetPhysicalDeviceFormatProperties";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceImageFormatProperties_EXT: return "vkGetPhysicalDeviceImageFormatProperties";
    case VK_COMMAND_TYPE_vkCreateDevice_EXT: return "vkCreateDevice";
    case VK_COMMAND_TYPE_vkDestroyDevice_EXT: return "vkDestroyDevice";
    case VK_COMMAND_TYPE_vkEnumerateInstanceVersion_EXT: return "vkEnumerateInstanceVersion";
    case VK_COMMAND_TYPE_vkEnumerateInstanceLayerProperties_EXT: return "vkEnumerateInstanceLayerProperties";
    case VK_COMMAND_TYPE_vkEnumerateInstanceExtensionProperties_EXT: return "vkEnumerateInstanceExtensionProperties";
    case VK_COMMAND_TYPE_vkEnumerateDeviceLayerProperties_EXT: return "vkEnumerateDeviceLayerProperties";
    case VK_COMMAND_TYPE_vkEnumerateDeviceExtensionProperties_EXT: return "vkEnumerateDeviceExtensionProperties";
    case VK_COMMAND_TYPE_vkGetDeviceQueue_EXT: return "vkGetDeviceQueue";
    case VK_COMMAND_TYPE_vkQueueSubmit_EXT: return "vkQueueSubmit";
    case VK_COMMAND_TYPE_vkQueueWaitIdle_EXT: return "vkQueueWaitIdle";
    case VK_COMMAND_TYPE_vkDeviceWaitIdle_EXT: return "vkDeviceWaitIdle";
    case VK_COMMAND_TYPE_vkAllocateMemory_EXT: return "vkAllocateMemory";
    case VK_COMMAND_TYPE_vkFreeMemory_EXT: return "vkFreeMemory";
    case VK_COMMAND_TYPE_vkUnmapMemory_EXT: return "vkUnmapMemory";
    case VK_COMMAND_TYPE_vkFlushMappedMemoryRanges_EXT: return "vkFlushMappedMemoryRanges";
    case VK_COMMAND_TYPE_vkInvalidateMappedMemoryRanges_EXT: return "vkInvalidateMappedMemoryRanges";
    case VK_COMMAND_TYPE_vkGetDeviceMemoryCommitment_EXT: return "vkGetDeviceMemoryCommitment";
    case VK_COMMAND_TYPE_vkGetBufferMemoryRequirements_EXT: return "vkGetBufferMemoryRequirements";
    case VK_COMMAND_TYPE_vkBindBufferMemory_EXT: return "vkBindBufferMemory";
    case VK_COMMAND_TYPE_vkGetImageMemoryRequirements_EXT: return "vkGetImageMemoryRequirements";
    case VK_COMMAND_TYPE_vkBindImageMemory_EXT: return "vkBindImageMemory";
    case VK_COMMAND_TYPE_vkGetImageSparseMemoryRequirements_EXT: return "vkGetImageSparseMemoryRequirements";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceSparseImageFormatProperties_EXT: return "vkGetPhysicalDeviceSparseImageFormatProperties";
    case VK_COMMAND_TYPE_vkQueueBindSparse_EXT: return "vkQueueBindSparse";
    case VK_COMMAND_TYPE_vkCreateFence_EXT: return "vkCreateFence";
    case VK_COMMAND_TYPE_vkDestroyFence_EXT: return "vkDestroyFence";
    case VK_COMMAND_TYPE_vkResetFences_EXT: return "vkResetFences";
    case VK_COMMAND_TYPE_vkGetFenceStatus_EXT: return "vkGetFenceStatus";
    case VK_COMMAND_TYPE_vkWaitForFences_EXT: return "vkWaitForFences";
    case VK_COMMAND_TYPE_vkCreateSemaphore_EXT: return "vkCreateSemaphore";
    case VK_COMMAND_TYPE_vkDestroySemaphore_EXT: return "vkDestroySemaphore";
    case VK_COMMAND_TYPE_vkCreateEvent_EXT: return "vkCreateEvent";
    case VK_COMMAND_TYPE_vkDestroyEvent_EXT: return "vkDestroyEvent";
    case VK_COMMAND_TYPE_vkGetEventStatus_EXT: return "vkGetEventStatus";
    case VK_COMMAND_TYPE_vkSetEvent_EXT: return "vkSetEvent";
    case VK_COMMAND_TYPE_vkResetEvent_EXT: return "vkResetEvent";
    case VK_COMMAND_TYPE_vkCreateQueryPool_EXT: return "vkCreateQueryPool";
    case VK_COMMAND_TYPE_vkDestroyQueryPool_EXT: return "vkDestroyQueryPool";
    case VK_COMMAND_TYPE_vkGetQueryPoolResults_EXT: return "vkGetQueryPoolResults";
    case VK_COMMAND_TYPE_vkResetQueryPool_EXT: return "vkResetQueryPool";
    case VK_COMMAND_TYPE_vkCreateBuffer_EXT: return "vkCreateBuffer";
    case VK_COMMAND_TYPE_vkDestroyBuffer_EXT: return "vkDestroyBuffer";
    case VK_COMMAND_TYPE_vkCreateBufferView_EXT: return "vkCreateBufferView";
    case VK_COMMAND_TYPE_vkDestroyBufferView_EXT: return "vkDestroyBufferView";
    case VK_COMMAND_TYPE_vkCreateImage_EXT: return "vkCreateImage";
    case VK_COMMAND_TYPE_vkDestroyImage_EXT: return "vkDestroyImage";
    case VK_COMMAND_TYPE_vkGetImageSubresourceLayout_EXT: return "vkGetImageSubresourceLayout";
    case VK_COMMAND_TYPE_vkCreateImageView_EXT: return "vkCreateImageView";
    case VK_COMMAND_TYPE_vkDestroyImageView_EXT: return "vkDestroyImageView";
    case VK_COMMAND_TYPE_vkCreateShaderModule_EXT: return "vkCreateShaderModule";
    case VK_COMMAND_TYPE_vkDestroyShaderModule_EXT: return "vkDestroyShaderModule";
    case VK_COMMAND_TYPE_vkCreatePipelineCache_EXT: return "vkCreatePipelineCache";
    case VK_COMMAND_TYPE_vkDestroyPipelineCache_EXT: return "vkDestroyPipelineCache";
    case VK_COMMAND_TYPE_vkGetPipelineCacheData_EXT: return "vkGetPipelineCacheData";
    case VK_COMMAND_TYPE_vkMergePipelineCaches_EXT: return "vkMergePipelineCaches";
    case VK_COMMAND_TYPE_vkCreateGraphicsPipelines_EXT: return "vkCreateGraphicsPipelines";
    case VK_COMMAND_TYPE_vkCreateComputePipelines_EXT: return "vkCreateComputePipelines";
    case VK_COMMAND_TYPE_vkDestroyPipeline_EXT: return "vkDestroyPipeline";
    case VK_COMMAND_TYPE_vkCreatePipelineLayout_EXT: return "vkCreatePipelineLayout";
    case VK_COMMAND_TYPE_vkDestroyPipelineLayout_EXT: return "vkDestroyPipelineLayout";
    case VK_COMMAND_TYPE_vkCreateSampler_EXT: return "vkCreateSampler";
    case VK_COMMAND_TYPE_vkDestroySampler_EXT: return "vkDestroySampler";
    case VK_COMMAND_TYPE_vkCreateDescriptorSetLayout_EXT: return "vkCreateDescriptorSetLayout";
    case VK_COMMAND_TYPE_vkDestroyDescriptorSetLayout_EXT: return "vkDestroyDescriptorSetLayout";
    case VK_COMMAND_TYPE_vkCreateDescriptorPool_EXT: return "vkCreateDescriptorPool";
    case VK_COMMAND_TYPE_vkDestroyDescriptorPool_EXT: return "vkDestroyDescriptorPool";
    case VK_COMMAND_TYPE_vkResetDescriptorPool_EXT: return "vkResetDescriptorPool";
    case VK_COMMAND_TYPE_vkAllocateDescriptorSets_EXT: return "vkAllocateDescriptorSets";
    case VK_COMMAND_TYPE_vkFreeDescriptorSets_EXT: return "vkFreeDescriptorSets";
    case VK_COMMAND_TYPE_vkUpdateDescriptorSets_EXT: return "vkUpdateDescriptorSets";
    case VK_COMMAND_TYPE_vkCreateFramebuffer_EXT: return "vkCreateFramebuffer";
    case VK_COMMAND_TYPE_vkDestroyFramebuffer_EXT: return "vkDestroyFramebuffer";
    case VK_COMMAND_TYPE_vkCreateRenderPass_EXT: return "vkCreateRenderPass";
    case VK_COMMAND_TYPE_vkDestroyRenderPass_EXT: return "vkDestroyRenderPass";
    case VK_COMMAND_TYPE_vkGetRenderAreaGranularity_EXT: return "vkGetRenderAreaGranularity";
    case VK_COMMAND_TYPE_vkCreateCommandPool_EXT: return "vkCreateCommandPool";
    case VK_COMMAND_TYPE_vkDestroyCommandPool_EXT: return "vkDestroyCommandPool";
    case VK_COMMAND_TYPE_vkResetCommandPool_EXT: return "vkResetCommandPool";
    case VK_COMMAND_TYPE_vkAllocateCommandBuffers_EXT: return "vkAllocateCommandBuffers";
    case VK_COMMAND_TYPE_vkFreeCommandBuffers_EXT: return "vkFreeCommandBuffers";
    case VK_COMMAND_TYPE_vkBeginCommandBuffer_EXT: return "vkBeginCommandBuffer";
    case VK_COMMAND_TYPE_vkEndCommandBuffer_EXT: return "vkEndCommandBuffer";
    case VK_COMMAND_TYPE_vkResetCommandBuffer_EXT: return "vkResetCommandBuffer";
    case VK_COMMAND_TYPE_vkCmdBindPipeline_EXT: return "vkCmdBindPipeline";
    case VK_COMMAND_TYPE_vkCmdSetViewport_EXT: return "vkCmdSetViewport";
    case VK_COMMAND_TYPE_vkCmdSetScissor_EXT: return "vkCmdSetScissor";
    case VK_COMMAND_TYPE_vkCmdSetLineWidth_EXT: return "vkCmdSetLineWidth";
    case VK_COMMAND_TYPE_vkCmdSetDepthBias_EXT: return "vkCmdSetDepthBias";
    case VK_COMMAND_TYPE_vkCmdSetBlendConstants_EXT: return "vkCmdSetBlendConstants";
    case VK_COMMAND_TYPE_vkCmdSetDepthBounds_EXT: return "vkCmdSetDepthBounds";
    case VK_COMMAND_TYPE_vkCmdSetStencilCompareMask_EXT: return "vkCmdSetStencilCompareMask";
    case VK_COMMAND_TYPE_vkCmdSetStencilWriteMask_EXT: return "vkCmdSetStencilWriteMask";
    case VK_COMMAND_TYPE_vkCmdSetStencilReference_EXT: return "vkCmdSetStencilReference";
    case VK_COMMAND_TYPE_vkCmdBindDescriptorSets_EXT: return "vkCmdBindDescriptorSets";
    case VK_COMMAND_TYPE_vkCmdBindIndexBuffer_EXT: return "vkCmdBindIndexBuffer";
    case VK_COMMAND_TYPE_vkCmdBindVertexBuffers_EXT: return "vkCmdBindVertexBuffers";
    case VK_COMMAND_TYPE_vkCmdDraw_EXT: return "vkCmdDraw";
    case VK_COMMAND_TYPE_vkCmdDrawIndexed_EXT: return "vkCmdDrawIndexed";
    case VK_COMMAND_TYPE_vkCmdDrawIndirect_EXT: return "vkCmdDrawIndirect";
    case VK_COMMAND_TYPE_vkCmdDrawIndexedIndirect_EXT: return "vkCmdDrawIndexedIndirect";
    case VK_COMMAND_TYPE_vkCmdDispatch_EXT: return "vkCmdDispatch";
    case VK_COMMAND_TYPE_vkCmdDispatchIndirect_EXT: return "vkCmdDispatchIndirect";
    case VK_COMMAND_TYPE_vkCmdCopyBuffer_EXT: return "vkCmdCopyBuffer";
    case VK_COMMAND_TYPE_vkCmdCopyImage_EXT: return "vkCmdCopyImage";
    case VK_COMMAND_TYPE_vkCmdBlitImage_EXT: return "vkCmdBlitImage";
    case VK_COMMAND_TYPE_vkCmdCopyBufferToImage_EXT: return "vkCmdCopyBufferToImage";
    case VK_COMMAND_TYPE_vkCmdCopyImageToBuffer_EXT: return "vkCmdCopyImageToBuffer";
    case VK_COMMAND_TYPE_vkCmdUpdateBuffer_EXT: return "vkCmdUpdateBuffer";
    case VK_COMMAND_TYPE_vkCmdFillBuffer_EXT: return "vkCmdFillBuffer";
    case VK_COMMAND_TYPE_vkCmdClearColorImage_EXT: return "vkCmdClearColorImage";
    case VK_COMMAND_TYPE_vkCmdClearDepthStencilImage_EXT: return "vkCmdClearDepthStencilImage";
    case VK_COMMAND_TYPE_vkCmdClearAttachments_EXT: return "vkCmdClearAttachments";
    case VK_COMMAND_TYPE_vkCmdResolveImage_EXT: return "vkCmdResolveImage";
    case VK_COMMAND_TYPE_vkCmdSetEvent_EXT: return "vkCmdSetEvent";
    case VK_COMMAND_TYPE_vkCmdResetEvent_EXT: return "vkCmdResetEvent";
    case VK_COMMAND_TYPE_vkCmdWaitEvents_EXT: return "vkCmdWaitEvents";
    case VK_COMMAND_TYPE_vkCmdPipelineBarrier_EXT: return "vkCmdPipelineBarrier";
    case VK_COMMAND_TYPE_vkCmdBeginQuery_EXT: return "vkCmdBeginQuery";
    case VK_COMMAND_TYPE_vkCmdEndQuery_EXT: return "vkCmdEndQuery";
    case VK_COMMAND_TYPE_vkCmdResetQueryPool_EXT: return "vkCmdResetQueryPool";
    case VK_COMMAND_TYPE_vkCmdWriteTimestamp_EXT: return "vkCmdWriteTimestamp";
    case VK_COMMAND_TYPE_vkCmdCopyQueryPoolResults_EXT: return "vkCmdCopyQueryPoolResults";
    case VK_COMMAND_TYPE_vkCmdPushConstants_EXT: return "vkCmdPushConstants";
    case VK_COMMAND_TYPE_vkCmdBeginRenderPass_EXT: return "vkCmdBeginRenderPass";
    case VK_COMMAND_TYPE_vkCmdNextSubpass_EXT: return "vkCmdNextSubpass";
    case VK_COMMAND_TYPE_vkCmdEndRenderPass_EXT: return "vkCmdEndRenderPass";
    case VK_COMMAND_TYPE_vkCmdExecuteCommands_EXT: return "vkCmdExecuteCommands";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceFeatures2_EXT: return "vkGetPhysicalDeviceFeatures2";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceProperties2_EXT: return "vkGetPhysicalDeviceProperties2";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceFormatProperties2_EXT: return "vkGetPhysicalDeviceFormatProperties2";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceImageFormatProperties2_EXT: return "vkGetPhysicalDeviceImageFormatProperties2";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceQueueFamilyProperties2_EXT: return "vkGetPhysicalDeviceQueueFamilyProperties2";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceMemoryProperties2_EXT: return "vkGetPhysicalDeviceMemoryProperties2";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceSparseImageFormatProperties2_EXT: return "vkGetPhysicalDeviceSparseImageFormatProperties2";
    case VK_COMMAND_TYPE_vkTrimCommandPool_EXT: return "vkTrimCommandPool";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalBufferProperties_EXT: return "vkGetPhysicalDeviceExternalBufferProperties";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalSemaphoreProperties_EXT: return "vkGetPhysicalDeviceExternalSemaphoreProperties";
    case VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalFenceProperties_EXT: return "vkGetPhysicalDeviceExternalFenceProperties";
    case VK_COMMAND_TYPE_vkEnumeratePhysicalDeviceGroups_EXT: return "vkEnumeratePhysicalDeviceGroups";
    case VK_COMMAND_TYPE_vkGetDeviceGroupPeerMemoryFeatures_EXT: return "vkGetDeviceGroupPeerMemoryFeatures";
    case VK_COMMAND_TYPE_vkBindBufferMemory2_EXT: return "vkBindBufferMemory2";
    case VK_COMMAND_TYPE_vkBindImageMemory2_EXT: return "vkBindImageMemory2";
    case VK_COMMAND_TYPE_vkCmdSetDeviceMask_EXT: return "vkCmdSetDeviceMask";
    case VK_COMMAND_TYPE_vkCmdDispatchBase_EXT: return "vkCmdDispatchBase";
    case VK_COMMAND_TYPE_vkCreateDescriptorUpdateTemplate_EXT: return "vkCreateDescriptorUpdateTemplate";
    case VK_COMMAND_TYPE_vkDestroyDescriptorUpdateTemplate_EXT: return "vkDestroyDescriptorUpdateTemplate";
    case VK_COMMAND_TYPE_vkGetBufferMemoryRequirements2_EXT: return "vkGetBufferMemoryRequirements2";
    case VK_COMMAND_TYPE_vkGetImageMemoryRequirements2_EXT: return "vkGetImageMemoryRequirements2";
    case VK_COMMAND_TYPE_vkGetImageSparseMemoryRequirements2_EXT: return "vkGetImageSparseMemoryRequirements2";
    case VK_COMMAND_TYPE_vkCreateSamplerYcbcrConversion_EXT: return "vkCreateSamplerYcbcrConversion";
    case VK_COMMAND_TYPE_vkDestroySamplerYcbcrConversion_EXT: return "vkDestroySamplerYcbcrConversion";
    case VK_COMMAND_TYPE_vkGetDeviceQueue2_EXT: return "vkGetDeviceQueue2";
    case VK_COMMAND_TYPE_vkGetDescriptorSetLayoutSupport_EXT: return "vkGetDescriptorSetLayoutSupport";
    case VK_COMMAND_TYPE_vkCreateRenderPass2_EXT: return "vkCreateRenderPass2";
    case VK_COMMAND_TYPE_vkCmdBeginRenderPass2_EXT: return "vkCmdBeginRenderPass2";
    case VK_COMMAND_TYPE_vkCmdNextSubpass2_EXT: return "vkCmdNextSubpass2";
    case VK_COMMAND_TYPE_vkCmdEndRenderPass2_EXT: return "vkCmdEndRenderPass2";
    case VK_COMMAND_TYPE_vkGetSemaphoreCounterValue_EXT: return "vkGetSemaphoreCounterValue";
    case VK_COMMAND_TYPE_vkWaitSemaphores_EXT: return "vkWaitSemaphores";
    case VK_COMMAND_TYPE_vkSignalSemaphore_EXT: return "vkSignalSemaphore";
    case VK_COMMAND_TYPE_vkCmdDrawIndirectCount_EXT: return "vkCmdDrawIndirectCount";
    case VK_COMMAND_TYPE_vkCmdDrawIndexedIndirectCount_EXT: return "vkCmdDrawIndexedIndirectCount";
    case VK_COMMAND_TYPE_vkCmdBindTransformFeedbackBuffersEXT_EXT: return "vkCmdBindTransformFeedbackBuffersEXT";
    case VK_COMMAND_TYPE_vkCmdBeginTransformFeedbackEXT_EXT: return "vkCmdBeginTransformFeedbackEXT";
    case VK_COMMAND_TYPE_vkCmdEndTransformFeedbackEXT_EXT: return "vkCmdEndTransformFeedbackEXT";
    case VK_COMMAND_TYPE_vkCmdBeginQueryIndexedEXT_EXT: return "vkCmdBeginQueryIndexedEXT";
    case VK_COMMAND_TYPE_vkCmdEndQueryIndexedEXT_EXT: return "vkCmdEndQueryIndexedEXT";
    case VK_COMMAND_TYPE_vkCmdDrawIndirectByteCountEXT_EXT: return "vkCmdDrawIndirectByteCountEXT";
    case VK_COMMAND_TYPE_vkGetImageDrmFormatModifierPropertiesEXT_EXT: return "vkGetImageDrmFormatModifierPropertiesEXT";
    case VK_COMMAND_TYPE_vkGetBufferOpaqueCaptureAddress_EXT: return "vkGetBufferOpaqueCaptureAddress";
    case VK_COMMAND_TYPE_vkGetBufferDeviceAddress_EXT: return "vkGetBufferDeviceAddress";
    case VK_COMMAND_TYPE_vkGetDeviceMemoryOpaqueCaptureAddress_EXT: return "vkGetDeviceMemoryOpaqueCaptureAddress";
    case VK_COMMAND_TYPE_vkSetReplyCommandStreamMESA_EXT: return "vkSetReplyCommandStreamMESA";
    case VK_COMMAND_TYPE_vkSeekReplyCommandStreamMESA_EXT: return "vkSeekReplyCommandStreamMESA";
    case VK_COMMAND_TYPE_vkExecuteCommandStreamsMESA_EXT: return "vkExecuteCommandStreamsMESA";
    case VK_COMMAND_TYPE_vkCreateRingMESA_EXT: return "vkCreateRingMESA";
    case VK_COMMAND_TYPE_vkDestroyRingMESA_EXT: return "vkDestroyRingMESA";
    case VK_COMMAND_TYPE_vkNotifyRingMESA_EXT: return "vkNotifyRingMESA";
    case VK_COMMAND_TYPE_vkWriteRingExtraMESA_EXT: return "vkWriteRingExtraMESA";
    case VK_COMMAND_TYPE_vkGetDeviceProcAddr_EXT: return "vkGetDeviceProcAddr";
    case VK_COMMAND_TYPE_vkGetInstanceProcAddr_EXT: return "vkGetInstanceProcAddr";
    case VK_COMMAND_TYPE_vkMapMemory_EXT: return "vkMapMemory";
    case VK_COMMAND_TYPE_vkUpdateDescriptorSetWithTemplate_EXT: return "vkUpdateDescriptorSetWithTemplate";
    default: return "unknown";
    }
}

static inline void vn_dispatch_debug_log(struct vn_dispatch_context *ctx, const char *format, ...)
{
    char msg[256];
    va_list va;

    if (!ctx->debug_log)
        return;

    va_start(va, format);
    vsnprintf(msg, sizeof(msg), format, va);
    ctx->debug_log(ctx, msg);
    va_end(va);
}

static inline void vn_dispatch_vkCreateInstance(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateInstance args;

    if (!ctx->dispatch_vkCreateInstance) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateInstance_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateInstance(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateInstance returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateInstance_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyInstance(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyInstance args;

    if (!ctx->dispatch_vkDestroyInstance) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyInstance_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyInstance(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyInstance_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumeratePhysicalDevices(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumeratePhysicalDevices args;

    if (!ctx->dispatch_vkEnumeratePhysicalDevices) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumeratePhysicalDevices_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumeratePhysicalDevices(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEnumeratePhysicalDevices returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumeratePhysicalDevices_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceQueueFamilyProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceQueueFamilyProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceQueueFamilyProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceQueueFamilyProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceQueueFamilyProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceMemoryProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceMemoryProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceMemoryProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceMemoryProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceMemoryProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceMemoryProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceFeatures(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceFeatures args;

    if (!ctx->dispatch_vkGetPhysicalDeviceFeatures) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceFeatures_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceFeatures(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceFeatures_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceFormatProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceFormatProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceFormatProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceFormatProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceFormatProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceFormatProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceImageFormatProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceImageFormatProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceImageFormatProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceImageFormatProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceImageFormatProperties(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetPhysicalDeviceImageFormatProperties returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceImageFormatProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateDevice(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateDevice args;

    if (!ctx->dispatch_vkCreateDevice) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateDevice_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateDevice(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateDevice returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateDevice_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyDevice(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyDevice args;

    if (!ctx->dispatch_vkDestroyDevice) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyDevice_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyDevice(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyDevice_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateInstanceVersion(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateInstanceVersion args;

    if (!ctx->dispatch_vkEnumerateInstanceVersion) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateInstanceVersion_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateInstanceVersion(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEnumerateInstanceVersion returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateInstanceVersion_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateInstanceLayerProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateInstanceLayerProperties args;

    if (!ctx->dispatch_vkEnumerateInstanceLayerProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateInstanceLayerProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateInstanceLayerProperties(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEnumerateInstanceLayerProperties returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateInstanceLayerProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateInstanceExtensionProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateInstanceExtensionProperties args;

    if (!ctx->dispatch_vkEnumerateInstanceExtensionProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateInstanceExtensionProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateInstanceExtensionProperties(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEnumerateInstanceExtensionProperties returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateInstanceExtensionProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateDeviceLayerProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateDeviceLayerProperties args;

    if (!ctx->dispatch_vkEnumerateDeviceLayerProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateDeviceLayerProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateDeviceLayerProperties(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEnumerateDeviceLayerProperties returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateDeviceLayerProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumerateDeviceExtensionProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumerateDeviceExtensionProperties args;

    if (!ctx->dispatch_vkEnumerateDeviceExtensionProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumerateDeviceExtensionProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumerateDeviceExtensionProperties(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEnumerateDeviceExtensionProperties returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumerateDeviceExtensionProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetDeviceQueue(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetDeviceQueue args;

    if (!ctx->dispatch_vkGetDeviceQueue) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetDeviceQueue_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetDeviceQueue(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetDeviceQueue_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkQueueSubmit(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkQueueSubmit args;

    if (!ctx->dispatch_vkQueueSubmit) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkQueueSubmit_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkQueueSubmit(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkQueueSubmit returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkQueueSubmit_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkQueueWaitIdle(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkQueueWaitIdle args;

    if (!ctx->dispatch_vkQueueWaitIdle) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkQueueWaitIdle_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkQueueWaitIdle(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkQueueWaitIdle returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkQueueWaitIdle_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDeviceWaitIdle(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDeviceWaitIdle args;

    if (!ctx->dispatch_vkDeviceWaitIdle) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDeviceWaitIdle_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDeviceWaitIdle(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkDeviceWaitIdle returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDeviceWaitIdle_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkAllocateMemory(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkAllocateMemory args;

    if (!ctx->dispatch_vkAllocateMemory) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkAllocateMemory_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkAllocateMemory(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkAllocateMemory returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkAllocateMemory_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkFreeMemory(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkFreeMemory args;

    if (!ctx->dispatch_vkFreeMemory) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkFreeMemory_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkFreeMemory(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkFreeMemory_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkUnmapMemory(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkUnmapMemory args;

    if (!ctx->dispatch_vkUnmapMemory) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkUnmapMemory_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkUnmapMemory(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkUnmapMemory_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkFlushMappedMemoryRanges(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkFlushMappedMemoryRanges args;

    if (!ctx->dispatch_vkFlushMappedMemoryRanges) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkFlushMappedMemoryRanges_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkFlushMappedMemoryRanges(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkFlushMappedMemoryRanges returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkFlushMappedMemoryRanges_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkInvalidateMappedMemoryRanges(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkInvalidateMappedMemoryRanges args;

    if (!ctx->dispatch_vkInvalidateMappedMemoryRanges) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkInvalidateMappedMemoryRanges_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkInvalidateMappedMemoryRanges(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkInvalidateMappedMemoryRanges returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkInvalidateMappedMemoryRanges_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetDeviceMemoryCommitment(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetDeviceMemoryCommitment args;

    if (!ctx->dispatch_vkGetDeviceMemoryCommitment) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetDeviceMemoryCommitment_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetDeviceMemoryCommitment(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetDeviceMemoryCommitment_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetBufferMemoryRequirements(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetBufferMemoryRequirements args;

    if (!ctx->dispatch_vkGetBufferMemoryRequirements) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetBufferMemoryRequirements_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetBufferMemoryRequirements(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetBufferMemoryRequirements_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkBindBufferMemory(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkBindBufferMemory args;

    if (!ctx->dispatch_vkBindBufferMemory) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkBindBufferMemory_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkBindBufferMemory(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkBindBufferMemory returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkBindBufferMemory_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetImageMemoryRequirements(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetImageMemoryRequirements args;

    if (!ctx->dispatch_vkGetImageMemoryRequirements) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetImageMemoryRequirements_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetImageMemoryRequirements(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetImageMemoryRequirements_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkBindImageMemory(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkBindImageMemory args;

    if (!ctx->dispatch_vkBindImageMemory) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkBindImageMemory_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkBindImageMemory(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkBindImageMemory returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkBindImageMemory_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetImageSparseMemoryRequirements(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetImageSparseMemoryRequirements args;

    if (!ctx->dispatch_vkGetImageSparseMemoryRequirements) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetImageSparseMemoryRequirements_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetImageSparseMemoryRequirements(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetImageSparseMemoryRequirements_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceSparseImageFormatProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceSparseImageFormatProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceSparseImageFormatProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceSparseImageFormatProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceSparseImageFormatProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkQueueBindSparse(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkQueueBindSparse args;

    if (!ctx->dispatch_vkQueueBindSparse) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkQueueBindSparse_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkQueueBindSparse(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkQueueBindSparse returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkQueueBindSparse_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateFence(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateFence args;

    if (!ctx->dispatch_vkCreateFence) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateFence_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateFence(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateFence returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateFence_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyFence(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyFence args;

    if (!ctx->dispatch_vkDestroyFence) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyFence_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyFence(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyFence_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetFences(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetFences args;

    if (!ctx->dispatch_vkResetFences) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetFences_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetFences(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkResetFences returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetFences_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetFenceStatus(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetFenceStatus args;

    if (!ctx->dispatch_vkGetFenceStatus) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetFenceStatus_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetFenceStatus(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetFenceStatus returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetFenceStatus_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkWaitForFences(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkWaitForFences args;

    if (!ctx->dispatch_vkWaitForFences) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkWaitForFences_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkWaitForFences(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkWaitForFences returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkWaitForFences_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateSemaphore(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateSemaphore args;

    if (!ctx->dispatch_vkCreateSemaphore) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateSemaphore_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateSemaphore(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateSemaphore returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateSemaphore_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroySemaphore(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroySemaphore args;

    if (!ctx->dispatch_vkDestroySemaphore) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroySemaphore_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroySemaphore(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroySemaphore_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateEvent args;

    if (!ctx->dispatch_vkCreateEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateEvent_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateEvent(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateEvent returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyEvent args;

    if (!ctx->dispatch_vkDestroyEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyEvent_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyEvent(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetEventStatus(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetEventStatus args;

    if (!ctx->dispatch_vkGetEventStatus) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetEventStatus_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetEventStatus(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetEventStatus returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetEventStatus_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkSetEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkSetEvent args;

    if (!ctx->dispatch_vkSetEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkSetEvent_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkSetEvent(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkSetEvent returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkSetEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetEvent args;

    if (!ctx->dispatch_vkResetEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetEvent_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetEvent(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkResetEvent returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateQueryPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateQueryPool args;

    if (!ctx->dispatch_vkCreateQueryPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateQueryPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateQueryPool(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateQueryPool returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateQueryPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyQueryPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyQueryPool args;

    if (!ctx->dispatch_vkDestroyQueryPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyQueryPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyQueryPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyQueryPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetQueryPoolResults(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetQueryPoolResults args;

    if (!ctx->dispatch_vkGetQueryPoolResults) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetQueryPoolResults_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetQueryPoolResults(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetQueryPoolResults returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetQueryPoolResults_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetQueryPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetQueryPool args;

    if (!ctx->dispatch_vkResetQueryPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetQueryPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetQueryPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetQueryPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateBuffer args;

    if (!ctx->dispatch_vkCreateBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateBuffer(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateBuffer returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyBuffer args;

    if (!ctx->dispatch_vkDestroyBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyBuffer(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateBufferView(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateBufferView args;

    if (!ctx->dispatch_vkCreateBufferView) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateBufferView_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateBufferView(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateBufferView returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateBufferView_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyBufferView(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyBufferView args;

    if (!ctx->dispatch_vkDestroyBufferView) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyBufferView_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyBufferView(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyBufferView_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateImage args;

    if (!ctx->dispatch_vkCreateImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateImage(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateImage returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyImage args;

    if (!ctx->dispatch_vkDestroyImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyImage(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetImageSubresourceLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetImageSubresourceLayout args;

    if (!ctx->dispatch_vkGetImageSubresourceLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetImageSubresourceLayout_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetImageSubresourceLayout(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetImageSubresourceLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateImageView(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateImageView args;

    if (!ctx->dispatch_vkCreateImageView) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateImageView_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateImageView(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateImageView returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateImageView_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyImageView(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyImageView args;

    if (!ctx->dispatch_vkDestroyImageView) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyImageView_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyImageView(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyImageView_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateShaderModule(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateShaderModule args;

    if (!ctx->dispatch_vkCreateShaderModule) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateShaderModule_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateShaderModule(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateShaderModule returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateShaderModule_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyShaderModule(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyShaderModule args;

    if (!ctx->dispatch_vkDestroyShaderModule) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyShaderModule_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyShaderModule(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyShaderModule_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreatePipelineCache(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreatePipelineCache args;

    if (!ctx->dispatch_vkCreatePipelineCache) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreatePipelineCache_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreatePipelineCache(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreatePipelineCache returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreatePipelineCache_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyPipelineCache(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyPipelineCache args;

    if (!ctx->dispatch_vkDestroyPipelineCache) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyPipelineCache_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyPipelineCache(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyPipelineCache_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPipelineCacheData(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPipelineCacheData args;

    if (!ctx->dispatch_vkGetPipelineCacheData) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPipelineCacheData_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPipelineCacheData(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetPipelineCacheData returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPipelineCacheData_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkMergePipelineCaches(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkMergePipelineCaches args;

    if (!ctx->dispatch_vkMergePipelineCaches) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkMergePipelineCaches_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkMergePipelineCaches(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkMergePipelineCaches returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkMergePipelineCaches_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateGraphicsPipelines(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateGraphicsPipelines args;

    if (!ctx->dispatch_vkCreateGraphicsPipelines) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateGraphicsPipelines_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateGraphicsPipelines(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateGraphicsPipelines returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateGraphicsPipelines_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateComputePipelines(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateComputePipelines args;

    if (!ctx->dispatch_vkCreateComputePipelines) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateComputePipelines_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateComputePipelines(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateComputePipelines returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateComputePipelines_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyPipeline(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyPipeline args;

    if (!ctx->dispatch_vkDestroyPipeline) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyPipeline_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyPipeline(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyPipeline_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreatePipelineLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreatePipelineLayout args;

    if (!ctx->dispatch_vkCreatePipelineLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreatePipelineLayout_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreatePipelineLayout(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreatePipelineLayout returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreatePipelineLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyPipelineLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyPipelineLayout args;

    if (!ctx->dispatch_vkDestroyPipelineLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyPipelineLayout_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyPipelineLayout(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyPipelineLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateSampler(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateSampler args;

    if (!ctx->dispatch_vkCreateSampler) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateSampler_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateSampler(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateSampler returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateSampler_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroySampler(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroySampler args;

    if (!ctx->dispatch_vkDestroySampler) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroySampler_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroySampler(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroySampler_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateDescriptorSetLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateDescriptorSetLayout args;

    if (!ctx->dispatch_vkCreateDescriptorSetLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateDescriptorSetLayout_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateDescriptorSetLayout(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateDescriptorSetLayout returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateDescriptorSetLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyDescriptorSetLayout(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyDescriptorSetLayout args;

    if (!ctx->dispatch_vkDestroyDescriptorSetLayout) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyDescriptorSetLayout_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyDescriptorSetLayout(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyDescriptorSetLayout_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateDescriptorPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateDescriptorPool args;

    if (!ctx->dispatch_vkCreateDescriptorPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateDescriptorPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateDescriptorPool(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateDescriptorPool returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateDescriptorPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyDescriptorPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyDescriptorPool args;

    if (!ctx->dispatch_vkDestroyDescriptorPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyDescriptorPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyDescriptorPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyDescriptorPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetDescriptorPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetDescriptorPool args;

    if (!ctx->dispatch_vkResetDescriptorPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetDescriptorPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetDescriptorPool(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkResetDescriptorPool returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetDescriptorPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkAllocateDescriptorSets(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkAllocateDescriptorSets args;

    if (!ctx->dispatch_vkAllocateDescriptorSets) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkAllocateDescriptorSets_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkAllocateDescriptorSets(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkAllocateDescriptorSets returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkAllocateDescriptorSets_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkFreeDescriptorSets(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkFreeDescriptorSets args;

    if (!ctx->dispatch_vkFreeDescriptorSets) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkFreeDescriptorSets_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkFreeDescriptorSets(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkFreeDescriptorSets returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkFreeDescriptorSets_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkUpdateDescriptorSets(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkUpdateDescriptorSets args;

    if (!ctx->dispatch_vkUpdateDescriptorSets) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkUpdateDescriptorSets_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkUpdateDescriptorSets(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkUpdateDescriptorSets_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateFramebuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateFramebuffer args;

    if (!ctx->dispatch_vkCreateFramebuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateFramebuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateFramebuffer(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateFramebuffer returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateFramebuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyFramebuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyFramebuffer args;

    if (!ctx->dispatch_vkDestroyFramebuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyFramebuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyFramebuffer(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyFramebuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateRenderPass(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateRenderPass args;

    if (!ctx->dispatch_vkCreateRenderPass) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateRenderPass_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateRenderPass(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateRenderPass returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateRenderPass_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyRenderPass(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyRenderPass args;

    if (!ctx->dispatch_vkDestroyRenderPass) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyRenderPass_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyRenderPass(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyRenderPass_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetRenderAreaGranularity(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetRenderAreaGranularity args;

    if (!ctx->dispatch_vkGetRenderAreaGranularity) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetRenderAreaGranularity_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetRenderAreaGranularity(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetRenderAreaGranularity_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateCommandPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateCommandPool args;

    if (!ctx->dispatch_vkCreateCommandPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateCommandPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateCommandPool(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateCommandPool returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateCommandPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyCommandPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyCommandPool args;

    if (!ctx->dispatch_vkDestroyCommandPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyCommandPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyCommandPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyCommandPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetCommandPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetCommandPool args;

    if (!ctx->dispatch_vkResetCommandPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetCommandPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetCommandPool(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkResetCommandPool returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetCommandPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkAllocateCommandBuffers(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkAllocateCommandBuffers args;

    if (!ctx->dispatch_vkAllocateCommandBuffers) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkAllocateCommandBuffers_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkAllocateCommandBuffers(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkAllocateCommandBuffers returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkAllocateCommandBuffers_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkFreeCommandBuffers(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkFreeCommandBuffers args;

    if (!ctx->dispatch_vkFreeCommandBuffers) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkFreeCommandBuffers_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkFreeCommandBuffers(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkFreeCommandBuffers_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkBeginCommandBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkBeginCommandBuffer args;

    if (!ctx->dispatch_vkBeginCommandBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkBeginCommandBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkBeginCommandBuffer(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkBeginCommandBuffer returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkBeginCommandBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEndCommandBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEndCommandBuffer args;

    if (!ctx->dispatch_vkEndCommandBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEndCommandBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEndCommandBuffer(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEndCommandBuffer returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEndCommandBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkResetCommandBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkResetCommandBuffer args;

    if (!ctx->dispatch_vkResetCommandBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkResetCommandBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkResetCommandBuffer(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkResetCommandBuffer returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkResetCommandBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBindPipeline(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBindPipeline args;

    if (!ctx->dispatch_vkCmdBindPipeline) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBindPipeline_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBindPipeline(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBindPipeline_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetViewport(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetViewport args;

    if (!ctx->dispatch_vkCmdSetViewport) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetViewport_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetViewport(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetViewport_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetScissor(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetScissor args;

    if (!ctx->dispatch_vkCmdSetScissor) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetScissor_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetScissor(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetScissor_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetLineWidth(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetLineWidth args;

    if (!ctx->dispatch_vkCmdSetLineWidth) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetLineWidth_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetLineWidth(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetLineWidth_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetDepthBias(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetDepthBias args;

    if (!ctx->dispatch_vkCmdSetDepthBias) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetDepthBias_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetDepthBias(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetDepthBias_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetBlendConstants(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetBlendConstants args;

    if (!ctx->dispatch_vkCmdSetBlendConstants) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetBlendConstants_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetBlendConstants(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetBlendConstants_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetDepthBounds(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetDepthBounds args;

    if (!ctx->dispatch_vkCmdSetDepthBounds) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetDepthBounds_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetDepthBounds(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetDepthBounds_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetStencilCompareMask(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetStencilCompareMask args;

    if (!ctx->dispatch_vkCmdSetStencilCompareMask) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetStencilCompareMask_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetStencilCompareMask(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetStencilCompareMask_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetStencilWriteMask(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetStencilWriteMask args;

    if (!ctx->dispatch_vkCmdSetStencilWriteMask) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetStencilWriteMask_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetStencilWriteMask(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetStencilWriteMask_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetStencilReference(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetStencilReference args;

    if (!ctx->dispatch_vkCmdSetStencilReference) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetStencilReference_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetStencilReference(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetStencilReference_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBindDescriptorSets(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBindDescriptorSets args;

    if (!ctx->dispatch_vkCmdBindDescriptorSets) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBindDescriptorSets_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBindDescriptorSets(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBindDescriptorSets_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBindIndexBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBindIndexBuffer args;

    if (!ctx->dispatch_vkCmdBindIndexBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBindIndexBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBindIndexBuffer(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBindIndexBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBindVertexBuffers(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBindVertexBuffers args;

    if (!ctx->dispatch_vkCmdBindVertexBuffers) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBindVertexBuffers_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBindVertexBuffers(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBindVertexBuffers_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDraw(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDraw args;

    if (!ctx->dispatch_vkCmdDraw) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDraw_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDraw(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDraw_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDrawIndexed(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDrawIndexed args;

    if (!ctx->dispatch_vkCmdDrawIndexed) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDrawIndexed_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDrawIndexed(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDrawIndexed_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDrawIndirect(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDrawIndirect args;

    if (!ctx->dispatch_vkCmdDrawIndirect) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDrawIndirect_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDrawIndirect(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDrawIndirect_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDrawIndexedIndirect(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDrawIndexedIndirect args;

    if (!ctx->dispatch_vkCmdDrawIndexedIndirect) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDrawIndexedIndirect_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDrawIndexedIndirect(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDrawIndexedIndirect_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDispatch(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDispatch args;

    if (!ctx->dispatch_vkCmdDispatch) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDispatch_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDispatch(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDispatch_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDispatchIndirect(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDispatchIndirect args;

    if (!ctx->dispatch_vkCmdDispatchIndirect) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDispatchIndirect_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDispatchIndirect(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDispatchIndirect_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdCopyBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdCopyBuffer args;

    if (!ctx->dispatch_vkCmdCopyBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdCopyBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdCopyBuffer(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdCopyBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdCopyImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdCopyImage args;

    if (!ctx->dispatch_vkCmdCopyImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdCopyImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdCopyImage(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdCopyImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBlitImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBlitImage args;

    if (!ctx->dispatch_vkCmdBlitImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBlitImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBlitImage(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBlitImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdCopyBufferToImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdCopyBufferToImage args;

    if (!ctx->dispatch_vkCmdCopyBufferToImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdCopyBufferToImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdCopyBufferToImage(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdCopyBufferToImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdCopyImageToBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdCopyImageToBuffer args;

    if (!ctx->dispatch_vkCmdCopyImageToBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdCopyImageToBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdCopyImageToBuffer(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdCopyImageToBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdUpdateBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdUpdateBuffer args;

    if (!ctx->dispatch_vkCmdUpdateBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdUpdateBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdUpdateBuffer(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdUpdateBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdFillBuffer(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdFillBuffer args;

    if (!ctx->dispatch_vkCmdFillBuffer) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdFillBuffer_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdFillBuffer(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdFillBuffer_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdClearColorImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdClearColorImage args;

    if (!ctx->dispatch_vkCmdClearColorImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdClearColorImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdClearColorImage(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdClearColorImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdClearDepthStencilImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdClearDepthStencilImage args;

    if (!ctx->dispatch_vkCmdClearDepthStencilImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdClearDepthStencilImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdClearDepthStencilImage(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdClearDepthStencilImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdClearAttachments(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdClearAttachments args;

    if (!ctx->dispatch_vkCmdClearAttachments) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdClearAttachments_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdClearAttachments(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdClearAttachments_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdResolveImage(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdResolveImage args;

    if (!ctx->dispatch_vkCmdResolveImage) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdResolveImage_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdResolveImage(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdResolveImage_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetEvent args;

    if (!ctx->dispatch_vkCmdSetEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetEvent_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetEvent(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdResetEvent(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdResetEvent args;

    if (!ctx->dispatch_vkCmdResetEvent) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdResetEvent_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdResetEvent(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdResetEvent_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdWaitEvents(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdWaitEvents args;

    if (!ctx->dispatch_vkCmdWaitEvents) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdWaitEvents_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdWaitEvents(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdWaitEvents_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdPipelineBarrier(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdPipelineBarrier args;

    if (!ctx->dispatch_vkCmdPipelineBarrier) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdPipelineBarrier_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdPipelineBarrier(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdPipelineBarrier_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBeginQuery(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBeginQuery args;

    if (!ctx->dispatch_vkCmdBeginQuery) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBeginQuery_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBeginQuery(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBeginQuery_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdEndQuery(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdEndQuery args;

    if (!ctx->dispatch_vkCmdEndQuery) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdEndQuery_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdEndQuery(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdEndQuery_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdResetQueryPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdResetQueryPool args;

    if (!ctx->dispatch_vkCmdResetQueryPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdResetQueryPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdResetQueryPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdResetQueryPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdWriteTimestamp(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdWriteTimestamp args;

    if (!ctx->dispatch_vkCmdWriteTimestamp) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdWriteTimestamp_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdWriteTimestamp(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdWriteTimestamp_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdCopyQueryPoolResults(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdCopyQueryPoolResults args;

    if (!ctx->dispatch_vkCmdCopyQueryPoolResults) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdCopyQueryPoolResults_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdCopyQueryPoolResults(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdCopyQueryPoolResults_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdPushConstants(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdPushConstants args;

    if (!ctx->dispatch_vkCmdPushConstants) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdPushConstants_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdPushConstants(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdPushConstants_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBeginRenderPass(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBeginRenderPass args;

    if (!ctx->dispatch_vkCmdBeginRenderPass) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBeginRenderPass_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBeginRenderPass(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBeginRenderPass_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdNextSubpass(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdNextSubpass args;

    if (!ctx->dispatch_vkCmdNextSubpass) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdNextSubpass_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdNextSubpass(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdNextSubpass_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdEndRenderPass(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdEndRenderPass args;

    if (!ctx->dispatch_vkCmdEndRenderPass) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdEndRenderPass_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdEndRenderPass(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdEndRenderPass_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdExecuteCommands(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdExecuteCommands args;

    if (!ctx->dispatch_vkCmdExecuteCommands) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdExecuteCommands_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdExecuteCommands(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdExecuteCommands_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceFeatures2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceFeatures2 args;

    if (!ctx->dispatch_vkGetPhysicalDeviceFeatures2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceFeatures2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceFeatures2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceFeatures2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceProperties2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceProperties2 args;

    if (!ctx->dispatch_vkGetPhysicalDeviceProperties2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceProperties2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceProperties2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceProperties2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceFormatProperties2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceFormatProperties2 args;

    if (!ctx->dispatch_vkGetPhysicalDeviceFormatProperties2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceFormatProperties2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceFormatProperties2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceFormatProperties2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceImageFormatProperties2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceImageFormatProperties2 args;

    if (!ctx->dispatch_vkGetPhysicalDeviceImageFormatProperties2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceImageFormatProperties2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceImageFormatProperties2(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetPhysicalDeviceImageFormatProperties2 returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceImageFormatProperties2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceQueueFamilyProperties2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties2 args;

    if (!ctx->dispatch_vkGetPhysicalDeviceQueueFamilyProperties2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceQueueFamilyProperties2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceQueueFamilyProperties2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceQueueFamilyProperties2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceMemoryProperties2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceMemoryProperties2 args;

    if (!ctx->dispatch_vkGetPhysicalDeviceMemoryProperties2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceMemoryProperties2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceMemoryProperties2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceMemoryProperties2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceSparseImageFormatProperties2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties2 args;

    if (!ctx->dispatch_vkGetPhysicalDeviceSparseImageFormatProperties2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceSparseImageFormatProperties2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceSparseImageFormatProperties2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceSparseImageFormatProperties2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkTrimCommandPool(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkTrimCommandPool args;

    if (!ctx->dispatch_vkTrimCommandPool) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkTrimCommandPool_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkTrimCommandPool(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkTrimCommandPool_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceExternalBufferProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceExternalBufferProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceExternalBufferProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceExternalBufferProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceExternalBufferProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceExternalBufferProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceExternalSemaphoreProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceExternalSemaphoreProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceExternalSemaphoreProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceExternalSemaphoreProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceExternalSemaphoreProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceExternalSemaphoreProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetPhysicalDeviceExternalFenceProperties(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetPhysicalDeviceExternalFenceProperties args;

    if (!ctx->dispatch_vkGetPhysicalDeviceExternalFenceProperties) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetPhysicalDeviceExternalFenceProperties_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetPhysicalDeviceExternalFenceProperties(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetPhysicalDeviceExternalFenceProperties_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkEnumeratePhysicalDeviceGroups(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkEnumeratePhysicalDeviceGroups args;

    if (!ctx->dispatch_vkEnumeratePhysicalDeviceGroups) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkEnumeratePhysicalDeviceGroups_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkEnumeratePhysicalDeviceGroups(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkEnumeratePhysicalDeviceGroups returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkEnumeratePhysicalDeviceGroups_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetDeviceGroupPeerMemoryFeatures(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetDeviceGroupPeerMemoryFeatures args;

    if (!ctx->dispatch_vkGetDeviceGroupPeerMemoryFeatures) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetDeviceGroupPeerMemoryFeatures_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetDeviceGroupPeerMemoryFeatures(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetDeviceGroupPeerMemoryFeatures_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkBindBufferMemory2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkBindBufferMemory2 args;

    if (!ctx->dispatch_vkBindBufferMemory2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkBindBufferMemory2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkBindBufferMemory2(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkBindBufferMemory2 returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkBindBufferMemory2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkBindImageMemory2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkBindImageMemory2 args;

    if (!ctx->dispatch_vkBindImageMemory2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkBindImageMemory2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkBindImageMemory2(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkBindImageMemory2 returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkBindImageMemory2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdSetDeviceMask(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdSetDeviceMask args;

    if (!ctx->dispatch_vkCmdSetDeviceMask) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdSetDeviceMask_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdSetDeviceMask(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdSetDeviceMask_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDispatchBase(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDispatchBase args;

    if (!ctx->dispatch_vkCmdDispatchBase) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDispatchBase_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDispatchBase(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDispatchBase_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateDescriptorUpdateTemplate(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateDescriptorUpdateTemplate args;

    if (!ctx->dispatch_vkCreateDescriptorUpdateTemplate) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateDescriptorUpdateTemplate_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateDescriptorUpdateTemplate(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateDescriptorUpdateTemplate returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateDescriptorUpdateTemplate_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyDescriptorUpdateTemplate(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyDescriptorUpdateTemplate args;

    if (!ctx->dispatch_vkDestroyDescriptorUpdateTemplate) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyDescriptorUpdateTemplate_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyDescriptorUpdateTemplate(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyDescriptorUpdateTemplate_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetBufferMemoryRequirements2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetBufferMemoryRequirements2 args;

    if (!ctx->dispatch_vkGetBufferMemoryRequirements2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetBufferMemoryRequirements2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetBufferMemoryRequirements2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetBufferMemoryRequirements2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetImageMemoryRequirements2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetImageMemoryRequirements2 args;

    if (!ctx->dispatch_vkGetImageMemoryRequirements2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetImageMemoryRequirements2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetImageMemoryRequirements2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetImageMemoryRequirements2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetImageSparseMemoryRequirements2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetImageSparseMemoryRequirements2 args;

    if (!ctx->dispatch_vkGetImageSparseMemoryRequirements2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetImageSparseMemoryRequirements2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetImageSparseMemoryRequirements2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetImageSparseMemoryRequirements2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateSamplerYcbcrConversion(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateSamplerYcbcrConversion args;

    if (!ctx->dispatch_vkCreateSamplerYcbcrConversion) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateSamplerYcbcrConversion_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateSamplerYcbcrConversion(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateSamplerYcbcrConversion returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateSamplerYcbcrConversion_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroySamplerYcbcrConversion(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroySamplerYcbcrConversion args;

    if (!ctx->dispatch_vkDestroySamplerYcbcrConversion) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroySamplerYcbcrConversion_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroySamplerYcbcrConversion(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroySamplerYcbcrConversion_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetDeviceQueue2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetDeviceQueue2 args;

    if (!ctx->dispatch_vkGetDeviceQueue2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetDeviceQueue2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetDeviceQueue2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetDeviceQueue2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetDescriptorSetLayoutSupport(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetDescriptorSetLayoutSupport args;

    if (!ctx->dispatch_vkGetDescriptorSetLayoutSupport) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetDescriptorSetLayoutSupport_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetDescriptorSetLayoutSupport(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetDescriptorSetLayoutSupport_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateRenderPass2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateRenderPass2 args;

    if (!ctx->dispatch_vkCreateRenderPass2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateRenderPass2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateRenderPass2(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkCreateRenderPass2 returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateRenderPass2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBeginRenderPass2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBeginRenderPass2 args;

    if (!ctx->dispatch_vkCmdBeginRenderPass2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBeginRenderPass2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBeginRenderPass2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBeginRenderPass2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdNextSubpass2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdNextSubpass2 args;

    if (!ctx->dispatch_vkCmdNextSubpass2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdNextSubpass2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdNextSubpass2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdNextSubpass2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdEndRenderPass2(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdEndRenderPass2 args;

    if (!ctx->dispatch_vkCmdEndRenderPass2) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdEndRenderPass2_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdEndRenderPass2(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdEndRenderPass2_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetSemaphoreCounterValue(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetSemaphoreCounterValue args;

    if (!ctx->dispatch_vkGetSemaphoreCounterValue) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetSemaphoreCounterValue_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetSemaphoreCounterValue(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetSemaphoreCounterValue returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetSemaphoreCounterValue_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkWaitSemaphores(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkWaitSemaphores args;

    if (!ctx->dispatch_vkWaitSemaphores) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkWaitSemaphores_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkWaitSemaphores(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkWaitSemaphores returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkWaitSemaphores_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkSignalSemaphore(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkSignalSemaphore args;

    if (!ctx->dispatch_vkSignalSemaphore) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkSignalSemaphore_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkSignalSemaphore(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkSignalSemaphore returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkSignalSemaphore_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDrawIndirectCount(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDrawIndirectCount args;

    if (!ctx->dispatch_vkCmdDrawIndirectCount) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDrawIndirectCount_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDrawIndirectCount(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDrawIndirectCount_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDrawIndexedIndirectCount(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDrawIndexedIndirectCount args;

    if (!ctx->dispatch_vkCmdDrawIndexedIndirectCount) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDrawIndexedIndirectCount_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDrawIndexedIndirectCount(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDrawIndexedIndirectCount_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBindTransformFeedbackBuffersEXT(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBindTransformFeedbackBuffersEXT args;

    if (!ctx->dispatch_vkCmdBindTransformFeedbackBuffersEXT) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBindTransformFeedbackBuffersEXT_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBindTransformFeedbackBuffersEXT(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBindTransformFeedbackBuffersEXT_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBeginTransformFeedbackEXT(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBeginTransformFeedbackEXT args;

    if (!ctx->dispatch_vkCmdBeginTransformFeedbackEXT) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBeginTransformFeedbackEXT_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBeginTransformFeedbackEXT(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBeginTransformFeedbackEXT_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdEndTransformFeedbackEXT(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdEndTransformFeedbackEXT args;

    if (!ctx->dispatch_vkCmdEndTransformFeedbackEXT) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdEndTransformFeedbackEXT_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdEndTransformFeedbackEXT(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdEndTransformFeedbackEXT_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdBeginQueryIndexedEXT(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdBeginQueryIndexedEXT args;

    if (!ctx->dispatch_vkCmdBeginQueryIndexedEXT) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdBeginQueryIndexedEXT_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdBeginQueryIndexedEXT(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdBeginQueryIndexedEXT_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdEndQueryIndexedEXT(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdEndQueryIndexedEXT args;

    if (!ctx->dispatch_vkCmdEndQueryIndexedEXT) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdEndQueryIndexedEXT_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdEndQueryIndexedEXT(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdEndQueryIndexedEXT_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCmdDrawIndirectByteCountEXT(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCmdDrawIndirectByteCountEXT args;

    if (!ctx->dispatch_vkCmdDrawIndirectByteCountEXT) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCmdDrawIndirectByteCountEXT_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCmdDrawIndirectByteCountEXT(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCmdDrawIndirectByteCountEXT_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetImageDrmFormatModifierPropertiesEXT(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetImageDrmFormatModifierPropertiesEXT args;

    if (!ctx->dispatch_vkGetImageDrmFormatModifierPropertiesEXT) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetImageDrmFormatModifierPropertiesEXT_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetImageDrmFormatModifierPropertiesEXT(ctx, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && args.ret < VK_SUCCESS) {
        switch (args.ret) {
        case VK_ERROR_FORMAT_NOT_SUPPORTED:
            break;
        default:
            vn_dispatch_debug_log(ctx, "vkGetImageDrmFormatModifierPropertiesEXT returned %d", args.ret);
            break;
        }
    }

    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetImageDrmFormatModifierPropertiesEXT_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetBufferOpaqueCaptureAddress(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetBufferOpaqueCaptureAddress args;

    if (!ctx->dispatch_vkGetBufferOpaqueCaptureAddress) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetBufferOpaqueCaptureAddress_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetBufferOpaqueCaptureAddress(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetBufferOpaqueCaptureAddress_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetBufferDeviceAddress(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetBufferDeviceAddress args;

    if (!ctx->dispatch_vkGetBufferDeviceAddress) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetBufferDeviceAddress_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetBufferDeviceAddress(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetBufferDeviceAddress_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkGetDeviceMemoryOpaqueCaptureAddress(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkGetDeviceMemoryOpaqueCaptureAddress args;

    if (!ctx->dispatch_vkGetDeviceMemoryOpaqueCaptureAddress) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkGetDeviceMemoryOpaqueCaptureAddress_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkGetDeviceMemoryOpaqueCaptureAddress(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkGetDeviceMemoryOpaqueCaptureAddress_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkSetReplyCommandStreamMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkSetReplyCommandStreamMESA args;

    if (!ctx->dispatch_vkSetReplyCommandStreamMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkSetReplyCommandStreamMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkSetReplyCommandStreamMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkSetReplyCommandStreamMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkSeekReplyCommandStreamMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkSeekReplyCommandStreamMESA args;

    if (!ctx->dispatch_vkSeekReplyCommandStreamMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkSeekReplyCommandStreamMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkSeekReplyCommandStreamMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkSeekReplyCommandStreamMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkExecuteCommandStreamsMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkExecuteCommandStreamsMESA args;

    if (!ctx->dispatch_vkExecuteCommandStreamsMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkExecuteCommandStreamsMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkExecuteCommandStreamsMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkExecuteCommandStreamsMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkCreateRingMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkCreateRingMESA args;

    if (!ctx->dispatch_vkCreateRingMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkCreateRingMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkCreateRingMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkCreateRingMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkDestroyRingMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkDestroyRingMESA args;

    if (!ctx->dispatch_vkDestroyRingMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkDestroyRingMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkDestroyRingMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkDestroyRingMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkNotifyRingMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkNotifyRingMESA args;

    if (!ctx->dispatch_vkNotifyRingMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkNotifyRingMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkNotifyRingMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkNotifyRingMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static inline void vn_dispatch_vkWriteRingExtraMESA(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags)
{
    struct vn_command_vkWriteRingExtraMESA args;

    if (!ctx->dispatch_vkWriteRingExtraMESA) {
        vn_cs_decoder_set_fatal(ctx->decoder);
        return;
    }

    vn_decode_vkWriteRingExtraMESA_args_temp(ctx->decoder, &args);

    if (!vn_cs_decoder_get_fatal(ctx->decoder))
        ctx->dispatch_vkWriteRingExtraMESA(ctx, &args);


    if (!vn_cs_decoder_get_fatal(ctx->decoder) && (flags & VK_COMMAND_GENERATE_REPLY_BIT_EXT))
       vn_encode_vkWriteRingExtraMESA_reply(ctx->encoder, &args);

    vn_cs_decoder_reset_temp_pool(ctx->decoder);
}

static void (*const vn_dispatch_table[192])(struct vn_dispatch_context *ctx, VkCommandFlagsEXT flags) = {
    [VK_COMMAND_TYPE_vkCreateInstance_EXT] = vn_dispatch_vkCreateInstance,
    [VK_COMMAND_TYPE_vkDestroyInstance_EXT] = vn_dispatch_vkDestroyInstance,
    [VK_COMMAND_TYPE_vkEnumeratePhysicalDevices_EXT] = vn_dispatch_vkEnumeratePhysicalDevices,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceProperties,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceQueueFamilyProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceQueueFamilyProperties,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceMemoryProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceMemoryProperties,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceFeatures_EXT] = vn_dispatch_vkGetPhysicalDeviceFeatures,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceFormatProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceFormatProperties,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceImageFormatProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceImageFormatProperties,
    [VK_COMMAND_TYPE_vkCreateDevice_EXT] = vn_dispatch_vkCreateDevice,
    [VK_COMMAND_TYPE_vkDestroyDevice_EXT] = vn_dispatch_vkDestroyDevice,
    [VK_COMMAND_TYPE_vkEnumerateInstanceVersion_EXT] = vn_dispatch_vkEnumerateInstanceVersion,
    [VK_COMMAND_TYPE_vkEnumerateInstanceLayerProperties_EXT] = vn_dispatch_vkEnumerateInstanceLayerProperties,
    [VK_COMMAND_TYPE_vkEnumerateInstanceExtensionProperties_EXT] = vn_dispatch_vkEnumerateInstanceExtensionProperties,
    [VK_COMMAND_TYPE_vkEnumerateDeviceLayerProperties_EXT] = vn_dispatch_vkEnumerateDeviceLayerProperties,
    [VK_COMMAND_TYPE_vkEnumerateDeviceExtensionProperties_EXT] = vn_dispatch_vkEnumerateDeviceExtensionProperties,
    [VK_COMMAND_TYPE_vkGetDeviceQueue_EXT] = vn_dispatch_vkGetDeviceQueue,
    [VK_COMMAND_TYPE_vkQueueSubmit_EXT] = vn_dispatch_vkQueueSubmit,
    [VK_COMMAND_TYPE_vkQueueWaitIdle_EXT] = vn_dispatch_vkQueueWaitIdle,
    [VK_COMMAND_TYPE_vkDeviceWaitIdle_EXT] = vn_dispatch_vkDeviceWaitIdle,
    [VK_COMMAND_TYPE_vkAllocateMemory_EXT] = vn_dispatch_vkAllocateMemory,
    [VK_COMMAND_TYPE_vkFreeMemory_EXT] = vn_dispatch_vkFreeMemory,
    [VK_COMMAND_TYPE_vkUnmapMemory_EXT] = vn_dispatch_vkUnmapMemory,
    [VK_COMMAND_TYPE_vkFlushMappedMemoryRanges_EXT] = vn_dispatch_vkFlushMappedMemoryRanges,
    [VK_COMMAND_TYPE_vkInvalidateMappedMemoryRanges_EXT] = vn_dispatch_vkInvalidateMappedMemoryRanges,
    [VK_COMMAND_TYPE_vkGetDeviceMemoryCommitment_EXT] = vn_dispatch_vkGetDeviceMemoryCommitment,
    [VK_COMMAND_TYPE_vkGetBufferMemoryRequirements_EXT] = vn_dispatch_vkGetBufferMemoryRequirements,
    [VK_COMMAND_TYPE_vkBindBufferMemory_EXT] = vn_dispatch_vkBindBufferMemory,
    [VK_COMMAND_TYPE_vkGetImageMemoryRequirements_EXT] = vn_dispatch_vkGetImageMemoryRequirements,
    [VK_COMMAND_TYPE_vkBindImageMemory_EXT] = vn_dispatch_vkBindImageMemory,
    [VK_COMMAND_TYPE_vkGetImageSparseMemoryRequirements_EXT] = vn_dispatch_vkGetImageSparseMemoryRequirements,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceSparseImageFormatProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceSparseImageFormatProperties,
    [VK_COMMAND_TYPE_vkQueueBindSparse_EXT] = vn_dispatch_vkQueueBindSparse,
    [VK_COMMAND_TYPE_vkCreateFence_EXT] = vn_dispatch_vkCreateFence,
    [VK_COMMAND_TYPE_vkDestroyFence_EXT] = vn_dispatch_vkDestroyFence,
    [VK_COMMAND_TYPE_vkResetFences_EXT] = vn_dispatch_vkResetFences,
    [VK_COMMAND_TYPE_vkGetFenceStatus_EXT] = vn_dispatch_vkGetFenceStatus,
    [VK_COMMAND_TYPE_vkWaitForFences_EXT] = vn_dispatch_vkWaitForFences,
    [VK_COMMAND_TYPE_vkCreateSemaphore_EXT] = vn_dispatch_vkCreateSemaphore,
    [VK_COMMAND_TYPE_vkDestroySemaphore_EXT] = vn_dispatch_vkDestroySemaphore,
    [VK_COMMAND_TYPE_vkCreateEvent_EXT] = vn_dispatch_vkCreateEvent,
    [VK_COMMAND_TYPE_vkDestroyEvent_EXT] = vn_dispatch_vkDestroyEvent,
    [VK_COMMAND_TYPE_vkGetEventStatus_EXT] = vn_dispatch_vkGetEventStatus,
    [VK_COMMAND_TYPE_vkSetEvent_EXT] = vn_dispatch_vkSetEvent,
    [VK_COMMAND_TYPE_vkResetEvent_EXT] = vn_dispatch_vkResetEvent,
    [VK_COMMAND_TYPE_vkCreateQueryPool_EXT] = vn_dispatch_vkCreateQueryPool,
    [VK_COMMAND_TYPE_vkDestroyQueryPool_EXT] = vn_dispatch_vkDestroyQueryPool,
    [VK_COMMAND_TYPE_vkGetQueryPoolResults_EXT] = vn_dispatch_vkGetQueryPoolResults,
    [VK_COMMAND_TYPE_vkResetQueryPool_EXT] = vn_dispatch_vkResetQueryPool,
    [VK_COMMAND_TYPE_vkCreateBuffer_EXT] = vn_dispatch_vkCreateBuffer,
    [VK_COMMAND_TYPE_vkDestroyBuffer_EXT] = vn_dispatch_vkDestroyBuffer,
    [VK_COMMAND_TYPE_vkCreateBufferView_EXT] = vn_dispatch_vkCreateBufferView,
    [VK_COMMAND_TYPE_vkDestroyBufferView_EXT] = vn_dispatch_vkDestroyBufferView,
    [VK_COMMAND_TYPE_vkCreateImage_EXT] = vn_dispatch_vkCreateImage,
    [VK_COMMAND_TYPE_vkDestroyImage_EXT] = vn_dispatch_vkDestroyImage,
    [VK_COMMAND_TYPE_vkGetImageSubresourceLayout_EXT] = vn_dispatch_vkGetImageSubresourceLayout,
    [VK_COMMAND_TYPE_vkCreateImageView_EXT] = vn_dispatch_vkCreateImageView,
    [VK_COMMAND_TYPE_vkDestroyImageView_EXT] = vn_dispatch_vkDestroyImageView,
    [VK_COMMAND_TYPE_vkCreateShaderModule_EXT] = vn_dispatch_vkCreateShaderModule,
    [VK_COMMAND_TYPE_vkDestroyShaderModule_EXT] = vn_dispatch_vkDestroyShaderModule,
    [VK_COMMAND_TYPE_vkCreatePipelineCache_EXT] = vn_dispatch_vkCreatePipelineCache,
    [VK_COMMAND_TYPE_vkDestroyPipelineCache_EXT] = vn_dispatch_vkDestroyPipelineCache,
    [VK_COMMAND_TYPE_vkGetPipelineCacheData_EXT] = vn_dispatch_vkGetPipelineCacheData,
    [VK_COMMAND_TYPE_vkMergePipelineCaches_EXT] = vn_dispatch_vkMergePipelineCaches,
    [VK_COMMAND_TYPE_vkCreateGraphicsPipelines_EXT] = vn_dispatch_vkCreateGraphicsPipelines,
    [VK_COMMAND_TYPE_vkCreateComputePipelines_EXT] = vn_dispatch_vkCreateComputePipelines,
    [VK_COMMAND_TYPE_vkDestroyPipeline_EXT] = vn_dispatch_vkDestroyPipeline,
    [VK_COMMAND_TYPE_vkCreatePipelineLayout_EXT] = vn_dispatch_vkCreatePipelineLayout,
    [VK_COMMAND_TYPE_vkDestroyPipelineLayout_EXT] = vn_dispatch_vkDestroyPipelineLayout,
    [VK_COMMAND_TYPE_vkCreateSampler_EXT] = vn_dispatch_vkCreateSampler,
    [VK_COMMAND_TYPE_vkDestroySampler_EXT] = vn_dispatch_vkDestroySampler,
    [VK_COMMAND_TYPE_vkCreateDescriptorSetLayout_EXT] = vn_dispatch_vkCreateDescriptorSetLayout,
    [VK_COMMAND_TYPE_vkDestroyDescriptorSetLayout_EXT] = vn_dispatch_vkDestroyDescriptorSetLayout,
    [VK_COMMAND_TYPE_vkCreateDescriptorPool_EXT] = vn_dispatch_vkCreateDescriptorPool,
    [VK_COMMAND_TYPE_vkDestroyDescriptorPool_EXT] = vn_dispatch_vkDestroyDescriptorPool,
    [VK_COMMAND_TYPE_vkResetDescriptorPool_EXT] = vn_dispatch_vkResetDescriptorPool,
    [VK_COMMAND_TYPE_vkAllocateDescriptorSets_EXT] = vn_dispatch_vkAllocateDescriptorSets,
    [VK_COMMAND_TYPE_vkFreeDescriptorSets_EXT] = vn_dispatch_vkFreeDescriptorSets,
    [VK_COMMAND_TYPE_vkUpdateDescriptorSets_EXT] = vn_dispatch_vkUpdateDescriptorSets,
    [VK_COMMAND_TYPE_vkCreateFramebuffer_EXT] = vn_dispatch_vkCreateFramebuffer,
    [VK_COMMAND_TYPE_vkDestroyFramebuffer_EXT] = vn_dispatch_vkDestroyFramebuffer,
    [VK_COMMAND_TYPE_vkCreateRenderPass_EXT] = vn_dispatch_vkCreateRenderPass,
    [VK_COMMAND_TYPE_vkDestroyRenderPass_EXT] = vn_dispatch_vkDestroyRenderPass,
    [VK_COMMAND_TYPE_vkGetRenderAreaGranularity_EXT] = vn_dispatch_vkGetRenderAreaGranularity,
    [VK_COMMAND_TYPE_vkCreateCommandPool_EXT] = vn_dispatch_vkCreateCommandPool,
    [VK_COMMAND_TYPE_vkDestroyCommandPool_EXT] = vn_dispatch_vkDestroyCommandPool,
    [VK_COMMAND_TYPE_vkResetCommandPool_EXT] = vn_dispatch_vkResetCommandPool,
    [VK_COMMAND_TYPE_vkAllocateCommandBuffers_EXT] = vn_dispatch_vkAllocateCommandBuffers,
    [VK_COMMAND_TYPE_vkFreeCommandBuffers_EXT] = vn_dispatch_vkFreeCommandBuffers,
    [VK_COMMAND_TYPE_vkBeginCommandBuffer_EXT] = vn_dispatch_vkBeginCommandBuffer,
    [VK_COMMAND_TYPE_vkEndCommandBuffer_EXT] = vn_dispatch_vkEndCommandBuffer,
    [VK_COMMAND_TYPE_vkResetCommandBuffer_EXT] = vn_dispatch_vkResetCommandBuffer,
    [VK_COMMAND_TYPE_vkCmdBindPipeline_EXT] = vn_dispatch_vkCmdBindPipeline,
    [VK_COMMAND_TYPE_vkCmdSetViewport_EXT] = vn_dispatch_vkCmdSetViewport,
    [VK_COMMAND_TYPE_vkCmdSetScissor_EXT] = vn_dispatch_vkCmdSetScissor,
    [VK_COMMAND_TYPE_vkCmdSetLineWidth_EXT] = vn_dispatch_vkCmdSetLineWidth,
    [VK_COMMAND_TYPE_vkCmdSetDepthBias_EXT] = vn_dispatch_vkCmdSetDepthBias,
    [VK_COMMAND_TYPE_vkCmdSetBlendConstants_EXT] = vn_dispatch_vkCmdSetBlendConstants,
    [VK_COMMAND_TYPE_vkCmdSetDepthBounds_EXT] = vn_dispatch_vkCmdSetDepthBounds,
    [VK_COMMAND_TYPE_vkCmdSetStencilCompareMask_EXT] = vn_dispatch_vkCmdSetStencilCompareMask,
    [VK_COMMAND_TYPE_vkCmdSetStencilWriteMask_EXT] = vn_dispatch_vkCmdSetStencilWriteMask,
    [VK_COMMAND_TYPE_vkCmdSetStencilReference_EXT] = vn_dispatch_vkCmdSetStencilReference,
    [VK_COMMAND_TYPE_vkCmdBindDescriptorSets_EXT] = vn_dispatch_vkCmdBindDescriptorSets,
    [VK_COMMAND_TYPE_vkCmdBindIndexBuffer_EXT] = vn_dispatch_vkCmdBindIndexBuffer,
    [VK_COMMAND_TYPE_vkCmdBindVertexBuffers_EXT] = vn_dispatch_vkCmdBindVertexBuffers,
    [VK_COMMAND_TYPE_vkCmdDraw_EXT] = vn_dispatch_vkCmdDraw,
    [VK_COMMAND_TYPE_vkCmdDrawIndexed_EXT] = vn_dispatch_vkCmdDrawIndexed,
    [VK_COMMAND_TYPE_vkCmdDrawIndirect_EXT] = vn_dispatch_vkCmdDrawIndirect,
    [VK_COMMAND_TYPE_vkCmdDrawIndexedIndirect_EXT] = vn_dispatch_vkCmdDrawIndexedIndirect,
    [VK_COMMAND_TYPE_vkCmdDispatch_EXT] = vn_dispatch_vkCmdDispatch,
    [VK_COMMAND_TYPE_vkCmdDispatchIndirect_EXT] = vn_dispatch_vkCmdDispatchIndirect,
    [VK_COMMAND_TYPE_vkCmdCopyBuffer_EXT] = vn_dispatch_vkCmdCopyBuffer,
    [VK_COMMAND_TYPE_vkCmdCopyImage_EXT] = vn_dispatch_vkCmdCopyImage,
    [VK_COMMAND_TYPE_vkCmdBlitImage_EXT] = vn_dispatch_vkCmdBlitImage,
    [VK_COMMAND_TYPE_vkCmdCopyBufferToImage_EXT] = vn_dispatch_vkCmdCopyBufferToImage,
    [VK_COMMAND_TYPE_vkCmdCopyImageToBuffer_EXT] = vn_dispatch_vkCmdCopyImageToBuffer,
    [VK_COMMAND_TYPE_vkCmdUpdateBuffer_EXT] = vn_dispatch_vkCmdUpdateBuffer,
    [VK_COMMAND_TYPE_vkCmdFillBuffer_EXT] = vn_dispatch_vkCmdFillBuffer,
    [VK_COMMAND_TYPE_vkCmdClearColorImage_EXT] = vn_dispatch_vkCmdClearColorImage,
    [VK_COMMAND_TYPE_vkCmdClearDepthStencilImage_EXT] = vn_dispatch_vkCmdClearDepthStencilImage,
    [VK_COMMAND_TYPE_vkCmdClearAttachments_EXT] = vn_dispatch_vkCmdClearAttachments,
    [VK_COMMAND_TYPE_vkCmdResolveImage_EXT] = vn_dispatch_vkCmdResolveImage,
    [VK_COMMAND_TYPE_vkCmdSetEvent_EXT] = vn_dispatch_vkCmdSetEvent,
    [VK_COMMAND_TYPE_vkCmdResetEvent_EXT] = vn_dispatch_vkCmdResetEvent,
    [VK_COMMAND_TYPE_vkCmdWaitEvents_EXT] = vn_dispatch_vkCmdWaitEvents,
    [VK_COMMAND_TYPE_vkCmdPipelineBarrier_EXT] = vn_dispatch_vkCmdPipelineBarrier,
    [VK_COMMAND_TYPE_vkCmdBeginQuery_EXT] = vn_dispatch_vkCmdBeginQuery,
    [VK_COMMAND_TYPE_vkCmdEndQuery_EXT] = vn_dispatch_vkCmdEndQuery,
    [VK_COMMAND_TYPE_vkCmdResetQueryPool_EXT] = vn_dispatch_vkCmdResetQueryPool,
    [VK_COMMAND_TYPE_vkCmdWriteTimestamp_EXT] = vn_dispatch_vkCmdWriteTimestamp,
    [VK_COMMAND_TYPE_vkCmdCopyQueryPoolResults_EXT] = vn_dispatch_vkCmdCopyQueryPoolResults,
    [VK_COMMAND_TYPE_vkCmdPushConstants_EXT] = vn_dispatch_vkCmdPushConstants,
    [VK_COMMAND_TYPE_vkCmdBeginRenderPass_EXT] = vn_dispatch_vkCmdBeginRenderPass,
    [VK_COMMAND_TYPE_vkCmdNextSubpass_EXT] = vn_dispatch_vkCmdNextSubpass,
    [VK_COMMAND_TYPE_vkCmdEndRenderPass_EXT] = vn_dispatch_vkCmdEndRenderPass,
    [VK_COMMAND_TYPE_vkCmdExecuteCommands_EXT] = vn_dispatch_vkCmdExecuteCommands,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceFeatures2_EXT] = vn_dispatch_vkGetPhysicalDeviceFeatures2,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceProperties2_EXT] = vn_dispatch_vkGetPhysicalDeviceProperties2,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceFormatProperties2_EXT] = vn_dispatch_vkGetPhysicalDeviceFormatProperties2,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceImageFormatProperties2_EXT] = vn_dispatch_vkGetPhysicalDeviceImageFormatProperties2,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceQueueFamilyProperties2_EXT] = vn_dispatch_vkGetPhysicalDeviceQueueFamilyProperties2,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceMemoryProperties2_EXT] = vn_dispatch_vkGetPhysicalDeviceMemoryProperties2,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceSparseImageFormatProperties2_EXT] = vn_dispatch_vkGetPhysicalDeviceSparseImageFormatProperties2,
    [VK_COMMAND_TYPE_vkTrimCommandPool_EXT] = vn_dispatch_vkTrimCommandPool,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalBufferProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceExternalBufferProperties,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalSemaphoreProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceExternalSemaphoreProperties,
    [VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalFenceProperties_EXT] = vn_dispatch_vkGetPhysicalDeviceExternalFenceProperties,
    [VK_COMMAND_TYPE_vkEnumeratePhysicalDeviceGroups_EXT] = vn_dispatch_vkEnumeratePhysicalDeviceGroups,
    [VK_COMMAND_TYPE_vkGetDeviceGroupPeerMemoryFeatures_EXT] = vn_dispatch_vkGetDeviceGroupPeerMemoryFeatures,
    [VK_COMMAND_TYPE_vkBindBufferMemory2_EXT] = vn_dispatch_vkBindBufferMemory2,
    [VK_COMMAND_TYPE_vkBindImageMemory2_EXT] = vn_dispatch_vkBindImageMemory2,
    [VK_COMMAND_TYPE_vkCmdSetDeviceMask_EXT] = vn_dispatch_vkCmdSetDeviceMask,
    [VK_COMMAND_TYPE_vkCmdDispatchBase_EXT] = vn_dispatch_vkCmdDispatchBase,
    [VK_COMMAND_TYPE_vkCreateDescriptorUpdateTemplate_EXT] = vn_dispatch_vkCreateDescriptorUpdateTemplate,
    [VK_COMMAND_TYPE_vkDestroyDescriptorUpdateTemplate_EXT] = vn_dispatch_vkDestroyDescriptorUpdateTemplate,
    [VK_COMMAND_TYPE_vkGetBufferMemoryRequirements2_EXT] = vn_dispatch_vkGetBufferMemoryRequirements2,
    [VK_COMMAND_TYPE_vkGetImageMemoryRequirements2_EXT] = vn_dispatch_vkGetImageMemoryRequirements2,
    [VK_COMMAND_TYPE_vkGetImageSparseMemoryRequirements2_EXT] = vn_dispatch_vkGetImageSparseMemoryRequirements2,
    [VK_COMMAND_TYPE_vkCreateSamplerYcbcrConversion_EXT] = vn_dispatch_vkCreateSamplerYcbcrConversion,
    [VK_COMMAND_TYPE_vkDestroySamplerYcbcrConversion_EXT] = vn_dispatch_vkDestroySamplerYcbcrConversion,
    [VK_COMMAND_TYPE_vkGetDeviceQueue2_EXT] = vn_dispatch_vkGetDeviceQueue2,
    [VK_COMMAND_TYPE_vkGetDescriptorSetLayoutSupport_EXT] = vn_dispatch_vkGetDescriptorSetLayoutSupport,
    [VK_COMMAND_TYPE_vkCreateRenderPass2_EXT] = vn_dispatch_vkCreateRenderPass2,
    [VK_COMMAND_TYPE_vkCmdBeginRenderPass2_EXT] = vn_dispatch_vkCmdBeginRenderPass2,
    [VK_COMMAND_TYPE_vkCmdNextSubpass2_EXT] = vn_dispatch_vkCmdNextSubpass2,
    [VK_COMMAND_TYPE_vkCmdEndRenderPass2_EXT] = vn_dispatch_vkCmdEndRenderPass2,
    [VK_COMMAND_TYPE_vkGetSemaphoreCounterValue_EXT] = vn_dispatch_vkGetSemaphoreCounterValue,
    [VK_COMMAND_TYPE_vkWaitSemaphores_EXT] = vn_dispatch_vkWaitSemaphores,
    [VK_COMMAND_TYPE_vkSignalSemaphore_EXT] = vn_dispatch_vkSignalSemaphore,
    [VK_COMMAND_TYPE_vkCmdDrawIndirectCount_EXT] = vn_dispatch_vkCmdDrawIndirectCount,
    [VK_COMMAND_TYPE_vkCmdDrawIndexedIndirectCount_EXT] = vn_dispatch_vkCmdDrawIndexedIndirectCount,
    [VK_COMMAND_TYPE_vkCmdBindTransformFeedbackBuffersEXT_EXT] = vn_dispatch_vkCmdBindTransformFeedbackBuffersEXT,
    [VK_COMMAND_TYPE_vkCmdBeginTransformFeedbackEXT_EXT] = vn_dispatch_vkCmdBeginTransformFeedbackEXT,
    [VK_COMMAND_TYPE_vkCmdEndTransformFeedbackEXT_EXT] = vn_dispatch_vkCmdEndTransformFeedbackEXT,
    [VK_COMMAND_TYPE_vkCmdBeginQueryIndexedEXT_EXT] = vn_dispatch_vkCmdBeginQueryIndexedEXT,
    [VK_COMMAND_TYPE_vkCmdEndQueryIndexedEXT_EXT] = vn_dispatch_vkCmdEndQueryIndexedEXT,
    [VK_COMMAND_TYPE_vkCmdDrawIndirectByteCountEXT_EXT] = vn_dispatch_vkCmdDrawIndirectByteCountEXT,
    [VK_COMMAND_TYPE_vkGetImageDrmFormatModifierPropertiesEXT_EXT] = vn_dispatch_vkGetImageDrmFormatModifierPropertiesEXT,
    [VK_COMMAND_TYPE_vkGetBufferOpaqueCaptureAddress_EXT] = vn_dispatch_vkGetBufferOpaqueCaptureAddress,
    [VK_COMMAND_TYPE_vkGetBufferDeviceAddress_EXT] = vn_dispatch_vkGetBufferDeviceAddress,
    [VK_COMMAND_TYPE_vkGetDeviceMemoryOpaqueCaptureAddress_EXT] = vn_dispatch_vkGetDeviceMemoryOpaqueCaptureAddress,
    [VK_COMMAND_TYPE_vkSetReplyCommandStreamMESA_EXT] = vn_dispatch_vkSetReplyCommandStreamMESA,
    [VK_COMMAND_TYPE_vkSeekReplyCommandStreamMESA_EXT] = vn_dispatch_vkSeekReplyCommandStreamMESA,
    [VK_COMMAND_TYPE_vkExecuteCommandStreamsMESA_EXT] = vn_dispatch_vkExecuteCommandStreamsMESA,
    [VK_COMMAND_TYPE_vkCreateRingMESA_EXT] = vn_dispatch_vkCreateRingMESA,
    [VK_COMMAND_TYPE_vkDestroyRingMESA_EXT] = vn_dispatch_vkDestroyRingMESA,
    [VK_COMMAND_TYPE_vkNotifyRingMESA_EXT] = vn_dispatch_vkNotifyRingMESA,
    [VK_COMMAND_TYPE_vkWriteRingExtraMESA_EXT] = vn_dispatch_vkWriteRingExtraMESA,
};

static inline void vn_dispatch_command(struct vn_dispatch_context *ctx)
{
    VkCommandTypeEXT cmd_type;
    VkCommandFlagsEXT cmd_flags;

    vn_decode_VkCommandTypeEXT(ctx->decoder, &cmd_type);
    vn_decode_VkFlags(ctx->decoder, &cmd_flags);

    if (cmd_type < 192 && vn_dispatch_table[cmd_type])
        vn_dispatch_table[cmd_type](ctx, cmd_flags);
    else
        vn_cs_decoder_set_fatal(ctx->decoder);

    if (vn_cs_decoder_get_fatal(ctx->decoder))
        vn_dispatch_debug_log(ctx, "%s resulted in CS error", vn_dispatch_command_name(cmd_type));
}

#endif /* VN_PROTOCOL_RENDERER_DISPATCHES_H */
