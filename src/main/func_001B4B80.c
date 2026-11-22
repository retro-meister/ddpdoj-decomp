#include "common.h"

extern u8 *reg_a6;

void func_001B4B80(void) {
    *(s16 *)(reg_a6 + 0xAE) = 0;
}
