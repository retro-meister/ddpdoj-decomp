#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s8 D_0028EB04;
extern s8 D_0028EB14;
extern s8 D_0028EB38;
extern s8 D_0028EB68;
extern s32 D_0028EB90;
extern s32 D_0028EBA0;

void func_0021EF10(void) {
    D_0028EBA0 = 0;
    D_0028EB68 += 1;
    func_00222340(0xF);
    D_0028EB90 = 0x40;
    D_0028EB14 = 0;
    D_0028EB38 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}
