#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_00207860();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_002679C0[];
extern s32 D_00267A60[];
extern s32 D_00267A80[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0;

void func_002078E0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0 = D_002679C0;
    func_00209200();
    reg_a0 = D_00267A60;
    func_00209200();
    reg_a0 = D_00267A80;
    func_00209200();
    func_00207860();
    reg_d0.w = 0;
}
