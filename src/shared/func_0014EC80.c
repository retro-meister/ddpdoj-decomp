#include "common.h"

extern s8 *reg_a0;

void func_0014EC80(void) {
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 -= reg_d0.h[0];
}
