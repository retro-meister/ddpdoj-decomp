#include "common.h"

extern u16 D_0028E82C;
extern u16 D_0028E830;
extern u16 D_0028E834;
extern u16 D_0028E838;

void func_00137BF0(void) {
    reg_d0.w = 0;
    D_0028E838 = reg_d0.h[0];
    D_0028E834 = reg_d0.h[0];
    D_0028E830 = reg_d0.h[0];
    D_0028E82C = reg_d0.h[0];
}
