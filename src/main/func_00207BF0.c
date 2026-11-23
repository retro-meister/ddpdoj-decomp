#include "common.h"

s32 func_0016A8D0();
s32 func_0018DA30();
s32 func_0018DA50();
s32 func_002077E0();
s32 func_00207860();
s32 func_00207950();
s32 func_00207B60();
s32 func_002093F0();
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern u8 D_0028E380;
extern u8 D_0028E384;
extern u8 D_0028E388;
extern u8 D_0028E38C;

void func_00207BF0(void) {
    s64 temp_v1;
    s64 temp_v1_2;

    func_0016A8D0();
    if (reg_d0.w & 1) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_002077E0();
        D_0028DFA0 -= 1;
        if (0 > D_0028DFA0) {
            D_0028DFA0 = 4;
        }
        func_00207860();
    }
    func_0016A8D0();
    if (reg_d0.w & 2) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_002077E0();
        D_0028DFA0 += 1;
        if (D_0028DFA0 > 4) {
            D_0028DFA0 = 0;
        }
        func_00207860();
    }
    func_0016A8D0();
    if (reg_d0.w & 4) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E38C -= 1;
            if (0 > (s8) D_0028E38C) {
                D_0028E38C = 3;
            }
        }
        temp_v1 = D_0028DFA0;
        if (temp_v1 == 1) {
            D_0028E388 -= 1;
            if (0 > (s8) D_0028E388) {
                D_0028E388 = 3;
            }
        }
        if (temp_v1 == 2) {
            D_0028E384 -= 1;
            if (0 > (s8) D_0028E384) {
                D_0028E384 = 4;
            }
        }
        if (temp_v1 == 3) {
            D_0028E380 -= 1;
            D_0028E380 &= 1;
        }
    }
    func_0016A8D0();
    if (reg_d0.w & 8) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E38C += 1;
            if ((s8) D_0028E38C >= 4) {
                D_0028E38C = 0;
            }
        }
        temp_v1_2 = D_0028DFA0;
        if (temp_v1_2 == 1) {
            D_0028E388 += 1;
            if ((s8) D_0028E388 >= 4) {
                D_0028E388 = 0;
            }
        }
        if (temp_v1_2 == 2) {
            D_0028E384 += 1;
            if ((s8) D_0028E384 >= 5) {
                D_0028E384 = 0;
            }
        }
        if (temp_v1_2 == 3) {
            D_0028E380 += 1;
            D_0028E380 &= 1;
        }
    }
    func_0016A8D0();
    if ((reg_d0.w & 0x10) && (D_0028DFA0 == 4)) {
        func_0018DA30();
        reg_d0.w = 0;
        func_002093F0();
    } else if (D_0028DF9C != 0) {
        D_0028DF9C = 0;
        func_00207950();
        func_00207B60();
    }
    reg_d0.w = 0;
}
