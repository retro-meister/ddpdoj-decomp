#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_001A3020();
extern u8 D_00260470[];
extern u8 D_002604B0[];
extern u8 D_002604F0[];
extern u8 D_002661C8[];
extern u8 D_002661E0[];
extern s16 D_0028E884;
extern s16 D_0028E888;
extern s16 D_00299768[];
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001FD760(void) {
    reg_a0 = (u8 *)D_002661E0;
    func_0014E370();
    reg_a0 = (u8 *)D_002661C8;
    reg_d0.h[0] = 5;
    func_0014E300();
    reg_tmp.w = 0xF4001C00;
    *(u16 *)(reg_a6 + 2) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 4) = reg_tmp.h[0];
    reg_d0.h[0] = D_0029C068[0];
    *(u16 *)(reg_a6 + 4) -= reg_d0.h[0];
    D_00299768[0] = 1;
    D_0028E888 = 1;
    D_0028E884 = 1;
    reg_d0.h[0] = 0x12;
    reg_a0 = (u8 *)D_00260470;
    func_001A3020();
    reg_d0.h[0] = 0x13;
    reg_a0 = (u8 *)D_002604B0;
    func_001A3020();
    reg_d0.h[0] = 0x14;
    reg_a0 = (u8 *)D_002604F0;
    func_001A3020();
}
