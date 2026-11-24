#include "common.h"

extern u16 *reg_a0_as_u16_p;

void func_0019BB40(void) {
    reg_d0.w = reg_d1.w;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *reg_a0_as_u16_p = reg_d0.h[1];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d0.h[0];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d2.h[1];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d2.h[0];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d3.h[0];
    reg_a0_as_u16_p += 1;
    *reg_a0_as_u16_p = reg_d4.h[0];
    reg_a0_as_u16_p += 1;
}
