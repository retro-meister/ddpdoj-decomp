#include "common.h"

extern u32 D_0028E108[];
extern u32 D_0028E10C[];
extern u16 D_0028E234;
extern u16 D_0028E238;
extern u16 *reg_a1;
extern u16 *reg_a2;

void func_0011C250(void) {
    reg_a1 = &D_0028E234;
    reg_a2 = &D_0028E238;
    reg_d0.w = D_0028E108[0];
    reg_d1.w = D_0028E10C[0];
    reg_d0.w = (u32) reg_d0.w >> 6;
    reg_d1.w = (u32) reg_d1.w >> 6;
    *reg_a2 = reg_d0.h[0];
    *reg_a1 = reg_d1.h[0];
}
