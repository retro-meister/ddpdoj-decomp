#include "common.h"


s32 func_001301B0();
s32 func_00169DA0();
s32 func_00169E20();
s32 func_00169EA0();
s32 func_0016A010();
s32 func_0016A140();
extern u8 D_0028E390;
extern u8 D_0028E39C;

void func_00169C60(void) {
    reg_d0.b[0] = D_0028E390;
    if (reg_d0.b[0] == 1) {
        func_0016A140();
        return;
    }
    func_001301B0();
    if (reg_d0.h[0] != 0) {
        func_00169DA0();
        return;
    }
    reg_d0.b[0] = D_0028E39C;
    if (reg_d0.b[0] == 0x12) {
        func_00169DA0();
        return;
    }
    if (reg_d0.b[0] == 0x11) {
        func_0016A010();
        return;
    }
    if ((s8)(reg_d0.b[0]) >= 9) {
        func_00169EA0();
        return;
    }
    func_00169E20();
}
