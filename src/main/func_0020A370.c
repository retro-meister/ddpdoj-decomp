#include "common.h"

s32 func_0020A3B0();                            /* extern */
extern u16 D_0028E928;

void func_0020A370(void) {
    reg_d2.w = 0x1D;
    if (D_0028E928 != 0) {
        func_0020A3B0();
        return;
    }
    reg_d2.w = 0xE;
    func_0020A3B0();
}
