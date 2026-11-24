#include "common.h"

extern u16 *reg_a5_as_u16_p;

void func_001713F0(u16 val) {
    reg_a5_as_u16_p[2] = val;
}
