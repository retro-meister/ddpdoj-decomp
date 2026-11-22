#include "common.h"

extern u16 D_0028E220;

void func_00206B20(void) {
    D_0028E220 &= 0x400;
    reg_d1.w = 0xA;
    reg_d0.h[0] <<= reg_d1.h[0];
    D_0028E220 |= reg_d0.h[0];
}
