#include "common.h"


s32 func_00124D90();
s32 func_001713B0();
extern u16 D_0026E8C0[];
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001BA3A0(void) {
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0x202;
    (*(s8 *)((u8 *)(reg_a4) + (9))) = 0xD;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 0x7050;
    (*(s16 *)((u8 *)(reg_a4) + (0x14))) = 0x2040;
    (*(s8 *)((u8 *)(reg_a4) + (0x11))) = 1;
    (*(s8 *)((u8 *)(reg_a4) + (0x10))) = 1;
    func_001713B0();
    reg_a0 = (u8 *)(D_0026E8C0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x118)));
    if ((s16) reg_d1.h[0] > 0x5) {
        reg_d1.h[0] = 5;
    }
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = (u16) reg_d1.h[0];
    (*(u16 *)((u8 *)(reg_a6) + (0x118))) += 1;
    if ((s16) (*(u16 *)((u8 *)(reg_a6) + (0x118))) > 0x5) {
        (*(u16 *)((u8 *)(reg_a6) + (0x118))) = 5U;
    }
    reg_d0.w = 6;
    func_00124D90();
}
