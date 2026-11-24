#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

extern s16 D_0026F900[];
extern s16 D_00269140[];
extern s16 D_002554B0[];
extern s16 D_0058D800[];
extern s32 D_0028EA78;
void func_00218990(u8 *destination, s32 mode, s32 blockCount);

void func_00218D90(void)
{
    s16 *source;
    s16 *palette;
    s32 colorIndex;

    source = D_0026F900;
    palette = D_0058D800;
    for (colorIndex = 0; colorIndex < 16; colorIndex++) {
        palette[colorIndex] = *source++;
    }
    D_0028EA78 = 0x3832;
    func_00218990((u8 *)D_0058D800, 0, 1);

    source = D_00269140;
    palette = D_0058D800;
    for (colorIndex = 0; colorIndex < 15; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    D_0028EA78 = 0x3830;
    func_00218990((u8 *)D_0058D800, 0, 1);

    source = D_002554B0;
    palette = D_0058D800;
    for (colorIndex = 0; colorIndex < 31; colorIndex++) {
        palette[colorIndex] = *source++ | 0x8000;
    }
    palette[colorIndex] = *source;
    D_0028EA78 = 0x383A;
    func_00218990((u8 *)D_0058D800, 1, 1);
}
