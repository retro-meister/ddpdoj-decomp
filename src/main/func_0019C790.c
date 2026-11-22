#include "common.h"

s32 func_0019BB40();
extern u16 D_0028E190;
extern u8 D_002A9AE0[];
extern u8 *reg_a0;

void func_0019C790(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = D_002A9AE0;
    reg_a0 += D_0028E190;
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    D_0028E190 += 0xC;
}
