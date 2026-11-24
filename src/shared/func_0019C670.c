#include "common.h"

s32 func_0019BB40();
extern u16 D_0028E19C;
extern u8 D_002AE100[];
extern u8 *reg_a0;

void func_0019C670(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = D_002AE100;
    reg_a0 += D_0028E19C;
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    D_0028E19C += 0xC;
}
