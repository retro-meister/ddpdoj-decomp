#include "common.h"

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
extern s32 D_0025B0E0[];
extern s32 D_0028CA00;
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a6;

void func_0016CCE0(void) {
    reg_a0_as_s32_p = D_0025B0E0;
    func_0014E370();
    reg_a0_as_s32_p = &D_0028CA00;
    reg_d0.w = 1;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
}
