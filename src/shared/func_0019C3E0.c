#include "common.h"

s32 func_0019B880();
s32 func_0019B9B0();
extern u16 D_0028E190;
extern u8 D_002A9AE0[];
extern u8 *reg_a0;

void func_0019C3E0(void) {
    func_0019B880();
    reg_a0 = D_002A9AE0;
    reg_a0 += D_0028E190;
    func_0019B9B0();
    D_0028E190 += 0xC;
}
