#include "common.h"

s32 func_00129280();                            /* extern */

void func_001DBE00(void) {
    reg_d1.b[0] += 3;
    func_00129280();
    reg_d1.b[0] += 6;
    func_00129280();
    reg_d1.b[0] += 6;
    func_00129280();
    reg_d1.b[0] += 6;
    func_00129280();
    reg_d1.b[0] += 6;
    func_00129280();
    reg_d1.h[0] = reg_d7.h[0];
    reg_d1.b[0] += 0xFD;
    func_00129280();
    reg_d1.b[0] += 0xFA;
    func_00129280();
    reg_d1.b[0] += 0xFA;
    func_00129280();
    reg_d1.b[0] += 0xFA;
    func_00129280();
    reg_d1.b[0] += 0xFA;
    func_00129280();
}
