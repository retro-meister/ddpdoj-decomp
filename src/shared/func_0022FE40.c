#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
void func_0022CF20(void);
void func_0022D240(s32 arg0);
void func_00233F50(void);
extern s32 D_0028DE18;
extern u16 D_0028EC9C;
extern u16 D_0028ECA0;
extern u16 D_0028ECA4;
extern u8 D_0028ECDC;
extern u8 D_0028ECEC;
extern u8 D_0028ECF0;
extern u8 D_0028ECFC;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0057CC78[];

void func_0022FE40(void) {
    s32 diff;
    s32 step;

    func_0022CF20();
    func_0022C5E0(200, D_0028DE18, 0, 20, 14, D_0028ED10, 100);
    switch (D_0028ECF0) {
    case 0:
        D_0028ECEC = 0;
        D_0028ECF0 += 1;
        D_0028ECA0 = 180;
        D_0028ECA4 = 214;
    case 1:
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            D_0028ECF0 = 3;
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 214;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 304;
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
        D_0028ECF0 = 0;
        if (D_0028ECEC == 1) {
            D_0028ECF0 = 4;
        } else {
            D_0028ECFC = 2;
        }
        break;
    case 4:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
    func_00233F50();
}
