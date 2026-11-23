#include "common.h"

s32 func_00222530();
extern s8 D_0028EADC;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB64;

void func_0022A930(void) {
    if (func_00222530(0xC) != 0) {
        D_0028EB64 += 1;
        if ((0 <= D_0028EADC) && (D_0028EADC < 5)) {
            D_0028EB58 = D_0028EADC + 3;
            D_0028EB54 = 1;
        } else {
            D_0028EB58 = -1;
            D_0028EB54 = 1;
        }
    }
}
