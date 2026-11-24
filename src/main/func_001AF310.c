#include "common.h"

extern u16 D_0028E928;
extern u8 D_0029BF30[];
extern u8 D_0029BF40[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern s8 D_0028E408;

void func_001AF310(void) {
    s32 d1 = reg_d1.w;

    reg_a0 = (u8 *)D_0029BF40;
    if (reg_a5[6] != 0) goto next_1;
    reg_a0 = (u8 *)D_0029BF30;
next_1:
    reg_d1.b[0] = *reg_a0;
    if (D_0028E928 != 0) goto next_2;
    reg_d1.h[0] = 0xFFFF;
next_2:
    if ((s8) reg_d1.b[0] == -1) goto next_3;
    if (reg_d7.b[0] != reg_d1.b[0]) goto next_3;
    reg_d1.w = d1;
    D_0028E408 = 1;
    return;
next_3:
    reg_d1.w = d1;
    D_0028E408 = 0;
}
