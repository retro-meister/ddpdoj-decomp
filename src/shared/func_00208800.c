#include "common.h"

extern s8 D_0028E408;

s32 func_0016A8D0();
s32 func_0018DA30();
s32 func_0018DA50();
s32 func_00208610();
s32 func_00208660();
s32 func_00208710();
s32 func_00209200();
s32 func_002093F0();
extern u8 D_00268010[];
extern u8 D_00268030[];
extern s8 D_0028DFA0;
extern u8 *reg_a0;

void func_00208800(void) {
    func_0016A8D0();
    if (reg_d0.w & 1) {
        func_0018DA50();
        func_00208610();
        D_0028DFA0 -= 1;
        if (0 > D_0028DFA0) {
            D_0028DFA0 = 9;
        }
        func_00208660();
        func_00208710();
        reg_d0.h[0] = 0;
        reg_a0 = (u8 *)D_00268010;
        func_00209200();
        if (D_0028DFA0 == 8) {
            reg_a0 = (u8 *)D_00268030;
            func_00209200();
        }
    }
    func_0016A8D0();
    if (reg_d0.w & 2) {
        func_0018DA50();
        func_00208610();
        D_0028DFA0 += 1;
        if (D_0028DFA0 > 9) {
            D_0028DFA0 = 0;
        }
        func_00208660();
        func_00208710();
        reg_d0.h[0] = 0;
        reg_a0 = (u8 *)D_00268010;
        func_00209200();
        if (D_0028DFA0 == 8) {
            reg_a0 = (u8 *)D_00268030;
            func_00209200();
        }
    }
    func_0016A8D0();
    if (reg_d0.w & 0x10) {
        func_0018DA30();
        if (D_0028DFA0 == 0) {
            reg_d0.w = 1;
            func_002093F0();
        }
        if (D_0028DFA0 == 1) {
            reg_d0.w = 2;
            func_002093F0();
        }
        if (D_0028DFA0 == 2) {
            reg_d0.w = 3;
            func_002093F0();
        }
        if (D_0028DFA0 == 3) {
            reg_d0.w = 4;
            func_002093F0();
        }
        if (D_0028DFA0 == 4) {
            reg_d0.w = 5;
            func_002093F0();
        }
        if (D_0028DFA0 == 5) {
            reg_d0.w = 6;
            func_002093F0();
        }
        if (D_0028DFA0 == 6) {
            reg_d0.w = 7;
            func_002093F0();
        }
        if (D_0028DFA0 == 7) {
            reg_d0.w = 8;
            func_002093F0();
        }
        if (D_0028DFA0 == 8) {
            reg_d0.w = 9;
            func_002093F0();
        }
        if (D_0028DFA0 == 9) {
            D_0028E408 = 1;
            return;
        }
        goto block_31;
    }
block_31:
    D_0028E408 = 0;
}
