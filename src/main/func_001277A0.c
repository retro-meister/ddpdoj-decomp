#include "common.h"

s32 func_001278D0();
extern u8 D_002695A0[];
extern u8 D_0029F1F0[];
extern u8 *reg_a0;
extern u8 *reg_a3;

void func_001277A0(void) {
    reg_a3 = D_002695A0;
    reg_tmp.w = (u32) D_0029F1F0;
    (*(u16 *)((u8 *)(reg_a0) + (0x24))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = (u16) reg_tmp.h[0];
    func_001278D0();
}
