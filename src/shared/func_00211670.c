#include "common.h"


s32 func_00211720();
extern u8 D_002515A0[];
extern u16 D_0028E3E0;
extern u16 D_0028E3EC;
extern u16 D_00299D20[];
extern u8 *reg_a4;

void func_00211670(void) {
    u32 temp_a0;

    reg_d7.h[0] = D_00299D20[0];
    if (reg_d7.h[0] != 0) {
        reg_d5.w = 0;
        reg_d7.h[0] -= 1;
        reg_d4.h[0] = 0xFFC0;
        reg_d2.h[0] = 0x3FF;
        reg_d6.h[0] = D_0028E3EC;
        reg_a4 = D_002515A0;
        reg_tmp.h[0] = reg_d6.h[0];
        reg_d6.h[0] <<= 0xF;
        temp_a0 = reg_d6.h[0];
        reg_tmp.h[0] >>= 1;
        reg_d6.h[0] = temp_a0 | reg_tmp.h[0];
        reg_tmp.w = reg_d6.w;
        reg_d6.h[0] = D_0028E3E0;
        reg_d6.h[1] = reg_tmp.h[0];
        func_00211720();
    }
}
