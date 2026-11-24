#include "common.h"

s32 func_00124DC0();
s32 func_00124F00();
s32 func_00124F50();
s32 func_0013B2E0();
s32 func_001D4550();
s32 func_001D4560();
extern u8 D_0026CBC0[];
extern u8 D_0028E855;
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CE5F0(void) {
    u16 t1;

    if (*(u16 *)(reg_a4 + 6) == 0) goto next_40;
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(u16 *)(reg_a4 + 6) == 0) {
        *(u16 *)(reg_a6 + 0xBC) = 0xC0;
        goto next_40;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
    *(u16 *)(reg_a6 + 0xBC) += 0xC;
    if (*(u16 *)(reg_a6 + 0xBC) != 0xC0) return;
    *(u16 *)(reg_a6 + 0xBC) = 0U;
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(u16 *)(reg_a4 + 6) != 0) return;
    *(u16 *)(reg_a6 + 0xBC) = 0x60;
next_40:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0xBC) += 0xC;
        t1 = *(u16 *)(reg_a6 + 0xBC);
        if (t1 == 0x1E0) {
            *(s16 *)reg_a4 = 0;
            D_0028E855 |= 2;
            D_0028E855 |= 0x10;
            func_001D4550();
            func_001D4560();
            reg_d0.w = 9;
            func_00124F00();
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
            func_00124DC0();
            reg_d0.w = 7;
            func_00124DC0();
            reg_d0.w = 8;
            func_00124DC0();
            reg_d0.w = 0;
            func_00124F50();
            reg_d0.w = 1;
            func_00124F50();
            reg_d0.w = 6;
            func_00124F50();
            reg_a0 = (u8 *)D_0026CBC0;
            func_0013B2E0();
        }
    }
    }
