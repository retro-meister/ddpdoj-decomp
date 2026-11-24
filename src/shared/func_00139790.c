#include "common.h"

extern void *reg_a1_as_void_p;
extern void *reg_a5_as_void_p;

void func_00139790(void) {
    u8 *entry = reg_a1_as_void_p;

    if (0 <= (s64)*(s16 *)entry) {
        return;
    }

    reg_d2.h[0] = *(u16 *)(entry + 4);
    reg_d3.w = 7;

    if ((s32)reg_d2.h[0] > 0x300) {
        reg_d3.w = 6;
        if ((s32)reg_d2.h[0] < 0x3500) {
            return;
        }
    }

    ((u8 *)reg_a5_as_void_p)[0x31] |= (u8)(1 << (s8)reg_d3.b[0]);
}
