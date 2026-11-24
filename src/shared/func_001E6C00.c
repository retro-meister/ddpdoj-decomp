#include "common.h"

extern u8 *reg_a6;

void func_001E6C00(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x27)));
    (*(u8 *)((u8 *)(reg_a6) + (0x27))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0x27))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x26)));
        (*(u16 *)((u8 *)(reg_a6) + (0x28))) += 4;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x28))) == 0x20) {
            (*(u16 *)((u8 *)(reg_a6) + (0x28))) = 0U;
        }
    }
}
