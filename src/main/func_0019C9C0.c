#include "common.h"

extern void func_0019BC10(void);
extern void func_0019BD40(void);
extern u16 D_0028E194;
extern u8 D_002AB240[];
extern u8 *reg_a0;

void func_0019C9C0(void)
{
    u8 *savedAddress;
    u32 savedD4;
    u32 savedD7;

    savedD7 = ((volatile Reg32 *)&reg_d7)->w;
    savedAddress = *(u8 *volatile *)&reg_a0;
    savedD4 = ((volatile Reg32 *)&reg_d4)->w;

    func_0019BC10();
    reg_a0 = D_002AB240;
    reg_a0 += D_0028E194;
    func_0019BD40();

    reg_d4.w = savedD4;
    reg_d7.w = savedD7;
    reg_a0 = savedAddress;
    D_0028E194 += 0xC;
}
