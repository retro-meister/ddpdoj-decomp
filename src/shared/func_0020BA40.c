#include "common.h"

extern u8 D_0028E0A0[];
extern u8 D_0029CEA0_as_u8_a[];
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0020BA40(void) {
    reg_d0.h[0] = 0xF800;
    reg_a5 = (u8 *)D_0028E0A0;
    *(u16 *) reg_a5 = reg_d0.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 = 0x4000;
    reg_a5 += 2;
    *(u16 *) reg_a5 = reg_d0.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 = 0x7C00;
    reg_a5 += 2;
    reg_d5.h[0] = 0x2C;
    reg_a6 = (u8 *)D_0029CEA0_as_u8_a;
loop_1:
    reg_tmp.h[0] = *(u16 *) reg_a6;
    reg_a6 += 2;
    if ((s16) reg_tmp.h[0] >= 0) goto next_9;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0);
    reg_d2.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = reg_d0.h[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_a5 = reg_a6 + 0xE;
    reg_d0.h[0] += *(u16 *) reg_a5;
    reg_a5 += 2;
    reg_d1.h[0] -= *(u16 *) reg_a5;
    reg_a5 += 2;
    reg_d2.h[0] += *(u16 *) reg_a5;
    reg_a5 += 2;
    reg_d3.h[0] -= *(u16 *) reg_a5;
    reg_a5 = (u8 *)D_0028E0A0;
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] >= (s16) reg_d2.h[0]) goto next_5;
    *(u16 *) (reg_a5 - 2) = reg_d2.h[0];
next_5:
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] <= (s16) reg_d3.h[0]) goto next_6;
    *(u16 *) (reg_a5 - 2) = reg_d3.h[0];
next_6:
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] >= (s16) reg_d0.h[0]) goto next_7;
    *(u16 *) (reg_a5 - 2) = reg_d0.h[0];
next_7:
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] <= (s16) reg_d1.h[0]) goto next_9;
    *(u16 *) (reg_a5 - 2) = reg_d1.h[0];
next_9:
    reg_a6 += 0x2E;
    if ((s16) --reg_d5.h[0] >= 0) goto loop_1;
    reg_a5 = (u8 *)D_0028E0A0;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
}
