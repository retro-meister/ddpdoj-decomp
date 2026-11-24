#include "common.h"

extern s8 D_0028E408;

s32 func_00129410();
s32 func_0013A780();
s32 func_0014D220();
s32 func_0014E290();
s32 func_0018D4E0();
s32 func_0019C3E0();
s32 func_001A9000();
s32 func_002010A0();
s32 func_00201F20();
s32 func_00202730();
s32 func_00203060();
extern u8 D_00263710[];
extern u8 D_00263750[];
extern u8 D_0028E2E4;
extern u16 D_0028E85C;
extern u16 D_0028E884;
extern u16 D_0028E8A0;
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_001D6D60(void) {
    if (D_0028E2E4 != 0) {
        goto next_1;
    }
    if (D_0028E884 == 0) {
        goto next_2;
    }
    if (D_0028E85C == 0) {
        goto next_2;
    }
    if (D_0028E85C == 2) {
        goto next_2;
    }
    reg_d1.w = 0x5C;
    reg_d1.b[0] &= *(u8 *) (reg_a6 + 1);
    if (reg_d1.b[0] == 0) {
        goto next_3;
    }
    reg_d0.b[0] = 0xA3;
    *(u8 *) (reg_a6 + 1) &= reg_d0.b[0];
    func_001A9000();
    reg_d0.b[0] = *(u8 *) (reg_a6 + 0x1C);
    reg_d2.b[0] = 0x15;
    reg_d0.b[0] ^= reg_d2.b[0];
    *(u8 *) (reg_a6 + 0x1C) = reg_d0.b[0];
    if (*(s16 *) (reg_a6 + 0x18) >= 0) {
        goto next_4;
    }
next_2:
    reg_d0.w = 2;
    func_0013A780();
    *(u16 *) (reg_a0 + 2) = *(u16 *) (reg_a6 + 2);
    *(u16 *) (reg_a0 + 4) = *(u16 *) (reg_a6 + 4);
    *(u16 *) (reg_a0 + 0x1A) = *(u16 *) (reg_a6 + 0x1A);
    *(u16 *) (reg_a0 + 0x1E) = 0x10;
    func_0018D4E0();
next_1:
    func_0014E290();
    return;
next_3:
    *(u8 *) (reg_a6 + 0x1C) = 0xA;
next_4:
    func_00203060();
    if (D_0028E408 == 0) {
        goto next_5;
    }
    if (*(u8 *) (reg_a5 + 0x17) == 0) {
        goto next_6;
    }
    func_0014E290();
    return;
next_5:
    *(u8 *) (reg_a5 + 0x17) = 1;
next_6:
    if (D_0028E8A0 != 0) {
        goto next_15;
    }
    func_00201F20();
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x1B);
    *(u8 *) (reg_a5 + 0x1B) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_8;
    }
    *(u8 *) (reg_a5 + 0x1B) = *(u8 *) (reg_a5 + 0x1A);
    if (*(u8 *) (reg_a5 + 0x27) == 0) {
        goto next_7;
    }
    if (*(u8 *) (reg_a6 + 0x1B) == 4) {
        goto next_8;
    }
next_7:
    *(u8 *) (reg_a6 + 0x1B) += 1;
next_8:
    if (*(s16 *) (reg_a6 + 2) <= 0x600) {
        goto next_9;
    }
    if (*(u8 *) (reg_a5 + 0x27) == 0) {
        goto next_10;
    }
    if (*(s8 *) (reg_a6 + 0x1B) < 4) {
        goto next_10;
    }
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x19);
    *(u8 *) (reg_a5 + 0x19) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_10;
    }
    *(u8 *) (reg_a5 + 0x19) = *(u8 *) (reg_a5 + 0x18);
    func_00202730();
    if (D_0028E408 != 0) {
        goto next_10;
    }
    func_002010A0();
    reg_d0.b[0] = (s8) reg_d0.b[0] >> 1;
    reg_d1.b[0] += reg_d0.b[0];
    reg_d0.w = 0x16;
    reg_d2.h[1] = *(u16 *) (reg_a6 + 2);
    reg_d2.h[0] = *(u16 *) (reg_a6 + 4);
    reg_d4.w = 0;
    reg_d3.w = 0;
    func_00129410();
next_9:
    *(u8 *) (reg_a5 + 0x27) -= 1;
next_10:
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x1F);
    *(u8 *) (reg_a5 + 0x1F) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_11;
    }
    *(u8 *) (reg_a5 + 0x1F) = *(u8 *) (reg_a5 + 0x1E);
    reg_a0 = (u8 *)D_00263710;
    reg_d0.h[0] = *(u16 *) (reg_a5 + 0x20);
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a5 + 0x20) += 4;
    *(u16 *) (reg_a5 + 0x20) &= 0x3F;
next_11:
    reg_tmp.b[0] = *(u8 *) (reg_a5 + 0x23);
    *(u8 *) (reg_a5 + 0x23) -= 1;
    if ((s32) reg_tmp.b[0] > 0) {
        goto next_15;
    }
    *(u8 *) (reg_a5 + 0x23) = *(u8 *) (reg_a5 + 0x22);
    if (*(u16 *) (reg_a5 + 0x24) == 0x5C) {
        goto next_15;
    }
    *(u16 *) (reg_a5 + 0x24) += 4;
    *(u16 *) (reg_a6 + 0x10) += 0x40;
    *(u16 *) (reg_a6 + 0x12) += 0x40;
    *(u16 *) (reg_a6 + 0x14) += 0x20;
    *(u16 *) (reg_a6 + 0x16) += 0x20;
next_15:
    reg_a0 = reg_a6;
    func_0014D220();
    reg_a0 = (u8 *)D_00263750;
    reg_a0 += *(u16 *) (reg_a5 + 0x24);
    reg_d6.h[1] = *(u16 *) reg_a0;
    reg_d6.h[0] = *(u16 *) (reg_a0 + 2);
    func_0019C3E0();
}
