#include "common.h"

extern u16 D_0028E974;
extern u16 D_0028E97C;
extern u16 *reg_a0_as_u16_p;

void func_00125860(void) {
    reg_a0_as_u16_p = &D_0028E97C;
    if (!(reg_d1.w & 0x1000)) {
        reg_a0_as_u16_p = &D_0028E974;
    }
    *reg_a0_as_u16_p += reg_d0.h[0];
    if ((s32) *reg_a0_as_u16_p >= 0x3E8) {
        *reg_a0_as_u16_p = 0x3E7;
    }
}
