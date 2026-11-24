#include "common.h"

s32 func_00137AD0();
extern u8 D_00251B40[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001B0100(void) {
    reg_a0 = D_00251B40;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0)));
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
}
