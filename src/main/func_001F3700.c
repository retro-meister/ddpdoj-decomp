#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_001251C0();
s32 func_00125250();
extern s8 D_0028E408;
extern u16 D_0028E89C;
extern u8 *reg_a4;

void func_001F3700() {
    u16 temp_a0;

    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_a0 - 1);
            if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
                reg_d0.w = 0xA;
                func_001251C0();
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xA;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_d0.w = 0xF;
            func_00124B20();
            reg_d0.w = 4;
            func_00124D90();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
