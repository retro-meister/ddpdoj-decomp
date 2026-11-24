#include "common.h"

s32 func_0019C5B0();
extern u8 D_0028E294;

void func_001A4740(void) {
    if (D_0028E294 != 0) {
        reg_d1.w = 0x5EC01800;
    } else {
        reg_d1.w = 0x4FC01800;
    }
    reg_d2.w = 0x1548;
    reg_d3.h[0] = 0x228;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        func_0019C5B0();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
