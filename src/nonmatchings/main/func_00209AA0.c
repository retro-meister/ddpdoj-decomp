#include "common.h"

extern u8 D_00268710[];
extern u8 D_0028E390;
extern u8 *reg_a0;
extern void func_002092F0(void);

void func_00209AA0(void)
{
    u16 entryIndex;

    reg_d0.w = 0;
    reg_a0 = D_00268710;
    reg_d1.h[0] = 0x18;
    reg_d0.b[0] = D_0028E390;
    entryIndex = reg_d0.h[0];
    reg_d2.h[0] = reg_d7.h[0];
    reg_d0.h[0] = entryIndex << 5;
    reg_a0 += reg_d0.h[0];
    reg_d0.h[0] = 7;
    func_002092F0();
}
