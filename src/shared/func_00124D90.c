#include "common.h"

extern s16 D_00295E50_as_s16_a[];
extern u16 D_00295E52[];
extern u8 D_00295E7C[];
extern void *reg_a0_as_void_p;

void func_00124D90(void) {
    D_00295E50_as_s16_a[0] = 1;
    reg_a0_as_void_p = D_00295E7C;
    D_00295E52[0] = reg_d0.h[0];
}
