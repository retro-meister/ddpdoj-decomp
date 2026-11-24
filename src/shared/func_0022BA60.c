#include "common.h"

s32 func_00213060();
s32 func_00214C70();
s32 func_00215350();
void func_00215DB0(s32 a, s32 b, s32 c, s32 d, s32 e, s32 alpha, s32 g, s32 h, s32 i);
s32 func_002228D0();
extern s32 D_0028DDA8;
extern s32 D_0028EB90;
extern u8 D_0028EC3C;
extern u8 *reg_a0;

void func_0022BA60(void) {
    s32 var_s0;

    if (D_0028EB90 != 0) {
        func_00213060();
        var_s0 = D_0028EB90;
        if (D_0028EB90 >= 0x40) {
            var_s0 = 0x40;
        }
        if (var_s0 != 0) {
            func_00214C70(D_0028EB90);
            func_00215DB0(0xC, 8, 0x40, 0xD0, 0x12C, var_s0, 1, 1, 0x40);
        }
        if ((D_0028EC3C != 0) && ((u32) (D_0028EC3C - 1) > 1U) && ((u32) (D_0028EC3C - 5) > 1U)) {
            reg_a0 = (u8 *)D_0028DDA8;
            func_002228D0(0x36, 8);
        }
        func_00215350();
    }
}
