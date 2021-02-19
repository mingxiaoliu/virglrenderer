/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_COMMANDS_H
#define VN_PROTOCOL_RENDERER_COMMANDS_H

#include "vn_protocol_renderer_structs.h"

/*
 * These commands are not included
 *
 *   vkGetDeviceProcAddr
 *   vkGetInstanceProcAddr
 *   vkMapMemory
 *   vkUpdateDescriptorSetWithTemplate
 */

static inline void vn_decode_vkCreateInstance_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateInstance *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkInstanceCreateInfo_temp(dec, (VkInstanceCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pInstance = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInstance));
        if (!args->pInstance) return;
        vn_decode_VkInstance_temp(dec, args->pInstance);
    } else {
        args->pInstance = NULL;
    }
}

static inline void vn_replace_vkCreateInstance_args_handle(struct vn_command_vkCreateInstance *args)
{
    if (args->pCreateInfo)
        vn_replace_VkInstanceCreateInfo_handle((VkInstanceCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pInstance */
}

static inline void vn_encode_vkCreateInstance_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateInstance *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateInstance_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pInstance))
        vn_encode_VkInstance(enc, args->pInstance);
}

static inline void vn_decode_vkDestroyInstance_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyInstance *args)
{
    vn_decode_VkInstance_lookup(dec, &args->instance);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyInstance_args_handle(struct vn_command_vkDestroyInstance *args)
{
    vn_replace_VkInstance_handle(&args->instance);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyInstance_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyInstance *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyInstance_EXT});

    /* skip args->instance */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkEnumeratePhysicalDevices_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumeratePhysicalDevices *args)
{
    vn_decode_VkInstance_lookup(dec, &args->instance);
    if (vn_decode_simple_pointer(dec)) {
        args->pPhysicalDeviceCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPhysicalDeviceCount));
        if (!args->pPhysicalDeviceCount) return;
        vn_decode_uint32_t(dec, args->pPhysicalDeviceCount);
    } else {
        args->pPhysicalDeviceCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pPhysicalDevices = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPhysicalDevices) * *args->pPhysicalDeviceCount);
        if (!args->pPhysicalDevices) return;
        vn_decode_array_size(dec, *args->pPhysicalDeviceCount);
        for (uint32_t i = 0; i < *args->pPhysicalDeviceCount; i++)
            vn_decode_VkPhysicalDevice_temp(dec, &args->pPhysicalDevices[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pPhysicalDevices = NULL;
    }
}

static inline void vn_replace_vkEnumeratePhysicalDevices_args_handle(struct vn_command_vkEnumeratePhysicalDevices *args)
{
    vn_replace_VkInstance_handle(&args->instance);
    /* skip args->pPhysicalDeviceCount */
    /* skip args->pPhysicalDevices */
}

static inline void vn_encode_vkEnumeratePhysicalDevices_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumeratePhysicalDevices *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumeratePhysicalDevices_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->instance */
    if (vn_encode_simple_pointer(enc, args->pPhysicalDeviceCount))
        vn_encode_uint32_t(enc, args->pPhysicalDeviceCount);
    if (args->pPhysicalDevices) {
        vn_encode_array_size(enc, *args->pPhysicalDeviceCount);
        for (uint32_t i = 0; i < *args->pPhysicalDeviceCount; i++)
            vn_encode_VkPhysicalDevice(enc, &args->pPhysicalDevices[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkGetPhysicalDeviceProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties));
        if (!args->pProperties) return;
        vn_decode_VkPhysicalDeviceProperties_partial_temp(dec, args->pProperties);
    } else {
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceProperties_args_handle(struct vn_command_vkGetPhysicalDeviceProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceProperties_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pProperties))
        vn_encode_VkPhysicalDeviceProperties(enc, args->pProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceQueueFamilyProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pQueueFamilyPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueueFamilyPropertyCount));
        if (!args->pQueueFamilyPropertyCount) return;
        vn_decode_uint32_t(dec, args->pQueueFamilyPropertyCount);
    } else {
        args->pQueueFamilyPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pQueueFamilyProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueueFamilyProperties) * *args->pQueueFamilyPropertyCount);
        if (!args->pQueueFamilyProperties) return;
        vn_decode_array_size(dec, *args->pQueueFamilyPropertyCount);
        for (uint32_t i = 0; i < *args->pQueueFamilyPropertyCount; i++)
            vn_decode_VkQueueFamilyProperties_partial_temp(dec, &args->pQueueFamilyProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pQueueFamilyProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceQueueFamilyProperties_args_handle(struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pQueueFamilyPropertyCount */
    /* skip args->pQueueFamilyProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceQueueFamilyProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceQueueFamilyProperties_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pQueueFamilyPropertyCount))
        vn_encode_uint32_t(enc, args->pQueueFamilyPropertyCount);
    if (args->pQueueFamilyProperties) {
        vn_encode_array_size(enc, *args->pQueueFamilyPropertyCount);
        for (uint32_t i = 0; i < *args->pQueueFamilyPropertyCount; i++)
            vn_encode_VkQueueFamilyProperties(enc, &args->pQueueFamilyProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkGetPhysicalDeviceMemoryProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceMemoryProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pMemoryProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryProperties));
        if (!args->pMemoryProperties) return;
        vn_decode_VkPhysicalDeviceMemoryProperties_partial_temp(dec, args->pMemoryProperties);
    } else {
        args->pMemoryProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceMemoryProperties_args_handle(struct vn_command_vkGetPhysicalDeviceMemoryProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pMemoryProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceMemoryProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceMemoryProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceMemoryProperties_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pMemoryProperties))
        vn_encode_VkPhysicalDeviceMemoryProperties(enc, args->pMemoryProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceFeatures_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceFeatures *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pFeatures = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFeatures));
        if (!args->pFeatures) return;
        vn_decode_VkPhysicalDeviceFeatures_partial_temp(dec, args->pFeatures);
    } else {
        args->pFeatures = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceFeatures_args_handle(struct vn_command_vkGetPhysicalDeviceFeatures *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pFeatures */
}

static inline void vn_encode_vkGetPhysicalDeviceFeatures_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceFeatures *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceFeatures_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pFeatures))
        vn_encode_VkPhysicalDeviceFeatures(enc, args->pFeatures);
}

static inline void vn_decode_vkGetPhysicalDeviceFormatProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceFormatProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    vn_decode_VkFormat(dec, &args->format);
    if (vn_decode_simple_pointer(dec)) {
        args->pFormatProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFormatProperties));
        if (!args->pFormatProperties) return;
        vn_decode_VkFormatProperties_partial_temp(dec, args->pFormatProperties);
    } else {
        args->pFormatProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceFormatProperties_args_handle(struct vn_command_vkGetPhysicalDeviceFormatProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->format */
    /* skip args->pFormatProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceFormatProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceFormatProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceFormatProperties_EXT});

    /* skip args->physicalDevice */
    /* skip args->format */
    if (vn_encode_simple_pointer(enc, args->pFormatProperties))
        vn_encode_VkFormatProperties(enc, args->pFormatProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceImageFormatProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceImageFormatProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    vn_decode_VkFormat(dec, &args->format);
    vn_decode_VkImageType(dec, &args->type);
    vn_decode_VkImageTiling(dec, &args->tiling);
    vn_decode_VkFlags(dec, &args->usage);
    vn_decode_VkFlags(dec, &args->flags);
    if (vn_decode_simple_pointer(dec)) {
        args->pImageFormatProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pImageFormatProperties));
        if (!args->pImageFormatProperties) return;
        vn_decode_VkImageFormatProperties_partial_temp(dec, args->pImageFormatProperties);
    } else {
        args->pImageFormatProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceImageFormatProperties_args_handle(struct vn_command_vkGetPhysicalDeviceImageFormatProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->format */
    /* skip args->type */
    /* skip args->tiling */
    /* skip args->usage */
    /* skip args->flags */
    /* skip args->pImageFormatProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceImageFormatProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceImageFormatProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceImageFormatProperties_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->physicalDevice */
    /* skip args->format */
    /* skip args->type */
    /* skip args->tiling */
    /* skip args->usage */
    /* skip args->flags */
    if (vn_encode_simple_pointer(enc, args->pImageFormatProperties))
        vn_encode_VkImageFormatProperties(enc, args->pImageFormatProperties);
}

static inline void vn_decode_vkCreateDevice_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateDevice *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDeviceCreateInfo_temp(dec, (VkDeviceCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pDevice = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDevice));
        if (!args->pDevice) return;
        vn_decode_VkDevice_temp(dec, args->pDevice);
    } else {
        args->pDevice = NULL;
    }
}

static inline void vn_replace_vkCreateDevice_args_handle(struct vn_command_vkCreateDevice *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    if (args->pCreateInfo)
        vn_replace_VkDeviceCreateInfo_handle((VkDeviceCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pDevice */
}

static inline void vn_encode_vkCreateDevice_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateDevice *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateDevice_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->physicalDevice */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pDevice))
        vn_encode_VkDevice(enc, args->pDevice);
}

static inline void vn_decode_vkDestroyDevice_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyDevice *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyDevice_args_handle(struct vn_command_vkDestroyDevice *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyDevice_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyDevice *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyDevice_EXT});

    /* skip args->device */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkEnumerateInstanceVersion_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateInstanceVersion *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pApiVersion = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pApiVersion));
        if (!args->pApiVersion) return;
    } else {
        args->pApiVersion = NULL;
    }
}

static inline void vn_replace_vkEnumerateInstanceVersion_args_handle(struct vn_command_vkEnumerateInstanceVersion *args)
{
    /* skip args->pApiVersion */
}

static inline void vn_encode_vkEnumerateInstanceVersion_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateInstanceVersion *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateInstanceVersion_EXT});

    vn_encode_VkResult(enc, &args->ret);
    if (vn_encode_simple_pointer(enc, args->pApiVersion))
        vn_encode_uint32_t(enc, args->pApiVersion);
}

static inline void vn_decode_vkEnumerateInstanceLayerProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateInstanceLayerProperties *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * *args->pPropertyCount);
        if (!args->pProperties) return;
        vn_decode_array_size(dec, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_decode_VkLayerProperties_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkEnumerateInstanceLayerProperties_args_handle(struct vn_command_vkEnumerateInstanceLayerProperties *args)
{
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkEnumerateInstanceLayerProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateInstanceLayerProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateInstanceLayerProperties_EXT});

    vn_encode_VkResult(enc, &args->ret);
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_encode_VkLayerProperties(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkEnumerateInstanceExtensionProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateInstanceExtensionProperties *args)
{
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        args->pLayerName = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pLayerName) * string_size);
        if (!args->pLayerName) return;
        vn_decode_blob_array(dec, (char *)args->pLayerName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pLayerName = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * *args->pPropertyCount);
        if (!args->pProperties) return;
        vn_decode_array_size(dec, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_decode_VkExtensionProperties_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkEnumerateInstanceExtensionProperties_args_handle(struct vn_command_vkEnumerateInstanceExtensionProperties *args)
{
    /* skip args->pLayerName */
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkEnumerateInstanceExtensionProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateInstanceExtensionProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateInstanceExtensionProperties_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->pLayerName */
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_encode_VkExtensionProperties(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkEnumerateDeviceLayerProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateDeviceLayerProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * *args->pPropertyCount);
        if (!args->pProperties) return;
        vn_decode_array_size(dec, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_decode_VkLayerProperties_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkEnumerateDeviceLayerProperties_args_handle(struct vn_command_vkEnumerateDeviceLayerProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkEnumerateDeviceLayerProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateDeviceLayerProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateDeviceLayerProperties_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_encode_VkLayerProperties(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkEnumerateDeviceExtensionProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumerateDeviceExtensionProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_peek_array_size(dec)) {
        const size_t string_size = vn_decode_array_size(dec, UINT64_MAX);
        args->pLayerName = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pLayerName) * string_size);
        if (!args->pLayerName) return;
        vn_decode_blob_array(dec, (char *)args->pLayerName, string_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pLayerName = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * *args->pPropertyCount);
        if (!args->pProperties) return;
        vn_decode_array_size(dec, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_decode_VkExtensionProperties_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkEnumerateDeviceExtensionProperties_args_handle(struct vn_command_vkEnumerateDeviceExtensionProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pLayerName */
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkEnumerateDeviceExtensionProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumerateDeviceExtensionProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumerateDeviceExtensionProperties_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->physicalDevice */
    /* skip args->pLayerName */
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_encode_VkExtensionProperties(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkGetDeviceQueue_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetDeviceQueue *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->queueFamilyIndex);
    vn_decode_uint32_t(dec, &args->queueIndex);
    if (vn_decode_simple_pointer(dec)) {
        args->pQueue = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueue));
        if (!args->pQueue) return;
        vn_decode_VkQueue_temp(dec, args->pQueue);
    } else {
        args->pQueue = NULL;
    }
}

static inline void vn_replace_vkGetDeviceQueue_args_handle(struct vn_command_vkGetDeviceQueue *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->queueFamilyIndex */
    /* skip args->queueIndex */
    /* skip args->pQueue */
}

static inline void vn_encode_vkGetDeviceQueue_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetDeviceQueue *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetDeviceQueue_EXT});

    /* skip args->device */
    /* skip args->queueFamilyIndex */
    /* skip args->queueIndex */
    if (vn_encode_simple_pointer(enc, args->pQueue))
        vn_encode_VkQueue(enc, args->pQueue);
}

static inline void vn_decode_vkQueueSubmit_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkQueueSubmit *args)
{
    vn_decode_VkQueue_lookup(dec, &args->queue);
    vn_decode_uint32_t(dec, &args->submitCount);
    if (vn_peek_array_size(dec)) {
        args->pSubmits = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSubmits) * args->submitCount);
        if (!args->pSubmits) return;
        vn_decode_array_size(dec, args->submitCount);
        for (uint32_t i = 0; i < args->submitCount; i++)
            vn_decode_VkSubmitInfo_temp(dec, &((VkSubmitInfo *)args->pSubmits)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pSubmits = NULL;
    }
    vn_decode_VkFence_lookup(dec, &args->fence);
}

static inline void vn_replace_vkQueueSubmit_args_handle(struct vn_command_vkQueueSubmit *args)
{
    vn_replace_VkQueue_handle(&args->queue);
    /* skip args->submitCount */
    if (args->pSubmits) {
       for (uint32_t i = 0; i < args->submitCount; i++)
            vn_replace_VkSubmitInfo_handle(&((VkSubmitInfo *)args->pSubmits)[i]);
    }
    vn_replace_VkFence_handle(&args->fence);
}

static inline void vn_encode_vkQueueSubmit_reply(struct vn_cs_encoder *enc, const struct vn_command_vkQueueSubmit *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkQueueSubmit_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->queue */
    /* skip args->submitCount */
    /* skip args->pSubmits */
    /* skip args->fence */
}

static inline void vn_decode_vkQueueWaitIdle_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkQueueWaitIdle *args)
{
    vn_decode_VkQueue_lookup(dec, &args->queue);
}

static inline void vn_replace_vkQueueWaitIdle_args_handle(struct vn_command_vkQueueWaitIdle *args)
{
    vn_replace_VkQueue_handle(&args->queue);
}

static inline void vn_encode_vkQueueWaitIdle_reply(struct vn_cs_encoder *enc, const struct vn_command_vkQueueWaitIdle *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkQueueWaitIdle_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->queue */
}

static inline void vn_decode_vkDeviceWaitIdle_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDeviceWaitIdle *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
}

static inline void vn_replace_vkDeviceWaitIdle_args_handle(struct vn_command_vkDeviceWaitIdle *args)
{
    vn_replace_VkDevice_handle(&args->device);
}

static inline void vn_encode_vkDeviceWaitIdle_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDeviceWaitIdle *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDeviceWaitIdle_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
}

static inline void vn_decode_vkAllocateMemory_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkAllocateMemory *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pAllocateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pAllocateInfo));
        if (!args->pAllocateInfo) return;
        vn_decode_VkMemoryAllocateInfo_temp(dec, (VkMemoryAllocateInfo *)args->pAllocateInfo);
    } else {
        args->pAllocateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pMemory = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemory));
        if (!args->pMemory) return;
        vn_decode_VkDeviceMemory(dec, args->pMemory);
    } else {
        args->pMemory = NULL;
    }
}

static inline void vn_replace_vkAllocateMemory_args_handle(struct vn_command_vkAllocateMemory *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pAllocateInfo)
        vn_replace_VkMemoryAllocateInfo_handle((VkMemoryAllocateInfo *)args->pAllocateInfo);
    /* skip args->pAllocator */
    /* skip args->pMemory */
}

static inline void vn_encode_vkAllocateMemory_reply(struct vn_cs_encoder *enc, const struct vn_command_vkAllocateMemory *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkAllocateMemory_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pAllocateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pMemory))
        vn_encode_VkDeviceMemory(enc, args->pMemory);
}

static inline void vn_decode_vkFreeMemory_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkFreeMemory *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDeviceMemory_lookup(dec, &args->memory);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkFreeMemory_args_handle(struct vn_command_vkFreeMemory *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDeviceMemory_handle(&args->memory);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkFreeMemory_reply(struct vn_cs_encoder *enc, const struct vn_command_vkFreeMemory *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkFreeMemory_EXT});

    /* skip args->device */
    /* skip args->memory */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkUnmapMemory_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkUnmapMemory *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDeviceMemory_lookup(dec, &args->memory);
}

static inline void vn_replace_vkUnmapMemory_args_handle(struct vn_command_vkUnmapMemory *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDeviceMemory_handle(&args->memory);
}

static inline void vn_encode_vkUnmapMemory_reply(struct vn_cs_encoder *enc, const struct vn_command_vkUnmapMemory *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkUnmapMemory_EXT});

    /* skip args->device */
    /* skip args->memory */
}

static inline void vn_decode_vkFlushMappedMemoryRanges_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkFlushMappedMemoryRanges *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->memoryRangeCount);
    if (vn_peek_array_size(dec)) {
        args->pMemoryRanges = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryRanges) * args->memoryRangeCount);
        if (!args->pMemoryRanges) return;
        vn_decode_array_size(dec, args->memoryRangeCount);
        for (uint32_t i = 0; i < args->memoryRangeCount; i++)
            vn_decode_VkMappedMemoryRange_temp(dec, &((VkMappedMemoryRange *)args->pMemoryRanges)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pMemoryRanges = NULL;
    }
}

static inline void vn_replace_vkFlushMappedMemoryRanges_args_handle(struct vn_command_vkFlushMappedMemoryRanges *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->memoryRangeCount */
    if (args->pMemoryRanges) {
       for (uint32_t i = 0; i < args->memoryRangeCount; i++)
            vn_replace_VkMappedMemoryRange_handle(&((VkMappedMemoryRange *)args->pMemoryRanges)[i]);
    }
}

static inline void vn_encode_vkFlushMappedMemoryRanges_reply(struct vn_cs_encoder *enc, const struct vn_command_vkFlushMappedMemoryRanges *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkFlushMappedMemoryRanges_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->memoryRangeCount */
    /* skip args->pMemoryRanges */
}

static inline void vn_decode_vkInvalidateMappedMemoryRanges_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkInvalidateMappedMemoryRanges *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->memoryRangeCount);
    if (vn_peek_array_size(dec)) {
        args->pMemoryRanges = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryRanges) * args->memoryRangeCount);
        if (!args->pMemoryRanges) return;
        vn_decode_array_size(dec, args->memoryRangeCount);
        for (uint32_t i = 0; i < args->memoryRangeCount; i++)
            vn_decode_VkMappedMemoryRange_temp(dec, &((VkMappedMemoryRange *)args->pMemoryRanges)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pMemoryRanges = NULL;
    }
}

static inline void vn_replace_vkInvalidateMappedMemoryRanges_args_handle(struct vn_command_vkInvalidateMappedMemoryRanges *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->memoryRangeCount */
    if (args->pMemoryRanges) {
       for (uint32_t i = 0; i < args->memoryRangeCount; i++)
            vn_replace_VkMappedMemoryRange_handle(&((VkMappedMemoryRange *)args->pMemoryRanges)[i]);
    }
}

static inline void vn_encode_vkInvalidateMappedMemoryRanges_reply(struct vn_cs_encoder *enc, const struct vn_command_vkInvalidateMappedMemoryRanges *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkInvalidateMappedMemoryRanges_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->memoryRangeCount */
    /* skip args->pMemoryRanges */
}

static inline void vn_decode_vkGetDeviceMemoryCommitment_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetDeviceMemoryCommitment *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDeviceMemory_lookup(dec, &args->memory);
    if (vn_decode_simple_pointer(dec)) {
        args->pCommittedMemoryInBytes = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCommittedMemoryInBytes));
        if (!args->pCommittedMemoryInBytes) return;
    } else {
        args->pCommittedMemoryInBytes = NULL;
    }
}

static inline void vn_replace_vkGetDeviceMemoryCommitment_args_handle(struct vn_command_vkGetDeviceMemoryCommitment *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDeviceMemory_handle(&args->memory);
    /* skip args->pCommittedMemoryInBytes */
}

static inline void vn_encode_vkGetDeviceMemoryCommitment_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetDeviceMemoryCommitment *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetDeviceMemoryCommitment_EXT});

    /* skip args->device */
    /* skip args->memory */
    if (vn_encode_simple_pointer(enc, args->pCommittedMemoryInBytes))
        vn_encode_VkDeviceSize(enc, args->pCommittedMemoryInBytes);
}

static inline void vn_decode_vkGetBufferMemoryRequirements_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetBufferMemoryRequirements *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    if (vn_decode_simple_pointer(dec)) {
        args->pMemoryRequirements = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryRequirements));
        if (!args->pMemoryRequirements) return;
        vn_decode_VkMemoryRequirements_partial_temp(dec, args->pMemoryRequirements);
    } else {
        args->pMemoryRequirements = NULL;
    }
}

static inline void vn_replace_vkGetBufferMemoryRequirements_args_handle(struct vn_command_vkGetBufferMemoryRequirements *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->pMemoryRequirements */
}

static inline void vn_encode_vkGetBufferMemoryRequirements_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetBufferMemoryRequirements *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetBufferMemoryRequirements_EXT});

    /* skip args->device */
    /* skip args->buffer */
    if (vn_encode_simple_pointer(enc, args->pMemoryRequirements))
        vn_encode_VkMemoryRequirements(enc, args->pMemoryRequirements);
}

