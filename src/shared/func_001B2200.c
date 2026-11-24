#include "common.h"

s32 func_001384E0();
s32 func_00138650();
s32 func_001B1D70();
s32 func_001B21F0();
s32 func_0020ED40();
s32 func_0020EE20();
extern u8 D_0029BE00[];
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001B2200(void) {
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;

    temp_a0 = (*(u8 *)((u8 *)(reg_a5) + (3)));
    if (temp_a0 == 0) {
        func_001B1D70();
        return;
    }
    if (temp_a0 == 2) {
        func_001B21F0();
        return;
    }
    (*(s8 *)((u8 *)(reg_a5) + (2))) = 0;
    reg_a6 = D_0029BE00;
    reg_d7.w = 1;
    do {
        if ((*(u8 *)((u8 *)(reg_a6) + (1))) != 0) {
            temp_a0_2 = (*(u8 *)((u8 *)(reg_a6) + (0)));
            if (temp_a0_2 == 3) {
                func_001384E0();
                (*(u8 *)((u8 *)(reg_a6) + (0))) = 5U;
            }
            temp_a0_3 = (*(u8 *)((u8 *)(reg_a6) + (0)));
            if (temp_a0_3 == 5) {
                func_00138650();
            }
            temp_a0_4 = (*(u8 *)((u8 *)(reg_a6) + (0)));
            if (temp_a0_4 == 6) {
                func_0020ED40();
            }
            temp_a0_5 = (*(u8 *)((u8 *)(reg_a6) + (0)));
            if (temp_a0_5 == 7) {
                func_0020EE20();
            }
        }
        reg_a6 += 0x70;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = 3;
    reg_a6 = D_0029BE00;
    if ((*(u8 *)((u8 *)(reg_a6) + (1))) != 0) {
        reg_d0.h[0] &= 0xFFFE;
        if ((*(u8 *)((u8 *)(reg_a6) + (0))) == 8) {
            reg_d0.h[0] |= 1;
        }
    }
    if ((*(u8 *)((u8 *)(reg_a6) + (0x71))) != 0) {
        reg_d0.h[0] &= 0xFFFD;
        if ((*(u8 *)((u8 *)(reg_a6) + (0x70))) == 8) {
            reg_d0.h[0] |= 2;
        }
    }
    if (reg_d0.h[0] == 3) {
        (*(u8 *)((u8 *)(reg_a5) + (3))) = 2U;
    }
}
