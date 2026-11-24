#include "common.h"

s32 func_0019BB40();
extern u16 D_0028E198;
extern u8 D_002AC9A0[];
extern u8 *reg_a0;

void func_0019C4F0(void) {
    reg_a0 = D_002AC9A0;
    reg_a0 += D_0028E198;
    func_0019BB40();
    D_0028E198 += 0xC;
}
