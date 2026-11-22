#include "common.h"


s32 func_00137AD0();
extern u8 D_0026A720[];
extern u8 D_0028E388;
extern u8 *reg_a0;

void func_0015C3A0(void) {
    u16 temp_a0;

    reg_a0 = D_0026A720;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E388;
    reg_d0.w += reg_d0.w;
    reg_d0.w += reg_d0.w;
    temp_a0 = reg_d0.h[0];
    reg_a0 = *(u8 **)((u8 *)reg_a0 + temp_a0);
    reg_d1.h[0] = 0xF;
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
}
