#include "common.h"

s32 func_0014E370();                            /* extern */
extern s32 D_00258980[];
extern s32 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015AE10(void) {
    reg_a0 = D_00258980;
    func_0014E370();
    reg_tmp.w = 0x38001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a5) + (0x16))) = 4;
    (*(s16 *)((u8 *)(reg_a5) + (0x18))) = 0x303;
}
