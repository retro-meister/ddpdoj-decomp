#include "common.h"


typedef void (*Fn)();

extern u8 D_0028E2C0;
extern u16 D_0028E91C;
extern u8 D_0028ED80;
extern u8 D_0029BF50[];
extern u16 D_0029C06C[];
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_0014C4B0(void) {
    u32 temp_s0;

    if ((D_0028ED80 == 0) || (D_0028E2C0 == 0) || (D_0028E91C != 2)) {
        reg_a6 = D_0029BF50;
        reg_d7.w = 7;
        do {
            if ((*(u8 *)((u8 *)(reg_a6) + (1))) != 0) {
                reg_d0.h[0] = D_0029C06C[0];
                (*(u16 *)((u8 *)(reg_a6) + (4))) -= reg_d0.h[0];
                reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (8)));
                reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA)));
                reg_a1 = (u8 *)reg_tmp.w;
                jtbl_0028E3F4 = reg_a1;
                temp_s0 = reg_d7.w;
                ((Fn)jtbl_0028E3F4)();
                reg_d7.w = temp_s0;
            }
            reg_a6 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}
