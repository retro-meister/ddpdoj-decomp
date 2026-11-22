#include "common.h"

extern u16 *D_0028E450;

void func_001BC400(void) {
    work_reg_0.h[0] = 0x8000;
    D_0028E450[0x0 / 2] = (u16) work_reg_0.h[0];
    D_0028E450[0x20 / 2] = (u16) work_reg_0.h[0];
    D_0028E450[0x60 / 2] = (u16) work_reg_0.h[0];
}
