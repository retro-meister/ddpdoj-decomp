#include "common.h"

s32 func_00125310();
s32 func_001292C0();
s32 func_00129370();
s32 func_001293C0();
s32 func_00171400();
s32 func_002027A0();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001CF800(void) {
    s16 *t1;
    s16 *t2;
    s16 *v1;
    u16 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u16 t7;
    u32 t8;
    u32 t9;
    u8 t10;
    u8 t11;
    u8 t12;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 7);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            t1 = (s16 *)(reg_a1);
            reg_a1 = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(t1);
        }
        v1 = (s16 *)(reg_a0);
        if ((*(s16 *)((u8 *)(v1) + (0))) >= 0) {
            t2 = (s16 *)(reg_a1);
            if (*t2 < 0) {
                reg_a1 = (u8 *)(v1);
                reg_a0 = (u8 *)(t2);
                goto next_1;
            }
        } else {
next_1:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            t8 = reg_d2.w;
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            t9 = reg_d3.w;
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d0.h[0] += 0x400;
            reg_d1.h[0] += 0x7FFF + 0x7D01;
            func_002027A0();
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d4.w = 0;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d3.w = 0x0400FD00;
            func_001292C0();
            reg_d2.w = t8;
            reg_d3.w = t9;
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d0.h[0] += 0x400;
            reg_d1.h[0] += 0x300;
            func_002027A0();
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d4.w = 0;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 8);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xA);
            reg_d3.w = 0x04000300;
            func_001292C0();
            func_00171400();
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x19);
            reg_d6.h[0] = reg_d1.h[0];
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d3.w = 0xFE00FD00;
            reg_d4.w = 0;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            func_00129370();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_d1.h[0] += 4;
            func_00129370();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            t3 = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = t3;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] += 4;
            func_00129370();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            t4 = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = t4;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] += 4;
            func_00129370();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] *= -1;
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_d3.h[0] = 0x300;
            func_00129370();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x12);
            reg_d1.h[0] -= 4;
            func_00129370();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xC);
            t5 = *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = t5;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] -= 4;
            func_00129370();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x10);
            t6 = *(u16 *)(reg_a4 + 0x12);
            reg_d0.h[0] = t6;
            reg_d0.w -= 0x80000;
            reg_d1.h[0] -= 4;
            func_00129370();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0x14);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0x16);
            reg_d1.b[0] = *(u8 *)(reg_a4 + 0x18);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d3.w = 0xF800FD00;
            func_001293C0();
            reg_d1.h[0] -= 0x10;
            func_001293C0();
            reg_d1.h[0] -= 0x10;
            func_001293C0();
            reg_d3.h[0] = 0x300;
            reg_d1.b[0] *= -1;
            func_001293C0();
            reg_d1.h[0] -= 0x10;
            func_001293C0();
            reg_d1.h[0] -= 0x10;
            func_001293C0();
            reg_d0.b[0] = reg_a4[0x1D];
            reg_a4[0x19] -= reg_d0.b[0];
            if (reg_a4[0x19] > 0xC0) {
                reg_a4[0x19] = 0xC0;
                goto next_11;
            }
            if (reg_a4[0x19] >= 0x40) {
                goto skip_1;
            }
            reg_a4[0x19] = 0x40;
next_11:
            reg_a4[0x1D] *= -1;
skip_1:
            reg_d0.b[0] = reg_a4[0x1C];
            reg_a4[0x18] -= reg_d0.b[0];
            if (reg_a4[0x18] > 0xC0) {
                reg_a4[0x18] = 0xC0;
                goto next_12;
            }
            if (reg_a4[0x18] >= 0x40) {
                goto skip_2;
            }
            reg_a4[0x18] = 0x40;
next_12:
            reg_a4[0x1C] *= -1;
skip_2:;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if (reg_tmp.b[0] == 0) {
            t10 = *(u8 *)(reg_a6 + 0x107);
            if ((s32) t10 < 0x60) {
                *(u8 *)(reg_a6 + 0x107) = (u8) (t10 + 0x10);
            }
            t11 = *(u8 *)(reg_a6 + 0x106);
            if ((s32) t11 < 4) {
                *(u8 *)(reg_a6 + 0x106) = (u8) (t11 - 2);
            }
            t7 = *(u16 *)(reg_a6 + 0x108);
            if ((s32) t7 < 5) {
                *(u16 *)(reg_a6 + 0x108) = (u16) (t7 + 1);
            }
            t12 = *(u8 *)(reg_a6 + 0x10B);
            if ((s32) t12 < 0xA) {
                *(u8 *)(reg_a6 + 0x10B) = (u8) (t12 + 2);
            }
            reg_d0.w = 4;
            func_00125310();
            reg_d0.w = 3;
            func_00125310();
        }
    }
}
