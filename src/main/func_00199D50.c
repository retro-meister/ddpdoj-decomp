#include "common.h"

s32 func_0019C670();
s32 func_0019C6D0();
extern u16 D_0025BE90[];
extern u16 D_0025BEA0[];
extern u16 D_0025BEB0[];
extern u16 D_0025BED0[];
extern u16 D_0025BEF0[];
extern u16 D_0025BF00[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a4;

void func_00199D50(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_a0_3;
    u16 temp_a1_3;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_a3_2;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_a2_2;

    (*(u8 *)((u8 *)(reg_a4) + (0x23))) -= 1;
    if (0 > (s64)*(s8 *)((u8 *)(reg_a4) + (0x23))) {
        (*(u8 *)((u8 *)(reg_a4) + (0x23))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x22)));
        (*(u16 *)((u8 *)(reg_a4) + (0x24))) -= 4;
        if (0 > (s16) (*(u16 *)((u8 *)(reg_a4) + (0x24)))) {
            (*(u16 *)((u8 *)(reg_a4) + (0x24))) = 0xCU;
        }
    }
    do {
        (*(u8 *)((u8 *)(reg_a4) + (0x27))) -= 1;
    } while (0 <= (s64)*(s8 *)((u8 *)(reg_a4) + (0x27)));
    (*(u8 *)((u8 *)(reg_a4) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0x26)));
    (*(u16 *)((u8 *)(reg_a4) + (0x28))) -= 8;
    if (0 > (s16) (*(u16 *)((u8 *)(reg_a4) + (0x28)))) {
        (*(u16 *)((u8 *)(reg_a4) + (0x28))) = 0x18U;
    }
    reg_d7.h[1] = (*(u16 *)((u8 *)(reg_a4) + (6)));
    reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_a0 = (u8 *)(D_0025BE90);
    reg_a1 = (u8 *)(D_0025BEB0);
    reg_a2 = (u8 *)(D_0025BEF0);
    if ((*(u16 *)((u8 *)(reg_a4) + (0x2C))) != 0) {
        reg_a0 = (u8 *)(D_0025BEA0);
        reg_a1 = (u8 *)(D_0025BED0);
        reg_a2 = (u8 *)(D_0025BF00);
    }
    reg_d4.h[0] = 5;
    reg_d1.w = reg_d7.w;
    temp_a1 = reg_d1.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a2;
    reg_a2 += 2;
    reg_d1.w = temp_a1 + reg_tmp.w;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x28)));
    reg_a1 += reg_d0.h[0];
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    temp_a0 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3808;
    func_0019C670();
    reg_d1.w = reg_d7.w;
    temp_a3 = *(u16 *)reg_a2;
    temp_a2_2 = reg_d1.w;
    reg_a2 += 2;
    reg_tmp.h[1] = temp_a3;
    temp_a3_2 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a3_2;
    reg_a2 += 2;
    temp_a1_2 = temp_a2_2 + reg_tmp.w;
    reg_d1.w = temp_a1_2;
    temp_a0_2 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d2.h[1] = temp_a0_2;
    temp_a0_3 = *(u16 *)reg_a1;
    reg_d2.h[0] = temp_a0_3;
    reg_a1 += 2;
    reg_d3.h[0] = 0x3C0;
    func_0019C670();
    reg_d1.w = reg_d7.w;
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1_3 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1_3;
    reg_a2 += 2;
    reg_d1.w += reg_tmp.w;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0x24)));
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x620;
    func_0019C6D0();
}
