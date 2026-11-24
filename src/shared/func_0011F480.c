#include "common.h"

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
extern s32 D_0024CBC0[];
extern s32 D_0028C088;
extern s32 *reg_a0;
extern u8 *reg_a6;

void func_0011F480(void) {
    reg_a0 = D_0024CBC0;
    func_0014E370();
    reg_a0 = &D_0028C088;
    reg_d0.w = 1;
    func_0014E300();
    reg_tmp.w = 0x38001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
}
