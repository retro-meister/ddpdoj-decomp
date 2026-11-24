#include "common.h"

s32 func_001713B0();
s32 func_001B6820();
extern u8 D_0026E120[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001B67A0(void) {
    func_001713B0();
    reg_a0 = D_0026E120;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 8) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 0xA) = *(u16 *)reg_a0;
    func_001B6820();
}
