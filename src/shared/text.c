#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"
#include "glyph_cache.h"
#include "cd.h"

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} PaletteColor;

typedef union {
    __int128 quadword;
    u32 header;
} GalleryDmaTag;

typedef struct {
    GalleryDmaTag startTag;
    u64 gifTag;
    u64 gifRegisters;
    u64 texflush;
    u64 texflushRegister;
    u64 tex0;
    u64 tex0Register;
    u64 tex1;
    u64 tex1Register;
    u64 clamp;
    u64 clampRegister;
    u64 test;
    u64 testRegister;
    u64 texa;
    u64 texaRegister;
    u64 alpha;
    u64 alphaRegister;
    GalleryDmaTag endTag;
} GalleryTexturePacket;

typedef struct {
    s16 x;
    s16 y;
    u16 depth;
    u16 u;
    u16 v;
    u16 tex;
    u16 w;
    u16 h;
    u16 alpha;
} SpriteEntry;

typedef struct {
    s32 value[4];
} QuadOffsets;

extern sceGsLoadImage g_gs_load_image;
extern void *g_font_file_buf;
extern s8 *g_font_glyph_data;
extern PaletteColor g_font_alt_palette[32];
extern PaletteColor g_font_palettes[20][16];
extern s32 g_text_queue_count;
extern s32 g_overlay_queue_count;
extern SpriteEntry g_text_queue[512];
extern SpriteEntry g_overlay_queue[512];
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u32 g_cd_total_bytes_read;
extern s8 g_cd_retry_timer;
extern u32 g_cd_last_read_size;
extern sceCdlFILE g_cd_file;
u8 g_font_alpha_table[16] = { 0, 25, 51, 76, 102, 51, 76, 102, 128, 128, 128, 128, 128, 128, 128, 128 };
u8 g_font_base_luma_table[16] = { 0, 0, 0, 0, 0, 51, 51, 51, 51, 102, 102, 102, 153, 153, 204, 255 };
u8 g_font_tint_luma_table[16] = { 0, 0, 0, 0, 0, 32, 48, 48, 2, 3, 3, 3, 4, 4, 5, 6 };
u8 g_font_highlight_alpha_table[16] = { 0, 64, 80, 96, 112, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128 };
u8 g_font_highlight_luma_table[16] = { 0, 4, 4, 4, 4, 5, 6, 6, 4, 4, 4, 4, 4, 4, 5, 6 };
u8 g_font_palette_rgb[17][3] = {
    { 255, 255, 255 },
    { 255, 100, 100 },
    { 0, 224, 96 },
    { 0, 144, 224 },
    { 255, 224, 64 },
    { 192, 96, 180 },
    { 255, 144, 176 },
    { 160, 255, 96 },
    { 255, 180, 64 },
    { 255, 100, 100 },
    { 0, 224, 96 },
    { 0, 144, 224 },
    { 255, 224, 64 },
    { 192, 96, 180 },
    { 255, 144, 176 },
    { 160, 255, 96 },
    { 255, 180, 64 }
};
u8 g_font_alt_palette_rgb[48] = {
    0, 0, 0,
    48, 48, 50,
    56, 56, 64,
    104, 104, 104,
    136, 248, 224,
    0, 104, 88,
    0, 72, 72,
    224, 128, 184,
    216, 48, 104,
    144, 48, 48,
    176, 168, 224,
    112, 104, 200,
    248, 176, 240,
    200, 96, 176,
    96, 96, 104,
    255, 255, 255
};
extern s8 D_00578780[];
extern void *g_dma_gif;
extern u8 g_gif_buf_as_u8_a2_a0x10000[2][0x10000];

void font_upload_palettes(void);
void font_init_palettes(void);
void text_build_rect_packet(Qword *packet, s32 firstEntry, s32 entryCount);
void text_queue_tile(s16 x, s16 y, u16 textureId, u16 attributes, u16 scale);
void text_build_quad_packet(Qword *pkt, s32 startIndex, s32 count);
void overlay_build_quad_packet(Qword *pkt, s32 startIndex, s32 count);
void font_load_async(void) {
    cd_read_async(g_font_file_buf, g_data_files[DATA_FILE_FONT].size, g_data_files[DATA_FILE_FONT].lba);
}

s32 clut_upload_defaults();

void font_init(void) {
    *(s32 *)0x10000000 = 0;
    g_font_file_buf = memalign(0x40, 0x300000);
    printf("mozi buf[%x] size[%d]\n", g_font_file_buf, 0x2D9248);
    g_font_glyph_data = g_font_file_buf;
    font_init_palettes();
    font_upload_palettes();
    glyph_cache_init();
    clut_upload_defaults();
}

void font_upload_palettes(void) {
    s32 entryIndex;
    s32 offset;
    s16 cbp;

    for (entryIndex = 0, offset = 0; entryIndex < 17; entryIndex++, offset += 0x40) {
        cbp = (s64)(entryIndex + 0x37E8);
        sceGsSetDefLoadImage(&g_gs_load_image, cbp, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, (u8 *)g_font_palettes + offset);
        sceGsSyncPath(0, 0);
    }

    sceGsSetDefLoadImage(&g_gs_load_image, 0x37FA, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, (u8 *)g_font_alt_palette);
    sceGsSyncPath(0, 0);
}

void font_make_tint_palette(s32 paletteIndex)
{
    s32 i;
    u32 gray;
    s32 j;

    for (i = 0; i < 8; i++) {
        gray = g_font_tint_luma_table[i];
        g_font_palettes[paletteIndex][i].red = gray;
        g_font_palettes[paletteIndex][i].green = gray;
        g_font_palettes[paletteIndex][i].blue = gray;
        g_font_palettes[paletteIndex][i].alpha = g_font_alpha_table[i];
    }

    for (j = 8; j < 16; j++) {
        g_font_palettes[paletteIndex][j].red = (g_font_tint_luma_table[j] * g_font_palette_rgb[paletteIndex][0]) / 6;
        g_font_palettes[paletteIndex][j].green = (g_font_tint_luma_table[j] * g_font_palette_rgb[paletteIndex][1]) / 6;
        g_font_palettes[paletteIndex][j].blue = (g_font_tint_luma_table[j] * g_font_palette_rgb[paletteIndex][2]) / 6;
        g_font_palettes[paletteIndex][j].alpha = g_font_alpha_table[j];
    }
}

