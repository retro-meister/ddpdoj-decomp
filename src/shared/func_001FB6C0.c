#include "common.h"

extern u8 *reg_a6;

void func_001FB6C0(void) {
    *(u16 *)(reg_a6 + 0x86) = 0xFFFF;
    *(u16 *)(reg_a6 + 0x88) = 0;
}
