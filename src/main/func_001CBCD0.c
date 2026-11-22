#include "common.h"

extern u8 *reg_a6;

void func_001CBCD0(void) {
    *(s16 *)(reg_a6 + 0x146) = 1;
}
