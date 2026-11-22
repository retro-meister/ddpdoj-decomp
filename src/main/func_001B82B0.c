#include "common.h"

extern s16 *reg_a6;
extern u16 D_0029AA30[];

void func_001B82B0(void) {
    *reg_a6 = 0;
    D_0029AA30[0] -= 1;
}
