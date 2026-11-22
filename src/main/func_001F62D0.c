#include "common.h"

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_0014E7E0(void);

extern u8 D_00265110[];
extern u8 D_00265130[];
extern s16 D_00299768[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F62D0(void)
{
    reg_a0 = D_00265130;
    func_0014E370();

    reg_a0 = D_00265110;
    reg_d0.w = 8;
    func_0014E300();
    func_0014E7E0();

    if (enemy_move_end_requested == 0) {
        reg_a6[0x1C] = reg_a5[0x19];
        D_00299768[0] = 1;
    }
}
