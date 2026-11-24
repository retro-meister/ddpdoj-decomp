#include "common.h"

extern s8 *reg_a6;
extern s8 *reg_a0;

void func_0014ECC0(void) {
    reg_a6[0x1E] = *reg_a0;
    reg_a0 += 1;
}
