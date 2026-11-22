#include "common.h"

extern u8 D_0028E1DA[];

void func_00131370(void) {
    work_reg_0.b[0] = D_0028E1DA[0];
    if (work_reg_0.b[0] != 0) {
        D_0028E1DA[0] -= 1;
    }
}
