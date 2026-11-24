#include "common.h"

s32 func_00124B20();
s32 func_00124D90();
s32 func_001251C0();
s32 func_00125250();
extern s8 D_0028E408;
extern u16 D_0028E89C;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001F37A0() {
    u16 temp_a0;

    temp_a0 = (*(u16 *)((u8 *)(reg_a4) + (2)));
    if (temp_a0 != 0) {
        if (D_0028E89C == 0) {
            (*(u16 *)((u8 *)(reg_a4) + (2))) = (u16) (temp_a0 - 1);
            if ((*(u16 *)((u8 *)(reg_a4) + (2))) == 0) {
                reg_d0.w = 0xB;
                func_001251C0();
                (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 4;
#ifdef DEATH_LABEL
                (*(s8 *)((u8 *)(reg_a6) + (0x21B))) = 4;
#endif
                goto block_4;
            }
        }
    } else {
block_4:
        reg_d0.w = 0xB;
        func_00125250();
        if (D_0028E408 == 0) {
            reg_d0.w = 0x10;
            func_00124B20();
            reg_d0.w = MAIN_OR_DEATH_LABEL(8, 0xD);
            func_00124D90();
            (*(s16 *)((u8 *)(reg_a4) + (0))) = 0;
        }
    }
}
