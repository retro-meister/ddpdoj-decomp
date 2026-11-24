#include "common.h"

s32 func_002071C0();                            /* extern */
s32 func_00224A90();                            /* extern */
s32 func_0022B620();                            /* extern */
extern u8 *reg_a0;

void func_00237790(void) {
    u32 temp_s0;
    u8 *temp_s1;

    temp_s0 = reg_d0.w;
    temp_s1 = reg_a0;
    func_0022B620();
    func_00224A90();
    reg_d0.h[0] = 0x14;
    func_002071C0();
    (*(s8 *)((u8 *)(reg_a0) + (5))) = 4;
    reg_d0.w = temp_s0;
    reg_a0 = temp_s1;
}
