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
vn_encode_VkOffset2D(struct vn_cs_encoder *enc, const VkOffset2D *val)
{
    vn_encode_int32_t(enc, &val->x);
    vn_encode_int32_t(enc, &val->y);
}

static inline void
vn_decode_VkOffset2D_temp(struct vn_cs_decoder *dec, VkOffset2D *val)
{
    vn_decode_int32_t(dec, &val->x);
    vn_decode_int32_t(dec, &val->y);
}

static inline void
vn_decode_VkOffset2D_partial_temp(struct vn_cs_decoder *dec, VkOffset2D *val)
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
vn_decode_VkOffset3D_temp(struct vn_cs_decoder *dec, VkOffset3D *val)
{
    vn_decode_int32_t(dec, &val->x);
    vn_decode_int32_t(dec, &val->y);
    vn_decode_int32_t(dec, &val->z);
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
vn_encode_VkExtent2D(struct vn_cs_encoder *enc, const VkExtent2D *val)
{
    vn_encode_uint32_t(enc, &val->width);
    vn_encode_uint32_t(enc, &val->height);
}

static inline void
vn_decode_VkExtent2D_temp(struct vn_cs_decoder *dec, VkExtent2D *val)
{
    vn_decode_uint32_t(dec, &val->width);
    vn_decode_uint32_t(dec, &val->height);
}

static inline void
vn_decode_VkExtent2D_partial_temp(struct vn_cs_decoder *dec, VkExtent2D *val)
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
vn_encode_VkExtent3D(struct vn_cs_encoder *enc, const VkExtent3D *val)
{
    vn_encode_uint32_t(enc, &val->width);
    vn_encode_uint32_t(enc, &val->height);
    vn_encode_uint32_t(enc, &val->depth);
}

static inline void
vn_decode_VkExtent3D_temp(struct vn_cs_decoder *dec, VkExtent3D *val)
{
    vn_decode_uint32_t(dec, &val->width);
    vn_decode_uint32_t(dec, &val->height);
    vn_decode_uint32_t(dec, &val->depth);
}

static inline void
vn_decode_VkExtent3D_partial_temp(struct vn_cs_decoder *dec, VkExtent3D *val)
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
vn_decode_VkViewport_temp(struct vn_cs_decoder *dec, VkViewport *val)
{
    vn_decode_float(dec, &val->x);
    vn_decode_float(dec, &val->y);
    vn_decode_float(dec, &val->width);
    vn_decode_float(dec, &val->height);
    vn_decode_float(dec, &val->minDepth);
    vn_decode_float(dec, &val->maxDepth);
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
vn_encode_VkRect2D(struct vn_cs_encoder *enc, const VkRect2D *val)
{
    vn_encode_VkOffset2D(enc, &val->offset);
    vn_encode_VkExtent2D(enc, &val->extent);
}

static inline void
vn_decode_VkRect2D_temp(struct vn_cs_decoder *dec, VkRect2D *val)
{
    vn_decode_VkOffset2D_temp(dec, &val->offset);
    vn_decode_VkExtent2D_temp(dec, &val->extent);
}

static inline void
vn_decode_VkRect2D_partial_temp(struct vn_cs_decoder *dec, VkRect2D *val)
{
    vn_decode_VkOffset2D_partial_temp(dec, &val->offset);
    vn_decode_VkExtent2D_partial_temp(dec, &val->extent);
}

static inline void
vn_replace_VkRect2D_handle(VkRect2D *val)
{
    vn_replace_VkOffset2D_handle(&val->offset);
    vn_replace_VkExtent2D_handle(&val->extent);
}

/* struct VkClearRect */

static inline void
vn_decode_VkClearRect_temp(struct vn_cs_decoder *dec, VkClearRect *val)
{
    vn_decode_VkRect2D_temp(dec, &val->rect);
    vn_decode_uint32_t(dec, &val->baseArrayLayer);
    vn_decode_uint32_t(dec, &val->layerCount);
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
vn_encode_VkComponentMapping(struct vn_cs_encoder *enc, const VkComponentMapping *val)
{
    vn_encode_VkComponentSwizzle(enc, &val->r);
    vn_encode_VkComponentSwizzle(enc, &val->g);
    vn_encode_VkComponentSwizzle(enc, &val->b);
    vn_encode_VkComponentSwizzle(enc, &val->a);
}

static inline void
vn_decode_VkComponentMapping_temp(struct vn_cs_decoder *dec, VkComponentMapping *val)
{
    vn_decode_VkComponentSwizzle(dec, &val->r);
    vn_decode_VkComponentSwizzle(dec, &val->g);
    vn_decode_VkComponentSwizzle(dec, &val->b);
    vn_decode_VkComponentSwizzle(dec, &val->a);
}

static inline void
vn_decode_VkComponentMapping_partial_temp(struct vn_cs_decoder *dec, VkComponentMapping *val)
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
vn_encode_VkPhysicalDeviceLimits(struct vn_cs_encoder *enc, const VkPhysicalDeviceLimits *val)
{
    vn_encode_uint32_t(enc, &val->maxImageDimension1D);
    vn_encode_uint32_t(enc, &val->maxImageDimension2D);
    vn_encode_uint32_t(enc, &val->maxImageDimension3D);
    vn_encode_uint32_t(enc, &val->maxImageDimensionCube);
    vn_encode_uint32_t(enc, &val->maxImageArrayLayers);
    vn_encode_uint32_t(enc, &val->maxTexelBufferElements);
    vn_encode_uint32_t(enc, &val->maxUniformBufferRange);
    vn_encode_uint32_t(enc, &val->maxStorageBufferRange);
    vn_encode_uint32_t(enc, &val->maxPushConstantsSize);
    vn_encode_uint32_t(enc, &val->maxMemoryAllocationCount);
    vn_encode_uint32_t(enc, &val->maxSamplerAllocationCount);
    vn_encode_VkDeviceSize(enc, &val->bufferImageGranularity);
    vn_encode_VkDeviceSize(enc, &val->sparseAddressSpaceSize);
    vn_encode_uint32_t(enc, &val->maxBoundDescriptorSets);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorSamplers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUniformBuffers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorStorageBuffers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorSampledImages);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorStorageImages);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorInputAttachments);
    vn_encode_uint32_t(enc, &val->maxPerStageResources);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetSamplers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUniformBuffers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUniformBuffersDynamic);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetStorageBuffers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetStorageBuffersDynamic);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetSampledImages);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetStorageImages);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetInputAttachments);
    vn_encode_uint32_t(enc, &val->maxVertexInputAttributes);
    vn_encode_uint32_t(enc, &val->maxVertexInputBindings);
    vn_encode_uint32_t(enc, &val->maxVertexInputAttributeOffset);
    vn_encode_uint32_t(enc, &val->maxVertexInputBindingStride);
    vn_encode_uint32_t(enc, &val->maxVertexOutputComponents);
    vn_encode_uint32_t(enc, &val->maxTessellationGenerationLevel);
    vn_encode_uint32_t(enc, &val->maxTessellationPatchSize);
    vn_encode_uint32_t(enc, &val->maxTessellationControlPerVertexInputComponents);
    vn_encode_uint32_t(enc, &val->maxTessellationControlPerVertexOutputComponents);
    vn_encode_uint32_t(enc, &val->maxTessellationControlPerPatchOutputComponents);
    vn_encode_uint32_t(enc, &val->maxTessellationControlTotalOutputComponents);
    vn_encode_uint32_t(enc, &val->maxTessellationEvaluationInputComponents);
    vn_encode_uint32_t(enc, &val->maxTessellationEvaluationOutputComponents);
    vn_encode_uint32_t(enc, &val->maxGeometryShaderInvocations);
    vn_encode_uint32_t(enc, &val->maxGeometryInputComponents);
    vn_encode_uint32_t(enc, &val->maxGeometryOutputComponents);
    vn_encode_uint32_t(enc, &val->maxGeometryOutputVertices);
    vn_encode_uint32_t(enc, &val->maxGeometryTotalOutputComponents);
    vn_encode_uint32_t(enc, &val->maxFragmentInputComponents);
    vn_encode_uint32_t(enc, &val->maxFragmentOutputAttachments);
    vn_encode_uint32_t(enc, &val->maxFragmentDualSrcAttachments);
    vn_encode_uint32_t(enc, &val->maxFragmentCombinedOutputResources);
    vn_encode_uint32_t(enc, &val->maxComputeSharedMemorySize);
    vn_encode_array_size(enc, 3);
    vn_encode_uint32_t_array(enc, val->maxComputeWorkGroupCount, 3);
    vn_encode_uint32_t(enc, &val->maxComputeWorkGroupInvocations);
    vn_encode_array_size(enc, 3);
    vn_encode_uint32_t_array(enc, val->maxComputeWorkGroupSize, 3);
    vn_encode_uint32_t(enc, &val->subPixelPrecisionBits);
    vn_encode_uint32_t(enc, &val->subTexelPrecisionBits);
    vn_encode_uint32_t(enc, &val->mipmapPrecisionBits);
    vn_encode_uint32_t(enc, &val->maxDrawIndexedIndexValue);
    vn_encode_uint32_t(enc, &val->maxDrawIndirectCount);
    vn_encode_float(enc, &val->maxSamplerLodBias);
    vn_encode_float(enc, &val->maxSamplerAnisotropy);
    vn_encode_uint32_t(enc, &val->maxViewports);
    vn_encode_array_size(enc, 2);
    vn_encode_uint32_t_array(enc, val->maxViewportDimensions, 2);
    vn_encode_array_size(enc, 2);
    vn_encode_float_array(enc, val->viewportBoundsRange, 2);
    vn_encode_uint32_t(enc, &val->viewportSubPixelBits);
    vn_encode_size_t(enc, &val->minMemoryMapAlignment);
    vn_encode_VkDeviceSize(enc, &val->minTexelBufferOffsetAlignment);
    vn_encode_VkDeviceSize(enc, &val->minUniformBufferOffsetAlignment);
    vn_encode_VkDeviceSize(enc, &val->minStorageBufferOffsetAlignment);
    vn_encode_int32_t(enc, &val->minTexelOffset);
    vn_encode_uint32_t(enc, &val->maxTexelOffset);
    vn_encode_int32_t(enc, &val->minTexelGatherOffset);
    vn_encode_uint32_t(enc, &val->maxTexelGatherOffset);
    vn_encode_float(enc, &val->minInterpolationOffset);
    vn_encode_float(enc, &val->maxInterpolationOffset);
    vn_encode_uint32_t(enc, &val->subPixelInterpolationOffsetBits);
    vn_encode_uint32_t(enc, &val->maxFramebufferWidth);
    vn_encode_uint32_t(enc, &val->maxFramebufferHeight);
    vn_encode_uint32_t(enc, &val->maxFramebufferLayers);
    vn_encode_VkFlags(enc, &val->framebufferColorSampleCounts);
    vn_encode_VkFlags(enc, &val->framebufferDepthSampleCounts);
    vn_encode_VkFlags(enc, &val->framebufferStencilSampleCounts);
    vn_encode_VkFlags(enc, &val->framebufferNoAttachmentsSampleCounts);
    vn_encode_uint32_t(enc, &val->maxColorAttachments);
    vn_encode_VkFlags(enc, &val->sampledImageColorSampleCounts);
    vn_encode_VkFlags(enc, &val->sampledImageIntegerSampleCounts);
    vn_encode_VkFlags(enc, &val->sampledImageDepthSampleCounts);
    vn_encode_VkFlags(enc, &val->sampledImageStencilSampleCounts);
    vn_encode_VkFlags(enc, &val->storageImageSampleCounts);
    vn_encode_uint32_t(enc, &val->maxSampleMaskWords);
    vn_encode_VkBool32(enc, &val->timestampComputeAndGraphics);
    vn_encode_float(enc, &val->timestampPeriod);
    vn_encode_uint32_t(enc, &val->maxClipDistances);
    vn_encode_uint32_t(enc, &val->maxCullDistances);
    vn_encode_uint32_t(enc, &val->maxCombinedClipAndCullDistances);
    vn_encode_uint32_t(enc, &val->discreteQueuePriorities);
    vn_encode_array_size(enc, 2);
    vn_encode_float_array(enc, val->pointSizeRange, 2);
    vn_encode_array_size(enc, 2);
    vn_encode_float_array(enc, val->lineWidthRange, 2);
    vn_encode_float(enc, &val->pointSizeGranularity);
    vn_encode_float(enc, &val->lineWidthGranularity);
    vn_encode_VkBool32(enc, &val->strictLines);
    vn_encode_VkBool32(enc, &val->standardSampleLocations);
    vn_encode_VkDeviceSize(enc, &val->optimalBufferCopyOffsetAlignment);
    vn_encode_VkDeviceSize(enc, &val->optimalBufferCopyRowPitchAlignment);
    vn_encode_VkDeviceSize(enc, &val->nonCoherentAtomSize);
}

static inline void
vn_decode_VkPhysicalDeviceLimits_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceLimits *val)
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
vn_encode_VkPhysicalDeviceSparseProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceSparseProperties *val)
{
    vn_encode_VkBool32(enc, &val->residencyStandard2DBlockShape);
    vn_encode_VkBool32(enc, &val->residencyStandard2DMultisampleBlockShape);
    vn_encode_VkBool32(enc, &val->residencyStandard3DBlockShape);
    vn_encode_VkBool32(enc, &val->residencyAlignedMipSize);
    vn_encode_VkBool32(enc, &val->residencyNonResidentStrict);
}

static inline void
vn_decode_VkPhysicalDeviceSparseProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSparseProperties *val)
{
    /* skip val->residencyStandard2DBlockShape */
    /* skip val->residencyStandard2DMultisampleBlockShape */
    /* skip val->residencyStandard3DBlockShape */
    /* skip val->residencyAlignedMipSize */
    /* skip val->residencyNonResidentStrict */
}

/* struct VkPhysicalDeviceProperties */

static inline void
vn_encode_VkPhysicalDeviceProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceProperties *val)
{
    vn_encode_uint32_t(enc, &val->apiVersion);
    vn_encode_uint32_t(enc, &val->driverVersion);
    vn_encode_uint32_t(enc, &val->vendorID);
    vn_encode_uint32_t(enc, &val->deviceID);
    vn_encode_VkPhysicalDeviceType(enc, &val->deviceType);
    vn_encode_array_size(enc, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);
    vn_encode_blob_array(enc, val->deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE);
    vn_encode_array_size(enc, VK_UUID_SIZE);
    vn_encode_uint8_t_array(enc, val->pipelineCacheUUID, VK_UUID_SIZE);
    vn_encode_VkPhysicalDeviceLimits(enc, &val->limits);
    vn_encode_VkPhysicalDeviceSparseProperties(enc, &val->sparseProperties);
}

static inline void
vn_decode_VkPhysicalDeviceProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProperties *val)
{
    /* skip val->apiVersion */
    /* skip val->driverVersion */
    /* skip val->vendorID */
    /* skip val->deviceID */
    /* skip val->deviceType */
    /* skip val->deviceName */
    /* skip val->pipelineCacheUUID */
    vn_decode_VkPhysicalDeviceLimits_partial_temp(dec, &val->limits);
    vn_decode_VkPhysicalDeviceSparseProperties_partial_temp(dec, &val->sparseProperties);
}

/* struct VkExtensionProperties */

static inline void
vn_encode_VkExtensionProperties(struct vn_cs_encoder *enc, const VkExtensionProperties *val)
{
    vn_encode_array_size(enc, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_blob_array(enc, val->extensionName, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_uint32_t(enc, &val->specVersion);
}

static inline void
vn_decode_VkExtensionProperties_partial_temp(struct vn_cs_decoder *dec, VkExtensionProperties *val)
{
    /* skip val->extensionName */
    /* skip val->specVersion */
}

/* struct VkLayerProperties */

static inline void
vn_encode_VkLayerProperties(struct vn_cs_encoder *enc, const VkLayerProperties *val)
{
    vn_encode_array_size(enc, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_blob_array(enc, val->layerName, VK_MAX_EXTENSION_NAME_SIZE);
    vn_encode_uint32_t(enc, &val->specVersion);
    vn_encode_uint32_t(enc, &val->implementationVersion);
    vn_encode_array_size(enc, VK_MAX_DESCRIPTION_SIZE);
    vn_encode_blob_array(enc, val->description, VK_MAX_DESCRIPTION_SIZE);
}

static inline void
vn_decode_VkLayerProperties_partial_temp(struct vn_cs_decoder *dec, VkLayerProperties *val)
{
    /* skip val->layerName */
    /* skip val->specVersion */
    /* skip val->implementationVersion */
    /* skip val->description */
}

/* struct VkApplicationInfo chain */

static inline void *
vn_decode_VkApplicationInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkApplicationInfo_self_temp(struct vn_cs_decoder *dec, VkApplicationInfo *val)
{
    /* skip val->{sType,pNext} */
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        val->pApplicationName = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pApplicationName) * string_size);
        if (!val->pApplicationName) return;
        vn_decode_blob_array(dec, (char *)val->pApplicationName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pApplicationName = NULL;
    }
    vn_decode_uint32_t(dec, &val->applicationVersion);
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        val->pEngineName = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pEngineName) * string_size);
        if (!val->pEngineName) return;
        vn_decode_blob_array(dec, (char *)val->pEngineName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pEngineName = NULL;
    }
    vn_decode_uint32_t(dec, &val->engineVersion);
    vn_decode_uint32_t(dec, &val->apiVersion);
}

static inline void
vn_decode_VkApplicationInfo_temp(struct vn_cs_decoder *dec, VkApplicationInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_APPLICATION_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkApplicationInfo_pnext_temp(dec);
    vn_decode_VkApplicationInfo_self_temp(dec, val);
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
vn_decode_VkDeviceQueueCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceQueueCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceQueueCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->queueFamilyIndex);
    vn_decode_uint32_t(dec, &val->queueCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->queueCount);
        val->pQueuePriorities = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pQueuePriorities) * array_size);
        if (!val->pQueuePriorities) return;
        vn_decode_float_array(dec, (float *)val->pQueuePriorities, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pQueuePriorities = NULL;
    }
}

static inline void
vn_decode_VkDeviceQueueCreateInfo_temp(struct vn_cs_decoder *dec, VkDeviceQueueCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceQueueCreateInfo_pnext_temp(dec);
    vn_decode_VkDeviceQueueCreateInfo_self_temp(dec, val);
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
vn_encode_VkPhysicalDeviceFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceFeatures *val)
{
    vn_encode_VkBool32(enc, &val->robustBufferAccess);
    vn_encode_VkBool32(enc, &val->fullDrawIndexUint32);
    vn_encode_VkBool32(enc, &val->imageCubeArray);
    vn_encode_VkBool32(enc, &val->independentBlend);
    vn_encode_VkBool32(enc, &val->geometryShader);
    vn_encode_VkBool32(enc, &val->tessellationShader);
    vn_encode_VkBool32(enc, &val->sampleRateShading);
    vn_encode_VkBool32(enc, &val->dualSrcBlend);
    vn_encode_VkBool32(enc, &val->logicOp);
    vn_encode_VkBool32(enc, &val->multiDrawIndirect);
    vn_encode_VkBool32(enc, &val->drawIndirectFirstInstance);
    vn_encode_VkBool32(enc, &val->depthClamp);
    vn_encode_VkBool32(enc, &val->depthBiasClamp);
    vn_encode_VkBool32(enc, &val->fillModeNonSolid);
    vn_encode_VkBool32(enc, &val->depthBounds);
    vn_encode_VkBool32(enc, &val->wideLines);
    vn_encode_VkBool32(enc, &val->largePoints);
    vn_encode_VkBool32(enc, &val->alphaToOne);
    vn_encode_VkBool32(enc, &val->multiViewport);
    vn_encode_VkBool32(enc, &val->samplerAnisotropy);
    vn_encode_VkBool32(enc, &val->textureCompressionETC2);
    vn_encode_VkBool32(enc, &val->textureCompressionASTC_LDR);
    vn_encode_VkBool32(enc, &val->textureCompressionBC);
    vn_encode_VkBool32(enc, &val->occlusionQueryPrecise);
    vn_encode_VkBool32(enc, &val->pipelineStatisticsQuery);
    vn_encode_VkBool32(enc, &val->vertexPipelineStoresAndAtomics);
    vn_encode_VkBool32(enc, &val->fragmentStoresAndAtomics);
    vn_encode_VkBool32(enc, &val->shaderTessellationAndGeometryPointSize);
    vn_encode_VkBool32(enc, &val->shaderImageGatherExtended);
    vn_encode_VkBool32(enc, &val->shaderStorageImageExtendedFormats);
    vn_encode_VkBool32(enc, &val->shaderStorageImageMultisample);
    vn_encode_VkBool32(enc, &val->shaderStorageImageReadWithoutFormat);
    vn_encode_VkBool32(enc, &val->shaderStorageImageWriteWithoutFormat);
    vn_encode_VkBool32(enc, &val->shaderUniformBufferArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderSampledImageArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageBufferArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageImageArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderClipDistance);
    vn_encode_VkBool32(enc, &val->shaderCullDistance);
    vn_encode_VkBool32(enc, &val->shaderFloat64);
    vn_encode_VkBool32(enc, &val->shaderInt64);
    vn_encode_VkBool32(enc, &val->shaderInt16);
    vn_encode_VkBool32(enc, &val->shaderResourceResidency);
    vn_encode_VkBool32(enc, &val->shaderResourceMinLod);
    vn_encode_VkBool32(enc, &val->sparseBinding);
    vn_encode_VkBool32(enc, &val->sparseResidencyBuffer);
    vn_encode_VkBool32(enc, &val->sparseResidencyImage2D);
    vn_encode_VkBool32(enc, &val->sparseResidencyImage3D);
    vn_encode_VkBool32(enc, &val->sparseResidency2Samples);
    vn_encode_VkBool32(enc, &val->sparseResidency4Samples);
    vn_encode_VkBool32(enc, &val->sparseResidency8Samples);
    vn_encode_VkBool32(enc, &val->sparseResidency16Samples);
    vn_encode_VkBool32(enc, &val->sparseResidencyAliased);
    vn_encode_VkBool32(enc, &val->variableMultisampleRate);
    vn_encode_VkBool32(enc, &val->inheritedQueries);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFeatures *val)
{
    vn_decode_VkBool32(dec, &val->robustBufferAccess);
    vn_decode_VkBool32(dec, &val->fullDrawIndexUint32);
    vn_decode_VkBool32(dec, &val->imageCubeArray);
    vn_decode_VkBool32(dec, &val->independentBlend);
    vn_decode_VkBool32(dec, &val->geometryShader);
    vn_decode_VkBool32(dec, &val->tessellationShader);
    vn_decode_VkBool32(dec, &val->sampleRateShading);
    vn_decode_VkBool32(dec, &val->dualSrcBlend);
    vn_decode_VkBool32(dec, &val->logicOp);
    vn_decode_VkBool32(dec, &val->multiDrawIndirect);
    vn_decode_VkBool32(dec, &val->drawIndirectFirstInstance);
    vn_decode_VkBool32(dec, &val->depthClamp);
    vn_decode_VkBool32(dec, &val->depthBiasClamp);
    vn_decode_VkBool32(dec, &val->fillModeNonSolid);
    vn_decode_VkBool32(dec, &val->depthBounds);
    vn_decode_VkBool32(dec, &val->wideLines);
    vn_decode_VkBool32(dec, &val->largePoints);
    vn_decode_VkBool32(dec, &val->alphaToOne);
    vn_decode_VkBool32(dec, &val->multiViewport);
    vn_decode_VkBool32(dec, &val->samplerAnisotropy);
    vn_decode_VkBool32(dec, &val->textureCompressionETC2);
    vn_decode_VkBool32(dec, &val->textureCompressionASTC_LDR);
    vn_decode_VkBool32(dec, &val->textureCompressionBC);
    vn_decode_VkBool32(dec, &val->occlusionQueryPrecise);
    vn_decode_VkBool32(dec, &val->pipelineStatisticsQuery);
    vn_decode_VkBool32(dec, &val->vertexPipelineStoresAndAtomics);
    vn_decode_VkBool32(dec, &val->fragmentStoresAndAtomics);
    vn_decode_VkBool32(dec, &val->shaderTessellationAndGeometryPointSize);
    vn_decode_VkBool32(dec, &val->shaderImageGatherExtended);
    vn_decode_VkBool32(dec, &val->shaderStorageImageExtendedFormats);
    vn_decode_VkBool32(dec, &val->shaderStorageImageMultisample);
    vn_decode_VkBool32(dec, &val->shaderStorageImageReadWithoutFormat);
    vn_decode_VkBool32(dec, &val->shaderStorageImageWriteWithoutFormat);
    vn_decode_VkBool32(dec, &val->shaderUniformBufferArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderSampledImageArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageBufferArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageImageArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderClipDistance);
    vn_decode_VkBool32(dec, &val->shaderCullDistance);
    vn_decode_VkBool32(dec, &val->shaderFloat64);
    vn_decode_VkBool32(dec, &val->shaderInt64);
    vn_decode_VkBool32(dec, &val->shaderInt16);
    vn_decode_VkBool32(dec, &val->shaderResourceResidency);
    vn_decode_VkBool32(dec, &val->shaderResourceMinLod);
    vn_decode_VkBool32(dec, &val->sparseBinding);
    vn_decode_VkBool32(dec, &val->sparseResidencyBuffer);
    vn_decode_VkBool32(dec, &val->sparseResidencyImage2D);
    vn_decode_VkBool32(dec, &val->sparseResidencyImage3D);
    vn_decode_VkBool32(dec, &val->sparseResidency2Samples);
    vn_decode_VkBool32(dec, &val->sparseResidency4Samples);
    vn_decode_VkBool32(dec, &val->sparseResidency8Samples);
    vn_decode_VkBool32(dec, &val->sparseResidency16Samples);
    vn_decode_VkBool32(dec, &val->sparseResidencyAliased);
    vn_decode_VkBool32(dec, &val->variableMultisampleRate);
    vn_decode_VkBool32(dec, &val->inheritedQueries);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFeatures *val)
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
vn_encode_VkPhysicalDeviceVariablePointersFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVariablePointersFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceVariablePointersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->variablePointersStorageBuffer);
    vn_encode_VkBool32(enc, &val->variablePointers);
}

static inline void
vn_encode_VkPhysicalDeviceVariablePointersFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceVariablePointersFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES });
    vn_encode_VkPhysicalDeviceVariablePointersFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceVariablePointersFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVariablePointersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->variablePointersStorageBuffer);
    vn_decode_VkBool32(dec, &val->variablePointers);
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVariablePointersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVariablePointersFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->variablePointersStorageBuffer */
    /* skip val->variablePointers */
}

static inline void
vn_decode_VkPhysicalDeviceVariablePointersFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVariablePointersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVariablePointersFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceMultiviewFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceMultiviewFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->multiview);
    vn_encode_VkBool32(enc, &val->multiviewGeometryShader);
    vn_encode_VkBool32(enc, &val->multiviewTessellationShader);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceMultiviewFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES });
    vn_encode_VkPhysicalDeviceMultiviewFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceMultiviewFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMultiviewFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->multiview);
    vn_decode_VkBool32(dec, &val->multiviewGeometryShader);
    vn_decode_VkBool32(dec, &val->multiviewTessellationShader);
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMultiviewFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMultiviewFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->multiview */
    /* skip val->multiviewGeometryShader */
    /* skip val->multiviewTessellationShader */
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMultiviewFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMultiviewFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceMultiviewFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDevice16BitStorageFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDevice16BitStorageFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDevice16BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->storageBuffer16BitAccess);
    vn_encode_VkBool32(enc, &val->uniformAndStorageBuffer16BitAccess);
    vn_encode_VkBool32(enc, &val->storagePushConstant16);
    vn_encode_VkBool32(enc, &val->storageInputOutput16);
}

static inline void
vn_encode_VkPhysicalDevice16BitStorageFeatures(struct vn_cs_encoder *enc, const VkPhysicalDevice16BitStorageFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES });
    vn_encode_VkPhysicalDevice16BitStorageFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDevice16BitStorageFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDevice16BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->storageBuffer16BitAccess);
    vn_decode_VkBool32(dec, &val->uniformAndStorageBuffer16BitAccess);
    vn_decode_VkBool32(dec, &val->storagePushConstant16);
    vn_decode_VkBool32(dec, &val->storageInputOutput16);
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDevice16BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDevice16BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->storageBuffer16BitAccess */
    /* skip val->uniformAndStorageBuffer16BitAccess */
    /* skip val->storagePushConstant16 */
    /* skip val->storageInputOutput16 */
}

static inline void
vn_decode_VkPhysicalDevice16BitStorageFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDevice16BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice16BitStorageFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDevice16BitStorageFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->shaderSubgroupExtendedTypes);
}

static inline void
vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES });
    vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->shaderSubgroupExtendedTypes);
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderSubgroupExtendedTypes */
}

static inline void
vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->samplerYcbcrConversion);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES });
    vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->samplerYcbcrConversion);
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->samplerYcbcrConversion */
}

static inline void
vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSamplerYcbcrConversionFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->protectedMemory);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES });
    vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->protectedMemory);
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->protectedMemory */
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProtectedMemoryFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->shaderDrawParameters);
}

static inline void
vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES });
    vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->shaderDrawParameters);
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderDrawParameters */
}

static inline void
vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderDrawParametersFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->shaderFloat16);
    vn_encode_VkBool32(enc, &val->shaderInt8);
}

