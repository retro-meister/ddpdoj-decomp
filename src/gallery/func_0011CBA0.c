#include "common.h"

extern u8 D_00128F70[];
extern u8 D_00128F80[];
extern u8 D_00128F90[][3];
extern u8 D_00132980[][16][4];

void func_0011CBA0(s32 paletteIndex)
{
    s32 i;

    for (i = 0; i < 8; i++) {
        D_00132980[paletteIndex][i][0] = (D_00128F80[i] * D_00128F90[paletteIndex][0]) / 6;
        D_00132980[paletteIndex][i][1] = (D_00128F80[i] * D_00128F90[paletteIndex][1]) / 6;
        D_00132980[paletteIndex][i][2] = (D_00128F80[i] * D_00128F90[paletteIndex][2]) / 6;
        D_00132980[paletteIndex][i][3] = D_00128F70[i];
    }

    for (i = 8; i < 16; i++) {
        D_00132980[paletteIndex][i][0] = (D_00128F90[0][0] * D_00128F80[i]) / 6;
        D_00132980[paletteIndex][i][1] = (D_00128F90[0][1] * D_00128F80[i]) / 6;
        D_00132980[paletteIndex][i][2] = (D_00128F90[0][2] * D_00128F80[i]) / 6;
        D_00132980[paletteIndex][i][3] = 0x80;
    }
}
