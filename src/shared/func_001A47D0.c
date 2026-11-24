#include "common.h"

void func_0019C5B0(void);
extern u8 D_0026B3C0[];
extern u8 D_0028E294;
extern Reg32 D_0028E484;
extern s8 D_002BB388_as_s8_a[];
extern u16 D_002BB398_as_u16_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_001A47D0(void) {
    reg_a0 = (u8 *)D_0026B3C0;
    reg_a1 = (u8 *)D_002BB398_as_u16_a;
    reg_a2 = (u8 *)D_002BB388_as_s8_a;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x5EC0;
    } else {
        reg_d1.h[0] = 0x4FC0;
    }
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        reg_d3.h[0] = 0x208;
        reg_d1.h[0] = 0x2400;
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (reg_d0.h[0] != 0) {
            if ((reg_d0.b[0] == 1) && (*(s8 *)reg_a2 == 5)) {
                reg_d1.h[0] = 0x2400;
                reg_a2 += 2;
                reg_d2.w = 0x14BE;
                reg_d3.h[0] = 0x218;
                goto next_2;
            }
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_d2.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
            func_0019C5B0();
            reg_d1.h[0] += 0x200;
            reg_d2.w = 0x1546;
            func_0019C5B0();
            reg_d1.h[0] += 0x200;
            goto next_1;
        }
        reg_d1.h[0] = 0x2600;
next_1:
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_d2.w = *(u32 *)(reg_a0 + reg_d0.h[0]);
next_2:
        func_0019C5B0();
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
