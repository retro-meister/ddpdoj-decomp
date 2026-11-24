#include "common.h"

s32 func_0019C5B0();
extern u8 D_0028C148[];
extern u8 D_0028C868[];
extern u16 D_0028E3E4;
extern u16 D_0028E3EC;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a6;

void func_00203F50(void) {
    u32 i;

    if (*(u16 *)(reg_a6 + 0x54) == 0) goto block_rts;
    if (D_0028E3EC == 0) goto block_rts;
    reg_a0 = (u8 *)D_0028C148;
    reg_a1 = (u8 *)D_0028C868;
    i = reg_d5.h[0];
    reg_tmp.h[1] = (i != 0) ? *(u16 *)(reg_a0 + ((s16) i & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16) i + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) i + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = D_0028E3E4;
    reg_d0.h[0] *= 2;
    reg_d0.h[0] &= 4;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = (i != 0) ? *(u16 *)(reg_a1 + ((s16) i & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = (((u16) i + 2) != 0) ? *(u16 *)(reg_a1 + ((s16) ((u16) i + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= 0xFA00;
    reg_d1.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] -= 0xFC00;
    reg_d1.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d4.h[0] = 0x1A;
    func_0019C5B0();
block_rts:
    return;
}
