#include "common.h"

s32 func_00125310();
s32 func_00171400();
s32 func_001EA990();
s32 func_001EA9A0();
s32 func_00201270();
s32 func_002027A0();
extern u16 D_00264320[];
extern s16 *D_0028E44C;
extern u16 D_0028E89C;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001EAAB0(void) {
    s16 *t1;
    s8 t2;
    s8 t3;
    u16 t4;
    u16 t5;
    u16 t6;
    u32 t7;
    u8 t8;
    u8 t9;
    u8 t10;
    u8 t11;

    if (D_0028E89C != 0) {
        func_001EA9A0();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        reg_d0.b[0] = *(u8 *)(reg_a4 + 5);
        t8 = *(u8 *)(reg_a4 + 4);
        if (t8 == reg_d0.b[0]) {
            func_00201270();
            *(u8 *)(reg_a4 + 0x15) = (u8) reg_d0.b[0];
        }
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            D_0028E44C = (s16 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(D_0028E44C);
        }
        if (0 > *(s16 *)reg_a0) {
            goto next_1;
        }
        if (!(0 > *(s16 *)reg_a1)) {
            goto next_2;
        }
        t1 = (s16 *)(reg_a0);
        reg_a0 = (u8 *)(reg_a1);
        D_0028E44C = (s16 *)(t1);
        reg_a1 = (u8 *)(t1);
next_1:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            reg_d6.h[0] = reg_d2.h[0];
            reg_d7.h[0] = reg_d3.h[0];
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_a3 = (u8 *)(D_00264320);
            reg_d4.h[0] = *(u16 *)(reg_a4 + 0xE);
            reg_a3 += reg_d4.h[0];
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0xD00;
            func_002027A0();
            t7 = reg_d1.w;
            reg_d2.h[0] = reg_d6.h[0];
            reg_d3.h[0] = reg_d7.h[0];
            reg_d0.h[0] = *(u16 *)(reg_a6 + 2);
            reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
            reg_d0.h[0] += 0x940;
            reg_d1.h[0] += 0x7FFF + 0x7301;
            func_002027A0();
            reg_d0.h[1] = *(u16 *)(reg_a4 + 0xA);
            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            t5 = *(u16 *)(reg_a6 + 4);
            reg_d2.h[0] = t5;
            t4 = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[1] = t4;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            t2 = (s8) reg_d4.b[0];
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (t2 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d4.w = 0;
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            func_001EA990();
            reg_d1.w = t7;
            reg_d3.h[1] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d3.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            reg_d4.h[0] = *(u16 *)reg_a3;
            reg_a3 += 2;
            t3 = (s8) reg_d4.b[0];
            reg_d5.b[0] = *(u8 *)(reg_a4 + 0x15);
            reg_d4.b[0] = (u8) (t3 >> reg_d5.b[0]);
            reg_d1.b[0] += reg_d4.b[0];
            reg_d6.b[0] = *(u8 *)(reg_a4 + 7);
            reg_d6.b[0] = ~(s8) reg_d6.b[0];
            func_001EA990();
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
            *(u16 *)(reg_a4 + 0xE) -= 0xC;
            if ((s32) reg_tmp.h[0] < 0xC) {
                *(u16 *)(reg_a4 + 0xE) = 0x30U;
            }
next_2:
        *(u16 *)(reg_a4 + 0xA) += 1;
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            func_00171400();
            t11 = *(u8 *)(reg_a4 + 4);
            if ((s32) t11 < 0x1E) {
                *(u8 *)(reg_a4 + 4) = (u8) (t11 + 0xF);
            }
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(u8 *)(reg_a4 + 3) += 4;
            *(u16 *)(reg_a4 + 0x12) += 1;
            *(u16 *)(reg_a4 + 0xA) = (u16) *(u16 *)(reg_a4 + 0x12);
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                t9 = *(u8 *)(reg_a6 + 0x1D7);
                if ((s32) t9 < 2) {
                    *(u8 *)(reg_a6 + 0x1D7) = (u8) (t9 + 1);
                }
                t6 = *(u16 *)(reg_a6 + 0x13E);
                if ((s32) t6 < 6) {
                    *(u16 *)(reg_a6 + 0x13E) = (u16) (t6 + 1);
                }
                t10 = *(u8 *)(reg_a6 + 0x1D6);
                if ((s32) t10 < 0x18) {
                    *(u8 *)(reg_a6 + 0x1D6) = (u8) (t10 + 2);
                }
                reg_d0.w = 3;
                func_00125310();
            }
        }
    }
}
