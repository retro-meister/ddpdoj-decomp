#include "common.h"

extern u8 *reg_a6;
extern u16 D_0029A528[];

void func_00209EC0(void) {
    *(u16 *)(reg_a6 - 8) = 0;
    D_0029A528[0] -= 1;
}
