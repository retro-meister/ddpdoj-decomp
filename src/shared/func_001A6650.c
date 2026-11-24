#include "common.h"

s32 func_0011C7C0();
s32 func_001A53D0();
s32 func_001A5400();
s32 func_001A5430();
s32 func_001A5960();
s32 func_001A59B0();
s32 func_001A5B50();
s32 func_001A6510();
s32 func_001A6B70();
s32 func_001A6BE0();
s32 func_001A6E70();
s32 func_001AC950();
s32 func_001AC9D0();
extern u32 D_0028E484;
extern s16 D_0028E628;
extern s16 D_0028E62C;
extern u16 D_0028E630;
extern u8 D_0028E634;
extern u16 D_0028E648;
extern s16 D_0028E684;
extern s16 D_0028E6B8;
extern s16 D_0028E6C4;
extern s16 D_0028E8C0;
extern s16 D_0028E8C4;

void func_001A6650(void) {
    u8 flags;

    flags = D_0028E634;
    if ((s8)flags >= 0) goto next_0;
    func_001A5B50();
    return;
next_0:
    if (flags & 8) goto next_5;
    if (flags & 1) goto next_2;
    D_0028E634 |= 1;
    D_0028E630 = 0x38;
    D_0028E628 = 0x10;
    D_0028E62C = 8;
    if (!(D_0028E634 & 2)) {
        D_0028E634 |= 2;
        goto next_1;
    }
    if (!(D_0028E634 & 4)) {
        D_0028E634 |= 4;
        goto next_1;
    }
    reg_d0.h[0] = 0xD4;
    reg_d1.h[0] = 0;
    reg_d2.w = 6;
    reg_d3.w = 0x1B;
    func_0011C7C0();
    goto next_2;
next_1:
    D_0028E634 &= 0xFE;
next_2:
    func_001A6E70();
    reg_d1.h[0] = 0x75C0;
    reg_d2.w = 0xCA2;
    reg_d3.h[0] = 0x2E0;
    reg_d4.h[0] = 9;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d1.h[0] -= reg_d6.h[0];
    D_0028E484 = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = 0;
    func_001A53D0();
    reg_d7.h[0] = reg_d6.h[0];
    func_001A5960();
    func_001A59B0();
    D_0028E630 -= 1;
    if (D_0028E630 != 0) {
        func_001A6510();
        return;
    }
    D_0028E634 |= 8;
    D_0028E630 = 0x41;
    func_001A6510();
    return;
next_5:
    if (D_0028E648 == 0) goto next_7;
    reg_d6.h[0] = D_0028E630;
    if (D_0028E630 == 0) goto next_6;
    D_0028E630 -= 1;
    reg_d6.h[0] = D_0028E630;
    reg_d6.h[0] <<= 6;
    reg_d6.h[0] *= 0xFFFF;
next_6:
    func_001A6B70();
    func_001A6BE0();
    func_001A6E70();
    func_001A6510();
    return;
next_7:
    D_0028E634 |= 0x80;
    D_0028E6C4 = 0;
    D_0028E684 = 0;
    D_0028E6B8 = 0;
    func_001A6E70();
    if (D_0028E8C4 < 0) goto next_8;
    func_001AC950();
    func_001A5400();
next_8:
    if (D_0028E8C0 < 0) {
        func_001A6510();
        return;
    }
    func_001AC9D0();
    func_001A5430();
    func_001A6510();
}
