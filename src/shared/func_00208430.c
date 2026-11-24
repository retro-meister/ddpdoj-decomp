#include "common.h"

s32 func_00209200();                            /* extern */
extern s32 D_00267EC0[];
extern s32 D_00267ED0[];
extern s32 D_00267EE0[];
extern s32 D_00267EF0[];
extern s32 D_00267F08[];
extern s32 *reg_a0_as_s32_p;

void func_00208430(void) {
    reg_a0_as_s32_p = D_00267EC0;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0_as_s32_p = D_00267ED0;
    func_00209200();
    reg_a0_as_s32_p = D_00267EE0;
    func_00209200();
    reg_a0_as_s32_p = D_00267EF0;
    func_00209200();
    reg_a0_as_s32_p = D_00267F08;
    func_00209200();
}
