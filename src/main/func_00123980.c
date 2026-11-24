#include "common.h"

typedef void (*Fn)();

s32 func_00122EB0();
s32 func_00123040();
s32 func_001232E0();
s32 func_00123780();
s32 func_0019C5B0();
extern u32 D_0024D070[];
extern u8 D_0024D090[];
extern u8 D_0028E368;
extern u8 D_0028E378;
extern u8 D_00295E00[];
extern u16 D_00295E2C[];
extern u8 D_00295E3E[];
extern u8 D_00295E3F[];
extern u16 D_00295E40[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00123980(void) {
    u8 mode;

    mode = (*(u8 *)((u8 *)(reg_a5) + (3)));
    if (mode == 0) {
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        func_00123780();
        return;
    }
    if (mode == 2) {
        func_00122EB0();
        return;
    }
    reg_a6 = (u8 *)D_00295E00;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (8)));
    ((Fn)*(u32 *)((u8 *)D_0024D090 + (reg_d0.h[0] * 4)))();
    func_001232E0();
    func_00123040();
    reg_d0.h[0] = D_00295E2C[0];
    if (reg_d0.h[0] != 0) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 = (u8 *)(D_0024D070);
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d2.w = *(u32 *)reg_a0;
        reg_d1.w = 0x38000000;
        reg_d3.h[0] = 0x1CE0;
        reg_d4.h[0] = 1;
        reg_d4.h[0] += D_00295E40[0];
        func_0019C5B0();
        D_00295E3F[0] -= 1;
        if (0 > (s8) D_00295E3F[0]) {
            D_00295E3F[0] = D_00295E3E[0];
            D_00295E40[0] += 1;
            D_00295E40[0] &= 1;
        }
    }
}
