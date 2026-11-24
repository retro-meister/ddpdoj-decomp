#include "common.h"

extern u16 D_002BB338_as_u16_a[];
extern u16 D_002BB348_as_u16_a[];
extern u16 D_002BB358_as_u16_a[];
extern u16 D_002BB368_as_u16_a[];
extern u16 D_002BB378_as_u16_a[];
extern u16 D_002BB398_as_u16_a[];
extern s32 D_002BB3B0_as_s32_a[];
extern u8 D_002BB3F0_as_u8_a[];
extern u8 *reg_a0;
extern u8 *reg_a1;
extern u8 *reg_a2;
extern u8 *reg_a3;
extern u8 *reg_a5;
extern u8 *reg_a6;

extern s8 D_0028E408;

void func_00199560(void) {
    u32 tmp;

    D_0028E408 = 0;
    reg_d4.w = 4;
    reg_d1.w = 0;
    reg_a0 = (u8 *)D_002BB3B0_as_s32_a;
loop_1:
    if (*(u32 *)reg_a0 != reg_d0.w) {
        reg_a0 += 0xC;
        reg_d1.h[0] += 1;
        tmp = reg_d4.h[0] - 1;
        reg_d4.h[0] = tmp;
        if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
            goto loop_1;
        }
        reg_d0.w = 0;
        D_0028E408 = 1;
        reg_d0.h[0] -= 1;
        return;
    }
    reg_a2 = (u8 *)D_002BB348_as_u16_a;
    reg_d0.h[0] = reg_d1.h[0];
    reg_a3 = (u8 *)D_002BB338_as_u16_a;
    reg_a5 = (u8 *)D_002BB378_as_u16_a;
    reg_a6 = (u8 *)D_002BB368_as_u16_a;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_a5 += reg_d0.h[0];
    reg_a6 += reg_d0.h[0];
    reg_d2.h[0] = *(u16 *)reg_a3;
    reg_tmp.w = reg_d2.w;
    reg_d2.h[1] = reg_tmp.h[0];
    reg_d2.h[0] = reg_tmp.h[1];
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_d3.h[0] = *(u16 *)reg_a6;
    reg_tmp.w = reg_d3.w;
    reg_d3.h[1] = reg_tmp.h[0];
    reg_d3.h[0] = reg_tmp.h[1];
    reg_d3.h[0] = *(u16 *)reg_a5;
    reg_a2 = (u8 *)D_002BB398_as_u16_a;
    reg_a3 = (u8 *)D_002BB358_as_u16_a;
    reg_a2 += reg_d0.h[0];
    reg_a3 += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 = (u8 *)D_002BB3F0_as_u8_a;
    reg_a1 += reg_d0.h[0];
}
