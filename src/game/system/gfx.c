#include "common.h"
#include "fade.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"
#include "glyph_cache.h"
#include "arcade_sprite.h"
#include "cd.h"
#include "gfx.h"
#include "system.h"
#ifdef DDPDOJ_PC
#include "pc_gs_game.h"
#endif

typedef struct {
    s32 interlace;
    s32 ffmode;
    s32 width;
    s32 height;
} VideoMode;

typedef struct {
    s32 x;
    s32 y;
    s32 u;
    s32 v;
} Vertex;

TexUploadInfo g_tex_upload_table[] = {
    { 0, 16, 0, 0, 256, 128 },
    { 1, 16, 0, 0, 256, 192 },
    { 0, 16, 0, 0, 1024, 512 },
    { 1, 8, 0, 0, 256, 192 },
    { 1, 8, 0, 0, 512, 256 },
    { 1, 8, 0, 0, 48, 416 },
#ifdef DEATH_LABEL
    { 1, 8, 0, 0, 512, 256 },
#endif
};

s16 g_default_palette[32] = {
    0x0000, 0x910A, 0xC2D9, 0xD39F, 0x8485, 0x8CC8, 0xBED9, 0xCF5D,
    0xBAB8, 0xAE34, 0xB276, 0xA1D1, 0xA5F2, 0xC71B, 0x994D, 0xFFFF,
};

/* Height of the stage map marker's travel per 1000 units of stage progress. */
s32 g_stage_map_scale[5] = { 440, 601, 851, 471, 388 };

/* Sprite size in 1/10000 for each of the 32 zoom steps (16 is 1:1). */
s32 g_sprite_zoom_table[32] = {
    0, 5005, 5338, 5671, 6004, 6337, 6670, 7003,
    7336, 7669, 8002, 8335, 8668, 9001, 9334, 9667,
    10000, 10333, 10666, 10999, 11332, 11665, 11998, 12331,
    12664, 12997, 13330, 13663, 13996, 14329, 14662, 14995,
};

VideoMode g_video_modes[12] = {
    { 0, 1, 448, 224 },
    { 0, 1, 448, 224 },
    { 1, 0, 384, 448 },
    { 1, 0, 384, 448 },
    { 0, 1, 448, 224 },
    { 0, 1, 448, 224 },
    { 0, 1, 640, 224 },
    { 0, 1, 640, 224 },
    { 1, 0, 512, 448 },
    { 1, 0, 512, 448 },
    { 0, 1, 640, 224 },
    { 0, 1, 640, 224 },
};

Vertex g_wallpaper_vertices[16] = {
    { 0x0, 0x0, 0x1CF0, 0x100 },
    { 0x500, 0x0, 0x1CF0, 0x600 },
    { 0x500, 0x1C00, 0x100, 0x600 },
    { 0x0, 0x1C00, 0x100, 0x100 },
    { 0x1300, 0x0, 0x1CF0, 0xA00 },
    { 0x1800, 0x0, 0x1CF0, 0xF00 },
    { 0x1800, 0x1C00, 0x100, 0xF00 },
    { 0x1300, 0x1C00, 0x100, 0xA00 },
    { 0x0, 0x0, 0x1CF0, 0x100 },
    { 0x900, 0x0, 0x1CF0, 0xA00 },
    { 0x900, 0x1C00, 0x100, 0xA00 },
    { 0x0, 0x1C00, 0x100, 0x100 },
    { 0x1700, 0x0, 0x1CF0, 0x600 },
    { 0x2000, 0x0, 0x1CF0, 0xF00 },
    { 0x2000, 0x1C00, 0x100, 0xF00 },
    { 0x1700, 0x1C00, 0x100, 0x600 },
};

extern s16 g_text_palette[];
extern s16 g_sprite_palette[];
extern s16 g_bg_palette[];
extern s16 g_clut_buf[];
extern s16 g_sprite_clut_buf[];
extern s16 g_bg_clut_buf[];

#ifndef DDPDOJ_PC
void splash_image_upload(void)
{
    g_tex_upload_tbp = 0x2240;
    switch (g_tex_upload_table[4].type) {
    case 0:
        sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, g_tex_upload_table[4].dbw, SCE_GS_PSMT4, g_tex_upload_table[4].x, g_tex_upload_table[4].y,
                             g_tex_upload_table[4].width, g_tex_upload_table[4].height);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, g_splash_file_buf + 0x80);
        sceGsSyncPath(0, 0);
        break;
    case 1:
        sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, g_tex_upload_table[4].dbw, SCE_GS_PSMT8, g_tex_upload_table[4].x, g_tex_upload_table[4].y,
                             g_tex_upload_table[4].width, g_tex_upload_table[4].height);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, g_splash_file_buf + 0x200);
        sceGsSyncPath(0, 0);
        break;
    case 2:
        break;
    }
}
#endif

extern u16 g_stage;

void stage_map_image_upload(void)
{
    g_tex_upload_tbp = 0x2240;
    sceGsSetDefLoadImage(&g_gs_load_image, 0x2240, g_tex_upload_table[5].dbw, SCE_GS_PSMT8, g_tex_upload_table[5].x, g_tex_upload_table[5].y,
                         g_tex_upload_table[5].width, g_tex_upload_table[5].height);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, g_stage_map_file_buf + g_stage * 0x4E00 + 0x200);
    sceGsSyncPath(0, 0);
}

void tex_upload(s32 index)
{
    s32 type;
    s32 chunkHeight;
    s32 remaining;
    s32 yOffset;
    s32 src;
    s32 src1;

    type = g_tex_upload_table[index].type;
    if (g_tex_upload_table[index].width != 0x400) {
        switch (type) {
            case 0:
                remaining = g_tex_upload_table[index].dbw;
                sceGsSetDefLoadImage(
                    &g_gs_load_image,
                    g_tex_upload_tbp,
                    remaining,
                    SCE_GS_PSMT4,
                    g_tex_upload_table[index].x,
                    g_tex_upload_table[index].y,
                    g_tex_upload_table[index].width,
                    g_tex_upload_table[index].height
                );
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, g_load_buf);
                sceGsSyncPath(0, 0);
                break;

            case 1:
                chunkHeight = g_tex_upload_table[index].height;
                sceGsSetDefLoadImage(
                    &g_gs_load_image,
                    g_tex_upload_tbp,
                    g_tex_upload_table[index].dbw,
                    SCE_GS_PSMT8,
                    g_tex_upload_table[index].x,
                    g_tex_upload_table[index].y,
                    g_tex_upload_table[index].width,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, g_load_buf);
                sceGsSyncPath(0, 0);
                break;

            case 2:
                break;
        }
        return;
    }

    switch (type) {
        case 0:
            remaining = g_tex_upload_table[index].height;
            yOffset = 0;
            src = 0;
        loop0:
            if (remaining > 0x100) {
                chunkHeight = 0x100;
            } else {
                chunkHeight = remaining;
            }
            sceGsSetDefLoadImage(
                &g_gs_load_image,
                g_tex_upload_tbp,
                g_tex_upload_table[index].dbw,
                SCE_GS_PSMT4,
                g_tex_upload_table[index].x,
                yOffset + g_tex_upload_table[index].y,
                0x400,
                chunkHeight
            );
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, g_load_buf + src);
            sceGsSyncPath(0, 0);
            remaining -= chunkHeight;
            src += 0x20000;
            yOffset += 0x100;
            if (remaining != 0) {
                goto loop0;
            } else {
                goto done;
            }

        case 1:
            remaining = g_tex_upload_table[index].height;
            yOffset = 0;
            src1 = 0;
            do {
                if (remaining > 0x80) {
                    chunkHeight = 0x80;
                } else {
                    chunkHeight = remaining;
                }
                sceGsSetDefLoadImage(
                    &g_gs_load_image,
                    g_tex_upload_tbp,
                    g_tex_upload_table[index].dbw,
                    SCE_GS_PSMT8,
                    g_tex_upload_table[index].x,
                    yOffset + g_tex_upload_table[index].y,
                    0x400,
                    chunkHeight
                );
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, g_load_buf + src1);
                sceGsSyncPath(0, 0);
                remaining -= chunkHeight;
                src1 += 0x20000;
                yOffset += 0x80;
            } while (remaining != 0);
            break;

        case 2:
            break;
    }

