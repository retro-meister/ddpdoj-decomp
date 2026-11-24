#include "common.h"

s32 func_002071C0();
s32 func_00224A90();
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u8 *reg_a0;

void func_002376F0(void) {
    u32 temp_s0;
    u8 *temp_s1;
    s32 var_s2;

    temp_s0 = reg_d0.w;
    temp_s1 = (u8 *)(reg_a0);
    var_s2 = 0;
    if (D_0028ED80 != 0) {
        var_s2 = 1;
    }
    if (D_0028ED7C == 2) {
        var_s2 = 0;
    }
    func_00224A90();
    reg_d0.h[0] = 0x14;
    func_002071C0();
    if (var_s2 != 0) {
        (*(s8 *)((u8 *)(reg_a0) + (5))) = 1;
    } else {
        (*(s8 *)((u8 *)(reg_a0) + (5))) = 2;
    }
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}
