#include "common.h"

s32 func_001D7880();
s32 func_001D7900();
s32 func_001DA070(s32, s32);
s32 func_002026F0();
extern u8 *reg_a4;
extern u8 *reg_a6;

void func_001DA3C0(void) {
    u16 t;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto next_1;
    *(u8 *)(reg_a4 + 5) = *(u8 *)(reg_a4 + 4);
    func_001D7880();
    func_001D7900();
next_1:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
    *(u8 *)(reg_a4 + 7) -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_rts;
    *(u8 *)(reg_a4 + 7) = *(u8 *)(reg_a4 + 6);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xC2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xC4);
    func_002026F0();
    *(u8 *)(reg_a4 + 0x1F) = reg_d1.b[0];
    func_001DA070(0xC6, 0xC2);
    *(u8 *)(reg_a4 + 0x1F) += 0x18;
    func_001DA070(0xC6, 0xC2);
    *(u8 *)(reg_a4 + 0x1F) -= 0x30;
    func_001DA070(0xC6, 0xC2);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0xE2);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0xE4);
    func_002026F0();
    *(u8 *)(reg_a4 + 0x1F) = reg_d1.b[0];
    func_001DA070(0xE6, 0xE2);
    *(u8 *)(reg_a4 + 0x1F) += 0x18;
    func_001DA070(0xE6, 0xE2);
    *(u8 *)(reg_a4 + 0x1F) -= 0x30;
    func_001DA070(0xE6, 0xE2);
    t = *(u16 *)(reg_a4 + 0xA);
    if (t == 3) goto next_2;
    *(u16 *)(reg_a4 + 0xA) = t + 1;
    if ((s16) *(u16 *)(reg_a4 + 0xA) < 3) goto block_rts;
    *(u16 *)(reg_a4 + 6) = 0x5020;
block_rts:
    return;
next_2:
    *(u16 *)(reg_a4 + 0xC) -= 1;
    if ((s16) *(u16 *)(reg_a4 + 0xC) != 0) return;
    *(s16 *)(reg_a4 + 0) = 0;
}
