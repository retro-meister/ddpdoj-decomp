#include "common.h"

s32 func_00219DF0();
s32 func_0021A170();
extern s16 D_0028E238;
extern s32 D_0028EA80;
extern u8 D_002B6D50[];
void func_00219D20(void) {
    s32 var_s0;
    s32 var_s1;
    s32 temp_s2;
    s32 var_s3;
    u8 *var_s4;

    var_s4 = (u8 *)(D_002B6D50);
    var_s1 = 0;
    D_0028EA80 = 0;
    temp_s2 = D_0028E238 & 0x7FF;
    do {
        var_s3 = temp_s2 / 32;
        for (var_s0 = 0; var_s0 < 0xF; var_s0++) {
            reg_d0.w = *(u32 *)(var_s4 + (var_s3 * 4));
            if ((reg_d0.w != 0xC0000000) && (reg_d0.w != 0)) {
                func_00219DF0(var_s0, var_s1);
            }
            var_s3++;
            var_s3 &= 0x3F;
        }
        var_s1 += 1;
        var_s4 += 0x100;
    } while (var_s1 < 9);
    func_0021A170();
}
