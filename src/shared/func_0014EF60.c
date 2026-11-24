#include "common.h"

extern s8 *reg_a5;
extern s8 *reg_a0;

void func_0014EF60(void) {
    reg_a5[0x25] = *reg_a0;
    reg_a0 += 1;
}
