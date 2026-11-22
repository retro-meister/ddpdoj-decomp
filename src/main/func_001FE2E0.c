#include "common.h"

extern u8 *reg_a6;

void func_001FE2E0(void) {
    *(u16 *)(reg_a6 + 0x66) = 0;
}
