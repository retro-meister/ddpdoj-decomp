#include "common.h"

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_0014E7E0(void);

extern u32 D_00257D70[];
extern u32 D_00257D90[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00155EC0(void)
{
    reg_a0 = (u8 *)D_00257D90;
    func_0014E370();

    reg_a0 = (u8 *)D_00257D70;
    reg_d0.w = 0xD;
    func_0014E300();
    func_0014E7E0();

    if (enemy_move_end_requested == 0) {
        *(u16 *)(reg_a6 + 4) -= 0x280;
        *(u16 *)(reg_a6 + 2) -= 0x80;
    }
}
