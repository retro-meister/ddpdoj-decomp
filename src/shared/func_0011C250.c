#include "common.h"

extern u32 D_0028E108_as_u32_a[];
extern u32 D_0028E10C_as_u32_a[];
extern u16 D_0028E234_as_u16;
extern u16 D_0028E238_as_u16;
extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a2_as_u16_p;

void func_0011C250(void) {
    reg_a1_as_u16_p = &D_0028E234_as_u16;
    reg_a2_as_u16_p = &D_0028E238_as_u16;
    reg_d0.w = D_0028E108_as_u32_a[0];
    reg_d1.w = D_0028E10C_as_u32_a[0];
    reg_d0.w = (u32) reg_d0.w >> 6;
    reg_d1.w = (u32) reg_d1.w >> 6;
    *reg_a2_as_u16_p = reg_d0.h[0];
    *reg_a1_as_u16_p = reg_d1.h[0];
}
