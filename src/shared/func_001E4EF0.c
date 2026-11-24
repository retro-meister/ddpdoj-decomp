#include "common.h"

extern s8 D_0028E408;

s32 func_00124D90();
s32 func_00124F50();
s32 func_00125060();
s32 func_001251C0();
s32 func_00125250();
s32 func_00125310();
void func_001E4D90(s32 dst, s32 src);
extern u8 *reg_a0;
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001E4EF0(void) {
    u32 t;

    if (!(reg_a4[3] & 1)) {
        goto next_1;
    }
    if (*(u16 *)(reg_a6 + 0x18E) == -0x1000) {
        goto next_1;
    }
    *(u16 *)(reg_a4 + 6) += 4;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 6);
    *(u16 *)(reg_a6 + 0x18E) -= reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x192) += reg_d0.h[0];
    if (*(s16 *)(reg_a6 + 0x192) < 0xE00) {
        goto next_1;
    }
    *(u16 *)(reg_a6 + 0x192) = 0xE00;
    *(u16 *)(reg_a6 + 0x18E) = 0xF200;
    t = reg_a4[3];
    if (t & 1) {
        reg_a4[3] = t & 0xFE;
    }
    reg_a4[3] |= 2;
    reg_a4[3] |= 4;
    *(u16 *)(reg_a6 + 0x198) = 0;
    *(u16 *)(reg_a6 + 0x19A) = 0;
    *(u16 *)(reg_a4 + 0xA) = 0;
    func_001E4D90(0x198, 0x82);
    func_001E4D90(0x19A, 0xA2);
    *(u16 *)(reg_a4 + 4) = 0x10;
    *(u16 *)(reg_a4 + 0xC) = 0x10;
    *(u16 *)(reg_a4 + 0x10) = 0x808;
    *(u16 *)(reg_a4 + 0x12) = 0;
    *(u16 *)(reg_a4 + 0x14) = 4;
next_1:
    if (!(reg_a4[2] & 1)) {
        goto next_2;
    }
    reg_d0.w = 6;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_2;
    }
    reg_d0.w = 8;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_2;
    }
    reg_d0.w = 5;
    func_00124F50();
    reg_d0.w = 7;
    func_00124F50();
    t = reg_a4[2];
    if (t & 1) {
        reg_a4[2] = t & 0xFE;
    }
    reg_a4[2] |= 2;
next_2:
    if (!(reg_a4[2] & 2)) {
        goto next_3;
    }
    reg_d0.w = 5;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_3;
    }
    reg_d0.w = 7;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_3;
    }
    reg_d0.w = 8;
    func_001251C0();
    t = reg_a4[2];
    if (t & 2) {
        reg_a4[2] = t & 0xFD;
    }
next_3:
    if (!(reg_a4[2] & 4)) {
        goto next_4;
    }
    reg_d0.w = 6;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_4;
    }
    reg_d0.w = 8;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_4;
    }
    reg_d0.w = 5;
    func_00124F50();
    reg_d0.w = 7;
    func_00124F50();
    t = reg_a4[2];
    if (t & 4) {
        reg_a4[2] = t & 0xFB;
    }
    reg_a4[2] |= 8;
next_4:
    if (!(reg_a4[2] & 8)) {
        goto next_5;
    }
    reg_d0.w = 5;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_5;
    }
    reg_d0.w = 7;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_5;
    }
    t = reg_a4[2];
    if (t & 8) {
        reg_a4[2] = t & 0xF7;
    }
next_5:
    if (!(reg_a4[3] & 2)) {
        goto next_6;
    }
    t = *(u16 *)(reg_a4 + 4);
    if (t != 0) {
        *(u16 *)(reg_a4 + 4) = t - 1;
    }
    func_001E4D90(0x198, 0x82);
    func_001E4D90(0x19A, 0xA2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x198);
    *(u16 *)(reg_a6 + 0x18C) += reg_d0.h[0];
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x19A);
    *(u16 *)(reg_a6 + 0x190) += reg_d0.h[0];
next_6:
    if (!(reg_a4[3] & 4)) {
        goto next_8;
    }
    reg_d0.w = 4;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_8;
    }
    t = *(u16 *)(reg_a4 + 0xC);
    if (t == 0) {
        goto next_7;
    }
    *(u16 *)(reg_a4 + 0xC) = t - 1;
    if (*(s16 *)(reg_a4 + 0xC) != 0) {
        goto next_8;
    }
    reg_d0.w = 8;
    func_00125310();
    reg_d0.w = 6;
    func_001251C0();
    reg_d0.w = 0xA;
    func_001251C0();
    reg_a4[2] |= 4;
next_7:
    reg_d0.w = 0xA;
    func_00125250();
    if (D_0028E408 != 0) {
        goto next_8;
    }
    reg_d0.w = 6;
    func_00125310();
    reg_d0.w = 7;
    func_00125310();
    reg_d0.w = 6;
    func_00124F50();
    reg_d0.w = 8;
    func_00124F50();
    t = reg_a4[3];
    if (t & 4) {
        reg_a4[3] = t & 0xFB;
    }
    reg_a4[3] |= 8;
    *(u16 *)(reg_a4 + 0xC) = 0x40;
next_8:
    if (!(reg_a4[3] & 8)) {
        goto next_9;
    }
    *(u16 *)(reg_a4 + 0xC) -= 1;
    if (*(s16 *)(reg_a4 + 0xC) != 0) {
        goto next_9;
    }
    reg_a4[2] |= 1;
    reg_d0.w = 3;
    func_00124F50();
    reg_d0.w = 7;
    func_00124D90();
    t = reg_a4[3];
    if (t & 8) {
        reg_a4[3] = t & 0xF7;
    }
    reg_a4[3] |= 0x10;
    reg_a4[0x11] = reg_a4[0x10];
    t = reg_a4[0x10];
    if (t == 8) {
        goto next_9;
    }
    reg_a4[0x10] = t + 1;
next_9:
    if (!(reg_a4[3] & 0x10)) {
        goto next_10;
    }
    reg_d0.w = 3;
    func_00125060();
    if (D_0028E408 != 0) {
        goto next_10;
    }
    reg_d0.w = 9;
    func_00125250();
    if (D_0028E408 != 0) {
        goto next_10;
    }
    reg_tmp.b[0] = reg_a4[0x15];
    reg_a4[0x15] -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_10;
    }
    reg_a4[0x15] = reg_a4[0x14];
    reg_d0.w = 9;
    func_001251C0();
    *(u16 *)(reg_a0 + 6) = *(u16 *)(reg_a4 + 0x12);
    *(u16 *)(reg_a4 + 0x12) += 1;
    *(u16 *)(reg_a4 + 0x12) &= 1;
    t = reg_a4[3];
    if (t & 0x10) {
        reg_a4[3] = t & 0xEF;
    }
    reg_a4[3] |= 0x20;
    *(u16 *)(reg_a4 + 0xC) = 0xE0;
next_10:
    if (!(reg_a4[3] & 0x20)) {
        return;
    }
    reg_d0.w = 9;
    func_00125250();
    if (D_0028E408 != 0) {
        return;
    }
    *(u16 *)(reg_a4 + 0xC) -= 1;
    if (*(s16 *)(reg_a4 + 0xC) != 0) {
        return;
    }
    reg_d0.w = 4;
    func_00124D90();
    reg_d0.w = 4;
    func_00124F50();
    t = reg_a4[3];
    if (t & 0x20) {
        reg_a4[3] = t & 0xDF;
    }
    reg_a4[3] |= 4;
    *(u16 *)(reg_a4 + 0xC) = 0x40;
}
