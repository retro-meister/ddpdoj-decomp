#include "common.h"

extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
extern u16 D_0028E7D4;
extern u8 D_002BBAF0[];
extern u8 D_002BBB40[];
extern u8 *reg_a0;

void func_0014E070(void) {
    reg_d2.h[0] = D_0028E7D4;
    if (reg_d2.h[0] == 0xC80) goto next_1;
    reg_a0 = (u8 *)D_002BBB40;
    reg_a0 += reg_d2.h[0];
    *(u16 *) (reg_a0 + 2) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 4) = reg_d1.h[0];
    *(s16 *) (reg_a0 + 0x12) = 0;
    *(s16 *) (reg_a0 + 0x14) = 0;
    reg_d2.h[0] += 0x50;
    D_0028E7D4 = reg_d2.h[0];
    reg_d0.w = D_0028DF44;
    reg_d1.w = D_0028DF40;
    reg_d2.w = D_0028DF3C;
    return;
next_1:
    reg_a0 = (u8 *)D_002BBAF0;
    reg_d0.w = D_0028DF44;
    reg_d1.w = D_0028DF40;
    reg_d2.w = D_0028DF3C;
}
