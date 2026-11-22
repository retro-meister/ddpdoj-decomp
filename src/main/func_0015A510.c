#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_00202180();
extern u8 D_002587C0[];
extern u8 D_002587E0[];
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0015A510(void) {
    reg_a0 = D_002587E0;
    func_0014E370();
    reg_a0 = D_002587C0;
    reg_d0.w = 0xA;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
        func_00202180();
        (*(u8 *)((u8 *)(reg_a5) + (0x23))) = (u8) reg_d1.b[0];
        if (D_0028E91C == 4) {
            (*(u16 *)((u8 *)(reg_a6) + (0))) = 0xA200;
            (*(s8 *)((u8 *)(reg_a5) + (0x19))) = 0xF;
            (*(s8 *)((u8 *)(reg_a5) + (0x18))) = 0x10;
        }
    }
}
