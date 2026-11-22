#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_00208660();                            /* extern */
s32 func_00208710();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_00267F18[];
extern s32 D_00267FF0[];
extern s32 D_00268010[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0;

void func_002086A0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 0;
    func_00208710();
    reg_d0.h[0] = 0;
    reg_a0 = D_00267F18;
    func_00209200();
    reg_a0 = D_00267FF0;
    func_00209200();
    reg_a0 = D_00268010;
    func_00209200();
    func_00208660();
    reg_d0.w = 0;
}
