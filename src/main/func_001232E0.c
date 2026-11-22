#include "common.h"

s32 func_0019C5B0();
extern u8 D_002BDA80[];
extern u8 *reg_a3;

void func_001232E0(void) {
    reg_a3 = D_002BDA80;
    reg_d7.h[0] = 0xC7;
    do {
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a3) + (0)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a3) + (2)));
        if (reg_d2.w != 0) {
            reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a3) + (4)));
            reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a3) + (6)));
            reg_d3.h[0] = 0x410;
            reg_d4.h[0] = 0;
            func_0019C5B0();
        }
        reg_a3 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
