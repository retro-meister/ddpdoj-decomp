#include "common.h"

s32 func_0019BB40();
extern u16 D_0028E194;
extern u8 D_002AB240[];
extern u8 *reg_a0;

void func_0019C730(void) {
    u8 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0;
    temp_s1 = reg_d0.w;
    reg_a0 = D_002AB240;
    reg_a0 += D_0028E194;
    func_0019BB40();
    reg_d0.w = temp_s1;
    reg_a0 = temp_s0;
    D_0028E194 += 0xC;
}
