#include "common.h"

s32 func_001C1A30();
s32 func_002011D0();
s32 func_00202140();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001C1930() {
    (*(u8 *)((u8 *)(reg_a4) + (3))) = 0;
    (*(s16 *)((u8 *)(reg_a4) + (6))) = 0x1000;
    (*(s16 *)((u8 *)(reg_a4) + (0xC))) = 0x2010;
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x82)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0x84)));
    func_00202140();
    reg_d1.b[0] &= 0x3F;
    (*(u8 *)((u8 *)(reg_a4) + (9))) = (u8) reg_d1.b[0];
    reg_d0.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA2)));
    reg_d1.h[0] = (*(u16 *)((u8 *)(reg_a6) + (0xA4)));
    func_00202140();
    reg_d1.b[0] &= 0x3F;
    (*(u8 *)((u8 *)(reg_a4) + (8))) = (u8) reg_d1.b[0];
    (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 1;
    func_002011D0();
    if (reg_d0.h[0] == 0) {
        (*(u8 *)((u8 *)(reg_a4) + (0xB))) = 0xFF;
    }
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) = 1;
    func_002011D0();
    if (reg_d0.h[0] != 0) {
        func_001C1A30();
        return;
    }
    (*(u8 *)((u8 *)(reg_a4) + (0xA))) = 0xFF;
    func_001C1A30();
}
