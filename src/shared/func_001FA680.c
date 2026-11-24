#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
extern u8 D_00265C90[];
extern u8 D_0028DA30;
extern s16 D_0028E890_as_s16;
extern s16 D_00299768[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FA680() {
    u16 temp_a1;

    reg_a0 = D_00265C90;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = temp_a1;
    reg_a0 = &D_0028DA30;
    reg_d0.h[0] = 2;
    func_0014E300();
    D_0028E890_as_s16 = 1;
    D_00299768[0] = 1;
}
