#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
s32 func_001BC8B0();
s32 func_001BCA10();
extern u8 D_002601B0[];
extern u8 D_002601F0[];
extern u8 D_00260230[];
extern u8 D_00262700[];
extern u8 D_00262720[];
extern s16 D_0028E890;
extern s16 D_0028E894;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001BCF30() {
    reg_a0 = D_00262720;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = D_00262700;
    reg_d0.h[0] = 9;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) += 0xA40;
        func_001BC8B0();
        func_001BCA10();
        D_0028E890 = 0;
        D_0028E894 = 1;
        reg_d0.h[0] = 0x10;
        reg_a0 = D_002601B0;
        func_001A3020();
        reg_d0.h[0] = 0x11;
        reg_a0 = D_002601F0;
        func_001A3020();
        reg_d0.h[0] = 0xF;
        reg_a0 = D_00260230;
        func_001A3020();
    }
}
