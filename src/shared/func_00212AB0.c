#include "gallery/gallery.h"

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} PaletteColor;

extern u8 D_0026F7E0[];
extern PaletteColor D_002C0200[][16];
extern u8 D_0026F7D0[];
extern u8 D_0026F7F0[][3];

void func_00212AB0(s32 paletteIndex)
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
