#include "common.h"

extern u8 *reg_a0;
extern u8 D_00295EA0[];

void func_00124DC0(void) {
    u8 *savedAddress;
    u32 savedData;

    savedData = reg_d0.w;
    savedAddress = reg_a0;
    reg_a0 = D_00295EA0;
    reg_d0.h[0] *= 8;
    reg_a0 += reg_d0.h[0];
    *(s16 *)reg_a0 |= 1;
    reg_a0 = savedAddress;
    reg_d0.w = savedData;
}
