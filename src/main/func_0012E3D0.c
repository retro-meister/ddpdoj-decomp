#include "common.h"

extern u8 *reg_a6;

void func_0012E3D0(void) {
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0x1B4;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = 0x1A;
    (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x1E)));
    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x20)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = 0U;
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0U;
}
