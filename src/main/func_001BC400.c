#include "common.h"

extern u16 *reg_a6;

void func_001BC400(void) {
    reg_d0.h[0] = 0x8000;
    reg_a6[0x0 / 2] = (u16) reg_d0.h[0];
    reg_a6[0x20 / 2] = (u16) reg_d0.h[0];
    reg_a6[0x60 / 2] = (u16) reg_d0.h[0];
}
