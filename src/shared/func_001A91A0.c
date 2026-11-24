#include "common.h"

s32 func_001A9180();
s32 func_001A9190();
s32 func_001A9370();
s32 func_001A95B0();
extern u16 D_0028DAD8[];
extern u16 D_0028E5CC;
extern u16 D_0028E5D0;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern u32 D_0028E66C_as_u32;
extern u32 D_0028E6AC_as_u32;
extern u16 D_0028E6DC;
extern u16 D_0028E910;
extern u8 *reg_a0;

void func_001A91A0(void) {
    u32 temp_s0;
    u32 temp_s0_2;
    u32 temp_s1;
    u32 temp_s1_2;

    reg_d2.h[0] = D_0028E910;
    reg_a0 = (u8 *)(D_0028DAD8);
    reg_d2.h[0] += reg_d2.h[0];
    D_0028E6DC = (reg_d2.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d2.h[0] & ~1)) : *(u16 *)reg_a0;
    if (reg_d1.w & 0x10) {
        func_001A9370();
        if (D_0028E5FC != 0) {
            reg_d2.h[0] = D_0028E5D0;
            reg_d2.h[0] -= 1;
            do {
                temp_s1 = reg_d2.w;
                reg_d0.w = D_0028E6AC_as_u32;
                temp_s0 = reg_d0.w;
                reg_d0.w >>= 4;
                D_0028E6AC_as_u32 = reg_d0.w;
                reg_d0.w = 0;
                func_001A9370();
                reg_d0.w = 0;
                func_001A9180();
                reg_d0.w = 0;
                func_001A9180();
                reg_d0.w = 0;
                func_001A9180();
                reg_d0.w = 0;
                func_001A9180();
                reg_d2.w = temp_s1;
                D_0028E6AC_as_u32 = temp_s0;
            } while ((s16)(--reg_d2.h[0]) >= 0);
        }
    }
    if (reg_d1.w & 8) {
        func_001A95B0();
        if (D_0028E5F8 != 0) {
            reg_d2.h[0] = D_0028E5CC;
            reg_d2.h[0] -= 1;
            do {
                temp_s0_2 = reg_d2.w;
                reg_d0.w = D_0028E66C_as_u32;
                temp_s1_2 = reg_d0.w;
                reg_d0.w >>= 4;
                D_0028E66C_as_u32 = reg_d0.w;
                reg_d0.w = 0;
                func_001A95B0();
                reg_d0.w = 0;
                func_001A9190();
                reg_d0.w = 0;
                func_001A9190();
                reg_d0.w = 0;
                func_001A9190();
                reg_d0.w = 0;
                func_001A9190();
                reg_d2.w = temp_s0_2;
                D_0028E66C_as_u32 = temp_s1_2;
            } while ((s16)(--reg_d2.h[0]) >= 0);
        }
    }
}
