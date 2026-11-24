#include "common.h"

extern void *reg_a6_as_void_p;
extern u16 D_0029A528[];

void func_00209EA0(void) {
    *(u16 *)((u8 *)reg_a6_as_void_p - 4) = 0;
    D_0029A528[0] -= 1;
}
