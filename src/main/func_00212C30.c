#include "gallery/gallery.h"

typedef struct {
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} PaletteColor;

void func_002128A0(s32 paletteIndex);
void func_00212AB0(s32 paletteIndex);
extern u8 D_0026F7A0[];
extern PaletteColor D_002C0180[];
extern u8 D_0026F830[];
extern PaletteColor D_002C0200[][16];
extern u8 D_0026F7B0[];
extern u8 D_00578780[][512];

void func_00212C30(void)
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
        func_002128A0(paletteIndex);
    } while ((++paletteIndex) < 9);

    paletteIndex = 9;
    do {
        func_00212AB0(paletteIndex);
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
