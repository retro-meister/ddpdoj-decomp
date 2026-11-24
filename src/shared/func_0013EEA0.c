#include "common.h"

s32 func_0011C4A0();
void func_0013EEA0(void) {
    s16 temp_a0;

    temp_a0 = (s16) reg_d6.h[0];
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 1;
    reg_d6.h[0] = temp_a0 << 9;
    reg_d1.h[0] += reg_d6.h[0];
    func_0011C4A0(temp_a0);
}
