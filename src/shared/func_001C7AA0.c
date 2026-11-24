#include "common.h"

extern u32 reg_a0_as_u32;
extern s8 enemy_move_end_requested;
extern u32 D_00262ED0[];
extern u32 D_00262EE0[];

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_0014E7E0(void);

void func_001C7AA0(void)
{
    reg_a0_as_u32 = (u32)D_00262EE0;
    func_0014E370();

    reg_a0_as_u32 = (u32)D_00262ED0;
    reg_d0.w = 5;
    func_0014E300();
    func_0014E7E0();

    if (enemy_move_end_requested) {
        return;
    }
}
