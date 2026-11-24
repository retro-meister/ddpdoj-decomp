#include "common.h"

s32 func_00146690();
extern u16 D_0028E000;
extern u16 D_0028E004;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_00147470(void) {
    *(u16 *) (reg_a6 + 2) = reg_d0.h[1];
    *(u16 *) (reg_a6 + 4) = reg_d0.h[0];
    if (*(u16 *) (reg_a6 + 0x28) == reg_d1.h[0]) goto next_1;
    *(u16 *) (reg_a6 + 0x28) = reg_d1.h[0];
    reg_d1.h[0] *= 2;
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x1E);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x20);
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d1.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d1.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = ((u16) reg_d1.h[0] + 2) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d1.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    *(u16 *) (reg_a6 + 0x2A) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 0x2C) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 6) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 8) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u16 *) (reg_a6 + 0xE) = *(u16 *) reg_a0;
    reg_a0 += 2;
    *(u8 *) (reg_a6 + 0x23) = 0;
    *(u16 *) (reg_a6 + 0x24) = *(u16 *) (reg_a6 + 0x26);
next_1:
    reg_tmp.b[0] = *(u8 *) (reg_a6 + 0x23);
    *(u8 *) (reg_a6 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_2;
    *(u8 *) (reg_a6 + 0x23) = *(u8 *) (reg_a6 + 0x22);
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x24);
    reg_tmp.h[1] = *(u16 *) (reg_a6 + 0x2A);
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x2C);
    reg_a0 = (u8 *) reg_tmp.w;
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0]) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = (reg_d0.h[0] + 2) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = *(u16 *) (reg_a6 + 0x24);
    *(u16 *) (reg_a6 + 0x24) -= 4;
    if ((s32) reg_tmp.h[0] >= 4) goto next_2;
    *(u16 *) (reg_a6 + 0x24) = *(u16 *) (reg_a6 + 0x26);
next_2:
    switch (*(u16 *) (reg_a6 + 0x1A)) { case 0: goto next_3; }
    if (D_0028E004 == 0) goto next_4;
    return;
next_3:
    if (D_0028E000 != 0) return;
next_4:
    func_00146690();
}
