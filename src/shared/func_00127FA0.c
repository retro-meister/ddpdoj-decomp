#include "common.h"

void func_001257E0(void);
void func_00125FF0(void);
void func_0019C3E0(void);
extern u8 *reg_a6;

void func_00127FA0(void) {
    u32 sd6;
    u8 t;
    u32 t1;

    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    switch (*(u8 *)(reg_a6 + 0x18)) {
        case 0:
            goto block_3;
    }
    *(u8 *)(reg_a6 + 0x19) -= 1;
    t = *(u8 *)(reg_a6 + 0x19);
    if ((s8)t < 0) goto block_2;
    if (t == 0) {
        *(u8 *)(reg_a6 + 0x15) = 0x28;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w += reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    goto block_1;
block_2:
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0xA);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xC);
    reg_tmp.w -= reg_d0.w;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
block_1:
    sd6 = reg_d6.w;
    reg_d6.w = 0x40004000;
    func_0019C3E0();
    reg_d6.w = sd6;
    goto block_4;
block_3:
    func_001257E0();
block_4:
    reg_a6 += 0x2C;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) {
        func_00125FF0();
    }
}
