#include "common.h"

extern u8 D_00258080[];
extern u8 D_002580A0[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a6;

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_0014E7E0(void);

void func_001565B0(void)
{
    reg_a0 = D_002580A0;
    func_0014E370();

    reg_a0 = D_00258080;
    reg_d0.w = 0xD;
    func_0014E300();
    func_0014E7E0();

    if (enemy_move_end_requested == 0) {
        ((u16 *)reg_a6)[1] -= 0x400;
    }
}
