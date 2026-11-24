#include "common.h"

extern u8 *reg_a6;

void func_001D4550(void) {
    *(s16 *)(reg_a6 + 0x88) = 0;
}
