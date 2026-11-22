#include "common.h"

s32 func_00137AD0();
extern u8 D_0026AAA0[];
extern u8 D_0028E350;
extern u8 *reg_a0;

void func_00169DA0(void) {
    if (D_0028E350 == 0) {
        reg_d0.h[0] = 0;
        reg_d2.h[0] = 0;
        reg_a0 = D_0026AAA0;
        reg_d1.h[0] = 0x13;
        func_00137AD0();
        reg_a0 += 0x20;
        reg_d1.h[0] -= 1;
        func_00137AD0();
        reg_a0 += 0x20;
        reg_d1.h[0] -= 1;
        func_00137AD0();
    }
}
