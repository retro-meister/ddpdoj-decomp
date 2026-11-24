#include "common.h"

s32 func_00129410();
s32 func_002026F0();
extern u16 D_00259570[];
extern u16 D_0028E89C;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D9D40(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
        if (D_0028E89C == 0) {
            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x102);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 0x104);
            func_002026F0();
            *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
            reg_a0 = (u8 *)(D_00259570);
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
            reg_d1.b[0] = (u8) ((s8) reg_d1.b[0] >> 2);
            reg_d1.b[0] += 1;
            reg_d1.h[0] &= 0x3E;
            reg_d3.h[0] = reg_d1.h[0];
            reg_d3.h[0] += reg_d3.h[0];
            reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
            reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
            reg_d0.w = 0xFFFC000B;
            reg_d2.h[1] = *(u16 *)(reg_a6 + 0x102);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x104);
            reg_d4.w = 0;
            func_00129410();
            reg_d6.w = 2;
            do {
                reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
                func_00129410();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] += *(u8 *)(reg_a4 + 7);
            reg_d0.w -= 0x40000;
            reg_d0.h[0] = 0xB;
            reg_d6.w = 5;
            do {
                reg_d1.b[0] += *(u8 *)(reg_a4 + 9);
                func_00129410();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d0.w = 0xFFFC000B;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 6);
            reg_d6.w = 2;
            do {
                reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
                func_00129410();
            } while ((s16)(--reg_d6.h[0]) >= 0);
            reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
            reg_d1.b[0] -= *(u8 *)(reg_a4 + 7);
            reg_d0.w -= 0x40000;
            reg_d0.h[0] = 0xB;
            reg_d6.w = 5;
            do {
                reg_d1.b[0] -= *(u8 *)(reg_a4 + 9);
                func_00129410();
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
    }
}
