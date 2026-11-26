#include "common.h"
#include "player.h"

extern void (*D_00250D00[8])();
extern void *D_00251120[256];
extern s16 g_player2[56];
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_0020A370(void);
void func_0020A3B0(void);
void func_0020AAA0(void);
void func_0020B5F0(void);
void func_0020B640(void);


s32 input_get_p1_pressed();
s32 sfx_confirm();
s32 sfx_cursor_move();
s32 test_screen_request();
s32 test_system_cursor_erase();
s32 test_system_cursor_draw();
s32 test_system_print_items();
s32 test_system_print_values();
extern s8 g_test_redraw;
extern s8 g_test_cursor;
extern u8 g_setting_chute_type;
extern u8 g_setting_demo_sound;
extern u8 g_setting_continue;
extern u8 g_setting_coin_mode;


extern u8 D_00299D30[];

void func_00209E60(void) {
    memset(&D_00299D30[0], 0, 0x7FC);
}

extern u16 D_0029A528[];

void func_00209E80(void) {
    *(u16 *)((u8 *)reg_a6 - 2) = 0;
    D_0029A528[0] -= 1;
}


void func_00209EA0(void) {
    *(u16 *)((u8 *)((void *)reg_a6) - 4) = 0;
    D_0029A528[0] -= 1;
}

void func_00209EC0(void) {
    *(u16 *)(reg_a6 - 8) = 0;
    D_0029A528[0] -= 1;
}

extern u8 *D_0028E570;
extern u16 g_sprite_sparks_used;

void func_00209EE0(void) {
    reg_a4 -= (*(s32 *)&D_0028E570);
    reg_tmp.sw = (s32)reg_a4;
    g_sprite_sparks_used = reg_tmp.h[0];
}


void func_00209F10(void) {
    (*(u8 *)&cond_flag) = 1;
}

extern u32 reg_save4_d7;
extern u32 reg_save4_d6;
extern u32 reg_save4_d5;
extern u32 reg_save4_d4;
extern u32 reg_save4_d3;
extern u32 reg_save4_d2;
extern u32 reg_save4_d1;
extern u32 reg_save4_d0;
extern u8 *reg_save4_a6;
extern u8 *reg_save4_a5;
extern u8 *reg_save4_a4;
extern u8 *reg_save4_a3;
extern u8 *reg_save4_a2;
extern u8 *reg_save4_a1;
extern u8 *reg_save4_a0;
extern u16 g_loop;
extern u8 D_0029A12C[];
extern s16 g_player1[56];

void func_00209F20(void) {
    if (g_loop != 0) {
        func_00209F10();
        return;
    }
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    *(u8 *)&rng_cursor += 1;
    reg_d5.h[0] = rng_cursor;
    reg_d1.w = 0;
    reg_a2 = *(u8 **)(((u8 *)D_00251120) + reg_d5.h[0] * 4);
    reg_a0 = (u8 *)D_00299D30;
    if (((u8 *)g_player1) == reg_a4) {
        func_0020A370();
        return;
    }
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}

extern u8 D_00250E00[];
extern void *reg_save4_a6_as_void_p;

void func_0020A040(void) {
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6_as_void_p = reg_a6;
    reg_d7.w = 0;
    reg_d1.w = 1;
    reg_a2 = (u8 *)D_00250E00;
    reg_a0 = (u8 *)D_00299D30;
    reg_d0.w = 0;
    if (ENTITY(reg_a6)->move.h != 0) {
        func_0020A370();
        return;
    }
    reg_d7.w = 1;
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}

void func_0020A120(void) {
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    reg_a2 = (u8 *)D_00250E00;
    reg_a0 = (u8 *)D_00299D30;
    reg_d1.w = 0;
    reg_d0.w = 0;
    reg_d7.w = 0;
    func_0020A370();
}

void func_0020A1C0(void) {
    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = reg_a0;
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    reg_a2 = (u8 *)D_00250E00;
    reg_a0 = (u8 *)D_0029A12C;
    reg_d7.w = 1;
    reg_d1.w = 0;
    reg_d0.w = 0;
    func_0020A370();
}

s32 func_00201230();
extern u8 D_00250D88[];
extern u16 g_bomb_entities[24];

