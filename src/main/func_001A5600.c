#include "common.h"

s32 func_001A53D0();
s32 func_001A53F0();
extern u8 D_0026BFD0[];
extern u8 D_0028DAF0[];
extern u16 D_0028E5BC;
extern u16 D_0028E5F8;
extern u16 D_0029F248[];
extern u8 *reg_a0;

void func_001A5600(void) {
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = D_0029F248[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0028DAF0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d4.h[0] = 1;
loop_0:
    func_001A53F0();
    reg_d1.h[0] -= 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.w = reg_d5.w;
next_0:
    if (D_0028E5F8 != 0) goto next_1;
    reg_d1.h[0] += 0xF500;
    reg_d1.h[1] += 0x100;
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    reg_d2.h[0] = D_0028E5BC;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0026BFD0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53D0();
next_1:
    return;
}
