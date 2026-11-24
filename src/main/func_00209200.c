#include "common.h"

s32 func_0011C2B0(void);
extern u16 D_0028E478;
extern s8 *reg_a0;

void func_00209200(void) {
    u32 saved;

    saved = reg_d0.w;
    reg_d3.w = 0;
    reg_d2.w = 0;
    reg_d5.h[0] = reg_d0.h[0];
loop_1:
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = *reg_a0;
    reg_a0 += 1;
    reg_d1.b[0] = *reg_a0;
    reg_a0 += 1;
    reg_a0 += 1;
loop_2:
    reg_d4.w = 0;
    reg_d4.b[0] = *reg_a0;
    reg_a0 += 1;
    if (reg_d4.b[0] == 0x7F) {
        goto loop_1;
    }
    if ((s8) reg_d4.b[0] != -1) {
        reg_d4.h[0] &= 0xFF;
        D_0028E478 = reg_d4.h[0];
        reg_d4.h[0] = reg_d5.h[0];
        reg_d4.h[1] = D_0028E478;
        func_0011C2B0();
        reg_d0.h[0] += 1;
        goto loop_2;
    }
    reg_d0.w = saved;
}
