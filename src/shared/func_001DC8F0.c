#include "common.h"

extern void func_0019C570(void);
extern u32 D_0026F040[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001DC8F0(void) {
    u8 *work = reg_a6;
    u16 *tableEntry;

    reg_a0 = (u8 *)D_0026F040;
    reg_a0 += *(u16 *)(work + 0x126);
    tableEntry = (u16 *)reg_a0;
    reg_d2.h[1] = tableEntry[0];
    reg_d2.h[0] = tableEntry[1];
    reg_d1.h[1] = *(u16 *)(work + 0x122);
    reg_d1.h[0] = *(u16 *)(work + 0x124);
    reg_d1.w += 0xD800E800U;
    reg_d3.h[0] = 0x28C0;
    reg_d4.w = 0x15;
    func_0019C570();
}
