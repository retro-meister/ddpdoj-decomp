#include "common.h"

s32 func_0013EAD0(u32, u32, u32, u32);          /* extern */
s32 func_0013EC50();                            /* extern */
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern u32 D_0028E428;
extern s32 *D_0028E42C;
extern s32 D_0029F1F0[];
extern s32 *reg_a6;

void func_0013EB60(void) {
    D_0028E41C = reg_d3.w;
    D_0028E418 = reg_d4.w;
    D_0028E414 = reg_d5.w;
    D_0028E428 = reg_d0.w;
    D_0028E424 = reg_d1.w;
    D_0028E420 = reg_d2.w;
    D_0028E410 = reg_d6.w;
    D_0028E40C = reg_d7.w;
    D_0028E42C = reg_a6;
    func_0013EAD0(reg_d6.w, reg_d2.w, reg_d1.w, reg_d0.w);
    reg_a6 = D_0029F1F0;
    func_0013EC50();
}
