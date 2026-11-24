#include "common.h"

s32 func_002092F0();
s32 func_002099D0();
extern u8 D_00268450[];
extern u8 D_002686B0[];
extern u8 D_0028E39C;
extern u8 *reg_a0;

void func_00209920(void) {
    reg_a0 = (u8 *)D_00268450;
    reg_d0.w = 0;
    reg_d0.b[0] = D_0028E39C;
    reg_d0.h[0] <<= 5;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x2A;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
    if (D_0028E39C != 0x11) {
        func_002099D0();
        return;
    }
    reg_a0 = (u8 *)D_002686B0;
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x29;
    reg_d2.h[0] = reg_d7.h[0];
    func_002092F0();
}
