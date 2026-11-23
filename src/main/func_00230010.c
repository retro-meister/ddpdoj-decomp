#include "common.h"

void func_0022CF20(void);
void func_0022D240(s32 arg0);
void func_00233F50(void);
void func_00234370(s32 arg0);
extern u16 D_0028EC9C;
extern u16 D_0028ECA0;
extern u16 D_0028ECA4;
extern s8 D_0028ECBC;
extern u8 D_0028ECDC;
extern u8 D_0028ECEC;
extern u8 D_0028ECF0;
extern u8 D_0028ECFC;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0028ED1C;
extern s32 D_0028ED20;
extern s32 D_0057CC78[];

void func_00230010(void) {
    s32 diff;
    s32 step;

    if (D_0028ED20 == 4) {
        if (D_0028ECBC != 0) {
            D_0028ECF0 = 0;
            D_0028ECFC = 2;
            return;
        }
        func_0022CF20();
        func_00234370(11);
    } else {
        if (D_0028ECBC != 0) {
            D_0028ECF0 = 0;
            D_0028ECFC = 2;
            return;
        }
        func_0022CF20();
        func_00234370(D_0028ED1C);
    }
    switch (D_0028ECF0) {
    case 0:
        if (D_0028ED20 == 4) {
            D_0028ECEC = 1;
            D_0028ECA4 = 324;
        } else {
            D_0028ECEC = 1;
            D_0028ECA4 = 324;
        }
        D_0028ECA0 = 206;
        D_0028ECF0 += 1;
    case 1:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECF0 = 3;
            } else {
                D_0028ECFC = 2;
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 2:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 1;
            break;
        }
        diff = D_0028EC9C - D_0028ECA4;
        step = diff / 2;
        if (step == 0) {
            step = 1;
            if (D_0028ECEC == 0) {
                step = -1;
            }
        }
        D_0028ECA4 += step;
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    func_00233F50();
}
