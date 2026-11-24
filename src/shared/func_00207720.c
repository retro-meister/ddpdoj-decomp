#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_001A3020();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_002554B0_as_s32_a[];
extern s32 D_00267990[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_00207720(void) {
    func_0012FD00();
    func_00208AD0();
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_002554B0_as_s32_a;
    func_001A3020();
    D_0028DFA0 = 0;
    D_0028DF9C = 1;
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00267990;
    func_00209200();
    reg_d0.w = 0;
}