void font_make_highlight_palette(s32 paletteIndex)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        g_font_palettes[paletteIndex][i].red = (g_font_highlight_luma_table[i] * g_font_palette_rgb[paletteIndex][0]) / 6;
        g_font_palettes[paletteIndex][i].green = (g_font_highlight_luma_table[i] * g_font_palette_rgb[paletteIndex][1]) / 6;
        g_font_palettes[paletteIndex][i].blue = (g_font_highlight_luma_table[i] * g_font_palette_rgb[paletteIndex][2]) / 6;
        g_font_palettes[paletteIndex][i].alpha = g_font_highlight_alpha_table[i];
    }

    for (i = 8; i < 16; i++) {
        g_font_palettes[paletteIndex][i].red = (g_font_palette_rgb[0][0] * g_font_highlight_luma_table[i]) / 6;
        g_font_palettes[paletteIndex][i].green = (g_font_palette_rgb[0][1] * g_font_highlight_luma_table[i]) / 6;
        g_font_palettes[paletteIndex][i].blue = (g_font_palette_rgb[0][2] * g_font_highlight_luma_table[i]) / 6;
        g_font_palettes[paletteIndex][i].alpha = 0x80;
    }
}

void font_init_palettes(void)
{
    s32 colorIndex;
    s32 paletteIndex;
    s32 rgbOffset;
    s32 column;

    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        PaletteColor *color = &g_font_palettes[0][colorIndex];
        column = g_font_base_luma_table[colorIndex];
        color->red = (color->green = (color->blue = column));
        color->alpha = g_font_alpha_table[colorIndex];
    }

    paletteIndex = 1;
    do {
        font_make_tint_palette(paletteIndex);
    } while ((++paletteIndex) < 9);

    paletteIndex = 9;
    do {
        font_make_highlight_palette(paletteIndex);
    } while ((++paletteIndex) < 17);

    for (rgbOffset = 0, colorIndex = 0; colorIndex < 16; colorIndex++) {
        g_font_alt_palette[colorIndex].red = g_font_alt_palette_rgb[rgbOffset++];
        g_font_alt_palette[colorIndex].green = g_font_alt_palette_rgb[rgbOffset++];
        g_font_alt_palette[colorIndex].blue = g_font_alt_palette_rgb[rgbOffset++];
        if (colorIndex == 0) {
            g_font_alt_palette[colorIndex].alpha = 0;
        } else {
            g_font_alt_palette[colorIndex].alpha = 0x80;
        }
    }

    for (colorIndex = 0; colorIndex < 32; colorIndex++) {
        for (column = 0; column < 512; column++) {
            ((u8 (*)[512])D_00578780)[colorIndex][column] = 0;
        }
    }
}

u64 sjis_to_jis(u64 sjis) {
    u64 hi = (sjis >> 8) & 0xFF;
    u64 lo = sjis & 0xFF;

    if (hi >= 0x81 && hi < 0xA0) {
        hi -= 0x81;
    } else if (hi >= 0xE0 && hi < 0xF0) {
        hi += -0xC1LL;
    }
    hi *= 2;
    if (lo >= 0x40 && lo < 0x7F) {
        lo -= 0x40;
    } else if (lo >= 0x80 && lo < 0x9F) {
        lo += -0x41LL;
    } else if (lo >= 0x9F && lo < 0xFD) {
        lo -= 0x9F;
        hi += 1;
    }
    return ((hi + 1) << 8) + lo + 0x2021;
}

u64 sjis_to_glyph_index(u64 sjis)
{
    u64 packed = sjis_to_jis(sjis);
    u64 upper = (packed >> 8) - 0x21;
    u64 scaled = upper * 0x5E;
    u64 lower = (packed & 0xFF) - 0x21;

    return scaled + lower;
}

void font_build_gs_setup_packet(void *packetPtr)
{
    GalleryTexturePacket *packet = packetPtr;
    packet->startTag.quadword = 0;
    packet->startTag.header = 0x10000008;
    packet->gifTag = SCE_GIF_SET_TAG(7, 1, 0, 0, SCE_GIF_PACKED, 1);
    packet->gifRegisters = SCE_GIF_PACKED_AD;
    packet->texflush = 0;
    packet->texflushRegister = SCE_GS_TEXFLUSH;
    packet->tex0 = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, 0x37E8, SCE_GS_PSMCT32, 0, 0, 1);
    packet->tex0Register = SCE_GS_TEX0_1;
    packet->tex1 = SCE_GS_SET_TEX1(0, 0, 1, 1, 0, 0, 0);
    packet->tex1Register = SCE_GS_TEX1_1;
    packet->clamp = 0;
    packet->clampRegister = SCE_GS_CLAMP_1;
    packet->test = SCE_GS_SET_TEST(1, 7, 0, 0, 0, 0, 1, 1);
    packet->testRegister = SCE_GS_TEST_1;
    packet->texa = SCE_GS_SET_TEXA(0x80, 1, 0x80);
    packet->texaRegister = SCE_GS_TEXA;
    packet->alpha = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    packet->alphaRegister = SCE_GS_ALPHA_1;
    packet->endTag.quadword = 0;
    packet->endTag.header = 0x70000000;
}

void text_queue_clear(void) {
    g_text_queue_count = 0;
}

void text_queue_clear_all(void) {
    g_overlay_queue_count = 0;
    g_text_queue_count = 0;
}


void text_queue_sjis(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 uploadCount;
    s32 uploadOffset = 0;
    GlyphCacheEntry *cache = g_glyph_cache;
    s32 leadByte;
    s32 shiftJis;
    s32 glyphIndex;
    s32 cacheIndex;
    s32 byteIndex;
    s16 textureY;
    s16 textureX;
    SpriteEntry *drawEntry;

    uploadCount = 0;
    while (((leadByte = *text) != 0) && (uploadCount < 30)) {
        shiftJis = leadByte;
        shiftJis &= 0xFF;
        shiftJis <<= 8;
        shiftJis |= (u8)text[1];
        text += 2;
        if (shiftJis == 0x818F) {
            break;
        }
        if ((g_text_queue_count < 512) || (shiftJis != 0x8140)) {
            glyphIndex = (s32)sjis_to_glyph_index((s64)shiftJis);
            cacheIndex = glyph_cache_lookup((u16)glyphIndex);
            if (cacheIndex & 0x8000) {
                for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                    (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + glyphIndex * 0x152)[byteIndex];
                }
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 16, SCE_GS_PSMT4, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_00578780 + uploadOffset);
                uploadOffset += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &g_text_queue[g_text_queue_count];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            g_text_queue_count++;
        }
        x = (s16)(x + ((s16)glyphWidth));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}

