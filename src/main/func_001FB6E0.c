#include "common.h"

extern u8 *D_0028E450;

void func_001FB6E0(void) {
    *(u16 *)(D_0028E450 + 0x86) = (u16)work_reg_0.h[0];
    *(u16 *)(D_0028E450 + 0x88) = 0;
}
