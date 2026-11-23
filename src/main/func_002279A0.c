#include "common.h"

void func_0018D490(void);
void func_0018D4B0(void);
s8 func_00221120(s32 arg0);
void func_002272D0(void);
void func_002273E0(void);
s32 printf(const char *format, ...);
extern s16 D_00270822[];
extern s8 D_002714FA[];
extern char D_00289E38[];
extern u8 D_0028E258;
extern u8 D_0028E280;
extern s8 D_0028EB58;
extern s8 D_0028EB84;
extern u8 D_0028EBE8;
extern s8 D_0028EBE9;
extern s8 D_0028EBEA;
extern s16 D_0028EBEC;
extern s8 D_0028EC18;
extern s8 D_0028EC1A;
extern s8 D_0028EC24;
extern u32 D_0057CC70[];
extern s16 D_0068DF02[];

void func_002279A0(void) {
    s32 confirm;
    s32 last;
    u32 buttons;
    s32 selected;

    confirm = 0;
    last = D_002714FA[0] - 1;
    func_002273E0();
    if (func_00221120(10) == 0) {
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EBEA = D_0028EB58;
    if (confirm != 0) {
        selected = D_0028EBEA - 1;
        if (last != D_0028EBEA) {
            if (D_0028E258 < selected) {
                func_0018D490();
                return;
            }
            D_0028E280 = selected;
            printf(D_00289E38, D_0028E280);
            func_0018D4B0();
            D_0028EBE8 += 1;
            D_0068DF02[0] = D_0028EBEA - 1;
            func_002272D0();
        } else {
            func_0018D4B0();
            D_0028EC1A = 2;
            D_0028EBE9 = 0;
            D_0028EB84 = 7;
            D_0028EBEC = 0;
            D_0028EC18 = 0;
            D_0068DF02[0] = D_00270822[0];
        }
    }
}
