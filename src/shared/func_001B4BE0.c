#include "common.h"

extern s8 D_0028E408;

s32 func_001713B0();
s32 func_00171400();
s32 func_002010A0();
s32 func_00202730();
extern u16 D_0026E070[];
extern u16 D_0026E080[];
extern u8 *reg_a0;
extern u8 *reg_a4;

void func_001B4BE0(void) {
    func_00171400();
    (*(s16 *)((u8 *)(reg_a4) + (2))) = 0x1001;
    (*(s16 *)((u8 *)(reg_a4) + (4))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 8;
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 0x80U;
    func_00202730();
    if (D_0028E408 == 0) {
        func_002010A0();
        reg_d1.b[0] += reg_d0.b[0];
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) = (u8) reg_d1.b[0];
    }
    func_001713B0();
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)(D_0026E070);
    (*(u16 *)((u8 *)(reg_a4) + (0xC))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)(D_0026E080);
    (*(u16 *)((u8 *)(reg_a4) + (6))) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
}
