#include "common.h"

s32 func_0019D290();
extern u16 D_0028E3EC;
extern u16 D_0028E988;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001255F0(void) {
    u16 t;

    if ((s32) D_0028E988 < 0x23) goto block_call;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x24);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x26);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d2.h[0] = *(u16 *)(reg_a0 + 4);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] -= reg_d2.h[0];
    t = reg_d0.h[0];
    if (((s64) ((s64) t << 0x30) >> 0x30) < 0) {
        reg_d0.h[0] = (t << 16) - t;
    }
    if ((s32) reg_d0.h[0] < 0x600) goto block_call;
    reg_d0.w = 1;
    reg_d0.h[0] &= reg_d7.h[0];
    switch (D_0028E3EC - reg_d0.h[0]) { case 0: return; }
block_call:
    func_0019D290();
}
