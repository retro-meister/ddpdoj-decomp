#include "common.h"

extern u8 *reg_a6;

void func_001DF300(void) {
    u16 temp_v1;

    temp_v1 = (*(u16 *)((u8 *)(reg_a6) + (0x5E)));
    if (temp_v1 != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x5E))) = (u16) (temp_v1 - 1);
        if ((*(u16 *)((u8 *)(reg_a6) + (0x5E))) == 0) {
            reg_tmp.w = 0x1D9C;
            (*(u16 *)((u8 *)(reg_a6) + (0x4A))) = (u16) reg_tmp.h[1];
            (*(u16 *)((u8 *)(reg_a6) + (0x4C))) = (u16) reg_tmp.h[0];
        }
    }
}
