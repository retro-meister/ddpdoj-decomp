#include "common.h"

extern u8* reg_a6;

void func_001F57C0(void) {
    *(s16*)(reg_a6 + 0x106) = 0;
}
