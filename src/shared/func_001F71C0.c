#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern s16 D_00265280[];
extern s16 D_00265290[];
extern s16 D_0028E87C_as_s16;
extern s16 D_0028E884_as_s16;
extern u16 D_0028E8A8;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F71C0(void) {
    reg_a0 = (u8 *)(D_00265290);
    func_0014E370();
    reg_a0 = (u8 *)(D_00265280);
    reg_d0.w = 6;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested != 0) return;
    if (D_0028E8A8 != 0x1F3) goto next_1;
    *(s8 *)(reg_a6 + 0x1D) = 0x40;
    *(s8 *)(reg_a5 + 0x16) = 1;
next_1:
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x19);
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    reg_a0 = (u8 *)(&D_0028E884_as_s16);
    if ((s32) D_0028E8A8 < 0x260) goto next_2;
    reg_a0 = (u8 *)(&D_0028E87C_as_s16);
next_2:
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x20) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x22) = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}
