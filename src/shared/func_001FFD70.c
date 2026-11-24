#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
extern u8 D_00266440[];
extern u8 D_00266460[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FFD70() {
    u8 temp_a1;

    reg_a0 = D_00266460;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    temp_a1 = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = temp_a1;
    reg_a0 = D_00266440;
    reg_d0.h[0] = 8;
    func_0014E300();
}
