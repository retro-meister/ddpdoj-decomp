#ifndef DDPDOJ_GFX_H
#define DDPDOJ_GFX_H

#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

/* A textured rectangle waiting in the quad queue. Only corners 0 (top left) and 1 (bottom right) are drawn. */
typedef struct {
    /* 0x00 */ s16 x[4];
    /* 0x08 */ s16 y[4];
    /* 0x10 */ s16 u[4];
    /* 0x18 */ s16 v[4];
    /* 0x20 */ s16 z;
    /* 0x24 */ s32 tbp;
    /* 0x28 */ s32 cbp;
    /* 0x2C */ s16 mode;  /* QUAD_TEX_* */
    /* 0x2E */ s16 alpha;
    /* 0x30 */ u16 color; /* same value for red, green and blue */
} Quad;

/* Texture layouts quad_build_packet knows (Quad.mode). */
enum {
    QUAD_TEX_4BIT_1024 = 0,     /* 4-bit, 1024x1024 */
    QUAD_TEX_8BIT_512 = 1,      /* 8-bit, 512x512 */
    QUAD_TEX_8BIT_1024x512 = 3  /* 8-bit, 1024x512 */
};

/* An off-screen drawing area that is later drawn as a texture. */
typedef struct {
    /* 0x00 */ u16 tbp;
    /* 0x02 */ u16 psm;
    /* 0x04 */ u32 width;
    /* 0x08 */ u32 height;
    /* 0x0C */ u16 tw;
    /* 0x0E */ u16 th;
} RenderTarget;

/* A character waiting in the glyph queue (8x8 cell of the font texture). */
typedef struct {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 page;
    /* 0x06 */ s16 code;
    /* 0x08 */ s16 z;
    /* 0x0A */ s16 alpha;
    /* 0x0C */ u16 color;
    /* 0x0E */ s16 pad;
} GlyphQueueEntry;

/* One image of the common texture file: pixel format (0 = 4-bit, 1 = 8-bit) and where it goes in its texture. */
typedef struct {
    s32 type;
    s32 dbw;
    s32 x;
    s32 y;
    s32 width;
    s32 height;
} TexUploadInfo;

extern sceGsLoadImage g_gs_load_image;
extern void *g_dma_gif;
extern u8 g_gif_buf[2][0x10000];
extern Quad g_quad_queue[];
extern s32 g_quad_count;
extern GlyphQueueEntry g_glyph_queue[];
extern s32 g_glyph_queue_count;
extern s32 g_clut_upload_cbp;  /* where the next clut_upload goes; advances by one block per palette */
extern s32 g_tex_upload_tbp;
extern s32 g_screen_mode;      /* 0-1 draw straight to the frame buffer, 2 and up go through g_render_target */
extern s32 g_screen_width;
extern s32 g_screen_margin;
extern RenderTarget g_render_target;
extern u8 g_load_buf[];
extern u8 g_splash_file_buf[];    /* ARIKA.8 (DON.8 in Death Label) */
extern u8 g_stage_map_file_buf[]; /* MAP2.8 */
extern s32 g_stage_map_progress;

extern u8 g_splash_visible;
void splash_image_upload(void);
void stage_map_image_upload(void);
void tex_upload(s32 index);
void clut_upload(u8 *src, s32 mode, s32 count);
void tex_load_common(void);
void stage_load_step(void);
void clut_upload_defaults(void);
void text_palette_upload(void);
void sprite_palette_upload(void);
void bg_palette_upload(void);
void splash_image_draw(void);
void stage_map_reset(void);
void stage_map_show(void);
void stage_map_hide(void);
void stage_map_update(void);
void stage_map_draw(void);
void text_layer_clear_edge_top(void);
void text_layer_clear_edge_bottom(void);
void text_layer_draw(void);
void text_layer_queue_tile(s32 x, s32 y);
void bg_layer_draw(void);
void bg_layer_queue_tile(s32 col, s32 row);
void quad_flush(void);
void quad_build_packet(Qword *pkt, s32 first, s32 count);
void render_target_init(RenderTarget *target, void *packetBuf, s32 tbp, u32 width, u32 height);
void render_target_begin(RenderTarget *target, void *packetBuf);
void framebuffer_begin_present(void *packetBuf);
void render_target_present(RenderTarget *target, void *packetBuf);
void render_target_present_wide(RenderTarget *target, void *packetBuf);
void framebuffer_begin(void *packetBuf);
void display_set_offset(s32 x, s32 y);
void display_reset(void);
void wallpaper_load(s32 image, u16 *palette);
void wallpaper_draw(void *packetBuf);
void scissor_set(void *packetBuf, s32 x, s32 y, s32 w, s32 h);
void label_draw(RenderTarget *target, s32 x, s32 y, const char *text);
void glyph_queue_clear(void);
void glyph_queue_add(s32 x, s32 y, s32 z, s32 page, s32 color, s32 alpha, s32 wide); /* text in reg_a0 */
void glyph_queue_flush(void);
void glyph_queue_emit(s32 index);

#endif
