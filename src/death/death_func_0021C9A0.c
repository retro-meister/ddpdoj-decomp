#include "common.h"

s32 func_00125310();
s32 death_func_0021B180();
s32 func_00129450();
s32 func_00171400();
s32 death_func_0021C8A0();
s32 func_00201100();
s32 func_002027A0();
extern s16 D_00262A50[];
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void death_func_0021C9A0(void) {
    s16 *t1;
    s16 *t2;
    u16 t3;
    u16 t4;
    u8 t5;
    u8 t6;

    if (D_0028E89C != 0) {
        death_func_0021C8A0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            D_0028E44C = (s16 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(D_0028E44C);
        }
        t1 = (s16 *)(reg_a0);
        if (0 <= (s64)*(s16 *)((u8 *)(t1) + (0))) {
            t2 = (s16 *)(reg_a1);
            if (0 > *t2) {
                reg_a0 = (u8 *)(t2);
                D_0028E44C = (s16 *)(t1);
                reg_a1 = (u8 *)(t1);
                goto next_1;
            }
        } else {
next_1:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            reg_d0.w = (u32) *(u16 *)(reg_a6 + 2);
            t3 = *(u16 *)(reg_a6 + 4);
            reg_d1.w = (u32) t3;
            if ((s32) reg_d0.h[0] <= (s32) reg_d2.h[0]) {
                func_002027A0();
                reg_d0.w = 0x80013;
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d3.w = 0;
                reg_d4.w = 0;
                func_00201100();
                reg_d5.b[0] = (u8) ((s8) reg_d5.b[0] >> 1);
                reg_d1.b[0] += reg_d5.b[0];
                func_00129450();
                reg_d1.b[0] -= 2;
                reg_d0.w += 0x40000;
                func_00129450();
                reg_d1.b[0] += 4;
                reg_d0.w += 0x40000;
                func_00129450();
            }
            t6 = 6;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d7.w = 6;
            reg_d1.h[0] -= 0x2D;
            reg_a1 = (u8 *)(D_00262A50);
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d4.w = 0x02020020;
                reg_d3.w += reg_d6.w;
                reg_d5.h[0] = 0x42;
                func_00129450();
                t4 = reg_d0.h[0];
                reg_d4.w = 0x2C03FFE0;
                reg_d0.h[0] += 1;
                reg_d1.b[0] += 0x80;
                reg_d5.h[0] = 0x2E;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] -= 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                func_00129450();
                reg_d1.b[0] += 0x80;
                reg_d0.h[0] -= 1;
                reg_d1.h[0] += 0xF;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = reg_a4[0x10];
            if (0 > (s8) reg_d1.b[0]) {
                goto next_21;
            }
            reg_a4[0x11] += reg_d1.b[0];
            if (*(s8 *)(reg_a4 + 0x11) > 0x30) {
                goto next_22;
            }
            goto next_23;
next_21:
            reg_a4[0x11] += reg_d1.b[0];
            if (*(s8 *)(reg_a4 + 0x11) >= -0x30) {
                goto next_23;
            }
next_22:
            reg_a4[0x10] *= -1;
next_23:;
        }
        func_00171400();
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            death_func_0021C8A0();
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            t5 = *(u8 *)(reg_a6 + 0xf);
            if ((s32) t5 < 0x28) {
                *(u8 *)(reg_a6 + 0xf) = (u8) (t5 + 0x14);
            }
            if (death_func_0021B180()) {
                reg_d0.w = 0x18;
            } else {
                reg_d0.w = 0x19;
            }
            func_00125310();
        }
    }
}
