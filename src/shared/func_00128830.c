#include "common.h"

s32 func_00129450();
extern s32 D_0028DE98;
extern u32 D_0028DE9C;
extern u32 D_0028DEA0;
extern u8 *reg_a0;

void func_00128830(void) {
    reg_d1.b[0] += reg_d1.b[0];
    reg_d0.w += 0x20000;
    reg_d1.b[0] += reg_d1.b[0];
    func_00129450();
    reg_d0.w -= 0x20000;
    reg_d1.b[0] -= 8;
    func_00129450();
    reg_d1.b[0] += 0x10;
    func_00129450();
    reg_d0.w = D_0028DEA0;
    reg_d1.w = D_0028DE9C;
    reg_a0 = (u8 *)D_0028DE98;
}
