#include "common.h"

void func_0018D4B0(void);
s8 func_00221120(s32 arg0);
void func_002273E0(void);
extern s8 D_002714F8[];
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB84;
extern s8 D_0028EBE0;
extern s8 D_0028EBF8;
extern s8 D_0028EC00;
extern s8 D_0028EC08;
extern u8 D_0028EC10;
extern s8 D_0028EC11;
extern s8 D_0028EC12;
extern s16 D_0028EC14;
extern s8 D_0028EC18;
extern s8 D_0028EC1A;
extern s8 D_0028EC24;
extern u32 D_0057CC70[];

void func_00228580(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F8[0] - 1;
    func_002273E0();
    if (func_00221120(8) == 0) {
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC12 = D_0028EB58;
    if (confirm != 0) {
        switch (D_0028EB58) {
        case 1:
            func_0018D4B0();
            D_0028EC11 = 0;
            D_0028EB84 = 0x11;
            D_0028EC14 = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC08 = 0;
            D_0028EC10 += 1;
            break;
        case 2:
            func_0018D4B0();
            D_0028EC11 = 0;
            D_0028EB84 = 0x12;
            D_0028EC14 = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC00 = 0;
            D_0028EC10 += 1;
            break;
        case 3:
            func_0018D4B0();
            D_0028EC11 = 0;
            D_0028EB84 = 0x13;
            D_0028EC14 = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EBF8 = 0;
            D_0028EC10 += 1;
            break;
        case 4:
            func_0018D4B0();
            D_0028EC11 = 0;
            D_0028EB84 = 0x14;
            D_0028EC14 = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EBE0 = 0;
            D_0028EC10 += 1;
            break;
        case 5:
            func_0018D4B0();
            D_0028EC11 = 0;
            D_0028EC1A = 1;
            D_0028EC14 = 0;
            D_0028EB84 = 7;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            D_0028EC18 = 0;
            D_0028EC10 += 1;
            break;
        }
    }
}
