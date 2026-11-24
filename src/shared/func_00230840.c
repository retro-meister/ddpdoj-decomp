#include "common.h"

s32 func_0010EFF0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_0010F150(s32 arg0);
s32 func_0010F370(s32 arg0, void *arg1, s32 arg2);
s32 func_0010F670(s32 arg0, s32 arg1, s32 *arg2);
s32 func_0022CAB0(void);
void func_0022CF20(void);
void func_0022D240(s32 arg0);
void func_00233EE0(void);
void func_00234150(s32 arg0);
void func_002343A0(void);
void func_002343C0(void);
extern s32 D_00272010[];
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028EC94;
extern s32 D_0028EC98;
extern s32 D_0028ECA8;
extern s8 D_0028ECBC;
extern s32 D_0028ECC4;
extern u8 D_0028ECD4;
extern u8 D_0028ECE4;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern u8 D_0028ECFC;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern u32 D_0028ED1C;
extern s32 D_0057CC78[];
extern u8 D_006A4800[];
extern u8 D_006C4EF0[];

void func_00230840(void) {
    s32 result;
    s32 status;

    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        D_0028ECC4 = 0;
        D_0028ECF0 += 1;
        D_0028EC98 = 0;
        D_0028EC94 = 0x414;
        D_0028ECE4 = 60;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF8 = 10;
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        status = func_0010EFF0(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C], 3);
        if (status == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 3:
        if (func_0010F670(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
            } else {
                D_0028ECA8 = result;
                D_0028ECF8 = 10;
                D_0028ECF0 += 1;
            }
        }
        break;
    case 4:
        switch (D_0028ED1C) {
        case 0:
            status = func_0010F370(D_0028ECA8, D_006C4EF0, 2472);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            status = func_0010F370(D_0028ECA8, D_006A4800, 0x206EC);
            break;
        }
        if (status == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 5:
        if (func_0010F670(1, 0, &result) != 0) {
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 6:
        if (func_0010F150(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 30;
            }
        }
        break;
    case 7:
        if (func_0010F670(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
            } else {
                D_0028ECF8 = 10;
                if (func_0022CAB0() == 0) {
                    D_0028ECF0 = 10;
                } else {
                    D_0028ECF0 = 30;
                }
            }
        }
        break;
    case 8:
        D_0028ECF0 = 10;
        break;
    case 9:
        func_0010F670(0, 0, &result);
        if (result < 0) {
            D_0028ECF0 = 30;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 10:
        func_0022D240(10);
        D_0028ECF8 = 60;
        D_0028ECF0 += 1;
        break;
    case 11:
        func_002343A0();
        if (D_0028ECD4 != 0) {
            D_0028ECF8 -= 1;
            if ((s32)D_0028ECF8 <= 0) {
                D_0028ECF0 += 1;
            }
        } else {
            func_00233EE0();
            if (D_0057CC78[0] & 0x20) {
                D_0028ECF0 += 1;
            }
        }
        break;
    case 12:
        D_0028ECC4 = 1;
        D_0028ECF0 += 1;
        break;
    case 13:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        func_0022D240(11);
        D_0028ECF0 += 1;
    case 31:
        func_002343C0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            if (D_0028ECBC != 0) {
                D_0028ECF0 = 13;
            } else {
                D_0028ECF0 = 0;
                D_0028ECFC = 25;
            }
        }
        break;
    }
    if ((D_0028ECF0 < 8) && (D_0028ECFC == 22)) {
        func_00234150(1);
    }
}
