#include "common.h"

s32 func_00129280();                            /* extern */

void func_001DB980(void) {
    reg_d1.b[0] -= 9;
    func_00129280();
    reg_d1.b[0] -= 0x12;
    func_00129280();
    reg_d1.b[0] += 0x24;
    func_00129280();
    reg_d1.b[0] += 0x12;
    func_00129280();
}
