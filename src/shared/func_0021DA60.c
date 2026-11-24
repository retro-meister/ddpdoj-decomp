#include "common.h"

s32 func_00222530(s32);                         /* extern */
extern s8 D_0028EB04;
extern s8 D_0028EB28;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB7C;

void func_0021DA60(void) {
    if (func_00222530(0) != 0) {
        D_0028EB54 = 1;
        D_0028EB04 = 1;
        D_0028EB7C += 1;
        D_0028EB58 = D_0028EB28;
    }
}
