#include "common.h"

extern u8 *reg_a6;
extern u8 *reg_a4;

void func_001BB560(void) {
    *(u16 *)reg_a4 = 0;
    reg_a4[3] = reg_a6[0x1B];
}
