#include "common.h"

extern s8 D_0028E408;

s32 func_00136BB0();
extern u16 D_0029BC00[];
extern u16 D_0029BD7C[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a5;

void func_00136A40(void) {
    reg_a0 = (u8 *)D_0029BC00;
    reg_d0.w = 9;
loop_0:
    if (*(u16 *)reg_a0 == 0) goto next_0;
    reg_a0 += 0x26;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_a1 += 0xC;
    reg_tmp.w = (u32)reg_a1;
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    D_0028E408 = 1;
    reg_d0.w = 0;
    reg_d0.h[0] -= 1;
    return;
next_0:
    reg_d1.h[1] = *(u16 *)(reg_a5 + 6);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 8);
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_tmp.w = (u32)reg_a1;
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    D_0029BD7C[0] += 1;
    func_00136BB0();
}
