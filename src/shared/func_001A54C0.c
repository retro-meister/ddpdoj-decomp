#include "common.h"

s32 func_001A53D0();
s32 func_001A53F0();
extern u8 D_0026BFD0[];
extern u8 D_0028DAE8[];
extern u16 D_0028E5C0;
extern u16 D_0028E5FC;
extern u16 D_0029F2B8[];
extern u8 *reg_a0;

void func_001A54C0(void) {
    u32 save_d1;

    save_d1 = reg_d1.w;
    if ((s16)reg_d0.h[0] < 0) goto next_0;
    reg_d5.w = reg_d1.w;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0xFE00;
    reg_d2.h[0] = D_0029F2B8[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0028DAE8;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    reg_d4.h[0] = 0;
loop_0:
    func_001A53F0();
    reg_d1.h[0] += 0x200;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_d1.w = reg_d5.w;
next_0:
    if (D_0028E5FC != 0) goto next_1;
    reg_d1.h[0] += 0xFF00;
    reg_d1.h[1] += 0x100;
    reg_d3.h[0] = 0x430;
    reg_d4.h[0] = 9;
    reg_d2.h[0] = D_0028E5C0;
    reg_d2.h[0] += reg_d2.h[0];
    reg_d2.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_0026BFD0;
    reg_d2.w = *(u32 *)(reg_a0 + reg_d2.h[0]);
    func_001A53D0();
next_1:
    reg_d1.w = save_d1;
}