static inline void
vn_encode_VkPhysicalDeviceShaderFloat16Int8Features(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES });
    vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->shaderFloat16);
    vn_decode_VkBool32(dec, &val->shaderInt8);
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderFloat16 */
    /* skip val->shaderInt8 */
}

static inline void
vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderFloat16Int8Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceHostQueryResetFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceHostQueryResetFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceHostQueryResetFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->hostQueryReset);
}

static inline void
vn_encode_VkPhysicalDeviceHostQueryResetFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceHostQueryResetFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES });
    vn_encode_VkPhysicalDeviceHostQueryResetFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceHostQueryResetFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->hostQueryReset);
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->hostQueryReset */
}

static inline void
vn_decode_VkPhysicalDeviceHostQueryResetFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceHostQueryResetFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceHostQueryResetFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_encode_VkBool32(enc, &val->descriptorBindingPartiallyBound);
    vn_encode_VkBool32(enc, &val->descriptorBindingVariableDescriptorCount);
    vn_encode_VkBool32(enc, &val->runtimeDescriptorArray);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES });
    vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_decode_VkBool32(dec, &val->descriptorBindingPartiallyBound);
    vn_decode_VkBool32(dec, &val->descriptorBindingVariableDescriptorCount);
    vn_decode_VkBool32(dec, &val->runtimeDescriptorArray);
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDescriptorIndexingFeatures *val)
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
vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDescriptorIndexingFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->timelineSemaphore);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES });
    vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->timelineSemaphore);
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->timelineSemaphore */
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTimelineSemaphoreFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDevice8BitStorageFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDevice8BitStorageFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDevice8BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->storageBuffer8BitAccess);
    vn_encode_VkBool32(enc, &val->uniformAndStorageBuffer8BitAccess);
    vn_encode_VkBool32(enc, &val->storagePushConstant8);
}

static inline void
vn_encode_VkPhysicalDevice8BitStorageFeatures(struct vn_cs_encoder *enc, const VkPhysicalDevice8BitStorageFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES });
    vn_encode_VkPhysicalDevice8BitStorageFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDevice8BitStorageFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDevice8BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->storageBuffer8BitAccess);
    vn_decode_VkBool32(dec, &val->uniformAndStorageBuffer8BitAccess);
    vn_decode_VkBool32(dec, &val->storagePushConstant8);
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDevice8BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDevice8BitStorageFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->storageBuffer8BitAccess */
    /* skip val->uniformAndStorageBuffer8BitAccess */
    /* skip val->storagePushConstant8 */
}

static inline void
vn_decode_VkPhysicalDevice8BitStorageFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDevice8BitStorageFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevice8BitStorageFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDevice8BitStorageFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->vulkanMemoryModel);
    vn_encode_VkBool32(enc, &val->vulkanMemoryModelDeviceScope);
    vn_encode_VkBool32(enc, &val->vulkanMemoryModelAvailabilityVisibilityChains);
}

static inline void
vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES });
    vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->vulkanMemoryModel);
    vn_decode_VkBool32(dec, &val->vulkanMemoryModelDeviceScope);
    vn_decode_VkBool32(dec, &val->vulkanMemoryModelAvailabilityVisibilityChains);
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->vulkanMemoryModel */
    /* skip val->vulkanMemoryModelDeviceScope */
    /* skip val->vulkanMemoryModelAvailabilityVisibilityChains */
}

static inline void
vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkanMemoryModelFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->shaderBufferInt64Atomics);
    vn_encode_VkBool32(enc, &val->shaderSharedInt64Atomics);
}

static inline void
vn_encode_VkPhysicalDeviceShaderAtomicInt64Features(struct vn_cs_encoder *enc, const VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES });
    vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->shaderBufferInt64Atomics);
    vn_decode_VkBool32(dec, &val->shaderSharedInt64Atomics);
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->shaderBufferInt64Atomics */
    /* skip val->shaderSharedInt64Atomics */
}

static inline void
vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceShaderAtomicInt64Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->transformFeedback);
    vn_encode_VkBool32(enc, &val->geometryStreams);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT(struct vn_cs_encoder *enc, const VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT });
    vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->transformFeedback);
    vn_decode_VkBool32(dec, &val->geometryStreams);
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->transformFeedback */
    /* skip val->geometryStreams */
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTransformFeedbackFeaturesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->scalarBlockLayout);
}

static inline void
vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES });
    vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->scalarBlockLayout);
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->scalarBlockLayout */
}

static inline void
vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceScalarBlockLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->uniformBufferStandardLayout);
}

static inline void
vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES });
    vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->uniformBufferStandardLayout);
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->uniformBufferStandardLayout */
}

static inline void
vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceUniformBufferStandardLayoutFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->bufferDeviceAddress);
    vn_encode_VkBool32(enc, &val->bufferDeviceAddressCaptureReplay);
    vn_encode_VkBool32(enc, &val->bufferDeviceAddressMultiDevice);
}

static inline void
vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES });
    vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->bufferDeviceAddress);
    vn_decode_VkBool32(dec, &val->bufferDeviceAddressCaptureReplay);
    vn_decode_VkBool32(dec, &val->bufferDeviceAddressMultiDevice);
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->bufferDeviceAddress */
    /* skip val->bufferDeviceAddressCaptureReplay */
    /* skip val->bufferDeviceAddressMultiDevice */
}

static inline void
vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceBufferDeviceAddressFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->imagelessFramebuffer);
}

static inline void
vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES });
    vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->imagelessFramebuffer);
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->imagelessFramebuffer */
}

static inline void
vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImagelessFramebufferFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->separateDepthStencilLayouts);
}

static inline void
vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures(struct vn_cs_encoder *enc, const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES });
    vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->separateDepthStencilLayouts);
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->separateDepthStencilLayouts */
}

