#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern s8 D_0025A288[];
extern s8 D_0025A2A0[];
extern s8 D_0025A2C0[];
extern u16 D_0028E8A8;
extern u16 D_0028E910;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015FC80(void) {
    reg_a0_as_s8_p = D_0025A2C0;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0_as_s8_p;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0_as_s8_p = D_0025A2A0;
    reg_d0.w = 0xE;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        if (D_0028E910 == 0) {
            reg_d0.b[0] = 0x18;
            reg_d1.b[0] = 0x10;
            if ((s32) D_0028E91C > 0x3) {
                goto block_4;
            }
        } else {
block_4:
            reg_d0.b[0] = 0x10;
            reg_d1.b[0] = 0x10;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x31))) = (u8) reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a5) + (0x30))) = (u8) reg_d1.b[0];
        reg_a0_as_s8_p = D_0025A288;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        if (D_0028E91C == 4) {
            (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x1000;
            if ((s32) D_0028E8A8 > 0x2E0) {
                (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0xE80;
            }
        }
    }
}
