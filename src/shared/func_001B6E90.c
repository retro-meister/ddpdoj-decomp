#include "common.h"

s32 func_00171400();
s32 func_002026F0();
extern s8 D_0028E408;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001B6E90(void) {
    (*(s16 *)((u8 *)(reg_a4) + (8))) = 8;
    (*(s16 *)((u8 *)(reg_a4) + (0xA))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xAC)));
    reg_d0.h[0] += 0x20;
    reg_d0.b[0] += reg_d0.b[0];
    reg_d0.b[0] += reg_d0.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) reg_d0.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    func_002026F0();
    if (D_0028E408 == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0x11))) = (u8) reg_d1.b[0];
    }
    func_00171400();
}
