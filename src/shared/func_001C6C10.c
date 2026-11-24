#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern s8 D_00262E00[];
extern s8 D_00262E10[];
extern s8 D_00262E30[];
extern u16 D_0028E8C8;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001C6C10(void) {
    reg_a0_as_s8_p = D_00262E30;
    func_0014E370();
    reg_a0_as_s8_p = D_00262E10;
    reg_d0.w = 0xB;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 6;
        if ((s32) D_0028E91C > 0x1) {
            reg_d0.b[0] = 2;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x16))) = (u8) reg_d0.b[0];
        reg_d0.h[0] = D_0028E8C8;
        (*(u8 *)((u8 *)(reg_a5) + (0x1C))) -= reg_d0.b[0];
        reg_a0_as_s8_p = D_00262E00;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1B))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1A))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
    }
}
