#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00208D30();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_002680D0[];
extern s32 D_00268100[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_00208CD0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    func_00208D30();
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_002680D0;
    func_00209200();
    reg_a0_as_s32_p = D_00268100;
    func_00209200();
    reg_d0.w = 0;
}
