#include "gallery/gallery.h"

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} PaletteColor;

extern u8 D_0026F7A0[];
extern u8 D_0026F7C0[];
extern u8 D_0026F7F0[][3];
extern PaletteColor D_002C0200[][16];

void func_002128A0(s32 paletteIndex)
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
