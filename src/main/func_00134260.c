#include "common.h"

extern u8 D_002BF3E0[];
extern u8 D_002BF3F6[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00134260(void) {
    u32 s_d0;
    u32 s_d1;
    u32 s_d2;
    u32 s_d3;
    u32 s_d4;
    u32 s_d5;
    u32 s_d6;
    u32 s_d7;
    u8 *s_a0;
    u8 *s_a1;
    u8 *s_a2;
    u8 *s_a3;
    u8 *s_a4;
    u8 *s_a5;
    u8 *s_a6;

    s_d0 = reg_d0.w;
    s_d1 = reg_d1.w;
    s_d2 = reg_d2.w;
    s_d3 = reg_d3.w;
    s_d4 = reg_d4.w;
    s_d5 = reg_d5.w;
    s_d6 = reg_d6.w;
    s_d7 = reg_d7.w;
    s_a0 = reg_a0;
    s_a1 = reg_a1;
    s_a2 = reg_a2;
    s_a3 = reg_a3;
    s_a4 = reg_a4;
    s_a5 = reg_a5;
    s_a6 = reg_a6;
    reg_a4 = (u8 *)D_002BF3E0;
    if (reg_d1.h[0] == 0) {
        goto next_1;
    }
    if (*(u16 *) D_002BF3E0 == 3) {
        goto next_2;
    }
    reg_a4 = (u8 *)D_002BF3F6;
next_1:
    if ((reg_d0.h[0] = *(u16 *) reg_a4) == 0) {
        goto next_4;
    }
    reg_d2.h[0] = 2;
    if (reg_d0.h[0] == 1) {
        goto next_3;
    }
next_2:
    reg_d2.h[0] = 4;
next_3:
    *(u16 *) reg_a4 = reg_d2.h[0];
    *(u16 *) (reg_a4 + 2) = 0;
    *(u16 *) (reg_a4 + 4) = reg_d1.h[0];
next_4:
    reg_d0.w = s_d0;
    reg_d1.w = s_d1;
    reg_d2.w = s_d2;
    reg_d3.w = s_d3;
    reg_d4.w = s_d4;
    reg_d5.w = s_d5;
    reg_d6.w = s_d6;
    reg_d7.w = s_d7;
    reg_a0 = s_a0;
    reg_a1 = s_a1;
    reg_a2 = s_a2;
    reg_a3 = s_a3;
    reg_a4 = s_a4;
    reg_a5 = s_a5;
    reg_a6 = s_a6;
}
