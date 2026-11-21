#include "gallery/gallery.h"

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
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} PaletteColor;

static u8 g_font_alpha_table[16] = {
    0, 25, 51, 76, 102, 51, 76, 102, 128, 128, 128, 128, 128, 128, 128, 128,
};

static u8 g_font_luma_table[16] = {
    0, 0, 0, 0, 0, 51, 51, 51, 51, 102, 102, 102, 153, 153, 204, 255,
};

static u8 g_font_alt_alpha_table[16] = {
    0, 0, 0, 0, 0, 32, 48, 48, 2, 3, 3, 3, 4, 4, 5, 6,
};

static u8 g_font_outline_alpha_table[16] = {
    0, 64, 80, 96, 112, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128,
};

static u8 g_font_alt_luma_table[16] = {
    0, 4, 4, 4, 4, 5, 6, 6, 4, 4, 4, 4, 4, 4, 5, 6,
};

static u8 g_font_palette_rgb[21][3] = {
    { 255, 255, 255 },
    { 255, 100, 100 },
    {   0, 224,  96 },
    {   0, 144, 224 },
    { 255, 224,  64 },
    { 192,  96, 180 },
    { 255, 144, 176 },
    { 160, 255,  96 },
    { 255, 180,  64 },
    { 255, 100, 100 },
    {   0, 224,  96 },
    {   0, 144, 224 },
    { 255, 224,  64 },
    { 192,  96, 180 },
    { 255, 144, 176 },
    { 160, 255,  96 },
    { 255, 180,  64 },
    {   0,   0,   0 },
    {   0,   0,   0 },
    {   0,   0,   0 },
    {   0,   0,   0 },
};

/* 16-color RGB888 alternate font palette (16 x { R, G, B }) */
static u8 g_font_alt_palette_rgb[48] = {
      0,   0,   0,
     48,  48,  50,
     56,  56,  64,
    104, 104, 104,
    136, 248, 224,
      0, 104,  88,
      0,  72,  72,
    224, 128, 184,
    216,  48, 104,
    144,  48,  48,
    176, 168, 224,
    112, 104, 200,
    248, 176, 240,
    200,  96, 176,
     96,  96, 104,
    255, 255, 255,
};
extern PaletteColor g_font_alt_clut[32];
extern PaletteColor g_font_cluts[20][16];
extern u8 g_glyph_upload_buf[32][512];

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

u64 sjis_to_jis(u64 shiftJis)
{
    u64 leadByte = (shiftJis >> 8) & 0xFF;
    u64 trailByte = shiftJis & 0xFF;

    if (leadByte >= 0x81 && leadByte < 0xA0) {
        leadByte -= 0x81;
    } else if (leadByte >= 0xE0 && leadByte < 0xF0) {
        leadByte += 0xFFFFFFFFFFFFFF3FULL;
    }

    leadByte <<= 1;
    if (trailByte >= 0x40 && trailByte < 0x7F) {
        trailByte -= 0x40;
    } else if (trailByte >= 0x80 && trailByte < 0x9F) {
        trailByte += 0xFFFFFFFFFFFFFFBFULL;
    } else if (trailByte >= 0x9F && trailByte < 0xFD) {
        trailByte -= 0x9F;
        leadByte++;
    }

    return ((leadByte + 1) << 8) + trailByte + 0x2021;
}

void font_init_clut_table(void)
{
    s32 colorIndex;
    s32 paletteIndex;
    s32 rgbOffset;
    s32 column;

    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        column = g_font_luma_table[colorIndex];
        g_font_cluts[0][colorIndex].red = (g_font_cluts[0][colorIndex].green = (g_font_cluts[0][colorIndex].blue = column));
        g_font_cluts[0][colorIndex].alpha = g_font_alpha_table[colorIndex];
    }

    paletteIndex = 1;
    do {
        font_upload_alt_clut(paletteIndex);
    } while ((++paletteIndex) < 9);

    paletteIndex = 9;
    do {
        font_upload_clut(paletteIndex);
    } while ((++paletteIndex) < 17);

    for (rgbOffset = 0, colorIndex = 0; colorIndex < 16; colorIndex++) {
        g_font_alt_clut[colorIndex].red = g_font_alt_palette_rgb[rgbOffset++];
        g_font_alt_clut[colorIndex].green = g_font_alt_palette_rgb[rgbOffset++];
        g_font_alt_clut[colorIndex].blue = g_font_alt_palette_rgb[rgbOffset++];
        if (colorIndex == 0) {
            g_font_alt_clut[colorIndex].alpha = 0;
        } else {
            g_font_alt_clut[colorIndex].alpha = 0x80;
        }
    }

    for (rgbOffset = 0; rgbOffset < 32; rgbOffset++) {
        for (column = 0; column < 512; column++) {
            g_glyph_upload_buf[rgbOffset][column] = 0;
        }
    }
}

