#include "common.h"

extern void *reg_a6;
extern void *reg_a4;

void func_001BB0B0(void) {
    *(u16 *)reg_a4 = 0;
    ((u8 *)reg_a4)[3] = ((u8 *)reg_a6)[0x1B];
}
