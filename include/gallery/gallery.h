#ifndef DDPDOJ_GALLERY_H
#define DDPDOJ_GALLERY_H

#include "common.h"
#include "sdk/ps2sdk.h"

typedef enum {
    GALLERY_MODE_LOADING = 0,
    GALLERY_MODE_FADE_IN = 1,
    GALLERY_MODE_GRID    = 2,
    GALLERY_MODE_VIEWER  = 3,
    GALLERY_MODE_EXIT    = 4
} GalleryMode;

typedef union {
    unsigned __int128 q;
    u64 d[2];
    u32 w[4];
} Qword;

typedef struct {
    s16 u;
    s16 v;
    s16 w;
    s16 h;
    u64 tex0;
} SpriteInfo;

typedef struct {
    s16 u;
    s16 v;
    s16 w;
    s16 h;
} Rect16;

typedef struct {
    s16 previous;
    s16 next;
    s16 key;
    s16 x;
    s16 y;
    s16 flags;
} GlyphCacheEntry;

typedef struct {
    u8 pad00[8];
    s32 x0;
    s32 y0;
    s32 x1;
    s32 y1;
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 alpha;
} GalleryBox;

typedef struct {
    s8 flags[6];
    s8 pad06;
    s8 zoomed;
    GalleryBox titleBox;
    GalleryBox menuBox;
    SpriteInfo *tex;
    const char *title;
    s32 state;
    s32 timer;
    u32 dispX;
    u32 dispY;
    u32 dispW;
    u32 dispH;
    s32 panX;
    s32 panY;
    s32 minX;
    s32 minY;
    s32 maxX;
    s32 maxY;
    s32 baseScale;
} GalleryView;

typedef struct {
    u8 readBuf[0x101000];
    u8 decodeBuf[0x101000];
    u8 flagBuf[0x101000];
    u8 bmpScratchBuf[0x101000];
    u8 textureBuffer[0x101000];
    s32 menu_params[12];
    u8 pad_505030[4];
    GalleryView sprites[2];
    GalleryView *curSprite;
    GalleryView *prevSprite;
    s32 exitRequested;
    s32 mode;
    s32 state;
    s32 subState;
    s32 stepState;
    s32 timer;
    s32 countdown;
    s32 exitMode;
    s16 overlayEnabled;
    s16 overlayAdjustment;
    s32 showHelp;
    s16 fadeState;
    s8 dialogState;
    s8 drawEnabled;
    SpriteInfo pageSprites[6];
    SpriteInfo allSprites[37];
    SpriteInfo viewerTextures[2];
    SpriteInfo bgSprite;
    SpriteInfo uiSprites[6];
    u8 pad_5054B0[0x30];
    SpriteInfo uiAtlasSprite;
    u8 pad_5054F0[0x8];
    s32 box_x0;
    s32 box_y0;
    s32 box_x1;
    s32 box_y1;
    u8 box_color_r;
    u8 box_color_g;
    u8 box_color_b;
    u8 box_color_a;
    u8 pad_50550C[0x1C];
    u8 cursor_color_r;
    u8 cursor_color_g;
    u8 cursor_color_b;
    u8 cursor_color_a;
    s32 unk_50552C;
    s32 unk_505530;
    u8 pad_505534[4];
    s16 scrollX;
    s16 scrollDirection;
    s32 slotIndex;
    s32 itemCount;
    s32 pageOffset;
    s32 currentThumbId;
    s8 activeBuffer;
    s8 bufferPending;
    s8 isInitialized;
    s8 dialogChoice;
    s16 uiX0[8];
    s16 uiY0[8];
    s16 uiX1[8];
    s16 uiY1[8];
    s8 uiMode[8];
    s32 flagBytePos;
    s32 flagBitPos;
    s32 flagSize;
    s32 dstSize;
    s32 srcSize;
    s32 chunkLimit;
    s32 dstPos;
    s32 srcPos;
    u8 itemStatus[0x100];
    u8 itemThumbIds[0x100];
    s8 slotFlags[6];
} GalleryContext;

