#include "common.h"

extern u8 *reg_a0;
extern s8 D_0028E408;

extern void func_0016A8F0(void);
extern void func_0016C770(void);

void func_0016A9B0(void)
{
    func_0016A8F0();
    do {
        if (*(u16 *)reg_a0 == 0) {
            func_0016C770();
            return;
        }
        reg_a0 += 0x40;
    } while ((s16)(--reg_d2.h[0]) >= 0);

    reg_d2.w = 0;
    D_0028E408 = 1;
    reg_d2.h[0] -= 1;
}
