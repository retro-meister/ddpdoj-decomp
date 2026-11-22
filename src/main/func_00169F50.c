#include "common.h"


s32 func_00130CC0();
s32 func_00137AD0();
s32 func_0016A0D0();
extern u8 D_0026AC20[];
extern u8 *reg_a0;

void func_00169F50(void) {
    u16 temp_a0;

    reg_d0.h[0] -= reg_d1.h[0];
    reg_d4.h[0] = reg_d0.h[0];
    if (reg_d4.h[0] == 1) {
        func_0016A0D0();
        return;
    }
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    reg_a0 = D_0026AC20;
    reg_d1.h[0] = 0x13;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d1.h[0] += 2;
    reg_d0.h[0] = 0xC;
    func_00130CC0();
}
