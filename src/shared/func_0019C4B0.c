#include "common.h"

s32 func_0019BB40();
extern u16 D_0028E19C;
extern u8 D_002AE100[];
extern u8 *reg_a0;

void func_0019C4B0(void) {
    reg_a0 = D_002AE100;
    reg_a0 += D_0028E19C;
    func_0019BB40();
    D_0028E19C += 0xC;
}