void overlay_queue_sjis(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 uploadCount;
    s32 uploadOffset = 0;
    GlyphCacheEntry *cache = g_glyph_cache;
    s32 leadByte;
    s32 shiftJis;
    s32 glyphIndex;
    s32 cacheIndex;
    s32 byteIndex;
    s16 textureY;
    s16 textureX;
    SpriteEntry *drawEntry;

    uploadCount = 0;
    while (((leadByte = *text) != 0) && (uploadCount < 30)) {
        shiftJis = leadByte;
        shiftJis &= 0xFF;
        shiftJis <<= 8;
        shiftJis |= (u8)text[1];
        text += 2;
        if (shiftJis == 0x818F) {
            break;
        }
        if ((g_overlay_queue_count < 512) || (shiftJis != 0x8140)) {
            glyphIndex = (s32)sjis_to_glyph_index((s64)shiftJis);
            cacheIndex = glyph_cache_lookup((u16)glyphIndex);
            if (cacheIndex & 0x8000) {
                for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                    (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + glyphIndex * 0x152)[byteIndex];
                }
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 16, SCE_GS_PSMT4, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_00578780 + uploadOffset);
                uploadOffset += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &g_overlay_queue[g_overlay_queue_count];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            g_overlay_queue_count++;
        }
        x = (s16)(x + ((s16)glyphWidth));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}

void text_queue_glyph(x, y, textureId, texturePage, glyphWidth, glyphHeight, alpha, depth)
    s16 x;
    s16 y;
    u16 textureId;
    u16 texturePage;
    u16 glyphWidth;
    u16 glyphHeight;
    u16 alpha;
    u16 depth;
{
    s32 id = textureId;
    s32 textureIndex;
    s32 uploadOffset = 0;
    GlyphCacheEntry *textures = g_glyph_cache;

    if (g_text_queue_count < 0x200) {
        s32 queueIndex;
        s16 height;
        s16 width;

        textureIndex = glyph_cache_lookup((u16)id);
        if (textureIndex & 0x8000) {
            s32 byteIndex;

            for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + id * 0x152)[byteIndex];
            }

            textureIndex &= 0x7FFF;
            width = textures[textureIndex].x;
            sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 0x10, SCE_GS_PSMT4,
                          width,
                          textures[textureIndex].y, 0x1A, 0x1A);
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, D_00578780);
        }

        width = textures[textureIndex & 0x7FFF].x;
        height = textures[textureIndex & 0x7FFF].y;
        if (glyphWidth == 0) {
            glyphWidth = 26;
            glyphHeight = glyphWidth;
        }
        if (depth == 0) {
            depth = 1;
        }

        queueIndex = g_text_queue_count;
        g_text_queue[queueIndex].x = x;
        g_text_queue[queueIndex].y = y;
        g_text_queue[queueIndex].depth = depth;
        g_text_queue[queueIndex].u = width;
        g_text_queue[queueIndex].v = height;
        g_text_queue[queueIndex].tex = texturePage;
        g_text_queue[queueIndex].w = glyphWidth;
        g_text_queue[queueIndex].h = glyphHeight;
        g_text_queue[queueIndex].alpha = alpha;
        g_text_queue_count++;
    }
}

void overlay_queue_glyph(x, y, textureId, texturePage, glyphWidth, glyphHeight, alpha, depth)
    s16 x;
    s16 y;
    u16 textureId;
    u16 texturePage;
    u16 glyphWidth;
    u16 glyphHeight;
    u16 alpha;
    u16 depth;
{
    s32 id = textureId;
    s32 textureIndex;
    s32 uploadOffset = 0;
    GlyphCacheEntry *textures = g_glyph_cache;

    if (g_overlay_queue_count < 0x200) {
        s32 queueIndex;
        s16 height;
        s16 width;

        textureIndex = glyph_cache_lookup((u16)id);
        if (textureIndex & 0x8000) {
            s32 byteIndex;

            for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + id * 0x152)[byteIndex];
            }

            textureIndex &= 0x7FFF;
            width = textures[textureIndex].x;
            sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 0x10, SCE_GS_PSMT4,
                          width,
                          textures[textureIndex].y, 0x1A, 0x1A);
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, D_00578780);
        }

        width = textures[textureIndex & 0x7FFF].x;
        height = textures[textureIndex & 0x7FFF].y;
        if (glyphWidth == 0) {
            glyphWidth = 26;
            glyphHeight = glyphWidth;
        }
        if (depth == 0) {
            depth = 1;
        }

        queueIndex = g_overlay_queue_count;
        g_overlay_queue[queueIndex].x = x;
        g_overlay_queue[queueIndex].y = y;
        g_overlay_queue[queueIndex].depth = depth;
        g_overlay_queue[queueIndex].u = width;
        g_overlay_queue[queueIndex].v = height;
        g_overlay_queue[queueIndex].tex = texturePage;
        g_overlay_queue[queueIndex].w = glyphWidth;
        g_overlay_queue[queueIndex].h = glyphHeight;
        g_overlay_queue[queueIndex].alpha = alpha;
        g_overlay_queue_count++;
    }
}

void text_queue_ascii(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 cacheIndex;
    s32 uploadCount;
    GlyphCacheEntry *cache = g_glyph_cache;
    s32 leadByte;
    s32 uploadOffset = 0;
    s32 glyphIndex;
    s32 byteIndex;
    s16 textureY;
    s16 textureX;
    SpriteEntry *drawEntry;

    uploadCount = 0;
    while (((leadByte = *text) != 0) && (uploadCount < 30) && (leadByte != '@')) {
        text++;
        if ((g_text_queue_count < 512) || ((leadByte & 0xFF) != ' ')) {
            cacheIndex = glyph_cache_lookup((u16)((u8)leadByte + 0x208D));
            if (cacheIndex & 0x8000) {
                for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                    glyphIndex = (leadByte & 0xFF) + 0x208D;
                    (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + glyphIndex * 0x152)[byteIndex];
                }
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 16, SCE_GS_PSMT4, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_00578780 + uploadOffset);
                uploadOffset += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &g_text_queue[g_text_queue_count];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            g_text_queue_count++;
        }
        x = (s16)(x + ((s16)(glyphWidth / 2)));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}

