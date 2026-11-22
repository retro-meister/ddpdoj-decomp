#include "common.h"

void func_0011C2B0(void);

void func_002093C0(void) {
    s32 value = 0x200002;

    reg_d4.sw = value;
    value = 0;
    if ((s16)value <= (s16)reg_d2.sw) {
        reg_d4.sw = 0x3E0002;
    }
    reg_d3.sw = value;
    reg_d2.sw = 0;
    func_0011C2B0();
}
