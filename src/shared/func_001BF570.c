#include "common.h"

s32 func_00129410();
void func_001BF570(void) {
    reg_d0.w = 0xFFFE0001;
    reg_d7.b[0] = reg_d1.b[0];
    reg_d6.h[0] = 0x10;
    func_00129410();
    reg_d1.b[0] += reg_d6.b[0];
    func_00129410();
    reg_d1.b[0] += reg_d6.b[0];
    func_00129410();
    reg_d1.b[0] += reg_d6.b[0];
    func_00129410();
    reg_d1.b[0] = reg_d7.b[0];
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129410();
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129410();
    reg_d1.b[0] -= reg_d6.b[0];
    func_00129410();
}
