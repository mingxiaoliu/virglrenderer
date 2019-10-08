/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_STRUCTS_H
#define VN_PROTOCOL_RENDERER_STRUCTS_H

#include "vn_protocol_renderer_handles.h"

/*
 * These structs/unions are not included
 *
 *   VkBaseOutStructure
 *   VkBaseInStructure
 *   VkAllocationCallbacks
 */

/* struct VkOffset2D */

static inline void
vn_encode_VkOffset2D(struct vn_cs *cs, const VkOffset2D *val)
{
    vn_encode_int32_t(cs, &val->x);
    vn_encode_int32_t(cs, &val->y);
}

static inline void
vn_decode_VkOffset2D_temp(struct vn_cs *cs, VkOffset2D *val)
{
    vn_decode_int32_t(cs, &val->x);
    vn_decode_int32_t(cs, &val->y);
}

static inline void
vn_decode_VkOffset2D_partial_temp(struct vn_cs *cs, VkOffset2D *val)
{
    /* skip val->x */
    /* skip val->y */
}

static inline void
vn_replace_VkOffset2D_handle(VkOffset2D *val)
{
    /* skip val->x */
    /* skip val->y */
}

/* struct VkOffset3D */

static inline void
vn_decode_VkOffset3D_temp(struct vn_cs *cs, VkOffset3D *val)
{
    vn_decode_int32_t(cs, &val->x);
    vn_decode_int32_t(cs, &val->y);
    vn_decode_int32_t(cs, &val->z);
}

static inline void
vn_replace_VkOffset3D_handle(VkOffset3D *val)
{
    /* skip val->x */
    /* skip val->y */
    /* skip val->z */
}

/* struct VkExtent2D */

static inline void
vn_encode_VkExtent2D(struct vn_cs *cs, const VkExtent2D *val)
{
    vn_encode_uint32_t(cs, &val->width);
    vn_encode_uint32_t(cs, &val->height);
}

static inline void
vn_decode_VkExtent2D_temp(struct vn_cs *cs, VkExtent2D *val)
{
    vn_decode_uint32_t(cs, &val->width);
    vn_decode_uint32_t(cs, &val->height);
}

static inline void
vn_decode_VkExtent2D_partial_temp(struct vn_cs *cs, VkExtent2D *val)
{
    /* skip val->width */
    /* skip val->height */
}

static inline void
vn_replace_VkExtent2D_handle(VkExtent2D *val)
{
    /* skip val->width */
    /* skip val->height */
}

/* struct VkExtent3D */

static inline void
vn_encode_VkExtent3D(struct vn_cs *cs, const VkExtent3D *val)
{
    vn_encode_uint32_t(cs, &val->width);
    vn_encode_uint32_t(cs, &val->height);
    vn_encode_uint32_t(cs, &val->depth);
}

static inline void
vn_decode_VkExtent3D_temp(struct vn_cs *cs, VkExtent3D *val)
{
    vn_decode_uint32_t(cs, &val->width);
    vn_decode_uint32_t(cs, &val->height);
    vn_decode_uint32_t(cs, &val->depth);
}

static inline void
vn_decode_VkExtent3D_partial_temp(struct vn_cs *cs, VkExtent3D *val)
{
    /* skip val->width */
    /* skip val->height */
    /* skip val->depth */
}

static inline void
vn_replace_VkExtent3D_handle(VkExtent3D *val)
{
    /* skip val->width */
    /* skip val->height */
    /* skip val->depth */
}

/* struct VkViewport */

static inline void
vn_decode_VkViewport_temp(struct vn_cs *cs, VkViewport *val)
{
    vn_decode_float(cs, &val->x);
    vn_decode_float(cs, &val->y);
    vn_decode_float(cs, &val->width);
    vn_decode_float(cs, &val->height);
    vn_decode_float(cs, &val->minDepth);
    vn_decode_float(cs, &val->maxDepth);
}

static inline void
vn_replace_VkViewport_handle(VkViewport *val)
{
    /* skip val->x */
    /* skip val->y */
    /* skip val->width */
    /* skip val->height */
    /* skip val->minDepth */
    /* skip val->maxDepth */
}

/* struct VkRect2D */

static inline void
vn_encode_VkRect2D(struct vn_cs *cs, const VkRect2D *val)
{
    vn_encode_VkOffset2D(cs, &val->offset);
    vn_encode_VkExtent2D(cs, &val->extent);
}

static inline void
vn_decode_VkRect2D_temp(struct vn_cs *cs, VkRect2D *val)
{
    vn_decode_VkOffset2D_temp(cs, &val->offset);
    vn_decode_VkExtent2D_temp(cs, &val->extent);
}

static inline void
vn_decode_VkRect2D_partial_temp(struct vn_cs *cs, VkRect2D *val)
{
    vn_decode_VkOffset2D_partial_temp(cs, &val->offset);
    vn_decode_VkExtent2D_partial_temp(cs, &val->extent);
}

static inline void
vn_replace_VkRect2D_handle(VkRect2D *val)
{
    vn_replace_VkOffset2D_handle(&val->offset);
    vn_replace_VkExtent2D_handle(&val->extent);
}

/* struct VkClearRect */

static inline void
vn_decode_VkClearRect_temp(struct vn_cs *cs, VkClearRect *val)
{
    vn_decode_VkRect2D_temp(cs, &val->rect);
    vn_decode_uint32_t(cs, &val->baseArrayLayer);
    vn_decode_uint32_t(cs, &val->layerCount);
}

static inline void
vn_replace_VkClearRect_handle(VkClearRect *val)
{
    vn_replace_VkRect2D_handle(&val->rect);
    /* skip val->baseArrayLayer */
    /* skip val->layerCount */
}

/* struct VkComponentMapping */

static inline void
vn_encode_VkComponentMapping(struct vn_cs *cs, const VkComponentMapping *val)
{
    vn_encode_VkComponentSwizzle(cs, &val->r);
    vn_encode_VkComponentSwizzle(cs, &val->g);
    vn_encode_VkComponentSwizzle(cs, &val->b);
    vn_encode_VkComponentSwizzle(cs, &val->a);
}

static inline void
vn_decode_VkComponentMapping_temp(struct vn_cs *cs, VkComponentMapping *val)
{
    vn_decode_VkComponentSwizzle(cs, &val->r);
    vn_decode_VkComponentSwizzle(cs, &val->g);
    vn_decode_VkComponentSwizzle(cs, &val->b);
    vn_decode_VkComponentSwizzle(cs, &val->a);
}

static inline void
vn_decode_VkComponentMapping_partial_temp(struct vn_cs *cs, VkComponentMapping *val)
{
    /* skip val->r */
    /* skip val->g */
    /* skip val->b */
    /* skip val->a */
}

static inline void
vn_replace_VkComponentMapping_handle(VkComponentMapping *val)
{
    /* skip val->r */
    /* skip val->g */
    /* skip val->b */
    /* skip val->a */
}

/* struct VkPhysicalDeviceLimits */

static inline void
vn_encode_VkPhysicalDeviceLimits(struct vn_cs *cs, const VkPhysicalDeviceLimits *val)
{
    vn_encode_uint32_t(cs, &val->maxImageDimension1D);
    vn_encode_uint32_t(cs, &val->maxImageDimension2D);
    vn_encode_uint32_t(cs, &val->maxImageDimension3D);
    vn_encode_uint32_t(cs, &val->maxImageDimensionCube);
    vn_encode_uint32_t(cs, &val->maxImageArrayLayers);
    vn_encode_uint32_t(cs, &val->maxTexelBufferElements);
    vn_encode_uint32_t(cs, &val->maxUniformBufferRange);
    vn_encode_uint32_t(cs, &val->maxStorageBufferRange);
    vn_encode_uint32_t(cs, &val->maxPushConstantsSize);
    vn_encode_uint32_t(cs, &val->maxMemoryAllocationCount);
    vn_encode_uint32_t(cs, &val->maxSamplerAllocationCount);
    vn_encode_VkDeviceSize(cs, &val->bufferImageGranularity);
    vn_encode_VkDeviceSize(cs, &val->sparseAddressSpaceSize);
    vn_encode_uint32_t(cs, &val->maxBoundDescriptorSets);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorSamplers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUniformBuffers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorStorageBuffers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorSampledImages);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorStorageImages);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorInputAttachments);
    vn_encode_uint32_t(cs, &val->maxPerStageResources);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetSamplers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUniformBuffers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUniformBuffersDynamic);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetStorageBuffers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetStorageBuffersDynamic);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetSampledImages);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetStorageImages);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetInputAttachments);
    vn_encode_uint32_t(cs, &val->maxVertexInputAttributes);
    vn_encode_uint32_t(cs, &val->maxVertexInputBindings);
    vn_encode_uint32_t(cs, &val->maxVertexInputAttributeOffset);
    vn_encode_uint32_t(cs, &val->maxVertexInputBindingStride);
    vn_encode_uint32_t(cs, &val->maxVertexOutputComponents);
    vn_encode_uint32_t(cs, &val->maxTessellationGenerationLevel);
    vn_encode_uint32_t(cs, &val->maxTessellationPatchSize);
    vn_encode_uint32_t(cs, &val->maxTessellationControlPerVertexInputComponents);
    vn_encode_uint32_t(cs, &val->maxTessellationControlPerVertexOutputComponents);
    vn_encode_uint32_t(cs, &val->maxTessellationControlPerPatchOutputComponents);
    vn_encode_uint32_t(cs, &val->maxTessellationControlTotalOutputComponents);
    vn_encode_uint32_t(cs, &val->maxTessellationEvaluationInputComponents);
    vn_encode_uint32_t(cs, &val->maxTessellationEvaluationOutputComponents);
    vn_encode_uint32_t(cs, &val->maxGeometryShaderInvocations);
    vn_encode_uint32_t(cs, &val->maxGeometryInputComponents);
    vn_encode_uint32_t(cs, &val->maxGeometryOutputComponents);
    vn_encode_uint32_t(cs, &val->maxGeometryOutputVertices);
    vn_encode_uint32_t(cs, &val->maxGeometryTotalOutputComponents);
    vn_encode_uint32_t(cs, &val->maxFragmentInputComponents);
    vn_encode_uint32_t(cs, &val->maxFragmentOutputAttachments);
    vn_encode_uint32_t(cs, &val->maxFragmentDualSrcAttachments);
    vn_encode_uint32_t(cs, &val->maxFragmentCombinedOutputResources);
    vn_encode_uint32_t(cs, &val->maxComputeSharedMemorySize);
    vn_encode_array_size(cs, 3);
    vn_encode_uint32_t_array(cs, val->maxComputeWorkGroupCount, 3);
    vn_encode_uint32_t(cs, &val->maxComputeWorkGroupInvocations);
    vn_encode_array_size(cs, 3);
    vn_encode_uint32_t_array(cs, val->maxComputeWorkGroupSize, 3);
    vn_encode_uint32_t(cs, &val->subPixelPrecisionBits);
    vn_encode_uint32_t(cs, &val->subTexelPrecisionBits);
    vn_encode_uint32_t(cs, &val->mipmapPrecisionBits);
    vn_encode_uint32_t(cs, &val->maxDrawIndexedIndexValue);
    vn_encode_uint32_t(cs, &val->maxDrawIndirectCount);
    vn_encode_float(cs, &val->maxSamplerLodBias);
    vn_encode_float(cs, &val->maxSamplerAnisotropy);
    vn_encode_uint32_t(cs, &val->maxViewports);
    vn_encode_array_size(cs, 2);
    vn_encode_uint32_t_array(cs, val->maxViewportDimensions, 2);
    vn_encode_array_size(cs, 2);
    vn_encode_float_array(cs, val->viewportBoundsRange, 2);
    vn_encode_uint32_t(cs, &val->viewportSubPixelBits);
    vn_encode_size_t(cs, &val->minMemoryMapAlignment);
    vn_encode_VkDeviceSize(cs, &val->minTexelBufferOffsetAlignment);
    vn_encode_VkDeviceSize(cs, &val->minUniformBufferOffsetAlignment);
    vn_encode_VkDeviceSize(cs, &val->minStorageBufferOffsetAlignment);
    vn_encode_int32_t(cs, &val->minTexelOffset);
    vn_encode_uint32_t(cs, &val->maxTexelOffset);
    vn_encode_int32_t(cs, &val->minTexelGatherOffset);
    vn_encode_uint32_t(cs, &val->maxTexelGatherOffset);
    vn_encode_float(cs, &val->minInterpolationOffset);
    vn_encode_float(cs, &val->maxInterpolationOffset);
    vn_encode_uint32_t(cs, &val->subPixelInterpolationOffsetBits);
    vn_encode_uint32_t(cs, &val->maxFramebufferWidth);
    vn_encode_uint32_t(cs, &val->maxFramebufferHeight);
    vn_encode_uint32_t(cs, &val->maxFramebufferLayers);
    vn_encode_VkFlags(cs, &val->framebufferColorSampleCounts);
    vn_encode_VkFlags(cs, &val->framebufferDepthSampleCounts);
    vn_encode_VkFlags(cs, &val->framebufferStencilSampleCounts);
    vn_encode_VkFlags(cs, &val->framebufferNoAttachmentsSampleCounts);
    vn_encode_uint32_t(cs, &val->maxColorAttachments);
    vn_encode_VkFlags(cs, &val->sampledImageColorSampleCounts);
    vn_encode_VkFlags(cs, &val->sampledImageIntegerSampleCounts);
    vn_encode_VkFlags(cs, &val->sampledImageDepthSampleCounts);
    vn_encode_VkFlags(cs, &val->sampledImageStencilSampleCounts);
    vn_encode_VkFlags(cs, &val->storageImageSampleCounts);
    vn_encode_uint32_t(cs, &val->maxSampleMaskWords);
    vn_encode_VkBool32(cs, &val->timestampComputeAndGraphics);
    vn_encode_float(cs, &val->timestampPeriod);
    vn_encode_uint32_t(cs, &val->maxClipDistances);
    vn_encode_uint32_t(cs, &val->maxCullDistances);
    vn_encode_uint32_t(cs, &val->maxCombinedClipAndCullDistances);
    vn_encode_uint32_t(cs, &val->discreteQueuePriorities);
    vn_encode_array_size(cs, 2);
    vn_encode_float_array(cs, val->pointSizeRange, 2);
    vn_encode_array_size(cs, 2);
    vn_encode_float_array(cs, val->lineWidthRange, 2);
    vn_encode_float(cs, &val->pointSizeGranularity);
    vn_encode_float(cs, &val->lineWidthGranularity);
    vn_encode_VkBool32(cs, &val->strictLines);
    vn_encode_VkBool32(cs, &val->standardSampleLocations);
    vn_encode_VkDeviceSize(cs, &val->optimalBufferCopyOffsetAlignment);
    vn_encode_VkDeviceSize(cs, &val->optimalBufferCopyRowPitchAlignment);
    vn_encode_VkDeviceSize(cs, &val->nonCoherentAtomSize);
}

static inline void
vn_decode_VkPhysicalDeviceLimits_partial_temp(struct vn_cs *cs, VkPhysicalDeviceLimits *val)
{
    /* skip val->maxImageDimension1D */
    /* skip val->maxImageDimension2D */
    /* skip val->maxImageDimension3D */
    /* skip val->maxImageDimensionCube */
    /* skip val->maxImageArrayLayers */
    /* skip val->maxTexelBufferElements */
    /* skip val->maxUniformBufferRange */
    /* skip val->maxStorageBufferRange */
    /* skip val->maxPushConstantsSize */
    /* skip val->maxMemoryAllocationCount */
    /* skip val->maxSamplerAllocationCount */
    /* skip val->bufferImageGranularity */
    /* skip val->sparseAddressSpaceSize */
    /* skip val->maxBoundDescriptorSets */
    /* skip val->maxPerStageDescriptorSamplers */
    /* skip val->maxPerStageDescriptorUniformBuffers */
    /* skip val->maxPerStageDescriptorStorageBuffers */
    /* skip val->maxPerStageDescriptorSampledImages */
    /* skip val->maxPerStageDescriptorStorageImages */
    /* skip val->maxPerStageDescriptorInputAttachments */
    /* skip val->maxPerStageResources */
    /* skip val->maxDescriptorSetSamplers */
    /* skip val->maxDescriptorSetUniformBuffers */
    /* skip val->maxDescriptorSetUniformBuffersDynamic */
    /* skip val->maxDescriptorSetStorageBuffers */
    /* skip val->maxDescriptorSetStorageBuffersDynamic */
    /* skip val->maxDescriptorSetSampledImages */
    /* skip val->maxDescriptorSetStorageImages */
    /* skip val->maxDescriptorSetInputAttachments */
    /* skip val->maxVertexInputAttributes */
    /* skip val->maxVertexInputBindings */
    /* skip val->maxVertexInputAttributeOffset */
    /* skip val->maxVertexInputBindingStride */
    /* skip val->maxVertexOutputComponents */
    /* skip val->maxTessellationGenerationLevel */
    /* skip val->maxTessellationPatchSize */
    /* skip val->maxTessellationControlPerVertexInputComponents */
    /* skip val->maxTessellationControlPerVertexOutputComponents */
    /* skip val->maxTessellationControlPerPatchOutputComponents */
    /* skip val->maxTessellationControlTotalOutputComponents */
    /* skip val->maxTessellationEvaluationInputComponents */
    /* skip val->maxTessellationEvaluationOutputComponents */
    /* skip val->maxGeometryShaderInvocations */
    /* skip val->maxGeometryInputComponents */
    /* skip val->maxGeometryOutputComponents */
    /* skip val->maxGeometryOutputVertices */
    /* skip val->maxGeometryTotalOutputComponents */
    /* skip val->maxFragmentInputComponents */
    /* skip val->maxFragmentOutputAttachments */
    /* skip val->maxFragmentDualSrcAttachments */
    /* skip val->maxFragmentCombinedOutputResources */
    /* skip val->maxComputeSharedMemorySize */
    /* skip val->maxComputeWorkGroupCount */
    /* skip val->maxComputeWorkGroupInvocations */
    /* skip val->maxComputeWorkGroupSize */
    /* skip val->subPixelPrecisionBits */
    /* skip val->subTexelPrecisionBits */
    /* skip val->mipmapPrecisionBits */
    /* skip val->maxDrawIndexedIndexValue */
    /* skip val->maxDrawIndirectCount */
    /* skip val->maxSamplerLodBias */
    /* skip val->maxSamplerAnisotropy */
    /* skip val->maxViewports */
    /* skip val->maxViewportDimensions */
    /* skip val->viewportBoundsRange */
    /* skip val->viewportSubPixelBits */
    /* skip val->minMemoryMapAlignment */
    /* skip val->minTexelBufferOffsetAlignment */
    /* skip val->minUniformBufferOffsetAlignment */
    /* skip val->minStorageBufferOffsetAlignment */
    /* skip val->minTexelOffset */
    /* skip val->maxTexelOffset */
    /* skip val->minTexelGatherOffset */
    /* skip val->maxTexelGatherOffset */
    /* skip val->minInterpolationOffset */
    /* skip val->maxInterpolationOffset */
    /* skip val->subPixelInterpolationOffsetBits */
    /* skip val->maxFramebufferWidth */
    /* skip val->maxFramebufferHeight */
    /* skip val->maxFramebufferLayers */
    /* skip val->framebufferColorSampleCounts */
    /* skip val->framebufferDepthSampleCounts */
    /* skip val->framebufferStencilSampleCounts */
    /* skip val->framebufferNoAttachmentsSampleCounts */
    /* skip val->maxColorAttachments */
    /* skip val->sampledImageColorSampleCounts */
    /* skip val->sampledImageIntegerSampleCounts */
    /* skip val->sampledImageDepthSampleCounts */
    /* skip val->sampledImageStencilSampleCounts */
    /* skip val->storageImageSampleCounts */
    /* skip val->maxSampleMaskWords */
    /* skip val->timestampComputeAndGraphics */
    /* skip val->timestampPeriod */
    /* skip val->maxClipDistances */
    /* skip val->maxCullDistances */
    /* skip val->maxCombinedClipAndCullDistances */
    /* skip val->discreteQueuePriorities */
    /* skip val->pointSizeRange */
    /* skip val->lineWidthRange */
    /* skip val->pointSizeGranularity */
    /* skip val->lineWidthGranularity */
    /* skip val->strictLines */
    /* skip val->standardSampleLocations */
    /* skip val->optimalBufferCopyOffsetAlignment */
    /* skip val->optimalBufferCopyRowPitchAlignment */
    /* skip val->nonCoherentAtomSize */
}

/* struct VkPhysicalDeviceSparseProperties */

static inline void
vn_encode_VkPhysicalDeviceSparseProperties(struct vn_cs *cs, const VkPhysicalDeviceSparseProperties *val)
{
    vn_encode_VkBool32(cs, &val->residencyStandard2DBlockShape);
    vn_encode_VkBool32(cs, &val->residencyStandard2DMultisampleBlockShape);
    vn_encode_VkBool32(cs, &val->residencyStandard3DBlockShape);
    vn_encode_VkBool32(cs, &val->residencyAlignedMipSize);
    vn_encode_VkBool32(cs, &val->residencyNonResidentStrict);
}

static inline void
vn_decode_VkPhysicalDeviceSparseProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSparseProperties *val)
{
    /* skip val->residencyStandard2DBlockShape */
    /* skip val->residencyStandard2DMultisampleBlockShape */
    /* skip val->residencyStandard3DBlockShape */
    /* skip val->residencyAlignedMipSize */
    /* skip val->residencyNonResidentStrict */
}

/* struct VkPhysicalDeviceProperties */

static inline void
vn_encode_VkPhysicalDeviceProperties(struct vn_cs *cs, const VkPhysicalDeviceProperties *val)
{
    vn_encode_uint32_t(cs, &val->apiVersion);
    vn_encode_uint32_t(cs, &val->driverVersion);
    vn_encode_uint32_t(cs, &val->vendorID);
    vn_encode_uint32_t(cs, &val->deviceID);
    vn_encode_VkPhysicalDeviceType(cs, &val->deviceType);
    vn_encode_array_size(cs, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);
    vn_encode_blob_array(cs, val->deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);
    vn_encode_array_size(cs, VK_UUID_SIZE);
    vn_encode_uint8_t_array(cs, val->pipelineCacheUUID, VK_UUID_SIZE);
    vn_encode_VkPhysicalDeviceLimits(cs, &val->limits);
    vn_encode_VkPhysicalDeviceSparseProperties(cs, &val->sparseProperties);
}

static inline void
vn_decode_VkPhysicalDeviceProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceProperties *val)
{
    /* skip val->apiVersion */
    /* skip val->driverVersion */
    /* skip val->vendorID */
    /* skip val->deviceID */
    /* skip val->deviceType */
    /* skip val->deviceName */
    /* skip val->pipelineCacheUUID */
    vn_decode_VkPhysicalDeviceLimits_partial_temp(cs, &val->limits);
    vn_decode_VkPhysicalDeviceSparseProperties_partial_temp(cs, &val->sparseProperties);
}

/* struct VkExtensionProperties */

static inline void
vn_encode_VkExtensionProperties(struct vn_cs *cs, const VkExtensionProperties *val)
{
    vn_encode_array_size(cs, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_blob_array(cs, val->extensionName, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_uint32_t(cs, &val->specVersion);
}

static inline void
vn_decode_VkExtensionProperties_partial_temp(struct vn_cs *cs, VkExtensionProperties *val)
{
    /* skip val->extensionName */
    /* skip val->specVersion */
}

/* struct VkLayerProperties */

static inline void
vn_encode_VkLayerProperties(struct vn_cs *cs, const VkLayerProperties *val)
{
    vn_encode_array_size(cs, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_blob_array(cs, val->layerName, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_uint32_t(cs, &val->specVersion);
    vn_encode_uint32_t(cs, &val->implementationVersion);
    vn_encode_array_size(cs, VK_MAX_DESCRIPTION_SIZE);
    vn_encode_blob_array(cs, val->description, VK_MAX_DESCRIPTION_SIZE);
}

static inline void
vn_decode_VkLayerProperties_partial_temp(struct vn_cs *cs, VkLayerProperties *val)
{
    /* skip val->layerName */
    /* skip val->specVersion */
    /* skip val->implementationVersion */
    /* skip val->description */
}

/* struct VkApplicationInfo chain */

static inline void *
vn_decode_VkApplicationInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkApplicationInfo_self_temp(struct vn_cs *cs, VkApplicationInfo *val)
{
    /* skip val->{sType,pNext} */
    if (vn_peek_array_size(cs)) {
        const size_t string_size = vn_decode_array_size(cs, UINT64_MAX);
        val->pApplicationName = vn_cs_alloc_temp(cs, sizeof(*val->pApplicationName) * string_size);
        if (!val->pApplicationName) return;
        vn_decode_blob_array(cs, (char *)val->pApplicationName, string_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pApplicationName = NULL;
    }
    vn_decode_uint32_t(cs, &val->applicationVersion);
    if (vn_peek_array_size(cs)) {
        const size_t string_size = vn_decode_array_size(cs, UINT64_MAX);
        val->pEngineName = vn_cs_alloc_temp(cs, sizeof(*val->pEngineName) * string_size);
        if (!val->pEngineName) return;
        vn_decode_blob_array(cs, (char *)val->pEngineName, string_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pEngineName = NULL;
    }
    vn_decode_uint32_t(cs, &val->engineVersion);
    vn_decode_uint32_t(cs, &val->apiVersion);
}

static inline void
vn_decode_VkApplicationInfo_temp(struct vn_cs *cs, VkApplicationInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_APPLICATION_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkApplicationInfo_pnext_temp(cs);
    vn_decode_VkApplicationInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkApplicationInfo_handle_self(VkApplicationInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->pApplicationName */
    /* skip val->applicationVersion */
    /* skip val->pEngineName */
    /* skip val->engineVersion */
    /* skip val->apiVersion */
}

static inline void
vn_replace_VkApplicationInfo_handle(VkApplicationInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_APPLICATION_INFO:
            vn_replace_VkApplicationInfo_handle_self((VkApplicationInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDeviceQueueCreateInfo chain */

static inline void *
vn_decode_VkDeviceQueueCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceQueueCreateInfo_self_temp(struct vn_cs *cs, VkDeviceQueueCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->queueFamilyIndex);
    vn_decode_uint32_t(cs, &val->queueCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->queueCount);
        val->pQueuePriorities = vn_cs_alloc_temp(cs, sizeof(*val->pQueuePriorities) * array_size);
        if (!val->pQueuePriorities) return;
        vn_decode_float_array(cs, (float *)val->pQueuePriorities, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pQueuePriorities = NULL;
    }
}

static inline void
vn_decode_VkDeviceQueueCreateInfo_temp(struct vn_cs *cs, VkDeviceQueueCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceQueueCreateInfo_pnext_temp(cs);
    vn_decode_VkDeviceQueueCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceQueueCreateInfo_handle_self(VkDeviceQueueCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->queueFamilyIndex */
    /* skip val->queueCount */
    /* skip val->pQueuePriorities */
}

static inline void
vn_replace_VkDeviceQueueCreateInfo_handle(VkDeviceQueueCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO:
            vn_replace_VkDeviceQueueCreateInfo_handle_self((VkDeviceQueueCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceFeatures */

static inline void
vn_encode_VkPhysicalDeviceFeatures(struct vn_cs *cs, const VkPhysicalDeviceFeatures *val)
{
    vn_encode_VkBool32(cs, &val->robustBufferAccess);
    vn_encode_VkBool32(cs, &val->fullDrawIndexUint32);
    vn_encode_VkBool32(cs, &val->imageCubeArray);
    vn_encode_VkBool32(cs, &val->independentBlend);
    vn_encode_VkBool32(cs, &val->geometryShader);
    vn_encode_VkBool32(cs, &val->tessellationShader);
    vn_encode_VkBool32(cs, &val->sampleRateShading);
    vn_encode_VkBool32(cs, &val->dualSrcBlend);
    vn_encode_VkBool32(cs, &val->logicOp);
    vn_encode_VkBool32(cs, &val->multiDrawIndirect);
    vn_encode_VkBool32(cs, &val->drawIndirectFirstInstance);
    vn_encode_VkBool32(cs, &val->depthClamp);
    vn_encode_VkBool32(cs, &val->depthBiasClamp);
    vn_encode_VkBool32(cs, &val->fillModeNonSolid);
    vn_encode_VkBool32(cs, &val->depthBounds);
    vn_encode_VkBool32(cs, &val->wideLines);
    vn_encode_VkBool32(cs, &val->largePoints);
    vn_encode_VkBool32(cs, &val->alphaToOne);
    vn_encode_VkBool32(cs, &val->multiViewport);
    vn_encode_VkBool32(cs, &val->samplerAnisotropy);
    vn_encode_VkBool32(cs, &val->textureCompressionETC2);
    vn_encode_VkBool32(cs, &val->textureCompressionASTC_LDR);
    vn_encode_VkBool32(cs, &val->textureCompressionBC);
    vn_encode_VkBool32(cs, &val->occlusionQueryPrecise);
    vn_encode_VkBool32(cs, &val->pipelineStatisticsQuery);
    vn_encode_VkBool32(cs, &val->vertexPipelineStoresAndAtomics);
    vn_encode_VkBool32(cs, &val->fragmentStoresAndAtomics);
    vn_encode_VkBool32(cs, &val->shaderTessellationAndGeometryPointSize);
    vn_encode_VkBool32(cs, &val->shaderImageGatherExtended);
    vn_encode_VkBool32(cs, &val->shaderStorageImageExtendedFormats);
    vn_encode_VkBool32(cs, &val->shaderStorageImageMultisample);
    vn_encode_VkBool32(cs, &val->shaderStorageImageReadWithoutFormat);
    vn_encode_VkBool32(cs, &val->shaderStorageImageWriteWithoutFormat);
    vn_encode_VkBool32(cs, &val->shaderUniformBufferArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderSampledImageArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageBufferArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageImageArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderClipDistance);
    vn_encode_VkBool32(cs, &val->shaderCullDistance);
    vn_encode_VkBool32(cs, &val->shaderFloat64);
    vn_encode_VkBool32(cs, &val->shaderInt64);
    vn_encode_VkBool32(cs, &val->shaderInt16);
    vn_encode_VkBool32(cs, &val->shaderResourceResidency);
    vn_encode_VkBool32(cs, &val->shaderResourceMinLod);
    vn_encode_VkBool32(cs, &val->sparseBinding);
    vn_encode_VkBool32(cs, &val->sparseResidencyBuffer);
    vn_encode_VkBool32(cs, &val->sparseResidencyImage2D);
    vn_encode_VkBool32(cs, &val->sparseResidencyImage3D);
    vn_encode_VkBool32(cs, &val->sparseResidency2Samples);
    vn_encode_VkBool32(cs, &val->sparseResidency4Samples);
    vn_encode_VkBool32(cs, &val->sparseResidency8Samples);
    vn_encode_VkBool32(cs, &val->sparseResidency16Samples);
    vn_encode_VkBool32(cs, &val->sparseResidencyAliased);
    vn_encode_VkBool32(cs, &val->variableMultisampleRate);
    vn_encode_VkBool32(cs, &val->inheritedQueries);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceFeatures *val)
{
    vn_decode_VkBool32(cs, &val->robustBufferAccess);
    vn_decode_VkBool32(cs, &val->fullDrawIndexUint32);
    vn_decode_VkBool32(cs, &val->imageCubeArray);
    vn_decode_VkBool32(cs, &val->independentBlend);
    vn_decode_VkBool32(cs, &val->geometryShader);
    vn_decode_VkBool32(cs, &val->tessellationShader);
    vn_decode_VkBool32(cs, &val->sampleRateShading);
    vn_decode_VkBool32(cs, &val->dualSrcBlend);
    vn_decode_VkBool32(cs, &val->logicOp);
    vn_decode_VkBool32(cs, &val->multiDrawIndirect);
    vn_decode_VkBool32(cs, &val->drawIndirectFirstInstance);
    vn_decode_VkBool32(cs, &val->depthClamp);
    vn_decode_VkBool32(cs, &val->depthBiasClamp);
    vn_decode_VkBool32(cs, &val->fillModeNonSolid);
    vn_decode_VkBool32(cs, &val->depthBounds);
    vn_decode_VkBool32(cs, &val->wideLines);
    vn_decode_VkBool32(cs, &val->largePoints);
    vn_decode_VkBool32(cs, &val->alphaToOne);
    vn_decode_VkBool32(cs, &val->multiViewport);
    vn_decode_VkBool32(cs, &val->samplerAnisotropy);
    vn_decode_VkBool32(cs, &val->textureCompressionETC2);
    vn_decode_VkBool32(cs, &val->textureCompressionASTC_LDR);
    vn_decode_VkBool32(cs, &val->textureCompressionBC);
    vn_decode_VkBool32(cs, &val->occlusionQueryPrecise);
    vn_decode_VkBool32(cs, &val->pipelineStatisticsQuery);
    vn_decode_VkBool32(cs, &val->vertexPipelineStoresAndAtomics);
    vn_decode_VkBool32(cs, &val->fragmentStoresAndAtomics);
    vn_decode_VkBool32(cs, &val->shaderTessellationAndGeometryPointSize);
    vn_decode_VkBool32(cs, &val->shaderImageGatherExtended);
    vn_decode_VkBool32(cs, &val->shaderStorageImageExtendedFormats);
    vn_decode_VkBool32(cs, &val->shaderStorageImageMultisample);
    vn_decode_VkBool32(cs, &val->shaderStorageImageReadWithoutFormat);
    vn_decode_VkBool32(cs, &val->shaderStorageImageWriteWithoutFormat);
    vn_decode_VkBool32(cs, &val->shaderUniformBufferArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderSampledImageArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageBufferArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageImageArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderClipDistance);
    vn_decode_VkBool32(cs, &val->shaderCullDistance);
    vn_decode_VkBool32(cs, &val->shaderFloat64);
    vn_decode_VkBool32(cs, &val->shaderInt64);
    vn_decode_VkBool32(cs, &val->shaderInt16);
    vn_decode_VkBool32(cs, &val->shaderResourceResidency);
    vn_decode_VkBool32(cs, &val->shaderResourceMinLod);
    vn_decode_VkBool32(cs, &val->sparseBinding);
    vn_decode_VkBool32(cs, &val->sparseResidencyBuffer);
    vn_decode_VkBool32(cs, &val->sparseResidencyImage2D);
    vn_decode_VkBool32(cs, &val->sparseResidencyImage3D);
    vn_decode_VkBool32(cs, &val->sparseResidency2Samples);
    vn_decode_VkBool32(cs, &val->sparseResidency4Samples);
    vn_decode_VkBool32(cs, &val->sparseResidency8Samples);
    vn_decode_VkBool32(cs, &val->sparseResidency16Samples);
    vn_decode_VkBool32(cs, &val->sparseResidencyAliased);
    vn_decode_VkBool32(cs, &val->variableMultisampleRate);
    vn_decode_VkBool32(cs, &val->inheritedQueries);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceFeatures *val)
{
    /* skip val->robustBufferAccess */
    /* skip val->fullDrawIndexUint32 */
    /* skip val->imageCubeArray */
    /* skip val->independentBlend */
    /* skip val->geometryShader */
    /* skip val->tessellationShader */
    /* skip val->sampleRateShading */
    /* skip val->dualSrcBlend */
    /* skip val->logicOp */
    /* skip val->multiDrawIndirect */
    /* skip val->drawIndirectFirstInstance */
    /* skip val->depthClamp */
    /* skip val->depthBiasClamp */
    /* skip val->fillModeNonSolid */
    /* skip val->depthBounds */
    /* skip val->wideLines */
    /* skip val->largePoints */
    /* skip val->alphaToOne */
    /* skip val->multiViewport */
    /* skip val->samplerAnisotropy */
    /* skip val->textureCompressionETC2 */
    /* skip val->textureCompressionASTC_LDR */
    /* skip val->textureCompressionBC */
    /* skip val->occlusionQueryPrecise */
    /* skip val->pipelineStatisticsQuery */
    /* skip val->vertexPipelineStoresAndAtomics */
    /* skip val->fragmentStoresAndAtomics */
    /* skip val->shaderTessellationAndGeometryPointSize */
    /* skip val->shaderImageGatherExtended */
    /* skip val->shaderStorageImageExtendedFormats */
    /* skip val->shaderStorageImageMultisample */
    /* skip val->shaderStorageImageReadWithoutFormat */
    /* skip val->shaderStorageImageWriteWithoutFormat */
    /* skip val->shaderUniformBufferArrayDynamicIndexing */
    /* skip val->shaderSampledImageArrayDynamicIndexing */
    /* skip val->shaderStorageBufferArrayDynamicIndexing */
    /* skip val->shaderStorageImageArrayDynamicIndexing */
    /* skip val->shaderClipDistance */
    /* skip val->shaderCullDistance */
    /* skip val->shaderFloat64 */
    /* skip val->shaderInt64 */
    /* skip val->shaderInt16 */
    /* skip val->shaderResourceResidency */
    /* skip val->shaderResourceMinLod */
    /* skip val->sparseBinding */
    /* skip val->sparseResidencyBuffer */
    /* skip val->sparseResidencyImage2D */
    /* skip val->sparseResidencyImage3D */
    /* skip val->sparseResidency2Samples */
    /* skip val->sparseResidency4Samples */
    /* skip val->sparseResidency8Samples */
    /* skip val->sparseResidency16Samples */
    /* skip val->sparseResidencyAliased */
    /* skip val->variableMultisampleRate */
    /* skip val->inheritedQueries */
}

static inline void
vn_replace_VkPhysicalDeviceFeatures_handle(VkPhysicalDeviceFeatures *val)
{
    /* skip val->robustBufferAccess */
    /* skip val->fullDrawIndexUint32 */
    /* skip val->imageCubeArray */
    /* skip val->independentBlend */
    /* skip val->geometryShader */
    /* skip val->tessellationShader */
    /* skip val->sampleRateShading */
    /* skip val->dualSrcBlend */
    /* skip val->logicOp */
    /* skip val->multiDrawIndirect */
    /* skip val->drawIndirectFirstInstance */
    /* skip val->depthClamp */
    /* skip val->depthBiasClamp */
    /* skip val->fillModeNonSolid */
    /* skip val->depthBounds */
    /* skip val->wideLines */
    /* skip val->largePoints */
    /* skip val->alphaToOne */
    /* skip val->multiViewport */
    /* skip val->samplerAnisotropy */
    /* skip val->textureCompressionETC2 */
    /* skip val->textureCompressionASTC_LDR */
    /* skip val->textureCompressionBC */
    /* skip val->occlusionQueryPrecise */
    /* skip val->pipelineStatisticsQuery */
    /* skip val->vertexPipelineStoresAndAtomics */
    /* skip val->fragmentStoresAndAtomics */
    /* skip val->shaderTessellationAndGeometryPointSize */
    /* skip val->shaderImageGatherExtended */
    /* skip val->shaderStorageImageExtendedFormats */
    /* skip val->shaderStorageImageMultisample */
    /* skip val->shaderStorageImageReadWithoutFormat */
    /* skip val->shaderStorageImageWriteWithoutFormat */
    /* skip val->shaderUniformBufferArrayDynamicIndexing */
    /* skip val->shaderSampledImageArrayDynamicIndexing */
    /* skip val->shaderStorageBufferArrayDynamicIndexing */
    /* skip val->shaderStorageImageArrayDynamicIndexing */
    /* skip val->shaderClipDistance */
    /* skip val->shaderCullDistance */
    /* skip val->shaderFloat64 */
    /* skip val->shaderInt64 */
    /* skip val->shaderInt16 */
    /* skip val->shaderResourceResidency */
    /* skip val->shaderResourceMinLod */
    /* skip val->sparseBinding */
    /* skip val->sparseResidencyBuffer */
    /* skip val->sparseResidencyImage2D */
    /* skip val->sparseResidencyImage3D */
    /* skip val->sparseResidency2Samples */
    /* skip val->sparseResidency4Samples */
    /* skip val->sparseResidency8Samples */
    /* skip val->sparseResidency16Samples */
    /* skip val->sparseResidencyAliased */
    /* skip val->variableMultisampleRate */
    /* skip val->inheritedQueries */
}

/* struct VkPhysicalDeviceVariablePointersFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceVariablePointersFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVariablePointersFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceVariablePointersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->variablePointersStorageBuffer);
    vn_encode_VkBool32(cs, &val->variablePointers);
}

static inline void
vn_encode_VkPhysicalDeviceVariablePointersFeatures(struct vn_cs *cs, const VkPhysicalDeviceVariablePointersFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES });
    vn_encode_VkPhysicalDeviceVariablePointersFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceVariablePointersFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceVariablePointersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->variablePointersStorageBuffer);
    vn_decode_VkBool32(cs, &val->variablePointers);
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceVariablePointersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVariablePointersFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->variablePointersStorageBuffer */
    /* skip val->variablePointers */
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVariablePointersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceVariablePointersFeatures_handle_self(VkPhysicalDeviceVariablePointersFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->variablePointersStorageBuffer */
    /* skip val->variablePointers */
}

static inline void
vn_replace_VkPhysicalDeviceVariablePointersFeatures_handle(VkPhysicalDeviceVariablePointersFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            vn_replace_VkPhysicalDeviceVariablePointersFeatures_handle_self((VkPhysicalDeviceVariablePointersFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceMultiviewFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceMultiviewFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceMultiviewFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->multiview);
    vn_encode_VkBool32(cs, &val->multiviewGeometryShader);
    vn_encode_VkBool32(cs, &val->multiviewTessellationShader);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewFeatures(struct vn_cs *cs, const VkPhysicalDeviceMultiviewFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES });
    vn_encode_VkPhysicalDeviceMultiviewFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceMultiviewFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceMultiviewFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->multiview);
    vn_decode_VkBool32(cs, &val->multiviewGeometryShader);
    vn_decode_VkBool32(cs, &val->multiviewTessellationShader);
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceMultiviewFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMultiviewFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->multiview */
    /* skip val->multiviewGeometryShader */
    /* skip val->multiviewTessellationShader */
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMultiviewFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceMultiviewFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceMultiviewFeatures_handle_self(VkPhysicalDeviceMultiviewFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->multiview */
    /* skip val->multiviewGeometryShader */
    /* skip val->multiviewTessellationShader */
}

static inline void
vn_replace_VkPhysicalDeviceMultiviewFeatures_handle(VkPhysicalDeviceMultiviewFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            vn_replace_VkPhysicalDeviceMultiviewFeatures_handle_self((VkPhysicalDeviceMultiviewFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDevice16BitStorageFeatures chain */

static inline void
vn_encode_VkPhysicalDevice16BitStorageFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDevice16BitStorageFeatures_self(struct vn_cs *cs, const VkPhysicalDevice16BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->storageBuffer16BitAccess);
    vn_encode_VkBool32(cs, &val->uniformAndStorageBuffer16BitAccess);
    vn_encode_VkBool32(cs, &val->storagePushConstant16);
    vn_encode_VkBool32(cs, &val->storageInputOutput16);
}

static inline void
vn_encode_VkPhysicalDevice16BitStorageFeatures(struct vn_cs *cs, const VkPhysicalDevice16BitStorageFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES });
    vn_encode_VkPhysicalDevice16BitStorageFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDevice16BitStorageFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(struct vn_cs *cs, VkPhysicalDevice16BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->storageBuffer16BitAccess);
    vn_decode_VkBool32(cs, &val->uniformAndStorageBuffer16BitAccess);
    vn_decode_VkBool32(cs, &val->storagePushConstant16);
    vn_decode_VkBool32(cs, &val->storageInputOutput16);
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_temp(struct vn_cs *cs, VkPhysicalDevice16BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDevice16BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->storageBuffer16BitAccess */
    /* skip val->uniformAndStorageBuffer16BitAccess */
    /* skip val->storagePushConstant16 */
    /* skip val->storageInputOutput16 */
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDevice16BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDevice16BitStorageFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDevice16BitStorageFeatures_handle_self(VkPhysicalDevice16BitStorageFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->storageBuffer16BitAccess */
    /* skip val->uniformAndStorageBuffer16BitAccess */
    /* skip val->storagePushConstant16 */
    /* skip val->storageInputOutput16 */
}

static inline void
vn_replace_VkPhysicalDevice16BitStorageFeatures_handle(VkPhysicalDevice16BitStorageFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            vn_replace_VkPhysicalDevice16BitStorageFeatures_handle_self((VkPhysicalDevice16BitStorageFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->shaderSubgroupExtendedTypes);
}

static inline void
vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(struct vn_cs *cs, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES });
    vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->shaderSubgroupExtendedTypes);
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderSubgroupExtendedTypes */
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_handle_self(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->shaderSubgroupExtendedTypes */
}

static inline void
vn_replace_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_handle(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            vn_replace_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_handle_self((VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceSamplerYcbcrConversionFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->samplerYcbcrConversion);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures(struct vn_cs *cs, const VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES });
    vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->samplerYcbcrConversion);
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->samplerYcbcrConversion */
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceSamplerYcbcrConversionFeatures_handle_self(VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->samplerYcbcrConversion */
}

static inline void
vn_replace_VkPhysicalDeviceSamplerYcbcrConversionFeatures_handle(VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            vn_replace_VkPhysicalDeviceSamplerYcbcrConversionFeatures_handle_self((VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceProtectedMemoryFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->protectedMemory);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryFeatures(struct vn_cs *cs, const VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES });
    vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->protectedMemory);
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->protectedMemory */
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceProtectedMemoryFeatures_handle_self(VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->protectedMemory */
}

static inline void
vn_replace_VkPhysicalDeviceProtectedMemoryFeatures_handle(VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            vn_replace_VkPhysicalDeviceProtectedMemoryFeatures_handle_self((VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceShaderDrawParametersFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->shaderDrawParameters);
}

static inline void
vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures(struct vn_cs *cs, const VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES });
    vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->shaderDrawParameters);
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderDrawParameters */
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceShaderDrawParametersFeatures_handle_self(VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->shaderDrawParameters */
}

static inline void
vn_replace_VkPhysicalDeviceShaderDrawParametersFeatures_handle(VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            vn_replace_VkPhysicalDeviceShaderDrawParametersFeatures_handle_self((VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceShaderFloat16Int8Features chain */

static inline void
vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_self(struct vn_cs *cs, const VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->shaderFloat16);
    vn_encode_VkBool32(cs, &val->shaderInt8);
}

static inline void
vn_encode_VkPhysicalDeviceShaderFloat16Int8Features(struct vn_cs *cs, const VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES });
    vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(struct vn_cs *cs, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->shaderFloat16);
    vn_decode_VkBool32(cs, &val->shaderInt8);
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_temp(struct vn_cs *cs, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderFloat16 */
    /* skip val->shaderInt8 */
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceShaderFloat16Int8Features_handle_self(VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->shaderFloat16 */
    /* skip val->shaderInt8 */
}

static inline void
vn_replace_VkPhysicalDeviceShaderFloat16Int8Features_handle(VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            vn_replace_VkPhysicalDeviceShaderFloat16Int8Features_handle_self((VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceHostQueryResetFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceHostQueryResetFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceHostQueryResetFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceHostQueryResetFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->hostQueryReset);
}

static inline void
vn_encode_VkPhysicalDeviceHostQueryResetFeatures(struct vn_cs *cs, const VkPhysicalDeviceHostQueryResetFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES });
    vn_encode_VkPhysicalDeviceHostQueryResetFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceHostQueryResetFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->hostQueryReset);
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->hostQueryReset */
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceHostQueryResetFeatures_handle_self(VkPhysicalDeviceHostQueryResetFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->hostQueryReset */
}

static inline void
vn_replace_VkPhysicalDeviceHostQueryResetFeatures_handle(VkPhysicalDeviceHostQueryResetFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            vn_replace_VkPhysicalDeviceHostQueryResetFeatures_handle_self((VkPhysicalDeviceHostQueryResetFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceDescriptorIndexingFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_encode_VkBool32(cs, &val->descriptorBindingPartiallyBound);
    vn_encode_VkBool32(cs, &val->descriptorBindingVariableDescriptorCount);
    vn_encode_VkBool32(cs, &val->runtimeDescriptorArray);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures(struct vn_cs *cs, const VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES });
    vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_decode_VkBool32(cs, &val->descriptorBindingPartiallyBound);
    vn_decode_VkBool32(cs, &val->descriptorBindingVariableDescriptorCount);
    vn_decode_VkBool32(cs, &val->runtimeDescriptorArray);
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderInputAttachmentArrayDynamicIndexing */
    /* skip val->shaderUniformTexelBufferArrayDynamicIndexing */
    /* skip val->shaderStorageTexelBufferArrayDynamicIndexing */
    /* skip val->shaderUniformBufferArrayNonUniformIndexing */
    /* skip val->shaderSampledImageArrayNonUniformIndexing */
    /* skip val->shaderStorageBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageImageArrayNonUniformIndexing */
    /* skip val->shaderInputAttachmentArrayNonUniformIndexing */
    /* skip val->shaderUniformTexelBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageTexelBufferArrayNonUniformIndexing */
    /* skip val->descriptorBindingUniformBufferUpdateAfterBind */
    /* skip val->descriptorBindingSampledImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageBufferUpdateAfterBind */
    /* skip val->descriptorBindingUniformTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingStorageTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingUpdateUnusedWhilePending */
    /* skip val->descriptorBindingPartiallyBound */
    /* skip val->descriptorBindingVariableDescriptorCount */
    /* skip val->runtimeDescriptorArray */
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceDescriptorIndexingFeatures_handle_self(VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->shaderInputAttachmentArrayDynamicIndexing */
    /* skip val->shaderUniformTexelBufferArrayDynamicIndexing */
    /* skip val->shaderStorageTexelBufferArrayDynamicIndexing */
    /* skip val->shaderUniformBufferArrayNonUniformIndexing */
    /* skip val->shaderSampledImageArrayNonUniformIndexing */
    /* skip val->shaderStorageBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageImageArrayNonUniformIndexing */
    /* skip val->shaderInputAttachmentArrayNonUniformIndexing */
    /* skip val->shaderUniformTexelBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageTexelBufferArrayNonUniformIndexing */
    /* skip val->descriptorBindingUniformBufferUpdateAfterBind */
    /* skip val->descriptorBindingSampledImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageBufferUpdateAfterBind */
    /* skip val->descriptorBindingUniformTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingStorageTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingUpdateUnusedWhilePending */
    /* skip val->descriptorBindingPartiallyBound */
    /* skip val->descriptorBindingVariableDescriptorCount */
    /* skip val->runtimeDescriptorArray */
}

static inline void
vn_replace_VkPhysicalDeviceDescriptorIndexingFeatures_handle(VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            vn_replace_VkPhysicalDeviceDescriptorIndexingFeatures_handle_self((VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceTimelineSemaphoreFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->timelineSemaphore);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures(struct vn_cs *cs, const VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES });
    vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->timelineSemaphore);
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->timelineSemaphore */
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceTimelineSemaphoreFeatures_handle_self(VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->timelineSemaphore */
}

static inline void
vn_replace_VkPhysicalDeviceTimelineSemaphoreFeatures_handle(VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            vn_replace_VkPhysicalDeviceTimelineSemaphoreFeatures_handle_self((VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDevice8BitStorageFeatures chain */

static inline void
vn_encode_VkPhysicalDevice8BitStorageFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDevice8BitStorageFeatures_self(struct vn_cs *cs, const VkPhysicalDevice8BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->storageBuffer8BitAccess);
    vn_encode_VkBool32(cs, &val->uniformAndStorageBuffer8BitAccess);
    vn_encode_VkBool32(cs, &val->storagePushConstant8);
}

static inline void
vn_encode_VkPhysicalDevice8BitStorageFeatures(struct vn_cs *cs, const VkPhysicalDevice8BitStorageFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES });
    vn_encode_VkPhysicalDevice8BitStorageFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDevice8BitStorageFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(struct vn_cs *cs, VkPhysicalDevice8BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->storageBuffer8BitAccess);
    vn_decode_VkBool32(cs, &val->uniformAndStorageBuffer8BitAccess);
    vn_decode_VkBool32(cs, &val->storagePushConstant8);
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_temp(struct vn_cs *cs, VkPhysicalDevice8BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDevice8BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->storageBuffer8BitAccess */
    /* skip val->uniformAndStorageBuffer8BitAccess */
    /* skip val->storagePushConstant8 */
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDevice8BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDevice8BitStorageFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDevice8BitStorageFeatures_handle_self(VkPhysicalDevice8BitStorageFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->storageBuffer8BitAccess */
    /* skip val->uniformAndStorageBuffer8BitAccess */
    /* skip val->storagePushConstant8 */
}

static inline void
vn_replace_VkPhysicalDevice8BitStorageFeatures_handle(VkPhysicalDevice8BitStorageFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            vn_replace_VkPhysicalDevice8BitStorageFeatures_handle_self((VkPhysicalDevice8BitStorageFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceVulkanMemoryModelFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->vulkanMemoryModel);
    vn_encode_VkBool32(cs, &val->vulkanMemoryModelDeviceScope);
    vn_encode_VkBool32(cs, &val->vulkanMemoryModelAvailabilityVisibilityChains);
}

static inline void
vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures(struct vn_cs *cs, const VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES });
    vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->vulkanMemoryModel);
    vn_decode_VkBool32(cs, &val->vulkanMemoryModelDeviceScope);
    vn_decode_VkBool32(cs, &val->vulkanMemoryModelAvailabilityVisibilityChains);
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->vulkanMemoryModel */
    /* skip val->vulkanMemoryModelDeviceScope */
    /* skip val->vulkanMemoryModelAvailabilityVisibilityChains */
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceVulkanMemoryModelFeatures_handle_self(VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->vulkanMemoryModel */
    /* skip val->vulkanMemoryModelDeviceScope */
    /* skip val->vulkanMemoryModelAvailabilityVisibilityChains */
}

static inline void
vn_replace_VkPhysicalDeviceVulkanMemoryModelFeatures_handle(VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            vn_replace_VkPhysicalDeviceVulkanMemoryModelFeatures_handle_self((VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceShaderAtomicInt64Features chain */

static inline void
vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_self(struct vn_cs *cs, const VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->shaderBufferInt64Atomics);
    vn_encode_VkBool32(cs, &val->shaderSharedInt64Atomics);
}

static inline void
vn_encode_VkPhysicalDeviceShaderAtomicInt64Features(struct vn_cs *cs, const VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES });
    vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(struct vn_cs *cs, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->shaderBufferInt64Atomics);
    vn_decode_VkBool32(cs, &val->shaderSharedInt64Atomics);
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_temp(struct vn_cs *cs, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderBufferInt64Atomics */
    /* skip val->shaderSharedInt64Atomics */
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_partial_temp(struct vn_cs *cs, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceShaderAtomicInt64Features_handle_self(VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->shaderBufferInt64Atomics */
    /* skip val->shaderSharedInt64Atomics */
}

static inline void
vn_replace_VkPhysicalDeviceShaderAtomicInt64Features_handle(VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            vn_replace_VkPhysicalDeviceShaderAtomicInt64Features_handle_self((VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceTransformFeedbackFeaturesEXT chain */

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self(struct vn_cs *cs, const VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->transformFeedback);
    vn_encode_VkBool32(cs, &val->geometryStreams);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT(struct vn_cs *cs, const VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT });
    vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(struct vn_cs *cs, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->transformFeedback);
    vn_decode_VkBool32(cs, &val->geometryStreams);
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_temp(struct vn_cs *cs, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->transformFeedback */
    /* skip val->geometryStreams */
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceTransformFeedbackFeaturesEXT_handle_self(VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->transformFeedback */
    /* skip val->geometryStreams */
}

static inline void
vn_replace_VkPhysicalDeviceTransformFeedbackFeaturesEXT_handle(VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            vn_replace_VkPhysicalDeviceTransformFeedbackFeaturesEXT_handle_self((VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceScalarBlockLayoutFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->scalarBlockLayout);
}

static inline void
vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures(struct vn_cs *cs, const VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES });
    vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->scalarBlockLayout);
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->scalarBlockLayout */
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceScalarBlockLayoutFeatures_handle_self(VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->scalarBlockLayout */
}

static inline void
vn_replace_VkPhysicalDeviceScalarBlockLayoutFeatures_handle(VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            vn_replace_VkPhysicalDeviceScalarBlockLayoutFeatures_handle_self((VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceUniformBufferStandardLayoutFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->uniformBufferStandardLayout);
}

static inline void
vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(struct vn_cs *cs, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES });
    vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->uniformBufferStandardLayout);
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->uniformBufferStandardLayout */
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_handle_self(VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->uniformBufferStandardLayout */
}

static inline void
vn_replace_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_handle(VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            vn_replace_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_handle_self((VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceBufferDeviceAddressFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->bufferDeviceAddress);
    vn_encode_VkBool32(cs, &val->bufferDeviceAddressCaptureReplay);
    vn_encode_VkBool32(cs, &val->bufferDeviceAddressMultiDevice);
}

static inline void
vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures(struct vn_cs *cs, const VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES });
    vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->bufferDeviceAddress);
    vn_decode_VkBool32(cs, &val->bufferDeviceAddressCaptureReplay);
    vn_decode_VkBool32(cs, &val->bufferDeviceAddressMultiDevice);
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->bufferDeviceAddress */
    /* skip val->bufferDeviceAddressCaptureReplay */
    /* skip val->bufferDeviceAddressMultiDevice */
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceBufferDeviceAddressFeatures_handle_self(VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->bufferDeviceAddress */
    /* skip val->bufferDeviceAddressCaptureReplay */
    /* skip val->bufferDeviceAddressMultiDevice */
}

static inline void
vn_replace_VkPhysicalDeviceBufferDeviceAddressFeatures_handle(VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            vn_replace_VkPhysicalDeviceBufferDeviceAddressFeatures_handle_self((VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceImagelessFramebufferFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->imagelessFramebuffer);
}

static inline void
vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures(struct vn_cs *cs, const VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES });
    vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->imagelessFramebuffer);
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->imagelessFramebuffer */
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceImagelessFramebufferFeatures_handle_self(VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->imagelessFramebuffer */
}

static inline void
vn_replace_VkPhysicalDeviceImagelessFramebufferFeatures_handle(VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            vn_replace_VkPhysicalDeviceImagelessFramebufferFeatures_handle_self((VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures chain */

static inline void
vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self(struct vn_cs *cs, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->separateDepthStencilLayouts);
}

static inline void
vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(struct vn_cs *cs, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES });
    vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(struct vn_cs *cs, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->separateDepthStencilLayouts);
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_temp(struct vn_cs *cs, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->separateDepthStencilLayouts */
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_handle_self(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->separateDepthStencilLayouts */
}

static inline void
vn_replace_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_handle(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            vn_replace_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_handle_self((VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceVulkan11Features chain */

static inline void
vn_encode_VkPhysicalDeviceVulkan11Features_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Features_self(struct vn_cs *cs, const VkPhysicalDeviceVulkan11Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->storageBuffer16BitAccess);
    vn_encode_VkBool32(cs, &val->uniformAndStorageBuffer16BitAccess);
    vn_encode_VkBool32(cs, &val->storagePushConstant16);
    vn_encode_VkBool32(cs, &val->storageInputOutput16);
    vn_encode_VkBool32(cs, &val->multiview);
    vn_encode_VkBool32(cs, &val->multiviewGeometryShader);
    vn_encode_VkBool32(cs, &val->multiviewTessellationShader);
    vn_encode_VkBool32(cs, &val->variablePointersStorageBuffer);
    vn_encode_VkBool32(cs, &val->variablePointers);
    vn_encode_VkBool32(cs, &val->protectedMemory);
    vn_encode_VkBool32(cs, &val->samplerYcbcrConversion);
    vn_encode_VkBool32(cs, &val->shaderDrawParameters);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Features(struct vn_cs *cs, const VkPhysicalDeviceVulkan11Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES });
    vn_encode_VkPhysicalDeviceVulkan11Features_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan11Features_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan11Features_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan11Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->storageBuffer16BitAccess);
    vn_decode_VkBool32(cs, &val->uniformAndStorageBuffer16BitAccess);
    vn_decode_VkBool32(cs, &val->storagePushConstant16);
    vn_decode_VkBool32(cs, &val->storageInputOutput16);
    vn_decode_VkBool32(cs, &val->multiview);
    vn_decode_VkBool32(cs, &val->multiviewGeometryShader);
    vn_decode_VkBool32(cs, &val->multiviewTessellationShader);
    vn_decode_VkBool32(cs, &val->variablePointersStorageBuffer);
    vn_decode_VkBool32(cs, &val->variablePointers);
    vn_decode_VkBool32(cs, &val->protectedMemory);
    vn_decode_VkBool32(cs, &val->samplerYcbcrConversion);
    vn_decode_VkBool32(cs, &val->shaderDrawParameters);
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Features_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan11Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan11Features_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan11Features_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Features_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan11Features *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->storageBuffer16BitAccess */
    /* skip val->uniformAndStorageBuffer16BitAccess */
    /* skip val->storagePushConstant16 */
    /* skip val->storageInputOutput16 */
    /* skip val->multiview */
    /* skip val->multiviewGeometryShader */
    /* skip val->multiviewTessellationShader */
    /* skip val->variablePointersStorageBuffer */
    /* skip val->variablePointers */
    /* skip val->protectedMemory */
    /* skip val->samplerYcbcrConversion */
    /* skip val->shaderDrawParameters */
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Features_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan11Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan11Features_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceVulkan11Features_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceVulkan11Features_handle_self(VkPhysicalDeviceVulkan11Features *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->storageBuffer16BitAccess */
    /* skip val->uniformAndStorageBuffer16BitAccess */
    /* skip val->storagePushConstant16 */
    /* skip val->storageInputOutput16 */
    /* skip val->multiview */
    /* skip val->multiviewGeometryShader */
    /* skip val->multiviewTessellationShader */
    /* skip val->variablePointersStorageBuffer */
    /* skip val->variablePointers */
    /* skip val->protectedMemory */
    /* skip val->samplerYcbcrConversion */
    /* skip val->shaderDrawParameters */
}

static inline void
vn_replace_VkPhysicalDeviceVulkan11Features_handle(VkPhysicalDeviceVulkan11Features *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            vn_replace_VkPhysicalDeviceVulkan11Features_handle_self((VkPhysicalDeviceVulkan11Features *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceVulkan12Features chain */

static inline void
vn_encode_VkPhysicalDeviceVulkan12Features_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Features_self(struct vn_cs *cs, const VkPhysicalDeviceVulkan12Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->samplerMirrorClampToEdge);
    vn_encode_VkBool32(cs, &val->drawIndirectCount);
    vn_encode_VkBool32(cs, &val->storageBuffer8BitAccess);
    vn_encode_VkBool32(cs, &val->uniformAndStorageBuffer8BitAccess);
    vn_encode_VkBool32(cs, &val->storagePushConstant8);
    vn_encode_VkBool32(cs, &val->shaderBufferInt64Atomics);
    vn_encode_VkBool32(cs, &val->shaderSharedInt64Atomics);
    vn_encode_VkBool32(cs, &val->shaderFloat16);
    vn_encode_VkBool32(cs, &val->shaderInt8);
    vn_encode_VkBool32(cs, &val->descriptorIndexing);
    vn_encode_VkBool32(cs, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(cs, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(cs, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_encode_VkBool32(cs, &val->descriptorBindingPartiallyBound);
    vn_encode_VkBool32(cs, &val->descriptorBindingVariableDescriptorCount);
    vn_encode_VkBool32(cs, &val->runtimeDescriptorArray);
    vn_encode_VkBool32(cs, &val->samplerFilterMinmax);
    vn_encode_VkBool32(cs, &val->scalarBlockLayout);
    vn_encode_VkBool32(cs, &val->imagelessFramebuffer);
    vn_encode_VkBool32(cs, &val->uniformBufferStandardLayout);
    vn_encode_VkBool32(cs, &val->shaderSubgroupExtendedTypes);
    vn_encode_VkBool32(cs, &val->separateDepthStencilLayouts);
    vn_encode_VkBool32(cs, &val->hostQueryReset);
    vn_encode_VkBool32(cs, &val->timelineSemaphore);
    vn_encode_VkBool32(cs, &val->bufferDeviceAddress);
    vn_encode_VkBool32(cs, &val->bufferDeviceAddressCaptureReplay);
    vn_encode_VkBool32(cs, &val->bufferDeviceAddressMultiDevice);
    vn_encode_VkBool32(cs, &val->vulkanMemoryModel);
    vn_encode_VkBool32(cs, &val->vulkanMemoryModelDeviceScope);
    vn_encode_VkBool32(cs, &val->vulkanMemoryModelAvailabilityVisibilityChains);
    vn_encode_VkBool32(cs, &val->shaderOutputViewportIndex);
    vn_encode_VkBool32(cs, &val->shaderOutputLayer);
    vn_encode_VkBool32(cs, &val->subgroupBroadcastDynamicId);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Features(struct vn_cs *cs, const VkPhysicalDeviceVulkan12Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES });
    vn_encode_VkPhysicalDeviceVulkan12Features_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan12Features_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan12Features_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan12Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->samplerMirrorClampToEdge);
    vn_decode_VkBool32(cs, &val->drawIndirectCount);
    vn_decode_VkBool32(cs, &val->storageBuffer8BitAccess);
    vn_decode_VkBool32(cs, &val->uniformAndStorageBuffer8BitAccess);
    vn_decode_VkBool32(cs, &val->storagePushConstant8);
    vn_decode_VkBool32(cs, &val->shaderBufferInt64Atomics);
    vn_decode_VkBool32(cs, &val->shaderSharedInt64Atomics);
    vn_decode_VkBool32(cs, &val->shaderFloat16);
    vn_decode_VkBool32(cs, &val->shaderInt8);
    vn_decode_VkBool32(cs, &val->descriptorIndexing);
    vn_decode_VkBool32(cs, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(cs, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(cs, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(cs, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_decode_VkBool32(cs, &val->descriptorBindingPartiallyBound);
    vn_decode_VkBool32(cs, &val->descriptorBindingVariableDescriptorCount);
    vn_decode_VkBool32(cs, &val->runtimeDescriptorArray);
    vn_decode_VkBool32(cs, &val->samplerFilterMinmax);
    vn_decode_VkBool32(cs, &val->scalarBlockLayout);
    vn_decode_VkBool32(cs, &val->imagelessFramebuffer);
    vn_decode_VkBool32(cs, &val->uniformBufferStandardLayout);
    vn_decode_VkBool32(cs, &val->shaderSubgroupExtendedTypes);
    vn_decode_VkBool32(cs, &val->separateDepthStencilLayouts);
    vn_decode_VkBool32(cs, &val->hostQueryReset);
    vn_decode_VkBool32(cs, &val->timelineSemaphore);
    vn_decode_VkBool32(cs, &val->bufferDeviceAddress);
    vn_decode_VkBool32(cs, &val->bufferDeviceAddressCaptureReplay);
    vn_decode_VkBool32(cs, &val->bufferDeviceAddressMultiDevice);
    vn_decode_VkBool32(cs, &val->vulkanMemoryModel);
    vn_decode_VkBool32(cs, &val->vulkanMemoryModelDeviceScope);
    vn_decode_VkBool32(cs, &val->vulkanMemoryModelAvailabilityVisibilityChains);
    vn_decode_VkBool32(cs, &val->shaderOutputViewportIndex);
    vn_decode_VkBool32(cs, &val->shaderOutputLayer);
    vn_decode_VkBool32(cs, &val->subgroupBroadcastDynamicId);
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Features_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan12Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan12Features_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan12Features_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Features_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan12Features *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->samplerMirrorClampToEdge */
    /* skip val->drawIndirectCount */
    /* skip val->storageBuffer8BitAccess */
    /* skip val->uniformAndStorageBuffer8BitAccess */
    /* skip val->storagePushConstant8 */
    /* skip val->shaderBufferInt64Atomics */
    /* skip val->shaderSharedInt64Atomics */
    /* skip val->shaderFloat16 */
    /* skip val->shaderInt8 */
    /* skip val->descriptorIndexing */
    /* skip val->shaderInputAttachmentArrayDynamicIndexing */
    /* skip val->shaderUniformTexelBufferArrayDynamicIndexing */
    /* skip val->shaderStorageTexelBufferArrayDynamicIndexing */
    /* skip val->shaderUniformBufferArrayNonUniformIndexing */
    /* skip val->shaderSampledImageArrayNonUniformIndexing */
    /* skip val->shaderStorageBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageImageArrayNonUniformIndexing */
    /* skip val->shaderInputAttachmentArrayNonUniformIndexing */
    /* skip val->shaderUniformTexelBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageTexelBufferArrayNonUniformIndexing */
    /* skip val->descriptorBindingUniformBufferUpdateAfterBind */
    /* skip val->descriptorBindingSampledImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageBufferUpdateAfterBind */
    /* skip val->descriptorBindingUniformTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingStorageTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingUpdateUnusedWhilePending */
    /* skip val->descriptorBindingPartiallyBound */
    /* skip val->descriptorBindingVariableDescriptorCount */
    /* skip val->runtimeDescriptorArray */
    /* skip val->samplerFilterMinmax */
    /* skip val->scalarBlockLayout */
    /* skip val->imagelessFramebuffer */
    /* skip val->uniformBufferStandardLayout */
    /* skip val->shaderSubgroupExtendedTypes */
    /* skip val->separateDepthStencilLayouts */
    /* skip val->hostQueryReset */
    /* skip val->timelineSemaphore */
    /* skip val->bufferDeviceAddress */
    /* skip val->bufferDeviceAddressCaptureReplay */
    /* skip val->bufferDeviceAddressMultiDevice */
    /* skip val->vulkanMemoryModel */
    /* skip val->vulkanMemoryModelDeviceScope */
    /* skip val->vulkanMemoryModelAvailabilityVisibilityChains */
    /* skip val->shaderOutputViewportIndex */
    /* skip val->shaderOutputLayer */
    /* skip val->subgroupBroadcastDynamicId */
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Features_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan12Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan12Features_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceVulkan12Features_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceVulkan12Features_handle_self(VkPhysicalDeviceVulkan12Features *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->samplerMirrorClampToEdge */
    /* skip val->drawIndirectCount */
    /* skip val->storageBuffer8BitAccess */
    /* skip val->uniformAndStorageBuffer8BitAccess */
    /* skip val->storagePushConstant8 */
    /* skip val->shaderBufferInt64Atomics */
    /* skip val->shaderSharedInt64Atomics */
    /* skip val->shaderFloat16 */
    /* skip val->shaderInt8 */
    /* skip val->descriptorIndexing */
    /* skip val->shaderInputAttachmentArrayDynamicIndexing */
    /* skip val->shaderUniformTexelBufferArrayDynamicIndexing */
    /* skip val->shaderStorageTexelBufferArrayDynamicIndexing */
    /* skip val->shaderUniformBufferArrayNonUniformIndexing */
    /* skip val->shaderSampledImageArrayNonUniformIndexing */
    /* skip val->shaderStorageBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageImageArrayNonUniformIndexing */
    /* skip val->shaderInputAttachmentArrayNonUniformIndexing */
    /* skip val->shaderUniformTexelBufferArrayNonUniformIndexing */
    /* skip val->shaderStorageTexelBufferArrayNonUniformIndexing */
    /* skip val->descriptorBindingUniformBufferUpdateAfterBind */
    /* skip val->descriptorBindingSampledImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageImageUpdateAfterBind */
    /* skip val->descriptorBindingStorageBufferUpdateAfterBind */
    /* skip val->descriptorBindingUniformTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingStorageTexelBufferUpdateAfterBind */
    /* skip val->descriptorBindingUpdateUnusedWhilePending */
    /* skip val->descriptorBindingPartiallyBound */
    /* skip val->descriptorBindingVariableDescriptorCount */
    /* skip val->runtimeDescriptorArray */
    /* skip val->samplerFilterMinmax */
    /* skip val->scalarBlockLayout */
    /* skip val->imagelessFramebuffer */
    /* skip val->uniformBufferStandardLayout */
    /* skip val->shaderSubgroupExtendedTypes */
    /* skip val->separateDepthStencilLayouts */
    /* skip val->hostQueryReset */
    /* skip val->timelineSemaphore */
    /* skip val->bufferDeviceAddress */
    /* skip val->bufferDeviceAddressCaptureReplay */
    /* skip val->bufferDeviceAddressMultiDevice */
    /* skip val->vulkanMemoryModel */
    /* skip val->vulkanMemoryModelDeviceScope */
    /* skip val->vulkanMemoryModelAvailabilityVisibilityChains */
    /* skip val->shaderOutputViewportIndex */
    /* skip val->shaderOutputLayer */
    /* skip val->subgroupBroadcastDynamicId */
}

static inline void
vn_replace_VkPhysicalDeviceVulkan12Features_handle(VkPhysicalDeviceVulkan12Features *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            vn_replace_VkPhysicalDeviceVulkan12Features_handle_self((VkPhysicalDeviceVulkan12Features *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceFeatures2 chain */

static inline void
vn_encode_VkPhysicalDeviceFeatures2_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceVariablePointersFeatures_self(cs, (const VkPhysicalDeviceVariablePointersFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceMultiviewFeatures_self(cs, (const VkPhysicalDeviceMultiviewFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDevice16BitStorageFeatures_self(cs, (const VkPhysicalDevice16BitStorageFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self(cs, (const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self(cs, (const VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_self(cs, (const VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_self(cs, (const VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_self(cs, (const VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceHostQueryResetFeatures_self(cs, (const VkPhysicalDeviceHostQueryResetFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_self(cs, (const VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_self(cs, (const VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDevice8BitStorageFeatures_self(cs, (const VkPhysicalDevice8BitStorageFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_self(cs, (const VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_self(cs, (const VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self(cs, (const VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_self(cs, (const VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self(cs, (const VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_self(cs, (const VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_self(cs, (const VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self(cs, (const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan11Features_self(cs, (const VkPhysicalDeviceVulkan11Features *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan12Features_self(cs, (const VkPhysicalDeviceVulkan12Features *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceFeatures2_self(struct vn_cs *cs, const VkPhysicalDeviceFeatures2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPhysicalDeviceFeatures(cs, &val->features);
}

static inline void
vn_encode_VkPhysicalDeviceFeatures2(struct vn_cs *cs, const VkPhysicalDeviceFeatures2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 });
    vn_encode_VkPhysicalDeviceFeatures2_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceFeatures2_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVariablePointersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(cs, (VkPhysicalDeviceVariablePointersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceMultiviewFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(cs, (VkPhysicalDeviceMultiviewFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDevice16BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(cs, (VkPhysicalDevice16BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(cs, (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(cs, (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(cs, (VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(cs, (VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(cs, (VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceHostQueryResetFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(cs, (VkPhysicalDeviceHostQueryResetFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(cs, (VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(cs, (VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDevice8BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(cs, (VkPhysicalDevice8BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(cs, (VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(cs, (VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(cs, (VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(cs, (VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(cs, (VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(cs, (VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(cs, (VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(cs, (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan11Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(cs, (VkPhysicalDeviceVulkan11Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan12Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(cs, (VkPhysicalDeviceVulkan12Features *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_self_temp(struct vn_cs *cs, VkPhysicalDeviceFeatures2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceFeatures_temp(cs, &val->features);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_temp(struct vn_cs *cs, VkPhysicalDeviceFeatures2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceFeatures2_self_temp(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVariablePointersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_partial_temp(cs, (VkPhysicalDeviceVariablePointersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceMultiviewFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceMultiviewFeatures_self_partial_temp(cs, (VkPhysicalDeviceMultiviewFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDevice16BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDevice16BitStorageFeatures_self_partial_temp(cs, (VkPhysicalDevice16BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_partial_temp(cs, (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_partial_temp(cs, (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_partial_temp(cs, (VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_partial_temp(cs, (VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_partial_temp(cs, (VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceHostQueryResetFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_partial_temp(cs, (VkPhysicalDeviceHostQueryResetFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_partial_temp(cs, (VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_partial_temp(cs, (VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDevice8BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDevice8BitStorageFeatures_self_partial_temp(cs, (VkPhysicalDevice8BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_partial_temp(cs, (VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_partial_temp(cs, (VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_partial_temp(cs, (VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_partial_temp(cs, (VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_partial_temp(cs, (VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_partial_temp(cs, (VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_partial_temp(cs, (VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_partial_temp(cs, (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan11Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan11Features_self_partial_temp(cs, (VkPhysicalDeviceVulkan11Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan12Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan12Features_self_partial_temp(cs, (VkPhysicalDeviceVulkan12Features *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceFeatures2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceFeatures_partial_temp(cs, &val->features);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_partial_temp(struct vn_cs *cs, VkPhysicalDeviceFeatures2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceFeatures2_self_partial_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceFeatures2_handle_self(VkPhysicalDeviceFeatures2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkPhysicalDeviceFeatures_handle(&val->features);
}

static inline void
vn_replace_VkPhysicalDeviceFeatures2_handle(VkPhysicalDeviceFeatures2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            vn_replace_VkPhysicalDeviceFeatures2_handle_self((VkPhysicalDeviceFeatures2 *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            vn_replace_VkPhysicalDeviceVariablePointersFeatures_handle_self((VkPhysicalDeviceVariablePointersFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            vn_replace_VkPhysicalDeviceMultiviewFeatures_handle_self((VkPhysicalDeviceMultiviewFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            vn_replace_VkPhysicalDevice16BitStorageFeatures_handle_self((VkPhysicalDevice16BitStorageFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            vn_replace_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_handle_self((VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            vn_replace_VkPhysicalDeviceSamplerYcbcrConversionFeatures_handle_self((VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            vn_replace_VkPhysicalDeviceProtectedMemoryFeatures_handle_self((VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            vn_replace_VkPhysicalDeviceShaderDrawParametersFeatures_handle_self((VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            vn_replace_VkPhysicalDeviceShaderFloat16Int8Features_handle_self((VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            vn_replace_VkPhysicalDeviceHostQueryResetFeatures_handle_self((VkPhysicalDeviceHostQueryResetFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            vn_replace_VkPhysicalDeviceDescriptorIndexingFeatures_handle_self((VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            vn_replace_VkPhysicalDeviceTimelineSemaphoreFeatures_handle_self((VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            vn_replace_VkPhysicalDevice8BitStorageFeatures_handle_self((VkPhysicalDevice8BitStorageFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            vn_replace_VkPhysicalDeviceVulkanMemoryModelFeatures_handle_self((VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            vn_replace_VkPhysicalDeviceShaderAtomicInt64Features_handle_self((VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            vn_replace_VkPhysicalDeviceTransformFeedbackFeaturesEXT_handle_self((VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            vn_replace_VkPhysicalDeviceScalarBlockLayoutFeatures_handle_self((VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            vn_replace_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_handle_self((VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            vn_replace_VkPhysicalDeviceBufferDeviceAddressFeatures_handle_self((VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            vn_replace_VkPhysicalDeviceImagelessFramebufferFeatures_handle_self((VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            vn_replace_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_handle_self((VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            vn_replace_VkPhysicalDeviceVulkan11Features_handle_self((VkPhysicalDeviceVulkan11Features *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            vn_replace_VkPhysicalDeviceVulkan12Features_handle_self((VkPhysicalDeviceVulkan12Features *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDeviceGroupDeviceCreateInfo chain */

static inline void *
vn_decode_VkDeviceGroupDeviceCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupDeviceCreateInfo_self_temp(struct vn_cs *cs, VkDeviceGroupDeviceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->physicalDeviceCount);
    if (vn_peek_array_size(cs)) {
        val->pPhysicalDevices = vn_cs_alloc_temp(cs, sizeof(*val->pPhysicalDevices) * val->physicalDeviceCount);
        if (!val->pPhysicalDevices) return;
        vn_decode_array_size(cs, val->physicalDeviceCount);
        for (uint32_t i = 0; i < val->physicalDeviceCount; i++)
            vn_decode_VkPhysicalDevice_lookup(cs, &((VkPhysicalDevice *)val->pPhysicalDevices)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pPhysicalDevices = NULL;
    }
}

static inline void
vn_decode_VkDeviceGroupDeviceCreateInfo_temp(struct vn_cs *cs, VkDeviceGroupDeviceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupDeviceCreateInfo_pnext_temp(cs);
    vn_decode_VkDeviceGroupDeviceCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceGroupDeviceCreateInfo_handle_self(VkDeviceGroupDeviceCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->physicalDeviceCount */
    if (val->pPhysicalDevices) {
       for (uint32_t i = 0; i < val->physicalDeviceCount; i++)
            vn_replace_VkPhysicalDevice_handle(&((VkPhysicalDevice *)val->pPhysicalDevices)[i]);
    }
}

static inline void
vn_replace_VkDeviceGroupDeviceCreateInfo_handle(VkDeviceGroupDeviceCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            vn_replace_VkDeviceGroupDeviceCreateInfo_handle_self((VkDeviceGroupDeviceCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDeviceCreateInfo chain */

static inline void *
vn_decode_VkDeviceCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceFeatures2));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceFeatures2_self_temp(cs, (VkPhysicalDeviceFeatures2 *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVariablePointersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(cs, (VkPhysicalDeviceVariablePointersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceMultiviewFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(cs, (VkPhysicalDeviceMultiviewFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDeviceGroupDeviceCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkDeviceGroupDeviceCreateInfo_self_temp(cs, (VkDeviceGroupDeviceCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDevice16BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(cs, (VkPhysicalDevice16BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(cs, (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(cs, (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(cs, (VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(cs, (VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(cs, (VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceHostQueryResetFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(cs, (VkPhysicalDeviceHostQueryResetFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(cs, (VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(cs, (VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDevice8BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(cs, (VkPhysicalDevice8BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(cs, (VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(cs, (VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(cs, (VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(cs, (VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(cs, (VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(cs, (VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(cs, (VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(cs, (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan11Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(cs, (VkPhysicalDeviceVulkan11Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan12Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(cs, (VkPhysicalDeviceVulkan12Features *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDeviceCreateInfo_self_temp(struct vn_cs *cs, VkDeviceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->queueCreateInfoCount);
    if (vn_peek_array_size(cs)) {
        val->pQueueCreateInfos = vn_cs_alloc_temp(cs, sizeof(*val->pQueueCreateInfos) * val->queueCreateInfoCount);
        if (!val->pQueueCreateInfos) return;
        vn_decode_array_size(cs, val->queueCreateInfoCount);
        for (uint32_t i = 0; i < val->queueCreateInfoCount; i++)
            vn_decode_VkDeviceQueueCreateInfo_temp(cs, &((VkDeviceQueueCreateInfo *)val->pQueueCreateInfos)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pQueueCreateInfos = NULL;
    }
    vn_decode_uint32_t(cs, &val->enabledLayerCount);
    if (vn_peek_array_size(cs)) {
        val->ppEnabledLayerNames = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledLayerNames) * val->enabledLayerCount);
        if (!val->ppEnabledLayerNames) return;
        vn_decode_array_size(cs, val->enabledLayerCount);
        for (uint32_t i = 0; i < val->enabledLayerCount; i++) {
            const size_t string_size = vn_decode_array_size(cs, UINT64_MAX);
            ((char **)val->ppEnabledLayerNames)[i] = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledLayerNames[i]) * string_size);
            if (!val->ppEnabledLayerNames[i]) return;
            vn_decode_blob_array(cs, ((char **)val->ppEnabledLayerNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(cs, 0);
        val->ppEnabledLayerNames = NULL;
    }
    vn_decode_uint32_t(cs, &val->enabledExtensionCount);
    if (vn_peek_array_size(cs)) {
        val->ppEnabledExtensionNames = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledExtensionNames) * val->enabledExtensionCount);
        if (!val->ppEnabledExtensionNames) return;
        vn_decode_array_size(cs, val->enabledExtensionCount);
        for (uint32_t i = 0; i < val->enabledExtensionCount; i++) {
            const size_t string_size = vn_decode_array_size(cs, UINT64_MAX);
            ((char **)val->ppEnabledExtensionNames)[i] = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledExtensionNames[i]) * string_size);
            if (!val->ppEnabledExtensionNames[i]) return;
            vn_decode_blob_array(cs, ((char **)val->ppEnabledExtensionNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(cs, 0);
        val->ppEnabledExtensionNames = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pEnabledFeatures = vn_cs_alloc_temp(cs, sizeof(*val->pEnabledFeatures));
        if (!val->pEnabledFeatures) return;
        vn_decode_VkPhysicalDeviceFeatures_temp(cs, (VkPhysicalDeviceFeatures *)val->pEnabledFeatures);
    } else {
        val->pEnabledFeatures = NULL;
    }
}

static inline void
vn_decode_VkDeviceCreateInfo_temp(struct vn_cs *cs, VkDeviceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(cs);
    vn_decode_VkDeviceCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceCreateInfo_handle_self(VkDeviceCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->queueCreateInfoCount */
    if (val->pQueueCreateInfos) {
       for (uint32_t i = 0; i < val->queueCreateInfoCount; i++)
            vn_replace_VkDeviceQueueCreateInfo_handle(&((VkDeviceQueueCreateInfo *)val->pQueueCreateInfos)[i]);
    }
    /* skip val->enabledLayerCount */
    /* skip val->ppEnabledLayerNames */
    /* skip val->enabledExtensionCount */
    /* skip val->ppEnabledExtensionNames */
    if (val->pEnabledFeatures)
        vn_replace_VkPhysicalDeviceFeatures_handle((VkPhysicalDeviceFeatures *)val->pEnabledFeatures);
}

static inline void
vn_replace_VkDeviceCreateInfo_handle(VkDeviceCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO:
            vn_replace_VkDeviceCreateInfo_handle_self((VkDeviceCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            vn_replace_VkPhysicalDeviceFeatures2_handle_self((VkPhysicalDeviceFeatures2 *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            vn_replace_VkPhysicalDeviceVariablePointersFeatures_handle_self((VkPhysicalDeviceVariablePointersFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            vn_replace_VkPhysicalDeviceMultiviewFeatures_handle_self((VkPhysicalDeviceMultiviewFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            vn_replace_VkDeviceGroupDeviceCreateInfo_handle_self((VkDeviceGroupDeviceCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            vn_replace_VkPhysicalDevice16BitStorageFeatures_handle_self((VkPhysicalDevice16BitStorageFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            vn_replace_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_handle_self((VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            vn_replace_VkPhysicalDeviceSamplerYcbcrConversionFeatures_handle_self((VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            vn_replace_VkPhysicalDeviceProtectedMemoryFeatures_handle_self((VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            vn_replace_VkPhysicalDeviceShaderDrawParametersFeatures_handle_self((VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            vn_replace_VkPhysicalDeviceShaderFloat16Int8Features_handle_self((VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            vn_replace_VkPhysicalDeviceHostQueryResetFeatures_handle_self((VkPhysicalDeviceHostQueryResetFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            vn_replace_VkPhysicalDeviceDescriptorIndexingFeatures_handle_self((VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            vn_replace_VkPhysicalDeviceTimelineSemaphoreFeatures_handle_self((VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            vn_replace_VkPhysicalDevice8BitStorageFeatures_handle_self((VkPhysicalDevice8BitStorageFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            vn_replace_VkPhysicalDeviceVulkanMemoryModelFeatures_handle_self((VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            vn_replace_VkPhysicalDeviceShaderAtomicInt64Features_handle_self((VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            vn_replace_VkPhysicalDeviceTransformFeedbackFeaturesEXT_handle_self((VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            vn_replace_VkPhysicalDeviceScalarBlockLayoutFeatures_handle_self((VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            vn_replace_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_handle_self((VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            vn_replace_VkPhysicalDeviceBufferDeviceAddressFeatures_handle_self((VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            vn_replace_VkPhysicalDeviceImagelessFramebufferFeatures_handle_self((VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            vn_replace_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_handle_self((VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            vn_replace_VkPhysicalDeviceVulkan11Features_handle_self((VkPhysicalDeviceVulkan11Features *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            vn_replace_VkPhysicalDeviceVulkan12Features_handle_self((VkPhysicalDeviceVulkan12Features *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkInstanceCreateInfo chain */

static inline void *
vn_decode_VkInstanceCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkInstanceCreateInfo_self_temp(struct vn_cs *cs, VkInstanceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    if (vn_decode_simple_pointer(cs)) {
        val->pApplicationInfo = vn_cs_alloc_temp(cs, sizeof(*val->pApplicationInfo));
        if (!val->pApplicationInfo) return;
        vn_decode_VkApplicationInfo_temp(cs, (VkApplicationInfo *)val->pApplicationInfo);
    } else {
        val->pApplicationInfo = NULL;
    }
    vn_decode_uint32_t(cs, &val->enabledLayerCount);
    if (vn_peek_array_size(cs)) {
        val->ppEnabledLayerNames = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledLayerNames) * val->enabledLayerCount);
        if (!val->ppEnabledLayerNames) return;
        vn_decode_array_size(cs, val->enabledLayerCount);
        for (uint32_t i = 0; i < val->enabledLayerCount; i++) {
            const size_t string_size = vn_decode_array_size(cs, UINT64_MAX);
            ((char **)val->ppEnabledLayerNames)[i] = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledLayerNames[i]) * string_size);
            if (!val->ppEnabledLayerNames[i]) return;
            vn_decode_blob_array(cs, ((char **)val->ppEnabledLayerNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(cs, 0);
        val->ppEnabledLayerNames = NULL;
    }
    vn_decode_uint32_t(cs, &val->enabledExtensionCount);
    if (vn_peek_array_size(cs)) {
        val->ppEnabledExtensionNames = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledExtensionNames) * val->enabledExtensionCount);
        if (!val->ppEnabledExtensionNames) return;
        vn_decode_array_size(cs, val->enabledExtensionCount);
        for (uint32_t i = 0; i < val->enabledExtensionCount; i++) {
            const size_t string_size = vn_decode_array_size(cs, UINT64_MAX);
            ((char **)val->ppEnabledExtensionNames)[i] = vn_cs_alloc_temp(cs, sizeof(*val->ppEnabledExtensionNames[i]) * string_size);
            if (!val->ppEnabledExtensionNames[i]) return;
            vn_decode_blob_array(cs, ((char **)val->ppEnabledExtensionNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(cs, 0);
        val->ppEnabledExtensionNames = NULL;
    }
}

static inline void
vn_decode_VkInstanceCreateInfo_temp(struct vn_cs *cs, VkInstanceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkInstanceCreateInfo_pnext_temp(cs);
    vn_decode_VkInstanceCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkInstanceCreateInfo_handle_self(VkInstanceCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    if (val->pApplicationInfo)
        vn_replace_VkApplicationInfo_handle((VkApplicationInfo *)val->pApplicationInfo);
    /* skip val->enabledLayerCount */
    /* skip val->ppEnabledLayerNames */
    /* skip val->enabledExtensionCount */
    /* skip val->ppEnabledExtensionNames */
}

static inline void
vn_replace_VkInstanceCreateInfo_handle(VkInstanceCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO:
            vn_replace_VkInstanceCreateInfo_handle_self((VkInstanceCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkQueueFamilyProperties */

static inline void
vn_encode_VkQueueFamilyProperties(struct vn_cs *cs, const VkQueueFamilyProperties *val)
{
    vn_encode_VkFlags(cs, &val->queueFlags);
    vn_encode_uint32_t(cs, &val->queueCount);
    vn_encode_uint32_t(cs, &val->timestampValidBits);
    vn_encode_VkExtent3D(cs, &val->minImageTransferGranularity);
}

static inline void
vn_decode_VkQueueFamilyProperties_partial_temp(struct vn_cs *cs, VkQueueFamilyProperties *val)
{
    /* skip val->queueFlags */
    /* skip val->queueCount */
    /* skip val->timestampValidBits */
    vn_decode_VkExtent3D_partial_temp(cs, &val->minImageTransferGranularity);
}

/* struct VkMemoryType */

static inline void
vn_encode_VkMemoryType(struct vn_cs *cs, const VkMemoryType *val)
{
    vn_encode_VkFlags(cs, &val->propertyFlags);
    vn_encode_uint32_t(cs, &val->heapIndex);
}

static inline void
vn_decode_VkMemoryType_partial_temp(struct vn_cs *cs, VkMemoryType *val)
{
    /* skip val->propertyFlags */
    /* skip val->heapIndex */
}

/* struct VkMemoryHeap */

static inline void
vn_encode_VkMemoryHeap(struct vn_cs *cs, const VkMemoryHeap *val)
{
    vn_encode_VkDeviceSize(cs, &val->size);
    vn_encode_VkFlags(cs, &val->flags);
}

static inline void
vn_decode_VkMemoryHeap_partial_temp(struct vn_cs *cs, VkMemoryHeap *val)
{
    /* skip val->size */
    /* skip val->flags */
}

/* struct VkPhysicalDeviceMemoryProperties */

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties(struct vn_cs *cs, const VkPhysicalDeviceMemoryProperties *val)
{
    vn_encode_uint32_t(cs, &val->memoryTypeCount);
    vn_encode_array_size(cs, VK_MAX_MEMORY_TYPES);
    for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; i++)
        vn_encode_VkMemoryType(cs, &val->memoryTypes[i]);
    vn_encode_uint32_t(cs, &val->memoryHeapCount);
    vn_encode_array_size(cs, VK_MAX_MEMORY_HEAPS);
    for (uint32_t i = 0; i < VK_MAX_MEMORY_HEAPS; i++)
        vn_encode_VkMemoryHeap(cs, &val->memoryHeaps[i]);
}

static inline void
vn_decode_VkPhysicalDeviceMemoryProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMemoryProperties *val)
{
    /* skip val->memoryTypeCount */
    {
        vn_decode_array_size(cs, VK_MAX_MEMORY_TYPES);
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; i++)
            vn_decode_VkMemoryType_partial_temp(cs, &val->memoryTypes[i]);
    }
    /* skip val->memoryHeapCount */
    {
        vn_decode_array_size(cs, VK_MAX_MEMORY_HEAPS);
        for (uint32_t i = 0; i < VK_MAX_MEMORY_HEAPS; i++)
            vn_decode_VkMemoryHeap_partial_temp(cs, &val->memoryHeaps[i]);
    }
}

/* struct VkExportMemoryAllocateInfo chain */

static inline void *
vn_decode_VkExportMemoryAllocateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExportMemoryAllocateInfo_self_temp(struct vn_cs *cs, VkExportMemoryAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->handleTypes);
}

static inline void
vn_decode_VkExportMemoryAllocateInfo_temp(struct vn_cs *cs, VkExportMemoryAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExportMemoryAllocateInfo_pnext_temp(cs);
    vn_decode_VkExportMemoryAllocateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkExportMemoryAllocateInfo_handle_self(VkExportMemoryAllocateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleTypes */
}

static inline void
vn_replace_VkExportMemoryAllocateInfo_handle(VkExportMemoryAllocateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            vn_replace_VkExportMemoryAllocateInfo_handle_self((VkExportMemoryAllocateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkMemoryAllocateFlagsInfo chain */

static inline void *
vn_decode_VkMemoryAllocateFlagsInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkMemoryAllocateFlagsInfo_self_temp(struct vn_cs *cs, VkMemoryAllocateFlagsInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->deviceMask);
}

static inline void
vn_decode_VkMemoryAllocateFlagsInfo_temp(struct vn_cs *cs, VkMemoryAllocateFlagsInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryAllocateFlagsInfo_pnext_temp(cs);
    vn_decode_VkMemoryAllocateFlagsInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkMemoryAllocateFlagsInfo_handle_self(VkMemoryAllocateFlagsInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->deviceMask */
}

static inline void
vn_replace_VkMemoryAllocateFlagsInfo_handle(VkMemoryAllocateFlagsInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            vn_replace_VkMemoryAllocateFlagsInfo_handle_self((VkMemoryAllocateFlagsInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkMemoryDedicatedAllocateInfo chain */

static inline void *
vn_decode_VkMemoryDedicatedAllocateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkMemoryDedicatedAllocateInfo_self_temp(struct vn_cs *cs, VkMemoryDedicatedAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(cs, &val->image);
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
}

static inline void
vn_decode_VkMemoryDedicatedAllocateInfo_temp(struct vn_cs *cs, VkMemoryDedicatedAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryDedicatedAllocateInfo_pnext_temp(cs);
    vn_decode_VkMemoryDedicatedAllocateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkMemoryDedicatedAllocateInfo_handle_self(VkMemoryDedicatedAllocateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkImage_handle(&val->image);
    vn_replace_VkBuffer_handle(&val->buffer);
}

static inline void
vn_replace_VkMemoryDedicatedAllocateInfo_handle(VkMemoryDedicatedAllocateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            vn_replace_VkMemoryDedicatedAllocateInfo_handle_self((VkMemoryDedicatedAllocateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkMemoryOpaqueCaptureAddressAllocateInfo chain */

static inline void *
vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_self_temp(struct vn_cs *cs, VkMemoryOpaqueCaptureAddressAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(cs, &val->opaqueCaptureAddress);
}

static inline void
vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_temp(struct vn_cs *cs, VkMemoryOpaqueCaptureAddressAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_pnext_temp(cs);
    vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkMemoryOpaqueCaptureAddressAllocateInfo_handle_self(VkMemoryOpaqueCaptureAddressAllocateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->opaqueCaptureAddress */
}

static inline void
vn_replace_VkMemoryOpaqueCaptureAddressAllocateInfo_handle(VkMemoryOpaqueCaptureAddressAllocateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            vn_replace_VkMemoryOpaqueCaptureAddressAllocateInfo_handle_self((VkMemoryOpaqueCaptureAddressAllocateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkMemoryAllocateInfo chain */

static inline void *
vn_decode_VkMemoryAllocateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkExportMemoryAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(cs);
            vn_decode_VkExportMemoryAllocateInfo_self_temp(cs, (VkExportMemoryAllocateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkMemoryAllocateFlagsInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(cs);
            vn_decode_VkMemoryAllocateFlagsInfo_self_temp(cs, (VkMemoryAllocateFlagsInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkMemoryDedicatedAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(cs);
            vn_decode_VkMemoryDedicatedAllocateInfo_self_temp(cs, (VkMemoryDedicatedAllocateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkMemoryOpaqueCaptureAddressAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(cs);
            vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_self_temp(cs, (VkMemoryOpaqueCaptureAddressAllocateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkMemoryAllocateInfo_self_temp(struct vn_cs *cs, VkMemoryAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDeviceSize(cs, &val->allocationSize);
    vn_decode_uint32_t(cs, &val->memoryTypeIndex);
}

static inline void
vn_decode_VkMemoryAllocateInfo_temp(struct vn_cs *cs, VkMemoryAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(cs);
    vn_decode_VkMemoryAllocateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkMemoryAllocateInfo_handle_self(VkMemoryAllocateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->allocationSize */
    /* skip val->memoryTypeIndex */
}

static inline void
vn_replace_VkMemoryAllocateInfo_handle(VkMemoryAllocateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO:
            vn_replace_VkMemoryAllocateInfo_handle_self((VkMemoryAllocateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            vn_replace_VkExportMemoryAllocateInfo_handle_self((VkExportMemoryAllocateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            vn_replace_VkMemoryAllocateFlagsInfo_handle_self((VkMemoryAllocateFlagsInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            vn_replace_VkMemoryDedicatedAllocateInfo_handle_self((VkMemoryDedicatedAllocateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            vn_replace_VkMemoryOpaqueCaptureAddressAllocateInfo_handle_self((VkMemoryOpaqueCaptureAddressAllocateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkMemoryRequirements */

static inline void
vn_encode_VkMemoryRequirements(struct vn_cs *cs, const VkMemoryRequirements *val)
{
    vn_encode_VkDeviceSize(cs, &val->size);
    vn_encode_VkDeviceSize(cs, &val->alignment);
    vn_encode_uint32_t(cs, &val->memoryTypeBits);
}

static inline void
vn_decode_VkMemoryRequirements_partial_temp(struct vn_cs *cs, VkMemoryRequirements *val)
{
    /* skip val->size */
    /* skip val->alignment */
    /* skip val->memoryTypeBits */
}

/* struct VkSparseImageFormatProperties */

static inline void
vn_encode_VkSparseImageFormatProperties(struct vn_cs *cs, const VkSparseImageFormatProperties *val)
{
    vn_encode_VkFlags(cs, &val->aspectMask);
    vn_encode_VkExtent3D(cs, &val->imageGranularity);
    vn_encode_VkFlags(cs, &val->flags);
}

static inline void
vn_decode_VkSparseImageFormatProperties_partial_temp(struct vn_cs *cs, VkSparseImageFormatProperties *val)
{
    /* skip val->aspectMask */
    vn_decode_VkExtent3D_partial_temp(cs, &val->imageGranularity);
    /* skip val->flags */
}

/* struct VkSparseImageMemoryRequirements */

static inline void
vn_encode_VkSparseImageMemoryRequirements(struct vn_cs *cs, const VkSparseImageMemoryRequirements *val)
{
    vn_encode_VkSparseImageFormatProperties(cs, &val->formatProperties);
    vn_encode_uint32_t(cs, &val->imageMipTailFirstLod);
    vn_encode_VkDeviceSize(cs, &val->imageMipTailSize);
    vn_encode_VkDeviceSize(cs, &val->imageMipTailOffset);
    vn_encode_VkDeviceSize(cs, &val->imageMipTailStride);
}

static inline void
vn_decode_VkSparseImageMemoryRequirements_partial_temp(struct vn_cs *cs, VkSparseImageMemoryRequirements *val)
{
    vn_decode_VkSparseImageFormatProperties_partial_temp(cs, &val->formatProperties);
    /* skip val->imageMipTailFirstLod */
    /* skip val->imageMipTailSize */
    /* skip val->imageMipTailOffset */
    /* skip val->imageMipTailStride */
}

/* struct VkMappedMemoryRange chain */

static inline void
vn_encode_VkMappedMemoryRange_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkMappedMemoryRange_self(struct vn_cs *cs, const VkMappedMemoryRange *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDeviceMemory(cs, &val->memory);
    vn_encode_VkDeviceSize(cs, &val->offset);
    vn_encode_VkDeviceSize(cs, &val->size);
}

static inline void
vn_encode_VkMappedMemoryRange(struct vn_cs *cs, const VkMappedMemoryRange *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE });
    vn_encode_VkMappedMemoryRange_pnext(cs, val->pNext);
    vn_encode_VkMappedMemoryRange_self(cs, val);
}

static inline void *
vn_decode_VkMappedMemoryRange_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkMappedMemoryRange_self_temp(struct vn_cs *cs, VkMappedMemoryRange *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDeviceMemory_lookup(cs, &val->memory);
    vn_decode_VkDeviceSize(cs, &val->offset);
    vn_decode_VkDeviceSize(cs, &val->size);
}

static inline void
vn_decode_VkMappedMemoryRange_temp(struct vn_cs *cs, VkMappedMemoryRange *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE);

    val->sType = stype;
    val->pNext = vn_decode_VkMappedMemoryRange_pnext_temp(cs);
    vn_decode_VkMappedMemoryRange_self_temp(cs, val);
}

static inline void
vn_replace_VkMappedMemoryRange_handle_self(VkMappedMemoryRange *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkDeviceMemory_handle(&val->memory);
    /* skip val->offset */
    /* skip val->size */
}

static inline void
vn_replace_VkMappedMemoryRange_handle(VkMappedMemoryRange *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE:
            vn_replace_VkMappedMemoryRange_handle_self((VkMappedMemoryRange *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkFormatProperties */

static inline void
vn_encode_VkFormatProperties(struct vn_cs *cs, const VkFormatProperties *val)
{
    vn_encode_VkFlags(cs, &val->linearTilingFeatures);
    vn_encode_VkFlags(cs, &val->optimalTilingFeatures);
    vn_encode_VkFlags(cs, &val->bufferFeatures);
}

static inline void
vn_decode_VkFormatProperties_partial_temp(struct vn_cs *cs, VkFormatProperties *val)
{
    /* skip val->linearTilingFeatures */
    /* skip val->optimalTilingFeatures */
    /* skip val->bufferFeatures */
}

/* struct VkImageFormatProperties */

static inline void
vn_encode_VkImageFormatProperties(struct vn_cs *cs, const VkImageFormatProperties *val)
{
    vn_encode_VkExtent3D(cs, &val->maxExtent);
    vn_encode_uint32_t(cs, &val->maxMipLevels);
    vn_encode_uint32_t(cs, &val->maxArrayLayers);
    vn_encode_VkFlags(cs, &val->sampleCounts);
    vn_encode_VkDeviceSize(cs, &val->maxResourceSize);
}

static inline void
vn_decode_VkImageFormatProperties_partial_temp(struct vn_cs *cs, VkImageFormatProperties *val)
{
    vn_decode_VkExtent3D_partial_temp(cs, &val->maxExtent);
    /* skip val->maxMipLevels */
    /* skip val->maxArrayLayers */
    /* skip val->sampleCounts */
    /* skip val->maxResourceSize */
}

/* struct VkDescriptorBufferInfo */

static inline void
vn_decode_VkDescriptorBufferInfo_temp(struct vn_cs *cs, VkDescriptorBufferInfo *val)
{
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
    vn_decode_VkDeviceSize(cs, &val->offset);
    vn_decode_VkDeviceSize(cs, &val->range);
}

static inline void
vn_replace_VkDescriptorBufferInfo_handle(VkDescriptorBufferInfo *val)
{
    vn_replace_VkBuffer_handle(&val->buffer);
    /* skip val->offset */
    /* skip val->range */
}

/* struct VkDescriptorImageInfo */

static inline void
vn_decode_VkDescriptorImageInfo_temp(struct vn_cs *cs, VkDescriptorImageInfo *val)
{
    vn_decode_VkSampler_lookup(cs, &val->sampler);
    vn_decode_VkImageView_lookup(cs, &val->imageView);
    vn_decode_VkImageLayout(cs, &val->imageLayout);
}

static inline void
vn_replace_VkDescriptorImageInfo_handle(VkDescriptorImageInfo *val)
{
    vn_replace_VkSampler_handle(&val->sampler);
    vn_replace_VkImageView_handle(&val->imageView);
    /* skip val->imageLayout */
}

/* struct VkWriteDescriptorSet chain */

static inline void *
vn_decode_VkWriteDescriptorSet_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkWriteDescriptorSet_self_temp(struct vn_cs *cs, VkWriteDescriptorSet *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDescriptorSet_lookup(cs, &val->dstSet);
    vn_decode_uint32_t(cs, &val->dstBinding);
    vn_decode_uint32_t(cs, &val->dstArrayElement);
    vn_decode_uint32_t(cs, &val->descriptorCount);
    vn_decode_VkDescriptorType(cs, &val->descriptorType);
    if (vn_peek_array_size(cs)) {
        val->pImageInfo = vn_cs_alloc_temp(cs, sizeof(*val->pImageInfo) * val->descriptorCount);
        if (!val->pImageInfo) return;
        vn_decode_array_size(cs, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkDescriptorImageInfo_temp(cs, &((VkDescriptorImageInfo *)val->pImageInfo)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pImageInfo = NULL;
    }
    if (vn_peek_array_size(cs)) {
        val->pBufferInfo = vn_cs_alloc_temp(cs, sizeof(*val->pBufferInfo) * val->descriptorCount);
        if (!val->pBufferInfo) return;
        vn_decode_array_size(cs, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkDescriptorBufferInfo_temp(cs, &((VkDescriptorBufferInfo *)val->pBufferInfo)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pBufferInfo = NULL;
    }
    if (vn_peek_array_size(cs)) {
        val->pTexelBufferView = vn_cs_alloc_temp(cs, sizeof(*val->pTexelBufferView) * val->descriptorCount);
        if (!val->pTexelBufferView) return;
        vn_decode_array_size(cs, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkBufferView_lookup(cs, &((VkBufferView *)val->pTexelBufferView)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pTexelBufferView = NULL;
    }
}

static inline void
vn_decode_VkWriteDescriptorSet_temp(struct vn_cs *cs, VkWriteDescriptorSet *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET);

    val->sType = stype;
    val->pNext = vn_decode_VkWriteDescriptorSet_pnext_temp(cs);
    vn_decode_VkWriteDescriptorSet_self_temp(cs, val);
}

static inline void
vn_replace_VkWriteDescriptorSet_handle_self(VkWriteDescriptorSet *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkDescriptorSet_handle(&val->dstSet);
    /* skip val->dstBinding */
    /* skip val->dstArrayElement */
    /* skip val->descriptorCount */
    /* skip val->descriptorType */
    if (val->pImageInfo) {
       for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_replace_VkDescriptorImageInfo_handle(&((VkDescriptorImageInfo *)val->pImageInfo)[i]);
    }
    if (val->pBufferInfo) {
       for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_replace_VkDescriptorBufferInfo_handle(&((VkDescriptorBufferInfo *)val->pBufferInfo)[i]);
    }
    if (val->pTexelBufferView) {
       for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_replace_VkBufferView_handle(&((VkBufferView *)val->pTexelBufferView)[i]);
    }
}

static inline void
vn_replace_VkWriteDescriptorSet_handle(VkWriteDescriptorSet *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET:
            vn_replace_VkWriteDescriptorSet_handle_self((VkWriteDescriptorSet *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkCopyDescriptorSet chain */

static inline void *
vn_decode_VkCopyDescriptorSet_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkCopyDescriptorSet_self_temp(struct vn_cs *cs, VkCopyDescriptorSet *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDescriptorSet_lookup(cs, &val->srcSet);
    vn_decode_uint32_t(cs, &val->srcBinding);
    vn_decode_uint32_t(cs, &val->srcArrayElement);
    vn_decode_VkDescriptorSet_lookup(cs, &val->dstSet);
    vn_decode_uint32_t(cs, &val->dstBinding);
    vn_decode_uint32_t(cs, &val->dstArrayElement);
    vn_decode_uint32_t(cs, &val->descriptorCount);
}

static inline void
vn_decode_VkCopyDescriptorSet_temp(struct vn_cs *cs, VkCopyDescriptorSet *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET);

    val->sType = stype;
    val->pNext = vn_decode_VkCopyDescriptorSet_pnext_temp(cs);
    vn_decode_VkCopyDescriptorSet_self_temp(cs, val);
}

static inline void
vn_replace_VkCopyDescriptorSet_handle_self(VkCopyDescriptorSet *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkDescriptorSet_handle(&val->srcSet);
    /* skip val->srcBinding */
    /* skip val->srcArrayElement */
    vn_replace_VkDescriptorSet_handle(&val->dstSet);
    /* skip val->dstBinding */
    /* skip val->dstArrayElement */
    /* skip val->descriptorCount */
}

static inline void
vn_replace_VkCopyDescriptorSet_handle(VkCopyDescriptorSet *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET:
            vn_replace_VkCopyDescriptorSet_handle_self((VkCopyDescriptorSet *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkExternalMemoryBufferCreateInfo chain */

static inline void *
vn_decode_VkExternalMemoryBufferCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExternalMemoryBufferCreateInfo_self_temp(struct vn_cs *cs, VkExternalMemoryBufferCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->handleTypes);
}

static inline void
vn_decode_VkExternalMemoryBufferCreateInfo_temp(struct vn_cs *cs, VkExternalMemoryBufferCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalMemoryBufferCreateInfo_pnext_temp(cs);
    vn_decode_VkExternalMemoryBufferCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkExternalMemoryBufferCreateInfo_handle_self(VkExternalMemoryBufferCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleTypes */
}

static inline void
vn_replace_VkExternalMemoryBufferCreateInfo_handle(VkExternalMemoryBufferCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            vn_replace_VkExternalMemoryBufferCreateInfo_handle_self((VkExternalMemoryBufferCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBufferOpaqueCaptureAddressCreateInfo chain */

static inline void *
vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_self_temp(struct vn_cs *cs, VkBufferOpaqueCaptureAddressCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(cs, &val->opaqueCaptureAddress);
}

static inline void
vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_temp(struct vn_cs *cs, VkBufferOpaqueCaptureAddressCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_pnext_temp(cs);
    vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBufferOpaqueCaptureAddressCreateInfo_handle_self(VkBufferOpaqueCaptureAddressCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->opaqueCaptureAddress */
}

static inline void
vn_replace_VkBufferOpaqueCaptureAddressCreateInfo_handle(VkBufferOpaqueCaptureAddressCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            vn_replace_VkBufferOpaqueCaptureAddressCreateInfo_handle_self((VkBufferOpaqueCaptureAddressCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBufferCreateInfo chain */

static inline void *
vn_decode_VkBufferCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkExternalMemoryBufferCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBufferCreateInfo_pnext_temp(cs);
            vn_decode_VkExternalMemoryBufferCreateInfo_self_temp(cs, (VkExternalMemoryBufferCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkBufferOpaqueCaptureAddressCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBufferCreateInfo_pnext_temp(cs);
            vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_self_temp(cs, (VkBufferOpaqueCaptureAddressCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBufferCreateInfo_self_temp(struct vn_cs *cs, VkBufferCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkDeviceSize(cs, &val->size);
    vn_decode_VkFlags(cs, &val->usage);
    vn_decode_VkSharingMode(cs, &val->sharingMode);
    vn_decode_uint32_t(cs, &val->queueFamilyIndexCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->queueFamilyIndexCount);
        val->pQueueFamilyIndices = vn_cs_alloc_temp(cs, sizeof(*val->pQueueFamilyIndices) * array_size);
        if (!val->pQueueFamilyIndices) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pQueueFamilyIndices, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pQueueFamilyIndices = NULL;
    }
}

static inline void
vn_decode_VkBufferCreateInfo_temp(struct vn_cs *cs, VkBufferCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferCreateInfo_pnext_temp(cs);
    vn_decode_VkBufferCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBufferCreateInfo_handle_self(VkBufferCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->size */
    /* skip val->usage */
    /* skip val->sharingMode */
    /* skip val->queueFamilyIndexCount */
    /* skip val->pQueueFamilyIndices */
}

static inline void
vn_replace_VkBufferCreateInfo_handle(VkBufferCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO:
            vn_replace_VkBufferCreateInfo_handle_self((VkBufferCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            vn_replace_VkExternalMemoryBufferCreateInfo_handle_self((VkExternalMemoryBufferCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            vn_replace_VkBufferOpaqueCaptureAddressCreateInfo_handle_self((VkBufferOpaqueCaptureAddressCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBufferViewCreateInfo chain */

static inline void *
vn_decode_VkBufferViewCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBufferViewCreateInfo_self_temp(struct vn_cs *cs, VkBufferViewCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkDeviceSize(cs, &val->offset);
    vn_decode_VkDeviceSize(cs, &val->range);
}

static inline void
vn_decode_VkBufferViewCreateInfo_temp(struct vn_cs *cs, VkBufferViewCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferViewCreateInfo_pnext_temp(cs);
    vn_decode_VkBufferViewCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBufferViewCreateInfo_handle_self(VkBufferViewCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    vn_replace_VkBuffer_handle(&val->buffer);
    /* skip val->format */
    /* skip val->offset */
    /* skip val->range */
}

static inline void
vn_replace_VkBufferViewCreateInfo_handle(VkBufferViewCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO:
            vn_replace_VkBufferViewCreateInfo_handle_self((VkBufferViewCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageSubresource */

static inline void
vn_decode_VkImageSubresource_temp(struct vn_cs *cs, VkImageSubresource *val)
{
    vn_decode_VkFlags(cs, &val->aspectMask);
    vn_decode_uint32_t(cs, &val->mipLevel);
    vn_decode_uint32_t(cs, &val->arrayLayer);
}

static inline void
vn_replace_VkImageSubresource_handle(VkImageSubresource *val)
{
    /* skip val->aspectMask */
    /* skip val->mipLevel */
    /* skip val->arrayLayer */
}

/* struct VkImageSubresourceLayers */

static inline void
vn_decode_VkImageSubresourceLayers_temp(struct vn_cs *cs, VkImageSubresourceLayers *val)
{
    vn_decode_VkFlags(cs, &val->aspectMask);
    vn_decode_uint32_t(cs, &val->mipLevel);
    vn_decode_uint32_t(cs, &val->baseArrayLayer);
    vn_decode_uint32_t(cs, &val->layerCount);
}

static inline void
vn_replace_VkImageSubresourceLayers_handle(VkImageSubresourceLayers *val)
{
    /* skip val->aspectMask */
    /* skip val->mipLevel */
    /* skip val->baseArrayLayer */
    /* skip val->layerCount */
}

/* struct VkImageSubresourceRange */

static inline void
vn_decode_VkImageSubresourceRange_temp(struct vn_cs *cs, VkImageSubresourceRange *val)
{
    vn_decode_VkFlags(cs, &val->aspectMask);
    vn_decode_uint32_t(cs, &val->baseMipLevel);
    vn_decode_uint32_t(cs, &val->levelCount);
    vn_decode_uint32_t(cs, &val->baseArrayLayer);
    vn_decode_uint32_t(cs, &val->layerCount);
}

static inline void
vn_replace_VkImageSubresourceRange_handle(VkImageSubresourceRange *val)
{
    /* skip val->aspectMask */
    /* skip val->baseMipLevel */
    /* skip val->levelCount */
    /* skip val->baseArrayLayer */
    /* skip val->layerCount */
}

/* struct VkMemoryBarrier chain */

static inline void *
vn_decode_VkMemoryBarrier_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkMemoryBarrier_self_temp(struct vn_cs *cs, VkMemoryBarrier *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->srcAccessMask);
    vn_decode_VkFlags(cs, &val->dstAccessMask);
}

static inline void
vn_decode_VkMemoryBarrier_temp(struct vn_cs *cs, VkMemoryBarrier *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_BARRIER);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryBarrier_pnext_temp(cs);
    vn_decode_VkMemoryBarrier_self_temp(cs, val);
}

static inline void
vn_replace_VkMemoryBarrier_handle_self(VkMemoryBarrier *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->srcAccessMask */
    /* skip val->dstAccessMask */
}

static inline void
vn_replace_VkMemoryBarrier_handle(VkMemoryBarrier *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER:
            vn_replace_VkMemoryBarrier_handle_self((VkMemoryBarrier *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBufferMemoryBarrier chain */

static inline void *
vn_decode_VkBufferMemoryBarrier_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBufferMemoryBarrier_self_temp(struct vn_cs *cs, VkBufferMemoryBarrier *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->srcAccessMask);
    vn_decode_VkFlags(cs, &val->dstAccessMask);
    vn_decode_uint32_t(cs, &val->srcQueueFamilyIndex);
    vn_decode_uint32_t(cs, &val->dstQueueFamilyIndex);
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
    vn_decode_VkDeviceSize(cs, &val->offset);
    vn_decode_VkDeviceSize(cs, &val->size);
}

static inline void
vn_decode_VkBufferMemoryBarrier_temp(struct vn_cs *cs, VkBufferMemoryBarrier *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferMemoryBarrier_pnext_temp(cs);
    vn_decode_VkBufferMemoryBarrier_self_temp(cs, val);
}

static inline void
vn_replace_VkBufferMemoryBarrier_handle_self(VkBufferMemoryBarrier *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->srcAccessMask */
    /* skip val->dstAccessMask */
    /* skip val->srcQueueFamilyIndex */
    /* skip val->dstQueueFamilyIndex */
    vn_replace_VkBuffer_handle(&val->buffer);
    /* skip val->offset */
    /* skip val->size */
}

static inline void
vn_replace_VkBufferMemoryBarrier_handle(VkBufferMemoryBarrier *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER:
            vn_replace_VkBufferMemoryBarrier_handle_self((VkBufferMemoryBarrier *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageMemoryBarrier chain */

static inline void *
vn_decode_VkImageMemoryBarrier_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageMemoryBarrier_self_temp(struct vn_cs *cs, VkImageMemoryBarrier *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->srcAccessMask);
    vn_decode_VkFlags(cs, &val->dstAccessMask);
    vn_decode_VkImageLayout(cs, &val->oldLayout);
    vn_decode_VkImageLayout(cs, &val->newLayout);
    vn_decode_uint32_t(cs, &val->srcQueueFamilyIndex);
    vn_decode_uint32_t(cs, &val->dstQueueFamilyIndex);
    vn_decode_VkImage_lookup(cs, &val->image);
    vn_decode_VkImageSubresourceRange_temp(cs, &val->subresourceRange);
}

static inline void
vn_decode_VkImageMemoryBarrier_temp(struct vn_cs *cs, VkImageMemoryBarrier *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER);

    val->sType = stype;
    val->pNext = vn_decode_VkImageMemoryBarrier_pnext_temp(cs);
    vn_decode_VkImageMemoryBarrier_self_temp(cs, val);
}

static inline void
vn_replace_VkImageMemoryBarrier_handle_self(VkImageMemoryBarrier *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->srcAccessMask */
    /* skip val->dstAccessMask */
    /* skip val->oldLayout */
    /* skip val->newLayout */
    /* skip val->srcQueueFamilyIndex */
    /* skip val->dstQueueFamilyIndex */
    vn_replace_VkImage_handle(&val->image);
    vn_replace_VkImageSubresourceRange_handle(&val->subresourceRange);
}

static inline void
vn_replace_VkImageMemoryBarrier_handle(VkImageMemoryBarrier *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER:
            vn_replace_VkImageMemoryBarrier_handle_self((VkImageMemoryBarrier *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkExternalMemoryImageCreateInfo chain */

static inline void *
vn_decode_VkExternalMemoryImageCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExternalMemoryImageCreateInfo_self_temp(struct vn_cs *cs, VkExternalMemoryImageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->handleTypes);
}

static inline void
vn_decode_VkExternalMemoryImageCreateInfo_temp(struct vn_cs *cs, VkExternalMemoryImageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalMemoryImageCreateInfo_pnext_temp(cs);
    vn_decode_VkExternalMemoryImageCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkExternalMemoryImageCreateInfo_handle_self(VkExternalMemoryImageCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleTypes */
}

static inline void
vn_replace_VkExternalMemoryImageCreateInfo_handle(VkExternalMemoryImageCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            vn_replace_VkExternalMemoryImageCreateInfo_handle_self((VkExternalMemoryImageCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageFormatListCreateInfo chain */

static inline void *
vn_decode_VkImageFormatListCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageFormatListCreateInfo_self_temp(struct vn_cs *cs, VkImageFormatListCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->viewFormatCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->viewFormatCount);
        val->pViewFormats = vn_cs_alloc_temp(cs, sizeof(*val->pViewFormats) * array_size);
        if (!val->pViewFormats) return;
        vn_decode_VkFormat_array(cs, (VkFormat *)val->pViewFormats, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pViewFormats = NULL;
    }
}

static inline void
vn_decode_VkImageFormatListCreateInfo_temp(struct vn_cs *cs, VkImageFormatListCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageFormatListCreateInfo_pnext_temp(cs);
    vn_decode_VkImageFormatListCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkImageFormatListCreateInfo_handle_self(VkImageFormatListCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->viewFormatCount */
    /* skip val->pViewFormats */
}

static inline void
vn_replace_VkImageFormatListCreateInfo_handle(VkImageFormatListCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            vn_replace_VkImageFormatListCreateInfo_handle_self((VkImageFormatListCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageDrmFormatModifierListCreateInfoEXT chain */

static inline void *
vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_self_temp(struct vn_cs *cs, VkImageDrmFormatModifierListCreateInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->drmFormatModifierCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->drmFormatModifierCount);
        val->pDrmFormatModifiers = vn_cs_alloc_temp(cs, sizeof(*val->pDrmFormatModifiers) * array_size);
        if (!val->pDrmFormatModifiers) return;
        vn_decode_uint64_t_array(cs, (uint64_t *)val->pDrmFormatModifiers, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDrmFormatModifiers = NULL;
    }
}

static inline void
vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_temp(struct vn_cs *cs, VkImageDrmFormatModifierListCreateInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_pnext_temp(cs);
    vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_self_temp(cs, val);
}

static inline void
vn_replace_VkImageDrmFormatModifierListCreateInfoEXT_handle_self(VkImageDrmFormatModifierListCreateInfoEXT *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->drmFormatModifierCount */
    /* skip val->pDrmFormatModifiers */
}

static inline void
vn_replace_VkImageDrmFormatModifierListCreateInfoEXT_handle(VkImageDrmFormatModifierListCreateInfoEXT *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            vn_replace_VkImageDrmFormatModifierListCreateInfoEXT_handle_self((VkImageDrmFormatModifierListCreateInfoEXT *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSubresourceLayout */

static inline void
vn_encode_VkSubresourceLayout(struct vn_cs *cs, const VkSubresourceLayout *val)
{
    vn_encode_VkDeviceSize(cs, &val->offset);
    vn_encode_VkDeviceSize(cs, &val->size);
    vn_encode_VkDeviceSize(cs, &val->rowPitch);
    vn_encode_VkDeviceSize(cs, &val->arrayPitch);
    vn_encode_VkDeviceSize(cs, &val->depthPitch);
}

static inline void
vn_decode_VkSubresourceLayout_temp(struct vn_cs *cs, VkSubresourceLayout *val)
{
    vn_decode_VkDeviceSize(cs, &val->offset);
    vn_decode_VkDeviceSize(cs, &val->size);
    vn_decode_VkDeviceSize(cs, &val->rowPitch);
    vn_decode_VkDeviceSize(cs, &val->arrayPitch);
    vn_decode_VkDeviceSize(cs, &val->depthPitch);
}

static inline void
vn_decode_VkSubresourceLayout_partial_temp(struct vn_cs *cs, VkSubresourceLayout *val)
{
    /* skip val->offset */
    /* skip val->size */
    /* skip val->rowPitch */
    /* skip val->arrayPitch */
    /* skip val->depthPitch */
}

static inline void
vn_replace_VkSubresourceLayout_handle(VkSubresourceLayout *val)
{
    /* skip val->offset */
    /* skip val->size */
    /* skip val->rowPitch */
    /* skip val->arrayPitch */
    /* skip val->depthPitch */
}

/* struct VkImageDrmFormatModifierExplicitCreateInfoEXT chain */

static inline void *
vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_self_temp(struct vn_cs *cs, VkImageDrmFormatModifierExplicitCreateInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(cs, &val->drmFormatModifier);
    vn_decode_uint32_t(cs, &val->drmFormatModifierPlaneCount);
    if (vn_peek_array_size(cs)) {
        val->pPlaneLayouts = vn_cs_alloc_temp(cs, sizeof(*val->pPlaneLayouts) * val->drmFormatModifierPlaneCount);
        if (!val->pPlaneLayouts) return;
        vn_decode_array_size(cs, val->drmFormatModifierPlaneCount);
        for (uint32_t i = 0; i < val->drmFormatModifierPlaneCount; i++)
            vn_decode_VkSubresourceLayout_temp(cs, &((VkSubresourceLayout *)val->pPlaneLayouts)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pPlaneLayouts = NULL;
    }
}

static inline void
vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_temp(struct vn_cs *cs, VkImageDrmFormatModifierExplicitCreateInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_pnext_temp(cs);
    vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_self_temp(cs, val);
}

static inline void
vn_replace_VkImageDrmFormatModifierExplicitCreateInfoEXT_handle_self(VkImageDrmFormatModifierExplicitCreateInfoEXT *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->drmFormatModifier */
    /* skip val->drmFormatModifierPlaneCount */
    if (val->pPlaneLayouts) {
       for (uint32_t i = 0; i < val->drmFormatModifierPlaneCount; i++)
            vn_replace_VkSubresourceLayout_handle(&((VkSubresourceLayout *)val->pPlaneLayouts)[i]);
    }
}

static inline void
vn_replace_VkImageDrmFormatModifierExplicitCreateInfoEXT_handle(VkImageDrmFormatModifierExplicitCreateInfoEXT *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            vn_replace_VkImageDrmFormatModifierExplicitCreateInfoEXT_handle_self((VkImageDrmFormatModifierExplicitCreateInfoEXT *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageStencilUsageCreateInfo chain */

static inline void *
vn_decode_VkImageStencilUsageCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageStencilUsageCreateInfo_self_temp(struct vn_cs *cs, VkImageStencilUsageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->stencilUsage);
}

static inline void
vn_decode_VkImageStencilUsageCreateInfo_temp(struct vn_cs *cs, VkImageStencilUsageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageStencilUsageCreateInfo_pnext_temp(cs);
    vn_decode_VkImageStencilUsageCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkImageStencilUsageCreateInfo_handle_self(VkImageStencilUsageCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->stencilUsage */
}

static inline void
vn_replace_VkImageStencilUsageCreateInfo_handle(VkImageStencilUsageCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            vn_replace_VkImageStencilUsageCreateInfo_handle_self((VkImageStencilUsageCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageCreateInfo chain */

static inline void *
vn_decode_VkImageCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkExternalMemoryImageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(cs);
            vn_decode_VkExternalMemoryImageCreateInfo_self_temp(cs, (VkExternalMemoryImageCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImageFormatListCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(cs);
            vn_decode_VkImageFormatListCreateInfo_self_temp(cs, (VkImageFormatListCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImageDrmFormatModifierListCreateInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(cs);
            vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_self_temp(cs, (VkImageDrmFormatModifierListCreateInfoEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImageDrmFormatModifierExplicitCreateInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(cs);
            vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_self_temp(cs, (VkImageDrmFormatModifierExplicitCreateInfoEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImageStencilUsageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(cs);
            vn_decode_VkImageStencilUsageCreateInfo_self_temp(cs, (VkImageStencilUsageCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageCreateInfo_self_temp(struct vn_cs *cs, VkImageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkImageType(cs, &val->imageType);
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkExtent3D_temp(cs, &val->extent);
    vn_decode_uint32_t(cs, &val->mipLevels);
    vn_decode_uint32_t(cs, &val->arrayLayers);
    vn_decode_VkSampleCountFlagBits(cs, &val->samples);
    vn_decode_VkImageTiling(cs, &val->tiling);
    vn_decode_VkFlags(cs, &val->usage);
    vn_decode_VkSharingMode(cs, &val->sharingMode);
    vn_decode_uint32_t(cs, &val->queueFamilyIndexCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->queueFamilyIndexCount);
        val->pQueueFamilyIndices = vn_cs_alloc_temp(cs, sizeof(*val->pQueueFamilyIndices) * array_size);
        if (!val->pQueueFamilyIndices) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pQueueFamilyIndices, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pQueueFamilyIndices = NULL;
    }
    vn_decode_VkImageLayout(cs, &val->initialLayout);
}

static inline void
vn_decode_VkImageCreateInfo_temp(struct vn_cs *cs, VkImageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageCreateInfo_pnext_temp(cs);
    vn_decode_VkImageCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkImageCreateInfo_handle_self(VkImageCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->imageType */
    /* skip val->format */
    vn_replace_VkExtent3D_handle(&val->extent);
    /* skip val->mipLevels */
    /* skip val->arrayLayers */
    /* skip val->samples */
    /* skip val->tiling */
    /* skip val->usage */
    /* skip val->sharingMode */
    /* skip val->queueFamilyIndexCount */
    /* skip val->pQueueFamilyIndices */
    /* skip val->initialLayout */
}

static inline void
vn_replace_VkImageCreateInfo_handle(VkImageCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO:
            vn_replace_VkImageCreateInfo_handle_self((VkImageCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            vn_replace_VkExternalMemoryImageCreateInfo_handle_self((VkExternalMemoryImageCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            vn_replace_VkImageFormatListCreateInfo_handle_self((VkImageFormatListCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            vn_replace_VkImageDrmFormatModifierListCreateInfoEXT_handle_self((VkImageDrmFormatModifierListCreateInfoEXT *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            vn_replace_VkImageDrmFormatModifierExplicitCreateInfoEXT_handle_self((VkImageDrmFormatModifierExplicitCreateInfoEXT *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            vn_replace_VkImageStencilUsageCreateInfo_handle_self((VkImageStencilUsageCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageViewUsageCreateInfo chain */

static inline void *
vn_decode_VkImageViewUsageCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageViewUsageCreateInfo_self_temp(struct vn_cs *cs, VkImageViewUsageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->usage);
}

static inline void
vn_decode_VkImageViewUsageCreateInfo_temp(struct vn_cs *cs, VkImageViewUsageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageViewUsageCreateInfo_pnext_temp(cs);
    vn_decode_VkImageViewUsageCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkImageViewUsageCreateInfo_handle_self(VkImageViewUsageCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->usage */
}

static inline void
vn_replace_VkImageViewUsageCreateInfo_handle(VkImageViewUsageCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            vn_replace_VkImageViewUsageCreateInfo_handle_self((VkImageViewUsageCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSamplerYcbcrConversionInfo chain */

static inline void *
vn_decode_VkSamplerYcbcrConversionInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSamplerYcbcrConversionInfo_self_temp(struct vn_cs *cs, VkSamplerYcbcrConversionInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSamplerYcbcrConversion_lookup(cs, &val->conversion);
}

static inline void
vn_decode_VkSamplerYcbcrConversionInfo_temp(struct vn_cs *cs, VkSamplerYcbcrConversionInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerYcbcrConversionInfo_pnext_temp(cs);
    vn_decode_VkSamplerYcbcrConversionInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSamplerYcbcrConversionInfo_handle_self(VkSamplerYcbcrConversionInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkSamplerYcbcrConversion_handle(&val->conversion);
}

static inline void
vn_replace_VkSamplerYcbcrConversionInfo_handle(VkSamplerYcbcrConversionInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            vn_replace_VkSamplerYcbcrConversionInfo_handle_self((VkSamplerYcbcrConversionInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageViewCreateInfo chain */

static inline void *
vn_decode_VkImageViewCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImageViewUsageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageViewCreateInfo_pnext_temp(cs);
            vn_decode_VkImageViewUsageCreateInfo_self_temp(cs, (VkImageViewUsageCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkSamplerYcbcrConversionInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageViewCreateInfo_pnext_temp(cs);
            vn_decode_VkSamplerYcbcrConversionInfo_self_temp(cs, (VkSamplerYcbcrConversionInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageViewCreateInfo_self_temp(struct vn_cs *cs, VkImageViewCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkImage_lookup(cs, &val->image);
    vn_decode_VkImageViewType(cs, &val->viewType);
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkComponentMapping_temp(cs, &val->components);
    vn_decode_VkImageSubresourceRange_temp(cs, &val->subresourceRange);
}

static inline void
vn_decode_VkImageViewCreateInfo_temp(struct vn_cs *cs, VkImageViewCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageViewCreateInfo_pnext_temp(cs);
    vn_decode_VkImageViewCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkImageViewCreateInfo_handle_self(VkImageViewCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    vn_replace_VkImage_handle(&val->image);
    /* skip val->viewType */
    /* skip val->format */
    vn_replace_VkComponentMapping_handle(&val->components);
    vn_replace_VkImageSubresourceRange_handle(&val->subresourceRange);
}

static inline void
vn_replace_VkImageViewCreateInfo_handle(VkImageViewCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO:
            vn_replace_VkImageViewCreateInfo_handle_self((VkImageViewCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            vn_replace_VkImageViewUsageCreateInfo_handle_self((VkImageViewUsageCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            vn_replace_VkSamplerYcbcrConversionInfo_handle_self((VkSamplerYcbcrConversionInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBufferCopy */

static inline void
vn_decode_VkBufferCopy_temp(struct vn_cs *cs, VkBufferCopy *val)
{
    vn_decode_VkDeviceSize(cs, &val->srcOffset);
    vn_decode_VkDeviceSize(cs, &val->dstOffset);
    vn_decode_VkDeviceSize(cs, &val->size);
}

static inline void
vn_replace_VkBufferCopy_handle(VkBufferCopy *val)
{
    /* skip val->srcOffset */
    /* skip val->dstOffset */
    /* skip val->size */
}

/* struct VkSparseMemoryBind */

static inline void
vn_decode_VkSparseMemoryBind_temp(struct vn_cs *cs, VkSparseMemoryBind *val)
{
    vn_decode_VkDeviceSize(cs, &val->resourceOffset);
    vn_decode_VkDeviceSize(cs, &val->size);
    vn_decode_VkDeviceMemory_lookup(cs, &val->memory);
    vn_decode_VkDeviceSize(cs, &val->memoryOffset);
    vn_decode_VkFlags(cs, &val->flags);
}

static inline void
vn_replace_VkSparseMemoryBind_handle(VkSparseMemoryBind *val)
{
    /* skip val->resourceOffset */
    /* skip val->size */
    vn_replace_VkDeviceMemory_handle(&val->memory);
    /* skip val->memoryOffset */
    /* skip val->flags */
}

/* struct VkSparseImageMemoryBind */

static inline void
vn_decode_VkSparseImageMemoryBind_temp(struct vn_cs *cs, VkSparseImageMemoryBind *val)
{
    vn_decode_VkImageSubresource_temp(cs, &val->subresource);
    vn_decode_VkOffset3D_temp(cs, &val->offset);
    vn_decode_VkExtent3D_temp(cs, &val->extent);
    vn_decode_VkDeviceMemory_lookup(cs, &val->memory);
    vn_decode_VkDeviceSize(cs, &val->memoryOffset);
    vn_decode_VkFlags(cs, &val->flags);
}

static inline void
vn_replace_VkSparseImageMemoryBind_handle(VkSparseImageMemoryBind *val)
{
    vn_replace_VkImageSubresource_handle(&val->subresource);
    vn_replace_VkOffset3D_handle(&val->offset);
    vn_replace_VkExtent3D_handle(&val->extent);
    vn_replace_VkDeviceMemory_handle(&val->memory);
    /* skip val->memoryOffset */
    /* skip val->flags */
}

/* struct VkSparseBufferMemoryBindInfo */

static inline void
vn_decode_VkSparseBufferMemoryBindInfo_temp(struct vn_cs *cs, VkSparseBufferMemoryBindInfo *val)
{
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
    vn_decode_uint32_t(cs, &val->bindCount);
    if (vn_peek_array_size(cs)) {
        val->pBinds = vn_cs_alloc_temp(cs, sizeof(*val->pBinds) * val->bindCount);
        if (!val->pBinds) return;
        vn_decode_array_size(cs, val->bindCount);
        for (uint32_t i = 0; i < val->bindCount; i++)
            vn_decode_VkSparseMemoryBind_temp(cs, &((VkSparseMemoryBind *)val->pBinds)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pBinds = NULL;
    }
}

static inline void
vn_replace_VkSparseBufferMemoryBindInfo_handle(VkSparseBufferMemoryBindInfo *val)
{
    vn_replace_VkBuffer_handle(&val->buffer);
    /* skip val->bindCount */
    if (val->pBinds) {
       for (uint32_t i = 0; i < val->bindCount; i++)
            vn_replace_VkSparseMemoryBind_handle(&((VkSparseMemoryBind *)val->pBinds)[i]);
    }
}

/* struct VkSparseImageOpaqueMemoryBindInfo */

static inline void
vn_decode_VkSparseImageOpaqueMemoryBindInfo_temp(struct vn_cs *cs, VkSparseImageOpaqueMemoryBindInfo *val)
{
    vn_decode_VkImage_lookup(cs, &val->image);
    vn_decode_uint32_t(cs, &val->bindCount);
    if (vn_peek_array_size(cs)) {
        val->pBinds = vn_cs_alloc_temp(cs, sizeof(*val->pBinds) * val->bindCount);
        if (!val->pBinds) return;
        vn_decode_array_size(cs, val->bindCount);
        for (uint32_t i = 0; i < val->bindCount; i++)
            vn_decode_VkSparseMemoryBind_temp(cs, &((VkSparseMemoryBind *)val->pBinds)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pBinds = NULL;
    }
}

static inline void
vn_replace_VkSparseImageOpaqueMemoryBindInfo_handle(VkSparseImageOpaqueMemoryBindInfo *val)
{
    vn_replace_VkImage_handle(&val->image);
    /* skip val->bindCount */
    if (val->pBinds) {
       for (uint32_t i = 0; i < val->bindCount; i++)
            vn_replace_VkSparseMemoryBind_handle(&((VkSparseMemoryBind *)val->pBinds)[i]);
    }
}

/* struct VkSparseImageMemoryBindInfo */

static inline void
vn_decode_VkSparseImageMemoryBindInfo_temp(struct vn_cs *cs, VkSparseImageMemoryBindInfo *val)
{
    vn_decode_VkImage_lookup(cs, &val->image);
    vn_decode_uint32_t(cs, &val->bindCount);
    if (vn_peek_array_size(cs)) {
        val->pBinds = vn_cs_alloc_temp(cs, sizeof(*val->pBinds) * val->bindCount);
        if (!val->pBinds) return;
        vn_decode_array_size(cs, val->bindCount);
        for (uint32_t i = 0; i < val->bindCount; i++)
            vn_decode_VkSparseImageMemoryBind_temp(cs, &((VkSparseImageMemoryBind *)val->pBinds)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pBinds = NULL;
    }
}

static inline void
vn_replace_VkSparseImageMemoryBindInfo_handle(VkSparseImageMemoryBindInfo *val)
{
    vn_replace_VkImage_handle(&val->image);
    /* skip val->bindCount */
    if (val->pBinds) {
       for (uint32_t i = 0; i < val->bindCount; i++)
            vn_replace_VkSparseImageMemoryBind_handle(&((VkSparseImageMemoryBind *)val->pBinds)[i]);
    }
}

/* struct VkDeviceGroupBindSparseInfo chain */

static inline void *
vn_decode_VkDeviceGroupBindSparseInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupBindSparseInfo_self_temp(struct vn_cs *cs, VkDeviceGroupBindSparseInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->resourceDeviceIndex);
    vn_decode_uint32_t(cs, &val->memoryDeviceIndex);
}

static inline void
vn_decode_VkDeviceGroupBindSparseInfo_temp(struct vn_cs *cs, VkDeviceGroupBindSparseInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupBindSparseInfo_pnext_temp(cs);
    vn_decode_VkDeviceGroupBindSparseInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceGroupBindSparseInfo_handle_self(VkDeviceGroupBindSparseInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->resourceDeviceIndex */
    /* skip val->memoryDeviceIndex */
}

static inline void
vn_replace_VkDeviceGroupBindSparseInfo_handle(VkDeviceGroupBindSparseInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            vn_replace_VkDeviceGroupBindSparseInfo_handle_self((VkDeviceGroupBindSparseInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkTimelineSemaphoreSubmitInfo chain */

static inline void *
vn_decode_VkTimelineSemaphoreSubmitInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(struct vn_cs *cs, VkTimelineSemaphoreSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->waitSemaphoreValueCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->waitSemaphoreValueCount);
        val->pWaitSemaphoreValues = vn_cs_alloc_temp(cs, sizeof(*val->pWaitSemaphoreValues) * array_size);
        if (!val->pWaitSemaphoreValues) return;
        vn_decode_uint64_t_array(cs, (uint64_t *)val->pWaitSemaphoreValues, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pWaitSemaphoreValues = NULL;
    }
    vn_decode_uint32_t(cs, &val->signalSemaphoreValueCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->signalSemaphoreValueCount);
        val->pSignalSemaphoreValues = vn_cs_alloc_temp(cs, sizeof(*val->pSignalSemaphoreValues) * array_size);
        if (!val->pSignalSemaphoreValues) return;
        vn_decode_uint64_t_array(cs, (uint64_t *)val->pSignalSemaphoreValues, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSignalSemaphoreValues = NULL;
    }
}

static inline void
vn_decode_VkTimelineSemaphoreSubmitInfo_temp(struct vn_cs *cs, VkTimelineSemaphoreSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkTimelineSemaphoreSubmitInfo_pnext_temp(cs);
    vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkTimelineSemaphoreSubmitInfo_handle_self(VkTimelineSemaphoreSubmitInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->waitSemaphoreValueCount */
    /* skip val->pWaitSemaphoreValues */
    /* skip val->signalSemaphoreValueCount */
    /* skip val->pSignalSemaphoreValues */
}

static inline void
vn_replace_VkTimelineSemaphoreSubmitInfo_handle(VkTimelineSemaphoreSubmitInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            vn_replace_VkTimelineSemaphoreSubmitInfo_handle_self((VkTimelineSemaphoreSubmitInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBindSparseInfo chain */

static inline void *
vn_decode_VkBindSparseInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDeviceGroupBindSparseInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindSparseInfo_pnext_temp(cs);
            vn_decode_VkDeviceGroupBindSparseInfo_self_temp(cs, (VkDeviceGroupBindSparseInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkTimelineSemaphoreSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindSparseInfo_pnext_temp(cs);
            vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(cs, (VkTimelineSemaphoreSubmitInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBindSparseInfo_self_temp(struct vn_cs *cs, VkBindSparseInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->waitSemaphoreCount);
    if (vn_peek_array_size(cs)) {
        val->pWaitSemaphores = vn_cs_alloc_temp(cs, sizeof(*val->pWaitSemaphores) * val->waitSemaphoreCount);
        if (!val->pWaitSemaphores) return;
        vn_decode_array_size(cs, val->waitSemaphoreCount);
        for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(cs, &((VkSemaphore *)val->pWaitSemaphores)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pWaitSemaphores = NULL;
    }
    vn_decode_uint32_t(cs, &val->bufferBindCount);
    if (vn_peek_array_size(cs)) {
        val->pBufferBinds = vn_cs_alloc_temp(cs, sizeof(*val->pBufferBinds) * val->bufferBindCount);
        if (!val->pBufferBinds) return;
        vn_decode_array_size(cs, val->bufferBindCount);
        for (uint32_t i = 0; i < val->bufferBindCount; i++)
            vn_decode_VkSparseBufferMemoryBindInfo_temp(cs, &((VkSparseBufferMemoryBindInfo *)val->pBufferBinds)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pBufferBinds = NULL;
    }
    vn_decode_uint32_t(cs, &val->imageOpaqueBindCount);
    if (vn_peek_array_size(cs)) {
        val->pImageOpaqueBinds = vn_cs_alloc_temp(cs, sizeof(*val->pImageOpaqueBinds) * val->imageOpaqueBindCount);
        if (!val->pImageOpaqueBinds) return;
        vn_decode_array_size(cs, val->imageOpaqueBindCount);
        for (uint32_t i = 0; i < val->imageOpaqueBindCount; i++)
            vn_decode_VkSparseImageOpaqueMemoryBindInfo_temp(cs, &((VkSparseImageOpaqueMemoryBindInfo *)val->pImageOpaqueBinds)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pImageOpaqueBinds = NULL;
    }
    vn_decode_uint32_t(cs, &val->imageBindCount);
    if (vn_peek_array_size(cs)) {
        val->pImageBinds = vn_cs_alloc_temp(cs, sizeof(*val->pImageBinds) * val->imageBindCount);
        if (!val->pImageBinds) return;
        vn_decode_array_size(cs, val->imageBindCount);
        for (uint32_t i = 0; i < val->imageBindCount; i++)
            vn_decode_VkSparseImageMemoryBindInfo_temp(cs, &((VkSparseImageMemoryBindInfo *)val->pImageBinds)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pImageBinds = NULL;
    }
    vn_decode_uint32_t(cs, &val->signalSemaphoreCount);
    if (vn_peek_array_size(cs)) {
        val->pSignalSemaphores = vn_cs_alloc_temp(cs, sizeof(*val->pSignalSemaphores) * val->signalSemaphoreCount);
        if (!val->pSignalSemaphores) return;
        vn_decode_array_size(cs, val->signalSemaphoreCount);
        for (uint32_t i = 0; i < val->signalSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(cs, &((VkSemaphore *)val->pSignalSemaphores)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSignalSemaphores = NULL;
    }
}

static inline void
vn_decode_VkBindSparseInfo_temp(struct vn_cs *cs, VkBindSparseInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_SPARSE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindSparseInfo_pnext_temp(cs);
    vn_decode_VkBindSparseInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBindSparseInfo_handle_self(VkBindSparseInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->waitSemaphoreCount */
    if (val->pWaitSemaphores) {
       for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_replace_VkSemaphore_handle(&((VkSemaphore *)val->pWaitSemaphores)[i]);
    }
    /* skip val->bufferBindCount */
    if (val->pBufferBinds) {
       for (uint32_t i = 0; i < val->bufferBindCount; i++)
            vn_replace_VkSparseBufferMemoryBindInfo_handle(&((VkSparseBufferMemoryBindInfo *)val->pBufferBinds)[i]);
    }
    /* skip val->imageOpaqueBindCount */
    if (val->pImageOpaqueBinds) {
       for (uint32_t i = 0; i < val->imageOpaqueBindCount; i++)
            vn_replace_VkSparseImageOpaqueMemoryBindInfo_handle(&((VkSparseImageOpaqueMemoryBindInfo *)val->pImageOpaqueBinds)[i]);
    }
    /* skip val->imageBindCount */
    if (val->pImageBinds) {
       for (uint32_t i = 0; i < val->imageBindCount; i++)
            vn_replace_VkSparseImageMemoryBindInfo_handle(&((VkSparseImageMemoryBindInfo *)val->pImageBinds)[i]);
    }
    /* skip val->signalSemaphoreCount */
    if (val->pSignalSemaphores) {
       for (uint32_t i = 0; i < val->signalSemaphoreCount; i++)
            vn_replace_VkSemaphore_handle(&((VkSemaphore *)val->pSignalSemaphores)[i]);
    }
}

static inline void
vn_replace_VkBindSparseInfo_handle(VkBindSparseInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_SPARSE_INFO:
            vn_replace_VkBindSparseInfo_handle_self((VkBindSparseInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            vn_replace_VkDeviceGroupBindSparseInfo_handle_self((VkDeviceGroupBindSparseInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            vn_replace_VkTimelineSemaphoreSubmitInfo_handle_self((VkTimelineSemaphoreSubmitInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageCopy */

static inline void
vn_decode_VkImageCopy_temp(struct vn_cs *cs, VkImageCopy *val)
{
    vn_decode_VkImageSubresourceLayers_temp(cs, &val->srcSubresource);
    vn_decode_VkOffset3D_temp(cs, &val->srcOffset);
    vn_decode_VkImageSubresourceLayers_temp(cs, &val->dstSubresource);
    vn_decode_VkOffset3D_temp(cs, &val->dstOffset);
    vn_decode_VkExtent3D_temp(cs, &val->extent);
}

static inline void
vn_replace_VkImageCopy_handle(VkImageCopy *val)
{
    vn_replace_VkImageSubresourceLayers_handle(&val->srcSubresource);
    vn_replace_VkOffset3D_handle(&val->srcOffset);
    vn_replace_VkImageSubresourceLayers_handle(&val->dstSubresource);
    vn_replace_VkOffset3D_handle(&val->dstOffset);
    vn_replace_VkExtent3D_handle(&val->extent);
}

/* struct VkImageBlit */

static inline void
vn_decode_VkImageBlit_temp(struct vn_cs *cs, VkImageBlit *val)
{
    vn_decode_VkImageSubresourceLayers_temp(cs, &val->srcSubresource);
    {
        vn_decode_array_size(cs, 2);
        for (uint32_t i = 0; i < 2; i++)
            vn_decode_VkOffset3D_temp(cs, &val->srcOffsets[i]);
    }
    vn_decode_VkImageSubresourceLayers_temp(cs, &val->dstSubresource);
    {
        vn_decode_array_size(cs, 2);
        for (uint32_t i = 0; i < 2; i++)
            vn_decode_VkOffset3D_temp(cs, &val->dstOffsets[i]);
    }
}

static inline void
vn_replace_VkImageBlit_handle(VkImageBlit *val)
{
    vn_replace_VkImageSubresourceLayers_handle(&val->srcSubresource);
    for (uint32_t i = 0; i < 2; i++)
        vn_replace_VkOffset3D_handle(&val->srcOffsets[i]);
    vn_replace_VkImageSubresourceLayers_handle(&val->dstSubresource);
    for (uint32_t i = 0; i < 2; i++)
        vn_replace_VkOffset3D_handle(&val->dstOffsets[i]);
}

/* struct VkBufferImageCopy */

static inline void
vn_decode_VkBufferImageCopy_temp(struct vn_cs *cs, VkBufferImageCopy *val)
{
    vn_decode_VkDeviceSize(cs, &val->bufferOffset);
    vn_decode_uint32_t(cs, &val->bufferRowLength);
    vn_decode_uint32_t(cs, &val->bufferImageHeight);
    vn_decode_VkImageSubresourceLayers_temp(cs, &val->imageSubresource);
    vn_decode_VkOffset3D_temp(cs, &val->imageOffset);
    vn_decode_VkExtent3D_temp(cs, &val->imageExtent);
}

static inline void
vn_replace_VkBufferImageCopy_handle(VkBufferImageCopy *val)
{
    /* skip val->bufferOffset */
    /* skip val->bufferRowLength */
    /* skip val->bufferImageHeight */
    vn_replace_VkImageSubresourceLayers_handle(&val->imageSubresource);
    vn_replace_VkOffset3D_handle(&val->imageOffset);
    vn_replace_VkExtent3D_handle(&val->imageExtent);
}

/* struct VkImageResolve */

static inline void
vn_decode_VkImageResolve_temp(struct vn_cs *cs, VkImageResolve *val)
{
    vn_decode_VkImageSubresourceLayers_temp(cs, &val->srcSubresource);
    vn_decode_VkOffset3D_temp(cs, &val->srcOffset);
    vn_decode_VkImageSubresourceLayers_temp(cs, &val->dstSubresource);
    vn_decode_VkOffset3D_temp(cs, &val->dstOffset);
    vn_decode_VkExtent3D_temp(cs, &val->extent);
}

static inline void
vn_replace_VkImageResolve_handle(VkImageResolve *val)
{
    vn_replace_VkImageSubresourceLayers_handle(&val->srcSubresource);
    vn_replace_VkOffset3D_handle(&val->srcOffset);
    vn_replace_VkImageSubresourceLayers_handle(&val->dstSubresource);
    vn_replace_VkOffset3D_handle(&val->dstOffset);
    vn_replace_VkExtent3D_handle(&val->extent);
}

/* struct VkShaderModuleCreateInfo chain */

static inline void *
vn_decode_VkShaderModuleCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkShaderModuleCreateInfo_self_temp(struct vn_cs *cs, VkShaderModuleCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_size_t(cs, &val->codeSize);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->codeSize / 4);
        val->pCode = vn_cs_alloc_temp(cs, sizeof(*val->pCode) * array_size);
        if (!val->pCode) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pCode, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pCode = NULL;
    }
}

static inline void
vn_decode_VkShaderModuleCreateInfo_temp(struct vn_cs *cs, VkShaderModuleCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkShaderModuleCreateInfo_pnext_temp(cs);
    vn_decode_VkShaderModuleCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkShaderModuleCreateInfo_handle_self(VkShaderModuleCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->codeSize */
    /* skip val->pCode */
}

static inline void
vn_replace_VkShaderModuleCreateInfo_handle(VkShaderModuleCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO:
            vn_replace_VkShaderModuleCreateInfo_handle_self((VkShaderModuleCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorSetLayoutBinding */

static inline void
vn_decode_VkDescriptorSetLayoutBinding_temp(struct vn_cs *cs, VkDescriptorSetLayoutBinding *val)
{
    vn_decode_uint32_t(cs, &val->binding);
    vn_decode_VkDescriptorType(cs, &val->descriptorType);
    vn_decode_uint32_t(cs, &val->descriptorCount);
    vn_decode_VkFlags(cs, &val->stageFlags);
    if (vn_peek_array_size(cs)) {
        val->pImmutableSamplers = vn_cs_alloc_temp(cs, sizeof(*val->pImmutableSamplers) * val->descriptorCount);
        if (!val->pImmutableSamplers) return;
        vn_decode_array_size(cs, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkSampler_lookup(cs, &((VkSampler *)val->pImmutableSamplers)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pImmutableSamplers = NULL;
    }
}

static inline void
vn_replace_VkDescriptorSetLayoutBinding_handle(VkDescriptorSetLayoutBinding *val)
{
    /* skip val->binding */
    /* skip val->descriptorType */
    /* skip val->descriptorCount */
    /* skip val->stageFlags */
    if (val->pImmutableSamplers) {
       for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_replace_VkSampler_handle(&((VkSampler *)val->pImmutableSamplers)[i]);
    }
}

/* struct VkDescriptorSetLayoutBindingFlagsCreateInfo chain */

static inline void *
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(struct vn_cs *cs, VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->bindingCount);
    if (vn_peek_array_size(cs)) {
        val->pBindingFlags = vn_cs_alloc_temp(cs, sizeof(*val->pBindingFlags) * val->bindingCount);
        if (!val->pBindingFlags) return;
        vn_decode_array_size(cs, val->bindingCount);
        for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_decode_VkFlags(cs, &((VkDescriptorBindingFlags *)val->pBindingFlags)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pBindingFlags = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_temp(struct vn_cs *cs, VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_pnext_temp(cs);
    vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle_self(VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->bindingCount */
    /* skip val->pBindingFlags */
}

static inline void
vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle(VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle_self((VkDescriptorSetLayoutBindingFlagsCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorSetLayoutCreateInfo chain */

static inline void *
vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDescriptorSetLayoutBindingFlagsCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(cs);
            vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(cs, (VkDescriptorSetLayoutBindingFlagsCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDescriptorSetLayoutCreateInfo_self_temp(struct vn_cs *cs, VkDescriptorSetLayoutCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->bindingCount);
    if (vn_peek_array_size(cs)) {
        val->pBindings = vn_cs_alloc_temp(cs, sizeof(*val->pBindings) * val->bindingCount);
        if (!val->pBindings) return;
        vn_decode_array_size(cs, val->bindingCount);
        for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_decode_VkDescriptorSetLayoutBinding_temp(cs, &((VkDescriptorSetLayoutBinding *)val->pBindings)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pBindings = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetLayoutCreateInfo_temp(struct vn_cs *cs, VkDescriptorSetLayoutCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(cs);
    vn_decode_VkDescriptorSetLayoutCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDescriptorSetLayoutCreateInfo_handle_self(VkDescriptorSetLayoutCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->bindingCount */
    if (val->pBindings) {
       for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_replace_VkDescriptorSetLayoutBinding_handle(&((VkDescriptorSetLayoutBinding *)val->pBindings)[i]);
    }
}

static inline void
vn_replace_VkDescriptorSetLayoutCreateInfo_handle(VkDescriptorSetLayoutCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO:
            vn_replace_VkDescriptorSetLayoutCreateInfo_handle_self((VkDescriptorSetLayoutCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            vn_replace_VkDescriptorSetLayoutBindingFlagsCreateInfo_handle_self((VkDescriptorSetLayoutBindingFlagsCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorPoolSize */

static inline void
vn_decode_VkDescriptorPoolSize_temp(struct vn_cs *cs, VkDescriptorPoolSize *val)
{
    vn_decode_VkDescriptorType(cs, &val->type);
    vn_decode_uint32_t(cs, &val->descriptorCount);
}

static inline void
vn_replace_VkDescriptorPoolSize_handle(VkDescriptorPoolSize *val)
{
    /* skip val->type */
    /* skip val->descriptorCount */
}

/* struct VkDescriptorPoolCreateInfo chain */

static inline void *
vn_decode_VkDescriptorPoolCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDescriptorPoolCreateInfo_self_temp(struct vn_cs *cs, VkDescriptorPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->maxSets);
    vn_decode_uint32_t(cs, &val->poolSizeCount);
    if (vn_peek_array_size(cs)) {
        val->pPoolSizes = vn_cs_alloc_temp(cs, sizeof(*val->pPoolSizes) * val->poolSizeCount);
        if (!val->pPoolSizes) return;
        vn_decode_array_size(cs, val->poolSizeCount);
        for (uint32_t i = 0; i < val->poolSizeCount; i++)
            vn_decode_VkDescriptorPoolSize_temp(cs, &((VkDescriptorPoolSize *)val->pPoolSizes)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pPoolSizes = NULL;
    }
}

static inline void
vn_decode_VkDescriptorPoolCreateInfo_temp(struct vn_cs *cs, VkDescriptorPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorPoolCreateInfo_pnext_temp(cs);
    vn_decode_VkDescriptorPoolCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDescriptorPoolCreateInfo_handle_self(VkDescriptorPoolCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->maxSets */
    /* skip val->poolSizeCount */
    if (val->pPoolSizes) {
       for (uint32_t i = 0; i < val->poolSizeCount; i++)
            vn_replace_VkDescriptorPoolSize_handle(&((VkDescriptorPoolSize *)val->pPoolSizes)[i]);
    }
}

static inline void
vn_replace_VkDescriptorPoolCreateInfo_handle(VkDescriptorPoolCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO:
            vn_replace_VkDescriptorPoolCreateInfo_handle_self((VkDescriptorPoolCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorSetVariableDescriptorCountAllocateInfo chain */

static inline void *
vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_self_temp(struct vn_cs *cs, VkDescriptorSetVariableDescriptorCountAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->descriptorSetCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->descriptorSetCount);
        val->pDescriptorCounts = vn_cs_alloc_temp(cs, sizeof(*val->pDescriptorCounts) * array_size);
        if (!val->pDescriptorCounts) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pDescriptorCounts, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDescriptorCounts = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_temp(struct vn_cs *cs, VkDescriptorSetVariableDescriptorCountAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_pnext_temp(cs);
    vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDescriptorSetVariableDescriptorCountAllocateInfo_handle_self(VkDescriptorSetVariableDescriptorCountAllocateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->descriptorSetCount */
    /* skip val->pDescriptorCounts */
}

static inline void
vn_replace_VkDescriptorSetVariableDescriptorCountAllocateInfo_handle(VkDescriptorSetVariableDescriptorCountAllocateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            vn_replace_VkDescriptorSetVariableDescriptorCountAllocateInfo_handle_self((VkDescriptorSetVariableDescriptorCountAllocateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorSetAllocateInfo chain */

static inline void *
vn_decode_VkDescriptorSetAllocateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDescriptorSetVariableDescriptorCountAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetAllocateInfo_pnext_temp(cs);
            vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_self_temp(cs, (VkDescriptorSetVariableDescriptorCountAllocateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDescriptorSetAllocateInfo_self_temp(struct vn_cs *cs, VkDescriptorSetAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDescriptorPool_lookup(cs, &val->descriptorPool);
    vn_decode_uint32_t(cs, &val->descriptorSetCount);
    if (vn_peek_array_size(cs)) {
        val->pSetLayouts = vn_cs_alloc_temp(cs, sizeof(*val->pSetLayouts) * val->descriptorSetCount);
        if (!val->pSetLayouts) return;
        vn_decode_array_size(cs, val->descriptorSetCount);
        for (uint32_t i = 0; i < val->descriptorSetCount; i++)
            vn_decode_VkDescriptorSetLayout_lookup(cs, &((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSetLayouts = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetAllocateInfo_temp(struct vn_cs *cs, VkDescriptorSetAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetAllocateInfo_pnext_temp(cs);
    vn_decode_VkDescriptorSetAllocateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDescriptorSetAllocateInfo_handle_self(VkDescriptorSetAllocateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkDescriptorPool_handle(&val->descriptorPool);
    /* skip val->descriptorSetCount */
    if (val->pSetLayouts) {
       for (uint32_t i = 0; i < val->descriptorSetCount; i++)
            vn_replace_VkDescriptorSetLayout_handle(&((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    }
}

static inline void
vn_replace_VkDescriptorSetAllocateInfo_handle(VkDescriptorSetAllocateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO:
            vn_replace_VkDescriptorSetAllocateInfo_handle_self((VkDescriptorSetAllocateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            vn_replace_VkDescriptorSetVariableDescriptorCountAllocateInfo_handle_self((VkDescriptorSetVariableDescriptorCountAllocateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSpecializationMapEntry */

static inline void
vn_decode_VkSpecializationMapEntry_temp(struct vn_cs *cs, VkSpecializationMapEntry *val)
{
    vn_decode_uint32_t(cs, &val->constantID);
    vn_decode_uint32_t(cs, &val->offset);
    vn_decode_size_t(cs, &val->size);
}

static inline void
vn_replace_VkSpecializationMapEntry_handle(VkSpecializationMapEntry *val)
{
    /* skip val->constantID */
    /* skip val->offset */
    /* skip val->size */
}

/* struct VkSpecializationInfo */

static inline void
vn_decode_VkSpecializationInfo_temp(struct vn_cs *cs, VkSpecializationInfo *val)
{
    vn_decode_uint32_t(cs, &val->mapEntryCount);
    if (vn_peek_array_size(cs)) {
        val->pMapEntries = vn_cs_alloc_temp(cs, sizeof(*val->pMapEntries) * val->mapEntryCount);
        if (!val->pMapEntries) return;
        vn_decode_array_size(cs, val->mapEntryCount);
        for (uint32_t i = 0; i < val->mapEntryCount; i++)
            vn_decode_VkSpecializationMapEntry_temp(cs, &((VkSpecializationMapEntry *)val->pMapEntries)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pMapEntries = NULL;
    }
    vn_decode_size_t(cs, &val->dataSize);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->dataSize);
        val->pData = vn_cs_alloc_temp(cs, array_size);
        if (!val->pData) return;
        vn_decode_blob_array(cs, (void *)val->pData, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pData = NULL;
    }
}

static inline void
vn_replace_VkSpecializationInfo_handle(VkSpecializationInfo *val)
{
    /* skip val->mapEntryCount */
    if (val->pMapEntries) {
       for (uint32_t i = 0; i < val->mapEntryCount; i++)
            vn_replace_VkSpecializationMapEntry_handle(&((VkSpecializationMapEntry *)val->pMapEntries)[i]);
    }
    /* skip val->dataSize */
    /* skip val->pData */
}

/* struct VkPipelineShaderStageCreateInfo chain */

static inline void *
vn_decode_VkPipelineShaderStageCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineShaderStageCreateInfo_self_temp(struct vn_cs *cs, VkPipelineShaderStageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkShaderStageFlagBits(cs, &val->stage);
    vn_decode_VkShaderModule_lookup(cs, &val->module);
    if (vn_peek_array_size(cs)) {
        const size_t string_size = vn_decode_array_size(cs, UINT64_MAX);
        val->pName = vn_cs_alloc_temp(cs, sizeof(*val->pName) * string_size);
        if (!val->pName) return;
        vn_decode_blob_array(cs, (char *)val->pName, string_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pName = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pSpecializationInfo = vn_cs_alloc_temp(cs, sizeof(*val->pSpecializationInfo));
        if (!val->pSpecializationInfo) return;
        vn_decode_VkSpecializationInfo_temp(cs, (VkSpecializationInfo *)val->pSpecializationInfo);
    } else {
        val->pSpecializationInfo = NULL;
    }
}

static inline void
vn_decode_VkPipelineShaderStageCreateInfo_temp(struct vn_cs *cs, VkPipelineShaderStageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineShaderStageCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineShaderStageCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineShaderStageCreateInfo_handle_self(VkPipelineShaderStageCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->stage */
    vn_replace_VkShaderModule_handle(&val->module);
    /* skip val->pName */
    if (val->pSpecializationInfo)
        vn_replace_VkSpecializationInfo_handle((VkSpecializationInfo *)val->pSpecializationInfo);
}

static inline void
vn_replace_VkPipelineShaderStageCreateInfo_handle(VkPipelineShaderStageCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO:
            vn_replace_VkPipelineShaderStageCreateInfo_handle_self((VkPipelineShaderStageCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkComputePipelineCreateInfo chain */

static inline void *
vn_decode_VkComputePipelineCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkComputePipelineCreateInfo_self_temp(struct vn_cs *cs, VkComputePipelineCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkPipelineShaderStageCreateInfo_temp(cs, &val->stage);
    vn_decode_VkPipelineLayout_lookup(cs, &val->layout);
    vn_decode_VkPipeline_lookup(cs, &val->basePipelineHandle);
    vn_decode_int32_t(cs, &val->basePipelineIndex);
}

static inline void
vn_decode_VkComputePipelineCreateInfo_temp(struct vn_cs *cs, VkComputePipelineCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkComputePipelineCreateInfo_pnext_temp(cs);
    vn_decode_VkComputePipelineCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkComputePipelineCreateInfo_handle_self(VkComputePipelineCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    vn_replace_VkPipelineShaderStageCreateInfo_handle(&val->stage);
    vn_replace_VkPipelineLayout_handle(&val->layout);
    vn_replace_VkPipeline_handle(&val->basePipelineHandle);
    /* skip val->basePipelineIndex */
}

static inline void
vn_replace_VkComputePipelineCreateInfo_handle(VkComputePipelineCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO:
            vn_replace_VkComputePipelineCreateInfo_handle_self((VkComputePipelineCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkVertexInputBindingDescription */

static inline void
vn_decode_VkVertexInputBindingDescription_temp(struct vn_cs *cs, VkVertexInputBindingDescription *val)
{
    vn_decode_uint32_t(cs, &val->binding);
    vn_decode_uint32_t(cs, &val->stride);
    vn_decode_VkVertexInputRate(cs, &val->inputRate);
}

static inline void
vn_replace_VkVertexInputBindingDescription_handle(VkVertexInputBindingDescription *val)
{
    /* skip val->binding */
    /* skip val->stride */
    /* skip val->inputRate */
}

/* struct VkVertexInputAttributeDescription */

static inline void
vn_decode_VkVertexInputAttributeDescription_temp(struct vn_cs *cs, VkVertexInputAttributeDescription *val)
{
    vn_decode_uint32_t(cs, &val->location);
    vn_decode_uint32_t(cs, &val->binding);
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_uint32_t(cs, &val->offset);
}

static inline void
vn_replace_VkVertexInputAttributeDescription_handle(VkVertexInputAttributeDescription *val)
{
    /* skip val->location */
    /* skip val->binding */
    /* skip val->format */
    /* skip val->offset */
}

/* struct VkPipelineVertexInputStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineVertexInputStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineVertexInputStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineVertexInputStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->vertexBindingDescriptionCount);
    if (vn_peek_array_size(cs)) {
        val->pVertexBindingDescriptions = vn_cs_alloc_temp(cs, sizeof(*val->pVertexBindingDescriptions) * val->vertexBindingDescriptionCount);
        if (!val->pVertexBindingDescriptions) return;
        vn_decode_array_size(cs, val->vertexBindingDescriptionCount);
        for (uint32_t i = 0; i < val->vertexBindingDescriptionCount; i++)
            vn_decode_VkVertexInputBindingDescription_temp(cs, &((VkVertexInputBindingDescription *)val->pVertexBindingDescriptions)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pVertexBindingDescriptions = NULL;
    }
    vn_decode_uint32_t(cs, &val->vertexAttributeDescriptionCount);
    if (vn_peek_array_size(cs)) {
        val->pVertexAttributeDescriptions = vn_cs_alloc_temp(cs, sizeof(*val->pVertexAttributeDescriptions) * val->vertexAttributeDescriptionCount);
        if (!val->pVertexAttributeDescriptions) return;
        vn_decode_array_size(cs, val->vertexAttributeDescriptionCount);
        for (uint32_t i = 0; i < val->vertexAttributeDescriptionCount; i++)
            vn_decode_VkVertexInputAttributeDescription_temp(cs, &((VkVertexInputAttributeDescription *)val->pVertexAttributeDescriptions)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pVertexAttributeDescriptions = NULL;
    }
}

static inline void
vn_decode_VkPipelineVertexInputStateCreateInfo_temp(struct vn_cs *cs, VkPipelineVertexInputStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineVertexInputStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineVertexInputStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineVertexInputStateCreateInfo_handle_self(VkPipelineVertexInputStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->vertexBindingDescriptionCount */
    if (val->pVertexBindingDescriptions) {
       for (uint32_t i = 0; i < val->vertexBindingDescriptionCount; i++)
            vn_replace_VkVertexInputBindingDescription_handle(&((VkVertexInputBindingDescription *)val->pVertexBindingDescriptions)[i]);
    }
    /* skip val->vertexAttributeDescriptionCount */
    if (val->pVertexAttributeDescriptions) {
       for (uint32_t i = 0; i < val->vertexAttributeDescriptionCount; i++)
            vn_replace_VkVertexInputAttributeDescription_handle(&((VkVertexInputAttributeDescription *)val->pVertexAttributeDescriptions)[i]);
    }
}

static inline void
vn_replace_VkPipelineVertexInputStateCreateInfo_handle(VkPipelineVertexInputStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO:
            vn_replace_VkPipelineVertexInputStateCreateInfo_handle_self((VkPipelineVertexInputStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineInputAssemblyStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineInputAssemblyStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineInputAssemblyStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineInputAssemblyStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkPrimitiveTopology(cs, &val->topology);
    vn_decode_VkBool32(cs, &val->primitiveRestartEnable);
}

static inline void
vn_decode_VkPipelineInputAssemblyStateCreateInfo_temp(struct vn_cs *cs, VkPipelineInputAssemblyStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineInputAssemblyStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineInputAssemblyStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineInputAssemblyStateCreateInfo_handle_self(VkPipelineInputAssemblyStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->topology */
    /* skip val->primitiveRestartEnable */
}

static inline void
vn_replace_VkPipelineInputAssemblyStateCreateInfo_handle(VkPipelineInputAssemblyStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO:
            vn_replace_VkPipelineInputAssemblyStateCreateInfo_handle_self((VkPipelineInputAssemblyStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineTessellationDomainOriginStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineTessellationDomainOriginStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkTessellationDomainOrigin(cs, &val->domainOrigin);
}

static inline void
vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_temp(struct vn_cs *cs, VkPipelineTessellationDomainOriginStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineTessellationDomainOriginStateCreateInfo_handle_self(VkPipelineTessellationDomainOriginStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->domainOrigin */
}

static inline void
vn_replace_VkPipelineTessellationDomainOriginStateCreateInfo_handle(VkPipelineTessellationDomainOriginStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            vn_replace_VkPipelineTessellationDomainOriginStateCreateInfo_handle_self((VkPipelineTessellationDomainOriginStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineTessellationStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineTessellationStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPipelineTessellationDomainOriginStateCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPipelineTessellationStateCreateInfo_pnext_temp(cs);
            vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_self_temp(cs, (VkPipelineTessellationDomainOriginStateCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPipelineTessellationStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineTessellationStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->patchControlPoints);
}

static inline void
vn_decode_VkPipelineTessellationStateCreateInfo_temp(struct vn_cs *cs, VkPipelineTessellationStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineTessellationStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineTessellationStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineTessellationStateCreateInfo_handle_self(VkPipelineTessellationStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->patchControlPoints */
}

static inline void
vn_replace_VkPipelineTessellationStateCreateInfo_handle(VkPipelineTessellationStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO:
            vn_replace_VkPipelineTessellationStateCreateInfo_handle_self((VkPipelineTessellationStateCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            vn_replace_VkPipelineTessellationDomainOriginStateCreateInfo_handle_self((VkPipelineTessellationDomainOriginStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineViewportStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineViewportStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineViewportStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineViewportStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->viewportCount);
    if (vn_peek_array_size(cs)) {
        val->pViewports = vn_cs_alloc_temp(cs, sizeof(*val->pViewports) * val->viewportCount);
        if (!val->pViewports) return;
        vn_decode_array_size(cs, val->viewportCount);
        for (uint32_t i = 0; i < val->viewportCount; i++)
            vn_decode_VkViewport_temp(cs, &((VkViewport *)val->pViewports)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pViewports = NULL;
    }
    vn_decode_uint32_t(cs, &val->scissorCount);
    if (vn_peek_array_size(cs)) {
        val->pScissors = vn_cs_alloc_temp(cs, sizeof(*val->pScissors) * val->scissorCount);
        if (!val->pScissors) return;
        vn_decode_array_size(cs, val->scissorCount);
        for (uint32_t i = 0; i < val->scissorCount; i++)
            vn_decode_VkRect2D_temp(cs, &((VkRect2D *)val->pScissors)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pScissors = NULL;
    }
}

static inline void
vn_decode_VkPipelineViewportStateCreateInfo_temp(struct vn_cs *cs, VkPipelineViewportStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineViewportStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineViewportStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineViewportStateCreateInfo_handle_self(VkPipelineViewportStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->viewportCount */
    if (val->pViewports) {
       for (uint32_t i = 0; i < val->viewportCount; i++)
            vn_replace_VkViewport_handle(&((VkViewport *)val->pViewports)[i]);
    }
    /* skip val->scissorCount */
    if (val->pScissors) {
       for (uint32_t i = 0; i < val->scissorCount; i++)
            vn_replace_VkRect2D_handle(&((VkRect2D *)val->pScissors)[i]);
    }
}

static inline void
vn_replace_VkPipelineViewportStateCreateInfo_handle(VkPipelineViewportStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO:
            vn_replace_VkPipelineViewportStateCreateInfo_handle_self((VkPipelineViewportStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineRasterizationStateStreamCreateInfoEXT chain */

static inline void *
vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_self_temp(struct vn_cs *cs, VkPipelineRasterizationStateStreamCreateInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->rasterizationStream);
}

static inline void
vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_temp(struct vn_cs *cs, VkPipelineRasterizationStateStreamCreateInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_pnext_temp(cs);
    vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineRasterizationStateStreamCreateInfoEXT_handle_self(VkPipelineRasterizationStateStreamCreateInfoEXT *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->rasterizationStream */
}

static inline void
vn_replace_VkPipelineRasterizationStateStreamCreateInfoEXT_handle(VkPipelineRasterizationStateStreamCreateInfoEXT *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            vn_replace_VkPipelineRasterizationStateStreamCreateInfoEXT_handle_self((VkPipelineRasterizationStateStreamCreateInfoEXT *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineRasterizationStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineRasterizationStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPipelineRasterizationStateStreamCreateInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPipelineRasterizationStateCreateInfo_pnext_temp(cs);
            vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_self_temp(cs, (VkPipelineRasterizationStateStreamCreateInfoEXT *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPipelineRasterizationStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineRasterizationStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkBool32(cs, &val->depthClampEnable);
    vn_decode_VkBool32(cs, &val->rasterizerDiscardEnable);
    vn_decode_VkPolygonMode(cs, &val->polygonMode);
    vn_decode_VkFlags(cs, &val->cullMode);
    vn_decode_VkFrontFace(cs, &val->frontFace);
    vn_decode_VkBool32(cs, &val->depthBiasEnable);
    vn_decode_float(cs, &val->depthBiasConstantFactor);
    vn_decode_float(cs, &val->depthBiasClamp);
    vn_decode_float(cs, &val->depthBiasSlopeFactor);
    vn_decode_float(cs, &val->lineWidth);
}

static inline void
vn_decode_VkPipelineRasterizationStateCreateInfo_temp(struct vn_cs *cs, VkPipelineRasterizationStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineRasterizationStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineRasterizationStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineRasterizationStateCreateInfo_handle_self(VkPipelineRasterizationStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->depthClampEnable */
    /* skip val->rasterizerDiscardEnable */
    /* skip val->polygonMode */
    /* skip val->cullMode */
    /* skip val->frontFace */
    /* skip val->depthBiasEnable */
    /* skip val->depthBiasConstantFactor */
    /* skip val->depthBiasClamp */
    /* skip val->depthBiasSlopeFactor */
    /* skip val->lineWidth */
}

static inline void
vn_replace_VkPipelineRasterizationStateCreateInfo_handle(VkPipelineRasterizationStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO:
            vn_replace_VkPipelineRasterizationStateCreateInfo_handle_self((VkPipelineRasterizationStateCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            vn_replace_VkPipelineRasterizationStateStreamCreateInfoEXT_handle_self((VkPipelineRasterizationStateStreamCreateInfoEXT *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineMultisampleStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineMultisampleStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineMultisampleStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineMultisampleStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkSampleCountFlagBits(cs, &val->rasterizationSamples);
    vn_decode_VkBool32(cs, &val->sampleShadingEnable);
    vn_decode_float(cs, &val->minSampleShading);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, (val->rasterizationSamples + 31) / 32);
        val->pSampleMask = vn_cs_alloc_temp(cs, sizeof(*val->pSampleMask) * array_size);
        if (!val->pSampleMask) return;
        vn_decode_VkSampleMask_array(cs, (VkSampleMask *)val->pSampleMask, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSampleMask = NULL;
    }
    vn_decode_VkBool32(cs, &val->alphaToCoverageEnable);
    vn_decode_VkBool32(cs, &val->alphaToOneEnable);
}

static inline void
vn_decode_VkPipelineMultisampleStateCreateInfo_temp(struct vn_cs *cs, VkPipelineMultisampleStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineMultisampleStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineMultisampleStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineMultisampleStateCreateInfo_handle_self(VkPipelineMultisampleStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->rasterizationSamples */
    /* skip val->sampleShadingEnable */
    /* skip val->minSampleShading */
    /* skip val->pSampleMask */
    /* skip val->alphaToCoverageEnable */
    /* skip val->alphaToOneEnable */
}

static inline void
vn_replace_VkPipelineMultisampleStateCreateInfo_handle(VkPipelineMultisampleStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO:
            vn_replace_VkPipelineMultisampleStateCreateInfo_handle_self((VkPipelineMultisampleStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineColorBlendAttachmentState */

static inline void
vn_decode_VkPipelineColorBlendAttachmentState_temp(struct vn_cs *cs, VkPipelineColorBlendAttachmentState *val)
{
    vn_decode_VkBool32(cs, &val->blendEnable);
    vn_decode_VkBlendFactor(cs, &val->srcColorBlendFactor);
    vn_decode_VkBlendFactor(cs, &val->dstColorBlendFactor);
    vn_decode_VkBlendOp(cs, &val->colorBlendOp);
    vn_decode_VkBlendFactor(cs, &val->srcAlphaBlendFactor);
    vn_decode_VkBlendFactor(cs, &val->dstAlphaBlendFactor);
    vn_decode_VkBlendOp(cs, &val->alphaBlendOp);
    vn_decode_VkFlags(cs, &val->colorWriteMask);
}

static inline void
vn_replace_VkPipelineColorBlendAttachmentState_handle(VkPipelineColorBlendAttachmentState *val)
{
    /* skip val->blendEnable */
    /* skip val->srcColorBlendFactor */
    /* skip val->dstColorBlendFactor */
    /* skip val->colorBlendOp */
    /* skip val->srcAlphaBlendFactor */
    /* skip val->dstAlphaBlendFactor */
    /* skip val->alphaBlendOp */
    /* skip val->colorWriteMask */
}

/* struct VkPipelineColorBlendStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineColorBlendStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineColorBlendStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineColorBlendStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkBool32(cs, &val->logicOpEnable);
    vn_decode_VkLogicOp(cs, &val->logicOp);
    vn_decode_uint32_t(cs, &val->attachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(cs, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkPipelineColorBlendAttachmentState_temp(cs, &((VkPipelineColorBlendAttachmentState *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pAttachments = NULL;
    }
    {
        const size_t array_size = vn_decode_array_size(cs, 4);
        vn_decode_float_array(cs, val->blendConstants, array_size);
    }
}

static inline void
vn_decode_VkPipelineColorBlendStateCreateInfo_temp(struct vn_cs *cs, VkPipelineColorBlendStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineColorBlendStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineColorBlendStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineColorBlendStateCreateInfo_handle_self(VkPipelineColorBlendStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->logicOpEnable */
    /* skip val->logicOp */
    /* skip val->attachmentCount */
    if (val->pAttachments) {
       for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_replace_VkPipelineColorBlendAttachmentState_handle(&((VkPipelineColorBlendAttachmentState *)val->pAttachments)[i]);
    }
    /* skip val->blendConstants */
}

static inline void
vn_replace_VkPipelineColorBlendStateCreateInfo_handle(VkPipelineColorBlendStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO:
            vn_replace_VkPipelineColorBlendStateCreateInfo_handle_self((VkPipelineColorBlendStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineDynamicStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineDynamicStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineDynamicStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineDynamicStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->dynamicStateCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->dynamicStateCount);
        val->pDynamicStates = vn_cs_alloc_temp(cs, sizeof(*val->pDynamicStates) * array_size);
        if (!val->pDynamicStates) return;
        vn_decode_VkDynamicState_array(cs, (VkDynamicState *)val->pDynamicStates, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDynamicStates = NULL;
    }
}

static inline void
vn_decode_VkPipelineDynamicStateCreateInfo_temp(struct vn_cs *cs, VkPipelineDynamicStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineDynamicStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineDynamicStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineDynamicStateCreateInfo_handle_self(VkPipelineDynamicStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->dynamicStateCount */
    /* skip val->pDynamicStates */
}

static inline void
vn_replace_VkPipelineDynamicStateCreateInfo_handle(VkPipelineDynamicStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO:
            vn_replace_VkPipelineDynamicStateCreateInfo_handle_self((VkPipelineDynamicStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkStencilOpState */

static inline void
vn_decode_VkStencilOpState_temp(struct vn_cs *cs, VkStencilOpState *val)
{
    vn_decode_VkStencilOp(cs, &val->failOp);
    vn_decode_VkStencilOp(cs, &val->passOp);
    vn_decode_VkStencilOp(cs, &val->depthFailOp);
    vn_decode_VkCompareOp(cs, &val->compareOp);
    vn_decode_uint32_t(cs, &val->compareMask);
    vn_decode_uint32_t(cs, &val->writeMask);
    vn_decode_uint32_t(cs, &val->reference);
}

static inline void
vn_replace_VkStencilOpState_handle(VkStencilOpState *val)
{
    /* skip val->failOp */
    /* skip val->passOp */
    /* skip val->depthFailOp */
    /* skip val->compareOp */
    /* skip val->compareMask */
    /* skip val->writeMask */
    /* skip val->reference */
}

/* struct VkPipelineDepthStencilStateCreateInfo chain */

static inline void *
vn_decode_VkPipelineDepthStencilStateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineDepthStencilStateCreateInfo_self_temp(struct vn_cs *cs, VkPipelineDepthStencilStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkBool32(cs, &val->depthTestEnable);
    vn_decode_VkBool32(cs, &val->depthWriteEnable);
    vn_decode_VkCompareOp(cs, &val->depthCompareOp);
    vn_decode_VkBool32(cs, &val->depthBoundsTestEnable);
    vn_decode_VkBool32(cs, &val->stencilTestEnable);
    vn_decode_VkStencilOpState_temp(cs, &val->front);
    vn_decode_VkStencilOpState_temp(cs, &val->back);
    vn_decode_float(cs, &val->minDepthBounds);
    vn_decode_float(cs, &val->maxDepthBounds);
}

static inline void
vn_decode_VkPipelineDepthStencilStateCreateInfo_temp(struct vn_cs *cs, VkPipelineDepthStencilStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineDepthStencilStateCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineDepthStencilStateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineDepthStencilStateCreateInfo_handle_self(VkPipelineDepthStencilStateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->depthTestEnable */
    /* skip val->depthWriteEnable */
    /* skip val->depthCompareOp */
    /* skip val->depthBoundsTestEnable */
    /* skip val->stencilTestEnable */
    vn_replace_VkStencilOpState_handle(&val->front);
    vn_replace_VkStencilOpState_handle(&val->back);
    /* skip val->minDepthBounds */
    /* skip val->maxDepthBounds */
}

static inline void
vn_replace_VkPipelineDepthStencilStateCreateInfo_handle(VkPipelineDepthStencilStateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO:
            vn_replace_VkPipelineDepthStencilStateCreateInfo_handle_self((VkPipelineDepthStencilStateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkGraphicsPipelineCreateInfo chain */

static inline void *
vn_decode_VkGraphicsPipelineCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkGraphicsPipelineCreateInfo_self_temp(struct vn_cs *cs, VkGraphicsPipelineCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->stageCount);
    if (vn_peek_array_size(cs)) {
        val->pStages = vn_cs_alloc_temp(cs, sizeof(*val->pStages) * val->stageCount);
        if (!val->pStages) return;
        vn_decode_array_size(cs, val->stageCount);
        for (uint32_t i = 0; i < val->stageCount; i++)
            vn_decode_VkPipelineShaderStageCreateInfo_temp(cs, &((VkPipelineShaderStageCreateInfo *)val->pStages)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pStages = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pVertexInputState = vn_cs_alloc_temp(cs, sizeof(*val->pVertexInputState));
        if (!val->pVertexInputState) return;
        vn_decode_VkPipelineVertexInputStateCreateInfo_temp(cs, (VkPipelineVertexInputStateCreateInfo *)val->pVertexInputState);
    } else {
        val->pVertexInputState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pInputAssemblyState = vn_cs_alloc_temp(cs, sizeof(*val->pInputAssemblyState));
        if (!val->pInputAssemblyState) return;
        vn_decode_VkPipelineInputAssemblyStateCreateInfo_temp(cs, (VkPipelineInputAssemblyStateCreateInfo *)val->pInputAssemblyState);
    } else {
        val->pInputAssemblyState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pTessellationState = vn_cs_alloc_temp(cs, sizeof(*val->pTessellationState));
        if (!val->pTessellationState) return;
        vn_decode_VkPipelineTessellationStateCreateInfo_temp(cs, (VkPipelineTessellationStateCreateInfo *)val->pTessellationState);
    } else {
        val->pTessellationState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pViewportState = vn_cs_alloc_temp(cs, sizeof(*val->pViewportState));
        if (!val->pViewportState) return;
        vn_decode_VkPipelineViewportStateCreateInfo_temp(cs, (VkPipelineViewportStateCreateInfo *)val->pViewportState);
    } else {
        val->pViewportState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pRasterizationState = vn_cs_alloc_temp(cs, sizeof(*val->pRasterizationState));
        if (!val->pRasterizationState) return;
        vn_decode_VkPipelineRasterizationStateCreateInfo_temp(cs, (VkPipelineRasterizationStateCreateInfo *)val->pRasterizationState);
    } else {
        val->pRasterizationState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pMultisampleState = vn_cs_alloc_temp(cs, sizeof(*val->pMultisampleState));
        if (!val->pMultisampleState) return;
        vn_decode_VkPipelineMultisampleStateCreateInfo_temp(cs, (VkPipelineMultisampleStateCreateInfo *)val->pMultisampleState);
    } else {
        val->pMultisampleState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pDepthStencilState = vn_cs_alloc_temp(cs, sizeof(*val->pDepthStencilState));
        if (!val->pDepthStencilState) return;
        vn_decode_VkPipelineDepthStencilStateCreateInfo_temp(cs, (VkPipelineDepthStencilStateCreateInfo *)val->pDepthStencilState);
    } else {
        val->pDepthStencilState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pColorBlendState = vn_cs_alloc_temp(cs, sizeof(*val->pColorBlendState));
        if (!val->pColorBlendState) return;
        vn_decode_VkPipelineColorBlendStateCreateInfo_temp(cs, (VkPipelineColorBlendStateCreateInfo *)val->pColorBlendState);
    } else {
        val->pColorBlendState = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pDynamicState = vn_cs_alloc_temp(cs, sizeof(*val->pDynamicState));
        if (!val->pDynamicState) return;
        vn_decode_VkPipelineDynamicStateCreateInfo_temp(cs, (VkPipelineDynamicStateCreateInfo *)val->pDynamicState);
    } else {
        val->pDynamicState = NULL;
    }
    vn_decode_VkPipelineLayout_lookup(cs, &val->layout);
    vn_decode_VkRenderPass_lookup(cs, &val->renderPass);
    vn_decode_uint32_t(cs, &val->subpass);
    vn_decode_VkPipeline_lookup(cs, &val->basePipelineHandle);
    vn_decode_int32_t(cs, &val->basePipelineIndex);
}

static inline void
vn_decode_VkGraphicsPipelineCreateInfo_temp(struct vn_cs *cs, VkGraphicsPipelineCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkGraphicsPipelineCreateInfo_pnext_temp(cs);
    vn_decode_VkGraphicsPipelineCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkGraphicsPipelineCreateInfo_handle_self(VkGraphicsPipelineCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->stageCount */
    if (val->pStages) {
       for (uint32_t i = 0; i < val->stageCount; i++)
            vn_replace_VkPipelineShaderStageCreateInfo_handle(&((VkPipelineShaderStageCreateInfo *)val->pStages)[i]);
    }
    if (val->pVertexInputState)
        vn_replace_VkPipelineVertexInputStateCreateInfo_handle((VkPipelineVertexInputStateCreateInfo *)val->pVertexInputState);
    if (val->pInputAssemblyState)
        vn_replace_VkPipelineInputAssemblyStateCreateInfo_handle((VkPipelineInputAssemblyStateCreateInfo *)val->pInputAssemblyState);
    if (val->pTessellationState)
        vn_replace_VkPipelineTessellationStateCreateInfo_handle((VkPipelineTessellationStateCreateInfo *)val->pTessellationState);
    if (val->pViewportState)
        vn_replace_VkPipelineViewportStateCreateInfo_handle((VkPipelineViewportStateCreateInfo *)val->pViewportState);
    if (val->pRasterizationState)
        vn_replace_VkPipelineRasterizationStateCreateInfo_handle((VkPipelineRasterizationStateCreateInfo *)val->pRasterizationState);
    if (val->pMultisampleState)
        vn_replace_VkPipelineMultisampleStateCreateInfo_handle((VkPipelineMultisampleStateCreateInfo *)val->pMultisampleState);
    if (val->pDepthStencilState)
        vn_replace_VkPipelineDepthStencilStateCreateInfo_handle((VkPipelineDepthStencilStateCreateInfo *)val->pDepthStencilState);
    if (val->pColorBlendState)
        vn_replace_VkPipelineColorBlendStateCreateInfo_handle((VkPipelineColorBlendStateCreateInfo *)val->pColorBlendState);
    if (val->pDynamicState)
        vn_replace_VkPipelineDynamicStateCreateInfo_handle((VkPipelineDynamicStateCreateInfo *)val->pDynamicState);
    vn_replace_VkPipelineLayout_handle(&val->layout);
    vn_replace_VkRenderPass_handle(&val->renderPass);
    /* skip val->subpass */
    vn_replace_VkPipeline_handle(&val->basePipelineHandle);
    /* skip val->basePipelineIndex */
}

static inline void
vn_replace_VkGraphicsPipelineCreateInfo_handle(VkGraphicsPipelineCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO:
            vn_replace_VkGraphicsPipelineCreateInfo_handle_self((VkGraphicsPipelineCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPipelineCacheCreateInfo chain */

static inline void *
vn_decode_VkPipelineCacheCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineCacheCreateInfo_self_temp(struct vn_cs *cs, VkPipelineCacheCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_size_t(cs, &val->initialDataSize);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->initialDataSize);
        val->pInitialData = vn_cs_alloc_temp(cs, array_size);
        if (!val->pInitialData) return;
        vn_decode_blob_array(cs, (void *)val->pInitialData, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pInitialData = NULL;
    }
}

static inline void
vn_decode_VkPipelineCacheCreateInfo_temp(struct vn_cs *cs, VkPipelineCacheCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineCacheCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineCacheCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineCacheCreateInfo_handle_self(VkPipelineCacheCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->initialDataSize */
    /* skip val->pInitialData */
}

static inline void
vn_replace_VkPipelineCacheCreateInfo_handle(VkPipelineCacheCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO:
            vn_replace_VkPipelineCacheCreateInfo_handle_self((VkPipelineCacheCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPushConstantRange */

static inline void
vn_decode_VkPushConstantRange_temp(struct vn_cs *cs, VkPushConstantRange *val)
{
    vn_decode_VkFlags(cs, &val->stageFlags);
    vn_decode_uint32_t(cs, &val->offset);
    vn_decode_uint32_t(cs, &val->size);
}

static inline void
vn_replace_VkPushConstantRange_handle(VkPushConstantRange *val)
{
    /* skip val->stageFlags */
    /* skip val->offset */
    /* skip val->size */
}

/* struct VkPipelineLayoutCreateInfo chain */

static inline void *
vn_decode_VkPipelineLayoutCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPipelineLayoutCreateInfo_self_temp(struct vn_cs *cs, VkPipelineLayoutCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->setLayoutCount);
    if (vn_peek_array_size(cs)) {
        val->pSetLayouts = vn_cs_alloc_temp(cs, sizeof(*val->pSetLayouts) * val->setLayoutCount);
        if (!val->pSetLayouts) return;
        vn_decode_array_size(cs, val->setLayoutCount);
        for (uint32_t i = 0; i < val->setLayoutCount; i++)
            vn_decode_VkDescriptorSetLayout_lookup(cs, &((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSetLayouts = NULL;
    }
    vn_decode_uint32_t(cs, &val->pushConstantRangeCount);
    if (vn_peek_array_size(cs)) {
        val->pPushConstantRanges = vn_cs_alloc_temp(cs, sizeof(*val->pPushConstantRanges) * val->pushConstantRangeCount);
        if (!val->pPushConstantRanges) return;
        vn_decode_array_size(cs, val->pushConstantRangeCount);
        for (uint32_t i = 0; i < val->pushConstantRangeCount; i++)
            vn_decode_VkPushConstantRange_temp(cs, &((VkPushConstantRange *)val->pPushConstantRanges)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pPushConstantRanges = NULL;
    }
}

static inline void
vn_decode_VkPipelineLayoutCreateInfo_temp(struct vn_cs *cs, VkPipelineLayoutCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineLayoutCreateInfo_pnext_temp(cs);
    vn_decode_VkPipelineLayoutCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPipelineLayoutCreateInfo_handle_self(VkPipelineLayoutCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->setLayoutCount */
    if (val->pSetLayouts) {
       for (uint32_t i = 0; i < val->setLayoutCount; i++)
            vn_replace_VkDescriptorSetLayout_handle(&((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    }
    /* skip val->pushConstantRangeCount */
    if (val->pPushConstantRanges) {
       for (uint32_t i = 0; i < val->pushConstantRangeCount; i++)
            vn_replace_VkPushConstantRange_handle(&((VkPushConstantRange *)val->pPushConstantRanges)[i]);
    }
}

static inline void
vn_replace_VkPipelineLayoutCreateInfo_handle(VkPipelineLayoutCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO:
            vn_replace_VkPipelineLayoutCreateInfo_handle_self((VkPipelineLayoutCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSamplerReductionModeCreateInfo chain */

static inline void *
vn_decode_VkSamplerReductionModeCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSamplerReductionModeCreateInfo_self_temp(struct vn_cs *cs, VkSamplerReductionModeCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSamplerReductionMode(cs, &val->reductionMode);
}

static inline void
vn_decode_VkSamplerReductionModeCreateInfo_temp(struct vn_cs *cs, VkSamplerReductionModeCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerReductionModeCreateInfo_pnext_temp(cs);
    vn_decode_VkSamplerReductionModeCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSamplerReductionModeCreateInfo_handle_self(VkSamplerReductionModeCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->reductionMode */
}

static inline void
vn_replace_VkSamplerReductionModeCreateInfo_handle(VkSamplerReductionModeCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            vn_replace_VkSamplerReductionModeCreateInfo_handle_self((VkSamplerReductionModeCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSamplerCreateInfo chain */

static inline void *
vn_decode_VkSamplerCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkSamplerYcbcrConversionInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(cs);
            vn_decode_VkSamplerYcbcrConversionInfo_self_temp(cs, (VkSamplerYcbcrConversionInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkSamplerReductionModeCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(cs);
            vn_decode_VkSamplerReductionModeCreateInfo_self_temp(cs, (VkSamplerReductionModeCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSamplerCreateInfo_self_temp(struct vn_cs *cs, VkSamplerCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkFilter(cs, &val->magFilter);
    vn_decode_VkFilter(cs, &val->minFilter);
    vn_decode_VkSamplerMipmapMode(cs, &val->mipmapMode);
    vn_decode_VkSamplerAddressMode(cs, &val->addressModeU);
    vn_decode_VkSamplerAddressMode(cs, &val->addressModeV);
    vn_decode_VkSamplerAddressMode(cs, &val->addressModeW);
    vn_decode_float(cs, &val->mipLodBias);
    vn_decode_VkBool32(cs, &val->anisotropyEnable);
    vn_decode_float(cs, &val->maxAnisotropy);
    vn_decode_VkBool32(cs, &val->compareEnable);
    vn_decode_VkCompareOp(cs, &val->compareOp);
    vn_decode_float(cs, &val->minLod);
    vn_decode_float(cs, &val->maxLod);
    vn_decode_VkBorderColor(cs, &val->borderColor);
    vn_decode_VkBool32(cs, &val->unnormalizedCoordinates);
}

static inline void
vn_decode_VkSamplerCreateInfo_temp(struct vn_cs *cs, VkSamplerCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(cs);
    vn_decode_VkSamplerCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSamplerCreateInfo_handle_self(VkSamplerCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->magFilter */
    /* skip val->minFilter */
    /* skip val->mipmapMode */
    /* skip val->addressModeU */
    /* skip val->addressModeV */
    /* skip val->addressModeW */
    /* skip val->mipLodBias */
    /* skip val->anisotropyEnable */
    /* skip val->maxAnisotropy */
    /* skip val->compareEnable */
    /* skip val->compareOp */
    /* skip val->minLod */
    /* skip val->maxLod */
    /* skip val->borderColor */
    /* skip val->unnormalizedCoordinates */
}

static inline void
vn_replace_VkSamplerCreateInfo_handle(VkSamplerCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO:
            vn_replace_VkSamplerCreateInfo_handle_self((VkSamplerCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            vn_replace_VkSamplerYcbcrConversionInfo_handle_self((VkSamplerYcbcrConversionInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            vn_replace_VkSamplerReductionModeCreateInfo_handle_self((VkSamplerReductionModeCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkCommandPoolCreateInfo chain */

static inline void *
vn_decode_VkCommandPoolCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkCommandPoolCreateInfo_self_temp(struct vn_cs *cs, VkCommandPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->queueFamilyIndex);
}

static inline void
vn_decode_VkCommandPoolCreateInfo_temp(struct vn_cs *cs, VkCommandPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandPoolCreateInfo_pnext_temp(cs);
    vn_decode_VkCommandPoolCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkCommandPoolCreateInfo_handle_self(VkCommandPoolCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->queueFamilyIndex */
}

static inline void
vn_replace_VkCommandPoolCreateInfo_handle(VkCommandPoolCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO:
            vn_replace_VkCommandPoolCreateInfo_handle_self((VkCommandPoolCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkCommandBufferAllocateInfo chain */

static inline void *
vn_decode_VkCommandBufferAllocateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkCommandBufferAllocateInfo_self_temp(struct vn_cs *cs, VkCommandBufferAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkCommandPool_lookup(cs, &val->commandPool);
    vn_decode_VkCommandBufferLevel(cs, &val->level);
    vn_decode_uint32_t(cs, &val->commandBufferCount);
}

static inline void
vn_decode_VkCommandBufferAllocateInfo_temp(struct vn_cs *cs, VkCommandBufferAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandBufferAllocateInfo_pnext_temp(cs);
    vn_decode_VkCommandBufferAllocateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkCommandBufferAllocateInfo_handle_self(VkCommandBufferAllocateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkCommandPool_handle(&val->commandPool);
    /* skip val->level */
    /* skip val->commandBufferCount */
}

static inline void
vn_replace_VkCommandBufferAllocateInfo_handle(VkCommandBufferAllocateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO:
            vn_replace_VkCommandBufferAllocateInfo_handle_self((VkCommandBufferAllocateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkCommandBufferInheritanceInfo chain */

static inline void
vn_encode_VkCommandBufferInheritanceInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkCommandBufferInheritanceInfo_self(struct vn_cs *cs, const VkCommandBufferInheritanceInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkRenderPass(cs, &val->renderPass);
    vn_encode_uint32_t(cs, &val->subpass);
    vn_encode_VkFramebuffer(cs, &val->framebuffer);
    vn_encode_VkBool32(cs, &val->occlusionQueryEnable);
    vn_encode_VkFlags(cs, &val->queryFlags);
    vn_encode_VkFlags(cs, &val->pipelineStatistics);
}

static inline void
vn_encode_VkCommandBufferInheritanceInfo(struct vn_cs *cs, const VkCommandBufferInheritanceInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO });
    vn_encode_VkCommandBufferInheritanceInfo_pnext(cs, val->pNext);
    vn_encode_VkCommandBufferInheritanceInfo_self(cs, val);
}

static inline void *
vn_decode_VkCommandBufferInheritanceInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkCommandBufferInheritanceInfo_self_temp(struct vn_cs *cs, VkCommandBufferInheritanceInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkRenderPass_lookup(cs, &val->renderPass);
    vn_decode_uint32_t(cs, &val->subpass);
    vn_decode_VkFramebuffer_lookup(cs, &val->framebuffer);
    vn_decode_VkBool32(cs, &val->occlusionQueryEnable);
    vn_decode_VkFlags(cs, &val->queryFlags);
    vn_decode_VkFlags(cs, &val->pipelineStatistics);
}

static inline void
vn_decode_VkCommandBufferInheritanceInfo_temp(struct vn_cs *cs, VkCommandBufferInheritanceInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandBufferInheritanceInfo_pnext_temp(cs);
    vn_decode_VkCommandBufferInheritanceInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkCommandBufferInheritanceInfo_handle_self(VkCommandBufferInheritanceInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkRenderPass_handle(&val->renderPass);
    /* skip val->subpass */
    vn_replace_VkFramebuffer_handle(&val->framebuffer);
    /* skip val->occlusionQueryEnable */
    /* skip val->queryFlags */
    /* skip val->pipelineStatistics */
}

static inline void
vn_replace_VkCommandBufferInheritanceInfo_handle(VkCommandBufferInheritanceInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO:
            vn_replace_VkCommandBufferInheritanceInfo_handle_self((VkCommandBufferInheritanceInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDeviceGroupCommandBufferBeginInfo chain */

static inline void
vn_encode_VkDeviceGroupCommandBufferBeginInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkDeviceGroupCommandBufferBeginInfo_self(struct vn_cs *cs, const VkDeviceGroupCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->deviceMask);
}

static inline void
vn_encode_VkDeviceGroupCommandBufferBeginInfo(struct vn_cs *cs, const VkDeviceGroupCommandBufferBeginInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO });
    vn_encode_VkDeviceGroupCommandBufferBeginInfo_pnext(cs, val->pNext);
    vn_encode_VkDeviceGroupCommandBufferBeginInfo_self(cs, val);
}

static inline void *
vn_decode_VkDeviceGroupCommandBufferBeginInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupCommandBufferBeginInfo_self_temp(struct vn_cs *cs, VkDeviceGroupCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->deviceMask);
}

static inline void
vn_decode_VkDeviceGroupCommandBufferBeginInfo_temp(struct vn_cs *cs, VkDeviceGroupCommandBufferBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupCommandBufferBeginInfo_pnext_temp(cs);
    vn_decode_VkDeviceGroupCommandBufferBeginInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceGroupCommandBufferBeginInfo_handle_self(VkDeviceGroupCommandBufferBeginInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->deviceMask */
}

static inline void
vn_replace_VkDeviceGroupCommandBufferBeginInfo_handle(VkDeviceGroupCommandBufferBeginInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            vn_replace_VkDeviceGroupCommandBufferBeginInfo_handle_self((VkDeviceGroupCommandBufferBeginInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkCommandBufferBeginInfo chain */

static inline void
vn_encode_VkCommandBufferBeginInfo_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkCommandBufferBeginInfo_pnext(cs, pnext->pNext);
            vn_encode_VkDeviceGroupCommandBufferBeginInfo_self(cs, (const VkDeviceGroupCommandBufferBeginInfo *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkCommandBufferBeginInfo_self(struct vn_cs *cs, const VkCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(cs, &val->flags);
    if (vn_encode_simple_pointer(cs, val->pInheritanceInfo))
        vn_encode_VkCommandBufferInheritanceInfo(cs, val->pInheritanceInfo);
}

static inline void
vn_encode_VkCommandBufferBeginInfo(struct vn_cs *cs, const VkCommandBufferBeginInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO });
    vn_encode_VkCommandBufferBeginInfo_pnext(cs, val->pNext);
    vn_encode_VkCommandBufferBeginInfo_self(cs, val);
}

static inline void *
vn_decode_VkCommandBufferBeginInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDeviceGroupCommandBufferBeginInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkCommandBufferBeginInfo_pnext_temp(cs);
            vn_decode_VkDeviceGroupCommandBufferBeginInfo_self_temp(cs, (VkDeviceGroupCommandBufferBeginInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkCommandBufferBeginInfo_self_temp(struct vn_cs *cs, VkCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    if (vn_decode_simple_pointer(cs)) {
        val->pInheritanceInfo = vn_cs_alloc_temp(cs, sizeof(*val->pInheritanceInfo));
        if (!val->pInheritanceInfo) return;
        vn_decode_VkCommandBufferInheritanceInfo_temp(cs, (VkCommandBufferInheritanceInfo *)val->pInheritanceInfo);
    } else {
        val->pInheritanceInfo = NULL;
    }
}

static inline void
vn_decode_VkCommandBufferBeginInfo_temp(struct vn_cs *cs, VkCommandBufferBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandBufferBeginInfo_pnext_temp(cs);
    vn_decode_VkCommandBufferBeginInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkCommandBufferBeginInfo_handle_self(VkCommandBufferBeginInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    if (val->pInheritanceInfo)
        vn_replace_VkCommandBufferInheritanceInfo_handle((VkCommandBufferInheritanceInfo *)val->pInheritanceInfo);
}

static inline void
vn_replace_VkCommandBufferBeginInfo_handle(VkCommandBufferBeginInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO:
            vn_replace_VkCommandBufferBeginInfo_handle_self((VkCommandBufferBeginInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            vn_replace_VkDeviceGroupCommandBufferBeginInfo_handle_self((VkDeviceGroupCommandBufferBeginInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* union VkClearColorValue */

static inline void
vn_decode_VkClearColorValue_temp(struct vn_cs *cs, VkClearColorValue *val)
{
    uint32_t tag;
    vn_decode_uint32_t(cs, &tag);
    switch (tag) {
    case 0:
        {
        const size_t array_size = vn_decode_array_size(cs, 4);
        vn_decode_float_array(cs, val->float32, array_size);
    }
        break;
    case 1:
        {
        const size_t array_size = vn_decode_array_size(cs, 4);
        vn_decode_int32_t_array(cs, val->int32, array_size);
    }
        break;
    case 2:
        {
        const size_t array_size = vn_decode_array_size(cs, 4);
        vn_decode_uint32_t_array(cs, val->uint32, array_size);
    }
        break;
    default:
        vn_cs_set_error(cs);
        break;
    }
}

/* struct VkClearDepthStencilValue */

static inline void
vn_decode_VkClearDepthStencilValue_temp(struct vn_cs *cs, VkClearDepthStencilValue *val)
{
    vn_decode_float(cs, &val->depth);
    vn_decode_uint32_t(cs, &val->stencil);
}

static inline void
vn_replace_VkClearDepthStencilValue_handle(VkClearDepthStencilValue *val)
{
    /* skip val->depth */
    /* skip val->stencil */
}

/* union VkClearValue */

static inline void
vn_decode_VkClearValue_temp(struct vn_cs *cs, VkClearValue *val)
{
    uint32_t tag;
    vn_decode_uint32_t(cs, &tag);
    switch (tag) {
    case 0:
        vn_decode_VkClearColorValue_temp(cs, &val->color);
        break;
    case 1:
        vn_decode_VkClearDepthStencilValue_temp(cs, &val->depthStencil);
        break;
    default:
        vn_cs_set_error(cs);
        break;
    }
}

/* struct VkDeviceGroupRenderPassBeginInfo chain */

static inline void *
vn_decode_VkDeviceGroupRenderPassBeginInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupRenderPassBeginInfo_self_temp(struct vn_cs *cs, VkDeviceGroupRenderPassBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->deviceMask);
    vn_decode_uint32_t(cs, &val->deviceRenderAreaCount);
    if (vn_peek_array_size(cs)) {
        val->pDeviceRenderAreas = vn_cs_alloc_temp(cs, sizeof(*val->pDeviceRenderAreas) * val->deviceRenderAreaCount);
        if (!val->pDeviceRenderAreas) return;
        vn_decode_array_size(cs, val->deviceRenderAreaCount);
        for (uint32_t i = 0; i < val->deviceRenderAreaCount; i++)
            vn_decode_VkRect2D_temp(cs, &((VkRect2D *)val->pDeviceRenderAreas)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDeviceRenderAreas = NULL;
    }
}

static inline void
vn_decode_VkDeviceGroupRenderPassBeginInfo_temp(struct vn_cs *cs, VkDeviceGroupRenderPassBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupRenderPassBeginInfo_pnext_temp(cs);
    vn_decode_VkDeviceGroupRenderPassBeginInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceGroupRenderPassBeginInfo_handle_self(VkDeviceGroupRenderPassBeginInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->deviceMask */
    /* skip val->deviceRenderAreaCount */
    if (val->pDeviceRenderAreas) {
       for (uint32_t i = 0; i < val->deviceRenderAreaCount; i++)
            vn_replace_VkRect2D_handle(&((VkRect2D *)val->pDeviceRenderAreas)[i]);
    }
}

static inline void
vn_replace_VkDeviceGroupRenderPassBeginInfo_handle(VkDeviceGroupRenderPassBeginInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            vn_replace_VkDeviceGroupRenderPassBeginInfo_handle_self((VkDeviceGroupRenderPassBeginInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkRenderPassAttachmentBeginInfo chain */

static inline void *
vn_decode_VkRenderPassAttachmentBeginInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkRenderPassAttachmentBeginInfo_self_temp(struct vn_cs *cs, VkRenderPassAttachmentBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->attachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(cs, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkImageView_lookup(cs, &((VkImageView *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pAttachments = NULL;
    }
}

static inline void
vn_decode_VkRenderPassAttachmentBeginInfo_temp(struct vn_cs *cs, VkRenderPassAttachmentBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassAttachmentBeginInfo_pnext_temp(cs);
    vn_decode_VkRenderPassAttachmentBeginInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkRenderPassAttachmentBeginInfo_handle_self(VkRenderPassAttachmentBeginInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->attachmentCount */
    if (val->pAttachments) {
       for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_replace_VkImageView_handle(&((VkImageView *)val->pAttachments)[i]);
    }
}

static inline void
vn_replace_VkRenderPassAttachmentBeginInfo_handle(VkRenderPassAttachmentBeginInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            vn_replace_VkRenderPassAttachmentBeginInfo_handle_self((VkRenderPassAttachmentBeginInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkRenderPassBeginInfo chain */

static inline void *
vn_decode_VkRenderPassBeginInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDeviceGroupRenderPassBeginInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassBeginInfo_pnext_temp(cs);
            vn_decode_VkDeviceGroupRenderPassBeginInfo_self_temp(cs, (VkDeviceGroupRenderPassBeginInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkRenderPassAttachmentBeginInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassBeginInfo_pnext_temp(cs);
            vn_decode_VkRenderPassAttachmentBeginInfo_self_temp(cs, (VkRenderPassAttachmentBeginInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkRenderPassBeginInfo_self_temp(struct vn_cs *cs, VkRenderPassBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkRenderPass_lookup(cs, &val->renderPass);
    vn_decode_VkFramebuffer_lookup(cs, &val->framebuffer);
    vn_decode_VkRect2D_temp(cs, &val->renderArea);
    vn_decode_uint32_t(cs, &val->clearValueCount);
    if (vn_peek_array_size(cs)) {
        val->pClearValues = vn_cs_alloc_temp(cs, sizeof(*val->pClearValues) * val->clearValueCount);
        if (!val->pClearValues) return;
        vn_decode_array_size(cs, val->clearValueCount);
        for (uint32_t i = 0; i < val->clearValueCount; i++)
            vn_decode_VkClearValue_temp(cs, &((VkClearValue *)val->pClearValues)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pClearValues = NULL;
    }
}

static inline void
vn_decode_VkRenderPassBeginInfo_temp(struct vn_cs *cs, VkRenderPassBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassBeginInfo_pnext_temp(cs);
    vn_decode_VkRenderPassBeginInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkRenderPassBeginInfo_handle_self(VkRenderPassBeginInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkRenderPass_handle(&val->renderPass);
    vn_replace_VkFramebuffer_handle(&val->framebuffer);
    vn_replace_VkRect2D_handle(&val->renderArea);
    /* skip val->clearValueCount */
    /* skip val->pClearValues */
}

static inline void
vn_replace_VkRenderPassBeginInfo_handle(VkRenderPassBeginInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO:
            vn_replace_VkRenderPassBeginInfo_handle_self((VkRenderPassBeginInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            vn_replace_VkDeviceGroupRenderPassBeginInfo_handle_self((VkDeviceGroupRenderPassBeginInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            vn_replace_VkRenderPassAttachmentBeginInfo_handle_self((VkRenderPassAttachmentBeginInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkClearAttachment */

static inline void
vn_decode_VkClearAttachment_temp(struct vn_cs *cs, VkClearAttachment *val)
{
    vn_decode_VkFlags(cs, &val->aspectMask);
    vn_decode_uint32_t(cs, &val->colorAttachment);
    vn_decode_VkClearValue_temp(cs, &val->clearValue);
}

static inline void
vn_replace_VkClearAttachment_handle(VkClearAttachment *val)
{
    /* skip val->aspectMask */
    /* skip val->colorAttachment */
    /* skip val->clearValue */
}

/* struct VkAttachmentDescription */

static inline void
vn_decode_VkAttachmentDescription_temp(struct vn_cs *cs, VkAttachmentDescription *val)
{
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkSampleCountFlagBits(cs, &val->samples);
    vn_decode_VkAttachmentLoadOp(cs, &val->loadOp);
    vn_decode_VkAttachmentStoreOp(cs, &val->storeOp);
    vn_decode_VkAttachmentLoadOp(cs, &val->stencilLoadOp);
    vn_decode_VkAttachmentStoreOp(cs, &val->stencilStoreOp);
    vn_decode_VkImageLayout(cs, &val->initialLayout);
    vn_decode_VkImageLayout(cs, &val->finalLayout);
}

static inline void
vn_replace_VkAttachmentDescription_handle(VkAttachmentDescription *val)
{
    /* skip val->flags */
    /* skip val->format */
    /* skip val->samples */
    /* skip val->loadOp */
    /* skip val->storeOp */
    /* skip val->stencilLoadOp */
    /* skip val->stencilStoreOp */
    /* skip val->initialLayout */
    /* skip val->finalLayout */
}

/* struct VkAttachmentReference */

static inline void
vn_decode_VkAttachmentReference_temp(struct vn_cs *cs, VkAttachmentReference *val)
{
    vn_decode_uint32_t(cs, &val->attachment);
    vn_decode_VkImageLayout(cs, &val->layout);
}

static inline void
vn_replace_VkAttachmentReference_handle(VkAttachmentReference *val)
{
    /* skip val->attachment */
    /* skip val->layout */
}

/* struct VkSubpassDescription */

static inline void
vn_decode_VkSubpassDescription_temp(struct vn_cs *cs, VkSubpassDescription *val)
{
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkPipelineBindPoint(cs, &val->pipelineBindPoint);
    vn_decode_uint32_t(cs, &val->inputAttachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pInputAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pInputAttachments) * val->inputAttachmentCount);
        if (!val->pInputAttachments) return;
        vn_decode_array_size(cs, val->inputAttachmentCount);
        for (uint32_t i = 0; i < val->inputAttachmentCount; i++)
            vn_decode_VkAttachmentReference_temp(cs, &((VkAttachmentReference *)val->pInputAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pInputAttachments = NULL;
    }
    vn_decode_uint32_t(cs, &val->colorAttachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pColorAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pColorAttachments) * val->colorAttachmentCount);
        if (!val->pColorAttachments) return;
        vn_decode_array_size(cs, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference_temp(cs, &((VkAttachmentReference *)val->pColorAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pColorAttachments = NULL;
    }
    if (vn_peek_array_size(cs)) {
        val->pResolveAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pResolveAttachments) * val->colorAttachmentCount);
        if (!val->pResolveAttachments) return;
        vn_decode_array_size(cs, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference_temp(cs, &((VkAttachmentReference *)val->pResolveAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pResolveAttachments = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pDepthStencilAttachment = vn_cs_alloc_temp(cs, sizeof(*val->pDepthStencilAttachment));
        if (!val->pDepthStencilAttachment) return;
        vn_decode_VkAttachmentReference_temp(cs, (VkAttachmentReference *)val->pDepthStencilAttachment);
    } else {
        val->pDepthStencilAttachment = NULL;
    }
    vn_decode_uint32_t(cs, &val->preserveAttachmentCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->preserveAttachmentCount);
        val->pPreserveAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pPreserveAttachments) * array_size);
        if (!val->pPreserveAttachments) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pPreserveAttachments, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pPreserveAttachments = NULL;
    }
}

static inline void
vn_replace_VkSubpassDescription_handle(VkSubpassDescription *val)
{
    /* skip val->flags */
    /* skip val->pipelineBindPoint */
    /* skip val->inputAttachmentCount */
    if (val->pInputAttachments) {
       for (uint32_t i = 0; i < val->inputAttachmentCount; i++)
            vn_replace_VkAttachmentReference_handle(&((VkAttachmentReference *)val->pInputAttachments)[i]);
    }
    /* skip val->colorAttachmentCount */
    if (val->pColorAttachments) {
       for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_replace_VkAttachmentReference_handle(&((VkAttachmentReference *)val->pColorAttachments)[i]);
    }
    if (val->pResolveAttachments) {
       for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_replace_VkAttachmentReference_handle(&((VkAttachmentReference *)val->pResolveAttachments)[i]);
    }
    if (val->pDepthStencilAttachment)
        vn_replace_VkAttachmentReference_handle((VkAttachmentReference *)val->pDepthStencilAttachment);
    /* skip val->preserveAttachmentCount */
    /* skip val->pPreserveAttachments */
}

/* struct VkSubpassDependency */

static inline void
vn_decode_VkSubpassDependency_temp(struct vn_cs *cs, VkSubpassDependency *val)
{
    vn_decode_uint32_t(cs, &val->srcSubpass);
    vn_decode_uint32_t(cs, &val->dstSubpass);
    vn_decode_VkFlags(cs, &val->srcStageMask);
    vn_decode_VkFlags(cs, &val->dstStageMask);
    vn_decode_VkFlags(cs, &val->srcAccessMask);
    vn_decode_VkFlags(cs, &val->dstAccessMask);
    vn_decode_VkFlags(cs, &val->dependencyFlags);
}

static inline void
vn_replace_VkSubpassDependency_handle(VkSubpassDependency *val)
{
    /* skip val->srcSubpass */
    /* skip val->dstSubpass */
    /* skip val->srcStageMask */
    /* skip val->dstStageMask */
    /* skip val->srcAccessMask */
    /* skip val->dstAccessMask */
    /* skip val->dependencyFlags */
}

/* struct VkRenderPassMultiviewCreateInfo chain */

static inline void *
vn_decode_VkRenderPassMultiviewCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkRenderPassMultiviewCreateInfo_self_temp(struct vn_cs *cs, VkRenderPassMultiviewCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->subpassCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->subpassCount);
        val->pViewMasks = vn_cs_alloc_temp(cs, sizeof(*val->pViewMasks) * array_size);
        if (!val->pViewMasks) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pViewMasks, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pViewMasks = NULL;
    }
    vn_decode_uint32_t(cs, &val->dependencyCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->dependencyCount);
        val->pViewOffsets = vn_cs_alloc_temp(cs, sizeof(*val->pViewOffsets) * array_size);
        if (!val->pViewOffsets) return;
        vn_decode_int32_t_array(cs, (int32_t *)val->pViewOffsets, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pViewOffsets = NULL;
    }
    vn_decode_uint32_t(cs, &val->correlationMaskCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->correlationMaskCount);
        val->pCorrelationMasks = vn_cs_alloc_temp(cs, sizeof(*val->pCorrelationMasks) * array_size);
        if (!val->pCorrelationMasks) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pCorrelationMasks, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pCorrelationMasks = NULL;
    }
}

static inline void
vn_decode_VkRenderPassMultiviewCreateInfo_temp(struct vn_cs *cs, VkRenderPassMultiviewCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassMultiviewCreateInfo_pnext_temp(cs);
    vn_decode_VkRenderPassMultiviewCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkRenderPassMultiviewCreateInfo_handle_self(VkRenderPassMultiviewCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->subpassCount */
    /* skip val->pViewMasks */
    /* skip val->dependencyCount */
    /* skip val->pViewOffsets */
    /* skip val->correlationMaskCount */
    /* skip val->pCorrelationMasks */
}

static inline void
vn_replace_VkRenderPassMultiviewCreateInfo_handle(VkRenderPassMultiviewCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            vn_replace_VkRenderPassMultiviewCreateInfo_handle_self((VkRenderPassMultiviewCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkInputAttachmentAspectReference */

static inline void
vn_decode_VkInputAttachmentAspectReference_temp(struct vn_cs *cs, VkInputAttachmentAspectReference *val)
{
    vn_decode_uint32_t(cs, &val->subpass);
    vn_decode_uint32_t(cs, &val->inputAttachmentIndex);
    vn_decode_VkFlags(cs, &val->aspectMask);
}

static inline void
vn_replace_VkInputAttachmentAspectReference_handle(VkInputAttachmentAspectReference *val)
{
    /* skip val->subpass */
    /* skip val->inputAttachmentIndex */
    /* skip val->aspectMask */
}

/* struct VkRenderPassInputAttachmentAspectCreateInfo chain */

static inline void *
vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_self_temp(struct vn_cs *cs, VkRenderPassInputAttachmentAspectCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->aspectReferenceCount);
    if (vn_peek_array_size(cs)) {
        val->pAspectReferences = vn_cs_alloc_temp(cs, sizeof(*val->pAspectReferences) * val->aspectReferenceCount);
        if (!val->pAspectReferences) return;
        vn_decode_array_size(cs, val->aspectReferenceCount);
        for (uint32_t i = 0; i < val->aspectReferenceCount; i++)
            vn_decode_VkInputAttachmentAspectReference_temp(cs, &((VkInputAttachmentAspectReference *)val->pAspectReferences)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pAspectReferences = NULL;
    }
}

static inline void
vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_temp(struct vn_cs *cs, VkRenderPassInputAttachmentAspectCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_pnext_temp(cs);
    vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkRenderPassInputAttachmentAspectCreateInfo_handle_self(VkRenderPassInputAttachmentAspectCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->aspectReferenceCount */
    if (val->pAspectReferences) {
       for (uint32_t i = 0; i < val->aspectReferenceCount; i++)
            vn_replace_VkInputAttachmentAspectReference_handle(&((VkInputAttachmentAspectReference *)val->pAspectReferences)[i]);
    }
}

static inline void
vn_replace_VkRenderPassInputAttachmentAspectCreateInfo_handle(VkRenderPassInputAttachmentAspectCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            vn_replace_VkRenderPassInputAttachmentAspectCreateInfo_handle_self((VkRenderPassInputAttachmentAspectCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkRenderPassCreateInfo chain */

static inline void *
vn_decode_VkRenderPassCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkRenderPassMultiviewCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassCreateInfo_pnext_temp(cs);
            vn_decode_VkRenderPassMultiviewCreateInfo_self_temp(cs, (VkRenderPassMultiviewCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkRenderPassInputAttachmentAspectCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassCreateInfo_pnext_temp(cs);
            vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_self_temp(cs, (VkRenderPassInputAttachmentAspectCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkRenderPassCreateInfo_self_temp(struct vn_cs *cs, VkRenderPassCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->attachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(cs, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkAttachmentDescription_temp(cs, &((VkAttachmentDescription *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pAttachments = NULL;
    }
    vn_decode_uint32_t(cs, &val->subpassCount);
    if (vn_peek_array_size(cs)) {
        val->pSubpasses = vn_cs_alloc_temp(cs, sizeof(*val->pSubpasses) * val->subpassCount);
        if (!val->pSubpasses) return;
        vn_decode_array_size(cs, val->subpassCount);
        for (uint32_t i = 0; i < val->subpassCount; i++)
            vn_decode_VkSubpassDescription_temp(cs, &((VkSubpassDescription *)val->pSubpasses)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSubpasses = NULL;
    }
    vn_decode_uint32_t(cs, &val->dependencyCount);
    if (vn_peek_array_size(cs)) {
        val->pDependencies = vn_cs_alloc_temp(cs, sizeof(*val->pDependencies) * val->dependencyCount);
        if (!val->pDependencies) return;
        vn_decode_array_size(cs, val->dependencyCount);
        for (uint32_t i = 0; i < val->dependencyCount; i++)
            vn_decode_VkSubpassDependency_temp(cs, &((VkSubpassDependency *)val->pDependencies)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDependencies = NULL;
    }
}

static inline void
vn_decode_VkRenderPassCreateInfo_temp(struct vn_cs *cs, VkRenderPassCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassCreateInfo_pnext_temp(cs);
    vn_decode_VkRenderPassCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkRenderPassCreateInfo_handle_self(VkRenderPassCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->attachmentCount */
    if (val->pAttachments) {
       for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_replace_VkAttachmentDescription_handle(&((VkAttachmentDescription *)val->pAttachments)[i]);
    }
    /* skip val->subpassCount */
    if (val->pSubpasses) {
       for (uint32_t i = 0; i < val->subpassCount; i++)
            vn_replace_VkSubpassDescription_handle(&((VkSubpassDescription *)val->pSubpasses)[i]);
    }
    /* skip val->dependencyCount */
    if (val->pDependencies) {
       for (uint32_t i = 0; i < val->dependencyCount; i++)
            vn_replace_VkSubpassDependency_handle(&((VkSubpassDependency *)val->pDependencies)[i]);
    }
}

static inline void
vn_replace_VkRenderPassCreateInfo_handle(VkRenderPassCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO:
            vn_replace_VkRenderPassCreateInfo_handle_self((VkRenderPassCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            vn_replace_VkRenderPassMultiviewCreateInfo_handle_self((VkRenderPassMultiviewCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            vn_replace_VkRenderPassInputAttachmentAspectCreateInfo_handle_self((VkRenderPassInputAttachmentAspectCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkEventCreateInfo chain */

static inline void *
vn_decode_VkEventCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkEventCreateInfo_self_temp(struct vn_cs *cs, VkEventCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
}

static inline void
vn_decode_VkEventCreateInfo_temp(struct vn_cs *cs, VkEventCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EVENT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkEventCreateInfo_pnext_temp(cs);
    vn_decode_VkEventCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkEventCreateInfo_handle_self(VkEventCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
}

static inline void
vn_replace_VkEventCreateInfo_handle(VkEventCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EVENT_CREATE_INFO:
            vn_replace_VkEventCreateInfo_handle_self((VkEventCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkExportFenceCreateInfo chain */

static inline void *
vn_decode_VkExportFenceCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExportFenceCreateInfo_self_temp(struct vn_cs *cs, VkExportFenceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->handleTypes);
}

static inline void
vn_decode_VkExportFenceCreateInfo_temp(struct vn_cs *cs, VkExportFenceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExportFenceCreateInfo_pnext_temp(cs);
    vn_decode_VkExportFenceCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkExportFenceCreateInfo_handle_self(VkExportFenceCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleTypes */
}

static inline void
vn_replace_VkExportFenceCreateInfo_handle(VkExportFenceCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            vn_replace_VkExportFenceCreateInfo_handle_self((VkExportFenceCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkFenceCreateInfo chain */

static inline void *
vn_decode_VkFenceCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkExportFenceCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkFenceCreateInfo_pnext_temp(cs);
            vn_decode_VkExportFenceCreateInfo_self_temp(cs, (VkExportFenceCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkFenceCreateInfo_self_temp(struct vn_cs *cs, VkFenceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
}

static inline void
vn_decode_VkFenceCreateInfo_temp(struct vn_cs *cs, VkFenceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FENCE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFenceCreateInfo_pnext_temp(cs);
    vn_decode_VkFenceCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkFenceCreateInfo_handle_self(VkFenceCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
}

static inline void
vn_replace_VkFenceCreateInfo_handle(VkFenceCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_FENCE_CREATE_INFO:
            vn_replace_VkFenceCreateInfo_handle_self((VkFenceCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            vn_replace_VkExportFenceCreateInfo_handle_self((VkExportFenceCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkExportSemaphoreCreateInfo chain */

static inline void *
vn_decode_VkExportSemaphoreCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExportSemaphoreCreateInfo_self_temp(struct vn_cs *cs, VkExportSemaphoreCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->handleTypes);
}

static inline void
vn_decode_VkExportSemaphoreCreateInfo_temp(struct vn_cs *cs, VkExportSemaphoreCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExportSemaphoreCreateInfo_pnext_temp(cs);
    vn_decode_VkExportSemaphoreCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkExportSemaphoreCreateInfo_handle_self(VkExportSemaphoreCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleTypes */
}

static inline void
vn_replace_VkExportSemaphoreCreateInfo_handle(VkExportSemaphoreCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            vn_replace_VkExportSemaphoreCreateInfo_handle_self((VkExportSemaphoreCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSemaphoreTypeCreateInfo chain */

static inline void *
vn_decode_VkSemaphoreTypeCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSemaphoreTypeCreateInfo_self_temp(struct vn_cs *cs, VkSemaphoreTypeCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSemaphoreType(cs, &val->semaphoreType);
    vn_decode_uint64_t(cs, &val->initialValue);
}

static inline void
vn_decode_VkSemaphoreTypeCreateInfo_temp(struct vn_cs *cs, VkSemaphoreTypeCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreTypeCreateInfo_pnext_temp(cs);
    vn_decode_VkSemaphoreTypeCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSemaphoreTypeCreateInfo_handle_self(VkSemaphoreTypeCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->semaphoreType */
    /* skip val->initialValue */
}

static inline void
vn_replace_VkSemaphoreTypeCreateInfo_handle(VkSemaphoreTypeCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            vn_replace_VkSemaphoreTypeCreateInfo_handle_self((VkSemaphoreTypeCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSemaphoreCreateInfo chain */

static inline void *
vn_decode_VkSemaphoreCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkExportSemaphoreCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSemaphoreCreateInfo_pnext_temp(cs);
            vn_decode_VkExportSemaphoreCreateInfo_self_temp(cs, (VkExportSemaphoreCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkSemaphoreTypeCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSemaphoreCreateInfo_pnext_temp(cs);
            vn_decode_VkSemaphoreTypeCreateInfo_self_temp(cs, (VkSemaphoreTypeCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSemaphoreCreateInfo_self_temp(struct vn_cs *cs, VkSemaphoreCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
}

static inline void
vn_decode_VkSemaphoreCreateInfo_temp(struct vn_cs *cs, VkSemaphoreCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreCreateInfo_pnext_temp(cs);
    vn_decode_VkSemaphoreCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSemaphoreCreateInfo_handle_self(VkSemaphoreCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
}

static inline void
vn_replace_VkSemaphoreCreateInfo_handle(VkSemaphoreCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO:
            vn_replace_VkSemaphoreCreateInfo_handle_self((VkSemaphoreCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            vn_replace_VkExportSemaphoreCreateInfo_handle_self((VkExportSemaphoreCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            vn_replace_VkSemaphoreTypeCreateInfo_handle_self((VkSemaphoreTypeCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkQueryPoolCreateInfo chain */

static inline void *
vn_decode_VkQueryPoolCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkQueryPoolCreateInfo_self_temp(struct vn_cs *cs, VkQueryPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkQueryType(cs, &val->queryType);
    vn_decode_uint32_t(cs, &val->queryCount);
    vn_decode_VkFlags(cs, &val->pipelineStatistics);
}

static inline void
vn_decode_VkQueryPoolCreateInfo_temp(struct vn_cs *cs, VkQueryPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkQueryPoolCreateInfo_pnext_temp(cs);
    vn_decode_VkQueryPoolCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkQueryPoolCreateInfo_handle_self(VkQueryPoolCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->queryType */
    /* skip val->queryCount */
    /* skip val->pipelineStatistics */
}

static inline void
vn_replace_VkQueryPoolCreateInfo_handle(VkQueryPoolCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO:
            vn_replace_VkQueryPoolCreateInfo_handle_self((VkQueryPoolCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkFramebufferAttachmentImageInfo chain */

static inline void *
vn_decode_VkFramebufferAttachmentImageInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkFramebufferAttachmentImageInfo_self_temp(struct vn_cs *cs, VkFramebufferAttachmentImageInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkFlags(cs, &val->usage);
    vn_decode_uint32_t(cs, &val->width);
    vn_decode_uint32_t(cs, &val->height);
    vn_decode_uint32_t(cs, &val->layerCount);
    vn_decode_uint32_t(cs, &val->viewFormatCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->viewFormatCount);
        val->pViewFormats = vn_cs_alloc_temp(cs, sizeof(*val->pViewFormats) * array_size);
        if (!val->pViewFormats) return;
        vn_decode_VkFormat_array(cs, (VkFormat *)val->pViewFormats, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pViewFormats = NULL;
    }
}

static inline void
vn_decode_VkFramebufferAttachmentImageInfo_temp(struct vn_cs *cs, VkFramebufferAttachmentImageInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFramebufferAttachmentImageInfo_pnext_temp(cs);
    vn_decode_VkFramebufferAttachmentImageInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkFramebufferAttachmentImageInfo_handle_self(VkFramebufferAttachmentImageInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->usage */
    /* skip val->width */
    /* skip val->height */
    /* skip val->layerCount */
    /* skip val->viewFormatCount */
    /* skip val->pViewFormats */
}

static inline void
vn_replace_VkFramebufferAttachmentImageInfo_handle(VkFramebufferAttachmentImageInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO:
            vn_replace_VkFramebufferAttachmentImageInfo_handle_self((VkFramebufferAttachmentImageInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkFramebufferAttachmentsCreateInfo chain */

static inline void *
vn_decode_VkFramebufferAttachmentsCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkFramebufferAttachmentsCreateInfo_self_temp(struct vn_cs *cs, VkFramebufferAttachmentsCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->attachmentImageInfoCount);
    if (vn_peek_array_size(cs)) {
        val->pAttachmentImageInfos = vn_cs_alloc_temp(cs, sizeof(*val->pAttachmentImageInfos) * val->attachmentImageInfoCount);
        if (!val->pAttachmentImageInfos) return;
        vn_decode_array_size(cs, val->attachmentImageInfoCount);
        for (uint32_t i = 0; i < val->attachmentImageInfoCount; i++)
            vn_decode_VkFramebufferAttachmentImageInfo_temp(cs, &((VkFramebufferAttachmentImageInfo *)val->pAttachmentImageInfos)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pAttachmentImageInfos = NULL;
    }
}

static inline void
vn_decode_VkFramebufferAttachmentsCreateInfo_temp(struct vn_cs *cs, VkFramebufferAttachmentsCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFramebufferAttachmentsCreateInfo_pnext_temp(cs);
    vn_decode_VkFramebufferAttachmentsCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkFramebufferAttachmentsCreateInfo_handle_self(VkFramebufferAttachmentsCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->attachmentImageInfoCount */
    if (val->pAttachmentImageInfos) {
       for (uint32_t i = 0; i < val->attachmentImageInfoCount; i++)
            vn_replace_VkFramebufferAttachmentImageInfo_handle(&((VkFramebufferAttachmentImageInfo *)val->pAttachmentImageInfos)[i]);
    }
}

static inline void
vn_replace_VkFramebufferAttachmentsCreateInfo_handle(VkFramebufferAttachmentsCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            vn_replace_VkFramebufferAttachmentsCreateInfo_handle_self((VkFramebufferAttachmentsCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkFramebufferCreateInfo chain */

static inline void *
vn_decode_VkFramebufferCreateInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkFramebufferAttachmentsCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkFramebufferCreateInfo_pnext_temp(cs);
            vn_decode_VkFramebufferAttachmentsCreateInfo_self_temp(cs, (VkFramebufferAttachmentsCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkFramebufferCreateInfo_self_temp(struct vn_cs *cs, VkFramebufferCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkRenderPass_lookup(cs, &val->renderPass);
    vn_decode_uint32_t(cs, &val->attachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(cs, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkImageView_lookup(cs, &((VkImageView *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pAttachments = NULL;
    }
    vn_decode_uint32_t(cs, &val->width);
    vn_decode_uint32_t(cs, &val->height);
    vn_decode_uint32_t(cs, &val->layers);
}

static inline void
vn_decode_VkFramebufferCreateInfo_temp(struct vn_cs *cs, VkFramebufferCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFramebufferCreateInfo_pnext_temp(cs);
    vn_decode_VkFramebufferCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkFramebufferCreateInfo_handle_self(VkFramebufferCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    vn_replace_VkRenderPass_handle(&val->renderPass);
    /* skip val->attachmentCount */
    if (val->pAttachments) {
       for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_replace_VkImageView_handle(&((VkImageView *)val->pAttachments)[i]);
    }
    /* skip val->width */
    /* skip val->height */
    /* skip val->layers */
}

static inline void
vn_replace_VkFramebufferCreateInfo_handle(VkFramebufferCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO:
            vn_replace_VkFramebufferCreateInfo_handle_self((VkFramebufferCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            vn_replace_VkFramebufferAttachmentsCreateInfo_handle_self((VkFramebufferAttachmentsCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDrawIndirectCommand */

/* struct VkDrawIndexedIndirectCommand */

/* struct VkDispatchIndirectCommand */

/* struct VkDeviceGroupSubmitInfo chain */

static inline void *
vn_decode_VkDeviceGroupSubmitInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupSubmitInfo_self_temp(struct vn_cs *cs, VkDeviceGroupSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->waitSemaphoreCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->waitSemaphoreCount);
        val->pWaitSemaphoreDeviceIndices = vn_cs_alloc_temp(cs, sizeof(*val->pWaitSemaphoreDeviceIndices) * array_size);
        if (!val->pWaitSemaphoreDeviceIndices) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pWaitSemaphoreDeviceIndices, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pWaitSemaphoreDeviceIndices = NULL;
    }
    vn_decode_uint32_t(cs, &val->commandBufferCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->commandBufferCount);
        val->pCommandBufferDeviceMasks = vn_cs_alloc_temp(cs, sizeof(*val->pCommandBufferDeviceMasks) * array_size);
        if (!val->pCommandBufferDeviceMasks) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pCommandBufferDeviceMasks, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pCommandBufferDeviceMasks = NULL;
    }
    vn_decode_uint32_t(cs, &val->signalSemaphoreCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->signalSemaphoreCount);
        val->pSignalSemaphoreDeviceIndices = vn_cs_alloc_temp(cs, sizeof(*val->pSignalSemaphoreDeviceIndices) * array_size);
        if (!val->pSignalSemaphoreDeviceIndices) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pSignalSemaphoreDeviceIndices, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSignalSemaphoreDeviceIndices = NULL;
    }
}

static inline void
vn_decode_VkDeviceGroupSubmitInfo_temp(struct vn_cs *cs, VkDeviceGroupSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupSubmitInfo_pnext_temp(cs);
    vn_decode_VkDeviceGroupSubmitInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceGroupSubmitInfo_handle_self(VkDeviceGroupSubmitInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->waitSemaphoreCount */
    /* skip val->pWaitSemaphoreDeviceIndices */
    /* skip val->commandBufferCount */
    /* skip val->pCommandBufferDeviceMasks */
    /* skip val->signalSemaphoreCount */
    /* skip val->pSignalSemaphoreDeviceIndices */
}

static inline void
vn_replace_VkDeviceGroupSubmitInfo_handle(VkDeviceGroupSubmitInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            vn_replace_VkDeviceGroupSubmitInfo_handle_self((VkDeviceGroupSubmitInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkProtectedSubmitInfo chain */

static inline void *
vn_decode_VkProtectedSubmitInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkProtectedSubmitInfo_self_temp(struct vn_cs *cs, VkProtectedSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(cs, &val->protectedSubmit);
}

static inline void
vn_decode_VkProtectedSubmitInfo_temp(struct vn_cs *cs, VkProtectedSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkProtectedSubmitInfo_pnext_temp(cs);
    vn_decode_VkProtectedSubmitInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkProtectedSubmitInfo_handle_self(VkProtectedSubmitInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->protectedSubmit */
}

static inline void
vn_replace_VkProtectedSubmitInfo_handle(VkProtectedSubmitInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            vn_replace_VkProtectedSubmitInfo_handle_self((VkProtectedSubmitInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSubmitInfo chain */

static inline void *
vn_decode_VkSubmitInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDeviceGroupSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubmitInfo_pnext_temp(cs);
            vn_decode_VkDeviceGroupSubmitInfo_self_temp(cs, (VkDeviceGroupSubmitInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkProtectedSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubmitInfo_pnext_temp(cs);
            vn_decode_VkProtectedSubmitInfo_self_temp(cs, (VkProtectedSubmitInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkTimelineSemaphoreSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubmitInfo_pnext_temp(cs);
            vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(cs, (VkTimelineSemaphoreSubmitInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSubmitInfo_self_temp(struct vn_cs *cs, VkSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->waitSemaphoreCount);
    if (vn_peek_array_size(cs)) {
        val->pWaitSemaphores = vn_cs_alloc_temp(cs, sizeof(*val->pWaitSemaphores) * val->waitSemaphoreCount);
        if (!val->pWaitSemaphores) return;
        vn_decode_array_size(cs, val->waitSemaphoreCount);
        for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(cs, &((VkSemaphore *)val->pWaitSemaphores)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pWaitSemaphores = NULL;
    }
    if (vn_peek_array_size(cs)) {
        val->pWaitDstStageMask = vn_cs_alloc_temp(cs, sizeof(*val->pWaitDstStageMask) * val->waitSemaphoreCount);
        if (!val->pWaitDstStageMask) return;
        vn_decode_array_size(cs, val->waitSemaphoreCount);
        for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_decode_VkFlags(cs, &((VkPipelineStageFlags *)val->pWaitDstStageMask)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pWaitDstStageMask = NULL;
    }
    vn_decode_uint32_t(cs, &val->commandBufferCount);
    if (vn_peek_array_size(cs)) {
        val->pCommandBuffers = vn_cs_alloc_temp(cs, sizeof(*val->pCommandBuffers) * val->commandBufferCount);
        if (!val->pCommandBuffers) return;
        vn_decode_array_size(cs, val->commandBufferCount);
        for (uint32_t i = 0; i < val->commandBufferCount; i++)
            vn_decode_VkCommandBuffer_lookup(cs, &((VkCommandBuffer *)val->pCommandBuffers)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pCommandBuffers = NULL;
    }
    vn_decode_uint32_t(cs, &val->signalSemaphoreCount);
    if (vn_peek_array_size(cs)) {
        val->pSignalSemaphores = vn_cs_alloc_temp(cs, sizeof(*val->pSignalSemaphores) * val->signalSemaphoreCount);
        if (!val->pSignalSemaphores) return;
        vn_decode_array_size(cs, val->signalSemaphoreCount);
        for (uint32_t i = 0; i < val->signalSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(cs, &((VkSemaphore *)val->pSignalSemaphores)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSignalSemaphores = NULL;
    }
}

static inline void
vn_decode_VkSubmitInfo_temp(struct vn_cs *cs, VkSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSubmitInfo_pnext_temp(cs);
    vn_decode_VkSubmitInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSubmitInfo_handle_self(VkSubmitInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->waitSemaphoreCount */
    if (val->pWaitSemaphores) {
       for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_replace_VkSemaphore_handle(&((VkSemaphore *)val->pWaitSemaphores)[i]);
    }
    /* skip val->pWaitDstStageMask */
    /* skip val->commandBufferCount */
    if (val->pCommandBuffers) {
       for (uint32_t i = 0; i < val->commandBufferCount; i++)
            vn_replace_VkCommandBuffer_handle(&((VkCommandBuffer *)val->pCommandBuffers)[i]);
    }
    /* skip val->signalSemaphoreCount */
    if (val->pSignalSemaphores) {
       for (uint32_t i = 0; i < val->signalSemaphoreCount; i++)
            vn_replace_VkSemaphore_handle(&((VkSemaphore *)val->pSignalSemaphores)[i]);
    }
}

static inline void
vn_replace_VkSubmitInfo_handle(VkSubmitInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SUBMIT_INFO:
            vn_replace_VkSubmitInfo_handle_self((VkSubmitInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            vn_replace_VkDeviceGroupSubmitInfo_handle_self((VkDeviceGroupSubmitInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            vn_replace_VkProtectedSubmitInfo_handle_self((VkProtectedSubmitInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            vn_replace_VkTimelineSemaphoreSubmitInfo_handle_self((VkTimelineSemaphoreSubmitInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkConformanceVersion */

static inline void
vn_encode_VkConformanceVersion(struct vn_cs *cs, const VkConformanceVersion *val)
{
    vn_encode_uint8_t(cs, &val->major);
    vn_encode_uint8_t(cs, &val->minor);
    vn_encode_uint8_t(cs, &val->subminor);
    vn_encode_uint8_t(cs, &val->patch);
}

static inline void
vn_decode_VkConformanceVersion_partial_temp(struct vn_cs *cs, VkConformanceVersion *val)
{
    /* skip val->major */
    /* skip val->minor */
    /* skip val->subminor */
    /* skip val->patch */
}

/* struct VkPhysicalDeviceDriverProperties chain */

static inline void
vn_encode_VkPhysicalDeviceDriverProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDriverProperties_self(struct vn_cs *cs, const VkPhysicalDeviceDriverProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDriverId(cs, &val->driverID);
    vn_encode_array_size(cs, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_blob_array(cs, val->driverName, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_array_size(cs, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_blob_array(cs, val->driverInfo, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_VkConformanceVersion(cs, &val->conformanceVersion);
}

static inline void
vn_encode_VkPhysicalDeviceDriverProperties(struct vn_cs *cs, const VkPhysicalDeviceDriverProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES });
    vn_encode_VkPhysicalDeviceDriverProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceDriverProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDriverProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDriverProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDriverProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->driverID */
    /* skip val->driverName */
    /* skip val->driverInfo */
    vn_decode_VkConformanceVersion_partial_temp(cs, &val->conformanceVersion);
}

static inline void
vn_decode_VkPhysicalDeviceDriverProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDriverProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDriverProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceDriverProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceIDProperties chain */

static inline void
vn_encode_VkPhysicalDeviceIDProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceIDProperties_self(struct vn_cs *cs, const VkPhysicalDeviceIDProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_array_size(cs, VK_UUID_SIZE);
    vn_encode_uint8_t_array(cs, val->deviceUUID, VK_UUID_SIZE);
    vn_encode_array_size(cs, VK_UUID_SIZE);
    vn_encode_uint8_t_array(cs, val->driverUUID, VK_UUID_SIZE);
    vn_encode_array_size(cs, VK_LUID_SIZE);
    vn_encode_uint8_t_array(cs, val->deviceLUID, VK_LUID_SIZE);
    vn_encode_uint32_t(cs, &val->deviceNodeMask);
    vn_encode_VkBool32(cs, &val->deviceLUIDValid);
}

static inline void
vn_encode_VkPhysicalDeviceIDProperties(struct vn_cs *cs, const VkPhysicalDeviceIDProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES });
    vn_encode_VkPhysicalDeviceIDProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceIDProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceIDProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceIDProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceIDProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->deviceUUID */
    /* skip val->driverUUID */
    /* skip val->deviceLUID */
    /* skip val->deviceNodeMask */
    /* skip val->deviceLUIDValid */
}

static inline void
vn_decode_VkPhysicalDeviceIDProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceIDProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceIDProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceIDProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceMultiviewProperties chain */

static inline void
vn_encode_VkPhysicalDeviceMultiviewProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewProperties_self(struct vn_cs *cs, const VkPhysicalDeviceMultiviewProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->maxMultiviewViewCount);
    vn_encode_uint32_t(cs, &val->maxMultiviewInstanceIndex);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewProperties(struct vn_cs *cs, const VkPhysicalDeviceMultiviewProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES });
    vn_encode_VkPhysicalDeviceMultiviewProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceMultiviewProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMultiviewProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMultiviewProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxMultiviewViewCount */
    /* skip val->maxMultiviewInstanceIndex */
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMultiviewProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMultiviewProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceMultiviewProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceSubgroupProperties chain */

static inline void
vn_encode_VkPhysicalDeviceSubgroupProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSubgroupProperties_self(struct vn_cs *cs, const VkPhysicalDeviceSubgroupProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->subgroupSize);
    vn_encode_VkFlags(cs, &val->supportedStages);
    vn_encode_VkFlags(cs, &val->supportedOperations);
    vn_encode_VkBool32(cs, &val->quadOperationsInAllStages);
}

static inline void
vn_encode_VkPhysicalDeviceSubgroupProperties(struct vn_cs *cs, const VkPhysicalDeviceSubgroupProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES });
    vn_encode_VkPhysicalDeviceSubgroupProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceSubgroupProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSubgroupProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSubgroupProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSubgroupProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->subgroupSize */
    /* skip val->supportedStages */
    /* skip val->supportedOperations */
    /* skip val->quadOperationsInAllStages */
}

static inline void
vn_decode_VkPhysicalDeviceSubgroupProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSubgroupProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSubgroupProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceSubgroupProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDevicePointClippingProperties chain */

static inline void
vn_encode_VkPhysicalDevicePointClippingProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDevicePointClippingProperties_self(struct vn_cs *cs, const VkPhysicalDevicePointClippingProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPointClippingBehavior(cs, &val->pointClippingBehavior);
}

static inline void
vn_encode_VkPhysicalDevicePointClippingProperties(struct vn_cs *cs, const VkPhysicalDevicePointClippingProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES });
    vn_encode_VkPhysicalDevicePointClippingProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDevicePointClippingProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDevicePointClippingProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevicePointClippingProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDevicePointClippingProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->pointClippingBehavior */
}

static inline void
vn_decode_VkPhysicalDevicePointClippingProperties_partial_temp(struct vn_cs *cs, VkPhysicalDevicePointClippingProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevicePointClippingProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDevicePointClippingProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceProtectedMemoryProperties chain */

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryProperties_self(struct vn_cs *cs, const VkPhysicalDeviceProtectedMemoryProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->protectedNoFault);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryProperties(struct vn_cs *cs, const VkPhysicalDeviceProtectedMemoryProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES });
    vn_encode_VkPhysicalDeviceProtectedMemoryProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceProtectedMemoryProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProtectedMemoryProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceProtectedMemoryProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->protectedNoFault */
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceProtectedMemoryProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProtectedMemoryProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceProtectedMemoryProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceSamplerFilterMinmaxProperties chain */

static inline void
vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self(struct vn_cs *cs, const VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->filterMinmaxSingleComponentFormats);
    vn_encode_VkBool32(cs, &val->filterMinmaxImageComponentMapping);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties(struct vn_cs *cs, const VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES });
    vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->filterMinmaxSingleComponentFormats */
    /* skip val->filterMinmaxImageComponentMapping */
}

static inline void
vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceMaintenance3Properties chain */

static inline void
vn_encode_VkPhysicalDeviceMaintenance3Properties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMaintenance3Properties_self(struct vn_cs *cs, const VkPhysicalDeviceMaintenance3Properties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->maxPerSetDescriptors);
    vn_encode_VkDeviceSize(cs, &val->maxMemoryAllocationSize);
}

static inline void
vn_encode_VkPhysicalDeviceMaintenance3Properties(struct vn_cs *cs, const VkPhysicalDeviceMaintenance3Properties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES });
    vn_encode_VkPhysicalDeviceMaintenance3Properties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceMaintenance3Properties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMaintenance3Properties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMaintenance3Properties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMaintenance3Properties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxPerSetDescriptors */
    /* skip val->maxMemoryAllocationSize */
}

static inline void
vn_decode_VkPhysicalDeviceMaintenance3Properties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMaintenance3Properties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMaintenance3Properties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceMaintenance3Properties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceFloatControlsProperties chain */

static inline void
vn_encode_VkPhysicalDeviceFloatControlsProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceFloatControlsProperties_self(struct vn_cs *cs, const VkPhysicalDeviceFloatControlsProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkShaderFloatControlsIndependence(cs, &val->denormBehaviorIndependence);
    vn_encode_VkShaderFloatControlsIndependence(cs, &val->roundingModeIndependence);
    vn_encode_VkBool32(cs, &val->shaderSignedZeroInfNanPreserveFloat16);
    vn_encode_VkBool32(cs, &val->shaderSignedZeroInfNanPreserveFloat32);
    vn_encode_VkBool32(cs, &val->shaderSignedZeroInfNanPreserveFloat64);
    vn_encode_VkBool32(cs, &val->shaderDenormPreserveFloat16);
    vn_encode_VkBool32(cs, &val->shaderDenormPreserveFloat32);
    vn_encode_VkBool32(cs, &val->shaderDenormPreserveFloat64);
    vn_encode_VkBool32(cs, &val->shaderDenormFlushToZeroFloat16);
    vn_encode_VkBool32(cs, &val->shaderDenormFlushToZeroFloat32);
    vn_encode_VkBool32(cs, &val->shaderDenormFlushToZeroFloat64);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTEFloat16);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTEFloat32);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTEFloat64);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTZFloat16);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTZFloat32);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTZFloat64);
}

static inline void
vn_encode_VkPhysicalDeviceFloatControlsProperties(struct vn_cs *cs, const VkPhysicalDeviceFloatControlsProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES });
    vn_encode_VkPhysicalDeviceFloatControlsProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceFloatControlsProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceFloatControlsProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceFloatControlsProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceFloatControlsProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->denormBehaviorIndependence */
    /* skip val->roundingModeIndependence */
    /* skip val->shaderSignedZeroInfNanPreserveFloat16 */
    /* skip val->shaderSignedZeroInfNanPreserveFloat32 */
    /* skip val->shaderSignedZeroInfNanPreserveFloat64 */
    /* skip val->shaderDenormPreserveFloat16 */
    /* skip val->shaderDenormPreserveFloat32 */
    /* skip val->shaderDenormPreserveFloat64 */
    /* skip val->shaderDenormFlushToZeroFloat16 */
    /* skip val->shaderDenormFlushToZeroFloat32 */
    /* skip val->shaderDenormFlushToZeroFloat64 */
    /* skip val->shaderRoundingModeRTEFloat16 */
    /* skip val->shaderRoundingModeRTEFloat32 */
    /* skip val->shaderRoundingModeRTEFloat64 */
    /* skip val->shaderRoundingModeRTZFloat16 */
    /* skip val->shaderRoundingModeRTZFloat32 */
    /* skip val->shaderRoundingModeRTZFloat64 */
}

static inline void
vn_decode_VkPhysicalDeviceFloatControlsProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceFloatControlsProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceFloatControlsProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceFloatControlsProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceDescriptorIndexingProperties chain */

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_self(struct vn_cs *cs, const VkPhysicalDeviceDescriptorIndexingProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->maxUpdateAfterBindDescriptorsInAllPools);
    vn_encode_VkBool32(cs, &val->shaderUniformBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderSampledImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderStorageBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderStorageImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderInputAttachmentArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->robustBufferAccessUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->quadDivergentImplicitLod);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindSamplers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindSampledImages);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindStorageImages);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindInputAttachments);
    vn_encode_uint32_t(cs, &val->maxPerStageUpdateAfterBindResources);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindSamplers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindSampledImages);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindStorageImages);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindInputAttachments);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingProperties(struct vn_cs *cs, const VkPhysicalDeviceDescriptorIndexingProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES });
    vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDescriptorIndexingProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxUpdateAfterBindDescriptorsInAllPools */
    /* skip val->shaderUniformBufferArrayNonUniformIndexingNative */
    /* skip val->shaderSampledImageArrayNonUniformIndexingNative */
    /* skip val->shaderStorageBufferArrayNonUniformIndexingNative */
    /* skip val->shaderStorageImageArrayNonUniformIndexingNative */
    /* skip val->shaderInputAttachmentArrayNonUniformIndexingNative */
    /* skip val->robustBufferAccessUpdateAfterBind */
    /* skip val->quadDivergentImplicitLod */
    /* skip val->maxPerStageDescriptorUpdateAfterBindSamplers */
    /* skip val->maxPerStageDescriptorUpdateAfterBindUniformBuffers */
    /* skip val->maxPerStageDescriptorUpdateAfterBindStorageBuffers */
    /* skip val->maxPerStageDescriptorUpdateAfterBindSampledImages */
    /* skip val->maxPerStageDescriptorUpdateAfterBindStorageImages */
    /* skip val->maxPerStageDescriptorUpdateAfterBindInputAttachments */
    /* skip val->maxPerStageUpdateAfterBindResources */
    /* skip val->maxDescriptorSetUpdateAfterBindSamplers */
    /* skip val->maxDescriptorSetUpdateAfterBindUniformBuffers */
    /* skip val->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic */
    /* skip val->maxDescriptorSetUpdateAfterBindStorageBuffers */
    /* skip val->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic */
    /* skip val->maxDescriptorSetUpdateAfterBindSampledImages */
    /* skip val->maxDescriptorSetUpdateAfterBindStorageImages */
    /* skip val->maxDescriptorSetUpdateAfterBindInputAttachments */
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDescriptorIndexingProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceTimelineSemaphoreProperties chain */

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_self(struct vn_cs *cs, const VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint64_t(cs, &val->maxTimelineSemaphoreValueDifference);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties(struct vn_cs *cs, const VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES });
    vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxTimelineSemaphoreValueDifference */
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceDepthStencilResolveProperties chain */

static inline void
vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_self(struct vn_cs *cs, const VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(cs, &val->supportedDepthResolveModes);
    vn_encode_VkFlags(cs, &val->supportedStencilResolveModes);
    vn_encode_VkBool32(cs, &val->independentResolveNone);
    vn_encode_VkBool32(cs, &val->independentResolve);
}

static inline void
vn_encode_VkPhysicalDeviceDepthStencilResolveProperties(struct vn_cs *cs, const VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES });
    vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->supportedDepthResolveModes */
    /* skip val->supportedStencilResolveModes */
    /* skip val->independentResolveNone */
    /* skip val->independentResolve */
}

static inline void
vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceTransformFeedbackPropertiesEXT chain */

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self(struct vn_cs *cs, const VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->maxTransformFeedbackStreams);
    vn_encode_uint32_t(cs, &val->maxTransformFeedbackBuffers);
    vn_encode_VkDeviceSize(cs, &val->maxTransformFeedbackBufferSize);
    vn_encode_uint32_t(cs, &val->maxTransformFeedbackStreamDataSize);
    vn_encode_uint32_t(cs, &val->maxTransformFeedbackBufferDataSize);
    vn_encode_uint32_t(cs, &val->maxTransformFeedbackBufferDataStride);
    vn_encode_VkBool32(cs, &val->transformFeedbackQueries);
    vn_encode_VkBool32(cs, &val->transformFeedbackStreamsLinesTriangles);
    vn_encode_VkBool32(cs, &val->transformFeedbackRasterizationStreamSelect);
    vn_encode_VkBool32(cs, &val->transformFeedbackDraw);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT(struct vn_cs *cs, const VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT });
    vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxTransformFeedbackStreams */
    /* skip val->maxTransformFeedbackBuffers */
    /* skip val->maxTransformFeedbackBufferSize */
    /* skip val->maxTransformFeedbackStreamDataSize */
    /* skip val->maxTransformFeedbackBufferDataSize */
    /* skip val->maxTransformFeedbackBufferDataStride */
    /* skip val->transformFeedbackQueries */
    /* skip val->transformFeedbackStreamsLinesTriangles */
    /* skip val->transformFeedbackRasterizationStreamSelect */
    /* skip val->transformFeedbackDraw */
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_partial_temp(struct vn_cs *cs, VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceVulkan11Properties chain */

static inline void
vn_encode_VkPhysicalDeviceVulkan11Properties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Properties_self(struct vn_cs *cs, const VkPhysicalDeviceVulkan11Properties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_array_size(cs, VK_UUID_SIZE);
    vn_encode_uint8_t_array(cs, val->deviceUUID, VK_UUID_SIZE);
    vn_encode_array_size(cs, VK_UUID_SIZE);
    vn_encode_uint8_t_array(cs, val->driverUUID, VK_UUID_SIZE);
    vn_encode_array_size(cs, VK_LUID_SIZE);
    vn_encode_uint8_t_array(cs, val->deviceLUID, VK_LUID_SIZE);
    vn_encode_uint32_t(cs, &val->deviceNodeMask);
    vn_encode_VkBool32(cs, &val->deviceLUIDValid);
    vn_encode_uint32_t(cs, &val->subgroupSize);
    vn_encode_VkFlags(cs, &val->subgroupSupportedStages);
    vn_encode_VkFlags(cs, &val->subgroupSupportedOperations);
    vn_encode_VkBool32(cs, &val->subgroupQuadOperationsInAllStages);
    vn_encode_VkPointClippingBehavior(cs, &val->pointClippingBehavior);
    vn_encode_uint32_t(cs, &val->maxMultiviewViewCount);
    vn_encode_uint32_t(cs, &val->maxMultiviewInstanceIndex);
    vn_encode_VkBool32(cs, &val->protectedNoFault);
    vn_encode_uint32_t(cs, &val->maxPerSetDescriptors);
    vn_encode_VkDeviceSize(cs, &val->maxMemoryAllocationSize);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Properties(struct vn_cs *cs, const VkPhysicalDeviceVulkan11Properties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES });
    vn_encode_VkPhysicalDeviceVulkan11Properties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan11Properties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan11Properties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Properties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan11Properties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->deviceUUID */
    /* skip val->driverUUID */
    /* skip val->deviceLUID */
    /* skip val->deviceNodeMask */
    /* skip val->deviceLUIDValid */
    /* skip val->subgroupSize */
    /* skip val->subgroupSupportedStages */
    /* skip val->subgroupSupportedOperations */
    /* skip val->subgroupQuadOperationsInAllStages */
    /* skip val->pointClippingBehavior */
    /* skip val->maxMultiviewViewCount */
    /* skip val->maxMultiviewInstanceIndex */
    /* skip val->protectedNoFault */
    /* skip val->maxPerSetDescriptors */
    /* skip val->maxMemoryAllocationSize */
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Properties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan11Properties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan11Properties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceVulkan11Properties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceVulkan12Properties chain */

static inline void
vn_encode_VkPhysicalDeviceVulkan12Properties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Properties_self(struct vn_cs *cs, const VkPhysicalDeviceVulkan12Properties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDriverId(cs, &val->driverID);
    vn_encode_array_size(cs, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_blob_array(cs, val->driverName, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_array_size(cs, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_blob_array(cs, val->driverInfo, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_VkConformanceVersion(cs, &val->conformanceVersion);
    vn_encode_VkShaderFloatControlsIndependence(cs, &val->denormBehaviorIndependence);
    vn_encode_VkShaderFloatControlsIndependence(cs, &val->roundingModeIndependence);
    vn_encode_VkBool32(cs, &val->shaderSignedZeroInfNanPreserveFloat16);
    vn_encode_VkBool32(cs, &val->shaderSignedZeroInfNanPreserveFloat32);
    vn_encode_VkBool32(cs, &val->shaderSignedZeroInfNanPreserveFloat64);
    vn_encode_VkBool32(cs, &val->shaderDenormPreserveFloat16);
    vn_encode_VkBool32(cs, &val->shaderDenormPreserveFloat32);
    vn_encode_VkBool32(cs, &val->shaderDenormPreserveFloat64);
    vn_encode_VkBool32(cs, &val->shaderDenormFlushToZeroFloat16);
    vn_encode_VkBool32(cs, &val->shaderDenormFlushToZeroFloat32);
    vn_encode_VkBool32(cs, &val->shaderDenormFlushToZeroFloat64);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTEFloat16);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTEFloat32);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTEFloat64);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTZFloat16);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTZFloat32);
    vn_encode_VkBool32(cs, &val->shaderRoundingModeRTZFloat64);
    vn_encode_uint32_t(cs, &val->maxUpdateAfterBindDescriptorsInAllPools);
    vn_encode_VkBool32(cs, &val->shaderUniformBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderSampledImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderStorageBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderStorageImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->shaderInputAttachmentArrayNonUniformIndexingNative);
    vn_encode_VkBool32(cs, &val->robustBufferAccessUpdateAfterBind);
    vn_encode_VkBool32(cs, &val->quadDivergentImplicitLod);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindSamplers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindSampledImages);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindStorageImages);
    vn_encode_uint32_t(cs, &val->maxPerStageDescriptorUpdateAfterBindInputAttachments);
    vn_encode_uint32_t(cs, &val->maxPerStageUpdateAfterBindResources);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindSamplers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindSampledImages);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindStorageImages);
    vn_encode_uint32_t(cs, &val->maxDescriptorSetUpdateAfterBindInputAttachments);
    vn_encode_VkFlags(cs, &val->supportedDepthResolveModes);
    vn_encode_VkFlags(cs, &val->supportedStencilResolveModes);
    vn_encode_VkBool32(cs, &val->independentResolveNone);
    vn_encode_VkBool32(cs, &val->independentResolve);
    vn_encode_VkBool32(cs, &val->filterMinmaxSingleComponentFormats);
    vn_encode_VkBool32(cs, &val->filterMinmaxImageComponentMapping);
    vn_encode_uint64_t(cs, &val->maxTimelineSemaphoreValueDifference);
    vn_encode_VkFlags(cs, &val->framebufferIntegerColorSampleCounts);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Properties(struct vn_cs *cs, const VkPhysicalDeviceVulkan12Properties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES });
    vn_encode_VkPhysicalDeviceVulkan12Properties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan12Properties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan12Properties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Properties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan12Properties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->driverID */
    /* skip val->driverName */
    /* skip val->driverInfo */
    vn_decode_VkConformanceVersion_partial_temp(cs, &val->conformanceVersion);
    /* skip val->denormBehaviorIndependence */
    /* skip val->roundingModeIndependence */
    /* skip val->shaderSignedZeroInfNanPreserveFloat16 */
    /* skip val->shaderSignedZeroInfNanPreserveFloat32 */
    /* skip val->shaderSignedZeroInfNanPreserveFloat64 */
    /* skip val->shaderDenormPreserveFloat16 */
    /* skip val->shaderDenormPreserveFloat32 */
    /* skip val->shaderDenormPreserveFloat64 */
    /* skip val->shaderDenormFlushToZeroFloat16 */
    /* skip val->shaderDenormFlushToZeroFloat32 */
    /* skip val->shaderDenormFlushToZeroFloat64 */
    /* skip val->shaderRoundingModeRTEFloat16 */
    /* skip val->shaderRoundingModeRTEFloat32 */
    /* skip val->shaderRoundingModeRTEFloat64 */
    /* skip val->shaderRoundingModeRTZFloat16 */
    /* skip val->shaderRoundingModeRTZFloat32 */
    /* skip val->shaderRoundingModeRTZFloat64 */
    /* skip val->maxUpdateAfterBindDescriptorsInAllPools */
    /* skip val->shaderUniformBufferArrayNonUniformIndexingNative */
    /* skip val->shaderSampledImageArrayNonUniformIndexingNative */
    /* skip val->shaderStorageBufferArrayNonUniformIndexingNative */
    /* skip val->shaderStorageImageArrayNonUniformIndexingNative */
    /* skip val->shaderInputAttachmentArrayNonUniformIndexingNative */
    /* skip val->robustBufferAccessUpdateAfterBind */
    /* skip val->quadDivergentImplicitLod */
    /* skip val->maxPerStageDescriptorUpdateAfterBindSamplers */
    /* skip val->maxPerStageDescriptorUpdateAfterBindUniformBuffers */
    /* skip val->maxPerStageDescriptorUpdateAfterBindStorageBuffers */
    /* skip val->maxPerStageDescriptorUpdateAfterBindSampledImages */
    /* skip val->maxPerStageDescriptorUpdateAfterBindStorageImages */
    /* skip val->maxPerStageDescriptorUpdateAfterBindInputAttachments */
    /* skip val->maxPerStageUpdateAfterBindResources */
    /* skip val->maxDescriptorSetUpdateAfterBindSamplers */
    /* skip val->maxDescriptorSetUpdateAfterBindUniformBuffers */
    /* skip val->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic */
    /* skip val->maxDescriptorSetUpdateAfterBindStorageBuffers */
    /* skip val->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic */
    /* skip val->maxDescriptorSetUpdateAfterBindSampledImages */
    /* skip val->maxDescriptorSetUpdateAfterBindStorageImages */
    /* skip val->maxDescriptorSetUpdateAfterBindInputAttachments */
    /* skip val->supportedDepthResolveModes */
    /* skip val->supportedStencilResolveModes */
    /* skip val->independentResolveNone */
    /* skip val->independentResolve */
    /* skip val->filterMinmaxSingleComponentFormats */
    /* skip val->filterMinmaxImageComponentMapping */
    /* skip val->maxTimelineSemaphoreValueDifference */
    /* skip val->framebufferIntegerColorSampleCounts */
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Properties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceVulkan12Properties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan12Properties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceVulkan12Properties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceProperties2 chain */

static inline void
vn_encode_VkPhysicalDeviceProperties2_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceDriverProperties_self(cs, (const VkPhysicalDeviceDriverProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceIDProperties_self(cs, (const VkPhysicalDeviceIDProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceMultiviewProperties_self(cs, (const VkPhysicalDeviceMultiviewProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceSubgroupProperties_self(cs, (const VkPhysicalDeviceSubgroupProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDevicePointClippingProperties_self(cs, (const VkPhysicalDevicePointClippingProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceProtectedMemoryProperties_self(cs, (const VkPhysicalDeviceProtectedMemoryProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self(cs, (const VkPhysicalDeviceSamplerFilterMinmaxProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceMaintenance3Properties_self(cs, (const VkPhysicalDeviceMaintenance3Properties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceFloatControlsProperties_self(cs, (const VkPhysicalDeviceFloatControlsProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_self(cs, (const VkPhysicalDeviceDescriptorIndexingProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_self(cs, (const VkPhysicalDeviceTimelineSemaphoreProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_self(cs, (const VkPhysicalDeviceDepthStencilResolveProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self(cs, (const VkPhysicalDeviceTransformFeedbackPropertiesEXT *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan11Properties_self(cs, (const VkPhysicalDeviceVulkan11Properties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan12Properties_self(cs, (const VkPhysicalDeviceVulkan12Properties *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceProperties2_self(struct vn_cs *cs, const VkPhysicalDeviceProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPhysicalDeviceProperties(cs, &val->properties);
}

static inline void
vn_encode_VkPhysicalDeviceProperties2(struct vn_cs *cs, const VkPhysicalDeviceProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2 });
    vn_encode_VkPhysicalDeviceProperties2_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceProperties2_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceDriverProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceDriverProperties_self_partial_temp(cs, (VkPhysicalDeviceDriverProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceIDProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceIDProperties_self_partial_temp(cs, (VkPhysicalDeviceIDProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceMultiviewProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceMultiviewProperties_self_partial_temp(cs, (VkPhysicalDeviceMultiviewProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSubgroupProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceSubgroupProperties_self_partial_temp(cs, (VkPhysicalDeviceSubgroupProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDevicePointClippingProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDevicePointClippingProperties_self_partial_temp(cs, (VkPhysicalDevicePointClippingProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceProtectedMemoryProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceProtectedMemoryProperties_self_partial_temp(cs, (VkPhysicalDeviceProtectedMemoryProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceSamplerFilterMinmaxProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self_partial_temp(cs, (VkPhysicalDeviceSamplerFilterMinmaxProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceMaintenance3Properties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceMaintenance3Properties_self_partial_temp(cs, (VkPhysicalDeviceMaintenance3Properties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceFloatControlsProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceFloatControlsProperties_self_partial_temp(cs, (VkPhysicalDeviceFloatControlsProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceDescriptorIndexingProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_self_partial_temp(cs, (VkPhysicalDeviceDescriptorIndexingProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTimelineSemaphoreProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_self_partial_temp(cs, (VkPhysicalDeviceTimelineSemaphoreProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceDepthStencilResolveProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_self_partial_temp(cs, (VkPhysicalDeviceDepthStencilResolveProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self_partial_temp(cs, (VkPhysicalDeviceTransformFeedbackPropertiesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan11Properties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan11Properties_self_partial_temp(cs, (VkPhysicalDeviceVulkan11Properties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceVulkan12Properties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
            vn_decode_VkPhysicalDeviceVulkan12Properties_self_partial_temp(cs, (VkPhysicalDeviceVulkan12Properties *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceProperties2_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceProperties_partial_temp(cs, &val->properties);
}

static inline void
vn_decode_VkPhysicalDeviceProperties2_partial_temp(struct vn_cs *cs, VkPhysicalDeviceProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceProperties2_self_partial_temp(cs, val);
}

/* struct VkDrmFormatModifierPropertiesEXT */

static inline void
vn_encode_VkDrmFormatModifierPropertiesEXT(struct vn_cs *cs, const VkDrmFormatModifierPropertiesEXT *val)
{
    vn_encode_uint64_t(cs, &val->drmFormatModifier);
    vn_encode_uint32_t(cs, &val->drmFormatModifierPlaneCount);
    vn_encode_VkFlags(cs, &val->drmFormatModifierTilingFeatures);
}

static inline void
vn_decode_VkDrmFormatModifierPropertiesEXT_partial_temp(struct vn_cs *cs, VkDrmFormatModifierPropertiesEXT *val)
{
    /* skip val->drmFormatModifier */
    /* skip val->drmFormatModifierPlaneCount */
    /* skip val->drmFormatModifierTilingFeatures */
}

/* struct VkDrmFormatModifierPropertiesListEXT chain */

static inline void
vn_encode_VkDrmFormatModifierPropertiesListEXT_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkDrmFormatModifierPropertiesListEXT_self(struct vn_cs *cs, const VkDrmFormatModifierPropertiesListEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->drmFormatModifierCount);
    if (val->pDrmFormatModifierProperties) {
        vn_encode_array_size(cs, val->drmFormatModifierCount);
        for (uint32_t i = 0; i < val->drmFormatModifierCount; i++)
            vn_encode_VkDrmFormatModifierPropertiesEXT(cs, &val->pDrmFormatModifierProperties[i]);
    } else {
        vn_encode_array_size(cs, 0);
    }
}

static inline void
vn_encode_VkDrmFormatModifierPropertiesListEXT(struct vn_cs *cs, const VkDrmFormatModifierPropertiesListEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT });
    vn_encode_VkDrmFormatModifierPropertiesListEXT_pnext(cs, val->pNext);
    vn_encode_VkDrmFormatModifierPropertiesListEXT_self(cs, val);
}

static inline void *
vn_decode_VkDrmFormatModifierPropertiesListEXT_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDrmFormatModifierPropertiesListEXT_self_partial_temp(struct vn_cs *cs, VkDrmFormatModifierPropertiesListEXT *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->drmFormatModifierCount */
    if (vn_peek_array_size(cs)) {
        val->pDrmFormatModifierProperties = vn_cs_alloc_temp(cs, sizeof(*val->pDrmFormatModifierProperties) * val->drmFormatModifierCount);
        if (!val->pDrmFormatModifierProperties) return;
        vn_decode_array_size(cs, val->drmFormatModifierCount);
        for (uint32_t i = 0; i < val->drmFormatModifierCount; i++)
            vn_decode_VkDrmFormatModifierPropertiesEXT_partial_temp(cs, &val->pDrmFormatModifierProperties[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDrmFormatModifierProperties = NULL;
    }
}

static inline void
vn_decode_VkDrmFormatModifierPropertiesListEXT_partial_temp(struct vn_cs *cs, VkDrmFormatModifierPropertiesListEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkDrmFormatModifierPropertiesListEXT_pnext_partial_temp(cs);
    vn_decode_VkDrmFormatModifierPropertiesListEXT_self_partial_temp(cs, val);
}

/* struct VkFormatProperties2 chain */

static inline void
vn_encode_VkFormatProperties2_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkFormatProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkDrmFormatModifierPropertiesListEXT_self(cs, (const VkDrmFormatModifierPropertiesListEXT *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkFormatProperties2_self(struct vn_cs *cs, const VkFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFormatProperties(cs, &val->formatProperties);
}

static inline void
vn_encode_VkFormatProperties2(struct vn_cs *cs, const VkFormatProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2 });
    vn_encode_VkFormatProperties2_pnext(cs, val->pNext);
    vn_encode_VkFormatProperties2_self(cs, val);
}

static inline void *
vn_decode_VkFormatProperties2_pnext_partial_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDrmFormatModifierPropertiesListEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkFormatProperties2_pnext_partial_temp(cs);
            vn_decode_VkDrmFormatModifierPropertiesListEXT_self_partial_temp(cs, (VkDrmFormatModifierPropertiesListEXT *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkFormatProperties2_self_partial_temp(struct vn_cs *cs, VkFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormatProperties_partial_temp(cs, &val->formatProperties);
}

static inline void
vn_decode_VkFormatProperties2_partial_temp(struct vn_cs *cs, VkFormatProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkFormatProperties2_pnext_partial_temp(cs);
    vn_decode_VkFormatProperties2_self_partial_temp(cs, val);
}

/* struct VkExternalMemoryProperties */

static inline void
vn_encode_VkExternalMemoryProperties(struct vn_cs *cs, const VkExternalMemoryProperties *val)
{
    vn_encode_VkFlags(cs, &val->externalMemoryFeatures);
    vn_encode_VkFlags(cs, &val->exportFromImportedHandleTypes);
    vn_encode_VkFlags(cs, &val->compatibleHandleTypes);
}

static inline void
vn_decode_VkExternalMemoryProperties_partial_temp(struct vn_cs *cs, VkExternalMemoryProperties *val)
{
    /* skip val->externalMemoryFeatures */
    /* skip val->exportFromImportedHandleTypes */
    /* skip val->compatibleHandleTypes */
}

/* struct VkExternalImageFormatProperties chain */

static inline void
vn_encode_VkExternalImageFormatProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkExternalImageFormatProperties_self(struct vn_cs *cs, const VkExternalImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkExternalMemoryProperties(cs, &val->externalMemoryProperties);
}

static inline void
vn_encode_VkExternalImageFormatProperties(struct vn_cs *cs, const VkExternalImageFormatProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES });
    vn_encode_VkExternalImageFormatProperties_pnext(cs, val->pNext);
    vn_encode_VkExternalImageFormatProperties_self(cs, val);
}

static inline void *
vn_decode_VkExternalImageFormatProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExternalImageFormatProperties_self_partial_temp(struct vn_cs *cs, VkExternalImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalMemoryProperties_partial_temp(cs, &val->externalMemoryProperties);
}

static inline void
vn_decode_VkExternalImageFormatProperties_partial_temp(struct vn_cs *cs, VkExternalImageFormatProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalImageFormatProperties_pnext_partial_temp(cs);
    vn_decode_VkExternalImageFormatProperties_self_partial_temp(cs, val);
}

/* struct VkSamplerYcbcrConversionImageFormatProperties chain */

static inline void
vn_encode_VkSamplerYcbcrConversionImageFormatProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkSamplerYcbcrConversionImageFormatProperties_self(struct vn_cs *cs, const VkSamplerYcbcrConversionImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->combinedImageSamplerDescriptorCount);
}

static inline void
vn_encode_VkSamplerYcbcrConversionImageFormatProperties(struct vn_cs *cs, const VkSamplerYcbcrConversionImageFormatProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES });
    vn_encode_VkSamplerYcbcrConversionImageFormatProperties_pnext(cs, val->pNext);
    vn_encode_VkSamplerYcbcrConversionImageFormatProperties_self(cs, val);
}

static inline void *
vn_decode_VkSamplerYcbcrConversionImageFormatProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSamplerYcbcrConversionImageFormatProperties_self_partial_temp(struct vn_cs *cs, VkSamplerYcbcrConversionImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->combinedImageSamplerDescriptorCount */
}

static inline void
vn_decode_VkSamplerYcbcrConversionImageFormatProperties_partial_temp(struct vn_cs *cs, VkSamplerYcbcrConversionImageFormatProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerYcbcrConversionImageFormatProperties_pnext_partial_temp(cs);
    vn_decode_VkSamplerYcbcrConversionImageFormatProperties_self_partial_temp(cs, val);
}

/* struct VkImageFormatProperties2 chain */

static inline void
vn_encode_VkImageFormatProperties2_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkImageFormatProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkExternalImageFormatProperties_self(cs, (const VkExternalImageFormatProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkImageFormatProperties2_pnext(cs, pnext->pNext);
            vn_encode_VkSamplerYcbcrConversionImageFormatProperties_self(cs, (const VkSamplerYcbcrConversionImageFormatProperties *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkImageFormatProperties2_self(struct vn_cs *cs, const VkImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkImageFormatProperties(cs, &val->imageFormatProperties);
}

static inline void
vn_encode_VkImageFormatProperties2(struct vn_cs *cs, const VkImageFormatProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2 });
    vn_encode_VkImageFormatProperties2_pnext(cs, val->pNext);
    vn_encode_VkImageFormatProperties2_self(cs, val);
}

static inline void *
vn_decode_VkImageFormatProperties2_pnext_partial_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkExternalImageFormatProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageFormatProperties2_pnext_partial_temp(cs);
            vn_decode_VkExternalImageFormatProperties_self_partial_temp(cs, (VkExternalImageFormatProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkSamplerYcbcrConversionImageFormatProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageFormatProperties2_pnext_partial_temp(cs);
            vn_decode_VkSamplerYcbcrConversionImageFormatProperties_self_partial_temp(cs, (VkSamplerYcbcrConversionImageFormatProperties *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageFormatProperties2_self_partial_temp(struct vn_cs *cs, VkImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageFormatProperties_partial_temp(cs, &val->imageFormatProperties);
}

static inline void
vn_decode_VkImageFormatProperties2_partial_temp(struct vn_cs *cs, VkImageFormatProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkImageFormatProperties2_pnext_partial_temp(cs);
    vn_decode_VkImageFormatProperties2_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceExternalImageFormatInfo chain */

static inline void *
vn_decode_VkPhysicalDeviceExternalImageFormatInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceExternalImageFormatInfo_self_temp(struct vn_cs *cs, VkPhysicalDeviceExternalImageFormatInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalMemoryHandleTypeFlagBits(cs, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalImageFormatInfo_temp(struct vn_cs *cs, VkPhysicalDeviceExternalImageFormatInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalImageFormatInfo_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceExternalImageFormatInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceExternalImageFormatInfo_handle_self(VkPhysicalDeviceExternalImageFormatInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleType */
}

static inline void
vn_replace_VkPhysicalDeviceExternalImageFormatInfo_handle(VkPhysicalDeviceExternalImageFormatInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            vn_replace_VkPhysicalDeviceExternalImageFormatInfo_handle_self((VkPhysicalDeviceExternalImageFormatInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceImageDrmFormatModifierInfoEXT chain */

static inline void *
vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_self_temp(struct vn_cs *cs, VkPhysicalDeviceImageDrmFormatModifierInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(cs, &val->drmFormatModifier);
    vn_decode_VkSharingMode(cs, &val->sharingMode);
    vn_decode_uint32_t(cs, &val->queueFamilyIndexCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->queueFamilyIndexCount);
        val->pQueueFamilyIndices = vn_cs_alloc_temp(cs, sizeof(*val->pQueueFamilyIndices) * array_size);
        if (!val->pQueueFamilyIndices) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pQueueFamilyIndices, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pQueueFamilyIndices = NULL;
    }
}

static inline void
vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_temp(struct vn_cs *cs, VkPhysicalDeviceImageDrmFormatModifierInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_self_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_handle_self(VkPhysicalDeviceImageDrmFormatModifierInfoEXT *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->drmFormatModifier */
    /* skip val->sharingMode */
    /* skip val->queueFamilyIndexCount */
    /* skip val->pQueueFamilyIndices */
}

static inline void
vn_replace_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_handle(VkPhysicalDeviceImageDrmFormatModifierInfoEXT *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            vn_replace_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_handle_self((VkPhysicalDeviceImageDrmFormatModifierInfoEXT *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceImageFormatInfo2 chain */

static inline void *
vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceExternalImageFormatInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceExternalImageFormatInfo_self_temp(cs, (VkPhysicalDeviceExternalImageFormatInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImageFormatListCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(cs);
            vn_decode_VkImageFormatListCreateInfo_self_temp(cs, (VkImageFormatListCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkPhysicalDeviceImageDrmFormatModifierInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(cs);
            vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_self_temp(cs, (VkPhysicalDeviceImageDrmFormatModifierInfoEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImageStencilUsageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(cs);
            vn_decode_VkImageStencilUsageCreateInfo_self_temp(cs, (VkImageStencilUsageCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceImageFormatInfo2_self_temp(struct vn_cs *cs, VkPhysicalDeviceImageFormatInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkImageType(cs, &val->type);
    vn_decode_VkImageTiling(cs, &val->tiling);
    vn_decode_VkFlags(cs, &val->usage);
    vn_decode_VkFlags(cs, &val->flags);
}

static inline void
vn_decode_VkPhysicalDeviceImageFormatInfo2_temp(struct vn_cs *cs, VkPhysicalDeviceImageFormatInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceImageFormatInfo2_self_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceImageFormatInfo2_handle_self(VkPhysicalDeviceImageFormatInfo2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->format */
    /* skip val->type */
    /* skip val->tiling */
    /* skip val->usage */
    /* skip val->flags */
}

static inline void
vn_replace_VkPhysicalDeviceImageFormatInfo2_handle(VkPhysicalDeviceImageFormatInfo2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2:
            vn_replace_VkPhysicalDeviceImageFormatInfo2_handle_self((VkPhysicalDeviceImageFormatInfo2 *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            vn_replace_VkPhysicalDeviceExternalImageFormatInfo_handle_self((VkPhysicalDeviceExternalImageFormatInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            vn_replace_VkImageFormatListCreateInfo_handle_self((VkImageFormatListCreateInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            vn_replace_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_handle_self((VkPhysicalDeviceImageDrmFormatModifierInfoEXT *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            vn_replace_VkImageStencilUsageCreateInfo_handle_self((VkImageStencilUsageCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkQueueFamilyProperties2 chain */

static inline void
vn_encode_VkQueueFamilyProperties2_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkQueueFamilyProperties2_self(struct vn_cs *cs, const VkQueueFamilyProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkQueueFamilyProperties(cs, &val->queueFamilyProperties);
}

static inline void
vn_encode_VkQueueFamilyProperties2(struct vn_cs *cs, const VkQueueFamilyProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2 });
    vn_encode_VkQueueFamilyProperties2_pnext(cs, val->pNext);
    vn_encode_VkQueueFamilyProperties2_self(cs, val);
}

static inline void *
vn_decode_VkQueueFamilyProperties2_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkQueueFamilyProperties2_self_partial_temp(struct vn_cs *cs, VkQueueFamilyProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkQueueFamilyProperties_partial_temp(cs, &val->queueFamilyProperties);
}

static inline void
vn_decode_VkQueueFamilyProperties2_partial_temp(struct vn_cs *cs, VkQueueFamilyProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkQueueFamilyProperties2_pnext_partial_temp(cs);
    vn_decode_VkQueueFamilyProperties2_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceMemoryProperties2 chain */

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties2_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties2_self(struct vn_cs *cs, const VkPhysicalDeviceMemoryProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPhysicalDeviceMemoryProperties(cs, &val->memoryProperties);
}

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties2(struct vn_cs *cs, const VkPhysicalDeviceMemoryProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2 });
    vn_encode_VkPhysicalDeviceMemoryProperties2_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceMemoryProperties2_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMemoryProperties2_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMemoryProperties2_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMemoryProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceMemoryProperties_partial_temp(cs, &val->memoryProperties);
}

static inline void
vn_decode_VkPhysicalDeviceMemoryProperties2_partial_temp(struct vn_cs *cs, VkPhysicalDeviceMemoryProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMemoryProperties2_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceMemoryProperties2_self_partial_temp(cs, val);
}

/* struct VkSparseImageFormatProperties2 chain */

static inline void
vn_encode_VkSparseImageFormatProperties2_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkSparseImageFormatProperties2_self(struct vn_cs *cs, const VkSparseImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkSparseImageFormatProperties(cs, &val->properties);
}

static inline void
vn_encode_VkSparseImageFormatProperties2(struct vn_cs *cs, const VkSparseImageFormatProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2 });
    vn_encode_VkSparseImageFormatProperties2_pnext(cs, val->pNext);
    vn_encode_VkSparseImageFormatProperties2_self(cs, val);
}

static inline void *
vn_decode_VkSparseImageFormatProperties2_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSparseImageFormatProperties2_self_partial_temp(struct vn_cs *cs, VkSparseImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSparseImageFormatProperties_partial_temp(cs, &val->properties);
}

static inline void
vn_decode_VkSparseImageFormatProperties2_partial_temp(struct vn_cs *cs, VkSparseImageFormatProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSparseImageFormatProperties2_pnext_partial_temp(cs);
    vn_decode_VkSparseImageFormatProperties2_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceSparseImageFormatInfo2 chain */

static inline void *
vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_self_temp(struct vn_cs *cs, VkPhysicalDeviceSparseImageFormatInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkImageType(cs, &val->type);
    vn_decode_VkSampleCountFlagBits(cs, &val->samples);
    vn_decode_VkFlags(cs, &val->usage);
    vn_decode_VkImageTiling(cs, &val->tiling);
}

static inline void
vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_temp(struct vn_cs *cs, VkPhysicalDeviceSparseImageFormatInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_self_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceSparseImageFormatInfo2_handle_self(VkPhysicalDeviceSparseImageFormatInfo2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->format */
    /* skip val->type */
    /* skip val->samples */
    /* skip val->usage */
    /* skip val->tiling */
}

static inline void
vn_replace_VkPhysicalDeviceSparseImageFormatInfo2_handle(VkPhysicalDeviceSparseImageFormatInfo2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2:
            vn_replace_VkPhysicalDeviceSparseImageFormatInfo2_handle_self((VkPhysicalDeviceSparseImageFormatInfo2 *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkPhysicalDeviceExternalBufferInfo chain */

static inline void *
vn_decode_VkPhysicalDeviceExternalBufferInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceExternalBufferInfo_self_temp(struct vn_cs *cs, VkPhysicalDeviceExternalBufferInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkFlags(cs, &val->usage);
    vn_decode_VkExternalMemoryHandleTypeFlagBits(cs, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalBufferInfo_temp(struct vn_cs *cs, VkPhysicalDeviceExternalBufferInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalBufferInfo_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceExternalBufferInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceExternalBufferInfo_handle_self(VkPhysicalDeviceExternalBufferInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->usage */
    /* skip val->handleType */
}

static inline void
vn_replace_VkPhysicalDeviceExternalBufferInfo_handle(VkPhysicalDeviceExternalBufferInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO:
            vn_replace_VkPhysicalDeviceExternalBufferInfo_handle_self((VkPhysicalDeviceExternalBufferInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkExternalBufferProperties chain */

static inline void
vn_encode_VkExternalBufferProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkExternalBufferProperties_self(struct vn_cs *cs, const VkExternalBufferProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkExternalMemoryProperties(cs, &val->externalMemoryProperties);
}

static inline void
vn_encode_VkExternalBufferProperties(struct vn_cs *cs, const VkExternalBufferProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES });
    vn_encode_VkExternalBufferProperties_pnext(cs, val->pNext);
    vn_encode_VkExternalBufferProperties_self(cs, val);
}

static inline void *
vn_decode_VkExternalBufferProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExternalBufferProperties_self_partial_temp(struct vn_cs *cs, VkExternalBufferProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalMemoryProperties_partial_temp(cs, &val->externalMemoryProperties);
}

static inline void
vn_decode_VkExternalBufferProperties_partial_temp(struct vn_cs *cs, VkExternalBufferProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalBufferProperties_pnext_partial_temp(cs);
    vn_decode_VkExternalBufferProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceExternalSemaphoreInfo chain */

static inline void *
vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkSemaphoreTypeCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_pnext_temp(cs);
            vn_decode_VkSemaphoreTypeCreateInfo_self_temp(cs, (VkSemaphoreTypeCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_self_temp(struct vn_cs *cs, VkPhysicalDeviceExternalSemaphoreInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalSemaphoreHandleTypeFlagBits(cs, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_temp(struct vn_cs *cs, VkPhysicalDeviceExternalSemaphoreInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceExternalSemaphoreInfo_handle_self(VkPhysicalDeviceExternalSemaphoreInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleType */
}

static inline void
vn_replace_VkPhysicalDeviceExternalSemaphoreInfo_handle(VkPhysicalDeviceExternalSemaphoreInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO:
            vn_replace_VkPhysicalDeviceExternalSemaphoreInfo_handle_self((VkPhysicalDeviceExternalSemaphoreInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            vn_replace_VkSemaphoreTypeCreateInfo_handle_self((VkSemaphoreTypeCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkExternalSemaphoreProperties chain */

static inline void
vn_encode_VkExternalSemaphoreProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkExternalSemaphoreProperties_self(struct vn_cs *cs, const VkExternalSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(cs, &val->exportFromImportedHandleTypes);
    vn_encode_VkFlags(cs, &val->compatibleHandleTypes);
    vn_encode_VkFlags(cs, &val->externalSemaphoreFeatures);
}

static inline void
vn_encode_VkExternalSemaphoreProperties(struct vn_cs *cs, const VkExternalSemaphoreProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES });
    vn_encode_VkExternalSemaphoreProperties_pnext(cs, val->pNext);
    vn_encode_VkExternalSemaphoreProperties_self(cs, val);
}

static inline void *
vn_decode_VkExternalSemaphoreProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExternalSemaphoreProperties_self_partial_temp(struct vn_cs *cs, VkExternalSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->exportFromImportedHandleTypes */
    /* skip val->compatibleHandleTypes */
    /* skip val->externalSemaphoreFeatures */
}

static inline void
vn_decode_VkExternalSemaphoreProperties_partial_temp(struct vn_cs *cs, VkExternalSemaphoreProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalSemaphoreProperties_pnext_partial_temp(cs);
    vn_decode_VkExternalSemaphoreProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceExternalFenceInfo chain */

static inline void *
vn_decode_VkPhysicalDeviceExternalFenceInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceExternalFenceInfo_self_temp(struct vn_cs *cs, VkPhysicalDeviceExternalFenceInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalFenceHandleTypeFlagBits(cs, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalFenceInfo_temp(struct vn_cs *cs, VkPhysicalDeviceExternalFenceInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalFenceInfo_pnext_temp(cs);
    vn_decode_VkPhysicalDeviceExternalFenceInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkPhysicalDeviceExternalFenceInfo_handle_self(VkPhysicalDeviceExternalFenceInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->handleType */
}

static inline void
vn_replace_VkPhysicalDeviceExternalFenceInfo_handle(VkPhysicalDeviceExternalFenceInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO:
            vn_replace_VkPhysicalDeviceExternalFenceInfo_handle_self((VkPhysicalDeviceExternalFenceInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkExternalFenceProperties chain */

static inline void
vn_encode_VkExternalFenceProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkExternalFenceProperties_self(struct vn_cs *cs, const VkExternalFenceProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(cs, &val->exportFromImportedHandleTypes);
    vn_encode_VkFlags(cs, &val->compatibleHandleTypes);
    vn_encode_VkFlags(cs, &val->externalFenceFeatures);
}

static inline void
vn_encode_VkExternalFenceProperties(struct vn_cs *cs, const VkExternalFenceProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES });
    vn_encode_VkExternalFenceProperties_pnext(cs, val->pNext);
    vn_encode_VkExternalFenceProperties_self(cs, val);
}

static inline void *
vn_decode_VkExternalFenceProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkExternalFenceProperties_self_partial_temp(struct vn_cs *cs, VkExternalFenceProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->exportFromImportedHandleTypes */
    /* skip val->compatibleHandleTypes */
    /* skip val->externalFenceFeatures */
}

static inline void
vn_decode_VkExternalFenceProperties_partial_temp(struct vn_cs *cs, VkExternalFenceProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalFenceProperties_pnext_partial_temp(cs);
    vn_decode_VkExternalFenceProperties_self_partial_temp(cs, val);
}

/* struct VkPhysicalDeviceGroupProperties chain */

static inline void
vn_encode_VkPhysicalDeviceGroupProperties_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceGroupProperties_self(struct vn_cs *cs, const VkPhysicalDeviceGroupProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->physicalDeviceCount);
    vn_encode_array_size(cs, VK_MAX_DEVICE_GROUP_SIZE);
    for (uint32_t i = 0; i < VK_MAX_DEVICE_GROUP_SIZE; i++)
        vn_encode_VkPhysicalDevice(cs, &val->physicalDevices[i]);
    vn_encode_VkBool32(cs, &val->subsetAllocation);
}

static inline void
vn_encode_VkPhysicalDeviceGroupProperties(struct vn_cs *cs, const VkPhysicalDeviceGroupProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES });
    vn_encode_VkPhysicalDeviceGroupProperties_pnext(cs, val->pNext);
    vn_encode_VkPhysicalDeviceGroupProperties_self(cs, val);
}

static inline void *
vn_decode_VkPhysicalDeviceGroupProperties_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceGroupProperties_self_partial_temp(struct vn_cs *cs, VkPhysicalDeviceGroupProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->physicalDeviceCount */
    {
        vn_decode_array_size(cs, VK_MAX_DEVICE_GROUP_SIZE);
        for (uint32_t i = 0; i < VK_MAX_DEVICE_GROUP_SIZE; i++)
            vn_decode_VkPhysicalDevice_temp(cs, &val->physicalDevices[i]);
    }
    /* skip val->subsetAllocation */
}

static inline void
vn_decode_VkPhysicalDeviceGroupProperties_partial_temp(struct vn_cs *cs, VkPhysicalDeviceGroupProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceGroupProperties_pnext_partial_temp(cs);
    vn_decode_VkPhysicalDeviceGroupProperties_self_partial_temp(cs, val);
}

/* struct VkBindBufferMemoryDeviceGroupInfo chain */

static inline void
vn_encode_VkBindBufferMemoryDeviceGroupInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkBindBufferMemoryDeviceGroupInfo_self(struct vn_cs *cs, const VkBindBufferMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->deviceIndexCount);
    if (val->pDeviceIndices) {
        vn_encode_array_size(cs, val->deviceIndexCount);
        vn_encode_uint32_t_array(cs, val->pDeviceIndices, val->deviceIndexCount);
    } else {
        vn_encode_array_size(cs, 0);
    }
}

static inline void
vn_encode_VkBindBufferMemoryDeviceGroupInfo(struct vn_cs *cs, const VkBindBufferMemoryDeviceGroupInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO });
    vn_encode_VkBindBufferMemoryDeviceGroupInfo_pnext(cs, val->pNext);
    vn_encode_VkBindBufferMemoryDeviceGroupInfo_self(cs, val);
}

static inline void *
vn_decode_VkBindBufferMemoryDeviceGroupInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBindBufferMemoryDeviceGroupInfo_self_temp(struct vn_cs *cs, VkBindBufferMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->deviceIndexCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->deviceIndexCount);
        val->pDeviceIndices = vn_cs_alloc_temp(cs, sizeof(*val->pDeviceIndices) * array_size);
        if (!val->pDeviceIndices) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pDeviceIndices, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDeviceIndices = NULL;
    }
}

static inline void
vn_decode_VkBindBufferMemoryDeviceGroupInfo_temp(struct vn_cs *cs, VkBindBufferMemoryDeviceGroupInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindBufferMemoryDeviceGroupInfo_pnext_temp(cs);
    vn_decode_VkBindBufferMemoryDeviceGroupInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBindBufferMemoryDeviceGroupInfo_handle_self(VkBindBufferMemoryDeviceGroupInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->deviceIndexCount */
    /* skip val->pDeviceIndices */
}

static inline void
vn_replace_VkBindBufferMemoryDeviceGroupInfo_handle(VkBindBufferMemoryDeviceGroupInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            vn_replace_VkBindBufferMemoryDeviceGroupInfo_handle_self((VkBindBufferMemoryDeviceGroupInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBindBufferMemoryInfo chain */

static inline void
vn_encode_VkBindBufferMemoryInfo_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkBindBufferMemoryInfo_pnext(cs, pnext->pNext);
            vn_encode_VkBindBufferMemoryDeviceGroupInfo_self(cs, (const VkBindBufferMemoryDeviceGroupInfo *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkBindBufferMemoryInfo_self(struct vn_cs *cs, const VkBindBufferMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBuffer(cs, &val->buffer);
    vn_encode_VkDeviceMemory(cs, &val->memory);
    vn_encode_VkDeviceSize(cs, &val->memoryOffset);
}

static inline void
vn_encode_VkBindBufferMemoryInfo(struct vn_cs *cs, const VkBindBufferMemoryInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO });
    vn_encode_VkBindBufferMemoryInfo_pnext(cs, val->pNext);
    vn_encode_VkBindBufferMemoryInfo_self(cs, val);
}

static inline void *
vn_decode_VkBindBufferMemoryInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkBindBufferMemoryDeviceGroupInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindBufferMemoryInfo_pnext_temp(cs);
            vn_decode_VkBindBufferMemoryDeviceGroupInfo_self_temp(cs, (VkBindBufferMemoryDeviceGroupInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBindBufferMemoryInfo_self_temp(struct vn_cs *cs, VkBindBufferMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
    vn_decode_VkDeviceMemory_lookup(cs, &val->memory);
    vn_decode_VkDeviceSize(cs, &val->memoryOffset);
}

static inline void
vn_decode_VkBindBufferMemoryInfo_temp(struct vn_cs *cs, VkBindBufferMemoryInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindBufferMemoryInfo_pnext_temp(cs);
    vn_decode_VkBindBufferMemoryInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBindBufferMemoryInfo_handle_self(VkBindBufferMemoryInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkBuffer_handle(&val->buffer);
    vn_replace_VkDeviceMemory_handle(&val->memory);
    /* skip val->memoryOffset */
}

static inline void
vn_replace_VkBindBufferMemoryInfo_handle(VkBindBufferMemoryInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO:
            vn_replace_VkBindBufferMemoryInfo_handle_self((VkBindBufferMemoryInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            vn_replace_VkBindBufferMemoryDeviceGroupInfo_handle_self((VkBindBufferMemoryDeviceGroupInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBindImageMemoryDeviceGroupInfo chain */

static inline void
vn_encode_VkBindImageMemoryDeviceGroupInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkBindImageMemoryDeviceGroupInfo_self(struct vn_cs *cs, const VkBindImageMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->deviceIndexCount);
    if (val->pDeviceIndices) {
        vn_encode_array_size(cs, val->deviceIndexCount);
        vn_encode_uint32_t_array(cs, val->pDeviceIndices, val->deviceIndexCount);
    } else {
        vn_encode_array_size(cs, 0);
    }
    vn_encode_uint32_t(cs, &val->splitInstanceBindRegionCount);
    if (val->pSplitInstanceBindRegions) {
        vn_encode_array_size(cs, val->splitInstanceBindRegionCount);
        for (uint32_t i = 0; i < val->splitInstanceBindRegionCount; i++)
            vn_encode_VkRect2D(cs, &val->pSplitInstanceBindRegions[i]);
    } else {
        vn_encode_array_size(cs, 0);
    }
}

static inline void
vn_encode_VkBindImageMemoryDeviceGroupInfo(struct vn_cs *cs, const VkBindImageMemoryDeviceGroupInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO });
    vn_encode_VkBindImageMemoryDeviceGroupInfo_pnext(cs, val->pNext);
    vn_encode_VkBindImageMemoryDeviceGroupInfo_self(cs, val);
}

static inline void *
vn_decode_VkBindImageMemoryDeviceGroupInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBindImageMemoryDeviceGroupInfo_self_temp(struct vn_cs *cs, VkBindImageMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->deviceIndexCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->deviceIndexCount);
        val->pDeviceIndices = vn_cs_alloc_temp(cs, sizeof(*val->pDeviceIndices) * array_size);
        if (!val->pDeviceIndices) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pDeviceIndices, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDeviceIndices = NULL;
    }
    vn_decode_uint32_t(cs, &val->splitInstanceBindRegionCount);
    if (vn_peek_array_size(cs)) {
        val->pSplitInstanceBindRegions = vn_cs_alloc_temp(cs, sizeof(*val->pSplitInstanceBindRegions) * val->splitInstanceBindRegionCount);
        if (!val->pSplitInstanceBindRegions) return;
        vn_decode_array_size(cs, val->splitInstanceBindRegionCount);
        for (uint32_t i = 0; i < val->splitInstanceBindRegionCount; i++)
            vn_decode_VkRect2D_temp(cs, &((VkRect2D *)val->pSplitInstanceBindRegions)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSplitInstanceBindRegions = NULL;
    }
}

static inline void
vn_decode_VkBindImageMemoryDeviceGroupInfo_temp(struct vn_cs *cs, VkBindImageMemoryDeviceGroupInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindImageMemoryDeviceGroupInfo_pnext_temp(cs);
    vn_decode_VkBindImageMemoryDeviceGroupInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBindImageMemoryDeviceGroupInfo_handle_self(VkBindImageMemoryDeviceGroupInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->deviceIndexCount */
    /* skip val->pDeviceIndices */
    /* skip val->splitInstanceBindRegionCount */
    if (val->pSplitInstanceBindRegions) {
       for (uint32_t i = 0; i < val->splitInstanceBindRegionCount; i++)
            vn_replace_VkRect2D_handle(&((VkRect2D *)val->pSplitInstanceBindRegions)[i]);
    }
}

static inline void
vn_replace_VkBindImageMemoryDeviceGroupInfo_handle(VkBindImageMemoryDeviceGroupInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            vn_replace_VkBindImageMemoryDeviceGroupInfo_handle_self((VkBindImageMemoryDeviceGroupInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBindImagePlaneMemoryInfo chain */

static inline void
vn_encode_VkBindImagePlaneMemoryInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkBindImagePlaneMemoryInfo_self(struct vn_cs *cs, const VkBindImagePlaneMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkImageAspectFlagBits(cs, &val->planeAspect);
}

static inline void
vn_encode_VkBindImagePlaneMemoryInfo(struct vn_cs *cs, const VkBindImagePlaneMemoryInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO });
    vn_encode_VkBindImagePlaneMemoryInfo_pnext(cs, val->pNext);
    vn_encode_VkBindImagePlaneMemoryInfo_self(cs, val);
}

static inline void *
vn_decode_VkBindImagePlaneMemoryInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBindImagePlaneMemoryInfo_self_temp(struct vn_cs *cs, VkBindImagePlaneMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageAspectFlagBits(cs, &val->planeAspect);
}

static inline void
vn_decode_VkBindImagePlaneMemoryInfo_temp(struct vn_cs *cs, VkBindImagePlaneMemoryInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindImagePlaneMemoryInfo_pnext_temp(cs);
    vn_decode_VkBindImagePlaneMemoryInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBindImagePlaneMemoryInfo_handle_self(VkBindImagePlaneMemoryInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->planeAspect */
}

static inline void
vn_replace_VkBindImagePlaneMemoryInfo_handle(VkBindImagePlaneMemoryInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            vn_replace_VkBindImagePlaneMemoryInfo_handle_self((VkBindImagePlaneMemoryInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBindImageMemoryInfo chain */

static inline void
vn_encode_VkBindImageMemoryInfo_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkBindImageMemoryInfo_pnext(cs, pnext->pNext);
            vn_encode_VkBindImageMemoryDeviceGroupInfo_self(cs, (const VkBindImageMemoryDeviceGroupInfo *)pnext);
            return;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkBindImageMemoryInfo_pnext(cs, pnext->pNext);
            vn_encode_VkBindImagePlaneMemoryInfo_self(cs, (const VkBindImagePlaneMemoryInfo *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkBindImageMemoryInfo_self(struct vn_cs *cs, const VkBindImageMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkImage(cs, &val->image);
    vn_encode_VkDeviceMemory(cs, &val->memory);
    vn_encode_VkDeviceSize(cs, &val->memoryOffset);
}

static inline void
vn_encode_VkBindImageMemoryInfo(struct vn_cs *cs, const VkBindImageMemoryInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO });
    vn_encode_VkBindImageMemoryInfo_pnext(cs, val->pNext);
    vn_encode_VkBindImageMemoryInfo_self(cs, val);
}

static inline void *
vn_decode_VkBindImageMemoryInfo_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkBindImageMemoryDeviceGroupInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindImageMemoryInfo_pnext_temp(cs);
            vn_decode_VkBindImageMemoryDeviceGroupInfo_self_temp(cs, (VkBindImageMemoryDeviceGroupInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkBindImagePlaneMemoryInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindImageMemoryInfo_pnext_temp(cs);
            vn_decode_VkBindImagePlaneMemoryInfo_self_temp(cs, (VkBindImagePlaneMemoryInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBindImageMemoryInfo_self_temp(struct vn_cs *cs, VkBindImageMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(cs, &val->image);
    vn_decode_VkDeviceMemory_lookup(cs, &val->memory);
    vn_decode_VkDeviceSize(cs, &val->memoryOffset);
}

static inline void
vn_decode_VkBindImageMemoryInfo_temp(struct vn_cs *cs, VkBindImageMemoryInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindImageMemoryInfo_pnext_temp(cs);
    vn_decode_VkBindImageMemoryInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBindImageMemoryInfo_handle_self(VkBindImageMemoryInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkImage_handle(&val->image);
    vn_replace_VkDeviceMemory_handle(&val->memory);
    /* skip val->memoryOffset */
}

static inline void
vn_replace_VkBindImageMemoryInfo_handle(VkBindImageMemoryInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO:
            vn_replace_VkBindImageMemoryInfo_handle_self((VkBindImageMemoryInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            vn_replace_VkBindImageMemoryDeviceGroupInfo_handle_self((VkBindImageMemoryDeviceGroupInfo *)pnext);
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            vn_replace_VkBindImagePlaneMemoryInfo_handle_self((VkBindImagePlaneMemoryInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorUpdateTemplateEntry */

static inline void
vn_decode_VkDescriptorUpdateTemplateEntry_temp(struct vn_cs *cs, VkDescriptorUpdateTemplateEntry *val)
{
    vn_decode_uint32_t(cs, &val->dstBinding);
    vn_decode_uint32_t(cs, &val->dstArrayElement);
    vn_decode_uint32_t(cs, &val->descriptorCount);
    vn_decode_VkDescriptorType(cs, &val->descriptorType);
    vn_decode_size_t(cs, &val->offset);
    vn_decode_size_t(cs, &val->stride);
}

static inline void
vn_replace_VkDescriptorUpdateTemplateEntry_handle(VkDescriptorUpdateTemplateEntry *val)
{
    /* skip val->dstBinding */
    /* skip val->dstArrayElement */
    /* skip val->descriptorCount */
    /* skip val->descriptorType */
    /* skip val->offset */
    /* skip val->stride */
}

/* struct VkDescriptorUpdateTemplateCreateInfo chain */

static inline void *
vn_decode_VkDescriptorUpdateTemplateCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDescriptorUpdateTemplateCreateInfo_self_temp(struct vn_cs *cs, VkDescriptorUpdateTemplateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->descriptorUpdateEntryCount);
    if (vn_peek_array_size(cs)) {
        val->pDescriptorUpdateEntries = vn_cs_alloc_temp(cs, sizeof(*val->pDescriptorUpdateEntries) * val->descriptorUpdateEntryCount);
        if (!val->pDescriptorUpdateEntries) return;
        vn_decode_array_size(cs, val->descriptorUpdateEntryCount);
        for (uint32_t i = 0; i < val->descriptorUpdateEntryCount; i++)
            vn_decode_VkDescriptorUpdateTemplateEntry_temp(cs, &((VkDescriptorUpdateTemplateEntry *)val->pDescriptorUpdateEntries)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDescriptorUpdateEntries = NULL;
    }
    vn_decode_VkDescriptorUpdateTemplateType(cs, &val->templateType);
    vn_decode_VkDescriptorSetLayout_lookup(cs, &val->descriptorSetLayout);
    vn_decode_VkPipelineBindPoint(cs, &val->pipelineBindPoint);
    vn_decode_VkPipelineLayout_lookup(cs, &val->pipelineLayout);
    vn_decode_uint32_t(cs, &val->set);
}

static inline void
vn_decode_VkDescriptorUpdateTemplateCreateInfo_temp(struct vn_cs *cs, VkDescriptorUpdateTemplateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorUpdateTemplateCreateInfo_pnext_temp(cs);
    vn_decode_VkDescriptorUpdateTemplateCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDescriptorUpdateTemplateCreateInfo_handle_self(VkDescriptorUpdateTemplateCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->descriptorUpdateEntryCount */
    if (val->pDescriptorUpdateEntries) {
       for (uint32_t i = 0; i < val->descriptorUpdateEntryCount; i++)
            vn_replace_VkDescriptorUpdateTemplateEntry_handle(&((VkDescriptorUpdateTemplateEntry *)val->pDescriptorUpdateEntries)[i]);
    }
    /* skip val->templateType */
    vn_replace_VkDescriptorSetLayout_handle(&val->descriptorSetLayout);
    /* skip val->pipelineBindPoint */
    vn_replace_VkPipelineLayout_handle(&val->pipelineLayout);
    /* skip val->set */
}

static inline void
vn_replace_VkDescriptorUpdateTemplateCreateInfo_handle(VkDescriptorUpdateTemplateCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO:
            vn_replace_VkDescriptorUpdateTemplateCreateInfo_handle_self((VkDescriptorUpdateTemplateCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkBufferMemoryRequirementsInfo2 chain */

static inline void *
vn_decode_VkBufferMemoryRequirementsInfo2_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBufferMemoryRequirementsInfo2_self_temp(struct vn_cs *cs, VkBufferMemoryRequirementsInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
}

static inline void
vn_decode_VkBufferMemoryRequirementsInfo2_temp(struct vn_cs *cs, VkBufferMemoryRequirementsInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferMemoryRequirementsInfo2_pnext_temp(cs);
    vn_decode_VkBufferMemoryRequirementsInfo2_self_temp(cs, val);
}

static inline void
vn_replace_VkBufferMemoryRequirementsInfo2_handle_self(VkBufferMemoryRequirementsInfo2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkBuffer_handle(&val->buffer);
}

static inline void
vn_replace_VkBufferMemoryRequirementsInfo2_handle(VkBufferMemoryRequirementsInfo2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2:
            vn_replace_VkBufferMemoryRequirementsInfo2_handle_self((VkBufferMemoryRequirementsInfo2 *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImagePlaneMemoryRequirementsInfo chain */

static inline void *
vn_decode_VkImagePlaneMemoryRequirementsInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImagePlaneMemoryRequirementsInfo_self_temp(struct vn_cs *cs, VkImagePlaneMemoryRequirementsInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageAspectFlagBits(cs, &val->planeAspect);
}

static inline void
vn_decode_VkImagePlaneMemoryRequirementsInfo_temp(struct vn_cs *cs, VkImagePlaneMemoryRequirementsInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImagePlaneMemoryRequirementsInfo_pnext_temp(cs);
    vn_decode_VkImagePlaneMemoryRequirementsInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkImagePlaneMemoryRequirementsInfo_handle_self(VkImagePlaneMemoryRequirementsInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->planeAspect */
}

static inline void
vn_replace_VkImagePlaneMemoryRequirementsInfo_handle(VkImagePlaneMemoryRequirementsInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            vn_replace_VkImagePlaneMemoryRequirementsInfo_handle_self((VkImagePlaneMemoryRequirementsInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageMemoryRequirementsInfo2 chain */

static inline void *
vn_decode_VkImageMemoryRequirementsInfo2_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkImagePlaneMemoryRequirementsInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageMemoryRequirementsInfo2_pnext_temp(cs);
            vn_decode_VkImagePlaneMemoryRequirementsInfo_self_temp(cs, (VkImagePlaneMemoryRequirementsInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageMemoryRequirementsInfo2_self_temp(struct vn_cs *cs, VkImageMemoryRequirementsInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(cs, &val->image);
}

static inline void
vn_decode_VkImageMemoryRequirementsInfo2_temp(struct vn_cs *cs, VkImageMemoryRequirementsInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkImageMemoryRequirementsInfo2_pnext_temp(cs);
    vn_decode_VkImageMemoryRequirementsInfo2_self_temp(cs, val);
}

static inline void
vn_replace_VkImageMemoryRequirementsInfo2_handle_self(VkImageMemoryRequirementsInfo2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkImage_handle(&val->image);
}

static inline void
vn_replace_VkImageMemoryRequirementsInfo2_handle(VkImageMemoryRequirementsInfo2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2:
            vn_replace_VkImageMemoryRequirementsInfo2_handle_self((VkImageMemoryRequirementsInfo2 *)pnext);
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            vn_replace_VkImagePlaneMemoryRequirementsInfo_handle_self((VkImagePlaneMemoryRequirementsInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageSparseMemoryRequirementsInfo2 chain */

static inline void *
vn_decode_VkImageSparseMemoryRequirementsInfo2_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageSparseMemoryRequirementsInfo2_self_temp(struct vn_cs *cs, VkImageSparseMemoryRequirementsInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(cs, &val->image);
}

static inline void
vn_decode_VkImageSparseMemoryRequirementsInfo2_temp(struct vn_cs *cs, VkImageSparseMemoryRequirementsInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkImageSparseMemoryRequirementsInfo2_pnext_temp(cs);
    vn_decode_VkImageSparseMemoryRequirementsInfo2_self_temp(cs, val);
}

static inline void
vn_replace_VkImageSparseMemoryRequirementsInfo2_handle_self(VkImageSparseMemoryRequirementsInfo2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkImage_handle(&val->image);
}

static inline void
vn_replace_VkImageSparseMemoryRequirementsInfo2_handle(VkImageSparseMemoryRequirementsInfo2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2:
            vn_replace_VkImageSparseMemoryRequirementsInfo2_handle_self((VkImageSparseMemoryRequirementsInfo2 *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkMemoryDedicatedRequirements chain */

static inline void
vn_encode_VkMemoryDedicatedRequirements_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkMemoryDedicatedRequirements_self(struct vn_cs *cs, const VkMemoryDedicatedRequirements *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->prefersDedicatedAllocation);
    vn_encode_VkBool32(cs, &val->requiresDedicatedAllocation);
}

static inline void
vn_encode_VkMemoryDedicatedRequirements(struct vn_cs *cs, const VkMemoryDedicatedRequirements *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS });
    vn_encode_VkMemoryDedicatedRequirements_pnext(cs, val->pNext);
    vn_encode_VkMemoryDedicatedRequirements_self(cs, val);
}

static inline void *
vn_decode_VkMemoryDedicatedRequirements_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkMemoryDedicatedRequirements_self_partial_temp(struct vn_cs *cs, VkMemoryDedicatedRequirements *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->prefersDedicatedAllocation */
    /* skip val->requiresDedicatedAllocation */
}

static inline void
vn_decode_VkMemoryDedicatedRequirements_partial_temp(struct vn_cs *cs, VkMemoryDedicatedRequirements *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryDedicatedRequirements_pnext_partial_temp(cs);
    vn_decode_VkMemoryDedicatedRequirements_self_partial_temp(cs, val);
}

/* struct VkMemoryRequirements2 chain */

static inline void
vn_encode_VkMemoryRequirements2_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkMemoryRequirements2_pnext(cs, pnext->pNext);
            vn_encode_VkMemoryDedicatedRequirements_self(cs, (const VkMemoryDedicatedRequirements *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkMemoryRequirements2_self(struct vn_cs *cs, const VkMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkMemoryRequirements(cs, &val->memoryRequirements);
}

static inline void
vn_encode_VkMemoryRequirements2(struct vn_cs *cs, const VkMemoryRequirements2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2 });
    vn_encode_VkMemoryRequirements2_pnext(cs, val->pNext);
    vn_encode_VkMemoryRequirements2_self(cs, val);
}

static inline void *
vn_decode_VkMemoryRequirements2_pnext_partial_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkMemoryDedicatedRequirements));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryRequirements2_pnext_partial_temp(cs);
            vn_decode_VkMemoryDedicatedRequirements_self_partial_temp(cs, (VkMemoryDedicatedRequirements *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkMemoryRequirements2_self_partial_temp(struct vn_cs *cs, VkMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkMemoryRequirements_partial_temp(cs, &val->memoryRequirements);
}

static inline void
vn_decode_VkMemoryRequirements2_partial_temp(struct vn_cs *cs, VkMemoryRequirements2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryRequirements2_pnext_partial_temp(cs);
    vn_decode_VkMemoryRequirements2_self_partial_temp(cs, val);
}

/* struct VkSparseImageMemoryRequirements2 chain */

static inline void
vn_encode_VkSparseImageMemoryRequirements2_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkSparseImageMemoryRequirements2_self(struct vn_cs *cs, const VkSparseImageMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkSparseImageMemoryRequirements(cs, &val->memoryRequirements);
}

static inline void
vn_encode_VkSparseImageMemoryRequirements2(struct vn_cs *cs, const VkSparseImageMemoryRequirements2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2 });
    vn_encode_VkSparseImageMemoryRequirements2_pnext(cs, val->pNext);
    vn_encode_VkSparseImageMemoryRequirements2_self(cs, val);
}

static inline void *
vn_decode_VkSparseImageMemoryRequirements2_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSparseImageMemoryRequirements2_self_partial_temp(struct vn_cs *cs, VkSparseImageMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSparseImageMemoryRequirements_partial_temp(cs, &val->memoryRequirements);
}

static inline void
vn_decode_VkSparseImageMemoryRequirements2_partial_temp(struct vn_cs *cs, VkSparseImageMemoryRequirements2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSparseImageMemoryRequirements2_pnext_partial_temp(cs);
    vn_decode_VkSparseImageMemoryRequirements2_self_partial_temp(cs, val);
}

/* struct VkSamplerYcbcrConversionCreateInfo chain */

static inline void *
vn_decode_VkSamplerYcbcrConversionCreateInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSamplerYcbcrConversionCreateInfo_self_temp(struct vn_cs *cs, VkSamplerYcbcrConversionCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkSamplerYcbcrModelConversion(cs, &val->ycbcrModel);
    vn_decode_VkSamplerYcbcrRange(cs, &val->ycbcrRange);
    vn_decode_VkComponentMapping_temp(cs, &val->components);
    vn_decode_VkChromaLocation(cs, &val->xChromaOffset);
    vn_decode_VkChromaLocation(cs, &val->yChromaOffset);
    vn_decode_VkFilter(cs, &val->chromaFilter);
    vn_decode_VkBool32(cs, &val->forceExplicitReconstruction);
}

static inline void
vn_decode_VkSamplerYcbcrConversionCreateInfo_temp(struct vn_cs *cs, VkSamplerYcbcrConversionCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerYcbcrConversionCreateInfo_pnext_temp(cs);
    vn_decode_VkSamplerYcbcrConversionCreateInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSamplerYcbcrConversionCreateInfo_handle_self(VkSamplerYcbcrConversionCreateInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->format */
    /* skip val->ycbcrModel */
    /* skip val->ycbcrRange */
    vn_replace_VkComponentMapping_handle(&val->components);
    /* skip val->xChromaOffset */
    /* skip val->yChromaOffset */
    /* skip val->chromaFilter */
    /* skip val->forceExplicitReconstruction */
}

static inline void
vn_replace_VkSamplerYcbcrConversionCreateInfo_handle(VkSamplerYcbcrConversionCreateInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO:
            vn_replace_VkSamplerYcbcrConversionCreateInfo_handle_self((VkSamplerYcbcrConversionCreateInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDeviceQueueInfo2 chain */

static inline void *
vn_decode_VkDeviceQueueInfo2_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceQueueInfo2_self_temp(struct vn_cs *cs, VkDeviceQueueInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->queueFamilyIndex);
    vn_decode_uint32_t(cs, &val->queueIndex);
}

static inline void
vn_decode_VkDeviceQueueInfo2_temp(struct vn_cs *cs, VkDeviceQueueInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceQueueInfo2_pnext_temp(cs);
    vn_decode_VkDeviceQueueInfo2_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceQueueInfo2_handle_self(VkDeviceQueueInfo2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->queueFamilyIndex */
    /* skip val->queueIndex */
}

static inline void
vn_replace_VkDeviceQueueInfo2_handle(VkDeviceQueueInfo2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2:
            vn_replace_VkDeviceQueueInfo2_handle_self((VkDeviceQueueInfo2 *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDescriptorSetVariableDescriptorCountLayoutSupport chain */

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(struct vn_cs *cs, const VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(cs, &val->maxVariableDescriptorCount);
}

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport(struct vn_cs *cs, const VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT });
    vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext(cs, val->pNext);
    vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(cs, val);
}

static inline void *
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(struct vn_cs *cs, VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxVariableDescriptorCount */
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_partial_temp(struct vn_cs *cs, VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext_partial_temp(cs);
    vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(cs, val);
}

/* struct VkDescriptorSetLayoutSupport chain */

static inline void
vn_encode_VkDescriptorSetLayoutSupport_pnext(struct vn_cs *cs, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            vn_encode_simple_pointer(cs, pnext);
            vn_encode_VkStructureType(cs, &pnext->sType);
            vn_encode_VkDescriptorSetLayoutSupport_pnext(cs, pnext->pNext);
            vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(cs, (const VkDescriptorSetVariableDescriptorCountLayoutSupport *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkDescriptorSetLayoutSupport_self(struct vn_cs *cs, const VkDescriptorSetLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(cs, &val->supported);
}

static inline void
vn_encode_VkDescriptorSetLayoutSupport(struct vn_cs *cs, const VkDescriptorSetLayoutSupport *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT });
    vn_encode_VkDescriptorSetLayoutSupport_pnext(cs, val->pNext);
    vn_encode_VkDescriptorSetLayoutSupport_self(cs, val);
}

static inline void *
vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkDescriptorSetVariableDescriptorCountLayoutSupport));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(cs);
            vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(cs, (VkDescriptorSetVariableDescriptorCountLayoutSupport *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDescriptorSetLayoutSupport_self_partial_temp(struct vn_cs *cs, VkDescriptorSetLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->supported */
}

static inline void
vn_decode_VkDescriptorSetLayoutSupport_partial_temp(struct vn_cs *cs, VkDescriptorSetLayoutSupport *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(cs);
    vn_decode_VkDescriptorSetLayoutSupport_self_partial_temp(cs, val);
}

/* struct VkAttachmentDescriptionStencilLayout chain */

static inline void *
vn_decode_VkAttachmentDescriptionStencilLayout_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkAttachmentDescriptionStencilLayout_self_temp(struct vn_cs *cs, VkAttachmentDescriptionStencilLayout *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageLayout(cs, &val->stencilInitialLayout);
    vn_decode_VkImageLayout(cs, &val->stencilFinalLayout);
}

static inline void
vn_decode_VkAttachmentDescriptionStencilLayout_temp(struct vn_cs *cs, VkAttachmentDescriptionStencilLayout *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentDescriptionStencilLayout_pnext_temp(cs);
    vn_decode_VkAttachmentDescriptionStencilLayout_self_temp(cs, val);
}

static inline void
vn_replace_VkAttachmentDescriptionStencilLayout_handle_self(VkAttachmentDescriptionStencilLayout *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->stencilInitialLayout */
    /* skip val->stencilFinalLayout */
}

static inline void
vn_replace_VkAttachmentDescriptionStencilLayout_handle(VkAttachmentDescriptionStencilLayout *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            vn_replace_VkAttachmentDescriptionStencilLayout_handle_self((VkAttachmentDescriptionStencilLayout *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkAttachmentDescription2 chain */

static inline void *
vn_decode_VkAttachmentDescription2_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkAttachmentDescriptionStencilLayout));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkAttachmentDescription2_pnext_temp(cs);
            vn_decode_VkAttachmentDescriptionStencilLayout_self_temp(cs, (VkAttachmentDescriptionStencilLayout *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkAttachmentDescription2_self_temp(struct vn_cs *cs, VkAttachmentDescription2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkFormat(cs, &val->format);
    vn_decode_VkSampleCountFlagBits(cs, &val->samples);
    vn_decode_VkAttachmentLoadOp(cs, &val->loadOp);
    vn_decode_VkAttachmentStoreOp(cs, &val->storeOp);
    vn_decode_VkAttachmentLoadOp(cs, &val->stencilLoadOp);
    vn_decode_VkAttachmentStoreOp(cs, &val->stencilStoreOp);
    vn_decode_VkImageLayout(cs, &val->initialLayout);
    vn_decode_VkImageLayout(cs, &val->finalLayout);
}

static inline void
vn_decode_VkAttachmentDescription2_temp(struct vn_cs *cs, VkAttachmentDescription2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentDescription2_pnext_temp(cs);
    vn_decode_VkAttachmentDescription2_self_temp(cs, val);
}

static inline void
vn_replace_VkAttachmentDescription2_handle_self(VkAttachmentDescription2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->format */
    /* skip val->samples */
    /* skip val->loadOp */
    /* skip val->storeOp */
    /* skip val->stencilLoadOp */
    /* skip val->stencilStoreOp */
    /* skip val->initialLayout */
    /* skip val->finalLayout */
}

static inline void
vn_replace_VkAttachmentDescription2_handle(VkAttachmentDescription2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2:
            vn_replace_VkAttachmentDescription2_handle_self((VkAttachmentDescription2 *)pnext);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            vn_replace_VkAttachmentDescriptionStencilLayout_handle_self((VkAttachmentDescriptionStencilLayout *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkAttachmentReferenceStencilLayout chain */

static inline void *
vn_decode_VkAttachmentReferenceStencilLayout_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkAttachmentReferenceStencilLayout_self_temp(struct vn_cs *cs, VkAttachmentReferenceStencilLayout *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageLayout(cs, &val->stencilLayout);
}

static inline void
vn_decode_VkAttachmentReferenceStencilLayout_temp(struct vn_cs *cs, VkAttachmentReferenceStencilLayout *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentReferenceStencilLayout_pnext_temp(cs);
    vn_decode_VkAttachmentReferenceStencilLayout_self_temp(cs, val);
}

static inline void
vn_replace_VkAttachmentReferenceStencilLayout_handle_self(VkAttachmentReferenceStencilLayout *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->stencilLayout */
}

static inline void
vn_replace_VkAttachmentReferenceStencilLayout_handle(VkAttachmentReferenceStencilLayout *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            vn_replace_VkAttachmentReferenceStencilLayout_handle_self((VkAttachmentReferenceStencilLayout *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkAttachmentReference2 chain */

static inline void *
vn_decode_VkAttachmentReference2_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkAttachmentReferenceStencilLayout));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkAttachmentReference2_pnext_temp(cs);
            vn_decode_VkAttachmentReferenceStencilLayout_self_temp(cs, (VkAttachmentReferenceStencilLayout *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkAttachmentReference2_self_temp(struct vn_cs *cs, VkAttachmentReference2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->attachment);
    vn_decode_VkImageLayout(cs, &val->layout);
    vn_decode_VkFlags(cs, &val->aspectMask);
}

static inline void
vn_decode_VkAttachmentReference2_temp(struct vn_cs *cs, VkAttachmentReference2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentReference2_pnext_temp(cs);
    vn_decode_VkAttachmentReference2_self_temp(cs, val);
}

static inline void
vn_replace_VkAttachmentReference2_handle_self(VkAttachmentReference2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->attachment */
    /* skip val->layout */
    /* skip val->aspectMask */
}

static inline void
vn_replace_VkAttachmentReference2_handle(VkAttachmentReference2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2:
            vn_replace_VkAttachmentReference2_handle_self((VkAttachmentReference2 *)pnext);
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            vn_replace_VkAttachmentReferenceStencilLayout_handle_self((VkAttachmentReferenceStencilLayout *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSubpassDescriptionDepthStencilResolve chain */

static inline void *
vn_decode_VkSubpassDescriptionDepthStencilResolve_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSubpassDescriptionDepthStencilResolve_self_temp(struct vn_cs *cs, VkSubpassDescriptionDepthStencilResolve *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkResolveModeFlagBits(cs, &val->depthResolveMode);
    vn_decode_VkResolveModeFlagBits(cs, &val->stencilResolveMode);
    if (vn_decode_simple_pointer(cs)) {
        val->pDepthStencilResolveAttachment = vn_cs_alloc_temp(cs, sizeof(*val->pDepthStencilResolveAttachment));
        if (!val->pDepthStencilResolveAttachment) return;
        vn_decode_VkAttachmentReference2_temp(cs, (VkAttachmentReference2 *)val->pDepthStencilResolveAttachment);
    } else {
        val->pDepthStencilResolveAttachment = NULL;
    }
}

static inline void
vn_decode_VkSubpassDescriptionDepthStencilResolve_temp(struct vn_cs *cs, VkSubpassDescriptionDepthStencilResolve *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassDescriptionDepthStencilResolve_pnext_temp(cs);
    vn_decode_VkSubpassDescriptionDepthStencilResolve_self_temp(cs, val);
}

static inline void
vn_replace_VkSubpassDescriptionDepthStencilResolve_handle_self(VkSubpassDescriptionDepthStencilResolve *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->depthResolveMode */
    /* skip val->stencilResolveMode */
    if (val->pDepthStencilResolveAttachment)
        vn_replace_VkAttachmentReference2_handle((VkAttachmentReference2 *)val->pDepthStencilResolveAttachment);
}

static inline void
vn_replace_VkSubpassDescriptionDepthStencilResolve_handle(VkSubpassDescriptionDepthStencilResolve *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            vn_replace_VkSubpassDescriptionDepthStencilResolve_handle_self((VkSubpassDescriptionDepthStencilResolve *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSubpassDescription2 chain */

static inline void *
vn_decode_VkSubpassDescription2_pnext_temp(struct vn_cs *cs)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(cs))
        return NULL;

    vn_decode_VkStructureType(cs, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
        pnext = vn_cs_alloc_temp(cs, sizeof(VkSubpassDescriptionDepthStencilResolve));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubpassDescription2_pnext_temp(cs);
            vn_decode_VkSubpassDescriptionDepthStencilResolve_self_temp(cs, (VkSubpassDescriptionDepthStencilResolve *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_set_error(cs);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSubpassDescription2_self_temp(struct vn_cs *cs, VkSubpassDescription2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_VkPipelineBindPoint(cs, &val->pipelineBindPoint);
    vn_decode_uint32_t(cs, &val->viewMask);
    vn_decode_uint32_t(cs, &val->inputAttachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pInputAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pInputAttachments) * val->inputAttachmentCount);
        if (!val->pInputAttachments) return;
        vn_decode_array_size(cs, val->inputAttachmentCount);
        for (uint32_t i = 0; i < val->inputAttachmentCount; i++)
            vn_decode_VkAttachmentReference2_temp(cs, &((VkAttachmentReference2 *)val->pInputAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pInputAttachments = NULL;
    }
    vn_decode_uint32_t(cs, &val->colorAttachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pColorAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pColorAttachments) * val->colorAttachmentCount);
        if (!val->pColorAttachments) return;
        vn_decode_array_size(cs, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference2_temp(cs, &((VkAttachmentReference2 *)val->pColorAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pColorAttachments = NULL;
    }
    if (vn_peek_array_size(cs)) {
        val->pResolveAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pResolveAttachments) * val->colorAttachmentCount);
        if (!val->pResolveAttachments) return;
        vn_decode_array_size(cs, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference2_temp(cs, &((VkAttachmentReference2 *)val->pResolveAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pResolveAttachments = NULL;
    }
    if (vn_decode_simple_pointer(cs)) {
        val->pDepthStencilAttachment = vn_cs_alloc_temp(cs, sizeof(*val->pDepthStencilAttachment));
        if (!val->pDepthStencilAttachment) return;
        vn_decode_VkAttachmentReference2_temp(cs, (VkAttachmentReference2 *)val->pDepthStencilAttachment);
    } else {
        val->pDepthStencilAttachment = NULL;
    }
    vn_decode_uint32_t(cs, &val->preserveAttachmentCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->preserveAttachmentCount);
        val->pPreserveAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pPreserveAttachments) * array_size);
        if (!val->pPreserveAttachments) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pPreserveAttachments, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pPreserveAttachments = NULL;
    }
}

static inline void
vn_decode_VkSubpassDescription2_temp(struct vn_cs *cs, VkSubpassDescription2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassDescription2_pnext_temp(cs);
    vn_decode_VkSubpassDescription2_self_temp(cs, val);
}

static inline void
vn_replace_VkSubpassDescription2_handle_self(VkSubpassDescription2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->pipelineBindPoint */
    /* skip val->viewMask */
    /* skip val->inputAttachmentCount */
    if (val->pInputAttachments) {
       for (uint32_t i = 0; i < val->inputAttachmentCount; i++)
            vn_replace_VkAttachmentReference2_handle(&((VkAttachmentReference2 *)val->pInputAttachments)[i]);
    }
    /* skip val->colorAttachmentCount */
    if (val->pColorAttachments) {
       for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_replace_VkAttachmentReference2_handle(&((VkAttachmentReference2 *)val->pColorAttachments)[i]);
    }
    if (val->pResolveAttachments) {
       for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_replace_VkAttachmentReference2_handle(&((VkAttachmentReference2 *)val->pResolveAttachments)[i]);
    }
    if (val->pDepthStencilAttachment)
        vn_replace_VkAttachmentReference2_handle((VkAttachmentReference2 *)val->pDepthStencilAttachment);
    /* skip val->preserveAttachmentCount */
    /* skip val->pPreserveAttachments */
}

static inline void
vn_replace_VkSubpassDescription2_handle(VkSubpassDescription2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2:
            vn_replace_VkSubpassDescription2_handle_self((VkSubpassDescription2 *)pnext);
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            vn_replace_VkSubpassDescriptionDepthStencilResolve_handle_self((VkSubpassDescriptionDepthStencilResolve *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSubpassDependency2 chain */

static inline void *
vn_decode_VkSubpassDependency2_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSubpassDependency2_self_temp(struct vn_cs *cs, VkSubpassDependency2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(cs, &val->srcSubpass);
    vn_decode_uint32_t(cs, &val->dstSubpass);
    vn_decode_VkFlags(cs, &val->srcStageMask);
    vn_decode_VkFlags(cs, &val->dstStageMask);
    vn_decode_VkFlags(cs, &val->srcAccessMask);
    vn_decode_VkFlags(cs, &val->dstAccessMask);
    vn_decode_VkFlags(cs, &val->dependencyFlags);
    vn_decode_int32_t(cs, &val->viewOffset);
}

static inline void
vn_decode_VkSubpassDependency2_temp(struct vn_cs *cs, VkSubpassDependency2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassDependency2_pnext_temp(cs);
    vn_decode_VkSubpassDependency2_self_temp(cs, val);
}

static inline void
vn_replace_VkSubpassDependency2_handle_self(VkSubpassDependency2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->srcSubpass */
    /* skip val->dstSubpass */
    /* skip val->srcStageMask */
    /* skip val->dstStageMask */
    /* skip val->srcAccessMask */
    /* skip val->dstAccessMask */
    /* skip val->dependencyFlags */
    /* skip val->viewOffset */
}

static inline void
vn_replace_VkSubpassDependency2_handle(VkSubpassDependency2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2:
            vn_replace_VkSubpassDependency2_handle_self((VkSubpassDependency2 *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkRenderPassCreateInfo2 chain */

static inline void *
vn_decode_VkRenderPassCreateInfo2_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkRenderPassCreateInfo2_self_temp(struct vn_cs *cs, VkRenderPassCreateInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->attachmentCount);
    if (vn_peek_array_size(cs)) {
        val->pAttachments = vn_cs_alloc_temp(cs, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(cs, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkAttachmentDescription2_temp(cs, &((VkAttachmentDescription2 *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pAttachments = NULL;
    }
    vn_decode_uint32_t(cs, &val->subpassCount);
    if (vn_peek_array_size(cs)) {
        val->pSubpasses = vn_cs_alloc_temp(cs, sizeof(*val->pSubpasses) * val->subpassCount);
        if (!val->pSubpasses) return;
        vn_decode_array_size(cs, val->subpassCount);
        for (uint32_t i = 0; i < val->subpassCount; i++)
            vn_decode_VkSubpassDescription2_temp(cs, &((VkSubpassDescription2 *)val->pSubpasses)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSubpasses = NULL;
    }
    vn_decode_uint32_t(cs, &val->dependencyCount);
    if (vn_peek_array_size(cs)) {
        val->pDependencies = vn_cs_alloc_temp(cs, sizeof(*val->pDependencies) * val->dependencyCount);
        if (!val->pDependencies) return;
        vn_decode_array_size(cs, val->dependencyCount);
        for (uint32_t i = 0; i < val->dependencyCount; i++)
            vn_decode_VkSubpassDependency2_temp(cs, &((VkSubpassDependency2 *)val->pDependencies)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pDependencies = NULL;
    }
    vn_decode_uint32_t(cs, &val->correlatedViewMaskCount);
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->correlatedViewMaskCount);
        val->pCorrelatedViewMasks = vn_cs_alloc_temp(cs, sizeof(*val->pCorrelatedViewMasks) * array_size);
        if (!val->pCorrelatedViewMasks) return;
        vn_decode_uint32_t_array(cs, (uint32_t *)val->pCorrelatedViewMasks, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pCorrelatedViewMasks = NULL;
    }
}

static inline void
vn_decode_VkRenderPassCreateInfo2_temp(struct vn_cs *cs, VkRenderPassCreateInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassCreateInfo2_pnext_temp(cs);
    vn_decode_VkRenderPassCreateInfo2_self_temp(cs, val);
}

static inline void
vn_replace_VkRenderPassCreateInfo2_handle_self(VkRenderPassCreateInfo2 *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->attachmentCount */
    if (val->pAttachments) {
       for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_replace_VkAttachmentDescription2_handle(&((VkAttachmentDescription2 *)val->pAttachments)[i]);
    }
    /* skip val->subpassCount */
    if (val->pSubpasses) {
       for (uint32_t i = 0; i < val->subpassCount; i++)
            vn_replace_VkSubpassDescription2_handle(&((VkSubpassDescription2 *)val->pSubpasses)[i]);
    }
    /* skip val->dependencyCount */
    if (val->pDependencies) {
       for (uint32_t i = 0; i < val->dependencyCount; i++)
            vn_replace_VkSubpassDependency2_handle(&((VkSubpassDependency2 *)val->pDependencies)[i]);
    }
    /* skip val->correlatedViewMaskCount */
    /* skip val->pCorrelatedViewMasks */
}

static inline void
vn_replace_VkRenderPassCreateInfo2_handle(VkRenderPassCreateInfo2 *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2:
            vn_replace_VkRenderPassCreateInfo2_handle_self((VkRenderPassCreateInfo2 *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSubpassBeginInfo chain */

static inline void *
vn_decode_VkSubpassBeginInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSubpassBeginInfo_self_temp(struct vn_cs *cs, VkSubpassBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSubpassContents(cs, &val->contents);
}

static inline void
vn_decode_VkSubpassBeginInfo_temp(struct vn_cs *cs, VkSubpassBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassBeginInfo_pnext_temp(cs);
    vn_decode_VkSubpassBeginInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSubpassBeginInfo_handle_self(VkSubpassBeginInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->contents */
}

static inline void
vn_replace_VkSubpassBeginInfo_handle(VkSubpassBeginInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO:
            vn_replace_VkSubpassBeginInfo_handle_self((VkSubpassBeginInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSubpassEndInfo chain */

static inline void *
vn_decode_VkSubpassEndInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSubpassEndInfo_self_temp(struct vn_cs *cs, VkSubpassEndInfo *val)
{
    /* skip val->{sType,pNext} */
}

static inline void
vn_decode_VkSubpassEndInfo_temp(struct vn_cs *cs, VkSubpassEndInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_END_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassEndInfo_pnext_temp(cs);
    vn_decode_VkSubpassEndInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSubpassEndInfo_handle_self(VkSubpassEndInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
}

static inline void
vn_replace_VkSubpassEndInfo_handle(VkSubpassEndInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SUBPASS_END_INFO:
            vn_replace_VkSubpassEndInfo_handle_self((VkSubpassEndInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSemaphoreWaitInfo chain */

static inline void *
vn_decode_VkSemaphoreWaitInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSemaphoreWaitInfo_self_temp(struct vn_cs *cs, VkSemaphoreWaitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(cs, &val->flags);
    vn_decode_uint32_t(cs, &val->semaphoreCount);
    if (vn_peek_array_size(cs)) {
        val->pSemaphores = vn_cs_alloc_temp(cs, sizeof(*val->pSemaphores) * val->semaphoreCount);
        if (!val->pSemaphores) return;
        vn_decode_array_size(cs, val->semaphoreCount);
        for (uint32_t i = 0; i < val->semaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(cs, &((VkSemaphore *)val->pSemaphores)[i]);
    } else {
        vn_decode_array_size(cs, 0);
        val->pSemaphores = NULL;
    }
    if (vn_peek_array_size(cs)) {
        const size_t array_size = vn_decode_array_size(cs, val->semaphoreCount);
        val->pValues = vn_cs_alloc_temp(cs, sizeof(*val->pValues) * array_size);
        if (!val->pValues) return;
        vn_decode_uint64_t_array(cs, (uint64_t *)val->pValues, array_size);
    } else {
        vn_decode_array_size(cs, 0);
        val->pValues = NULL;
    }
}

static inline void
vn_decode_VkSemaphoreWaitInfo_temp(struct vn_cs *cs, VkSemaphoreWaitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreWaitInfo_pnext_temp(cs);
    vn_decode_VkSemaphoreWaitInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSemaphoreWaitInfo_handle_self(VkSemaphoreWaitInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    /* skip val->flags */
    /* skip val->semaphoreCount */
    if (val->pSemaphores) {
       for (uint32_t i = 0; i < val->semaphoreCount; i++)
            vn_replace_VkSemaphore_handle(&((VkSemaphore *)val->pSemaphores)[i]);
    }
    /* skip val->pValues */
}

static inline void
vn_replace_VkSemaphoreWaitInfo_handle(VkSemaphoreWaitInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO:
            vn_replace_VkSemaphoreWaitInfo_handle_self((VkSemaphoreWaitInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkSemaphoreSignalInfo chain */

static inline void
vn_encode_VkSemaphoreSignalInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkSemaphoreSignalInfo_self(struct vn_cs *cs, const VkSemaphoreSignalInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkSemaphore(cs, &val->semaphore);
    vn_encode_uint64_t(cs, &val->value);
}

static inline void
vn_encode_VkSemaphoreSignalInfo(struct vn_cs *cs, const VkSemaphoreSignalInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO });
    vn_encode_VkSemaphoreSignalInfo_pnext(cs, val->pNext);
    vn_encode_VkSemaphoreSignalInfo_self(cs, val);
}

static inline void *
vn_decode_VkSemaphoreSignalInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkSemaphoreSignalInfo_self_temp(struct vn_cs *cs, VkSemaphoreSignalInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSemaphore_lookup(cs, &val->semaphore);
    vn_decode_uint64_t(cs, &val->value);
}

static inline void
vn_decode_VkSemaphoreSignalInfo_temp(struct vn_cs *cs, VkSemaphoreSignalInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreSignalInfo_pnext_temp(cs);
    vn_decode_VkSemaphoreSignalInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkSemaphoreSignalInfo_handle_self(VkSemaphoreSignalInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkSemaphore_handle(&val->semaphore);
    /* skip val->value */
}

static inline void
vn_replace_VkSemaphoreSignalInfo_handle(VkSemaphoreSignalInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO:
            vn_replace_VkSemaphoreSignalInfo_handle_self((VkSemaphoreSignalInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkImageDrmFormatModifierPropertiesEXT chain */

static inline void
vn_encode_VkImageDrmFormatModifierPropertiesEXT_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkImageDrmFormatModifierPropertiesEXT_self(struct vn_cs *cs, const VkImageDrmFormatModifierPropertiesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint64_t(cs, &val->drmFormatModifier);
}

static inline void
vn_encode_VkImageDrmFormatModifierPropertiesEXT(struct vn_cs *cs, const VkImageDrmFormatModifierPropertiesEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT });
    vn_encode_VkImageDrmFormatModifierPropertiesEXT_pnext(cs, val->pNext);
    vn_encode_VkImageDrmFormatModifierPropertiesEXT_self(cs, val);
}

static inline void *
vn_decode_VkImageDrmFormatModifierPropertiesEXT_pnext_partial_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkImageDrmFormatModifierPropertiesEXT_self_partial_temp(struct vn_cs *cs, VkImageDrmFormatModifierPropertiesEXT *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->drmFormatModifier */
}

static inline void
vn_decode_VkImageDrmFormatModifierPropertiesEXT_partial_temp(struct vn_cs *cs, VkImageDrmFormatModifierPropertiesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkImageDrmFormatModifierPropertiesEXT_pnext_partial_temp(cs);
    vn_decode_VkImageDrmFormatModifierPropertiesEXT_self_partial_temp(cs, val);
}

/* struct VkBufferDeviceAddressInfo chain */

static inline void
vn_encode_VkBufferDeviceAddressInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkBufferDeviceAddressInfo_self(struct vn_cs *cs, const VkBufferDeviceAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBuffer(cs, &val->buffer);
}

static inline void
vn_encode_VkBufferDeviceAddressInfo(struct vn_cs *cs, const VkBufferDeviceAddressInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO });
    vn_encode_VkBufferDeviceAddressInfo_pnext(cs, val->pNext);
    vn_encode_VkBufferDeviceAddressInfo_self(cs, val);
}

static inline void *
vn_decode_VkBufferDeviceAddressInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkBufferDeviceAddressInfo_self_temp(struct vn_cs *cs, VkBufferDeviceAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBuffer_lookup(cs, &val->buffer);
}

static inline void
vn_decode_VkBufferDeviceAddressInfo_temp(struct vn_cs *cs, VkBufferDeviceAddressInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferDeviceAddressInfo_pnext_temp(cs);
    vn_decode_VkBufferDeviceAddressInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkBufferDeviceAddressInfo_handle_self(VkBufferDeviceAddressInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkBuffer_handle(&val->buffer);
}

static inline void
vn_replace_VkBufferDeviceAddressInfo_handle(VkBufferDeviceAddressInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO:
            vn_replace_VkBufferDeviceAddressInfo_handle_self((VkBufferDeviceAddressInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkDeviceMemoryOpaqueCaptureAddressInfo chain */

static inline void
vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext(struct vn_cs *cs, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(cs, NULL);
}

static inline void
vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_self(struct vn_cs *cs, const VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDeviceMemory(cs, &val->memory);
}

static inline void
vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo(struct vn_cs *cs, const VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO);
    vn_encode_VkStructureType(cs, &(VkStructureType){ VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO });
    vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext(cs, val->pNext);
    vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_self(cs, val);
}

static inline void *
vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext_temp(struct vn_cs *cs)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(cs))
        vn_cs_set_error(cs);
    return NULL;
}

static inline void
vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_self_temp(struct vn_cs *cs, VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDeviceMemory_lookup(cs, &val->memory);
}

static inline void
vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_temp(struct vn_cs *cs, VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(cs, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext_temp(cs);
    vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_self_temp(cs, val);
}

static inline void
vn_replace_VkDeviceMemoryOpaqueCaptureAddressInfo_handle_self(VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    /* skip val->sType */
    /* skip val->pNext */
    vn_replace_VkDeviceMemory_handle(&val->memory);
}

static inline void
vn_replace_VkDeviceMemoryOpaqueCaptureAddressInfo_handle(VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    struct VkBaseOutStructure *pnext = (struct VkBaseOutStructure *)val;

    do {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO:
            vn_replace_VkDeviceMemoryOpaqueCaptureAddressInfo_handle_self((VkDeviceMemoryOpaqueCaptureAddressInfo *)pnext);
            break;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    } while (pnext);
}

/* struct VkCommandStreamDescriptionMESA */

static inline void
vn_decode_VkCommandStreamDescriptionMESA_temp(struct vn_cs *cs, VkCommandStreamDescriptionMESA *val)
{
    vn_decode_uint32_t(cs, &val->resourceId);
    vn_decode_size_t(cs, &val->offset);
    vn_decode_size_t(cs, &val->size);
}

static inline void
vn_replace_VkCommandStreamDescriptionMESA_handle(VkCommandStreamDescriptionMESA *val)
{
    /* skip val->resourceId */
    /* skip val->offset */
    /* skip val->size */
}

/* struct VkCommandStreamDependencyMESA */

static inline void
vn_decode_VkCommandStreamDependencyMESA_temp(struct vn_cs *cs, VkCommandStreamDependencyMESA *val)
{
    vn_decode_uint32_t(cs, &val->srcCommandStream);
    vn_decode_uint32_t(cs, &val->dstCommandStream);
}

static inline void
vn_replace_VkCommandStreamDependencyMESA_handle(VkCommandStreamDependencyMESA *val)
{
    /* skip val->srcCommandStream */
    /* skip val->dstCommandStream */
}

/*
 * Helpers for manual serialization
 */

#endif /* VN_PROTOCOL_RENDERER_STRUCTS_H */
