#include "common.h"

extern u8 *reg_a6;

void func_001BC390(void) {
    *(s16 *)((u8 *)reg_a6 + 0xE8) = 1;
}
