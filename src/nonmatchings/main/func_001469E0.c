#include "common.h"

extern u8 D_0029D730[];
extern u8 D_0029D770[];
extern u16 D_0029F264[];
extern u16 D_0029F290[];
extern u8 *reg_a0;
extern u8 *reg_a1;

extern void func_00146A90(u16 value);

void func_001469E0(void)
{
    u16 value = D_0029F290[0];

    reg_a0 = D_0029D770;
    reg_a1 = D_0029D730;
    reg_d1.h[0] = value;
    reg_d2.h[0] = D_0029F264[0];
    func_00146A90(value);
}
