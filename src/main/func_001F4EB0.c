#include "common.h"

s32 func_00124B20();
s32 func_00124D10();
s32 func_001253B0();
s32 func_001A9000();
s32 func_001A91A0();
s32 func_001F5520();
s32 func_001F5620();
s32 func_001F57E0();
s32 func_001F5850();
s32 func_002016D0();
s32 func_00203400();
extern u8 D_0028E290;
extern u16 D_0028E2E8;
extern s32 D_0028E638;
extern u16 D_0028E8B8;
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define TW(o) (*(u16 *)(reg_a5 + (o)))

void func_001F4EB0(void) {
    s32 top;
    s32 p1;
    s32 p2;
    s32 p3;
    s32 p4;
    s32 p5;
    u16 hp;

    if (W(0x106) != 0) return;
    if (reg_a6[0x10F] != 0) {
        func_001F5850();
        return;
    }
    reg_d1.b[0] = reg_a6[1];
    reg_d1.b[0] |= reg_a6[0x21];
    reg_d1.b[0] |= reg_a6[0x41];
    reg_d1.b[0] |= reg_a6[0x61];
    reg_d1.b[0] |= reg_a6[0x81];
    reg_d1.b[0] |= reg_a6[0xA1];
    reg_d1.b[0] |= reg_a6[0xC1];
    reg_d1.b[0] |= reg_a6[0x1A1];
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_1;
    reg_a6[0xE7] = 0x10;
    reg_a6[0xE6] = 0x11;
    reg_a6[0xE9] = 0x12;
    reg_a6[0xE8] = 0x16;
    reg_tmp.h[1] = TW(0x16);
    reg_tmp.h[0] = TW(0x18);
    if (reg_tmp.w >= 0x15000) goto block_chk;
    if (D_0028E8B8 != 0) goto block_chk;
    reg_d0.w = 0x19;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_a6[0xE6] = reg_d0.b[0];
    reg_a6[0xE9] = reg_d0.b[0];
    reg_a6[0xE8] = reg_d0.b[0];
    goto block_chk;
next_1:
    reg_d0.b[0] = 0xA3;
    reg_a6[1] &= reg_d0.b[0];
    reg_a6[0x21] &= reg_d0.b[0];
    reg_a6[0x41] &= reg_d0.b[0];
    reg_a6[0x61] &= reg_d0.b[0];
    reg_a6[0x81] &= reg_d0.b[0];
    reg_a6[0xA1] &= reg_d0.b[0];
    reg_a6[0xC1] &= reg_d0.b[0];
    reg_a6[0x1A1] &= reg_d0.b[0];
    W(0x10A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = reg_a6[0xE7];
    reg_d2.b[0] = reg_a6[0xE6];
    reg_d3.b[0] = reg_a6[0xE9];
    reg_d4.b[0] = reg_a6[0xE8];
    if (reg_d0.b[0] != 0x19) goto next_2;
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
    reg_d4.b[0] = 0x16;
next_2:
    reg_d0.b[0] ^= 0xF;
    reg_a6[0xE7] = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    reg_a6[0xE6] = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    reg_a6[0xE9] = reg_d3.b[0];
    reg_d4.b[0] ^= 9;
    reg_a6[0xE8] = reg_d4.b[0];
    if (D_0028E290 == 2) {
        top = W(0x18);
        p1 = W(0x38);
        p2 = W(0x58);
        p3 = W(0x78);
        p4 = W(0xD8);
        p5 = W(0x1B8);
        if (top > p1) goto skip_1;
        top = p1;
skip_1:
        if (p2 > p3) goto skip_2;
        p2 = p3;
skip_2:
        if (p4 > p5) goto skip_3;
        p4 = p5;
skip_3:
        if (top > p2) goto skip_4;
        top = p2;
skip_4:
        if (top > p4) goto skip_5;
        top = p4;
skip_5:;
    }
    reg_d4.h[0] = W(0x18);
    hp = W(0x38);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x58);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x78);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x98);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0xB8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0xD8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    hp = W(0x1B8);
    if ((s16) hp < reg_d4.sh[0]) reg_d4.h[0] = hp;
    reg_d5.w = 0x7FFF;
    W(0x18) = reg_d5.h[0];
    W(0x38) = reg_d5.h[0];
    W(0x58) = reg_d5.h[0];
    W(0x78) = reg_d5.h[0];
    W(0x98) = reg_d5.h[0];
    W(0xB8) = reg_d5.h[0];
    W(0xD8) = reg_d5.h[0];
    W(0x1B8) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (W(0x108) != 0) goto block_chk;
    reg_tmp.h[1] = TW(0x16);
    reg_tmp.h[0] = TW(0x18);
    if (D_0028E290 == 2) {
        if (top > 0x7FFF) {
            reg_tmp.w += top - 0x7FFF;
            if (reg_tmp.w >= 0x3F000) reg_tmp.w = 0x3F000;
        } else {
            reg_tmp.w -= reg_d5.w;
        }
    } else {
        reg_tmp.w -= reg_d5.w;
    }
    TW(0x16) = reg_tmp.h[1];
    TW(0x18) = reg_tmp.h[0];
    if (0 > (s32) reg_tmp.w) goto next_9;
    goto block_chk;
next_9:
    func_00203400();
    if (reg_d0.h[0] != 0) goto next_6;
    reg_tmp.w = 0x200;
    TW(0x16) = reg_tmp.h[1];
    TW(0x18) = reg_tmp.h[0];
    goto block_chk;
next_6:
    if (D_0028E2E8 != 0) goto next_7;
    D_0028E638 = 0x70000;
    func_001F5520();
    return;
next_7:
    reg_d1.h[0] = W(0x10A);
    reg_d0.w = 0x70000;
    func_001A91A0();
    func_001F5520();
    return;
block_chk:
    if (reg_a6[0x10D] != 0) goto next_8;
    if (D_0028E2E8 != 0) goto next_8;
    reg_d0.h[1] = TW(0x16);
    reg_d0.h[0] = TW(0x18);
    reg_d0.w += 0xFFFD6000;
    if (0 > (s32) reg_d0.w) goto next_10;
    goto next_8;
next_10:
    func_001253B0();
    func_00124D10();
    reg_d0.w = 0xE;
    func_00124B20();
    func_001F5620();
    reg_a6[0x10D] = 1;
    func_002016D0();
next_8:
    func_001F57E0();
}
