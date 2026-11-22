#include "common.h"

s32 func_00137AD0();
extern u8 D_0026AD40[];
extern u8 *reg_a0;

void func_0016A690(void) {
    reg_a0 = D_0026AD40;
    reg_d2.h[0] = 0;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
}
