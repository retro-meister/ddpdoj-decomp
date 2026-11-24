#include "common.h"

s32 func_00129370();
s32 func_002011A0();
void func_001D8F40(void) {
    u32 temp_s0;

    temp_s0 = reg_d0.w;
    reg_d7.w = temp_s0;
    func_002011A0();
    reg_d0.b[0] &= 0xF;
    reg_d0.b[0] += 6;
    reg_d6.b[0] = reg_d0.b[0];
    reg_d0.w = temp_s0;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d1.b[0] -= reg_d6.b[0];
    reg_d0.w = reg_d7.w;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.w = reg_d7.w;
    reg_d1.b[0] += reg_d6.b[0];
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
    reg_d0.w -= 0x20000;
    func_00129370();
}
