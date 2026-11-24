#include "common.h"

void func_0019D390(void);
extern u16 D_0028DFC0;
extern u16 D_0028E3EC;
extern u16 D_0028E484;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 *reg_a6;

void func_0019F620(void) {
    if ((D_0028DFC0 == 0) && (D_0028E910 == 0) && (D_0028E3EC == 0) && (D_0028E91C != 2)) {
        reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        D_0028E484 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484;
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        D_0028E484 = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484;
        reg_d1.w += 0xFE00FE00;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        reg_d2.h[1] = *(u16 *)(reg_a6 + 0x5C);
        reg_d2.h[0] = *(u16 *)(reg_a6 + 0x5E);
        func_0019D390();
    }
}