void overlay_queue_ascii(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 cacheIndex;
    s32 uploadCount;
    GlyphCacheEntry *cache = g_glyph_cache;
    s32 leadByte;
    s32 uploadOffset = 0;
    s32 glyphIndex;
    s32 byteIndex;
    s16 textureY;
    s16 textureX;
    SpriteEntry *drawEntry;

    uploadCount = 0;
    while (((leadByte = *text) != 0) && (uploadCount < 30) && (leadByte != '@')) {
        text++;
        if ((g_overlay_queue_count < 512) || ((leadByte & 0xFF) != ' ')) {
            cacheIndex = glyph_cache_lookup((u16)((u8)leadByte + 0x208D));
            if (cacheIndex & 0x8000) {
                for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                    glyphIndex = (leadByte & 0xFF) + 0x208D;
                    (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + glyphIndex * 0x152)[byteIndex];
                }
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 16, SCE_GS_PSMT4, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_00578780 + uploadOffset);
                uploadOffset += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &g_overlay_queue[g_overlay_queue_count];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            g_overlay_queue_count++;
        }
        x = (s16)(x + ((s16)(glyphWidth / 2)));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}

void text_flush_rects(void)
{
    u8 *packet;
    s32 firstEntry;
    s32 batchCount;
    s32 bufferIndex;
    s32 remainingEntries;

    if (g_text_queue_count == 0) {
        return;
    }
    font_build_gs_setup_packet(g_gif_buf_as_u8_a2_a0x10000[0]);
    FlushCache(0);
    sceDmaSend(g_dma_gif, g_gif_buf_as_u8_a2_a0x10000[0]);
    sceGsSyncPath(0, 0);

    bufferIndex = 0;
    firstEntry = 0;
    while ((remainingEntries = g_text_queue_count) != 0) {
        if (remainingEntries >= 6) {
            batchCount = 6;
        } else {
            batchCount = remainingEntries;
        }

        packet = g_gif_buf_as_u8_a2_a0x10000[bufferIndex];
        text_build_rect_packet((Qword *)packet, firstEntry, batchCount);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceDmaSend(g_dma_gif, packet);

        bufferIndex ^= 1;
        firstEntry += batchCount;
        g_text_queue_count -= batchCount;
    }
}

void text_build_rect_packet(Qword *packet, s32 firstEntry, s32 entryCount)
{
    s32 packetIndex;
    s32 entryIndex;

    packetIndex = 1;
    packet[0].q = 0;
    packet[0].w[0] = (entryCount * 10) | 0x10000000;

    for (entryIndex = 0; entryIndex < entryCount; entryIndex++) {
        s32 x = g_text_queue[firstEntry].x;
        s32 y = g_text_queue[firstEntry].y;
        s32 depth = g_text_queue[firstEntry].depth;
        s32 textureU = g_text_queue[firstEntry].u;
        s32 textureV = g_text_queue[firstEntry].v;
        s32 width = g_text_queue[firstEntry].w;
        s32 height = g_text_queue[firstEntry].h;
        s32 alpha = g_text_queue[firstEntry].alpha;
        s32 texturePage = g_text_queue[firstEntry].tex;
        s32 textureBase;

        if (texturePage == 0x14) {
            textureBase = 0x37FA;
        } else {
            textureBase = texturePage + 0x37E8;
        }

        firstEntry++;

        packet[packetIndex].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
        packet[packetIndex].d[1] = SCE_GIF_PACKED_AD;
        packetIndex++;

        packet[packetIndex].d[0] = 0;
        packet[packetIndex].d[1] = SCE_GS_TEXFLUSH;
        packetIndex++;

        packet[packetIndex].d[0] =
            SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, textureBase, SCE_GS_PSMCT32, 0, 0, 1);
        packet[packetIndex].d[1] = SCE_GS_TEX0_1;
        packetIndex++;

        packet[packetIndex].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_SPRITE, 0, 1, 0, 1, 1, 1, 0, 0), SCE_GIF_PACKED, 6);
        packet[packetIndex].d[1] = 0x431431;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = textureU << 4;
        packet[packetIndex].w[1] = textureV << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)(x + 0x700) << 4;
        packet[packetIndex].w[1] = ((u32)y << 3) + 0x7900;
        packet[packetIndex].w[2] = depth << 4;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = 0x7F;
        packet[packetIndex].w[1] = 0x7F;
        packet[packetIndex].w[2] = 0x7F;
        packet[packetIndex].w[3] = alpha;
        packetIndex++;

        packet[packetIndex].w[0] = (textureU + 0x1A) << 4;
        packet[packetIndex].w[1] = (textureV + 0x1A) << 4;
        packet[packetIndex].w[2] = 0;
        packet[packetIndex].w[3] = 0;
        packetIndex++;

        packet[packetIndex].w[0] = (u32)(x + 0x700 + width) << 4;
        packet[packetIndex].w[1] = (((height >> 1) + 0x790) << 4) + ((u32)y << 3);
        packet[packetIndex].w[2] = depth << 4;
        packet[packetIndex].w[3] = 0;
        packetIndex++;
    }

    packet[packetIndex].q = 0;
    packet[packetIndex].w[0] = 0x70000000;
}

void text_queue_sjis_vertical(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 uploadCount;
    s32 uploadOffset = 0;
    GlyphCacheEntry *cache = g_glyph_cache;
    s32 leadByte;
    s32 shiftJis;
    s32 glyphIndex;
    s32 cacheIndex;
    s32 byteIndex;
    s16 textureY;
    s16 textureX;
    SpriteEntry *drawEntry;

    uploadCount = 0;
    while (((leadByte = *text) != 0) && (uploadCount < 30)) {
        shiftJis = leadByte;
        shiftJis &= 0xFF;
        shiftJis <<= 8;
        shiftJis |= (u8)text[1];
        text += 2;
        if (shiftJis == 0x818F) {
            break;
        }
        if ((g_text_queue_count < 512) || (shiftJis != 0x8140)) {
            glyphIndex = (s32)sjis_to_glyph_index((s64)shiftJis);
            cacheIndex = glyph_cache_lookup((u16)glyphIndex);
            if (cacheIndex & 0x8000) {
                for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                    (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + glyphIndex * 0x152)[byteIndex];
                }
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 16, SCE_GS_PSMT4, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_00578780 + uploadOffset);
                uploadOffset += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &g_text_queue[g_text_queue_count];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            g_text_queue_count++;
        }
        y = (s16)(y + ((s16)glyphHeight));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}

