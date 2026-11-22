#include "common.h"


s32 func_00130CC0();
s32 func_00137AD0();
s32 func_0016A690();
extern u8 D_0026AD80[];
extern u8 *reg_a0;

void func_0016A4A0(void) {
    u16 temp_a0;

    reg_d0.h[0] -= reg_d1.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    if (reg_d4.h[0] == 1) {
        func_0016A690();
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = D_0026AD80;
    reg_d0.h[0] = reg_d7.h[0];
    reg_d1.h[0] = reg_d6.h[0];
    func_00137AD0();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d0.h[0] = 2;
    reg_d0.h[0] += reg_d7.h[0];
    func_00130CC0();
}
