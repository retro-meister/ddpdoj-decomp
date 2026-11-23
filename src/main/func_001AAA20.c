#include "common.h"

s32 func_0011C4A0();
extern u16 D_0026BFF0[];
extern u16 D_0028E5BC;
extern u16 D_0028E5F8;
extern s8 D_0028E634;
extern u8 D_0028E635;
extern u8 D_0028E854;
extern u8 *reg_a0;

void func_001AAA20(void) {
    reg_d0.h[0] = 0xC8;
    reg_d1.h[0] = 0x1400;
    if ((D_0028E854 & 1) && (D_0028E634 >= 0)) {
        if (D_0028E635 & 0x10) {
            reg_d0.h[0] = 0xCC;
            reg_d1.h[0] = 0x1600;
            goto block_4;
        }
    } else {
block_4:
        reg_d2.h[0] = 2;
        reg_d3.h[0] = 5;
        if (D_0028E5F8 == 0) {
            reg_d4.h[0] = D_0028E5BC;
            reg_a0 = (u8 *)(D_0026BFF0);
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[0] += reg_d4.h[0];
            reg_d4.h[1] = (reg_d4.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d4.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d4.h[0] = ((reg_d4.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            func_0011C4A0();
            return;
        }
        reg_d4.w = 0x0414000A;
        func_0011C4A0();
    }
}
