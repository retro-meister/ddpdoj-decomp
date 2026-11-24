#include "common.h"


extern s8 D_0028E408;

s32 func_001FDDD0();
s32 func_001FF000();
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001FE990(s32 arg1) {
    s32 var_a1;
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    var_a1 = arg1;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0) {
        var_a1 = 0xF0;
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 1U;
        (*(u16 *)((u8 *)(reg_a6) + (0x30))) = 0xF0U;
        (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0x10;
    }
    temp_v1 = (*(u16 *)((u8 *)(reg_a5) + (0x1E)));
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = (u16) (temp_v1 - 0x40);
        if ((s16) (*(u16 *)((u8 *)(reg_a5) + (0x1E))) <= 0) {
            (*(u16 *)((u8 *)(reg_a5) + (0x1E))) = 0U;
        }
    }
    temp_a0 = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    if (temp_a0 == 1) {
        reg_d2.h[0] = 0x5C00;
        reg_d3.h[0] = 0x1C00;
        func_001FF000();
        if (D_0028E408 == 0) {
            (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
            (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 2U;
        }
    }
    temp_a0_2 = (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    if (temp_a0_2 == 2) {
        (*(u16 *)((u8 *)(reg_a6) + (0x30))) -= 1;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x30))) == 0) {
            reg_d0.w = 1;
            func_001FDDD0();
        }
    }
}
