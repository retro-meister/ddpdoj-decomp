#include "common.h"

s32 func_00124F50();
s32 func_00125120();
s32 func_001B23C0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B4380() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if ((*(u8 *)((u8 *)(reg_a6) + (0x3E))) != 0) {
        func_001B23C0();
        return;
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 0) {
        temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (4)));
        if (temp_v1 != 0) {
            (*(u16 *)((u8 *)(reg_a4) + (4))) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                func_00125120();
                (*(u8 *)((u8 *)(reg_a4) + (7))) = 1U;
            }
        }
    }
    if ((*(u8 *)((u8 *)(reg_a4) + (7))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            (*(u16 *)((u8 *)(reg_a6) + (0x4C))) -= 0xC0;
            (*(u8 *)((u8 *)(reg_a6) + (0x4B))) -= 2;
            (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 4;
            temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x2A)));
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 2;
                func_00124F50();
                (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
            }
        }
    }
}
