#include "common.h"

extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
void func_0022CDB0(s32 arg0);
void func_0022D240(s32 arg0);
void func_00233EE0(void);
void func_00233F50(void);
void func_00234230(void);
void func_002343E0(void);
s32 sceMcSync(s32, s32, s32 *);
s32 sceMcGetDir(s32, s32, char *, s32, s32, void *);
s32 printf(const char *, ...);
extern s32 D_00271D60[];
extern char *D_00271FB0_as_char_p_a[];
extern char *D_00271FB4[];
extern char *D_00271FB8[];
extern char *D_00271FBC[];
extern char *D_00271FC0[];
extern char *D_00271FC4[];
extern char *D_00271FC8[];
extern char *D_00271FCC[];
extern char *D_00271FD0[];
extern char *D_00271FD4[];
extern char *D_00271FD8[];
extern char D_0028BC80[];
extern s32 D_0028DE08;
extern s32 D_0028DE0C;
extern s32 D_0028DE10;
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028EC80;
extern s32 D_0028EC84;
extern s32 D_0028EC88;
extern u8 D_0028EC8C;
extern u8 D_0028EC8D;
extern u8 D_0028EC8E;
extern u8 D_0028EC8F;
extern u16 D_0028EC9C;
extern u16 D_0028ECA0;
extern u16 D_0028ECA4;
extern s32 D_0028ECB4;
extern s32 D_0028ECC8;
extern s32 D_0028ECD0;
extern u8 D_0028ECDC;
extern u8 D_0028ECE0;
extern u8 D_0028ECE4;
extern u8 D_0028ECEC;
extern u8 D_0028ECF0;
extern u8 D_0028ECF4;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0057CC78[];
extern u8 D_0069F580[];

