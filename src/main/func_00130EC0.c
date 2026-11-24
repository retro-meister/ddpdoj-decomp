#include "common.h"

s32 func_00130CC0();                            /* extern */
s32 func_00137AD0();                            /* extern */
extern s32 D_0028C0A8;
extern u8 D_0028E1D8[];
extern s32 *reg_a0_as_s32_p;

void func_00130EC0(void) {
    reg_d0.h[0] = 0x12;
    reg_d1.h[0] = 3;
    reg_a0_as_s32_p = &D_0028C0A8;
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_d0.h[0] += 6;
    reg_d4.b[0] = D_0028E1D8[0];
    func_00130CC0();
}
