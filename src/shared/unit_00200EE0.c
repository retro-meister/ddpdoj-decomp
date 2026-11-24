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

void func_00201010(void)
{
    unsigned char low = reg_d0.b[0];
    unsigned char high = reg_d0.b[1];

    reg_d2.w = 0;
    reg_tmp.b[0] = low & 15;
    reg_tmp.b[1] = low >> 4;
    reg_tmp.b[2] = high & 15;
    reg_tmp.b[3] = high >> 4;
    reg_d2.h[0] = reg_tmp.b[0] + (reg_tmp.b[1] * 10 +
        (reg_tmp.b[3] * 1000 + reg_tmp.b[2] * 100));
}

void func_002010A0(void)
{
    ++*(unsigned char *)&rng_cursor;
    reg_d0.h[0] = rng_cursor;
    reg_d0.b[0] = rng_values[reg_d0.h[0]];
}

void func_002010D0(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d1.h[0] = rng_cursor;
    reg_d1.b[0] = rng_values[reg_d1.h[0]];
}

extern Reg32 reg_d5;

void func_00201100(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d5.h[0] = rng_cursor;
    reg_d5.b[0] = rng_values[reg_d5.h[0]];
}

extern s8 rng_signed_word_values[256];

void func_00201130(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.h[0] = rng_cursor;
    reg_d0.h[0] = rng_signed_word_values[reg_d0.h[0]];
}

extern s8 rng_masked_values[128];

void func_00201160(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.w = rng_cursor & 0x7F;
    reg_d0.b[0] = rng_masked_values[reg_d0.h[0]];
}

extern u8 rng_unsigned_values[256];

void func_002011A0(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.h[0] = rng_cursor;
    reg_d0.b[0] = rng_unsigned_values[reg_d0.h[0]];
}
