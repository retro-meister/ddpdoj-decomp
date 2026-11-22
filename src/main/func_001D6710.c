#include "common.h"

extern u8 *reg_a6;

void func_001D6710(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x69))) == 1) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x6B)));
        (*(u8 *)((u8 *)(reg_a6) + (0x6B))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a6) + (0x6B))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x6A)));
            (*(u16 *)((u8 *)(reg_a6) + (0xA))) += 4;
            if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0xA))) >= 0x1C) {
                (*(u16 *)((u8 *)(reg_a6) + (0xA))) = 0x1CU;
                (*(u8 *)((u8 *)(reg_a6) + (0x69))) = 0U;
            }
        }
    }
}
