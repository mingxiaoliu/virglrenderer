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
 *   struct vn_cs_encoder
 *   vn_cs_encoder_write
 *
 *   struct vn_cs_decoder
 *   vn_cs_decoder_set_fatal
 *   vn_cs_decoder_get_fatal
 *   vn_cs_decoder_lookup_object
 *   vn_cs_decoder_reset_temp_pool
 *   vn_cs_decoder_alloc_temp
 *   vn_cs_decoder_read
 *   vn_cs_decoder_peek
 *
 *   vn_object_id
 *   vn_cs_get_object_handle
 *   vn_cs_handle_load_id
 *   vn_cs_handle_store_id
 */
#include "vkr_parser.h"

struct vn_cs_encoder;
struct vn_cs_decoder;

typedef vkr_object_id vn_object_id;

static inline void
vn_cs_encoder_write(struct vn_cs_encoder *enc, size_t size, const void *val, size_t val_size)
{
   struct vkr_parser *parser = (struct vkr_parser *)enc;
   vkr_parser_reply(parser, size, val, val_size);
}

static inline void
vn_cs_decoder_set_fatal(struct vn_cs_decoder *dec)
{
   struct vkr_parser *parser = (struct vkr_parser *)dec;
   vkr_parser_set_error(parser);
}

static inline bool
vn_cs_decoder_get_fatal(const struct vn_cs_decoder *dec)
{
   struct vkr_parser *parser = (struct vkr_parser *)dec;
   return vkr_parser_has_error(parser);
}

static inline void *
vn_cs_decoder_lookup_object(struct vn_cs_decoder *dec, vn_object_id id)
{
   struct vkr_parser *parser = (struct vkr_parser *)dec;
   return vkr_parser_lookup_object(parser, id);
}

static inline void
vn_cs_decoder_reset_temp_pool(struct vn_cs_decoder *dec)
{
   struct vkr_parser *parser = (struct vkr_parser *)dec;
   vkr_parser_reset_temp_pool(parser);
}

static inline void *
vn_cs_decoder_alloc_temp(struct vn_cs_decoder *dec, size_t size)
{
   struct vkr_parser *parser = (struct vkr_parser *)dec;
   return vkr_parser_alloc_temp(parser, size);
}

static inline void
vn_cs_decoder_read(struct vn_cs_decoder *dec, size_t size, void *val, size_t val_size)
{
   struct vkr_parser *parser = (struct vkr_parser *)dec;
   vkr_parser_read(parser, size, val, val_size);
}

static inline void
vn_cs_decoder_peek(struct vn_cs_decoder *dec, void *val, size_t val_size)
{
   struct vkr_parser *parser = (struct vkr_parser *)dec;
   vkr_parser_peek(parser, val, val_size);
}

static inline uint64_t
vn_cs_get_object_handle(const void *vk_handle)
{
   const struct vkr_object *obj = *(const struct vkr_object **)vk_handle;
   return obj ? obj->handle : 0;
}

static inline vn_object_id
vn_cs_handle_load_id(const void *vk_handle, bool in_place)
{
   return vkr_parser_handle_load_id(vk_handle, in_place);
}

static inline void
vn_cs_handle_store_id(void *vk_handle, vn_object_id id, bool in_place)
{
   vkr_parser_handle_store_id(vk_handle, id, in_place);
}

static inline void
vn_encode(struct vn_cs_encoder *enc, size_t size, const void *data, size_t data_size)
{
   assert(size % 4 == 0);
   /* no vn_cs_encoder_reserve; vn_cs_encoder_write must do size check */
   /* TODO check if the generated code is optimal */
   vn_cs_encoder_write(enc, size, data, data_size);
}

static inline void
vn_decode(struct vn_cs_decoder *dec, size_t size, void *data, size_t data_size)
{
   assert(size % 4 == 0);
   vn_cs_decoder_read(dec, size, data, data_size);
}

#endif /* VN_PROTOCOL_RENDERER_CS_H */
