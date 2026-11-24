#include "common.h"

extern void func_0019C570(void);
extern u8 D_0026F080[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC960(void) {
    u8 *work = reg_a6;
    u16 *tableEntry;

    reg_a0 = D_0026F080;
    reg_a0 += *(u16 *)(work + 0x128);
    tableEntry = (u16 *)reg_a0;
    reg_d2.h[1] = tableEntry[0];
    reg_d2.h[0] = tableEntry[1];
    reg_d1.h[1] = *(u16 *)(work + 0x122);
    reg_d1.h[0] = *(u16 *)(work + 0x124);
    reg_d1.w += 0xDC00EE00U;
    reg_d3.h[0] = 0x2490;
    reg_d4.w = 0x15;
    func_0019C570();
}
