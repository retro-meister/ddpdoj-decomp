#include "common.h"

extern u8 *reg_a6;

void func_001D6790(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x69))) == 2) {
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2F)));
        reg_d0.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x4F)));
        if (reg_d0.b[0] != 2) {
            reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x6B)));
            (*(u8 *)((u8 *)(reg_a6) + (0x6B))) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                (*(u8 *)((u8 *)(reg_a6) + (0x6B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x6A)));
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) -= 4;
                if (0 >= (s16) (*(u16 *)((u8 *)(reg_a6) + (0xA)))) {
                    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = 0U;
                    goto block_5;
                }
            }
        } else {
block_5:
            (*(u8 *)((u8 *)(reg_a6) + (0x69))) = 0U;
        }
    }
}
