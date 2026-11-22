#include "common.h"

s32 func_0019B6E0();
extern u16 D_0028E194;
extern u8 D_002AB240[];
extern u8 *reg_a0;

void func_0019BF80(void) {
    reg_a0 = D_002AB240;
    reg_a0 += D_0028E194;
    func_0019B6E0();
    D_0028E194 += 0xC;
}
