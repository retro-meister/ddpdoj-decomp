#include "common.h"

extern u16 D_0028E914;
extern u16 D_0028E918;
extern u16 D_0028E91C;

void func_00134FE0(void) {
    u32 value;

    value = reg_d0.h[0];
    D_0028E91C = value;
    value = value + value;
    reg_d0.h[0] = value;
    value = reg_d0.h[0];
    D_0028E918 = value;
    value = value + value;
    reg_d0.h[0] = value;
    value = reg_d0.h[0];
    D_0028E914 = value;
}
