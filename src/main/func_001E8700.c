#include "common.h"

extern u8 *reg_a6;

void func_001E8700(void) {
    *(s16 *)(reg_a6 + 0x168) = 1;
}
