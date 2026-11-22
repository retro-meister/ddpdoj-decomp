#include "common.h"

extern u16 D_0026EED0[];
extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern u8 *reg_a0;
extern u8 *reg_a6;

extern void func_001DC160(void);

void func_001DC410(void)
{
    reg_a0 = (u8 *)D_0026EED0;
    reg_a0 += *(u16 *)(reg_a6 + 0x66);

    D_0028E4A2 = *(u16 *)reg_a0;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    D_0028E4A6 = *(u16 *)(reg_a6 + 0x62);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x64);
    reg_d3.h[0] = 0x0A30;
    reg_d1.w += 0xF600FA00u;
    reg_d4.h[0] = *(u16 *)(reg_a6 + 0x7C);
    *(u8 *)&reg_d4 = reg_a6[0x149];

    func_001DC160();
}
