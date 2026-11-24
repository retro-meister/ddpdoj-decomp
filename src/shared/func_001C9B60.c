#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C9B60(void)
{
    reg_d0.b[0] = reg_a4[3];
    reg_d1.b[0] = reg_a6[0x1B];

    if (reg_d0.b[0] != reg_d1.b[0]) {
        if ((s8)reg_d0.b[0] >= (s8)reg_d1.b[0]) {
            reg_d1.b[0]++;
        } else {
            reg_d1.b[0]--;
        }
    }

    reg_a6[0x1B] = reg_d1.b[0];
}
