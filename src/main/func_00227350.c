#include "common.h"

s32 func_00222530(s32);                             /* extern */
extern s8 D_0028EB04;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s32 D_0028EB90;

s32 func_00227350(u8 *arg0, s32 arg1) {
    if (func_00222530(arg1) != 0) {
        *arg0 += 1;
        D_0028EB58 = 1;
        D_0028EB90 = 0x40;
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        return 1;
    }
    return 0;
}
