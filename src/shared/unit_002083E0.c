#include "common.h"

void func_00208430(void);

s32 func_0012FD00();                            /* extern */
s32 func_00208AD0();                            /* extern */
s32 func_00209200();                            /* extern */
extern s32 D_00267EB0[];
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern s32 *reg_a0_as_s32_p;

void func_002083E0(void) {
    func_0012FD00();
    func_00208AD0();
    D_0028DFA0 = 0;
    D_0028DF9C = 0x50;
    func_00208430();
    reg_d0.h[0] = 0;
    reg_a0_as_s32_p = D_00267EB0;
    func_00209200();
    reg_d0.w = 0;
}

extern s32 D_00267EC0[];
extern s32 D_00267ED0[];
extern s32 D_00267EE0[];
extern s32 D_00267EF0[];
extern s32 D_00267F08[];

void func_00208430(void) {
    reg_a0_as_s32_p = D_00267EC0;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0_as_s32_p = D_00267ED0;
    func_00209200();
    reg_a0_as_s32_p = D_00267EE0;
    func_00209200();
    reg_a0_as_s32_p = D_00267EF0;
    func_00209200();
    reg_a0_as_s32_p = D_00267F08;
    func_00209200();
}

s32 func_002092F0();
s32 func_002093F0();
extern u8 D_0028DA94;

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
