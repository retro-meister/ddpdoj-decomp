#include "common.h"

s32 func_00133070();
s32 func_0014BEC0();
s32 func_0014BF90();
s32 func_0018D410();
s32 func_0019C470();
s32 func_00201160();
s32 func_0022B660();
s32 func_002376F0();
extern u16 D_0026A380[];
extern u16 D_0026A3A0[];
extern u16 D_0026A3C0[];
extern u8 D_0028ED64;
extern u8 D_0028ED7C;
extern u8 D_0028ED80;
extern u8 *reg_a0;
extern u8 *reg_a5;

void func_0014BFF0(void) {
    u16 t;
    u8 st;

    st = *(u8 *)(reg_a5 + 3);
    if (st == 0) {
        func_0014BEC0();
        return;
    }
    if (st == 2) {
        if ((D_0028ED64 != 0) && (func_00133070(reg_a5) != 0)) {
            if (func_0022B660() == 0) {
                return;
            }
            goto block_1;
        }
        if ((D_0028ED7C == 2) || (D_0028ED80 != 0)) {
            func_002376F0();
            return;
        }
block_1:
        D_0028ED7C = 0;
        func_0014BF90();
        return;
    }
    t = *(u16 *)(reg_a5 + 0x1A);
    if (t == 0) goto next_1;
    *(u16 *)(reg_a5 + 0x1A) = t - 1;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) goto next_1;
    func_0018D410();
next_1:
    *(u16 *)(reg_a5 + 4) -= 1;
    if ((s16) *(u16 *)(reg_a5 + 4) >= 0) goto next_2;
    *(u8 *)(reg_a5 + 3) = 2;
next_2:
    if (*(u16 *)(reg_a5 + 0x10) != 0) goto next_6;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_3;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d1.h[0] != 0x1C) goto next_3;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u16 *)(reg_a5 + 0x18) += 1;
    if (*(u16 *)(reg_a5 + 0x18) == 0x14) goto next_5;
    func_00201160();
    reg_d0.h[0] >>= 3;
    st = reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x17) = st;
    if (st != 0) goto next_3;
    *(u8 *)(reg_a5 + 0x16) += 1;
    if ((s32) *(u8 *)(reg_a5 + 0x16) < 3) goto next_3;
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    reg_a0 = (u8 *)(D_0026A380);
    if (*(u8 *)(reg_a5 + 0x17) != 0) goto next_4;
    reg_a0 = (u8 *)(D_0026A3A0);
next_4:
    *(u16 *)(reg_a5 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    goto next_8;
next_5:
    *(u16 *)(reg_a5 + 0x10) = 1;
    *(u16 *)(reg_a5 + 0x14) = 0;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_8;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d0.h[0] != 0x1C) goto next_7;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u8 *)(reg_a5 + 3) = 2;
next_7:
    reg_a0 = (u8 *)(D_0026A3C0);
    *(u16 *)(reg_a5 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
next_8:
    reg_d1.h[1] = *(u16 *)(reg_a5 + 8);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d1.w += 0xE600E400;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0xC);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0xE);
    reg_d3.h[0] = 0x1AE0;
    reg_d4.h[0] = 2;
    func_0019C470();
}
