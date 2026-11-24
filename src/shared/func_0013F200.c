#include "common.h"

s32 func_0011C4A0();
extern u8 D_00255550[];
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern u32 D_0028E428;
extern s32 D_0028E444;
extern u8 *reg_a0;

void func_0013F200(void) {
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 0xB;
    reg_d4.h[0] -= 1;
    reg_d4.w = *(u32 *)(D_00255550 + (reg_d4.h[0] * 4));
    func_0011C4A0();
    reg_d0.w = D_0028E428;
    reg_d1.w = D_0028E424;
    reg_d2.w = D_0028E420;
    reg_d3.w = D_0028E41C;
    reg_d4.w = D_0028E418;
    reg_d5.w = D_0028E414;
    reg_d6.w = D_0028E410;
    reg_d7.w = D_0028E40C;
    reg_a0 = (u8 *)D_0028E444;
}
