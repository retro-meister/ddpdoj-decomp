#include "common.h"

s32 func_00209F10();
s32 func_0020A370();
extern u8 D_00251120[];
extern u32 D_0028E534;
extern u32 D_0028E538;
extern u32 D_0028E53C;
extern u32 D_0028E540;
extern u32 D_0028E544;
extern u32 D_0028E548;
extern u32 D_0028E54C;
extern u32 D_0028E550;
extern u8 *D_0028E554;
extern u8 *D_0028E558;
extern u8 *D_0028E55C;
extern u8 *D_0028E560;
extern u8 *D_0028E564;
extern u8 *D_0028E568;
extern u8 *D_0028E56C;
extern u16 D_0028E910;
extern u8 D_00299D30[];
extern u8 D_0029A12C[];
extern u8 D_0029F260_as_u8_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_00209F20(void) {
    if (D_0028E910 != 0) {
        func_00209F10();
        return;
    }
    D_0028E550 = reg_d0.w;
    D_0028E54C = reg_d1.w;
    D_0028E548 = reg_d2.w;
    D_0028E544 = reg_d3.w;
    D_0028E540 = reg_d4.w;
    D_0028E53C = reg_d5.w;
    D_0028E538 = reg_d6.w;
    D_0028E534 = reg_d7.w;
    D_0028E56C = reg_a0;
    D_0028E568 = reg_a1;
    D_0028E564 = reg_a2;
    D_0028E560 = reg_a3;
    D_0028E55C = reg_a4;
    D_0028E558 = reg_a5;
    D_0028E554 = reg_a6;
    *(u8 *)&rng_cursor += 1;
    reg_d5.h[0] = rng_cursor;
    reg_d1.w = 0;
    reg_a2 = *(u8 **)(D_00251120 + reg_d5.h[0] * 4);
    reg_a0 = (u8 *)D_00299D30;
    if (D_0029F260_as_u8_a == reg_a4) {
        func_0020A370();
        return;
    }
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}
