#include "common.h"

s32 func_001A3D30();                            /* extern */
s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s32 D_0028EAEC;
extern s32 D_0028EAF0;
extern s32 D_0028EAF4;
extern s8 D_0028EB04;
extern s8 D_0028EB08;
extern s8 D_0028EB2C;
extern s8 D_0028EB5C;
extern s32 D_0028EB90;
extern s32 D_0028EB94;

void func_0021F820(void) {
    D_0028EB94 = 0;
    D_0028EB5C += 1;
    func_00222340(0x18);
    D_0028EB90 = 0x40;
    D_0028EB2C = 1;
    D_0028EB04 = 1;
    D_0028E320 = 0xE10;
    D_0028EB08 = 0;
    D_0028EAF0 = 0;
    D_0028EAEC = 0;
    D_0028EAF4 = 0;
    func_001A3D30();
}
