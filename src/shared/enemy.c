#include "common.h"

extern s8 *reg_a0_as_s8_p;

void func_0014EC80(void) {
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0_as_s8_p -= reg_d0.h[0];
}

extern s8 *reg_a6_as_s8_p;

void func_0014ECC0(void) {
    reg_a6_as_s8_p[0x1E] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
}

extern u8 *reg_a6;

void func_0014ECE0(void)
{
    reg_d0.b[0] = *reg_a0_as_s8_p++;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        reg_a6[1] &= 0xDF;
    } else {
        reg_a6[1] |= 0x20;
    }
}

extern u16 *reg_a6_as_u16_p;

void func_0014ED40(void)
{
    reg_d0.b[0] = (u8)*reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        *reg_a6_as_u16_p &= 0xDFFE;
    } else {
        *reg_a6_as_u16_p |= 0x2001;
    }
}

extern s8 *reg_a5_as_s8_p;

void func_0014EDA0(void) {
    reg_a5_as_s8_p[0x23] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p++;
}

extern s8 D_0028E4A1;
extern s8 D_0028E4A5;
extern u8 *reg_a5;

void func_0014EDC0(void) {
    s8 temp_a2;

    reg_d0.h[0] = 0;
    reg_d0.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    D_0028E4A5 = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d1.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d1.h[0] &= 0xFF0;
    reg_d1.h[0] *= 0x10;
    temp_a2 = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    D_0028E4A1 = temp_a2;
    reg_d2.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d2.h[0] &= 0xFF0;
    reg_d2.h[0] >>= 4;
    reg_d1.h[0] += reg_d2.h[0];
    *(u16 *)(reg_a5 + ((s32) reg_d0.h[0] >> 1)) = reg_d1.h[0];
}

void func_0014EE90(void) {
    s8 temp_a2;

    reg_d0.h[0] = 0;
    reg_d0.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    D_0028E4A5 = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d1.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d1.h[0] &= 0xFF0;
    reg_d1.h[0] *= 0x10;
    temp_a2 = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    D_0028E4A1 = temp_a2;
    reg_d2.b[0] = (u8) *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d2.h[0] &= 0xFF0;
    reg_d2.h[0] >>= 4;
    reg_d1.h[0] += reg_d2.h[0];
    *(u16 *)(reg_a6 + ((s32) reg_d0.h[0] >> 1)) = reg_d1.h[0];
}

void func_0014EF60(void) {
    reg_a5_as_s8_p[0x25] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
}

void func_0014EF80(void) {
    reg_a6_as_s8_p[0x1F] = *reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
}

extern s32 reg_a0_as_s32;
extern u16 D_0029C068[];
void func_0014EFA0(void) {
    reg_d0.h[0] = D_0029C068[0];
    reg_a6_as_u16_p[2] -= reg_d0.h[0];
    reg_a0_as_s32 += 1;
}

extern u8 enemy_move_end_requested_as_u8;

void func_0014E290(void);

void func_0014EFD0(void) {
    enemy_move_end_requested_as_u8 = 1;
    func_0014E290();
}

void func_0014EFE0(void) {

}
