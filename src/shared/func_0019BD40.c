#include "common.h"

extern u16 D_0028E46C;
extern u16 D_0028E478;
extern u16 D_0028E484_as_u16;
extern u8 *reg_a0;

void func_0019BD40(void) {
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484_as_u16;
    D_0028E484_as_u16 = reg_d1.h[0];
    reg_d7.h[0] += reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = D_0028E484_as_u16;
    D_0028E46C = reg_d7.h[0];
    reg_d7.h[0] = reg_d7.h[1];
    reg_d7.h[1] = D_0028E46C;
    reg_d7.h[0] += reg_d1.h[0];
    reg_d7.w = (u32) ((s32) reg_d7.w >> 6);
    reg_d7.w &= 0x07FF03FF;
    reg_d7.w |= reg_d6.w;
    *(u16 *)reg_a0 = reg_d7.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d7.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    D_0028E478 = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = D_0028E478;
    *(u16 *)reg_a0 = reg_d4.h[0];
    reg_a0 += 2;
}
