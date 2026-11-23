#include "common.h"

s32 func_0014E290();
s32 func_0014EA50();
s32 func_0019BF00();
extern u16 D_00263D20[];
extern Reg32 D_0028E484;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001E24F0(void) {
    func_0014EA50();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        D_0028E484.w = 0;
        D_0028E484.h[0] = 0x2000;
        reg_tmp.w = 0;
        reg_d0.h[0] += 0x3800;
        reg_tmp.h[0] = reg_d0.h[0];
        reg_tmp.w += D_0028E484.w;
        reg_d0.h[0] += 0x2000;
        if (reg_tmp.h[1] != 0) {
            if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
                func_0014E290();
                return;
            }
            goto block_5;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_5:
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
            reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
            reg_a0 = (u8 *)(D_00263D20);
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) -= 4;
            if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1A))) < 0) {
                (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0x3CU;
            }
        }
        func_0019BF00();
    }
}
