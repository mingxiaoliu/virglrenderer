/*
 * Copyright 2020 Google LLC
 * SPDX-License-Identifier: MIT
 */

#ifndef VN_PROTOCOL_RENDERER_CS_H
#define VN_PROTOCOL_RENDERER_CS_H

#include <assert.h>

/*
 * These types/functions are expected
 *
 *   struct vn_cs
 *   vn_cs_object_id
 *   vn_cs_set_error
 *   vn_cs_has_error
 *   vn_cs_lookup_object
 *   vn_cs_get_object_handle
 *   vn_cs_reset_temp_pool
 *   vn_cs_alloc_temp
 *   vn_cs_in
 *   vn_cs_in_peek
 *   vn_cs_out
 *   vn_cs_handle_load_id
 *   vn_cs_handle_store_id
 */
#include "vkr_parser.h"

struct vn_cs;

typedef vkr_parser_object_id vn_cs_object_id;

static inline void
vn_cs_set_error(struct vn_cs *cs)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   vkr_parser_set_error(parser);
}

static inline bool
vn_cs_has_error(const struct vn_cs *cs)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   return vkr_parser_has_error(parser);
}

static inline void *
vn_cs_lookup_object(struct vn_cs *cs, vn_cs_object_id id)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   return vkr_parser_lookup_object(parser, id);
}

static inline uint64_t
vn_cs_get_object_handle(const void *vk_handle)
{
   const struct vkr_parser_object *obj =
      *(const struct vkr_parser_object **)vk_handle;
   return obj ? obj->handle : 0;
}

static inline void
vn_cs_reset_temp_pool(struct vn_cs *cs)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   vkr_parser_reset_temp_pool(parser);
}

static inline void *
vn_cs_alloc_temp(struct vn_cs *cs, size_t size)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   return vkr_parser_alloc_temp(parser, size);
}

static inline void
vn_cs_in(struct vn_cs *cs, size_t size, void *val, size_t val_size)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   vkr_parser_read(parser, size, val, val_size);
}

static inline void
vn_cs_in_peek(struct vn_cs *cs, void *val, size_t val_size)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   vkr_parser_peek(parser, val, val_size);
}

static inline void
vn_cs_out(struct vn_cs *cs, size_t size, const void *val, size_t val_size)
{
   struct vkr_parser *parser = (struct vkr_parser *)cs;
   vkr_parser_reply(parser, size, val, val_size);
}

static inline vn_cs_object_id
vn_cs_handle_load_id(const void *vk_handle, bool in_place)
{
   return vkr_parser_handle_load_id(vk_handle, in_place);
}

static inline void
vn_cs_handle_store_id(void *vk_handle, vn_cs_object_id id, bool in_place)
{
   vkr_parser_handle_store_id(vk_handle, id, in_place);
}

static inline void
vn_encode(struct vn_cs *cs, size_t size, const void *data, size_t data_size)
{
   assert(size % 4 == 0);
   /* no vn_cs_reserve_out; vn_cs_out must do size check */
   /* TODO check if the generated code is optimal */
   vn_cs_out(cs, size, data, data_size);
}

static inline void
vn_decode(struct vn_cs *cs, size_t size, void *data, size_t data_size)
{
   assert(size % 4 == 0);
   vn_cs_in(cs, size, data, data_size);
}

#endif /* VN_PROTOCOL_RENDERER_CS_H */
