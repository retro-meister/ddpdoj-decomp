#include "common.h"

void func_0018D4B0(void);
s8 func_00221120(s32 arg0);
void func_00222260(s32 arg0);
void func_002273E0(void);
extern s8 D_002714F7[];
extern s8 D_0028EB04;
extern s8 D_0028EB4C;
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s8 D_0028EBE0;
extern s8 D_0028EBE8;
extern s8 D_0028EC10;
extern s8 D_0028EC12;
extern u8 D_0028EC18;
extern s8 D_0028EC19;
extern s8 D_0028EC1A;
extern s16 D_0028EC1C;
extern s8 D_0028EC24;
extern u32 D_0057CC70[];

void func_002276C0(void) {
    s32 confirm;
    s32 last;
    u32 buttons;

    confirm = 0;
    last = D_002714F7[0] - 1;
    func_002273E0();
    if (func_00221120(7) == 0) {
        buttons = D_0057CC70[D_0028EC24];
        if (buttons & 0x40) {
            D_0028EB58 = last;
            confirm = 1;
        } else if (buttons & 0x20) {
            confirm = 1;
        }
    }
    D_0028EC1A = D_0028EB58;
    if (confirm != 0) {
        func_0018D4B0();
        D_0028EC18 += 1;
        if (last == D_0028EC1A) {
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB84 = 0;
            D_0028EB90 = 0x40;
            D_0028EB4C = 1;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EC19 = 2;
        } else {
            D_0028EC19 = 0;
            D_0028EC1C = 0;
            D_0028EB54 = 0;
            D_0028EB50 = 0;
            switch (D_0028EC1A) {
            case 1:
                D_0028EC12 = 1;
                D_0028EC10 = 0;
                D_0028EB84 = 8;
                break;
            case 2:
                D_0028EBE8 = 0;
                D_0028EB84 = 10;
                break;
            case 3:
                D_0028EBE0 = 0;
                D_0028EB84 = 11;
                break;
            case 4:
                D_0028EBE0 = 0;
                D_0028EB84 = 22;
                break;
            }
        }
    }
}