static inline void vn_decode_vkBindBufferMemory_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkBindBufferMemory *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    vn_decode_VkDeviceMemory_lookup(dec, &args->memory);
    vn_decode_VkDeviceSize(dec, &args->memoryOffset);
}

static inline void vn_replace_vkBindBufferMemory_args_handle(struct vn_command_vkBindBufferMemory *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkBuffer_handle(&args->buffer);
    vn_replace_VkDeviceMemory_handle(&args->memory);
    /* skip args->memoryOffset */
}

static inline void vn_encode_vkBindBufferMemory_reply(struct vn_cs_encoder *enc, const struct vn_command_vkBindBufferMemory *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkBindBufferMemory_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->buffer */
    /* skip args->memory */
    /* skip args->memoryOffset */
}

static inline void vn_decode_vkGetImageMemoryRequirements_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetImageMemoryRequirements *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkImage_lookup(dec, &args->image);
    if (vn_decode_simple_pointer(dec)) {
        args->pMemoryRequirements = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryRequirements));
        if (!args->pMemoryRequirements) return;
        vn_decode_VkMemoryRequirements_partial_temp(dec, args->pMemoryRequirements);
    } else {
        args->pMemoryRequirements = NULL;
    }
}

static inline void vn_replace_vkGetImageMemoryRequirements_args_handle(struct vn_command_vkGetImageMemoryRequirements *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkImage_handle(&args->image);
    /* skip args->pMemoryRequirements */
}

static inline void vn_encode_vkGetImageMemoryRequirements_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetImageMemoryRequirements *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetImageMemoryRequirements_EXT});

    /* skip args->device */
    /* skip args->image */
    if (vn_encode_simple_pointer(enc, args->pMemoryRequirements))
        vn_encode_VkMemoryRequirements(enc, args->pMemoryRequirements);
}

static inline void vn_decode_vkBindImageMemory_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkBindImageMemory *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkImage_lookup(dec, &args->image);
    vn_decode_VkDeviceMemory_lookup(dec, &args->memory);
    vn_decode_VkDeviceSize(dec, &args->memoryOffset);
}

static inline void vn_replace_vkBindImageMemory_args_handle(struct vn_command_vkBindImageMemory *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkImage_handle(&args->image);
    vn_replace_VkDeviceMemory_handle(&args->memory);
    /* skip args->memoryOffset */
}

static inline void vn_encode_vkBindImageMemory_reply(struct vn_cs_encoder *enc, const struct vn_command_vkBindImageMemory *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkBindImageMemory_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->image */
    /* skip args->memory */
    /* skip args->memoryOffset */
}

static inline void vn_decode_vkGetImageSparseMemoryRequirements_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetImageSparseMemoryRequirements *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkImage_lookup(dec, &args->image);
    if (vn_decode_simple_pointer(dec)) {
        args->pSparseMemoryRequirementCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSparseMemoryRequirementCount));
        if (!args->pSparseMemoryRequirementCount) return;
        vn_decode_uint32_t(dec, args->pSparseMemoryRequirementCount);
    } else {
        args->pSparseMemoryRequirementCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pSparseMemoryRequirements = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSparseMemoryRequirements) * *args->pSparseMemoryRequirementCount);
        if (!args->pSparseMemoryRequirements) return;
        vn_decode_array_size(dec, *args->pSparseMemoryRequirementCount);
        for (uint32_t i = 0; i < *args->pSparseMemoryRequirementCount; i++)
            vn_decode_VkSparseImageMemoryRequirements_partial_temp(dec, &args->pSparseMemoryRequirements[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pSparseMemoryRequirements = NULL;
    }
}

static inline void vn_replace_vkGetImageSparseMemoryRequirements_args_handle(struct vn_command_vkGetImageSparseMemoryRequirements *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkImage_handle(&args->image);
    /* skip args->pSparseMemoryRequirementCount */
    /* skip args->pSparseMemoryRequirements */
}

static inline void vn_encode_vkGetImageSparseMemoryRequirements_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetImageSparseMemoryRequirements *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetImageSparseMemoryRequirements_EXT});

    /* skip args->device */
    /* skip args->image */
    if (vn_encode_simple_pointer(enc, args->pSparseMemoryRequirementCount))
        vn_encode_uint32_t(enc, args->pSparseMemoryRequirementCount);
    if (args->pSparseMemoryRequirements) {
        vn_encode_array_size(enc, *args->pSparseMemoryRequirementCount);
        for (uint32_t i = 0; i < *args->pSparseMemoryRequirementCount; i++)
            vn_encode_VkSparseImageMemoryRequirements(enc, &args->pSparseMemoryRequirements[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkGetPhysicalDeviceSparseImageFormatProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    vn_decode_VkFormat(dec, &args->format);
    vn_decode_VkImageType(dec, &args->type);
    vn_decode_VkSampleCountFlagBits(dec, &args->samples);
    vn_decode_VkFlags(dec, &args->usage);
    vn_decode_VkImageTiling(dec, &args->tiling);
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * *args->pPropertyCount);
        if (!args->pProperties) return;
        vn_decode_array_size(dec, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_decode_VkSparseImageFormatProperties_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceSparseImageFormatProperties_args_handle(struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->format */
    /* skip args->type */
    /* skip args->samples */
    /* skip args->usage */
    /* skip args->tiling */
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceSparseImageFormatProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceSparseImageFormatProperties_EXT});

    /* skip args->physicalDevice */
    /* skip args->format */
    /* skip args->type */
    /* skip args->samples */
    /* skip args->usage */
    /* skip args->tiling */
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_encode_VkSparseImageFormatProperties(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkQueueBindSparse_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkQueueBindSparse *args)
{
    vn_decode_VkQueue_lookup(dec, &args->queue);
    vn_decode_uint32_t(dec, &args->bindInfoCount);
    if (vn_peek_array_size(dec)) {
        args->pBindInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBindInfo) * args->bindInfoCount);
        if (!args->pBindInfo) return;
        vn_decode_array_size(dec, args->bindInfoCount);
        for (uint32_t i = 0; i < args->bindInfoCount; i++)
            vn_decode_VkBindSparseInfo_temp(dec, &((VkBindSparseInfo *)args->pBindInfo)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pBindInfo = NULL;
    }
    vn_decode_VkFence_lookup(dec, &args->fence);
}

static inline void vn_replace_vkQueueBindSparse_args_handle(struct vn_command_vkQueueBindSparse *args)
{
    vn_replace_VkQueue_handle(&args->queue);
    /* skip args->bindInfoCount */
    if (args->pBindInfo) {
       for (uint32_t i = 0; i < args->bindInfoCount; i++)
            vn_replace_VkBindSparseInfo_handle(&((VkBindSparseInfo *)args->pBindInfo)[i]);
    }
    vn_replace_VkFence_handle(&args->fence);
}

static inline void vn_encode_vkQueueBindSparse_reply(struct vn_cs_encoder *enc, const struct vn_command_vkQueueBindSparse *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkQueueBindSparse_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->queue */
    /* skip args->bindInfoCount */
    /* skip args->pBindInfo */
    /* skip args->fence */
}

static inline void vn_decode_vkCreateFence_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateFence *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkFenceCreateInfo_temp(dec, (VkFenceCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pFence = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFence));
        if (!args->pFence) return;
        vn_decode_VkFence(dec, args->pFence);
    } else {
        args->pFence = NULL;
    }
}

static inline void vn_replace_vkCreateFence_args_handle(struct vn_command_vkCreateFence *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkFenceCreateInfo_handle((VkFenceCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pFence */
}

static inline void vn_encode_vkCreateFence_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateFence *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateFence_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pFence))
        vn_encode_VkFence(enc, args->pFence);
}

static inline void vn_decode_vkDestroyFence_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyFence *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkFence_lookup(dec, &args->fence);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyFence_args_handle(struct vn_command_vkDestroyFence *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkFence_handle(&args->fence);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyFence_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyFence *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyFence_EXT});

    /* skip args->device */
    /* skip args->fence */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkResetFences_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetFences *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->fenceCount);
    if (vn_peek_array_size(dec)) {
        args->pFences = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFences) * args->fenceCount);
        if (!args->pFences) return;
        vn_decode_array_size(dec, args->fenceCount);
        for (uint32_t i = 0; i < args->fenceCount; i++)
            vn_decode_VkFence_lookup(dec, &((VkFence *)args->pFences)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pFences = NULL;
    }
}

static inline void vn_replace_vkResetFences_args_handle(struct vn_command_vkResetFences *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->fenceCount */
    if (args->pFences) {
       for (uint32_t i = 0; i < args->fenceCount; i++)
            vn_replace_VkFence_handle(&((VkFence *)args->pFences)[i]);
    }
}

static inline void vn_encode_vkResetFences_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetFences *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetFences_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->fenceCount */
    /* skip args->pFences */
}

static inline void vn_decode_vkGetFenceStatus_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetFenceStatus *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkFence_lookup(dec, &args->fence);
}

static inline void vn_replace_vkGetFenceStatus_args_handle(struct vn_command_vkGetFenceStatus *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkFence_handle(&args->fence);
}

static inline void vn_encode_vkGetFenceStatus_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetFenceStatus *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetFenceStatus_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->fence */
}

static inline void vn_decode_vkWaitForFences_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkWaitForFences *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->fenceCount);
    if (vn_peek_array_size(dec)) {
        args->pFences = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFences) * args->fenceCount);
        if (!args->pFences) return;
        vn_decode_array_size(dec, args->fenceCount);
        for (uint32_t i = 0; i < args->fenceCount; i++)
            vn_decode_VkFence_lookup(dec, &((VkFence *)args->pFences)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pFences = NULL;
    }
    vn_decode_VkBool32(dec, &args->waitAll);
    vn_decode_uint64_t(dec, &args->timeout);
}

static inline void vn_replace_vkWaitForFences_args_handle(struct vn_command_vkWaitForFences *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->fenceCount */
    if (args->pFences) {
       for (uint32_t i = 0; i < args->fenceCount; i++)
            vn_replace_VkFence_handle(&((VkFence *)args->pFences)[i]);
    }
    /* skip args->waitAll */
    /* skip args->timeout */
}

static inline void vn_encode_vkWaitForFences_reply(struct vn_cs_encoder *enc, const struct vn_command_vkWaitForFences *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkWaitForFences_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->fenceCount */
    /* skip args->pFences */
    /* skip args->waitAll */
    /* skip args->timeout */
}

static inline void vn_decode_vkCreateSemaphore_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateSemaphore *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkSemaphoreCreateInfo_temp(dec, (VkSemaphoreCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSemaphore = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSemaphore));
        if (!args->pSemaphore) return;
        vn_decode_VkSemaphore(dec, args->pSemaphore);
    } else {
        args->pSemaphore = NULL;
    }
}

static inline void vn_replace_vkCreateSemaphore_args_handle(struct vn_command_vkCreateSemaphore *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkSemaphoreCreateInfo_handle((VkSemaphoreCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pSemaphore */
}

static inline void vn_encode_vkCreateSemaphore_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateSemaphore *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateSemaphore_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pSemaphore))
        vn_encode_VkSemaphore(enc, args->pSemaphore);
}

static inline void vn_decode_vkDestroySemaphore_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroySemaphore *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkSemaphore_lookup(dec, &args->semaphore);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroySemaphore_args_handle(struct vn_command_vkDestroySemaphore *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkSemaphore_handle(&args->semaphore);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroySemaphore_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroySemaphore *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroySemaphore_EXT});

    /* skip args->device */
    /* skip args->semaphore */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkEventCreateInfo_temp(dec, (VkEventCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pEvent = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pEvent));
        if (!args->pEvent) return;
        vn_decode_VkEvent(dec, args->pEvent);
    } else {
        args->pEvent = NULL;
    }
}

static inline void vn_replace_vkCreateEvent_args_handle(struct vn_command_vkCreateEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkEventCreateInfo_handle((VkEventCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pEvent */
}

static inline void vn_encode_vkCreateEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateEvent_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pEvent))
        vn_encode_VkEvent(enc, args->pEvent);
}

static inline void vn_decode_vkDestroyEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyEvent_args_handle(struct vn_command_vkDestroyEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyEvent_EXT});

    /* skip args->device */
    /* skip args->event */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetEventStatus_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetEventStatus *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
}

static inline void vn_replace_vkGetEventStatus_args_handle(struct vn_command_vkGetEventStatus *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
}

static inline void vn_encode_vkGetEventStatus_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetEventStatus *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetEventStatus_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->event */
}

static inline void vn_decode_vkSetEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkSetEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
}

static inline void vn_replace_vkSetEvent_args_handle(struct vn_command_vkSetEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
}

static inline void vn_encode_vkSetEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkSetEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkSetEvent_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->event */
}

static inline void vn_decode_vkResetEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetEvent *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkEvent_lookup(dec, &args->event);
}

static inline void vn_replace_vkResetEvent_args_handle(struct vn_command_vkResetEvent *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkEvent_handle(&args->event);
}

static inline void vn_encode_vkResetEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetEvent_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->event */
}

static inline void vn_decode_vkCreateQueryPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateQueryPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkQueryPoolCreateInfo_temp(dec, (VkQueryPoolCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pQueryPool = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueryPool));
        if (!args->pQueryPool) return;
        vn_decode_VkQueryPool(dec, args->pQueryPool);
    } else {
        args->pQueryPool = NULL;
    }
}

static inline void vn_replace_vkCreateQueryPool_args_handle(struct vn_command_vkCreateQueryPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkQueryPoolCreateInfo_handle((VkQueryPoolCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pQueryPool */
}

static inline void vn_encode_vkCreateQueryPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateQueryPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateQueryPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pQueryPool))
        vn_encode_VkQueryPool(enc, args->pQueryPool);
}

static inline void vn_decode_vkDestroyQueryPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyQueryPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyQueryPool_args_handle(struct vn_command_vkDestroyQueryPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyQueryPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyQueryPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyQueryPool_EXT});

    /* skip args->device */
    /* skip args->queryPool */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetQueryPoolResults_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetQueryPoolResults *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->firstQuery);
    vn_decode_uint32_t(dec, &args->queryCount);
    vn_decode_size_t(dec, &args->dataSize);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->dataSize);
        args->pData = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!args->pData) return;
    } else {
        vn_decode_array_size(dec, 0);
        args->pData = NULL;
    }
    vn_decode_VkDeviceSize(dec, &args->stride);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkGetQueryPoolResults_args_handle(struct vn_command_vkGetQueryPoolResults *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->firstQuery */
    /* skip args->queryCount */
    /* skip args->dataSize */
    /* skip args->pData */
    /* skip args->stride */
    /* skip args->flags */
}

static inline void vn_encode_vkGetQueryPoolResults_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetQueryPoolResults *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetQueryPoolResults_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->queryPool */
    /* skip args->firstQuery */
    /* skip args->queryCount */
    /* skip args->dataSize */
    if (args->pData) {
        vn_encode_array_size(enc, args->dataSize);
        vn_encode_blob_array(enc, args->pData, args->dataSize);
    } else {
        vn_encode_array_size(enc, 0);
    }
    /* skip args->stride */
    /* skip args->flags */
}

static inline void vn_decode_vkResetQueryPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetQueryPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->firstQuery);
    vn_decode_uint32_t(dec, &args->queryCount);
}

static inline void vn_replace_vkResetQueryPool_args_handle(struct vn_command_vkResetQueryPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->firstQuery */
    /* skip args->queryCount */
}

static inline void vn_encode_vkResetQueryPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetQueryPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetQueryPool_EXT});

    /* skip args->device */
    /* skip args->queryPool */
    /* skip args->firstQuery */
    /* skip args->queryCount */
}

static inline void vn_decode_vkCreateBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateBuffer *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkBufferCreateInfo_temp(dec, (VkBufferCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pBuffer = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBuffer));
        if (!args->pBuffer) return;
        vn_decode_VkBuffer(dec, args->pBuffer);
    } else {
        args->pBuffer = NULL;
    }
}

static inline void vn_replace_vkCreateBuffer_args_handle(struct vn_command_vkCreateBuffer *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkBufferCreateInfo_handle((VkBufferCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pBuffer */
}

static inline void vn_encode_vkCreateBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateBuffer_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pBuffer))
        vn_encode_VkBuffer(enc, args->pBuffer);
}

static inline void vn_decode_vkDestroyBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyBuffer *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyBuffer_args_handle(struct vn_command_vkDestroyBuffer *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyBuffer_EXT});

    /* skip args->device */
    /* skip args->buffer */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateBufferView_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateBufferView *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkBufferViewCreateInfo_temp(dec, (VkBufferViewCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pView = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pView));
        if (!args->pView) return;
        vn_decode_VkBufferView(dec, args->pView);
    } else {
        args->pView = NULL;
    }
}

static inline void vn_replace_vkCreateBufferView_args_handle(struct vn_command_vkCreateBufferView *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkBufferViewCreateInfo_handle((VkBufferViewCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pView */
}

static inline void vn_encode_vkCreateBufferView_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateBufferView *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateBufferView_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pView))
        vn_encode_VkBufferView(enc, args->pView);
}

static inline void vn_decode_vkDestroyBufferView_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyBufferView *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkBufferView_lookup(dec, &args->bufferView);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyBufferView_args_handle(struct vn_command_vkDestroyBufferView *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkBufferView_handle(&args->bufferView);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyBufferView_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyBufferView *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyBufferView_EXT});

    /* skip args->device */
    /* skip args->bufferView */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateImage *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkImageCreateInfo_temp(dec, (VkImageCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pImage = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pImage));
        if (!args->pImage) return;
        vn_decode_VkImage(dec, args->pImage);
    } else {
        args->pImage = NULL;
    }
}

static inline void vn_replace_vkCreateImage_args_handle(struct vn_command_vkCreateImage *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkImageCreateInfo_handle((VkImageCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pImage */
}

static inline void vn_encode_vkCreateImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateImage_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pImage))
        vn_encode_VkImage(enc, args->pImage);
}

static inline void vn_decode_vkDestroyImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyImage *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkImage_lookup(dec, &args->image);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyImage_args_handle(struct vn_command_vkDestroyImage *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkImage_handle(&args->image);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyImage_EXT});

    /* skip args->device */
    /* skip args->image */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetImageSubresourceLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetImageSubresourceLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkImage_lookup(dec, &args->image);
    if (vn_decode_simple_pointer(dec)) {
        args->pSubresource = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSubresource));
        if (!args->pSubresource) return;
        vn_decode_VkImageSubresource_temp(dec, (VkImageSubresource *)args->pSubresource);
    } else {
        args->pSubresource = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pLayout = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pLayout));
        if (!args->pLayout) return;
        vn_decode_VkSubresourceLayout_partial_temp(dec, args->pLayout);
    } else {
        args->pLayout = NULL;
    }
}

static inline void vn_replace_vkGetImageSubresourceLayout_args_handle(struct vn_command_vkGetImageSubresourceLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkImage_handle(&args->image);
    if (args->pSubresource)
        vn_replace_VkImageSubresource_handle((VkImageSubresource *)args->pSubresource);
    /* skip args->pLayout */
}

static inline void vn_encode_vkGetImageSubresourceLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetImageSubresourceLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetImageSubresourceLayout_EXT});

    /* skip args->device */
    /* skip args->image */
    /* skip args->pSubresource */
    if (vn_encode_simple_pointer(enc, args->pLayout))
        vn_encode_VkSubresourceLayout(enc, args->pLayout);
}

static inline void vn_decode_vkCreateImageView_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateImageView *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkImageViewCreateInfo_temp(dec, (VkImageViewCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pView = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pView));
        if (!args->pView) return;
        vn_decode_VkImageView(dec, args->pView);
    } else {
        args->pView = NULL;
    }
}

static inline void vn_replace_vkCreateImageView_args_handle(struct vn_command_vkCreateImageView *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkImageViewCreateInfo_handle((VkImageViewCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pView */
}

static inline void vn_encode_vkCreateImageView_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateImageView *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateImageView_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pView))
        vn_encode_VkImageView(enc, args->pView);
}

static inline void vn_decode_vkDestroyImageView_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyImageView *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkImageView_lookup(dec, &args->imageView);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyImageView_args_handle(struct vn_command_vkDestroyImageView *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkImageView_handle(&args->imageView);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyImageView_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyImageView *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyImageView_EXT});

    /* skip args->device */
    /* skip args->imageView */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateShaderModule_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateShaderModule *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkShaderModuleCreateInfo_temp(dec, (VkShaderModuleCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pShaderModule = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pShaderModule));
        if (!args->pShaderModule) return;
        vn_decode_VkShaderModule(dec, args->pShaderModule);
    } else {
        args->pShaderModule = NULL;
    }
}

static inline void vn_replace_vkCreateShaderModule_args_handle(struct vn_command_vkCreateShaderModule *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkShaderModuleCreateInfo_handle((VkShaderModuleCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pShaderModule */
}

static inline void vn_encode_vkCreateShaderModule_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateShaderModule *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateShaderModule_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pShaderModule))
        vn_encode_VkShaderModule(enc, args->pShaderModule);
}

static inline void vn_decode_vkDestroyShaderModule_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyShaderModule *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkShaderModule_lookup(dec, &args->shaderModule);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyShaderModule_args_handle(struct vn_command_vkDestroyShaderModule *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkShaderModule_handle(&args->shaderModule);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyShaderModule_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyShaderModule *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyShaderModule_EXT});

    /* skip args->device */
    /* skip args->shaderModule */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreatePipelineCache_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreatePipelineCache *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkPipelineCacheCreateInfo_temp(dec, (VkPipelineCacheCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pPipelineCache = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPipelineCache));
        if (!args->pPipelineCache) return;
        vn_decode_VkPipelineCache(dec, args->pPipelineCache);
    } else {
        args->pPipelineCache = NULL;
    }
}

static inline void vn_replace_vkCreatePipelineCache_args_handle(struct vn_command_vkCreatePipelineCache *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkPipelineCacheCreateInfo_handle((VkPipelineCacheCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pPipelineCache */
}

static inline void vn_encode_vkCreatePipelineCache_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreatePipelineCache *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreatePipelineCache_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pPipelineCache))
        vn_encode_VkPipelineCache(enc, args->pPipelineCache);
}

