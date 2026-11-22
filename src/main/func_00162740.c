#include "common.h"

extern u8 D_0025A530[];
extern u8 D_0025A550[];
extern u8 D_002623B0[];
extern u8 *reg_a0;
extern u8 *reg_a6;

extern void func_0014E300(void);
extern void func_0014E370(void);
extern void func_001A3020(void);

void func_00162740(void)
{
    reg_a0 = D_0025A550;
    func_0014E370();

    reg_a0 = D_0025A530;
    reg_d0.w = 8;
    func_0014E300();

    reg_tmp.w = 0x38001C00;
    *(u16 *)(reg_a6 + 2) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 4) = reg_tmp.h[0];

    reg_a0 = D_002623B0;
    reg_d0.h[0] = 0x16;
    func_001A3020();
}
