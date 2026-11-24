#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_00124DC0();
s32 func_00124F00();
s32 func_001F5630();
s32 func_001F56F0();
s32 func_001F57C0();
s32 func_0020ED10();
extern u8 *reg_a4;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F1E20() {
    u16 temp_v1;
    u8 *temp_a0;

    temp_v1 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    temp_a0 = reg_a4 + 2;
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_v1 - 1);
        if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
            reg_d0.w = 0;
            func_00124F00();
            reg_d0.w = 1;
            func_00124F00();
            reg_d0.w = 9;
            func_00124F00();
            reg_d0.w = 2;
            func_00124F00();
            reg_d0.w = 5;
            func_00124F00();
            reg_d0.w = 4;
            func_00124F00();
            reg_d0.w = 3;
            func_00124F00();
            reg_d0.w = 8;
            func_00124F00();
            reg_d0.w = 7;
            func_00124F00();
            reg_d0.w = 6;
            func_00124F00();
            reg_d0.w = 0xB;
            func_00124DC0();
            reg_d0.w = 0xC;
            func_00124DC0();
            reg_d0.w = 0xD;
            func_00124DC0();
            reg_d0.w = 0xF;
            func_00124DC0();
            reg_d0.w = 1;
            func_00124D90();
            (*(s8 *)((u8 *)(reg_a6) + (0x10F))) = 1;
            (*(s16 *)((u8 *)(reg_a6) + (0x172))) = 0;
            reg_tmp.w = 0x23000;
            (*(u16 *)((u8 *)(reg_a5) + (0x16))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a5) + (0x18))) = (u16) reg_tmp.h[0];
            func_001F5630();
            func_001F56F0();
            func_001F57C0();
            func_0020ED10();
        }
    } else {
        (*(u16 *)((u8 *)(reg_a4) + (4))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a4) + (4))) == 0) {
            reg_d0.w = 0xA;
            func_00124B20();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
