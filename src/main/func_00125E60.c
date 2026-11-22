#include "common.h"

extern u16 D_0028E970;
extern u16 D_0028E974;
extern u16 D_0028E984;

void func_00125E60(void) {
    work_reg_0.w = 0;
    D_0028E984 = work_reg_0.h[0];
    D_0028E974 = work_reg_0.h[0];
    D_0028E970 = work_reg_0.h[0];
}
