#include "common.h"

extern u8 *reg_a6;

void func_0012ED50(void) {
    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 1;
    reg_tmp.w = 0x19;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x283;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
}
