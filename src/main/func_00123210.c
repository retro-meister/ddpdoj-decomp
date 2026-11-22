#include "common.h"

extern Reg32 reg_d0;
extern u8 D_00295E00[];
extern u16 *reg_a6;

void func_00123210(void) {
    reg_a6 = (u16 *)D_00295E00;
    reg_a6[4] = reg_d0.h[0];
    reg_a6[3] = 0;
}
