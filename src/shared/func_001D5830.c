#include "common.h"

extern s8 D_0028E408;

s32 func_00202140();
extern u8 *reg_a6;

void func_001D5830(void) {
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x22)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x24)));
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x26)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x28)));
    func_00202140();
    if (D_0028E408 != 0) {
        reg_d1.h[0] = 0x20;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x91))) = (u8) reg_d1.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x42)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x44)));
    reg_d0.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x46)));
    reg_d1.h[0] += (*(u16 *)((u8 *)(reg_a6) + (0x48)));
    func_00202140();
    if (D_0028E408 != 0) {
        reg_d1.h[0] = 0x20;
    }
    (*(u8 *)((u8 *)(reg_a6) + (0x90))) = (u8) reg_d1.b[0];
}
