#include "common.h"

extern u8 D_0029F1F1[];
extern u8 D_0029F261[];

void func_00203380(void) {
    reg_d1.b[0] = D_0029F261[0];
    reg_d0.w = 0;
    if (((s8) reg_d1.b[0] < 0) && !(reg_d1.h[0] & (1 << reg_d0.h[0]))) {
        reg_d0.w = 1;
    }
    reg_d1.b[0] = D_0029F1F1[0];
    if (((s8) reg_d1.b[0] < 0) && !(reg_d1.h[0] & 1)) {
        reg_d0.h[0] += 2;
    }
}
