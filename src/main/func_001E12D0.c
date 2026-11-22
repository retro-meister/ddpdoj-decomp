#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
extern u8 D_00261830[];
extern u8 D_002618B0[];
extern u8 D_002618F0[];
extern u8 D_00263B50[];
extern u8 D_00263B80[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001E12D0(void) {
    reg_a0 = D_00263B80;
    func_0014E370();
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a5) + (0x44))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a5) + (0x46))) = (u16) reg_tmp.h[0];
    reg_a0 = D_00263B50;
    reg_d0.w = 0x12;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_a0 = D_002618B0;
        reg_d0.h[0] = 0x13;
        func_001A3020();
        reg_a0 = D_002618F0;
        reg_d0.h[0] = 0x14;
        func_001A3020();
        reg_a0 = D_00261830;
        reg_d0.h[0] = 0x15;
        func_001A3020();
    }
}
