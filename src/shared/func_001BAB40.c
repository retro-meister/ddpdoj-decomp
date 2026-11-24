#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_00124DC0();
s32 func_00124F50();
s32 func_0013B2E0();
s32 func_001BA820();
s32 func_001BC3A0();
s32 func_001BC3B0();
s32 func_00201C60();
s32 func_002021F0();
s32 func_00202500();
s32 func_00202B50();
extern u16 D_0026E930[];
extern u8 D_0028E855;
extern u16 D_0029C068[];
extern u16 D_002BDA80[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BAB40(void) {
    u8 temp_v0_2;

    reg_d2.h[0] = 0x5400;
    reg_d3.h[0] = 0x1C00;
    reg_d3.h[0] -= D_0029C068[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    func_00201C60();
    reg_a0 = (u8 *)(D_002BDA80);
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_d0.w = 4;
    do {
        *(u16 *)reg_a0 = reg_d1.h[1];
        reg_a0 += 2;
        *(u16 *)reg_a0 = reg_d1.h[0];
        reg_a0 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d2.h[0] = 0x5400;
    reg_d3.h[0] = 0x1C00;
    reg_d3.h[0] -= D_0029C068[0];
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x1801) {
        (*(u8 *)((u8 *)(reg_a4) + (5))) = 1U;
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            temp_v0_2 = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
            if (temp_v0_2 != 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) (temp_v0_2 - 1);
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (5))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x11A))) += 0x10;
        (*(u16 *)((u8 *)(reg_a6) + (0x11A))) &= 0x3F;
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (5))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (7)));
        (*(u8 *)((u8 *)(reg_a4) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (7))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (6)));
            (*(u16 *)((u8 *)(reg_a6) + (0x11A))) += 0x10;
            if ((*(u16 *)((u8 *)(reg_a6) + (0x11A))) == 0x180) {
                D_0028E855 |= 0x10;
                D_0028E855 |= 2;
                reg_d0.w = 2;
                func_00124D90();
                reg_d0.w = 1;
                func_00124B20();
                func_001BC3A0();
                func_001BC3B0();
                reg_d0.w = 0;
                func_00124F50();
                reg_d0.w = 1;
                func_00124F50();
                reg_d0.w = 2;
                func_00124F50();
                reg_d0.w = 3;
                func_00124F50();
                reg_d0.w = 7;
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
                reg_d0.w = 6;
                reg_a0 = (u8 *)(D_0026E930);
                func_0013B2E0();
            }
        }
    }
    func_001BA820();
}
