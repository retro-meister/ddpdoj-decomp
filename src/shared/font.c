#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern void *D_0028E9C8;
extern s32 D_0029CAB0[];
extern s32 D_0029CAB4[];
void func_00215FF0(void *, s32, s32);

void font_load_async(void) {
    func_00215FF0(D_0028E9C8, D_0029CAB0[0], D_0029CAB4[0]);
}

void font_upload_palettes(void);
void font_init_palettes(void);
s32 func_002182F0();
s32 func_00218D90();
extern void *D_0028E9D8;

void font_init(void) {
    *(s32 *)0x10000000 = 0;
    D_0028E9C8 = memalign(0x40, 0x300000);
    printf("mozi buf[%x] size[%d]\n", D_0028E9C8, 0x2D9248);
    D_0028E9D8 = D_0028E9C8;
    font_init_palettes();
    font_upload_palettes();
    func_002182F0();
    func_00218D90();
}

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} PaletteColor;

extern PaletteColor D_002C0180[];
extern PaletteColor D_002C0200[][16];
extern sceGsLoadImage D_0057C780;

void font_upload_palettes(void) {
    s32 entryIndex;
    s32 offset;
    s16 cbp;

    for (entryIndex = 0, offset = 0; entryIndex < 17; entryIndex++, offset += 0x40) {
        cbp = (s64)(entryIndex + 0x37E8);
        sceGsSetDefLoadImage(&D_0057C780, cbp, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
        FlushCache(0);
        sceGsExecLoadImage(&D_0057C780, (u8 *)D_002C0200 + offset);
        sceGsSyncPath(0, 0);
    }

    sceGsSetDefLoadImage(&D_0057C780, 0x37FA, 1, SCE_GS_PSMCT32, 0, 0, 8, 2);
    FlushCache(0);
    sceGsExecLoadImage(&D_0057C780, (u8 *)D_002C0180);
    sceGsSyncPath(0, 0);
}


extern u8 D_0026F7A0[];
extern u8 D_0026F7C0[];
extern u8 D_0026F7F0[][3];
extern PaletteColor D_002C0200[][16];

void font_make_tint_palette(s32 paletteIndex)
{
    s32 i;
    u32 gray;
    s32 j;

    for (i = 0; i < 8; i++) {
        gray = D_0026F7C0[i];
        D_002C0200[paletteIndex][i].red = gray;
        D_002C0200[paletteIndex][i].green = gray;
        D_002C0200[paletteIndex][i].blue = gray;
        D_002C0200[paletteIndex][i].alpha = D_0026F7A0[i];
    }

    for (j = 8; j < 16; j++) {
        D_002C0200[paletteIndex][j].red = (D_0026F7C0[j] * D_0026F7F0[paletteIndex][0]) / 6;
        D_002C0200[paletteIndex][j].green = (D_0026F7C0[j] * D_0026F7F0[paletteIndex][1]) / 6;
        D_002C0200[paletteIndex][j].blue = (D_0026F7C0[j] * D_0026F7F0[paletteIndex][2]) / 6;
        D_002C0200[paletteIndex][j].alpha = D_0026F7A0[j];
    }
}

extern u8 D_0026F7E0[];
extern u8 D_0026F7D0[];

void font_make_highlight_palette(s32 paletteIndex)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        D_002C0200[paletteIndex][i].red = (D_0026F7E0[i] * D_0026F7F0[paletteIndex][0]) / 6;
        D_002C0200[paletteIndex][i].green = (D_0026F7E0[i] * D_0026F7F0[paletteIndex][1]) / 6;
        D_002C0200[paletteIndex][i].blue = (D_0026F7E0[i] * D_0026F7F0[paletteIndex][2]) / 6;
        D_002C0200[paletteIndex][i].alpha = D_0026F7D0[i];
    }

    for (i = 8; i < 16; i++) {
        D_002C0200[paletteIndex][i].red = (D_0026F7F0[0][0] * D_0026F7E0[i]) / 6;
        D_002C0200[paletteIndex][i].green = (D_0026F7F0[0][1] * D_0026F7E0[i]) / 6;
        D_002C0200[paletteIndex][i].blue = (D_0026F7F0[0][2] * D_0026F7E0[i]) / 6;
        D_002C0200[paletteIndex][i].alpha = 0x80;
    }
}

void font_make_tint_palette(s32 paletteIndex);
void font_make_highlight_palette(s32 paletteIndex);
extern PaletteColor D_002C0180[];
extern u8 D_0026F830[];
extern u8 D_0026F7B0[];
extern u8 D_00578780[][512];

void font_init_palettes(void)
{
    s32 colorIndex;
    s32 paletteIndex;
    s32 rgbOffset;
    s32 column;

    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        PaletteColor *color = &D_002C0200[0][colorIndex];
        column = D_0026F7B0[colorIndex];
        color->red = (color->green = (color->blue = column));
        color->alpha = D_0026F7A0[colorIndex];
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
        D_002C0180[colorIndex].red = D_0026F830[rgbOffset++];
        D_002C0180[colorIndex].green = D_0026F830[rgbOffset++];
        D_002C0180[colorIndex].blue = D_0026F830[rgbOffset++];
        if (colorIndex == 0) {
            D_002C0180[colorIndex].alpha = 0;
        } else {
            D_002C0180[colorIndex].alpha = 0x80;
        }
    }

    for (colorIndex = 0; colorIndex < 32; colorIndex++) {
        for (column = 0; column < 512; column++) {
            D_00578780[colorIndex][column] = 0;
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