static inline void vn_decode_vkDestroyPipelineCache_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyPipelineCache *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipelineCache_lookup(dec, &args->pipelineCache);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyPipelineCache_args_handle(struct vn_command_vkDestroyPipelineCache *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipelineCache_handle(&args->pipelineCache);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyPipelineCache_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyPipelineCache *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyPipelineCache_EXT});

    /* skip args->device */
    /* skip args->pipelineCache */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetPipelineCacheData_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPipelineCacheData *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipelineCache_lookup(dec, &args->pipelineCache);
    if (vn_decode_simple_pointer(dec)) {
        args->pDataSize = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDataSize));
        if (!args->pDataSize) return;
        vn_decode_size_t(dec, args->pDataSize);
    } else {
        args->pDataSize = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, *args->pDataSize);
        args->pData = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!args->pData) return;
    } else {
        vn_decode_array_size(dec, 0);
        args->pData = NULL;
    }
}

static inline void vn_replace_vkGetPipelineCacheData_args_handle(struct vn_command_vkGetPipelineCacheData *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipelineCache_handle(&args->pipelineCache);
    /* skip args->pDataSize */
    /* skip args->pData */
}

static inline void vn_encode_vkGetPipelineCacheData_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPipelineCacheData *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPipelineCacheData_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pipelineCache */
    if (vn_encode_simple_pointer(enc, args->pDataSize))
        vn_encode_size_t(enc, args->pDataSize);
    if (args->pData) {
        vn_encode_array_size(enc, *args->pDataSize);
        vn_encode_blob_array(enc, args->pData, *args->pDataSize);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkMergePipelineCaches_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkMergePipelineCaches *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipelineCache_lookup(dec, &args->dstCache);
    vn_decode_uint32_t(dec, &args->srcCacheCount);
    if (vn_peek_array_size(dec)) {
        args->pSrcCaches = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSrcCaches) * args->srcCacheCount);
        if (!args->pSrcCaches) return;
        vn_decode_array_size(dec, args->srcCacheCount);
        for (uint32_t i = 0; i < args->srcCacheCount; i++)
            vn_decode_VkPipelineCache_lookup(dec, &((VkPipelineCache *)args->pSrcCaches)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pSrcCaches = NULL;
    }
}

static inline void vn_replace_vkMergePipelineCaches_args_handle(struct vn_command_vkMergePipelineCaches *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipelineCache_handle(&args->dstCache);
    /* skip args->srcCacheCount */
    if (args->pSrcCaches) {
       for (uint32_t i = 0; i < args->srcCacheCount; i++)
            vn_replace_VkPipelineCache_handle(&((VkPipelineCache *)args->pSrcCaches)[i]);
    }
}

static inline void vn_encode_vkMergePipelineCaches_reply(struct vn_cs_encoder *enc, const struct vn_command_vkMergePipelineCaches *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkMergePipelineCaches_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->dstCache */
    /* skip args->srcCacheCount */
    /* skip args->pSrcCaches */
}

static inline void vn_decode_vkCreateGraphicsPipelines_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateGraphicsPipelines *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipelineCache_lookup(dec, &args->pipelineCache);
    vn_decode_uint32_t(dec, &args->createInfoCount);
    if (vn_peek_array_size(dec)) {
        args->pCreateInfos = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfos) * args->createInfoCount);
        if (!args->pCreateInfos) return;
        vn_decode_array_size(dec, args->createInfoCount);
        for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_decode_VkGraphicsPipelineCreateInfo_temp(dec, &((VkGraphicsPipelineCreateInfo *)args->pCreateInfos)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCreateInfos = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pPipelines = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPipelines) * args->createInfoCount);
        if (!args->pPipelines) return;
        vn_decode_array_size(dec, args->createInfoCount);
        for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_decode_VkPipeline(dec, &args->pPipelines[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pPipelines = NULL;
    }
}

static inline void vn_replace_vkCreateGraphicsPipelines_args_handle(struct vn_command_vkCreateGraphicsPipelines *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipelineCache_handle(&args->pipelineCache);
    /* skip args->createInfoCount */
    if (args->pCreateInfos) {
       for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_replace_VkGraphicsPipelineCreateInfo_handle(&((VkGraphicsPipelineCreateInfo *)args->pCreateInfos)[i]);
    }
    /* skip args->pAllocator */
    /* skip args->pPipelines */
}

static inline void vn_encode_vkCreateGraphicsPipelines_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateGraphicsPipelines *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateGraphicsPipelines_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pipelineCache */
    /* skip args->createInfoCount */
    /* skip args->pCreateInfos */
    /* skip args->pAllocator */
    if (args->pPipelines) {
        vn_encode_array_size(enc, args->createInfoCount);
        for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_encode_VkPipeline(enc, &args->pPipelines[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkCreateComputePipelines_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateComputePipelines *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipelineCache_lookup(dec, &args->pipelineCache);
    vn_decode_uint32_t(dec, &args->createInfoCount);
    if (vn_peek_array_size(dec)) {
        args->pCreateInfos = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfos) * args->createInfoCount);
        if (!args->pCreateInfos) return;
        vn_decode_array_size(dec, args->createInfoCount);
        for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_decode_VkComputePipelineCreateInfo_temp(dec, &((VkComputePipelineCreateInfo *)args->pCreateInfos)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCreateInfos = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pPipelines = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPipelines) * args->createInfoCount);
        if (!args->pPipelines) return;
        vn_decode_array_size(dec, args->createInfoCount);
        for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_decode_VkPipeline(dec, &args->pPipelines[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pPipelines = NULL;
    }
}

static inline void vn_replace_vkCreateComputePipelines_args_handle(struct vn_command_vkCreateComputePipelines *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipelineCache_handle(&args->pipelineCache);
    /* skip args->createInfoCount */
    if (args->pCreateInfos) {
       for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_replace_VkComputePipelineCreateInfo_handle(&((VkComputePipelineCreateInfo *)args->pCreateInfos)[i]);
    }
    /* skip args->pAllocator */
    /* skip args->pPipelines */
}

static inline void vn_encode_vkCreateComputePipelines_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateComputePipelines *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateComputePipelines_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pipelineCache */
    /* skip args->createInfoCount */
    /* skip args->pCreateInfos */
    /* skip args->pAllocator */
    if (args->pPipelines) {
        vn_encode_array_size(enc, args->createInfoCount);
        for (uint32_t i = 0; i < args->createInfoCount; i++)
            vn_encode_VkPipeline(enc, &args->pPipelines[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkDestroyPipeline_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyPipeline *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipeline_lookup(dec, &args->pipeline);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyPipeline_args_handle(struct vn_command_vkDestroyPipeline *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipeline_handle(&args->pipeline);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyPipeline_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyPipeline *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyPipeline_EXT});

    /* skip args->device */
    /* skip args->pipeline */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreatePipelineLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreatePipelineLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkPipelineLayoutCreateInfo_temp(dec, (VkPipelineLayoutCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pPipelineLayout = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPipelineLayout));
        if (!args->pPipelineLayout) return;
        vn_decode_VkPipelineLayout(dec, args->pPipelineLayout);
    } else {
        args->pPipelineLayout = NULL;
    }
}

static inline void vn_replace_vkCreatePipelineLayout_args_handle(struct vn_command_vkCreatePipelineLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkPipelineLayoutCreateInfo_handle((VkPipelineLayoutCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pPipelineLayout */
}

static inline void vn_encode_vkCreatePipelineLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreatePipelineLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreatePipelineLayout_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pPipelineLayout))
        vn_encode_VkPipelineLayout(enc, args->pPipelineLayout);
}

static inline void vn_decode_vkDestroyPipelineLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyPipelineLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkPipelineLayout_lookup(dec, &args->pipelineLayout);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyPipelineLayout_args_handle(struct vn_command_vkDestroyPipelineLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkPipelineLayout_handle(&args->pipelineLayout);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyPipelineLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyPipelineLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyPipelineLayout_EXT});

    /* skip args->device */
    /* skip args->pipelineLayout */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateSampler_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateSampler *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkSamplerCreateInfo_temp(dec, (VkSamplerCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSampler = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSampler));
        if (!args->pSampler) return;
        vn_decode_VkSampler(dec, args->pSampler);
    } else {
        args->pSampler = NULL;
    }
}

static inline void vn_replace_vkCreateSampler_args_handle(struct vn_command_vkCreateSampler *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkSamplerCreateInfo_handle((VkSamplerCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pSampler */
}

static inline void vn_encode_vkCreateSampler_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateSampler *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateSampler_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pSampler))
        vn_encode_VkSampler(enc, args->pSampler);
}

static inline void vn_decode_vkDestroySampler_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroySampler *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkSampler_lookup(dec, &args->sampler);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroySampler_args_handle(struct vn_command_vkDestroySampler *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkSampler_handle(&args->sampler);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroySampler_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroySampler *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroySampler_EXT});

    /* skip args->device */
    /* skip args->sampler */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateDescriptorSetLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateDescriptorSetLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDescriptorSetLayoutCreateInfo_temp(dec, (VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSetLayout = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSetLayout));
        if (!args->pSetLayout) return;
        vn_decode_VkDescriptorSetLayout(dec, args->pSetLayout);
    } else {
        args->pSetLayout = NULL;
    }
}

static inline void vn_replace_vkCreateDescriptorSetLayout_args_handle(struct vn_command_vkCreateDescriptorSetLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkDescriptorSetLayoutCreateInfo_handle((VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pSetLayout */
}

static inline void vn_encode_vkCreateDescriptorSetLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateDescriptorSetLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateDescriptorSetLayout_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pSetLayout))
        vn_encode_VkDescriptorSetLayout(enc, args->pSetLayout);
}

static inline void vn_decode_vkDestroyDescriptorSetLayout_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyDescriptorSetLayout *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorSetLayout_lookup(dec, &args->descriptorSetLayout);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyDescriptorSetLayout_args_handle(struct vn_command_vkDestroyDescriptorSetLayout *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorSetLayout_handle(&args->descriptorSetLayout);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyDescriptorSetLayout_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyDescriptorSetLayout *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyDescriptorSetLayout_EXT});

    /* skip args->device */
    /* skip args->descriptorSetLayout */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateDescriptorPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateDescriptorPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDescriptorPoolCreateInfo_temp(dec, (VkDescriptorPoolCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pDescriptorPool = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorPool));
        if (!args->pDescriptorPool) return;
        vn_decode_VkDescriptorPool(dec, args->pDescriptorPool);
    } else {
        args->pDescriptorPool = NULL;
    }
}

static inline void vn_replace_vkCreateDescriptorPool_args_handle(struct vn_command_vkCreateDescriptorPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkDescriptorPoolCreateInfo_handle((VkDescriptorPoolCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pDescriptorPool */
}

static inline void vn_encode_vkCreateDescriptorPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateDescriptorPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateDescriptorPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pDescriptorPool))
        vn_encode_VkDescriptorPool(enc, args->pDescriptorPool);
}

static inline void vn_decode_vkDestroyDescriptorPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyDescriptorPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorPool_lookup(dec, &args->descriptorPool);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyDescriptorPool_args_handle(struct vn_command_vkDestroyDescriptorPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorPool_handle(&args->descriptorPool);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyDescriptorPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyDescriptorPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyDescriptorPool_EXT});

    /* skip args->device */
    /* skip args->descriptorPool */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkResetDescriptorPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetDescriptorPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorPool_lookup(dec, &args->descriptorPool);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkResetDescriptorPool_args_handle(struct vn_command_vkResetDescriptorPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorPool_handle(&args->descriptorPool);
    /* skip args->flags */
}

static inline void vn_encode_vkResetDescriptorPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetDescriptorPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetDescriptorPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->descriptorPool */
    /* skip args->flags */
}

static inline void vn_decode_vkAllocateDescriptorSets_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkAllocateDescriptorSets *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pAllocateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pAllocateInfo));
        if (!args->pAllocateInfo) return;
        vn_decode_VkDescriptorSetAllocateInfo_temp(dec, (VkDescriptorSetAllocateInfo *)args->pAllocateInfo);
    } else {
        args->pAllocateInfo = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pDescriptorSets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorSets) * args->pAllocateInfo->descriptorSetCount);
        if (!args->pDescriptorSets) return;
        vn_decode_array_size(dec, args->pAllocateInfo->descriptorSetCount);
        for (uint32_t i = 0; i < args->pAllocateInfo->descriptorSetCount; i++)
            vn_decode_VkDescriptorSet(dec, &args->pDescriptorSets[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pDescriptorSets = NULL;
    }
}

static inline void vn_replace_vkAllocateDescriptorSets_args_handle(struct vn_command_vkAllocateDescriptorSets *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pAllocateInfo)
        vn_replace_VkDescriptorSetAllocateInfo_handle((VkDescriptorSetAllocateInfo *)args->pAllocateInfo);
    /* skip args->pDescriptorSets */
}

static inline void vn_encode_vkAllocateDescriptorSets_reply(struct vn_cs_encoder *enc, const struct vn_command_vkAllocateDescriptorSets *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkAllocateDescriptorSets_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pAllocateInfo */
    if (args->pDescriptorSets) {
        vn_encode_array_size(enc, args->pAllocateInfo->descriptorSetCount);
        for (uint32_t i = 0; i < args->pAllocateInfo->descriptorSetCount; i++)
            vn_encode_VkDescriptorSet(enc, &args->pDescriptorSets[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkFreeDescriptorSets_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkFreeDescriptorSets *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorPool_lookup(dec, &args->descriptorPool);
    vn_decode_uint32_t(dec, &args->descriptorSetCount);
    if (vn_peek_array_size(dec)) {
        args->pDescriptorSets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorSets) * args->descriptorSetCount);
        if (!args->pDescriptorSets) return;
        vn_decode_array_size(dec, args->descriptorSetCount);
        for (uint32_t i = 0; i < args->descriptorSetCount; i++)
            vn_decode_VkDescriptorSet_lookup(dec, &((VkDescriptorSet *)args->pDescriptorSets)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pDescriptorSets = NULL;
    }
}

static inline void vn_replace_vkFreeDescriptorSets_args_handle(struct vn_command_vkFreeDescriptorSets *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorPool_handle(&args->descriptorPool);
    /* skip args->descriptorSetCount */
    if (args->pDescriptorSets) {
       for (uint32_t i = 0; i < args->descriptorSetCount; i++)
            vn_replace_VkDescriptorSet_handle(&((VkDescriptorSet *)args->pDescriptorSets)[i]);
    }
}

static inline void vn_encode_vkFreeDescriptorSets_reply(struct vn_cs_encoder *enc, const struct vn_command_vkFreeDescriptorSets *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkFreeDescriptorSets_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->descriptorPool */
    /* skip args->descriptorSetCount */
    /* skip args->pDescriptorSets */
}

static inline void vn_decode_vkUpdateDescriptorSets_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkUpdateDescriptorSets *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->descriptorWriteCount);
    if (vn_peek_array_size(dec)) {
        args->pDescriptorWrites = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorWrites) * args->descriptorWriteCount);
        if (!args->pDescriptorWrites) return;
        vn_decode_array_size(dec, args->descriptorWriteCount);
        for (uint32_t i = 0; i < args->descriptorWriteCount; i++)
            vn_decode_VkWriteDescriptorSet_temp(dec, &((VkWriteDescriptorSet *)args->pDescriptorWrites)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pDescriptorWrites = NULL;
    }
    vn_decode_uint32_t(dec, &args->descriptorCopyCount);
    if (vn_peek_array_size(dec)) {
        args->pDescriptorCopies = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorCopies) * args->descriptorCopyCount);
        if (!args->pDescriptorCopies) return;
        vn_decode_array_size(dec, args->descriptorCopyCount);
        for (uint32_t i = 0; i < args->descriptorCopyCount; i++)
            vn_decode_VkCopyDescriptorSet_temp(dec, &((VkCopyDescriptorSet *)args->pDescriptorCopies)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pDescriptorCopies = NULL;
    }
}

static inline void vn_replace_vkUpdateDescriptorSets_args_handle(struct vn_command_vkUpdateDescriptorSets *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->descriptorWriteCount */
    if (args->pDescriptorWrites) {
       for (uint32_t i = 0; i < args->descriptorWriteCount; i++)
            vn_replace_VkWriteDescriptorSet_handle(&((VkWriteDescriptorSet *)args->pDescriptorWrites)[i]);
    }
    /* skip args->descriptorCopyCount */
    if (args->pDescriptorCopies) {
       for (uint32_t i = 0; i < args->descriptorCopyCount; i++)
            vn_replace_VkCopyDescriptorSet_handle(&((VkCopyDescriptorSet *)args->pDescriptorCopies)[i]);
    }
}

static inline void vn_encode_vkUpdateDescriptorSets_reply(struct vn_cs_encoder *enc, const struct vn_command_vkUpdateDescriptorSets *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkUpdateDescriptorSets_EXT});

    /* skip args->device */
    /* skip args->descriptorWriteCount */
    /* skip args->pDescriptorWrites */
    /* skip args->descriptorCopyCount */
    /* skip args->pDescriptorCopies */
}

static inline void vn_decode_vkCreateFramebuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateFramebuffer *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkFramebufferCreateInfo_temp(dec, (VkFramebufferCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pFramebuffer = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFramebuffer));
        if (!args->pFramebuffer) return;
        vn_decode_VkFramebuffer(dec, args->pFramebuffer);
    } else {
        args->pFramebuffer = NULL;
    }
}

static inline void vn_replace_vkCreateFramebuffer_args_handle(struct vn_command_vkCreateFramebuffer *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkFramebufferCreateInfo_handle((VkFramebufferCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pFramebuffer */
}

static inline void vn_encode_vkCreateFramebuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateFramebuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateFramebuffer_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pFramebuffer))
        vn_encode_VkFramebuffer(enc, args->pFramebuffer);
}

static inline void vn_decode_vkDestroyFramebuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyFramebuffer *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkFramebuffer_lookup(dec, &args->framebuffer);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyFramebuffer_args_handle(struct vn_command_vkDestroyFramebuffer *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkFramebuffer_handle(&args->framebuffer);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyFramebuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyFramebuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyFramebuffer_EXT});

    /* skip args->device */
    /* skip args->framebuffer */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkCreateRenderPass_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateRenderPass *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkRenderPassCreateInfo_temp(dec, (VkRenderPassCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pRenderPass = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRenderPass));
        if (!args->pRenderPass) return;
        vn_decode_VkRenderPass(dec, args->pRenderPass);
    } else {
        args->pRenderPass = NULL;
    }
}

static inline void vn_replace_vkCreateRenderPass_args_handle(struct vn_command_vkCreateRenderPass *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkRenderPassCreateInfo_handle((VkRenderPassCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pRenderPass */
}

static inline void vn_encode_vkCreateRenderPass_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateRenderPass *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateRenderPass_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pRenderPass))
        vn_encode_VkRenderPass(enc, args->pRenderPass);
}

static inline void vn_decode_vkDestroyRenderPass_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyRenderPass *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkRenderPass_lookup(dec, &args->renderPass);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyRenderPass_args_handle(struct vn_command_vkDestroyRenderPass *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkRenderPass_handle(&args->renderPass);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyRenderPass_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyRenderPass *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyRenderPass_EXT});

    /* skip args->device */
    /* skip args->renderPass */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetRenderAreaGranularity_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetRenderAreaGranularity *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkRenderPass_lookup(dec, &args->renderPass);
    if (vn_decode_simple_pointer(dec)) {
        args->pGranularity = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pGranularity));
        if (!args->pGranularity) return;
        vn_decode_VkExtent2D_partial_temp(dec, args->pGranularity);
    } else {
        args->pGranularity = NULL;
    }
}

static inline void vn_replace_vkGetRenderAreaGranularity_args_handle(struct vn_command_vkGetRenderAreaGranularity *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkRenderPass_handle(&args->renderPass);
    /* skip args->pGranularity */
}

static inline void vn_encode_vkGetRenderAreaGranularity_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetRenderAreaGranularity *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetRenderAreaGranularity_EXT});

    /* skip args->device */
    /* skip args->renderPass */
    if (vn_encode_simple_pointer(enc, args->pGranularity))
        vn_encode_VkExtent2D(enc, args->pGranularity);
}

static inline void vn_decode_vkCreateCommandPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateCommandPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkCommandPoolCreateInfo_temp(dec, (VkCommandPoolCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pCommandPool = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCommandPool));
        if (!args->pCommandPool) return;
        vn_decode_VkCommandPool(dec, args->pCommandPool);
    } else {
        args->pCommandPool = NULL;
    }
}

static inline void vn_replace_vkCreateCommandPool_args_handle(struct vn_command_vkCreateCommandPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkCommandPoolCreateInfo_handle((VkCommandPoolCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pCommandPool */
}

static inline void vn_encode_vkCreateCommandPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateCommandPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateCommandPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pCommandPool))
        vn_encode_VkCommandPool(enc, args->pCommandPool);
}

static inline void vn_decode_vkDestroyCommandPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyCommandPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkCommandPool_lookup(dec, &args->commandPool);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyCommandPool_args_handle(struct vn_command_vkDestroyCommandPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkCommandPool_handle(&args->commandPool);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyCommandPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyCommandPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyCommandPool_EXT});

    /* skip args->device */
    /* skip args->commandPool */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkResetCommandPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetCommandPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkCommandPool_lookup(dec, &args->commandPool);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkResetCommandPool_args_handle(struct vn_command_vkResetCommandPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkCommandPool_handle(&args->commandPool);
    /* skip args->flags */
}

static inline void vn_encode_vkResetCommandPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetCommandPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetCommandPool_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->commandPool */
    /* skip args->flags */
}

static inline void vn_decode_vkAllocateCommandBuffers_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkAllocateCommandBuffers *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pAllocateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pAllocateInfo));
        if (!args->pAllocateInfo) return;
        vn_decode_VkCommandBufferAllocateInfo_temp(dec, (VkCommandBufferAllocateInfo *)args->pAllocateInfo);
    } else {
        args->pAllocateInfo = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pCommandBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCommandBuffers) * args->pAllocateInfo->commandBufferCount);
        if (!args->pCommandBuffers) return;
        vn_decode_array_size(dec, args->pAllocateInfo->commandBufferCount);
        for (uint32_t i = 0; i < args->pAllocateInfo->commandBufferCount; i++)
            vn_decode_VkCommandBuffer_temp(dec, &args->pCommandBuffers[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCommandBuffers = NULL;
    }
}

static inline void vn_replace_vkAllocateCommandBuffers_args_handle(struct vn_command_vkAllocateCommandBuffers *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pAllocateInfo)
        vn_replace_VkCommandBufferAllocateInfo_handle((VkCommandBufferAllocateInfo *)args->pAllocateInfo);
    /* skip args->pCommandBuffers */
}

