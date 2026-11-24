#include "common.h"

s32 func_00125310();
s32 func_00129450();
s32 func_00171400();
s32 func_001EB300();
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

void func_001EB440(s16 *arg1) {
    s16 *t1;
    s16 *t2;
    u32 t3;
    u32 t4;
    u16 t5;
    u8 t6;

    t2 = (s16 *)(arg1);
    if (D_0028E89C != 0) {
        func_001EB300();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        if (*(u8 *)(reg_a4 + 5) & 1) {
            reg_a0 = (u8 *)(D_0029F260);
            reg_a1 = (u8 *)(D_0029F1F0);
            if (*(u8 *)(reg_a5 + 2) != 0) {
                D_0028E44C = (s16 *)(reg_a0);
                reg_a0 = (u8 *)(reg_a1);
                reg_a1 = (u8 *)(D_0028E44C);
            }
            t1 = (s16 *)(reg_a0);
            if (0 <= (s64)*(s16 *)t1) {
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
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 4);
                reg_d0.h[0] += 0x7FFF + 0x70C1;
                func_002027A0();
                reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
                reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
                reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                reg_d5.w = 0xF0C00000;
                reg_d7.w = 6;
                reg_d1.h[0] -= 0x36;
                reg_a1 = (u8 *)(D_00262A50);
                reg_d4.w = 0;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                    reg_d3.w += reg_d5.w;
                    func_00129450();
                    reg_d1.h[0] += 0x12;
                } while ((s16)(--reg_d7.h[0]) >= 0);
                func_00171400();
                goto next_2;
            }
        } else {
next_2:
            t5 = 0xC;
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x11);
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d5.w = 0xF0C00000;
            reg_d7.w = 0xC;
            reg_d1.h[0] -= 0x3C;
            reg_a1 = (u8 *)(D_00262A50);
            reg_d4.w = 0;
            do {
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : (u16) *(s16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d5.w;
                func_00129450();
                t5 = (u32)reg_d1.h[0] + 0xA;
                reg_d1.h[0] = t5;
            } while ((s16)(--reg_d7.h[0]) >= 0);
            reg_d1.b[0] = reg_a4[0x10];
            if (!(0 > (s8) reg_d1.b[0])) {
                goto next_31;
            }
            reg_a4[0x11] += reg_d1.b[0];
            if ((s32) reg_a4[0x11] < 0x50) {
                goto next_32;
            }
            goto next_33;
next_31:
            reg_a4[0x11] += reg_d1.b[0];
            if ((s32) reg_a4[0x11] <= 0xB0) {
                goto next_33;
            }
next_32:
            reg_a4[0x10] *= -1;
next_33:;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            t6 = *(u8 *)(reg_a6 + 0x1DB);
            if ((s32) t6 < 0x28) {
                *(u8 *)(reg_a6 + 0x1DB) = (u8) (t6 + 0xA);
            }
            t3 = *(u16 *)(reg_a6 + 0x1DC);
            if ((s16)(t3) < 4) {
                *(u16 *)(reg_a6 + 0x1DC) = (u16) (t3 + 1);
            }
            t4 = *(u16 *)(reg_a6 + 0x1DE);
            if ((s16)(t4) < 0x1A) {
                *(u16 *)(reg_a6 + 0x1DE) = (u16) (t4 + 1);
            }
            reg_d0.w = 5;
            func_00125310();
        }
    }
}
