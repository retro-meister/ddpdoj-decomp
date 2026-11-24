#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern s8 D_00263D60[];
extern s8 D_00263D70[];
extern s8 D_00263D90[];
extern u16 D_0028E8D0;
extern u16 D_0028E8D4;
extern u16 D_0028E918;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E26A0(void) {
    reg_a0_as_s8_p = D_00263D90;
    func_0014E370();
    reg_a0_as_s8_p = D_00263D70;
    reg_d0.w = 0xE;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = D_0028E8D0;
        (*(u8 *)((u8 *)(reg_a5) + (0x1D))) -= reg_d0.b[0];
        reg_d0.h[0] = D_0028E8D4;
        (*(u8 *)((u8 *)(reg_a5) + (0x1C))) -= reg_d0.b[0];
        if ((*(u8 *)((u8 *)(reg_a6) + (0x1F))) != 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = 0U;
            (*(u8 *)((u8 *)(reg_a6) + (0x1D))) |= 0x40;
            (*(u16 *)((u8 *)(reg_a5) + (0x28))) *= (0xFFFF & 0xFFFF);
            (*(u16 *)((u8 *)(reg_a5) + (0x2A))) *= 0xFFFF;
            (*(u16 *)((u8 *)(reg_a5) + (0x2C))) *= 0xFFFF;
        }
        reg_d0.w = (u32) reg_a6;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x24)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x26)));
        reg_tmp.w += reg_d0.w;
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = (u16) reg_tmp.h[0];
        reg_a0_as_s8_p = D_00263D60;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1B))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1A))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}
