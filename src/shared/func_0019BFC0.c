#include "common.h"

s32 func_0019B6E0();
extern u16 D_0028E190;
extern u8 D_002A9AE0[];
extern u8 *reg_a0;

void func_0019BFC0(void) {
    reg_a0 = D_002A9AE0;
    reg_a0 += D_0028E190;
    func_0019B6E0();
    D_0028E190 += 0xC;
}
