#include "common.h"

void func_0019C5B0(void);
extern u16 D_0026B390[];
extern u8 D_0028E294;
extern u16 D_002BB378_as_u16_a[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001A44C0(void) {
    u16 idx;

    reg_a6 = (u8 *)D_002BB378_as_u16_a;
    reg_a0 = (u8 *)D_0026B390;
    if (D_0028E294 != 0) {
        reg_d1.w = 0x62000A80;
    } else {
        reg_d1.w = 0x53000A80;
    }
    reg_d7.w = 4;
    do {
        reg_d0.h[0] = *(u16 *)reg_a6;
        reg_a6 += 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        idx = reg_d0.h[0] & 0xFFFF;
        reg_d2.h[0] = ((idx + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(idx + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = ((idx + 4) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(idx + 4) & ~1)) : *(u16 *)reg_a0;
        reg_d4.h[0] = ((idx + 6) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(idx + 6) & ~1)) : *(u16 *)reg_a0;
        func_0019C5B0();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
