#include "common.h"

void func_00202410(void) {
    reg_d1.h[0] -= reg_d0.h[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] &= 0x3F;
}
