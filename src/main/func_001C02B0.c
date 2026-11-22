#include "common.h"

s32 func_0014E030();
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C02B0(void) {
    reg_d6.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9A)));
    reg_d6.b[0] += 0x20;
    reg_d6.b[0] &= 0x3F;
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    reg_d0.w = 0x32;
    func_0014E030();
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x18;
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x18;
    reg_d6.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x18;
    reg_d6.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x18;
    reg_d6.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d6.b[0];
    reg_d0.w = 0x32;
    func_0014E030();
    (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d2.h[1];
    (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d2.h[0];
    (*(s8 *)((u8 *)(reg_a0) + (0x1B))) = 0x18;
    reg_d6.h[0] += 2;
    (*(u8 *)((u8 *)(reg_a0) + (0x1A))) = (u8) reg_d6.b[0];
    *(s16 *)reg_a4 = 0;
}
