#include "common.h"

void func_00201010(void)
{
    unsigned char low = reg_d0.b[0];
    unsigned char high = reg_d0.b[1];

    reg_d2.w = 0;
    reg_tmp.b[0] = low & 15;
    reg_tmp.b[1] = low >> 4;
    reg_tmp.b[2] = high & 15;
    reg_tmp.b[3] = high >> 4;
    reg_d2.h[0] = reg_tmp.b[0] + (reg_tmp.b[1] * 10 +
        (reg_tmp.b[3] * 1000 + reg_tmp.b[2] * 100));
}
