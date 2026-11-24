#include "common.h"

s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
s32 sceMcGetInfo(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3, s32 *arg4);
s32 sceMcFormat(s32 arg0, s32 arg1);
extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
void func_0022CF20(void);
void func_00233EE0(void);
void func_00234150(s32 arg0);
void func_00234200(void);
extern s32 D_0028DE00;
extern s32 D_0028DE04;
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECAC;
extern s32 D_0028ECB0;
extern s32 D_0028ECB4;
extern s32 D_0028ECB8;
extern u8 D_0028ECE4;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern u8 D_0028ECFC;
extern s32 D_0028ED10;
extern s32 D_0057CC78[];

void func_00232710(void) {
    s32 result;

    func_0022CF20();
    if (D_0028ECF0 < 6) {
        func_00234150(3);
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECE4 = 30;
        D_0028ECF0 += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF8 = 10;
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        D_0028ECAC = sceMcGetInfo(D_0028EC70, D_0028EC74, &D_0028ECB8, &D_0028ECB4, &D_0028ECB0);
        if (D_0028ECAC == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            switch (result) {
            case 0:
                D_0028ECF0 += 1;
                D_0028ECF8 = 10;
                break;
            default:
            case -1:
            case -2:
                D_0028ECF0 = 10;
                break;
            }
        }
        break;
    case 4:
        if (sceMcFormat(D_0028EC70, D_0028EC74) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                D_0028ECF0 += 1;
            } else {
                D_0028ECF0 = 10;
            }
        }
        break;
    case 6:
        func_0022C5E0(200, D_0028DE00, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 += 1;
        }
        break;
    case 7:
        D_0028ECF0 = 0;
        D_0028ECFC = 11;
        break;
    case 10:
        func_0022C5E0(200, D_0028DE04, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 7;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 7;
        }
        break;
    }
}
