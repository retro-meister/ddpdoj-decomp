#include "common.h"

s32 func_0019C430(s32);                     /* extern */

void func_001A42A0(void) {
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;

    temp_s1 = reg_d2.w;
    temp_s2 = reg_d3.w;
    temp_s3 = reg_d4.w;
    temp_s0 = reg_d1.w;
    reg_d2.w = 0x1458;
    reg_d3.h[0] = 0x38E0;
    reg_d4.h[0] = 7;
    reg_d1.w = 0;
    func_0019C430(0x1458);
    reg_d1.w = temp_s0;
    reg_d2.w = temp_s1;
    reg_d3.w = temp_s2;
    reg_d4.w = temp_s3;
}
