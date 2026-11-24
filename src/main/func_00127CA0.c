#include "common.h"

void func_002010A0(void);
void func_00201D10(void);
extern u8 D_00269708[];
extern u16 D_0029C06C[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_00127CA0(void) {
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x10);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x12);
    reg_a0 = (u8 *)D_00269708;
    reg_a0 = *(u8 **)(D_00269708 + (reg_d0.h[0] & ~3));
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 = reg_a6;
    reg_a2 = (u8 *)reg_tmp.w;
    *(u16 *)(reg_a6 + 0) &= 0xF8DF;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 0x06000000;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[0];
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_a1 += 2;
    *(u16 *)(reg_a1 + 0) = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *)(reg_a6 + 0x12) = 0x10;
    *(s16 *)(reg_a6 + 0x14) = 0x202;
    *(u16 *)(reg_a6 + 0x16) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(s8 *)(reg_a6 + 0x19) = 7;
    *(s8 *)(reg_a6 + 0x18) = 0xF;
    *(s16 *)(reg_a6 + 0x1C) = 0x1D;
    reg_d0.h[0] = D_0029C06C[0];
    reg_d0.h[0] = (s16)reg_d0.h[0] + *(s16 *)(reg_a6 + 4);
    reg_d1.w = 0x30;
    if ((s32)reg_d0.h[0] < 0x1C00) {
        reg_d1.w = 0x10;
    }
    func_002010A0();
    if ((s8)reg_d0.b[0] < 0) {
        reg_d0.b[0] *= -1;
    }
    reg_d0.h[0] &= 6;
    reg_d0.h[0] += 6;
    func_00201D10();
    *(u16 *)(reg_a6 + 0x1A) = reg_d3.h[0];
}
