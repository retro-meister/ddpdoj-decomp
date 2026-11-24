#include "common.h"

s32 func_0019C730();
extern u16 D_00259170[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001554E0(void) {
    u16 temp_a1;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x5E))) == 0) {
        reg_d2.w = 0;
        reg_a0 = (u8 *)(D_00259170);
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5A)));
        reg_d2.b[0] += 1;
        reg_d2.h[0] &= 0x3E;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
        temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
        reg_d1.h[0] = temp_a1;
        reg_d1.w += 0xFA00FC00;
        reg_d3.h[0] = 0x620;
        reg_d4.w = 0;
        reg_d4.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x5C)));
        func_0019C730();
    }
}
