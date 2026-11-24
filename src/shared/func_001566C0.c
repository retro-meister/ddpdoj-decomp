#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_002011A0();
extern u8 D_00258100[];
extern u8 D_00258130[];
extern s16 D_0028E88C_as_s16;
extern s16 D_0028E890_as_s16;
extern s16 D_0028E894_as_s16;
extern u16 D_0028E8A8;
extern s16 D_00299768[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001566C0(void) {
    reg_a0 = D_00258130;
    func_0014E370();
    reg_a0 = D_00258100;
    reg_d0.w = 0x14;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        D_00299768[0] = 1;
        reg_d0.h[0] = D_0028E8A8;
        (*(u16 *)((u8 *)(reg_a5) + (0x3A))) = (u16) reg_d0.h[0];
        if (reg_d0.h[0] == 0x48) {
            D_0028E894_as_s16 = 1;
            D_0028E890_as_s16 = 1;
            D_0028E88C_as_s16 = 1;
            (*(u16 *)((u8 *)(reg_a6) + (2))) += 0x900;
            (*(u16 *)((u8 *)(reg_a6) + (4))) -= 0x100;
        }
        if (reg_d0.h[0] == 0x8D) {
            D_0028E890_as_s16 = 1;
            (*(u16 *)((u8 *)(reg_a6) + (2))) += 0x900;
            (*(u16 *)((u8 *)(reg_a6) + (4))) -= 0x100;
        }
        if (reg_d0.h[0] == 0xAC) {
            D_0028E88C_as_s16 = 1;
            (*(u16 *)((u8 *)(reg_a6) + (2))) += 0x900;
            (*(u16 *)((u8 *)(reg_a6) + (4))) -= 0x100;
        }
        (*(u8 *)((u8 *)(reg_a5) + (0x39))) = 0xFE;
        func_002011A0();
        if ((s8) reg_d0.b[0] < 0) {
            (*(s8 *)((u8 *)(reg_a5) + (0x39))) = 2;
        }
    }
}
