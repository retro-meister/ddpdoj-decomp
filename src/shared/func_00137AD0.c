#include "common.h"

s32 func_0011C2B0();
extern u32 D_0028E478_as_u32;
extern s8 *reg_a0_as_s8_p;

void func_00137AD0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    s8 *temp_s5;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    temp_s5 = (s8 *)(reg_a0_as_s8_p);
    reg_d3.w = 0;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
loop_1:
    reg_d4.w = 0;
    reg_d4.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    if (reg_d4.b[0] != 0) {
        reg_d4.h[0] = reg_d4.w & 0xFF;
        D_0028E478_as_u32 = reg_d4.w;
        reg_d4.h[1] = reg_d4.h[0];
        reg_d4.h[0] = reg_d5.h[0];
        func_0011C2B0();
        reg_d0.h[0] += 1;
        goto loop_1;
    }
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_a0_as_s8_p = temp_s5;
}
