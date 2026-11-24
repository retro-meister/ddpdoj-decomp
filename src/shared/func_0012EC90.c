#include "common.h"

extern u8 *reg_a6;

void func_0012EC90(void) {
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x297;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
    (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x20)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = 0U;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0U;
    reg_tmp.w = 0x18;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
}
