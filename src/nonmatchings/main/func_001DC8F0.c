#include "common.h"

extern void func_0019C570(u32 positionBias, u16 positionLow, u16 *tableEntry, u8 *work);
extern u32 D_0026F040[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC8F0(void)
{
    u8 *work = reg_a6;
    u16 *tableEntry;
    u16 positionLow;
    u32 positionBias = 0xD800E800U;

    reg_a0 = (u8 *)D_0026F040;
    reg_a0 += *(u16 *)(work + 0x126);
    tableEntry = (u16 *)reg_a0;
    reg_d2.h[1] = tableEntry[0];
    reg_d2.h[0] = tableEntry[1];
    reg_d1.h[1] = *(u16 *)(work + 0x122);
    positionLow = *(u16 *)(work + 0x124);
    reg_d1.h[0] = positionLow;
    reg_d4.w = 0x15;
    reg_d3.h[0] = 0x28C0;
    reg_d1.w += positionBias;
    func_0019C570(positionBias, positionLow, tableEntry, work);
}
