#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
extern u8 D_002584B0[];
extern u8 D_002584E0[];
extern s16 D_0028E3A8;
extern s16 D_00299768[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001586A0() {
    u16 temp_a1;

    reg_a0 = D_002584E0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
    (*(u16 *)((u8 *)(reg_a6) + (0x1A))) = temp_a1;
    reg_a0 = D_002584B0;
    reg_d0.w = 0x11;
    func_0014E300();
    D_00299768[0] = 1;
    D_0028E3A8 = 1;
}
