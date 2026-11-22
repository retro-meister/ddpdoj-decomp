#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s8 D_0028EB04;
extern s8 D_0028EB24;
extern s8 D_0028EB48;
extern s8 D_0028EB78;
extern s32 D_0028EB90;
extern s32 D_0028EBB0;

void func_0021DD40(void) {
    D_0028EBB0 = 0;
    D_0028EB78 += 1;
    func_00222340(1);
    D_0028EB90 = 0x40;
    D_0028EB24 = 0;
    D_0028EB48 = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}
