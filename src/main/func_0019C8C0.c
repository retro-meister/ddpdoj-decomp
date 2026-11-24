#include "common.h"
#pragma opt_propagation off

extern void func_0019BC10(void);
extern void func_0019BD40(void);
extern u16 D_0028E19C;
extern u8 D_002AE100[];
extern u8 *reg_a0;

void func_0019C8C0(void)
{
    u8 *savedAddress;
    u32 savedD4;
    u32 savedD7;

    savedD4 = reg_d4.w;
    savedD7 = reg_d7.w;
    savedAddress = reg_a0;
    func_0019BC10();

    reg_a0 = D_002AE100;
    reg_a0 += D_0028E19C;
    func_0019BD40();

    reg_d4.w = savedD4;
    reg_d7.w = savedD7;
    reg_a0 = savedAddress;
    D_0028E19C += 0xC;
}
