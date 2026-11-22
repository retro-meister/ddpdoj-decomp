#include "common.h"

s32 func_001AEB10();                            /* extern */
extern s32 D_0028E718;
extern s32 D_0028E71C;
extern s32 D_0028E728;
extern s32 D_0028E72C;
extern s32 D_0028E730;
extern s32 D_0028E734;
extern s32 D_0028E758;
extern s32 D_0028E75C;
extern s32 D_0028E768;
extern s32 D_0028E76C;
extern s32 D_0028E8C0;
extern s32 D_0028E8C4;
extern s32 *reg_a0;
extern s32 *reg_a1;
extern s32 *reg_a2;
extern s32 *reg_a3;
extern s32 *reg_a4;
extern s32 *reg_a6;

void func_001AEA80(void) {
    reg_a0 = &D_0028E76C;
    reg_a1 = &D_0028E71C;
    reg_a2 = &D_0028E734;
    reg_a3 = &D_0028E8C4;
    reg_a4 = &D_0028E72C;
    reg_a6 = &D_0028E75C;
    reg_d7.w = 0;
    func_001AEB10();
    reg_a0 = &D_0028E768;
    reg_a1 = &D_0028E718;
    reg_a2 = &D_0028E730;
    reg_a3 = &D_0028E8C0;
    reg_a4 = &D_0028E728;
    reg_a6 = &D_0028E758;
    reg_d7.w = 1;
    func_001AEB10();
}
