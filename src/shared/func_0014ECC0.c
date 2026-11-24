#include "common.h"

extern s8 *reg_a6_as_s8_p;
extern s8 *reg_a0_as_s8_p;

void func_0014ECC0(void) {
    reg_a6_as_s8_p[0x1E] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
}
