#include "common.h"

s32 func_00125310();
s32 func_00129410();
s32 func_00171400();
s32 func_001EE0F0();
s32 func_001EE1C0();
s32 func_001EE290();
s32 func_001EE390();
extern u16 D_00262A50[];
extern u16 D_00264600[];
extern u16 D_00264620[];
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EE540(void) {
    u32 t1;
    u32 t2;
    u32 t3;
    u8 t4;
    u8 t5;
    u8 t6;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if (reg_tmp.b[0] == 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 9);
        *(s8 *)(reg_a6 + 0x3F) = 1;
        *(s8 *)(reg_a6 + 0x5F) = 1;
        *(s8 *)(reg_a6 + 0x7F) = 1;
        *(s8 *)(reg_a6 + 0x9F) = 1;
        *(s8 *)(reg_a6 + 0xBF) = 1;
        *(s8 *)(reg_a6 + 0xDF) = 1;
        reg_a3 = (u8 *)(D_00264600);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x3A);
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1B);
        func_001EE290();
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x5A);
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1A);
        func_001EE1C0();
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x7A);
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1D);
        func_001EE0F0();
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0x9A);
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1C);
        func_001EE290();
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0xBA);
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1F);
        func_001EE1C0();
        reg_d1.h[0] = *(u16 *)(reg_a6 + 0xDA);
        reg_d2.b[0] = *(u8 *)(reg_a4 + 0x1E);
        func_001EE0F0();
        if (*(u8 *)(reg_a4 + 5) == 0) {
            reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
            reg_a1 = (u8 *)(D_00262A50);
            reg_a3 = (u8 *)(D_00264620);
            reg_d6.w = 5;
            do {
                reg_d7.w = 6;
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1D8);
                reg_d0.h[0] += *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                reg_d0.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d1.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d1.h[0] -= 0x18;
                reg_d5.h[1] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d5.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                do {
                    reg_d3.h[0] = reg_d1.h[0];
                    reg_d3.h[0] += 2;
                    reg_d3.h[0] &= 0xFC;
                    reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
                    reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                    reg_d3.w += reg_d5.w;
                    func_00129410();
                    reg_d1.h[0] += 8;
                } while ((s16)(--reg_d7.h[0]) >= 0);
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            func_001EE390();
            t1 = *(u16 *)(reg_a4 + 0xA);
            if ((s16)(t1) < 0x10) {
                *(u16 *)(reg_a4 + 0xA) = (u16) (t1 + 1);
            }
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 8);
            *(s8 *)(reg_a6 + 0x3F) = 0;
            *(s8 *)(reg_a6 + 0x5F) = 0;
            *(s8 *)(reg_a6 + 0x7F) = 0;
            *(s8 *)(reg_a6 + 0x9F) = 0;
            *(s8 *)(reg_a6 + 0xBF) = 0;
            *(s8 *)(reg_a6 + 0xDF) = 0;
            func_00171400();
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
            *(u8 *)(reg_a4 + 7) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
                t4 = *(u8 *)(reg_a6 + 0x1C7);
                if ((s32) t4 < 6) {
                    *(u8 *)(reg_a6 + 0x1C7) = (u8) (t4 + 2);
                }
                t5 = *(u8 *)(reg_a6 + 0x1C9);
                if ((s32) t5 < 2) {
                    *(u8 *)(reg_a6 + 0x1C9) = (u8) (t5 + 1);
                }
                t6 = *(u8 *)(reg_a6 + 0x1C8);
                if ((s32) t6 < 0x20) {
                    *(u8 *)(reg_a6 + 0x1C8) = (u8) (t6 + 8);
                }
                t2 = *(u16 *)(reg_a6 + 0x1CA);
                if ((s16)(t2) < 0x10) {
                    *(u16 *)(reg_a6 + 0x1CA) = (u16) (t2 + 1);
                }
                t3 = *(u16 *)(reg_a6 + 0x1D8);
                if ((s16)(t3) < 8) {
                    *(u16 *)(reg_a6 + 0x1D8) = (u16) (t3 + 2);
                }
                reg_d0.w = 0;
                func_00125310();
            }
        }
    }
}
