#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CDE10(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x8D))) == 0) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
        (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
            goto block_3;
        }
    } else {
block_3:
        (*(u16 *)((u8 *)(reg_a6) + (0xA6))) += 4;
        if ((*(u16 *)((u8 *)(reg_a6) + (0xA6))) == 0x40) {
            (*(u16 *)((u8 *)(reg_a6) + (0xA6))) = 0U;
        }
    }
}
