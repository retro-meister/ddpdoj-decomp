#include "common.h"

s32 func_00124DC0();
s32 func_00124F00();
s32 func_001D71C0();
s32 func_001E8710();
s32 func_001E8730();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D7210() {
    u16 temp_a0;

    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x106))) += 4;
        temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x106)));
        if (temp_a0 == 0x3C) {
            (*(u16 *)((u8 *)(reg_a6) + (0x106))) = 0U;
            reg_d0.w = 6;
            func_00124F00();
            reg_d0.w = 9;
            func_00124DC0();
            reg_d0.w = 7;
            func_00124DC0();
            reg_d0.w = 8;
            func_00124DC0();
            (*(s16 *)((u8 *)(reg_a6) + (0x30))) = 0xC00;
            (*(s16 *)((u8 *)(reg_a6) + (0x32))) = 0xD80;
            (*(s16 *)((u8 *)(reg_a6) + (0x34))) = 0x900;
            (*(s16 *)((u8 *)(reg_a6) + (0x36))) = 0x900;
            reg_d0.h[0] = 0x80;
            func_001E8730();
            reg_d0.h[0] = 0xA0;
            func_001E8730();
            func_001E8710();
            func_001D71C0();
        }
    }
}
