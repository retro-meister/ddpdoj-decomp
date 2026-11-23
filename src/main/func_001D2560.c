#include "common.h"

extern s8 D_0028E408;

s32 func_0014D220();
s32 func_0014E290();
s32 func_0019D620();
s32 func_001D24D0();
s32 func_001D2550();
s32 func_001D27A0();
s32 func_00201F20();
extern u8 D_0026D7B0[];
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D2560(void) {
    u32 var_a0;

    if ((*(s8 *)((u8 *)(reg_a6) + (0))) < 0) {
        func_001D24D0();
        return;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (1)));
    func_001D27A0();
    if (D_0028E408 != 0) {
        if ((*(s8 *)((u8 *)(reg_a6) + (0))) < 0) {
            (*(u8 *)((u8 *)(reg_a6) + (1))) = 0x80U;
            reg_tmp.w = 0x24F;
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
            (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
            reg_tmp.w = 0xFC00FE00;
            (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
            (*(s16 *)((u8 *)(reg_a6) + (0x10))) = 0x10;
            func_001D2550();
            return;
        }
        func_0014E290();
        return;
    }
    func_00201F20();
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    D_0028E484.w = 0;
    D_0028E484.h[0] = 0xFFC6;
    reg_d0.h[0] += 0x400;
    reg_tmp.w = (u32) reg_d0.h[0];
    var_a0 = reg_tmp.w;
    reg_tmp.w = var_a0 + D_0028E484.w;
    reg_d0.h[0] += 0x7FFF + 0x7FC7;
    if (reg_tmp.h[1] != 0) {
        if ((*(u8 *)((u8 *)(reg_a5) + (0x17))) != 0) {
            func_0014E290();
            return;
        }
        goto block_10;
    }
    (*(u8 *)((u8 *)(reg_a5) + (0x17))) = 1U;
block_10:
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a5) + (0x19)));
    (*(u8 *)((u8 *)(reg_a5) + (0x19))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0x19))) = (u8) (*(u8 *)((u8 *)(reg_a5) + (0x18)));
        reg_a0 = (u8 *)D_0026D7B0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        var_a0 = (u32) reg_d0.h[0];
        reg_tmp.w = *(u32 *)(D_0026D7B0 + (var_a0 & ~3));
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x1A)));
        (*(u16 *)((u8 *)(reg_a5) + (0x1A))) -= 4;
        if ((s32) reg_tmp.h[0] < 4) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1A))) = 0xCU;
        }
    }
    func_0019D620();
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = reg_a6 + 0x20;
    func_0014D220();
}
