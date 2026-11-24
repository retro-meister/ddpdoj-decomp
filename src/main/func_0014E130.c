#include "common.h"

extern u8 D_002BE0C0[];
extern u8 D_002BE160[];
extern u8 D_002BE3E0[];
extern u8 D_002BF2E0[];
extern u8 *reg_a0;

extern s8 D_0028E408;

void func_0014E130(void) {
    u32 sd0;
    u32 sd1;
    u32 sd2;
    u32 tmp;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    if (((s16) reg_d0.h[0] >= 0x20) && ((s16) reg_d0.h[0] < 0x24)) {
        reg_a0 = (u8 *)D_002BE160;
        reg_d2.w = 7;
    } else if ((s16) reg_d1.h[0] < 0) {
        reg_a0 = (u8 *)D_002BE0C0;
        reg_d2.w = 1;
    } else {
        reg_d3.w = 0;
        reg_a0 = (u8 *)D_002BE3E0;
        reg_d2.w = 0x2F;
    }
loop_1:
    if (*(u16 *)(reg_a0 + 0) == 0) {
        reg_d3.h[0] |= 0x8000;
        *(u16 *)(reg_a0 + 0) = reg_d3.h[0];
        *(s16 *)(reg_a0 + 2) = 0;
        *(s16 *)(reg_a0 + 4) = 0;
        *(s16 *)(reg_a0 + 0xA) = 0;
        *(u8 *)(reg_a0 + 0xD) = reg_d0.b[0];
        *(u8 *)(reg_a0 + 0xC) = reg_d1.b[0];
        reg_d0.w = sd0;
        reg_d1.w = sd1;
        reg_d2.w = sd2;
        D_0028E408 = 0;
        return;
    }
    reg_a0 += 0x50;
    reg_d3.h[0] += 1;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_a0 = (u8 *)D_002BF2E0;
    D_0028E408 = 1;
}
