#include "common.h"

s32 func_0014E300();                            /* extern */
s32 func_0014E370();                            /* extern */
s32 func_0014E7E0();                            /* extern */
extern s8 D_00262C80[];
extern s8 D_00262C90[];
extern s8 D_0028D9A0;
extern u16 D_0028E918;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C5740(void) {
    reg_a0_as_s8_p = D_00262C90;
    func_0014E370();
    reg_a0_as_s8_p = &D_0028D9A0;
    reg_d0.w = 1;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0_as_s8_p = D_00262C80;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x19))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x18))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}
