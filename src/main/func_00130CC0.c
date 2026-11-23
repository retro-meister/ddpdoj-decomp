#include "common.h"

s32 func_0011C2B0();
extern u16 D_0028E478;

void func_00130CC0(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;
    u32 temp_s4;

    temp_s0 = reg_d0.w;
    temp_s1 = reg_d1.w;
    temp_s2 = reg_d2.w;
    temp_s3 = reg_d3.w;
    temp_s4 = reg_d4.w;
    reg_d4.w &= 0xF;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d3.w = 0;
    reg_d2.w = 0;
    if ((s8) reg_d4.b[0] >= 0xA) {
        reg_d4.h[0] += 7;
    }
    reg_d4.h[0] += 0x30;
    D_0028E478 = reg_d4.h[0];
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[1] = D_0028E478;
    func_0011C2B0();
    reg_d0.w = temp_s0;
    reg_d1.w = temp_s1;
    reg_d2.w = temp_s2;
    reg_d3.w = temp_s3;
    reg_d4.w = temp_s4;
}