void overlay_queue_sjis_vertical(s16 x, s16 y, const char *text, u16 texturePage, u16 glyphWidth, u16 glyphHeight, u16 alpha, u16 depth)
{
    s32 uploadCount;
    s32 uploadOffset = 0;
    GlyphCacheEntry *cache = g_glyph_cache;
    s32 leadByte;
    s32 shiftJis;
    s32 glyphIndex;
    s32 cacheIndex;
    s32 byteIndex;
    s16 textureY;
    s16 textureX;
    SpriteEntry *drawEntry;

    uploadCount = 0;
    while (((leadByte = *text) != 0) && (uploadCount < 30)) {
        shiftJis = leadByte;
        shiftJis &= 0xFF;
        shiftJis <<= 8;
        shiftJis |= (u8)text[1];
        text += 2;
        if (shiftJis == 0x818F) {
            break;
        }
        if ((g_overlay_queue_count < 512) || (shiftJis != 0x8140)) {
            glyphIndex = (s32)sjis_to_glyph_index((s64)shiftJis);
            cacheIndex = glyph_cache_lookup((u16)glyphIndex);
            if (cacheIndex & 0x8000) {
                for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                    (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + glyphIndex * 0x152)[byteIndex];
                }
                cacheIndex &= 0x7FFF;
                sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 16, SCE_GS_PSMT4, cache[cacheIndex].x, cache[cacheIndex].y, 26, 26);
                FlushCache(0);
                sceGsExecLoadImage(&g_gs_load_image, D_00578780 + uploadOffset);
                uploadOffset += 0x200;
                uploadCount++;
            }
            textureX = cache[cacheIndex & 0x7FFF].x;
            textureY = cache[cacheIndex & 0x7FFF].y;
            if (glyphWidth == 0) {
                glyphWidth = 26;
                glyphHeight = glyphWidth;
            }
            if (depth == 0) {
                depth = 1;
            }
            drawEntry = &g_overlay_queue[g_overlay_queue_count];
            drawEntry->x = x;
            drawEntry->y = y;
            drawEntry->depth = depth;
            drawEntry->u = textureX;
            drawEntry->v = textureY;
            drawEntry->tex = texturePage;
            drawEntry->w = glyphWidth;
            drawEntry->h = glyphHeight;
            drawEntry->alpha = alpha;
            g_overlay_queue_count++;
        }
        y = (s16)(y + ((s16)glyphHeight));
    }

    if (uploadCount != 0) {
        sceGsSyncPath(0, 0);
    }
}

void frame_draw_column(s32 x, s32 y, s32 alpha) {
    s32 pos;
    s32 i;

    text_queue_tile(x - 10, y, 0x2289, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(x - 10, y + pos, 0x228A, alpha, 300);
    }
    text_queue_tile(x - 10, y + pos, 0x228B, alpha, 300);
    for (pos = 6, i = 0; i < 1; i++, pos += 16) {
        text_queue_tile(x + pos, y, 0x2287, alpha, 300);
    }
    for (pos = 6, i = 0; i < 1; i++, pos += 16) {
        text_queue_tile(x + pos, y + 0xD0, 0x2288, alpha, 300);
    }
    text_queue_tile(x + 10, y, 0x2284, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(x + 10, y + pos, 0x2285, alpha, 300);
    }
    text_queue_tile(x + 10, y + pos, 0x2286, alpha, 300);
}

void frame_draw_left_panel(s32 alpha) {
    s32 pos;
    s32 i;

    text_queue_tile(-6, 0, 0x2289, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(-6, pos, 0x228A, alpha, 300);
    }
    text_queue_tile(-6, pos, 0x228B, alpha, 300);
    for (pos = 10, i = 0; i < 3; i++, pos += 16) {
        text_queue_tile(pos, 0, 0x2287, alpha, 300);
    }
    for (pos = 10, i = 0; i < 3; i++, pos += 16) {
        text_queue_tile(pos, 0xD0, 0x2288, alpha, 300);
    }
    text_queue_tile(0x3A, 0, 0x2284, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(0x3A, pos, 0x2285, alpha, 300);
    }
    text_queue_tile(0x3A, pos, 0x2286, alpha, 300);
}

void frame_draw_right_panel(s32 alpha) {
    s32 pos;
    s32 i;

    text_queue_tile(0xDA, 0, 0x2289, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(0xDA, pos, 0x228A, alpha, 300);
    }
    text_queue_tile(0xDA, pos, 0x228B, alpha, 300);
    for (pos = 0xEA, i = 0; i < 3; i++, pos += 16) {
        text_queue_tile(pos, 0, 0x2287, alpha, 300);
    }
    for (pos = 0xEA, i = 0; i < 3; i++, pos += 16) {
        text_queue_tile(pos, 0xD0, 0x2288, alpha, 300);
    }
    text_queue_tile(0x11A, 0, 0x2284, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(0x11A, pos, 0x2285, alpha, 300);
    }
    text_queue_tile(0x11A, pos, 0x2286, alpha, 300);
}

void frame_draw_wide_left_panel(s32 alpha) {
    s32 pos;
    s32 i;

    text_queue_tile(-6, 0, 0x2289, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(-6, pos, 0x228A, alpha, 300);
    }
    text_queue_tile(-6, pos, 0x228B, alpha, 300);
    for (pos = 10, i = 0; i < 6; i++, pos += 16) {
        text_queue_tile(pos, 0, 0x2287, alpha, 300);
    }
    for (pos = 10, i = 0; i < 6; i++, pos += 16) {
        text_queue_tile(pos, 0xD0, 0x2288, alpha, 300);
    }
    text_queue_tile(0x6A, 0, 0x2284, alpha, 300);
    for (pos = 16, i = 0; i < 12; i++, pos += 16) {
        text_queue_tile(0x6A, pos, 0x2285, alpha, 300);
    }
    text_queue_tile(0x6A, pos, 0x2286, alpha, 300);
}

