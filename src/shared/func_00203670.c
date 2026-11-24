#include "common.h"

s32 func_0016A8C0();
s32 func_00201C60();
extern s8 D_002670B0[];
extern u8 *reg_a6;

void func_00203670(void) {
    func_0016A8C0();
    reg_d0.h[0] &= 0xF;
    *(s8 *)(reg_a6 + 0x1A) = D_002670B0[reg_d0.h[0]];
    if (*(s8 *)(reg_a6 + 0x1A) >= 0) {
        func_00201C60();
        return;
    }
    *(s8 *)(reg_a6 + 0x1A) = 0x40;
    reg_d2.w = 0;
    reg_d3.h[0] = reg_d2.h[0];
}
