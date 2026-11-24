#include "common.h"

extern u32 D_002A17C0[];
extern u8 D_002A3C80[];
extern u8 D_002B4D50[];
extern u8 *reg_a0;

void func_0011C4A0(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;
    u32 t;
    s32 t2;

    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    reg_a0 = (u8 *)D_002A17C0[0];
    reg_tmp.w = (u32)reg_a0;
    if (reg_tmp.w == (u32)D_002A3C80) goto block_rts;
    reg_d5.w = 0;
loop_1:
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
loop_2:
    reg_tmp.w = (u32)D_002B4D50;
    *(u32 *)reg_a0 = (u32)D_002B4D50;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.h[0] += reg_d0.h[0];
    reg_tmp.w += reg_d5.w;
    *(u32 *)reg_a0 = reg_tmp.w;
    reg_a0 += 4;
    *(u32 *)reg_a0 = reg_d4.w;
    reg_a0 += 4;
    reg_d4.w += 0x10000;
    reg_d6.h[0] += 0x100;
    t2 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t2;
    if (((s64) ((s64) (u16) t2 << 0x30) >> 0x30) >= 0) goto loop_2;
    reg_d0.h[0] -= 4;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    *(u32 *)reg_a0 = -1;
    D_002A17C0[0] = (u32)reg_a0;
block_rts:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
}