void text_queue_tile(s16 x, s16 y, u16 textureId, u16 attributes, u16 scale)
{
    s32 id = textureId;
    s32 textureIndex;
    s32 uploaded;
    s32 uploadOffset = 0;
    GlyphCacheEntry *textures = g_glyph_cache;

    uploaded = 0;

    if (g_text_queue_count < 0x200) {
        s32 queueIndex;
        s16 height;
        s16 width;

        textureIndex = glyph_cache_lookup((u16)id);
        if (textureIndex & 0x8000) {
            s32 byteIndex;

            for (byteIndex = 0; byteIndex < 0x152; byteIndex++) {
                (D_00578780 + uploadOffset)[byteIndex] = (g_font_glyph_data + id * 0x152)[byteIndex];
            }

            textureIndex &= 0x7FFF;
            width = textures[textureIndex].x;
            sceGsSetDefLoadImage(&g_gs_load_image, 0x3800, 0x10, SCE_GS_PSMT4,
                          width,
                          textures[textureIndex].y, 0x1A, 0x1A);
            FlushCache(0);
            sceGsExecLoadImage(&g_gs_load_image, D_00578780);
            uploaded++;
        }

        width = textures[textureIndex & 0x7FFF].x;
        height = textures[textureIndex & 0x7FFF].y;
        if (scale == 0) {
            scale = 1;
        }

        queueIndex = g_text_queue_count;
        g_text_queue[queueIndex].x = x;
        g_text_queue[queueIndex].y = y;
        g_text_queue[queueIndex].depth = scale;
        g_text_queue[queueIndex].u = width;
        g_text_queue[queueIndex].v = height;
        g_text_queue[queueIndex].tex = 0x3832;
        g_text_queue[queueIndex].w = 0x1B;
        g_text_queue[queueIndex].h = 0x1B;
        g_text_queue[queueIndex].alpha = attributes;
        g_text_queue_count++;
    }

    if (uploaded != 0) {
        sceGsSyncPath(0, 0);
    }
}

void text_flush(void)
{
    u8 *packet;
    s32 firstEntry;
    s32 batchCount;
    s32 bufferIndex;
    s32 remainingEntries;

    if (g_text_queue_count == 0) {
        return;
    }
    font_build_gs_setup_packet(g_gif_buf_as_u8_a2_a0x10000[0]);
    FlushCache(0);
    sceDmaSend(g_dma_gif, g_gif_buf_as_u8_a2_a0x10000[0]);
    sceGsSyncPath(0, 0);

    bufferIndex = 0;
    firstEntry = 0;
    while ((remainingEntries = g_text_queue_count) != 0) {
        if (remainingEntries >= 6) {
            batchCount = 6;
        } else {
            batchCount = remainingEntries;
        }

        packet = g_gif_buf_as_u8_a2_a0x10000[bufferIndex];
        text_build_quad_packet((Qword *)packet, firstEntry, batchCount);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceDmaSend(g_dma_gif, packet);

        bufferIndex ^= 1;
        firstEntry += batchCount;
        g_text_queue_count -= batchCount;
    }
}

void text_build_quad_packet(Qword *pkt, s32 startIndex, s32 count)
{
    s32 x[4];
    s32 y[4];
    s32 u[4];
    s32 v[4];
    QuadOffsets uOffset = { 9, -9, 9, -9 };
    s32 qwc;
    s32 i;
    s32 j;

    qwc = 1;
    pkt[0].q = 0;
    pkt[0].w[0] = (count << 4) | 0x10000000;

    for (i = 0; i < count; i++) {
        s32 z;
        s32 tex;
        s32 width;
        s32 height;
        s32 alpha;
        s32 cbp;

        x[0] = g_text_queue[startIndex].x;
        y[0] = g_text_queue[startIndex].y;
        z = g_text_queue[startIndex].depth;
        u[0] = g_text_queue[startIndex].u;
        v[0] = g_text_queue[startIndex].v;
        width = g_text_queue[startIndex].w;
        height = g_text_queue[startIndex].h;
        alpha = g_text_queue[startIndex].alpha;
        tex = g_text_queue[startIndex].tex;

        if (tex == 0x14) {
            cbp = 0x37FA;
        } else if (tex == 0x3832) {
            cbp = 0x3832;
        } else {
            cbp = tex + 0x37E8;
        }

        startIndex++;

        x[1] = x[0];
        x[2] = x[0];
        x[3] = x[0];
        y[1] = y[0];
        y[2] = y[0];
        y[3] = y[0];
        x[0] += width;
        x[1] += width;
        y[1] += height;
        y[3] += height;

        u[1] = u[0] + 0x1A;
        u[2] = u[0];
        u[3] = u[0] + 0x1A;
        v[1] = v[0];
        v[2] = v[0] + 0x1A;
        v[3] = v[0] + 0x1A;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
        pkt[qwc].d[1] = SCE_GIF_PACKED_AD;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEXFLUSH;
        qwc++;

        if (cbp == 0x3832) {
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
        } else {
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT32, 0, 0, 1);
        }
        pkt[qwc].d[1] = SCE_GS_TEX0_1;
        qwc++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_TRISTRIP, 0, 1, 0, 1, 0, 1, 0, 0), SCE_GIF_PACKED, 12);
        pkt[qwc].d[1] = 0x0000431431431431ULL;
        qwc++;

        for (j = 0; j < 4; j++) {
            pkt[qwc].w[0] = 0x7F;
            pkt[qwc].w[1] = 0x7F;
            pkt[qwc].w[2] = 0x7F;
            pkt[qwc].w[3] = alpha;
            qwc++;

            pkt[qwc].w[0] = u[j] << 4;
            pkt[qwc].w[1] = v[j] << 4;
            pkt[qwc].w[2] = 0;
            pkt[qwc].w[3] = 0;
            if (cbp == 0x3832) {
                pkt[qwc].w[0] += uOffset.value[j];
            }
            qwc++;

            pkt[qwc].w[0] = (x[j] + 0x700) << 4;
            pkt[qwc].w[1] = (y[j] << 4) + 0x7900;
            pkt[qwc].w[2] = z << 4;
            pkt[qwc].w[3] = 0;
            qwc++;
        }
    }

    pkt[qwc].q = 0;
    pkt[qwc].w[0] = 0x70000000;
}

void overlay_flush(void)
{
    u8 *packet;
    s32 firstEntry;
    s32 batchCount;
    s32 bufferIndex;
    s32 remainingEntries;

    if (g_overlay_queue_count == 0) {
        return;
    }
    font_build_gs_setup_packet(g_gif_buf_as_u8_a2_a0x10000[0]);
    FlushCache(0);
    sceDmaSend(g_dma_gif, g_gif_buf_as_u8_a2_a0x10000[0]);
    sceGsSyncPath(0, 0);

    bufferIndex = 0;
    firstEntry = 0;
    while ((remainingEntries = g_overlay_queue_count) != 0) {
        if (remainingEntries >= 6) {
            batchCount = 6;
        } else {
            batchCount = remainingEntries;
        }

        packet = g_gif_buf_as_u8_a2_a0x10000[bufferIndex];
        overlay_build_quad_packet((Qword *)packet, firstEntry, batchCount);
        sceGsSyncPath(0, 0);
        FlushCache(0);
        sceDmaSend(g_dma_gif, packet);

        bufferIndex ^= 1;
        firstEntry += batchCount;
        g_overlay_queue_count -= batchCount;
    }
}

