#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s8 D_0028EB10;
extern s8 D_0028EB34;
extern s8 D_0028EB64;
extern s32 D_0028EB9C;

void func_0022A8F0(void) {
    D_0028EB9C = 0;
    D_0028EB64 += 1;
    func_00222340(0xC);
    D_0028EB10 = 0;
    D_0028EB34 = 1;
}
