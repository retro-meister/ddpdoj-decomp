#include "common.h"

s32 func_001AE9A0(Reg32 *, Reg32 *);            /* extern */
extern u16 *reg_a0_as_u16_p;

void func_001A8FC0(void) {
    reg_d0.w = 1;
    reg_d2.w = (u32) *reg_a0_as_u16_p;
    func_001AE9A0(&reg_d0, &reg_d2);
    *reg_a0_as_u16_p = reg_d2.h[0];
}
