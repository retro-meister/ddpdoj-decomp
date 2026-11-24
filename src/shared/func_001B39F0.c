#include "common.h"

extern u8 *reg_a6;

void func_001B39F0(void) {
    u8 temp_a0;

    reg_tmp.b[0] = (*(u8 *)(reg_a6 + 0xAF));
    (*(u8 *)(reg_a6 + 0xAF)) -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        (*(u8 *)(reg_a6 + 0xAF)) = (*(u8 *)(reg_a6 + 0xAE));
        temp_a0 = (*(u8 *)(reg_a6 + 0xAE));
        if (temp_a0 != 2) {
            if ((s8)temp_a0 >= 2) {
                (*(u8 *)(reg_a6 + 0xAE)) = temp_a0 - 1;
            } else {
                (*(u8 *)(reg_a6 + 0xAE)) = temp_a0 + 1;
            }
        }
        (*(u16 *)(reg_a6 + 0xAA)) += 4;
        if ((s16)(*(u16 *)(reg_a6 + 0xAA)) >= 0x1C) {
            (*(u16 *)(reg_a6 + 0xAA)) = 0;
        }
    }
}
