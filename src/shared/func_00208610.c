#include "common.h"

s32 func_002093C0();
extern u8 D_0028DFA0_as_u8;

void func_00208610(void) {
    reg_d0.w = 5;
    reg_d1.w = 9;
    reg_d2.w = -1U;
    reg_d1.b[0] -= D_0028DFA0_as_u8;
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] += 0x18;
    func_002093C0();
}
