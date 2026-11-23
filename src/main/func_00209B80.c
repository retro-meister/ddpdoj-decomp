#include "common.h"

extern s8 D_0028E408;

s32 func_0016A8D0();
s32 func_0018DA30();
s32 func_0018DA50();
s32 func_002093F0();
s32 func_00209710();
s32 func_00209790();
s32 func_00209880();
s32 func_00209AF0();
extern s8 D_0028DF9C;
extern s8 D_0028DFA0;
extern u8 D_0028E390;
extern u8 D_0028E394;
extern u8 D_0028E398;
extern u8 D_0028E39C;

void func_00209B80(void) {
    s64 temp_v1;
    s64 temp_v1_2;

    func_0016A8D0();
    if (reg_d0.w & 1) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_00209710();
        D_0028DFA0 -= 1;
        if (0 > D_0028DFA0) {
            D_0028DFA0 = 4;
        }
        func_00209790();
    }
    func_0016A8D0();
    if (reg_d0.w & 2) {
        D_0028DF9C = 1;
        func_0018DA50();
        func_00209710();
        D_0028DFA0 += 1;
        if (D_0028DFA0 > 4) {
            D_0028DFA0 = 0;
        }
        func_00209790();
    }
    func_0016A8D0();
    if (reg_d0.w & 4) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E39C -= 1;
            if (0 > (s8) D_0028E39C) {
                D_0028E39C = 0x12;
            }
        }
        temp_v1 = D_0028DFA0;
        if (temp_v1 == 1) {
            D_0028E398 -= 1;
            D_0028E398 &= 1;
        }
        if (temp_v1 == 2) {
            D_0028E394 -= 1;
            D_0028E394 &= 1;
        }
        if (temp_v1 == 3) {
            D_0028E390 -= 1;
            if (0 > (s8) D_0028E390) {
                D_0028E390 = 2;
            }
        }
    }
    func_0016A8D0();
    if (reg_d0.w & 8) {
        D_0028DF9C = 1;
        if (D_0028DFA0 != 4) {
            func_0018DA50();
        }
        if (D_0028DFA0 == 0) {
            D_0028E39C += 1;
            if ((s8) D_0028E39C >= 0x13) {
                D_0028E39C = 0;
            }
        }
        temp_v1_2 = D_0028DFA0;
        if (temp_v1_2 == 1) {
            D_0028E398 += 1;
            D_0028E398 &= 1;
        }
        if (temp_v1_2 == 2) {
            D_0028E394 += 1;
            D_0028E394 &= 1;
        }
        if (temp_v1_2 == 3) {
            D_0028E390 += 1;
            if ((s8) D_0028E390 >= 3) {
                D_0028E390 = 0;
            }
        }
    }
    func_0016A8D0();
    if ((reg_d0.w & 0x10) && (D_0028DFA0 == 4)) {
        func_0018DA30();
        reg_d0.w = 0;
        func_002093F0();
    } else if (D_0028DF9C != 0) {
        D_0028DF9C = 0;
        func_00209880();
        func_00209AF0();
    }
    D_0028E408 = 0;
}
