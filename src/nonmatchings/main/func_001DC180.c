#include "common.h"

extern void func_001DC160(void);
extern u32 D_0026EE10[];
extern u16 D_0028E4A2;
extern u16 D_0028E4A6;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC180(void)
{
    u8 *object = reg_a6;
    u16 *entry;

    reg_a0 = (u8 *)D_0026EE10;
    reg_a0 += *(u16 *)(object + 0x26);
    entry = (u16 *)reg_a0;
    D_0028E4A2 = entry[0];
    reg_d2.h[0] = entry[1];
    D_0028E4A6 = *(u16 *)(object + 0x22);
    reg_d1.h[0] = *(u16 *)(object + 0x24);
    reg_d3.h[0] = 0x1290;
    reg_d1.w += 0xEE00EE00u;
    reg_d4.h[0] = *(u16 *)(object + 0x3C);
    *(u8 *)&reg_d4 = object[0x147];
    func_001DC160();
}
