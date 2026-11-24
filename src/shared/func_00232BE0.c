#include "common.h"

s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
s32 sceMcUnformat(s32 arg0, s32 arg1);
extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
s32 func_0022CC70(s32 arg0);
void func_0022CF20(void);
void func_00233EE0(void);
void func_00234150(s32 arg0);
void func_00234200(void);
extern s32 D_0028DDEC;
extern s32 D_0028DDF0;
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern u8 D_0028ECF0;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0057CC78[];

void func_00232BE0(void) {
    s32 result;
    s32 status;

    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        status = func_0022CC70(0);
        if ((status == 4) || (status == 3)) {
            D_0028ECF0 = 20;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 1:
        if (sceMcUnformat(D_0028EC70, D_0028EC74) == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_00234150(4);
        if (sceMcSync(1, 0, &result) != 0) {
            if (result == 0) {
                D_0028ECF0 += 1;
            } else {
                D_0028ECF0 = 10;
            }
        }
        break;
    case 3:
        func_0022C5E0(200, D_0028DDEC, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 += 1;
        }
        break;
    case 4:
        D_0028ECF0 = 5;
        break;
    case 5:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 10:
        func_0022C5E0(200, D_0028DDF0, 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 4;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 4;
        }
        break;
    }
}
