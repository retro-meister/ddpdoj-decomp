#include "common.h"

s32 func_002032F0();                            /* extern */
extern s32 *D_0028E448_as_s32_p;
extern s32 D_0029F1F0_as_s32_a[];
extern s32 D_0029F260_as_s32_a[];
extern s32 *reg_a0_as_s32_p;
extern s32 *reg_a1_as_s32_p;
extern u8 *reg_a6;

void func_00203330(void) {
    reg_a0_as_s32_p = D_0029F260_as_s32_a;
    reg_a1_as_s32_p = D_0029F1F0_as_s32_a;
    if ((*(u8 *)((u8 *)(reg_a6) + (0x2B))) != 0) {
        D_0028E448_as_s32_p = reg_a1_as_s32_p;
        reg_a1_as_s32_p = reg_a0_as_s32_p;
        reg_a0_as_s32_p = D_0028E448_as_s32_p;
    }
    func_002032F0();
}
