#include "common.h"

s32 func_0011C7C0();
void func_001A34E0(void) {
    reg_d1.h[0] = 0;
    reg_d0.h[0] = 0xDC;
    if (reg_d2.b[0] != 0) {
        reg_d0.h[0] = 0xDC;
        reg_d1.h[0] = 0xE00;
    }
    reg_d4.w = 0;
    reg_d2.w = 1;
    reg_d3.w = 0xD;
    func_0011C7C0();
}
