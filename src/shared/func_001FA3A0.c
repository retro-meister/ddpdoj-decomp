#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u8 D_002603F0[];
extern u8 D_00260430[];
extern u8 D_00260530[];
extern u8 D_00265C20[];
extern u8 D_00265C30[];
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001FA3A0(void) {

    reg_a0 = D_00265C30;
    func_0014E370();
    reg_a0 = D_00265C20;
    reg_d0.h[0] = 4;
    func_0014E300();
    reg_tmp.w = 0x30001C00;
    (*(u16 *)((u8 *)(reg_a6) + (2))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = D_0029C068[0];
    (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
    reg_d0.h[0] = 0x12;
    reg_a0 = D_002603F0;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0 = D_00260430;
    func_001A3020();
    reg_d0.h[0] = 0x14;
    reg_a0 = D_00260530;
    func_001A3020();
}
