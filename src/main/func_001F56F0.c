#include "common.h"

extern u8 *reg_a6;

void func_001F56F0(void) {
    reg_d0.h[0] = 0xA001;
    (*(u16 *)((u8 *)(reg_a6) + (0x140))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x160))) |= reg_d0.h[0];
}
