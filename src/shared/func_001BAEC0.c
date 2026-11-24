#include "common.h"

s32 func_00201160();
extern u8 *reg_a4;

void func_001BAEC0(void) {
    func_00201160();
    reg_d0.h[0] &= 7;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0))) = (u16) reg_d0.h[0];
    func_00201160();
    reg_d0.b[0] &= 3;
    reg_d0.b[0] += 2;
    (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) reg_d0.b[0];
}
