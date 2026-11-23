#include "common.h"

s32 func_00202C40();
void func_00202B70(void) {
    u32 temp_a0;
    u32 temp_a1;

    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    temp_a1 = reg_d0.h[0];
    reg_d4.h[0] = temp_a1;
    reg_d4.h[0] >>= 2;
    reg_d1.h[0] -= reg_d3.h[0];
    temp_a0 = temp_a1 - reg_d4.h[0];
    reg_d0.h[0] = temp_a0;
    if ((s16)(reg_d1.h[0]) < 0) {
        reg_d1.h[0] *= 0xFFFF;
    }
    if ((s32) reg_d1.h[0] > (s32) reg_d0.h[0]) {
        reg_tmp.w = reg_d0.w;
        reg_d0.w = reg_d1.w;
        reg_d1.w = reg_tmp.w;
    }
    reg_d1.h[0] >>= 1;
    reg_d0.h[0] += reg_d1.h[0];
    func_00202C40();
}
