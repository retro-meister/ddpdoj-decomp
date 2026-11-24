#include "common.h"

s32 func_0019C5B0();
extern u8 *reg_a6;

void func_00203850(void) {
    if (*(u16 *)(reg_a6 + 0x64) == 0) goto block_rts;
    if (*(u8 *)(reg_a6 + 0x34) != 0) goto block_rts;
    reg_d1.w = 0x34010D00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x46);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xACE;
    reg_d3.h[0] = 0xC78;
    reg_d4.h[0] = 0x13;
    func_0019C5B0();
    reg_d1.w = 0x21410D00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x46);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d2.w = 0xACF;
    func_0019C5B0();
    reg_d1.w = 0x21810E00;
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 0x48);
    reg_d2.w = 0xADB;
    reg_d3.h[0] = 0x1650;
    reg_d4.h[0] = 0x14;
    func_0019C5B0();
    reg_d1.h[0] = 0x1640;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x48);
    reg_d2.w = 0xADC;
    func_0019C5B0();
block_rts:
    return;
}
