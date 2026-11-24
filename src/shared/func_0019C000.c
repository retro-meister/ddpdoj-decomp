#include "common.h"

s32 func_0019B6E0();
extern u16 D_0028E1A0;
extern u8 D_002AF860[];
extern u8 *reg_a0;
extern s32 reg_a1_as_s32;

void func_0019C000(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = reg_a1_as_s32;
    reg_a0 = D_002AF860;
    reg_a0 += D_0028E1A0;
    func_0019B6E0();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1_as_s32 = temp_s2;
    D_0028E1A0 += 0xC;
}
