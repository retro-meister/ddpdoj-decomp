#include "common.h"

extern u8 D_0028E1DA[];

void func_00131370(void) {
    reg_d0.b[0] = D_0028E1DA[0];
    if (reg_d0.b[0] != 0) {
        D_0028E1DA[0] -= 1;
    }
}
