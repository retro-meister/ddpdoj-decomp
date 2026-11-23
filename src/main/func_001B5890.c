#include "common.h"

extern s8 D_0028E408;

s32 func_00171400();
s32 func_001B5990();
s32 func_002011D0();
s32 func_002026F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B5890(void) {
    u16 temp_a0;
    u8 temp_a0_2;

    func_00171400();
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 4;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x820;
    func_002011D0();
    reg_d0.b[0] -= 1;
    (*(u8 *)((u8 *)(reg_a4) + (6))) += reg_d0.b[0];
    reg_d0.h[1] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d0.w += 0xF6C00140;
    (*(u16 *)((u8 *)(reg_a4) + (8))) = (u16) reg_d0.h[1];
    temp_a0 = reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a4) + (0xA))) = temp_a0;
    (*(u8 *)((u8 *)(reg_a4) + (0xD))) = 0x80U;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a4) + (8)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a4) + (0xA)));
    func_002026F0();
    if (D_0028E408 != 0) {
        func_001B5990();
        return;
    }
    (*(u8 *)((u8 *)(reg_a4) + (0xD))) = (u8) reg_d1.b[0];
    temp_a0_2 = (*(u8 *)((u8 *)(reg_a4) + (2)));
    if (temp_a0_2 != 2) {
        func_001B5990();
    }
}