/* Shared gallery globals */
extern u16 g_system_mute;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u32 g_cd_total_bytes_read;
extern s8 g_cd_retry_timer;
extern void *g_vram_load_buf;
extern u32 g_cd_last_read_size;
extern s32 g_sprite_queue_count;
extern s8 *g_font_glyph_buf;
extern void *g_dma_gif;
extern void *g_pad_dma_buf;
extern GalleryContext *g_gallery;
extern u32 g_cd_file_lba[3];
extern u32 g_cd_file_size[3];
extern u8 g_gif_buf[2][0x10000];
extern u64 g_gs_load_image[12];
extern u32 g_pad_trigger[4];
extern GlyphCacheEntry g_glyph_cache[0x401];

/* sys.c */
void gallery_reset_slot_states(void);
void gallery_exit_to_elf(s32 destination);

/* sound.c */
void sound_update_bgm_fade(void);
void sound_update(void);
void sound_init(void);
void sound_play_cursor_se(void);
void sound_play_page_se(void);
void sound_play_confirm_se(void);
void sound_play_se(s32 selection);
void sound_init_file_tables(void);
void sound_init_iop_rpc(void);

/* cd.c */
void cd_search_file(const char *path);
void cd_read_sync(void *destination, u32 byteCount, u32 startSector);
void cd_read_async(void *destination, s32 byteCount, u32 startSector);
void cd_load_file(void *destination, const char *path);

/* sprite.c */
void sprite_build_quad_packet(Qword *pkt, s32 startIndex, s32 count);
void sprite_flush_quads(void);
void sprite_queue_glyph(); /* (s16 x, s16 y, u16 textureId, u16 attributes, u16 scale) */
void sprite_build_rect_packet(Qword *packet, s32 firstEntry, s32 entryCount);
void sprite_flush_rects(void);
void sprite_queue_sjis_text(s32 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth);
void sprite_clear_queue(void);

/* font.c */
void font_build_gs_setup_packet(void *packet);
u64 sjis_to_jis(u64 shiftJis);
void font_init_clut_table(void);
void font_upload_clut(s32 paletteIndex);
void font_upload_alt_clut(s32 paletteIndex);
void font_init(void);
void font_upload_default_cluts(void);

/* tex_upload.c */
void tex_upload_step(void);
void tex_upload_reset(void);
void tex_upload_init_vram(void);
void tex_upload_clut_slot(u8 *destination, s32 mode, s32 blockCount);
void tex_upload_bitmap(s32 index);
void pad_update_vibration(void);
void vram_clear_all(void);

/* pad.c */
void pad_poll_hardware(void);
void pad_init_system(void);
void pad_update(void);
void pad_open_ports(void);

/* iop.c */
void iop_reboot_and_load_modules(void);

/* glyph_cache.c */
void glyph_cache_init(void);
s32 glyph_cache_lookup(u16 key);

/* main.c */
void gallery_load_font_files(void);
void gallery_main(void);
void gallery_run_loop(void);
void gallery_init_frame_gs(void);
void gallery_tick_and_render(void);
s32 gallery_state_exit(void);
s32 gallery_state_viewer(void);
s32 gallery_state_grid(void);
s32 gallery_state_fade_in(void);
s32 gallery_state_loading(void);
s32 gallery_load_ui_assets(void);
void gallery_draw_background(u8 alpha);
void gallery_draw_grid_and_ui(void);

/* bmp.c */
s32 bmp_upload_texture(void *tex, s16 tbp, s16 cbp, u8 *bmp, s32 x, s32 y);
void bmp_upload_clut(s16 destinationBase, const void *palette, s32 colorCount);
void bmp_draw_ascii_char(void *packet, s32 x, s32 y, u8 glyphIndex);

/* viewer.c */
void viewer_draw_yes_no_dialog(s32 selection, s32 centerX, s32 y, s32 spacing);
s32 viewer_update_and_draw(GalleryView *view, s32 mode);
void viewer_init_image(GalleryView *viewer, SpriteInfo *image, const char *title);
s32 viewer_update_grid_cursor(void *menu, void *input);

/* lzss.c */
s32 lzss_decompress_step(u8 *dst, u8 *src);
void lzss_draw_frame_overlay(void *frame);
void gallery_draw_solid_rect(s32 xStart, s32 yStart, s32 xEnd, s32 yEnd, s32 red, s32 green, s32 blue, s32 alpha, s32 layer);

#endif
