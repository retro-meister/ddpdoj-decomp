#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_002011A0();
extern u8 D_002654F0[];
extern u8 D_00265510[];
extern u16 D_0028E8A8;
extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F7650(void) {
    reg_a0 = D_00265510;
    func_0014E370();
    reg_a0 = D_002654F0;
    reg_d0.w = 8;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        if (D_0028E8A8 == 0x2B6) {
            (*(s8 *)((u8 *)(reg_a6) + (0x1D))) = 0x40;
            (*(s8 *)((u8 *)(reg_a5) + (0x16))) = 1;
        }
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        (*(u8 *)((u8 *)(reg_a6) + (0x1C))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x19)));
        func_002011A0();
        (*(u8 *)((u8 *)(reg_a5) + (0x21))) = (u8) reg_d0.b[0];
        func_002011A0();
        (*(u8 *)((u8 *)(reg_a5) + (0x20))) = (u8) reg_d0.b[0];
    }
}
