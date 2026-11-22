#include "common.h"

extern u16 D_0028E220;

void func_00206BE0(void) {
    D_0028E220 &= 0x2000;
    reg_d1.w = 0xD;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}
