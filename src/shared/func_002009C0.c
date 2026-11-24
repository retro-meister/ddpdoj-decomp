#include "common.h"

extern void func_00128970(void);

void func_002009C0(void)
{
    u32 savedD0;
    s8 command;

    savedD0 = reg_d0.w;
    command = (s8)reg_d1.b[0];
    if (command < 0x34 && command > 0xC) {
        func_00128970();
    }
    reg_d0.w = savedD0;
}
