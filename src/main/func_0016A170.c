#include "common.h"


s32 func_001301B0();
s32 func_0016A2D0();
s32 func_0016A340();
s32 func_0016A3A0();
s32 func_0016A550();
extern u8 D_0028E39C;

void func_0016A170(void) {
    reg_d7.w = 0;
    func_001301B0();
    if (reg_d0.h[0] != 0) {
        func_0016A2D0();
        return;
    }
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) {
        func_0016A2D0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_0016A550();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        func_0016A3A0();
        return;
    }
    func_0016A340();
}
