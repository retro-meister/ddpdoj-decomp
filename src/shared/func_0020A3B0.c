#include "common.h"

extern s8 D_0028E408;

s32 func_0020AAA0();
extern u32 D_0028E534;
extern u32 D_0028E538;
extern u32 D_0028E53C;
extern u32 D_0028E540;
extern u32 D_0028E544;
extern u32 D_0028E548;
extern u32 D_0028E54C;
extern u32 D_0028E550;
extern s32 D_0028E554_as_s32;
extern s32 D_0028E558_as_s32;
extern s32 D_0028E55C_as_s32;
extern s32 D_0028E560_as_s32;
extern s32 D_0028E564_as_s32;
extern s32 D_0028E568_as_s32;
extern u16 *D_0028E56C_as_u16_p;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0020A3B0(void) {
    u32 t;

loop_1:
    if (*(u16 *)reg_a0 == 0) goto next_2;
    reg_a0 += 0x22;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    D_0028E408 = 1;
    reg_d0.w = D_0028E550;
    reg_d1.w = D_0028E54C;
    reg_d2.w = D_0028E548;
    reg_d3.w = D_0028E544;
    reg_d4.w = D_0028E540;
    reg_d5.w = D_0028E53C;
    reg_d6.w = D_0028E538;
    reg_d7.w = D_0028E534;
    reg_a0 = (u8 *)D_0028E56C_as_u16_p;
    reg_a1 = (u8 *)D_0028E568_as_s32;
    reg_a2 = (u8 *)D_0028E564_as_s32;
    reg_a3 = (u8 *)D_0028E560_as_s32;
    reg_a4 = (u8 *)D_0028E55C_as_s32;
    reg_a5 = (u8 *)D_0028E558_as_s32;
    reg_a6 = (u8 *)D_0028E554_as_s32;
    return;
next_2:
    func_0020AAA0();
    reg_tmp.h[0] = reg_d1.h[0];
    reg_d1.h[0] -= 1;
    if (reg_tmp.h[0] == 0) goto next_3;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_3:
    D_0028E408 = 0;
    reg_d0.w = D_0028E550;
    reg_d1.w = D_0028E54C;
    reg_d2.w = D_0028E548;
    reg_d3.w = D_0028E544;
    reg_d4.w = D_0028E540;
    reg_d5.w = D_0028E53C;
    reg_d6.w = D_0028E538;
    reg_d7.w = D_0028E534;
    reg_a0 = (u8 *)D_0028E56C_as_u16_p;
    reg_a1 = (u8 *)D_0028E568_as_s32;
    reg_a2 = (u8 *)D_0028E564_as_s32;
    reg_a3 = (u8 *)D_0028E560_as_s32;
    reg_a4 = (u8 *)D_0028E55C_as_s32;
    reg_a5 = (u8 *)D_0028E558_as_s32;
    reg_a6 = (u8 *)D_0028E554_as_s32;
}
