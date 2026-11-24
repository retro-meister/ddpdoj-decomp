#include "common.h"

s32 func_00128970();
s32 func_0014E030();
s32 func_002011A0();
extern u8 D_00259870_as_u8_a[];
extern u16 D_0028E3DC;
extern s16 D_0029F1F0[];
extern u16 D_0029F1F2[];
extern s16 D_0029F260[];
extern u16 D_0029F262[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001FE330(void) {
    u16 t1;
    u16 t2;
    if (*(u16 *)(reg_a6 + 0x66) != 0) {
        if (*(u16 *)(reg_a6 + 0x6C) == 1) {
            *(u16 *)(reg_a6 + 0x68) = 0x800U;
            *(u16 *)(reg_a6 + 0x6C) = 0U;
        }
        if (*(u16 *)(reg_a6 + 0x6C) == 2) {
            *(u16 *)(reg_a6 + 0x6A) = 0x800U;
            *(u16 *)(reg_a6 + 0x6C) = 0U;
        }
        if (*(u16 *)(reg_a6 + 0x6C) == 0) {
            if (D_0028E3DC == 0) {
                reg_d0.w = 0;
                if (D_0029F260[0] < 0) {
                    reg_d0.h[0] = D_0029F262[0];
                }
                reg_d1.w = 0;
                if (D_0029F1F0[0] < 0) {
                    reg_d1.h[0] = D_0029F1F2[0];
                }
                if ((s32) reg_d0.h[0] <= (s32) reg_d1.h[0]) {
                    reg_d0.h[0] = reg_d1.h[0];
                }
                reg_d1.h[0] = *(u16 *)(reg_a6 + 2);
                reg_d1.h[0] -= 0x400;
                if ((s32) reg_d1.h[0] <= (s32) reg_d0.h[0]) {
                    reg_d7.h[0] = 0x24;
                    reg_d0.w = 0x10007;
                    reg_d1.h[0] = 0x2E;
                    reg_d2.h[1] = *(u16 *)(reg_a6 + 2);
                    reg_d2.h[0] = *(u16 *)(reg_a6 + 4);
                    reg_a0 = (u8 *)D_00259870_as_u8_a;
                    reg_d5.w = 0;
                    do {
                        reg_d3.h[0] = reg_d1.h[0];
                        reg_d3.h[0] &= 0x3F;
                        reg_d3.h[0] *= 4;
                        reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a0;
                        reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
                        reg_d3.w += reg_d5.w;
                        func_00128970();
                        reg_d1.b[0] += 1;
                        reg_d1.h[0] &= 0x3F;
                    } while ((s16)(--reg_d7.h[0]) >= 0);
                }
            }
            reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x6F);
            *(u8 *)(reg_a6 + 0x6F) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a6 + 0x6F) = (u8) *(u8 *)(reg_a6 + 0x6E);
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x68);
                reg_d0.h[0] += *(u16 *)(reg_a6 + 0x6A);
                if (reg_d0.h[0] == 0) {
                    func_002011A0();
                    reg_d0.h[0] &= 1;
                    if (reg_d0.h[0] == 0) {
                        reg_d0.w = 0x50;
                        func_0014E030();
                        reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
                        reg_d0.w += 0xF47FFC00;
                        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                        *(u16 *)(reg_a6 + 0x6C) = 1;
                    } else {
                        reg_d0.w = 0x50;
                        func_0014E030();
                        reg_d0.h[1] = *(u16 *)(reg_a6 + 2);
                        reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
                        reg_d0.w += 0xF4800400;
                        *(u16 *)(reg_a0 + 0x16) = (u16) reg_d0.h[1];
                        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d0.h[0];
                        *(u16 *)(reg_a6 + 0x6C) = 2;
                    }
                }
            }
        }
    }
    t1 = *(u16 *)(reg_a6 + 0x68);
    if (t1 != 0) {
        *(u16 *)(reg_a6 + 0x68) = (u16) (t1 - 0x80);
        if ((s16) *(u16 *)(reg_a6 + 0x68) <= 0) {
            *(u16 *)(reg_a6 + 0x68) = 0U;
        }
    }
    t2 = *(u16 *)(reg_a6 + 0x6A);
    if (t2 != 0) {
        *(u16 *)(reg_a6 + 0x6A) = (u16) (t2 - 0x80);
        if ((s16) *(u16 *)(reg_a6 + 0x6A) <= 0) {
            *(u16 *)(reg_a6 + 0x6A) = 0U;
        }
    }
}
