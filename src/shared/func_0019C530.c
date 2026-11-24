#include "common.h"

s32 func_0019BB40();
extern u16 D_0028E194;
extern u8 D_002AB240[];
extern u8 *reg_a0;

void func_0019C530(void) {
    reg_a0 = D_002AB240;
    reg_a0 += D_0028E194;
    func_0019BB40();
    D_0028E194 += 0xC;
}