void func_0020A270(void) {
    s32 temp_a1;
    s32 temp_a2;

    reg_save4_d0 = reg_d0.w;
    reg_save4_d1 = reg_d1.w;
    reg_save4_d2 = reg_d2.w;
    reg_save4_d3 = reg_d3.w;
    reg_save4_d4 = reg_d4.w;
    reg_save4_d5 = reg_d5.w;
    reg_save4_d6 = reg_d6.w;
    reg_save4_d7 = reg_d7.w;
    reg_save4_a0 = (u8 *)(reg_a0);
    reg_save4_a1 = reg_a1;
    reg_save4_a2 = reg_a2;
    reg_save4_a3 = reg_a3;
    reg_save4_a4 = reg_a4;
    reg_save4_a5 = reg_a5;
    reg_save4_a6 = reg_a6;
    reg_d1.w = 0;
    func_00201230();
    temp_a2 = reg_d0.h[0] * 4;
    temp_a1 = *(u32 *)(D_00250D88 + temp_a2);
    reg_a2 = (u8 *)temp_a1;
    reg_d7.h[0] = 0xFFFF;
    reg_a0 = (u8 *)D_00299D30;
    reg_d0.w = 0;
    if (!(((u8 *)g_bomb_entities)[0] & 0x80)) {
        func_0020A370();
        return;
    }
    reg_a0 = (u8 *)D_0029A12C;
    func_0020A370();
}

extern u16 g_two_player_game;

void func_0020A370(void) {
    reg_d2.w = 0x1D;
    if (g_two_player_game != 0) {
        func_0020A3B0();
        return;
    }
    reg_d2.w = 0xE;
    func_0020A3B0();
}


