#include "common.h"

s32 func_001D01D0();
extern u16 D_002594F0[];
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D03B0(void) {
    u16 var_a0_3;
    u8 *var_a0_4;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        reg_a3 = (u8 *)(D_002594F0);
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xB0)));
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] &= 0x3E;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d3.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_d3.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_d3.w += 0x11000080;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        var_a0_3 = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_d4.w = (u32) reg_a6;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d2.h[0] = var_a0_3;
        reg_d4.w += 0x20;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] -= (*(u16 *)((u8 *)(reg_a4) + (0x10)));
        reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
        do {
            if (!(reg_d7.w & 1)) {
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (6)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
                func_001D01D0();
                reg_d0.w += 0x30000;
                func_001D01D0();
                reg_d0.w += 0xFFFD0000;
            } else {
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                func_001D01D0();
            }
            reg_d1.b[0] += 4;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
        var_a0_4 = (u8 *)(reg_a6);
        reg_a3 = (u8 *)(D_002594F0);
        reg_d1.h[0] = (*(u16 *)((u8 *)(var_a0_4) + (0xB2)));
        reg_d3.w = 0x1100FF80;
        reg_d5.h[0] = reg_d1.h[0];
        reg_d5.h[0] &= 0x3E;
        reg_d5.h[0] += reg_d5.h[0];
        reg_d2.h[1] = (*(u16 *)((u8 *)(var_a0_4) + (0x42)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(var_a0_4) + (0x44)));
        reg_d1.h[0] += reg_d1.h[0];
        reg_d4.w = (u32) var_a0_4;
        reg_d4.w += 0x40;
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a4) + (0x10)));
        reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xE)));
        do {
            if (!(reg_d7.w & 1)) {
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (6)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
                func_001D01D0();
                reg_d0.w += 0x30000;
                func_001D01D0();
                reg_d0.w += 0xFFFD0000;
            } else {
                reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xC)));
                func_001D01D0();
            }
            var_a0_4 = (u8 *)(reg_d1.b[0] - 4);
            reg_d1.b[0] = (u8) var_a0_4;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}
