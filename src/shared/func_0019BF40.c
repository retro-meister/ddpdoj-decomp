#include "common.h"

s32 func_0019B6E0();
extern u16 D_0028E198;
extern u8 D_002AC9A0[];
extern u8 *reg_a0;

void func_0019BF40(void) {
    reg_a0 = D_002AC9A0;
    reg_a0 += D_0028E198;
    func_0019B6E0();
    D_0028E198 += 0xC;
}
