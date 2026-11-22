#include "common.h"

s32 func_001A3130();
extern u8 D_002555A0[];
extern u16 D_0028E070;
extern u32 reg_a0;
extern u8 *reg_a1;

void func_0013E970(void) {
    reg_a1 = D_002555A0;
    reg_d0.h[0] = D_0028E070;
    reg_d0.h[0] *= 2;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 = reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    func_001A3130();
}
