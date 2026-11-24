#include "common.h"

s32 func_00222340(s32);                     /* extern */
extern s16 D_0028E320;
extern s8 D_0028E368_as_s8;
extern s8 D_0028EB4C;
extern s8 D_0028EB7C;
extern s8 D_0028EB80;
extern s32 D_0028EBB4;

void func_0021DA10(void) {
    D_0028E368_as_s8 = 0;
    D_0028EBB4 = 0;
    D_0028EB80 = 0;
    D_0028EB7C += 1;
    func_00222340(0);
    D_0028EB4C = 1;
    D_0028E320 = 0xE10;
}