static inline void vn_encode_vkAllocateCommandBuffers_reply(struct vn_cs_encoder *enc, const struct vn_command_vkAllocateCommandBuffers *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkAllocateCommandBuffers_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pAllocateInfo */
    if (args->pCommandBuffers) {
        vn_encode_array_size(enc, args->pAllocateInfo->commandBufferCount);
        for (uint32_t i = 0; i < args->pAllocateInfo->commandBufferCount; i++)
            vn_encode_VkCommandBuffer(enc, &args->pCommandBuffers[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkFreeCommandBuffers_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkFreeCommandBuffers *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkCommandPool_lookup(dec, &args->commandPool);
    vn_decode_uint32_t(dec, &args->commandBufferCount);
    if (vn_peek_array_size(dec)) {
        args->pCommandBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCommandBuffers) * args->commandBufferCount);
        if (!args->pCommandBuffers) return;
        vn_decode_array_size(dec, args->commandBufferCount);
        for (uint32_t i = 0; i < args->commandBufferCount; i++)
            vn_decode_VkCommandBuffer_lookup(dec, &((VkCommandBuffer *)args->pCommandBuffers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCommandBuffers = NULL;
    }
}

static inline void vn_replace_vkFreeCommandBuffers_args_handle(struct vn_command_vkFreeCommandBuffers *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkCommandPool_handle(&args->commandPool);
    /* skip args->commandBufferCount */
    if (args->pCommandBuffers) {
       for (uint32_t i = 0; i < args->commandBufferCount; i++)
            vn_replace_VkCommandBuffer_handle(&((VkCommandBuffer *)args->pCommandBuffers)[i]);
    }
}

static inline void vn_encode_vkFreeCommandBuffers_reply(struct vn_cs_encoder *enc, const struct vn_command_vkFreeCommandBuffers *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkFreeCommandBuffers_EXT});

    /* skip args->device */
    /* skip args->commandPool */
    /* skip args->commandBufferCount */
    /* skip args->pCommandBuffers */
}

static inline void vn_decode_vkBeginCommandBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkBeginCommandBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    if (vn_decode_simple_pointer(dec)) {
        args->pBeginInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBeginInfo));
        if (!args->pBeginInfo) return;
        vn_decode_VkCommandBufferBeginInfo_temp(dec, (VkCommandBufferBeginInfo *)args->pBeginInfo);
    } else {
        args->pBeginInfo = NULL;
    }
}

static inline void vn_replace_vkBeginCommandBuffer_args_handle(struct vn_command_vkBeginCommandBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    if (args->pBeginInfo)
        vn_replace_VkCommandBufferBeginInfo_handle((VkCommandBufferBeginInfo *)args->pBeginInfo);
}

static inline void vn_encode_vkBeginCommandBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkBeginCommandBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkBeginCommandBuffer_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->commandBuffer */
    /* skip args->pBeginInfo */
}

static inline void vn_decode_vkEndCommandBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEndCommandBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
}

static inline void vn_replace_vkEndCommandBuffer_args_handle(struct vn_command_vkEndCommandBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
}

static inline void vn_encode_vkEndCommandBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEndCommandBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEndCommandBuffer_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->commandBuffer */
}

static inline void vn_decode_vkResetCommandBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkResetCommandBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkResetCommandBuffer_args_handle(struct vn_command_vkResetCommandBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->flags */
}

static inline void vn_encode_vkResetCommandBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkResetCommandBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkResetCommandBuffer_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->commandBuffer */
    /* skip args->flags */
}

static inline void vn_decode_vkCmdBindPipeline_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBindPipeline *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkPipelineBindPoint(dec, &args->pipelineBindPoint);
    vn_decode_VkPipeline_lookup(dec, &args->pipeline);
}

static inline void vn_replace_vkCmdBindPipeline_args_handle(struct vn_command_vkCmdBindPipeline *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->pipelineBindPoint */
    vn_replace_VkPipeline_handle(&args->pipeline);
}

static inline void vn_encode_vkCmdBindPipeline_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBindPipeline *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBindPipeline_EXT});

    /* skip args->commandBuffer */
    /* skip args->pipelineBindPoint */
    /* skip args->pipeline */
}

static inline void vn_decode_vkCmdSetViewport_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetViewport *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->firstViewport);
    vn_decode_uint32_t(dec, &args->viewportCount);
    if (vn_peek_array_size(dec)) {
        args->pViewports = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pViewports) * args->viewportCount);
        if (!args->pViewports) return;
        vn_decode_array_size(dec, args->viewportCount);
        for (uint32_t i = 0; i < args->viewportCount; i++)
            vn_decode_VkViewport_temp(dec, &((VkViewport *)args->pViewports)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pViewports = NULL;
    }
}

static inline void vn_replace_vkCmdSetViewport_args_handle(struct vn_command_vkCmdSetViewport *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->firstViewport */
    /* skip args->viewportCount */
    if (args->pViewports) {
       for (uint32_t i = 0; i < args->viewportCount; i++)
            vn_replace_VkViewport_handle(&((VkViewport *)args->pViewports)[i]);
    }
}

static inline void vn_encode_vkCmdSetViewport_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetViewport *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetViewport_EXT});

    /* skip args->commandBuffer */
    /* skip args->firstViewport */
    /* skip args->viewportCount */
    /* skip args->pViewports */
}

static inline void vn_decode_vkCmdSetScissor_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetScissor *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->firstScissor);
    vn_decode_uint32_t(dec, &args->scissorCount);
    if (vn_peek_array_size(dec)) {
        args->pScissors = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pScissors) * args->scissorCount);
        if (!args->pScissors) return;
        vn_decode_array_size(dec, args->scissorCount);
        for (uint32_t i = 0; i < args->scissorCount; i++)
            vn_decode_VkRect2D_temp(dec, &((VkRect2D *)args->pScissors)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pScissors = NULL;
    }
}

static inline void vn_replace_vkCmdSetScissor_args_handle(struct vn_command_vkCmdSetScissor *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->firstScissor */
    /* skip args->scissorCount */
    if (args->pScissors) {
       for (uint32_t i = 0; i < args->scissorCount; i++)
            vn_replace_VkRect2D_handle(&((VkRect2D *)args->pScissors)[i]);
    }
}

static inline void vn_encode_vkCmdSetScissor_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetScissor *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetScissor_EXT});

    /* skip args->commandBuffer */
    /* skip args->firstScissor */
    /* skip args->scissorCount */
    /* skip args->pScissors */
}

static inline void vn_decode_vkCmdSetLineWidth_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetLineWidth *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_float(dec, &args->lineWidth);
}

static inline void vn_replace_vkCmdSetLineWidth_args_handle(struct vn_command_vkCmdSetLineWidth *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->lineWidth */
}

static inline void vn_encode_vkCmdSetLineWidth_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetLineWidth *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetLineWidth_EXT});

    /* skip args->commandBuffer */
    /* skip args->lineWidth */
}

static inline void vn_decode_vkCmdSetDepthBias_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetDepthBias *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_float(dec, &args->depthBiasConstantFactor);
    vn_decode_float(dec, &args->depthBiasClamp);
    vn_decode_float(dec, &args->depthBiasSlopeFactor);
}

static inline void vn_replace_vkCmdSetDepthBias_args_handle(struct vn_command_vkCmdSetDepthBias *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->depthBiasConstantFactor */
    /* skip args->depthBiasClamp */
    /* skip args->depthBiasSlopeFactor */
}

static inline void vn_encode_vkCmdSetDepthBias_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetDepthBias *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetDepthBias_EXT});

    /* skip args->commandBuffer */
    /* skip args->depthBiasConstantFactor */
    /* skip args->depthBiasClamp */
    /* skip args->depthBiasSlopeFactor */
}

static inline void vn_decode_vkCmdSetBlendConstants_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetBlendConstants *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    {
        const size_t array_size = vn_decode_array_size(dec, 4);
        vn_decode_float_array(dec, (float *)args->blendConstants, array_size);
    }
}

static inline void vn_replace_vkCmdSetBlendConstants_args_handle(struct vn_command_vkCmdSetBlendConstants *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->blendConstants */
}

static inline void vn_encode_vkCmdSetBlendConstants_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetBlendConstants *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetBlendConstants_EXT});

    /* skip args->commandBuffer */
    /* skip args->blendConstants */
}

static inline void vn_decode_vkCmdSetDepthBounds_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetDepthBounds *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_float(dec, &args->minDepthBounds);
    vn_decode_float(dec, &args->maxDepthBounds);
}

static inline void vn_replace_vkCmdSetDepthBounds_args_handle(struct vn_command_vkCmdSetDepthBounds *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->minDepthBounds */
    /* skip args->maxDepthBounds */
}

static inline void vn_encode_vkCmdSetDepthBounds_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetDepthBounds *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetDepthBounds_EXT});

    /* skip args->commandBuffer */
    /* skip args->minDepthBounds */
    /* skip args->maxDepthBounds */
}

static inline void vn_decode_vkCmdSetStencilCompareMask_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetStencilCompareMask *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkFlags(dec, &args->faceMask);
    vn_decode_uint32_t(dec, &args->compareMask);
}

static inline void vn_replace_vkCmdSetStencilCompareMask_args_handle(struct vn_command_vkCmdSetStencilCompareMask *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->faceMask */
    /* skip args->compareMask */
}

static inline void vn_encode_vkCmdSetStencilCompareMask_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetStencilCompareMask *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetStencilCompareMask_EXT});

    /* skip args->commandBuffer */
    /* skip args->faceMask */
    /* skip args->compareMask */
}

static inline void vn_decode_vkCmdSetStencilWriteMask_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetStencilWriteMask *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkFlags(dec, &args->faceMask);
    vn_decode_uint32_t(dec, &args->writeMask);
}

static inline void vn_replace_vkCmdSetStencilWriteMask_args_handle(struct vn_command_vkCmdSetStencilWriteMask *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->faceMask */
    /* skip args->writeMask */
}

static inline void vn_encode_vkCmdSetStencilWriteMask_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetStencilWriteMask *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetStencilWriteMask_EXT});

    /* skip args->commandBuffer */
    /* skip args->faceMask */
    /* skip args->writeMask */
}

static inline void vn_decode_vkCmdSetStencilReference_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetStencilReference *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkFlags(dec, &args->faceMask);
    vn_decode_uint32_t(dec, &args->reference);
}

static inline void vn_replace_vkCmdSetStencilReference_args_handle(struct vn_command_vkCmdSetStencilReference *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->faceMask */
    /* skip args->reference */
}

static inline void vn_encode_vkCmdSetStencilReference_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetStencilReference *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetStencilReference_EXT});

    /* skip args->commandBuffer */
    /* skip args->faceMask */
    /* skip args->reference */
}

static inline void vn_decode_vkCmdBindDescriptorSets_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBindDescriptorSets *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkPipelineBindPoint(dec, &args->pipelineBindPoint);
    vn_decode_VkPipelineLayout_lookup(dec, &args->layout);
    vn_decode_uint32_t(dec, &args->firstSet);
    vn_decode_uint32_t(dec, &args->descriptorSetCount);
    if (vn_peek_array_size(dec)) {
        args->pDescriptorSets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorSets) * args->descriptorSetCount);
        if (!args->pDescriptorSets) return;
        vn_decode_array_size(dec, args->descriptorSetCount);
        for (uint32_t i = 0; i < args->descriptorSetCount; i++)
            vn_decode_VkDescriptorSet_lookup(dec, &((VkDescriptorSet *)args->pDescriptorSets)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pDescriptorSets = NULL;
    }
    vn_decode_uint32_t(dec, &args->dynamicOffsetCount);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->dynamicOffsetCount);
        args->pDynamicOffsets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDynamicOffsets) * array_size);
        if (!args->pDynamicOffsets) return;
        vn_decode_uint32_t_array(dec, (uint32_t *)args->pDynamicOffsets, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pDynamicOffsets = NULL;
    }
}

static inline void vn_replace_vkCmdBindDescriptorSets_args_handle(struct vn_command_vkCmdBindDescriptorSets *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->pipelineBindPoint */
    vn_replace_VkPipelineLayout_handle(&args->layout);
    /* skip args->firstSet */
    /* skip args->descriptorSetCount */
    if (args->pDescriptorSets) {
       for (uint32_t i = 0; i < args->descriptorSetCount; i++)
            vn_replace_VkDescriptorSet_handle(&((VkDescriptorSet *)args->pDescriptorSets)[i]);
    }
    /* skip args->dynamicOffsetCount */
    /* skip args->pDynamicOffsets */
}

static inline void vn_encode_vkCmdBindDescriptorSets_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBindDescriptorSets *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBindDescriptorSets_EXT});

    /* skip args->commandBuffer */
    /* skip args->pipelineBindPoint */
    /* skip args->layout */
    /* skip args->firstSet */
    /* skip args->descriptorSetCount */
    /* skip args->pDescriptorSets */
    /* skip args->dynamicOffsetCount */
    /* skip args->pDynamicOffsets */
}

static inline void vn_decode_vkCmdBindIndexBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBindIndexBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    vn_decode_VkDeviceSize(dec, &args->offset);
    vn_decode_VkIndexType(dec, &args->indexType);
}

static inline void vn_replace_vkCmdBindIndexBuffer_args_handle(struct vn_command_vkCmdBindIndexBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->offset */
    /* skip args->indexType */
}

static inline void vn_encode_vkCmdBindIndexBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBindIndexBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBindIndexBuffer_EXT});

    /* skip args->commandBuffer */
    /* skip args->buffer */
    /* skip args->offset */
    /* skip args->indexType */
}

static inline void vn_decode_vkCmdBindVertexBuffers_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBindVertexBuffers *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->firstBinding);
    vn_decode_uint32_t(dec, &args->bindingCount);
    if (vn_peek_array_size(dec)) {
        args->pBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBuffers) * args->bindingCount);
        if (!args->pBuffers) return;
        vn_decode_array_size(dec, args->bindingCount);
        for (uint32_t i = 0; i < args->bindingCount; i++)
            vn_decode_VkBuffer_lookup(dec, &((VkBuffer *)args->pBuffers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pBuffers = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->bindingCount);
        args->pOffsets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pOffsets) * array_size);
        if (!args->pOffsets) return;
        vn_decode_VkDeviceSize_array(dec, (VkDeviceSize *)args->pOffsets, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pOffsets = NULL;
    }
}

static inline void vn_replace_vkCmdBindVertexBuffers_args_handle(struct vn_command_vkCmdBindVertexBuffers *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->firstBinding */
    /* skip args->bindingCount */
    if (args->pBuffers) {
       for (uint32_t i = 0; i < args->bindingCount; i++)
            vn_replace_VkBuffer_handle(&((VkBuffer *)args->pBuffers)[i]);
    }
    /* skip args->pOffsets */
}

static inline void vn_encode_vkCmdBindVertexBuffers_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBindVertexBuffers *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBindVertexBuffers_EXT});

    /* skip args->commandBuffer */
    /* skip args->firstBinding */
    /* skip args->bindingCount */
    /* skip args->pBuffers */
    /* skip args->pOffsets */
}

static inline void vn_decode_vkCmdDraw_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDraw *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->vertexCount);
    vn_decode_uint32_t(dec, &args->instanceCount);
    vn_decode_uint32_t(dec, &args->firstVertex);
    vn_decode_uint32_t(dec, &args->firstInstance);
}

static inline void vn_replace_vkCmdDraw_args_handle(struct vn_command_vkCmdDraw *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->vertexCount */
    /* skip args->instanceCount */
    /* skip args->firstVertex */
    /* skip args->firstInstance */
}

static inline void vn_encode_vkCmdDraw_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDraw *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDraw_EXT});

    /* skip args->commandBuffer */
    /* skip args->vertexCount */
    /* skip args->instanceCount */
    /* skip args->firstVertex */
    /* skip args->firstInstance */
}

static inline void vn_decode_vkCmdDrawIndexed_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDrawIndexed *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->indexCount);
    vn_decode_uint32_t(dec, &args->instanceCount);
    vn_decode_uint32_t(dec, &args->firstIndex);
    vn_decode_int32_t(dec, &args->vertexOffset);
    vn_decode_uint32_t(dec, &args->firstInstance);
}

static inline void vn_replace_vkCmdDrawIndexed_args_handle(struct vn_command_vkCmdDrawIndexed *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->indexCount */
    /* skip args->instanceCount */
    /* skip args->firstIndex */
    /* skip args->vertexOffset */
    /* skip args->firstInstance */
}

static inline void vn_encode_vkCmdDrawIndexed_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDrawIndexed *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDrawIndexed_EXT});

    /* skip args->commandBuffer */
    /* skip args->indexCount */
    /* skip args->instanceCount */
    /* skip args->firstIndex */
    /* skip args->vertexOffset */
    /* skip args->firstInstance */
}

static inline void vn_decode_vkCmdDrawIndirect_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDrawIndirect *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    vn_decode_VkDeviceSize(dec, &args->offset);
    vn_decode_uint32_t(dec, &args->drawCount);
    vn_decode_uint32_t(dec, &args->stride);
}

static inline void vn_replace_vkCmdDrawIndirect_args_handle(struct vn_command_vkCmdDrawIndirect *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->offset */
    /* skip args->drawCount */
    /* skip args->stride */
}

static inline void vn_encode_vkCmdDrawIndirect_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDrawIndirect *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDrawIndirect_EXT});

    /* skip args->commandBuffer */
    /* skip args->buffer */
    /* skip args->offset */
    /* skip args->drawCount */
    /* skip args->stride */
}

static inline void vn_decode_vkCmdDrawIndexedIndirect_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDrawIndexedIndirect *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    vn_decode_VkDeviceSize(dec, &args->offset);
    vn_decode_uint32_t(dec, &args->drawCount);
    vn_decode_uint32_t(dec, &args->stride);
}

static inline void vn_replace_vkCmdDrawIndexedIndirect_args_handle(struct vn_command_vkCmdDrawIndexedIndirect *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->offset */
    /* skip args->drawCount */
    /* skip args->stride */
}

static inline void vn_encode_vkCmdDrawIndexedIndirect_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDrawIndexedIndirect *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDrawIndexedIndirect_EXT});

    /* skip args->commandBuffer */
    /* skip args->buffer */
    /* skip args->offset */
    /* skip args->drawCount */
    /* skip args->stride */
}

static inline void vn_decode_vkCmdDispatch_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDispatch *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->groupCountX);
    vn_decode_uint32_t(dec, &args->groupCountY);
    vn_decode_uint32_t(dec, &args->groupCountZ);
}

static inline void vn_replace_vkCmdDispatch_args_handle(struct vn_command_vkCmdDispatch *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->groupCountX */
    /* skip args->groupCountY */
    /* skip args->groupCountZ */
}

static inline void vn_encode_vkCmdDispatch_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDispatch *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDispatch_EXT});

    /* skip args->commandBuffer */
    /* skip args->groupCountX */
    /* skip args->groupCountY */
    /* skip args->groupCountZ */
}

static inline void vn_decode_vkCmdDispatchIndirect_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDispatchIndirect *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    vn_decode_VkDeviceSize(dec, &args->offset);
}

static inline void vn_replace_vkCmdDispatchIndirect_args_handle(struct vn_command_vkCmdDispatchIndirect *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->offset */
}

static inline void vn_encode_vkCmdDispatchIndirect_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDispatchIndirect *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDispatchIndirect_EXT});

    /* skip args->commandBuffer */
    /* skip args->buffer */
    /* skip args->offset */
}

static inline void vn_decode_vkCmdCopyBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdCopyBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->srcBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->dstBuffer);
    vn_decode_uint32_t(dec, &args->regionCount);
    if (vn_peek_array_size(dec)) {
        args->pRegions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRegions) * args->regionCount);
        if (!args->pRegions) return;
        vn_decode_array_size(dec, args->regionCount);
        for (uint32_t i = 0; i < args->regionCount; i++)
            vn_decode_VkBufferCopy_temp(dec, &((VkBufferCopy *)args->pRegions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRegions = NULL;
    }
}

static inline void vn_replace_vkCmdCopyBuffer_args_handle(struct vn_command_vkCmdCopyBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->srcBuffer);
    vn_replace_VkBuffer_handle(&args->dstBuffer);
    /* skip args->regionCount */
    if (args->pRegions) {
       for (uint32_t i = 0; i < args->regionCount; i++)
            vn_replace_VkBufferCopy_handle(&((VkBufferCopy *)args->pRegions)[i]);
    }
}

static inline void vn_encode_vkCmdCopyBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdCopyBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdCopyBuffer_EXT});

    /* skip args->commandBuffer */
    /* skip args->srcBuffer */
    /* skip args->dstBuffer */
    /* skip args->regionCount */
    /* skip args->pRegions */
}

static inline void vn_decode_vkCmdCopyImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdCopyImage *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkImage_lookup(dec, &args->srcImage);
    vn_decode_VkImageLayout(dec, &args->srcImageLayout);
    vn_decode_VkImage_lookup(dec, &args->dstImage);
    vn_decode_VkImageLayout(dec, &args->dstImageLayout);
    vn_decode_uint32_t(dec, &args->regionCount);
    if (vn_peek_array_size(dec)) {
        args->pRegions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRegions) * args->regionCount);
        if (!args->pRegions) return;
        vn_decode_array_size(dec, args->regionCount);
        for (uint32_t i = 0; i < args->regionCount; i++)
            vn_decode_VkImageCopy_temp(dec, &((VkImageCopy *)args->pRegions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRegions = NULL;
    }
}

static inline void vn_replace_vkCmdCopyImage_args_handle(struct vn_command_vkCmdCopyImage *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkImage_handle(&args->srcImage);
    /* skip args->srcImageLayout */
    vn_replace_VkImage_handle(&args->dstImage);
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    if (args->pRegions) {
       for (uint32_t i = 0; i < args->regionCount; i++)
            vn_replace_VkImageCopy_handle(&((VkImageCopy *)args->pRegions)[i]);
    }
}

static inline void vn_encode_vkCmdCopyImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdCopyImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdCopyImage_EXT});

    /* skip args->commandBuffer */
    /* skip args->srcImage */
    /* skip args->srcImageLayout */
    /* skip args->dstImage */
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    /* skip args->pRegions */
}

