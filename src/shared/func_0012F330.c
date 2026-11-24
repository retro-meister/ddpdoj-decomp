#include "common.h"

extern u8 *reg_a6;

void func_0012F330(void) {
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x1B4;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
    (*(s16 *)((u8 *)(reg_a6) + (0x2C))) = 0x14;
    (*(s16 *)((u8 *)(reg_a6) + (0x2E))) = 0x101;
    reg_tmp.w = 0x21;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
}
