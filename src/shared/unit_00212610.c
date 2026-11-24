#include "common.h"

s32 func_0012FD00();                            /* extern */
s32 func_00208AD0();                            /* extern */
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;

void func_00212610(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 0;
    reg_d0.w = 0;
}

s32 func_002092F0();
s32 func_002093F0();
s32 func_00209410();
extern u8 D_0026F760[];
extern u8 D_0026F780[];
extern u8 *reg_a0;

void func_00212640(void) {
    D_0028DF9C += 1;
    if (D_0028DF9C >= 7) {
        D_0028DF9C = 0;
        D_0028DFA0 += 1;
    }
    reg_d0.b[0] = (u8) D_0028DFA0;
    reg_d0.b[0] &= 1;
    if (reg_d0.b[0] == 0) {
        reg_d0.h[0] = 8;
        reg_d1.h[0] = 0x1E;
        reg_d2.h[0] = 2;
        reg_a0 = (u8 *)D_0026F760;
        func_002092F0();
    } else {
        reg_d0.h[0] = 8;
        reg_d1.h[0] = 0x1E;
        reg_d2.h[0] = 2;
        reg_a0 = (u8 *)D_0026F780;
        func_002092F0();
    }
    if (D_0028DFA0 == 8) {
        func_00209410();
        reg_d0.w = 0;
        func_002093F0();
        reg_d0.w = 0;
    } else {
        reg_d0.w = 0;
    }
}
