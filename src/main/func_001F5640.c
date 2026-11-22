#include "common.h"

extern u8 *reg_a6;

void func_001F5640(void) {
    reg_d0.h[0] = 0xA001;
    (*(u16 *)((u8 *)(reg_a6) + (0))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x60))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x80))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xA0))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xC0))) |= reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x1A0))) |= reg_d0.h[0];
}