void font_upload_clut(s32 paletteIndex)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        g_font_cluts[paletteIndex][i].red = (g_font_alt_luma_table[i] * g_font_palette_rgb[paletteIndex][0]) / 6;
        g_font_cluts[paletteIndex][i].green = (g_font_alt_luma_table[i] * g_font_palette_rgb[paletteIndex][1]) / 6;
        g_font_cluts[paletteIndex][i].blue = (g_font_alt_luma_table[i] * g_font_palette_rgb[paletteIndex][2]) / 6;
        g_font_cluts[paletteIndex][i].alpha = g_font_outline_alpha_table[i];
    }

    for (i = 8; i < 16; i++) {
        g_font_cluts[paletteIndex][i].red = (g_font_palette_rgb[0][0] * g_font_alt_luma_table[i]) / 6;
        g_font_cluts[paletteIndex][i].green = (g_font_palette_rgb[0][1] * g_font_alt_luma_table[i]) / 6;
        g_font_cluts[paletteIndex][i].blue = (g_font_palette_rgb[0][2] * g_font_alt_luma_table[i]) / 6;
        g_font_cluts[paletteIndex][i].alpha = 0x80;
    }
}

void font_upload_alt_clut(s32 paletteIndex)
{
    s32 i;
    u32 gray;
    s32 j;

    for (i = 0; i < 8; i++) {
        gray = g_font_alt_alpha_table[i];
        g_font_cluts[paletteIndex][i].red = gray;
        g_font_cluts[paletteIndex][i].green = gray;
        g_font_cluts[paletteIndex][i].blue = gray;
        g_font_cluts[paletteIndex][i].alpha = g_font_alpha_table[i];
    }

    for (j = 8; j < 16; j++) {
        g_font_cluts[paletteIndex][j].red = (g_font_alt_alpha_table[j] * g_font_palette_rgb[paletteIndex][0]) / 6;
        g_font_cluts[paletteIndex][j].green = (g_font_alt_alpha_table[j] * g_font_palette_rgb[paletteIndex][1]) / 6;
        g_font_cluts[paletteIndex][j].blue = (g_font_alt_alpha_table[j] * g_font_palette_rgb[paletteIndex][2]) / 6;
        g_font_cluts[paletteIndex][j].alpha = g_font_alpha_table[j];
    }
}

void font_init(void)
{
    s32 entryIndex;
    u8 *clutBytes;
    s16 cbp;

    font_init_clut_table();
    clutBytes = (u8 *)g_font_cluts;
    for (entryIndex = 0; entryIndex < 17; entryIndex++, clutBytes += 0x40) {
        cbp = (s64)(entryIndex + 0x37E8);
        sceGsSetDefLoadImage(&g_gs_load_image, cbp, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, clutBytes);
        sceGsSyncPath(0, 0);
    }

    sceGsSetDefLoadImage(&g_gs_load_image, 0x37FA, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, g_font_alt_clut);
    sceGsSyncPath(0, 0);
    glyph_cache_init();
}

void font_upload_default_cluts(void)
{
    s32 resourceIndex;
    PaletteColor (*resourceBuffer)[16];

    *T0_COUNT = 0;
    g_vram_load_buf = memalign(0x40, 0x300000);
    printf("mozi buf[%x] size[%d]\n", g_vram_load_buf, 0x2D9248);
    g_font_glyph_buf = g_vram_load_buf;
    font_init_clut_table();

    resourceBuffer = g_font_cluts;
    for (resourceIndex = 0; resourceIndex < 17; resourceIndex++, resourceBuffer++) {
        sceGsSetDefLoadImage(&g_gs_load_image, (s16)(0x37E8 + resourceIndex), 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, *resourceBuffer);
        sceGsSyncPath(0, 0);
    }

    sceGsSetDefLoadImage(&g_gs_load_image, 0x37FA, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(&g_gs_load_image, g_font_alt_clut);
    sceGsSyncPath(0, 0);
    glyph_cache_init();
    tex_upload_reset();
}

s8 *g_font_glyph_buf;
PaletteColor g_font_cluts[20][16] __attribute__((aligned(64)));
PaletteColor g_font_alt_clut[32] __attribute__((aligned(64)));
