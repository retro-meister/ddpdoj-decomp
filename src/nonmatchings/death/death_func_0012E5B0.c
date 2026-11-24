#include "common.h"

extern u8 *reg_a6;

void death_func_0012E5B0(void) {
    *(u16 *)(reg_a6 + 0x28) = 0x1410;
    reg_tmp.w = 0x24;
    *(u16 *)(reg_a6 + 0x22) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = reg_tmp.h[0];
    *(u8 *)(reg_a6 + 1) &= 0xFE;
    reg_tmp.w = 0x283;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    *(u16 *)(reg_a6 + 6) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 8) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0xE) = 0;
    *(u8 *)(reg_a6 + 0x1C) = 0x1A;
}
