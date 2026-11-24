#include "common.h"

extern u16 *reg_a6;

s32 death_func_001271E0(void) {
    return (*reg_a6 & 0x3F) == 0x24;
}
