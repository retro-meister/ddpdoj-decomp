#include "common.h"

void func_0019C5B0(void);
extern u8 D_0026B3F0[];
extern u8 D_0028E294;
extern Reg32 D_0028E484;
extern u16 D_002BB358[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001A4A20(void) {
    u32 tmp;

    reg_a6 = (u8 *)D_002BB358;
    reg_a0 = (u8 *)D_0026B3F0;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x6380;
    } else {
        reg_d1.h[0] = 0x5480;
    }
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 8;
    reg_d7.w = 4;
    do {
        reg_d0.h[0] = *(u16 *)reg_a6;
        reg_a6 += 2;
        reg_d1.h[0] = 0x31C0;
        reg_d6.w = 3;
loop_1:
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] &= 0xF;
        reg_d2.w = *(u32 *)(D_0026B3F0 + (reg_d2.h[0] * 4));
        func_0019C5B0();
        reg_d1.h[0] -= 0x200;
        reg_d0.h[0] >>= 4;
        if (reg_d0.h[0] != 0) {
            tmp = reg_d6.h[0] - 1;
            reg_d6.h[0] = tmp;
            if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                goto loop_1;
            }
        }
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
