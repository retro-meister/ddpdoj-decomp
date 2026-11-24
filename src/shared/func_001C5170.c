#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern s8 D_00262C40[];
extern s8 D_00262C50[];
extern s8 D_00262C60[];
extern u16 D_0028E910;
extern u16 D_0028E918;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C5170(void) {
    reg_a0_as_s8_p = D_00262C60;
    func_0014E370();
    reg_a0_as_s8_p = D_00262C50;
    reg_d0.w = 5;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0_as_s8_p = D_00262C40;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1B))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1A))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        if (D_0028E910 != 0) {
            (*(s16 *)((u8 *)(reg_a5) + (0x1E))) = 0;
        }
    }
}
