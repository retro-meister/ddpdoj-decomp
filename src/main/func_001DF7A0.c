#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
extern u8 D_002616F0[];
extern u8 D_002617B0[];
extern u8 D_002617F0[];
extern u8 D_00263890[];
extern u8 D_002638B0[];
extern s16 D_0028E88C;
extern s16 D_0028E894;
extern u16 D_0028E8DC;
extern s16 D_00299768[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001DF7A0(void) {

    reg_a0 = D_002638B0;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = D_00263890;
    reg_d0.w = 0xF;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = D_0028E8DC;
        (*(u8 *)((u8 *)(reg_a5) + (0x1C))) -= reg_d0.b[0];
        D_0028E894 = 1;
        reg_a0 = D_002616F0;
        reg_d0.h[0] = 0xF;
        D_0028E88C = 1;
        D_00299768[0] = 1;
        func_001A3020();
        reg_a0 = D_002617B0;
        reg_d0.h[0] = 0x10;
        func_001A3020();
        reg_a0 = D_002617F0;
        reg_d0.h[0] = 0x11;
        func_001A3020();
    }
}
