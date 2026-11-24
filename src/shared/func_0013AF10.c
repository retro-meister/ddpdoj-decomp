#include "common.h"

void func_0013AF10(void) {
    reg_d2.h[0] = reg_d1.h[0];
    reg_d0.w = 0xA;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d3.h[0] = reg_d1.h[0];
    reg_d2.h[0] &= 0x7C00;
    reg_d3.h[0] &= 0x3E0;
    reg_d4.h[0] &= 0x1F;
    reg_d2.h[0] >>= 0xA;
    reg_d3.h[0] >>= 5;
}
