#include "common.h"

extern u8 D_0028E2D4;
extern u16 D_0028E5E8;
extern u16 D_0028E5EC;
extern u16 D_0028E5F8;
extern u16 D_0028E5FC;
extern s32 D_0028E7F4;
extern u32 D_0028E8BC_as_u32;
extern u8 D_0028E8C8_as_u8;
extern u8 D_0028E8CC_as_u8;
extern u8 D_0028E8D0_as_u8;
extern u8 D_0028E8D4_as_u8;
extern u8 D_0028E8D8_as_u8;
extern u8 D_0028E8DC_as_u8;
extern u8 D_0028E8E0_as_u8;
extern u8 D_0028E8E4_as_u8;
extern u8 D_0028E8E8_as_u8;
extern u8 D_0028E8EC_as_u8;
extern u8 D_0028E8F0_as_u8;
extern u8 D_0028E8F4_as_u8;
extern u8 D_0028E8F8_as_u8;
extern u8 D_0028E8FC_as_u8;
extern u8 D_0028E900_as_u8;
extern u16 D_0028E904;
extern u16 D_0028E910;
extern u16 D_0028E91C;
extern u8 D_0028ED80;
extern u16 D_006E5C02[];
extern u8 *reg_a0;

void func_00138170(void) {
    reg_a0 = (u8 *) D_0028E7F4;
    reg_d2.h[0] = D_0028E91C;
    reg_d1.w = 0;
    reg_d1.b[0] = *(s8 *) (reg_a0 + reg_d2.h[0]);
    reg_d2.w = D_0028E8BC_as_u32;
    reg_d3.w = 8;
    if (D_0028ED80 != 0 && D_006E5C02[0] != 0) {
        reg_d1.b[0] = D_0028E2D4;
    }
    reg_d2.w >>= reg_d3.w;
    reg_d1.h[0] += reg_d2.h[0];
    reg_d2.h[0] = 0xDF;
    reg_d0.h[0] = D_0028E5FC;
    if (((reg_d0.h[0] |= D_0028E5F8) & 0xFFFF) == 0) {
        goto next_2;
    }
    reg_d0.h[0] = D_0028E5EC;
    if ((s32) D_0028E5E8 <= (s32) reg_d0.h[0]) {
        goto next_1;
    }
    reg_d0.h[0] = D_0028E5E8;
next_1:
    reg_d0.h[0] <<= 4;
    reg_d1.h[0] += reg_d0.h[0];
next_2:
    if (D_0028E910 == 0) {
        goto next_3;
    }
    if (D_0028ED80 != 0 && D_006E5C02[0] != 0) {
        goto next_3;
    }
    D_0028E904 = 0xFF;
    reg_d0.h[0] = D_0028E5FC;
    reg_d0.h[0] |= D_0028E5F8;
    if (reg_d0.h[0] != 0) {
        goto next_5;
    }
    D_0028E904 = 0xF8;
    goto next_5;
next_3:
    D_0028E904 = reg_d1.h[0];
    reg_d0.h[0] = D_0028E5FC;
    reg_d0.h[0] |= D_0028E5F8;
    if (reg_d0.h[0] != 0) {
        goto next_4;
    }
    if (D_0028E904 <= 0xF0) {
        goto next_5;
    }
    D_0028E904 = 0xF0;
    goto next_5;
next_4:
    if (D_0028E904 <= 0xFF) {
        goto next_5;
    }
    D_0028E904 = 0xFF;
next_5:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *) &D_0028E904;
    reg_d7.h[0] = reg_d0.h[0];
    reg_d7.h[0] >>= 4;
    reg_d0.h[0] >>= 1;
    reg_d1.b[0] = reg_d0.b[0];
    reg_d6.b[0] = reg_d0.b[0];
    D_0028E8E4_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8E8_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d2.h[0] = reg_d0.h[0];
    reg_d6.b[0] = reg_d0.b[0];
    D_0028E8D4_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8D8_as_u8 = reg_d6.b[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    D_0028E8F4_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8F8_as_u8 = reg_d6.b[0];
    reg_d0.h[0] >>= 1;
    reg_d3.h[0] = reg_d1.h[0];
    reg_d1.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d1.b[0];
    D_0028E8FC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E900_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    D_0028E8EC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8F0_as_u8 = reg_d6.b[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.b[0] += reg_d0.b[0];
    reg_d6.b[0] = reg_d2.b[0];
    D_0028E8DC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8E0_as_u8 = reg_d6.b[0];
    reg_d3.b[0] -= reg_d0.b[0];
    reg_d6.b[0] = reg_d3.b[0];
    D_0028E8CC_as_u8 = reg_d6.b[0];
    reg_d6.b[0] += reg_d7.b[0];
    D_0028E8D0_as_u8 = reg_d6.b[0];
    D_0028E8C8_as_u8 = reg_d7.b[0];
}
