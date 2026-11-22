#include "common.h"

extern s8 D_0028E4A1;
extern s8 D_0028E4A5;
extern s8 *reg_a0;
extern u8 *reg_a5;

void func_0014EDC0(void) {
    s8 temp_a2;

    reg_d0.h[0] = 0;
    reg_d0.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    D_0028E4A5 = *reg_a0;
    reg_a0 += 1;
    reg_d1.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= 0xFF0;
    reg_d1.h[0] *= 0x10;
    temp_a2 = *reg_a0;
    reg_a0 += 1;
    D_0028E4A1 = temp_a2;
    reg_d2.b[0] = (u8) *reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= 0xFF0;
    reg_d2.h[0] >>= 4;
    reg_d1.h[0] += reg_d2.h[0];
    *(u16 *)(reg_a5 + ((s32) reg_d0.h[0] >> 1)) = reg_d1.h[0];
}
