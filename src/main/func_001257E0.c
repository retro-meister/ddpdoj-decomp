#include "common.h"

extern u16 *reg_a6;
extern u16 D_0028E988;

void func_001257E0(void) {
    reg_d0.w = 0;
    reg_a6[0] = (u16) reg_d0.h[0];
    reg_a6[1] = (u16) reg_d0.h[0];
    D_0028E988 -= 1;
}
