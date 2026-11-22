#include "common.h"

extern void *D_0028E450;

void func_001F5730(void) {
    u16 *flags;
    u32 combined;

    work_reg_0.h[0] = 0xA001;
    flags = (u16 *)D_0028E450;
    combined = (u32)flags[0xC0] | (u32)*(u16 *)&work_reg_0.h[0];
    flags[0xC0] = (u16)combined;
}
