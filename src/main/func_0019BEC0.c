#include "common.h"

s32 func_0019B6E0();
extern u16 D_0028E1A0;
extern u8 D_002AF860[];
extern u8 *reg_a0;

void func_0019BEC0(void) {
    reg_a0 = D_002AF860;
    reg_a0 += D_0028E1A0;
    func_0019B6E0();
    D_0028E1A0 += 0xC;
}
