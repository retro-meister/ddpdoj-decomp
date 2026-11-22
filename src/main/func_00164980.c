#include "common.h"

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_0014E7E0(void);

extern u32 D_0025A6A0[];
extern u32 D_0028C9F0;
extern s16 D_0028E8A8;
extern u16 D_0028E91C;
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00164980(void)
{
    reg_a0 = (u8 *)D_0025A6A0;
    func_0014E370();

    reg_a0 = (u8 *)&D_0028C9F0;
    reg_d0.w = 1;
    func_0014E300();
    func_0014E7E0();

    if (enemy_move_end_requested == 0 && D_0028E91C == 1 && D_0028E8A8 < 4) {
        *(u16 *)reg_a6 = 0x8000;
    }
}
