#include "common.h"

extern u16 D_0024EC80[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0012F4C0(void) {
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0xFE00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x210;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_a1 = (u8 *)(D_0024EC80);
    reg_d0.b[0] += 4;
    reg_d0.h[0] &= 0xF8;
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d1.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d1.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x12))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_tmp.h[0];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) -= 4;
}
