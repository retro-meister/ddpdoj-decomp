#include "common.h"

s32 func_00201160();
extern u16 *reg_a4;

void func_001C9B10(void) {
    func_00201160();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    *reg_a4 = reg_d0.h[0];
}
