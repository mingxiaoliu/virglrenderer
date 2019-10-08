/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_INFO_H
#define VN_PROTOCOL_RENDERER_INFO_H

#include "vn_protocol_renderer_defines.h"

static inline uint32_t
vn_info_wire_format_version(void)
{
    return 0;
}

static inline uint32_t
vn_info_vk_xml_version(void)
{
    return VK_MAKE_VERSION(1, 2, 167);
}

static inline int
vn_info_extension_compare(const void *a, const void *b)
{
   return strcmp(a, *(const char **)b);
}

static inline uint32_t
vn_info_extension_spec_version(const char *name)
{
    static uint32_t ext_count = 51;
    static const char *ext_names[51] = {
        "VK_EXT_command_serialization",
        "VK_EXT_descriptor_indexing",
        "VK_EXT_host_query_reset",
        "VK_EXT_image_drm_format_modifier",
        "VK_EXT_sampler_filter_minmax",
        "VK_EXT_scalar_block_layout",
        "VK_EXT_separate_stencil_usage",
        "VK_EXT_shader_viewport_index_layer",
        "VK_EXT_transform_feedback",
        "VK_KHR_16bit_storage",
        "VK_KHR_8bit_storage",
        "VK_KHR_bind_memory2",
        "VK_KHR_buffer_device_address",
        "VK_KHR_create_renderpass2",
        "VK_KHR_dedicated_allocation",
        "VK_KHR_depth_stencil_resolve",
        "VK_KHR_descriptor_update_template",
        "VK_KHR_device_group",
        "VK_KHR_device_group_creation",
        "VK_KHR_draw_indirect_count",
        "VK_KHR_driver_properties",
        "VK_KHR_external_fence",
        "VK_KHR_external_fence_capabilities",
        "VK_KHR_external_memory",
        "VK_KHR_external_memory_capabilities",
        "VK_KHR_external_semaphore",
        "VK_KHR_external_semaphore_capabilities",
        "VK_KHR_get_memory_requirements2",
        "VK_KHR_get_physical_device_properties2",
        "VK_KHR_image_format_list",
        "VK_KHR_imageless_framebuffer",
        "VK_KHR_maintenance1",
        "VK_KHR_maintenance2",
        "VK_KHR_maintenance3",
        "VK_KHR_multiview",
        "VK_KHR_relaxed_block_layout",
        "VK_KHR_sampler_mirror_clamp_to_edge",
        "VK_KHR_sampler_ycbcr_conversion",
        "VK_KHR_separate_depth_stencil_layouts",
        "VK_KHR_shader_atomic_int64",
        "VK_KHR_shader_draw_parameters",
        "VK_KHR_shader_float16_int8",
        "VK_KHR_shader_float_controls",
        "VK_KHR_shader_subgroup_extended_types",
        "VK_KHR_spirv_1_4",
        "VK_KHR_storage_buffer_storage_class",
        "VK_KHR_timeline_semaphore",
        "VK_KHR_uniform_buffer_standard_layout",
        "VK_KHR_variable_pointers",
        "VK_KHR_vulkan_memory_model",
        "VK_MESA_venus_protocol",
    };
    static const uint32_t ext_versions[51] = {
        1,
        2,
        1,
        1,
        2,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        3,
        1,
        1,
        4,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        2,
        1,
        1,
        2,
        1,
        1,
        1,
        1,
        3,
        14,
        1,
        1,
        1,
        1,
        4,
        1,
        1,
        1,
        2,
        1,
        1,
        3,
        1,
    };
    const char **found;

    found = bsearch(name, ext_names, ext_count, sizeof(ext_names[0]),
          vn_info_extension_compare);

    return found ? ext_versions[found - ext_names] : 0;
}

#endif /* VN_PROTOCOL_RENDERER_INFO_H */
