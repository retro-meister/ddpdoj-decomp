#include "common.h"

s32 func_0010F670(s32 arg0, s32 arg1, s32 *arg2);
s32 func_0010F998(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5);
void func_0022CDB0(s32 arg0);
void func_0022CF20(void);
void func_00233EE0(void);
void func_00234200(void);
void func_00234230(void);
void func_00234250(s32 arg0, s32 arg1);
void func_002342F0(s32 arg0);
void func_002343C0(void);
void func_002343E0(void);
s32 printf(const char *format, ...);
extern s32 D_00272010[];
extern char D_0028BB20[];
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028EC90;
extern s8 D_0028ECBC;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern u8 D_0028ECFC;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0028ED1C;
extern s32 D_0028ED20;
extern s32 D_0057CC78[];
extern u8 D_0069F580[];
extern s32 D_0069F590[];

void func_00230230(void) {
    s32 result;
    s32 error;

    func_0022CF20();
    switch (D_0028ECF0) {
    case 0:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                D_0028ECF0 = 20;
                break;
            default:
                D_0028ECF8 = 60;
                D_0028ECF0 += 1;
                break;
            }
        }
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
            case 0:
                D_0028ECF8 = 10;
                D_0028ECF0 += 1;
                if (D_0028ED20 == 4) {
                    D_0028ECF0 = 60;
                }
                if ((D_0028ED20 == 6) || (D_0028ED20 == 7)) {
                    D_0028ECF0 = 0;
                    D_0028ECFC = 27;
                }
                break;
            case 1:
                D_0028ECF0 = 40;
                break;
            case 2:
                D_0028ECF0 = 30;
                break;
            case 3:
            case 4:
                D_0028ECF0 = 20;
                break;
            }
        }
        break;
    case 3:
        if (func_0010F998(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C], 0, 99, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 4:
        if (func_0010F670(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028ECF0 = 50;
            } else {
                D_0028ECF0 = 5;
            }
        }
        break;
    case 5:
        printf(D_0028BB20, D_0069F590[0]);
        error = 0;
        if (D_0028ED1C == 0) {
            if (D_0069F590[0] != 2472) {
                error = 1;
            }
        }
        if (((u32)(D_0028ED1C - 1) <= 8) || (D_0028ED1C == 10)) {
            if (D_0069F590[0] != 0x206EC) {
                error = 1;
            }
        }
        if (error != 0) {
            D_0028ECF0 = 35;
        } else {
            D_0028ECF0 = 0;
            D_0028ECFC = 22;
        }
        break;
    case 9:
        if ((D_0028ED20 == 4) && (D_0028ECBC != 0)) {
            D_0028ECF0 = 67;
            break;
        }
        if (D_0028ECBC != 0) {
            D_0028ECF0 = 67;
        } else {
            D_0028ECF0 = 0;
            D_0028ECFC = 25;
        }
        break;
    case 60:
        D_0028EC90 = 0;
        if (func_0010F998(D_0028EC70, D_0028EC74, D_00272010[0], 0, 99, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 10;
        }
        break;
    case 61:
        if (func_0010F670(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC90 += 1;
            }
            D_0028ECF8 = 10;
            D_0028ECF0 += 1;
        }
        break;
    case 62:
        D_0028ECF8 = 180;
        D_0028ECF0 = 0;
        if (D_0028EC90 == 1) {
            D_0028ECF0 = 66;
        } else {
            D_0028ECFC = 23;
        }
        break;
    case 66:
        func_002342F0(11);
        if (D_0028ECBC != 0) {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 += 1;
            }
        } else {
            func_00233EE0();
            if (D_0057CC78[0] & 0x20) {
                D_0028ECF0 = 9;
            }
        }
        break;
    case 67:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 10:
        func_002343C0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 30:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 35:
        if (D_0028ED1C == 0) {
            func_00234250(0, 0);
        } else {
            func_00234250(0, D_0028ED1C);
        }
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 40:
        func_002343E0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    case 50:
        func_002342F0(D_0028ED1C);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 9;
        }
        break;
    }
}