done:
    return;
}


void clut_upload(u8 *src, s32 mode, s32 count) {
    s32 i;
    s32 offset;
    s32 off2;

    sceGsSyncPath(0, 0);
    switch (mode) {
    case 0:
        if (0 < count) {
            i = 0;
            offset = 0;
            do {
                sceGsSetDefLoadImage(&g_gs_load_image, g_clut_upload_cbp, 1, SCE_GS_PSMCT16, 0, 0, 8, 2);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, src + offset);
                sceGsSyncPath(0, 0);
                g_clut_upload_cbp += 1;
                i++;
                offset += 0x80;
            } while (i < count);
        }
        break;
    case 1:
        if (0 < count) {
            i = 0;
            off2 = 0;
            do {
                sceGsSetDefLoadImage(&g_gs_load_image, g_clut_upload_cbp, 1, SCE_GS_PSMCT16, 0, 0, 16, 16);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, src + off2);
                sceGsSyncPath(0, 0);
                g_clut_upload_cbp += 4;
                i++;
                off2 += 0x80;
            } while (i < count);
        }
        break;
    case 2:
        break;
    }
}


void tex_load_common(void) {
    g_tex_upload_tbp = 0x1E40;
    cd_read_sync(g_load_buf, g_data_files[DATA_FILE_COMMON_TEX].size, g_data_files[DATA_FILE_COMMON_TEX].lba);
    tex_upload(2);
    printf("tex load end\n");
}

extern void music_stop(void);
extern u8 g_stage_load_state;
extern s16 g_loaded_stage;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern s32 g_stage_unpack_state;
extern u8 g_bg_tile_pixels[];
extern s32 g_bg_tile_offsets[];

