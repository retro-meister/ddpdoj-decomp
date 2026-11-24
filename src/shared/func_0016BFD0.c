#include "common.h"


s32 func_0019D230();
extern u32 D_0026AE30[];
extern Reg32 D_0028E484;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_0016BFD0(void) {
    u16 temp_a1;
    u32 temp_a0;

    (*(u8 *)((u8 *)(reg_a6) + (0xD))) -= 1;
    if ((s8) (*(u8 *)((u8 *)(reg_a6) + (0xD))) < 0) {
        (*(u8 *)((u8 *)(reg_a6) + (0xD))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0xC)));
        (*(u16 *)((u8 *)(reg_a6) + (0xE))) += 4;
        (*(u16 *)((u8 *)(reg_a6) + (0xE))) &= 0xF;
    }
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (2)));
    reg_d1.h[0] += 0xFC00 & 0xFFFF;
    D_0028E484.w = reg_d1.w;
    reg_d1.h[1] = reg_d1.h[0];
    reg_d1.h[0] = D_0028E484.h[1];
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
    reg_a0 = (u8 *)(D_0026AE30);
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    temp_a1 = (*(u16 *)((u8 *)(reg_a6) + (0xE)));
    reg_a0 += temp_a1;
    temp_a0 = *(u32 *)reg_a0;
    reg_d2.w = temp_a0;
    reg_d3.h[0] = 0x420;
    reg_d4.h[0] = 0x1C;
    func_0019D230();
}
