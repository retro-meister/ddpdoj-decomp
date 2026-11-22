#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00208E20();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_00268120[];
extern s32 D_00268210[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0;

void func_00208DC0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    func_00208E20();
    reg_d0.h[0] = 0;
    reg_a0 = D_00268120;
    func_00209200();
    reg_a0 = D_00268210;
    func_00209200();
    reg_d0.w = 0;
}
