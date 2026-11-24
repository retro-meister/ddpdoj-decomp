#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_00201D10();
s32 func_00202180();
extern u8 D_002666A0[];
extern u8 D_002666B0[];
extern s8 D_0028E408;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_002005E0() {
    u8 temp_a1;

    reg_a0 = D_002666B0;
    func_0014E370();
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x16)));
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a5) + (0x18)));
    temp_a1 = (*(u8 *)((u8 *)(reg_a5) + (0x1B)));
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = temp_a1;
    reg_a0 = D_002666A0;
    reg_d0.h[0] = 7;
    func_0014E300();
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x20))) = (u16) reg_d3.h[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = 0x20U;
    func_00202180();
    if (D_0028E408 == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) = (u8) reg_d1.b[0];
    }
}
