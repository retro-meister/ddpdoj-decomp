#include "common.h"


s32 func_0013A780();
s32 func_002010A0();
extern u8 *reg_a0;

void func_0013A930(u32 arg0, u32 arg1, s16 arg2) {
    u32 temp_a0;

    reg_d0.w = arg0;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = (u16) reg_d3.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) reg_d2.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) reg_d2.h[0];
    reg_d0.w = arg1;
    temp_a0 = reg_d0.h[0];
    reg_d0.h[0] = (u16) (temp_a0 >> reg_d6.h[0]);
    (*(u8 *)((u8 *)(reg_a0) + (0x1B))) = (u8) reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d1.b[0];
    func_002010A0();
    reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) += reg_d0.b[0];
    (*(s16 *)((u8 *)(reg_a0) + (0x18))) = arg2;
}
