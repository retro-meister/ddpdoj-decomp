#include "common.h"

extern s8 D_0028E408;

s32 func_001AF010();
extern u8 D_0029BF30[];
extern u8 D_0029BF31[];
extern u8 D_0029BF40[];
extern u8 D_0029BF41[];

void func_001AEF50(void) {
    u8 *p;

    *(p = D_0029BF41) = 0xFF;
    D_0029BF40[0] = 0xFF;
    reg_d5.w = 0;
    reg_d6.h[0] = reg_d0.h[0];
    reg_d7.h[0] = reg_d2.h[0];
    func_001AF010();
    if (D_0028E408 != 0) goto next_1;
    *p = reg_d6.b[0];
    D_0029BF40[0] = reg_d7.b[0];
next_1:
    *(p = D_0029BF31) = 0xFF;
    D_0029BF30[0] = 0xFF;
    reg_d5.w = 1;
    reg_d6.h[0] = reg_d1.h[0];
    reg_d7.h[0] = reg_d3.h[0];
    func_001AF010();
    if (D_0028E408 != 0) goto next_2;
    *p = reg_d6.b[0];
    D_0029BF30[0] = reg_d7.b[0];
next_2:
    return;
}
