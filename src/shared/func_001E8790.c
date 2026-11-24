#include "common.h"

extern u8 *reg_a6;

void func_001E8790(void) {
    *(s16 *)(reg_a6 + 0x166) = 1;
}
