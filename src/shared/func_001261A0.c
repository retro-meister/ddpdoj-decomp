#include "common.h"

typedef void (*Fn)();

extern s8 D_0028E408;

s32 func_001256C0();
s32 func_001257B0();
s32 func_001257E0();
s32 func_00127CA0();
s32 func_00128130();
s32 func_00170DF0();
s32 func_00170F80();
s32 func_00171100();
s32 func_0018D970();
s32 func_0019D290();
extern u8 D_00269490[];
extern u8 *jtbl_0028E3F4;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001261A0(void) {
    u32 t;

    if (reg_d1.w & 1) {
        func_00128130();
        return;
    }
    reg_d0.w = 0;
    if (reg_d1.w & 0x1000) goto next_1;
    if (!(reg_d1.w & 0x800)) goto next_3;
    func_00170F80();
    goto next_2;
next_1:
    func_00170DF0();
next_2:
    func_00171100();
    func_0018D970();
    *(u8 *)(reg_a6 + 0) |= 1;
    func_00127CA0();
    return;
block_1:
    func_001257E0();
    return;
next_3:
    reg_tmp.w = 0xBBD;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
    *(u16 *)(reg_a6 + 0x18) -= 1;
    if ((s16) *(u16 *)(reg_a6 + 0x18) >= 0) goto next_4;
    *(u16 *)(reg_a6 + 0x18) = 2;
    reg_tmp.w = 0xBBE;
    *(u16 *)(reg_a6 + 0xA) = reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0xC) = reg_tmp.h[0];
next_4:
    func_001256C0();
    if (D_0028E408 != 0) goto block_1;
    reg_d0.w = 4;
    reg_d1.h[0] &= reg_d0.h[0];
    t = reg_d1.h[0] ^ reg_d0.h[0];
    reg_d1.h[0] = t;
    if (t & 0xFFFF) goto next_5;
    func_001257B0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
    reg_a0 = (u8 *)(reg_tmp.w);
    jtbl_0028E3F4 = reg_a0;
    ((Fn)jtbl_0028E3F4)();
    return;
next_5:
    *(u16 *)(reg_a6 + 2) -= 0x60;
    *(u8 *)(reg_a6 + 0x1E) -= 1;
    if (*(u8 *)(reg_a6 + 0x1E) != 0) goto next_6;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x1F);
    reg_a0 = (u8 *)(D_00269490);
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a6 + 0x1E) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x20) = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a6 + 0x22) = *(u16 *)reg_a0;
    reg_a0 += 2;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d1.h[0] = *(u16 *)(reg_a6 + 0x22);
    *(u16 *)(reg_a6 + 2) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) += reg_d1.h[0];
    func_0019D290();
}
