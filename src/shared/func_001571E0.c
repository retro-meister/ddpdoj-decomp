#include "common.h"

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern u8 D_00258220[];
extern u8 D_00258240[];
extern u16 D_0028E860;
extern s16 D_0028E8A8_as_s16;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;

void func_001571E0(void) {
    reg_a0 = D_00258240;
    func_0014E370();
    reg_a0 = D_00258220;
    reg_d0.w = 9;
    func_0014E300();
    func_0014E7E0();
    if ((enemy_move_end_requested == 0) && (D_0028E8A8_as_s16 > 0x10) && (D_0028E8A8_as_s16 < 0x36) && (D_0028E860 != 0)) {
        func_0014E290();
    }
}
