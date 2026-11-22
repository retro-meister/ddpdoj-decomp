#include "common.h"

extern u8 *reg_a6;

void func_001F5630(void) {
    *(s16 *)(reg_a6 + 0x108) = 0;
}
