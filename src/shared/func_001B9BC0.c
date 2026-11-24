#include "common.h"

extern s8 D_0028E408;

s32 func_00124D80();
s32 func_00124D90();
s32 func_00124F50();
s32 func_00125060();
s32 func_00125250();
s32 func_001B9DE0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B9BC0(void) {
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;

    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x3E)));
    reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x7E)));
    if (reg_d0.b[0] == 2) {
        func_001B9DE0();
        return;
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        func_00124D80();
        if (reg_d0.h[0] == 4) {
            reg_d0.w = 8;
            func_00124F50();
            reg_d0.w = 9;
            func_00124F50();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 1) {
        reg_d0.w = 9;
        func_00125060();
        if (D_0028E408 == 0) {
            reg_d0.w = 8;
            func_00125060();
            if (D_0028E408 == 0) {
                (*(s8 *)((u8 *)(reg_a4) + (2))) = 1;
                (*(u8 *)((u8 *)(reg_a4) + (3))) = 2U;
            }
        }
    }
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_2 == 2) {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            reg_d0.w = 0xE;
            func_00124F50();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 3U;
        }
    }
    temp_a0_3 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_3 == 3) {
        reg_d0.w = 0xE;
        func_00125060();
        if (D_0028E408 == 0) {
            reg_d0.w = 0xC;
            func_00124F50();
            reg_d0.w = 0xD;
            func_00124F50();
            (*(s8 *)((u8 *)(reg_a4) + (2))) = 0;
            reg_d0.w = 5;
            func_00124D90();
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 4U;
        }
    }
    temp_a0_4 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0_4 == 4) {
        reg_d0.w = 2;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_d0.w = 0xC;
            func_00125060();
            if (D_0028E408 == 0) {
                reg_d0.w = 0xD;
                func_00125060();
                if (D_0028E408 == 0) {
                    reg_d0.w = 0xF;
                    func_00124F50();
                    func_001B9DE0();
                }
            }
        }
    }
}
