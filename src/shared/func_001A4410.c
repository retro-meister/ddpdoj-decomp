#include "common.h"

s32 func_0019C5B0();
extern u8 D_0026B370[];
extern u8 D_0028E294;

void func_001A4410(void) {
    if (D_0028E294 != 0) {
        reg_d1.w = 0x628004C0;
    } else {
        reg_d1.w = 0x538004C0;
    }
    reg_d6.w = 0;
    reg_d3.h[0] = 0x610;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        reg_d2.w = *(u32 *)(D_0026B370 + (reg_d6.h[0] & ~3));
        func_0019C5B0();
        reg_d6.h[0] += 4;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
