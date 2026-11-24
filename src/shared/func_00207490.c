#include "common.h"

extern u16 D_0028E0CC;
extern u8 D_002A0AF0[];
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_00207490(void) {
    u8 *a1;
    u8 *a0;
    s32 d1;
    s32 d2;

    d1 = reg_d1.w;
    a0 = reg_a0;
    a1 = reg_a1;
    d2 = reg_d2.w;
    reg_d2.h[0] = D_0028E0CC;
    if ((s16) reg_d2.h[0] < 0x640) {
        reg_a1 = (u8 *)D_002A0AF0;
        reg_a1 += reg_d2.h[0] & 0xFFFF;
        *(u16 *) (reg_a1 + 0) = *(u16 *) (reg_a0 + 0);
        *(u16 *) (reg_a1 + 2) = *(u16 *) (reg_a0 + 2);
        D_0028E0CC += 0x50;
    }
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_a0 = a0;
    reg_a1 = a1;
}
