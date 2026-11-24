#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_001A3020();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_00263F00[];
extern s32 D_00263F10[];
extern s32 D_00263F30[];
extern s32 D_00263F50[];
extern s32 D_00263F90[];
extern s32 D_00263FD0[];
extern s32 D_00264010[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_001E76A0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00263F00;
    func_00209200();
    reg_a0_as_s32_p = D_00263F10;
    func_00209200();
    reg_a0_as_s32_p = D_00263F30;
    func_00209200();
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00263F50;
    func_001A3020();
    reg_d0.h[0] = 1;
    reg_a0_as_s32_p = D_00263F90;
    func_001A3020();
    reg_d0.h[0] = 2;
    reg_a0_as_s32_p = D_00263FD0;
    func_001A3020();
    reg_d0.h[0] = 3;
    reg_a0_as_s32_p = D_00264010;
    func_001A3020();
    reg_d0.w = 0;
}
