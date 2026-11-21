#include "common.h"

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} PaletteColor;

extern u8 D_00128F40[];
extern u8 D_00128F50[];
extern u8 D_00128FD0[];
extern PaletteColor D_00132900[];
extern PaletteColor D_00132980[];
extern u8 D_001A0A80[32][512];

extern void func_0011CBA0(s32 paletteIndex);
extern void func_0011CD30(s32 paletteIndex);

void func_0011C990(void)
{
    s32 colorIndex;
    s32 paletteIndex;
    s32 row;
    s32 column;

    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        D_00132980[colorIndex].red = D_00132980[colorIndex].green =
            D_00132980[colorIndex].blue = D_00128F50[colorIndex];
        D_00132980[colorIndex].alpha = D_00128F40[colorIndex];
    }

    for (paletteIndex = 1; paletteIndex < 9; paletteIndex++) {
        func_0011CD30(paletteIndex);
    }

    for (paletteIndex = 9; paletteIndex < 17; paletteIndex++) {
        func_0011CBA0(paletteIndex);
    }

    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        D_00132900[colorIndex].red = D_00128FD0[colorIndex * 3];
        D_00132900[colorIndex].green = D_00128FD0[colorIndex * 3 + 1];
        D_00132900[colorIndex].blue = D_00128FD0[colorIndex * 3 + 2];
        if (colorIndex == 0) {
            D_00132900[colorIndex].alpha = 0;
        } else {
            D_00132900[colorIndex].alpha = 0x80;
        }
    }

    for (row = 0; row < 32; row++) {
        for (column = 511; column >= 0; column--) {
            D_001A0A80[row][column] = 0;
        }
    }
}
