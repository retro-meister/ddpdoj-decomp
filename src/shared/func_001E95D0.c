#include "common.h"

s32 func_00125310();
s32 func_00129280();
s32 func_001E9150();
s32 func_001E9220();
s32 func_001E9320();
s32 func_001E9420();
s32 func_001E94A0();
extern u16 D_00262A50[];
extern u16 D_00264160[];
extern u16 D_00264180[];
extern u16 D_0028E89C;
extern u8 *reg_a1;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E95D0(void) {
    u32 t1;
    u32 t2;
    u32 t3;
    u32 t4;
    u32 t5;
    u32 t6;
    u8 t7;
    u8 t8;
    u8 t9;

    if (D_0028E89C != 0) {
        func_001E94A0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if (reg_tmp.b[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (9)));
        (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 1;
        (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 1;
        reg_a3 = (u8 *)(D_00264160);
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x3A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1B)));
        func_001E9320();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x5A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1A)));
        func_001E9220();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x7A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1D)));
        func_001E9150();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x9A)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1C)));
        func_001E9320();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xBA)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1F)));
        func_001E9220();
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xDA)));
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0x1E)));
        func_001E9150();
        if ((*(u8 *)((u8 *)(reg_a4) + (5))) == 0) {
            reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_a1 = (u8 *)(D_00262A50);
            reg_a3 = (u8 *)(D_00264180);
            reg_d6.w = 5;
            do {
                reg_d7.w = 8;
                reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1D8)));
                reg_d0.h[0] += *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_tmp.w = reg_d0.w;
                reg_d0.h[1] = reg_tmp.h[0];
                reg_d0.h[0] = reg_tmp.h[1];
                t2 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d0.h[0] = t2;
                reg_d1.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d1.h[0] -= 0x20;
                t3 = *(u16 *)reg_a3;
                reg_a3 += 2;
                reg_d5.h[1] = t3;
                reg_d5.h[0] = *(u16 *)reg_a3;
                reg_a3 += 2;
loop_6:
                reg_d3.h[0] = reg_d1.h[0];
                reg_d3.h[0] += 2;
                reg_d3.h[0] &= 0xFC;
                reg_d3.h[1] = (reg_d3.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d3.h[0] & ~1)) : *(u16 *)reg_a1;
                reg_d3.h[0] = ((reg_d3.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(reg_d3.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                reg_d3.w += reg_d5.w;
                if (reg_d7.w & 1) {
                    func_00129280();
                } else {
                    func_00129280();
                }
                reg_d1.h[0] += 8;
                t4 = reg_d7.h[0] - 1;
                reg_d7.h[0] = t4;
                if (((s64) ((s64) (t4 & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                    goto loop_6;
                }
            } while ((s16)(--reg_d6.h[0]) >= 0);
        }
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            func_001E9420();
            t1 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
            if ((s16)(t1) < 0x10) {
                (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) (t1 + 1);
            }
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (8)));
            (*(s8 *)((u8 *)(reg_a6) + (0x3F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x5F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x7F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xBF))) = 0;
            (*(s8 *)((u8 *)(reg_a6) + (0xDF))) = 0;
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
            (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
                (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
                t7 = (*(u8 *)((u8 *)(reg_a6) + (0x1C7)));
                if ((s32) t7 < 6) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1C7))) = (u8) (t7 + 2);
                }
                t8 = (*(u8 *)((u8 *)(reg_a6) + (0x1C9)));
                if ((s32) t8 < 3) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1C9))) = (u8) (t8 + 1);
                }
                t9 = (*(u8 *)((u8 *)(reg_a6) + (0x1C8)));
                if ((s32) t9 < 0x20) {
                    (*(u8 *)((u8 *)(reg_a6) + (0x1C8))) = (u8) (t9 + 8);
                }
                t5 = (*(u16 *)((u8 *)(reg_a6) + (0x1CA)));
                if ((s16)(t5) < 0x10) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1CA))) = (u16) (t5 + 1);
                }
                t6 = (*(u16 *)((u8 *)(reg_a6) + (0x1D8)));
                if ((s16)(t6) < 4) {
                    (*(u16 *)((u8 *)(reg_a6) + (0x1D8))) = (u16) (t6 + 1);
                }
                reg_d0.w = 0;
                func_00125310();
            }
        }
    }
}
