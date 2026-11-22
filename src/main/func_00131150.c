#include "common.h"

s32 func_00130CC0();                            /* extern */
s32 func_00137AD0();                            /* extern */
extern s32 D_0024F398[];
extern u8 D_0028E1E6[];
extern s32 *reg_a0;

void func_00131150(void) {
    reg_d0.h[0] = 3;
    reg_a0 = D_0024F398;
    reg_d1.h[0] = 3;
    reg_d2.h[0] = 0;
    func_00137AD0();
    reg_d0.h[0] += 8;
    reg_d4.b[0] = D_0028E1E6[0];
    func_00130CC0();
}
