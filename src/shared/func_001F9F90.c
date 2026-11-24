#include "common.h"

extern s8 D_0028E408;

s32 func_00129370();
extern u8 *reg_a6;

void func_001F9F90(void) {
    u8 var_a0;

    D_0028E408 = 0;
    reg_tmp.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x29)));
    (*(u8 *)((u8 *)(reg_a6) + (0x29))) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        var_a0 = 0x10000000;
        (*(u8 *)((u8 *)(reg_a6) + (0x29))) = (u8) (*(u8 *)((u8 *)(reg_a6) + (0x28)));
        (*(u8 *)((u8 *)(reg_a6) + (0x2C))) += 1;
        reg_d0.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2C)));
        (*(u8 *)((u8 *)(reg_a6) + (0x2D))) += reg_d0.b[0];
        reg_d1.b[0] = (*(u8 *)((u8 *)(reg_a6) + (0x2D)));
        reg_d0.w = 0x50003;
        reg_d2.h[1] = (*(u16 *)((u8 *)(reg_a6) + (2)));
        reg_d2.h[0] = (*(u16 *)((u8 *)(reg_a6) + (4)));
        reg_d2.w += 0x10000000;
        reg_d1.b[0] -= 0x18;
        reg_d7.w = 3;
        reg_d4.w = 0;
        reg_d3.w = 0;
        do {
            reg_d6.h[0] = reg_d1.h[0];
            func_00129370();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] += 0x80;
            reg_d6.h[0] = reg_d1.h[0];
            func_00129370();
            reg_d1.h[0] = reg_d6.h[0];
            reg_d1.b[0] += 0x8C;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
    (*(u16 *)((u8 *)(reg_a6) + (0x2A))) -= 1;
    if ((*(u16 *)((u8 *)(reg_a6) + (0x2A))) != 0) {
        D_0028E408 = 1;
        return;
    }
    D_0028E408 = 0;
}
