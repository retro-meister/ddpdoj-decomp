#include "common.h"

s32 func_0021C0F0();
s32 func_0021C2F0();
s32 func_00221E20();
extern s32 D_0028EAF8;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00221CF0(void) {
    u8 * spA0;
    u8 * spB0;
    u8 * spC0;
    u8 * spD0;
    u8 * spE0;
    u8 * spF0;
    u8 * temp_fp;
    u32 temp_s7;
    u32 temp_s6;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_s4;
    u32 temp_s5;

    if (D_0028EAF8 != 0) {
        temp_s7 = reg_d0.w;
        temp_s6 = reg_d1.w;
        temp_s0 = reg_d2.w;
        temp_s1 = reg_d3.w;
        temp_s2 = reg_d4.w;
        temp_s3 = reg_d5.w;
        temp_s4 = reg_d6.w;
        temp_s5 = reg_d7.w;
        spA0 = reg_a0;
        spB0 = reg_a1;
        spC0 = reg_a2;
        spD0 = reg_a3;
        spE0 = reg_a4;
        spF0 = reg_a5;
        temp_fp = reg_a6;
        func_0021C0F0();
        func_00221E20();
        func_0021C2F0();
        reg_d0.w = temp_s7;
        reg_d1.w = temp_s6;
        reg_d2.w = temp_s0;
        reg_d3.w = temp_s1;
        reg_d4.w = temp_s2;
        reg_d5.w = temp_s3;
        reg_d6.w = temp_s4;
        reg_d7.w = temp_s5;
        reg_a0 = spA0;
        reg_a1 = spB0;
        reg_a2 = spC0;
        reg_a3 = spD0;
        reg_a4 = spE0;
        reg_a5 = spF0;
        reg_a6 = temp_fp;
    }
}
