#include "common.h"


extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0014CD70(void) {
    reg_a2 = reg_a5 + 0x10;
    if (reg_d6.h[0] != 0) {
        reg_a2 = reg_a5 + 0xA;
    }
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a2) + (0)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a2) + (2)));
    reg_a3 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (s16) reg_d1.h[0] << 5;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] += reg_d0.h[0];
    reg_a3 += (s16) reg_d1.h[0];
    reg_tmp.w = (u32)reg_a3;
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xE))) = (u16) reg_tmp.h[0];
    reg_tmp.w = (u32)reg_a3;
    (*(u16 *)((u8 *)(reg_a2) + (0))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a2) + (2))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    (*(u16 *)((u8 *)(reg_a6) + (0x14))) = (u16) reg_d0.h[0];
    reg_d0.h[0] += 1;
    (*(u16 *)((u8 *)(reg_a6) + (0x16))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x10))) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
}
