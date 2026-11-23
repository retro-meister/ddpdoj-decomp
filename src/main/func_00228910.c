#include "common.h"

void func_0018D4B0(void);
void func_0018D4C0(void);
s8 func_00221120(s32 arg0);
void func_002273E0(void);
void *memcpy(void *dst, const void *src, u32 n);
extern s8 D_00271501[];
extern s32 D_00270828[];
extern u8 D_0028DCA8[8];
extern s8 D_0028DCB0[8];
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB84;
extern u8 D_0028EC08;
extern s8 D_0028EC09;
extern s8 D_0028EC0A;
extern s16 D_0028EC0C;
extern s8 D_0028EC10;
extern s8 D_0028EC12;
extern s8 D_0028EC24;
extern u32 D_0057CC60[];
extern u32 D_0057CC70[];
extern s16 D_0068DED8[];
extern s16 D_0068DEF6[];
extern s16 D_0068DEF8[];

void func_00228910(void) {
    s32 confirm;
    s32 last;
    s32 dir;
    s32 skip;
    u32 buttons;
    s32 count;
    s32 item;
    s16 *value;

    dir = 0;
    confirm = 0;
    last = D_00271501[0] - 1;
    func_002273E0();
    skip = func_00221120(17);
    if (skip == 0) {
        buttons = D_0057CC60[D_0028EC24];
        if (buttons & 0x8000) {
            dir = -1;
            skip = 1;
        } else if (buttons & 0x2000) {
            dir = 1;
            skip = 1;
        }
    }
    if (skip == 0) {
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC0A = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 6:
            func_0018D4B0();
            memcpy(D_0068DED8, D_00270828, 10);
            break;
        case 7:
            func_0018D4B0();
            D_0028EC09 = 0;
            D_0028EC12 = 1;
            D_0028EC0C = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10 = 0;
            D_0028EC08 += 1;
            break;
        }
    } else if (dir != 0) {
        item = D_0028DCB0[D_0028EB58];
        if (!(0 > item)) {
            value = &D_0068DED8[item];
            count = D_0028DCA8[item];
            func_0018D4C0();
            if (item == 2) {
                D_0068DEF6[0] = 6;
                D_0068DEF8[0] = 8;
            }
            if (dir == -1) {
                (*value)--;
                if (0 > *value) {
                    *value = count - 1;
                }
            } else {
                (*value)++;
                if (count <= *value) {
                    *value = 0;
                }
            }
        }
    }
}
