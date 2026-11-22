#include "common.h"

s32 func_0013B2E0();
s32 func_00198F30();
extern u8 D_0025BF90[];
extern s16 D_002BAE80[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_00198EF0() {
    (*(s16 *)((u8 *)(reg_a4) + (0x2E))) = 1;
    D_002BAE80[0] = 1;
    reg_a0 = D_0025BF90;
    func_0013B2E0();
    func_00198F30();
}
