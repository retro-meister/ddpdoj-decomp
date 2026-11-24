#include "common.h"

s32 func_001A3020();
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_0014CC90(void) {
    u16 temp_a1;

    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (6)));
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1;
    reg_a2 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    if ((u32)reg_a0 != -1U) {
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        func_001A3020();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}
