#include "common.h"

extern s8 *reg_a5_as_s8_p;
extern s8 *reg_a0_as_s8_p;

void func_0014EDA0(void) {
    reg_a5_as_s8_p[0x23] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p++;
}
