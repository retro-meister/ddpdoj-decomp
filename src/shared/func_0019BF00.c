#include "common.h"

s32 func_0019B6E0();
extern u16 D_0028E19C;
extern u8 D_002AE100[];
extern u8 *reg_a0;

void func_0019BF00(void) {
    reg_a0 = D_002AE100;
    reg_a0 += D_0028E19C;
    func_0019B6E0();
    D_0028E19C += 0xC;
}
