#include "common.h"

s32 func_00201230();
s32 func_0020A370();
extern u8 D_00250D88[];
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
extern u8 D_00299D30[];
extern u8 D_0029A12C[];
extern u8 D_0029CEA0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0020A270(void) {
    s32 temp_a1;
    s32 temp_a2;

    D_0028E550 = reg_d0.w;
    D_0028E54C = reg_d1.w;
    D_0028E548 = reg_d2.w;
    D_0028E544 = reg_d3.w;
    D_0028E540 = reg_d4.w;
    D_0028E53C = reg_d5.w;
    D_0028E538 = reg_d6.w;
    D_0028E534 = reg_d7.w;
    D_0028E56C = (u8 *)(reg_a0);
    D_0028E568 = reg_a1;
    D_0028E564 = reg_a2;
    D_0028E560 = reg_a3;
    D_0028E55C = reg_a4;
    D_0028E558 = reg_a5;
    D_0028E554 = reg_a6;
    reg_d1.w = 0;
    func_00201230();
    temp_a2 = reg_d0.h[0] * 4;
    temp_a1 = *(u32 *)(D_00250D88 + temp_a2);
    reg_a2 = (u8 *)temp_a1;
    reg_d7.h[0] = 0xFFFF;
    reg_a0 = (u8 *)D_00299D30;
    reg_d0.w = 0;
    if (!(D_0029CEA0[0] & 0x80)) {
        func_0020A370();
        return;
    }
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}
