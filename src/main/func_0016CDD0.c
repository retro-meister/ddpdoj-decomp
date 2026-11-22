#include "common.h"

extern u8 D_0025B100[];
extern u8 *reg_a0;
extern u8 *reg_a5;
extern u8 *reg_a6;

void func_0016CDD0(void) {
    u8 temp_v1;

    reg_d0.w = 0;
    reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x1E)));
    reg_a0 = D_0025B100;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] *= 8;
    reg_a0 += reg_d0.h[0];
    (*(u16 *)((u8 *)(reg_a5) + (0x2A))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a5) + (0x2C))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a5) + (0x2E))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (0)));
    (*(u16 *)((u8 *)(reg_a5) + (0x30))) = (u16) (*(u16 *)((u8 *)(reg_a0) + (2)));
    temp_v1 = (*(u8 *)((u8 *)(reg_a6) + (0x1F)));
    if (temp_v1 != 0) {
        reg_d1.b[0] = temp_v1;
    }
    reg_d1.h[0] += reg_d1.h[0];
    (*(u8 *)((u8 *)(reg_a6) + (0x1F))) = (u8) reg_d1.b[0];
}
