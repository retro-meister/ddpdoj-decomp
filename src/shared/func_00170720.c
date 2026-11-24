#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0018DCE0();
s32 func_001A3020();
extern u16 D_0025B820[];
extern u16 D_0025B830[];
extern u8 D_0025B840[];
extern u8 D_0025B850[];
extern u8 D_00261C30[];
extern u8 D_00261CF0[];
extern u16 D_0028E918;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_00170720(void) {
    reg_a0 = D_0025B850;
    func_0014E370();
    reg_a0 = D_0025B840;
    reg_d0.w = 5;
    func_0014E300();
    reg_tmp.w = 0x40001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    func_0018DCE0();
    reg_a0 = D_00261CF0;
    reg_d6.h[0] = D_0028E918;
    reg_a1 = (u8 *)(D_0025B820);
    reg_d0.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
    (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) reg_d0.b[0];
    func_001A3020();
    reg_a0 = D_00261C30;
    reg_a1 = (u8 *)(D_0025B830);
    reg_d0.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
    func_001A3020();
}
