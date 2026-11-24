#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_00124DC0();
s32 func_00124F00();
s32 func_001251C0();
s32 func_00125250();
extern s8 D_0028E408;
extern u16 D_0028E89C;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F32D0() {
    u16 temp_a0;

    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_a0 - 1);
            if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
                reg_d0.w = 6;
                func_001251C0();
                reg_d0.w = 0xE;
                func_00124F00();
                (*(s16 *)((u8 *)(reg_a6) + (0x172))) = 0;
                reg_d0.w = 5;
                func_00124D90();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 6;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_d0.w = 0xE;
            func_00124DC0();
            (*(s16 *)((u8 *)(reg_a6) + (0x172))) = 0x1000;
            reg_d0.w = 0xC;
            func_00124B20();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
