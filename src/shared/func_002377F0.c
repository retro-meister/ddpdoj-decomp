#include "common.h"

s32 func_0012FAB0();                            /* extern */
s32 func_0013B350();                            /* extern */
s32 func_001A2FA0();                            /* extern */
s32 func_00225B70();                            /* extern */
extern s32 D_00269160_as_s32_a[];
extern s32 D_0026B580_as_s32_a[];
extern u32 D_0028ED84;
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a5;

void func_002377F0(void) {
    s32 *temp_s0;
    u32 temp_s1;

    temp_s0 = reg_a0_as_s32_p;
    temp_s1 = reg_d0.w;
    func_0012FAB0();
    reg_d0.w = 0;
    reg_a0_as_s32_p = D_00269160_as_s32_a;
    func_001A2FA0();
    (*(s8 *)((u8 *)(reg_a5) + (3))) = 1;
    (*(s16 *)((u8 *)(reg_a5) + (6))) = 0;
    func_00225B70();
    reg_a0_as_s32_p = D_0026B580_as_s32_a;
    func_0013B350();
    reg_a0_as_s32_p = temp_s0;
    D_0028ED84 = reg_d0.w;
    reg_d0.w = temp_s1;
}
