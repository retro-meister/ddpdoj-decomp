#include "common.h"

typedef struct {
    char *name[3];
} NameSet;

s32 sceMcOpen(s32 arg0, s32 arg1, void *arg2, s32 arg3);
s32 sceMcClose(s32 arg0);
s32 sceMcWrite(s32 arg0, void *arg1, s32 arg2);
s32 sceMcSync(s32 arg0, s32 arg1, s32 *arg2);
void *memcpy(void *dst, const void *src, u32 n);
void *memset(void *dst, s32 c, u32 n);
char *strcpy(u8 *dst, const char *src);
extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
void func_0022CF20(void);
void func_0022D240(s32 arg0);
void func_00233EE0(void);
void func_00234150(s32 arg0);
void func_002342D0(void);
void func_00234460(s32 arg0);
s32 printf(const char *format, ...);

extern char *D_00272010_as_char_p_a[];
extern u8 D_00272040[];
extern u8 D_00272080[];
extern u8 D_002720B0[];
extern u8 D_002720E0[];
extern NameSet D_00272100;
extern char D_0028B6E8[];
extern char D_0028B710[];
extern char D_0028B750[];
extern char D_0028B770[];
extern char D_0028B790[];
extern char D_0028B7B0[];
extern char D_0028B7D0[];
extern char D_0028B7F0[];
extern char D_0028B810[];
extern char D_0028B830[];
extern char D_0028B850[];
extern char D_0028B870[];
extern char D_0028B890[];
extern char D_0028B8B0[];
extern char D_0028B8D0[];
extern char D_0028B8F0[];
extern char D_0028B910[];
extern char D_0028B930[];
extern char D_0028B950[];
extern char D_0028B970[];
extern char D_0028B990[];
extern char D_0028B9B0[];
extern char D_0028B9E0[];
extern char D_0028BA00[];
extern char D_0028BA20[];
extern char D_0028BA40[];
extern char D_0028BA60[];
extern char D_0028BA80[];
extern char D_0028BAA0[];
extern char D_0028BAC0[];
extern char D_0028BAE0[];
extern char D_0028BB00[];
extern s32 D_0028DE1C;
extern s32 D_0028EC70;
extern s32 D_0028EC74;
extern s32 D_0028ECA8;
extern s32 D_0028ECC0;
extern u8 D_0028ECD8;
extern u8 D_0028ECE4;
extern u8 D_0028ECF0;
extern u8 D_0028ECF8;
extern u8 D_0028ECFC;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern s32 D_0028ED1C;
extern s32 D_0028ED24;
extern s32 D_0057CC78[];
extern u8 D_0068E1B0[];
extern s16 D_0068E1B6[];
extern s32 D_0068E1BC[];
extern u8 D_0068E1C0[];
extern u8 D_0068E200[];
extern u8 D_0068E230[];
extern u8 D_0068E260[];
extern u8 D_0068E270[];
extern u8 D_0068E2B4[];
extern u8 D_0068E2F4[];
extern u8 D_0068E334[];
extern u8 D_0068E580[];
extern u8 D_006A4800[];
void func_0022F070(void) {
    s32 ret;
    s32 result;
    NameSet names = D_00272100;

    func_0022CF20();
    switch (D_0028ECF0) {   
    case 0x0:
        D_0028ECC0 = 0;
        D_0028ECF0 += 1;
        D_0028ECE4 = 0x3C;
        break;
    case 0x1:
        D_0028ECE4 -= 1;
        if (D_0028ECE4 == 0) {
            D_0028ECF8 = 0xA;
            if (D_0028ECD8 == 0) {
                D_0028ECF0 += 1;
            } else {
                D_0028ECF0 = 0x24;
            }
        }
        break;
    case 0x2:
        if (D_0028ED1C == 1) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B750, 0x203);
        }
        if (D_0028ED1C == 2) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B770, 0x203);
        }
        if (D_0028ED1C == 3) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B790, 0x203);
        }
        if (D_0028ED1C == 4) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B7B0, 0x203);
        }
        if (D_0028ED1C == 5) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B7D0, 0x203);
        }
        if (D_0028ED1C == 6) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B7F0, 0x203);
        }
        if (D_0028ED1C == 7) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B810, 0x203);
        }
        if (D_0028ED1C == 8) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B830, 0x203);
        }
        if (D_0028ED1C == 9) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B850, 0x203);
        }
        if (D_0028ED1C == 10) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B870, 0x203);
        }
        if (ret == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x3:
        ret = sceMcSync(1, 0, &result);
        if (ret != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
            }
        }
        break;
    case 0x4:
        memset(D_0068E1B0, 0, 0x3C4);
        strcpy(D_0068E1B0, D_0028B6E8);
        if (D_0028ED1C == 1) {
            strcpy(D_0068E270, D_0028B890);
        }
        if (D_0028ED1C == 2) {
            strcpy(D_0068E270, D_0028B8B0);
        }
        if (D_0028ED1C == 3) {
            strcpy(D_0068E270, D_0028B8D0);
        }
        if (D_0028ED1C == 4) {
            strcpy(D_0068E270, D_0028B8F0);
        }
        if (D_0028ED1C == 5) {
            strcpy(D_0068E270, D_0028B910);
        }
        if (D_0028ED1C == 6) {
            strcpy(D_0068E270, D_0028B930);
        }
        if (D_0028ED1C == 7) {
            strcpy(D_0068E270, D_0028B950);
        }
        if (D_0028ED1C == 8) {
            strcpy(D_0068E270, D_0028B970);
        }
        if (D_0028ED1C == 9) {
            strcpy(D_0068E270, D_0028B990);
        }
        if (D_0028ED1C == 10) {
            strcpy(D_0068E270, D_0028B9B0);
        }
        D_0068E1B6[0] = 0xE;
        D_0068E1BC[0] = 0x60;
        memcpy(D_0068E1C0, D_00272040, 0x40);
        memcpy(D_0068E200, D_00272080, 0x30);
        memcpy(D_0068E230, D_002720B0, 0x30);
        memcpy(D_0068E260, D_002720E0, 0x10);
        strcpy(D_0068E2B4, names.name[0]);
        strcpy(D_0068E2F4, names.name[1]);
        strcpy(D_0068E334, names.name[2]);
        D_0028ECF0 += 1;
        D_0028ECF8 = 0xA;
        break;
    case 0x5:
        if (sceMcWrite(D_0028ECA8, D_0068E1B0, 0x3C4) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x6:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x7:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x8:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 += 1;
            }
        }
        break;
    case 0x9:
        printf(D_0028B710, D_0028ED24);
        D_0028ECF0 += 1;
        D_0028ECF8 = 0xA;
        break;
    case 0xA:
        if (D_0028ED1C == 1) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028B9E0, 0x203);
        }
        if (D_0028ED1C == 2) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BA00, 0x203);
        }
        if (D_0028ED1C == 3) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BA20, 0x203);
        }
        if (D_0028ED1C == 4) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BA40, 0x203);
        }
        if (D_0028ED1C == 5) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BA60, 0x203);
        }
        if (D_0028ED1C == 6) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BA80, 0x203);
        }
        if (D_0028ED1C == 7) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BAA0, 0x203);
        }
        if (D_0028ED1C == 8) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BAC0, 0x203);
        }
        if (D_0028ED1C == 9) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BAE0, 0x203);
        }
        if (D_0028ED1C == 10) {
            ret = sceMcOpen(D_0028EC70, D_0028EC74, D_0028BB00, 0x203);
        }
        if (ret == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xB:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0xC:
        if (sceMcWrite(D_0028ECA8, D_0068E580, D_0028ED24) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xD:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0xE:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0xF:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 = 0x24;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x24:
        if (sceMcOpen(D_0028EC70, D_0028EC74, D_00272010_as_char_p_a[D_0028ED1C], 0x203) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x25:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECA8 = result;
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x26:
        if (sceMcWrite(D_0028ECA8, D_006A4800, 0x206EC) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x27:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                if (result == -3) {
                    D_0028ECF0 = 0x30;
                } else {
                    D_0028ECF0 = 0x2D;
                }
            } else {
                D_0028ECF0 += 1;
                D_0028ECF8 = 0xA;
            }
        }
        break;
    case 0x28:
        if (sceMcClose(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
        } else {
            D_0028ECF8 -= 1;
            if (D_0028ECF8 == 0) {
                D_0028ECF0 = 0x2D;
            }
        }
        break;
    case 0x29:
        if (sceMcSync(1, 0, &result) != 0) {
            if (result < 0) {
                D_0028ECF0 = 0x2D;
            } else {
                D_0028ECF0 = 0x32;
                func_0022D240(0xA);
                D_0028ECF8 = 0x3C;
            }
        }
        break;
    case 0x32:
        func_0022C5E0(0xC8, D_0028DE1C, 0, 0x14, 0xE, D_0028ED10, 0x64);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 += 1;
        }
        break;
    case 0x33:
        D_0028ECC0 = 1;
        D_0028ECF0 += 1;
        break;
    case 0x34:
        D_0028ED08 = 1;
        if ((s32) D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    case 0x2D:
        func_0022D240(0xB);
        D_0028ECF0 += 1;
    case 0x2E:
        func_002342D0();
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 0x11;
        }
        break;
    case 0x30:
        func_0022D240(0xB);
        D_0028ECF0 += 1;
    case 0x31:
        func_00234460(D_0028ED1C);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0 = 0;
            D_0028ECFC = 0x11;
        }
        break;
    }
    if ((D_0028ECFC == 0x10) && ((s32) D_0028ECF0 < 0x2A)) {
        func_00234150(0);
    }
}
