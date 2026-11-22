#include "common.h"

s32 func_001BC930();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001BC8B0(void) {
    reg_d5.w = 0;
    reg_d7.w = 7;
    reg_d6.w = 0;
    reg_a0 = reg_a6 + 0x20;
    do {
        *(u8 *)(reg_a0 + 0x1A) = reg_d6.b[0];
        *(u8 *)(reg_a0 + 0x28) = reg_d5.b[0];
        reg_d6.b[0] += 0x20;
        reg_d5.b[0] += 8;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    func_001BC930();
}
