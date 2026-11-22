#include "common.h"


void func_00202500(void) {
    reg_d2.w = 0x3F;
    reg_d0.h[0] &= reg_d2.h[0];
    reg_d1.h[0] &= reg_d2.h[0];
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] += 1;
        reg_d1.h[0] &= reg_d2.h[0];
        if ((s32) reg_d1.h[0] >= 0x20) {
            reg_d0.b[0] -= 2;
        }
        reg_d0.h[0] &= reg_d2.h[0];
    }
    reg_d1.h[0] = reg_d0.h[0];
}
