#include "common.h"

s32 func_0016AA30();
extern u16 D_0028E5B4;
extern u16 D_0028E5E0;
extern u8 *reg_a0;
extern u8 *reg_a2;

void func_001ABEA0(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    u16 var_a0;
    reg_d7.h[0] = D_0028E5B4;
    if (D_0028E5B4 != 0) {
        if (D_0028E5E0 == 0x95F) {
            D_0028E5E0 = 0;
            reg_d7.h[0] += 1;
        }
        reg_d7.h[0] -= 1;
        reg_d6.h[0] = 0x7000;
        temp_s0 = reg_d0.w;
        temp_s1 = reg_d2.w;
        temp_s2 = reg_d6.w;
        temp_s3 = (s32)reg_a0;
        temp_s4 = (s32)reg_a2;
        do {
            reg_d0.w = 0x14;
            func_0016AA30();
            var_a0 = (u32)reg_d6.h[0] + 0x800;
            reg_d6.h[0] = var_a0;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        reg_d0.w = temp_s0;
        reg_d2.w = temp_s1;
        reg_d6.w = temp_s2;
        reg_a0 = (u8 *)temp_s3;
        reg_a2 = (u8 *)temp_s4;
        D_0028E5B4 = 0;
    }
}
