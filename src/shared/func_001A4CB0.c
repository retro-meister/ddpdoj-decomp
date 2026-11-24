#include "common.h"

void func_0019C5B0(void);
extern u8 D_0026B520[];
extern u8 D_0026B550[];
extern u8 D_0028E294;
extern u32 D_0028E480;
extern Reg32 D_0028E484;
extern u16 D_002BB338[];
extern u32 D_002BB3F0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;

void func_001A4CB0(void) {
    u32 tmp;

    reg_a1 = (u8 *)D_002BB3F0;
    reg_a2 = (u8 *)D_002BB338;
    reg_a0 = (u8 *)D_0026B520;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x62C0;
    } else {
        reg_d1.h[0] = 0x53C0;
    }
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_d3.h[0] = 0x208;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    do {
        reg_d1.h[0] = 0x2580;
        reg_d6.w = 7;
        reg_d0.w = *(u32 *)reg_a1;
        reg_a1 += 4;
loop_1:
        reg_d2.h[0] = reg_d0.h[0];
        reg_d2.h[0] &= 0xF;
        reg_d2.h[0] += reg_d2.h[0];
        reg_d2.h[0] += reg_d2.h[0];
        D_0028E480 = reg_d2.w;
        reg_d2.w = *(u32 *)(reg_a0 + (u16) D_0028E480);
        func_0019C5B0();
        reg_d1.h[0] -= 0x200;
        reg_d0.w >>= 4;
        if (reg_d0.w != 0) {
            goto next_1;
        }
        if (*(u16 *)reg_a2 == 0) {
            goto next_2;
        }
next_1:
        tmp = reg_d6.h[0] - 1;
        reg_d6.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        if (reg_d0.h[0] != 0) {
            reg_d2.h[0] = reg_d0.h[0];
            reg_d2.h[0] &= 0xF;
            reg_d2.h[0] += reg_d2.h[0];
            reg_d2.h[0] += reg_d2.h[0];
            D_0028E480 = reg_d2.w;
            reg_d2.w = *(u32 *)(reg_a0 + (u16) D_0028E480);
            func_0019C5B0();
        }
next_2:
        reg_a0 = (u8 *)D_0026B550;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
