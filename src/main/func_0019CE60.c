#include "common.h"

extern u16 reg_d7;

void func_0019CE60(void) {
    u32 value = reg_d7;
    reg_d7 = (u16)(value << 1);
}
