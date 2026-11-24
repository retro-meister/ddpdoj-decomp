#include "common.h"
#pragma opt_propagation off

extern s32 func_002365A0(void);
extern s16 D_0028E320;
extern s8 D_0028EB18;
extern s8 D_0028EB54;
extern s8 D_0028EB58;
extern s8 D_0028EB6C;

void func_0021ED70(void) {
    if (func_002365A0() != 0) {
        s8 val = D_0028EB18;
        D_0028EB6C = 2;
        D_0028EB54 = 1;
        D_0028E320 = 0xE10;
        D_0028EB58 = val;
    }
}
