#include "common.h"

s32 func_00209200();                            /* extern */
extern s32 D_00268130[];
extern s32 D_00268150[];
extern s32 D_00268170[];
extern s32 D_00268190[];
extern s32 D_002681B0[];
extern s32 D_002681D0[];
extern s32 D_002681F0[];
extern s32 *reg_a0_as_s32_p;

void func_00208E20(void) {
    reg_a0_as_s32_p = D_00268130;
    reg_d0.h[0] = 0;
    func_00209200();
    reg_a0_as_s32_p = D_00268150;
    func_00209200();
    reg_a0_as_s32_p = D_00268170;
    func_00209200();
    reg_a0_as_s32_p = D_00268190;
    func_00209200();
    reg_a0_as_s32_p = D_002681B0;
    func_00209200();
    reg_a0_as_s32_p = D_002681D0;
    func_00209200();
    reg_a0_as_s32_p = D_002681F0;
    func_00209200();
}
