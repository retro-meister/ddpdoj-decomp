#include "common.h"

s32 func_00127530();
extern s8 D_0028E408;
extern u8 *reg_a0;

void func_001276D0(void) {
    func_00127530();
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) += 5;
    D_0028E408 = 0;
}
