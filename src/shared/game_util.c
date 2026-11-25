#include "common.h"
#include "credits_roll.h"

s32 task_start();                            /* extern */
#ifdef DEATH_LABEL
s32 task_reset_all();
extern u8 death_D_00290DC0;
#else
s32 task_stop_self();                            /* extern */
#endif

void func_00200D30(void) {
#ifdef DEATH_LABEL
    death_D_00290DC0 = 1;
    task_reset_all();
    reg_d0.h[0] = 0x15;
    task_start();
#else
    reg_d0.h[0] = 0xE;
    task_start();
    g_ending_started = 0;
    task_stop_self();
#endif
}

s32 sprite_palette_load();
extern u8 D_0025F770[];
extern s16 g_game_completed_as_s16;
extern u16 g_loop;

void func_00200D60(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    credits_roll_begin();
    reg_a0 = D_0025F770;
    reg_d0.h[0] = 2;
    sprite_palette_load();
    *(s16 *)(reg_a5 + 4) = 0;
    *(s16 *)(reg_a5 + 6) = 0x80;
    if (g_loop == 0) {
        *(s8 *)(reg_a5 + 3) = 2;
#ifndef DEATH_LABEL
        return;
#endif
    }
#ifndef DEATH_LABEL
    g_game_completed_as_s16 = 1;
#endif
}

s32 func_0013BE50();
s32 func_0013C300();
s32 func_0013C350();
s32 func_0018DED0();
extern u8 D_0024E090[];