void func_0020A3B0(void) {
    u32 t;

loop_1:
    if (*(u16 *)reg_a0 == 0) goto next_2;
    reg_a0 += 0x22;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
    cond_flag = 1;
    reg_d0.w = reg_save4_d0;
    reg_d1.w = reg_save4_d1;
    reg_d2.w = reg_save4_d2;
    reg_d3.w = reg_save4_d3;
    reg_d4.w = reg_save4_d4;
    reg_d5.w = reg_save4_d5;
    reg_d6.w = reg_save4_d6;
    reg_d7.w = reg_save4_d7;
    reg_a0 = (u8 *)((u16 *)reg_save4_a0);
    reg_a1 = (u8 *)(*(s32 *)&reg_save4_a1);
    reg_a2 = (u8 *)(*(s32 *)&reg_save4_a2);
    reg_a3 = (u8 *)(*(s32 *)&reg_save4_a3);
    reg_a4 = (u8 *)(*(s32 *)&reg_save4_a4);
    reg_a5 = (u8 *)(*(s32 *)&reg_save4_a5);
    reg_a6 = (u8 *)(*(s32 *)&reg_save4_a6);
    return;
next_2:
    func_0020AAA0();
    reg_tmp.h[0] = reg_d1.h[0];
    reg_d1.h[0] -= 1;
    if (reg_tmp.h[0] == 0) goto next_3;
    t = reg_d2.h[0] - 1;
    reg_d2.h[0] = t;
    if (((s64) ((s64) (t & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_3:
    cond_flag = 0;
    reg_d0.w = reg_save4_d0;
    reg_d1.w = reg_save4_d1;
    reg_d2.w = reg_save4_d2;
    reg_d3.w = reg_save4_d3;
    reg_d4.w = reg_save4_d4;
    reg_d5.w = reg_save4_d5;
    reg_d6.w = reg_save4_d6;
    reg_d7.w = reg_save4_d7;
    reg_a0 = (u8 *)((u16 *)reg_save4_a0);
    reg_a1 = (u8 *)(*(s32 *)&reg_save4_a1);
    reg_a2 = (u8 *)(*(s32 *)&reg_save4_a2);
    reg_a3 = (u8 *)(*(s32 *)&reg_save4_a3);
    reg_a4 = (u8 *)(*(s32 *)&reg_save4_a4);
    reg_a5 = (u8 *)(*(s32 *)&reg_save4_a5);
    reg_a6 = (u8 *)(*(s32 *)&reg_save4_a6);
}

extern u16 g_frame_mod8;
extern u16 g_frame_mod2;
extern u8 *D_0028E570;
extern u16 D_0029A52A[];
extern u8 g_sprite_sparks_buf[];

#define W(o) (*(u16 *)(reg_a6 + (o)))
#define LOOKUP(d) (((d) != 0) ? *(u16 *)(reg_a0 + ((s16)(d) & ~1)) : *(u16 *)reg_a0)

void func_0020A540(void) {
    reg_d0.w = 0;
    D_0029A52A[0] = 0xD0;
    D_0029A52A[0] -= reg_d0.h[0];
    if (0 > (s16) D_0029A52A[0]) {
        D_0029A52A[0] = 0;
    }
    reg_d7.h[0] = D_0029A528[0];
    if (reg_d7.h[0] == 0) return;
    reg_d7.h[0] -= 1;
    reg_d6.h[0] = g_frame_mod8;
    reg_d6.h[0] = -reg_d6.sh[0];
    reg_tmp.w = reg_d6.w;
    reg_d6.h[1] = reg_tmp.h[0];
    reg_d6.h[0] = g_frame_mod2;
    reg_d5.h[0] = 0x7000;
    reg_tmp.w = reg_d5.w;
    reg_d5.h[1] = reg_tmp.h[0];
    reg_d5.h[0] = D_0029A52A[0];
    reg_d4.w = 6;
    reg_d3.w = 0x07FF03FF;
    reg_d2.w = 0x80008000;
    reg_d1.w = 0x1A;
    reg_a6 = (u8 *)D_00299D30;
    reg_a4 = (u8 *)g_sprite_sparks_buf;
    D_0028E570 = reg_a4;
    goto loop_2;
loop_1:
    reg_a6 += 0x20;
loop_2:
    reg_d0.h[0] = W(0);
    reg_a6 += 2;
    if (reg_d0.h[0] == 0) goto loop_1;
    if (reg_d5.h[0] == 0) goto block_clr2;
    reg_d5.h[0] -= 1;
    reg_d0.h[0] = W(0);
    reg_a6 += 2;
    switch (reg_d0.h[0]) {
    default:
    block_clr2:
        func_00209E80();
        reg_a6 += 0x20;
        if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
        func_00209EE0();
        return;
    case 0:
    block_a:
        reg_a6[0xF] -= 1;
        if (0 > (s8) reg_a6[0xF]) goto next_4;
        goto block_move;
    next_4:
        reg_a6[0xF] = reg_a6[0xE];
        goto block_anim;
    block_d:
        reg_a6[0x17] -= 1;
        if (0 > (s8) reg_a6[0x17]) goto next_5;
        goto block_a;
    next_5:
        reg_a6[0x17] = reg_a6[0x16];
    case 4:
        reg_a6[0x17] -= 1;
        if (0 > (s8) reg_a6[0x17]) goto next_6;
        goto block_a;
    next_6:
        reg_a6[0x17] = reg_a6[0x16];
    case 8:
    block_anim:
        reg_d0.h[0] = W(0x10);
        reg_tmp.h[0] = W(0x10);
        W(0x10) -= 4;
        if (reg_tmp.h[0] < 4) goto block_clr4;
        reg_tmp.h[1] = W(0x12);
        reg_tmp.h[0] = W(0x14);
        reg_a0 = (u8 *) reg_tmp.w;
        W(4) = LOOKUP(reg_d0.h[0]);
        W(6) = LOOKUP(reg_d0.h[0] + 2);
    block_move:
        reg_d0.h[1] = W(0x18);
        reg_d0.h[0] = W(0x1A);
        reg_tmp.h[1] = W(0);
        reg_tmp.h[0] = W(2);
        reg_d0.w += reg_tmp.w;
        W(0) = reg_d0.h[1];
        reg_a6 += 2;
        W(0) = reg_d0.h[0];
        reg_a6 += 2;
        if (0 > reg_d6.sh[0]) goto next_3;
        if (!(reg_d5.w > reg_d0.w)) goto block_clr8;
    next_3:
        reg_d0.w = reg_d0.sw >> reg_d4.w;
        reg_d0.w &= reg_d3.w;
        reg_d0.w |= reg_d2.w;
        *(u16 *)reg_a4 = reg_d0.h[1];
        reg_a4 += 2;
        *(u16 *)reg_a4 = reg_d0.h[0];
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a6 += 2;
        reg_a4 += 2;
        *(u16 *)reg_a4 = W(0);
        reg_a4 += 2;
        reg_a6 += 0x14;
        if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
        func_00209EE0();
        return;
    case 12:
        goto block_d;
    }
block_clr4:
    func_00209EA0();
    reg_a6 += 0x1E;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
    func_00209EE0();
    return;
block_clr8:
    func_00209EC0();
    reg_a6 += 0x1A;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_2;
    func_00209EE0();
}

typedef void (*Fn)();

s32 func_00201200();
extern s32 D_0028E530;

void func_0020AAA0(void) {
    u16 *temp_a2;
    u16 *temp_a3;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a1;

    (*(u16 **)&D_0028E530) = (u16 *)(reg_a2);
    reg_d3.h[0] = reg_d0.h[0];
    reg_d3.h[0] |= 0x8000;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    reg_d3.h[0] = ENTITY(reg_a6)->y.h;
    temp_a0 = reg_d3.h[0] + *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d3.h[0] = temp_a0;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_d3.h[0] = ENTITY(reg_a6)->x.h;
    temp_a0_2 = *(u16 *)reg_a2;
    temp_a1 = reg_d3.h[0];
    reg_d3.h[0] = temp_a1 + temp_a0_2;
    reg_a2 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_a0 += 4;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    reg_d3.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if (0 > (s16) reg_d3.h[0]) {
        reg_d3.w = 0;
        reg_d3.b[0] = ENTITY(reg_a6)->attr.b.palette;
    }
    func_00201200();
    if (reg_d5.h[0] == 0) {
        reg_d3.h[0] |= 0x2000;
    }
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a2;
    temp_a3 = (u16 *)(reg_a2 + 2);
    temp_a2 = (u16 *)(reg_a0 + 2);
    reg_a2 = (u8 *)(temp_a3);
    reg_a0 = (u8 *)(temp_a2);
    D_0029A528[0] += 1;
    ((Fn)*(u32 *)((u8 *)((u8 *)D_00250D00) + (reg_d0.h[0] & ~3)))();
}

s32 rng_next_masked();
s32 rng_next_unsigned();
s32 velocity_from_direction();
extern u16 D_00250D20[];

void func_0020AD50(void) {
    u32 temp_a0;
    u32 temp_s0;
    u32 temp_s1;
    u32 temp_s2;
    u32 temp_s3;

    temp_s1 = reg_d0.w;
    temp_s2 = reg_d1.w;
    temp_s3 = reg_d2.w;
    reg_d3.w = 0x18;
    rng_next_unsigned();
    if (0 > reg_d0.sb[0]) {
        reg_d3.w = 0x28;
    }
    func_0020B5F0();
    reg_d1.b[0] += reg_d3.b[0];
    reg_d1.b[0] &= 0x3F;
    rng_next_masked();
    temp_s0 = reg_d1.w;
    reg_d0.b[0] += 4;
    velocity_from_direction();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    temp_a0 = (*(u16 *)((u8 *)(reg_a0) + (-0x1C)));
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.h[0] = 0xC0;
    if (0 <= (s16)(reg_d7.h[0])) {
        if (reg_d7.h[0] & 0xFFFF) {
            reg_d1.h[0] = PLAYER(((u8 *)g_player2))->laser_power.h;
        } else {
            reg_d1.h[0] = PLAYER(((u8 *)g_player1))->laser_power.h;
        }
        reg_a2 = (u8 *)(D_00250D20);
        reg_a2 += reg_d1.h[0];
        reg_d0.h[0] = *(u16 *)reg_a2;
    } else {
        reg_d3.h[0] = 2;
        if (((u8 *)g_bomb_entities)[0] & 0x80) {
            reg_d3.h[0] = 3;
        }
        (*(u8 *)((u8 *)(reg_a0) + (-0x12))) = (u8) reg_d3.b[0];
    }
    reg_d1.w = temp_s0;
    velocity_from_direction();
    (*(u16 *)((u8 *)(reg_a0) + (-0x1A))) += reg_d3.h[0];
    reg_d0.w = temp_s1;
    reg_d1.w = temp_s2;
    reg_d2.w = temp_s3;
    reg_a0 += 2;
    reg_a2 = (u8 *)((*(u16 **)&D_0028E530));
}


void func_0020AF10(void) {
    reg_a0 += 6;
}

extern s32 D_0028E530;

void func_0020AF20(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    rng_next_masked();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B5F0();
    reg_d1.h[0] &= 0x3F;
    velocity_from_direction();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

s32 velocity_from_dir256();

void func_0020B030(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    rng_next_masked();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B640();
    velocity_from_dir256();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B140(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    rng_next_masked();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B5F0();
    reg_d1.b[0] += ENTITY(reg_a6)->move.b.dir;
    reg_d1.h[0] &= 0x3F;
    velocity_from_direction();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B270(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    rng_next_masked();
    reg_d0.b[0] += 8;
    if ((s32) reg_d0.b[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B640();
    reg_d1.b[0] += ENTITY(reg_a6)->move.b.dir;
    velocity_from_dir256();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B390(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    rng_next_masked();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B5F0();
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] += 0x20;
    reg_d1.h[0] &= 0x3F;
    velocity_from_direction();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

void func_0020B4C0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    rng_next_masked();
    reg_d0.h[0] += 8;
    if ((s32) reg_d0.h[0] >= 0x24) {
        reg_d0.w = 0x24;
    }
    func_0020B640();
    reg_d1.b[0] += ENTITY(reg_a6)->move.b.dir;
    reg_d1.b[0] += 0x80;
    velocity_from_dir256();
    *(u16 *)reg_a0 = (u16) reg_d2.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = (u16) reg_d3.h[0];
    reg_a0 += 2;
    reg_d2.h[0] = (s16) reg_d2.h[0] * 4;
    reg_d3.h[0] += reg_d3.h[0];
    reg_d3.h[0] += reg_d3.h[0];
    reg_a0 += 2;
    (*(u16 *)((u8 *)(reg_a0) + (-0x1E))) += reg_d2.h[0];
    (*(u16 *)((u8 *)(reg_a0) + (-0x1C))) += reg_d3.h[0];
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_a2 = (u8 *)D_0028E530;
}

extern s8 D_00251520[];

void func_0020B5F0(void)
{
    u32 cursor = *(u8 *)&rng_cursor;

    reg_d1.w = 0x3F;
    reg_a2 = (u8 *)D_00251520;
    *(u8 *)&rng_cursor = cursor + 1U;
    reg_d1.h[0] &= rng_cursor;
    reg_a2 += reg_d1.h[0];
    reg_d1.b[0] = (u8)*(s8 *)reg_a2;
}

extern s8 D_00251560[];

void func_0020B640(void)
{
    u32 cursor = *(u8 *)&rng_cursor;
    s8 *table;
    u32 mask;

    reg_d1.w = 0x3F;
    table = D_00251560;
    mask = reg_d1.h[0];
    reg_a2 = (u8 *)table;
    *(u8 *)&rng_cursor = (u8)(cursor + 1U);
    reg_d1.h[0] = (u16)(mask & (u32)rng_cursor);
    reg_a2 += reg_d1.h[0];
    reg_d1.b[0] = (u8)*(s8 *)reg_a2;
}

extern u16 D_00250D30[16];
extern u16 D_00250D50[16];
struct D00250d70Record { u16 w0[12]; void *p1; void *p2; void *p3; u16 w4[6]; };
extern struct D00250d70Record D_00250D70;
extern u16 D_00251100[16];
extern u16 D_002510A0[16];
extern u16 D_00251020[16];
extern u16 D_00251080[16];
extern u16 D_002510C0[16];
extern u16 D_00250FC0[16];
extern u16 D_00250F40[16];
extern u16 D_002510E0[16];
extern u16 D_00251000[16];
extern u16 D_00250FA0[16];
extern u16 D_00251040[16];
extern u16 D_00250F60[16];
extern u16 D_00250FE0[16];
extern u16 D_00251060[16];
extern u16 D_00250F80[16];
void entity_draw_layer1();
void entity_draw_layer2();
void entity_draw_layer3();
void entity_draw_layer4();
void entity_draw_layer5();
extern u16 D_00251680[16];
extern u16 D_002516A0[16];
extern u16 D_002516C0[16];
extern u16 D_002516E0[16];
extern u8 D_0028C0E8[];
extern u8 D_0028C0EC[];
extern u8 D_0028C0F0[];
extern u8 D_0028C0F4[];

void (*D_00250D00[8])() = {
    func_0020AD50,
    func_0020AF10,
    func_0020AF20,
    func_0020B030,
    func_0020B140,
    func_0020B270,
    func_0020B390,
    func_0020B4C0,
};

u16 D_00250D20[8] = {
    0x0020, 0x0040, 0x0060, 0x0080, 0x00B0, 0x0000, 0x0000, 0x0000,
};

u16 D_00250D30[16] = {
    0x0000, 0xFC00, 0xFD00, 0x0418, 0x0006, 0x0606, 0x0002, 0x001C,
    0x0008, 0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00250D50[16] = {
    0x0000, 0xFC00, 0xFD00, 0x0418, 0x0006, 0x0606, 0x0002, 0x001C,
    0x0008, 0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

struct D00250d70Record D_00250D70 = {
    { 0x0000, 0xFC00, 0xFD00, 0x0418, 0x0006, 0x0606, 0x0002, 0x001C, 0x0008, 0x0009, 0x0000, 0x0000 },
    D_00250D30,
    D_00250D50,
    &D_00250D70,
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000 },
};

u16 D_00250DA0[16] = {
    0x0000, 0x09D7, 0x0000, 0x09D6, 0x0000, 0x09D5, 0x0000, 0x09D4,
    0x0000, 0x09D3, 0x0000, 0x09D2, 0x0000, 0x09D1, 0x0000, 0x09D0,
};

u16 D_00250DC0[16] = {
    0x0000, 0x09DF, 0x0000, 0x09DE, 0x0000, 0x09DD, 0x0000, 0x09DC,
    0x0000, 0x09DB, 0x0000, 0x09DA, 0x0000, 0x09D9, 0x0000, 0x09D8,
};

u16 D_00250DE0[16] = {
    0x0000, 0x09E7, 0x0000, 0x09E6, 0x0000, 0x09E5, 0x0000, 0x09E4,
    0x0000, 0x09E3, 0x0000, 0x09E2, 0x0000, 0x09E1, 0x0000, 0x09E0,
};

u8 D_00250E00[32] = {
    0x04, 0x00, 0x00, 0xFE, 0x00, 0xFF, 0x08, 0x02, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x8C, 0x00,
    0x08, 0x00, 0x09, 0x00, 0x06, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u16 D_00250E20[72] = {
    0x0000, 0x1403, 0x0000, 0x1402, 0x0000, 0x1401, 0x0000, 0x1400,
    0x0000, 0x13FF, 0x0000, 0x13FE, 0x0000, 0x13FD, 0x0000, 0x13FC,
    0x0000, 0x13FB, 0x0000, 0x13FA, 0x0000, 0x13F9, 0x0000, 0x13F8,
    0x0000, 0x13F7, 0x0000, 0x13F6, 0x0000, 0x13F5, 0x0000, 0x13F4,
    0x0000, 0x13F3, 0x0000, 0x13F2, 0x0000, 0x13F1, 0x0000, 0x13F0,
    0x0000, 0x13EF, 0x0000, 0x13EE, 0x0000, 0x13ED, 0x0000, 0x13EC,
    0x0000, 0x13EB, 0x0000, 0x13EA, 0x0000, 0x13E9, 0x0000, 0x13E8,
    0x0000, 0x13E7, 0x0000, 0x13E6, 0x0000, 0x13E5, 0x0000, 0x13E4,
    0x0000, 0x13E3, 0x0000, 0x13E2, 0x0000, 0x13E1, 0x0000, 0x13E0,
};

u16 D_00250EB0[72] = {
    0x0000, 0x144B, 0x0000, 0x144A, 0x0000, 0x1449, 0x0000, 0x1448,
    0x0000, 0x1447, 0x0000, 0x1446, 0x0000, 0x1445, 0x0000, 0x1444,
    0x0000, 0x1443, 0x0000, 0x1442, 0x0000, 0x1441, 0x0000, 0x1440,
    0x0000, 0x143F, 0x0000, 0x143E, 0x0000, 0x143D, 0x0000, 0x143C,
    0x0000, 0x143B, 0x0000, 0x143A, 0x0000, 0x1439, 0x0000, 0x1438,
    0x0000, 0x1437, 0x0000, 0x1436, 0x0000, 0x1435, 0x0000, 0x1434,
    0x0000, 0x1433, 0x0000, 0x1432, 0x0000, 0x1431, 0x0000, 0x1430,
    0x0000, 0x142F, 0x0000, 0x142E, 0x0000, 0x142D, 0x0000, 0x142C,
    0x0000, 0x142B, 0x0000, 0x142A, 0x0000, 0x1429, 0x0000, 0x1428,
};

u16 D_00250F40[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x008C,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00250F60[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0080,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00250F80[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0074,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00250FA0[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0068,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00250FC0[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x005C,
    0x0008, 0x0009, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00250FE0[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0050,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00251000[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0044,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00251020[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0038,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00251040[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x002C,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00251060[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0020,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00251080[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x008C,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_002510A0[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0074,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_002510C0[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0050,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_002510E0[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x002C,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u16 D_00251100[16] = {
    0x000C, 0xFE00, 0xFF00, 0x0208, 0x001E, 0x1E1D, 0x0000, 0x0020,
    0x0008, 0x0009, 0x0E06, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

void *D_00251120[256] = {
    D_00251100,
    D_002510A0,
    D_00251020,
    D_00251080,
    D_002510C0,
    D_00250FC0,
    D_00251020,
    D_00250F40,
    D_002510E0,
    D_00251000,
    D_00250FA0,
    D_00251040,
    D_00251080,
    D_00250F60,
    D_002510A0,
    D_00250FE0,
    D_00250F60,
    D_00251060,
    D_00250FA0,
    D_002510A0,
    D_00250FE0,
    D_002510A0,
    D_00251100,
    D_00251020,
    D_00251020,
    D_00250F40,
    D_00251000,
    D_00250F80,
    D_00250FE0,
    D_00251080,
    D_002510E0,
    D_002510E0,
    D_00251020,
    D_00251000,
    D_00250F40,
    D_002510C0,
    D_00251020,
    D_00250F60,
    D_002510A0,
    D_00250FA0,
    D_00251040,
    D_002510A0,
    D_00251020,
    D_00251080,
    D_00250F80,
    D_00250FE0,
    D_00251020,
    D_00251080,
    D_002510A0,
    D_00250F60,
    D_002510A0,
    D_00250F40,
    D_00250FA0,
    D_00251080,
    D_00250F60,
    D_00251060,
    D_002510E0,
    D_00250F80,
    D_00251080,
    D_00251020,
    D_00250FA0,
    D_00250F80,
    D_00251060,
    D_00251100,
    D_002510C0,
    D_00250FC0,
    D_00250F40,
    D_00251060,
    D_00251040,
    D_00250FE0,
    D_00250FA0,
    D_00251040,
    D_00250FC0,
    D_00250F60,
    D_002510E0,
    D_002510C0,
    D_00250FE0,
    D_00251040,
    D_00251000,
    D_002510A0,
    D_00251080,
    D_00251000,
    D_00250FC0,
    D_00250F80,
    D_00250FE0,
    D_00250F80,
    D_00251080,
    D_00251020,
    D_00250FC0,
    D_00250FC0,
    D_00250FA0,
    D_00251080,
    D_00250FE0,
    D_002510E0,
    D_00251020,
    D_002510C0,
    D_00251060,
    D_00250FC0,
    D_00251020,
    D_002510E0,
    D_002510E0,
    D_00250F80,
    D_00250F40,
    D_00251040,
    D_00251060,
    D_00250FC0,
    D_00251000,
    D_00250FC0,
    D_00251020,
    D_002510E0,
    D_00250F40,
    D_00250F40,
    D_002510E0,
    D_002510C0,
    D_00251100,
    D_00251000,
    D_00251000,
    D_00251040,
    D_00251000,
    D_002510E0,
    D_00251000,
    D_00250F60,
    D_002510C0,
    D_00251060,
    D_00251040,
    D_00250F40,
    D_002510A0,
    D_00250F80,
    D_00251060,
    D_00251080,
    D_00250F80,
    D_00250FC0,
    D_002510A0,
    D_00251060,
    D_00251100,
    D_002510C0,
    D_00251100,
    D_00250FE0,
    D_00251080,
    D_00251020,
    D_00250F60,
    D_00250FE0,
    D_00251020,
    D_00251020,
    D_00251020,
    D_00251020,
    D_00250FA0,
    D_00251100,
    D_00251040,
    D_002510C0,
    D_002510A0,
    D_00251020,
    D_00251080,
    D_00251060,
    D_00250FC0,
    D_00251020,
    D_00250F60,
    D_00251020,
    D_00251040,
    D_002510E0,
    D_00250FA0,
    D_00251100,
    D_00250F60,
    D_00251040,
    D_002510C0,
    D_002510A0,
    D_00251000,
    D_00250FA0,
    D_00251060,
    D_00251100,
    D_00251100,
    D_00251020,
    D_00251000,
    D_002510C0,
    D_00251020,
    D_00251020,
    D_00251100,
    D_002510A0,
    D_00250FE0,
    D_00250FC0,
    D_00250FC0,
    D_00251100,
    D_00251060,
    D_00250FE0,
    D_00251040,
    D_00251100,
    D_00250F40,
    D_00251020,
    D_00251040,
    D_00251040,
    D_00251000,
    D_00251080,
    D_00251020,
    D_00250F80,
    D_00251020,
    D_00251020,
    D_00251060,
    D_00250FA0,
    D_002510E0,
    D_00250FA0,
    D_00250F80,
    D_00251000,
    D_002510E0,
    D_00250FE0,
    D_00251020,
    D_00251000,
    D_00251020,
    D_00250F40,
    D_00251020,
    D_00251060,
    D_002510C0,
    D_00250FE0,
    D_002510E0,
    D_002510C0,
    D_00250F40,
    D_00251040,
    D_00250F40,
    D_002510C0,
    D_00250FA0,
    D_00250FA0,
    D_00250FA0,
    D_00250F60,
    D_00251080,
    D_002510C0,
    D_00250F40,
    D_002510A0,
    D_00250F40,
    D_00250FC0,
    D_00250F60,
    D_00250F60,
    D_00251040,
    D_00250F80,
    D_00250FE0,
    D_00250F60,
    D_00250F80,
    D_00250FC0,
    D_00251100,
    D_00250F60,
    D_00250F80,
    D_00250FA0,
    D_002510E0,
    D_002510C0,
    D_00250F80,
    D_00251060,
    D_00251080,
    D_00251100,
    D_002510A0,
    D_00250FE0,
    D_00250F40,
    D_00251020,
    D_00251000,
    D_00251060,
    D_00251100,
    D_00250F60,
    D_00250FC0,
    D_00250F80,
};

s8 D_00251520[64] = {
    0xFE, 0x01, 0xFB, 0xFD, 0x03, 0xFC, 0x02, 0xFD, 0x02, 0xFA, 0x05, 0x03, 0xFF, 0x04, 0xFB, 0xFF,
    0x05, 0x02, 0xFD, 0xFF, 0x04, 0xFE, 0x00, 0xFE, 0x03, 0xFE, 0x04, 0xFB, 0x00, 0x01, 0xFF, 0x06,
    0xFD, 0x01, 0xFE, 0xFA, 0x04, 0xFE, 0x00, 0xFB, 0xFD, 0x04, 0x05, 0xFC, 0x00, 0xFF, 0x02, 0x06,
    0xFE, 0x01, 0x04, 0x05, 0x03, 0xFC, 0xFF, 0xFE, 0x02, 0xFF, 0x02, 0xFD, 0x02, 0x04, 0xFB, 0xFF,
};

s8 D_00251560[64] = {
    0xF8, 0x04, 0xEC, 0xF4, 0x0C, 0xF0, 0x08, 0xF4, 0x08, 0xE8, 0x14, 0x0C, 0xFC, 0x10, 0xEC, 0xFC,
    0x14, 0x08, 0xF4, 0xFC, 0x10, 0xF8, 0x00, 0xF8, 0x0C, 0xF8, 0x10, 0xEC, 0x00, 0x04, 0xFC, 0x18,
    0xF4, 0x04, 0xF8, 0xE8, 0x10, 0xF8, 0x00, 0xEC, 0xF4, 0x10, 0x14, 0xF0, 0x00, 0xFC, 0x08, 0x18,
    0xF8, 0x04, 0x10, 0x14, 0x0C, 0xF0, 0xFC, 0xF8, 0x08, 0xFC, 0x08, 0xF4, 0x08, 0x10, 0xEC, 0xFC,
};

void (*D_002515A0[8])() = {
    entity_draw_layer1,
    entity_draw_layer2,
    entity_draw_layer3,
    entity_draw_layer4,
    entity_draw_layer5,
    0,
    0,
    0,
};

u16 D_002515C0[8] = {
    0x0000, 0x1317, 0x0000, 0x1316, 0x0000, 0x1315, 0x0000, 0x1314,
};

u16 D_002515D0[8] = {
    0x0000, 0x131B, 0x0000, 0x131A, 0x0000, 0x1319, 0x0000, 0x1318,
};

u16 D_002515E0[8] = {
    0x0000, 0x131F, 0x0000, 0x131E, 0x0000, 0x131D, 0x0000, 0x131C,
};

u16 D_002515F0[8] = {
    0x0000, 0x130B, 0x0000, 0x130A, 0x0000, 0x1309, 0x0000, 0x1308,
};

u16 D_00251600[8] = {
    0x0000, 0x130F, 0x0000, 0x130E, 0x0000, 0x130D, 0x0000, 0x130C,
};

u16 D_00251610[8] = {
    0x0000, 0x130F, 0x0000, 0x130E, 0x0000, 0x130D, 0x0000, 0x130C,
};

u16 D_00251620[8] = {
    0x0000, 0x12FF, 0x0000, 0x12FE, 0x0000, 0x12FD, 0x0000, 0x12FC,
};

u16 D_00251630[8] = {
    0x0000, 0x1303, 0x0000, 0x1302, 0x0000, 0x1301, 0x0000, 0x1300,
};

u16 D_00251640[8] = {
    0x0000, 0x1307, 0x0000, 0x1306, 0x0000, 0x1305, 0x0000, 0x1304,
};

u16 D_00251650[8] = {
    0x0000, 0x12F3, 0x0000, 0x12F2, 0x0000, 0x12F1, 0x0000, 0x12F0,
};

u16 D_00251660[8] = {
    0x0000, 0x12F7, 0x0000, 0x12F6, 0x0000, 0x12F5, 0x0000, 0x12F4,
};

u16 D_00251670[8] = {
    0x0000, 0x12FB, 0x0000, 0x12FA, 0x0000, 0x12F9, 0x0000, 0x12F8,
};

u16 D_00251680[16] = {
    0x8000, 0xFE00, 0xFE00, 0x0210, 0x0001, 0x000C, 0xFC00, 0x0000,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x0000, 0x0000,
};

u16 D_002516A0[16] = {
    0x8004, 0xFA00, 0xFC00, 0x0620, 0x0001, 0x000C, 0xF400, 0x0000,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x0000, 0x0000,
};

u16 D_002516C0[16] = {
    0x8008, 0xF800, 0xFA00, 0x0830, 0x0002, 0x000C, 0xF000, 0x0000,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x0000, 0x0000,
};

u16 D_002516E0[16] = {
    0x800C, 0xF400, 0xF700, 0x0C48, 0x0002, 0x000C, 0xE800, 0x0000,
    0x0008, 0x0009, 0x000A, 0x000B, 0x000C, 0x000D, 0x0000, 0x0000,
};

void *D_00251700[8] = {
    D_00251680,
    D_002516A0,
    D_002516C0,
    D_002516E0,
    D_0028C0E8,
    D_0028C0EC,
    D_0028C0F0,
    D_0028C0F4,
};

/* .bss (the compiler lays these out in reverse) */
u8 D_00299D30[2048];

/* .sbss (the compiler lays these out in reverse) */
u8 *D_0028E570;
u8 *reg_save4_a0;
u8 *reg_save4_a1;
u8 *reg_save4_a2;
u8 *reg_save4_a3;
u8 *reg_save4_a4;
u8 *reg_save4_a5;
u8 *reg_save4_a6;
u32 reg_save4_d0;
u32 reg_save4_d1;
u32 reg_save4_d2;
u32 reg_save4_d3;
u32 reg_save4_d4;
u32 reg_save4_d5;
u32 reg_save4_d6;
u32 reg_save4_d7;
s32 D_0028E530;
