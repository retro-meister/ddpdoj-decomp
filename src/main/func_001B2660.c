#include "common.h"

s32 func_001B23C0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B2660(void) {
    if ((*(u8 *)((u8 *)(reg_a6) + (0x7E))) != 0) {
        func_001B23C0();
        return;
    }
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        (*(u16 *)((u8 *)(reg_a6) + (0x6A))) += 4;
        if ((*(s16 *)((u8 *)(reg_a6) + (0x6A))) > 0xc) {
            (*(u16 *)((u8 *)(reg_a6) + (0x6A))) = 0U;
        }
    }
}
