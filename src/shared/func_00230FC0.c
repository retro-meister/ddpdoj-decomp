#include "common.h"

s32 sceMcOpen(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 sceMcClose(s32 arg0);
s32 sceMcRead(s32 arg0, void *arg1, s32 arg2);
s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
s32 sceMcGetDir(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5);
s32 func_0022CAB0(void);
void func_0022CDB0(s32 arg0);
s32 printf(const char *format, ...);
extern s32 D_00272010[];
extern char D_0028BB20[];
extern char D_0028BB70[];
extern char D_0028BB80[];
extern char D_0028BB98[];
extern char D_0028BBB0[];
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECA8;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;
extern u8 D_0028ECE4;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern s32 D_0028ED14;
extern s32 D_0028ED1C;
extern u8 D_0069F580[];
extern s32 D_0069F590[];
extern s32 D_006A0E40[];
extern u8 D_006C4EF0[];

void func_00230FC0(void) {
    s32 result;
    s32 error;
    s32 status;

    switch (D_0028ECF0) {
    case 0:
        D_006A0E40[D_0028ED1C] = 0;
        D_0028ECE4 = 10;
        D_0028ECF0 += 1;
        break;
    case 1:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                D_0028ECF0 = 30;
                break;
            default:
                D_0028ECF8 = 10;
                D_0028ECF0 += 1;
                break;
            }
        }
        break;
    case 2:
        if (sceMcGetDir(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C], 0, 99, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 20;
        }
        break;
    case 3:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028ECF0 = 20;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 4:
        if (sceMcOpen(D_0028EC70, D_0028EC74, D_00272010[D_0028ED1C], 3) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 20;
        }
        break;
    case 5:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 20;
                break;
            }
            printf(D_0028BB20, D_0069F590[0]);
            D_0028ECF8 = 10;
            error = 0;
            if (D_0028ED1C == 0) {
                if (D_0069F590[0] != 2472) {
                    error = 1;
                }
            }
            if (error != 0) {
                D_0028ECF0 = 35;
                break;
            }
            D_0028ECF8 = 10;
            D_0028ECA8 = result;
            D_0028ECF0 += 1;
        }
        break;
    case 6:
        switch (D_0028ED1C) {
        case 0:
            status = sceMcRead(D_0028ECA8, D_006C4EF0, 2472);
            break;
        }
        if (status == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 30;
        }
        break;
    case 7:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 8:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 30;
        }
        break;
    case 9:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
                break;
            }
            D_0028ECF8 = 10;
            if (func_0022CAB0() == 0) {
                D_0028ECF0 += 1;
                break;
            }
            printf(D_0028BB70);
            D_0028ECF0 = 40;
        }
        break;
    case 10:
        D_0028ECF0 += 1;
        break;
    case 11:
        printf(D_0028BB80, D_0028ED1C);
        D_006A0E40[D_0028ED1C] = 1;
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    case 20:
        printf(D_0028BB98, D_0028ED1C);
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    case 30:
        printf(D_0028BBB0, D_0028ED1C);
        D_0028ECF0 = 0;
        D_0028ED14 = 30;
        break;
    case 35:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 30;
        }
        break;
    case 36:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 30;
                break;
            }
            D_0028ECF0 = 0;
            D_0028ED14 = 35;
        }
        break;
    case 40:
        D_0028ECF0 = 0;
        D_0028ED14 = 35;
        break;
    }
}