void overlay_build_quad_packet(Qword *pkt, s32 startIndex, s32 count)
{
    s32 x[4];
    s32 y[4];
    s32 u[4];
    s32 v[4];
    s32 qwc;
    s32 i;
    s32 j;

    qwc = 1;
    pkt[0].q = 0;
    pkt[0].w[0] = (count << 4) | 0x10000000;

    for (i = 0; i < count; i++) {
        s32 z;
        s32 tex;
        s32 width;
        s32 height;
        s32 alpha;
        s32 cbp;

        x[0] = g_overlay_queue[startIndex].x;
        y[0] = g_overlay_queue[startIndex].y;
        z = g_overlay_queue[startIndex].depth;
        u[0] = g_overlay_queue[startIndex].u;
        v[0] = g_overlay_queue[startIndex].v;
        width = g_overlay_queue[startIndex].w;
        height = g_overlay_queue[startIndex].h;
        alpha = g_overlay_queue[startIndex].alpha;
        tex = g_overlay_queue[startIndex].tex;

        if (tex == 0x14) {
            cbp = 0x37FA;
        } else if (tex == 0x3832) {
            cbp = 0x3832;
        } else {
            cbp = tex + 0x37E8;
        }

        startIndex++;

        x[1] = x[0];
        x[2] = x[0];
        x[3] = x[0];
        y[1] = y[0];
        y[2] = y[0];
        y[3] = y[0];
        x[0] += width;
        x[1] += width;
        y[1] += height;
        y[3] += height;

        u[1] = u[0] + 0x1A;
        u[2] = u[0];
        u[3] = u[0] + 0x1A;
        v[1] = v[0];
        v[2] = v[0] + 0x1A;
        v[3] = v[0] + 0x1A;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
        pkt[qwc].d[1] = SCE_GIF_PACKED_AD;
        qwc++;

        pkt[qwc].d[0] = 0;
        pkt[qwc].d[1] = SCE_GS_TEXFLUSH;
        qwc++;

        if (cbp == 0x3832) {
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT16, 0, 0, 1);
        } else {
            pkt[qwc].d[0] = SCE_GS_SET_TEX0(0x3800, 16, SCE_GS_PSMT4, 10, 10, 1, 0, cbp, SCE_GS_PSMCT32, 0, 0, 1);
        }
        pkt[qwc].d[1] = SCE_GS_TEX0_1;
        qwc++;

        pkt[qwc].d[0] = SCE_GIF_SET_TAG(1, 1, 1, SCE_GS_SET_PRIM(SCE_GS_PRIM_TRISTRIP, 0, 1, 0, 1, 0, 1, 0, 0), SCE_GIF_PACKED, 12);
        pkt[qwc].d[1] = 0x0000431431431431ULL;
        qwc++;

        for (j = 0; j < 4; j++) {
            pkt[qwc].w[0] = 0x7F;
            pkt[qwc].w[1] = 0x7F;
            pkt[qwc].w[2] = 0x7F;
            pkt[qwc].w[3] = alpha;
            qwc++;

            pkt[qwc].w[0] = u[j] << 4;
            pkt[qwc].w[1] = v[j] << 4;
            pkt[qwc].w[2] = 0;
            pkt[qwc].w[3] = 0;
            qwc++;

            pkt[qwc].w[0] = (x[j] + 0x700) << 4;
            pkt[qwc].w[1] = (y[j] << 4) + 0x7900;
            pkt[qwc].w[2] = z << 4;
            pkt[qwc].w[3] = 0;
            qwc++;
        }
    }

    pkt[qwc].q = 0;
    pkt[qwc].w[0] = 0x70000000;
}

void gfx_draw_shaded_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha) {
    Qword *packet = (Qword *)g_gif_buf_as_u8_a2_a0x10000[0];

    packet[0].q = 0;
    packet[0].w[0] = 0x1000000C;
    packet[1].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
    packet[1].d[1] = SCE_GIF_PACKED_AD;
    packet[2].d[0] = 0;
    packet[2].d[1] = SCE_GS_TEXFLUSH;
    packet[3].d[0] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    packet[3].d[1] = SCE_GS_ALPHA_1;
    packet[4].d[0] = SCE_GIF_SET_TAG(1, 1, 1, 0x14C, SCE_GIF_PACKED, 8);
    packet[4].d[1] = 0x41414141;
    packet[5].w[0] = 0x7F;
    packet[5].w[1] = 0;
    packet[5].w[2] = 0;
    packet[5].w[3] = alpha;
    packet[6].w[0] = ((x + 0x700) << 4) + 8;
    packet[6].w[1] = ((y + 0x790) << 4) + 8;
    packet[6].w[2] = depth << 4;
    packet[6].w[3] = 0;
    packet[7].w[0] = 0x5F;
    packet[7].w[1] = 0;
    packet[7].w[2] = 0;
    packet[7].w[3] = alpha;
    packet[8].w[0] = ((x + 0x700) << 4) + 8;
    packet[8].w[1] = ((y + 0x798 + h) << 4) + 8;
    packet[8].w[2] = depth << 4;
    packet[8].w[3] = 0;
    packet[9].w[0] = 0x7F;
    packet[9].w[1] = 0;
    packet[9].w[2] = 0;
    packet[9].w[3] = alpha;
    packet[10].w[0] = ((x + 0x700 + w) << 4) + 8;
    packet[10].w[1] = ((y + 0x794) << 4) + 8;
    packet[10].w[2] = depth << 4;
    packet[10].w[3] = 0;
    packet[11].w[0] = 0x5F;
    packet[11].w[1] = 0;
    packet[11].w[2] = 0;
    packet[11].w[3] = alpha;
    packet[12].w[0] = ((x + 0x700 + w) << 4) + 8;
    packet[12].w[1] = ((y + 0x79C + h) << 4) + 8;
    packet[12].w[2] = depth << 4;
    packet[12].w[3] = 0;
    packet[13].q = 0;
    packet[13].w[0] = 0x70000000;
    FlushCache(0);
    sceDmaSend(g_dma_gif, g_gif_buf_as_u8_a2_a0x10000[0]);
    sceGsSyncPath(0, 0);
}

