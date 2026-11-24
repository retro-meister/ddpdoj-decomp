#include "common.h"

s32 func_0019B880();
s32 func_0019B9B0();
extern u16 D_0028E198;
extern u8 D_002AC9A0[];
extern u8 *reg_a0;

void func_0019C340(void) {
    func_0019B880();
    reg_a0 = D_002AC9A0;
    reg_a0 += D_0028E198;
    func_0019B9B0();
    D_0028E198 += 0xC;
}
