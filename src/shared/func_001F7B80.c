#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern s16 D_002655E0[];
extern s16 D_00265600[];
extern s16 D_0028E878;
extern s16 D_0028E880;
extern u16 D_0028E8A8;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F7B80(void) {
    reg_a0 = (u8 *)(D_00265600);
    func_0014E370();
    reg_a0 = (u8 *)(D_002655E0);
    reg_d0.w = 9;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested != 0) return;
    if (D_0028E8A8 != 0x299) goto next_1;
    *(s8 *)(reg_a6 + 0x1D) = 0x40;
    *(s8 *)(reg_a5 + 0x16) = 1;
next_1:
    *(u8 *)(reg_a6 + 0x1C) = *(u8 *)(reg_a5 + 0x19);
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    D_0028E880 = 1;
    reg_a0 = (u8 *)(&D_0028E880);
    if ((s32) D_0028E8A8 < 0x280) goto next_2;
    reg_a0 = (u8 *)(&D_0028E878);
    *(s16 *)(reg_a5 + 0x1A) = 0x202;
next_2:
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a5 + 0x26) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x28) = reg_tmp.h[0];
    *(s16 *)reg_a0 = 1;
}
