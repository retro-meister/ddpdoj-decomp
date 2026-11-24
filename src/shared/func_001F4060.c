#include "common.h"

extern void func_001F4090(u8);
extern void *reg_a4_as_void_p;
extern void *reg_a6_as_void_p;

void func_001F4060(void) {
    u8 val;

    reg_d0.w = 0;
    val = reg_d0.b[0];
    *((u8 *)reg_a4_as_void_p + 1) = reg_d0.b[0];
    val = reg_d0.b[0];
    *((u8 *)reg_a4_as_void_p + 0) = reg_d0.b[0];
    *((u8 *)reg_a6_as_void_p + 0x1B) = 6;
    func_001F4090(val);
}
