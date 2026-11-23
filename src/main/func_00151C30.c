#include "common.h"

extern s8 D_0028E408;

s32 func_0014E290();
s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00150740();
s32 func_00150790();
s32 func_00202180();
s32 func_002036F0();
extern u16 D_002578D0[];
extern u16 D_00257950[];
extern u16 D_00257AD0[];
extern u16 D_00257AF0[];
extern u16 D_0028E878;
extern u16 D_0028E87C;
extern u16 D_0028E880;
extern u16 D_0028E884;
extern u16 D_0028E8CC;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00151C30(void) {
    func_00150740();
    if ((D_0028E408 == 0) && (func_00150790(), (D_0028E408 == 0)) && (reg_a0 = (u8 *)D_00257AF0, func_0014E370(), reg_a0 = (u8 *)D_00257AD0, reg_d0.h[0] = 0xA, func_0014E300(), (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x2B))), func_0014E7E0(), (enemy_move_end_requested == 0))) {
        reg_a0 = (u8 *)(D_002578D0);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        reg_d1.h[0] &= 0x3E;
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)(D_00257950);
        (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
        (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        if ((*(u8 *)((u8 *)(reg_a5) + (0xD))) & 0x20) {
            func_002036F0();
        }
        reg_d1.w = 0x20;
        func_00202180();
        (*(u8 *)((u8 *)(reg_a5) + (0x22))) = (u8) reg_d1.b[0];
        reg_d0.h[0] = D_0028E8CC;
        reg_d0.b[0] -= 8;
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= reg_d0.b[0];
        if (D_0028E91C == 4) {
            if (D_0028E884 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E880 != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E87C != 0) {
                func_0014E290();
                return;
            }
            if (D_0028E878 != 0) {
                func_0014E290();
            }
        }
    }
}
