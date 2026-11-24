#include "common.h"

extern Reg32 D_0028E46C;
extern u32 D_0028E484;
extern u16 D_0028E710;
extern u32 D_0028E714;
extern u8 *reg_a0;
extern u8 *reg_a6;

void func_001AED90(void) {
    u32 tmp;
    u32 d2;

    reg_d5.w = 8;
    D_0028E46C.w = reg_d7.w;
    reg_d7.h[1] = reg_d7.h[0];
    reg_d7.h[0] = 0;
    reg_d1.h[0] = *(u16 *)reg_a6;
    if (D_0028E710 != reg_d1.h[0]) {
        reg_d7.h[0] = 1;
        *(s16 *)(reg_a0 + 0) = 1;
        reg_d1.h[0] += 0xC030;
        *(u16 *)(reg_a0 + 6) = reg_d1.h[0];
    }
    if (reg_d1.h[0] != 0) {
        reg_d7.h[0] = 1;
    }
    reg_d1.w = D_0028E714;
    goto next_2;
loop_1:
    reg_d2.w = 0xF;
    reg_tmp.w = reg_d0.w;
    reg_d0.w <<= 4;
    D_0028E484 = reg_d1.w;
    reg_d1.w <<= 4;
    reg_d0.w |= reg_tmp.w >> 0x1C;
    reg_d1.w |= D_0028E484 >> 0x1C;
    d2 = reg_d2.w & reg_d0.w;
    reg_d2.w = d2;
    if ((d2 == 0) && (reg_d7.h[0] == 0)) {
        if (*(u16 *)(reg_a0 + 6) != 0) {
            *(s16 *)(reg_a0 + 0) = 1;
            *(u16 *)(reg_a0 + 6) = 0;
        }
    } else {
        reg_d7.h[0] = 1;
        if (*(u16 *)(reg_a0 + 6) == 0) {
            goto next_1;
        }
        reg_d3.w = 0xF;
        reg_d3.w &= reg_d1.w;
        if (reg_d2.h[0] != reg_d3.h[0]) {
next_1:
            *(s16 *)(reg_a0 + 0) = 1;
            reg_d2.h[0] += 0xC030;
            *(u16 *)(reg_a0 + 6) = reg_d2.h[0];
        }
    }
next_2:
    reg_a0 += 0xA;
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    D_0028E46C.w = reg_d7.w;
    reg_d7.h[1] = reg_d7.h[0];
    reg_d7.h[0] = D_0028E46C.h[1];
}
