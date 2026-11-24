#include "common.h"

s32 func_0019C5B0();
extern u16 D_0028E910;
extern u8 *reg_a6;

void func_00205DA0(void) {
    if (D_0028E910 != 0) goto block_rts;
    reg_d1.w = 0x5B001C00;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xEA00;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x36);
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xE400;
    reg_d2.w = 0xAD8;
    reg_d3.h[0] = 0x16E0;
    reg_d4.h[0] = 0x16;
    func_0019C5B0();
    reg_d1.w = 0x3FC03000;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xF600;
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_d1.h[0] += 0xF800;
    reg_d1.h[0] += *(u16 *)(reg_a6 + 0x38);
    reg_d2.w = 0xAD9;
    reg_d3.h[0] = 0xA40;
    reg_d4.h[0] = 0x16;
    func_0019C5B0();
block_rts:
    return;
}
