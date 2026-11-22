#include "common.h"

extern u8 *reg_a6;

void func_001FEF40(void) {
    if (*(u16 *)(reg_a6 + 0x28) == 0) {
        *(u16 *)(reg_a6 + 0x28) = 1;
        *(u16 *)(reg_a6 + 0x1A) = 0x420;
    }
}
