#include "common.h"

extern u8 *reg_a0;
extern u16 D_0028E1A0;
extern u8 D_002AF860[];

extern void func_0019BC10(void);
extern void func_0019BD40(void);

void func_0019C840(void)
{
    u8 *savedA0;
    u32 savedD4;
    u32 savedD7;

    savedD4 = reg_d4.w;
    savedD7 = reg_d7.w;
    savedA0 = reg_a0;
    func_0019BC10();

    reg_a0 = D_002AF860;
    reg_a0 += D_0028E1A0;
    func_0019BD40();

    reg_d4.w = savedD4;
    reg_d7.w = savedD7;
    reg_a0 = savedA0;
    D_0028E1A0 += 0xC;
}
