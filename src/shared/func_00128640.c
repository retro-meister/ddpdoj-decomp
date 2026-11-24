#include "common.h"

extern u16 *reg_a6_as_u16_p;

void func_00128640(void) {
    reg_a6_as_u16_p[0] = 0;
    reg_a6_as_u16_p[1] = 0xFFFF;
}
