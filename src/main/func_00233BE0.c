#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
void func_0022CDB0(s32 arg0);
void func_0022CF20(void);
void func_0022D240(s32 arg0);
void func_00233EE0(void);
void func_00234230(void);
extern s32 D_0028DE14;
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECC4;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;
extern u8 D_0028ECE0;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0057CC78[];

void func_00233BE0(void) {
    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        D_0028ECC4 = 0;
        D_0028ECF0 += 1;
        D_0028ECE0 = 0;
        D_0028ECF8 = 60;
        break;
    case 1:
        func_00234230();
        if (D_0028ECF8 != 0) {
            D_0028ECF8 -= 1;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_00234230();
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 2:
            case 3:
            case 4:
                func_0022D240(11);
                D_0028ECF0 = 20;
                break;
            default:
                D_0028ECC4 = 1;
                D_0028ECF0 += 1;
                break;
            }
        }
        break;
    case 3:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 20:
        if (D_0028ECE0 > 60) {
            D_0028EC70 = 0;
            D_0028EC74 = 0;
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    D_0028ECF0 = 0;
                    break;
                }
                D_0028ECE0 = 0;
            }
        } else {
            D_0028ECE0 += 1;
        }
        func_0022C5E0(200, D_0028DE14, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 3;
        }
        break;
    }
}