void gfx_draw_color_box(s32 x, s32 y, s32 w, s32 h, s32 depth, s32 alpha, s32 r, s32 g, s32 b) {
    Qword *packet = (Qword *)g_gif_buf_as_u8_a2_a0x10000[0];

    packet[0].q = 0;
    packet[0].w[0] = 0x1000000C;
    packet[1].d[0] = SCE_GIF_SET_TAG(2, 0, 0, 0, SCE_GIF_PACKED, 1);
    packet[1].d[1] = SCE_GIF_PACKED_AD;
    packet[2].d[0] = 0;
    packet[2].d[1] = SCE_GS_TEXFLUSH;
    packet[3].d[0] = SCE_GS_SET_ALPHA(0, 1, 0, 1, 0);
    packet[3].d[1] = SCE_GS_ALPHA_1;
    packet[4].d[0] = SCE_GIF_SET_TAG(1, 1, 1, 0x14C, SCE_GIF_PACKED, 8);
    packet[4].d[1] = 0x41414141;
    packet[5].w[0] = r;
    packet[5].w[1] = g;
    packet[5].w[2] = b;
    packet[5].w[3] = alpha;
    packet[6].w[0] = ((x + 0x700) << 4) + 8;
    packet[6].w[1] = ((y + 0x790) << 4) + 8;
    packet[6].w[2] = depth << 4;
    packet[6].w[3] = 0;
    packet[7].w[0] = r;
    packet[7].w[1] = g;
    packet[7].w[2] = b;
    packet[7].w[3] = alpha;
    packet[8].w[0] = ((x + 0x700) << 4) + 8;
    packet[8].w[1] = ((y + 0x790 + h) << 4) + 8;
    packet[8].w[2] = depth << 4;
    packet[8].w[3] = 0;
    packet[9].w[0] = r;
    packet[9].w[1] = g;
    packet[9].w[2] = b;
    packet[9].w[3] = alpha;
    packet[10].w[0] = ((x + 0x700 + w) << 4) + 8;
    packet[10].w[1] = ((y + 0x790) << 4) + 8;
    packet[10].w[2] = depth << 4;
    packet[10].w[3] = 0;
    packet[11].w[0] = r;
    packet[11].w[1] = g;
    packet[11].w[2] = b;
    packet[11].w[3] = alpha;
    packet[12].w[0] = ((x + 0x700 + w) << 4) + 8;
    packet[12].w[1] = ((y + 0x790 + h) << 4) + 8;
    packet[12].w[2] = depth << 4;
    packet[12].w[3] = 0;
    packet[13].q = 0;
    packet[13].w[0] = 0x70000000;
    FlushCache(0);
    sceDmaSend(g_dma_gif, g_gif_buf_as_u8_a2_a0x10000[0]);
    sceGsSyncPath(0, 0);
}

void cd_load_file(void *destination, const char *path)
{
    sceCdRMode readMode;
    s32 error;

    do {
        sceCdDiskReady(0);
    } while (!sceCdSearchFile(&g_cd_file, path));

    for (;;) {
        do {
            sceCdDiskReady(0);
            g_cd_last_read_size = g_cd_file.size;
            readMode.trycount = 0;
            readMode.spindlctrl = SCECdSpinNom;
            readMode.datapattern = SCECdSecS2048;
        } while (!sceCdRead(g_cd_file.lsn, (g_cd_file.size + 0x7FF) >> 11, destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf("cd1 err[%x]\n", error);
        sceCdBreak();
    }
}

void cd_read_async(void *destination, s32 byteCount, u32 startSector)
{
    sceCdRMode readMode;
    s32 readError;

    switch (g_cd_async_state) {
    case 0:
        g_cd_async_busy = 1;
        g_cd_last_read_size = 0;
        g_cd_async_state++;
        g_cd_retry_timer = 0;
        break;

    case 1:
        if (sceCdDiskReady(1) == SCECdComplete) {
            g_cd_async_state++;
        } else {
            g_cd_retry_timer++;
            if (g_cd_retry_timer > 60) {
                sceCdBreak();
                g_cd_retry_timer = 0;
                printf("err cd break\n");
            }
        }
        break;

    case 2:
        g_cd_last_read_size = byteCount;
        readMode.trycount = 0;
        readMode.spindlctrl = SCECdSpinNom;
        readMode.datapattern = SCECdSecS2048;
        if (sceCdRead(startSector, (byteCount + 2047) / 2048, destination, &readMode) != 0) {
            g_cd_async_state++;
        }
        break;

    case 3:
        if (sceCdSync(1) == 0) {
            readError = sceCdGetError();
            if (readError != 0) {
                printf("cd3 err[%x]\n", (u32)readError);
                g_cd_retry_timer = 0;
                g_cd_async_state = 1;
                sceCdBreak();
            } else {
                g_cd_async_busy = 0;
                g_cd_async_state = 0;
                g_cd_total_bytes_read += g_cd_last_read_size;
            }
        }
        break;
    }
}

void cd_read_sync(void *destination, u32 byteCount, u32 startSector)
{
    sceCdRMode readMode;
    s32 error;

    g_cd_file.size = byteCount;
    g_cd_file.lsn = startSector;

    for (;;) {
        do {
            sceCdDiskReady(0);
            g_cd_last_read_size = g_cd_file.size;
            readMode.trycount = 0;
            readMode.spindlctrl = SCECdSpinNom;
            readMode.datapattern = SCECdSecS2048;
        } while (!sceCdRead(g_cd_file.lsn, (g_cd_file.size + 0x7FF) >> 11, destination, &readMode));

        sceCdSync(0);
        error = sceCdGetError();
        if (error == 0) {
            break;
        }

        printf("cd4 err[%x]\n", error);
        sceCdBreak();
    }
}

void cd_search_file(const char *path)
{
    do {
        sceCdDiskReady(0);
    } while (sceCdSearchFile(&g_cd_file, path) == 0);
}

s8 *g_font_glyph_data;
s32 g_text_queue_count;
s32 g_overlay_queue_count;
u32 g_cd_last_read_size;
void *g_font_file_buf;
s8 g_cd_retry_timer __attribute__((aligned(4)));
u32 g_cd_total_bytes_read;
s8 g_cd_async_busy __attribute__((aligned(4)));
s8 g_cd_async_state __attribute__((aligned(4)));

SpriteEntry g_text_queue[512] __attribute__((aligned(64)));
SpriteEntry g_overlay_queue[512] __attribute__((aligned(64)));
PaletteColor g_font_palettes[20][16] __attribute__((aligned(64)));
PaletteColor g_font_alt_palette[32] __attribute__((aligned(64)));
u8 g_cd_unused[64] __attribute__((aligned(64)));    /* nothing refers to these 64 bytes */
sceCdlFILE g_cd_file __attribute__((aligned(64)));
