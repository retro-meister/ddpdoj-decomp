#include "common.h"

s32 func_001D71C0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001D7660() {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0xA8))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0xA8))) >= 0x20) {
            (*(u16 *)((u8 *)(reg_a6) + (0xA8))) = 0x20U;
            func_001D71C0();
        }
    }
}
