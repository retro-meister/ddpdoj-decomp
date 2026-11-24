#include "common.h"

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
extern s8 D_0025ACC0[];
extern s8 D_0025ACD0[];
extern s8 D_0025ACF0[];
extern u16 D_0028E878;
extern u16 D_0028E87C;
extern u16 D_0028E880;
extern u16 D_0028E884;
extern u16 D_0028E894;
extern u16 D_0028E8A8;
extern u16 D_0028E8CC;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern s8 *reg_a0_as_s8_p;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001667E0(void) {
    s8 *temp_a1_2;

    reg_a0_as_s8_p = (s8 *)D_0025ACF0;
    func_0014E370();
    reg_a0_as_s8_p = (s8 *)D_0025ACD0;
    reg_d0.w = 0xC;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.b[0] = 5;
        if ((s32) D_0028E91C > 1) {
            reg_d0.b[0] = 2;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2E))) = (u8) reg_d0.b[0];
        reg_d0.h[0] = D_0028E8CC;
        (*(u8 *)((u8 *)(reg_a5) + (0x2A))) -= reg_d0.b[0];
        if (D_0028E91C == 1) {
            if (((s32) D_0028E8A8 >= 0x100) && ((s32) D_0028E8A8 < 0x16C)) {
                if (D_0028E894 != 0) {
                    func_0014E290();
                    return;
                }
                goto block_10;
            }
            if ((s32) D_0028E8A8 >= 0x80) {
                (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x680;
            }
            goto block_10;
        }
block_10:
        reg_a0_as_s8_p = (s8 *)D_0025ACC0;
        reg_d0.h[0] = D_0028E918;
        reg_a0_as_s8_p = &reg_a0_as_s8_p[reg_d0.h[0]];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = (s8) *reg_a0_as_s8_p;
        (*(s8 *)((u8 *)(reg_a5) + (0x1B))) = (s8) *reg_a0_as_s8_p;
        reg_a0_as_s8_p += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1A))) = (s8) *reg_a0_as_s8_p;
        temp_a1_2 = (s8 *)(reg_a0_as_s8_p + 1);
        reg_a0_as_s8_p = temp_a1_2;
        if (D_0028E91C == 4) {
            (*(s16 *)((u8 *)(reg_a6) + (0x18))) = 0x880;
            if ((s32) D_0028E8A8 < 0x230) {
                if (D_0028E884 != 0) {
                    func_0014E290();
                }
            } else if ((s32) D_0028E8A8 < 0x250) {
                if (D_0028E880 != 0) {
                    func_0014E290();
                }
            } else if ((s32) D_0028E8A8 < 0x290) {
                if (D_0028E87C != 0) {
                    func_0014E290();
                }
            } else if ((D_0028E878 != 0) && ((s32) D_0028E8A8 > 0x240)) {
                func_0014E290();
            }
        }
    }
}
