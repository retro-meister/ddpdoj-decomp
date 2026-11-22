#include "common.h"

s32 memset();
extern u8 D_002962E0[];
extern u8 *reg_a0;

void func_00128660(void) {
    memset(D_002962E0, 0, 0x3494);
    reg_a0 = D_002962E0 + 2;
    reg_d0.h[0] = 0xD1;
    do {
        *(u16 *)reg_a0 = 0xFFFF;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
