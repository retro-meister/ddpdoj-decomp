#include "common.h"

s32 func_00129410();                            /* extern */

void func_001DAF90(void) {
    u32 temp_s0;

    temp_s0 = reg_d1.w;
    reg_d6.b[0] = reg_d1.b[0];
    reg_d1.b[0] += 4;
    func_00129410();
    reg_d1.b[0] += 8;
    func_00129410();
    reg_d1.b[0] = reg_d6.b[0];
    reg_d1.b[0] -= 4;
    func_00129410();
    reg_d1.b[0] -= 8;
    func_00129410();
    reg_d1.w = temp_s0;
}
