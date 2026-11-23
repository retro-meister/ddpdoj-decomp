#include "common.h"

s32 func_0010F118(s32 arg0, s32 arg1, s32 arg2);
s32 func_0010F670(s32 arg0, s32 arg1, s32 *arg2);
void func_0022CDB0(s32 arg0);
void func_0022CF20(void);
void func_00233EE0(void);
void func_00234150(s32 arg0);
void func_00234200(void);
void func_002342D0(void);
extern s32 D_00271FB0[];
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECC0;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;
extern u8 D_0028ECD8;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern u8 D_0028ECFC;
extern s32 D_0028ED1C;
extern s32 D_0057CC78[];

void func_0022DFF0(void) {
    s32 result;

    func_0022CF20();
    if (D_0028ECF0 == 1) {
        func_00234150(0);
    }
    switch (D_0028ECF0) {
    case 0:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 != 0) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECC0 = 0;
            if (func_0010F118(D_0028EC70, D_0028EC74, D_00271FB0[D_0028ED1C]) == 0) {
                D_0028ECF0 += 1;
                break;
            }
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 1:
        if (func_0010F670(1, 0, &result) != 0) {
            if (result == 0) {
                D_0028ECD8 = 0;
                D_0028ECFC = 16;
                D_0028ECF0 = 0;
            } else {
                D_0028ECF0 = 30;
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
    case 30:
        func_002342D0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 17;
        }
        break;
    }
}
