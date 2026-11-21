#include "common.h"

extern u8 D_00128F40[];
extern u8 D_00128F60[];
extern u8 D_00128F90[][3];
extern u8 D_00132980[][16][4];

void func_0011CD30(s32 paletteIndex)
{
    s32 i;
    u32 gray;
    s32 j;

    for (i = 0; i < 8; i++) {
        gray = D_00128F60[i];
        D_00132980[paletteIndex][i][0] = gray;
        D_00132980[paletteIndex][i][1] = gray;
        D_00132980[paletteIndex][i][2] = gray;
        D_00132980[paletteIndex][i][3] = D_00128F40[i];
    }

    for (j = 8; j < 16; j++) {
        D_00132980[paletteIndex][j][0] = (D_00128F60[j] * D_00128F90[paletteIndex][0]) / 6;
        D_00132980[paletteIndex][j][1] = (D_00128F60[j] * D_00128F90[paletteIndex][1]) / 6;
        D_00132980[paletteIndex][j][2] = (D_00128F60[j] * D_00128F90[paletteIndex][2]) / 6;
        D_00132980[paletteIndex][j][3] = D_00128F40[j];
    }
}
