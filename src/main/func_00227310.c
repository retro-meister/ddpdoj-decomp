#include "common.h"

extern s16 D_0028E320;
extern s8 D_0028EB04;
extern s8 D_0028EB50;
extern s8 D_0028EB54;
extern s32 D_0028EB90;

void func_00227310(u8 *arg0) {
    D_0028E320 = 0xE10;
    (*(s16 *)((u8 *)(arg0) + (4))) = 0x40;
    (*(s8 *)((u8 *)(arg0) + (1))) = 1;
    (*(u8 *)((u8 *)(arg0) + (0))) += 1;
    (*(s8 *)((u8 *)(arg0) + (2))) = 1;
    D_0028EB90 = 0x40;
    D_0028EB04 = 1;
    D_0028EB54 = 0;
    D_0028EB50 = 0;
}
