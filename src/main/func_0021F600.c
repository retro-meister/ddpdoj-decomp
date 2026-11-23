#include "common.h"

s32 func_0018CBB0();
s32 func_0018D4B0();
s32 func_0018D4D0();
s32 func_00217A40();
s32 func_00222260();
extern s8 D_0028EAA8;
extern s8 D_0028EAE8;
extern s8 D_0028EB04;
extern s8 D_0028EB0C;
extern s8 D_0028EB30;
extern s8 D_0028EB4C;
extern s8 D_0028EB54;
extern s8 D_0028EB60;
extern s8 D_0028EB7C;
extern s8 D_0028EB84;
extern s32 D_0028EB90;
extern s8 D_0028EBC0;
extern s32 D_0057CC78[];
void func_0021F600(void) {
    s32 selected;
    s32 choice;
    u32 buttons;

    buttons = D_0057CC78[0];
    choice = D_0028EAE8;
    selected = 0;
    if ((buttons & 0x8000) && D_0028EB0C == 0) {
        D_0028EBC0 = 0;
        D_0028EB0C = 1;
        func_0018D4D0();
    } else if ((buttons & 0x2000) && D_0028EB0C == 1) {
        D_0028EBC0 = 0;
        D_0028EB0C = 0;
        func_0018D4D0();
    } else if (buttons & 0x20) {
        selected = 1;
        if (D_0028EB0C == 0) {
            choice = 3;
        }
    }
    if (selected != 0) {
        switch (choice) {
        case 1:
        case 2:
            D_0028EAA8 = choice;
            func_00217A40();
            func_0018D4B0();
            D_0028EB60 += 1;
            break;
        case 3:
            func_0018CBB0();
            func_00222260(0);
            D_0028EB7C = 3;
            D_0028EB4C = 1;
            D_0028EB90 = 0x40;
            D_0028EB04 = 1;
            D_0028EB54 = 2;
            D_0028EB30 = 2;
            D_0028EB84 = 0;
            D_0028EB60 += 1;
            func_0018D4B0();
            break;
        }
    }
}
