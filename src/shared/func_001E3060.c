#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_002010A0();
s32 func_002011A0();
s32 func_002012F0();
extern u8 D_00263E10[];
extern u8 D_00263E40[];
extern u16 D_0028E8D4;
extern u16 D_0029C068[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E3060(void) {
    u16 temp_a0;

    reg_a0 = D_00263E40;
    func_0014E370();
    reg_a0 = D_00263E10;
    reg_d0.w = 0x13;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] = 0x1C00;
        reg_d7.h[0] = temp_a0;
        reg_d0.h[0] -= D_0029C068[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (u16) reg_d0.h[0];
        reg_d0.h[0] += 0x1C00;
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_d0.h[0];
        func_002011A0();
        if ((s8) reg_d0.b[0] < 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x2A))) *= 0xFFFF;
        }
        func_002010A0();
        reg_d0.h[0] += 7;
        reg_d0.h[0] += reg_d0.h[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= reg_d0.b[0];
        reg_d0.h[0] = D_0028E8D4;
        (*(u8 *)((u8 *)(reg_a5) + (0x1C))) -= reg_d0.b[0];
    }
}