static inline void vn_decode_vkCmdBlitImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBlitImage *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkImage_lookup(dec, &args->srcImage);
    vn_decode_VkImageLayout(dec, &args->srcImageLayout);
    vn_decode_VkImage_lookup(dec, &args->dstImage);
    vn_decode_VkImageLayout(dec, &args->dstImageLayout);
    vn_decode_uint32_t(dec, &args->regionCount);
    if (vn_peek_array_size(dec)) {
        args->pRegions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRegions) * args->regionCount);
        if (!args->pRegions) return;
        vn_decode_array_size(dec, args->regionCount);
        for (uint32_t i = 0; i < args->regionCount; i++)
            vn_decode_VkImageBlit_temp(dec, &((VkImageBlit *)args->pRegions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRegions = NULL;
    }
    vn_decode_VkFilter(dec, &args->filter);
}

static inline void vn_replace_vkCmdBlitImage_args_handle(struct vn_command_vkCmdBlitImage *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkImage_handle(&args->srcImage);
    /* skip args->srcImageLayout */
    vn_replace_VkImage_handle(&args->dstImage);
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    if (args->pRegions) {
       for (uint32_t i = 0; i < args->regionCount; i++)
            vn_replace_VkImageBlit_handle(&((VkImageBlit *)args->pRegions)[i]);
    }
    /* skip args->filter */
}

static inline void vn_encode_vkCmdBlitImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBlitImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBlitImage_EXT});

    /* skip args->commandBuffer */
    /* skip args->srcImage */
    /* skip args->srcImageLayout */
    /* skip args->dstImage */
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    /* skip args->pRegions */
    /* skip args->filter */
}

static inline void vn_decode_vkCmdCopyBufferToImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdCopyBufferToImage *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->srcBuffer);
    vn_decode_VkImage_lookup(dec, &args->dstImage);
    vn_decode_VkImageLayout(dec, &args->dstImageLayout);
    vn_decode_uint32_t(dec, &args->regionCount);
    if (vn_peek_array_size(dec)) {
        args->pRegions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRegions) * args->regionCount);
        if (!args->pRegions) return;
        vn_decode_array_size(dec, args->regionCount);
        for (uint32_t i = 0; i < args->regionCount; i++)
            vn_decode_VkBufferImageCopy_temp(dec, &((VkBufferImageCopy *)args->pRegions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRegions = NULL;
    }
}

static inline void vn_replace_vkCmdCopyBufferToImage_args_handle(struct vn_command_vkCmdCopyBufferToImage *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->srcBuffer);
    vn_replace_VkImage_handle(&args->dstImage);
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    if (args->pRegions) {
       for (uint32_t i = 0; i < args->regionCount; i++)
            vn_replace_VkBufferImageCopy_handle(&((VkBufferImageCopy *)args->pRegions)[i]);
    }
}

static inline void vn_encode_vkCmdCopyBufferToImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdCopyBufferToImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdCopyBufferToImage_EXT});

    /* skip args->commandBuffer */
    /* skip args->srcBuffer */
    /* skip args->dstImage */
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    /* skip args->pRegions */
}

static inline void vn_decode_vkCmdCopyImageToBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdCopyImageToBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkImage_lookup(dec, &args->srcImage);
    vn_decode_VkImageLayout(dec, &args->srcImageLayout);
    vn_decode_VkBuffer_lookup(dec, &args->dstBuffer);
    vn_decode_uint32_t(dec, &args->regionCount);
    if (vn_peek_array_size(dec)) {
        args->pRegions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRegions) * args->regionCount);
        if (!args->pRegions) return;
        vn_decode_array_size(dec, args->regionCount);
        for (uint32_t i = 0; i < args->regionCount; i++)
            vn_decode_VkBufferImageCopy_temp(dec, &((VkBufferImageCopy *)args->pRegions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRegions = NULL;
    }
}

static inline void vn_replace_vkCmdCopyImageToBuffer_args_handle(struct vn_command_vkCmdCopyImageToBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkImage_handle(&args->srcImage);
    /* skip args->srcImageLayout */
    vn_replace_VkBuffer_handle(&args->dstBuffer);
    /* skip args->regionCount */
    if (args->pRegions) {
       for (uint32_t i = 0; i < args->regionCount; i++)
            vn_replace_VkBufferImageCopy_handle(&((VkBufferImageCopy *)args->pRegions)[i]);
    }
}

static inline void vn_encode_vkCmdCopyImageToBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdCopyImageToBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdCopyImageToBuffer_EXT});

    /* skip args->commandBuffer */
    /* skip args->srcImage */
    /* skip args->srcImageLayout */
    /* skip args->dstBuffer */
    /* skip args->regionCount */
    /* skip args->pRegions */
}

static inline void vn_decode_vkCmdUpdateBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdUpdateBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->dstBuffer);
    vn_decode_VkDeviceSize(dec, &args->dstOffset);
    vn_decode_VkDeviceSize(dec, &args->dataSize);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->dataSize);
        args->pData = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!args->pData) return;
        vn_decode_blob_array(dec, (void *)args->pData, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pData = NULL;
    }
}

static inline void vn_replace_vkCmdUpdateBuffer_args_handle(struct vn_command_vkCmdUpdateBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->dstBuffer);
    /* skip args->dstOffset */
    /* skip args->dataSize */
    /* skip args->pData */
}

static inline void vn_encode_vkCmdUpdateBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdUpdateBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdUpdateBuffer_EXT});

    /* skip args->commandBuffer */
    /* skip args->dstBuffer */
    /* skip args->dstOffset */
    /* skip args->dataSize */
    /* skip args->pData */
}

static inline void vn_decode_vkCmdFillBuffer_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdFillBuffer *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->dstBuffer);
    vn_decode_VkDeviceSize(dec, &args->dstOffset);
    vn_decode_VkDeviceSize(dec, &args->size);
    vn_decode_uint32_t(dec, &args->data);
}

static inline void vn_replace_vkCmdFillBuffer_args_handle(struct vn_command_vkCmdFillBuffer *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->dstBuffer);
    /* skip args->dstOffset */
    /* skip args->size */
    /* skip args->data */
}

static inline void vn_encode_vkCmdFillBuffer_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdFillBuffer *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdFillBuffer_EXT});

    /* skip args->commandBuffer */
    /* skip args->dstBuffer */
    /* skip args->dstOffset */
    /* skip args->size */
    /* skip args->data */
}

static inline void vn_decode_vkCmdClearColorImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdClearColorImage *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkImage_lookup(dec, &args->image);
    vn_decode_VkImageLayout(dec, &args->imageLayout);
    if (vn_decode_simple_pointer(dec)) {
        args->pColor = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pColor));
        if (!args->pColor) return;
        vn_decode_VkClearColorValue_temp(dec, (VkClearColorValue *)args->pColor);
    } else {
        args->pColor = NULL;
    }
    vn_decode_uint32_t(dec, &args->rangeCount);
    if (vn_peek_array_size(dec)) {
        args->pRanges = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRanges) * args->rangeCount);
        if (!args->pRanges) return;
        vn_decode_array_size(dec, args->rangeCount);
        for (uint32_t i = 0; i < args->rangeCount; i++)
            vn_decode_VkImageSubresourceRange_temp(dec, &((VkImageSubresourceRange *)args->pRanges)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRanges = NULL;
    }
}

static inline void vn_replace_vkCmdClearColorImage_args_handle(struct vn_command_vkCmdClearColorImage *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkImage_handle(&args->image);
    /* skip args->imageLayout */
    /* skip args->pColor */
    /* skip args->rangeCount */
    if (args->pRanges) {
       for (uint32_t i = 0; i < args->rangeCount; i++)
            vn_replace_VkImageSubresourceRange_handle(&((VkImageSubresourceRange *)args->pRanges)[i]);
    }
}

static inline void vn_encode_vkCmdClearColorImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdClearColorImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdClearColorImage_EXT});

    /* skip args->commandBuffer */
    /* skip args->image */
    /* skip args->imageLayout */
    /* skip args->pColor */
    /* skip args->rangeCount */
    /* skip args->pRanges */
}

static inline void vn_decode_vkCmdClearDepthStencilImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdClearDepthStencilImage *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkImage_lookup(dec, &args->image);
    vn_decode_VkImageLayout(dec, &args->imageLayout);
    if (vn_decode_simple_pointer(dec)) {
        args->pDepthStencil = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDepthStencil));
        if (!args->pDepthStencil) return;
        vn_decode_VkClearDepthStencilValue_temp(dec, (VkClearDepthStencilValue *)args->pDepthStencil);
    } else {
        args->pDepthStencil = NULL;
    }
    vn_decode_uint32_t(dec, &args->rangeCount);
    if (vn_peek_array_size(dec)) {
        args->pRanges = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRanges) * args->rangeCount);
        if (!args->pRanges) return;
        vn_decode_array_size(dec, args->rangeCount);
        for (uint32_t i = 0; i < args->rangeCount; i++)
            vn_decode_VkImageSubresourceRange_temp(dec, &((VkImageSubresourceRange *)args->pRanges)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRanges = NULL;
    }
}

static inline void vn_replace_vkCmdClearDepthStencilImage_args_handle(struct vn_command_vkCmdClearDepthStencilImage *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkImage_handle(&args->image);
    /* skip args->imageLayout */
    if (args->pDepthStencil)
        vn_replace_VkClearDepthStencilValue_handle((VkClearDepthStencilValue *)args->pDepthStencil);
    /* skip args->rangeCount */
    if (args->pRanges) {
       for (uint32_t i = 0; i < args->rangeCount; i++)
            vn_replace_VkImageSubresourceRange_handle(&((VkImageSubresourceRange *)args->pRanges)[i]);
    }
}

static inline void vn_encode_vkCmdClearDepthStencilImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdClearDepthStencilImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdClearDepthStencilImage_EXT});

    /* skip args->commandBuffer */
    /* skip args->image */
    /* skip args->imageLayout */
    /* skip args->pDepthStencil */
    /* skip args->rangeCount */
    /* skip args->pRanges */
}

static inline void vn_decode_vkCmdClearAttachments_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdClearAttachments *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->attachmentCount);
    if (vn_peek_array_size(dec)) {
        args->pAttachments = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pAttachments) * args->attachmentCount);
        if (!args->pAttachments) return;
        vn_decode_array_size(dec, args->attachmentCount);
        for (uint32_t i = 0; i < args->attachmentCount; i++)
            vn_decode_VkClearAttachment_temp(dec, &((VkClearAttachment *)args->pAttachments)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pAttachments = NULL;
    }
    vn_decode_uint32_t(dec, &args->rectCount);
    if (vn_peek_array_size(dec)) {
        args->pRects = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRects) * args->rectCount);
        if (!args->pRects) return;
        vn_decode_array_size(dec, args->rectCount);
        for (uint32_t i = 0; i < args->rectCount; i++)
            vn_decode_VkClearRect_temp(dec, &((VkClearRect *)args->pRects)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRects = NULL;
    }
}

static inline void vn_replace_vkCmdClearAttachments_args_handle(struct vn_command_vkCmdClearAttachments *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->attachmentCount */
    if (args->pAttachments) {
       for (uint32_t i = 0; i < args->attachmentCount; i++)
            vn_replace_VkClearAttachment_handle(&((VkClearAttachment *)args->pAttachments)[i]);
    }
    /* skip args->rectCount */
    if (args->pRects) {
       for (uint32_t i = 0; i < args->rectCount; i++)
            vn_replace_VkClearRect_handle(&((VkClearRect *)args->pRects)[i]);
    }
}

static inline void vn_encode_vkCmdClearAttachments_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdClearAttachments *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdClearAttachments_EXT});

    /* skip args->commandBuffer */
    /* skip args->attachmentCount */
    /* skip args->pAttachments */
    /* skip args->rectCount */
    /* skip args->pRects */
}

static inline void vn_decode_vkCmdResolveImage_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdResolveImage *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkImage_lookup(dec, &args->srcImage);
    vn_decode_VkImageLayout(dec, &args->srcImageLayout);
    vn_decode_VkImage_lookup(dec, &args->dstImage);
    vn_decode_VkImageLayout(dec, &args->dstImageLayout);
    vn_decode_uint32_t(dec, &args->regionCount);
    if (vn_peek_array_size(dec)) {
        args->pRegions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRegions) * args->regionCount);
        if (!args->pRegions) return;
        vn_decode_array_size(dec, args->regionCount);
        for (uint32_t i = 0; i < args->regionCount; i++)
            vn_decode_VkImageResolve_temp(dec, &((VkImageResolve *)args->pRegions)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pRegions = NULL;
    }
}

static inline void vn_replace_vkCmdResolveImage_args_handle(struct vn_command_vkCmdResolveImage *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkImage_handle(&args->srcImage);
    /* skip args->srcImageLayout */
    vn_replace_VkImage_handle(&args->dstImage);
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    if (args->pRegions) {
       for (uint32_t i = 0; i < args->regionCount; i++)
            vn_replace_VkImageResolve_handle(&((VkImageResolve *)args->pRegions)[i]);
    }
}

static inline void vn_encode_vkCmdResolveImage_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdResolveImage *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdResolveImage_EXT});

    /* skip args->commandBuffer */
    /* skip args->srcImage */
    /* skip args->srcImageLayout */
    /* skip args->dstImage */
    /* skip args->dstImageLayout */
    /* skip args->regionCount */
    /* skip args->pRegions */
}

static inline void vn_decode_vkCmdSetEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetEvent *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkEvent_lookup(dec, &args->event);
    vn_decode_VkFlags(dec, &args->stageMask);
}

static inline void vn_replace_vkCmdSetEvent_args_handle(struct vn_command_vkCmdSetEvent *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkEvent_handle(&args->event);
    /* skip args->stageMask */
}

static inline void vn_encode_vkCmdSetEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetEvent_EXT});

    /* skip args->commandBuffer */
    /* skip args->event */
    /* skip args->stageMask */
}

static inline void vn_decode_vkCmdResetEvent_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdResetEvent *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkEvent_lookup(dec, &args->event);
    vn_decode_VkFlags(dec, &args->stageMask);
}

static inline void vn_replace_vkCmdResetEvent_args_handle(struct vn_command_vkCmdResetEvent *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkEvent_handle(&args->event);
    /* skip args->stageMask */
}

static inline void vn_encode_vkCmdResetEvent_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdResetEvent *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdResetEvent_EXT});

    /* skip args->commandBuffer */
    /* skip args->event */
    /* skip args->stageMask */
}

static inline void vn_decode_vkCmdWaitEvents_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdWaitEvents *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->eventCount);
    if (vn_peek_array_size(dec)) {
        args->pEvents = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pEvents) * args->eventCount);
        if (!args->pEvents) return;
        vn_decode_array_size(dec, args->eventCount);
        for (uint32_t i = 0; i < args->eventCount; i++)
            vn_decode_VkEvent_lookup(dec, &((VkEvent *)args->pEvents)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pEvents = NULL;
    }
    vn_decode_VkFlags(dec, &args->srcStageMask);
    vn_decode_VkFlags(dec, &args->dstStageMask);
    vn_decode_uint32_t(dec, &args->memoryBarrierCount);
    if (vn_peek_array_size(dec)) {
        args->pMemoryBarriers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryBarriers) * args->memoryBarrierCount);
        if (!args->pMemoryBarriers) return;
        vn_decode_array_size(dec, args->memoryBarrierCount);
        for (uint32_t i = 0; i < args->memoryBarrierCount; i++)
            vn_decode_VkMemoryBarrier_temp(dec, &((VkMemoryBarrier *)args->pMemoryBarriers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pMemoryBarriers = NULL;
    }
    vn_decode_uint32_t(dec, &args->bufferMemoryBarrierCount);
    if (vn_peek_array_size(dec)) {
        args->pBufferMemoryBarriers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBufferMemoryBarriers) * args->bufferMemoryBarrierCount);
        if (!args->pBufferMemoryBarriers) return;
        vn_decode_array_size(dec, args->bufferMemoryBarrierCount);
        for (uint32_t i = 0; i < args->bufferMemoryBarrierCount; i++)
            vn_decode_VkBufferMemoryBarrier_temp(dec, &((VkBufferMemoryBarrier *)args->pBufferMemoryBarriers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pBufferMemoryBarriers = NULL;
    }
    vn_decode_uint32_t(dec, &args->imageMemoryBarrierCount);
    if (vn_peek_array_size(dec)) {
        args->pImageMemoryBarriers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pImageMemoryBarriers) * args->imageMemoryBarrierCount);
        if (!args->pImageMemoryBarriers) return;
        vn_decode_array_size(dec, args->imageMemoryBarrierCount);
        for (uint32_t i = 0; i < args->imageMemoryBarrierCount; i++)
            vn_decode_VkImageMemoryBarrier_temp(dec, &((VkImageMemoryBarrier *)args->pImageMemoryBarriers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pImageMemoryBarriers = NULL;
    }
}

static inline void vn_replace_vkCmdWaitEvents_args_handle(struct vn_command_vkCmdWaitEvents *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->eventCount */
    if (args->pEvents) {
       for (uint32_t i = 0; i < args->eventCount; i++)
            vn_replace_VkEvent_handle(&((VkEvent *)args->pEvents)[i]);
    }
    /* skip args->srcStageMask */
    /* skip args->dstStageMask */
    /* skip args->memoryBarrierCount */
    if (args->pMemoryBarriers) {
       for (uint32_t i = 0; i < args->memoryBarrierCount; i++)
            vn_replace_VkMemoryBarrier_handle(&((VkMemoryBarrier *)args->pMemoryBarriers)[i]);
    }
    /* skip args->bufferMemoryBarrierCount */
    if (args->pBufferMemoryBarriers) {
       for (uint32_t i = 0; i < args->bufferMemoryBarrierCount; i++)
            vn_replace_VkBufferMemoryBarrier_handle(&((VkBufferMemoryBarrier *)args->pBufferMemoryBarriers)[i]);
    }
    /* skip args->imageMemoryBarrierCount */
    if (args->pImageMemoryBarriers) {
       for (uint32_t i = 0; i < args->imageMemoryBarrierCount; i++)
            vn_replace_VkImageMemoryBarrier_handle(&((VkImageMemoryBarrier *)args->pImageMemoryBarriers)[i]);
    }
}

static inline void vn_encode_vkCmdWaitEvents_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdWaitEvents *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdWaitEvents_EXT});

    /* skip args->commandBuffer */
    /* skip args->eventCount */
    /* skip args->pEvents */
    /* skip args->srcStageMask */
    /* skip args->dstStageMask */
    /* skip args->memoryBarrierCount */
    /* skip args->pMemoryBarriers */
    /* skip args->bufferMemoryBarrierCount */
    /* skip args->pBufferMemoryBarriers */
    /* skip args->imageMemoryBarrierCount */
    /* skip args->pImageMemoryBarriers */
}

static inline void vn_decode_vkCmdPipelineBarrier_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdPipelineBarrier *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkFlags(dec, &args->srcStageMask);
    vn_decode_VkFlags(dec, &args->dstStageMask);
    vn_decode_VkFlags(dec, &args->dependencyFlags);
    vn_decode_uint32_t(dec, &args->memoryBarrierCount);
    if (vn_peek_array_size(dec)) {
        args->pMemoryBarriers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryBarriers) * args->memoryBarrierCount);
        if (!args->pMemoryBarriers) return;
        vn_decode_array_size(dec, args->memoryBarrierCount);
        for (uint32_t i = 0; i < args->memoryBarrierCount; i++)
            vn_decode_VkMemoryBarrier_temp(dec, &((VkMemoryBarrier *)args->pMemoryBarriers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pMemoryBarriers = NULL;
    }
    vn_decode_uint32_t(dec, &args->bufferMemoryBarrierCount);
    if (vn_peek_array_size(dec)) {
        args->pBufferMemoryBarriers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBufferMemoryBarriers) * args->bufferMemoryBarrierCount);
        if (!args->pBufferMemoryBarriers) return;
        vn_decode_array_size(dec, args->bufferMemoryBarrierCount);
        for (uint32_t i = 0; i < args->bufferMemoryBarrierCount; i++)
            vn_decode_VkBufferMemoryBarrier_temp(dec, &((VkBufferMemoryBarrier *)args->pBufferMemoryBarriers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pBufferMemoryBarriers = NULL;
    }
    vn_decode_uint32_t(dec, &args->imageMemoryBarrierCount);
    if (vn_peek_array_size(dec)) {
        args->pImageMemoryBarriers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pImageMemoryBarriers) * args->imageMemoryBarrierCount);
        if (!args->pImageMemoryBarriers) return;
        vn_decode_array_size(dec, args->imageMemoryBarrierCount);
        for (uint32_t i = 0; i < args->imageMemoryBarrierCount; i++)
            vn_decode_VkImageMemoryBarrier_temp(dec, &((VkImageMemoryBarrier *)args->pImageMemoryBarriers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pImageMemoryBarriers = NULL;
    }
}

static inline void vn_replace_vkCmdPipelineBarrier_args_handle(struct vn_command_vkCmdPipelineBarrier *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->srcStageMask */
    /* skip args->dstStageMask */
    /* skip args->dependencyFlags */
    /* skip args->memoryBarrierCount */
    if (args->pMemoryBarriers) {
       for (uint32_t i = 0; i < args->memoryBarrierCount; i++)
            vn_replace_VkMemoryBarrier_handle(&((VkMemoryBarrier *)args->pMemoryBarriers)[i]);
    }
    /* skip args->bufferMemoryBarrierCount */
    if (args->pBufferMemoryBarriers) {
       for (uint32_t i = 0; i < args->bufferMemoryBarrierCount; i++)
            vn_replace_VkBufferMemoryBarrier_handle(&((VkBufferMemoryBarrier *)args->pBufferMemoryBarriers)[i]);
    }
    /* skip args->imageMemoryBarrierCount */
    if (args->pImageMemoryBarriers) {
       for (uint32_t i = 0; i < args->imageMemoryBarrierCount; i++)
            vn_replace_VkImageMemoryBarrier_handle(&((VkImageMemoryBarrier *)args->pImageMemoryBarriers)[i]);
    }
}

static inline void vn_encode_vkCmdPipelineBarrier_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdPipelineBarrier *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdPipelineBarrier_EXT});

    /* skip args->commandBuffer */
    /* skip args->srcStageMask */
    /* skip args->dstStageMask */
    /* skip args->dependencyFlags */
    /* skip args->memoryBarrierCount */
    /* skip args->pMemoryBarriers */
    /* skip args->bufferMemoryBarrierCount */
    /* skip args->pBufferMemoryBarriers */
    /* skip args->imageMemoryBarrierCount */
    /* skip args->pImageMemoryBarriers */
}

static inline void vn_decode_vkCmdBeginQuery_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBeginQuery *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->query);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkCmdBeginQuery_args_handle(struct vn_command_vkCmdBeginQuery *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->query */
    /* skip args->flags */
}

