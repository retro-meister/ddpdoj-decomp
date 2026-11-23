#include "common.h"

extern s32 D_0028DF20;
extern s32 D_0028DF24;
extern s32 D_0028DF28;
extern s32 D_0028DF2C;
extern s32 D_0028DF30;
extern s32 D_0028DF34;
extern s32 D_0028DF38;
extern u8 D_0029C0C0[];
extern u8 D_0029C150[];
extern u8 *reg_a0;

void func_0013B190(void) {
    s32 i;

    for (i = 0; i < 0x8C0; i++) {
        D_0029C150[i] = 0;
    }
    for (i = 0; i < 0x90; i++) {
        D_0029C0C0[i] = 0;
    }
    reg_a0 = (u8 *)D_0029C0C0;
    reg_d7.w = 2;
    D_0028DF38 = 0;
    D_0028DF34 = 0;
    D_0028DF30 = 0;
    D_0028DF2C = 0;
    D_0028DF28 = 0;
    D_0028DF24 = 0;
    D_0028DF20 = 0;
    do {
        (*(s16 *)((u8 *)(reg_a0) + (0))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (4))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x2C))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x2E))) = 0;
        reg_a0 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d7.h[0] = 0x13;
    reg_a0 = (u8 *)D_0029C150;
    do {
        (*(s16 *)((u8 *)(reg_a0) + (0))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x2C))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x2E))) = 0;
        reg_a0 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
