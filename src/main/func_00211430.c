#include "common.h"

s32 func_00201B80();
extern u16 D_0029C06C[];
extern u8 *reg_a6;

void func_00211430(void) {
    func_00201B80();
    reg_d1.h[0] = D_0029C06C[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d1.h[0];
}
