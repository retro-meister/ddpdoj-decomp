#include "common.h"

s32 func_0016C410();
s32 func_001A9130();
extern u32 reg_a0_as_u32;
extern u8 *reg_a6;

void func_0016C2A0() {
    u32 temp_s0;
    u32 temp_s1;

    temp_s0 = reg_d1.w;
    temp_s1 = reg_a0_as_u32;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
    reg_d0.w = 0x10;
    func_001A9130();
    reg_d1.w = temp_s0;
    reg_a0_as_u32 = temp_s1;
    (*(u8 *)((u8 *)(reg_a6) + (1))) = 0x80U;
    (*(u8 *)((u8 *)(reg_a6) + (0))) |= 1;
    (*(s16 *)((u8 *)(reg_a6) + (0xC))) = 0x202;
    reg_tmp.w = reg_a0_as_u32;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 0;
    (*(s8 *)((u8 *)(reg_a6) + (0xF))) = 0;
    func_0016C410();
}
