#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
extern u8 D_00258580[];
extern u8 D_002585B0[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00159040() {
    u16 temp_a1;

    reg_a0 = D_002585B0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = temp_a1;
    reg_a0 = D_00258580;
    reg_d0.w = 0x11;
    func_0014E300();
}
