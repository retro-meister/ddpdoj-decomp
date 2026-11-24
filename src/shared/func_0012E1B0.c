#include "common.h"

s32 func_0012E3D0();                            /* extern */
extern u8 *reg_a6;

void func_0012E1B0(void) {
    func_0012E3D0();
    (*(u16 *)((u8 *)(reg_a6) + (0x1E))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x30)));
    (*(u16 *)((u8 *)(reg_a6) + (0x20))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (0x32)));
    reg_tmp.w = 0x1A6;
    (*(u16 *)((u8 *)(reg_a6) + (0xA))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0xC))) = (u16) reg_tmp.h[0];
    reg_tmp.w = 5;
    (*(u16 *)((u8 *)(reg_a6) + (0x22))) = (u16) reg_tmp.h[1];
    (*(u16 *)((u8 *)(reg_a6) + (0x24))) = (u16) reg_tmp.h[0];
}
