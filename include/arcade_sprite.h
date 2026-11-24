#ifndef DDPDOJ_ARCADE_SPRITE_H
#define DDPDOJ_ARCADE_SPRITE_H

#include "types.h"

/* Directory entry of the sprite sheet (SPHED.PRS): where an image starts in the pixel data and its size. */
typedef struct {
    s32 offset;
    s16 w;
    s16 h;
} SpriteImage;

extern SpriteImage *g_sprite_images; /* SPHED.PRS */
extern u8 *g_sprite_pixels;          /* SPDAT.PRS */
extern u8 *g_stage_sprite_buf;       /* unpacked STnSP.PRS; the packed file is read to +0x5DC800 */
extern u8 *g_frame_file_buf;         /* WAKU.8: 0x200 bytes of palette, then a 320x208 image */
extern u32 g_image_unpack_buf[];
extern s32 g_sprite_zoom_table[];

void arcade_sprite_init(void);
void sprite_header_load_async(void);
void sprite_pixels_load_async(void);
void stage_sprite_unpack_begin(s32 chunkSize);
s32 stage_sprite_unpack_step(void);
void arcade_sprite_draw(void);
void frame_image_draw(u16 alpha);

#endif
