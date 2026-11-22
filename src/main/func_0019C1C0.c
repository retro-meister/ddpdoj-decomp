#include "common.h"

s32 func_0019B6E0();
extern u16 D_0028E194;
extern u8 D_002AB240[];
extern u8 *reg_a0;
extern s32 reg_a1;

void func_0019C1C0(void) {
    u8 *temp_s1;
    s32 temp_s2;
    u32 temp_s0;

    temp_s1 = reg_a0;
    temp_s0 = reg_d0.w;
    temp_s2 = reg_a1;
    reg_a0 = D_002AB240;
    reg_a0 += D_0028E194;
    func_0019B6E0();
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
    reg_a1 = temp_s2;
    D_0028E194 += 0xC;
}
