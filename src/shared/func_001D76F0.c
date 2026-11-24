#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

extern void func_001D71C0(void);

void func_001D76F0(void)
{
    reg_tmp.b[0] = reg_a4[3];
    reg_a4[3] -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        s16 *remaining;

        reg_a4[3] = reg_a4[2];
        *(u16 *)(reg_a6 + 0xA8) -= 4;
        remaining = (s16 *)(reg_a6 + 0xA8);
        if (0 < *remaining) {
            return;
        }
        *remaining = 0;
        func_001D71C0();
    }
}
