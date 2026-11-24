#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s8 D_0028EB04;
extern s8 D_0028EB20;
extern s8 D_0028EB44;
extern s8 D_0028EB74;
extern s32 D_0028EB90;
extern s32 D_0028EBAC;

void func_0021E370(void) {
    D_0028EBAC = 0;
    D_0028EB74 += 1;
    func_00222340(2);
    D_0028EB90 = 0x40;
    D_0028EB20 = 0;
    D_0028EB44 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}
