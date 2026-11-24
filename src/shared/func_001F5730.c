#include "common.h"

extern void *reg_a6_as_void_p;

void func_001F5730(void) {
    u16 *flags;
    u32 combined;

    reg_d0.h[0] = 0xA001;
    flags = (u16 *)reg_a6_as_void_p;
    combined = (u32)flags[0xC0] | (u32)reg_d0.h[0];
    flags[0xC0] = (u16)combined;
#ifdef DEATH_LABEL
    flags = (u16 *)reg_a6_as_void_p;
    combined = (u32)flags[0x100] | (u32)reg_d0.h[0];
    flags[0x100] = (u16)combined;
#endif
}