static inline void
vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceVulkan11Features_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Features_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan11Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->storageBuffer16BitAccess);
    vn_encode_VkBool32(enc, &val->uniformAndStorageBuffer16BitAccess);
    vn_encode_VkBool32(enc, &val->storagePushConstant16);
    vn_encode_VkBool32(enc, &val->storageInputOutput16);
    vn_encode_VkBool32(enc, &val->multiview);
    vn_encode_VkBool32(enc, &val->multiviewGeometryShader);
    vn_encode_VkBool32(enc, &val->multiviewTessellationShader);
    vn_encode_VkBool32(enc, &val->variablePointersStorageBuffer);
    vn_encode_VkBool32(enc, &val->variablePointers);
    vn_encode_VkBool32(enc, &val->protectedMemory);
    vn_encode_VkBool32(enc, &val->samplerYcbcrConversion);
    vn_encode_VkBool32(enc, &val->shaderDrawParameters);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Features(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan11Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES });
    vn_encode_VkPhysicalDeviceVulkan11Features_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan11Features_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan11Features_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan11Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->storageBuffer16BitAccess);
    vn_decode_VkBool32(dec, &val->uniformAndStorageBuffer16BitAccess);
    vn_decode_VkBool32(dec, &val->storagePushConstant16);
    vn_decode_VkBool32(dec, &val->storageInputOutput16);
    vn_decode_VkBool32(dec, &val->multiview);
    vn_decode_VkBool32(dec, &val->multiviewGeometryShader);
    vn_decode_VkBool32(dec, &val->multiviewTessellationShader);
    vn_decode_VkBool32(dec, &val->variablePointersStorageBuffer);
    vn_decode_VkBool32(dec, &val->variablePointers);
    vn_decode_VkBool32(dec, &val->protectedMemory);
    vn_decode_VkBool32(dec, &val->samplerYcbcrConversion);
    vn_decode_VkBool32(dec, &val->shaderDrawParameters);
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Features_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan11Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan11Features_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan11Features_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Features_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan11Features *val)
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
vn_decode_VkPhysicalDeviceVulkan11Features_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan11Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan11Features_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceVulkan11Features_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceVulkan12Features_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Features_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan12Features *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->samplerMirrorClampToEdge);
    vn_encode_VkBool32(enc, &val->drawIndirectCount);
    vn_encode_VkBool32(enc, &val->storageBuffer8BitAccess);
    vn_encode_VkBool32(enc, &val->uniformAndStorageBuffer8BitAccess);
    vn_encode_VkBool32(enc, &val->storagePushConstant8);
    vn_encode_VkBool32(enc, &val->shaderBufferInt64Atomics);
    vn_encode_VkBool32(enc, &val->shaderSharedInt64Atomics);
    vn_encode_VkBool32(enc, &val->shaderFloat16);
    vn_encode_VkBool32(enc, &val->shaderInt8);
    vn_encode_VkBool32(enc, &val->descriptorIndexing);
    vn_encode_VkBool32(enc, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_encode_VkBool32(enc, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_encode_VkBool32(enc, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_encode_VkBool32(enc, &val->descriptorBindingPartiallyBound);
    vn_encode_VkBool32(enc, &val->descriptorBindingVariableDescriptorCount);
    vn_encode_VkBool32(enc, &val->runtimeDescriptorArray);
    vn_encode_VkBool32(enc, &val->samplerFilterMinmax);
    vn_encode_VkBool32(enc, &val->scalarBlockLayout);
    vn_encode_VkBool32(enc, &val->imagelessFramebuffer);
    vn_encode_VkBool32(enc, &val->uniformBufferStandardLayout);
    vn_encode_VkBool32(enc, &val->shaderSubgroupExtendedTypes);
    vn_encode_VkBool32(enc, &val->separateDepthStencilLayouts);
    vn_encode_VkBool32(enc, &val->hostQueryReset);
    vn_encode_VkBool32(enc, &val->timelineSemaphore);
    vn_encode_VkBool32(enc, &val->bufferDeviceAddress);
    vn_encode_VkBool32(enc, &val->bufferDeviceAddressCaptureReplay);
    vn_encode_VkBool32(enc, &val->bufferDeviceAddressMultiDevice);
    vn_encode_VkBool32(enc, &val->vulkanMemoryModel);
    vn_encode_VkBool32(enc, &val->vulkanMemoryModelDeviceScope);
    vn_encode_VkBool32(enc, &val->vulkanMemoryModelAvailabilityVisibilityChains);
    vn_encode_VkBool32(enc, &val->shaderOutputViewportIndex);
    vn_encode_VkBool32(enc, &val->shaderOutputLayer);
    vn_encode_VkBool32(enc, &val->subgroupBroadcastDynamicId);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Features(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan12Features *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES });
    vn_encode_VkPhysicalDeviceVulkan12Features_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan12Features_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan12Features_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan12Features *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->samplerMirrorClampToEdge);
    vn_decode_VkBool32(dec, &val->drawIndirectCount);
    vn_decode_VkBool32(dec, &val->storageBuffer8BitAccess);
    vn_decode_VkBool32(dec, &val->uniformAndStorageBuffer8BitAccess);
    vn_decode_VkBool32(dec, &val->storagePushConstant8);
    vn_decode_VkBool32(dec, &val->shaderBufferInt64Atomics);
    vn_decode_VkBool32(dec, &val->shaderSharedInt64Atomics);
    vn_decode_VkBool32(dec, &val->shaderFloat16);
    vn_decode_VkBool32(dec, &val->shaderInt8);
    vn_decode_VkBool32(dec, &val->descriptorIndexing);
    vn_decode_VkBool32(dec, &val->shaderInputAttachmentArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderUniformTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageTexelBufferArrayDynamicIndexing);
    vn_decode_VkBool32(dec, &val->shaderUniformBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderSampledImageArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageImageArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderInputAttachmentArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderUniformTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->shaderStorageTexelBufferArrayNonUniformIndexing);
    vn_decode_VkBool32(dec, &val->descriptorBindingUniformBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingSampledImageUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingStorageImageUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingStorageBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingUniformTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingStorageTexelBufferUpdateAfterBind);
    vn_decode_VkBool32(dec, &val->descriptorBindingUpdateUnusedWhilePending);
    vn_decode_VkBool32(dec, &val->descriptorBindingPartiallyBound);
    vn_decode_VkBool32(dec, &val->descriptorBindingVariableDescriptorCount);
    vn_decode_VkBool32(dec, &val->runtimeDescriptorArray);
    vn_decode_VkBool32(dec, &val->samplerFilterMinmax);
    vn_decode_VkBool32(dec, &val->scalarBlockLayout);
    vn_decode_VkBool32(dec, &val->imagelessFramebuffer);
    vn_decode_VkBool32(dec, &val->uniformBufferStandardLayout);
    vn_decode_VkBool32(dec, &val->shaderSubgroupExtendedTypes);
    vn_decode_VkBool32(dec, &val->separateDepthStencilLayouts);
    vn_decode_VkBool32(dec, &val->hostQueryReset);
    vn_decode_VkBool32(dec, &val->timelineSemaphore);
    vn_decode_VkBool32(dec, &val->bufferDeviceAddress);
    vn_decode_VkBool32(dec, &val->bufferDeviceAddressCaptureReplay);
    vn_decode_VkBool32(dec, &val->bufferDeviceAddressMultiDevice);
    vn_decode_VkBool32(dec, &val->vulkanMemoryModel);
    vn_decode_VkBool32(dec, &val->vulkanMemoryModelDeviceScope);
    vn_decode_VkBool32(dec, &val->vulkanMemoryModelAvailabilityVisibilityChains);
    vn_decode_VkBool32(dec, &val->shaderOutputViewportIndex);
    vn_decode_VkBool32(dec, &val->shaderOutputLayer);
    vn_decode_VkBool32(dec, &val->subgroupBroadcastDynamicId);
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Features_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan12Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan12Features_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan12Features_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Features_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan12Features *val)
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
vn_decode_VkPhysicalDeviceVulkan12Features_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan12Features *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan12Features_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceVulkan12Features_self_partial_temp(dec, val);
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
vn_encode_VkPhysicalDeviceFeatures2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceVariablePointersFeatures_self(enc, (const VkPhysicalDeviceVariablePointersFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceMultiviewFeatures_self(enc, (const VkPhysicalDeviceMultiviewFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDevice16BitStorageFeatures_self(enc, (const VkPhysicalDevice16BitStorageFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self(enc, (const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self(enc, (const VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceProtectedMemoryFeatures_self(enc, (const VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderDrawParametersFeatures_self(enc, (const VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderFloat16Int8Features_self(enc, (const VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceHostQueryResetFeatures_self(enc, (const VkPhysicalDeviceHostQueryResetFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceDescriptorIndexingFeatures_self(enc, (const VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceTimelineSemaphoreFeatures_self(enc, (const VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDevice8BitStorageFeatures_self(enc, (const VkPhysicalDevice8BitStorageFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkanMemoryModelFeatures_self(enc, (const VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceShaderAtomicInt64Features_self(enc, (const VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self(enc, (const VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceScalarBlockLayoutFeatures_self(enc, (const VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self(enc, (const VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceBufferDeviceAddressFeatures_self(enc, (const VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceImagelessFramebufferFeatures_self(enc, (const VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self(enc, (const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan11Features_self(enc, (const VkPhysicalDeviceVulkan11Features *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan12Features_self(enc, (const VkPhysicalDeviceVulkan12Features *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceFeatures2_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceFeatures2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPhysicalDeviceFeatures(enc, &val->features);
}

static inline void
vn_encode_VkPhysicalDeviceFeatures2(struct vn_cs_encoder *enc, const VkPhysicalDeviceFeatures2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2 });
    vn_encode_VkPhysicalDeviceFeatures2_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceFeatures2_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVariablePointersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(dec, (VkPhysicalDeviceVariablePointersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceMultiviewFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(dec, (VkPhysicalDeviceMultiviewFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDevice16BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(dec, (VkPhysicalDevice16BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(dec, (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(dec, (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(dec, (VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(dec, (VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(dec, (VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceHostQueryResetFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(dec, (VkPhysicalDeviceHostQueryResetFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(dec, (VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(dec, (VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDevice8BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(dec, (VkPhysicalDevice8BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(dec, (VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(dec, (VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(dec, (VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(dec, (VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(dec, (VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(dec, (VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(dec, (VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(dec, (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan11Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(dec, (VkPhysicalDeviceVulkan11Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan12Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(dec, (VkPhysicalDeviceVulkan12Features *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFeatures2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceFeatures_temp(dec, &val->features);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFeatures2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceFeatures2_self_temp(dec, val);
}

static inline void *
vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVariablePointersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_partial_temp(dec, (VkPhysicalDeviceVariablePointersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceMultiviewFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceMultiviewFeatures_self_partial_temp(dec, (VkPhysicalDeviceMultiviewFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDevice16BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDevice16BitStorageFeatures_self_partial_temp(dec, (VkPhysicalDevice16BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_partial_temp(dec, (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_partial_temp(dec, (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_partial_temp(dec, (VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_partial_temp(dec, (VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_partial_temp(dec, (VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceHostQueryResetFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_partial_temp(dec, (VkPhysicalDeviceHostQueryResetFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_partial_temp(dec, (VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_partial_temp(dec, (VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDevice8BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDevice8BitStorageFeatures_self_partial_temp(dec, (VkPhysicalDevice8BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_partial_temp(dec, (VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_partial_temp(dec, (VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_partial_temp(dec, (VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_partial_temp(dec, (VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_partial_temp(dec, (VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_partial_temp(dec, (VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_partial_temp(dec, (VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_partial_temp(dec, (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan11Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan11Features_self_partial_temp(dec, (VkPhysicalDeviceVulkan11Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan12Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan12Features_self_partial_temp(dec, (VkPhysicalDeviceVulkan12Features *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFeatures2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceFeatures_partial_temp(dec, &val->features);
}

static inline void
vn_decode_VkPhysicalDeviceFeatures2_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFeatures2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceFeatures2_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceFeatures2_self_partial_temp(dec, val);
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
vn_decode_VkDeviceGroupDeviceCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupDeviceCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceGroupDeviceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->physicalDeviceCount);
    if (vn_peek_array_size(dec)) {
        val->pPhysicalDevices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPhysicalDevices) * val->physicalDeviceCount);
        if (!val->pPhysicalDevices) return;
        vn_decode_array_size(dec, val->physicalDeviceCount);
        for (uint32_t i = 0; i < val->physicalDeviceCount; i++)
            vn_decode_VkPhysicalDevice_lookup(dec, &((VkPhysicalDevice *)val->pPhysicalDevices)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pPhysicalDevices = NULL;
    }
}

static inline void
vn_decode_VkDeviceGroupDeviceCreateInfo_temp(struct vn_cs_decoder *dec, VkDeviceGroupDeviceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupDeviceCreateInfo_pnext_temp(dec);
    vn_decode_VkDeviceGroupDeviceCreateInfo_self_temp(dec, val);
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
vn_decode_VkDeviceCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceFeatures2));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceFeatures2_self_temp(dec, (VkPhysicalDeviceFeatures2 *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVariablePointersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVariablePointersFeatures_self_temp(dec, (VkPhysicalDeviceVariablePointersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceMultiviewFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceMultiviewFeatures_self_temp(dec, (VkPhysicalDeviceMultiviewFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDeviceGroupDeviceCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkDeviceGroupDeviceCreateInfo_self_temp(dec, (VkDeviceGroupDeviceCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDevice16BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDevice16BitStorageFeatures_self_temp(dec, (VkPhysicalDevice16BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures_self_temp(dec, (VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceSamplerYcbcrConversionFeatures_self_temp(dec, (VkPhysicalDeviceSamplerYcbcrConversionFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceProtectedMemoryFeatures_self_temp(dec, (VkPhysicalDeviceProtectedMemoryFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderDrawParametersFeatures_self_temp(dec, (VkPhysicalDeviceShaderDrawParametersFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderFloat16Int8Features_self_temp(dec, (VkPhysicalDeviceShaderFloat16Int8Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceHostQueryResetFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceHostQueryResetFeatures_self_temp(dec, (VkPhysicalDeviceHostQueryResetFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceDescriptorIndexingFeatures_self_temp(dec, (VkPhysicalDeviceDescriptorIndexingFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreFeatures_self_temp(dec, (VkPhysicalDeviceTimelineSemaphoreFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDevice8BitStorageFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDevice8BitStorageFeatures_self_temp(dec, (VkPhysicalDevice8BitStorageFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVulkanMemoryModelFeatures_self_temp(dec, (VkPhysicalDeviceVulkanMemoryModelFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceShaderAtomicInt64Features_self_temp(dec, (VkPhysicalDeviceShaderAtomicInt64Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceTransformFeedbackFeaturesEXT_self_temp(dec, (VkPhysicalDeviceTransformFeedbackFeaturesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceScalarBlockLayoutFeatures_self_temp(dec, (VkPhysicalDeviceScalarBlockLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceUniformBufferStandardLayoutFeatures_self_temp(dec, (VkPhysicalDeviceUniformBufferStandardLayoutFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceBufferDeviceAddressFeatures_self_temp(dec, (VkPhysicalDeviceBufferDeviceAddressFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceImagelessFramebufferFeatures_self_temp(dec, (VkPhysicalDeviceImagelessFramebufferFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures_self_temp(dec, (VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan11Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan11Features_self_temp(dec, (VkPhysicalDeviceVulkan11Features *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan12Features));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan12Features_self_temp(dec, (VkPhysicalDeviceVulkan12Features *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDeviceCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->queueCreateInfoCount);
    if (vn_peek_array_size(dec)) {
        val->pQueueCreateInfos = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pQueueCreateInfos) * val->queueCreateInfoCount);
        if (!val->pQueueCreateInfos) return;
        vn_decode_array_size(dec, val->queueCreateInfoCount);
        for (uint32_t i = 0; i < val->queueCreateInfoCount; i++)
            vn_decode_VkDeviceQueueCreateInfo_temp(dec, &((VkDeviceQueueCreateInfo *)val->pQueueCreateInfos)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pQueueCreateInfos = NULL;
    }
    vn_decode_uint32_t(dec, &val->enabledLayerCount);
    if (vn_peek_array_size(dec)) {
        val->ppEnabledLayerNames = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledLayerNames) * val->enabledLayerCount);
        if (!val->ppEnabledLayerNames) return;
        vn_decode_array_size(dec, val->enabledLayerCount);
        for (uint32_t i = 0; i < val->enabledLayerCount; i++) {
            const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
            ((char **)val->ppEnabledLayerNames)[i] = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledLayerNames[i]) * string_size);
            if (!val->ppEnabledLayerNames[i]) return;
            vn_decode_blob_array(dec, ((char **)val->ppEnabledLayerNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(dec, 0);
        val->ppEnabledLayerNames = NULL;
    }
    vn_decode_uint32_t(dec, &val->enabledExtensionCount);
    if (vn_peek_array_size(dec)) {
        val->ppEnabledExtensionNames = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledExtensionNames) * val->enabledExtensionCount);
        if (!val->ppEnabledExtensionNames) return;
        vn_decode_array_size(dec, val->enabledExtensionCount);
        for (uint32_t i = 0; i < val->enabledExtensionCount; i++) {
            const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
            ((char **)val->ppEnabledExtensionNames)[i] = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledExtensionNames[i]) * string_size);
            if (!val->ppEnabledExtensionNames[i]) return;
            vn_decode_blob_array(dec, ((char **)val->ppEnabledExtensionNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(dec, 0);
        val->ppEnabledExtensionNames = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pEnabledFeatures = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pEnabledFeatures));
        if (!val->pEnabledFeatures) return;
        vn_decode_VkPhysicalDeviceFeatures_temp(dec, (VkPhysicalDeviceFeatures *)val->pEnabledFeatures);
    } else {
        val->pEnabledFeatures = NULL;
    }
}

static inline void
vn_decode_VkDeviceCreateInfo_temp(struct vn_cs_decoder *dec, VkDeviceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceCreateInfo_pnext_temp(dec);
    vn_decode_VkDeviceCreateInfo_self_temp(dec, val);
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
vn_decode_VkInstanceCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkInstanceCreateInfo_self_temp(struct vn_cs_decoder *dec, VkInstanceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    if (vn_decode_simple_pointer(dec)) {
        val->pApplicationInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pApplicationInfo));
        if (!val->pApplicationInfo) return;
        vn_decode_VkApplicationInfo_temp(dec, (VkApplicationInfo *)val->pApplicationInfo);
    } else {
        val->pApplicationInfo = NULL;
    }
    vn_decode_uint32_t(dec, &val->enabledLayerCount);
    if (vn_peek_array_size(dec)) {
        val->ppEnabledLayerNames = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledLayerNames) * val->enabledLayerCount);
        if (!val->ppEnabledLayerNames) return;
        vn_decode_array_size(dec, val->enabledLayerCount);
        for (uint32_t i = 0; i < val->enabledLayerCount; i++) {
            const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
            ((char **)val->ppEnabledLayerNames)[i] = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledLayerNames[i]) * string_size);
            if (!val->ppEnabledLayerNames[i]) return;
            vn_decode_blob_array(dec, ((char **)val->ppEnabledLayerNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(dec, 0);
        val->ppEnabledLayerNames = NULL;
    }
    vn_decode_uint32_t(dec, &val->enabledExtensionCount);
    if (vn_peek_array_size(dec)) {
        val->ppEnabledExtensionNames = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledExtensionNames) * val->enabledExtensionCount);
        if (!val->ppEnabledExtensionNames) return;
        vn_decode_array_size(dec, val->enabledExtensionCount);
        for (uint32_t i = 0; i < val->enabledExtensionCount; i++) {
            const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
            ((char **)val->ppEnabledExtensionNames)[i] = vn_cs_decoder_alloc_temp(dec, sizeof(*val->ppEnabledExtensionNames[i]) * string_size);
            if (!val->ppEnabledExtensionNames[i]) return;
            vn_decode_blob_array(dec, ((char **)val->ppEnabledExtensionNames)[i], string_size);
        }
    } else {
        vn_decode_array_size(dec, 0);
        val->ppEnabledExtensionNames = NULL;
    }
}

static inline void
vn_decode_VkInstanceCreateInfo_temp(struct vn_cs_decoder *dec, VkInstanceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkInstanceCreateInfo_pnext_temp(dec);
    vn_decode_VkInstanceCreateInfo_self_temp(dec, val);
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
vn_encode_VkQueueFamilyProperties(struct vn_cs_encoder *enc, const VkQueueFamilyProperties *val)
{
    vn_encode_VkFlags(enc, &val->queueFlags);
    vn_encode_uint32_t(enc, &val->queueCount);
    vn_encode_uint32_t(enc, &val->timestampValidBits);
    vn_encode_VkExtent3D(enc, &val->minImageTransferGranularity);
}

static inline void
vn_decode_VkQueueFamilyProperties_partial_temp(struct vn_cs_decoder *dec, VkQueueFamilyProperties *val)
{
    /* skip val->queueFlags */
    /* skip val->queueCount */
    /* skip val->timestampValidBits */
    vn_decode_VkExtent3D_partial_temp(dec, &val->minImageTransferGranularity);
}

/* struct VkMemoryType */

static inline void
vn_encode_VkMemoryType(struct vn_cs_encoder *enc, const VkMemoryType *val)
{
    vn_encode_VkFlags(enc, &val->propertyFlags);
    vn_encode_uint32_t(enc, &val->heapIndex);
}

static inline void
vn_decode_VkMemoryType_partial_temp(struct vn_cs_decoder *dec, VkMemoryType *val)
{
    /* skip val->propertyFlags */
    /* skip val->heapIndex */
}

/* struct VkMemoryHeap */

static inline void
vn_encode_VkMemoryHeap(struct vn_cs_encoder *enc, const VkMemoryHeap *val)
{
    vn_encode_VkDeviceSize(enc, &val->size);
    vn_encode_VkFlags(enc, &val->flags);
}

static inline void
vn_decode_VkMemoryHeap_partial_temp(struct vn_cs_decoder *dec, VkMemoryHeap *val)
{
    /* skip val->size */
    /* skip val->flags */
}

/* struct VkPhysicalDeviceMemoryProperties */

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceMemoryProperties *val)
{
    vn_encode_uint32_t(enc, &val->memoryTypeCount);
    vn_encode_array_size(enc, VK_MAX_MEMORY_TYPES);
    for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; i++)
        vn_encode_VkMemoryType(enc, &val->memoryTypes[i]);
    vn_encode_uint32_t(enc, &val->memoryHeapCount);
    vn_encode_array_size(enc, VK_MAX_MEMORY_HEAPS);
    for (uint32_t i = 0; i < VK_MAX_MEMORY_HEAPS; i++)
        vn_encode_VkMemoryHeap(enc, &val->memoryHeaps[i]);
}

static inline void
vn_decode_VkPhysicalDeviceMemoryProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMemoryProperties *val)
{
    /* skip val->memoryTypeCount */
    {
        vn_decode_array_size(dec, VK_MAX_MEMORY_TYPES);
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; i++)
            vn_decode_VkMemoryType_partial_temp(dec, &val->memoryTypes[i]);
    }
    /* skip val->memoryHeapCount */
    {
        vn_decode_array_size(dec, VK_MAX_MEMORY_HEAPS);
        for (uint32_t i = 0; i < VK_MAX_MEMORY_HEAPS; i++)
            vn_decode_VkMemoryHeap_partial_temp(dec, &val->memoryHeaps[i]);
    }
}

/* struct VkExportMemoryAllocateInfo chain */

static inline void *
vn_decode_VkExportMemoryAllocateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExportMemoryAllocateInfo_self_temp(struct vn_cs_decoder *dec, VkExportMemoryAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->handleTypes);
}

static inline void
vn_decode_VkExportMemoryAllocateInfo_temp(struct vn_cs_decoder *dec, VkExportMemoryAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExportMemoryAllocateInfo_pnext_temp(dec);
    vn_decode_VkExportMemoryAllocateInfo_self_temp(dec, val);
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
vn_decode_VkMemoryAllocateFlagsInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkMemoryAllocateFlagsInfo_self_temp(struct vn_cs_decoder *dec, VkMemoryAllocateFlagsInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->deviceMask);
}

static inline void
vn_decode_VkMemoryAllocateFlagsInfo_temp(struct vn_cs_decoder *dec, VkMemoryAllocateFlagsInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryAllocateFlagsInfo_pnext_temp(dec);
    vn_decode_VkMemoryAllocateFlagsInfo_self_temp(dec, val);
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
vn_decode_VkMemoryDedicatedAllocateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkMemoryDedicatedAllocateInfo_self_temp(struct vn_cs_decoder *dec, VkMemoryDedicatedAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(dec, &val->image);
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
}

static inline void
vn_decode_VkMemoryDedicatedAllocateInfo_temp(struct vn_cs_decoder *dec, VkMemoryDedicatedAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryDedicatedAllocateInfo_pnext_temp(dec);
    vn_decode_VkMemoryDedicatedAllocateInfo_self_temp(dec, val);
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
vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_self_temp(struct vn_cs_decoder *dec, VkMemoryOpaqueCaptureAddressAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(dec, &val->opaqueCaptureAddress);
}

static inline void
vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_temp(struct vn_cs_decoder *dec, VkMemoryOpaqueCaptureAddressAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_pnext_temp(dec);
    vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_self_temp(dec, val);
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
vn_decode_VkMemoryAllocateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkExportMemoryAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(dec);
            vn_decode_VkExportMemoryAllocateInfo_self_temp(dec, (VkExportMemoryAllocateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkMemoryAllocateFlagsInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(dec);
            vn_decode_VkMemoryAllocateFlagsInfo_self_temp(dec, (VkMemoryAllocateFlagsInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkMemoryDedicatedAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(dec);
            vn_decode_VkMemoryDedicatedAllocateInfo_self_temp(dec, (VkMemoryDedicatedAllocateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkMemoryOpaqueCaptureAddressAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(dec);
            vn_decode_VkMemoryOpaqueCaptureAddressAllocateInfo_self_temp(dec, (VkMemoryOpaqueCaptureAddressAllocateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkMemoryAllocateInfo_self_temp(struct vn_cs_decoder *dec, VkMemoryAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDeviceSize(dec, &val->allocationSize);
    vn_decode_uint32_t(dec, &val->memoryTypeIndex);
}

static inline void
vn_decode_VkMemoryAllocateInfo_temp(struct vn_cs_decoder *dec, VkMemoryAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryAllocateInfo_pnext_temp(dec);
    vn_decode_VkMemoryAllocateInfo_self_temp(dec, val);
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
vn_encode_VkMemoryRequirements(struct vn_cs_encoder *enc, const VkMemoryRequirements *val)
{
    vn_encode_VkDeviceSize(enc, &val->size);
    vn_encode_VkDeviceSize(enc, &val->alignment);
    vn_encode_uint32_t(enc, &val->memoryTypeBits);
}

static inline void
vn_decode_VkMemoryRequirements_partial_temp(struct vn_cs_decoder *dec, VkMemoryRequirements *val)
{
    /* skip val->size */
    /* skip val->alignment */
    /* skip val->memoryTypeBits */
}

/* struct VkSparseImageFormatProperties */

static inline void
vn_encode_VkSparseImageFormatProperties(struct vn_cs_encoder *enc, const VkSparseImageFormatProperties *val)
{
    vn_encode_VkFlags(enc, &val->aspectMask);
    vn_encode_VkExtent3D(enc, &val->imageGranularity);
    vn_encode_VkFlags(enc, &val->flags);
}

static inline void
vn_decode_VkSparseImageFormatProperties_partial_temp(struct vn_cs_decoder *dec, VkSparseImageFormatProperties *val)
{
    /* skip val->aspectMask */
    vn_decode_VkExtent3D_partial_temp(dec, &val->imageGranularity);
    /* skip val->flags */
}

/* struct VkSparseImageMemoryRequirements */

static inline void
vn_encode_VkSparseImageMemoryRequirements(struct vn_cs_encoder *enc, const VkSparseImageMemoryRequirements *val)
{
    vn_encode_VkSparseImageFormatProperties(enc, &val->formatProperties);
    vn_encode_uint32_t(enc, &val->imageMipTailFirstLod);
    vn_encode_VkDeviceSize(enc, &val->imageMipTailSize);
    vn_encode_VkDeviceSize(enc, &val->imageMipTailOffset);
    vn_encode_VkDeviceSize(enc, &val->imageMipTailStride);
}

static inline void
vn_decode_VkSparseImageMemoryRequirements_partial_temp(struct vn_cs_decoder *dec, VkSparseImageMemoryRequirements *val)
{
    vn_decode_VkSparseImageFormatProperties_partial_temp(dec, &val->formatProperties);
    /* skip val->imageMipTailFirstLod */
    /* skip val->imageMipTailSize */
    /* skip val->imageMipTailOffset */
    /* skip val->imageMipTailStride */
}

/* struct VkMappedMemoryRange chain */

static inline void
vn_encode_VkMappedMemoryRange_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkMappedMemoryRange_self(struct vn_cs_encoder *enc, const VkMappedMemoryRange *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDeviceMemory(enc, &val->memory);
    vn_encode_VkDeviceSize(enc, &val->offset);
    vn_encode_VkDeviceSize(enc, &val->size);
}

static inline void
vn_encode_VkMappedMemoryRange(struct vn_cs_encoder *enc, const VkMappedMemoryRange *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE });
    vn_encode_VkMappedMemoryRange_pnext(enc, val->pNext);
    vn_encode_VkMappedMemoryRange_self(enc, val);
}

static inline void *
vn_decode_VkMappedMemoryRange_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkMappedMemoryRange_self_temp(struct vn_cs_decoder *dec, VkMappedMemoryRange *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDeviceMemory_lookup(dec, &val->memory);
    vn_decode_VkDeviceSize(dec, &val->offset);
    vn_decode_VkDeviceSize(dec, &val->size);
}

static inline void
vn_decode_VkMappedMemoryRange_temp(struct vn_cs_decoder *dec, VkMappedMemoryRange *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE);

    val->sType = stype;
    val->pNext = vn_decode_VkMappedMemoryRange_pnext_temp(dec);
    vn_decode_VkMappedMemoryRange_self_temp(dec, val);
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
vn_encode_VkFormatProperties(struct vn_cs_encoder *enc, const VkFormatProperties *val)
{
    vn_encode_VkFlags(enc, &val->linearTilingFeatures);
    vn_encode_VkFlags(enc, &val->optimalTilingFeatures);
    vn_encode_VkFlags(enc, &val->bufferFeatures);
}

static inline void
vn_decode_VkFormatProperties_partial_temp(struct vn_cs_decoder *dec, VkFormatProperties *val)
{
    /* skip val->linearTilingFeatures */
    /* skip val->optimalTilingFeatures */
    /* skip val->bufferFeatures */
}

/* struct VkImageFormatProperties */

static inline void
vn_encode_VkImageFormatProperties(struct vn_cs_encoder *enc, const VkImageFormatProperties *val)
{
    vn_encode_VkExtent3D(enc, &val->maxExtent);
    vn_encode_uint32_t(enc, &val->maxMipLevels);
    vn_encode_uint32_t(enc, &val->maxArrayLayers);
    vn_encode_VkFlags(enc, &val->sampleCounts);
    vn_encode_VkDeviceSize(enc, &val->maxResourceSize);
}

static inline void
vn_decode_VkImageFormatProperties_partial_temp(struct vn_cs_decoder *dec, VkImageFormatProperties *val)
{
    vn_decode_VkExtent3D_partial_temp(dec, &val->maxExtent);
    /* skip val->maxMipLevels */
    /* skip val->maxArrayLayers */
    /* skip val->sampleCounts */
    /* skip val->maxResourceSize */
}

/* struct VkDescriptorBufferInfo */

static inline void
vn_decode_VkDescriptorBufferInfo_temp(struct vn_cs_decoder *dec, VkDescriptorBufferInfo *val)
{
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
    vn_decode_VkDeviceSize(dec, &val->offset);
    vn_decode_VkDeviceSize(dec, &val->range);
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
vn_decode_VkDescriptorImageInfo_temp(struct vn_cs_decoder *dec, VkDescriptorImageInfo *val)
{
    vn_decode_VkSampler_lookup(dec, &val->sampler);
    vn_decode_VkImageView_lookup(dec, &val->imageView);
    vn_decode_VkImageLayout(dec, &val->imageLayout);
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
vn_decode_VkWriteDescriptorSet_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkWriteDescriptorSet_self_temp(struct vn_cs_decoder *dec, VkWriteDescriptorSet *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDescriptorSet_lookup(dec, &val->dstSet);
    vn_decode_uint32_t(dec, &val->dstBinding);
    vn_decode_uint32_t(dec, &val->dstArrayElement);
    vn_decode_uint32_t(dec, &val->descriptorCount);
    vn_decode_VkDescriptorType(dec, &val->descriptorType);
    if (vn_peek_array_size(dec)) {
        val->pImageInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pImageInfo) * val->descriptorCount);
        if (!val->pImageInfo) return;
        vn_decode_array_size(dec, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkDescriptorImageInfo_temp(dec, &((VkDescriptorImageInfo *)val->pImageInfo)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pImageInfo = NULL;
    }
    if (vn_peek_array_size(dec)) {
        val->pBufferInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBufferInfo) * val->descriptorCount);
        if (!val->pBufferInfo) return;
        vn_decode_array_size(dec, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkDescriptorBufferInfo_temp(dec, &((VkDescriptorBufferInfo *)val->pBufferInfo)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pBufferInfo = NULL;
    }
    if (vn_peek_array_size(dec)) {
        val->pTexelBufferView = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pTexelBufferView) * val->descriptorCount);
        if (!val->pTexelBufferView) return;
        vn_decode_array_size(dec, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkBufferView_lookup(dec, &((VkBufferView *)val->pTexelBufferView)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pTexelBufferView = NULL;
    }
}

static inline void
vn_decode_VkWriteDescriptorSet_temp(struct vn_cs_decoder *dec, VkWriteDescriptorSet *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET);

    val->sType = stype;
    val->pNext = vn_decode_VkWriteDescriptorSet_pnext_temp(dec);
    vn_decode_VkWriteDescriptorSet_self_temp(dec, val);
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
vn_decode_VkCopyDescriptorSet_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkCopyDescriptorSet_self_temp(struct vn_cs_decoder *dec, VkCopyDescriptorSet *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDescriptorSet_lookup(dec, &val->srcSet);
    vn_decode_uint32_t(dec, &val->srcBinding);
    vn_decode_uint32_t(dec, &val->srcArrayElement);
    vn_decode_VkDescriptorSet_lookup(dec, &val->dstSet);
    vn_decode_uint32_t(dec, &val->dstBinding);
    vn_decode_uint32_t(dec, &val->dstArrayElement);
    vn_decode_uint32_t(dec, &val->descriptorCount);
}

static inline void
vn_decode_VkCopyDescriptorSet_temp(struct vn_cs_decoder *dec, VkCopyDescriptorSet *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET);

    val->sType = stype;
    val->pNext = vn_decode_VkCopyDescriptorSet_pnext_temp(dec);
    vn_decode_VkCopyDescriptorSet_self_temp(dec, val);
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
vn_decode_VkExternalMemoryBufferCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExternalMemoryBufferCreateInfo_self_temp(struct vn_cs_decoder *dec, VkExternalMemoryBufferCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->handleTypes);
}

static inline void
vn_decode_VkExternalMemoryBufferCreateInfo_temp(struct vn_cs_decoder *dec, VkExternalMemoryBufferCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalMemoryBufferCreateInfo_pnext_temp(dec);
    vn_decode_VkExternalMemoryBufferCreateInfo_self_temp(dec, val);
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
vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_self_temp(struct vn_cs_decoder *dec, VkBufferOpaqueCaptureAddressCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(dec, &val->opaqueCaptureAddress);
}

static inline void
vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_temp(struct vn_cs_decoder *dec, VkBufferOpaqueCaptureAddressCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_pnext_temp(dec);
    vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_self_temp(dec, val);
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
vn_decode_VkBufferCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkExternalMemoryBufferCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBufferCreateInfo_pnext_temp(dec);
            vn_decode_VkExternalMemoryBufferCreateInfo_self_temp(dec, (VkExternalMemoryBufferCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkBufferOpaqueCaptureAddressCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBufferCreateInfo_pnext_temp(dec);
            vn_decode_VkBufferOpaqueCaptureAddressCreateInfo_self_temp(dec, (VkBufferOpaqueCaptureAddressCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBufferCreateInfo_self_temp(struct vn_cs_decoder *dec, VkBufferCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkDeviceSize(dec, &val->size);
    vn_decode_VkFlags(dec, &val->usage);
    vn_decode_VkSharingMode(dec, &val->sharingMode);
    vn_decode_uint32_t(dec, &val->queueFamilyIndexCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->queueFamilyIndexCount);
        val->pQueueFamilyIndices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pQueueFamilyIndices) * array_size);
        if (!val->pQueueFamilyIndices) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pQueueFamilyIndices, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pQueueFamilyIndices = NULL;
    }
}

static inline void
vn_decode_VkBufferCreateInfo_temp(struct vn_cs_decoder *dec, VkBufferCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferCreateInfo_pnext_temp(dec);
    vn_decode_VkBufferCreateInfo_self_temp(dec, val);
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
vn_decode_VkBufferViewCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBufferViewCreateInfo_self_temp(struct vn_cs_decoder *dec, VkBufferViewCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkDeviceSize(dec, &val->offset);
    vn_decode_VkDeviceSize(dec, &val->range);
}

static inline void
vn_decode_VkBufferViewCreateInfo_temp(struct vn_cs_decoder *dec, VkBufferViewCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferViewCreateInfo_pnext_temp(dec);
    vn_decode_VkBufferViewCreateInfo_self_temp(dec, val);
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
vn_decode_VkImageSubresource_temp(struct vn_cs_decoder *dec, VkImageSubresource *val)
{
    vn_decode_VkFlags(dec, &val->aspectMask);
    vn_decode_uint32_t(dec, &val->mipLevel);
    vn_decode_uint32_t(dec, &val->arrayLayer);
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
vn_decode_VkImageSubresourceLayers_temp(struct vn_cs_decoder *dec, VkImageSubresourceLayers *val)
{
    vn_decode_VkFlags(dec, &val->aspectMask);
    vn_decode_uint32_t(dec, &val->mipLevel);
    vn_decode_uint32_t(dec, &val->baseArrayLayer);
    vn_decode_uint32_t(dec, &val->layerCount);
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
vn_decode_VkImageSubresourceRange_temp(struct vn_cs_decoder *dec, VkImageSubresourceRange *val)
{
    vn_decode_VkFlags(dec, &val->aspectMask);
    vn_decode_uint32_t(dec, &val->baseMipLevel);
    vn_decode_uint32_t(dec, &val->levelCount);
    vn_decode_uint32_t(dec, &val->baseArrayLayer);
    vn_decode_uint32_t(dec, &val->layerCount);
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
vn_decode_VkMemoryBarrier_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkMemoryBarrier_self_temp(struct vn_cs_decoder *dec, VkMemoryBarrier *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->srcAccessMask);
    vn_decode_VkFlags(dec, &val->dstAccessMask);
}

static inline void
vn_decode_VkMemoryBarrier_temp(struct vn_cs_decoder *dec, VkMemoryBarrier *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_BARRIER);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryBarrier_pnext_temp(dec);
    vn_decode_VkMemoryBarrier_self_temp(dec, val);
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
vn_decode_VkBufferMemoryBarrier_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBufferMemoryBarrier_self_temp(struct vn_cs_decoder *dec, VkBufferMemoryBarrier *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->srcAccessMask);
    vn_decode_VkFlags(dec, &val->dstAccessMask);
    vn_decode_uint32_t(dec, &val->srcQueueFamilyIndex);
    vn_decode_uint32_t(dec, &val->dstQueueFamilyIndex);
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
    vn_decode_VkDeviceSize(dec, &val->offset);
    vn_decode_VkDeviceSize(dec, &val->size);
}

static inline void
vn_decode_VkBufferMemoryBarrier_temp(struct vn_cs_decoder *dec, VkBufferMemoryBarrier *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferMemoryBarrier_pnext_temp(dec);
    vn_decode_VkBufferMemoryBarrier_self_temp(dec, val);
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
vn_decode_VkImageMemoryBarrier_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageMemoryBarrier_self_temp(struct vn_cs_decoder *dec, VkImageMemoryBarrier *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->srcAccessMask);
    vn_decode_VkFlags(dec, &val->dstAccessMask);
    vn_decode_VkImageLayout(dec, &val->oldLayout);
    vn_decode_VkImageLayout(dec, &val->newLayout);
    vn_decode_uint32_t(dec, &val->srcQueueFamilyIndex);
    vn_decode_uint32_t(dec, &val->dstQueueFamilyIndex);
    vn_decode_VkImage_lookup(dec, &val->image);
    vn_decode_VkImageSubresourceRange_temp(dec, &val->subresourceRange);
}

static inline void
vn_decode_VkImageMemoryBarrier_temp(struct vn_cs_decoder *dec, VkImageMemoryBarrier *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER);

    val->sType = stype;
    val->pNext = vn_decode_VkImageMemoryBarrier_pnext_temp(dec);
    vn_decode_VkImageMemoryBarrier_self_temp(dec, val);
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
vn_decode_VkExternalMemoryImageCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExternalMemoryImageCreateInfo_self_temp(struct vn_cs_decoder *dec, VkExternalMemoryImageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->handleTypes);
}

static inline void
vn_decode_VkExternalMemoryImageCreateInfo_temp(struct vn_cs_decoder *dec, VkExternalMemoryImageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalMemoryImageCreateInfo_pnext_temp(dec);
    vn_decode_VkExternalMemoryImageCreateInfo_self_temp(dec, val);
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
vn_decode_VkImageFormatListCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageFormatListCreateInfo_self_temp(struct vn_cs_decoder *dec, VkImageFormatListCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->viewFormatCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->viewFormatCount);
        val->pViewFormats = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pViewFormats) * array_size);
        if (!val->pViewFormats) return;
        vn_decode_VkFormat_array(dec, (VkFormat *)val->pViewFormats, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pViewFormats = NULL;
    }
}

static inline void
vn_decode_VkImageFormatListCreateInfo_temp(struct vn_cs_decoder *dec, VkImageFormatListCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageFormatListCreateInfo_pnext_temp(dec);
    vn_decode_VkImageFormatListCreateInfo_self_temp(dec, val);
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
vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_self_temp(struct vn_cs_decoder *dec, VkImageDrmFormatModifierListCreateInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->drmFormatModifierCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->drmFormatModifierCount);
        val->pDrmFormatModifiers = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDrmFormatModifiers) * array_size);
        if (!val->pDrmFormatModifiers) return;
        vn_decode_uint64_t_array(dec, (uint64_t *)val->pDrmFormatModifiers, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDrmFormatModifiers = NULL;
    }
}

static inline void
vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_temp(struct vn_cs_decoder *dec, VkImageDrmFormatModifierListCreateInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_pnext_temp(dec);
    vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_self_temp(dec, val);
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
vn_encode_VkSubresourceLayout(struct vn_cs_encoder *enc, const VkSubresourceLayout *val)
{
    vn_encode_VkDeviceSize(enc, &val->offset);
    vn_encode_VkDeviceSize(enc, &val->size);
    vn_encode_VkDeviceSize(enc, &val->rowPitch);
    vn_encode_VkDeviceSize(enc, &val->arrayPitch);
    vn_encode_VkDeviceSize(enc, &val->depthPitch);
}

static inline void
vn_decode_VkSubresourceLayout_temp(struct vn_cs_decoder *dec, VkSubresourceLayout *val)
{
    vn_decode_VkDeviceSize(dec, &val->offset);
    vn_decode_VkDeviceSize(dec, &val->size);
    vn_decode_VkDeviceSize(dec, &val->rowPitch);
    vn_decode_VkDeviceSize(dec, &val->arrayPitch);
    vn_decode_VkDeviceSize(dec, &val->depthPitch);
}

static inline void
vn_decode_VkSubresourceLayout_partial_temp(struct vn_cs_decoder *dec, VkSubresourceLayout *val)
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
vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_self_temp(struct vn_cs_decoder *dec, VkImageDrmFormatModifierExplicitCreateInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(dec, &val->drmFormatModifier);
    vn_decode_uint32_t(dec, &val->drmFormatModifierPlaneCount);
    if (vn_peek_array_size(dec)) {
        val->pPlaneLayouts = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPlaneLayouts) * val->drmFormatModifierPlaneCount);
        if (!val->pPlaneLayouts) return;
        vn_decode_array_size(dec, val->drmFormatModifierPlaneCount);
        for (uint32_t i = 0; i < val->drmFormatModifierPlaneCount; i++)
            vn_decode_VkSubresourceLayout_temp(dec, &((VkSubresourceLayout *)val->pPlaneLayouts)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pPlaneLayouts = NULL;
    }
}

static inline void
vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_temp(struct vn_cs_decoder *dec, VkImageDrmFormatModifierExplicitCreateInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_pnext_temp(dec);
    vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_self_temp(dec, val);
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
vn_decode_VkImageStencilUsageCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageStencilUsageCreateInfo_self_temp(struct vn_cs_decoder *dec, VkImageStencilUsageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->stencilUsage);
}

static inline void
vn_decode_VkImageStencilUsageCreateInfo_temp(struct vn_cs_decoder *dec, VkImageStencilUsageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageStencilUsageCreateInfo_pnext_temp(dec);
    vn_decode_VkImageStencilUsageCreateInfo_self_temp(dec, val);
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
vn_decode_VkImageCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkExternalMemoryImageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(dec);
            vn_decode_VkExternalMemoryImageCreateInfo_self_temp(dec, (VkExternalMemoryImageCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImageFormatListCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(dec);
            vn_decode_VkImageFormatListCreateInfo_self_temp(dec, (VkImageFormatListCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImageDrmFormatModifierListCreateInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(dec);
            vn_decode_VkImageDrmFormatModifierListCreateInfoEXT_self_temp(dec, (VkImageDrmFormatModifierListCreateInfoEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImageDrmFormatModifierExplicitCreateInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(dec);
            vn_decode_VkImageDrmFormatModifierExplicitCreateInfoEXT_self_temp(dec, (VkImageDrmFormatModifierExplicitCreateInfoEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImageStencilUsageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageCreateInfo_pnext_temp(dec);
            vn_decode_VkImageStencilUsageCreateInfo_self_temp(dec, (VkImageStencilUsageCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageCreateInfo_self_temp(struct vn_cs_decoder *dec, VkImageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkImageType(dec, &val->imageType);
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkExtent3D_temp(dec, &val->extent);
    vn_decode_uint32_t(dec, &val->mipLevels);
    vn_decode_uint32_t(dec, &val->arrayLayers);
    vn_decode_VkSampleCountFlagBits(dec, &val->samples);
    vn_decode_VkImageTiling(dec, &val->tiling);
    vn_decode_VkFlags(dec, &val->usage);
    vn_decode_VkSharingMode(dec, &val->sharingMode);
    vn_decode_uint32_t(dec, &val->queueFamilyIndexCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->queueFamilyIndexCount);
        val->pQueueFamilyIndices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pQueueFamilyIndices) * array_size);
        if (!val->pQueueFamilyIndices) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pQueueFamilyIndices, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pQueueFamilyIndices = NULL;
    }
    vn_decode_VkImageLayout(dec, &val->initialLayout);
}

static inline void
vn_decode_VkImageCreateInfo_temp(struct vn_cs_decoder *dec, VkImageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageCreateInfo_pnext_temp(dec);
    vn_decode_VkImageCreateInfo_self_temp(dec, val);
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
vn_decode_VkImageViewUsageCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageViewUsageCreateInfo_self_temp(struct vn_cs_decoder *dec, VkImageViewUsageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->usage);
}

static inline void
vn_decode_VkImageViewUsageCreateInfo_temp(struct vn_cs_decoder *dec, VkImageViewUsageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageViewUsageCreateInfo_pnext_temp(dec);
    vn_decode_VkImageViewUsageCreateInfo_self_temp(dec, val);
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
vn_decode_VkSamplerYcbcrConversionInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSamplerYcbcrConversionInfo_self_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSamplerYcbcrConversion_lookup(dec, &val->conversion);
}

static inline void
vn_decode_VkSamplerYcbcrConversionInfo_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerYcbcrConversionInfo_pnext_temp(dec);
    vn_decode_VkSamplerYcbcrConversionInfo_self_temp(dec, val);
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
vn_decode_VkImageViewCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImageViewUsageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageViewCreateInfo_pnext_temp(dec);
            vn_decode_VkImageViewUsageCreateInfo_self_temp(dec, (VkImageViewUsageCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSamplerYcbcrConversionInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageViewCreateInfo_pnext_temp(dec);
            vn_decode_VkSamplerYcbcrConversionInfo_self_temp(dec, (VkSamplerYcbcrConversionInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageViewCreateInfo_self_temp(struct vn_cs_decoder *dec, VkImageViewCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkImage_lookup(dec, &val->image);
    vn_decode_VkImageViewType(dec, &val->viewType);
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkComponentMapping_temp(dec, &val->components);
    vn_decode_VkImageSubresourceRange_temp(dec, &val->subresourceRange);
}

static inline void
vn_decode_VkImageViewCreateInfo_temp(struct vn_cs_decoder *dec, VkImageViewCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImageViewCreateInfo_pnext_temp(dec);
    vn_decode_VkImageViewCreateInfo_self_temp(dec, val);
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
vn_decode_VkBufferCopy_temp(struct vn_cs_decoder *dec, VkBufferCopy *val)
{
    vn_decode_VkDeviceSize(dec, &val->srcOffset);
    vn_decode_VkDeviceSize(dec, &val->dstOffset);
    vn_decode_VkDeviceSize(dec, &val->size);
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
vn_decode_VkSparseMemoryBind_temp(struct vn_cs_decoder *dec, VkSparseMemoryBind *val)
{
    vn_decode_VkDeviceSize(dec, &val->resourceOffset);
    vn_decode_VkDeviceSize(dec, &val->size);
    vn_decode_VkDeviceMemory_lookup(dec, &val->memory);
    vn_decode_VkDeviceSize(dec, &val->memoryOffset);
    vn_decode_VkFlags(dec, &val->flags);
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
vn_decode_VkSparseImageMemoryBind_temp(struct vn_cs_decoder *dec, VkSparseImageMemoryBind *val)
{
    vn_decode_VkImageSubresource_temp(dec, &val->subresource);
    vn_decode_VkOffset3D_temp(dec, &val->offset);
    vn_decode_VkExtent3D_temp(dec, &val->extent);
    vn_decode_VkDeviceMemory_lookup(dec, &val->memory);
    vn_decode_VkDeviceSize(dec, &val->memoryOffset);
    vn_decode_VkFlags(dec, &val->flags);
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
vn_decode_VkSparseBufferMemoryBindInfo_temp(struct vn_cs_decoder *dec, VkSparseBufferMemoryBindInfo *val)
{
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
    vn_decode_uint32_t(dec, &val->bindCount);
    if (vn_peek_array_size(dec)) {
        val->pBinds = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBinds) * val->bindCount);
        if (!val->pBinds) return;
        vn_decode_array_size(dec, val->bindCount);
        for (uint32_t i = 0; i < val->bindCount; i++)
            vn_decode_VkSparseMemoryBind_temp(dec, &((VkSparseMemoryBind *)val->pBinds)[i]);
    } else {
        vn_decode_array_size(dec, 0);
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
vn_decode_VkSparseImageOpaqueMemoryBindInfo_temp(struct vn_cs_decoder *dec, VkSparseImageOpaqueMemoryBindInfo *val)
{
    vn_decode_VkImage_lookup(dec, &val->image);
    vn_decode_uint32_t(dec, &val->bindCount);
    if (vn_peek_array_size(dec)) {
        val->pBinds = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBinds) * val->bindCount);
        if (!val->pBinds) return;
        vn_decode_array_size(dec, val->bindCount);
        for (uint32_t i = 0; i < val->bindCount; i++)
            vn_decode_VkSparseMemoryBind_temp(dec, &((VkSparseMemoryBind *)val->pBinds)[i]);
    } else {
        vn_decode_array_size(dec, 0);
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
vn_decode_VkSparseImageMemoryBindInfo_temp(struct vn_cs_decoder *dec, VkSparseImageMemoryBindInfo *val)
{
    vn_decode_VkImage_lookup(dec, &val->image);
    vn_decode_uint32_t(dec, &val->bindCount);
    if (vn_peek_array_size(dec)) {
        val->pBinds = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBinds) * val->bindCount);
        if (!val->pBinds) return;
        vn_decode_array_size(dec, val->bindCount);
        for (uint32_t i = 0; i < val->bindCount; i++)
            vn_decode_VkSparseImageMemoryBind_temp(dec, &((VkSparseImageMemoryBind *)val->pBinds)[i]);
    } else {
        vn_decode_array_size(dec, 0);
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
vn_decode_VkDeviceGroupBindSparseInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupBindSparseInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceGroupBindSparseInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->resourceDeviceIndex);
    vn_decode_uint32_t(dec, &val->memoryDeviceIndex);
}

static inline void
vn_decode_VkDeviceGroupBindSparseInfo_temp(struct vn_cs_decoder *dec, VkDeviceGroupBindSparseInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupBindSparseInfo_pnext_temp(dec);
    vn_decode_VkDeviceGroupBindSparseInfo_self_temp(dec, val);
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
vn_decode_VkTimelineSemaphoreSubmitInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(struct vn_cs_decoder *dec, VkTimelineSemaphoreSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->waitSemaphoreValueCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->waitSemaphoreValueCount);
        val->pWaitSemaphoreValues = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pWaitSemaphoreValues) * array_size);
        if (!val->pWaitSemaphoreValues) return;
        vn_decode_uint64_t_array(dec, (uint64_t *)val->pWaitSemaphoreValues, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pWaitSemaphoreValues = NULL;
    }
    vn_decode_uint32_t(dec, &val->signalSemaphoreValueCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->signalSemaphoreValueCount);
        val->pSignalSemaphoreValues = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSignalSemaphoreValues) * array_size);
        if (!val->pSignalSemaphoreValues) return;
        vn_decode_uint64_t_array(dec, (uint64_t *)val->pSignalSemaphoreValues, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSignalSemaphoreValues = NULL;
    }
}

static inline void
vn_decode_VkTimelineSemaphoreSubmitInfo_temp(struct vn_cs_decoder *dec, VkTimelineSemaphoreSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkTimelineSemaphoreSubmitInfo_pnext_temp(dec);
    vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(dec, val);
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
vn_decode_VkBindSparseInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDeviceGroupBindSparseInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindSparseInfo_pnext_temp(dec);
            vn_decode_VkDeviceGroupBindSparseInfo_self_temp(dec, (VkDeviceGroupBindSparseInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkTimelineSemaphoreSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindSparseInfo_pnext_temp(dec);
            vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(dec, (VkTimelineSemaphoreSubmitInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBindSparseInfo_self_temp(struct vn_cs_decoder *dec, VkBindSparseInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->waitSemaphoreCount);
    if (vn_peek_array_size(dec)) {
        val->pWaitSemaphores = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pWaitSemaphores) * val->waitSemaphoreCount);
        if (!val->pWaitSemaphores) return;
        vn_decode_array_size(dec, val->waitSemaphoreCount);
        for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(dec, &((VkSemaphore *)val->pWaitSemaphores)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pWaitSemaphores = NULL;
    }
    vn_decode_uint32_t(dec, &val->bufferBindCount);
    if (vn_peek_array_size(dec)) {
        val->pBufferBinds = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBufferBinds) * val->bufferBindCount);
        if (!val->pBufferBinds) return;
        vn_decode_array_size(dec, val->bufferBindCount);
        for (uint32_t i = 0; i < val->bufferBindCount; i++)
            vn_decode_VkSparseBufferMemoryBindInfo_temp(dec, &((VkSparseBufferMemoryBindInfo *)val->pBufferBinds)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pBufferBinds = NULL;
    }
    vn_decode_uint32_t(dec, &val->imageOpaqueBindCount);
    if (vn_peek_array_size(dec)) {
        val->pImageOpaqueBinds = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pImageOpaqueBinds) * val->imageOpaqueBindCount);
        if (!val->pImageOpaqueBinds) return;
        vn_decode_array_size(dec, val->imageOpaqueBindCount);
        for (uint32_t i = 0; i < val->imageOpaqueBindCount; i++)
            vn_decode_VkSparseImageOpaqueMemoryBindInfo_temp(dec, &((VkSparseImageOpaqueMemoryBindInfo *)val->pImageOpaqueBinds)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pImageOpaqueBinds = NULL;
    }
    vn_decode_uint32_t(dec, &val->imageBindCount);
    if (vn_peek_array_size(dec)) {
        val->pImageBinds = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pImageBinds) * val->imageBindCount);
        if (!val->pImageBinds) return;
        vn_decode_array_size(dec, val->imageBindCount);
        for (uint32_t i = 0; i < val->imageBindCount; i++)
            vn_decode_VkSparseImageMemoryBindInfo_temp(dec, &((VkSparseImageMemoryBindInfo *)val->pImageBinds)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pImageBinds = NULL;
    }
    vn_decode_uint32_t(dec, &val->signalSemaphoreCount);
    if (vn_peek_array_size(dec)) {
        val->pSignalSemaphores = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSignalSemaphores) * val->signalSemaphoreCount);
        if (!val->pSignalSemaphores) return;
        vn_decode_array_size(dec, val->signalSemaphoreCount);
        for (uint32_t i = 0; i < val->signalSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(dec, &((VkSemaphore *)val->pSignalSemaphores)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSignalSemaphores = NULL;
    }
}

static inline void
vn_decode_VkBindSparseInfo_temp(struct vn_cs_decoder *dec, VkBindSparseInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_SPARSE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindSparseInfo_pnext_temp(dec);
    vn_decode_VkBindSparseInfo_self_temp(dec, val);
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
vn_decode_VkImageCopy_temp(struct vn_cs_decoder *dec, VkImageCopy *val)
{
    vn_decode_VkImageSubresourceLayers_temp(dec, &val->srcSubresource);
    vn_decode_VkOffset3D_temp(dec, &val->srcOffset);
    vn_decode_VkImageSubresourceLayers_temp(dec, &val->dstSubresource);
    vn_decode_VkOffset3D_temp(dec, &val->dstOffset);
    vn_decode_VkExtent3D_temp(dec, &val->extent);
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
vn_decode_VkImageBlit_temp(struct vn_cs_decoder *dec, VkImageBlit *val)
{
    vn_decode_VkImageSubresourceLayers_temp(dec, &val->srcSubresource);
    {
        vn_decode_array_size(dec, 2);
        for (uint32_t i = 0; i < 2; i++)
            vn_decode_VkOffset3D_temp(dec, &val->srcOffsets[i]);
    }
    vn_decode_VkImageSubresourceLayers_temp(dec, &val->dstSubresource);
    {
        vn_decode_array_size(dec, 2);
        for (uint32_t i = 0; i < 2; i++)
            vn_decode_VkOffset3D_temp(dec, &val->dstOffsets[i]);
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
vn_decode_VkBufferImageCopy_temp(struct vn_cs_decoder *dec, VkBufferImageCopy *val)
{
    vn_decode_VkDeviceSize(dec, &val->bufferOffset);
    vn_decode_uint32_t(dec, &val->bufferRowLength);
    vn_decode_uint32_t(dec, &val->bufferImageHeight);
    vn_decode_VkImageSubresourceLayers_temp(dec, &val->imageSubresource);
    vn_decode_VkOffset3D_temp(dec, &val->imageOffset);
    vn_decode_VkExtent3D_temp(dec, &val->imageExtent);
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
vn_decode_VkImageResolve_temp(struct vn_cs_decoder *dec, VkImageResolve *val)
{
    vn_decode_VkImageSubresourceLayers_temp(dec, &val->srcSubresource);
    vn_decode_VkOffset3D_temp(dec, &val->srcOffset);
    vn_decode_VkImageSubresourceLayers_temp(dec, &val->dstSubresource);
    vn_decode_VkOffset3D_temp(dec, &val->dstOffset);
    vn_decode_VkExtent3D_temp(dec, &val->extent);
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
vn_decode_VkShaderModuleCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkShaderModuleCreateInfo_self_temp(struct vn_cs_decoder *dec, VkShaderModuleCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_size_t(dec, &val->codeSize);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->codeSize / 4);
        val->pCode = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pCode) * array_size);
        if (!val->pCode) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pCode, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pCode = NULL;
    }
}

static inline void
vn_decode_VkShaderModuleCreateInfo_temp(struct vn_cs_decoder *dec, VkShaderModuleCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkShaderModuleCreateInfo_pnext_temp(dec);
    vn_decode_VkShaderModuleCreateInfo_self_temp(dec, val);
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
vn_decode_VkDescriptorSetLayoutBinding_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutBinding *val)
{
    vn_decode_uint32_t(dec, &val->binding);
    vn_decode_VkDescriptorType(dec, &val->descriptorType);
    vn_decode_uint32_t(dec, &val->descriptorCount);
    vn_decode_VkFlags(dec, &val->stageFlags);
    if (vn_peek_array_size(dec)) {
        val->pImmutableSamplers = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pImmutableSamplers) * val->descriptorCount);
        if (!val->pImmutableSamplers) return;
        vn_decode_array_size(dec, val->descriptorCount);
        for (uint32_t i = 0; i < val->descriptorCount; i++)
            vn_decode_VkSampler_lookup(dec, &((VkSampler *)val->pImmutableSamplers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
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
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->bindingCount);
    if (vn_peek_array_size(dec)) {
        val->pBindingFlags = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBindingFlags) * val->bindingCount);
        if (!val->pBindingFlags) return;
        vn_decode_array_size(dec, val->bindingCount);
        for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_decode_VkFlags(dec, &((VkDescriptorBindingFlags *)val->pBindingFlags)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pBindingFlags = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutBindingFlagsCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(dec, val);
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
vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDescriptorSetLayoutBindingFlagsCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(dec);
            vn_decode_VkDescriptorSetLayoutBindingFlagsCreateInfo_self_temp(dec, (VkDescriptorSetLayoutBindingFlagsCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDescriptorSetLayoutCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->bindingCount);
    if (vn_peek_array_size(dec)) {
        val->pBindings = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pBindings) * val->bindingCount);
        if (!val->pBindings) return;
        vn_decode_array_size(dec, val->bindingCount);
        for (uint32_t i = 0; i < val->bindingCount; i++)
            vn_decode_VkDescriptorSetLayoutBinding_temp(dec, &((VkDescriptorSetLayoutBinding *)val->pBindings)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pBindings = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetLayoutCreateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutCreateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorSetLayoutCreateInfo_self_temp(dec, val);
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
vn_decode_VkDescriptorPoolSize_temp(struct vn_cs_decoder *dec, VkDescriptorPoolSize *val)
{
    vn_decode_VkDescriptorType(dec, &val->type);
    vn_decode_uint32_t(dec, &val->descriptorCount);
}

static inline void
vn_replace_VkDescriptorPoolSize_handle(VkDescriptorPoolSize *val)
{
    /* skip val->type */
    /* skip val->descriptorCount */
}

/* struct VkDescriptorPoolCreateInfo chain */

static inline void *
vn_decode_VkDescriptorPoolCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorPoolCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->maxSets);
    vn_decode_uint32_t(dec, &val->poolSizeCount);
    if (vn_peek_array_size(dec)) {
        val->pPoolSizes = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPoolSizes) * val->poolSizeCount);
        if (!val->pPoolSizes) return;
        vn_decode_array_size(dec, val->poolSizeCount);
        for (uint32_t i = 0; i < val->poolSizeCount; i++)
            vn_decode_VkDescriptorPoolSize_temp(dec, &((VkDescriptorPoolSize *)val->pPoolSizes)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pPoolSizes = NULL;
    }
}

static inline void
vn_decode_VkDescriptorPoolCreateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorPoolCreateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorPoolCreateInfo_self_temp(dec, val);
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
vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorSetVariableDescriptorCountAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->descriptorSetCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->descriptorSetCount);
        val->pDescriptorCounts = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDescriptorCounts) * array_size);
        if (!val->pDescriptorCounts) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pDescriptorCounts, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDescriptorCounts = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorSetVariableDescriptorCountAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_self_temp(dec, val);
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
vn_decode_VkDescriptorSetAllocateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDescriptorSetVariableDescriptorCountAllocateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetAllocateInfo_pnext_temp(dec);
            vn_decode_VkDescriptorSetVariableDescriptorCountAllocateInfo_self_temp(dec, (VkDescriptorSetVariableDescriptorCountAllocateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDescriptorSetAllocateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorSetAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDescriptorPool_lookup(dec, &val->descriptorPool);
    vn_decode_uint32_t(dec, &val->descriptorSetCount);
    if (vn_peek_array_size(dec)) {
        val->pSetLayouts = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSetLayouts) * val->descriptorSetCount);
        if (!val->pSetLayouts) return;
        vn_decode_array_size(dec, val->descriptorSetCount);
        for (uint32_t i = 0; i < val->descriptorSetCount; i++)
            vn_decode_VkDescriptorSetLayout_lookup(dec, &((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSetLayouts = NULL;
    }
}

static inline void
vn_decode_VkDescriptorSetAllocateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorSetAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetAllocateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorSetAllocateInfo_self_temp(dec, val);
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
vn_decode_VkSpecializationMapEntry_temp(struct vn_cs_decoder *dec, VkSpecializationMapEntry *val)
{
    vn_decode_uint32_t(dec, &val->constantID);
    vn_decode_uint32_t(dec, &val->offset);
    vn_decode_size_t(dec, &val->size);
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
vn_decode_VkSpecializationInfo_temp(struct vn_cs_decoder *dec, VkSpecializationInfo *val)
{
    vn_decode_uint32_t(dec, &val->mapEntryCount);
    if (vn_peek_array_size(dec)) {
        val->pMapEntries = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pMapEntries) * val->mapEntryCount);
        if (!val->pMapEntries) return;
        vn_decode_array_size(dec, val->mapEntryCount);
        for (uint32_t i = 0; i < val->mapEntryCount; i++)
            vn_decode_VkSpecializationMapEntry_temp(dec, &((VkSpecializationMapEntry *)val->pMapEntries)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pMapEntries = NULL;
    }
    vn_decode_size_t(dec, &val->dataSize);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->dataSize);
        val->pData = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!val->pData) return;
        vn_decode_blob_array(dec, (void *)val->pData, array_size);
    } else {
        vn_decode_array_size(dec, 0);
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
vn_decode_VkPipelineShaderStageCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineShaderStageCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineShaderStageCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkShaderStageFlagBits(dec, &val->stage);
    vn_decode_VkShaderModule_lookup(dec, &val->module);
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        val->pName = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pName) * string_size);
        if (!val->pName) return;
        vn_decode_blob_array(dec, (char *)val->pName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pName = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pSpecializationInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSpecializationInfo));
        if (!val->pSpecializationInfo) return;
        vn_decode_VkSpecializationInfo_temp(dec, (VkSpecializationInfo *)val->pSpecializationInfo);
    } else {
        val->pSpecializationInfo = NULL;
    }
}

static inline void
vn_decode_VkPipelineShaderStageCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineShaderStageCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineShaderStageCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineShaderStageCreateInfo_self_temp(dec, val);
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
vn_decode_VkComputePipelineCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkComputePipelineCreateInfo_self_temp(struct vn_cs_decoder *dec, VkComputePipelineCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkPipelineShaderStageCreateInfo_temp(dec, &val->stage);
    vn_decode_VkPipelineLayout_lookup(dec, &val->layout);
    vn_decode_VkPipeline_lookup(dec, &val->basePipelineHandle);
    vn_decode_int32_t(dec, &val->basePipelineIndex);
}

static inline void
vn_decode_VkComputePipelineCreateInfo_temp(struct vn_cs_decoder *dec, VkComputePipelineCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkComputePipelineCreateInfo_pnext_temp(dec);
    vn_decode_VkComputePipelineCreateInfo_self_temp(dec, val);
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
vn_decode_VkVertexInputBindingDescription_temp(struct vn_cs_decoder *dec, VkVertexInputBindingDescription *val)
{
    vn_decode_uint32_t(dec, &val->binding);
    vn_decode_uint32_t(dec, &val->stride);
    vn_decode_VkVertexInputRate(dec, &val->inputRate);
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
vn_decode_VkVertexInputAttributeDescription_temp(struct vn_cs_decoder *dec, VkVertexInputAttributeDescription *val)
{
    vn_decode_uint32_t(dec, &val->location);
    vn_decode_uint32_t(dec, &val->binding);
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_uint32_t(dec, &val->offset);
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
vn_decode_VkPipelineVertexInputStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineVertexInputStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineVertexInputStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->vertexBindingDescriptionCount);
    if (vn_peek_array_size(dec)) {
        val->pVertexBindingDescriptions = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pVertexBindingDescriptions) * val->vertexBindingDescriptionCount);
        if (!val->pVertexBindingDescriptions) return;
        vn_decode_array_size(dec, val->vertexBindingDescriptionCount);
        for (uint32_t i = 0; i < val->vertexBindingDescriptionCount; i++)
            vn_decode_VkVertexInputBindingDescription_temp(dec, &((VkVertexInputBindingDescription *)val->pVertexBindingDescriptions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pVertexBindingDescriptions = NULL;
    }
    vn_decode_uint32_t(dec, &val->vertexAttributeDescriptionCount);
    if (vn_peek_array_size(dec)) {
        val->pVertexAttributeDescriptions = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pVertexAttributeDescriptions) * val->vertexAttributeDescriptionCount);
        if (!val->pVertexAttributeDescriptions) return;
        vn_decode_array_size(dec, val->vertexAttributeDescriptionCount);
        for (uint32_t i = 0; i < val->vertexAttributeDescriptionCount; i++)
            vn_decode_VkVertexInputAttributeDescription_temp(dec, &((VkVertexInputAttributeDescription *)val->pVertexAttributeDescriptions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pVertexAttributeDescriptions = NULL;
    }
}

static inline void
vn_decode_VkPipelineVertexInputStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineVertexInputStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineVertexInputStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineVertexInputStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineInputAssemblyStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineInputAssemblyStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineInputAssemblyStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkPrimitiveTopology(dec, &val->topology);
    vn_decode_VkBool32(dec, &val->primitiveRestartEnable);
}

static inline void
vn_decode_VkPipelineInputAssemblyStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineInputAssemblyStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineInputAssemblyStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineInputAssemblyStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineTessellationDomainOriginStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkTessellationDomainOrigin(dec, &val->domainOrigin);
}

static inline void
vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineTessellationDomainOriginStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineTessellationStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPipelineTessellationDomainOriginStateCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPipelineTessellationStateCreateInfo_pnext_temp(dec);
            vn_decode_VkPipelineTessellationDomainOriginStateCreateInfo_self_temp(dec, (VkPipelineTessellationDomainOriginStateCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPipelineTessellationStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineTessellationStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->patchControlPoints);
}

static inline void
vn_decode_VkPipelineTessellationStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineTessellationStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineTessellationStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineTessellationStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineViewportStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineViewportStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineViewportStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->viewportCount);
    if (vn_peek_array_size(dec)) {
        val->pViewports = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pViewports) * val->viewportCount);
        if (!val->pViewports) return;
        vn_decode_array_size(dec, val->viewportCount);
        for (uint32_t i = 0; i < val->viewportCount; i++)
            vn_decode_VkViewport_temp(dec, &((VkViewport *)val->pViewports)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pViewports = NULL;
    }
    vn_decode_uint32_t(dec, &val->scissorCount);
    if (vn_peek_array_size(dec)) {
        val->pScissors = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pScissors) * val->scissorCount);
        if (!val->pScissors) return;
        vn_decode_array_size(dec, val->scissorCount);
        for (uint32_t i = 0; i < val->scissorCount; i++)
            vn_decode_VkRect2D_temp(dec, &((VkRect2D *)val->pScissors)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pScissors = NULL;
    }
}

static inline void
vn_decode_VkPipelineViewportStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineViewportStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineViewportStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineViewportStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_self_temp(struct vn_cs_decoder *dec, VkPipelineRasterizationStateStreamCreateInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->rasterizationStream);
}

static inline void
vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_temp(struct vn_cs_decoder *dec, VkPipelineRasterizationStateStreamCreateInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_pnext_temp(dec);
    vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_self_temp(dec, val);
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
vn_decode_VkPipelineRasterizationStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPipelineRasterizationStateStreamCreateInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPipelineRasterizationStateCreateInfo_pnext_temp(dec);
            vn_decode_VkPipelineRasterizationStateStreamCreateInfoEXT_self_temp(dec, (VkPipelineRasterizationStateStreamCreateInfoEXT *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPipelineRasterizationStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineRasterizationStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkBool32(dec, &val->depthClampEnable);
    vn_decode_VkBool32(dec, &val->rasterizerDiscardEnable);
    vn_decode_VkPolygonMode(dec, &val->polygonMode);
    vn_decode_VkFlags(dec, &val->cullMode);
    vn_decode_VkFrontFace(dec, &val->frontFace);
    vn_decode_VkBool32(dec, &val->depthBiasEnable);
    vn_decode_float(dec, &val->depthBiasConstantFactor);
    vn_decode_float(dec, &val->depthBiasClamp);
    vn_decode_float(dec, &val->depthBiasSlopeFactor);
    vn_decode_float(dec, &val->lineWidth);
}

static inline void
vn_decode_VkPipelineRasterizationStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineRasterizationStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineRasterizationStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineRasterizationStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineMultisampleStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineMultisampleStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineMultisampleStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkSampleCountFlagBits(dec, &val->rasterizationSamples);
    vn_decode_VkBool32(dec, &val->sampleShadingEnable);
    vn_decode_float(dec, &val->minSampleShading);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, (val->rasterizationSamples + 31) / 32);
        val->pSampleMask = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSampleMask) * array_size);
        if (!val->pSampleMask) return;
        vn_decode_VkSampleMask_array(dec, (VkSampleMask *)val->pSampleMask, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSampleMask = NULL;
    }
    vn_decode_VkBool32(dec, &val->alphaToCoverageEnable);
    vn_decode_VkBool32(dec, &val->alphaToOneEnable);
}

static inline void
vn_decode_VkPipelineMultisampleStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineMultisampleStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineMultisampleStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineMultisampleStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineColorBlendAttachmentState_temp(struct vn_cs_decoder *dec, VkPipelineColorBlendAttachmentState *val)
{
    vn_decode_VkBool32(dec, &val->blendEnable);
    vn_decode_VkBlendFactor(dec, &val->srcColorBlendFactor);
    vn_decode_VkBlendFactor(dec, &val->dstColorBlendFactor);
    vn_decode_VkBlendOp(dec, &val->colorBlendOp);
    vn_decode_VkBlendFactor(dec, &val->srcAlphaBlendFactor);
    vn_decode_VkBlendFactor(dec, &val->dstAlphaBlendFactor);
    vn_decode_VkBlendOp(dec, &val->alphaBlendOp);
    vn_decode_VkFlags(dec, &val->colorWriteMask);
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
vn_decode_VkPipelineColorBlendStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineColorBlendStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineColorBlendStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkBool32(dec, &val->logicOpEnable);
    vn_decode_VkLogicOp(dec, &val->logicOp);
    vn_decode_uint32_t(dec, &val->attachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(dec, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkPipelineColorBlendAttachmentState_temp(dec, &((VkPipelineColorBlendAttachmentState *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pAttachments = NULL;
    }
    {
        const size_t array_size = vn_decode_array_size(dec, 4);
        vn_decode_float_array(dec, val->blendConstants, array_size);
    }
}

static inline void
vn_decode_VkPipelineColorBlendStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineColorBlendStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineColorBlendStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineColorBlendStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineDynamicStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineDynamicStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineDynamicStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->dynamicStateCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->dynamicStateCount);
        val->pDynamicStates = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDynamicStates) * array_size);
        if (!val->pDynamicStates) return;
        vn_decode_VkDynamicState_array(dec, (VkDynamicState *)val->pDynamicStates, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDynamicStates = NULL;
    }
}

static inline void
vn_decode_VkPipelineDynamicStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineDynamicStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineDynamicStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineDynamicStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkStencilOpState_temp(struct vn_cs_decoder *dec, VkStencilOpState *val)
{
    vn_decode_VkStencilOp(dec, &val->failOp);
    vn_decode_VkStencilOp(dec, &val->passOp);
    vn_decode_VkStencilOp(dec, &val->depthFailOp);
    vn_decode_VkCompareOp(dec, &val->compareOp);
    vn_decode_uint32_t(dec, &val->compareMask);
    vn_decode_uint32_t(dec, &val->writeMask);
    vn_decode_uint32_t(dec, &val->reference);
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
vn_decode_VkPipelineDepthStencilStateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineDepthStencilStateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineDepthStencilStateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkBool32(dec, &val->depthTestEnable);
    vn_decode_VkBool32(dec, &val->depthWriteEnable);
    vn_decode_VkCompareOp(dec, &val->depthCompareOp);
    vn_decode_VkBool32(dec, &val->depthBoundsTestEnable);
    vn_decode_VkBool32(dec, &val->stencilTestEnable);
    vn_decode_VkStencilOpState_temp(dec, &val->front);
    vn_decode_VkStencilOpState_temp(dec, &val->back);
    vn_decode_float(dec, &val->minDepthBounds);
    vn_decode_float(dec, &val->maxDepthBounds);
}

static inline void
vn_decode_VkPipelineDepthStencilStateCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineDepthStencilStateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineDepthStencilStateCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineDepthStencilStateCreateInfo_self_temp(dec, val);
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
vn_decode_VkGraphicsPipelineCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkGraphicsPipelineCreateInfo_self_temp(struct vn_cs_decoder *dec, VkGraphicsPipelineCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->stageCount);
    if (vn_peek_array_size(dec)) {
        val->pStages = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pStages) * val->stageCount);
        if (!val->pStages) return;
        vn_decode_array_size(dec, val->stageCount);
        for (uint32_t i = 0; i < val->stageCount; i++)
            vn_decode_VkPipelineShaderStageCreateInfo_temp(dec, &((VkPipelineShaderStageCreateInfo *)val->pStages)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pStages = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pVertexInputState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pVertexInputState));
        if (!val->pVertexInputState) return;
        vn_decode_VkPipelineVertexInputStateCreateInfo_temp(dec, (VkPipelineVertexInputStateCreateInfo *)val->pVertexInputState);
    } else {
        val->pVertexInputState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pInputAssemblyState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pInputAssemblyState));
        if (!val->pInputAssemblyState) return;
        vn_decode_VkPipelineInputAssemblyStateCreateInfo_temp(dec, (VkPipelineInputAssemblyStateCreateInfo *)val->pInputAssemblyState);
    } else {
        val->pInputAssemblyState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pTessellationState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pTessellationState));
        if (!val->pTessellationState) return;
        vn_decode_VkPipelineTessellationStateCreateInfo_temp(dec, (VkPipelineTessellationStateCreateInfo *)val->pTessellationState);
    } else {
        val->pTessellationState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pViewportState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pViewportState));
        if (!val->pViewportState) return;
        vn_decode_VkPipelineViewportStateCreateInfo_temp(dec, (VkPipelineViewportStateCreateInfo *)val->pViewportState);
    } else {
        val->pViewportState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pRasterizationState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pRasterizationState));
        if (!val->pRasterizationState) return;
        vn_decode_VkPipelineRasterizationStateCreateInfo_temp(dec, (VkPipelineRasterizationStateCreateInfo *)val->pRasterizationState);
    } else {
        val->pRasterizationState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pMultisampleState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pMultisampleState));
        if (!val->pMultisampleState) return;
        vn_decode_VkPipelineMultisampleStateCreateInfo_temp(dec, (VkPipelineMultisampleStateCreateInfo *)val->pMultisampleState);
    } else {
        val->pMultisampleState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pDepthStencilState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDepthStencilState));
        if (!val->pDepthStencilState) return;
        vn_decode_VkPipelineDepthStencilStateCreateInfo_temp(dec, (VkPipelineDepthStencilStateCreateInfo *)val->pDepthStencilState);
    } else {
        val->pDepthStencilState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pColorBlendState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pColorBlendState));
        if (!val->pColorBlendState) return;
        vn_decode_VkPipelineColorBlendStateCreateInfo_temp(dec, (VkPipelineColorBlendStateCreateInfo *)val->pColorBlendState);
    } else {
        val->pColorBlendState = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pDynamicState = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDynamicState));
        if (!val->pDynamicState) return;
        vn_decode_VkPipelineDynamicStateCreateInfo_temp(dec, (VkPipelineDynamicStateCreateInfo *)val->pDynamicState);
    } else {
        val->pDynamicState = NULL;
    }
    vn_decode_VkPipelineLayout_lookup(dec, &val->layout);
    vn_decode_VkRenderPass_lookup(dec, &val->renderPass);
    vn_decode_uint32_t(dec, &val->subpass);
    vn_decode_VkPipeline_lookup(dec, &val->basePipelineHandle);
    vn_decode_int32_t(dec, &val->basePipelineIndex);
}

static inline void
vn_decode_VkGraphicsPipelineCreateInfo_temp(struct vn_cs_decoder *dec, VkGraphicsPipelineCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkGraphicsPipelineCreateInfo_pnext_temp(dec);
    vn_decode_VkGraphicsPipelineCreateInfo_self_temp(dec, val);
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
vn_decode_VkPipelineCacheCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineCacheCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineCacheCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_size_t(dec, &val->initialDataSize);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->initialDataSize);
        val->pInitialData = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!val->pInitialData) return;
        vn_decode_blob_array(dec, (void *)val->pInitialData, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pInitialData = NULL;
    }
}

static inline void
vn_decode_VkPipelineCacheCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineCacheCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineCacheCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineCacheCreateInfo_self_temp(dec, val);
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
vn_decode_VkPushConstantRange_temp(struct vn_cs_decoder *dec, VkPushConstantRange *val)
{
    vn_decode_VkFlags(dec, &val->stageFlags);
    vn_decode_uint32_t(dec, &val->offset);
    vn_decode_uint32_t(dec, &val->size);
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
vn_decode_VkPipelineLayoutCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPipelineLayoutCreateInfo_self_temp(struct vn_cs_decoder *dec, VkPipelineLayoutCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->setLayoutCount);
    if (vn_peek_array_size(dec)) {
        val->pSetLayouts = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSetLayouts) * val->setLayoutCount);
        if (!val->pSetLayouts) return;
        vn_decode_array_size(dec, val->setLayoutCount);
        for (uint32_t i = 0; i < val->setLayoutCount; i++)
            vn_decode_VkDescriptorSetLayout_lookup(dec, &((VkDescriptorSetLayout *)val->pSetLayouts)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSetLayouts = NULL;
    }
    vn_decode_uint32_t(dec, &val->pushConstantRangeCount);
    if (vn_peek_array_size(dec)) {
        val->pPushConstantRanges = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPushConstantRanges) * val->pushConstantRangeCount);
        if (!val->pPushConstantRanges) return;
        vn_decode_array_size(dec, val->pushConstantRangeCount);
        for (uint32_t i = 0; i < val->pushConstantRangeCount; i++)
            vn_decode_VkPushConstantRange_temp(dec, &((VkPushConstantRange *)val->pPushConstantRanges)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pPushConstantRanges = NULL;
    }
}

static inline void
vn_decode_VkPipelineLayoutCreateInfo_temp(struct vn_cs_decoder *dec, VkPipelineLayoutCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPipelineLayoutCreateInfo_pnext_temp(dec);
    vn_decode_VkPipelineLayoutCreateInfo_self_temp(dec, val);
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
vn_decode_VkSamplerReductionModeCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSamplerReductionModeCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSamplerReductionModeCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSamplerReductionMode(dec, &val->reductionMode);
}

static inline void
vn_decode_VkSamplerReductionModeCreateInfo_temp(struct vn_cs_decoder *dec, VkSamplerReductionModeCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerReductionModeCreateInfo_pnext_temp(dec);
    vn_decode_VkSamplerReductionModeCreateInfo_self_temp(dec, val);
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
vn_decode_VkSamplerCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSamplerYcbcrConversionInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(dec);
            vn_decode_VkSamplerYcbcrConversionInfo_self_temp(dec, (VkSamplerYcbcrConversionInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSamplerReductionModeCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(dec);
            vn_decode_VkSamplerReductionModeCreateInfo_self_temp(dec, (VkSamplerReductionModeCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSamplerCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSamplerCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkFilter(dec, &val->magFilter);
    vn_decode_VkFilter(dec, &val->minFilter);
    vn_decode_VkSamplerMipmapMode(dec, &val->mipmapMode);
    vn_decode_VkSamplerAddressMode(dec, &val->addressModeU);
    vn_decode_VkSamplerAddressMode(dec, &val->addressModeV);
    vn_decode_VkSamplerAddressMode(dec, &val->addressModeW);
    vn_decode_float(dec, &val->mipLodBias);
    vn_decode_VkBool32(dec, &val->anisotropyEnable);
    vn_decode_float(dec, &val->maxAnisotropy);
    vn_decode_VkBool32(dec, &val->compareEnable);
    vn_decode_VkCompareOp(dec, &val->compareOp);
    vn_decode_float(dec, &val->minLod);
    vn_decode_float(dec, &val->maxLod);
    vn_decode_VkBorderColor(dec, &val->borderColor);
    vn_decode_VkBool32(dec, &val->unnormalizedCoordinates);
}

static inline void
vn_decode_VkSamplerCreateInfo_temp(struct vn_cs_decoder *dec, VkSamplerCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerCreateInfo_pnext_temp(dec);
    vn_decode_VkSamplerCreateInfo_self_temp(dec, val);
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
vn_decode_VkCommandPoolCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkCommandPoolCreateInfo_self_temp(struct vn_cs_decoder *dec, VkCommandPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->queueFamilyIndex);
}

static inline void
vn_decode_VkCommandPoolCreateInfo_temp(struct vn_cs_decoder *dec, VkCommandPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandPoolCreateInfo_pnext_temp(dec);
    vn_decode_VkCommandPoolCreateInfo_self_temp(dec, val);
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
vn_decode_VkCommandBufferAllocateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkCommandBufferAllocateInfo_self_temp(struct vn_cs_decoder *dec, VkCommandBufferAllocateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkCommandPool_lookup(dec, &val->commandPool);
    vn_decode_VkCommandBufferLevel(dec, &val->level);
    vn_decode_uint32_t(dec, &val->commandBufferCount);
}

static inline void
vn_decode_VkCommandBufferAllocateInfo_temp(struct vn_cs_decoder *dec, VkCommandBufferAllocateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandBufferAllocateInfo_pnext_temp(dec);
    vn_decode_VkCommandBufferAllocateInfo_self_temp(dec, val);
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
vn_encode_VkCommandBufferInheritanceInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkCommandBufferInheritanceInfo_self(struct vn_cs_encoder *enc, const VkCommandBufferInheritanceInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkRenderPass(enc, &val->renderPass);
    vn_encode_uint32_t(enc, &val->subpass);
    vn_encode_VkFramebuffer(enc, &val->framebuffer);
    vn_encode_VkBool32(enc, &val->occlusionQueryEnable);
    vn_encode_VkFlags(enc, &val->queryFlags);
    vn_encode_VkFlags(enc, &val->pipelineStatistics);
}

static inline void
vn_encode_VkCommandBufferInheritanceInfo(struct vn_cs_encoder *enc, const VkCommandBufferInheritanceInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO });
    vn_encode_VkCommandBufferInheritanceInfo_pnext(enc, val->pNext);
    vn_encode_VkCommandBufferInheritanceInfo_self(enc, val);
}

static inline void *
vn_decode_VkCommandBufferInheritanceInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkCommandBufferInheritanceInfo_self_temp(struct vn_cs_decoder *dec, VkCommandBufferInheritanceInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkRenderPass_lookup(dec, &val->renderPass);
    vn_decode_uint32_t(dec, &val->subpass);
    vn_decode_VkFramebuffer_lookup(dec, &val->framebuffer);
    vn_decode_VkBool32(dec, &val->occlusionQueryEnable);
    vn_decode_VkFlags(dec, &val->queryFlags);
    vn_decode_VkFlags(dec, &val->pipelineStatistics);
}

static inline void
vn_decode_VkCommandBufferInheritanceInfo_temp(struct vn_cs_decoder *dec, VkCommandBufferInheritanceInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandBufferInheritanceInfo_pnext_temp(dec);
    vn_decode_VkCommandBufferInheritanceInfo_self_temp(dec, val);
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
vn_encode_VkDeviceGroupCommandBufferBeginInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkDeviceGroupCommandBufferBeginInfo_self(struct vn_cs_encoder *enc, const VkDeviceGroupCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->deviceMask);
}

static inline void
vn_encode_VkDeviceGroupCommandBufferBeginInfo(struct vn_cs_encoder *enc, const VkDeviceGroupCommandBufferBeginInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO });
    vn_encode_VkDeviceGroupCommandBufferBeginInfo_pnext(enc, val->pNext);
    vn_encode_VkDeviceGroupCommandBufferBeginInfo_self(enc, val);
}

static inline void *
vn_decode_VkDeviceGroupCommandBufferBeginInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupCommandBufferBeginInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceGroupCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->deviceMask);
}

static inline void
vn_decode_VkDeviceGroupCommandBufferBeginInfo_temp(struct vn_cs_decoder *dec, VkDeviceGroupCommandBufferBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupCommandBufferBeginInfo_pnext_temp(dec);
    vn_decode_VkDeviceGroupCommandBufferBeginInfo_self_temp(dec, val);
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
vn_encode_VkCommandBufferBeginInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkCommandBufferBeginInfo_pnext(enc, pnext->pNext);
            vn_encode_VkDeviceGroupCommandBufferBeginInfo_self(enc, (const VkDeviceGroupCommandBufferBeginInfo *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkCommandBufferBeginInfo_self(struct vn_cs_encoder *enc, const VkCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(enc, &val->flags);
    if (vn_encode_simple_pointer(enc, val->pInheritanceInfo))
        vn_encode_VkCommandBufferInheritanceInfo(enc, val->pInheritanceInfo);
}

static inline void
vn_encode_VkCommandBufferBeginInfo(struct vn_cs_encoder *enc, const VkCommandBufferBeginInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO });
    vn_encode_VkCommandBufferBeginInfo_pnext(enc, val->pNext);
    vn_encode_VkCommandBufferBeginInfo_self(enc, val);
}

static inline void *
vn_decode_VkCommandBufferBeginInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDeviceGroupCommandBufferBeginInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkCommandBufferBeginInfo_pnext_temp(dec);
            vn_decode_VkDeviceGroupCommandBufferBeginInfo_self_temp(dec, (VkDeviceGroupCommandBufferBeginInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkCommandBufferBeginInfo_self_temp(struct vn_cs_decoder *dec, VkCommandBufferBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    if (vn_decode_simple_pointer(dec)) {
        val->pInheritanceInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pInheritanceInfo));
        if (!val->pInheritanceInfo) return;
        vn_decode_VkCommandBufferInheritanceInfo_temp(dec, (VkCommandBufferInheritanceInfo *)val->pInheritanceInfo);
    } else {
        val->pInheritanceInfo = NULL;
    }
}

static inline void
vn_decode_VkCommandBufferBeginInfo_temp(struct vn_cs_decoder *dec, VkCommandBufferBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkCommandBufferBeginInfo_pnext_temp(dec);
    vn_decode_VkCommandBufferBeginInfo_self_temp(dec, val);
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
vn_decode_VkClearColorValue_temp(struct vn_cs_decoder *dec, VkClearColorValue *val)
{
    uint32_t tag;
    vn_decode_uint32_t(dec, &tag);
    switch (tag) {
    case 0:
        {
        const size_t array_size = vn_decode_array_size(dec, 4);
        vn_decode_float_array(dec, val->float32, array_size);
    }
        break;
    case 1:
        {
        const size_t array_size = vn_decode_array_size(dec, 4);
        vn_decode_int32_t_array(dec, val->int32, array_size);
    }
        break;
    case 2:
        {
        const size_t array_size = vn_decode_array_size(dec, 4);
        vn_decode_uint32_t_array(dec, val->uint32, array_size);
    }
        break;
    default:
        vn_cs_decoder_set_fatal(dec);
        break;
    }
}

/* struct VkClearDepthStencilValue */

static inline void
vn_decode_VkClearDepthStencilValue_temp(struct vn_cs_decoder *dec, VkClearDepthStencilValue *val)
{
    vn_decode_float(dec, &val->depth);
    vn_decode_uint32_t(dec, &val->stencil);
}

static inline void
vn_replace_VkClearDepthStencilValue_handle(VkClearDepthStencilValue *val)
{
    /* skip val->depth */
    /* skip val->stencil */
}

/* union VkClearValue */

static inline void
vn_decode_VkClearValue_temp(struct vn_cs_decoder *dec, VkClearValue *val)
{
    uint32_t tag;
    vn_decode_uint32_t(dec, &tag);
    switch (tag) {
    case 0:
        vn_decode_VkClearColorValue_temp(dec, &val->color);
        break;
    case 1:
        vn_decode_VkClearDepthStencilValue_temp(dec, &val->depthStencil);
        break;
    default:
        vn_cs_decoder_set_fatal(dec);
        break;
    }
}

/* struct VkDeviceGroupRenderPassBeginInfo chain */

static inline void *
vn_decode_VkDeviceGroupRenderPassBeginInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupRenderPassBeginInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceGroupRenderPassBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->deviceMask);
    vn_decode_uint32_t(dec, &val->deviceRenderAreaCount);
    if (vn_peek_array_size(dec)) {
        val->pDeviceRenderAreas = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDeviceRenderAreas) * val->deviceRenderAreaCount);
        if (!val->pDeviceRenderAreas) return;
        vn_decode_array_size(dec, val->deviceRenderAreaCount);
        for (uint32_t i = 0; i < val->deviceRenderAreaCount; i++)
            vn_decode_VkRect2D_temp(dec, &((VkRect2D *)val->pDeviceRenderAreas)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDeviceRenderAreas = NULL;
    }
}

static inline void
vn_decode_VkDeviceGroupRenderPassBeginInfo_temp(struct vn_cs_decoder *dec, VkDeviceGroupRenderPassBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupRenderPassBeginInfo_pnext_temp(dec);
    vn_decode_VkDeviceGroupRenderPassBeginInfo_self_temp(dec, val);
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
vn_decode_VkRenderPassAttachmentBeginInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkRenderPassAttachmentBeginInfo_self_temp(struct vn_cs_decoder *dec, VkRenderPassAttachmentBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->attachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(dec, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkImageView_lookup(dec, &((VkImageView *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pAttachments = NULL;
    }
}

static inline void
vn_decode_VkRenderPassAttachmentBeginInfo_temp(struct vn_cs_decoder *dec, VkRenderPassAttachmentBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassAttachmentBeginInfo_pnext_temp(dec);
    vn_decode_VkRenderPassAttachmentBeginInfo_self_temp(dec, val);
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
vn_decode_VkRenderPassBeginInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDeviceGroupRenderPassBeginInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassBeginInfo_pnext_temp(dec);
            vn_decode_VkDeviceGroupRenderPassBeginInfo_self_temp(dec, (VkDeviceGroupRenderPassBeginInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkRenderPassAttachmentBeginInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassBeginInfo_pnext_temp(dec);
            vn_decode_VkRenderPassAttachmentBeginInfo_self_temp(dec, (VkRenderPassAttachmentBeginInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkRenderPassBeginInfo_self_temp(struct vn_cs_decoder *dec, VkRenderPassBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkRenderPass_lookup(dec, &val->renderPass);
    vn_decode_VkFramebuffer_lookup(dec, &val->framebuffer);
    vn_decode_VkRect2D_temp(dec, &val->renderArea);
    vn_decode_uint32_t(dec, &val->clearValueCount);
    if (vn_peek_array_size(dec)) {
        val->pClearValues = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pClearValues) * val->clearValueCount);
        if (!val->pClearValues) return;
        vn_decode_array_size(dec, val->clearValueCount);
        for (uint32_t i = 0; i < val->clearValueCount; i++)
            vn_decode_VkClearValue_temp(dec, &((VkClearValue *)val->pClearValues)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pClearValues = NULL;
    }
}

static inline void
vn_decode_VkRenderPassBeginInfo_temp(struct vn_cs_decoder *dec, VkRenderPassBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassBeginInfo_pnext_temp(dec);
    vn_decode_VkRenderPassBeginInfo_self_temp(dec, val);
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
vn_decode_VkClearAttachment_temp(struct vn_cs_decoder *dec, VkClearAttachment *val)
{
    vn_decode_VkFlags(dec, &val->aspectMask);
    vn_decode_uint32_t(dec, &val->colorAttachment);
    vn_decode_VkClearValue_temp(dec, &val->clearValue);
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
vn_decode_VkAttachmentDescription_temp(struct vn_cs_decoder *dec, VkAttachmentDescription *val)
{
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkSampleCountFlagBits(dec, &val->samples);
    vn_decode_VkAttachmentLoadOp(dec, &val->loadOp);
    vn_decode_VkAttachmentStoreOp(dec, &val->storeOp);
    vn_decode_VkAttachmentLoadOp(dec, &val->stencilLoadOp);
    vn_decode_VkAttachmentStoreOp(dec, &val->stencilStoreOp);
    vn_decode_VkImageLayout(dec, &val->initialLayout);
    vn_decode_VkImageLayout(dec, &val->finalLayout);
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
vn_decode_VkAttachmentReference_temp(struct vn_cs_decoder *dec, VkAttachmentReference *val)
{
    vn_decode_uint32_t(dec, &val->attachment);
    vn_decode_VkImageLayout(dec, &val->layout);
}

static inline void
vn_replace_VkAttachmentReference_handle(VkAttachmentReference *val)
{
    /* skip val->attachment */
    /* skip val->layout */
}

/* struct VkSubpassDescription */

static inline void
vn_decode_VkSubpassDescription_temp(struct vn_cs_decoder *dec, VkSubpassDescription *val)
{
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkPipelineBindPoint(dec, &val->pipelineBindPoint);
    vn_decode_uint32_t(dec, &val->inputAttachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pInputAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pInputAttachments) * val->inputAttachmentCount);
        if (!val->pInputAttachments) return;
        vn_decode_array_size(dec, val->inputAttachmentCount);
        for (uint32_t i = 0; i < val->inputAttachmentCount; i++)
            vn_decode_VkAttachmentReference_temp(dec, &((VkAttachmentReference *)val->pInputAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pInputAttachments = NULL;
    }
    vn_decode_uint32_t(dec, &val->colorAttachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pColorAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pColorAttachments) * val->colorAttachmentCount);
        if (!val->pColorAttachments) return;
        vn_decode_array_size(dec, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference_temp(dec, &((VkAttachmentReference *)val->pColorAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pColorAttachments = NULL;
    }
    if (vn_peek_array_size(dec)) {
        val->pResolveAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pResolveAttachments) * val->colorAttachmentCount);
        if (!val->pResolveAttachments) return;
        vn_decode_array_size(dec, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference_temp(dec, &((VkAttachmentReference *)val->pResolveAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pResolveAttachments = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pDepthStencilAttachment = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDepthStencilAttachment));
        if (!val->pDepthStencilAttachment) return;
        vn_decode_VkAttachmentReference_temp(dec, (VkAttachmentReference *)val->pDepthStencilAttachment);
    } else {
        val->pDepthStencilAttachment = NULL;
    }
    vn_decode_uint32_t(dec, &val->preserveAttachmentCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->preserveAttachmentCount);
        val->pPreserveAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPreserveAttachments) * array_size);
        if (!val->pPreserveAttachments) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pPreserveAttachments, array_size);
    } else {
        vn_decode_array_size(dec, 0);
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
vn_decode_VkSubpassDependency_temp(struct vn_cs_decoder *dec, VkSubpassDependency *val)
{
    vn_decode_uint32_t(dec, &val->srcSubpass);
    vn_decode_uint32_t(dec, &val->dstSubpass);
    vn_decode_VkFlags(dec, &val->srcStageMask);
    vn_decode_VkFlags(dec, &val->dstStageMask);
    vn_decode_VkFlags(dec, &val->srcAccessMask);
    vn_decode_VkFlags(dec, &val->dstAccessMask);
    vn_decode_VkFlags(dec, &val->dependencyFlags);
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
vn_decode_VkRenderPassMultiviewCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkRenderPassMultiviewCreateInfo_self_temp(struct vn_cs_decoder *dec, VkRenderPassMultiviewCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->subpassCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->subpassCount);
        val->pViewMasks = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pViewMasks) * array_size);
        if (!val->pViewMasks) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pViewMasks, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pViewMasks = NULL;
    }
    vn_decode_uint32_t(dec, &val->dependencyCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->dependencyCount);
        val->pViewOffsets = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pViewOffsets) * array_size);
        if (!val->pViewOffsets) return;
        vn_decode_int32_t_array(dec, (int32_t *)val->pViewOffsets, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pViewOffsets = NULL;
    }
    vn_decode_uint32_t(dec, &val->correlationMaskCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->correlationMaskCount);
        val->pCorrelationMasks = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pCorrelationMasks) * array_size);
        if (!val->pCorrelationMasks) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pCorrelationMasks, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pCorrelationMasks = NULL;
    }
}

static inline void
vn_decode_VkRenderPassMultiviewCreateInfo_temp(struct vn_cs_decoder *dec, VkRenderPassMultiviewCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassMultiviewCreateInfo_pnext_temp(dec);
    vn_decode_VkRenderPassMultiviewCreateInfo_self_temp(dec, val);
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
vn_decode_VkInputAttachmentAspectReference_temp(struct vn_cs_decoder *dec, VkInputAttachmentAspectReference *val)
{
    vn_decode_uint32_t(dec, &val->subpass);
    vn_decode_uint32_t(dec, &val->inputAttachmentIndex);
    vn_decode_VkFlags(dec, &val->aspectMask);
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
vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_self_temp(struct vn_cs_decoder *dec, VkRenderPassInputAttachmentAspectCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->aspectReferenceCount);
    if (vn_peek_array_size(dec)) {
        val->pAspectReferences = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pAspectReferences) * val->aspectReferenceCount);
        if (!val->pAspectReferences) return;
        vn_decode_array_size(dec, val->aspectReferenceCount);
        for (uint32_t i = 0; i < val->aspectReferenceCount; i++)
            vn_decode_VkInputAttachmentAspectReference_temp(dec, &((VkInputAttachmentAspectReference *)val->pAspectReferences)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pAspectReferences = NULL;
    }
}

static inline void
vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_temp(struct vn_cs_decoder *dec, VkRenderPassInputAttachmentAspectCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_pnext_temp(dec);
    vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_self_temp(dec, val);
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
vn_decode_VkRenderPassCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkRenderPassMultiviewCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassCreateInfo_pnext_temp(dec);
            vn_decode_VkRenderPassMultiviewCreateInfo_self_temp(dec, (VkRenderPassMultiviewCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkRenderPassInputAttachmentAspectCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkRenderPassCreateInfo_pnext_temp(dec);
            vn_decode_VkRenderPassInputAttachmentAspectCreateInfo_self_temp(dec, (VkRenderPassInputAttachmentAspectCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkRenderPassCreateInfo_self_temp(struct vn_cs_decoder *dec, VkRenderPassCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->attachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(dec, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkAttachmentDescription_temp(dec, &((VkAttachmentDescription *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pAttachments = NULL;
    }
    vn_decode_uint32_t(dec, &val->subpassCount);
    if (vn_peek_array_size(dec)) {
        val->pSubpasses = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSubpasses) * val->subpassCount);
        if (!val->pSubpasses) return;
        vn_decode_array_size(dec, val->subpassCount);
        for (uint32_t i = 0; i < val->subpassCount; i++)
            vn_decode_VkSubpassDescription_temp(dec, &((VkSubpassDescription *)val->pSubpasses)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSubpasses = NULL;
    }
    vn_decode_uint32_t(dec, &val->dependencyCount);
    if (vn_peek_array_size(dec)) {
        val->pDependencies = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDependencies) * val->dependencyCount);
        if (!val->pDependencies) return;
        vn_decode_array_size(dec, val->dependencyCount);
        for (uint32_t i = 0; i < val->dependencyCount; i++)
            vn_decode_VkSubpassDependency_temp(dec, &((VkSubpassDependency *)val->pDependencies)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDependencies = NULL;
    }
}

static inline void
vn_decode_VkRenderPassCreateInfo_temp(struct vn_cs_decoder *dec, VkRenderPassCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassCreateInfo_pnext_temp(dec);
    vn_decode_VkRenderPassCreateInfo_self_temp(dec, val);
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
vn_decode_VkEventCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkEventCreateInfo_self_temp(struct vn_cs_decoder *dec, VkEventCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
}

static inline void
vn_decode_VkEventCreateInfo_temp(struct vn_cs_decoder *dec, VkEventCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EVENT_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkEventCreateInfo_pnext_temp(dec);
    vn_decode_VkEventCreateInfo_self_temp(dec, val);
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
vn_decode_VkExportFenceCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExportFenceCreateInfo_self_temp(struct vn_cs_decoder *dec, VkExportFenceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->handleTypes);
}

static inline void
vn_decode_VkExportFenceCreateInfo_temp(struct vn_cs_decoder *dec, VkExportFenceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExportFenceCreateInfo_pnext_temp(dec);
    vn_decode_VkExportFenceCreateInfo_self_temp(dec, val);
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
vn_decode_VkFenceCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkExportFenceCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkFenceCreateInfo_pnext_temp(dec);
            vn_decode_VkExportFenceCreateInfo_self_temp(dec, (VkExportFenceCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkFenceCreateInfo_self_temp(struct vn_cs_decoder *dec, VkFenceCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
}

static inline void
vn_decode_VkFenceCreateInfo_temp(struct vn_cs_decoder *dec, VkFenceCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FENCE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFenceCreateInfo_pnext_temp(dec);
    vn_decode_VkFenceCreateInfo_self_temp(dec, val);
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
vn_decode_VkExportSemaphoreCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExportSemaphoreCreateInfo_self_temp(struct vn_cs_decoder *dec, VkExportSemaphoreCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->handleTypes);
}

static inline void
vn_decode_VkExportSemaphoreCreateInfo_temp(struct vn_cs_decoder *dec, VkExportSemaphoreCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkExportSemaphoreCreateInfo_pnext_temp(dec);
    vn_decode_VkExportSemaphoreCreateInfo_self_temp(dec, val);
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
vn_decode_VkSemaphoreTypeCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSemaphoreTypeCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSemaphoreTypeCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSemaphoreType(dec, &val->semaphoreType);
    vn_decode_uint64_t(dec, &val->initialValue);
}

static inline void
vn_decode_VkSemaphoreTypeCreateInfo_temp(struct vn_cs_decoder *dec, VkSemaphoreTypeCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreTypeCreateInfo_pnext_temp(dec);
    vn_decode_VkSemaphoreTypeCreateInfo_self_temp(dec, val);
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
vn_decode_VkSemaphoreCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkExportSemaphoreCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSemaphoreCreateInfo_pnext_temp(dec);
            vn_decode_VkExportSemaphoreCreateInfo_self_temp(dec, (VkExportSemaphoreCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSemaphoreTypeCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSemaphoreCreateInfo_pnext_temp(dec);
            vn_decode_VkSemaphoreTypeCreateInfo_self_temp(dec, (VkSemaphoreTypeCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSemaphoreCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSemaphoreCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
}

static inline void
vn_decode_VkSemaphoreCreateInfo_temp(struct vn_cs_decoder *dec, VkSemaphoreCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreCreateInfo_pnext_temp(dec);
    vn_decode_VkSemaphoreCreateInfo_self_temp(dec, val);
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
vn_decode_VkQueryPoolCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkQueryPoolCreateInfo_self_temp(struct vn_cs_decoder *dec, VkQueryPoolCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkQueryType(dec, &val->queryType);
    vn_decode_uint32_t(dec, &val->queryCount);
    vn_decode_VkFlags(dec, &val->pipelineStatistics);
}

static inline void
vn_decode_VkQueryPoolCreateInfo_temp(struct vn_cs_decoder *dec, VkQueryPoolCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkQueryPoolCreateInfo_pnext_temp(dec);
    vn_decode_VkQueryPoolCreateInfo_self_temp(dec, val);
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
vn_decode_VkFramebufferAttachmentImageInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkFramebufferAttachmentImageInfo_self_temp(struct vn_cs_decoder *dec, VkFramebufferAttachmentImageInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkFlags(dec, &val->usage);
    vn_decode_uint32_t(dec, &val->width);
    vn_decode_uint32_t(dec, &val->height);
    vn_decode_uint32_t(dec, &val->layerCount);
    vn_decode_uint32_t(dec, &val->viewFormatCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->viewFormatCount);
        val->pViewFormats = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pViewFormats) * array_size);
        if (!val->pViewFormats) return;
        vn_decode_VkFormat_array(dec, (VkFormat *)val->pViewFormats, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pViewFormats = NULL;
    }
}

static inline void
vn_decode_VkFramebufferAttachmentImageInfo_temp(struct vn_cs_decoder *dec, VkFramebufferAttachmentImageInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFramebufferAttachmentImageInfo_pnext_temp(dec);
    vn_decode_VkFramebufferAttachmentImageInfo_self_temp(dec, val);
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
vn_decode_VkFramebufferAttachmentsCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkFramebufferAttachmentsCreateInfo_self_temp(struct vn_cs_decoder *dec, VkFramebufferAttachmentsCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->attachmentImageInfoCount);
    if (vn_peek_array_size(dec)) {
        val->pAttachmentImageInfos = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pAttachmentImageInfos) * val->attachmentImageInfoCount);
        if (!val->pAttachmentImageInfos) return;
        vn_decode_array_size(dec, val->attachmentImageInfoCount);
        for (uint32_t i = 0; i < val->attachmentImageInfoCount; i++)
            vn_decode_VkFramebufferAttachmentImageInfo_temp(dec, &((VkFramebufferAttachmentImageInfo *)val->pAttachmentImageInfos)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pAttachmentImageInfos = NULL;
    }
}

static inline void
vn_decode_VkFramebufferAttachmentsCreateInfo_temp(struct vn_cs_decoder *dec, VkFramebufferAttachmentsCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFramebufferAttachmentsCreateInfo_pnext_temp(dec);
    vn_decode_VkFramebufferAttachmentsCreateInfo_self_temp(dec, val);
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
vn_decode_VkFramebufferCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkFramebufferAttachmentsCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkFramebufferCreateInfo_pnext_temp(dec);
            vn_decode_VkFramebufferAttachmentsCreateInfo_self_temp(dec, (VkFramebufferAttachmentsCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkFramebufferCreateInfo_self_temp(struct vn_cs_decoder *dec, VkFramebufferCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkRenderPass_lookup(dec, &val->renderPass);
    vn_decode_uint32_t(dec, &val->attachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(dec, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkImageView_lookup(dec, &((VkImageView *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pAttachments = NULL;
    }
    vn_decode_uint32_t(dec, &val->width);
    vn_decode_uint32_t(dec, &val->height);
    vn_decode_uint32_t(dec, &val->layers);
}

static inline void
vn_decode_VkFramebufferCreateInfo_temp(struct vn_cs_decoder *dec, VkFramebufferCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkFramebufferCreateInfo_pnext_temp(dec);
    vn_decode_VkFramebufferCreateInfo_self_temp(dec, val);
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
vn_decode_VkDeviceGroupSubmitInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceGroupSubmitInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceGroupSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->waitSemaphoreCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->waitSemaphoreCount);
        val->pWaitSemaphoreDeviceIndices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pWaitSemaphoreDeviceIndices) * array_size);
        if (!val->pWaitSemaphoreDeviceIndices) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pWaitSemaphoreDeviceIndices, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pWaitSemaphoreDeviceIndices = NULL;
    }
    vn_decode_uint32_t(dec, &val->commandBufferCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->commandBufferCount);
        val->pCommandBufferDeviceMasks = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pCommandBufferDeviceMasks) * array_size);
        if (!val->pCommandBufferDeviceMasks) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pCommandBufferDeviceMasks, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pCommandBufferDeviceMasks = NULL;
    }
    vn_decode_uint32_t(dec, &val->signalSemaphoreCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->signalSemaphoreCount);
        val->pSignalSemaphoreDeviceIndices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSignalSemaphoreDeviceIndices) * array_size);
        if (!val->pSignalSemaphoreDeviceIndices) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pSignalSemaphoreDeviceIndices, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSignalSemaphoreDeviceIndices = NULL;
    }
}

static inline void
vn_decode_VkDeviceGroupSubmitInfo_temp(struct vn_cs_decoder *dec, VkDeviceGroupSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceGroupSubmitInfo_pnext_temp(dec);
    vn_decode_VkDeviceGroupSubmitInfo_self_temp(dec, val);
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
vn_decode_VkProtectedSubmitInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkProtectedSubmitInfo_self_temp(struct vn_cs_decoder *dec, VkProtectedSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBool32(dec, &val->protectedSubmit);
}

static inline void
vn_decode_VkProtectedSubmitInfo_temp(struct vn_cs_decoder *dec, VkProtectedSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkProtectedSubmitInfo_pnext_temp(dec);
    vn_decode_VkProtectedSubmitInfo_self_temp(dec, val);
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
vn_decode_VkSubmitInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDeviceGroupSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubmitInfo_pnext_temp(dec);
            vn_decode_VkDeviceGroupSubmitInfo_self_temp(dec, (VkDeviceGroupSubmitInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkProtectedSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubmitInfo_pnext_temp(dec);
            vn_decode_VkProtectedSubmitInfo_self_temp(dec, (VkProtectedSubmitInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkTimelineSemaphoreSubmitInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubmitInfo_pnext_temp(dec);
            vn_decode_VkTimelineSemaphoreSubmitInfo_self_temp(dec, (VkTimelineSemaphoreSubmitInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSubmitInfo_self_temp(struct vn_cs_decoder *dec, VkSubmitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->waitSemaphoreCount);
    if (vn_peek_array_size(dec)) {
        val->pWaitSemaphores = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pWaitSemaphores) * val->waitSemaphoreCount);
        if (!val->pWaitSemaphores) return;
        vn_decode_array_size(dec, val->waitSemaphoreCount);
        for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(dec, &((VkSemaphore *)val->pWaitSemaphores)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pWaitSemaphores = NULL;
    }
    if (vn_peek_array_size(dec)) {
        val->pWaitDstStageMask = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pWaitDstStageMask) * val->waitSemaphoreCount);
        if (!val->pWaitDstStageMask) return;
        vn_decode_array_size(dec, val->waitSemaphoreCount);
        for (uint32_t i = 0; i < val->waitSemaphoreCount; i++)
            vn_decode_VkFlags(dec, &((VkPipelineStageFlags *)val->pWaitDstStageMask)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pWaitDstStageMask = NULL;
    }
    vn_decode_uint32_t(dec, &val->commandBufferCount);
    if (vn_peek_array_size(dec)) {
        val->pCommandBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pCommandBuffers) * val->commandBufferCount);
        if (!val->pCommandBuffers) return;
        vn_decode_array_size(dec, val->commandBufferCount);
        for (uint32_t i = 0; i < val->commandBufferCount; i++)
            vn_decode_VkCommandBuffer_lookup(dec, &((VkCommandBuffer *)val->pCommandBuffers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pCommandBuffers = NULL;
    }
    vn_decode_uint32_t(dec, &val->signalSemaphoreCount);
    if (vn_peek_array_size(dec)) {
        val->pSignalSemaphores = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSignalSemaphores) * val->signalSemaphoreCount);
        if (!val->pSignalSemaphores) return;
        vn_decode_array_size(dec, val->signalSemaphoreCount);
        for (uint32_t i = 0; i < val->signalSemaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(dec, &((VkSemaphore *)val->pSignalSemaphores)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSignalSemaphores = NULL;
    }
}

static inline void
vn_decode_VkSubmitInfo_temp(struct vn_cs_decoder *dec, VkSubmitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBMIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSubmitInfo_pnext_temp(dec);
    vn_decode_VkSubmitInfo_self_temp(dec, val);
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
vn_encode_VkConformanceVersion(struct vn_cs_encoder *enc, const VkConformanceVersion *val)
{
    vn_encode_uint8_t(enc, &val->major);
    vn_encode_uint8_t(enc, &val->minor);
    vn_encode_uint8_t(enc, &val->subminor);
    vn_encode_uint8_t(enc, &val->patch);
}

static inline void
vn_decode_VkConformanceVersion_partial_temp(struct vn_cs_decoder *dec, VkConformanceVersion *val)
{
    /* skip val->major */
    /* skip val->minor */
    /* skip val->subminor */
    /* skip val->patch */
}

/* struct VkPhysicalDeviceDriverProperties chain */

static inline void
vn_encode_VkPhysicalDeviceDriverProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDriverProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceDriverProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDriverId(enc, &val->driverID);
    vn_encode_array_size(enc, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_blob_array(enc, val->driverName, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_array_size(enc, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_blob_array(enc, val->driverInfo, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_VkConformanceVersion(enc, &val->conformanceVersion);
}

static inline void
vn_encode_VkPhysicalDeviceDriverProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceDriverProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES });
    vn_encode_VkPhysicalDeviceDriverProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceDriverProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDriverProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDriverProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDriverProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->driverID */
    /* skip val->driverName */
    /* skip val->driverInfo */
    vn_decode_VkConformanceVersion_partial_temp(dec, &val->conformanceVersion);
}

static inline void
vn_decode_VkPhysicalDeviceDriverProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDriverProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDriverProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceDriverProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceIDProperties chain */

static inline void
vn_encode_VkPhysicalDeviceIDProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceIDProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceIDProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_array_size(enc, VK_UUID_SIZE);
    vn_encode_uint8_t_array(enc, val->deviceUUID, VK_UUID_SIZE);
    vn_encode_array_size(enc, VK_UUID_SIZE);
    vn_encode_uint8_t_array(enc, val->driverUUID, VK_UUID_SIZE);
    vn_encode_array_size(enc, VK_LUID_SIZE);
    vn_encode_uint8_t_array(enc, val->deviceLUID, VK_LUID_SIZE);
    vn_encode_uint32_t(enc, &val->deviceNodeMask);
    vn_encode_VkBool32(enc, &val->deviceLUIDValid);
}

static inline void
vn_encode_VkPhysicalDeviceIDProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceIDProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES });
    vn_encode_VkPhysicalDeviceIDProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceIDProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceIDProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceIDProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceIDProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->deviceUUID */
    /* skip val->driverUUID */
    /* skip val->deviceLUID */
    /* skip val->deviceNodeMask */
    /* skip val->deviceLUIDValid */
}

static inline void
vn_decode_VkPhysicalDeviceIDProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceIDProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceIDProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceIDProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceMultiviewProperties chain */

static inline void
vn_encode_VkPhysicalDeviceMultiviewProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceMultiviewProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->maxMultiviewViewCount);
    vn_encode_uint32_t(enc, &val->maxMultiviewInstanceIndex);
}

static inline void
vn_encode_VkPhysicalDeviceMultiviewProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceMultiviewProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES });
    vn_encode_VkPhysicalDeviceMultiviewProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceMultiviewProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMultiviewProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMultiviewProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxMultiviewViewCount */
    /* skip val->maxMultiviewInstanceIndex */
}

static inline void
vn_decode_VkPhysicalDeviceMultiviewProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMultiviewProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMultiviewProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceMultiviewProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceSubgroupProperties chain */

static inline void
vn_encode_VkPhysicalDeviceSubgroupProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSubgroupProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceSubgroupProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->subgroupSize);
    vn_encode_VkFlags(enc, &val->supportedStages);
    vn_encode_VkFlags(enc, &val->supportedOperations);
    vn_encode_VkBool32(enc, &val->quadOperationsInAllStages);
}

static inline void
vn_encode_VkPhysicalDeviceSubgroupProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceSubgroupProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES });
    vn_encode_VkPhysicalDeviceSubgroupProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceSubgroupProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSubgroupProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSubgroupProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSubgroupProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->subgroupSize */
    /* skip val->supportedStages */
    /* skip val->supportedOperations */
    /* skip val->quadOperationsInAllStages */
}

static inline void
vn_decode_VkPhysicalDeviceSubgroupProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSubgroupProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSubgroupProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceSubgroupProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDevicePointClippingProperties chain */

static inline void
vn_encode_VkPhysicalDevicePointClippingProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDevicePointClippingProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDevicePointClippingProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPointClippingBehavior(enc, &val->pointClippingBehavior);
}

static inline void
vn_encode_VkPhysicalDevicePointClippingProperties(struct vn_cs_encoder *enc, const VkPhysicalDevicePointClippingProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES });
    vn_encode_VkPhysicalDevicePointClippingProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDevicePointClippingProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDevicePointClippingProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDevicePointClippingProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDevicePointClippingProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->pointClippingBehavior */
}

static inline void
vn_decode_VkPhysicalDevicePointClippingProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDevicePointClippingProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDevicePointClippingProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDevicePointClippingProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceProtectedMemoryProperties chain */

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceProtectedMemoryProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->protectedNoFault);
}

static inline void
vn_encode_VkPhysicalDeviceProtectedMemoryProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceProtectedMemoryProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES });
    vn_encode_VkPhysicalDeviceProtectedMemoryProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceProtectedMemoryProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProtectedMemoryProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProtectedMemoryProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->protectedNoFault */
}

static inline void
vn_decode_VkPhysicalDeviceProtectedMemoryProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProtectedMemoryProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProtectedMemoryProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceProtectedMemoryProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceSamplerFilterMinmaxProperties chain */

static inline void
vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->filterMinmaxSingleComponentFormats);
    vn_encode_VkBool32(enc, &val->filterMinmaxImageComponentMapping);
}

static inline void
vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES });
    vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->filterMinmaxSingleComponentFormats */
    /* skip val->filterMinmaxImageComponentMapping */
}

static inline void
vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSamplerFilterMinmaxProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceMaintenance3Properties chain */

static inline void
vn_encode_VkPhysicalDeviceMaintenance3Properties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMaintenance3Properties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceMaintenance3Properties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->maxPerSetDescriptors);
    vn_encode_VkDeviceSize(enc, &val->maxMemoryAllocationSize);
}

static inline void
vn_encode_VkPhysicalDeviceMaintenance3Properties(struct vn_cs_encoder *enc, const VkPhysicalDeviceMaintenance3Properties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES });
    vn_encode_VkPhysicalDeviceMaintenance3Properties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceMaintenance3Properties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMaintenance3Properties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMaintenance3Properties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMaintenance3Properties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxPerSetDescriptors */
    /* skip val->maxMemoryAllocationSize */
}

static inline void
vn_decode_VkPhysicalDeviceMaintenance3Properties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMaintenance3Properties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMaintenance3Properties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceMaintenance3Properties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceFloatControlsProperties chain */

static inline void
vn_encode_VkPhysicalDeviceFloatControlsProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceFloatControlsProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceFloatControlsProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkShaderFloatControlsIndependence(enc, &val->denormBehaviorIndependence);
    vn_encode_VkShaderFloatControlsIndependence(enc, &val->roundingModeIndependence);
    vn_encode_VkBool32(enc, &val->shaderSignedZeroInfNanPreserveFloat16);
    vn_encode_VkBool32(enc, &val->shaderSignedZeroInfNanPreserveFloat32);
    vn_encode_VkBool32(enc, &val->shaderSignedZeroInfNanPreserveFloat64);
    vn_encode_VkBool32(enc, &val->shaderDenormPreserveFloat16);
    vn_encode_VkBool32(enc, &val->shaderDenormPreserveFloat32);
    vn_encode_VkBool32(enc, &val->shaderDenormPreserveFloat64);
    vn_encode_VkBool32(enc, &val->shaderDenormFlushToZeroFloat16);
    vn_encode_VkBool32(enc, &val->shaderDenormFlushToZeroFloat32);
    vn_encode_VkBool32(enc, &val->shaderDenormFlushToZeroFloat64);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTEFloat16);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTEFloat32);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTEFloat64);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTZFloat16);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTZFloat32);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTZFloat64);
}

static inline void
vn_encode_VkPhysicalDeviceFloatControlsProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceFloatControlsProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES });
    vn_encode_VkPhysicalDeviceFloatControlsProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceFloatControlsProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceFloatControlsProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceFloatControlsProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFloatControlsProperties *val)
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
vn_decode_VkPhysicalDeviceFloatControlsProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceFloatControlsProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceFloatControlsProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceFloatControlsProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceDescriptorIndexingProperties chain */

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceDescriptorIndexingProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->maxUpdateAfterBindDescriptorsInAllPools);
    vn_encode_VkBool32(enc, &val->shaderUniformBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderSampledImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderStorageBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderStorageImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderInputAttachmentArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->robustBufferAccessUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->quadDivergentImplicitLod);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindSamplers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindSampledImages);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindStorageImages);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindInputAttachments);
    vn_encode_uint32_t(enc, &val->maxPerStageUpdateAfterBindResources);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindSamplers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindSampledImages);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindStorageImages);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindInputAttachments);
}

static inline void
vn_encode_VkPhysicalDeviceDescriptorIndexingProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceDescriptorIndexingProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES });
    vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDescriptorIndexingProperties *val)
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
vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDescriptorIndexingProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceTimelineSemaphoreProperties chain */

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint64_t(enc, &val->maxTimelineSemaphoreValueDifference);
}

static inline void
vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES });
    vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxTimelineSemaphoreValueDifference */
}

static inline void
vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTimelineSemaphoreProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceDepthStencilResolveProperties chain */

static inline void
vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(enc, &val->supportedDepthResolveModes);
    vn_encode_VkFlags(enc, &val->supportedStencilResolveModes);
    vn_encode_VkBool32(enc, &val->independentResolveNone);
    vn_encode_VkBool32(enc, &val->independentResolve);
}

static inline void
vn_encode_VkPhysicalDeviceDepthStencilResolveProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES });
    vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->supportedDepthResolveModes */
    /* skip val->supportedStencilResolveModes */
    /* skip val->independentResolveNone */
    /* skip val->independentResolve */
}

static inline void
vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceDepthStencilResolveProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceTransformFeedbackPropertiesEXT chain */

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->maxTransformFeedbackStreams);
    vn_encode_uint32_t(enc, &val->maxTransformFeedbackBuffers);
    vn_encode_VkDeviceSize(enc, &val->maxTransformFeedbackBufferSize);
    vn_encode_uint32_t(enc, &val->maxTransformFeedbackStreamDataSize);
    vn_encode_uint32_t(enc, &val->maxTransformFeedbackBufferDataSize);
    vn_encode_uint32_t(enc, &val->maxTransformFeedbackBufferDataStride);
    vn_encode_VkBool32(enc, &val->transformFeedbackQueries);
    vn_encode_VkBool32(enc, &val->transformFeedbackStreamsLinesTriangles);
    vn_encode_VkBool32(enc, &val->transformFeedbackRasterizationStreamSelect);
    vn_encode_VkBool32(enc, &val->transformFeedbackDraw);
}

static inline void
vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT(struct vn_cs_encoder *enc, const VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT });
    vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
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
vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceTransformFeedbackPropertiesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceVulkan11Properties chain */

static inline void
vn_encode_VkPhysicalDeviceVulkan11Properties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Properties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan11Properties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_array_size(enc, VK_UUID_SIZE);
    vn_encode_uint8_t_array(enc, val->deviceUUID, VK_UUID_SIZE);
    vn_encode_array_size(enc, VK_UUID_SIZE);
    vn_encode_uint8_t_array(enc, val->driverUUID, VK_UUID_SIZE);
    vn_encode_array_size(enc, VK_LUID_SIZE);
    vn_encode_uint8_t_array(enc, val->deviceLUID, VK_LUID_SIZE);
    vn_encode_uint32_t(enc, &val->deviceNodeMask);
    vn_encode_VkBool32(enc, &val->deviceLUIDValid);
    vn_encode_uint32_t(enc, &val->subgroupSize);
    vn_encode_VkFlags(enc, &val->subgroupSupportedStages);
    vn_encode_VkFlags(enc, &val->subgroupSupportedOperations);
    vn_encode_VkBool32(enc, &val->subgroupQuadOperationsInAllStages);
    vn_encode_VkPointClippingBehavior(enc, &val->pointClippingBehavior);
    vn_encode_uint32_t(enc, &val->maxMultiviewViewCount);
    vn_encode_uint32_t(enc, &val->maxMultiviewInstanceIndex);
    vn_encode_VkBool32(enc, &val->protectedNoFault);
    vn_encode_uint32_t(enc, &val->maxPerSetDescriptors);
    vn_encode_VkDeviceSize(enc, &val->maxMemoryAllocationSize);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan11Properties(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan11Properties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES });
    vn_encode_VkPhysicalDeviceVulkan11Properties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan11Properties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan11Properties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan11Properties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan11Properties *val)
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
vn_decode_VkPhysicalDeviceVulkan11Properties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan11Properties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan11Properties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceVulkan11Properties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceVulkan12Properties chain */

static inline void
vn_encode_VkPhysicalDeviceVulkan12Properties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Properties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan12Properties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDriverId(enc, &val->driverID);
    vn_encode_array_size(enc, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_blob_array(enc, val->driverName, VK_MAX_DRIVER_NAME_SIZE);
    vn_encode_array_size(enc, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_blob_array(enc, val->driverInfo, VK_MAX_DRIVER_INFO_SIZE);
    vn_encode_VkConformanceVersion(enc, &val->conformanceVersion);
    vn_encode_VkShaderFloatControlsIndependence(enc, &val->denormBehaviorIndependence);
    vn_encode_VkShaderFloatControlsIndependence(enc, &val->roundingModeIndependence);
    vn_encode_VkBool32(enc, &val->shaderSignedZeroInfNanPreserveFloat16);
    vn_encode_VkBool32(enc, &val->shaderSignedZeroInfNanPreserveFloat32);
    vn_encode_VkBool32(enc, &val->shaderSignedZeroInfNanPreserveFloat64);
    vn_encode_VkBool32(enc, &val->shaderDenormPreserveFloat16);
    vn_encode_VkBool32(enc, &val->shaderDenormPreserveFloat32);
    vn_encode_VkBool32(enc, &val->shaderDenormPreserveFloat64);
    vn_encode_VkBool32(enc, &val->shaderDenormFlushToZeroFloat16);
    vn_encode_VkBool32(enc, &val->shaderDenormFlushToZeroFloat32);
    vn_encode_VkBool32(enc, &val->shaderDenormFlushToZeroFloat64);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTEFloat16);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTEFloat32);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTEFloat64);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTZFloat16);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTZFloat32);
    vn_encode_VkBool32(enc, &val->shaderRoundingModeRTZFloat64);
    vn_encode_uint32_t(enc, &val->maxUpdateAfterBindDescriptorsInAllPools);
    vn_encode_VkBool32(enc, &val->shaderUniformBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderSampledImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderStorageBufferArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderStorageImageArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->shaderInputAttachmentArrayNonUniformIndexingNative);
    vn_encode_VkBool32(enc, &val->robustBufferAccessUpdateAfterBind);
    vn_encode_VkBool32(enc, &val->quadDivergentImplicitLod);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindSamplers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindSampledImages);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindStorageImages);
    vn_encode_uint32_t(enc, &val->maxPerStageDescriptorUpdateAfterBindInputAttachments);
    vn_encode_uint32_t(enc, &val->maxPerStageUpdateAfterBindResources);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindSamplers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindUniformBuffers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindUniformBuffersDynamic);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindStorageBuffers);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindStorageBuffersDynamic);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindSampledImages);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindStorageImages);
    vn_encode_uint32_t(enc, &val->maxDescriptorSetUpdateAfterBindInputAttachments);
    vn_encode_VkFlags(enc, &val->supportedDepthResolveModes);
    vn_encode_VkFlags(enc, &val->supportedStencilResolveModes);
    vn_encode_VkBool32(enc, &val->independentResolveNone);
    vn_encode_VkBool32(enc, &val->independentResolve);
    vn_encode_VkBool32(enc, &val->filterMinmaxSingleComponentFormats);
    vn_encode_VkBool32(enc, &val->filterMinmaxImageComponentMapping);
    vn_encode_uint64_t(enc, &val->maxTimelineSemaphoreValueDifference);
    vn_encode_VkFlags(enc, &val->framebufferIntegerColorSampleCounts);
}

static inline void
vn_encode_VkPhysicalDeviceVulkan12Properties(struct vn_cs_encoder *enc, const VkPhysicalDeviceVulkan12Properties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES });
    vn_encode_VkPhysicalDeviceVulkan12Properties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceVulkan12Properties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceVulkan12Properties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceVulkan12Properties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan12Properties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->driverID */
    /* skip val->driverName */
    /* skip val->driverInfo */
    vn_decode_VkConformanceVersion_partial_temp(dec, &val->conformanceVersion);
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
vn_decode_VkPhysicalDeviceVulkan12Properties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceVulkan12Properties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceVulkan12Properties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceVulkan12Properties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceProperties2 chain */

static inline void
vn_encode_VkPhysicalDeviceProperties2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceDriverProperties_self(enc, (const VkPhysicalDeviceDriverProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceIDProperties_self(enc, (const VkPhysicalDeviceIDProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceMultiviewProperties_self(enc, (const VkPhysicalDeviceMultiviewProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceSubgroupProperties_self(enc, (const VkPhysicalDeviceSubgroupProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDevicePointClippingProperties_self(enc, (const VkPhysicalDevicePointClippingProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceProtectedMemoryProperties_self(enc, (const VkPhysicalDeviceProtectedMemoryProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self(enc, (const VkPhysicalDeviceSamplerFilterMinmaxProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceMaintenance3Properties_self(enc, (const VkPhysicalDeviceMaintenance3Properties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceFloatControlsProperties_self(enc, (const VkPhysicalDeviceFloatControlsProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceDescriptorIndexingProperties_self(enc, (const VkPhysicalDeviceDescriptorIndexingProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceTimelineSemaphoreProperties_self(enc, (const VkPhysicalDeviceTimelineSemaphoreProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceDepthStencilResolveProperties_self(enc, (const VkPhysicalDeviceDepthStencilResolveProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self(enc, (const VkPhysicalDeviceTransformFeedbackPropertiesEXT *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan11Properties_self(enc, (const VkPhysicalDeviceVulkan11Properties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkPhysicalDeviceProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkPhysicalDeviceVulkan12Properties_self(enc, (const VkPhysicalDeviceVulkan12Properties *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceProperties2_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPhysicalDeviceProperties(enc, &val->properties);
}

static inline void
vn_encode_VkPhysicalDeviceProperties2(struct vn_cs_encoder *enc, const VkPhysicalDeviceProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2 });
    vn_encode_VkPhysicalDeviceProperties2_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceProperties2_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceDriverProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceDriverProperties_self_partial_temp(dec, (VkPhysicalDeviceDriverProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceIDProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceIDProperties_self_partial_temp(dec, (VkPhysicalDeviceIDProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceMultiviewProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceMultiviewProperties_self_partial_temp(dec, (VkPhysicalDeviceMultiviewProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSubgroupProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceSubgroupProperties_self_partial_temp(dec, (VkPhysicalDeviceSubgroupProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDevicePointClippingProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDevicePointClippingProperties_self_partial_temp(dec, (VkPhysicalDevicePointClippingProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceProtectedMemoryProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceProtectedMemoryProperties_self_partial_temp(dec, (VkPhysicalDeviceProtectedMemoryProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceSamplerFilterMinmaxProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceSamplerFilterMinmaxProperties_self_partial_temp(dec, (VkPhysicalDeviceSamplerFilterMinmaxProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceMaintenance3Properties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceMaintenance3Properties_self_partial_temp(dec, (VkPhysicalDeviceMaintenance3Properties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceFloatControlsProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceFloatControlsProperties_self_partial_temp(dec, (VkPhysicalDeviceFloatControlsProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceDescriptorIndexingProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceDescriptorIndexingProperties_self_partial_temp(dec, (VkPhysicalDeviceDescriptorIndexingProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTimelineSemaphoreProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceTimelineSemaphoreProperties_self_partial_temp(dec, (VkPhysicalDeviceTimelineSemaphoreProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceDepthStencilResolveProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceDepthStencilResolveProperties_self_partial_temp(dec, (VkPhysicalDeviceDepthStencilResolveProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceTransformFeedbackPropertiesEXT_self_partial_temp(dec, (VkPhysicalDeviceTransformFeedbackPropertiesEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan11Properties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan11Properties_self_partial_temp(dec, (VkPhysicalDeviceVulkan11Properties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceVulkan12Properties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
            vn_decode_VkPhysicalDeviceVulkan12Properties_self_partial_temp(dec, (VkPhysicalDeviceVulkan12Properties *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceProperties2_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceProperties_partial_temp(dec, &val->properties);
}

static inline void
vn_decode_VkPhysicalDeviceProperties2_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceProperties2_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceProperties2_self_partial_temp(dec, val);
}

/* struct VkDrmFormatModifierPropertiesEXT */

static inline void
vn_encode_VkDrmFormatModifierPropertiesEXT(struct vn_cs_encoder *enc, const VkDrmFormatModifierPropertiesEXT *val)
{
    vn_encode_uint64_t(enc, &val->drmFormatModifier);
    vn_encode_uint32_t(enc, &val->drmFormatModifierPlaneCount);
    vn_encode_VkFlags(enc, &val->drmFormatModifierTilingFeatures);
}

static inline void
vn_decode_VkDrmFormatModifierPropertiesEXT_partial_temp(struct vn_cs_decoder *dec, VkDrmFormatModifierPropertiesEXT *val)
{
    /* skip val->drmFormatModifier */
    /* skip val->drmFormatModifierPlaneCount */
    /* skip val->drmFormatModifierTilingFeatures */
}

/* struct VkDrmFormatModifierPropertiesListEXT chain */

static inline void
vn_encode_VkDrmFormatModifierPropertiesListEXT_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkDrmFormatModifierPropertiesListEXT_self(struct vn_cs_encoder *enc, const VkDrmFormatModifierPropertiesListEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->drmFormatModifierCount);
    if (val->pDrmFormatModifierProperties) {
        vn_encode_array_size(enc, val->drmFormatModifierCount);
        for (uint32_t i = 0; i < val->drmFormatModifierCount; i++)
            vn_encode_VkDrmFormatModifierPropertiesEXT(enc, &val->pDrmFormatModifierProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void
vn_encode_VkDrmFormatModifierPropertiesListEXT(struct vn_cs_encoder *enc, const VkDrmFormatModifierPropertiesListEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT });
    vn_encode_VkDrmFormatModifierPropertiesListEXT_pnext(enc, val->pNext);
    vn_encode_VkDrmFormatModifierPropertiesListEXT_self(enc, val);
}

static inline void *
vn_decode_VkDrmFormatModifierPropertiesListEXT_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDrmFormatModifierPropertiesListEXT_self_partial_temp(struct vn_cs_decoder *dec, VkDrmFormatModifierPropertiesListEXT *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->drmFormatModifierCount */
    if (vn_peek_array_size(dec)) {
        val->pDrmFormatModifierProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDrmFormatModifierProperties) * val->drmFormatModifierCount);
        if (!val->pDrmFormatModifierProperties) return;
        vn_decode_array_size(dec, val->drmFormatModifierCount);
        for (uint32_t i = 0; i < val->drmFormatModifierCount; i++)
            vn_decode_VkDrmFormatModifierPropertiesEXT_partial_temp(dec, &val->pDrmFormatModifierProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDrmFormatModifierProperties = NULL;
    }
}

static inline void
vn_decode_VkDrmFormatModifierPropertiesListEXT_partial_temp(struct vn_cs_decoder *dec, VkDrmFormatModifierPropertiesListEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkDrmFormatModifierPropertiesListEXT_pnext_partial_temp(dec);
    vn_decode_VkDrmFormatModifierPropertiesListEXT_self_partial_temp(dec, val);
}

/* struct VkFormatProperties2 chain */

static inline void
vn_encode_VkFormatProperties2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkFormatProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkDrmFormatModifierPropertiesListEXT_self(enc, (const VkDrmFormatModifierPropertiesListEXT *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkFormatProperties2_self(struct vn_cs_encoder *enc, const VkFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFormatProperties(enc, &val->formatProperties);
}

static inline void
vn_encode_VkFormatProperties2(struct vn_cs_encoder *enc, const VkFormatProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2 });
    vn_encode_VkFormatProperties2_pnext(enc, val->pNext);
    vn_encode_VkFormatProperties2_self(enc, val);
}

static inline void *
vn_decode_VkFormatProperties2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDrmFormatModifierPropertiesListEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkFormatProperties2_pnext_partial_temp(dec);
            vn_decode_VkDrmFormatModifierPropertiesListEXT_self_partial_temp(dec, (VkDrmFormatModifierPropertiesListEXT *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkFormatProperties2_self_partial_temp(struct vn_cs_decoder *dec, VkFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormatProperties_partial_temp(dec, &val->formatProperties);
}

static inline void
vn_decode_VkFormatProperties2_partial_temp(struct vn_cs_decoder *dec, VkFormatProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkFormatProperties2_pnext_partial_temp(dec);
    vn_decode_VkFormatProperties2_self_partial_temp(dec, val);
}

/* struct VkExternalMemoryProperties */

static inline void
vn_encode_VkExternalMemoryProperties(struct vn_cs_encoder *enc, const VkExternalMemoryProperties *val)
{
    vn_encode_VkFlags(enc, &val->externalMemoryFeatures);
    vn_encode_VkFlags(enc, &val->exportFromImportedHandleTypes);
    vn_encode_VkFlags(enc, &val->compatibleHandleTypes);
}

static inline void
vn_decode_VkExternalMemoryProperties_partial_temp(struct vn_cs_decoder *dec, VkExternalMemoryProperties *val)
{
    /* skip val->externalMemoryFeatures */
    /* skip val->exportFromImportedHandleTypes */
    /* skip val->compatibleHandleTypes */
}

/* struct VkExternalImageFormatProperties chain */

static inline void
vn_encode_VkExternalImageFormatProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkExternalImageFormatProperties_self(struct vn_cs_encoder *enc, const VkExternalImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkExternalMemoryProperties(enc, &val->externalMemoryProperties);
}

static inline void
vn_encode_VkExternalImageFormatProperties(struct vn_cs_encoder *enc, const VkExternalImageFormatProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES });
    vn_encode_VkExternalImageFormatProperties_pnext(enc, val->pNext);
    vn_encode_VkExternalImageFormatProperties_self(enc, val);
}

static inline void *
vn_decode_VkExternalImageFormatProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExternalImageFormatProperties_self_partial_temp(struct vn_cs_decoder *dec, VkExternalImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalMemoryProperties_partial_temp(dec, &val->externalMemoryProperties);
}

static inline void
vn_decode_VkExternalImageFormatProperties_partial_temp(struct vn_cs_decoder *dec, VkExternalImageFormatProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalImageFormatProperties_pnext_partial_temp(dec);
    vn_decode_VkExternalImageFormatProperties_self_partial_temp(dec, val);
}

/* struct VkSamplerYcbcrConversionImageFormatProperties chain */

static inline void
vn_encode_VkSamplerYcbcrConversionImageFormatProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkSamplerYcbcrConversionImageFormatProperties_self(struct vn_cs_encoder *enc, const VkSamplerYcbcrConversionImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->combinedImageSamplerDescriptorCount);
}

static inline void
vn_encode_VkSamplerYcbcrConversionImageFormatProperties(struct vn_cs_encoder *enc, const VkSamplerYcbcrConversionImageFormatProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES });
    vn_encode_VkSamplerYcbcrConversionImageFormatProperties_pnext(enc, val->pNext);
    vn_encode_VkSamplerYcbcrConversionImageFormatProperties_self(enc, val);
}

static inline void *
vn_decode_VkSamplerYcbcrConversionImageFormatProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSamplerYcbcrConversionImageFormatProperties_self_partial_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionImageFormatProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->combinedImageSamplerDescriptorCount */
}

static inline void
vn_decode_VkSamplerYcbcrConversionImageFormatProperties_partial_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionImageFormatProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerYcbcrConversionImageFormatProperties_pnext_partial_temp(dec);
    vn_decode_VkSamplerYcbcrConversionImageFormatProperties_self_partial_temp(dec, val);
}

/* struct VkImageFormatProperties2 chain */

static inline void
vn_encode_VkImageFormatProperties2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkImageFormatProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkExternalImageFormatProperties_self(enc, (const VkExternalImageFormatProperties *)pnext);
            return;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkImageFormatProperties2_pnext(enc, pnext->pNext);
            vn_encode_VkSamplerYcbcrConversionImageFormatProperties_self(enc, (const VkSamplerYcbcrConversionImageFormatProperties *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkImageFormatProperties2_self(struct vn_cs_encoder *enc, const VkImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkImageFormatProperties(enc, &val->imageFormatProperties);
}

static inline void
vn_encode_VkImageFormatProperties2(struct vn_cs_encoder *enc, const VkImageFormatProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2 });
    vn_encode_VkImageFormatProperties2_pnext(enc, val->pNext);
    vn_encode_VkImageFormatProperties2_self(enc, val);
}

static inline void *
vn_decode_VkImageFormatProperties2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkExternalImageFormatProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageFormatProperties2_pnext_partial_temp(dec);
            vn_decode_VkExternalImageFormatProperties_self_partial_temp(dec, (VkExternalImageFormatProperties *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSamplerYcbcrConversionImageFormatProperties));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageFormatProperties2_pnext_partial_temp(dec);
            vn_decode_VkSamplerYcbcrConversionImageFormatProperties_self_partial_temp(dec, (VkSamplerYcbcrConversionImageFormatProperties *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageFormatProperties2_self_partial_temp(struct vn_cs_decoder *dec, VkImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageFormatProperties_partial_temp(dec, &val->imageFormatProperties);
}

static inline void
vn_decode_VkImageFormatProperties2_partial_temp(struct vn_cs_decoder *dec, VkImageFormatProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkImageFormatProperties2_pnext_partial_temp(dec);
    vn_decode_VkImageFormatProperties2_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceExternalImageFormatInfo chain */

static inline void *
vn_decode_VkPhysicalDeviceExternalImageFormatInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceExternalImageFormatInfo_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalImageFormatInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalMemoryHandleTypeFlagBits(dec, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalImageFormatInfo_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalImageFormatInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalImageFormatInfo_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceExternalImageFormatInfo_self_temp(dec, val);
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
vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImageDrmFormatModifierInfoEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint64_t(dec, &val->drmFormatModifier);
    vn_decode_VkSharingMode(dec, &val->sharingMode);
    vn_decode_uint32_t(dec, &val->queueFamilyIndexCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->queueFamilyIndexCount);
        val->pQueueFamilyIndices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pQueueFamilyIndices) * array_size);
        if (!val->pQueueFamilyIndices) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pQueueFamilyIndices, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pQueueFamilyIndices = NULL;
    }
}

static inline void
vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImageDrmFormatModifierInfoEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_self_temp(dec, val);
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
vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceExternalImageFormatInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceExternalImageFormatInfo_self_temp(dec, (VkPhysicalDeviceExternalImageFormatInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImageFormatListCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(dec);
            vn_decode_VkImageFormatListCreateInfo_self_temp(dec, (VkImageFormatListCreateInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkPhysicalDeviceImageDrmFormatModifierInfoEXT));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(dec);
            vn_decode_VkPhysicalDeviceImageDrmFormatModifierInfoEXT_self_temp(dec, (VkPhysicalDeviceImageDrmFormatModifierInfoEXT *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImageStencilUsageCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(dec);
            vn_decode_VkImageStencilUsageCreateInfo_self_temp(dec, (VkImageStencilUsageCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceImageFormatInfo2_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImageFormatInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkImageType(dec, &val->type);
    vn_decode_VkImageTiling(dec, &val->tiling);
    vn_decode_VkFlags(dec, &val->usage);
    vn_decode_VkFlags(dec, &val->flags);
}

static inline void
vn_decode_VkPhysicalDeviceImageFormatInfo2_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceImageFormatInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceImageFormatInfo2_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceImageFormatInfo2_self_temp(dec, val);
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
vn_encode_VkQueueFamilyProperties2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkQueueFamilyProperties2_self(struct vn_cs_encoder *enc, const VkQueueFamilyProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkQueueFamilyProperties(enc, &val->queueFamilyProperties);
}

static inline void
vn_encode_VkQueueFamilyProperties2(struct vn_cs_encoder *enc, const VkQueueFamilyProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2 });
    vn_encode_VkQueueFamilyProperties2_pnext(enc, val->pNext);
    vn_encode_VkQueueFamilyProperties2_self(enc, val);
}

static inline void *
vn_decode_VkQueueFamilyProperties2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkQueueFamilyProperties2_self_partial_temp(struct vn_cs_decoder *dec, VkQueueFamilyProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkQueueFamilyProperties_partial_temp(dec, &val->queueFamilyProperties);
}

static inline void
vn_decode_VkQueueFamilyProperties2_partial_temp(struct vn_cs_decoder *dec, VkQueueFamilyProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkQueueFamilyProperties2_pnext_partial_temp(dec);
    vn_decode_VkQueueFamilyProperties2_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceMemoryProperties2 chain */

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties2_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceMemoryProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkPhysicalDeviceMemoryProperties(enc, &val->memoryProperties);
}

static inline void
vn_encode_VkPhysicalDeviceMemoryProperties2(struct vn_cs_encoder *enc, const VkPhysicalDeviceMemoryProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2 });
    vn_encode_VkPhysicalDeviceMemoryProperties2_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceMemoryProperties2_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceMemoryProperties2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceMemoryProperties2_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMemoryProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkPhysicalDeviceMemoryProperties_partial_temp(dec, &val->memoryProperties);
}

static inline void
vn_decode_VkPhysicalDeviceMemoryProperties2_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceMemoryProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceMemoryProperties2_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceMemoryProperties2_self_partial_temp(dec, val);
}

/* struct VkSparseImageFormatProperties2 chain */

static inline void
vn_encode_VkSparseImageFormatProperties2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkSparseImageFormatProperties2_self(struct vn_cs_encoder *enc, const VkSparseImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkSparseImageFormatProperties(enc, &val->properties);
}

static inline void
vn_encode_VkSparseImageFormatProperties2(struct vn_cs_encoder *enc, const VkSparseImageFormatProperties2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2 });
    vn_encode_VkSparseImageFormatProperties2_pnext(enc, val->pNext);
    vn_encode_VkSparseImageFormatProperties2_self(enc, val);
}

static inline void *
vn_decode_VkSparseImageFormatProperties2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSparseImageFormatProperties2_self_partial_temp(struct vn_cs_decoder *dec, VkSparseImageFormatProperties2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSparseImageFormatProperties_partial_temp(dec, &val->properties);
}

static inline void
vn_decode_VkSparseImageFormatProperties2_partial_temp(struct vn_cs_decoder *dec, VkSparseImageFormatProperties2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSparseImageFormatProperties2_pnext_partial_temp(dec);
    vn_decode_VkSparseImageFormatProperties2_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceSparseImageFormatInfo2 chain */

static inline void *
vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSparseImageFormatInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkImageType(dec, &val->type);
    vn_decode_VkSampleCountFlagBits(dec, &val->samples);
    vn_decode_VkFlags(dec, &val->usage);
    vn_decode_VkImageTiling(dec, &val->tiling);
}

static inline void
vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceSparseImageFormatInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_self_temp(dec, val);
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
vn_decode_VkPhysicalDeviceExternalBufferInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceExternalBufferInfo_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalBufferInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkFlags(dec, &val->usage);
    vn_decode_VkExternalMemoryHandleTypeFlagBits(dec, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalBufferInfo_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalBufferInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalBufferInfo_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceExternalBufferInfo_self_temp(dec, val);
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
vn_encode_VkExternalBufferProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkExternalBufferProperties_self(struct vn_cs_encoder *enc, const VkExternalBufferProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkExternalMemoryProperties(enc, &val->externalMemoryProperties);
}

static inline void
vn_encode_VkExternalBufferProperties(struct vn_cs_encoder *enc, const VkExternalBufferProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES });
    vn_encode_VkExternalBufferProperties_pnext(enc, val->pNext);
    vn_encode_VkExternalBufferProperties_self(enc, val);
}

static inline void *
vn_decode_VkExternalBufferProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExternalBufferProperties_self_partial_temp(struct vn_cs_decoder *dec, VkExternalBufferProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalMemoryProperties_partial_temp(dec, &val->externalMemoryProperties);
}

static inline void
vn_decode_VkExternalBufferProperties_partial_temp(struct vn_cs_decoder *dec, VkExternalBufferProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalBufferProperties_pnext_partial_temp(dec);
    vn_decode_VkExternalBufferProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceExternalSemaphoreInfo chain */

static inline void *
vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSemaphoreTypeCreateInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_pnext_temp(dec);
            vn_decode_VkSemaphoreTypeCreateInfo_self_temp(dec, (VkSemaphoreTypeCreateInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalSemaphoreInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalSemaphoreHandleTypeFlagBits(dec, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalSemaphoreInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_self_temp(dec, val);
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
vn_encode_VkExternalSemaphoreProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkExternalSemaphoreProperties_self(struct vn_cs_encoder *enc, const VkExternalSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(enc, &val->exportFromImportedHandleTypes);
    vn_encode_VkFlags(enc, &val->compatibleHandleTypes);
    vn_encode_VkFlags(enc, &val->externalSemaphoreFeatures);
}

static inline void
vn_encode_VkExternalSemaphoreProperties(struct vn_cs_encoder *enc, const VkExternalSemaphoreProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES });
    vn_encode_VkExternalSemaphoreProperties_pnext(enc, val->pNext);
    vn_encode_VkExternalSemaphoreProperties_self(enc, val);
}

static inline void *
vn_decode_VkExternalSemaphoreProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExternalSemaphoreProperties_self_partial_temp(struct vn_cs_decoder *dec, VkExternalSemaphoreProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->exportFromImportedHandleTypes */
    /* skip val->compatibleHandleTypes */
    /* skip val->externalSemaphoreFeatures */
}

static inline void
vn_decode_VkExternalSemaphoreProperties_partial_temp(struct vn_cs_decoder *dec, VkExternalSemaphoreProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalSemaphoreProperties_pnext_partial_temp(dec);
    vn_decode_VkExternalSemaphoreProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceExternalFenceInfo chain */

static inline void *
vn_decode_VkPhysicalDeviceExternalFenceInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceExternalFenceInfo_self_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalFenceInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkExternalFenceHandleTypeFlagBits(dec, &val->handleType);
}

static inline void
vn_decode_VkPhysicalDeviceExternalFenceInfo_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceExternalFenceInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceExternalFenceInfo_pnext_temp(dec);
    vn_decode_VkPhysicalDeviceExternalFenceInfo_self_temp(dec, val);
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
vn_encode_VkExternalFenceProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkExternalFenceProperties_self(struct vn_cs_encoder *enc, const VkExternalFenceProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkFlags(enc, &val->exportFromImportedHandleTypes);
    vn_encode_VkFlags(enc, &val->compatibleHandleTypes);
    vn_encode_VkFlags(enc, &val->externalFenceFeatures);
}

static inline void
vn_encode_VkExternalFenceProperties(struct vn_cs_encoder *enc, const VkExternalFenceProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES });
    vn_encode_VkExternalFenceProperties_pnext(enc, val->pNext);
    vn_encode_VkExternalFenceProperties_self(enc, val);
}

static inline void *
vn_decode_VkExternalFenceProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkExternalFenceProperties_self_partial_temp(struct vn_cs_decoder *dec, VkExternalFenceProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->exportFromImportedHandleTypes */
    /* skip val->compatibleHandleTypes */
    /* skip val->externalFenceFeatures */
}

static inline void
vn_decode_VkExternalFenceProperties_partial_temp(struct vn_cs_decoder *dec, VkExternalFenceProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkExternalFenceProperties_pnext_partial_temp(dec);
    vn_decode_VkExternalFenceProperties_self_partial_temp(dec, val);
}

/* struct VkPhysicalDeviceGroupProperties chain */

static inline void
vn_encode_VkPhysicalDeviceGroupProperties_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkPhysicalDeviceGroupProperties_self(struct vn_cs_encoder *enc, const VkPhysicalDeviceGroupProperties *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->physicalDeviceCount);
    vn_encode_array_size(enc, VK_MAX_DEVICE_GROUP_SIZE);
    for (uint32_t i = 0; i < VK_MAX_DEVICE_GROUP_SIZE; i++)
        vn_encode_VkPhysicalDevice(enc, &val->physicalDevices[i]);
    vn_encode_VkBool32(enc, &val->subsetAllocation);
}

static inline void
vn_encode_VkPhysicalDeviceGroupProperties(struct vn_cs_encoder *enc, const VkPhysicalDeviceGroupProperties *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES });
    vn_encode_VkPhysicalDeviceGroupProperties_pnext(enc, val->pNext);
    vn_encode_VkPhysicalDeviceGroupProperties_self(enc, val);
}

static inline void *
vn_decode_VkPhysicalDeviceGroupProperties_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkPhysicalDeviceGroupProperties_self_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceGroupProperties *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->physicalDeviceCount */
    {
        vn_decode_array_size(dec, VK_MAX_DEVICE_GROUP_SIZE);
        for (uint32_t i = 0; i < VK_MAX_DEVICE_GROUP_SIZE; i++)
            vn_decode_VkPhysicalDevice_temp(dec, &val->physicalDevices[i]);
    }
    /* skip val->subsetAllocation */
}

static inline void
vn_decode_VkPhysicalDeviceGroupProperties_partial_temp(struct vn_cs_decoder *dec, VkPhysicalDeviceGroupProperties *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES);

    val->sType = stype;
    val->pNext = vn_decode_VkPhysicalDeviceGroupProperties_pnext_partial_temp(dec);
    vn_decode_VkPhysicalDeviceGroupProperties_self_partial_temp(dec, val);
}

/* struct VkBindBufferMemoryDeviceGroupInfo chain */

static inline void
vn_encode_VkBindBufferMemoryDeviceGroupInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkBindBufferMemoryDeviceGroupInfo_self(struct vn_cs_encoder *enc, const VkBindBufferMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->deviceIndexCount);
    if (val->pDeviceIndices) {
        vn_encode_array_size(enc, val->deviceIndexCount);
        vn_encode_uint32_t_array(enc, val->pDeviceIndices, val->deviceIndexCount);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void
vn_encode_VkBindBufferMemoryDeviceGroupInfo(struct vn_cs_encoder *enc, const VkBindBufferMemoryDeviceGroupInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO });
    vn_encode_VkBindBufferMemoryDeviceGroupInfo_pnext(enc, val->pNext);
    vn_encode_VkBindBufferMemoryDeviceGroupInfo_self(enc, val);
}

static inline void *
vn_decode_VkBindBufferMemoryDeviceGroupInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBindBufferMemoryDeviceGroupInfo_self_temp(struct vn_cs_decoder *dec, VkBindBufferMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->deviceIndexCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->deviceIndexCount);
        val->pDeviceIndices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDeviceIndices) * array_size);
        if (!val->pDeviceIndices) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pDeviceIndices, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDeviceIndices = NULL;
    }
}

static inline void
vn_decode_VkBindBufferMemoryDeviceGroupInfo_temp(struct vn_cs_decoder *dec, VkBindBufferMemoryDeviceGroupInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindBufferMemoryDeviceGroupInfo_pnext_temp(dec);
    vn_decode_VkBindBufferMemoryDeviceGroupInfo_self_temp(dec, val);
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
vn_encode_VkBindBufferMemoryInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkBindBufferMemoryInfo_pnext(enc, pnext->pNext);
            vn_encode_VkBindBufferMemoryDeviceGroupInfo_self(enc, (const VkBindBufferMemoryDeviceGroupInfo *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkBindBufferMemoryInfo_self(struct vn_cs_encoder *enc, const VkBindBufferMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBuffer(enc, &val->buffer);
    vn_encode_VkDeviceMemory(enc, &val->memory);
    vn_encode_VkDeviceSize(enc, &val->memoryOffset);
}

static inline void
vn_encode_VkBindBufferMemoryInfo(struct vn_cs_encoder *enc, const VkBindBufferMemoryInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO });
    vn_encode_VkBindBufferMemoryInfo_pnext(enc, val->pNext);
    vn_encode_VkBindBufferMemoryInfo_self(enc, val);
}

static inline void *
vn_decode_VkBindBufferMemoryInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkBindBufferMemoryDeviceGroupInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindBufferMemoryInfo_pnext_temp(dec);
            vn_decode_VkBindBufferMemoryDeviceGroupInfo_self_temp(dec, (VkBindBufferMemoryDeviceGroupInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBindBufferMemoryInfo_self_temp(struct vn_cs_decoder *dec, VkBindBufferMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
    vn_decode_VkDeviceMemory_lookup(dec, &val->memory);
    vn_decode_VkDeviceSize(dec, &val->memoryOffset);
}

static inline void
vn_decode_VkBindBufferMemoryInfo_temp(struct vn_cs_decoder *dec, VkBindBufferMemoryInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindBufferMemoryInfo_pnext_temp(dec);
    vn_decode_VkBindBufferMemoryInfo_self_temp(dec, val);
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
vn_encode_VkBindImageMemoryDeviceGroupInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkBindImageMemoryDeviceGroupInfo_self(struct vn_cs_encoder *enc, const VkBindImageMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->deviceIndexCount);
    if (val->pDeviceIndices) {
        vn_encode_array_size(enc, val->deviceIndexCount);
        vn_encode_uint32_t_array(enc, val->pDeviceIndices, val->deviceIndexCount);
    } else {
        vn_encode_array_size(enc, 0);
    }
    vn_encode_uint32_t(enc, &val->splitInstanceBindRegionCount);
    if (val->pSplitInstanceBindRegions) {
        vn_encode_array_size(enc, val->splitInstanceBindRegionCount);
        for (uint32_t i = 0; i < val->splitInstanceBindRegionCount; i++)
            vn_encode_VkRect2D(enc, &val->pSplitInstanceBindRegions[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void
vn_encode_VkBindImageMemoryDeviceGroupInfo(struct vn_cs_encoder *enc, const VkBindImageMemoryDeviceGroupInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO });
    vn_encode_VkBindImageMemoryDeviceGroupInfo_pnext(enc, val->pNext);
    vn_encode_VkBindImageMemoryDeviceGroupInfo_self(enc, val);
}

static inline void *
vn_decode_VkBindImageMemoryDeviceGroupInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBindImageMemoryDeviceGroupInfo_self_temp(struct vn_cs_decoder *dec, VkBindImageMemoryDeviceGroupInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->deviceIndexCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->deviceIndexCount);
        val->pDeviceIndices = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDeviceIndices) * array_size);
        if (!val->pDeviceIndices) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pDeviceIndices, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDeviceIndices = NULL;
    }
    vn_decode_uint32_t(dec, &val->splitInstanceBindRegionCount);
    if (vn_peek_array_size(dec)) {
        val->pSplitInstanceBindRegions = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSplitInstanceBindRegions) * val->splitInstanceBindRegionCount);
        if (!val->pSplitInstanceBindRegions) return;
        vn_decode_array_size(dec, val->splitInstanceBindRegionCount);
        for (uint32_t i = 0; i < val->splitInstanceBindRegionCount; i++)
            vn_decode_VkRect2D_temp(dec, &((VkRect2D *)val->pSplitInstanceBindRegions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSplitInstanceBindRegions = NULL;
    }
}

static inline void
vn_decode_VkBindImageMemoryDeviceGroupInfo_temp(struct vn_cs_decoder *dec, VkBindImageMemoryDeviceGroupInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindImageMemoryDeviceGroupInfo_pnext_temp(dec);
    vn_decode_VkBindImageMemoryDeviceGroupInfo_self_temp(dec, val);
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
vn_encode_VkBindImagePlaneMemoryInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkBindImagePlaneMemoryInfo_self(struct vn_cs_encoder *enc, const VkBindImagePlaneMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkImageAspectFlagBits(enc, &val->planeAspect);
}

static inline void
vn_encode_VkBindImagePlaneMemoryInfo(struct vn_cs_encoder *enc, const VkBindImagePlaneMemoryInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO });
    vn_encode_VkBindImagePlaneMemoryInfo_pnext(enc, val->pNext);
    vn_encode_VkBindImagePlaneMemoryInfo_self(enc, val);
}

static inline void *
vn_decode_VkBindImagePlaneMemoryInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBindImagePlaneMemoryInfo_self_temp(struct vn_cs_decoder *dec, VkBindImagePlaneMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageAspectFlagBits(dec, &val->planeAspect);
}

static inline void
vn_decode_VkBindImagePlaneMemoryInfo_temp(struct vn_cs_decoder *dec, VkBindImagePlaneMemoryInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindImagePlaneMemoryInfo_pnext_temp(dec);
    vn_decode_VkBindImagePlaneMemoryInfo_self_temp(dec, val);
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
vn_encode_VkBindImageMemoryInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkBindImageMemoryInfo_pnext(enc, pnext->pNext);
            vn_encode_VkBindImageMemoryDeviceGroupInfo_self(enc, (const VkBindImageMemoryDeviceGroupInfo *)pnext);
            return;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkBindImageMemoryInfo_pnext(enc, pnext->pNext);
            vn_encode_VkBindImagePlaneMemoryInfo_self(enc, (const VkBindImagePlaneMemoryInfo *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkBindImageMemoryInfo_self(struct vn_cs_encoder *enc, const VkBindImageMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkImage(enc, &val->image);
    vn_encode_VkDeviceMemory(enc, &val->memory);
    vn_encode_VkDeviceSize(enc, &val->memoryOffset);
}

static inline void
vn_encode_VkBindImageMemoryInfo(struct vn_cs_encoder *enc, const VkBindImageMemoryInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO });
    vn_encode_VkBindImageMemoryInfo_pnext(enc, val->pNext);
    vn_encode_VkBindImageMemoryInfo_self(enc, val);
}

static inline void *
vn_decode_VkBindImageMemoryInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkBindImageMemoryDeviceGroupInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindImageMemoryInfo_pnext_temp(dec);
            vn_decode_VkBindImageMemoryDeviceGroupInfo_self_temp(dec, (VkBindImageMemoryDeviceGroupInfo *)pnext);
        }
        break;
    case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkBindImagePlaneMemoryInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkBindImageMemoryInfo_pnext_temp(dec);
            vn_decode_VkBindImagePlaneMemoryInfo_self_temp(dec, (VkBindImagePlaneMemoryInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkBindImageMemoryInfo_self_temp(struct vn_cs_decoder *dec, VkBindImageMemoryInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(dec, &val->image);
    vn_decode_VkDeviceMemory_lookup(dec, &val->memory);
    vn_decode_VkDeviceSize(dec, &val->memoryOffset);
}

static inline void
vn_decode_VkBindImageMemoryInfo_temp(struct vn_cs_decoder *dec, VkBindImageMemoryInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBindImageMemoryInfo_pnext_temp(dec);
    vn_decode_VkBindImageMemoryInfo_self_temp(dec, val);
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
vn_decode_VkDescriptorUpdateTemplateEntry_temp(struct vn_cs_decoder *dec, VkDescriptorUpdateTemplateEntry *val)
{
    vn_decode_uint32_t(dec, &val->dstBinding);
    vn_decode_uint32_t(dec, &val->dstArrayElement);
    vn_decode_uint32_t(dec, &val->descriptorCount);
    vn_decode_VkDescriptorType(dec, &val->descriptorType);
    vn_decode_size_t(dec, &val->offset);
    vn_decode_size_t(dec, &val->stride);
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
vn_decode_VkDescriptorUpdateTemplateCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorUpdateTemplateCreateInfo_self_temp(struct vn_cs_decoder *dec, VkDescriptorUpdateTemplateCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->descriptorUpdateEntryCount);
    if (vn_peek_array_size(dec)) {
        val->pDescriptorUpdateEntries = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDescriptorUpdateEntries) * val->descriptorUpdateEntryCount);
        if (!val->pDescriptorUpdateEntries) return;
        vn_decode_array_size(dec, val->descriptorUpdateEntryCount);
        for (uint32_t i = 0; i < val->descriptorUpdateEntryCount; i++)
            vn_decode_VkDescriptorUpdateTemplateEntry_temp(dec, &((VkDescriptorUpdateTemplateEntry *)val->pDescriptorUpdateEntries)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDescriptorUpdateEntries = NULL;
    }
    vn_decode_VkDescriptorUpdateTemplateType(dec, &val->templateType);
    vn_decode_VkDescriptorSetLayout_lookup(dec, &val->descriptorSetLayout);
    vn_decode_VkPipelineBindPoint(dec, &val->pipelineBindPoint);
    vn_decode_VkPipelineLayout_lookup(dec, &val->pipelineLayout);
    vn_decode_uint32_t(dec, &val->set);
}

static inline void
vn_decode_VkDescriptorUpdateTemplateCreateInfo_temp(struct vn_cs_decoder *dec, VkDescriptorUpdateTemplateCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorUpdateTemplateCreateInfo_pnext_temp(dec);
    vn_decode_VkDescriptorUpdateTemplateCreateInfo_self_temp(dec, val);
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
vn_decode_VkBufferMemoryRequirementsInfo2_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBufferMemoryRequirementsInfo2_self_temp(struct vn_cs_decoder *dec, VkBufferMemoryRequirementsInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
}

static inline void
vn_decode_VkBufferMemoryRequirementsInfo2_temp(struct vn_cs_decoder *dec, VkBufferMemoryRequirementsInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferMemoryRequirementsInfo2_pnext_temp(dec);
    vn_decode_VkBufferMemoryRequirementsInfo2_self_temp(dec, val);
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
vn_decode_VkImagePlaneMemoryRequirementsInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImagePlaneMemoryRequirementsInfo_self_temp(struct vn_cs_decoder *dec, VkImagePlaneMemoryRequirementsInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageAspectFlagBits(dec, &val->planeAspect);
}

static inline void
vn_decode_VkImagePlaneMemoryRequirementsInfo_temp(struct vn_cs_decoder *dec, VkImagePlaneMemoryRequirementsInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkImagePlaneMemoryRequirementsInfo_pnext_temp(dec);
    vn_decode_VkImagePlaneMemoryRequirementsInfo_self_temp(dec, val);
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
vn_decode_VkImageMemoryRequirementsInfo2_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkImagePlaneMemoryRequirementsInfo));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkImageMemoryRequirementsInfo2_pnext_temp(dec);
            vn_decode_VkImagePlaneMemoryRequirementsInfo_self_temp(dec, (VkImagePlaneMemoryRequirementsInfo *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkImageMemoryRequirementsInfo2_self_temp(struct vn_cs_decoder *dec, VkImageMemoryRequirementsInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(dec, &val->image);
}

static inline void
vn_decode_VkImageMemoryRequirementsInfo2_temp(struct vn_cs_decoder *dec, VkImageMemoryRequirementsInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkImageMemoryRequirementsInfo2_pnext_temp(dec);
    vn_decode_VkImageMemoryRequirementsInfo2_self_temp(dec, val);
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
vn_decode_VkImageSparseMemoryRequirementsInfo2_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageSparseMemoryRequirementsInfo2_self_temp(struct vn_cs_decoder *dec, VkImageSparseMemoryRequirementsInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImage_lookup(dec, &val->image);
}

static inline void
vn_decode_VkImageSparseMemoryRequirementsInfo2_temp(struct vn_cs_decoder *dec, VkImageSparseMemoryRequirementsInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkImageSparseMemoryRequirementsInfo2_pnext_temp(dec);
    vn_decode_VkImageSparseMemoryRequirementsInfo2_self_temp(dec, val);
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
vn_encode_VkMemoryDedicatedRequirements_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkMemoryDedicatedRequirements_self(struct vn_cs_encoder *enc, const VkMemoryDedicatedRequirements *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->prefersDedicatedAllocation);
    vn_encode_VkBool32(enc, &val->requiresDedicatedAllocation);
}

static inline void
vn_encode_VkMemoryDedicatedRequirements(struct vn_cs_encoder *enc, const VkMemoryDedicatedRequirements *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS });
    vn_encode_VkMemoryDedicatedRequirements_pnext(enc, val->pNext);
    vn_encode_VkMemoryDedicatedRequirements_self(enc, val);
}

static inline void *
vn_decode_VkMemoryDedicatedRequirements_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkMemoryDedicatedRequirements_self_partial_temp(struct vn_cs_decoder *dec, VkMemoryDedicatedRequirements *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->prefersDedicatedAllocation */
    /* skip val->requiresDedicatedAllocation */
}

static inline void
vn_decode_VkMemoryDedicatedRequirements_partial_temp(struct vn_cs_decoder *dec, VkMemoryDedicatedRequirements *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryDedicatedRequirements_pnext_partial_temp(dec);
    vn_decode_VkMemoryDedicatedRequirements_self_partial_temp(dec, val);
}

/* struct VkMemoryRequirements2 chain */

static inline void
vn_encode_VkMemoryRequirements2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkMemoryRequirements2_pnext(enc, pnext->pNext);
            vn_encode_VkMemoryDedicatedRequirements_self(enc, (const VkMemoryDedicatedRequirements *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkMemoryRequirements2_self(struct vn_cs_encoder *enc, const VkMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkMemoryRequirements(enc, &val->memoryRequirements);
}

static inline void
vn_encode_VkMemoryRequirements2(struct vn_cs_encoder *enc, const VkMemoryRequirements2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2 });
    vn_encode_VkMemoryRequirements2_pnext(enc, val->pNext);
    vn_encode_VkMemoryRequirements2_self(enc, val);
}

static inline void *
vn_decode_VkMemoryRequirements2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkMemoryDedicatedRequirements));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkMemoryRequirements2_pnext_partial_temp(dec);
            vn_decode_VkMemoryDedicatedRequirements_self_partial_temp(dec, (VkMemoryDedicatedRequirements *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkMemoryRequirements2_self_partial_temp(struct vn_cs_decoder *dec, VkMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkMemoryRequirements_partial_temp(dec, &val->memoryRequirements);
}

static inline void
vn_decode_VkMemoryRequirements2_partial_temp(struct vn_cs_decoder *dec, VkMemoryRequirements2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2);

    val->sType = stype;
    val->pNext = vn_decode_VkMemoryRequirements2_pnext_partial_temp(dec);
    vn_decode_VkMemoryRequirements2_self_partial_temp(dec, val);
}

/* struct VkSparseImageMemoryRequirements2 chain */

static inline void
vn_encode_VkSparseImageMemoryRequirements2_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkSparseImageMemoryRequirements2_self(struct vn_cs_encoder *enc, const VkSparseImageMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkSparseImageMemoryRequirements(enc, &val->memoryRequirements);
}

static inline void
vn_encode_VkSparseImageMemoryRequirements2(struct vn_cs_encoder *enc, const VkSparseImageMemoryRequirements2 *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2 });
    vn_encode_VkSparseImageMemoryRequirements2_pnext(enc, val->pNext);
    vn_encode_VkSparseImageMemoryRequirements2_self(enc, val);
}

static inline void *
vn_decode_VkSparseImageMemoryRequirements2_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSparseImageMemoryRequirements2_self_partial_temp(struct vn_cs_decoder *dec, VkSparseImageMemoryRequirements2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSparseImageMemoryRequirements_partial_temp(dec, &val->memoryRequirements);
}

static inline void
vn_decode_VkSparseImageMemoryRequirements2_partial_temp(struct vn_cs_decoder *dec, VkSparseImageMemoryRequirements2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSparseImageMemoryRequirements2_pnext_partial_temp(dec);
    vn_decode_VkSparseImageMemoryRequirements2_self_partial_temp(dec, val);
}

/* struct VkSamplerYcbcrConversionCreateInfo chain */

static inline void *
vn_decode_VkSamplerYcbcrConversionCreateInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSamplerYcbcrConversionCreateInfo_self_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionCreateInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkSamplerYcbcrModelConversion(dec, &val->ycbcrModel);
    vn_decode_VkSamplerYcbcrRange(dec, &val->ycbcrRange);
    vn_decode_VkComponentMapping_temp(dec, &val->components);
    vn_decode_VkChromaLocation(dec, &val->xChromaOffset);
    vn_decode_VkChromaLocation(dec, &val->yChromaOffset);
    vn_decode_VkFilter(dec, &val->chromaFilter);
    vn_decode_VkBool32(dec, &val->forceExplicitReconstruction);
}

static inline void
vn_decode_VkSamplerYcbcrConversionCreateInfo_temp(struct vn_cs_decoder *dec, VkSamplerYcbcrConversionCreateInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSamplerYcbcrConversionCreateInfo_pnext_temp(dec);
    vn_decode_VkSamplerYcbcrConversionCreateInfo_self_temp(dec, val);
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
vn_decode_VkDeviceQueueInfo2_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceQueueInfo2_self_temp(struct vn_cs_decoder *dec, VkDeviceQueueInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->queueFamilyIndex);
    vn_decode_uint32_t(dec, &val->queueIndex);
}

static inline void
vn_decode_VkDeviceQueueInfo2_temp(struct vn_cs_decoder *dec, VkDeviceQueueInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceQueueInfo2_pnext_temp(dec);
    vn_decode_VkDeviceQueueInfo2_self_temp(dec, val);
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
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(struct vn_cs_encoder *enc, const VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint32_t(enc, &val->maxVariableDescriptorCount);
}

static inline void
vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport(struct vn_cs_encoder *enc, const VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT });
    vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext(enc, val->pNext);
    vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(enc, val);
}

static inline void *
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->maxVariableDescriptorCount */
}

static inline void
vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetVariableDescriptorCountLayoutSupport *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_pnext_partial_temp(dec);
    vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(dec, val);
}

/* struct VkDescriptorSetLayoutSupport chain */

static inline void
vn_encode_VkDescriptorSetLayoutSupport_pnext(struct vn_cs_encoder *enc, const void *val)
{
    const VkBaseInStructure *pnext = val;

    while (pnext) {
        switch ((int32_t)pnext->sType) {
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            vn_encode_simple_pointer(enc, pnext);
            vn_encode_VkStructureType(enc, &pnext->sType);
            vn_encode_VkDescriptorSetLayoutSupport_pnext(enc, pnext->pNext);
            vn_encode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self(enc, (const VkDescriptorSetVariableDescriptorCountLayoutSupport *)pnext);
            return;
        default:
            /* ignore unknown/unsupported struct */
            break;
        }
        pnext = pnext->pNext;
    }

    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkDescriptorSetLayoutSupport_self(struct vn_cs_encoder *enc, const VkDescriptorSetLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBool32(enc, &val->supported);
}

static inline void
vn_encode_VkDescriptorSetLayoutSupport(struct vn_cs_encoder *enc, const VkDescriptorSetLayoutSupport *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT });
    vn_encode_VkDescriptorSetLayoutSupport_pnext(enc, val->pNext);
    vn_encode_VkDescriptorSetLayoutSupport_self(enc, val);
}

static inline void *
vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkDescriptorSetVariableDescriptorCountLayoutSupport));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(dec);
            vn_decode_VkDescriptorSetVariableDescriptorCountLayoutSupport_self_partial_temp(dec, (VkDescriptorSetVariableDescriptorCountLayoutSupport *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkDescriptorSetLayoutSupport_self_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutSupport *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->supported */
}

static inline void
vn_decode_VkDescriptorSetLayoutSupport_partial_temp(struct vn_cs_decoder *dec, VkDescriptorSetLayoutSupport *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT);

    val->sType = stype;
    val->pNext = vn_decode_VkDescriptorSetLayoutSupport_pnext_partial_temp(dec);
    vn_decode_VkDescriptorSetLayoutSupport_self_partial_temp(dec, val);
}

/* struct VkAttachmentDescriptionStencilLayout chain */

static inline void *
vn_decode_VkAttachmentDescriptionStencilLayout_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkAttachmentDescriptionStencilLayout_self_temp(struct vn_cs_decoder *dec, VkAttachmentDescriptionStencilLayout *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageLayout(dec, &val->stencilInitialLayout);
    vn_decode_VkImageLayout(dec, &val->stencilFinalLayout);
}

static inline void
vn_decode_VkAttachmentDescriptionStencilLayout_temp(struct vn_cs_decoder *dec, VkAttachmentDescriptionStencilLayout *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentDescriptionStencilLayout_pnext_temp(dec);
    vn_decode_VkAttachmentDescriptionStencilLayout_self_temp(dec, val);
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
vn_decode_VkAttachmentDescription2_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkAttachmentDescriptionStencilLayout));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkAttachmentDescription2_pnext_temp(dec);
            vn_decode_VkAttachmentDescriptionStencilLayout_self_temp(dec, (VkAttachmentDescriptionStencilLayout *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkAttachmentDescription2_self_temp(struct vn_cs_decoder *dec, VkAttachmentDescription2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkFormat(dec, &val->format);
    vn_decode_VkSampleCountFlagBits(dec, &val->samples);
    vn_decode_VkAttachmentLoadOp(dec, &val->loadOp);
    vn_decode_VkAttachmentStoreOp(dec, &val->storeOp);
    vn_decode_VkAttachmentLoadOp(dec, &val->stencilLoadOp);
    vn_decode_VkAttachmentStoreOp(dec, &val->stencilStoreOp);
    vn_decode_VkImageLayout(dec, &val->initialLayout);
    vn_decode_VkImageLayout(dec, &val->finalLayout);
}

static inline void
vn_decode_VkAttachmentDescription2_temp(struct vn_cs_decoder *dec, VkAttachmentDescription2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentDescription2_pnext_temp(dec);
    vn_decode_VkAttachmentDescription2_self_temp(dec, val);
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
vn_decode_VkAttachmentReferenceStencilLayout_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkAttachmentReferenceStencilLayout_self_temp(struct vn_cs_decoder *dec, VkAttachmentReferenceStencilLayout *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkImageLayout(dec, &val->stencilLayout);
}

static inline void
vn_decode_VkAttachmentReferenceStencilLayout_temp(struct vn_cs_decoder *dec, VkAttachmentReferenceStencilLayout *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentReferenceStencilLayout_pnext_temp(dec);
    vn_decode_VkAttachmentReferenceStencilLayout_self_temp(dec, val);
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
vn_decode_VkAttachmentReference2_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkAttachmentReferenceStencilLayout));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkAttachmentReference2_pnext_temp(dec);
            vn_decode_VkAttachmentReferenceStencilLayout_self_temp(dec, (VkAttachmentReferenceStencilLayout *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkAttachmentReference2_self_temp(struct vn_cs_decoder *dec, VkAttachmentReference2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->attachment);
    vn_decode_VkImageLayout(dec, &val->layout);
    vn_decode_VkFlags(dec, &val->aspectMask);
}

static inline void
vn_decode_VkAttachmentReference2_temp(struct vn_cs_decoder *dec, VkAttachmentReference2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2);

    val->sType = stype;
    val->pNext = vn_decode_VkAttachmentReference2_pnext_temp(dec);
    vn_decode_VkAttachmentReference2_self_temp(dec, val);
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
vn_decode_VkSubpassDescriptionDepthStencilResolve_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSubpassDescriptionDepthStencilResolve_self_temp(struct vn_cs_decoder *dec, VkSubpassDescriptionDepthStencilResolve *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkResolveModeFlagBits(dec, &val->depthResolveMode);
    vn_decode_VkResolveModeFlagBits(dec, &val->stencilResolveMode);
    if (vn_decode_simple_pointer(dec)) {
        val->pDepthStencilResolveAttachment = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDepthStencilResolveAttachment));
        if (!val->pDepthStencilResolveAttachment) return;
        vn_decode_VkAttachmentReference2_temp(dec, (VkAttachmentReference2 *)val->pDepthStencilResolveAttachment);
    } else {
        val->pDepthStencilResolveAttachment = NULL;
    }
}

static inline void
vn_decode_VkSubpassDescriptionDepthStencilResolve_temp(struct vn_cs_decoder *dec, VkSubpassDescriptionDepthStencilResolve *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassDescriptionDepthStencilResolve_pnext_temp(dec);
    vn_decode_VkSubpassDescriptionDepthStencilResolve_self_temp(dec, val);
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
vn_decode_VkSubpassDescription2_pnext_temp(struct vn_cs_decoder *dec)
{
    VkBaseOutStructure *pnext;
    VkStructureType stype;

    if (!vn_decode_simple_pointer(dec))
        return NULL;

    vn_decode_VkStructureType(dec, &stype);
    switch ((int32_t)stype) {
    case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
        pnext = vn_cs_decoder_alloc_temp(dec, sizeof(VkSubpassDescriptionDepthStencilResolve));
        if (pnext) {
            pnext->sType = stype;
            pnext->pNext = vn_decode_VkSubpassDescription2_pnext_temp(dec);
            vn_decode_VkSubpassDescriptionDepthStencilResolve_self_temp(dec, (VkSubpassDescriptionDepthStencilResolve *)pnext);
        }
        break;
    default:
        /* unexpected struct */
        pnext = NULL;
        vn_cs_decoder_set_fatal(dec);
        break;
    }

    return pnext;
}

static inline void
vn_decode_VkSubpassDescription2_self_temp(struct vn_cs_decoder *dec, VkSubpassDescription2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_VkPipelineBindPoint(dec, &val->pipelineBindPoint);
    vn_decode_uint32_t(dec, &val->viewMask);
    vn_decode_uint32_t(dec, &val->inputAttachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pInputAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pInputAttachments) * val->inputAttachmentCount);
        if (!val->pInputAttachments) return;
        vn_decode_array_size(dec, val->inputAttachmentCount);
        for (uint32_t i = 0; i < val->inputAttachmentCount; i++)
            vn_decode_VkAttachmentReference2_temp(dec, &((VkAttachmentReference2 *)val->pInputAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pInputAttachments = NULL;
    }
    vn_decode_uint32_t(dec, &val->colorAttachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pColorAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pColorAttachments) * val->colorAttachmentCount);
        if (!val->pColorAttachments) return;
        vn_decode_array_size(dec, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference2_temp(dec, &((VkAttachmentReference2 *)val->pColorAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pColorAttachments = NULL;
    }
    if (vn_peek_array_size(dec)) {
        val->pResolveAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pResolveAttachments) * val->colorAttachmentCount);
        if (!val->pResolveAttachments) return;
        vn_decode_array_size(dec, val->colorAttachmentCount);
        for (uint32_t i = 0; i < val->colorAttachmentCount; i++)
            vn_decode_VkAttachmentReference2_temp(dec, &((VkAttachmentReference2 *)val->pResolveAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pResolveAttachments = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        val->pDepthStencilAttachment = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDepthStencilAttachment));
        if (!val->pDepthStencilAttachment) return;
        vn_decode_VkAttachmentReference2_temp(dec, (VkAttachmentReference2 *)val->pDepthStencilAttachment);
    } else {
        val->pDepthStencilAttachment = NULL;
    }
    vn_decode_uint32_t(dec, &val->preserveAttachmentCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->preserveAttachmentCount);
        val->pPreserveAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pPreserveAttachments) * array_size);
        if (!val->pPreserveAttachments) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pPreserveAttachments, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pPreserveAttachments = NULL;
    }
}

static inline void
vn_decode_VkSubpassDescription2_temp(struct vn_cs_decoder *dec, VkSubpassDescription2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassDescription2_pnext_temp(dec);
    vn_decode_VkSubpassDescription2_self_temp(dec, val);
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
vn_decode_VkSubpassDependency2_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSubpassDependency2_self_temp(struct vn_cs_decoder *dec, VkSubpassDependency2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_uint32_t(dec, &val->srcSubpass);
    vn_decode_uint32_t(dec, &val->dstSubpass);
    vn_decode_VkFlags(dec, &val->srcStageMask);
    vn_decode_VkFlags(dec, &val->dstStageMask);
    vn_decode_VkFlags(dec, &val->srcAccessMask);
    vn_decode_VkFlags(dec, &val->dstAccessMask);
    vn_decode_VkFlags(dec, &val->dependencyFlags);
    vn_decode_int32_t(dec, &val->viewOffset);
}

static inline void
vn_decode_VkSubpassDependency2_temp(struct vn_cs_decoder *dec, VkSubpassDependency2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassDependency2_pnext_temp(dec);
    vn_decode_VkSubpassDependency2_self_temp(dec, val);
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
vn_decode_VkRenderPassCreateInfo2_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkRenderPassCreateInfo2_self_temp(struct vn_cs_decoder *dec, VkRenderPassCreateInfo2 *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->attachmentCount);
    if (vn_peek_array_size(dec)) {
        val->pAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pAttachments) * val->attachmentCount);
        if (!val->pAttachments) return;
        vn_decode_array_size(dec, val->attachmentCount);
        for (uint32_t i = 0; i < val->attachmentCount; i++)
            vn_decode_VkAttachmentDescription2_temp(dec, &((VkAttachmentDescription2 *)val->pAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pAttachments = NULL;
    }
    vn_decode_uint32_t(dec, &val->subpassCount);
    if (vn_peek_array_size(dec)) {
        val->pSubpasses = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSubpasses) * val->subpassCount);
        if (!val->pSubpasses) return;
        vn_decode_array_size(dec, val->subpassCount);
        for (uint32_t i = 0; i < val->subpassCount; i++)
            vn_decode_VkSubpassDescription2_temp(dec, &((VkSubpassDescription2 *)val->pSubpasses)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSubpasses = NULL;
    }
    vn_decode_uint32_t(dec, &val->dependencyCount);
    if (vn_peek_array_size(dec)) {
        val->pDependencies = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pDependencies) * val->dependencyCount);
        if (!val->pDependencies) return;
        vn_decode_array_size(dec, val->dependencyCount);
        for (uint32_t i = 0; i < val->dependencyCount; i++)
            vn_decode_VkSubpassDependency2_temp(dec, &((VkSubpassDependency2 *)val->pDependencies)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pDependencies = NULL;
    }
    vn_decode_uint32_t(dec, &val->correlatedViewMaskCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->correlatedViewMaskCount);
        val->pCorrelatedViewMasks = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pCorrelatedViewMasks) * array_size);
        if (!val->pCorrelatedViewMasks) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)val->pCorrelatedViewMasks, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pCorrelatedViewMasks = NULL;
    }
}

static inline void
vn_decode_VkRenderPassCreateInfo2_temp(struct vn_cs_decoder *dec, VkRenderPassCreateInfo2 *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2);

    val->sType = stype;
    val->pNext = vn_decode_VkRenderPassCreateInfo2_pnext_temp(dec);
    vn_decode_VkRenderPassCreateInfo2_self_temp(dec, val);
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
vn_decode_VkSubpassBeginInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSubpassBeginInfo_self_temp(struct vn_cs_decoder *dec, VkSubpassBeginInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSubpassContents(dec, &val->contents);
}

static inline void
vn_decode_VkSubpassBeginInfo_temp(struct vn_cs_decoder *dec, VkSubpassBeginInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassBeginInfo_pnext_temp(dec);
    vn_decode_VkSubpassBeginInfo_self_temp(dec, val);
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
vn_decode_VkSubpassEndInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSubpassEndInfo_self_temp(struct vn_cs_decoder *dec, VkSubpassEndInfo *val)
{
    /* skip val->{sType,pNext} */
}

static inline void
vn_decode_VkSubpassEndInfo_temp(struct vn_cs_decoder *dec, VkSubpassEndInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SUBPASS_END_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSubpassEndInfo_pnext_temp(dec);
    vn_decode_VkSubpassEndInfo_self_temp(dec, val);
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
vn_decode_VkSemaphoreWaitInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSemaphoreWaitInfo_self_temp(struct vn_cs_decoder *dec, VkSemaphoreWaitInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkFlags(dec, &val->flags);
    vn_decode_uint32_t(dec, &val->semaphoreCount);
    if (vn_peek_array_size(dec)) {
        val->pSemaphores = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pSemaphores) * val->semaphoreCount);
        if (!val->pSemaphores) return;
        vn_decode_array_size(dec, val->semaphoreCount);
        for (uint32_t i = 0; i < val->semaphoreCount; i++)
            vn_decode_VkSemaphore_lookup(dec, &((VkSemaphore *)val->pSemaphores)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        val->pSemaphores = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, val->semaphoreCount);
        val->pValues = vn_cs_decoder_alloc_temp(dec, sizeof(*val->pValues) * array_size);
        if (!val->pValues) return;
        vn_decode_uint64_t_array(dec, (uint64_t *)val->pValues, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        val->pValues = NULL;
    }
}

static inline void
vn_decode_VkSemaphoreWaitInfo_temp(struct vn_cs_decoder *dec, VkSemaphoreWaitInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreWaitInfo_pnext_temp(dec);
    vn_decode_VkSemaphoreWaitInfo_self_temp(dec, val);
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
vn_encode_VkSemaphoreSignalInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkSemaphoreSignalInfo_self(struct vn_cs_encoder *enc, const VkSemaphoreSignalInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkSemaphore(enc, &val->semaphore);
    vn_encode_uint64_t(enc, &val->value);
}

static inline void
vn_encode_VkSemaphoreSignalInfo(struct vn_cs_encoder *enc, const VkSemaphoreSignalInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO });
    vn_encode_VkSemaphoreSignalInfo_pnext(enc, val->pNext);
    vn_encode_VkSemaphoreSignalInfo_self(enc, val);
}

static inline void *
vn_decode_VkSemaphoreSignalInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkSemaphoreSignalInfo_self_temp(struct vn_cs_decoder *dec, VkSemaphoreSignalInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkSemaphore_lookup(dec, &val->semaphore);
    vn_decode_uint64_t(dec, &val->value);
}

static inline void
vn_decode_VkSemaphoreSignalInfo_temp(struct vn_cs_decoder *dec, VkSemaphoreSignalInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkSemaphoreSignalInfo_pnext_temp(dec);
    vn_decode_VkSemaphoreSignalInfo_self_temp(dec, val);
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
vn_encode_VkImageDrmFormatModifierPropertiesEXT_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkImageDrmFormatModifierPropertiesEXT_self(struct vn_cs_encoder *enc, const VkImageDrmFormatModifierPropertiesEXT *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_uint64_t(enc, &val->drmFormatModifier);
}

static inline void
vn_encode_VkImageDrmFormatModifierPropertiesEXT(struct vn_cs_encoder *enc, const VkImageDrmFormatModifierPropertiesEXT *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT });
    vn_encode_VkImageDrmFormatModifierPropertiesEXT_pnext(enc, val->pNext);
    vn_encode_VkImageDrmFormatModifierPropertiesEXT_self(enc, val);
}

static inline void *
vn_decode_VkImageDrmFormatModifierPropertiesEXT_pnext_partial_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkImageDrmFormatModifierPropertiesEXT_self_partial_temp(struct vn_cs_decoder *dec, VkImageDrmFormatModifierPropertiesEXT *val)
{
    /* skip val->{sType,pNext} */
    /* skip val->drmFormatModifier */
}

static inline void
vn_decode_VkImageDrmFormatModifierPropertiesEXT_partial_temp(struct vn_cs_decoder *dec, VkImageDrmFormatModifierPropertiesEXT *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT);

    val->sType = stype;
    val->pNext = vn_decode_VkImageDrmFormatModifierPropertiesEXT_pnext_partial_temp(dec);
    vn_decode_VkImageDrmFormatModifierPropertiesEXT_self_partial_temp(dec, val);
}

/* struct VkBufferDeviceAddressInfo chain */

static inline void
vn_encode_VkBufferDeviceAddressInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkBufferDeviceAddressInfo_self(struct vn_cs_encoder *enc, const VkBufferDeviceAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkBuffer(enc, &val->buffer);
}

static inline void
vn_encode_VkBufferDeviceAddressInfo(struct vn_cs_encoder *enc, const VkBufferDeviceAddressInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO });
    vn_encode_VkBufferDeviceAddressInfo_pnext(enc, val->pNext);
    vn_encode_VkBufferDeviceAddressInfo_self(enc, val);
}

static inline void *
vn_decode_VkBufferDeviceAddressInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkBufferDeviceAddressInfo_self_temp(struct vn_cs_decoder *dec, VkBufferDeviceAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkBuffer_lookup(dec, &val->buffer);
}

static inline void
vn_decode_VkBufferDeviceAddressInfo_temp(struct vn_cs_decoder *dec, VkBufferDeviceAddressInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkBufferDeviceAddressInfo_pnext_temp(dec);
    vn_decode_VkBufferDeviceAddressInfo_self_temp(dec, val);
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
vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext(struct vn_cs_encoder *enc, const void *val)
{
    /* no known/supported struct */
    vn_encode_simple_pointer(enc, NULL);
}

static inline void
vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_self(struct vn_cs_encoder *enc, const VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_encode_VkDeviceMemory(enc, &val->memory);
}

static inline void
vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo(struct vn_cs_encoder *enc, const VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    assert(val->sType == VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO);
    vn_encode_VkStructureType(enc, &(VkStructureType){ VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO });
    vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext(enc, val->pNext);
    vn_encode_VkDeviceMemoryOpaqueCaptureAddressInfo_self(enc, val);
}

static inline void *
vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext_temp(struct vn_cs_decoder *dec)
{
    /* no known/supported struct */
    if (vn_decode_simple_pointer(dec))
        vn_cs_decoder_set_fatal(dec);
    return NULL;
}

static inline void
vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_self_temp(struct vn_cs_decoder *dec, VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    /* skip val->{sType,pNext} */
    vn_decode_VkDeviceMemory_lookup(dec, &val->memory);
}

static inline void
vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_temp(struct vn_cs_decoder *dec, VkDeviceMemoryOpaqueCaptureAddressInfo *val)
{
    VkStructureType stype;
    vn_decode_VkStructureType(dec, &stype);
    assert(stype == VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO);

    val->sType = stype;
    val->pNext = vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_pnext_temp(dec);
    vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_self_temp(dec, val);
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
vn_decode_VkCommandStreamDescriptionMESA_temp(struct vn_cs_decoder *dec, VkCommandStreamDescriptionMESA *val)
{
    vn_decode_uint32_t(dec, &val->resourceId);
    vn_decode_size_t(dec, &val->offset);
    vn_decode_size_t(dec, &val->size);
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
vn_decode_VkCommandStreamDependencyMESA_temp(struct vn_cs_decoder *dec, VkCommandStreamDependencyMESA *val)
{
    vn_decode_uint32_t(dec, &val->srcCommandStream);
    vn_decode_uint32_t(dec, &val->dstCommandStream);
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
