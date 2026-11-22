#include "common.h"

extern u8 D_0029D710[];
extern u8 D_0029D750[];
extern u16 D_0029F1F4[];
extern u16 D_0029F220[];

extern u8 *reg_a0;
extern u8 *reg_a1;

extern void func_00146A90(u16 sourceValue);

void func_00146A50(void)
{
    u16 sourceValue = D_0029F220[0];

    reg_a0 = D_0029D750;
    reg_a1 = D_0029D710;
    reg_d1.h[0] = sourceValue;
    reg_d2.h[0] = D_0029F1F4[0];
    func_00146A90(sourceValue);
}
