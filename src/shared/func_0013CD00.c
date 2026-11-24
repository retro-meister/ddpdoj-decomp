#include "common.h"

void func_0019DBE0(void);
extern u16 D_0028DFC0;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern Reg32 D_0028E484;
extern u16 D_0028E910;
extern u8 *reg_a0;
extern u8 *reg_a1;

void func_0013CD00(void) {
    if (reg_d0.h[0] != 5) {
        reg_d4.h[0] = 5;
        reg_d2.w = 0x1E;
        reg_d2.h[0] &= D_0028E3F0;
        reg_d2.h[0] <<= 1;
    } else {
        reg_d4.h[0] = 5;
        reg_d2.w = 0xF;
        reg_d2.h[0] &= D_0028E3F0;
    }
    reg_d2.h[0] >>= 1;
    reg_d2.w += 0xB42;
    reg_d3.h[0] = 0x418;
    reg_d6.h[0] = 0xF000;
    reg_d7.w = 5;
    reg_a0 += 0x40;
    goto loop_2;
loop_1:
    if (reg_d7.h[0] == 0) {
        *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
        *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
        reg_a0 -= 4;
        reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        reg_d2.h[0] = 0xF700;
        if (*(u16 *)(reg_a1 + 0x58) != 0) {
            reg_d2.h[0] = 0xF800;
        }
        reg_d0.h[0] += reg_d2.h[0];
        *(u16 *)(reg_a0 - 4) = reg_d0.h[0];
        *(u16 *)(reg_a0 - 2) = reg_d1.h[0];
        return;
    }
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
loop_2:
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    if ((D_0028DFC0 == 0) && (reg_d7.h[0] == reg_d0.h[0])) {
        reg_d0.h[0] -= 1;
        reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
        reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
        D_0028E484.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = D_0028E484.h[0];
        reg_d1.h[0] += reg_d6.h[0];
        if (((s16) reg_d1.h[0] >= -0x500) && ((D_0028E910 == 0) || (*(u8 *)(reg_a1 + 0x3E) == 0) || (D_0028E3EC == 0))) {
            D_0028E484.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = D_0028E484.h[0];
            reg_d1.h[0] += 0xFCC0;
            func_0019DBE0();
        }
    }
    reg_d2.w += 1;
    if ((u32) reg_d2.w >= 0xB52U) {
        if (reg_d2.w == 0xB52) {
            reg_d2.w = 0xB42;
        } else {
            reg_d2.w = 0xB43;
        }
    }
    reg_d6.h[0] -= 0xFD00;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
}
