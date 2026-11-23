#include "common.h"

s32 func_0010F670(s32 arg0, s32 arg1, s32 *arg2);
s32 func_0010F998(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5);
s32 func_00117750(const char *a, const char *b);
void func_0022CDB0(s32 arg0);
void func_0022CF20(void);
void func_00233EE0(void);
void func_00234200(void);
void func_00234230(void);
void func_00234250(s32 arg0, s32 arg1);
void func_002342D0(void);
void func_00234460(s32 arg0);
s32 printf(const char *format, ...);
extern s32 D_00271D60[];
extern s32 D_00271FE0[];
extern char D_0028B3E0[];
extern char D_0028B3F0[];
extern char D_0028B410[];
extern char D_0028B430[];
extern char D_0028B450[];
extern char D_0028B470[];
extern char D_0028B490[];
extern char D_0028B4B0[];
extern char D_0028B4D0[];
extern char D_0028B4F0[];
extern char D_0028B510[];
extern char D_0028B530[];
extern char D_0028B550[];
extern char D_0028B570[];
extern char D_0028B590[];
extern char D_0028B5B0[];
extern char D_0028B5D0[];
extern char D_0028B5F0[];
extern char D_0028B610[];
extern char D_0028B630[];
extern char D_0028B650[];
extern char D_0028B670[];
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECB4;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern u8 D_0028ECFC;
extern s32 D_0028ED1C;
extern s32 D_0057CC78[];
extern u8 D_0069F580[];

void func_0022D550(void) {
    s32 result;
    s32 missing;
    s32 i;
    s32 offset;
    s32 offset2;
    s32 j;
    u8 *entry;

    func_0022CF20();
    if ((D_0028ECF0 != 0) && ((D_0028ECF0 < 10) || (D_0028ECF0 > 60))) {
        func_00234230();
    }
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
                D_0028ECF0 += 1;
                D_0028ECF8 = 60;
                break;
            }
        }
        break;
    case 1:
        if (D_0028ECF8 != 0) {
            D_0028ECF8 -= 1;
        } else {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 0:
                D_0028ECF0 += 1;
                D_0028ECF8 = 10;
                break;
            case 1:
                D_0028ECF0 = 0;
                D_0028ECFC = 30;
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
        if (func_0010F998(D_0028EC70, D_0028EC74, D_00271FE0[D_0028ED1C], 0, 5, D_0069F580) == 0) {
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
                if (D_0028ECB4 < D_00271D60[D_0028ED1C * 2]) {
                    D_0028ECF0 = 50;
                } else {
                    D_0028ECF0 = 0;
                    D_0028ECFC = 18;
                }
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 10;
        }
        break;
    case 5:
        missing = 1;
        for (i = 0, offset = 0; i < 5; i++, offset += 0x40) {
            if (D_0028ED1C == 0) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B3E0) == 0) && (*(s32 *)(entry + 0x10) == 0x9A8)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 1) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B3F0) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 2) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B410) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 3) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B430) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 4) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B450) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 5) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B470) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 6) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B490) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 7) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B4B0) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 8) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B4D0) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 9) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B4F0) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
            if (D_0028ED1C == 10) {
                entry = D_0069F580 + offset;
                if ((func_00117750((char *)entry + 0x20, D_0028B510) == 0) && (*(s32 *)(entry + 0x10) == 0x206EC)) {
                    missing = 0;
                }
            }
        }
        for (j = 0, offset2 = 0; j < 5; j++, offset2 += 0x40) {
            if (D_0028ED1C == 0) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B3E0) == 0) {
                    printf(D_0028B530, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 1) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B3F0) == 0) {
                    printf(D_0028B550, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 2) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B410) == 0) {
                    printf(D_0028B570, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 3) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B430) == 0) {
                    printf(D_0028B590, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 4) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B450) == 0) {
                    printf(D_0028B5B0, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 5) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B470) == 0) {
                    printf(D_0028B5D0, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 6) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B490) == 0) {
                    printf(D_0028B5F0, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 7) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B4B0) == 0) {
                    printf(D_0028B610, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 8) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B4D0) == 0) {
                    printf(D_0028B630, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 9) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B4F0) == 0) {
                    printf(D_0028B650, *(s32 *)(entry + 0x10));
                }
            }
            if (D_0028ED1C == 10) {
                entry = D_0069F580 + offset2;
                if (func_00117750((char *)entry + 0x20, D_0028B510) == 0) {
                    printf(D_0028B670, *(s32 *)(entry + 0x10));
                }
            }
        }
        if (missing != 0) {
            D_0028ECF0 = 35;
        } else {
            D_0028ECF0 = 0;
            D_0028ECFC = 13;
        }
        break;
    case 40:
        D_0028ECF0 = 0;
        D_0028ECFC = 17;
        break;
    case 10:
        func_002342D0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 20:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 30:
        func_00234200();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 35:
        if (D_0028ED1C == 0) {
            func_00234250(1, 0);
        } else {
            func_00234250(1, D_0028ED1C);
        }
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    case 50:
        func_00234460(D_0028ED1C);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 40;
        }
        break;
    }
}
