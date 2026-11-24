#include "common.h"

s32 func_002011A0();
extern u16 D_00264540[];
extern u32 D_0028D9F0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EC810(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264540);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9F0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    (*(s8 *)((u8 *)(reg_a4) + (0xF))) = 0x20;
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0xE))) *= -1;
    }
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1F8)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1F7)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
}
