#include "common.h"

extern s32 D_0028E0C4;
extern s16 D_0028E0C8;
extern s16 D_0028E0CC;
extern s16 D_0028E0D0;
extern u8 D_002A04B0[];
extern u8 *reg_a0;

void func_00206D70(void) {
    D_0028E0C4 = 0;
    D_0028E0C8 = 0;
    reg_a0 = D_002A04B0;
    D_0028E0D0 = 0;
    reg_d0.w = 0x13;
    D_0028E0CC = 0;
    do {
        (*(s16 *)((u8 *)(reg_a0) + (0))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x4A))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x4C))) = 0;
        (*(s16 *)((u8 *)(reg_a0) + (0x4E))) = 0;
        reg_a0 += 0x50;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}
