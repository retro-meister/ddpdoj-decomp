#include "common.h"

void func_00202590(void) {
    reg_d1.b[0] -= reg_d0.b[0];
    if (reg_d1.b[0] != 0) {
        reg_d0.b[0] += 1;
        if ((s32) reg_d1.b[0] >= 0x80) {
            reg_d0.b[0] -= 2;
        }
    }
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] = (u16) reg_d1.b[0];
}
