#include "common.h"

s32 func_0013A780();
s32 func_0018D500();
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001E2FD0(void) {
    func_0018D500();
    reg_d0.h[0] = 0xC;
    func_0013A780();
    (*(u16 *)((u8 *)(reg_a0) + (2))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (2)));
    (*(u16 *)((u8 *)(reg_a0) + (4))) = (u16) (*(u16 *)((u8 *)(reg_a6) + (4)));
    (*(u16 *)((u8 *)(reg_a0) + (0x1E))) = 8;
    (*(u16 *)((u8 *)(reg_a0) + (0x12))) = 0;
    (*(u16 *)((u8 *)(reg_a0) + (0x14))) = 0;
    (*(u16 *)((u8 *)(reg_a0) + (0x26))) = 0xFE00;
    (*(u16 *)((u8 *)(reg_a0) + (0x10))) = 2;
}
