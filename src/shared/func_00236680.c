#include "common.h"

extern void func_0018D9B0(void);
extern void func_0022C5E0(s32, s32, s32, s32, s32, u16, s32);
extern void func_00233EE0(void);
extern s32 D_00271FA0[];
extern s32 D_00271FA4[];
extern s32 D_00271FA8[];
extern s16 D_0028E2FC;
extern u16 D_0028E300;
extern u8 D_0028ECF0;
extern s32 D_0028ED08;
extern s32 D_0028ED10;
extern s32 D_0028ED18;
extern u32 D_0057CC78[];

void func_00236680(void) {
    s16 pressed;

    switch (D_0028ECF0) {
    case 0:
        pressed = (s16)(s32)D_0028E300 ^ D_0028E2FC;
        pressed &= (s16)D_0028E300;
        if (pressed == 0) {
            D_0028ECF0 = 99;
        } else {
            D_0028ECF0++;
        }
        break;
    case 1:
        if (pressed & 1) {
            func_0018D9B0();
            D_0028ECF0++;
        } else {
            D_0028ECF0 = 3;
        }
        break;
    case 2:
        func_0022C5E0(200, D_00271FA0[0], 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0++;
        }
        break;
    case 3:
        if (pressed & 2) {
            func_0018D9B0();
            D_0028ECF0++;
        } else {
            D_0028ECF0 = 5;
        }
        break;
    case 4:
        func_0022C5E0(200, D_00271FA4[0], 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0++;
        }
        break;
    case 5:
        if (pressed & 8) {
            func_0018D9B0();
            D_0028ECF0++;
        } else {
            D_0028ECF0 = 7;
        }
        break;
    case 6:
        func_0022C5E0(200, D_00271FA8[0], 0, 20, 14, D_0028ED10, 100);
        func_00233EE0();
        if (D_0057CC78[0] & 0x20) {
            D_0028ECF0++;
        }
        break;
    case 7:
        D_0028ECF0 = 99;
        break;
    case 99:
        D_0028ED08 = 1;
        if (D_0028ED10 == 0) {
            D_0028ECF0 = 0;
            D_0028ED18 = 2;
        }
        break;
    }
}
