#include "common.h"

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_0014E7E0(void);

extern u8 D_002580C0[];
extern u8 D_002580E0[];
extern s8 enemy_move_end_requested;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00156620(void)
{
    reg_a0 = D_002580E0;
    func_0014E370();

    reg_a0 = D_002580C0;
    reg_d0.w = 0xD;
    func_0014E300();
    func_0014E7E0();

    if (enemy_move_end_requested == 0) {
        *(u16 *)(reg_a6 + 4) -= 0x400;
        *(u16 *)(reg_a6 + 2) -= 0x600;
    }
}
