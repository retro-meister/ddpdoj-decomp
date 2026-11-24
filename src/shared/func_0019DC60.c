#include "common.h"

extern u8 *reg_a6;

void func_0019DC60(void) {
    (*(u16 *)((u8 *)(reg_a6) + (0x52))) -= 4;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x52))) < 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x52))) = 8U;
    }
    reg_d6.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x52)));
}
