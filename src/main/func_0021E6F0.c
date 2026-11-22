#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s8 D_0028EB04;
extern s8 D_0028EB1C;
extern s8 D_0028EB40;
extern s8 D_0028EB70;
extern s32 D_0028EB90;
extern s32 D_0028EBA8;

void func_0021E6F0(void) {
    D_0028EBA8 = 0;
    D_0028EB70 += 1;
    func_00222340(3);
    D_0028EB90 = 0x40;
    D_0028EB1C = 0;
    D_0028EB40 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}
