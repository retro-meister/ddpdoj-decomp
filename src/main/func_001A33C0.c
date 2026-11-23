#include "common.h"

s32 func_001A2FA0();
s32 func_001A3020();
extern u8 D_0025F640[];
extern u8 D_0025F650[];
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 *reg_a0;

void func_001A33C0(void) {
    u8 *temp_s0;
    u8 *var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;

    temp_s0 = (u8 *)(D_0025F640 + (reg_d0.h[0] * 8));
    var_s1 = (u8 *)(D_0025F650 + (((reg_d1.h[0] != 0) + (reg_d0.h[0] * 2)) * 0x10));
    if (reg_d0.h[0] == 0) {
        if (D_0028E99C >= 0) {
            var_v0 = D_0028E99C * 0x10;
            var_s1 = (u8 *)(D_0025F650 + var_v0);
        }
    } else {
        if (D_0028E998 >= 0) {
            var_v0 = D_0028E998 * 0x10;
            var_s1 = (u8 *)(D_0025F650 + var_v0);
        }
    }
    var_s2 = 0;
    var_s3 = 0;
    var_s4 = 0;
    do {
        reg_a0 = *(u8 **)((u8 *)var_s1 + var_s3);
        reg_d0.h[0] = *(u16 *)(temp_s0 + var_s4);
        func_001A3020();
        var_s2 += 1;
        var_s3 += 4;
        var_s4 += 2;
    } while (var_s2 < 3);
    reg_a0 = *(u8 **)((u8 *)var_s1 + (var_s2 * 4));
    reg_d0.w = (u32) *(u16 *)(temp_s0 + (var_s2 * 2));
    func_001A2FA0();
}
