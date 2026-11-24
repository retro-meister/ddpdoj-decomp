#include "common.h"

void func_0022CF20(void);
void func_0022D240(s32 arg0);
void func_00230FC0(void);
void func_00233EE0(void);
void func_00234150(s32 arg0);
void func_00234250(s32 arg0, s32 arg1);
void func_002343A0(void);
void func_002343C0(void);
extern s8 D_0028ECBC;
extern u8 D_0028ECE4;
extern u8 D_0028ECF0;
extern u8 D_0028ECFC;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED14;
extern s32 D_0028ED18;
extern s32 D_0028ED1C;
extern s32 D_0057CC78[];
extern s32 D_006A0E40[];
extern s32 D_006A0E44[];
extern s32 D_006A0E48[];
extern s32 D_006A0E4C[];

void func_00230CD0(void) {
    s32 i;
    s32 count;

    func_0022CF20();
    switch (D_0028ED14) {
    case 0:
        D_006A0E40[0] = 0;
        D_0028ED14 += 1;
        D_006A0E44[0] = 0;
        D_0028ECE4 = 60;
        D_006A0E48[0] = 0;
        D_0028ECF0 = 0;
        D_006A0E4C[0] = 0;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ED14 += 1;
        }
        break;
    case 2:
        D_0028ED1C = 0;
        func_00230FC0();
        break;
    case 3:
        D_0028ED14 += 1;
        break;
    case 4:
        D_0028ED14 += 1;
        break;
    case 5:
        D_0028ED14 += 1;
        break;
    case 6:
        count = 0;
        for (i = 0; i < 4; i++) {
            if (D_006A0E40[i] != 0) {
                count++;
            }
        }
        if (count != 0) {
            func_0022D240(10);
            D_0028ED14 += 1;
            D_0028ECE4 = 60;
        } else {
            D_0028ED14 = 30;
        }
        break;
    case 7:
        func_002343A0();
        if (D_0028ECBC != 0) {
            D_0028ECE4 -= 1;
            if (D_0028ECE4 == 0) {
                D_0028ED14 = 10;
            }
        } else {
            func_00233EE0();
            if (D_0057CC78[0] & 0x20) {
                D_0028ED14 = 10;
            }
        }
        break;
    case 10:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 30:
        func_0022D240(11);
        D_0028ED14 += 1;
    case 31:
        func_002343C0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_006A0E40[0] = 0;
            D_006A0E44[0] = 0;
            D_006A0E48[0] = 0;
            D_006A0E4C[0] = 0;
            if (D_0028ECBC != 0) {
                D_0028ED14 = 10;
            } else {
                D_0028ED14 = 0;
                D_0028ECFC = 25;
                D_0028ECF0 = 0;
            }
        }
        break;
    case 35:
        func_0022D240(11);
        D_0028ED14 += 1;
    case 36:
        func_00234250(0, 0);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ED14 = 30;
        }
        break;
    }
    if ((D_0028ED14 < 6) && (D_0028ECFC == 23)) {
        func_00234150(2);
    }
}
