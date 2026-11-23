#include "common.h"

void func_0018D4B0(void);
void func_0018D4C0(void);
s8 func_00221120(s32 arg0);
void func_002273E0(void);
void *memcpy(void *dst, const void *src, u32 n);
extern s8 D_00271503[];
extern s32 D_00270838[];
extern u16 D_00271458[];
extern s8 D_00271468[];
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB84;
extern u8 D_0028EBF8;
extern s8 D_0028EBF9;
extern s8 D_0028EBFA;
extern s16 D_0028EBFC;
extern s8 D_0028EC10;
extern s8 D_0028EC12;
extern s8 D_0028EC24;
extern u32 D_0057CC60[];
extern u32 D_0057CC70[];
extern s16 D_0068DEC8[];

void func_00229E20(void) {
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
    last = D_00271503[0] - 1;
    func_002273E0();
    skip = func_00221120(19);
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
    D_0028EBFA = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 7:
            func_0018D4B0();
            memcpy(D_0068DEC8, D_00270838, 12);
            break;
        case 8:
            func_0018D4B0();
            D_0028EBF9 = 0;
            D_0028EC12 = 3;
            D_0028EBFC = 0;
            D_0028EB84 = 8;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC10 = 0;
            D_0028EBF8 += 1;
            break;
        }
    } else if (dir != 0) {
        item = D_00271468[D_0028EB58];
        if (!(0 > item)) {
            value = &D_0068DEC8[item];
            count = D_00271458[item];
            func_0018D4C0();
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
