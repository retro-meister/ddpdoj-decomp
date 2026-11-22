#include "common.h"

s32 func_002034C0();                            /* extern */
s32 func_00203630();                            /* extern */
extern u16 D_0028E91C;

void func_002035A0(void) {
    func_002034C0();
    reg_d7.h[0] = D_0028E91C;
    reg_d7.h[0] += 1;
    if ((s32) reg_d7.h[0] >= 5) {
        reg_d7.w = 0;
    }
    func_00203630();
}
