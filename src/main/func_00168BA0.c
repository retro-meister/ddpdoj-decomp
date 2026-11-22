#include "common.h"

extern u8 *reg_a5;
extern u16 D_0028E7BC;

void func_00168BA0(void) {
    reg_a5[2] = 0;
    D_0028E7BC = reg_d0.h[0];
}
