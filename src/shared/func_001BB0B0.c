#include "common.h"

extern void *reg_a6_as_void_p;
extern void *reg_a4_as_void_p;

void func_001BB0B0(void) {
    *(u16 *)reg_a4_as_void_p = 0;
    ((u8 *)reg_a4_as_void_p)[3] = ((u8 *)reg_a6_as_void_p)[0x1B];
}
