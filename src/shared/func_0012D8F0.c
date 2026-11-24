#include "common.h"

s32 func_0012D810();
extern u8 *reg_a6;

void func_0012D8F0(void) {
    (*(u8 *)((u8 *)(reg_a6) + (1))) &= 0xFE;
    reg_tmp.w = 0xFE00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x210;
    func_0012D810();
}
