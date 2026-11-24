#include "common.h"

extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a6;

void func_0014ECE0(void)
{
    reg_d0.b[0] = *reg_a0_as_s8_p++;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        reg_a6[1] &= 0xDF;
    } else {
        reg_a6[1] |= 0x20;
    }
}
