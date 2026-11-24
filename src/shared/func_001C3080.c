#include "common.h"

s32 func_001BF210();
s32 func_00202140();
s32 func_00202500();
extern u16 D_0028E4A2;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C3080(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    func_00202140();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x9A))) = (u8) reg_d1.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    func_00202140();
    reg_d1.b[0] += 0x20;
    reg_d1.b[0] &= 0x3F;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBA)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0xBA))) = (u8) reg_d1.b[0];
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
    (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
        reg_d0.w = 0x6000B;
        reg_d1.w = 0;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x9A)));
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
        reg_d3.w = 0;
        reg_d4.w = 0;
        func_001BF210();
        reg_d1.w = 0;
        reg_d0.w = 0x6000B;
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0xBA)));
        reg_d1.b[0] += 0x20;
        reg_d1.b[0] &= 0x3F;
        D_0028E4A2 = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
        reg_d3.w = 0;
        reg_d4.w = 0;
        func_001BF210();
        (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
    }
}
