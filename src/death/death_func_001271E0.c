#include "common.h"

extern u16 *reg_a6_as_u16_p;

s32 death_func_001271E0(void) {
    return (*reg_a6_as_u16_p & 0x3F) == 0x24;
}
