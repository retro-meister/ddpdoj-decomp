#include "common.h"

void func_0019D8B0(void);
extern u16 D_0028E3EC;
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a6;

void func_0013F5C0(void) {
    u32 tmp;

    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = 0x1F;
    reg_a2 = reg_a0;
    reg_a3 = reg_a1;
    reg_d6.h[1] = *(u16 *)(reg_a6 + 2);
    reg_d6.h[0] = *(u16 *)(reg_a6 + 4);
    reg_d6.w &= 0xFF80FF80;
    reg_a1 += 0x40;
    reg_a0 += 0x40;
    reg_d7.w = 5;
    goto loop_2;
loop_1:
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
loop_2:
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    if (reg_d7.h[0] == 0) {
        *(u16 *)(reg_a3 + 0) = *(u16 *)(reg_a6 + 0xA);
        *(u16 *)(reg_a3 + 2) = *(u16 *)(reg_a6 + 0xC);
        *(u16 *)(reg_a2 + 0) = *(u16 *)(reg_a6 + 2);
        *(u16 *)(reg_a2 + 2) = *(u16 *)(reg_a6 + 4);
        return;
    }
    if (D_0028E3EC == 0) {
        goto next_1;
    }
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d5.w = reg_d1.w;
    reg_d5.w &= 0xFF80FF80;
    if (reg_d6.w == reg_d5.w) {
        goto next_1;
    }
    reg_d1.w += 0xFA00FC00;
    reg_d2.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    func_0019D8B0();
next_1:
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}
