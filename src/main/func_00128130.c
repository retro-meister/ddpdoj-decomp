#include "common.h"

void func_001257E0(void);
void func_00128320(void);
void func_001285A0(void);
void func_0019C3E0(void);
extern u16 D_0028E3EC;
extern u8 *reg_a6;

void func_00128130(void) {
    u32 sd6;
    u8 t;

    if ((reg_d1.w & 0x2000) && (D_0028E3EC != 0)) {
        *(u8 *)(reg_a6 + 0x1C) ^= 0x10;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x1A);
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u8 *)(reg_a6 + 0x15) -= 1;
    if (*(u8 *)(reg_a6 + 0x15) != 0) goto block_1;
    *(u8 *)(reg_a6 + 0x15) = *(u8 *)(reg_a6 + 0x14);
    reg_d0.w = 0;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x16);
    *(u8 *)(reg_a6 + 0x18) -= 1;
    if (*(u8 *)(reg_a6 + 0x18) == 0) goto block_3;
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
    if ((s32)*(u8 *)(reg_a6 + 0x15) < 3) return;
    reg_d1.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d1.h[0] -= *(u16 *)(reg_a6 + 8);
    reg_d1.h[1] += *(u16 *)(reg_a6 + 6);
    func_00128320();
    if (*(u8 *)(reg_a6 + 1) & 0x20) {
        func_001285A0();
    }
    return;
block_3:
    func_001257E0();
}
