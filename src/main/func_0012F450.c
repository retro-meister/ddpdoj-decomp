#include "common.h"

s32 func_0012E3D0();                            /* extern */
extern u8 *reg_a6;

void func_0012F450(void) {
    func_0012E3D0();
    reg_tmp.w = 0x23;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0x1A6;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    (*(s16 *)((u8 *)(reg_a6) + (0x28))) = 0x404;
    (*(s8 *)((u8 *)(reg_a6) + (0x1B))) = 0;
}
