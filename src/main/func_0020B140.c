#include "common.h"

s32 func_00201160();
s32 func_00201D10();
s32 func_0020B5F0();
extern s32 D_0028E530;
extern u8 *reg_a0;
extern u8 *reg_a2;
extern u8 *reg_a6;

void func_0020B140(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    func_00201160();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B5F0();
    reg_d1.b[0] += (*(u8 *)((u8 *)(reg_a6) + (0x1A)));
    reg_d1.h[0] &= 0x3F;
    func_00201D10();
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d2.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (0))) = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}
