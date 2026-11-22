#include "common.h"

s32 func_00129280();                            /* extern */

void func_001DB900(void) {
    reg_d1.b[0] -= 0xA;
    func_00129280();
    reg_d1.b[0] += 0x14;
    func_00129280();
}
