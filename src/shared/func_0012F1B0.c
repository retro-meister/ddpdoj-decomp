#include "common.h"

s32 func_0012DA30();
s32 func_0012E350();
extern u8 *reg_a6;

void func_0012F1B0() {
    func_0012E350();
    reg_tmp.w = 0x220;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    reg_tmp.w = 0x1F;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    reg_d1.w = 0;
    reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.b[0] -= (*(u8 *)((u8 *)(reg_a6) + (0x36)));
    func_0012DA30();
    reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 3);
    reg_d3.h[0] = (u16) ((s16) reg_d3.h[0] >> 3);
    (*(u16 *)((u8 *)(reg_a6) + (0x30))) = (u16) reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x32))) = (u16) reg_d3.h[0];
}
