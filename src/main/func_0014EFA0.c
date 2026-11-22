#include "common.h"

extern u16 *reg_a6;
extern s32 reg_a0;
extern u16 D_0029C068[];
void func_0014EFA0(void) {
    reg_d0.h[0] = D_0029C068[0];
    reg_a6[2] -= reg_d0.h[0];
    reg_a0 += 1;
}
