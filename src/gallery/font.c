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

extern u8 D_00128F40[];
extern u8 D_00128F50[];
extern u8 D_00128F60[];
extern u8 D_00128F70[];
extern u8 D_00128F80[];
extern u8 D_00128F90[][3];
extern u8 D_00128FD0[];
extern char D_0012AE00[];
extern void *D_0012B300;
extern void *D_0012B30C;
extern PaletteColor D_00132900[16];
extern PaletteColor D_00132980[17][16];
extern u8 D_001A0A80[32][512];
extern u8 D_001A4A80[];

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
        column = D_00128F50[colorIndex];
        D_00132980[0][colorIndex].red = (D_00132980[0][colorIndex].green = (D_00132980[0][colorIndex].blue = column));
        D_00132980[0][colorIndex].alpha = D_00128F40[colorIndex];
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
        D_00132900[colorIndex].red = D_00128FD0[rgbOffset++];
        D_00132900[colorIndex].green = D_00128FD0[rgbOffset++];
        D_00132900[colorIndex].blue = D_00128FD0[rgbOffset++];
        if (colorIndex == 0) {
            D_00132900[colorIndex].alpha = 0;
        } else {
            D_00132900[colorIndex].alpha = 0x80;
        }
    }

    for (rgbOffset = 0; rgbOffset < 32; rgbOffset++) {
        for (column = 0; column < 512; column++) {
            D_001A0A80[rgbOffset][column] = 16 * 0;
        }
    }
}

void font_upload_clut(s32 paletteIndex)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        D_00132980[paletteIndex][i].red = (D_00128F80[i] * D_00128F90[paletteIndex][0]) / 6;
        D_00132980[paletteIndex][i].green = (D_00128F80[i] * D_00128F90[paletteIndex][1]) / 6;
        D_00132980[paletteIndex][i].blue = (D_00128F80[i] * D_00128F90[paletteIndex][2]) / 6;
        D_00132980[paletteIndex][i].alpha = D_00128F70[i];
    }

    for (i = 8; i < 16; i++) {
        D_00132980[paletteIndex][i].red = (D_00128F90[0][0] * D_00128F80[i]) / 6;
        D_00132980[paletteIndex][i].green = (D_00128F90[0][1] * D_00128F80[i]) / 6;
        D_00132980[paletteIndex][i].blue = (D_00128F90[0][2] * D_00128F80[i]) / 6;
        D_00132980[paletteIndex][i].alpha = 0x80;
    }
}

void font_upload_alt_clut(s32 paletteIndex)
{
    s32 i;
    u32 gray;
    s32 j;

    for (i = 0; i < 8; i++) {
        gray = D_00128F60[i];
        D_00132980[paletteIndex][i].red = gray;
        D_00132980[paletteIndex][i].green = gray;
        D_00132980[paletteIndex][i].blue = gray;
        D_00132980[paletteIndex][i].alpha = D_00128F40[i];
    }

    for (j = 8; j < 16; j++) {
        D_00132980[paletteIndex][j].red = (D_00128F60[j] * D_00128F90[paletteIndex][0]) / 6;
        D_00132980[paletteIndex][j].green = (D_00128F60[j] * D_00128F90[paletteIndex][1]) / 6;
        D_00132980[paletteIndex][j].blue = (D_00128F60[j] * D_00128F90[paletteIndex][2]) / 6;
        D_00132980[paletteIndex][j].alpha = D_00128F40[j];
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
        sceGsSetDefLoadImage(D_001A4A80, new_var, 1, 0, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(D_001A4A80, galleryEntry);
        sceGsSyncPath(0, 0);
        entryIndex++;
        galleryEntry += 0x40;
    } while (entryIndex < 0x11);

    sceGsSetDefLoadImage(D_001A4A80, 0x37FA, 1, 0, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(D_001A4A80, D_00132900);
    sceGsSyncPath(0, 0);
    glyph_cache_init();
}

void font_upload_default_cluts(void)
{
    s32 resourceIndex;
    PaletteColor (*resourceBuffer)[16];

    *(volatile u32 *)0x10000000 = 0;
    D_0012B300 = memalign(0x40, 0x300000);
    printf(D_0012AE00, D_0012B300, 0x2D9248);
    D_0012B30C = D_0012B300;
    font_init_clut_table();

    resourceBuffer = D_00132980;
    for (resourceIndex = 0; resourceIndex < 17; resourceIndex++, resourceBuffer++) {
        sceGsSetDefLoadImage(D_001A4A80, (s16)(0x37E8 + resourceIndex), 1, 0, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(D_001A4A80, *resourceBuffer);
        sceGsSyncPath(0, 0);
    }

    sceGsSetDefLoadImage(D_001A4A80, 0x37FA, 1, 0, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(D_001A4A80, D_00132900);
    sceGsSyncPath(0, 0);
    glyph_cache_init();
    tex_upload_reset();
}
