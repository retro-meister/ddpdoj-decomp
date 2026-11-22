#include "common.h"

s32 func_00208430();
s32 func_002092F0();
s32 func_002093F0();
extern u8 D_0028DA94;
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern u8 *reg_a0;

void func_002084A0(void) {
    func_00208430();
    if (D_0028DFA0 == 0) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x26;
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA94;
        func_002092F0();
        D_0028DFA0 = 1;
    }
    if (D_0028DFA0 == 1) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x24;
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA94;
        func_002092F0(D_0028DFA0);
        D_0028DFA0 = 2;
    }
    if (D_0028DFA0 == 2) {
        reg_d2.h[0] = 2;
        reg_d0.w = 0x15;
        reg_d1.w = 0x22;
        reg_a0 = &D_0028DA94;
        func_002092F0(D_0028DFA0);
        D_0028DFA0 = 3;
    }
    if (D_0028DFA0 == 3) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x20;
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA94;
        func_002092F0(D_0028DFA0);
        D_0028DFA0 = 4;
    }
    if (D_0028DFA0 == 4) {
        reg_d0.w = 0x15;
        reg_d1.w = 0x1E;
        reg_d2.h[0] = 2;
        reg_a0 = &D_0028DA94;
        func_002092F0(D_0028DFA0);
        D_0028DFA0 = 5;
    }
    if (D_0028DFA0 == 5) {
        D_0028DF9C -= 1;
        if (D_0028DF9C == 0) {
            reg_d0.w = 0;
            func_002093F0(D_0028DFA0);
        }
    }
    reg_d0.w = 0;
}
