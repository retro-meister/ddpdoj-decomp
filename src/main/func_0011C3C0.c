#include "common.h"

extern u8 D_002B6D50[];
extern u8 *reg_a0;

void func_0011C3C0(void) {
    u8 *a0 = reg_a0;
    u32 d0 = reg_d0.w;
    u32 d1 = reg_d1.w;
    u32 d2 = reg_d2.w;
    u32 d3 = reg_d3.w;
    u32 d4 = reg_d4.w;

    reg_d0.h[0] <<= 6;
    reg_a0 = D_002B6D50;
    reg_d0.h[0] += reg_d1.h[0];
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    *(u32 *)reg_a0 = reg_d4.w;
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_a0 = a0;
}
