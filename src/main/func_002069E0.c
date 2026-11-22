#include "common.h"

extern u16 D_0028E220;

void func_002069E0(void) {
    D_0028E220 &= 8;
    reg_d1.w = 3;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}
