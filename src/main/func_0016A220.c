#include "common.h"


s32 func_001301B0();
s32 func_0016A2E0();
s32 func_0016A340();
s32 func_0016A3E0();
s32 func_0016A5C0();
extern u8 D_0028E39C;

void func_0016A220(void) {
    reg_d7.w = 0xE;
    func_001301B0();
    if (reg_d1.h[0] != 0) {
        func_0016A2E0();
        return;
    }
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) {
        func_0016A2E0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_0016A5C0();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        func_0016A3E0();
        return;
    }
    func_0016A340();
}
