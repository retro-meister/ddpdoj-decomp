#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_00124DC0();
s32 func_00124F00();
s32 func_00124F50();
s32 func_0013B2E0();
s32 func_001A3020();
s32 func_001BE270();
s32 func_00201E20();
extern u8 D_0025FEF0[];
extern u8 D_0026F440[];
extern u8 D_0028E855;
extern u16 D_0029C068[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BE5F0(void) {
    if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xA))) += 2;
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        reg_d1.w = 0;
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xA)));
        func_00201E20();
        reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
        reg_d1.h[0] = reg_d3.h[0];
        reg_d1.h[0] = (u16) -(s16) reg_d1.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 6);
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 4);
        reg_d1.h[0] += 7;
        if ((s16) reg_d1.h[0] > 0xF) {
            reg_d1.h[0] = 0xF;
        }
        if (0 > (s16) reg_d1.h[0]) {
            reg_d1.h[0] = 0;
        }
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] += reg_d1.h[0];
        (*(u16 *)((u8 *)(reg_a6) + (0x126))) = (u16) reg_d1.h[0];
        reg_d0.h[0] = 0x1C00;
        reg_d0.h[0] += reg_d3.h[0];
        reg_d0.h[0] -= D_0029C068[0];
        (*(u16 *)((u8 *)(reg_a6) + (4))) = (u16) reg_d0.h[0];
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
        (*(u16 *)((u8 *)(reg_a6) + (2))) += reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a4) + (8))) -= 5;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (8))) <= 0) {
            (*(u16 *)((u8 *)(reg_a4) + (8))) = 0U;
            (*(u8 *)((u8 *)(reg_a4) + (7))) = 1U;
            reg_d0.w = 0xA;
            func_00124F00();
            reg_d0.w = 0xB;
            func_00124DC0();
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
            (*(u16 *)((u8 *)(reg_a6) + (0x128))) += 4;
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x128))) > 0x1C) {
                (*(u16 *)((u8 *)(reg_a6) + (0x128))) = 0U;
                reg_d0.w = 0xB;
                func_00124F00();
                reg_d0.h[0] = 0x15;
                reg_a0 = (u8 *)D_0025FEF0;
                func_001A3020();
                D_0028E855 |= 0x10;
                reg_d0.w = 1;
                D_0028E855 |= 2;
                func_00124D90();
                reg_d0.w = 3;
                func_00124B20();
                reg_d0.w = 9;
                func_00124F50();
                reg_d0.w = 0xA;
                func_00124F50();
                reg_d0.w = 0;
                func_00124DC0();
                reg_d0.w = 1;
                func_00124DC0();
                reg_d0.w = 2;
                func_00124DC0();
                reg_d0.w = 3;
                func_00124DC0();
                reg_d0.w = 4;
                func_00124DC0();
                reg_d0.w = 5;
                func_00124DC0();
                (*(u16 *)((u8 *)(reg_a6) + (0x20))) = 0xA001;
                (*(u16 *)((u8 *)(reg_a6) + (0x40))) = 0xA001;
                (*(u16 *)((u8 *)(reg_a6) + (0x60))) = 0xA001;
                reg_a0 = (u8 *)D_0026F440;
                func_0013B2E0();
            }
        }
    }
    func_001BE270();
}
