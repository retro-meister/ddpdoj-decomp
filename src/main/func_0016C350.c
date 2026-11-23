#include "common.h"

s32 func_0016C410();
s32 func_0018D910();
s32 func_001A9130();
extern u8 D_0026B040[];
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016C350(void) {
    u32 temp_s0;
    u8 *temp_s1;

    func_0018D910();
    temp_s0 = reg_d1.w;
    temp_s1 = (u8 *)(reg_a0);
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (1)));
    reg_d0.w = 0x1000;
    func_001A9130();
    reg_d1.w = temp_s0;
    reg_a0 = temp_s1;
    (*(u8 *)((u8 *)(reg_a6) + (1))) = 0x80U;
    (*(u8 *)((u8 *)(reg_a6) + (0))) |= 0x80;
    reg_a0 = (u8 *)D_0026B040;
    reg_tmp.w = (u32) reg_a0;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xA))) = 0;
    (*(s16 *)((u8 *)(reg_a6) + (0xC))) = 0x202;
    (*(s8 *)((u8 *)(reg_a6) + (0xF))) = 0;
    func_0016C410();
}
