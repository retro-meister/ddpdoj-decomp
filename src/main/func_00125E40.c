#include "common.h"

extern u16 D_0028E978;
extern u16 D_0028E97C;
extern u16 D_0028E984;

void func_00125E40(void) {
    work_reg_0.w = 0;
    D_0028E984 = work_reg_0.h[0];
    D_0028E97C = work_reg_0.h[0];
    D_0028E978 = work_reg_0.h[0];
}
