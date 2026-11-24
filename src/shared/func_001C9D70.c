#include "common.h"

s32 func_001C9DB0();
extern u8 *reg_a4;

void func_001C9D70(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 2;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x404;
    reg_tmp.w = 0x5C001C00;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_tmp.h[0];
    func_001C9DB0();
}
