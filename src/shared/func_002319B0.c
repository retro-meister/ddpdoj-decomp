#include "common.h"

s32 func_0010EFF0();
s32 func_0010F150();
s32 func_0010F370();
s32 func_0010F670();
s32 func_0010F998();
s32 func_00117750();
s32 func_0022CDB0();
s32 printf();
extern u8 D_00271FE0[];
extern u8 D_00272010[];
extern u8 D_0028B3F0[];
extern u8 D_0028B410[];
extern u8 D_0028B430[];
extern u8 D_0028B450[];
extern u8 D_0028B470[];
extern u8 D_0028B490[];
extern u8 D_0028B4B0[];
extern u8 D_0028B4D0[];
extern u8 D_0028B4F0[];
extern u8 D_0028B510[];
extern u8 D_0028BB20[];
extern u8 D_0028BB98[];
extern u8 D_0028BBB0[];
extern u8 D_0028BC30[];
extern u8 D_0028BC50[];
extern u8 D_0028BC70[];
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
extern u8 D_006A0E50[];
typedef struct {
    u8 pad0[0x10];
    s16 state;
    u8 pad12[0x34];
    u16 id;
    u8 pad48[0x3B8];
} Slot;
extern Slot D_006A0E40[];
void func_002319B0(void) {
    s32 sp5C;
    s32 ok;
    s32 i;
    s32 off;
    u8 *entry;

    switch (D_0028ECF0) {
    case 0:
        D_0028ECE4 = 0xA;
        D_0028ECF0 += 1;
        break;
    case 1:
        func_0022CDB0(0);
        if (D_0028ECD0 == 0) {
            switch (D_0028ECC8) {
            case 3:
            case 4:
                D_0028ECF0 = 0x1E;
                break;
            default:
                D_0028ECF8 = 0xA;
                D_0028ECF0 += 1;
                break;
            }
        } else {
            break;
        }
        break;
    case 2:
        if (func_0010F998(D_0028EC70, D_0028EC74, *(u32 *)(D_00271FE0 + (D_0028ED1C * 4)), 0, 5, D_0069F580) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x14;
            break;
        }
        break;
    case 3:
        if (func_0010F670(1, 0, &sp5C) != 0) {
            ok = 1;
            if (sp5C <= 0) {
                D_0028ECF0 = 0x14;
                break;
            }
            i = 0;
            off = 0;
            do {
                if (D_0028ED1C == 1) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B3F0) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 2) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B410) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 3) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B430) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 4) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B450) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 5) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B470) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 6) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B490) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 7) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B4B0) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 8) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B4D0) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 9) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B4F0) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                if (D_0028ED1C == 0xA) {
                    entry = (u8 *)(D_0069F580 + off);
                    if ((func_00117750(entry + 0x20, D_0028B510) == 0) && ((*(s32 *)((u8 *)(entry) + (0x10))) == 0x206EC)) {
                        ok = 0;
                    }
                }
                i += 1;
                off += 0x40;
            } while (i < 5);
            if (ok != 0) {
                D_0028ECF0 = 0x25;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 0xA;
            break;
        }
        break;
    case 4:
        if (func_0010EFF0(D_0028EC70, D_0028EC74, *(u32 *)(D_00272010 + (D_0028ED1C * 4)), 3) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x14;
            break;
        }
        break;
    case 5:
        if (func_0010F670(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x14;
                break;
            }
            printf(D_0028BB20, D_0069F590[0]);
            D_0028ECF8 = 0xA;
            D_0028ECA8 = sp5C;
            D_0028ECF0 += 1;
            break;
        }
        break;
    case 6:
        if (func_0010F370(D_0028ECA8, D_006A0E50 + ((D_0028ED1C - 1) << 0xA), 0x400) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x1E;
            break;
        }
        break;
    case 7:
        if (func_0010F670(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x1E;
                break;
            }
            D_0028ECF0 += 1;
            D_0028ECF8 = 0xA;
            break;
        }
        break;
    case 8:
        if (func_0010F150(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x1E;
            break;
        }
        break;
    case 9:
        if (func_0010F670(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x1E;
                break;
            }
            D_0028ECF8 = 0xA;
            D_0028ECF0 += 1;
            break;
        }
        break;
    case 10:
        off = D_0028ED1C - 1;
        ok = D_0028ED1C;
        D_006A0E40[off].state = 1;
        if (D_006A0E40[off].id == MAIN_OR_DEATH_LABEL(0xCB, 0x6E)) {
            printf(D_0028BC30, ok);
        } else {
            D_006A0E40[off].state = 3;
            printf(D_0028BC50, ok, D_006A0E40[off].id, MAIN_OR_DEATH_LABEL(0xCB, 0x6E));
        }
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
        D_0028ED14 = 0x1E;
        break;
    case 35:
        if (func_0010F150(D_0028ECA8) == 0) {
            D_0028ECF0 += 1;
            break;
        }
        D_0028ECF8 -= 1;
        if (D_0028ECF8 == 0) {
            D_0028ECF0 = 0x1E;
            break;
        }
        break;
    case 36:
        if (func_0010F670(1, 0, &sp5C) != 0) {
            if (sp5C < 0) {
                D_0028ECF0 = 0x1E;
                break;
            }
            printf(D_0028BC70, D_0028ED1C);
            *(s16 *)(D_006A0E50 + ((D_0028ED1C - 1) << 0xA)) = 2;
            D_0028ECF0 = 0;
            D_0028ED14 += 1;
            break;
        }
        break;
    case 37:
        printf(D_0028BC70, D_0028ED1C);
        *(s16 *)(D_006A0E50 + ((D_0028ED1C - 1) << 0xA)) = 2;
        D_0028ECF0 = 0;
        D_0028ED14 += 1;
        break;
    }
}
