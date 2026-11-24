#include "common.h"

s32 func_00144F00();
s32 func_00145640();
extern u16 D_0028E91C;
extern s32 D_0028ED70;
extern u8 D_0028ED7C;
extern u16 D_0029F1F0_as_u16_a[];
extern u16 D_006C6918_as_u16_a[];
extern u16 *reg_a6_as_u16_p;

void func_00144DA0(u8 arg0) {
    u8 var_a0;

    var_a0 = arg0;
    if ((D_0028E91C == 0) && (var_a0 = D_0028ED7C, (var_a0 == 2)) && (D_0028ED70 == 0)) {
        reg_a6_as_u16_p = D_006C6918_as_u16_a;
        reg_d0.h[0] = *reg_a6_as_u16_p;
        if ((s16) reg_d0.h[0] < 0) {
            func_00145640();
        }
    } else {
        reg_a6_as_u16_p = D_0029F1F0_as_u16_a;
        reg_d0.h[0] = *reg_a6_as_u16_p;
        if ((s16) reg_d0.h[0] < 0) {
            func_00144F00();
        }
    }
}
