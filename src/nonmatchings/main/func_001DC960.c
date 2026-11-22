#include "common.h"

extern void func_0019C570(u32, u16, u8 *, u8 *);
extern u8 D_0026F080[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC960(void)
{
    u8 *work = reg_a6;
    u8 *tableEntry;
    u16 position;
    u32 positionOffset = 0xDC00EE00U;

    reg_a0 = D_0026F080;
    reg_a0 += *(u16 *)(work + 0x128);
    tableEntry = reg_a0;
    reg_d2.h[1] = *(u16 *)tableEntry;
    reg_d2.h[0] = *(u16 *)(tableEntry + 2);
    reg_d1.h[1] = *(u16 *)(work + 0x122);
    position = *(u16 *)(work + 0x124);
    reg_d1.h[0] = position;
    reg_d4.w = 0x15;
    reg_d3.h[0] = 0x2490;
    reg_d1.w += positionOffset;
    func_0019C570(positionOffset, position, tableEntry, work);
}
