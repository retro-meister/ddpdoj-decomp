#include "common.h"

extern u8 *reg_a1;
extern u8 *reg_a6;

void func_00139ED0(void) {
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x2C)));
    reg_a1 = (u8 *)reg_tmp.w;
loop_1:
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
    if (0 > (s32) reg_d0.w) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
        reg_a1 += 2;
        if ((s16) reg_d0.h[0] == -1) {
            (*(u16 *)((u8 *)(reg_a6) + (0xE))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
        } else {
            reg_a1 += 2;
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a1) + (0)));
            reg_a1 += 2;
            reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
            reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
            reg_tmp.w += reg_d1.w;
            (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
        }
        goto loop_1;
    }
    reg_tmp.w = (u32)reg_a1;
    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = (u16) reg_tmp.h[0];
}
