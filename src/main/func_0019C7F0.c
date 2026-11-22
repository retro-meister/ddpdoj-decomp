#include "common.h"

s32 func_0019BC10();
s32 func_0019BD40();
extern u16 D_0028E190;
extern u8 D_002A9AE0[];
extern u8 *reg_a0;

void func_0019C7F0(void) {
    func_0019BC10();
    reg_a0 = D_002A9AE0;
    reg_a0 += D_0028E190;
    func_0019BD40();
    D_0028E190 += 0xC;
}
