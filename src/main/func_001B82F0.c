#include "common.h"

extern s8 D_0028E408;

void func_001B8D00(void);
extern u32 D_0028E52C;
extern u16 D_0028E910;
extern u16 D_0028E928;
extern u16 D_0029A530[];
extern u16 D_0029AA30[];
extern u8 *reg_a0;

void func_001B82F0(void) {
    u32 tmp;
    s32 tmp2;

    reg_d3.w = reg_d0.w;
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = *(volatile u16 *)&reg_tmp.h[0];
    reg_d3.h[0] = *(volatile u16 *)&reg_tmp.h[1];
    reg_d3.w = (u32) reg_d3.b[0];
    if (reg_d3.w != 0) {
        reg_d3.w -= 0x10000;
    }
loop_1:
    reg_a0 = (u8 *)D_0029A530;
    reg_d1.h[0] = 0x13;
    if ((D_0028E910 != 0) || (D_0028E928 == 0)) {
        reg_d1.h[0] = 9;
    }
loop_2:
    if (*(u16 *)reg_a0 != 0) {
        reg_a0 += 0x40;
        tmp2 = reg_d1.h[0] - 1;
        reg_d1.h[0] = tmp2;
        if (((s64) ((s64) (u16) tmp2 << 0x30) >> 0x30) >= 0) {
            goto loop_2;
        }
        reg_d1.w = 0;
        D_0028E408 = 1;
        reg_d1.h[0] -= 1;
        return;
    }
    D_0028E52C = reg_d0.w;
    func_001B8D00();
    D_0029AA30[0] += 1;
    reg_d0.w = D_0028E52C;
    tmp = reg_d3.h[0] - 1;
    reg_d3.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    D_0028E408 = 0;
}
