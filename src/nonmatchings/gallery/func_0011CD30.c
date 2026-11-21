#include "common.h"

extern u8 D_00128F40[];
extern u8 D_00128F60[];
extern u8 D_00128F90[];
extern u8 D_00132980[];
extern u8 D_00132981[];
extern u8 D_00132982[];
extern u8 D_00132983[];

void func_0011CD30(s32 paletteIndex)
{
    u8 gray = D_00128F60[0];
    s32 paletteOffset = paletteIndex * 64;
    u8 *red = D_00132980 + paletteOffset;
    u8 *intensity = D_00128F60 + 8;
    s32 entry = 8;
    u8 *green = D_00132981 + paletteOffset;
    u8 *colorEntry = red + 32;
    u8 *blue = D_00132982 + paletteOffset;
    u8 *alpha;
    u8 *tint;
    u8 *opacity;
    u8 firstAlpha;
    s32 redScale;
    s32 greenScale;
    s32 blueScale;

    blue[0] = green[0] = red[0] = gray;
    firstAlpha = D_00128F40[0];
    alpha = D_00132983 + paletteOffset;
    tint = D_00128F90 + paletteIndex * 3;
    opacity = D_00128F40 + 8;
    alpha[0] = firstAlpha;

    blue[4] = green[4] = red[4] = D_00128F60[1];
    alpha[4] = D_00128F40[1];

    blue[8] = green[8] = red[8] = D_00128F60[2];
    alpha[8] = D_00128F40[2];

    blue[12] = green[12] = red[12] = D_00128F60[3];
    alpha[12] = D_00128F40[3];

    blue[16] = green[16] = red[16] = D_00128F60[4];
    alpha[16] = D_00128F40[4];

    blue[20] = green[20] = red[20] = D_00128F60[5];
    alpha[20] = D_00128F40[5];

    blue[24] = green[24] = red[24] = D_00128F60[6];
    alpha[24] = D_00128F40[6];

    blue[28] = green[28] = red[28] = D_00128F60[7];
    alpha[28] = D_00128F40[7];

    redScale = tint[0];
    greenScale = tint[1];
    blueScale = tint[2];

    do {
        colorEntry[0] = (*intensity * redScale) / 6;
        colorEntry[1] = (*intensity * greenScale) / 6;
        colorEntry[2] = (*intensity * blueScale) / 6;
        intensity++;
        colorEntry[3] = *opacity;
        opacity++;
        colorEntry += 4;
    } while (++entry < 16);
}