void stage_load_step(void) {
    u8 *buffer;

    buffer = g_stage_sprite_buf + 0x5DC800;
    if (g_stage != g_loaded_stage) {
    switch (g_stage_load_state) {
    case 0:
#ifdef DEATH_LABEL
        printf("stage load start\n");
#else
        printf("stage load start[%d]\n", g_stage);
#endif
        music_stop();
        glyph_cache_init();
        g_stage_load_state++;
        break;
    case 1:
        g_stage_load_state++;
        if (g_cd_async_state != 0) {
            sceCdBreak();
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        break;
    case 2:
        cd_read_async((u8 *)g_bg_tile_offsets, g_stage_bg_files[g_stage * 2].size, g_stage_bg_files[g_stage * 2].lba);
        if (g_cd_async_busy != 0) {
            break;
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        g_stage_load_state++;
    case 3:
        cd_read_async(g_bg_tile_pixels, g_stage_bg_files[(u32)(g_stage * 2 + 1)].size,
                      g_stage_bg_files[(u32)(g_stage * 2 + 1)].lba);
        if (g_cd_async_busy != 0) {
            break;
        }
        g_cd_async_state = 0;
        g_cd_async_busy = 1;
        g_stage_load_state++;
    case 4:
        cd_read_async(buffer, g_data_files[(u32)(g_stage + DATA_FILE_STAGE_SPRITES)].size,
                      g_data_files[(u32)(g_stage + DATA_FILE_STAGE_SPRITES)].lba);
        if (g_cd_async_busy != 0) {
            break;
        }
        g_stage_unpack_state = 0;
        g_cd_async_busy = 1;
        g_cd_async_state = 0;
        g_stage_load_state++;
        break;
    case 5:
        switch (g_stage_unpack_state) {
        case 0:
            stage_sprite_unpack_begin(0x14000);
            g_stage_unpack_state++;
            break;
        }
        if (stage_sprite_unpack_step() != 0) {
            g_stage_load_state++;
        }
        break;
    case 6:
        printf("stage load end\n");
        g_stage_load_state = 0;
        g_loaded_stage = g_stage;
        break;
    case 7:
        break;
    }
    } else {
        glyph_cache_init();
        g_stage_load_state = 0;
    }
}

extern s16 g_default_text_palette[];

extern u8 g_text_layer[];

extern u8 g_stage_map_active;

void clut_upload_defaults(void)
{
    s16 *source;
    s16 *palette;
    s32 colorIndex;

    source = g_default_palette;
    palette = g_clut_buf;
    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        palette[colorIndex] = *source++;
    }
    g_clut_upload_cbp = 0x3832;
    clut_upload((u8 *)g_clut_buf, 0, 1);

    source = g_default_text_palette;
    palette = g_clut_buf;
    for (colorIndex = 0; colorIndex < 15; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    g_clut_upload_cbp = 0x3830;
    clut_upload((u8 *)g_clut_buf, 0, 1);

    source = (s16 *)palette_white;
    palette = g_clut_buf;
    for (colorIndex = 0; colorIndex < 31; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    g_clut_upload_cbp = 0x383A;
    clut_upload((u8 *)g_clut_buf, 1, 1);
}


/* The game logic keeps its palettes in the arcade layout; these copy them out with the alpha bit set on every
   colour but the last one of a palette, and send them to the GS. */
void text_palette_upload(void) {
    s32 i;
    s32 colorIndex;
    s16 *source;
    s16 *palette;

    source = g_text_palette;
    palette = g_clut_buf;
    for (i = 0; i < 16; i++) {
        for (colorIndex = 0; colorIndex < 15; colorIndex++) {
            palette[colorIndex] = *source++ | 0x8000;
        }
        palette[colorIndex] = *source++;
        palette += 0x40;
    }
    g_clut_upload_cbp = 0x37B0;
    clut_upload((u8 *)g_clut_buf, 0, 16);
}

/* 32-colour palettes go out in the GS's CSM1 order (entries 8-15 and 16-23 swapped). */
void sprite_palette_upload(void) {
    s32 i;
    s16 *src;
    s16 *dst;

    src = g_sprite_palette;
    dst = g_sprite_clut_buf;
    i = 0;
    do {
        i++;
        dst[0] = src[0] | 0x8000;
        dst[1] = src[1] | 0x8000;
        dst[2] = src[2] | 0x8000;
        dst[3] = src[3] | 0x8000;
        dst[4] = src[4] | 0x8000;
        dst[5] = src[5] | 0x8000;
        dst[6] = src[6] | 0x8000;
        dst[7] = src[7] | 0x8000;
        dst[16] = src[8] | 0x8000;
        dst[17] = src[9] | 0x8000;
        dst[18] = src[10] | 0x8000;
        dst[19] = src[11] | 0x8000;
        dst[20] = src[12] | 0x8000;
        dst[21] = src[13] | 0x8000;
        dst[22] = src[14] | 0x8000;
        dst[23] = src[15] | 0x8000;
        dst[8] = src[16] | 0x8000;
        dst[9] = src[17] | 0x8000;
        dst[10] = src[18] | 0x8000;
        dst[11] = src[19] | 0x8000;
        dst[12] = src[20] | 0x8000;
        dst[13] = src[21] | 0x8000;
        dst[14] = src[22] | 0x8000;
        dst[15] = src[23] | 0x8000;
        dst[24] = src[24] | 0x8000;
        dst[25] = src[25] | 0x8000;
        dst[26] = src[26] | 0x8000;
        dst[27] = src[27] | 0x8000;
        dst[28] = src[28] | 0x8000;
        dst[29] = src[29] | 0x8000;
        dst[30] = src[30] | 0x8000;
        dst[31] = src[31];
        src += 32;
        dst += 64;
    } while (i < 32);
    g_clut_upload_cbp = 0x3730;
    clut_upload((u8 *)g_sprite_clut_buf, 1, 32);
}

void bg_palette_upload(void) {
    s32 i;
    s16 *src;
    s16 *dst;

    src = g_bg_palette;
    dst = g_bg_clut_buf;
    i = 0;
    do {
        i++;
        dst[0] = src[0] | 0x8000;
        dst[1] = src[1] | 0x8000;
        dst[2] = src[2] | 0x8000;
        dst[3] = src[3] | 0x8000;
        dst[4] = src[4] | 0x8000;
        dst[5] = src[5] | 0x8000;
        dst[6] = src[6] | 0x8000;
        dst[7] = src[7] | 0x8000;
        dst[16] = src[8] | 0x8000;
        dst[17] = src[9] | 0x8000;
        dst[18] = src[10] | 0x8000;
        dst[19] = src[11] | 0x8000;
        dst[20] = src[12] | 0x8000;
        dst[21] = src[13] | 0x8000;
        dst[22] = src[14] | 0x8000;
        dst[23] = src[15] | 0x8000;
        dst[8] = src[16] | 0x8000;
        dst[9] = src[17] | 0x8000;
        dst[10] = src[18] | 0x8000;
        dst[11] = src[19] | 0x8000;
        dst[12] = src[20] | 0x8000;
        dst[13] = src[21] | 0x8000;
        dst[14] = src[22] | 0x8000;
        dst[15] = src[23] | 0x8000;
        dst[24] = src[24] | 0x8000;
        dst[25] = src[25] | 0x8000;
        dst[26] = src[26] | 0x8000;
        dst[27] = src[27] | 0x8000;
        dst[28] = src[28] | 0x8000;
        dst[29] = src[29] | 0x8000;
        dst[30] = src[30] | 0x8000;
        dst[31] = src[31];
        src += 32;
        dst += 64;
    } while (i < 32);
    g_clut_upload_cbp = 0x36B0;
    clut_upload((u8 *)g_bg_clut_buf, 1, 32);
}

#ifndef DDPDOJ_PC
#include "splash_draw.inc.h"
#endif

extern s32 g_stage_map_unused_b;
extern s32 g_stage_map_unused_a;
extern s32 g_stage_map_state;
extern s32 g_stage_map_marker_step;
extern s32 g_stage_map_marker_level;
extern s32 g_stage_map_alpha;

void stage_map_reset(void) {
    g_stage_map_active = 0;
    g_stage_map_marker_level = 0x80;
    g_stage_map_state = 0;
    g_stage_map_marker_step = 1;
    g_stage_map_alpha = 0;
    g_stage_map_unused_a = 0;
    g_stage_map_unused_b = 0;
    g_stage_map_progress = 0;
}


void stage_map_show(void) {
    stage_map_reset();
    g_stage_map_alpha = 0;
    g_stage_map_active = 1;
    g_stage_map_state = 1;
}

void stage_map_hide(void) {
    g_stage_map_active = 1;
    g_stage_map_state = 2;
    g_stage_map_alpha = 0x80;
}

extern u8 g_stage_map_enabled;
extern u8 g_paused;

void stage_map_update(void) {
    s32 level;
    s32 top;
    s32 h;

    if (g_stage_map_active == 0) {
        return;
    }
    switch (g_stage_map_state) {
    case 0:
        break;
    case 1:
        g_stage_map_alpha += 8;
        if (g_stage_map_alpha >= 0x80) {
            g_stage_map_state = 3;
            g_stage_map_alpha = 0x80;
        }
        break;
    case 2:
        g_stage_map_alpha -= 8;
        if (g_stage_map_alpha <= 0) {
            g_stage_map_alpha = 0;
            g_stage_map_state = 0;
            g_stage_map_active = 0;
        }
        break;
    case 3:
        break;
    }
    if (g_paused == 0) {
        g_stage_map_marker_level += g_stage_map_marker_step;
    }
    if (g_stage_map_marker_step >= 0) {
        if (g_stage_map_marker_level >= 0xFF) {
            g_stage_map_marker_level = 0xFF;
            g_stage_map_marker_step = -1;
        }
    } else if (g_stage_map_marker_level <= 0x80) {
        g_stage_map_marker_level = 0x80;
        g_stage_map_marker_step = 1;
    }
    if ((g_screen_mode == 2 || g_screen_mode == 3) && g_stage_map_alpha != 0 && g_stage_map_enabled != 0) {
        stage_map_draw();
        level = g_stage_map_progress * g_stage_map_scale[g_stage] / 1000;
        level += 2;
        if (level >= 0x170) {
            level = 0x170;
        }
        top = 0x190 - level;
        h = top - 0x20;
        if (h > 0) {
            gfx_draw_color_box(0x188, -0x50, 0x20, h, 12, g_stage_map_alpha, 1, 1, 1);
        }
        gfx_draw_color_box(0x188, top - 0x50, 0x20, 2, 12, g_stage_map_alpha, g_stage_map_marker_level, 0, 0);
        gfx_draw_color_box(0x188, top - 0x70, 0x20, 2, 12, g_stage_map_alpha, g_stage_map_marker_level, 0, 0);
        gfx_draw_color_box(0x188, top - 0x70, 2, 0x20, 12, g_stage_map_alpha, g_stage_map_marker_level, 0, 0);
        gfx_draw_color_box(0x1A6, top - 0x70, 2, 0x20, 12, g_stage_map_alpha, g_stage_map_marker_level, 0, 0);
    }
}




void stage_map_draw(void) {
    stage_map_image_upload();
    g_quad_queue[0].u[0] = 0;
    g_quad_queue[0].z = 0xA;
    g_quad_queue[0].tbp = 0x2240;
    g_quad_queue[0].mode = 1;
    g_quad_queue[0].cbp = 0x3838;
    g_quad_queue[0].color = 0x80;
    g_quad_queue[0].x[0] = 0x180;
    g_quad_queue[0].y[0] = -0x58;
    g_quad_queue[0].x[1] = 0x1B0;
    g_quad_queue[0].y[1] = 0x148;
    g_quad_queue[0].u[1] = 0x30;
    g_quad_queue[0].v[1] = 0x1A0;
    g_quad_queue[0].v[0] = 0;
    g_quad_queue[0].alpha = g_stage_map_alpha;
    g_quad_count = 1;
    quad_flush();
}

#ifndef DEATH_LABEL
#pragma push
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off


void text_layer_clear_edge_top(void) {
    s32 i;
    u32 *p;
    s32 row;
    s32 x1;
    s32 x2;
    s32 idx;

    i = 0;
    row = 0;
    do {
        x1 = 54;
        p = (u32 *)g_text_layer;
        p += x1 + row;
        *p = 0;
        x2 = 55;
        idx = x2 + row;
        i++;
        row += 64;
        p = (u32 *)g_text_layer;
        p += idx;
        *p = 0;
    } while (i < 14);
}

#pragma pop
#pragma pop
#endif

#ifndef DEATH_LABEL
#pragma push
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void text_layer_clear_edge_bottom(void) {
    s32 i;
    u32 *p;
    s32 row;
    s32 x1;
    s32 x2;
    s32 idx;

    i = 14;
    row = 0x380;
    do {
        x1 = 54;
        p = (u32 *)g_text_layer;
        p += x1 + row;
        *p = 0;
        x2 = 55;
        idx = x2 + row;
        i++;
        row += 64;
        p = (u32 *)g_text_layer;
        p += idx;
        *p = 0;
    } while (i < 27);
}

#pragma pop
#pragma pop
#endif


void text_layer_draw(void) {
    s32 y;
    u32 *p = (u32 *)g_text_layer;
    s32 x;

    g_quad_count = 0;
    for (y = 0; y < 32; y++) {
        for (x = 0; x < 64; x++) {
            reg_d0.w = *p++;
            if (reg_d0.w != 0xC0000000 && reg_d0.w != 0) {
                text_layer_queue_tile(x, y);
            }
        }
    }
    quad_flush();
}

#pragma push
#pragma opt_propagation off


void text_layer_queue_tile(s32 arg0, s32 arg1) {
    s32 x;
    s32 y;
    s32 code;
    s32 n;
    s32 u;
    s32 v;
    s32 palette;

    n = g_quad_count;
    x = arg0 * 8;
    y = arg1 * 8;
    palette = (reg_d0.h[0] & 0x3F) >> 1;
    code = reg_d0.h[1] & 0x1FFF;
    u = (code % 126 + 1) * 8;
    v = (code / 126 + 1) * 8;
    g_quad_queue[n].z = 0x14;
    g_quad_queue[n].alpha = 0x80;
    g_quad_queue[n].tbp = 0x1E40;
    g_quad_queue[n].mode = 0;
    g_quad_queue[n].cbp = palette + 0x37B0;
    g_quad_queue[n].color = 0x80;
    g_quad_queue[n].x[0] = x - 1;
    g_quad_queue[n].y[0] = y;
    g_quad_queue[n].x[1] = x + 7;
    g_quad_queue[n].y[1] = y + 8;
    switch ((reg_d0.h[0] >> 6) & 3) {
    case 0:
        g_quad_queue[n].u[0] = u;
        g_quad_queue[n].v[0] = v;
        g_quad_queue[n].u[1] = u + 8;
        g_quad_queue[n].v[1] = v + 8;
        break;
    case 1:
        g_quad_queue[n].u[0] = u + 8;
        g_quad_queue[n].v[0] = v;
        g_quad_queue[n].u[1] = u;
        g_quad_queue[n].v[1] = v + 8;
        break;
    case 2:
        g_quad_queue[n].u[0] = u;
        g_quad_queue[n].v[0] = v + 8;
        g_quad_queue[n].u[1] = u + 8;
        g_quad_queue[n].v[1] = v;
        break;
    case 3:
        g_quad_queue[n].u[0] = u + 8;
        g_quad_queue[n].v[0] = v + 8;
        g_quad_queue[n].u[1] = u;
        g_quad_queue[n].v[1] = v;
        break;
    }
    g_quad_count = n + 1;
}
#pragma pop

extern s16 g_bg_scroll_x;
extern u8 g_bg_layer[];
void bg_layer_draw(void) {
    s32 var_s0;
    s32 var_s1;
    s32 temp_s2;
    s32 var_s3;
    u8 *var_s4;

    var_s4 = (u8 *)(g_bg_layer);
    var_s1 = 0;
    g_quad_count = 0;
    temp_s2 = g_bg_scroll_x & 0x7FF;
    do {
        var_s3 = temp_s2 / 32;
        for (var_s0 = 0; var_s0 < 0xF; var_s0++) {
            reg_d0.w = *(u32 *)(var_s4 + (var_s3 * 4));
            if ((reg_d0.w != 0xC0000000) && (reg_d0.w != 0)) {
                bg_layer_queue_tile(var_s0, var_s1);
            }
            var_s3++;
            var_s3 &= 0x3F;
        }
        var_s1 += 1;
        var_s4 += 0x100;
    } while (var_s1 < 9);
    quad_flush();
}


extern s16 g_bg_scroll_y;

void bg_layer_queue_tile(s32 col, s32 row) {
    s32 uploads;
    GlyphCacheEntry *cache;
    s32 u;
    s32 palette;
    s32 key;
    s32 n;
    s32 slot;
    s32 v;
    s32 x;
    s32 y;
    u32 *src;
    u32 *dst;
    s32 out;
    s32 in;
    u32 word;
    u32 fill;
    s32 count;

    uploads = 0;
    cache = g_glyph_cache_sub;
    x = g_bg_scroll_x & 0x1F;
    x *= -1;
    y = -g_bg_scroll_y;
    x += col * 32;
    y += row * 32;
    palette = (reg_d0.h[0] & 0x3F) >> 1;
    key = reg_d0.h[1] & 0x1FFF;
    n = g_quad_count;
    slot = glyph_cache_sub_lookup(key);
    if (slot & 0x8000) {
        slot &= 0x7FFF;
        u = cache[slot].x;
        v = cache[slot].y;
        sceGsSetDefLoadImage(&g_gs_load_image, 0x1A40, 8, SCE_GS_PSMT8, u, v, 32, 32);
        FlushCache(0);
        out = 0;
        in = 0;
        dst = g_image_unpack_buf;
        src = (u32 *)(g_bg_tile_pixels + g_bg_tile_offsets[key]);
        if (!(src[0] & 0x80000000)) {
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, src);
            sceGsSyncPath(0, 0);
        } else {
            do {
                fill = src[in++];
                word = fill;
                if (!(word & 0x40000000)) {
                    dst[out++] = word & 0x1F1F1F1F;
                } else {
                    count = word & 0x3FFF;
                    fill = src[in++] & 0x1F1F1F1F;
                    for (; count >= 0; count--) {
                        dst[out++] = fill;
                    }
                }
            } while (out < 32 * 32 / 4);
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, dst);
            sceGsSyncPath(0, 0);
        }
        uploads++;
    } else {
        u = cache[slot & 0x7FFF].x;
        v = cache[slot & 0x7FFF].y;
    }
    g_quad_queue[n].z = 1;
    g_quad_queue[n].alpha = 0x80;
    g_quad_queue[n].tbp = 0x1A40;
    g_quad_queue[n].mode = 1;
    g_quad_queue[n].cbp = palette * 4 + 0x36B0;
    g_quad_queue[n].color = 0x80;
    g_quad_queue[n].x[0] = x;
    g_quad_queue[n].y[0] = y;
    g_quad_queue[n].x[1] = x + 32;
    g_quad_queue[n].y[1] = y + 32;
    g_quad_queue[n].u[0] = u;
    g_quad_queue[n].v[0] = v;
    g_quad_queue[n].u[1] = u + 32;
    g_quad_queue[n].v[1] = v + 32;
    g_quad_count = n + 1;
    if (uploads != 0) {
        sceGsSyncPath(0, 0);
    }
}


void quad_flush(void)
{
    u8 *packet;
    s32 bufferIndex;
    s32 firstEntry;
    s32 batchCount;
    s32 remainingEntries;

    if (g_quad_count == 0) {
        return;
    }
    bufferIndex = 0;
    firstEntry = 0;
    while ((remainingEntries = g_quad_count) != 0) {
        if (remainingEntries >= 6) {
            batchCount = 6;
        } else {
            batchCount = remainingEntries;
        }

        packet = g_gif_buf[bufferIndex];
        quad_build_packet((Qword *)packet, firstEntry, batchCount);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        SEND_DMA_CHAIN(g_dma_gif, packet, sizeof(g_gif_buf[0]));

        bufferIndex ^= 1;
        firstEntry += batchCount;
        g_quad_count -= batchCount;
    }
    sceGsSyncPath(0, 0);
}

void quad_build_packet(Qword *pkt, s32 first, s32 count) {
    s32 qwc;
    s32 i;
    s32 j;

    qwc = 1;
    pkt[0].q = 0;
    pkt[0].w[0] = 0x10000000;
    for (i = 0; i < count; i++) {
        s32 x[4];
        s32 y[4];
        s32 u[4];
        s32 v[4];
        s32 z;
        s32 alpha;
        u32 color;
        s32 tbp;
        s32 cbp;
        s32 mode;

        x[0] = g_quad_queue[first].x[0];
        x[1] = g_quad_queue[first].x[1];
        x[2] = g_quad_queue[first].x[2];
        x[3] = g_quad_queue[first].x[3];
        y[0] = g_quad_queue[first].y[0];
        y[1] = g_quad_queue[first].y[1];
        y[2] = g_quad_queue[first].y[2];
        y[3] = g_quad_queue[first].y[3];
        u[0] = g_quad_queue[first].u[0];
        u[1] = g_quad_queue[first].u[1];
        u[2] = g_quad_queue[first].u[2];
        u[3] = g_quad_queue[first].u[3];
        v[0] = g_quad_queue[first].v[0];
        v[1] = g_quad_queue[first].v[1];
        v[2] = g_quad_queue[first].v[2];
        v[3] = g_quad_queue[first].v[3];
        z = g_quad_queue[first].z;
        alpha = g_quad_queue[first].alpha;
        color = g_quad_queue[first].color;
        cbp = g_quad_queue[first].cbp;
        tbp = g_quad_queue[first].tbp;
        mode = g_quad_queue[first].mode;
        first++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1);
        pkt[qwc].d[1] = SCE_GIF_PACKED_AD;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEXFLUSH;
        qwc++;

        switch (mode) {
        case 0:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        case 1:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 8, SCE_GS_PSMT8, 9, 9, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        case 3:
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(tbp, 16, SCE_GS_PSMT8, 10, 9, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
            break;
        }
        pkt[qwc].d[1] = SCE_GS_TEX0_1;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEX1_1;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_CLAMP_1;
        qwc++;

        pkt[qwc].d[0] = 0x3000F;
        pkt[qwc].d[1] = SCE_GS_TEST_1;
        qwc++;

        pkt[qwc].d[0] = (u64)0x80 << 32;
        pkt[qwc].d[1] = SCE_GS_TEXA;
        qwc++;

        pkt[qwc].d[0] = 0x44;
        pkt[qwc].d[1] = SCE_GS_ALPHA_1;
        qwc++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 0, 1, 0, 0), SCE_GIF_PACKED, 6);
        pkt[qwc].d[1] = 0x431431;
        qwc++;

        for (j = 0; j < 2; j++) {
            pkt[qwc].w[0] = color;
            pkt[qwc].w[1] = color;
            pkt[qwc].w[2] = color;
            pkt[qwc].w[3] = alpha;
            qwc++;

            pkt[qwc].w[0] = u[j] << 4;
            pkt[qwc].w[1] = v[j] << 4;
            pkt[qwc].w[2] = 0;
            pkt[qwc].w[3] = 0;
            qwc++;

            pkt[qwc].w[0] = ((x[j] + 0x700) << 4) + 8;
            pkt[qwc].w[1] = ((y[j] + 0x790) << 4) + 8;
            pkt[qwc].w[2] = z << 4;
            pkt[qwc].w[3] = 0;
            qwc++;
        }
    }
    pkt[qwc].q = 0;
    pkt[qwc].w[0] = 0x70000000;
    pkt[0].w[0] = (qwc - 1) | 0x10000000;
}



