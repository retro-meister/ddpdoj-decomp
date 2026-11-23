#include "common.h"

s32 func_001A9180();
s32 func_001A9190();
extern u32 D_0028E40C;
extern u32 D_0028E410;
extern u32 D_0028E414;
extern u32 D_0028E418;
extern u32 D_0028E41C;
extern u32 D_0028E420;
extern u32 D_0028E424;
extern u32 D_0028E428;
extern s32 D_0028E42C;
extern s32 D_0028E430;
extern s32 D_0028E434;
extern s32 D_0028E438;
extern u16 *D_0028E43C;
extern s32 D_0028E440;
extern s32 D_0028E444;
extern u16 D_002962E0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00201A00(void) {
    u16 *var_a0;
    var_a0 = (u16 *)(D_002962E0);
    reg_d2.w = 0;
    reg_a2 = (u8 *)(D_002962E0);
    reg_d7.h[0] = 0xD1;
    do {
        reg_d0.h[0] = *(u16 *)reg_a2;
        if ((s16) reg_d0.h[0] < 0) {
            if (reg_d1.h[0] & 0x10) {
                reg_d0.w = 0x23;
                func_001A9180();
            }
            if (reg_d1.h[0] & 8) {
                reg_d0.w = 0x23;
                func_001A9190();
            }
        }
        var_a0 = (u16 *)(reg_a2 + 0x40);
        reg_a2 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = D_0028E428;
    reg_d1.w = D_0028E424;
    reg_d2.w = D_0028E420;
    reg_d3.w = D_0028E41C;
    reg_d4.w = D_0028E418;
    reg_d5.w = D_0028E414;
    reg_d6.w = D_0028E410;
    reg_d7.w = D_0028E40C;
    reg_a0 = (u8 *)D_0028E444;
    reg_a1 = (u8 *)D_0028E440;
    reg_a2 = (u8 *)(D_0028E43C);
    reg_a3 = (u8 *)D_0028E438;
    reg_a4 = (u8 *)D_0028E434;
    reg_a5 = (u8 *)D_0028E430;
    reg_a6 = (u8 *)D_0028E42C;
}