static inline void vn_encode_vkCmdBeginQuery_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBeginQuery *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBeginQuery_EXT});

    /* skip args->commandBuffer */
    /* skip args->queryPool */
    /* skip args->query */
    /* skip args->flags */
}

static inline void vn_decode_vkCmdEndQuery_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdEndQuery *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->query);
}

static inline void vn_replace_vkCmdEndQuery_args_handle(struct vn_command_vkCmdEndQuery *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->query */
}

static inline void vn_encode_vkCmdEndQuery_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdEndQuery *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdEndQuery_EXT});

    /* skip args->commandBuffer */
    /* skip args->queryPool */
    /* skip args->query */
}

static inline void vn_decode_vkCmdResetQueryPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdResetQueryPool *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->firstQuery);
    vn_decode_uint32_t(dec, &args->queryCount);
}

static inline void vn_replace_vkCmdResetQueryPool_args_handle(struct vn_command_vkCmdResetQueryPool *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->firstQuery */
    /* skip args->queryCount */
}

static inline void vn_encode_vkCmdResetQueryPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdResetQueryPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdResetQueryPool_EXT});

    /* skip args->commandBuffer */
    /* skip args->queryPool */
    /* skip args->firstQuery */
    /* skip args->queryCount */
}

static inline void vn_decode_vkCmdWriteTimestamp_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdWriteTimestamp *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkPipelineStageFlagBits(dec, &args->pipelineStage);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->query);
}

static inline void vn_replace_vkCmdWriteTimestamp_args_handle(struct vn_command_vkCmdWriteTimestamp *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->pipelineStage */
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->query */
}

static inline void vn_encode_vkCmdWriteTimestamp_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdWriteTimestamp *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdWriteTimestamp_EXT});

    /* skip args->commandBuffer */
    /* skip args->pipelineStage */
    /* skip args->queryPool */
    /* skip args->query */
}

static inline void vn_decode_vkCmdCopyQueryPoolResults_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdCopyQueryPoolResults *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->firstQuery);
    vn_decode_uint32_t(dec, &args->queryCount);
    vn_decode_VkBuffer_lookup(dec, &args->dstBuffer);
    vn_decode_VkDeviceSize(dec, &args->dstOffset);
    vn_decode_VkDeviceSize(dec, &args->stride);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkCmdCopyQueryPoolResults_args_handle(struct vn_command_vkCmdCopyQueryPoolResults *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->firstQuery */
    /* skip args->queryCount */
    vn_replace_VkBuffer_handle(&args->dstBuffer);
    /* skip args->dstOffset */
    /* skip args->stride */
    /* skip args->flags */
}

static inline void vn_encode_vkCmdCopyQueryPoolResults_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdCopyQueryPoolResults *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdCopyQueryPoolResults_EXT});

    /* skip args->commandBuffer */
    /* skip args->queryPool */
    /* skip args->firstQuery */
    /* skip args->queryCount */
    /* skip args->dstBuffer */
    /* skip args->dstOffset */
    /* skip args->stride */
    /* skip args->flags */
}

static inline void vn_decode_vkCmdPushConstants_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdPushConstants *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkPipelineLayout_lookup(dec, &args->layout);
    vn_decode_VkFlags(dec, &args->stageFlags);
    vn_decode_uint32_t(dec, &args->offset);
    vn_decode_uint32_t(dec, &args->size);
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->size);
        args->pValues = vn_cs_decoder_alloc_temp(dec, array_size);
        if (!args->pValues) return;
        vn_decode_blob_array(dec, (void *)args->pValues, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pValues = NULL;
    }
}

static inline void vn_replace_vkCmdPushConstants_args_handle(struct vn_command_vkCmdPushConstants *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkPipelineLayout_handle(&args->layout);
    /* skip args->stageFlags */
    /* skip args->offset */
    /* skip args->size */
    /* skip args->pValues */
}

static inline void vn_encode_vkCmdPushConstants_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdPushConstants *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdPushConstants_EXT});

    /* skip args->commandBuffer */
    /* skip args->layout */
    /* skip args->stageFlags */
    /* skip args->offset */
    /* skip args->size */
    /* skip args->pValues */
}

static inline void vn_decode_vkCmdBeginRenderPass_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBeginRenderPass *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    if (vn_decode_simple_pointer(dec)) {
        args->pRenderPassBegin = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRenderPassBegin));
        if (!args->pRenderPassBegin) return;
        vn_decode_VkRenderPassBeginInfo_temp(dec, (VkRenderPassBeginInfo *)args->pRenderPassBegin);
    } else {
        args->pRenderPassBegin = NULL;
    }
    vn_decode_VkSubpassContents(dec, &args->contents);
}

static inline void vn_replace_vkCmdBeginRenderPass_args_handle(struct vn_command_vkCmdBeginRenderPass *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    if (args->pRenderPassBegin)
        vn_replace_VkRenderPassBeginInfo_handle((VkRenderPassBeginInfo *)args->pRenderPassBegin);
    /* skip args->contents */
}

static inline void vn_encode_vkCmdBeginRenderPass_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBeginRenderPass *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBeginRenderPass_EXT});

    /* skip args->commandBuffer */
    /* skip args->pRenderPassBegin */
    /* skip args->contents */
}

static inline void vn_decode_vkCmdNextSubpass_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdNextSubpass *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkSubpassContents(dec, &args->contents);
}

static inline void vn_replace_vkCmdNextSubpass_args_handle(struct vn_command_vkCmdNextSubpass *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->contents */
}

static inline void vn_encode_vkCmdNextSubpass_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdNextSubpass *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdNextSubpass_EXT});

    /* skip args->commandBuffer */
    /* skip args->contents */
}

static inline void vn_decode_vkCmdEndRenderPass_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdEndRenderPass *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
}

static inline void vn_replace_vkCmdEndRenderPass_args_handle(struct vn_command_vkCmdEndRenderPass *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
}

static inline void vn_encode_vkCmdEndRenderPass_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdEndRenderPass *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdEndRenderPass_EXT});

    /* skip args->commandBuffer */
}

static inline void vn_decode_vkCmdExecuteCommands_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdExecuteCommands *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->commandBufferCount);
    if (vn_peek_array_size(dec)) {
        args->pCommandBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCommandBuffers) * args->commandBufferCount);
        if (!args->pCommandBuffers) return;
        vn_decode_array_size(dec, args->commandBufferCount);
        for (uint32_t i = 0; i < args->commandBufferCount; i++)
            vn_decode_VkCommandBuffer_lookup(dec, &((VkCommandBuffer *)args->pCommandBuffers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCommandBuffers = NULL;
    }
}

static inline void vn_replace_vkCmdExecuteCommands_args_handle(struct vn_command_vkCmdExecuteCommands *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->commandBufferCount */
    if (args->pCommandBuffers) {
       for (uint32_t i = 0; i < args->commandBufferCount; i++)
            vn_replace_VkCommandBuffer_handle(&((VkCommandBuffer *)args->pCommandBuffers)[i]);
    }
}

static inline void vn_encode_vkCmdExecuteCommands_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdExecuteCommands *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdExecuteCommands_EXT});

    /* skip args->commandBuffer */
    /* skip args->commandBufferCount */
    /* skip args->pCommandBuffers */
}

static inline void vn_decode_vkGetPhysicalDeviceFeatures2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceFeatures2 *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pFeatures = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFeatures));
        if (!args->pFeatures) return;
        vn_decode_VkPhysicalDeviceFeatures2_partial_temp(dec, args->pFeatures);
    } else {
        args->pFeatures = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceFeatures2_args_handle(struct vn_command_vkGetPhysicalDeviceFeatures2 *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pFeatures */
}

static inline void vn_encode_vkGetPhysicalDeviceFeatures2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceFeatures2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceFeatures2_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pFeatures))
        vn_encode_VkPhysicalDeviceFeatures2(enc, args->pFeatures);
}

static inline void vn_decode_vkGetPhysicalDeviceProperties2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceProperties2 *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties));
        if (!args->pProperties) return;
        vn_decode_VkPhysicalDeviceProperties2_partial_temp(dec, args->pProperties);
    } else {
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceProperties2_args_handle(struct vn_command_vkGetPhysicalDeviceProperties2 *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceProperties2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceProperties2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceProperties2_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pProperties))
        vn_encode_VkPhysicalDeviceProperties2(enc, args->pProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceFormatProperties2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceFormatProperties2 *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    vn_decode_VkFormat(dec, &args->format);
    if (vn_decode_simple_pointer(dec)) {
        args->pFormatProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFormatProperties));
        if (!args->pFormatProperties) return;
        vn_decode_VkFormatProperties2_partial_temp(dec, args->pFormatProperties);
    } else {
        args->pFormatProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceFormatProperties2_args_handle(struct vn_command_vkGetPhysicalDeviceFormatProperties2 *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->format */
    /* skip args->pFormatProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceFormatProperties2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceFormatProperties2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceFormatProperties2_EXT});

    /* skip args->physicalDevice */
    /* skip args->format */
    if (vn_encode_simple_pointer(enc, args->pFormatProperties))
        vn_encode_VkFormatProperties2(enc, args->pFormatProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceImageFormatProperties2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceImageFormatProperties2 *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pImageFormatInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pImageFormatInfo));
        if (!args->pImageFormatInfo) return;
        vn_decode_VkPhysicalDeviceImageFormatInfo2_temp(dec, (VkPhysicalDeviceImageFormatInfo2 *)args->pImageFormatInfo);
    } else {
        args->pImageFormatInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pImageFormatProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pImageFormatProperties));
        if (!args->pImageFormatProperties) return;
        vn_decode_VkImageFormatProperties2_partial_temp(dec, args->pImageFormatProperties);
    } else {
        args->pImageFormatProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceImageFormatProperties2_args_handle(struct vn_command_vkGetPhysicalDeviceImageFormatProperties2 *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    if (args->pImageFormatInfo)
        vn_replace_VkPhysicalDeviceImageFormatInfo2_handle((VkPhysicalDeviceImageFormatInfo2 *)args->pImageFormatInfo);
    /* skip args->pImageFormatProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceImageFormatProperties2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceImageFormatProperties2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceImageFormatProperties2_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->physicalDevice */
    /* skip args->pImageFormatInfo */
    if (vn_encode_simple_pointer(enc, args->pImageFormatProperties))
        vn_encode_VkImageFormatProperties2(enc, args->pImageFormatProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceQueueFamilyProperties2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties2 *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pQueueFamilyPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueueFamilyPropertyCount));
        if (!args->pQueueFamilyPropertyCount) return;
        vn_decode_uint32_t(dec, args->pQueueFamilyPropertyCount);
    } else {
        args->pQueueFamilyPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pQueueFamilyProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueueFamilyProperties) * *args->pQueueFamilyPropertyCount);
        if (!args->pQueueFamilyProperties) return;
        vn_decode_array_size(dec, *args->pQueueFamilyPropertyCount);
        for (uint32_t i = 0; i < *args->pQueueFamilyPropertyCount; i++)
            vn_decode_VkQueueFamilyProperties2_partial_temp(dec, &args->pQueueFamilyProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pQueueFamilyProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceQueueFamilyProperties2_args_handle(struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties2 *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pQueueFamilyPropertyCount */
    /* skip args->pQueueFamilyProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceQueueFamilyProperties2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceQueueFamilyProperties2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceQueueFamilyProperties2_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pQueueFamilyPropertyCount))
        vn_encode_uint32_t(enc, args->pQueueFamilyPropertyCount);
    if (args->pQueueFamilyProperties) {
        vn_encode_array_size(enc, *args->pQueueFamilyPropertyCount);
        for (uint32_t i = 0; i < *args->pQueueFamilyPropertyCount; i++)
            vn_encode_VkQueueFamilyProperties2(enc, &args->pQueueFamilyProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkGetPhysicalDeviceMemoryProperties2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceMemoryProperties2 *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pMemoryProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryProperties));
        if (!args->pMemoryProperties) return;
        vn_decode_VkPhysicalDeviceMemoryProperties2_partial_temp(dec, args->pMemoryProperties);
    } else {
        args->pMemoryProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceMemoryProperties2_args_handle(struct vn_command_vkGetPhysicalDeviceMemoryProperties2 *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    /* skip args->pMemoryProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceMemoryProperties2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceMemoryProperties2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceMemoryProperties2_EXT});

    /* skip args->physicalDevice */
    if (vn_encode_simple_pointer(enc, args->pMemoryProperties))
        vn_encode_VkPhysicalDeviceMemoryProperties2(enc, args->pMemoryProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceSparseImageFormatProperties2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties2 *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pFormatInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pFormatInfo));
        if (!args->pFormatInfo) return;
        vn_decode_VkPhysicalDeviceSparseImageFormatInfo2_temp(dec, (VkPhysicalDeviceSparseImageFormatInfo2 *)args->pFormatInfo);
    } else {
        args->pFormatInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pPropertyCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPropertyCount));
        if (!args->pPropertyCount) return;
        vn_decode_uint32_t(dec, args->pPropertyCount);
    } else {
        args->pPropertyCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties) * *args->pPropertyCount);
        if (!args->pProperties) return;
        vn_decode_array_size(dec, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_decode_VkSparseImageFormatProperties2_partial_temp(dec, &args->pProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceSparseImageFormatProperties2_args_handle(struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties2 *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    if (args->pFormatInfo)
        vn_replace_VkPhysicalDeviceSparseImageFormatInfo2_handle((VkPhysicalDeviceSparseImageFormatInfo2 *)args->pFormatInfo);
    /* skip args->pPropertyCount */
    /* skip args->pProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceSparseImageFormatProperties2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceSparseImageFormatProperties2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceSparseImageFormatProperties2_EXT});

    /* skip args->physicalDevice */
    /* skip args->pFormatInfo */
    if (vn_encode_simple_pointer(enc, args->pPropertyCount))
        vn_encode_uint32_t(enc, args->pPropertyCount);
    if (args->pProperties) {
        vn_encode_array_size(enc, *args->pPropertyCount);
        for (uint32_t i = 0; i < *args->pPropertyCount; i++)
            vn_encode_VkSparseImageFormatProperties2(enc, &args->pProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkTrimCommandPool_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkTrimCommandPool *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkCommandPool_lookup(dec, &args->commandPool);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkTrimCommandPool_args_handle(struct vn_command_vkTrimCommandPool *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkCommandPool_handle(&args->commandPool);
    /* skip args->flags */
}

static inline void vn_encode_vkTrimCommandPool_reply(struct vn_cs_encoder *enc, const struct vn_command_vkTrimCommandPool *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkTrimCommandPool_EXT});

    /* skip args->device */
    /* skip args->commandPool */
    /* skip args->flags */
}

static inline void vn_decode_vkGetPhysicalDeviceExternalBufferProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceExternalBufferProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pExternalBufferInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pExternalBufferInfo));
        if (!args->pExternalBufferInfo) return;
        vn_decode_VkPhysicalDeviceExternalBufferInfo_temp(dec, (VkPhysicalDeviceExternalBufferInfo *)args->pExternalBufferInfo);
    } else {
        args->pExternalBufferInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pExternalBufferProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pExternalBufferProperties));
        if (!args->pExternalBufferProperties) return;
        vn_decode_VkExternalBufferProperties_partial_temp(dec, args->pExternalBufferProperties);
    } else {
        args->pExternalBufferProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceExternalBufferProperties_args_handle(struct vn_command_vkGetPhysicalDeviceExternalBufferProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    if (args->pExternalBufferInfo)
        vn_replace_VkPhysicalDeviceExternalBufferInfo_handle((VkPhysicalDeviceExternalBufferInfo *)args->pExternalBufferInfo);
    /* skip args->pExternalBufferProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceExternalBufferProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceExternalBufferProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalBufferProperties_EXT});

    /* skip args->physicalDevice */
    /* skip args->pExternalBufferInfo */
    if (vn_encode_simple_pointer(enc, args->pExternalBufferProperties))
        vn_encode_VkExternalBufferProperties(enc, args->pExternalBufferProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceExternalSemaphoreProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceExternalSemaphoreProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pExternalSemaphoreInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pExternalSemaphoreInfo));
        if (!args->pExternalSemaphoreInfo) return;
        vn_decode_VkPhysicalDeviceExternalSemaphoreInfo_temp(dec, (VkPhysicalDeviceExternalSemaphoreInfo *)args->pExternalSemaphoreInfo);
    } else {
        args->pExternalSemaphoreInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pExternalSemaphoreProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pExternalSemaphoreProperties));
        if (!args->pExternalSemaphoreProperties) return;
        vn_decode_VkExternalSemaphoreProperties_partial_temp(dec, args->pExternalSemaphoreProperties);
    } else {
        args->pExternalSemaphoreProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceExternalSemaphoreProperties_args_handle(struct vn_command_vkGetPhysicalDeviceExternalSemaphoreProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    if (args->pExternalSemaphoreInfo)
        vn_replace_VkPhysicalDeviceExternalSemaphoreInfo_handle((VkPhysicalDeviceExternalSemaphoreInfo *)args->pExternalSemaphoreInfo);
    /* skip args->pExternalSemaphoreProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceExternalSemaphoreProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceExternalSemaphoreProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalSemaphoreProperties_EXT});

    /* skip args->physicalDevice */
    /* skip args->pExternalSemaphoreInfo */
    if (vn_encode_simple_pointer(enc, args->pExternalSemaphoreProperties))
        vn_encode_VkExternalSemaphoreProperties(enc, args->pExternalSemaphoreProperties);
}

static inline void vn_decode_vkGetPhysicalDeviceExternalFenceProperties_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetPhysicalDeviceExternalFenceProperties *args)
{
    vn_decode_VkPhysicalDevice_lookup(dec, &args->physicalDevice);
    if (vn_decode_simple_pointer(dec)) {
        args->pExternalFenceInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pExternalFenceInfo));
        if (!args->pExternalFenceInfo) return;
        vn_decode_VkPhysicalDeviceExternalFenceInfo_temp(dec, (VkPhysicalDeviceExternalFenceInfo *)args->pExternalFenceInfo);
    } else {
        args->pExternalFenceInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pExternalFenceProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pExternalFenceProperties));
        if (!args->pExternalFenceProperties) return;
        vn_decode_VkExternalFenceProperties_partial_temp(dec, args->pExternalFenceProperties);
    } else {
        args->pExternalFenceProperties = NULL;
    }
}

static inline void vn_replace_vkGetPhysicalDeviceExternalFenceProperties_args_handle(struct vn_command_vkGetPhysicalDeviceExternalFenceProperties *args)
{
    vn_replace_VkPhysicalDevice_handle(&args->physicalDevice);
    if (args->pExternalFenceInfo)
        vn_replace_VkPhysicalDeviceExternalFenceInfo_handle((VkPhysicalDeviceExternalFenceInfo *)args->pExternalFenceInfo);
    /* skip args->pExternalFenceProperties */
}

static inline void vn_encode_vkGetPhysicalDeviceExternalFenceProperties_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetPhysicalDeviceExternalFenceProperties *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetPhysicalDeviceExternalFenceProperties_EXT});

    /* skip args->physicalDevice */
    /* skip args->pExternalFenceInfo */
    if (vn_encode_simple_pointer(enc, args->pExternalFenceProperties))
        vn_encode_VkExternalFenceProperties(enc, args->pExternalFenceProperties);
}

static inline void vn_decode_vkEnumeratePhysicalDeviceGroups_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkEnumeratePhysicalDeviceGroups *args)
{
    vn_decode_VkInstance_lookup(dec, &args->instance);
    if (vn_decode_simple_pointer(dec)) {
        args->pPhysicalDeviceGroupCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPhysicalDeviceGroupCount));
        if (!args->pPhysicalDeviceGroupCount) return;
        vn_decode_uint32_t(dec, args->pPhysicalDeviceGroupCount);
    } else {
        args->pPhysicalDeviceGroupCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pPhysicalDeviceGroupProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPhysicalDeviceGroupProperties) * *args->pPhysicalDeviceGroupCount);
        if (!args->pPhysicalDeviceGroupProperties) return;
        vn_decode_array_size(dec, *args->pPhysicalDeviceGroupCount);
        for (uint32_t i = 0; i < *args->pPhysicalDeviceGroupCount; i++)
            vn_decode_VkPhysicalDeviceGroupProperties_partial_temp(dec, &args->pPhysicalDeviceGroupProperties[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pPhysicalDeviceGroupProperties = NULL;
    }
}

static inline void vn_replace_vkEnumeratePhysicalDeviceGroups_args_handle(struct vn_command_vkEnumeratePhysicalDeviceGroups *args)
{
    vn_replace_VkInstance_handle(&args->instance);
    /* skip args->pPhysicalDeviceGroupCount */
    /* skip args->pPhysicalDeviceGroupProperties */
}

static inline void vn_encode_vkEnumeratePhysicalDeviceGroups_reply(struct vn_cs_encoder *enc, const struct vn_command_vkEnumeratePhysicalDeviceGroups *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkEnumeratePhysicalDeviceGroups_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->instance */
    if (vn_encode_simple_pointer(enc, args->pPhysicalDeviceGroupCount))
        vn_encode_uint32_t(enc, args->pPhysicalDeviceGroupCount);
    if (args->pPhysicalDeviceGroupProperties) {
        vn_encode_array_size(enc, *args->pPhysicalDeviceGroupCount);
        for (uint32_t i = 0; i < *args->pPhysicalDeviceGroupCount; i++)
            vn_encode_VkPhysicalDeviceGroupProperties(enc, &args->pPhysicalDeviceGroupProperties[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkGetDeviceGroupPeerMemoryFeatures_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetDeviceGroupPeerMemoryFeatures *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->heapIndex);
    vn_decode_uint32_t(dec, &args->localDeviceIndex);
    vn_decode_uint32_t(dec, &args->remoteDeviceIndex);
    if (vn_decode_simple_pointer(dec)) {
        args->pPeerMemoryFeatures = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pPeerMemoryFeatures));
        if (!args->pPeerMemoryFeatures) return;
    } else {
        args->pPeerMemoryFeatures = NULL;
    }
}

static inline void vn_replace_vkGetDeviceGroupPeerMemoryFeatures_args_handle(struct vn_command_vkGetDeviceGroupPeerMemoryFeatures *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->heapIndex */
    /* skip args->localDeviceIndex */
    /* skip args->remoteDeviceIndex */
    /* skip args->pPeerMemoryFeatures */
}

