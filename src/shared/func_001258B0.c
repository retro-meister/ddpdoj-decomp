#include "common.h"

extern u16 D_0028E978;
extern u16 *reg_a0;

void func_001258B0(void) {
    reg_a0 = &D_0028E978;
    *reg_a0 += reg_d0.h[0];
    if ((s32) *reg_a0 >= 0x3E8) {
        *reg_a0 = 0x3E7;
    }
}
