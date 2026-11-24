#include "common.h"

s32 func_00124D90();
s32 func_0013B8B0();
s32 func_001E62B0(s32, s32, s32, s32);
extern u8 D_0026F340[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001E6210(void) {
    reg_d0.w = 5;
    func_00124D90();
    reg_a0 = D_0026F340;
    func_0013B8B0();
    (*(s8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(u16 *)((u8 *)(reg_a4) + (4))) = 0x10;
    (*(u16 *)((u8 *)(reg_a4) + (6))) = 0xFF02;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = 0xFF04;
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = 0;
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = 0xC0C;
    (*(u16 *)((u8 *)(reg_a4) + (0xE))) = 3;
    (*(u16 *)((u8 *)(reg_a4) + (0x10))) = 4;
    (*(u16 *)((u8 *)(reg_a4) + (0x12))) = 0;
    func_001E62B0(3, 0xC0C, 0xFF04, 0xFF02);
}
