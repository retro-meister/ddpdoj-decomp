#include "common.h"

s32 death_func_0021B180(void);
s32 func_00125310();
s32 func_00129450();
s32 func_00171400();
s32 death_func_0021BE80();
s32 func_00201E20();
s32 func_002027A0();
extern s16 D_00262A50[];
extern s16 *D_0028E44C;
extern u16 D_0028E890;
extern u16 D_0028E894;
extern u16 D_0028E89C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void death_func_0021BFC0(void) {
    s16 *t1;
    u8 t2;
    u8 t3;

    if (death_func_0021B180()) {
        reg_d0.w = 0x14;
    } else {
        reg_d0.w = 0x15;
    }
    func_00125310();
    if (D_0028E89C != 0) {
        death_func_0021BE80();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        if (*(u8 *)(reg_a4 + 4) == reg_d0.b[0]) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if (*(u8 *)(reg_a5 + 2) != 0) {
                D_0028E44C = (s16 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(D_0028E44C);
            }
            t1 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)((u8 *)(t1) + (0))) {
                if (0 > *(s16 *)reg_a1) {
                    reg_a0 = (u8 *)(reg_a1);
                    D_0028E44C = (s16 *)(t1);
                    reg_a1 = (u8 *)(t1);
                    goto next_1;
                }
            } else {
next_1:
                reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
                reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 2);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 4);
                reg_d0.h[0] += 0x7FFF + 0x7A01;
                func_002027A0();
                *(u8 *)(reg_a4 + 0x1B) = (u8) reg_d1.b[0];
                goto next_2;
            }
        } else {
next_2:
            reg_d1.w = 0;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x1B);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x18);
            func_00201E20();
            D_0028E894 = reg_d2.h[0];
            D_0028E890 = reg_d3.h[0];
            func_00171400();
            t3 = 0xFA000000;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0xF);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0x10);
            reg_tmp.w = reg_d4.w;
            reg_d4.h[1] = reg_tmp.h[0];
            reg_d4.h[0] = reg_tmp.h[1];
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_d5.h[0] = *(u16 *)(reg_a4 + 0x14);
            reg_tmp.w = reg_d5.w;
            reg_d5.h[1] = reg_tmp.h[0];
            reg_d5.h[0] = reg_tmp.h[1];
            reg_d5.h[0] = *(u16 *)(reg_a4 + 0x16);
            reg_d6.w = 0xFA000000;
            reg_d7.w = 7;
            reg_a1 = (u8 *)(D_00262A50);
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d6.w;
                func_00129450();
                reg_d1.b[0] += 0x20;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0xE);
            *(u8 *)(reg_a4 + 0xF) += reg_d1.b[0];
            *(u16 *)(reg_a4 + 0x18) += 1;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 4) += 1;
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 0xE) *= -1;
            *(u16 *)(reg_a4 + 0x18) = 0x12U;
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 8) -= 4;
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x1C);
            reg_d0.h[0] += 1;
            if ((s32) reg_d0.h[0] > 2) {
                reg_d0.h[0] = 0;
            }
            *(u16 *)(reg_a4 + 0x1C) = (u16) reg_d0.h[0];
            reg_d0.h[0] += 2;
            *(u16 *)(reg_a4 + 0x12) = (u16) reg_d0.h[0];
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                t2 = *(u8 *)(reg_a6 + 0xE);
                if ((s32) t2 < 4) {
                    *(u8 *)(reg_a6 + 0xE) = (u8) (t2 + 2);
                }
                if (death_func_0021B180()) {
                    reg_d0.w = 0x14;
                } else {
                    reg_d0.w = 0x15;
                }
                func_00125310();
            }
        }
    }
}
