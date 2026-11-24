#include "common.h"

s32 func_002026F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a6 + ((s16)(d) & ~1)) : *(u16 *)reg_a6)

void func_001D9520(u32 arg0, u8 arg1) {
    *(u16 *)(reg_a4 + 4) = 4;
    *(u16 *)(reg_a4 + 6) = 0x50;
    *(u16 *)(reg_a4 + 8) = -4;
    *(u16 *)(reg_a4 + 0xA) = 0x40;
    *(u16 *)(reg_a4 + 0xC) = 2;
    *(u16 *)(reg_a4 + 0x10) = 0;
    *(u16 *)(reg_a4 + 0x12) = 0xC;
    *(u16 *)(reg_a4 + 0x14) = 5;
    reg_a4[0x17] = 0;
    reg_a4[0x16] = arg1;
    reg_a4[0x19] = 1;
    *(u16 *)(reg_a4 + 0x1A) = 0x808;
    reg_d0.h[0] = LOOKUP(arg0);
    reg_d1.h[0] = LOOKUP(arg0 + 2);
    func_002026F0();
    reg_a4[0xF] = reg_d1.b[0];
    reg_d0.b[0] = reg_a4[0x16];
    reg_d0.b[0] = (s8) reg_d0.b[0] * 0x10;
    reg_a4[0xF] -= reg_d0.b[0];
}
