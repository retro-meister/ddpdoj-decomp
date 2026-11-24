#include "common.h"

s32 func_001A9000();
s32 func_001A91A0();
s32 func_001F5BB0();
s32 func_001F5C90();
s32 func_001F5D00();
s32 func_00203400();
extern u8 D_0028E290;
extern u16 D_0028E8B8;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001F5850(void) {
    u32 big;
    u16 t;

    if (reg_a6[0x10F] != 1) {
        func_001F5D00();
        return;
    }
    reg_d1.b[0] = reg_a6[0x141];
    reg_d1.b[0] |= reg_a6[0x161];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) {
        goto next_1;
    }
    reg_a6[0xE7] = 0x10;
    reg_a6[0xE6] = 0x11;
    reg_a6[0xE9] = 0x12;
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0x18);
    if (reg_tmp.w >= 0xE000) {
        goto next_9;
    }
    if (D_0028E8B8 != 0) {
        goto next_9;
    }
    reg_d0.w = 0x19;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_a6[0xE6] = reg_d0.b[0];
    reg_a6[0xE9] = reg_d0.b[0];
    goto next_9;
next_1:
    reg_d0.b[0] = 0xA3;
    reg_a6[0x141] &= reg_d0.b[0];
    reg_a6[0x161] &= reg_d0.b[0];
    *(u16 *) (reg_a6 + 0x10A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = reg_a6[0xE7];
    reg_d2.b[0] = reg_a6[0xE6];
    reg_d3.b[0] = reg_a6[0xE9];
    if (reg_d0.b[0] != 0x19) {
        goto next_2;
    }
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
next_2:
    reg_d0.b[0] ^= 0xF;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    reg_a6[0xE6] = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    reg_a6[0xE9] = reg_d3.b[0];
    if (D_0028E290 != 2) {
        goto next_3;
    }
    big = *(u16 *) (reg_a6 + 0x158);
    t = *(u16 *) (reg_a6 + 0x178);
    if ((s32) big <= (s32) t) {
        big = t;
    }
next_3:
    reg_d4.h[0] = *(u16 *) (reg_a6 + 0x158);
    t = *(u16 *) (reg_a6 + 0x178);
    if (!((s16) t < (s16) reg_d4.h[0])) {
        goto next_4;
    }
    reg_d4.h[0] = t;
next_4:
    reg_d5.w = 0x7FFF;
    *(u16 *) (reg_a6 + 0x158) = reg_d5.h[0];
    *(u16 *) (reg_a6 + 0x178) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (*(u16 *) (reg_a6 + 0x108) != 0) {
        goto next_9;
    }
    reg_tmp.h[1] = *(u16 *) (reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *) (reg_a5 + 0x18);
    if (D_0028E290 != 2) {
        goto next_6;
    }
    if ((s32) big <= 0x7FFF) {
        goto next_5;
    }
    reg_tmp.w += big - 0x7FFF;
    if (reg_tmp.w < 0x2A000) {
        goto next_7;
    }
    reg_tmp.w = 0x2A000;
    goto next_7;
next_5:
    reg_tmp.w -= reg_d5.w;
    goto next_7;
next_6:
    reg_tmp.w -= reg_d5.w;
next_7:
    *(u16 *) (reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0x18) = reg_tmp.h[0];
    if (0 <= (s64) (s32) reg_tmp.w) {
        goto next_9;
    }
    func_00203400();
    if (reg_d0.h[0] != 0) {
        goto next_8;
    }
    reg_tmp.w = 0x200;
    *(u16 *) (reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *) (reg_a5 + 0x18) = reg_tmp.h[0];
    goto next_9;
next_8:
    reg_d1.h[0] = *(u16 *) (reg_a6 + 0x10A);
    reg_d0.w = 0x80000;
    func_001A91A0();
    func_001F5BB0();
    return;
next_9:
    func_001F5C90();
}
