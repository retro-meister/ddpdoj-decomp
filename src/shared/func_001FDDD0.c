#include "common.h"

extern void *reg_a6;

void func_001FDDD0(void) {
    if (((u16 *)reg_a6)[0x26 / 2] != reg_d0.h[0]) {
        ((u16 *)reg_a6)[0x26 / 2] = (u16) reg_d0.h[0];
        ((u16 *)reg_a6)[0x28 / 2] = 0;
    }
}
