#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_0016CDD0();
s32 func_00201160();
extern u16 D_0025B440[];
extern u16 D_0025B450[];
extern u16 D_0025B470[];
extern u16 D_0025B610[];
extern u16 D_0028E8A8;
extern u16 D_0028E8C8;
extern u16 D_0028E8CC;
extern u16 D_0028E8DC;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016E010(void) {
    reg_a0 = (u8 *)(D_0025B470);
    func_0014E370();
    reg_a0 = (u8 *)(D_0025B450);
    reg_d0.w = 0xF;
    func_0014E300();
    reg_d0.h[0] = D_0028E8DC;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) -= reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= reg_d0.b[0];
    func_00201160();
    reg_d0.b[0] >>= 1;
    (*(u8 *)((u8 *)(reg_a5) + (0x29))) += reg_d0.b[0];
    reg_d0.h[0] = D_0028E8C8;
    reg_d0.h[0] >>= 4;
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
    if ((D_0028E91C == 1) && ((s32) D_0028E8A8 >= 0x159)) {
        reg_d0.w = 0x30;
        reg_d0.h[0] -= D_0028E8CC;
        reg_d0.h[0] -= 6;
        (*(u8 *)((u8 *)(reg_a5) + (0x29))) = (u8) reg_d0.b[0];
    }
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        if (D_0028E91C == 2) {
            (*(s8 *)((u8 *)(reg_a6) + (0x1E))) = 2;
        }
        func_0016CDD0();
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (6)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
        reg_a6 = (void *) reg_tmp.w;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        (*(u8 *)((u8 *)(reg_a5) + (0x32))) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025B610);
        reg_d1.b[0] += 1;
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x22))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025B440);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = *(s8 *)reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x35))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x34))) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}
