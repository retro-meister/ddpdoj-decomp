#include "common.h"

void func_0019C5B0(void);
extern u8 D_0026B420[];
extern u8 D_0026B4A0[];
extern u8 D_0028E294;
extern Reg32 D_0028E484;
extern u8 D_002BB3B0_as_u8_a[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001A4B60(void) {
    s32 flag;
    u32 tmp;

    reg_a6 = (u8 *)D_002BB3B0_as_u8_a;
    if (D_0028E294 != 0) {
        reg_d1.h[0] = 0x66C0;
    } else {
        reg_d1.h[0] = 0x57C0;
    }
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_d3.h[0] = 0x410;
    reg_d4.h[0] = 5;
    reg_d7.w = 4;
    reg_a0 = (u8 *)D_0026B420;
    do {
        reg_d1.h[0] = 0x1680;
        reg_d5.w = 2;
        flag = 0;
loop_1:
        reg_d2.w = *(u32 *)reg_a6;
        reg_a6 += 4;
        if ((u32) reg_d2.w > 0x70U) {
            flag = 1;
        }
        if (flag != 0) {
            reg_d2.w = 0x68;
            *(u32 *)(reg_a6 - 4) = reg_d2.w;
        }
        reg_d2.w = *(u32 *)(reg_a0 + reg_d2.w);
        func_0019C5B0();
        reg_d1.h[0] += 0x400;
        tmp = reg_d5.h[0] - 1;
        reg_d5.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_a0 = (u8 *)D_0026B4A0;
        reg_d1.h[1] -= 0x11C0;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
