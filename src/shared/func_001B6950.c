#include "common.h"


s32 func_001713B0();
s32 func_001B69E0();
extern u16 D_0026E140[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001B6950(void) {
    u16 temp_a0;

    func_001713B0();
    reg_a0 = (u8 *)(D_0026E140);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    temp_a0 = *(u16 *)reg_a0;
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = temp_a0;
    (*(s8 *)((u8 *)(reg_a4) + (0xD))) = 0x20;
    func_001B69E0();
}
