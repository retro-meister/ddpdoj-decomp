#include "common.h"

extern u8 *reg_a6;

void func_001FB6E0(void) {
    *(u16 *)(reg_a6 + 0x86) = (u16)reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x88) = 0;
}
