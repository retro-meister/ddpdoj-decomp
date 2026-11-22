#include "common.h"

extern u16 *D_0028E450;
extern u16 D_0028E988;

void func_001257E0(void) {
    work_reg_0.w = 0;
    D_0028E450[0] = (u16) work_reg_0.h[0];
    D_0028E450[1] = (u16) work_reg_0.h[0];
    D_0028E988 -= 1;
}
