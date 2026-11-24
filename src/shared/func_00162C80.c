#include "common.h"

extern s8 D_0028E408;

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202140();
extern u16 D_002590F0[];
extern u16 D_0025A570[];
extern u16 D_0025A580[];
extern u16 D_0025A5A0[];
extern u16 D_0025A610[];
extern u16 D_0028E8E4;
extern u16 D_0028E910;
extern u16 D_0028E918;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00162C80(void) {
    reg_a0 = (u8 *)(D_0025A5A0);
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = (u8 *)(D_0025A580);
    reg_d0.w = 0xF;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a2 = (u8 *)(D_002590F0);
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x300;
        reg_d1.h[0] += 0x5C0;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x28))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x24))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a5) + (0x26))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d0.h[0] += 0x300;
        reg_d1.h[0] += 0x7FFF + 0x79C1;
        func_00202140();
        if (D_0028E408 != 0) {
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x2E))) = (u8) reg_d1.b[0];
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a2;
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        reg_d1.b[0] = 4;
        if ((s32) D_0028E91C > 1) {
            reg_d1.b[0] = 4;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x30))) = (u8) reg_d1.b[0];
        if (D_0028E910 != 0) {
            (*(u8 *)((u8 *)(reg_a5) + (0x21))) += 1;
            (*(u8 *)((u8 *)(reg_a5) + (0x20))) += 1;
        }
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
        reg_a0 = (u8 *)(D_0025A610);
        (*(u16 *)((u8 *)(reg_a6) + (0x2A))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0x2C))) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = D_0028E8E4;
        (*(u8 *)((u8 *)(reg_a5) + (0x1F))) -= reg_d0.b[0];
        reg_a0 = (u8 *)(D_0025A570);
        reg_d0.h[0] = D_0028E918;
        reg_a0 += reg_d0.h[0];
        (*(s8 *)((u8 *)(reg_a6) + (0x1C))) = *(s8 *)reg_a0;
        (*(s8 *)((u8 *)(reg_a5) + (0x1D))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        (*(s8 *)((u8 *)(reg_a5) + (0x1C))) = *(s8 *)reg_a0;
        reg_a0 += 1;
        if (!((*(u8 *)((u8 *)(reg_a6) + (1))) & 0x20)) {
            (*(s16 *)((u8 *)(reg_a6) + (0x2E))) = 1;
            (*(u8 *)((u8 *)(reg_a6) + (0x30))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
            if ((*(u8 *)((u8 *)(reg_a6) + (0x30))) == 0) {
                reg_a0 = reg_a6 + 0x16;
            } else {
                reg_a0 = reg_a6 + 0x14;
            }
            *(u16 *)reg_a0 = 0xF400;
            (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = 0U;
        }
    }
}
