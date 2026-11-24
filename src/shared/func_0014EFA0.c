#include "common.h"

extern u16 *reg_a6_as_u16_p;
extern s32 reg_a0_as_s32;
extern u16 D_0029C068[];
void func_0014EFA0(void) {
    reg_d0.h[0] = D_0029C068[0];
    reg_a6_as_u16_p[2] -= reg_d0.h[0];
    reg_a0_as_s32 += 1;
}
