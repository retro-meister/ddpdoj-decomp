#include "common.h"

s32 func_0011C2B0();
extern u16 D_0028E478;
extern u8 *reg_a0;

void func_002092F0(void) {
    u8 *a0;
    u32 d0;
    u32 d1;
    u32 d2;

    d2 = reg_d2.w;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    a0 = reg_a0;
    reg_d3.w = 0;
    reg_d5.h[0] = reg_d2.h[0];
    reg_d2.w = 0;
loop_1:
    reg_d4.w = 0;
    reg_d4.sb[0] = *(s8 *)reg_a0;
    reg_a0 += 1;
    if (reg_d4.sb[0] == -1) goto next_1;
    reg_d4.h[0] = reg_d4.b[0];
    D_0028E478 = reg_d4.h[0];
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[1] = D_0028E478;
    func_0011C2B0();
    reg_d0.h[0] += 1;
    goto loop_1;
next_1:
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
}
