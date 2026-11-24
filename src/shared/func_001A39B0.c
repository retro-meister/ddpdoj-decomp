#include "common.h"

s32 func_0011C4A0();
s32 func_001A34E0();
s32 func_001AB7F0();
s32 func_001AB860();
extern u8 D_0026B2F0[];
extern u8 D_0026B310[];
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_001A39B0(s32 arg2, s32 arg3) {
    s32 var_a2;
    s32 var_a3;
    u16 temp_a0_2;
    u8 *temp_a0;

    var_a2 = arg2;
    var_a3 = arg3;
    temp_a0 = (u8 *)(reg_a5 + 2);
    if ((*(u8 *)((u8 *)(reg_a5) + (2))) == 0) {
        (*(u8 *)((u8 *)(reg_a5) + (2))) = 1U;
        if ((*(u8 *)((u8 *)(reg_a5) + (6))) == 0) {
            func_001AB7F0();
        } else {
            func_001AB860();
        }
        reg_d2.b[0] = (*(u8 *)((u8 *)(reg_a5) + (6)));
        func_001A34E0();
        var_a2 = 0xDC0000;
        var_a3 = 0x101;
        (*(u8 *)((u8 *)(reg_a5) + (7))) = 1U;
        (*(u16 *)((u8 *)(reg_a5) + (0xC))) = 0U;
        (*(s16 *)((u8 *)(reg_a5) + (0xE))) = 0x101;
        reg_tmp.w = 0xDC0100;
        (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32) D_0026B2F0;
        (*(u16 *)((u8 *)(reg_a5) + (0x10))) = (u16) reg_tmp.h[1];
        (*(u16 *)((u8 *)(reg_a5) + (0x12))) = (u16) reg_tmp.h[0];
        switch ((*(u8 *)((u8 *)(reg_a5) + (6)))) { case 0: break; default:
            reg_tmp.w = 0xDC1200;
            (*(u16 *)((u8 *)(reg_a5) + (8))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0xA))) = (u16) reg_tmp.h[0];
            reg_tmp.w = (u32) D_0026B310;
            (*(u16 *)((u8 *)(reg_a5) + (0x10))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0x12))) = (u16) reg_tmp.h[0];
        }
    }
    (*(u8 *)((u8 *)(reg_a5) + (0xF))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a5) + (0xF))) < 0) {
        (*(u8 *)((u8 *)(reg_a5) + (0xF))) = (*(u8 *)((u8 *)(reg_a5) + (0xE)));
        (*(u8 *)((u8 *)(reg_a5) + (7))) = 1U;
        (*(u16 *)((u8 *)(reg_a5) + (0xC))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0xC))) >= 0x20) {
            (*(u16 *)((u8 *)(reg_a5) + (0xC))) = 0U;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a5) + (7))) != 0) {
        (*(u8 *)((u8 *)(reg_a5) + (7))) = 0U;
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a5) + (0x10)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0x12)));
        reg_a0 = (u8 *)(reg_tmp.w);
        temp_a0_2 = (*(u16 *)((u8 *)(reg_a5) + (0xC)));
        reg_a0 += temp_a0_2;
        reg_d4.w = *(u32 *)reg_a0;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a5) + (8)));
        reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a5) + (0xA)));
        reg_d3.w = 6;
        reg_d2.w = 0;
        func_0011C4A0();
    }
}
