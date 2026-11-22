#include "common.h"

extern u8 *reg_a6;

void func_001F5750(void) {
    reg_d0.h[0] = 0x8000;
    (*(u16 *)((u8 *)(reg_a6) + (0))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x40))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x60))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x80))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xA0))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0xC0))) = (u16) reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x1A0))) = (u16) reg_d0.h[0];
}
