#include "common.h"

extern u8 *D_0028DF48, *D_0028DF4C, *D_0028DF50, *D_0028DF54, *D_0028DF58, *D_0028DF5C, *D_0028DF60;
extern u32 D_0028DF64, D_0028DF68, D_0028DF6C, D_0028DF70, D_0028DF74, D_0028DF78, D_0028DF7C, D_0028DF80;
extern s8 D_0028E408;
extern u8 *reg_a0, *reg_a1, *reg_a2, *reg_a3, *reg_a4, *reg_a5, *reg_a6;

void func_0015C0E0(void) {
    reg_d0.w = D_0028DF80;
    reg_d1.w = D_0028DF7C;
    reg_d2.w = D_0028DF78;
    reg_d3.w = D_0028DF74;
    reg_d4.w = D_0028DF70;
    reg_d5.w = D_0028DF6C;
    reg_d6.w = D_0028DF68;
    reg_d7.w = D_0028DF64;
    reg_a0 = (u8 *)D_0028DF60;
    reg_a1 = (u8 *)D_0028DF5C;
    reg_a2 = (u8 *)D_0028DF58;
    reg_a3 = (u8 *)D_0028DF54;
    reg_a4 = (u8 *)D_0028DF50;
    reg_a5 = (u8 *)D_0028DF4C;
    reg_a6 = (u8 *)D_0028DF48;
    D_0028E408 = 1;
}
