#include "common.h"

s32 func_00130CC0();                            /* extern */
s32 func_00137AD0();                            /* extern */
extern s32 D_0028C0B0;
extern s32 D_0028C0B8;
extern u8 D_0028E1D8[];
extern u8 D_0028E1DA[];
extern u8 D_0028E1EC;
extern s32 *reg_a0;

void func_00131050(void) {
    reg_d0.h[0] = 0x11;
    reg_d1.h[0] = 4;
    reg_a0 = &D_0028C0B0;
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_a0 = &D_0028C0B8;
    reg_d1.h[0] = 3;
    func_00137AD0();
    reg_d0.h[0] += 5;
    reg_d4.b[0] = D_0028E1EC;
    func_00130CC0();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1D8[0];
    func_00130CC0();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1DA[0];
    func_00130CC0();
}
