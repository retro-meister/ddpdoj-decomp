#include "common.h"

extern u16 reg_d6;
extern void *reg_a6;

void func_002037B0(void) {
    u32 scaled = (u32)reg_d6 << 16;
    reg_d6 = (u16)(scaled - reg_d6);
    reg_d6 += 0x1C00;
    *(u16 *)((u8 *)reg_a6 + 4) = reg_d6;
}
