#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
extern u8 D_00266360[];
extern u8 D_0028DA40;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FF610() {
    u16 temp_a1;

    reg_a0 = D_00266360;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    temp_a1 = (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = temp_a1;
    reg_a0 = &D_0028DA40;
    reg_d0.h[0] = 2;
    func_0014E300();
}
