#include "common.h"

s32 func_0019C5B0();
extern u8 D_0028E294;

void func_001A4990(void) {
    if (D_0028E294 != 0) {
        reg_d1.w = 0x66C02BC0;
    } else {
        reg_d1.w = 0x57C02BC0;
    }
    reg_d2.w = 0x14C9;
    reg_d3.h[0] = 0x220;
    reg_d4.h[0] = 8;
    reg_d7.w = 4;
    do {
        func_0019C5B0();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
