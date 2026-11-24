#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E73A0(void)
{
    s16 *remaining;

    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;
    if ((s32)(u8)reg_tmp.b[0] <= 0) {
        reg_a4[3] = reg_a4[2];
        *(u16 *)(reg_a6 + 0x166) -= 4;
        remaining = (s16 *)(reg_a6 + 0x166);
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        *(u16 *)reg_a4 = 0;
    }
}
