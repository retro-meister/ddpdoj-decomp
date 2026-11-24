#include "common.h"

extern u8 *reg_a6;
extern void func_001FDBD0(void);

void func_001FDC10(void) {
    u8 *object = reg_a6;

    reg_d2.w = 0x1E94;
    reg_d1.h[1] = *(u16 *)(object + 0x02);
    reg_d1.h[0] = *(u16 *)(object + 0x04);
    reg_d1.w += 0xFC3FEC80U;
    reg_d1.h[0] += *(u16 *)(object + 0x48);
    reg_d1.w += 0xFA00FF00U;
    reg_d3.h[0] = 0x608;
    reg_d4.w = 0;
    *(u8 *)&reg_d4 = object[0x5C];
    func_001FDBD0();
}
