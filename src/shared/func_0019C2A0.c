#include "common.h"

s32 func_0019B880();
s32 func_0019B9B0();
extern u16 D_0028E1A0;
extern u8 D_002AF860[];
extern u8 *reg_a0;

void func_0019C2A0(void) {
    func_0019B880();
    reg_a0 = D_002AF860;
    reg_a0 += D_0028E1A0;
    func_0019B9B0();
    D_0028E1A0 += 0xC;
}
