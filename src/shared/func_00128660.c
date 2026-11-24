#include "common.h"

s32 memset();
extern u8 D_002962E0[];
extern u8 *reg_a0;

void func_00128660(void) {
    memset(D_002962E0, 0, MAIN_OR_DEATH_LABEL(0x3494, 0x10694));
    reg_a0 = D_002962E0 + 2;
    reg_d0.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
    do {
        *(u16 *)reg_a0 = 0xFFFF;
        reg_a0 += 0x40;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
