#include "common.h"

s32 func_0011C4A0();
s32 func_001A34E0();
extern u32 D_0026B2B0[];
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001A3830(s32 arg3) {
    s32 var_a3;
    u16 temp_a0;
    u16 temp_a1;

    var_a3 = arg3;
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
        func_001A34E0();
        var_a3 = 1;
        (*(u8 *)((u8 *)(reg_a5) + (7))) = 1U;
        (*(u16 *)((u8 *)(reg_a5) + (0xC))) = 0U;
        (*(s16 *)((u8 *)(reg_a5) + (0xE))) = 0x202;
        reg_tmp.w = 0xDC0100;
        (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[0];
        switch ((*(u8 *)((u8 *)(reg_a5) + (6)))) { case 0: break; default:
            reg_tmp.w = 0xDC0F00;
            (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[0];
        }
    }
    (*(u8 *)((u8 *)(reg_a5) + (0xF))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0xF))) < 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0xF))) = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
        (*(u8 *)((u8 *)(reg_a5) + (7))) = 1U;
        (*(u16 *)((u8 *)(reg_a5) + (0xC))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0xC))) >= 0x40) {
            (*(u16 *)((u8 *)(reg_a5) + (0xC))) = 0U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) != 0) {
        (*(u8 *)((u8 *)(reg_a5) + (7))) = 0U;
        reg_a0 = (u8 *)(D_0026B2B0);
        temp_a1 = (*(u16 *)((u8 *)(reg_a5) + (0xC)));
        reg_a0 += temp_a1;
        reg_d4.w = *(u32 *)reg_a0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
        temp_a0 = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
        reg_d1.h[0] = temp_a0;
        reg_d2.w = 1;
        reg_d3.w = 0xB;
        func_0011C4A0();
    }
}
