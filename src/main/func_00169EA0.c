#include "common.h"


s32 func_0012FFE0();
s32 func_00130CC0();
s32 func_00137AD0();
s32 func_00169F50();
extern u8 D_0026ABC0[];
extern u8 *reg_a0;

void func_00169EA0(void) {
    func_0012FFE0();
    if (reg_d1.h[0] != 0) {
        func_00169F50();
        return;
    }
    reg_d2.h[0] = 0;
    reg_a0 = D_0026ABC0;
    reg_d1.h[0] = 0x13;
    reg_d4.h[0] = reg_d0.h[0];
    reg_d0.h[0] = 0;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_d1.h[0] += 2;
    reg_d0.h[0] = 0xE;
    func_00130CC0();
}
