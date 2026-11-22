#include "common.h"

extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E8EF0(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x132))) += 4;
        if ((*(u16 *)((u8 *)(reg_a6) + (0x132))) == 0x20) {
            (*(u16 *)((u8 *)(reg_a6) + (0x132))) = 0U;
        }
    }
}
