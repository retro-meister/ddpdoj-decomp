#include "common.h"

extern s16 *reg_a6_as_s16_p;
extern u16 D_0029AA30[];

void func_001B82B0(void) {
    *reg_a6_as_s16_p = 0;
    D_0029AA30[0] -= 1;
}
