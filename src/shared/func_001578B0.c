#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_002012F0();
extern u8 D_00258380[];
extern u8 D_002583A0[];
extern u16 D_0028E91C;
extern u16 D_0029C068[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001578B0(void) {
    reg_a0 = D_002583A0;
    func_0014E370();
    reg_a0 = D_00258380;
    reg_d0.w = 9;
    func_0014E300();
    if (D_0028E91C == 4) {
        (*(s8 *)((u8 *)(reg_a5) + (0x19))) = 0xF;
        (*(s8 *)((u8 *)(reg_a5) + (0x18))) = 0x10;
        reg_tmp.w = 0x74001C00;
        (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
        reg_d0.h[0] = D_0029C068[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
        goto block_3;
    }
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
block_3:
        func_002012F0();
        reg_d0.h[0] += 0x1C00;
        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
        (*(s16 *)((u8 *)(reg_a6) + (0x1A))) = 0x2820;
    }
}
