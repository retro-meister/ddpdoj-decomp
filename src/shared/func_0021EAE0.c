#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s8 D_0028EB04;
extern s8 D_0028EB18;
extern s8 D_0028EB3C;
extern s8 D_0028EB6C;
extern s32 D_0028EB90;
extern s32 D_0028EBA4;

void func_0021EAE0(void) {
    D_0028EBA4 = 0;
    D_0028EB6C += 1;
    func_00222340(0xE);
    D_0028EB90 = 0x40;
    D_0028EB18 = 0;
    D_0028EB3C = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
}
