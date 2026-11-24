#include "common.h"

extern u8 *reg_a6;

void func_0019DCE0(void) {
    (*(u16 *)((u8 *)(reg_a6) + (0x54))) -= 4;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x54))) < 0) {
        (*(u16 *)((u8 *)(reg_a6) + (0x54))) = 8U;
    }
    reg_d7.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x54)));
}
