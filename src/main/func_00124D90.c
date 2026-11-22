#include "common.h"

extern s16 D_00295E50[];
extern u16 D_00295E52[];
extern u8 D_00295E7C[];
extern void *D_0028E468;

void func_00124D90(void) {
    D_00295E50[0] = 1;
    D_0028E468 = D_00295E7C;
    D_00295E52[0] = work_reg_0.h[0];
}
