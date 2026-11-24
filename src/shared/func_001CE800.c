#include "common.h"

s32 func_00124F00();
s32 func_0014E030();
s32 func_002010A0();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CE800(void) {
    u32 temp_s0;

    if ((*(u16 *)((u8 *)(reg_a4) + (2))) != 0) {
        reg_d0.w = 2;
        func_00124F00();
        reg_d0.w = 3;
        func_00124F00();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        return;
    }
    reg_d0.h[0] = 0x99;
    func_0014E030();
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[1] += 0x4C0;
    reg_d0.h[0] += 0x7FFF + 0x7601;
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x68)));
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d0.h[0];
    (*(s16 *)((u8 *)(reg_a0) + (0x34))) = 0x184;
    func_002010A0();
    temp_s0 = reg_d0.w;
    (*(u8 *)((u8 *)(reg_a0) + (0x37))) = (u8) reg_d0.b[0];
    reg_d0.h[0] = 0x99;
    func_0014E030();
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.h[1] += 0x4C0;
    reg_d0.h[0] += 0xA00;
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
    reg_d0.h[0] = 0x4000;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x68)));
    (*(u16 *)((u8 *)(reg_a0) + (0x1A))) = (u16) reg_d0.h[0];
    (*(s16 *)((u8 *)(reg_a0) + (0x34))) = 0x17C;
    reg_d0.w = temp_s0;
    (*(u8 *)((u8 *)(reg_a0) + (0x37))) = (u8) reg_d0.b[0];
    (*(u16 *)((u8 *)(reg_a4) + (2))) = 1U;
}