void func_00200DD0() {
    u16 temp_a0;
    u8 temp_v1;

    temp_v1 = *(u8 *)(reg_a5 + 3);
    if (temp_v1 == 0) {
        func_00200D60();
        return;
    }
    if (temp_v1 == 2) {
        func_00200D30();
        return;
    }
#ifdef DEATH_LABEL
    if (*(u16 *)(reg_a5 + 4) == 0) {
        {
#else
    credits_roll_update();
    if ((*(u16 *)(reg_a5 + 4) == 0) && (g_credits_roll.scroll_speed == 0)) {
        *(u16 *)(reg_a5 + 6) -= 1;
        if (*(u16 *)(reg_a5 + 6) == 0) {
#endif
            *(u16 *)(reg_a5 + 4) = 1U;
            reg_a0 = D_0024E090;
            func_0013BE50();
            *(u16 *)(reg_a5 + 8) = (u16) reg_d0.h[1];
            *(u16 *)(reg_a5 + 0xA) = (u16) reg_d0.h[0];
            reg_d1.w = 0;
            func_0018DED0();
        }
    }
    temp_a0 = *(u16 *)(reg_a5 + 4);
    if (temp_a0 == 1) {
        reg_d0.h[1] = *(u16 *)(reg_a5 + 8);
        reg_d0.h[0] = *(u16 *)(reg_a5 + 0xA);
        func_0013C350();
        if (cond_flag == 0) {
            func_0013C300();
            *(u8 *)(reg_a5 + 3) = 2U;
        }
    }
}

s64 __divdi3(s64, s64);
s64 __moddi3(s64, s64);
extern s64 D_00267010[];

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

void rng_next(void)
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

void rng_next_masked(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.w = rng_cursor & 0x7F;
    reg_d0.b[0] = rng_masked_values[reg_d0.h[0]];
}

extern u8 rng_unsigned_values[256];

void rng_next_unsigned(void)
{
    ++*(u8 *)&rng_cursor;
    reg_d0.h[0] = rng_cursor;
    reg_d0.b[0] = rng_unsigned_values[reg_d0.h[0]];
}

extern u16 rng_cursor;
extern Reg32 reg_d0;
extern s8 D_00266B90[];

void rng_next_bit(void) {
    *(u8 *)&rng_cursor += 1;
    reg_d0.h[0] = rng_cursor;
    reg_d0.h[0] = D_00266B90[reg_d0.h[0]];
}

void func_00201200(void) {
    *(u8 *)&rng_cursor += 1;
    reg_d5.h[0] = rng_cursor;
    reg_d5.h[0] = (u16)D_00266B90[reg_d5.h[0]];
}

extern s8 D_00266B10[];

void func_00201230(void)
{
    *(u8 *)&rng_cursor += 1;
    reg_d0.w = rng_cursor & 0x7F;
    reg_d0.b[0] = D_00266B10[reg_d0.h[0]];
}

extern s8 D_00266AD0[];

void func_00201270(void)
{
    *(u8 *)&rng_cursor += 1;
    reg_d0.w = rng_cursor & 0x3F;
    reg_d0.b[0] = D_00266AD0[reg_d0.h[0]];
}

void func_002012B0(void)
{
    *(u8 *)&rng_cursor += 1;
    reg_d1.w = rng_cursor & 0x3F;
    reg_d1.b[0] = D_00266AD0[reg_d1.h[0]];
}

extern s16 D_002669D0[];

void rng_next_word(void)
{
    *(u8 *)&rng_cursor += 1;
    reg_d0.w = rng_cursor & 0x7F;
    reg_d0.h[0] = D_002669D0[reg_d0.h[0]];
}

extern s16 D_002668D0[];
extern s16 D_002668D2[];

void func_00201330(void)
{
    s32 table_index;

    *(u8 *)&rng_cursor += 1;
    reg_d1.w = rng_cursor & 0x3F;
    reg_d1.h[0] *= 2;
    table_index = reg_d1.h[0];
    reg_d1.sh[1] = D_002668D0[table_index];
    reg_d1.h[0] = (u16)D_002668D2[table_index];
}

extern s16 D_002667D0[];
extern s16 D_002667D2[];

void func_00201390(void)
{
    u16 table_index;

    *(u8 *)&rng_cursor += 1;
    reg_d4.w = rng_cursor & 0x3F;
    reg_d4.h[0] <<= 1;
    table_index = reg_d4.h[0];
    reg_d4.sh[1] = D_002667D0[table_index];
    reg_d4.h[0] = (u16)D_002667D2[table_index];
}

extern s16 D_002666D0[];
extern s16 D_002666D2[];

void func_002013F0(void)
{
    u16 table_index;

    (*(u8 *)&rng_cursor)++;
    reg_d1.w = rng_cursor & 0x3F;
    reg_d1.h[0] *= 2;
    table_index = reg_d1.h[0];
    reg_d1.sh[1] = D_002666D0[table_index];
    reg_d1.h[0] = (u16)D_002666D2[table_index];
}

extern u16 D_00299764[];
extern u16 D_00299766[];

void func_00201450(void) {
    cond_flag = 0;
    if ((D_00299764[0] != 0) && ((s32) D_00299766[0] >= 0x20) && ((s32) D_00299766[0] < 0x3D)) {
        cond_flag = 1;
    }
}

s32 func_002018E0();
void func_00201490(void) {
    func_00201450();
    if (cond_flag == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
        func_002018E0();
    }
}

s32 func_00201A00();
s32 func_00201B30();
extern u32 reg_save_d7;
extern u32 reg_save_d6;
extern u32 reg_save_d5;
extern u32 reg_save_d4;
extern u32 reg_save_d3;
extern u32 reg_save_d2;
extern u32 reg_save_d1;
extern u32 reg_save_d0;
extern u8 *reg_save_a6;
extern u8 *reg_save_a5;
extern u8 *reg_save_a4_as_u8_p;
extern u8 *reg_save_a3_as_u8_p;
extern u8 *reg_save_a2;
extern u8 *reg_save_a1;
extern u8 *reg_save_a0_as_u8_p;
extern u8 D_0028E855;

void func_002014D0(void) {
    func_00201450();
    if (cond_flag == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
        if (D_0028E855 & 2) {
            func_00201B30();
            return;
        }
        reg_save_d0 = reg_d0.w;
        reg_save_d1 = reg_d1.w;
        reg_save_d2 = reg_d2.w;
        reg_save_d3 = reg_d3.w;
        reg_save_d4 = reg_d4.w;
        reg_save_d5 = reg_d5.w;
        reg_save_d6 = reg_d6.w;
        reg_save_d7 = reg_d7.w;
        reg_save_a0_as_u8_p = reg_a0;
        reg_save_a1 = reg_a1;
        reg_save_a2 = reg_a2;
        reg_save_a3_as_u8_p = reg_a3;
        reg_save_a4_as_u8_p = reg_a4;
        reg_save_a5 = reg_a5;
        reg_save_a6 = reg_a6;
        reg_d1.h[0] = 0x8010;
        func_00201A00();
    }
}

void func_002015B0(void) {
    func_00201450();
    if (cond_flag == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
        if (D_0028E855 & 2) {
            func_00201B30();
            return;
        }
        reg_save_d0 = reg_d0.w;
        reg_save_d1 = reg_d1.w;
        reg_save_d2 = reg_d2.w;
        reg_save_d3 = reg_d3.w;
        reg_save_d4 = reg_d4.w;
        reg_save_d5 = reg_d5.w;
        reg_save_d6 = reg_d6.w;
        reg_save_d7 = reg_d7.w;
        reg_save_a0_as_u8_p = reg_a0;
        reg_save_a1 = reg_a1;
        reg_save_a2 = reg_a2;
        reg_save_a3_as_u8_p = reg_a3;
        reg_save_a4_as_u8_p = reg_a4;
        reg_save_a5 = reg_a5;
        reg_save_a6 = reg_a6;
        reg_d1.h[0] = 0x8008;
        func_00201A00();
    }
}

void func_00201690(void) {
    func_00201450();
    if (cond_flag == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
    }
}

void func_002016D0(void) {
    func_00201450();
    if (cond_flag == 0) {
        D_00299764[0] = 1;
        D_00299766[0] = 0xFFFF;
        func_00201B30();
    }
}
