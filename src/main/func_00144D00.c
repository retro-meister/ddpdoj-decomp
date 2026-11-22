#include "common.h"

s32 func_00144F00();
s32 func_00145640();
extern u16 D_0028E91C;
extern s32 D_0028ED70;
extern u8 D_0028ED7C;
extern u16 D_0029F260[];
extern u16 D_006C68B6[];
extern u16 *reg_a6;

void func_00144D00(u8 arg0) {
    u8 var_a0;

    var_a0 = arg0;
    if ((D_0028E91C == 0) && (var_a0 = D_0028ED7C, (var_a0 == 2)) && (D_0028ED70 == 0)) {
        reg_a6 = D_006C68B6;
        reg_d0.h[0] = *reg_a6;
        if ((s16) reg_d0.h[0] < 0) {
            func_00145640();
        }
    } else {
        reg_a6 = D_0029F260;
        reg_d0.h[0] = *reg_a6;
        if ((s16) reg_d0.h[0] < 0) {
            func_00144F00();
        }
    }
}
