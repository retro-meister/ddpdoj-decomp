#include "common.h"

extern u8 *reg_a4;

void func_001D8700(void) {
    *(u16 *)(reg_a4 + 0x4) = 0x2020;
    *(u16 *)(reg_a4 + 0x6) = 5;
    *(u16 *)(reg_a4 + 0x8) = 4;
    *(u8 *)(reg_a4 + 0xB) = 0;
}
