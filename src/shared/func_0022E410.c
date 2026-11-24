#include "common.h"

void func_0022CDB0(s32 arg0);
void func_0022CF20(void);
void func_0022D240(s32 arg0);
void func_00233EE0(void);
void func_00233F50(void);
void func_00234200(void);
s32 func_00234400(s32 index);
extern u16 D_0028EC9C;
extern u16 D_0028ECA0;
extern u16 D_0028ECA4;
extern s32 D_0028ECC8;
extern s32 D_0028ECCC;
extern s32 D_0028ECD0;
extern u8 D_0028ECD8;
extern u8 D_0028ECDC;
extern u8 D_0028ECE0;
extern u8 D_0028ECE4;
extern u8 D_0028ECEC;
extern u8 D_0028ECF0;
extern u8 D_0028ECFC;
extern s32 D_0028ED1C;
extern s32 D_0057CC78[];

void func_0022E410(void) {
    s32 diff;
    s32 step;

    func_0022CF20();
    if ((D_0028ECF0 != 20) && (D_0028ECF0 != 0)) {
        func_00234400(D_0028ED1C);
        func_00233F50();
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 1;
        D_0028ECE4 = 3;
        D_0028ECA0 = 206;
        D_0028ECA4 = 324;
        D_0028ECF0 += 1;
        D_0028ECE0 = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        if (D_0028ECE0 > 60) {
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                D_0028ECE0 = 0;
                if (D_0028ECC8 != 0) {
                    D_0028ECF0 = 20;
                    break;
                }
            }
        } else {
            D_0028ECE0 += 1;
        }
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 4;
            if (D_0028ECD0 == 0) {
                D_0028ECCC = 0;
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
    case 3:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 2;
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
    case 4:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECF0 = 0;
            if (D_0028ECEC == 1) {
                D_0028ECFC = 17;
            } else {
                D_0028ECD8 = 1;
                D_0028ECFC = 16;
            }
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 17;
        }
        break;
    }
}
