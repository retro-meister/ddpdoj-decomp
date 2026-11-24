#include "common.h"

extern s8 D_0028E408;

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202180();
extern u16 D_0025AEF0[];
extern u16 D_0025AF00[];
extern u16 D_0025AF20[];
extern u16 D_0025AF40[];
extern u16 D_0025AFC0[];
extern u16 D_0028E88C;
extern u16 D_0028E8C8;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00168120(void) {
    if ((D_0028E91C == 3) && (D_0028E88C != 0)) {
        func_0014E290();
        return;
    }
    reg_a0 = (u8 *)(D_0025AF20);
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025AF00);
    reg_d0.w = 8;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        func_00202180();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x26))) = (u8) reg_d1.b[0];
        reg_a0 = (u8 *)(D_0025AF40);
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_0025AFC0);
        (*(u16 *)((u8 *)(reg_a5) + (0x22))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = D_0028E8C8;
        reg_d0.b[0] >>= 1;
        (*(u8 *)((u8 *)(reg_a5) + (0x1B))) -= reg_d0.b[0];
        reg_d0.h[0] = D_0028E8C8;
        (*(u8 *)((u8 *)(reg_a5) + (0x1A))) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025AEF0);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a5) + (0x19))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x18))) = *(s8 *)reg_a0;
        reg_a0 += 1;
    }
}
