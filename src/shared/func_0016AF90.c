#include "common.h"

extern s8 D_0028E408;

s32 func_0016C260();
s32 func_002010A0();
s32 func_00201C60();
s32 func_00203060();
extern u8 D_0028E855;
extern u16 D_0028E8A0;
extern u8 *reg_a6;

void func_0016AF90(void) {
    if (D_0028E855 & 0x40) {
        goto block_7;
    }
    switch (*(u16 *)(reg_a6 + 0x18)) {
    case 0:
        goto block_7;
    }
    if (D_0028E8A0 == 0) {
        *(u16 *)(reg_a6 + 0x18) -= 1;
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d0.h[0] += 0x800;
    if (reg_d0.h[0] <= 0xB00) {
        goto block_6;
    }
    if (reg_d0.h[0] < 0x3D00) {
        goto next_2;
    }
    *(u16 *)(reg_a6 + 4) = 0x3500;
    if (*(u8 *)(reg_a6 + 0x1A) > 0x20) {
        goto next_2;
    }
    if (*(u16 *)(reg_a6 + 2) < 0x2B00) {
        goto block_1;
    }
    *(u8 *)(reg_a6 + 0x1A) = 0x18;
    goto block_1;
block_6:
    *(u16 *)(reg_a6 + 4) = 0x300;
    if (*(u8 *)(reg_a6 + 0x1A) < 0x20) {
        goto next_2;
    }
    if (*(u16 *)(reg_a6 + 2) < 0x2B00) {
        goto block_1;
    }
    *(u8 *)(reg_a6 + 0x1A) = 0x28;
block_1:
    *(u8 *)(reg_a6 + 0x1A) *= -1;
    func_002010A0();
    *(u8 *)(reg_a6 + 0x1A) += reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1A) &= 0x3F;
next_2:
    if (*(u16 *)(reg_a6 + 2) >= 0x6D00) {
        goto block_3;
    }
    if (*(u16 *)(reg_a6 + 2) <= 0x700) {
        goto block_4;
    }
    goto block_7;
block_3:
    if (*(u8 *)(reg_a6 + 0x1A) < 0x10) {
        goto block_5;
    }
    if (*(u8 *)(reg_a6 + 0x1A) > 0x30) {
        goto block_5;
    }
    goto block_7;
block_4:
    if (*(u8 *)(reg_a6 + 0x1A) <= 0x10) {
        goto block_7;
    }
    if (*(u8 *)(reg_a6 + 0x1A) > 0x30) {
        goto block_7;
    }
block_5:
    *(u8 *)(reg_a6 + 0x1A) += 0x20;
    *(u8 *)(reg_a6 + 0x1A) *= -1;
    func_002010A0();
    *(u8 *)(reg_a6 + 0x1A) += reg_d0.b[0];
    *(u8 *)(reg_a6 + 0x1A) &= 0x3F;
block_7:
    func_00201C60();
    D_0028E408 = 0;
    func_00203060();
    if (D_0028E408 != 0) {
        func_0016C260();
    }
}
