#include "common.h"

extern u16 D_0028E978;
extern u16 D_0028E97C;
extern u16 D_0028E984;

void func_00125E40(void) {
    reg_d0.w = 0;
    D_0028E984 = reg_d0.h[0];
    D_0028E97C = reg_d0.h[0];
    D_0028E978 = reg_d0.h[0];
}
