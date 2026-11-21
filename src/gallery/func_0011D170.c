#include "common.h"

extern s16 D_00128BE0[];
extern s16 D_00128CE0[];
extern s16 D_001290A0[];
extern s32 D_0012B314;
extern s16 D_00135280[];

extern void func_0011D3B0(s16 *palette, s32 mode, s32 count);

void func_0011D170(void)
{
    s16 *source;
    s16 *palette;
    s32 colorIndex;

    source = D_001290A0;
    palette = D_00135280;
    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        palette[colorIndex] = *source++;
    }
    D_0012B314 = 0x3832;
    func_0011D3B0(D_00135280, 0, 1);

    palette = D_00135280;
    source = D_00128CE0;
    for (colorIndex = 0; colorIndex < 15; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    D_0012B314 = 0x3830;
    func_0011D3B0(D_00135280, 0, 1);

    palette = D_00135280;
    source = D_00128BE0;
    for (colorIndex = 0; colorIndex < 31; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    D_0012B314 = 0x383A;
    func_0011D3B0(D_00135280, 1, 1);
}
