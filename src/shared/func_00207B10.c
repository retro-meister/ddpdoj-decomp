#include "common.h"

extern u8 D_00267BE0[];
extern u8 D_0028E380;
extern u8 *reg_a0;

extern void func_002092F0(void);

void func_00207B10(void)
{
    u8 selection;
    u8 *entry;

    selection = D_0028E380;
    reg_d0.w = 0;
    reg_a0 = D_00267BE0;
    reg_d0.b[0] = selection;
    reg_d0.h[0] <<= 5;
    entry = reg_a0 + reg_d0.h[0];
    reg_d0.h[0] = 7;
    reg_d1.h[0] = 0x18;
    reg_d2.h[0] = reg_d7.h[0];
    reg_a0 = entry;
    func_002092F0();
}
