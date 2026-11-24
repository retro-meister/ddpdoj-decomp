#include "common.h"

extern u8 *reg_a6;

void func_001FEF70(void) {
    u8 temp_v1;

    if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 1U;
        (*(s8 *)((u8 *)(reg_a6) + (0x1A))) = 0;
    }
    temp_v1 = (*(u8 *)((u8 *)(reg_a6) + (0x1B)));
    if (temp_v1 != 8) {
        (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = (u8) (temp_v1 + 1);
        if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0x1B))) >= 8) {
            (*(u8 *)((u8 *)(reg_a6) + (0x1B))) = 8U;
        }
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    if ((s16) reg_d0.h[0] < -0x67FF) {
        (*(s8 *)((u8 *)(reg_a6) + (0x9F))) = 1;
    }
}
