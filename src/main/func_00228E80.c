#include "common.h"

extern void *memcpy(void *dst, const void *src, u32 n);
extern void func_0018D4B0(void);
extern void func_0018D4C0(void);
extern s8 func_00221120(s32 id);
extern void func_002273E0(void);
extern s16 D_00270810[];
extern u16 D_002712C0[];
extern s8 D_002712D8[];
extern s8 D_00271502[];
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB84;
extern u8 D_0028EC00;
extern s8 D_0028EC01;
extern s8 D_0028EC02;
extern s16 D_0028EC04;
extern s8 D_0028EC10;
extern s8 D_0028EC12;
extern s8 D_0028EC24;
extern s32 D_0057CC20[];
extern s32 D_0057CC50[];
extern s32 D_0057CC60[];
extern s32 D_0057CC70[];
extern s16 D_0068DEDC[];
extern s16 D_0068DEF0[];

void func_00228E80(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 moved;
    s32 count;
    s32 idx;
    s32 pad;
    s8 sel;
    s32 limit;
    s16 *value;
    s32 base;
    s32 total;
    s32 extra;

    last = D_00271502[0] - 1;
    dir = 0;
    confirm = 0;
    func_002273E0();
    moved = func_00221120(0x12);
    if (moved == 0) {
        if (D_0028EB58 == 3 || D_0028EB58 == 9 || D_0028EB58 == 7) {
            pad = D_0057CC50[D_0028EC24];
            if (pad & 0x8000) {
                dir = -1;
                moved = 1;
            } else if (pad & 0x2000) {
                dir = 1;
                moved = dir;
            }
        } else {
            pad = D_0057CC60[D_0028EC24];
            if (pad & 0x8000) {
                dir = -1;
                moved = 1;
            } else if (pad & 0x2000) {
                dir = 1;
                moved = dir;
            }
        }
    }
    if (moved == 0) {
        pad = D_0057CC70[D_0028EC24];
        if (pad & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (pad & 0x20) {
            confirm = 1;
        }
    }
    sel = D_0028EB58;
    D_0028EC02 = sel;
    if (confirm != 0) {
        switch (sel) {
        case 3:
            func_0018D4B0();
            D_0068DEF0[10] += 1;
            D_0068DEF0[10] &= 1;
            break;
        case 10:
            func_0018D4B0();
            memcpy(D_0068DEF0, D_00270810, 0x16);
            break;
        case 11:
            func_0018D4B0();
            D_0028EC01 = 0;
            D_0028EC12 = 2;
            D_0028EC04 = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10 = 0;
            D_0028EC00++;
            break;
        }
    } else if (dir != 0) {
        idx = D_002712D8[sel];
        if (sel == 3 && D_0068DEF0[10] == 0) {
            idx = -1;
        }
        if (!(0 > idx)) {
        value = &D_0068DEF0[idx];
        count = D_002712C0[idx];
        if (sel == 3 || sel == 9 || sel == 7) {
            pad = D_0057CC20[D_0028EC24];
            if (pad == 0 || pad == 0xE) {
                if (!(*value == 0 && dir == -1) && !(*value == count - 1 && dir == 1)) {
                    func_0018D4C0();
                }
            }
        } else {
            func_0018D4C0();
        }
        if (idx == 5) {
            if (D_0068DEF0[5] == 0 && D_0068DEF0[7] == 0) {
                D_0068DEF0[7] = 1;
            }
            if (D_0068DEF0[5] != 0) {
                D_0068DEF0[7] = 0;
                D_0068DEF0[8] = 0;
            }
        }
        if (idx == 3) {
            D_0068DEF0[4] = 8;
        }
        limit = D_0068DEF0[3] + 1;
        if (limit == 7) {
            if (D_0068DEDC[0] == 0) {
                limit = 3;
            }
            if (D_0068DEDC[0] == 1) {
                limit = 2;
            }
            if (D_0068DEDC[0] == 2) {
                limit = 1;
            }
        }
        if (dir == -1) {
            (*value)--;
            if (idx == 3) {
                if (D_0068DEDC[0] == 0 && *value == 1) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 1 && *value == 5) {
                    *value = 3;
                }
                if (D_0068DEDC[0] == 1 && *value == 0) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 2 && *value == 5) {
                    *value = 1;
                }
            }
            if (idx == 4 && *value == 6) {
                *value = limit;
            }
            if (idx == 7 && D_0068DEF0[5] == 1 && *value == 0) {
                *value = 5;
            }
            if (D_0028EB58 == 3 || D_0028EB58 == 9 || D_0028EB58 == 7) {
                if (0 > *value) {
                    *value = 0;
                }
            } else {
                if (0 > *value) {
                    *value = count - 1;
                }
            }
        } else {
            (*value)++;
            if (idx == 3) {
                if (D_0068DEDC[0] == 0 && *value == 7) {
                    *value = 2;
                }
                if (D_0068DEDC[0] == 1 && *value == 4) {
                    *value = 6;
                }
                if (D_0068DEDC[0] == 1 && *value == 7) {
                    *value = 1;
                }
                if (D_0068DEDC[0] == 2 && *value == 2) {
                    *value = 6;
                }
            }
            if (idx == 4 && *value < 7 && limit < *value) {
                *value = 7;
            }
            if (idx == 7 && D_0068DEF0[5] == 1 && *value == 6) {
                *value = 1;
            }
            if (D_0028EB58 == 3 || D_0028EB58 == 9 || D_0028EB58 == 7) {
                if (count <= *value) {
                    *value = count - 1;
                }
            } else {
                if (count <= *value) {
                    *value = 0;
                }
            }
        }
        if (D_0068DEF0[5] == 0) {
            base = D_0068DEF0[8];
            total = 0;
            if (base != 0) {
                total = (s16)base / 100;
            }
            extra = D_0068DEF0[7];
            total += extra;
            if (total > 5) {
                if (idx == 7) {
                    D_0068DEF0[8] = (5 - extra) * 100 + 99;
                } else if (idx == 8) {
                    D_0068DEF0[7] = (500 - (s16)base) / 100;
                }
            }
        }
    }
    }
}
