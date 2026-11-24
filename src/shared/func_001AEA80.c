#include "common.h"

s32 func_001AEB10();                            /* extern */
extern s32 D_0028E718;
extern s32 D_0028E71C;
extern s32 D_0028E728_as_s32;
extern s32 D_0028E72C_as_s32;
extern s32 D_0028E730;
extern s32 D_0028E734;
extern s32 D_0028E758_as_s32;
extern s32 D_0028E75C_as_s32;
extern s32 D_0028E768_as_s32;
extern s32 D_0028E76C_as_s32;
extern s32 D_0028E8C0_as_s32;
extern s32 D_0028E8C4_as_s32;
extern s32 *reg_a0_as_s32_p;
extern s32 *reg_a1_as_s32_p;
extern s32 *reg_a2_as_s32_p;
extern s32 *reg_a3_as_s32_p;
extern s32 *reg_a4_as_s32_p;
extern s32 *reg_a6_as_s32_p;

void func_001AEA80(void) {
    reg_a0_as_s32_p = &D_0028E76C_as_s32;
    reg_a1_as_s32_p = &D_0028E71C;
    reg_a2_as_s32_p = &D_0028E734;
    reg_a3_as_s32_p = &D_0028E8C4_as_s32;
    reg_a4_as_s32_p = &D_0028E72C_as_s32;
    reg_a6_as_s32_p = &D_0028E75C_as_s32;
    reg_d7.w = 0;
    func_001AEB10();
    reg_a0_as_s32_p = &D_0028E768_as_s32;
    reg_a1_as_s32_p = &D_0028E718;
    reg_a2_as_s32_p = &D_0028E730;
    reg_a3_as_s32_p = &D_0028E8C0_as_s32;
    reg_a4_as_s32_p = &D_0028E728_as_s32;
    reg_a6_as_s32_p = &D_0028E758_as_s32;
    reg_d7.w = 1;
    func_001AEB10();
}
