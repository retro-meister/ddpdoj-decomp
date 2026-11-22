#include "common.h"


s32 func_00130200();
s32 func_00137AD0();
s32 func_00169DA0();
s32 func_0016A0D0();
extern u8 D_0026AB00[];
extern u8 *reg_a0;

void func_0016A010(void) {
    func_00130200();
    if (reg_d0.h[0] == 1) {
        func_0016A0D0();
        return;
    }
    if ((s16)(reg_d0.h[0]) >= 2) {
        func_00169DA0();
        return;
    }
    reg_d0.h[0] = 0;
    reg_d2.h[0] = 0;
    reg_a0 = D_0026AB00;
    reg_d1.h[0] = 0x13;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
    reg_a0 += 0x20;
    reg_d1.h[0] -= 1;
    func_00137AD0();
}
