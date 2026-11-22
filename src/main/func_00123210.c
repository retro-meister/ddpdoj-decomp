#include "common.h"

extern Reg32 work_reg_0;
extern u8 D_00295E00[];
extern u16 *D_0028E450;

void func_00123210(void) {
    D_0028E450 = (u16 *)D_00295E00;
    D_0028E450[4] = work_reg_0.h[0];
    D_0028E450[3] = 0;
}
