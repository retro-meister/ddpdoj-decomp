#include "common.h"

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern u8 D_00257C10[];
extern u8 D_0028C9B0;
extern u16 D_0028E858;
extern u16 D_0028E85C;
extern s16 D_0028E860_as_s16;
extern u16 D_0028E8A8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00153CB0(void) {
    reg_a0 = (u8 *)D_00257C10;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x44) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = (u16) reg_tmp.h[0];
    reg_a0 = &D_0028C9B0;
    reg_d0.w = 3;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested != 0) return;
    *(s8 *)(reg_a6 + 0x5D) = 0x10;
    *(s8 *)(reg_a6 + 0x5F) = 0xF;
    *(s8 *)(reg_a6 + 0x7D) = 0x10;
    *(s8 *)(reg_a6 + 0x7F) = 0xF;
    *(s8 *)(reg_a6 + 0x9D) = 0x10;
    *(s8 *)(reg_a6 + 0x9F) = 0xF;
    *(s8 *)(reg_a6 + 0xBD) = 0x10;
    *(s8 *)(reg_a6 + 0xBF) = 0xF;
    if (D_0028E8A8 != 0x26) goto next_1;
    if (D_0028E85C == 0) goto block_f3;
    func_0014E290();
    return;
next_1:
    if (D_0028E8A8 != 0x1B) goto next_2;
    if (D_0028E858 == 0) goto block_f2;
    func_0014E290();
    return;
next_2:
    D_0028E858 = 1;
    D_0028E85C = 1;
    D_0028E860_as_s16 = 1;
    return;
block_f2:
    *(s8 *)(reg_a6 + 0xD8) = 1;
    D_0028E85C = 1;
    D_0028E860_as_s16 = 1;
    return;
block_f3:
    D_0028E860_as_s16 = 1;
}
