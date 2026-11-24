#include "common.h"

s32 func_0019C430();
s32 func_001A4400();
extern u8 D_0028E294;
extern u16 D_0028E3EC;

void func_001A4320(void) {
    reg_d2.w = 0x1458;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 7;
    reg_d1.w = 0;
    func_0019C430();
    if (D_0028E294 == 0) {
        func_001A4400();
        reg_d1.w = 0x5F000400;
        reg_d2.w = 0x153A;
        reg_d3.h[0] = 0x8C0;
        reg_d4.h[0] = 6;
        func_0019C430();
        if (D_0028E3EC != 0) {
            reg_d1.w = 0x63000800;
            reg_d2.w = 0x1547;
            reg_d3.h[0] = 0x4A0;
            reg_d4.h[0] = 5;
            func_0019C430();
        }
    }
    if (D_0028E294 != 0) {
        reg_d1.w = 0x14C00000;
    } else {
        reg_d1.w = 0x05C00000;
    }
    reg_d2.w = 0x153B;
    reg_d3.h[0] = 0x2EE0;
    reg_d4.h[0] = 6;
    func_0019C430();
}
