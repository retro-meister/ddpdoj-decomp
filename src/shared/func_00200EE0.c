#include "common.h"

s64 __divdi3(s64, s64);
s64 __moddi3(s64, s64);
extern s64 D_00267010[];
extern u8 *reg_a0;

void func_00200EE0(void) {
    s8 buf[4];
    u8 *a0;
    u32 s0;
    u32 s1;
    u32 s3;
    u32 s4;
    s32 i;
    s32 off;
    s64 t;
    s64 x;

    s0 = reg_d0.w;
    s1 = reg_d1.w;
    s3 = reg_d3.w;
    s4 = reg_d4.w;
    a0 = reg_a0;
    reg_d2.w = 0;
    off = 0;
    for (i = 0; i < 4; i++) {
        x = (s32) reg_d0.h[0];
        t = *(s64 *)((u8 *)D_00267010 + off);
        if (x >= t) {
            buf[i] = __divdi3(x, t);
            reg_d0.h[0] = __moddi3(x, t);
        } else {
            buf[i] = 0;
        }
        reg_d2.w |= buf[i];
        reg_d2.w <<= 4;
        off += 8;
    }
    reg_d2.w |= reg_d0.h[0];
    reg_d1.w = s1;
    reg_d3.w = s3;
    reg_d4.w = s4;
    reg_a0 = a0;
    reg_d0.w = s0;
}