void func_00232DE0(void) {
    s32 result;
    s32 diff;
    s32 step;

    if ((D_0028ECF0 == 3) || (D_0028ECF0 == 4) || (D_0028ECF0 == 30) || (D_0028ECF0 == 31)) {
        func_0022C5E0(120, D_0028DE08, 0, 20, 14, D_0028ED10, 100);
        func_00233F50();
    }
    if ((D_0028ECF0 == 11) || (D_0028ECF0 == 12) || (D_0028ECF0 == 40) || (D_0028ECF0 == 41)) {
        func_0022C5E0(120, D_0028DE0C, 0, 20, 14, D_0028ED10, 100);
        func_0022C5E0(240, D_0028DE10, 0, 20, 14, D_0028ED10, 100);
        func_00233F50();
    }
    switch (D_0028ECF0) {
    case 0:
        D_0028ECE4 = 60;
        D_0028ECF0 += 1;
        D_0028EC80 = 0;
        break;
    case 1:
        func_00234230();
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF0 += 1;
        }
        break;
    case 2:
        func_00234230();
        D_0028EC70 = 0;
        D_0028EC74 = 0;
        D_0028ECF4 = 0;
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 3) || (D_0028ECC8 == 2)) {
                D_0028ECF4 |= 1;
            } else if (D_0028ECC8 == 1) {
                D_0028ECF4 |= 0x10;
            }
            if ((D_0028ECF4 & 0x10) == 0x10) {
                D_0028ECF0 = 20;
            } else if ((D_0028ECF4 & 1) != 1) {
                D_0028ECF0 = 50;
            } else {
                D_0028ECEC = 1;
                D_0028ECE0 = 0;
                D_0028ECA0 = 232;
                D_0028ECA4 = 324;
                D_0028ECF0 += 1;
            }
        }
        break;
    case 3:
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
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            if (D_0028ECD0 != 0) {
                D_0028ECF0 = 30;
            } else {
                D_0028ECF0 = 0;
                if (D_0028ECEC == 0) {
                    D_0028ECF0 = 5;
                }
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 4:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 3;
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
    case 5:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x32:
        func_00234230();
        D_0028EC88 = 0;
        D_0028EC8C = 0;
        D_0028EC8D = 0;
        D_0028EC8E = 0;
        D_0028EC8F = 0;
        D_0028EC80 = 0;
        D_0028EC84 = 0;
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FB0_as_char_p_a[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x33:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC8D = 1;
                D_0028EC88 += D_00271D60[0];
            } else {
                D_0028EC80 = 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x34:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FB4[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x35:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x36:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FB8[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x37:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x38:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FBC[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x39:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x3A:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FC0[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x3B:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x3C:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FC4[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x3D:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x3E:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FC8[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x3F:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x40:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FCC[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x41:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x42:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FD0[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x43:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x44:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FD4[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x45:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            D_0028ECF0 += 1;
        }
        break;
    case 0x46:
        func_00234230();
        sceMcGetDir(D_0028EC70, D_0028EC74, D_00271FD8[0], 0, 99, D_0069F580);
        D_0028ECF0 += 1;
        break;
    case 0x47:
        func_00234230();
        if (sceMcSync(1, 0, &result) != 0) {
            if (result <= 0) {
                D_0028EC84 += 1;
            }
            printf(D_0028BC80, D_0028ECB4, D_0028EC88, D_0028EC84);
            if ((D_0028EC88 != 0) && (D_0028ECB4 < D_0028EC88)) {
                D_0028ECF4 = 0;
                D_0028ECF0 = 0x50;
            } else {
                D_0028ECF4 |= 4;
                D_0028ECF0 = 0x50;
            }
        }
        break;
    case 0x50:
        D_0028EC70 = 0;
        D_0028EC74 = 0;
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if ((D_0028ECC8 == 2) || (D_0028ECC8 == 3) || (D_0028ECC8 == 4) || (D_0028ECC8 == 1)) {
                D_0028ECF0 = 0;
            } else {
                D_0028ECF0 = 10;
            }
        }
        break;
    case 10:
        if (D_0028ECF4 & 0xC) {
            D_0028ECF0 = 20;
            break;
        }
        D_0028ECE0 = 0;
        D_0028ECF0 += 1;
        D_0028ECEC = 1;
        D_0028ECA0 = 256;
        D_0028ECA4 = 324;
        break;
    case 11:
        if (D_0028ECE0 == 71) {
            D_0028ECE0 = 0;
        } else if (D_0028ECE0 > 60) {
            D_0028EC70 = 0;
            D_0028EC74 = 0;
            func_0022CDB0(1);
            if (D_0028ECD0 == 0) {
                if (D_0028ECC8 == 4) {
                    D_0028ECF0 = 0;
                    break;
                }
                D_0028ECE0 = 71;
            }
        } else {
            D_0028ECE0 += 1;
        }
        if (D_0057CC78[0] & 0x20) {
            func_0022D240(2);
            if (D_0028ECD0 != 0) {
                D_0028ECF0 = 40;
            } else {
                D_0028ECF0 = 0;
                if (D_0028ECEC == 0) {
                    D_0028ECF0 = 21;
                }
            }
        } else {
            if ((D_0028ECEC == 1) && (D_0057CC78[0] & 0x8000)) {
                func_0022D240(1);
                D_0028ECEC = 0;
                D_0028EC9C = 234;
                D_0028ECDC = 0;
            }
            if ((D_0028ECEC == 0) && (D_0057CC78[0] & 0x2000)) {
                func_0022D240(1);
                D_0028ECDC = 0;
                D_0028ECEC = 1;
                D_0028EC9C = 324;
            }
        }
        break;
    case 12:
        if (D_0028EC9C == D_0028ECA4) {
            D_0028ECF0 = 11;
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
    case 20:
        D_0028ECF0 = 21;
        break;
    case 21:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ED18 = 2;
            D_0028ECF0 = 0;
            if (D_0028EC80 != 0) {
                D_0028ECF4 |= 4;
            }
        }
        break;
    case 30:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 == 4) {
                D_0028ECF0 = 0;
                break;
            }
            D_0028ECE0 = 0;
            D_0028ECF0 = 0;
            if (D_0028ECEC == 0) {
                D_0028ECF0 = 5;
            }
        }
        break;
    case 40:
        func_0022CDB0(1);
        if (D_0028ECD0 == 0) {
            if (D_0028ECC8 == 4) {
                D_0028ECF0 = 0;
                break;
            }
            D_0028ECE0 = 0;
            D_0028ECF0 = 0;
            if (D_0028ECEC == 0) {
                D_0028ECF0 = 21;
            }
        }
        break;
    case 100:
        func_002343E0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 21;
        }
        break;
    }
}
