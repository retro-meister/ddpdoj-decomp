#include "common.h"

extern u16 D_0028E970;
extern u16 D_0028E974;
extern u16 D_0028E984;

void func_00125E60(void) {
    reg_d0.w = 0;
    D_0028E984 = reg_d0.h[0];
    D_0028E974 = reg_d0.h[0];
    D_0028E970 = reg_d0.h[0];
}
