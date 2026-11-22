#include "common.h"

s32 func_00137AD0();
extern u8 D_0026AA40[];
extern u8 *reg_a0;

void func_00169D30(void) {
    reg_a0 = D_0026AA40;
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
