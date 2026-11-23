#include "common.h"

s32 func_00130CC0();
s32 func_00137AD0();
extern u8 D_0024F388[];
extern u8 D_0028E1D8[];
extern u8 D_0028E1E4[];
extern u8 D_0028E1E6[];
extern u8 D_0028E1EC;
extern u8 *reg_a0;

void func_00130F10(void) {
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    reg_a0 = (u8 *)D_0024F388;
    func_00137AD0();
    reg_d0.h[0] += 0xC;
    reg_d4.b[0] = D_0028E1EC;
    func_00130CC0();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E4[0];
    reg_d4.b[0] += D_0028E1D8[0];
    func_00130CC0();
    reg_d0.h[0] -= 2;
    reg_d4.b[0] = D_0028E1E6[0];
    func_00130CC0();
}