static inline void vn_encode_vkGetDeviceGroupPeerMemoryFeatures_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetDeviceGroupPeerMemoryFeatures *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetDeviceGroupPeerMemoryFeatures_EXT});

    /* skip args->device */
    /* skip args->heapIndex */
    /* skip args->localDeviceIndex */
    /* skip args->remoteDeviceIndex */
    if (vn_encode_simple_pointer(enc, args->pPeerMemoryFeatures))
        vn_encode_VkFlags(enc, args->pPeerMemoryFeatures);
}

static inline void vn_decode_vkBindBufferMemory2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkBindBufferMemory2 *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->bindInfoCount);
    if (vn_peek_array_size(dec)) {
        args->pBindInfos = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBindInfos) * args->bindInfoCount);
        if (!args->pBindInfos) return;
        vn_decode_array_size(dec, args->bindInfoCount);
        for (uint32_t i = 0; i < args->bindInfoCount; i++)
            vn_decode_VkBindBufferMemoryInfo_temp(dec, &((VkBindBufferMemoryInfo *)args->pBindInfos)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pBindInfos = NULL;
    }
}

static inline void vn_replace_vkBindBufferMemory2_args_handle(struct vn_command_vkBindBufferMemory2 *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->bindInfoCount */
    if (args->pBindInfos) {
       for (uint32_t i = 0; i < args->bindInfoCount; i++)
            vn_replace_VkBindBufferMemoryInfo_handle(&((VkBindBufferMemoryInfo *)args->pBindInfos)[i]);
    }
}

static inline void vn_encode_vkBindBufferMemory2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkBindBufferMemory2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkBindBufferMemory2_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->bindInfoCount */
    /* skip args->pBindInfos */
}

static inline void vn_decode_vkBindImageMemory2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkBindImageMemory2 *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_uint32_t(dec, &args->bindInfoCount);
    if (vn_peek_array_size(dec)) {
        args->pBindInfos = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBindInfos) * args->bindInfoCount);
        if (!args->pBindInfos) return;
        vn_decode_array_size(dec, args->bindInfoCount);
        for (uint32_t i = 0; i < args->bindInfoCount; i++)
            vn_decode_VkBindImageMemoryInfo_temp(dec, &((VkBindImageMemoryInfo *)args->pBindInfos)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pBindInfos = NULL;
    }
}

static inline void vn_replace_vkBindImageMemory2_args_handle(struct vn_command_vkBindImageMemory2 *args)
{
    vn_replace_VkDevice_handle(&args->device);
    /* skip args->bindInfoCount */
    if (args->pBindInfos) {
       for (uint32_t i = 0; i < args->bindInfoCount; i++)
            vn_replace_VkBindImageMemoryInfo_handle(&((VkBindImageMemoryInfo *)args->pBindInfos)[i]);
    }
}

static inline void vn_encode_vkBindImageMemory2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkBindImageMemory2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkBindImageMemory2_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->bindInfoCount */
    /* skip args->pBindInfos */
}

static inline void vn_decode_vkCmdSetDeviceMask_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdSetDeviceMask *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->deviceMask);
}

static inline void vn_replace_vkCmdSetDeviceMask_args_handle(struct vn_command_vkCmdSetDeviceMask *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->deviceMask */
}

static inline void vn_encode_vkCmdSetDeviceMask_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdSetDeviceMask *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdSetDeviceMask_EXT});

    /* skip args->commandBuffer */
    /* skip args->deviceMask */
}

static inline void vn_decode_vkCmdDispatchBase_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDispatchBase *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->baseGroupX);
    vn_decode_uint32_t(dec, &args->baseGroupY);
    vn_decode_uint32_t(dec, &args->baseGroupZ);
    vn_decode_uint32_t(dec, &args->groupCountX);
    vn_decode_uint32_t(dec, &args->groupCountY);
    vn_decode_uint32_t(dec, &args->groupCountZ);
}

static inline void vn_replace_vkCmdDispatchBase_args_handle(struct vn_command_vkCmdDispatchBase *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->baseGroupX */
    /* skip args->baseGroupY */
    /* skip args->baseGroupZ */
    /* skip args->groupCountX */
    /* skip args->groupCountY */
    /* skip args->groupCountZ */
}

static inline void vn_encode_vkCmdDispatchBase_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDispatchBase *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDispatchBase_EXT});

    /* skip args->commandBuffer */
    /* skip args->baseGroupX */
    /* skip args->baseGroupY */
    /* skip args->baseGroupZ */
    /* skip args->groupCountX */
    /* skip args->groupCountY */
    /* skip args->groupCountZ */
}

static inline void vn_decode_vkCreateDescriptorUpdateTemplate_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateDescriptorUpdateTemplate *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDescriptorUpdateTemplateCreateInfo_temp(dec, (VkDescriptorUpdateTemplateCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pDescriptorUpdateTemplate = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDescriptorUpdateTemplate));
        if (!args->pDescriptorUpdateTemplate) return;
        vn_decode_VkDescriptorUpdateTemplate(dec, args->pDescriptorUpdateTemplate);
    } else {
        args->pDescriptorUpdateTemplate = NULL;
    }
}

static inline void vn_replace_vkCreateDescriptorUpdateTemplate_args_handle(struct vn_command_vkCreateDescriptorUpdateTemplate *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkDescriptorUpdateTemplateCreateInfo_handle((VkDescriptorUpdateTemplateCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pDescriptorUpdateTemplate */
}

static inline void vn_encode_vkCreateDescriptorUpdateTemplate_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateDescriptorUpdateTemplate *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateDescriptorUpdateTemplate_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pDescriptorUpdateTemplate))
        vn_encode_VkDescriptorUpdateTemplate(enc, args->pDescriptorUpdateTemplate);
}

static inline void vn_decode_vkDestroyDescriptorUpdateTemplate_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyDescriptorUpdateTemplate *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkDescriptorUpdateTemplate_lookup(dec, &args->descriptorUpdateTemplate);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroyDescriptorUpdateTemplate_args_handle(struct vn_command_vkDestroyDescriptorUpdateTemplate *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkDescriptorUpdateTemplate_handle(&args->descriptorUpdateTemplate);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroyDescriptorUpdateTemplate_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyDescriptorUpdateTemplate *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyDescriptorUpdateTemplate_EXT});

    /* skip args->device */
    /* skip args->descriptorUpdateTemplate */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetBufferMemoryRequirements2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetBufferMemoryRequirements2 *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInfo));
        if (!args->pInfo) return;
        vn_decode_VkBufferMemoryRequirementsInfo2_temp(dec, (VkBufferMemoryRequirementsInfo2 *)args->pInfo);
    } else {
        args->pInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pMemoryRequirements = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryRequirements));
        if (!args->pMemoryRequirements) return;
        vn_decode_VkMemoryRequirements2_partial_temp(dec, args->pMemoryRequirements);
    } else {
        args->pMemoryRequirements = NULL;
    }
}

static inline void vn_replace_vkGetBufferMemoryRequirements2_args_handle(struct vn_command_vkGetBufferMemoryRequirements2 *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pInfo)
        vn_replace_VkBufferMemoryRequirementsInfo2_handle((VkBufferMemoryRequirementsInfo2 *)args->pInfo);
    /* skip args->pMemoryRequirements */
}

static inline void vn_encode_vkGetBufferMemoryRequirements2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetBufferMemoryRequirements2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetBufferMemoryRequirements2_EXT});

    /* skip args->device */
    /* skip args->pInfo */
    if (vn_encode_simple_pointer(enc, args->pMemoryRequirements))
        vn_encode_VkMemoryRequirements2(enc, args->pMemoryRequirements);
}

static inline void vn_decode_vkGetImageMemoryRequirements2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetImageMemoryRequirements2 *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInfo));
        if (!args->pInfo) return;
        vn_decode_VkImageMemoryRequirementsInfo2_temp(dec, (VkImageMemoryRequirementsInfo2 *)args->pInfo);
    } else {
        args->pInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pMemoryRequirements = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pMemoryRequirements));
        if (!args->pMemoryRequirements) return;
        vn_decode_VkMemoryRequirements2_partial_temp(dec, args->pMemoryRequirements);
    } else {
        args->pMemoryRequirements = NULL;
    }
}

static inline void vn_replace_vkGetImageMemoryRequirements2_args_handle(struct vn_command_vkGetImageMemoryRequirements2 *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pInfo)
        vn_replace_VkImageMemoryRequirementsInfo2_handle((VkImageMemoryRequirementsInfo2 *)args->pInfo);
    /* skip args->pMemoryRequirements */
}

static inline void vn_encode_vkGetImageMemoryRequirements2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetImageMemoryRequirements2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetImageMemoryRequirements2_EXT});

    /* skip args->device */
    /* skip args->pInfo */
    if (vn_encode_simple_pointer(enc, args->pMemoryRequirements))
        vn_encode_VkMemoryRequirements2(enc, args->pMemoryRequirements);
}

static inline void vn_decode_vkGetImageSparseMemoryRequirements2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetImageSparseMemoryRequirements2 *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInfo));
        if (!args->pInfo) return;
        vn_decode_VkImageSparseMemoryRequirementsInfo2_temp(dec, (VkImageSparseMemoryRequirementsInfo2 *)args->pInfo);
    } else {
        args->pInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSparseMemoryRequirementCount = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSparseMemoryRequirementCount));
        if (!args->pSparseMemoryRequirementCount) return;
        vn_decode_uint32_t(dec, args->pSparseMemoryRequirementCount);
    } else {
        args->pSparseMemoryRequirementCount = NULL;
    }
    if (vn_peek_array_size(dec)) {
        args->pSparseMemoryRequirements = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSparseMemoryRequirements) * *args->pSparseMemoryRequirementCount);
        if (!args->pSparseMemoryRequirements) return;
        vn_decode_array_size(dec, *args->pSparseMemoryRequirementCount);
        for (uint32_t i = 0; i < *args->pSparseMemoryRequirementCount; i++)
            vn_decode_VkSparseImageMemoryRequirements2_partial_temp(dec, &args->pSparseMemoryRequirements[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pSparseMemoryRequirements = NULL;
    }
}

static inline void vn_replace_vkGetImageSparseMemoryRequirements2_args_handle(struct vn_command_vkGetImageSparseMemoryRequirements2 *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pInfo)
        vn_replace_VkImageSparseMemoryRequirementsInfo2_handle((VkImageSparseMemoryRequirementsInfo2 *)args->pInfo);
    /* skip args->pSparseMemoryRequirementCount */
    /* skip args->pSparseMemoryRequirements */
}

static inline void vn_encode_vkGetImageSparseMemoryRequirements2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetImageSparseMemoryRequirements2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetImageSparseMemoryRequirements2_EXT});

    /* skip args->device */
    /* skip args->pInfo */
    if (vn_encode_simple_pointer(enc, args->pSparseMemoryRequirementCount))
        vn_encode_uint32_t(enc, args->pSparseMemoryRequirementCount);
    if (args->pSparseMemoryRequirements) {
        vn_encode_array_size(enc, *args->pSparseMemoryRequirementCount);
        for (uint32_t i = 0; i < *args->pSparseMemoryRequirementCount; i++)
            vn_encode_VkSparseImageMemoryRequirements2(enc, &args->pSparseMemoryRequirements[i]);
    } else {
        vn_encode_array_size(enc, 0);
    }
}

static inline void vn_decode_vkCreateSamplerYcbcrConversion_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateSamplerYcbcrConversion *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkSamplerYcbcrConversionCreateInfo_temp(dec, (VkSamplerYcbcrConversionCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pYcbcrConversion = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pYcbcrConversion));
        if (!args->pYcbcrConversion) return;
        vn_decode_VkSamplerYcbcrConversion(dec, args->pYcbcrConversion);
    } else {
        args->pYcbcrConversion = NULL;
    }
}

static inline void vn_replace_vkCreateSamplerYcbcrConversion_args_handle(struct vn_command_vkCreateSamplerYcbcrConversion *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkSamplerYcbcrConversionCreateInfo_handle((VkSamplerYcbcrConversionCreateInfo *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pYcbcrConversion */
}

static inline void vn_encode_vkCreateSamplerYcbcrConversion_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateSamplerYcbcrConversion *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateSamplerYcbcrConversion_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pYcbcrConversion))
        vn_encode_VkSamplerYcbcrConversion(enc, args->pYcbcrConversion);
}

static inline void vn_decode_vkDestroySamplerYcbcrConversion_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroySamplerYcbcrConversion *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkSamplerYcbcrConversion_lookup(dec, &args->ycbcrConversion);
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
}

static inline void vn_replace_vkDestroySamplerYcbcrConversion_args_handle(struct vn_command_vkDestroySamplerYcbcrConversion *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkSamplerYcbcrConversion_handle(&args->ycbcrConversion);
    /* skip args->pAllocator */
}

static inline void vn_encode_vkDestroySamplerYcbcrConversion_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroySamplerYcbcrConversion *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroySamplerYcbcrConversion_EXT});

    /* skip args->device */
    /* skip args->ycbcrConversion */
    /* skip args->pAllocator */
}

static inline void vn_decode_vkGetDeviceQueue2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetDeviceQueue2 *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pQueueInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueueInfo));
        if (!args->pQueueInfo) return;
        vn_decode_VkDeviceQueueInfo2_temp(dec, (VkDeviceQueueInfo2 *)args->pQueueInfo);
    } else {
        args->pQueueInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pQueue = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pQueue));
        if (!args->pQueue) return;
        vn_decode_VkQueue_temp(dec, args->pQueue);
    } else {
        args->pQueue = NULL;
    }
}

static inline void vn_replace_vkGetDeviceQueue2_args_handle(struct vn_command_vkGetDeviceQueue2 *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pQueueInfo)
        vn_replace_VkDeviceQueueInfo2_handle((VkDeviceQueueInfo2 *)args->pQueueInfo);
    /* skip args->pQueue */
}

static inline void vn_encode_vkGetDeviceQueue2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetDeviceQueue2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetDeviceQueue2_EXT});

    /* skip args->device */
    /* skip args->pQueueInfo */
    if (vn_encode_simple_pointer(enc, args->pQueue))
        vn_encode_VkQueue(enc, args->pQueue);
}

static inline void vn_decode_vkGetDescriptorSetLayoutSupport_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetDescriptorSetLayoutSupport *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkDescriptorSetLayoutCreateInfo_temp(dec, (VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSupport = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSupport));
        if (!args->pSupport) return;
        vn_decode_VkDescriptorSetLayoutSupport_partial_temp(dec, args->pSupport);
    } else {
        args->pSupport = NULL;
    }
}

static inline void vn_replace_vkGetDescriptorSetLayoutSupport_args_handle(struct vn_command_vkGetDescriptorSetLayoutSupport *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkDescriptorSetLayoutCreateInfo_handle((VkDescriptorSetLayoutCreateInfo *)args->pCreateInfo);
    /* skip args->pSupport */
}

static inline void vn_encode_vkGetDescriptorSetLayoutSupport_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetDescriptorSetLayoutSupport *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetDescriptorSetLayoutSupport_EXT});

    /* skip args->device */
    /* skip args->pCreateInfo */
    if (vn_encode_simple_pointer(enc, args->pSupport))
        vn_encode_VkDescriptorSetLayoutSupport(enc, args->pSupport);
}

static inline void vn_decode_vkCreateRenderPass2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateRenderPass2 *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkRenderPassCreateInfo2_temp(dec, (VkRenderPassCreateInfo2 *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        assert(false);
    } else {
        args->pAllocator = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pRenderPass = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRenderPass));
        if (!args->pRenderPass) return;
        vn_decode_VkRenderPass(dec, args->pRenderPass);
    } else {
        args->pRenderPass = NULL;
    }
}

static inline void vn_replace_vkCreateRenderPass2_args_handle(struct vn_command_vkCreateRenderPass2 *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pCreateInfo)
        vn_replace_VkRenderPassCreateInfo2_handle((VkRenderPassCreateInfo2 *)args->pCreateInfo);
    /* skip args->pAllocator */
    /* skip args->pRenderPass */
}

static inline void vn_encode_vkCreateRenderPass2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateRenderPass2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateRenderPass2_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pCreateInfo */
    /* skip args->pAllocator */
    if (vn_encode_simple_pointer(enc, args->pRenderPass))
        vn_encode_VkRenderPass(enc, args->pRenderPass);
}

static inline void vn_decode_vkCmdBeginRenderPass2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBeginRenderPass2 *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    if (vn_decode_simple_pointer(dec)) {
        args->pRenderPassBegin = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pRenderPassBegin));
        if (!args->pRenderPassBegin) return;
        vn_decode_VkRenderPassBeginInfo_temp(dec, (VkRenderPassBeginInfo *)args->pRenderPassBegin);
    } else {
        args->pRenderPassBegin = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSubpassBeginInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSubpassBeginInfo));
        if (!args->pSubpassBeginInfo) return;
        vn_decode_VkSubpassBeginInfo_temp(dec, (VkSubpassBeginInfo *)args->pSubpassBeginInfo);
    } else {
        args->pSubpassBeginInfo = NULL;
    }
}

static inline void vn_replace_vkCmdBeginRenderPass2_args_handle(struct vn_command_vkCmdBeginRenderPass2 *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    if (args->pRenderPassBegin)
        vn_replace_VkRenderPassBeginInfo_handle((VkRenderPassBeginInfo *)args->pRenderPassBegin);
    if (args->pSubpassBeginInfo)
        vn_replace_VkSubpassBeginInfo_handle((VkSubpassBeginInfo *)args->pSubpassBeginInfo);
}

static inline void vn_encode_vkCmdBeginRenderPass2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBeginRenderPass2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBeginRenderPass2_EXT});

    /* skip args->commandBuffer */
    /* skip args->pRenderPassBegin */
    /* skip args->pSubpassBeginInfo */
}

static inline void vn_decode_vkCmdNextSubpass2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdNextSubpass2 *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    if (vn_decode_simple_pointer(dec)) {
        args->pSubpassBeginInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSubpassBeginInfo));
        if (!args->pSubpassBeginInfo) return;
        vn_decode_VkSubpassBeginInfo_temp(dec, (VkSubpassBeginInfo *)args->pSubpassBeginInfo);
    } else {
        args->pSubpassBeginInfo = NULL;
    }
    if (vn_decode_simple_pointer(dec)) {
        args->pSubpassEndInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSubpassEndInfo));
        if (!args->pSubpassEndInfo) return;
        vn_decode_VkSubpassEndInfo_temp(dec, (VkSubpassEndInfo *)args->pSubpassEndInfo);
    } else {
        args->pSubpassEndInfo = NULL;
    }
}

static inline void vn_replace_vkCmdNextSubpass2_args_handle(struct vn_command_vkCmdNextSubpass2 *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    if (args->pSubpassBeginInfo)
        vn_replace_VkSubpassBeginInfo_handle((VkSubpassBeginInfo *)args->pSubpassBeginInfo);
    if (args->pSubpassEndInfo)
        vn_replace_VkSubpassEndInfo_handle((VkSubpassEndInfo *)args->pSubpassEndInfo);
}

static inline void vn_encode_vkCmdNextSubpass2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdNextSubpass2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdNextSubpass2_EXT});

    /* skip args->commandBuffer */
    /* skip args->pSubpassBeginInfo */
    /* skip args->pSubpassEndInfo */
}

static inline void vn_decode_vkCmdEndRenderPass2_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdEndRenderPass2 *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    if (vn_decode_simple_pointer(dec)) {
        args->pSubpassEndInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSubpassEndInfo));
        if (!args->pSubpassEndInfo) return;
        vn_decode_VkSubpassEndInfo_temp(dec, (VkSubpassEndInfo *)args->pSubpassEndInfo);
    } else {
        args->pSubpassEndInfo = NULL;
    }
}

static inline void vn_replace_vkCmdEndRenderPass2_args_handle(struct vn_command_vkCmdEndRenderPass2 *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    if (args->pSubpassEndInfo)
        vn_replace_VkSubpassEndInfo_handle((VkSubpassEndInfo *)args->pSubpassEndInfo);
}

static inline void vn_encode_vkCmdEndRenderPass2_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdEndRenderPass2 *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdEndRenderPass2_EXT});

    /* skip args->commandBuffer */
    /* skip args->pSubpassEndInfo */
}

static inline void vn_decode_vkGetSemaphoreCounterValue_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetSemaphoreCounterValue *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkSemaphore_lookup(dec, &args->semaphore);
    if (vn_decode_simple_pointer(dec)) {
        args->pValue = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pValue));
        if (!args->pValue) return;
    } else {
        args->pValue = NULL;
    }
}

static inline void vn_replace_vkGetSemaphoreCounterValue_args_handle(struct vn_command_vkGetSemaphoreCounterValue *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkSemaphore_handle(&args->semaphore);
    /* skip args->pValue */
}

static inline void vn_encode_vkGetSemaphoreCounterValue_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetSemaphoreCounterValue *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetSemaphoreCounterValue_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->semaphore */
    if (vn_encode_simple_pointer(enc, args->pValue))
        vn_encode_uint64_t(enc, args->pValue);
}

static inline void vn_decode_vkWaitSemaphores_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkWaitSemaphores *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pWaitInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pWaitInfo));
        if (!args->pWaitInfo) return;
        vn_decode_VkSemaphoreWaitInfo_temp(dec, (VkSemaphoreWaitInfo *)args->pWaitInfo);
    } else {
        args->pWaitInfo = NULL;
    }
    vn_decode_uint64_t(dec, &args->timeout);
}

static inline void vn_replace_vkWaitSemaphores_args_handle(struct vn_command_vkWaitSemaphores *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pWaitInfo)
        vn_replace_VkSemaphoreWaitInfo_handle((VkSemaphoreWaitInfo *)args->pWaitInfo);
    /* skip args->timeout */
}

static inline void vn_encode_vkWaitSemaphores_reply(struct vn_cs_encoder *enc, const struct vn_command_vkWaitSemaphores *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkWaitSemaphores_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pWaitInfo */
    /* skip args->timeout */
}

static inline void vn_decode_vkSignalSemaphore_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkSignalSemaphore *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pSignalInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSignalInfo));
        if (!args->pSignalInfo) return;
        vn_decode_VkSemaphoreSignalInfo_temp(dec, (VkSemaphoreSignalInfo *)args->pSignalInfo);
    } else {
        args->pSignalInfo = NULL;
    }
}

static inline void vn_replace_vkSignalSemaphore_args_handle(struct vn_command_vkSignalSemaphore *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pSignalInfo)
        vn_replace_VkSemaphoreSignalInfo_handle((VkSemaphoreSignalInfo *)args->pSignalInfo);
}

