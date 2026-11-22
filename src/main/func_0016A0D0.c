#include "common.h"

s32 func_00137AD0();
extern u8 D_0026AB60[];
extern u8 *reg_a0;

void func_0016A0D0(void) {
    reg_a0 = D_0026AB60;
    reg_d0.h[0] = 0;
    reg_d1.h[0] = 0x13;
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
}
