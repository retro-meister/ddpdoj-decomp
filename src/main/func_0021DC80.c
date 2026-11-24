#include "common.h"
#pragma opt_propagation off

extern s32 func_002365A0(void);
extern s16 D_0028E320;
extern s8 D_0028EB28;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB7C;

void func_0021DC80(void) {
    if (func_002365A0() != 0) {
        s8 val = D_0028EB28;
        D_0028EB7C = 2;
        D_0028EB54 = 1;
        D_0028E320 = 0xE10;
        D_0028EB58 = val;
    }
}
