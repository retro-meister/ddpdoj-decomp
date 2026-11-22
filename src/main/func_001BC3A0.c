#include "common.h"

extern u8 *reg_a6;

void func_001BC3A0(void) {
    *(s16 *)(reg_a6 + 0xE8) = 0;
}
