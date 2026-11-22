#include "common.h"

s32 func_00201160();
extern s8 D_0028E408;
extern u8 *reg_a0;

void func_001275D0(void) {
    reg_d7.w = reg_d0.w;
    func_00201160();
    reg_d0.h[0] &= 0x1F;
    (*(u8 *)((u8 *)(reg_a0) + (0x19))) += reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a0) + (0x20))) = 0;
    D_0028E408 = 0;
    reg_d0.w = reg_d7.w;
}
