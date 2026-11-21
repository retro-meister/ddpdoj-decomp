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

static u8 g_font_alt_palette_rgb[48] = {
      0,   0,   0,  48,  48,  50,  56,  56,  64, 104, 104, 104,
    136, 248, 224,   0, 104,  88,   0,  72,  72, 224, 128, 184,
    216,  48, 104, 144,  48,  48, 176, 168, 224, 112, 104, 200,
    248, 176, 240, 200,  96, 176,  96,  96, 104, 255, 255, 255,
};
extern PaletteColor D_00132900[16];
extern PaletteColor D_00132980[17][16];
extern u8 g_glyph_upload_buf[32][512];

void font_build_gs_setup_packet(void *packetPtr)
{
    GalleryTexturePacket *packet = packetPtr;
    packet->startTag.quadword = 0;
    packet->startTag.header = 0x10000008;
    packet->gifTag = 0x1000000000008007ULL;
    packet->gifRegisters = 0x0E;
    packet->texflush = 0;
    packet->texflushRegister = 0x3F;
    packet->tex0 = 0x2006FD06A9443800ULL;
    packet->tex0Register = 0x06;
    packet->tex1 = 0x60;
    packet->tex1Register = 0x14;
    packet->clamp = 0;
    packet->clampRegister = 0x08;
    packet->test = 0x3000F;
    packet->testRegister = 0x47;
    packet->texa = 0x0000008000008080ULL;
    packet->texaRegister = 0x3B;
    packet->alpha = 0x44;
    packet->alphaRegister = 0x42;
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
        D_00132980[0][colorIndex].red = (D_00132980[0][colorIndex].green = (D_00132980[0][colorIndex].blue = column));
        D_00132980[0][colorIndex].alpha = g_font_alpha_table[colorIndex];
    }

    paletteIndex = 1;
first_palette:
    font_upload_alt_clut(paletteIndex);
    if ((++paletteIndex) < 9) {
        goto first_palette;
    }

    paletteIndex = 9;
second_palette:
    font_upload_clut(paletteIndex);
    if ((++paletteIndex) < 17) {
        goto second_palette;
    }

    for (rgbOffset = 0, colorIndex = 0; colorIndex < 16; colorIndex++) {
        D_00132900[colorIndex].red = g_font_alt_palette_rgb[rgbOffset++];
        D_00132900[colorIndex].green = g_font_alt_palette_rgb[rgbOffset++];
        D_00132900[colorIndex].blue = g_font_alt_palette_rgb[rgbOffset++];
        if (colorIndex == 0) {
            D_00132900[colorIndex].alpha = 0;
        } else {
            D_00132900[colorIndex].alpha = 0x80;
        }
    }

    for (rgbOffset = 0; rgbOffset < 32; rgbOffset++) {
        for (column = 0; column < 512; column++) {
            g_glyph_upload_buf[rgbOffset][column] = 16 * 0;
        }
    }
}

void font_upload_clut(s32 paletteIndex)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        D_00132980[paletteIndex][i].red = (g_font_alt_luma_table[i] * g_font_palette_rgb[paletteIndex][0]) / 6;
        D_00132980[paletteIndex][i].green = (g_font_alt_luma_table[i] * g_font_palette_rgb[paletteIndex][1]) / 6;
        D_00132980[paletteIndex][i].blue = (g_font_alt_luma_table[i] * g_font_palette_rgb[paletteIndex][2]) / 6;
        D_00132980[paletteIndex][i].alpha = g_font_outline_alpha_table[i];
    }

    for (i = 8; i < 16; i++) {
        D_00132980[paletteIndex][i].red = (g_font_palette_rgb[0][0] * g_font_alt_luma_table[i]) / 6;
        D_00132980[paletteIndex][i].green = (g_font_palette_rgb[0][1] * g_font_alt_luma_table[i]) / 6;
        D_00132980[paletteIndex][i].blue = (g_font_palette_rgb[0][2] * g_font_alt_luma_table[i]) / 6;
        D_00132980[paletteIndex][i].alpha = 0x80;
    }
}

void font_upload_alt_clut(s32 paletteIndex)
{
    s32 i;
    u32 gray;
    s32 j;

    for (i = 0; i < 8; i++) {
        gray = g_font_alt_alpha_table[i];
        D_00132980[paletteIndex][i].red = gray;
        D_00132980[paletteIndex][i].green = gray;
        D_00132980[paletteIndex][i].blue = gray;
        D_00132980[paletteIndex][i].alpha = g_font_alpha_table[i];
    }

    for (j = 8; j < 16; j++) {
        D_00132980[paletteIndex][j].red = (g_font_alt_alpha_table[j] * g_font_palette_rgb[paletteIndex][0]) / 6;
        D_00132980[paletteIndex][j].green = (g_font_alt_alpha_table[j] * g_font_palette_rgb[paletteIndex][1]) / 6;
        D_00132980[paletteIndex][j].blue = (g_font_alt_alpha_table[j] * g_font_palette_rgb[paletteIndex][2]) / 6;
        D_00132980[paletteIndex][j].alpha = g_font_alpha_table[j];
    }
}

void font_init(void)
{
    s32 entryIndex;
    u8 *galleryEntry;
    short new_var;

    font_init_clut_table();
    entryIndex = 0;
    galleryEntry = (u8 *)D_00132980;
    do {
        new_var = (s64)(entryIndex + 0x37E8);
        sceGsSetDefLoadImage(g_gs_load_image, new_var, 1, 0, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(g_gs_load_image, galleryEntry);
        sceGsSyncPath(0, 0);
        entryIndex++;
        galleryEntry += 0x40;
    } while (entryIndex < 0x11);

    sceGsSetDefLoadImage(g_gs_load_image, 0x37FA, 1, 0, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(g_gs_load_image, D_00132900);
    sceGsSyncPath(0, 0);
    glyph_cache_init();
}

void font_upload_default_cluts(void)
{
    s32 resourceIndex;
    PaletteColor (*resourceBuffer)[16];

    *(volatile u32 *)0x10000000 = 0;
    g_vram_load_buf = memalign(0x40, 0x300000);
    printf("mozi buf[%x] size[%d]\n", g_vram_load_buf, 0x2D9248);
    g_font_glyph_buf = g_vram_load_buf;
    font_init_clut_table();

    resourceBuffer = D_00132980;
    for (resourceIndex = 0; resourceIndex < 17; resourceIndex++, resourceBuffer++) {
        sceGsSetDefLoadImage(g_gs_load_image, (s16)(0x37E8 + resourceIndex), 1, 0, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(g_gs_load_image, *resourceBuffer);
        sceGsSyncPath(0, 0);
    }

    sceGsSetDefLoadImage(g_gs_load_image, 0x37FA, 1, 0, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(g_gs_load_image, D_00132900);
    sceGsSyncPath(0, 0);
    glyph_cache_init();
    tex_upload_reset();
}
