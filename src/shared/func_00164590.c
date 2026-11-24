#include "common.h"

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
s32 func_0014E7E0();                            /* extern */
extern s32 D_0025A680[];
extern s32 D_0028C9E8;
extern s8 enemy_move_end_requested;
extern s32 *reg_a0_as_s32_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00164590(void) {
    reg_a0_as_s32_p = D_0025A680;
    func_0014E370();
    reg_a0_as_s32_p = &D_0028C9E8;
    reg_d0.w = 2;
    func_0014E300();
    func_0014E7E0();
    if ((enemy_move_end_requested == 0) && ((*(u8 *)((u8 *)(reg_a6) + (0x1F))) != 0)) {
        (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = 0U;
        (*(s16 *)((u8 *)(reg_a5) + (0x1A))) = 0x40;
    }
}
