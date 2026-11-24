#include "common.h"

s32 func_00201160();
s32 func_002011A0();
extern u16 D_00264380[];
extern u32 D_0028D9E0;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001EB300(void) {
    u16 *temp_a0;
    reg_a0 = (u8 *)(D_00264380);
    reg_a1 = (u8 *)(reg_a4 + 2);
    reg_d0.w = ((u32) D_0028D9E0 >> 1) - 1;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        temp_a0 = (u16 *)(reg_a0 + 2);
        reg_a0 = (u8 *)(temp_a0);
        reg_a1 += 2;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    func_00201160();
    reg_d0.b[0] += 0x60;
    (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) reg_d0.b[0];
    func_002011A0();
    if (0 > reg_d0.sb[0]) {
        (*(u8 *)((u8 *)(reg_a4) + (0x10))) *= -1;
    }
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1DB)));
    (*(u8 *)((u8 *)(reg_a4) + (5))) += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (4))) += reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1DC)));
    (*(u16 *)((u8 *)(reg_a4) + (8))) += reg_d0.h[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x1DE)));
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) += reg_d0.h[0];
}
