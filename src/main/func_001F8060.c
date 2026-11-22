#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u8 D_00261BB0[];
extern u8 D_002657F0[];
extern u8 D_00265810[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F8060(void) {
    reg_a0 = D_00265810;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x1C)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) -= 1;
    reg_a0 = D_002657F0;
    reg_d0.w = 0xB;
    func_0014E300();
    reg_d0.h[0] = 0x15;
    reg_a0 = D_00261BB0;
    func_001A3020();
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
}
