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
    s32 paletteOffset = paletteIndex * 64;
    u8 *red = D_00132980 + paletteOffset;
    u8 *green = D_00132981 + paletteOffset;
    u8 *blue = D_00132982 + paletteOffset;
    u8 *alpha = D_00132983 + paletteOffset;
    u8 *colorEntry = red + 32;
    u8 *intensity = D_00128F60 + 8;
    u8 *opacity = D_00128F40 + 8;
    u8 *tint = D_00128F90 + paletteIndex * 3;
    s32 redScale;
    s32 greenScale;
    s32 blueScale;
    s32 entry;
    u8 gray;

    gray = D_00128F60[0];
    red[0] = gray;
    green[0] = gray;
    blue[0] = gray;
    alpha[0] = D_00128F40[0];

    gray = D_00128F60[1];
    red[4] = gray;
    green[4] = gray;
    blue[4] = gray;
    alpha[4] = D_00128F40[1];

    gray = D_00128F60[2];
    red[8] = gray;
    green[8] = gray;
    blue[8] = gray;
    alpha[8] = D_00128F40[2];

    gray = D_00128F60[3];
    red[12] = gray;
    green[12] = gray;
    blue[12] = gray;
    alpha[12] = D_00128F40[3];

    gray = D_00128F60[4];
    red[16] = gray;
    green[16] = gray;
    blue[16] = gray;
    alpha[16] = D_00128F40[4];

    gray = D_00128F60[5];
    red[20] = gray;
    green[20] = gray;
    blue[20] = gray;
    alpha[20] = D_00128F40[5];

    gray = D_00128F60[6];
    red[24] = gray;
    green[24] = gray;
    blue[24] = gray;
    alpha[24] = D_00128F40[6];

    gray = D_00128F60[7];
    red[28] = gray;
    green[28] = gray;
    blue[28] = gray;
    alpha[28] = D_00128F40[7];

    redScale = tint[0];
    greenScale = tint[1];
    blueScale = tint[2];

    entry = 8;
    do {
        colorEntry[0] = (*intensity * redScale) / 6;
        colorEntry[1] = (*intensity * greenScale) / 6;
        colorEntry[2] = (*intensity++ * blueScale) / 6;
        colorEntry[3] = *opacity++;
        colorEntry += 4;
        entry++;
    } while (entry < 16);
}
