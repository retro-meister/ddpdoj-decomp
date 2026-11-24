#include "common.h"

s32 func_0014E030();
extern u8 D_0026C0B0[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E75C0(void) {
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a4) + (3)));
    (*(u8 *)((u8 *)(reg_a4) + (3))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        (*(u8 *)((u8 *)(reg_a4) + (3))) = (u8) (*(u8 *)((u8 *)(reg_a4) + (2)));
        reg_d0.w = 0x4D;
        func_0014E030();
        reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
        reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
        reg_a1 = D_0026C0B0;
        reg_a1 += (*(u16 *)((u8 *)(reg_a4) + (4)));
        reg_tmp.h[1] = (*(u16 *)((u8 *)(reg_a1) + (0)));
        reg_tmp.h[0] = (*(u16 *)((u8 *)(reg_a1) + (2)));
        reg_d0.w += reg_tmp.w;
        (*(u16 *)((u8 *)(reg_a0) + (0x16))) = (u16) reg_d0.h[1];
        (*(u16 *)((u8 *)(reg_a0) + (0x18))) = (u16) reg_d0.h[0];
        (*(u16 *)((u8 *)(reg_a4) + (4))) += 4;
        (*(u16 *)((u8 *)(reg_a4) + (4))) &= 0xF;
    }
}
