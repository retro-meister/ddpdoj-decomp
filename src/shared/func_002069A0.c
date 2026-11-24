#include "common.h"

extern u16 D_0028E220;

void func_002069A0(void) {
    D_0028E220 &= 4;
    reg_d1.w = 2;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}
