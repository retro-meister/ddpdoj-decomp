#include "common.h"

s32 func_0019C730();
extern u8 D_00262910[];
extern u8 D_00262930[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_001BDD40(void) {
    u16 temp_a0;
    u16 temp_a1;
    reg_a0 = reg_a6 + 0x20;
    reg_d7.w = 7;
    do {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
        if (reg_d0.h[0] != 0x8000) {
            reg_a1 = (u8 *)D_00262930;
            reg_a1 += (*(u16 *)((u8 *)(reg_a0) + (0x30)));
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d1.h[0] = temp_a0;
            reg_d1.w += 0xFA00FC00;
            reg_d3.h[0] = 0x620;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x1C)));
            func_0019C730();
            reg_a1 = (u8 *)D_00262910;
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0xA)));
            reg_d2.h[1] = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d2.h[0] & ~1)) : (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a0) + (2)));
            temp_a1 = (*(u16 *)((u8 *)(reg_a0) + (4)));
            reg_d1.h[0] = temp_a1;
            reg_d1.w += 0xFC00FC00;
            reg_d3.h[0] = 0x420;
            reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0x1C)));
            func_0019C730();
        }
        reg_a0 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
