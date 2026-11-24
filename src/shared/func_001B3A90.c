#include "common.h"

extern u8 *reg_a4;

void func_001B3A90(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    reg_a4[7] = 0;
}
