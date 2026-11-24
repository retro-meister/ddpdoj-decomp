#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s8 D_0028EB04;
extern s8 D_0028EB0C;
extern s8 D_0028EB30;
extern s8 D_0028EB60;
extern s32 D_0028EB90;
extern s32 D_0028EB98;

void func_0021F560(void) {
    D_0028EB98 = 0;
    D_0028EB60 += 1;
    func_00222340(0x15);
    D_0028EB90 = 0x40;
    D_0028EB0C = 0;
    D_0028EB30 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}
