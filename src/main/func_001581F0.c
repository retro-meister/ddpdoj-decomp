#include "common.h"

s32 func_0014E000();
s32 func_0014E050();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern u8 D_00258460[];
extern u8 D_00258490[];
extern u16 D_0028E8A8;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001581F0(void) {
    reg_a0 = (u8 *)D_00258490;
    func_0014E370();
    reg_a0 = (u8 *)D_00258460;
    reg_d0.w = 0x10;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        if (D_0028E8A8 == 0x168) {
            reg_d0.w = 0x18;
            func_0014E000();
            *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 0x18) = (u16) *(u16 *)(reg_a6 + 4);
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x16);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x18);
            reg_tmp.w += 0x10000400;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_tmp.h[0];
            *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)(reg_a6 + 0x1A);
            *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a6 + 0x1C);
        } else {
            reg_d0.w = 0x17;
            reg_d1.h[0] = 0x20;
            func_0014E050();
            *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)(reg_a6 + 2);
            *(u16 *)(reg_a0 + 0x18) = (u16) *(u16 *)(reg_a6 + 4);
            reg_tmp.h[1] = *(u16 *)(reg_a0 + 0x16);
            reg_tmp.h[0] = *(u16 *)(reg_a0 + 0x18);
            reg_tmp.w += 0x10000400;
            *(u16 *)(reg_a0 + 0x16) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x18) = (u16) reg_tmp.h[0];
            *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)(reg_a6 + 0x1A);
            *(u16 *)(reg_a0 + 0x1C) = *(u16 *)(reg_a6 + 0x1C);
        }
    }
}
