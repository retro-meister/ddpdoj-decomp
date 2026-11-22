#include "common.h"

extern u8 D_0028E1D8[];

void func_001313E0(void) {
    reg_d1.b[0] = D_0028E1D8[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if ((s8) reg_d1.b[0] < 0) {
        reg_d1.w = 0;
    }
    D_0028E1D8[0] = reg_d1.b[0];
}
