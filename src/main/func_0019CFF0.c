#include "common.h"

extern u16 reg_d7;

void func_0019CFF0(void) {
    u32 value = (u16)reg_d7;
    reg_d7 = (u16)(value << 4);
}
