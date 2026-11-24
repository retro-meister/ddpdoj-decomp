#include "common.h"

s32 printf(const char *format, ...);
void func_0022CF20(void);
void func_0022D240(s32 arg0);
s32 func_00231840(void);
void func_002319B0(void);
void func_00233EE0(void);
void func_00234230(void);
void func_002343C0(void);
void func_00236900(void);
extern char D_0028BBD0[];
extern u8 D_0028ECBC_as_u8;
extern s32 D_0028ECC0;
extern s32 D_0028ECC4;
extern s32 D_0028ECCC;
extern u8 D_0028ECD8;
extern u8 D_0028ECE4;
extern u8 D_0028ECF0;
extern u8 D_0028ECFC;
extern s32 D_0028ED00;
extern s32 D_0028ED08;
extern s32 D_0028ED0C;
extern s32 D_0028ED10;
extern s32 D_0028ED14;
extern s32 D_0028ED18;
extern s32 D_0028ED1C;
extern s32 D_0028ED20;
extern s32 D_0057CC78[];
extern s32 D_006A0E40[];
extern s32 D_006A0E44[];
extern s32 D_006A0E48[];
extern s32 D_006A0E4C[];

void func_00231520(void) {
    s32 slot;

    func_0022CF20();
    switch (D_0028ED14) {
    case 0:
        func_00236900();
        D_0028ECF0 = 0;
        D_0028ECE4 = 2;
        D_0028ED14 += 1;
        break;
    case 1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ED14 += 1;
        }
        break;
    case 2:
        D_0028ED1C = 1;
        func_002319B0();
        break;
    case 3:
        D_0028ED1C = 2;
        func_002319B0();
        break;
    case 4:
        D_0028ED1C = 3;
        func_002319B0();
        break;
    case 5:
        D_0028ED1C = 4;
        func_002319B0();
        break;
    case 6:
        D_0028ED1C = 5;
        func_002319B0();
        break;
    case 7:
        D_0028ED1C = 6;
        func_002319B0();
        break;
    case 8:
        D_0028ED1C = 7;
        func_002319B0();
        break;
    case 9:
        D_0028ED1C = 8;
        func_002319B0();
        break;
    case 10:
        D_0028ED1C = 9;
        func_002319B0();
        break;
    case 11:
        D_0028ED1C = 10;
        func_002319B0();
        break;
    case 12:
        if (D_0028ED20 == 7) {
            D_0028ED14 = 13;
        } else {
            D_0028ED14 = 20;
        }
        break;
    case 13:
        slot = func_00231840();
        if (slot == 0xFF) {
            D_0028ED14 = 20;
            break;
        }
        D_0028ED1C = slot;
        D_0028ED20 = 1;
        D_006A0E40[0] = 0;
        D_006A0E44[0] = 0;
        D_0028ECFC = 20;
        D_006A0E48[0] = 0;
        D_0028ECBC_as_u8 = 1;
        D_0028ED00 = 1;
        D_0028ED0C = 0;
        D_0028ECC4 = 0;
        D_0028ECC0 = 0;
        D_006A0E4C[0] = 0;
        D_0028ECD8 = 0;
        D_0028ECCC = 0;
        D_0028ECF0 = 0;
        printf(D_0028BBD0, slot);
        break;
    case 20:
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
            func_0022D240(2);
            func_00236900();
            D_0028ED14 = 20;
        }
        break;
    }
    if ((D_0028ED14 < 12) && (D_0028ECFC == 27)) {
        func_00234230();
    }
}
