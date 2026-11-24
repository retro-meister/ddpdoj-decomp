#include "common.h"

extern u8 *reg_a4;

void func_001B45E0(void) {
    *(u16 *)(reg_a4 + 2) = 0x101;
}
