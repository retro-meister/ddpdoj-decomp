#include "common.h"

s32 func_0012E350();                            /* extern */
extern u8 *reg_a6;

void func_0012EC00(void) {
    func_0012E350();
    reg_tmp.w = 0x220;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    (*(u16 *)((u8 *)(reg_a6) + (6))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (8))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0xE))) = 0x410;
    reg_tmp.w = 0x17;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
}
