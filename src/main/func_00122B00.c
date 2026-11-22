#include "common.h"

extern u8 D_0029F22F[];
extern u8 D_0029F29F[];

void func_00122B00(void) {
    work_reg_0.w = 0;
    D_0029F29F[0] = work_reg_0.b[0];
    D_0029F22F[0] = work_reg_0.b[0];
}