static inline void vn_encode_vkSignalSemaphore_reply(struct vn_cs_encoder *enc, const struct vn_command_vkSignalSemaphore *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkSignalSemaphore_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->pSignalInfo */
}

static inline void vn_decode_vkCmdDrawIndirectCount_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDrawIndirectCount *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    vn_decode_VkDeviceSize(dec, &args->offset);
    vn_decode_VkBuffer_lookup(dec, &args->countBuffer);
    vn_decode_VkDeviceSize(dec, &args->countBufferOffset);
    vn_decode_uint32_t(dec, &args->maxDrawCount);
    vn_decode_uint32_t(dec, &args->stride);
}

static inline void vn_replace_vkCmdDrawIndirectCount_args_handle(struct vn_command_vkCmdDrawIndirectCount *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->offset */
    vn_replace_VkBuffer_handle(&args->countBuffer);
    /* skip args->countBufferOffset */
    /* skip args->maxDrawCount */
    /* skip args->stride */
}

static inline void vn_encode_vkCmdDrawIndirectCount_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDrawIndirectCount *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDrawIndirectCount_EXT});

    /* skip args->commandBuffer */
    /* skip args->buffer */
    /* skip args->offset */
    /* skip args->countBuffer */
    /* skip args->countBufferOffset */
    /* skip args->maxDrawCount */
    /* skip args->stride */
}

static inline void vn_decode_vkCmdDrawIndexedIndirectCount_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDrawIndexedIndirectCount *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkBuffer_lookup(dec, &args->buffer);
    vn_decode_VkDeviceSize(dec, &args->offset);
    vn_decode_VkBuffer_lookup(dec, &args->countBuffer);
    vn_decode_VkDeviceSize(dec, &args->countBufferOffset);
    vn_decode_uint32_t(dec, &args->maxDrawCount);
    vn_decode_uint32_t(dec, &args->stride);
}

static inline void vn_replace_vkCmdDrawIndexedIndirectCount_args_handle(struct vn_command_vkCmdDrawIndexedIndirectCount *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkBuffer_handle(&args->buffer);
    /* skip args->offset */
    vn_replace_VkBuffer_handle(&args->countBuffer);
    /* skip args->countBufferOffset */
    /* skip args->maxDrawCount */
    /* skip args->stride */
}

static inline void vn_encode_vkCmdDrawIndexedIndirectCount_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDrawIndexedIndirectCount *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDrawIndexedIndirectCount_EXT});

    /* skip args->commandBuffer */
    /* skip args->buffer */
    /* skip args->offset */
    /* skip args->countBuffer */
    /* skip args->countBufferOffset */
    /* skip args->maxDrawCount */
    /* skip args->stride */
}

static inline void vn_decode_vkCmdBindTransformFeedbackBuffersEXT_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBindTransformFeedbackBuffersEXT *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->firstBinding);
    vn_decode_uint32_t(dec, &args->bindingCount);
    if (vn_peek_array_size(dec)) {
        args->pBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pBuffers) * args->bindingCount);
        if (!args->pBuffers) return;
        vn_decode_array_size(dec, args->bindingCount);
        for (uint32_t i = 0; i < args->bindingCount; i++)
            vn_decode_VkBuffer_lookup(dec, &((VkBuffer *)args->pBuffers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pBuffers = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->bindingCount);
        args->pOffsets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pOffsets) * array_size);
        if (!args->pOffsets) return;
        vn_decode_VkDeviceSize_array(dec, (VkDeviceSize *)args->pOffsets, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pOffsets = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->bindingCount);
        args->pSizes = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pSizes) * array_size);
        if (!args->pSizes) return;
        vn_decode_VkDeviceSize_array(dec, (VkDeviceSize *)args->pSizes, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pSizes = NULL;
    }
}

static inline void vn_replace_vkCmdBindTransformFeedbackBuffersEXT_args_handle(struct vn_command_vkCmdBindTransformFeedbackBuffersEXT *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->firstBinding */
    /* skip args->bindingCount */
    if (args->pBuffers) {
       for (uint32_t i = 0; i < args->bindingCount; i++)
            vn_replace_VkBuffer_handle(&((VkBuffer *)args->pBuffers)[i]);
    }
    /* skip args->pOffsets */
    /* skip args->pSizes */
}

static inline void vn_encode_vkCmdBindTransformFeedbackBuffersEXT_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBindTransformFeedbackBuffersEXT *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBindTransformFeedbackBuffersEXT_EXT});

    /* skip args->commandBuffer */
    /* skip args->firstBinding */
    /* skip args->bindingCount */
    /* skip args->pBuffers */
    /* skip args->pOffsets */
    /* skip args->pSizes */
}

static inline void vn_decode_vkCmdBeginTransformFeedbackEXT_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBeginTransformFeedbackEXT *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->firstCounterBuffer);
    vn_decode_uint32_t(dec, &args->counterBufferCount);
    if (vn_peek_array_size(dec)) {
        args->pCounterBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCounterBuffers) * args->counterBufferCount);
        if (!args->pCounterBuffers) return;
        vn_decode_array_size(dec, args->counterBufferCount);
        for (uint32_t i = 0; i < args->counterBufferCount; i++)
            vn_decode_VkBuffer_lookup(dec, &((VkBuffer *)args->pCounterBuffers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCounterBuffers = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->counterBufferCount);
        args->pCounterBufferOffsets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCounterBufferOffsets) * array_size);
        if (!args->pCounterBufferOffsets) return;
        vn_decode_VkDeviceSize_array(dec, (VkDeviceSize *)args->pCounterBufferOffsets, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCounterBufferOffsets = NULL;
    }
}

static inline void vn_replace_vkCmdBeginTransformFeedbackEXT_args_handle(struct vn_command_vkCmdBeginTransformFeedbackEXT *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->firstCounterBuffer */
    /* skip args->counterBufferCount */
    if (args->pCounterBuffers) {
       for (uint32_t i = 0; i < args->counterBufferCount; i++)
            vn_replace_VkBuffer_handle(&((VkBuffer *)args->pCounterBuffers)[i]);
    }
    /* skip args->pCounterBufferOffsets */
}

static inline void vn_encode_vkCmdBeginTransformFeedbackEXT_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBeginTransformFeedbackEXT *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBeginTransformFeedbackEXT_EXT});

    /* skip args->commandBuffer */
    /* skip args->firstCounterBuffer */
    /* skip args->counterBufferCount */
    /* skip args->pCounterBuffers */
    /* skip args->pCounterBufferOffsets */
}

static inline void vn_decode_vkCmdEndTransformFeedbackEXT_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdEndTransformFeedbackEXT *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->firstCounterBuffer);
    vn_decode_uint32_t(dec, &args->counterBufferCount);
    if (vn_peek_array_size(dec)) {
        args->pCounterBuffers = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCounterBuffers) * args->counterBufferCount);
        if (!args->pCounterBuffers) return;
        vn_decode_array_size(dec, args->counterBufferCount);
        for (uint32_t i = 0; i < args->counterBufferCount; i++)
            vn_decode_VkBuffer_lookup(dec, &((VkBuffer *)args->pCounterBuffers)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCounterBuffers = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->counterBufferCount);
        args->pCounterBufferOffsets = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCounterBufferOffsets) * array_size);
        if (!args->pCounterBufferOffsets) return;
        vn_decode_VkDeviceSize_array(dec, (VkDeviceSize *)args->pCounterBufferOffsets, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pCounterBufferOffsets = NULL;
    }
}

static inline void vn_replace_vkCmdEndTransformFeedbackEXT_args_handle(struct vn_command_vkCmdEndTransformFeedbackEXT *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->firstCounterBuffer */
    /* skip args->counterBufferCount */
    if (args->pCounterBuffers) {
       for (uint32_t i = 0; i < args->counterBufferCount; i++)
            vn_replace_VkBuffer_handle(&((VkBuffer *)args->pCounterBuffers)[i]);
    }
    /* skip args->pCounterBufferOffsets */
}

static inline void vn_encode_vkCmdEndTransformFeedbackEXT_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdEndTransformFeedbackEXT *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdEndTransformFeedbackEXT_EXT});

    /* skip args->commandBuffer */
    /* skip args->firstCounterBuffer */
    /* skip args->counterBufferCount */
    /* skip args->pCounterBuffers */
    /* skip args->pCounterBufferOffsets */
}

static inline void vn_decode_vkCmdBeginQueryIndexedEXT_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdBeginQueryIndexedEXT *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->query);
    vn_decode_VkFlags(dec, &args->flags);
    vn_decode_uint32_t(dec, &args->index);
}

static inline void vn_replace_vkCmdBeginQueryIndexedEXT_args_handle(struct vn_command_vkCmdBeginQueryIndexedEXT *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->query */
    /* skip args->flags */
    /* skip args->index */
}

static inline void vn_encode_vkCmdBeginQueryIndexedEXT_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdBeginQueryIndexedEXT *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdBeginQueryIndexedEXT_EXT});

    /* skip args->commandBuffer */
    /* skip args->queryPool */
    /* skip args->query */
    /* skip args->flags */
    /* skip args->index */
}

static inline void vn_decode_vkCmdEndQueryIndexedEXT_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdEndQueryIndexedEXT *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_VkQueryPool_lookup(dec, &args->queryPool);
    vn_decode_uint32_t(dec, &args->query);
    vn_decode_uint32_t(dec, &args->index);
}

static inline void vn_replace_vkCmdEndQueryIndexedEXT_args_handle(struct vn_command_vkCmdEndQueryIndexedEXT *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    vn_replace_VkQueryPool_handle(&args->queryPool);
    /* skip args->query */
    /* skip args->index */
}

static inline void vn_encode_vkCmdEndQueryIndexedEXT_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdEndQueryIndexedEXT *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdEndQueryIndexedEXT_EXT});

    /* skip args->commandBuffer */
    /* skip args->queryPool */
    /* skip args->query */
    /* skip args->index */
}

static inline void vn_decode_vkCmdDrawIndirectByteCountEXT_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCmdDrawIndirectByteCountEXT *args)
{
    vn_decode_VkCommandBuffer_lookup(dec, &args->commandBuffer);
    vn_decode_uint32_t(dec, &args->instanceCount);
    vn_decode_uint32_t(dec, &args->firstInstance);
    vn_decode_VkBuffer_lookup(dec, &args->counterBuffer);
    vn_decode_VkDeviceSize(dec, &args->counterBufferOffset);
    vn_decode_uint32_t(dec, &args->counterOffset);
    vn_decode_uint32_t(dec, &args->vertexStride);
}

static inline void vn_replace_vkCmdDrawIndirectByteCountEXT_args_handle(struct vn_command_vkCmdDrawIndirectByteCountEXT *args)
{
    vn_replace_VkCommandBuffer_handle(&args->commandBuffer);
    /* skip args->instanceCount */
    /* skip args->firstInstance */
    vn_replace_VkBuffer_handle(&args->counterBuffer);
    /* skip args->counterBufferOffset */
    /* skip args->counterOffset */
    /* skip args->vertexStride */
}

static inline void vn_encode_vkCmdDrawIndirectByteCountEXT_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCmdDrawIndirectByteCountEXT *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCmdDrawIndirectByteCountEXT_EXT});

    /* skip args->commandBuffer */
    /* skip args->instanceCount */
    /* skip args->firstInstance */
    /* skip args->counterBuffer */
    /* skip args->counterBufferOffset */
    /* skip args->counterOffset */
    /* skip args->vertexStride */
}

static inline void vn_decode_vkGetImageDrmFormatModifierPropertiesEXT_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetImageDrmFormatModifierPropertiesEXT *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    vn_decode_VkImage_lookup(dec, &args->image);
    if (vn_decode_simple_pointer(dec)) {
        args->pProperties = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pProperties));
        if (!args->pProperties) return;
        vn_decode_VkImageDrmFormatModifierPropertiesEXT_partial_temp(dec, args->pProperties);
    } else {
        args->pProperties = NULL;
    }
}

static inline void vn_replace_vkGetImageDrmFormatModifierPropertiesEXT_args_handle(struct vn_command_vkGetImageDrmFormatModifierPropertiesEXT *args)
{
    vn_replace_VkDevice_handle(&args->device);
    vn_replace_VkImage_handle(&args->image);
    /* skip args->pProperties */
}

static inline void vn_encode_vkGetImageDrmFormatModifierPropertiesEXT_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetImageDrmFormatModifierPropertiesEXT *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetImageDrmFormatModifierPropertiesEXT_EXT});

    vn_encode_VkResult(enc, &args->ret);
    /* skip args->device */
    /* skip args->image */
    if (vn_encode_simple_pointer(enc, args->pProperties))
        vn_encode_VkImageDrmFormatModifierPropertiesEXT(enc, args->pProperties);
}

static inline void vn_decode_vkGetBufferOpaqueCaptureAddress_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetBufferOpaqueCaptureAddress *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInfo));
        if (!args->pInfo) return;
        vn_decode_VkBufferDeviceAddressInfo_temp(dec, (VkBufferDeviceAddressInfo *)args->pInfo);
    } else {
        args->pInfo = NULL;
    }
}

static inline void vn_replace_vkGetBufferOpaqueCaptureAddress_args_handle(struct vn_command_vkGetBufferOpaqueCaptureAddress *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pInfo)
        vn_replace_VkBufferDeviceAddressInfo_handle((VkBufferDeviceAddressInfo *)args->pInfo);
}

static inline void vn_encode_vkGetBufferOpaqueCaptureAddress_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetBufferOpaqueCaptureAddress *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetBufferOpaqueCaptureAddress_EXT});

    vn_encode_uint64_t(enc, &args->ret);
    /* skip args->device */
    /* skip args->pInfo */
}

static inline void vn_decode_vkGetBufferDeviceAddress_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetBufferDeviceAddress *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInfo));
        if (!args->pInfo) return;
        vn_decode_VkBufferDeviceAddressInfo_temp(dec, (VkBufferDeviceAddressInfo *)args->pInfo);
    } else {
        args->pInfo = NULL;
    }
}

static inline void vn_replace_vkGetBufferDeviceAddress_args_handle(struct vn_command_vkGetBufferDeviceAddress *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pInfo)
        vn_replace_VkBufferDeviceAddressInfo_handle((VkBufferDeviceAddressInfo *)args->pInfo);
}

static inline void vn_encode_vkGetBufferDeviceAddress_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetBufferDeviceAddress *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetBufferDeviceAddress_EXT});

    vn_encode_VkDeviceAddress(enc, &args->ret);
    /* skip args->device */
    /* skip args->pInfo */
}

static inline void vn_decode_vkGetDeviceMemoryOpaqueCaptureAddress_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkGetDeviceMemoryOpaqueCaptureAddress *args)
{
    vn_decode_VkDevice_lookup(dec, &args->device);
    if (vn_decode_simple_pointer(dec)) {
        args->pInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pInfo));
        if (!args->pInfo) return;
        vn_decode_VkDeviceMemoryOpaqueCaptureAddressInfo_temp(dec, (VkDeviceMemoryOpaqueCaptureAddressInfo *)args->pInfo);
    } else {
        args->pInfo = NULL;
    }
}

static inline void vn_replace_vkGetDeviceMemoryOpaqueCaptureAddress_args_handle(struct vn_command_vkGetDeviceMemoryOpaqueCaptureAddress *args)
{
    vn_replace_VkDevice_handle(&args->device);
    if (args->pInfo)
        vn_replace_VkDeviceMemoryOpaqueCaptureAddressInfo_handle((VkDeviceMemoryOpaqueCaptureAddressInfo *)args->pInfo);
}

static inline void vn_encode_vkGetDeviceMemoryOpaqueCaptureAddress_reply(struct vn_cs_encoder *enc, const struct vn_command_vkGetDeviceMemoryOpaqueCaptureAddress *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkGetDeviceMemoryOpaqueCaptureAddress_EXT});

    vn_encode_uint64_t(enc, &args->ret);
    /* skip args->device */
    /* skip args->pInfo */
}

static inline void vn_decode_vkSetReplyCommandStreamMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkSetReplyCommandStreamMESA *args)
{
    if (vn_decode_simple_pointer(dec)) {
        args->pStream = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pStream));
        if (!args->pStream) return;
        vn_decode_VkCommandStreamDescriptionMESA_temp(dec, (VkCommandStreamDescriptionMESA *)args->pStream);
    } else {
        args->pStream = NULL;
    }
}

static inline void vn_replace_vkSetReplyCommandStreamMESA_args_handle(struct vn_command_vkSetReplyCommandStreamMESA *args)
{
    if (args->pStream)
        vn_replace_VkCommandStreamDescriptionMESA_handle((VkCommandStreamDescriptionMESA *)args->pStream);
}

static inline void vn_encode_vkSetReplyCommandStreamMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkSetReplyCommandStreamMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkSetReplyCommandStreamMESA_EXT});

    /* skip args->pStream */
}

static inline void vn_decode_vkSeekReplyCommandStreamMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkSeekReplyCommandStreamMESA *args)
{
    vn_decode_size_t(dec, &args->position);
}

static inline void vn_replace_vkSeekReplyCommandStreamMESA_args_handle(struct vn_command_vkSeekReplyCommandStreamMESA *args)
{
    /* skip args->position */
}

static inline void vn_encode_vkSeekReplyCommandStreamMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkSeekReplyCommandStreamMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkSeekReplyCommandStreamMESA_EXT});

    /* skip args->position */
}

static inline void vn_decode_vkExecuteCommandStreamsMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkExecuteCommandStreamsMESA *args)
{
    vn_decode_uint32_t(dec, &args->streamCount);
    if (vn_peek_array_size(dec)) {
        args->pStreams = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pStreams) * args->streamCount);
        if (!args->pStreams) return;
        vn_decode_array_size(dec, args->streamCount);
        for (uint32_t i = 0; i < args->streamCount; i++)
            vn_decode_VkCommandStreamDescriptionMESA_temp(dec, &((VkCommandStreamDescriptionMESA *)args->pStreams)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pStreams = NULL;
    }
    if (vn_peek_array_size(dec)) {
        const size_t array_size = vn_decode_array_size(dec, args->streamCount);
        args->pReplyPositions = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pReplyPositions) * array_size);
        if (!args->pReplyPositions) return;
        vn_decode_size_t_array(dec, (size_t *)args->pReplyPositions, array_size);
    } else {
        vn_decode_array_size(dec, 0);
        args->pReplyPositions = NULL;
    }
    vn_decode_uint32_t(dec, &args->dependencyCount);
    if (vn_peek_array_size(dec)) {
        args->pDependencies = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pDependencies) * args->dependencyCount);
        if (!args->pDependencies) return;
        vn_decode_array_size(dec, args->dependencyCount);
        for (uint32_t i = 0; i < args->dependencyCount; i++)
            vn_decode_VkCommandStreamDependencyMESA_temp(dec, &((VkCommandStreamDependencyMESA *)args->pDependencies)[i]);
    } else {
        vn_decode_array_size(dec, 0);
        args->pDependencies = NULL;
    }
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkExecuteCommandStreamsMESA_args_handle(struct vn_command_vkExecuteCommandStreamsMESA *args)
{
    /* skip args->streamCount */
    if (args->pStreams) {
       for (uint32_t i = 0; i < args->streamCount; i++)
            vn_replace_VkCommandStreamDescriptionMESA_handle(&((VkCommandStreamDescriptionMESA *)args->pStreams)[i]);
    }
    /* skip args->pReplyPositions */
    /* skip args->dependencyCount */
    if (args->pDependencies) {
       for (uint32_t i = 0; i < args->dependencyCount; i++)
            vn_replace_VkCommandStreamDependencyMESA_handle(&((VkCommandStreamDependencyMESA *)args->pDependencies)[i]);
    }
    /* skip args->flags */
}

static inline void vn_encode_vkExecuteCommandStreamsMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkExecuteCommandStreamsMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkExecuteCommandStreamsMESA_EXT});

    /* skip args->streamCount */
    /* skip args->pStreams */
    /* skip args->pReplyPositions */
    /* skip args->dependencyCount */
    /* skip args->pDependencies */
    /* skip args->flags */
}

static inline void vn_decode_vkCreateRingMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkCreateRingMESA *args)
{
    vn_decode_uint64_t(dec, &args->ring);
    if (vn_decode_simple_pointer(dec)) {
        args->pCreateInfo = vn_cs_decoder_alloc_temp(dec, sizeof(*args->pCreateInfo));
        if (!args->pCreateInfo) return;
        vn_decode_VkRingCreateInfoMESA_temp(dec, (VkRingCreateInfoMESA *)args->pCreateInfo);
    } else {
        args->pCreateInfo = NULL;
    }
}

static inline void vn_replace_vkCreateRingMESA_args_handle(struct vn_command_vkCreateRingMESA *args)
{
    /* skip args->ring */
    if (args->pCreateInfo)
        vn_replace_VkRingCreateInfoMESA_handle((VkRingCreateInfoMESA *)args->pCreateInfo);
}

static inline void vn_encode_vkCreateRingMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkCreateRingMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkCreateRingMESA_EXT});

    /* skip args->ring */
    /* skip args->pCreateInfo */
}

static inline void vn_decode_vkDestroyRingMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkDestroyRingMESA *args)
{
    vn_decode_uint64_t(dec, &args->ring);
}

static inline void vn_replace_vkDestroyRingMESA_args_handle(struct vn_command_vkDestroyRingMESA *args)
{
    /* skip args->ring */
}

static inline void vn_encode_vkDestroyRingMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkDestroyRingMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkDestroyRingMESA_EXT});

    /* skip args->ring */
}

static inline void vn_decode_vkNotifyRingMESA_args_temp(struct vn_cs_decoder *dec, struct vn_command_vkNotifyRingMESA *args)
{
    vn_decode_uint64_t(dec, &args->ring);
    vn_decode_uint32_t(dec, &args->seqno);
    vn_decode_VkFlags(dec, &args->flags);
}

static inline void vn_replace_vkNotifyRingMESA_args_handle(struct vn_command_vkNotifyRingMESA *args)
{
    /* skip args->ring */
    /* skip args->seqno */
    /* skip args->flags */
}

static inline void vn_encode_vkNotifyRingMESA_reply(struct vn_cs_encoder *enc, const struct vn_command_vkNotifyRingMESA *args)
{
    vn_encode_VkCommandTypeEXT(enc, &(VkCommandTypeEXT){VK_COMMAND_TYPE_vkNotifyRingMESA_EXT});

    /* skip args->ring */
    /* skip args->seqno */
    /* skip args->flags */
}

#endif /* VN_PROTOCOL_RENDERER_COMMANDS_H */
