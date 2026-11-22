#include "common.h"

extern u16 D_0028E82C;
extern u16 D_0028E830;
extern u16 D_0028E834;
extern u16 D_0028E838;

void func_00137BF0(void) {
    work_reg_0.w = 0;
    D_0028E838 = work_reg_0.h[0];
    D_0028E834 = work_reg_0.h[0];
    D_0028E830 = work_reg_0.h[0];
    D_0028E82C = work_reg_0.h[0];
}
