#include "common.h"

void func_0019C530(void);
extern u16 D_002629B0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001BDEE0(void) {
    reg_a0 = (u8 *)D_002629B0;
    reg_d2.h[0] = *(u16 *)(reg_a6 + 8);
    reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[1] += 0x1600;
    reg_d1.h[0] += 0x7FFF + 0x7401;
    reg_d1.h[1] += 0x7FFF + 0x6601;
    reg_d3.h[0] = 0x1A60;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x1C);
    func_0019C530();
}
