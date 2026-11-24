#include "common.h"

extern u8 D_002586F0[];
extern u8 D_00258720[];
extern u8 *reg_a0;
extern s8 enemy_move_end_requested;

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_0014E7E0(void);

void func_00159C60(void)
{
    reg_a0 = D_00258720;
    func_0014E370();

    reg_a0 = D_002586F0;
    reg_d0.w = 0x11;
    func_0014E300();

    func_0014E7E0();
    if (enemy_move_end_requested != 0) {
        return;
    }
}