void render_target_init(RenderTarget *tex, void *buffer, s32 tbp, u32 width, u32 height) {
    sceGifPacket packet;
    u32 n;
    u32 m;
    s32 x;
    s32 y;

    n = 2;
    m = 2;
    tex->width = width;
    tex->height = height;
    tex->tbp = tbp;
    tex->psm = 2;
#ifdef DDPDOJ_PC
    pc_gs_game_target(tbp, width, height);
#endif
    tex->tw = 1;
    while (width > n) {
        tex->tw++;
        n <<= 1;
    }
    tex->th = 1;
    while (height > m) {
        tex->th++;
        m <<= 1;
    }
    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(5, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)(tex->tbp >> 5) | ((u64)((tex->width + 63) >> 6) << 16) | ((u64)tex->psm << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, (u64)((0x800 - (tex->width >> 1)) << 4) | ((u64)((0x800 - (tex->height >> 1)) << 4) << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(tex->width - 1) << 16) | ((u64)(tex->height - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, 0x3000F);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, (u64)1 << 32);
    sceGifPkAddGsData(&packet, 0x4E);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, (u64)0x3F800000 << 32);
    x = (0x800 - (tex->width >> 1)) << 4;
    y = (0x800 - (tex->height >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    x += tex->width << 4;
    y += tex->height << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void render_target_begin(RenderTarget *tex, void *buffer) {
    sceGifPacket packet;
    s32 x;
    s32 y;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(6, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)(tex->tbp >> 5) | ((u64)((tex->width + 63) >> 6) << 16) | ((u64)tex->psm << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, (u64)((0x800 - (tex->width >> 1)) << 4) | ((u64)((0x800 - (tex->height >> 1)) << 4) << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(tex->width - 1) << 16) | ((u64)(tex->height - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, 0x3000F);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, (u64)1 << 32);
    sceGifPkAddGsData(&packet, 0x4E);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, ((u64)0x80 << 24) | ((u64)0x3F800000 << 32));
    x = (0x800 - (tex->width >> 1)) << 4;
    y = (0x800 - (tex->height >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    x += tex->width << 4;
    y += tex->height << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)y << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

extern s32 g_frame_counter;

void framebuffer_begin_present(void *buffer) {
    sceGifPacket packet;
    s32 index;
    s32 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(6, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    index = (g_frame_counter + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)&g_gs_dbuff.disp[index].dispfb & 0x1FF) | ((u64)((g_screen_width + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x800 - (u64)(g_screen_width >> 1)) << 4) | ((u64)0x7200 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(g_screen_width - 1) << 16) | ((u64)0x1BF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    if (g_screen_mode == 2) {
        sceGifPkAddGsData(&packet, 0);
    } else {
        sceGifPkAddGsData(&packet, 0x60);
    }
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, 0x3000E);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x3F);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 4));
    sceGifPkAddGsData(&packet, 0x5510);
    sceGifPkAddGsData(&packet, 0x106);
    sceGifPkAddGsData(&packet, 0x80000000ULL | ((u64)0x3F800000 << 32));
    x = (0x800 - (g_screen_width >> 1)) << 4;
    sceGifPkAddGsData(&packet, (u64)x | 0x72000000);
    x += g_screen_width << 4;
    sceGifPkAddGsData(&packet, (u64)x | ((u64)0x8E00 << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}


void render_target_present(RenderTarget *tex, void *buffer) {
    sceGifPacket packet;
    s32 x;
    s64 right;
    s64 left;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(2, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, ((u64)(g_screen_width - 1) << 16) | ((u64)0x1BE << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, SCE_GS_SET_TEX0(tex->tbp, tex->width >> 6, tex->psm, tex->tw, tex->th, 1, 0, 0, 0, 0, 0, 0));
    sceGifPkAddGsData(&packet, SCE_GS_TEX0_1);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
    sceGifPkAddGsData(&packet, 0x5353535310ULL);
    sceGifPkAddGsData(&packet, 0x115);
    sceGifPkAddGsData(&packet, 0x80808080 | ((u64)0x3F800000 << 32));
    x = ((0x800 - g_screen_width / 2) << 4) + 8;
    x += g_screen_margin << 4;
    sceGifPkAddGsData(&packet, 0x1101C00);
    left = x;
    sceGifPkAddGsData(&packet, left | 0x72000000);
    sceGifPkAddGsData(&packet, 0xF101C00);
    right = x + 0xE00;
    sceGifPkAddGsData(&packet, right | 0x72000000);
    sceGifPkAddGsData(&packet, 0xF100000);
    sceGifPkAddGsData(&packet, right | ((u64)0x8E00 << 16));
    sceGifPkAddGsData(&packet, 0x1100000);
    sceGifPkAddGsData(&packet, left | ((u64)0x8E00 << 16));
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}



void render_target_present_wide(RenderTarget *tex, void *buffer) {
    sceGifPacket packet;
    s32 index;
    s32 x;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    if (g_screen_mode == 4) {
        sceGifPkAddGsData(&packet, 0);
    } else {
        sceGifPkAddGsData(&packet, 0x60);
    }
    sceGifPkAddGsData(&packet, 0x14);
    sceGifPkAddGsData(&packet, 0x3000E);
    sceGifPkAddGsData(&packet, 0x47);
    sceGifPkAddGsData(&packet, 0);
    sceGifPkAddGsData(&packet, 0x3F);
    index = (g_frame_counter + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)&g_gs_dbuff.disp[index].dispfb & 0x1FF) | ((u64)((g_screen_width + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x800 - (u64)(g_screen_width >> 1)) << 4) | ((u64)0x7900 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, ((u64)(g_screen_margin + 0x1BF) << 16) | 1 | ((u64)1 << 32) | ((u64)0xDF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkAddGsData(&packet, (u64)tex->tbp | ((u64)(tex->width >> 6) << 14) | ((u64)tex->psm << 20) | ((u64)tex->tw << 26) | ((u64)tex->th << 30) | ((u64)1 << 34));
    sceGifPkAddGsData(&packet, 6);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
    sceGifPkAddGsData(&packet, 0x5353535310ULL);
    sceGifPkAddGsData(&packet, 0x115);
    sceGifPkAddGsData(&packet, 0x80808080ULL | ((u64)0x3F800000 << 32));
    x = ((0x800 - g_screen_width / 2) << 4) + 8;
    x += (g_screen_margin + 0x1B0) << 4;
    sceGifPkAddGsData(&packet, 0x1101C10);
    sceGifPkAddGsData(&packet, (u64)x | 0x79080000);
    sceGifPkAddGsData(&packet, 0xF101C10);
    sceGifPkAddGsData(&packet, (u64)x | 0x87080000);
    sceGifPkAddGsData(&packet, 0xF100010);
    x -= 0x1A00;
    sceGifPkAddGsData(&packet, (u64)x | 0x87080000);
    sceGifPkAddGsData(&packet, 0x1100010);
    sceGifPkAddGsData(&packet, (u64)x | 0x79080000);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void framebuffer_begin(void *buffer) {
    sceGifPacket packet;
    s32 index;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(3, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    index = (g_frame_counter + 1) & 1;
    sceGifPkAddGsData(&packet, ((u64)*(u16 *)&g_gs_dbuff.disp[index].dispfb & 0x1FF) | ((u64)((g_screen_width + 63) >> 6) << 16) | ((u64)2 << 24));
    sceGifPkAddGsData(&packet, 0x4C);
    sceGifPkAddGsData(&packet, ((0x700 - (u64)g_screen_margin) << 4) | ((u64)0x7900 << 32));
    sceGifPkAddGsData(&packet, 0x18);
    sceGifPkAddGsData(&packet, (u64)(g_screen_margin + 1) | ((u64)(g_screen_margin + 0x1BF) << 16) | ((u64)1 << 32) | ((u64)0xDF << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}


void display_set_offset(s32 x, s32 y) {
    s32 dx;
    s32 dy;
    s32 base_x;
    s32 base_y;

    switch (g_screen_width) {
    case 0x180:
        base_x = 0x21E;
        base_y = 0x32;
        break;
    case 0x1C0:
        base_x = 0x21C;
        x = (s8)(x * 4);
        base_y = 0x19;
        break;
    case 0x200:
        base_x = 0x256;
        base_y = 0x32;
        break;
    case 0x280:
        base_x = 0x27C;
        x = (s8)(x * 4);
        base_y = 0x19;
        break;
    }
    dy = base_y + (s8)y;
    dx = base_x + (s8)(x * 2);
    g_gs_dbuff.disp[0].display.DX = dx;
    g_gs_dbuff.disp[0].display.DY = dy;
    g_gs_dbuff.disp[1].display.DX = dx;
    g_gs_dbuff.disp[1].display.DY = dy;
}

extern s8 g_display_offset_y;
extern s8 g_display_offset_x;
extern u8 g_screen_wide;

void display_reset(void) {
    VideoMode *mode;

    mode = &g_video_modes[g_screen_mode + g_screen_wide * 6];
#ifdef DDPDOJ_PC
    g_screen_width = mode->width;
    g_screen_margin = (g_screen_width - (mode->interlace ? 0xE0 : 0x1C0)) >> 1;
    g_gs_dbuff.disp[0].dispfb.FBP = 0;
    g_gs_dbuff.disp[1].dispfb.FBP =
        ((mode->width + 63) / 64) * ((mode->height + 31) / 32);
    pc_gs_game_display(mode->width, mode->height, g_screen_wide != 0);
#else
    sceGsResetGraph(0, (s16)mode->interlace, 2, (s16)mode->ffmode);
    g_screen_width = mode->width;
    if (mode->interlace == 0) {
        sceGsSetDefDBuffDc(&g_gs_dbuff, 2, (s16)mode->width, (s16)mode->height, 1, 0x31, 1);
        g_screen_margin = (g_screen_width - 0x1C0) >> 1;
    } else {
        sceGsSetDefDBuffDc(&g_gs_dbuff, 2, (s16)mode->width, (s16)mode->height, 1, 0x31, 0);
        g_screen_margin = (g_screen_width - 0xE0) >> 1;
        g_gs_dbuff.disp[0].dispfb.FBP = 0;
        g_gs_dbuff.disp[1].dispfb.FBP = ((((mode->width + 63) / 64 * 64) * ((mode->height + 31) / 32 * 32)) >> 11) / 2;
    }
    display_set_offset(g_display_offset_x, g_display_offset_y);
    FlushCache(0);
    sceGsSyncV(0);
    sceGsPutDrawEnv(&g_gs_dbuff.giftag0);
    sceGsSyncPath(0, 0);
    sceGsPutDrawEnv(&g_gs_dbuff.giftag1);
    sceGsSyncPath(0, 0);
#endif
}


void wallpaper_load(s32 index, u16 *src) {
    s32 n;
    s32 i;
    u32 *data;
    s32 word;
    s16 w;
    s16 h;
    s32 row;
    u16 *dst;
    u32 *buf;
    u32 fill;

    n = 0;
    i = 0;
    buf = g_image_unpack_buf;
    w = g_sprite_images[index].w;
    h = g_sprite_images[index].h;
    data = (u32 *)(g_sprite_pixels + g_sprite_images[index].offset);
    if (!(data[0] & 0x80000000)) {
        sceGsSetDefLoadImage(&g_gs_load_image, 0x16C0, 8, 0x13, 16, 16, w, h);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, data);
    } else {
        do {
            fill = data[i++];
            word = fill;
            if (!(word & 0x40000000)) {
                buf[n++] = word & 0x1F1F1F1F;
            } else {
                word &= 0x3FFF;
                fill = data[i++] & 0x1F1F1F1F;
                for (; word >= 0; word--) {
                    buf[n++] = fill;
                }
            }
        } while (n < w * h / 4);
        sceGsSetDefLoadImage(&g_gs_load_image, 0x16C0, 8, 0x13, 16, 16, w, h);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, buf);
    }
    row = 0;
    dst = (u16 *)g_sprite_clut_buf;
    do {
        row++;
        dst[0] = src[0] | 0x8000;
        dst[1] = src[1] | 0x8000;
        dst[2] = src[2] | 0x8000;
        dst[3] = src[3] | 0x8000;
        dst[4] = src[4] | 0x8000;
        dst[5] = src[5] | 0x8000;
        dst[6] = src[6] | 0x8000;
        dst[7] = src[7] | 0x8000;
        dst[16] = src[8] | 0x8000;
        dst[17] = src[9] | 0x8000;
        dst[18] = src[10] | 0x8000;
        dst[19] = src[11] | 0x8000;
        dst[20] = src[12] | 0x8000;
        dst[21] = src[13] | 0x8000;
        dst[22] = src[14] | 0x8000;
        dst[23] = src[15] | 0x8000;
        src += 16;
        dst += 8;
    } while (row < 2);
    g_clut_upload_cbp = 0x18C0;
    clut_upload((u8 *)g_sprite_clut_buf, 1, 1);
}


void wallpaper_draw(void *buffer) {
    sceGifPacket packet;
    s32 left;
    s32 i;
    Vertex *vtx;
    s32 x;
    s32 y;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, 0x253216C0 | ((u64)0x20131806 << 32));
    sceGifPkAddGsData(&packet, 6);
    left = ((0x800 - g_screen_width / 2) << 4) + 8;
    vtx = g_wallpaper_vertices;
    vtx += g_screen_wide * 8;
    for (i = 0; i < 2; i++) {
        s64 t;
        sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_REGLIST, 10));
        sceGifPkAddGsData(&packet, 0x53535310 | ((u64)0x53 << 32));
        sceGifPkAddGsData(&packet, 0x115);
        sceGifPkAddGsData(&packet, 0x80808080 | ((u64)0x3F800000 << 32));
        sceGifPkAddGsData(&packet, vtx[0].u | ((s64)vtx[0].v << 16));
        t = (s64)(left + vtx[0].x);
        sceGifPkAddGsData(&packet, t | ((s64)(vtx[0].y + 0x7200) << 16));
        sceGifPkAddGsData(&packet, vtx[1].u | ((s64)vtx[1].v << 16));
        x = left + vtx[1].x;
        y = vtx[1].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        sceGifPkAddGsData(&packet, vtx[2].u | ((s64)vtx[2].v << 16));
        x = left + vtx[2].x;
        y = vtx[2].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        sceGifPkAddGsData(&packet, vtx[3].u | ((s64)vtx[3].v << 16));
        x = left + vtx[3].x;
        y = vtx[3].y + 0x7200;
        sceGifPkAddGsData(&packet, (s64)x | ((s64)y << 16));
        vtx += 4;
    }
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

void scissor_set(void *buffer, s32 x, s32 y, s32 w, s32 h) {
    sceGifPacket packet;

    sceGifPkInit(&packet, buffer);
    sceGifPkReset(&packet);
    sceGifPkAddGsData(&packet, SCE_GIF_SET_TAG(1, 1, 0, 0, SCE_GIF_PACKED, 1));
    sceGifPkAddGsData(&packet, SCE_GIF_PACKED_AD);
    sceGifPkAddGsData(&packet, (u64)x | ((u64)(x + w - 1) << 16) | ((u64)y << 32) | ((u64)(y + h - 1) << 48));
    sceGifPkAddGsData(&packet, 0x40);
    sceGifPkTerminate(&packet);
    FlushCache(0);
    sceDmaSendN(g_dma_gif, buffer, sceGifPkSize(&packet));
    sceGsSyncPath(0, 0);
}

extern void gfx_draw_shaded_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha);
extern s32 g_label_fade;
extern s32 g_label_timer;

void label_draw(RenderTarget *target, s32 x, s32 y, const char *text) {
    u8 *saved;
    s32 bright;

    if (text == 0) {
        g_label_timer = 0;
        g_label_fade = 0;
        return;
    }
    saved = reg_a0;
    bright = 0x80;
    if (text != 0) {
        gfx_draw_shaded_box(x, y - 16, 17, (strlen(text) + 2) * 8, 100, g_label_fade);
    } else {
        gfx_draw_shaded_box(x, y - 16, 17, 64, 100, g_label_fade);
    }
    if (g_label_fade < 0x60) {
        g_label_fade++;
        return;
    }
    if (g_screen_mode < 2) {
        scissor_set(g_gif_buf, g_screen_margin + 2 + x, 1, 16, 223);
    } else {
        scissor_set(g_gif_buf, x + 1, 0, 16, target->height);
    }
    glyph_queue_clear();
    reg_a0 = (u8 *)text;
    if (g_paused == 0) {
        g_label_timer++;
    }
    switch (g_label_timer >> 6) {
    case 4:
        g_label_timer = 0;
    case 0:
    case 1:
        x += ((g_label_timer >> 1) & 0x1F) - 15;
        break;
    case 2:
        bright = (g_label_timer << 1) & 0x7F;
        break;
    case 3:
        bright = (0x7F - (g_label_timer << 1)) & 0x7F;
        break;
    }
    if (text != 0) {
        glyph_queue_add(x + 8, y, 100, 0, 0x80, bright, 1);
    }
    glyph_queue_flush();
    if (g_screen_mode < 2) {
        scissor_set(g_gif_buf, g_screen_margin + 1, 1, 447, 223);
    } else {
        scissor_set(g_gif_buf, 0, 0, target->width, target->height);
    }
    reg_a0 = saved;
}


void glyph_queue_clear(void) {
    g_glyph_queue_count = 0;
}


extern u16 g_wide_font_codes[];

void glyph_queue_add(x, y, z, page, alpha, attr, wide)
    s32 x;
    s32 y;
    s32 z;
    s32 page;
    s32 alpha;
    s16 attr;
    s32 wide;
{
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    s32 count;
    GlyphQueueEntry *entry;
    u16 code;

    save_d0 = reg_d0.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_d1 = reg_d1.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_d2 = reg_d2.w;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    count = g_glyph_queue_count;
    while (1) {
        reg_d4.w = 0;
        reg_d4.sb[0] = *(s8 *)reg_a0;
        reg_a0++;
        if (reg_d4.w == 0) {
            break;
        }
        reg_d4.h[0] = reg_d4.b[0];
        if (wide) {
            reg_d4.h[0] -= 0x20;
            reg_a1 = (u8 *)g_wide_font_codes;
            reg_d4.h[0] += reg_d4.h[0];
            reg_a1 += reg_d4.h[0];
            reg_d4.h[0] = *(u16 *)reg_a1;
        }
        entry = &g_glyph_queue[count];
        count++;
        entry->x = x;
        entry->y = y;
        entry->z = z;
        entry->page = page;
        entry->alpha = attr;
        entry->color = alpha;
        code = reg_d4.h[0];
        entry->code = code;
        if (wide) {
            entry = &g_glyph_queue[count];
            count++;
            entry->x = x - 8;
            entry->y = y;
            entry->z = z;
            entry->page = page;
            entry->alpha = attr;
            entry->color = alpha;
            entry->code = (s16)code + 0x10;
        }
        y += 8;
    }
    g_glyph_queue_count = count;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}


void glyph_queue_flush(void)
{
    s32 index;

    if (g_glyph_queue_count != 0) {
        g_quad_count = 0;
        for (index = 0; index < g_glyph_queue_count; index++) {
            glyph_queue_emit(index);
        }
        quad_flush();
    }
}




void glyph_queue_emit(s32 index) {
    u32 n;
    s32 u;
    s32 v;
    s32 x;
    s32 y;

    n = g_quad_count;
    x = g_glyph_queue[index].x;
    y = g_glyph_queue[index].y;
    u = (g_glyph_queue[index].code % 126 + 1) * 8;
    v = (g_glyph_queue[index].code / 126 + 1) * 8;
    g_quad_queue[n].z = g_glyph_queue[index].z;
    g_quad_queue[n].alpha = g_glyph_queue[index].alpha;
    g_quad_queue[n].tbp = 0x1E40;
    g_quad_queue[n].mode = 0;
    g_quad_queue[n].cbp = 0x3830;
    g_quad_queue[n].color = g_glyph_queue[index].color;
    g_quad_queue[n].x[0] = x;
    g_quad_queue[n].y[0] = y;
    g_quad_queue[n].x[1] = x + 8;
    g_quad_queue[n].y[1] = y + 8;
    g_quad_queue[n].u[0] = u;
    g_quad_queue[n].v[0] = v;
    g_quad_queue[n].u[1] = u + 8;
    g_quad_queue[n].v[1] = v + 8;
    g_quad_count = n + 1;
}

s32 g_quad_count;
s32 g_glyph_queue_count;
s32 g_clut_upload_cbp;
s32 g_tex_upload_tbp;
s32 g_stage_map_alpha;
s32 g_stage_map_marker_level;
s32 g_stage_map_marker_step;
s32 g_stage_map_state;
s32 g_stage_map_unused_a;
s32 g_stage_map_unused_b;
s32 g_stage_unpack_state;
s32 g_screen_width;
s32 g_screen_margin;
s32 g_label_timer;
s32 g_label_fade;

/* .bss (the compiler lays these out in reverse) */
#ifdef DEATH_LABEL
u32 g_image_unpack_buf[65536];
#else
u32 g_image_unpack_buf[196608];
#endif
#ifdef DEATH_LABEL
Quad g_quad_queue[2001];
#else
Quad g_quad_queue[4000];
#endif
GlyphQueueEntry g_glyph_queue[1024];
s16 g_clut_buf[1024];
s16 g_sprite_clut_buf[2048];
s16 g_bg_clut_buf[2048];
#ifdef DEATH_LABEL
s32 g_bg_tile_offsets[4624];
#else
s32 g_bg_tile_offsets[4608];
#endif
RenderTarget g_render_target;

#if defined(DDPDOJ_PC) && defined(DEATH_LABEL)
#include "pc_data_alias.h"

PC_DATA_ALIAS(g_quad_queue_as_GlyphQuad_a, g_quad_queue, 0);
#endif
