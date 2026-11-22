#include "common.h"

s32 func_0014E030();
s32 func_001FAD00();
s32 func_002011A0();
extern u16 D_0028E89C;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001FBD90(u16 arg1) {
    u16 var_a1;

    var_a1 = arg1;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x88))) == 0) {
        reg_d0.w = 2;
        func_001FAD00();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0x2828;
        func_002011A0();
        reg_d0.h[0] &= 1;
        var_a1 = reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a4) + (2))) = var_a1;
        (*(u16 *)((u8 *)(reg_a6) + (0x88))) = 1U;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (1)));
    (*(u8 *)((u8 *)(reg_a4) + (1))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (1))) = (*(u8 *)((u8 *)(reg_a4) + (0)));
        if (D_0028E89C == 0) {
            reg_d0.w = 0x53;
            func_0014E030();
            reg_tmp.w = (u32) reg_a6;
            (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_tmp.h[0];
            (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) (*(u16 *)((u8 *)(reg_a4) + (2)));
            (*(u16 *)((u8 *)(reg_a4) + (2))) += 1;
            (*(u16 *)((u8 *)(reg_a4) + (2))) &= 1;
        }
    }
}
