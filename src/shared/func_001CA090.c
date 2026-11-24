#include "common.h"

s32 func_001C9750();
s32 func_001C9B60();
s32 func_002012F0();
s32 func_00201C60();
s32 func_002021F0();
s32 func_00202500();
s32 func_00202B50();
extern u16 D_0028E4AA;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001CA090() {
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    func_002021F0();
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    func_00202500();
    (*(u8 *)((u8 *)(reg_a6) + (0x1A))) = (u8) reg_d1.b[0];
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (0xD)));
    (*(u8 *)((u8 *)(reg_a4) + (0xD))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (0xC)));
        func_001C9B60();
    }
    func_00201C60();
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d3.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    func_00202B50();
    if ((s16) reg_d0.h[0] < 0x101) {
        D_0028E4AA = (*(u16 *)((u8 *)(reg_a4) + (4)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (6)));
        (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) D_0028E4AA;
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) = (u16) reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
        func_002012F0();
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        (*(u16 *)((u8 *)(reg_a4) + (0xA))) += reg_d0.h[0];
    }
    func_001C9750();
}
