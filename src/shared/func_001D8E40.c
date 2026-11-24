#include "common.h"

s32 func_00129320();
s32 func_002011A0();
void func_001D8E40(void) {
    u32 temp_s0;

    temp_s0 = reg_d0.sw;
    reg_d7.sw = temp_s0;
    func_002011A0();
    reg_d0.b[0] &= 7;
    reg_d0.b[0] += 3;
    reg_d6.b[0] = reg_d0.b[0];
    reg_d0.sw = temp_s0;
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129320();
    reg_d0.sw += 0xFFFE0000;
    func_00129320();
    reg_d0.sw += 0xFFFE0000;
    func_00129320();
    reg_d0.sw += 0xFFFE0000;
    func_00129320();
    reg_d1.b[0] += reg_d6.b[0];
    reg_d0.sw = reg_d7.sw;
    reg_d1.b[0] += reg_d6.b[0];
    func_00129320(reg_d6.b[0]);
    reg_d0.sw += 0xFFFE0000;
    func_00129320();
    reg_d0.sw += 0xFFFE0000;
    func_00129320();
    reg_d0.sw += 0xFFFE0000;
    func_00129320();
}
