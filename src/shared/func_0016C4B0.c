#include "common.h"

s32 func_0016C260();
s32 func_0016C620();
s32 func_0019D230();
s32 func_00201C60();
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016C4B0(void) {
    u16 temp_a0;
    u16 temp_a0_2;
    u32 temp_a1;

    if ((*(u8 *)((u8 *)(reg_a6) + (0))) & 0x80) {
        func_0016C620();
        return;
    }
    reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a6) + (6)));
    reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a6) + (8)));
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d1.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (0)));
    temp_a1 = reg_d1.w;
    reg_a0 += 2;
    D_0028E484.h[1] = temp_a0;
    D_0028E484.h[0] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d1.w = temp_a1 + (s32) D_0028E484.w;
    reg_a0 += 2;
    temp_a0_2 = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_a0 += 2;
    reg_d3.h[0] = temp_a0_2;
    reg_a0 += 2;
    reg_a0 += (*(u16 *)((u8 *)(reg_a6) + (0xA)));
    reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a0) + (2)));
    reg_d4.h[0] = 0x1D;
    func_0019D230();
    if ((*(u8 *)((u8 *)(reg_a6) + (0xF))) != 0) {
        (*(u16 *)((u8 *)(reg_a6) + (2))) += 0x20;
    } else {
        func_00201C60();
    }
    (*(u8 *)((u8 *)(reg_a6) + (0xD))) -= 1;
    if ((*(u8 *)((u8 *)(reg_a6) + (0xD))) == 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0xC)));
        (*(u8 *)((u8 *)(reg_a6) + (0xF))) = 0U;
        (*(u16 *)((u8 *)(reg_a6) + (0xA))) += 4;
        if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0xA))) >= 0x78) {
            func_0016C260();
        }
    }
}
