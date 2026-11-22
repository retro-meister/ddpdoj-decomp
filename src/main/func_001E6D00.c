#include "common.h"

s32 func_001E6C70();
s32 func_00202500();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E6D00() {
    u8 temp_a0;
    u8 temp_a0_2;

    if ((*(u8 *)((u8 *)(reg_a4) + (3))) == 0) {
        (*(u16 *)((u8 *)(reg_a4) + (6))) -= 1;
        if ((s16) (*(u16 *)((u8 *)(reg_a4) + (6))) < 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = 1U;
        }
    }
    temp_a0 = (*(u8 *)((u8 *)(reg_a4) + (3)));
    if (temp_a0 == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (5)));
        (*(u8 *)((u8 *)(reg_a4) + (5))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (5))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (4)));
            reg_d0.w = 0;
            reg_d1.w = 0;
            reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x11A)));
            reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a4) + (2)));
            func_00202500();
            (*(u8 *)((u8 *)(reg_a6) + (0x11A))) = (u8) reg_d1.b[0];
            temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (2)));
            if (temp_a0_2 == reg_d1.b[0]) {
                func_001E6C70();
            }
        }
    }
}
