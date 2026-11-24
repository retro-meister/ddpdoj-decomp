#include "common.h"

extern void func_002092F0(void);
extern u8 D_00267C20[];
extern u8 D_0028E388;
extern u8 *reg_a0;

void func_00207A40(void) {
    reg_a0 = D_00267C20;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E388;
    reg_d0.h[0] <<= 6;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x24;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
    reg_d1.h[0] = 0x23;
    reg_a0 += 0x20;
    func_002092F0();
}
