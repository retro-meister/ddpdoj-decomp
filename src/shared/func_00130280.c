#include "common.h"

s32 func_001301B0();
s32 func_00130200();
s32 func_001305C0();
s32 func_001305D0();
s32 func_00131340();
s32 func_001313A0();
extern u8 D_0028E1E5[];
extern u8 D_0028E39C;

void func_00130280(void) {
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) {
        func_001305C0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_00130200();
        reg_d2.w = 0;
        reg_d2.b[0] = D_0028E1E5[0];
        if ((s16)(reg_d2.h[0]) > (s16) reg_d0.h[0]) {
            func_001305D0();
            return;
        }
        if (reg_d3.h[0] == 0) {
            func_001305C0();
            return;
        }
        reg_d0.h[0] = reg_d2.h[0];
        D_0028E1E5[0] = 1;
        func_001313A0();
        func_001305C0();
        return;
    }
    func_001301B0();
    if (reg_d0.h[0] == 0) {
        func_001305D0();
        return;
    }
    if (reg_d3.h[0] == 0) {
        func_001305C0();
        return;
    }
    func_00131340();
    func_001305C0();
}
