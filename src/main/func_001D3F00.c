#include "common.h"

s32 func_00124B20();
s32 func_00124D10();
s32 func_001253B0();
s32 func_001A9000();
s32 func_001D4400();
s32 func_001D4510();
s32 func_001D4540();
s32 func_001D4630();
s32 func_002016D0();
s32 func_00203400();
extern u8 D_0028E290;
extern Reg32 D_0028E474;
extern s32 D_0028E638;
extern u16 D_0028E8B8;
extern u16 D_00299768[];
extern u16 D_0029976A[];
extern u16 D_0029976C[];
extern u8 *reg_a5;
extern u8 *reg_a6;

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define B(o) (*(u8 *)(reg_a6 + (o)))

void func_001D3F00(void) {
    s32 m0;
    s32 m1;
    s32 m2;
    s32 m3;
    s32 m4;

    if (W(0x86) != 0) return;
    reg_d1.b[0] = B(1);
    reg_d1.b[0] |= B(0x21);
    reg_d1.b[0] |= B(0x41);
    reg_d1.b[0] |= B(0xC1);
    reg_d1.b[0] |= B(0xE1);
    reg_d1.h[0] &= 0x5C;
    if (reg_d1.h[0] != 0) goto next_10;
    B(0x67) = 0x10;
    B(0x66) = 0x11;
    B(0x69) = 0x12;
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (reg_tmp.w >= 0x8C00) goto block_check;
    if (D_0028E8B8 != 0) goto block_check;
    reg_d0.w = 0x19;
    B(0x67) = reg_d0.b[0];
    B(0x66) = reg_d0.b[0];
    B(0x69) = reg_d0.b[0];
    goto block_check;
next_10:
    reg_d0.b[0] = 0xA3;
    B(1) &= reg_d0.b[0];
    B(0x21) &= reg_d0.b[0];
    B(0x41) &= reg_d0.b[0];
    B(0xC1) &= reg_d0.b[0];
    B(0xE1) &= reg_d0.b[0];
    W(0x8A) = reg_d1.h[0];
    func_001A9000();
    reg_d0.b[0] = B(0x67);
    reg_d2.b[0] = B(0x66);
    reg_d3.b[0] = B(0x69);
    if (reg_d0.b[0] != 0x19) goto next_20;
    reg_d0.b[0] = 0x10;
    reg_d2.b[0] = 0x11;
    reg_d3.b[0] = 0x12;
next_20:
    reg_d0.b[0] ^= 0xF;
    B(0x67) = reg_d0.b[0];
    reg_d2.b[0] ^= 0xE;
    B(0x66) = reg_d2.b[0];
    reg_d3.b[0] ^= 0xD;
    B(0x69) = reg_d3.b[0];
    if (D_0028E290 == 2) {
        m0 = W(0x18);
        m1 = W(0x38);
        m2 = W(0x58);
        m3 = W(0xD8);
        m4 = W(0xF8);
        if (m0 <= m1) m0 = m1;
        if (m2 <= m3) m2 = m3;
        if (m2 <= m4) m2 = m4;
        if (m0 <= m2) m0 = m2;
    }
    reg_d4.h[0] = W(0x18);
    if ((s16) W(0x38) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0x38);
    if ((s16) W(0x58) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0x58);
    if ((s16) W(0xD8) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0xD8);
    if ((s16) W(0xF8) < (s16) reg_d4.h[0]) reg_d4.h[0] = W(0xF8);
    reg_d5.w = 0x7FFF;
    W(0x18) = reg_d5.h[0];
    W(0x38) = reg_d5.h[0];
    W(0x58) = reg_d5.h[0];
    W(0xD8) = reg_d5.h[0];
    W(0xF8) = reg_d5.h[0];
    reg_d5.h[0] -= reg_d4.h[0];
    if (W(0x88) != 0) goto block_check;
    D_0028E474.h[1] = *(u16 *)(reg_a5 + 0x16);
    D_0028E474.h[0] = *(u16 *)(reg_a5 + 0x18);
    if (D_0028E290 == 2) {
        if (m0 > 0x7FFF) {
            D_0028E474.w += m0 - 0x7FFF;
            if (D_0028E474.w >= 0x40C00) D_0028E474.w = 0x40C00;
        } else {
            D_0028E474.w -= reg_d5.w;
        }
    } else {
        D_0028E474.w -= reg_d5.w;
    }
    *(u16 *)(reg_a5 + 0x16) = D_0028E474.h[1];
    *(u16 *)(reg_a5 + 0x18) = D_0028E474.h[0];
    if ((s32) D_0028E474.w >= 0) goto block_check;
    func_00203400();
    if (reg_d0.h[0] != 0) goto next_30;
    reg_tmp.w = 0x200;
    *(u16 *)(reg_a5 + 0x16) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x18) = reg_tmp.h[0];
    goto block_check;
next_30:
    reg_d1.h[0] = W(0x8A);
    D_0028E638 = 0x50000;
    func_001D4400();
    return;
block_check:
    if (B(0x8D) != 0) goto block_tail;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x16);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x18);
    reg_d0.w += 0xFFFEE800;
    if ((s32) reg_d0.w >= 0) goto block_tail;
    func_001253B0();
    func_00124D10();
    reg_d0.w = 9;
    func_00124B20();
    func_001D4540();
    func_001D4510();
    B(0x8D) = 1;
    D_00299768[0] = 1;
    D_0029976A[0] = 1;
    D_0029976C[0] = 1;
    func_002016D0();
block_tail:
    func_001D4630();
}
