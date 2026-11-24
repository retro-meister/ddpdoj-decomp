#include "common.h"

s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
s32 func_0020ED00();
extern u8 D_00261AF0[];
extern u8 D_00265AB0[];
extern u8 D_00265AD0[];
extern s16 D_0028E88C;
extern s16 D_00299768[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;

void func_001F96D0(void) {
    reg_a0 = D_00265AD0;
    func_0014E370();
    reg_a0 = D_00265AB0;
    reg_d0.h[0] = 0xF;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d0.h[0] = 0x10;
        D_00299768[0] = 1;
        D_0028E88C = 1;
        reg_a0 = D_00261AF0;
        func_001A3020();
        func_0020ED00();
    }
}
