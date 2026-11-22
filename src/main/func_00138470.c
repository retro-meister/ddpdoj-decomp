#include "common.h"

extern u16 D_0028C108[4];
extern u16 D_0028C110[4];
extern u16 *reg_a0;

void func_00138470(void)
{
    reg_a0 = D_0028C108;
    if (reg_d7.h[0] == 0) {
        reg_a0 = D_0028C110;
    }

    reg_d1.w = 2;
    do {
        if (*reg_a0 != reg_d0.h[0]) {
            break;
        }
        reg_a0++;
    } while ((s16)(--reg_d1.h[0]) >= 0);

    reg_d0.h[0] = *reg_a0;
}
