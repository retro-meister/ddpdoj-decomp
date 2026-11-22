#include "common.h"

extern u8 D_0028E1E6[];

void func_00131340(void) {
    work_reg_0.b[0] = D_0028E1E6[0];
    if (work_reg_0.b[0] != 0) {
        D_0028E1E6[0] -= 1;
    }
}
