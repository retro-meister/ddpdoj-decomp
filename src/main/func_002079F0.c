#include "common.h"

extern void func_002092F0(void);
extern u8 D_00267AC0[];
extern u8 D_0028E38C;
extern u8 *reg_a0;

void func_002079F0(void) {
    reg_a0 = D_00267AC0;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E38C;
    reg_d0.h[0] <<= 5;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x2A;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}
