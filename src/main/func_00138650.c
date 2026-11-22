#include "common.h"


s32 func_00137AD0();
extern u16 D_00251AA0[];
extern u16 D_0028C100;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00138650(void) {
    u16 temp_a0;
    if (D_0028E910 == 0) {
        reg_d0.w = 0;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (4)));
        reg_a0 = (u8 *)(&D_0028C100);
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        if (reg_d7.h[0] != 0) {
            (*(u8 *)((u8 *)(reg_a5) + (5))) = (u8) reg_d0.b[0];
        } else {
            (*(u8 *)((u8 *)(reg_a5) + (4))) = (u8) reg_d0.b[0];
        }
    }
    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d1.h[0] = temp_a0;
    reg_d0.h[0] = 8;
    reg_a0 = (u8 *)(D_00251AA0);
    reg_d2.h[0] = 0;
    reg_d1.h[0] >>= 6;
    reg_d1.h[0] >>= 3;
    reg_d1.h[0] += 8;
    func_00137AD0();
    (*(s8 *)((u8 *)(reg_a6) + (0))) = 6;
}
