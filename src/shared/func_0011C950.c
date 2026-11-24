#include "common.h"

s32 func_0011C920();
extern u32 D_002A2400[];
extern u32 *reg_a0;
extern u32 *reg_a1;

void func_0011C950(void) {
    reg_a0 = D_002A2400;
    reg_d0.h[0] = 0x30F;
loop_1:
    reg_tmp.w = *reg_a0;
    reg_a0 += 1;
    if (reg_tmp.w != -1U) {
        reg_a1 = (u32 *)(reg_tmp.w);
        *reg_a1 = (u32) *reg_a0;
        reg_a0 += 1;
        goto loop_1;
    }
    func_0011C920();
}
