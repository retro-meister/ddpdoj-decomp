#include "common.h"


s32 func_0014E300();
s32 func_0014E370();
s32 func_0014E7E0();
s32 func_001A3020();
extern u8 D_00261870[];
extern u8 D_002637B0[];
extern u8 D_0028D9AC;
extern u16 D_0028E8A8;
extern u16 D_0029C068[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DE200(void) {

    reg_a0 = D_002637B0;
    func_0014E370();
    reg_a0 = &D_0028D9AC;
    reg_d0.w = 1;
    func_0014E300();
    func_0014E7E0();
    if (enemy_move_end_requested == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
        (*(u16 *)((u8 *)(reg_a6) + (4))) += 0x1600;
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) += 0x7FFF + 0x7801;
        reg_d0.h[0] = D_0029C068[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x24))) -= reg_d0.h[0];
        reg_a0 = D_00261870;
        reg_d0.h[0] = 0x16;
        if (D_0028E8A8 == 0x19) {
            reg_d0.h[0] = 0x14;
        }
        func_001A3020();
    }
}
