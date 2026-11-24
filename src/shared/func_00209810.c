#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
s32 func_00209790();                            /* extern */
extern s32 D_00268360[];
extern s32 D_002683F0[];
extern s32 D_00268410[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_00209810(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00268360;
    func_00209200();
    reg_a0_as_s32_p = D_002683F0;
    func_00209200();
    reg_a0_as_s32_p = D_00268410;
    func_00209200();
    func_00209790();
    reg_d0.w = 0;
}
