#include "common.h"

extern s16 D_00128BE0[];
extern s16 D_00128CE0[];
extern s16 D_001290A0[];
extern s32 D_0012B314;
extern s16 D_00135280[];

extern void func_0011D3B0(s16 *palette, s32 mode, s32 count);

void func_0011D170(void)
{
    s32 i;
    s16 *src;
    s16 *dst;

    src = D_001290A0;
    dst = D_00135280;
    for (i = 0; i < 16; i++) {
        dst[i] = *src++;
    }
    D_0012B314 = 0x3832;
    func_0011D3B0(D_00135280, 0, 1);

    dst = D_00135280;
    src = D_00128CE0;
    for (i = 0; i < 15; i++) {
        dst[i] = *src++ | 0x8000;
    }
    dst[i] = *src;
    D_0012B314 = 0x3830;
    func_0011D3B0(D_00135280, 0, 1);

    dst = D_00135280;
    src = D_00128BE0;
    for (i = 0; i < 31; i++) {
        dst[i] = *src++ | 0x8000;
    }
    dst[i] = *src;
    D_0012B314 = 0x383A;
    func_0011D3B0(D_00135280, 1, 1);
}
