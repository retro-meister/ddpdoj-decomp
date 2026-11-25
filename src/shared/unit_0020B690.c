#include "common.h"
#include "entity.h"

void func_0020E020(void);
void func_0020E230(void);
void func_0020E290(void);
void func_0020E6F0(void);

extern u16 D_0028E08C;
extern u16 D_0028E090;

void func_0020B690(void) {
    D_0028E08C = 0;
    D_0028E090 = 0;
}

extern s16 D_0028E094_as_s16;


#ifdef DEATH_LABEL
extern u16 g_attract_demo;
s32 death_func_001271E0(void);
#endif

void func_0020B6A0(void) {
    u8 *temp_a2;

    cond_flag = 0;
#ifdef DEATH_LABEL
    if (death_func_001271E0() != 0) {
        return;
    }
#endif
    reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
    reg_a6 += 2;
#ifdef DEATH_LABEL
    if (g_attract_demo != 0) {
        return;
    }
#endif
    if (((s32) reg_d4.h[0] <= (s32) reg_d0.h[0]) && ((s32) reg_d1.h[0] <= (s32) reg_d4.h[0])) {
        reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
        if (((s32) reg_d3.h[0] <= (s32) reg_d4.h[0]) && ((s32) reg_d4.h[0] <= (s32) reg_d2.h[0])) {
            reg_d4.w = 0x51;
            reg_d4.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (-3)));
            temp_a2 = (u8 *)(reg_a6 - 3);
            if (reg_d4.b[0] == 0) {
                reg_d4.w = 0x10;
                *temp_a2 |= reg_d4.b[0];
                *(u8 *)(reg_a4 + 1) |= reg_d4.b[0];
                D_0028E094_as_s16 = 1;
                cond_flag = 1;
            }
        }
    }
}

extern u8 D_0028E0A0[];

void func_0020B770(void) {
    u8 *save_a1;

    save_a1 = reg_a1;
    reg_d0.w = 0;
    reg_a1 = (u8 *)D_0028E0A0;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = 0x7000;
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = 0x3800;
    reg_a1 += 2;
    reg_d5.h[0] = 0x23;
    reg_a6 = reg_a0;
loop_1:
    reg_tmp.h[0] = *(u16 *) reg_a6;
    reg_a6 += 2;
    if ((s16) reg_tmp.h[0] >= 0) goto next_9;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0);
    reg_d2.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d3.h[0] = reg_d2.h[0];
    reg_a1 = reg_a6 + 0xE;
    reg_d0.h[0] += *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] -= *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d2.h[0] += *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d3.h[0] -= *(u16 *) reg_a1;
    reg_a1 = (u8 *)D_0028E0A0;
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    if ((s16) reg_tmp.h[0] >= (s16) reg_d0.h[0]) goto next_5;
    *(u16 *) (reg_a1 - 2) = reg_d0.h[0];
next_5:
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    if ((s16) reg_tmp.h[0] <= (s16) reg_d1.h[0]) goto next_6;
    *(u16 *) (reg_a1 - 2) = reg_d1.h[0];
next_6:
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    if ((s16) reg_tmp.h[0] >= (s16) reg_d2.h[0]) goto next_7;
    *(u16 *) (reg_a1 - 2) = reg_d2.h[0];
next_7:
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    if ((s16) reg_tmp.h[0] <= (s16) reg_d3.h[0]) goto next_9;
    *(u16 *) (reg_a1 - 2) = reg_d3.h[0];
next_9:
    reg_a6 += 0x2E;
    if ((s16) --reg_d5.h[0] >= 0) goto loop_1;
    reg_a1 = (u8 *)D_0028E0A0;
    *(u16 *) reg_a1 += reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 += reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 += reg_d7.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 += reg_d7.h[0];
    reg_a1 = save_a1;
}

extern u8 D_0029CEA0_as_u8_a[];

void func_0020BA40(void) {
    reg_d0.h[0] = 0xF800;
    reg_a5 = (u8 *)D_0028E0A0;
    *(u16 *) reg_a5 = reg_d0.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 = 0x4000;
    reg_a5 += 2;
    *(u16 *) reg_a5 = reg_d0.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 = 0x7C00;
    reg_a5 += 2;
    reg_d5.h[0] = 0x2C;
    reg_a6 = (u8 *)D_0029CEA0_as_u8_a;
loop_1:
    reg_tmp.h[0] = *(u16 *) reg_a6;
    reg_a6 += 2;
    if ((s16) reg_tmp.h[0] >= 0) goto next_9;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0);
    reg_d2.h[0] = *(u16 *) (reg_a6 + 2);
    reg_d1.h[0] = reg_d0.h[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_a5 = reg_a6 + 0xE;
    reg_d0.h[0] += *(u16 *) reg_a5;
    reg_a5 += 2;
    reg_d1.h[0] -= *(u16 *) reg_a5;
    reg_a5 += 2;
    reg_d2.h[0] += *(u16 *) reg_a5;
    reg_a5 += 2;
    reg_d3.h[0] -= *(u16 *) reg_a5;
    reg_a5 = (u8 *)D_0028E0A0;
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] >= (s16) reg_d2.h[0]) goto next_5;
    *(u16 *) (reg_a5 - 2) = reg_d2.h[0];
next_5:
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] <= (s16) reg_d3.h[0]) goto next_6;
    *(u16 *) (reg_a5 - 2) = reg_d3.h[0];
next_6:
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] >= (s16) reg_d0.h[0]) goto next_7;
    *(u16 *) (reg_a5 - 2) = reg_d0.h[0];
next_7:
    reg_tmp.h[0] = *(u16 *) reg_a5;
    reg_a5 += 2;
    if ((s16) reg_tmp.h[0] <= (s16) reg_d1.h[0]) goto next_9;
    *(u16 *) (reg_a5 - 2) = reg_d1.h[0];
next_9:
    reg_a6 += 0x2E;
    if ((s16) --reg_d5.h[0] >= 0) goto loop_1;
    reg_a5 = (u8 *)D_0028E0A0;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
    *(u16 *) reg_a5 += reg_d6.h[0];
    reg_a5 += 2;
}

extern u16 D_0028E0A8;
extern u16 g_hyper_level_hit_scratch;
extern u16 g_hyper_hit_scratch;

void func_0020BD10(void)
{
    D_0028E0A8 = reg_d0.h[0];
    g_hyper_hit_scratch = reg_d1.h[0];
    reg_d7.h[0] = 0x2800;
    g_hyper_level_hit_scratch = reg_d2.h[0];

    if (*(s16 *)reg_a4 < 0) {
        func_0020E020();
    }
}

extern u32 g_laser_bomb_hit_entity_as_u32;
extern u16 g_laser_bomb_hit_position;
extern u16 D_0028E094;
extern u16 D_0028E0A0_as_u16_a[];
extern u8 g_game_mode;
extern u16 D_0028E7B0;
extern u16 D_0028E7E4;
extern u16 D_0028E7E8;
extern u16 g_two_player_game;
extern u16 g_bullet_count;
extern u8 D_002962E0[];
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u16 D_0029CEA0[];
extern u16 D_002BB4B2[];
extern u16 D_002BC7C0_as_u16_a[];
extern u16 D_002BD440[];
extern u16 D_002BF4F0_as_u16_a[];
#ifdef DEATH_LABEL
extern u16 g_attract_demo;
extern u16 g_stage;
extern u8 death_D_0029085C;
extern u8 death_D_00290DC0;
extern u16 D_00684C80[];
#endif

void func_0020BD60(void) {
    u8 *saved_a1;
    u32 tmp_dec;
    s32 tmp_dec2;
#ifdef DEATH_LABEL
    s32 gain;
    s32 base;
#endif

    D_0028E0A8 = reg_d0.h[0];
    g_hyper_hit_scratch = reg_d1.h[0];
    g_hyper_level_hit_scratch = reg_d2.h[0];
    reg_d7.h[0] = 0x2800;
    if ((s16) *(u16 *)reg_a4 < 0) {
        D_0028E094 = 0;
        func_0020E020();
        if (D_0028E094 == 0) {
            reg_d6.h[0] = D_0028E7B0;
            reg_d0.h[0] += reg_d7.h[0];
            reg_d1.h[0] += reg_d7.h[0];
            reg_d2.h[0] += reg_d7.h[0];
            reg_d3.h[0] += reg_d7.h[0];
            if (reg_d6.h[0] != 0) {
                reg_d6.h[0] -= 1;
                reg_a6 = (u8 *)D_002BB4B2;
                goto loop_5;
skip_5:
                reg_a6 += 0x3E;
loop_5:
                reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
                reg_a6 += 2;
                if (reg_d4.h[0] == 0) goto skip_5;
                reg_d4.h[0] += reg_d7.h[0];
                reg_d5.h[0] = reg_d4.h[0];
                reg_d5.h[0] -= ENTITY(reg_a6)->sprite.h;
                if ((s32) reg_d5.h[0] <= (s32) reg_d0.h[0]) {
                    reg_d4.h[0] += ENTITY(reg_a6)->sprite.h;
                    if ((s32) reg_d1.h[0] <= (s32) reg_d4.h[0]) {
                        reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
                        reg_d4.h[0] += reg_d7.h[0];
                        reg_d5.h[0] = reg_d4.h[0];
                        reg_d4.h[0] += ENTITY(reg_a6)->look.h;
                        if ((s32) reg_d3.h[0] <= (s32) reg_d4.h[0]) {
                            reg_d5.h[0] -= ENTITY(reg_a6)->look.h;
                            if ((s32) reg_d5.h[0] <= (s32) reg_d2.h[0]) {
                                reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (-4)));
                                reg_d4.h[0] &= 0xC0;
                                if (reg_d4.h[0] == 0) {
                                    reg_d4.h[0] = D_0028E0A8;
                                    (*(u16 *)((u8 *)(reg_a6) + (-4))) |= reg_d4.h[0];
                                }
                            }
                        }
                    }
                }
                reg_a6 += 0x3E;
                tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
                if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_5;
            }
            reg_d6.h[0] = g_bullet_count;
            if (reg_d6.h[0] != 0) {
                reg_a6 = (u8 *)D_002BF4F0_as_u16_a;
                goto loop_17;
skip_17:
                reg_a6 += 0x2A;
loop_17:
                    reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
                    reg_a6 += 2;
                    if ((s16) reg_tmp.h[0] >= 0) goto skip_17;
                    reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
                    reg_a6 += 2;
                    if (reg_d4.h[0] == 0) goto next_17;
                    reg_d4.h[0] += reg_d7.h[0];
                    reg_d5.h[0] = reg_d4.h[0];
                    reg_d5.h[0] -= ENTITY(reg_a6)->look.h;
                    if ((s32) reg_d5.h[0] > (s32) reg_d0.h[0]) goto next_17;
                    reg_d4.h[0] += ENTITY(reg_a6)->sprite.h;
                    if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_17;
                    reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
                    reg_d4.h[0] += reg_d7.h[0];
                    reg_d5.h[0] = reg_d4.h[0];
                    reg_d4.h[0] += ENTITY(reg_a6)->hit_y_plus.h;
                    if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_17;
                    reg_d5.h[0] -= ENTITY(reg_a6)->hit_y_minus.h;
                    if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto next_17;
                    if ((s8) *(u8 *)(reg_a6 - 4) < 0) goto next_17;
                    reg_d4.h[0] = D_0028E0A8;
                    *(u16 *)(reg_a6 - 4) |= reg_d4.h[0];
next_17:
                    reg_a6 += 0x28;
                    tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
                    if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_17;
            }
            reg_a6 = (u8 *)(D_002BC7C0_as_u16_a);
            reg_d6.h[0] = D_0028E7E8;
            reg_d6.h[0] += D_0028E7E4;
            if (reg_d6.h[0] != 0) {
                reg_d6.h[0] -= 1;
                goto loop_30;
skip_30:
                reg_a6 += 0x1E;
loop_30:
                reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
                reg_a6 += 2;
                if ((s16) reg_d4.h[0] >= 0) goto skip_30;
                reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
                reg_d4.h[0] += reg_d7.h[0];
                reg_d5.h[0] = reg_d4.h[0];
                reg_d5.h[0] -= ENTITY(reg_a6)->hit_y_plus.h;
                if ((s32) reg_d5.h[0] > (s32) reg_d0.h[0]) goto next_30;
                reg_d4.h[0] += ENTITY(reg_a6)->look.h;
                if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_30;
                reg_d4.h[0] = ENTITY(reg_a6)->y.h;
                reg_d4.h[0] += reg_d7.h[0];
                reg_d5.h[0] = reg_d4.h[0];
                reg_d4.h[0] += ENTITY(reg_a6)->hit_y_minus.h;
                if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_30;
                reg_d5.h[0] -= ENTITY(reg_a6)->hit_x_plus.h;
                if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto next_30;
                reg_d4.h[0] = (*(u16 *)((u8 *)(reg_a6) + (-2)));
                reg_d4.h[0] &= 1;
                if (reg_d4.h[0] == 0) goto next_30;
                reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
                reg_d4.h[0] += reg_d7.h[0];
                reg_d4.h[0] -= ENTITY(reg_a6)->hit_y_plus.h;
                if (!((s32) reg_d4.h[0] < 0xF800)) goto next_30;
#ifdef DEATH_LABEL
                if (g_attract_demo != 0) goto block_23;
#endif
                *(u8 *)(reg_a4 + 1) |= 0x10;
                reg_d4.h[0] = D_0028E0A8;
                (*(u16 *)((u8 *)(reg_a6) + (-2))) |= reg_d4.h[0];
                ENTITY(reg_a6)->hit_x_minus.h -= 1;
                goto block_23;
next_30:
                reg_a6 += 0x1E;
                tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
                if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_30;
            }
        }
    }
block_23:
    reg_a6 = (u8 *)(reg_a0);
    reg_d6.w = 0x23;
loop_40:
    if ((ENTITY(reg_a6)->flags.sh) < 0) goto found_40;
    reg_a6 += 0x30;
    tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
    if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
    goto exit_40;
found_40:
    {
        func_0020B770();
        saved_a1 = reg_a1;
        reg_a5 = (u8 *)(D_002BC7C0_as_u16_a);
        reg_d6.h[0] = D_0028E7E8;
        if (reg_d6.h[0] == 0) goto done_48;
        reg_d6.h[0] -= 1;
        goto loop_48;
next_48:
        reg_a5 += 0x1E;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_48;
        goto done_48;
skip_48:
        reg_a5 += 0x1E;
loop_48:
        reg_d0.h[0] = *(u16 *)reg_a5;
        reg_a5 += 2;
        if ((s16)(reg_d0.h[0]) >= 0) goto skip_48;
        reg_d0.h[0] &= 0x2000;
        if (reg_d0.h[0] == 0) goto next_48;
        reg_d0.h[0] = *(u16 *)reg_a5;
        reg_d2.h[0] = *(u16 *)(reg_a5 + 2);
        reg_d0.h[0] += reg_d7.h[0];
        reg_d1.h[0] = reg_d0.h[0];
        reg_a1 = (u8 *)(reg_a5 + 0xE);
        reg_d0.h[0] += *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_d1.h[0] -= *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_a6 = (u8 *)D_0028E0A0_as_u16_a;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] < (s32) reg_d1.h[0]) goto next_48;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] > (s32) reg_d0.h[0]) goto next_48;
        reg_d2.h[0] += reg_d7.h[0];
        reg_d3.h[0] = reg_d2.h[0];
        reg_d2.h[0] += *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_d3.h[0] -= *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] < (s32) reg_d3.h[0]) goto next_48;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] > (s32) reg_d2.h[0]) goto next_48;
        if (!((s32) reg_d1.h[0] < 0x9700)) goto next_48;
        reg_tmp6.h[0] = reg_d6.h[0];
        reg_d6.h[0] = reg_d6.h[1];
        reg_d6.h[1] = reg_tmp6.h[0];
        reg_a6 = (u8 *)(reg_a0);
        reg_d6.h[0] = 0x23;
        goto loop_59;
skip_59:
        reg_a6 += 0x2E;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_59;
        goto end_59;
next_59:
        reg_a6 += 0x2C;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) < 0) goto end_59;
loop_59:
        reg_d5.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s16) reg_d5.h[0] >= 0) goto skip_59;
        reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        reg_d4.h[0] += reg_d7.h[0];
        reg_d4.h[0] += ENTITY(reg_a6)->sprite.h;
        if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_59;
        reg_d4.h[0] -= ENTITY(reg_a6)->look.h;
        if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) goto next_59;
        reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
        reg_d4.h[0] += reg_d7.h[0];
        reg_d4.h[0] += ENTITY(reg_a6)->hit_y_plus.h;
        if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_59;
        reg_d4.h[0] -= ENTITY(reg_a6)->hit_y_minus.h;
        reg_d4.h[0] -= ENTITY(reg_a6)->hit_y_minus.h;
        if ((s32) reg_d4.h[0] > (s32) reg_d2.h[0]) goto next_59;
        if (ENTITY(reg_a6)->hit_x_plus.sh < 0) goto cont_59;
        reg_d4.h[0] = *(u16 *)(reg_a5 + 0x16);
        reg_tmp4.h[0] = reg_d4.h[0];
        reg_d4.h[0] = D_0028E0A8;
        reg_d4.h[1] = reg_tmp4.h[0];
        (*(u16 *)((u8 *)(reg_a5) + (-2))) |= reg_d4.h[0];
        reg_d5.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
        if (g_two_player_game == 0) {
            reg_d4.h[0] = reg_d5.h[0];
            reg_d4.h[0] >>= 2;
            reg_d5.h[0] -= reg_d4.h[0];
        }
        (*(u8 *)((u8 *)(reg_a6) + (-4))) |= 0x80;
        reg_d4.h[0] = *(u16 *)(reg_a5 + 0x16);
        ENTITY(reg_a6)->hit_x_plus.h -= reg_d4.h[0];
        reg_tmp4.h[0] = reg_d4.h[0];
        reg_d4.h[0] = reg_d4.h[1];
        reg_d4.h[1] = reg_tmp4.h[0];
        *(u16 *)(reg_a5 + 0x16) = (u16) reg_d4.h[0];
        if ((s32) *(u16 *)reg_a5 > 0x6EFF) goto cont_59;
        *(u16 *)(reg_a5 + 0x16) -= reg_d5.h[0];
        if (*(s16 *)(reg_a5 + 0x16) < 0) goto end_59;
cont_59:
        reg_a6 += 0x2C;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_59;
end_59:
        reg_tmp6.h[0] = reg_d6.h[0];
        reg_d6.h[0] = reg_d6.h[1];
        reg_d6.h[1] = reg_tmp6.h[0];
        reg_a5 += 0x1E;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_48;
done_48:
        reg_a5 = (u8 *)(D_002BD440);
        reg_d6.h[0] = D_0028E7E4;
        if (reg_d6.h[0] == 0) goto done_76;
        reg_d6.h[0] -= 1;
        reg_d7.h[0] = 0xF000;
        reg_a1 = (u8 *)(D_0028E0A0_as_u16_a);
        *(u16 *)reg_a1 += reg_d7.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 += reg_d7.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 += reg_d7.h[0];
        reg_a1 += 2;
        *(u16 *)reg_a1 += reg_d7.h[0];
        reg_d7.h[0] = 0x1800;
        reg_a1 += 2;
        goto loop_76;
next_76:
        reg_a5 += 0x1E;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_76;
        goto done_76;
skip_76:
        reg_a5 += 0x1E;
loop_76:
        reg_d0.h[0] = *(u16 *)reg_a5;
        reg_a5 += 2;
        if ((s16)(reg_d0.h[0]) >= 0) goto skip_76;
        reg_d0.h[0] &= 0x2000;
        if (reg_d0.h[0] == 0) goto next_76;
        reg_d0.h[0] = *(u16 *)reg_a5;
        reg_d2.h[0] = *(u16 *)(reg_a5 + 2);
        reg_d0.h[0] += reg_d7.h[0];
        reg_d1.h[0] = reg_d0.h[0];
        reg_a1 = (u8 *)(reg_a5 + 0xE);
        reg_d0.h[0] += *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_d1.h[0] -= *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_a6 = (u8 *)D_0028E0A0_as_u16_a;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] < (s32) reg_d1.h[0]) goto next_76;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] > (s32) reg_d0.h[0]) goto next_76;
        reg_d2.h[0] += reg_d7.h[0];
        reg_d3.h[0] = reg_d2.h[0];
        reg_d2.h[0] += *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_d3.h[0] -= *(u16 *)reg_a1;
        reg_a1 += 2;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] < (s32) reg_d3.h[0]) goto next_76;
        reg_tmp.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s32) reg_tmp.h[0] > (s32) reg_d2.h[0]) goto next_76;
        if (!((s32) reg_d1.h[0] < 0x8800)) goto next_76;
        reg_tmp6.h[0] = reg_d6.h[0];
        reg_d6.h[0] = reg_d6.h[1];
        reg_d6.h[1] = reg_tmp6.h[0];
        reg_a6 = (u8 *)(reg_a0);
        reg_d6.h[0] = 0x23;
        goto loop_85;
skip_85:
        reg_a6 += 0x2E;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) < 0) goto end_85;
loop_85:
        reg_d5.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        if ((s16) reg_d5.h[0] >= 0) goto skip_85;
        reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a6 += 2;
        reg_d4.h[0] += reg_d7.h[0];
        reg_d4.h[0] += ENTITY(reg_a6)->sprite.h;
        if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_85;
        reg_d4.h[0] -= ENTITY(reg_a6)->look.h;
        if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) goto next_85;
        reg_d4.h[0] = ENTITY(reg_a6)->flags.h;
        reg_d4.h[0] += reg_d7.h[0];
        reg_d4.h[0] += ENTITY(reg_a6)->hit_y_plus.h;
        if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_85;
        reg_d4.h[0] -= ENTITY(reg_a6)->hit_y_minus.h;
        reg_d4.h[0] -= ENTITY(reg_a6)->hit_y_minus.h;
        if ((s32) reg_d4.h[0] > (s32) reg_d2.h[0]) goto next_85;
        reg_d4.w = 0x30;
        reg_d4.b[0] &= (*(u8 *)((u8 *)(reg_a6) + (-3)));
        if (reg_d4.b[0] != 0) goto next_85;
        if (ENTITY(reg_a6)->hit_x_plus.sh < 0) goto next_85;
        reg_d4.h[0] = D_0028E0A8;
        (*(u16 *)((u8 *)(reg_a5) + (-2))) |= reg_d4.h[0];
        (*(u8 *)((u8 *)(reg_a6) + (-4))) |= 0x80;
        reg_d5.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
        reg_d4.h[0] = *(u16 *)(reg_a5 + 0x16);
        ENTITY(reg_a6)->hit_x_plus.h -= reg_d4.h[0];
        if (g_two_player_game == 0) {
            reg_d4.h[0] = reg_d5.h[0];
            reg_d4.h[0] >>= 2;
            reg_d5.h[0] -= reg_d4.h[0];
        }
        *(u16 *)(reg_a5 + 0x16) -= reg_d5.h[0];
        if (*(s16 *)(reg_a5 + 0x16) < 0) goto end_85;
next_85:
        reg_a6 += 0x2C;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_85;
end_85:
        reg_tmp6.h[0] = reg_d6.h[0];
        reg_d6.h[0] = reg_d6.h[1];
        reg_d6.h[1] = reg_tmp6.h[0];
        reg_a5 += 0x1E;
        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_76;
done_76:
        reg_a1 = saved_a1;
    }
exit_40:

    reg_d6.h[0] = 0x2800;
    reg_d0.h[0] = *(u16 *)reg_a4;
    if ((s16) reg_d0.h[0] < 0) {
        if ((s8) reg_d0.b[0] < 0) goto block_120;
        if (*(u8 *)(reg_a4 + 0x3E) == 0) goto block_120;
        if (*(s16 *)reg_a2 >= 0) goto check_110;
        *(u8 *)(reg_a2 + 1) &= 0xEF;
        if (!((s32) *(u16 *)(reg_a2 + 2) < 0x7000)) goto check_110;
        reg_a0 = reg_a2 + 0x10;
        reg_d0.h[0] = *(u16 *)(reg_a2 + 2);
        reg_d0.h[0] += reg_d6.h[0];
        reg_d1.h[0] = reg_d0.h[0];
        reg_d0.h[0] += *(u16 *)reg_a0; reg_a0 += 2;
        reg_d1.h[0] -= *(u16 *)reg_a0; reg_a0 += 2;
        reg_d2.h[0] = *(u16 *)(reg_a2 + 4);
        reg_d2.h[0] += reg_d6.h[0];
        reg_d3.h[0] = reg_d2.h[0];
        reg_d2.h[0] += *(u16 *)reg_a0; reg_a0 += 2;
        reg_d3.h[0] -= *(u16 *)reg_a0; reg_a0 += 2;
        reg_a5 = (u8 *) D_002BC7C0_as_u16_a;
        reg_d7.h[0] = 0x95;
loop_100:
        reg_d4.h[0] = *(u16 *)reg_a5;
        if ((s16) reg_d4.h[0] >= 0) goto next_100;
        reg_d4.h[0] = *(u16 *)(reg_a5 + 2);
        reg_d4.h[0] += reg_d6.h[0];
        reg_d5.h[0] = reg_d4.h[0];
        reg_d4.h[0] += *(u16 *)(reg_a5 + 0x10);
        if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_100;
        reg_d5.h[0] -= *(u16 *)(reg_a5 + 0x12);
        if ((s32) reg_d5.h[0] > (s32) reg_d0.h[0]) goto next_100;
        if (!((s32) reg_d5.h[0] < 0x9800)) goto next_100;
        reg_d4.h[0] = *(u16 *)(reg_a5 + 4);
        reg_d4.h[0] += reg_d6.h[0];
        reg_d5.h[0] = reg_d4.h[0];
        reg_d4.h[0] += *(u16 *)(reg_a5 + 0x14);
        if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_100;
        reg_d5.h[0] -= *(u16 *)(reg_a5 + 0x16);
        if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto next_100;
        reg_d4.b[0] = *(u8 *)(reg_a5 + 1);
        if (reg_d4.h[0] & 0x20) goto hit_100;
        if (!(reg_d4.h[0] & 1)) goto next_100;
hit_100:
        if (*(s16 *)(reg_a5 + 0x18) < 0) goto next_100;
        reg_d5.h[0] = *(u16 *)(reg_a2 + 0x18);
        if (g_two_player_game == 0) {
            reg_d4.h[0] = reg_d5.h[0];
            reg_d4.h[0] >>= 1;
            reg_d5.h[0] -= reg_d4.h[0];
        }
        reg_d4.h[0] = D_0028E0A8;
        reg_d4.h[0] |= 0x400;
        *(u16 *)reg_a5 |= reg_d4.h[0];
        if ((s32) *(u16 *)(reg_a5 + 2) < 0x6F00) {
            *(u16 *)(reg_a5 + 0x18) -= reg_d5.h[0];
        }
next_100:
        reg_a5 += 0x20;
        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_100;
check_110:
        if (*(s16 *)reg_a3 >= 0) {
            func_0020E230();
            return;
        }
        reg_a0 = reg_a3 + 0x10;
        reg_d0.h[0] = *(u16 *)(reg_a3 + 2);
        reg_d0.h[0] += reg_d6.h[0];
        reg_d1.h[0] = reg_d0.h[0];
        reg_d0.h[0] += *(u16 *)reg_a0; reg_a0 += 2;
        reg_d1.h[0] -= *(u16 *)reg_a0; reg_a0 += 2;
        reg_d2.h[0] = *(u16 *)(reg_a3 + 4);
        reg_d2.h[0] += reg_d6.h[0];
        reg_d3.h[0] = reg_d2.h[0];
        reg_d2.h[0] += *(u16 *)reg_a0; reg_a0 += 2;
        reg_d3.h[0] -= *(u16 *)reg_a0; reg_a0 += 2;
        reg_a5 = (u8 *) D_002BC7C0_as_u16_a;
        reg_d7.h[0] = 0x95;
loop_110:
        reg_d4.b[0] = *(u8 *)(reg_a5 + 1);
        if ((s8) reg_d4.b[0] >= 0) goto next_110;
        reg_d4.h[0] = *(u16 *)(reg_a5 + 2);
        reg_d4.h[0] += reg_d6.h[0];
        reg_d5.h[0] = reg_d4.h[0];
        reg_d5.h[0] -= *(u16 *)(reg_a5 + 0x12);
        if ((s32) reg_d5.h[0] > (s32) reg_d0.h[0]) goto next_110;
        reg_d4.h[0] += *(u16 *)(reg_a5 + 0x10);
        if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_110;
        if (!((s32) reg_d5.h[0] < 0x9700)) goto next_110;
        reg_d4.h[0] = *(u16 *)(reg_a5 + 4);
        reg_d4.h[0] += reg_d6.h[0];
        reg_d5.h[0] = reg_d4.h[0];
        reg_d4.h[0] += *(u16 *)(reg_a5 + 0x14);
        if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_110;
        reg_d5.h[0] -= *(u16 *)(reg_a5 + 0x16);
        if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto next_110;
        if (!(*(u8 *)(reg_a5 + 1) & 0x20)) goto next_110;
        if (*(s16 *)(reg_a5 + 0x18) < 0) goto next_110;
        reg_d5.h[0] = *(u16 *)(reg_a3 + 0x18);
        if (g_hyper_hit_scratch != 0) {
            reg_d5.h[0] += reg_d5.h[0];
        }
        if (g_two_player_game == 0) {
            reg_d4.h[0] = reg_d5.h[0];
            reg_d4.h[0] >>= 1;
            reg_d5.h[0] -= reg_d4.h[0];
        }
        reg_d4.h[0] = D_0028E0A8;
        reg_d4.h[0] |= 0x4400;
        *(u16 *)reg_a5 |= reg_d4.h[0];
        if ((s32) *(u16 *)(reg_a5 + 2) < 0x6F00) {
            *(u16 *)(reg_a5 + 0x18) -= reg_d5.h[0];
        }
next_110:
        reg_a5 += 0x20;
        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_110;
        func_0020E230();
block_120:
        reg_a6 = (u8 *)(D_0029CEA0);
        reg_a0 = (u8 *)(reg_a6);
        reg_d5.h[0] = ENTITY(reg_a6)->flags.h;
        if (((s16)(reg_d5.h[0]) < 0) && (*(u8 *)reg_a4 & 0x40)) {
            reg_d0.w = 0;
            g_laser_bomb_hit_position = 0x7800;
            g_laser_bomb_hit_entity_as_u32 = reg_d0.w;
            if (!(reg_d5.h[0] & 0xFFFF & 1)) {
                reg_a5 = (u8 *) D_002BC7C0_as_u16_a;
                reg_d6.h[0] = D_0028E0A8;
                reg_d7.h[0] = 0x95;
                reg_d5.w = 0x50;
                if (ENTITY(reg_a6)->misc.h == 0) {
                    reg_d5.w = 1;
                }
loop_130:
                reg_d0.h[0] = *(u16 *)reg_a5;
                if ((s16) reg_d0.h[0] >= 0) goto next_130;
                if (*(s16 *)(reg_a5 + 0x18) < 0) goto next_130;
                if (!(reg_d0.h[0] & 0xFFFF & 0x2000)) goto next_130;
                reg_a1 = reg_a5 + 0x10;
                reg_d0.h[0] = *(u16 *)(reg_a5 + 2);
                reg_d1.h[0] = reg_d0.h[0];
                reg_d0.h[0] += *(u16 *)reg_a1; reg_a1 += 2;
                reg_tmp1.w = 0x2800;
                reg_tmp.w = 0;
                reg_tmp.h[0] = reg_d0.h[0];
                reg_d0.h[0] += 0x2800;
                reg_tmp1.w += reg_tmp.w;
                if (reg_tmp1.h[1] != 0) goto next_130;
                reg_d1.h[0] -= *(u16 *)reg_a1; reg_a1 += 2;
                reg_d1.h[0] += 0x2800;
                if (!((s32) reg_d1.h[0] < 0x9801)) goto next_130;
                reg_d2.h[0] = *(u16 *)(reg_a5 + 4);
                reg_d3.h[0] = reg_d2.h[0];
                reg_d2.h[0] += *(u16 *)reg_a1; reg_a1 += 2;
                if ((s16) reg_d2.h[0] < 0) goto next_130;
                reg_d3.h[0] -= *(u16 *)reg_a1; reg_a1 += 2;
                reg_d3.h[0] += 0x2800;
                if (!((s32) reg_d3.h[0] < 0x6001)) goto next_130;
                if (g_game_mode == 2) {
#ifdef DEATH_LABEL
                    base = reg_d5.h[0];
                    gain = base;
                    if (death_D_00290DC0 == 0) {
                        if (D_00684C80[9] == 2) {
                            gain = 0;
                        }
                        if (D_00684C80[9] == 4) {
                            if ((g_stage == 0) || (g_stage == 1) || (g_stage == 2) || (g_stage == 3)) {
                                gain /= 5;
                            } else {
                                gain /= 10;
                            }
                            if ((g_stage == 4) && (death_D_0029085C == 2)) {
                                gain = 0;
                            }
                        }
                        if (D_00684C80[9] == 6) {
                            gain /= 10;
                            if ((g_stage == 0) || (g_stage == 1) || (g_stage == 2)) {
                                gain = 0;
                            }
                            if ((g_stage == 4) && (death_D_0029085C == 2)) {
                                gain = 0;
                            }
                        }
                    } else {
                        if (D_00684C80[9] == 2) {
                            gain *= 2;
                            if (g_stage == 4) {
                                gain = 0;
                            }
                        }
                        if (D_00684C80[9] == 4) {
                            gain *= 2;
                            if (g_stage == 4) {
                                gain = 0;
                            }
                        }
                        if (D_00684C80[9] == 6) {
                            gain *= 2;
                            if (g_stage == 4) {
                                gain = 0;
                            }
                        }
                    }
                    if (gain != 0) {
                        *(u16 *)(reg_a5 + 0x18) += gain;
                    } else {
                        *(u16 *)(reg_a5 + 0x18) -= reg_d5.h[0];
                    }
#else
                    *(u16 *)(reg_a5 + 0x18) += (u16) ((s32) reg_d5.h[0] >> 2);
#endif
                } else {
                    *(u16 *)(reg_a5 + 0x18) -= reg_d5.h[0];
                }
                *(u16 *)reg_a5 |= reg_d6.h[0];
next_130:
                reg_a5 += 0x20;
                tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_130;
                return;
            }
            func_0020BA40();
            reg_a5 = (u8 *) D_002BD440;
            reg_d7.w = 0x31;
            goto loop_140;
skip_140:
            reg_a5 += 0x20;
            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) < 0) goto done_140;
loop_140:
            reg_d0.h[0] = *(u16 *)reg_a5;
            if ((s16) reg_d0.h[0] >= 0) goto skip_140;
            if (*(s16 *)(reg_a5 + 0x18) < 0) goto skip_140;
            if (reg_d0.h[0] & 0xFFFF & 0x2000) goto hit_140;
            if (!(reg_d0.h[0] & 0xFFFF & 1)) goto skip_140;
hit_140:
            reg_d0.h[0] = *(u16 *)(reg_a5 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 4);
            reg_d0.h[0] += reg_d6.h[0];
            reg_d1.h[0] = reg_d0.h[0];
            reg_d2.h[0] += reg_d6.h[0];
            reg_d3.h[0] = reg_d2.h[0];
            reg_a2 = reg_a5 + 0x10;
            reg_d0.h[0] += *(u16 *)reg_a2; reg_a2 += 2;
            reg_d1.h[0] -= *(u16 *)reg_a2; reg_a2 += 2;
            reg_d2.h[0] += *(u16 *)reg_a2; reg_a2 += 2;
            reg_d3.h[0] -= *(u16 *)reg_a2; reg_a2 += 2;
            reg_a6 = (u8 *) D_0028E0A0_as_u16_a;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] < (s32) reg_d3.h[0]) goto skip_140;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] > (s32) reg_d2.h[0]) goto skip_140;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] < (s32) reg_d1.h[0]) goto skip_140;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] > (s32) reg_d0.h[0]) goto skip_140;
            if (!((s32) reg_d1.h[0] < 0x9800)) goto skip_140;
            reg_tmp7.h[0] = reg_d7.h[0];
            reg_d7.h[0] = reg_d7.h[1];
            reg_d7.h[1] = reg_tmp7.h[0];
            reg_a6 = reg_a0;
            reg_a6 += 0x30;
            reg_d7.h[0] = 0x28;
loop_145:
            reg_d4.b[0] = ENTITY(reg_a6)->flags.b[1];
            if ((s8) reg_d4.b[0] >= 0) goto next_145;
            if (reg_d4.h[0] & 2) goto next_145;
            reg_d4.h[0] = ENTITY(reg_a6)->y.h;
            reg_d4.h[0] += reg_d6.h[0];
            reg_d5.h[0] = reg_d4.h[0];
            reg_d4.h[0] += ENTITY(reg_a6)->hit_y_plus.h;
            if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_145;
            reg_d5.h[0] -= ENTITY(reg_a6)->hit_y_minus.h;
            if ((s32) reg_d5.h[0] > (s32) reg_d0.h[0]) goto next_145;
            reg_d4.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.h[0] += reg_d6.h[0];
            reg_d5.h[0] = reg_d4.h[0];
            reg_d4.h[0] += ENTITY(reg_a6)->hit_x_plus.h;
            if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_145;
            reg_d5.h[0] -= ENTITY(reg_a6)->hit_x_minus.h;
            if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto next_145;
            reg_d4.h[0] = reg_d1.h[0];
            reg_d4.h[0] -= reg_d6.h[0];
            if (!((s32) reg_d4.h[0] < (s32) g_laser_bomb_hit_position)) goto next_145;
            reg_d5.h[0] = *(u16 *)(reg_a4 + 2);
            reg_d5.h[0] += 0xC00;
            if ((s32) reg_d5.h[0] < (s32) reg_d4.h[0]) goto store_145;
            reg_d4.h[0] = reg_d5.h[0];
store_145:
            g_laser_bomb_hit_entity_as_u32 = (u32) reg_a5;
            g_laser_bomb_hit_position = reg_d4.h[0];
next_145:
            reg_a6 += 0x30;
            tmp_dec2 = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec2;
            if (((s64) ((s64) (u16) tmp_dec2 << 0x30) >> 0x30) >= 0) goto loop_145;
            reg_tmp7.h[0] = reg_d7.h[0];
            reg_d7.h[0] = reg_d7.h[1];
            reg_d7.h[1] = reg_tmp7.h[0];
            reg_a5 += 0x20;
            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_140;
done_140:
            if (g_laser_bomb_hit_entity_as_u32 != 0) {
                reg_a5 = (u8 *) g_laser_bomb_hit_entity_as_u32;
                reg_d4.h[0] = D_0028E0A8;
                reg_d4.h[0] |= 0x400;
                *(u16 *)reg_a5 |= reg_d4.h[0];
                if (g_game_mode == 2) {
#ifdef DEATH_LABEL
                    gain = 0x208;
                    if (death_D_00290DC0 == 0) {
                        if (D_00684C80[9] == 2) {
                            gain = 0;
                        }
                        if (D_00684C80[9] == 4) {
                            if ((g_stage == 0) || (g_stage == 1) || (g_stage == 2) || (g_stage == 3)) {
                                gain /= 5;
                            } else {
                                gain /= 10;
                            }
                            if ((g_stage == 4) && (death_D_0029085C == 2)) {
                                gain = 0;
                            }
                        }
                        if (D_00684C80[9] == 6) {
                            gain /= 10;
                            if ((g_stage == 0) || (g_stage == 1) || (g_stage == 2)) {
                                gain = 0;
                            }
                            if ((g_stage == 4) && (death_D_0029085C == 2)) {
                                gain = 0;
                            }
                        }
                    } else {
                        if (D_00684C80[9] == 2) {
                            gain *= 2;
                            if (g_stage == 4) {
                                gain = 0;
                            }
                        }
                        if (D_00684C80[9] == 4) {
                            gain *= 2;
                            if (g_stage == 4) {
                                gain = 0;
                            }
                        }
                        if (D_00684C80[9] == 6) {
                            gain *= 2;
                            if (g_stage == 4) {
                                gain = 0;
                            }
                        }
                    }
                    if (gain != 0) {
                        *(u16 *)(reg_a5 + 0x18) += gain;
                    } else {
                        *(u16 *)(reg_a5 + 0x18) -= 0x208;
                    }
#else
                    *(u16 *)(reg_a5 + 0x18) += 0x82;
#endif
                } else {
                    *(u16 *)(reg_a5 + 0x18) -= 0x208;
                }
            }
            reg_a1 = reg_a0;
            reg_a5 = (u8 *)(D_002BC7C0_as_u16_a);
            reg_d7.h[0] = 0x63;
            goto loop_150;
skip_150:
            reg_a5 += 0x20;
            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) < 0) goto start_160;
loop_150:
            reg_d1.h[0] = *(u16 *)reg_a5;
            if ((s16) reg_d1.h[0] >= 0) goto skip_150;
            if (reg_d1.h[0] & 0xFFFF & 0x2000) goto alive_150;
            if (reg_d1.h[0] & 0xFFFF & 1) goto hit_150;
            goto skip_150;
alive_150:
            if (*(s16 *)(reg_a5 + 0x18) < 0) goto skip_150;
hit_150:
            reg_d0.h[0] = *(u16 *)(reg_a5 + 2);
            reg_d2.h[0] = *(u16 *)(reg_a5 + 4);
            reg_d0.h[0] += reg_d6.h[0];
            reg_d1.h[0] = reg_d0.h[0];
            reg_d2.h[0] += reg_d6.h[0];
            reg_d3.h[0] = reg_d2.h[0];
            reg_a2 = reg_a5 + 0x10;
            reg_d0.h[0] += *(u16 *)reg_a2; reg_a2 += 2;
            reg_d1.h[0] -= *(u16 *)reg_a2; reg_a2 += 2;
            reg_d2.h[0] += *(u16 *)reg_a2; reg_a2 += 2;
            reg_d3.h[0] -= *(u16 *)reg_a2; reg_a2 += 2;
            reg_a6 = (u8 *) D_0028E0A0_as_u16_a;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] < (s32) reg_d3.h[0]) goto skip_150;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] > (s32) reg_d2.h[0]) goto skip_150;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] < (s32) reg_d1.h[0]) goto skip_150;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] > (s32) reg_d0.h[0]) goto skip_150;
            reg_d4.h[0] = *(u16 *)(reg_a5 + 2);
            if (!((s32) reg_d4.h[0] < 0x7000)) goto skip_150;
            if (g_laser_bomb_hit_entity_as_u32 == 0) goto scan_150;
            if (!((s32) reg_d4.h[0] < (s32) g_laser_bomb_hit_position)) goto skip_150;
scan_150:
            reg_tmp7.h[0] = reg_d7.h[0];
            reg_d7.h[0] = reg_d7.h[1];
            reg_d7.h[1] = reg_tmp7.h[0];
            reg_a6 = reg_a0;
            reg_d7.h[0] = 0x2C;
loop_155:
            reg_d4.b[0] = ENTITY(reg_a6)->flags.b[1];
            if ((s8) reg_d4.b[0] >= 0) goto next_155;
            if (reg_d4.h[0] & 2) goto next_155;
            reg_d4.h[0] = ENTITY(reg_a6)->y.h;
            reg_d4.h[0] += reg_d6.h[0];
            reg_d5.h[0] = reg_d4.h[0];
            reg_d4.h[0] += ENTITY(reg_a6)->hit_y_plus.h;
            if ((s32) reg_d1.h[0] > (s32) reg_d4.h[0]) goto next_155;
            reg_d5.h[0] -= ENTITY(reg_a6)->hit_y_minus.h;
            if ((s32) reg_d5.h[0] > (s32) reg_d0.h[0]) goto next_155;
            reg_d4.h[0] = ENTITY(reg_a6)->x.h;
            reg_d4.h[0] += reg_d6.h[0];
            reg_d5.h[0] = reg_d4.h[0];
            reg_d4.h[0] += ENTITY(reg_a6)->hit_x_plus.h;
            if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto next_155;
            reg_d5.h[0] -= ENTITY(reg_a6)->hit_x_minus.h;
            if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto next_155;
            ENTITY(reg_a6)->flags.b[1] |= 0x10;
            reg_d4.h[0] = D_0028E0A8;
            reg_d4.h[0] |= 0x400;
            *(u16 *)reg_a5 |= reg_d4.h[0];
            *(u16 *)(reg_a5 + 0x18) -= 0x1E0;
            if (*(s16 *)(reg_a5 + 0x18) < 0) goto end_155;
next_155:
            reg_a6 += 0x30;
            tmp_dec2 = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec2;
            if (((s64) ((s64) (u16) tmp_dec2 << 0x30) >> 0x30) >= 0) goto loop_155;
end_155:
            reg_tmp7.h[0] = reg_d7.h[0];
            reg_d7.h[0] = reg_d7.h[1];
            reg_d7.h[1] = reg_tmp7.h[0];
            reg_a5 += 0x20;
            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_150;
start_160:
            reg_a5 = (u8 *)(D_002962E0 + 2);
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
            if (D_00299768_as_u16_a[0] == 0) goto loop_160;
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
            if (D_0029976A_as_u16_a[0] == 0) goto loop_160;
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
            if (D_0029976C[0] == 0) goto loop_160;
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
            if (D_0029976E[0] == 0) goto loop_160;
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
loop_160:
            reg_d0.h[0] = *(u16 *)reg_a5;
            if ((s16) reg_d0.h[0] < 0) goto next_160;
            if (g_laser_bomb_hit_entity_as_u32 == 0) goto hit_160;
            if ((s32) g_laser_bomb_hit_position <= (s32) (reg_d0.h[0] & 0xFFFF)) goto next_160;
hit_160:
            reg_d0.h[0] += reg_d6.h[0];
            reg_d2.h[0] = *(u16 *)(reg_a5 + 2);
            reg_d2.h[0] += reg_d6.h[0];
            reg_a6 = (u8 *) D_0028E0A0_as_u16_a;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] < (s32) reg_d2.h[0]) goto next_160;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] > (s32) reg_d2.h[0]) goto next_160;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] < (s32) reg_d0.h[0]) goto next_160;
            reg_tmp.h[0] = ENTITY(reg_a6)->flags.h; reg_a6 += 2;
            if ((s32) reg_tmp.h[0] > (s32) reg_d0.h[0]) goto next_160;
            reg_tmp7.h[0] = reg_d7.h[0];
            reg_d7.h[0] = reg_d7.h[1];
            reg_d7.h[1] = reg_tmp7.h[0];
            reg_a0 = reg_a1;
            reg_d7.h[0] = 0x2C;
loop_165:
            reg_d4.b[0] = *(u8 *)(reg_a0 + 1);
            if ((s8) reg_d4.b[0] >= 0) goto next_165;
            if (reg_d4.h[0] & 2) goto next_165;
            reg_d4.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d4.h[0] += reg_d6.h[0];
            reg_d5.h[0] = reg_d4.h[0];
            reg_d4.h[0] += *(u16 *)(reg_a0 + 0x10);
            if ((s32) reg_d0.h[0] > (s32) reg_d4.h[0]) goto next_165;
            reg_d5.h[0] -= *(u16 *)(reg_a0 + 0x12);
            if ((s32) reg_d5.h[0] > (s32) reg_d0.h[0]) goto next_165;
            reg_d4.h[0] = *(u16 *)(reg_a0 + 4);
            reg_d4.h[0] += reg_d6.h[0];
            reg_d5.h[0] = reg_d4.h[0];
            reg_d4.h[0] += *(u16 *)(reg_a0 + 0x14);
            if ((s32) reg_d2.h[0] > (s32) reg_d4.h[0]) goto next_165;
            reg_d5.h[0] -= *(u16 *)(reg_a0 + 0x16);
            if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto next_165;
            *(u16 *)(reg_a5 - 2) = 0;
            *(u16 *)reg_a5 = 0xFFFF;
            goto end_165;
next_165:
            reg_a0 += 0x30;
            tmp_dec2 = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec2;
            if (((s64) ((s64) (u16) tmp_dec2 << 0x30) >> 0x30) >= 0) goto loop_165;
end_165:
            reg_tmp7.h[0] = reg_d7.h[0];
            reg_d7.h[0] = reg_d7.h[1];
            reg_d7.h[1] = reg_tmp7.h[0];
next_160:
            reg_a5 += 0x40;
            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_160;
        }
    }
}


void func_0020E020(void) {
    reg_d0.h[0] = *(u16 *) (reg_a4 + 2);
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] += *(u16 *) (reg_a4 + 0x10);
    reg_d1.h[0] -= *(u16 *) (reg_a4 + 0x12);
    reg_d2.h[0] = *(u16 *) (reg_a4 + 4);
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.h[0] += *(u16 *) (reg_a4 + 0x14);
    reg_d3.h[0] -= *(u16 *) (reg_a4 + 0x16);
    reg_a6 = (u8 *)D_002962E0 + 2;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(6, 34);
    if (D_00299768_as_u16_a[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0xA, 54);
    if (D_0029976A_as_u16_a[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0xF, 79);
    if (D_0029976C[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0x12, 94);
    if (D_0029976E[0] == 0) goto loop_5;
    reg_d6.h[0] = MAIN_OR_DEATH_LABEL(0x14, 104);
loop_5:
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    func_0020B6A0();
    if (cond_flag != 0) return;
    reg_a6 += 0x3E;
    if ((s16) --reg_d6.h[0] >= 0) goto loop_5;
}

extern s16 D_0028E098_as_s16;

void func_0020E230() {
    D_0028E098_as_s16 = 0;
    reg_a2 = reg_a1;
    if (*(s16 *)reg_a1 < 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a1 + 1);
        *(u8 *)(reg_a1 + 1) |= 2;
        if (reg_tmp.b[0] & 2) {
            func_0020E290();
        }
    }
}

extern u16 D_0028E098;
extern u16 D_00299764[];
extern u8 D_002BC7C0[];

void func_0020E290(void) {
    *(u8 *) (reg_a1 + 1) &= 0xEF;
    *(u16 *) (reg_a1 + 0x10) = 0x7400;
    *(u16 *) (reg_a1 + 0x10) += reg_d6.h[0];
    reg_a0 = reg_a1 + 2;
    reg_d0.h[0] = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] += reg_d6.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_d0.h[0] += 0x400;
    reg_d0.h[0] += *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d2.h[0] += reg_d6.h[0];
    reg_d3.h[0] = reg_d2.h[0];
    reg_d2.h[0] += *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_d3.h[0] -= *(u16 *) reg_a0;
    reg_a0 += 2;
    if (g_hyper_hit_scratch == 0) goto next_30;
    if (D_00299764[0] != 0) goto next_30;
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0x1C);
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[0] >>= 2;
    reg_d7.h[0] = g_hyper_level_hit_scratch;
    reg_d7.h[0] -= 1;
loop_20:
    reg_d5.h[0] += reg_d4.h[0];
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
    *(u16 *) (reg_a1 + 0xE) = reg_d5.h[0];
next_30:
    reg_a5 = (u8 *)D_002BC7C0;
    reg_d7.h[0] = 0x63;
    goto loop_10;
skip_2:
    reg_a5 += 0x20;
    if ((s16) --reg_d7.h[0] < 0) goto next_70;
loop_10:
    reg_d4.b[0] = *(u8 *) (reg_a5 + 1);
    if ((s8) reg_d4.b[0] >= 0) goto skip_2;
    reg_d4.h[1] = *(u16 *) (reg_a5 + 2);
    reg_d4.h[0] = *(u16 *) (reg_a5 + 4);
    reg_d4.h[0] += reg_d6.h[0];
    reg_d5.h[0] = reg_d4.h[0];
    reg_d4.h[0] += *(u16 *) (reg_a5 + 0x14);
    if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto skip_2;
    reg_d5.h[0] -= *(u16 *) (reg_a5 + 0x16);
    if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto skip_2;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    reg_d4.h[0] += reg_d6.h[0];
    reg_d5.h[0] = reg_d4.h[0];
    reg_d4.h[0] -= *(u16 *) (reg_a5 + 0x12);
    if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) goto skip_2;
    reg_d5.h[0] += *(u16 *) (reg_a5 + 0x10);
    if ((s32) reg_d1.h[0] > (s32) reg_d5.h[0]) goto skip_2;
    if (reg_d4.h[0] >= 0x9800) goto skip_2;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    if (!(*(u8 *) (reg_a5 + 1) & 0x20)) goto skip_2;
    if (*(s16 *) (reg_a5 + 0x18) < 0) goto next_60;
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0xE);
    if (g_hyper_hit_scratch == 0) goto next_13;
    if (D_00299764[0] != 0) goto next_20;
next_13:
    if (*(u16 *) (reg_a1 + 0x1A) == 0) goto next_20;
    if (!(*(u8 *) (reg_a5 + 1) & 2)) goto next_20;
    reg_d5.h[0] += reg_d5.h[0];
    goto next_40;
next_20:
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    if (!((s32) *(u16 *) (reg_a1 + 0x10) > (s32) reg_d4.h[0])) goto next_60;
    *(u16 *) (reg_a1 + 0) |= 0x1001;
    *(u16 *) (reg_a1 + 0xC) = 0;
    if (!((s32) reg_d1.h[0] > (s32) reg_d4.h[0])) goto next_35;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] += 0x400;
next_35:
    *(u16 *) (reg_a1 + 0x10) = reg_d4.h[0];
    reg_d0.h[0] = reg_d4.h[0];
next_40:
    if (D_0028E098 != 0) goto next_60;
    if (g_two_player_game != 0) goto next_50;
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[0] >>= 2;
    reg_d5.h[0] -= reg_d4.h[0];
next_50:
    reg_d4.h[0] = D_0028E0A8;
    reg_d4.h[0] |= 0x400;
    *(u16 *) (reg_a5 + 0) |= reg_d4.h[0];
    if (*(u16 *) (reg_a5 + 2) >= 0x6F00) goto next_60;
    *(u16 *) (reg_a5 + 0x18) -= reg_d5.h[0];
next_60:
    reg_a5 += 0x20;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_10;
next_70:
    func_0020E6F0();
}

extern u8 g_boss_present_b1;
extern u8 D_002BD440_as_u8_a[];

void func_0020E6F0(void) {
    reg_a1 = reg_a2;
    if (g_hyper_hit_scratch == 0) goto next_10;
    if (D_00299764[0] == 0) goto next_5;
    *(u16 *) (reg_a1 + 0xE) = 0;
    goto next_10;
next_5:
    reg_d7.h[0] = g_hyper_level_hit_scratch;
    reg_d7.h[0] -= 1;
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0x1C);
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[0] >>= 1;
    if (g_boss_present_b1 & 1) goto loop_6;
    reg_d4.h[0] >>= 1;
loop_6:
    reg_d5.h[0] += reg_d4.h[0];
    if ((s16) --reg_d7.h[0] >= 0) goto loop_6;
    *(u16 *) (reg_a1 + 0xE) = reg_d5.h[0];
next_10:
    reg_a5 = (u8 *)D_002BD440_as_u8_a;
    reg_d7.h[0] = 0x31;
    goto loop_20;
skip_2:
    reg_a5 += 0x20;
    if ((s16) --reg_d7.h[0] < 0) goto next_70;
loop_20:
    reg_d4.b[0] = *(u8 *) (reg_a5 + 1);
    if ((s8) reg_d4.b[0] >= 0) goto skip_2;
    reg_d4.h[1] = *(u16 *) (reg_a5 + 2);
    reg_d4.h[0] = *(u16 *) (reg_a5 + 4);
    reg_d4.h[0] += reg_d6.h[0];
    reg_d5.h[0] = reg_d4.h[0];
    reg_d4.h[0] += *(u16 *) (reg_a5 + 0x14);
    if ((s32) reg_d3.h[0] > (s32) reg_d4.h[0]) goto skip_2;
    reg_d5.h[0] -= *(u16 *) (reg_a5 + 0x16);
    if ((s32) reg_d5.h[0] > (s32) reg_d2.h[0]) goto skip_2;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    reg_d4.h[0] += reg_d6.h[0];
    reg_d5.h[0] = reg_d4.h[0];
    reg_d4.h[0] -= *(u16 *) (reg_a5 + 0x12);
    if ((s32) reg_d4.h[0] > (s32) reg_d0.h[0]) goto skip_2;
    reg_d5.h[0] += *(u16 *) (reg_a5 + 0x10);
    if ((s32) reg_d1.h[0] > (s32) reg_d5.h[0]) goto skip_2;
    if (reg_d4.h[0] >= 0x9800) goto skip_2;
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    if (!(*(u8 *) (reg_a5 + 1) & 0x20)) goto skip_2;
    if (*(s16 *) (reg_a5 + 0x18) < 0) goto next_60;
    reg_d5.h[0] = *(u16 *) (reg_a1 + 0xE);
    reg_tmp4.h[0] = reg_d4.h[0];
    reg_d4.h[0] = reg_d4.h[1];
    reg_d4.h[1] = reg_tmp4.h[0];
    if (!((s32) *(u16 *) (reg_a1 + 0x10) > (s32) reg_d4.h[0])) goto next_60;
    *(u16 *) (reg_a1 + 0) |= 0x1001;
    *(u16 *) (reg_a1 + 0xC) = 0;
    if (!((s32) reg_d1.h[0] > (s32) reg_d4.h[0])) goto next_35;
    reg_d4.h[0] = reg_d1.h[0];
    reg_d4.h[0] += 0x400;
next_35:
    *(u16 *) (reg_a1 + 0x10) = reg_d4.h[0];
    reg_d0.h[0] = reg_d4.h[0];
    if (D_0028E098 != 0) goto next_60;
    reg_d4.h[0] = reg_d5.h[0];
    if ((s16) reg_d4.h[0] >= 0) goto next_42;
    reg_d5.h[0] *= 0xFFFF;
    goto next_44;
next_42:
    reg_d4.h[0] >>= 3;
    reg_d4.h[0] *= 0xFFFF;
    *(u16 *) (reg_a1 + 0xE) = reg_d4.h[0];
next_44:
    if (g_two_player_game != 0) goto next_50;
    reg_d4.h[0] = reg_d5.h[0];
    reg_d4.h[0] >>= 2;
    reg_d5.h[0] -= reg_d4.h[0];
next_50:
    reg_d4.h[0] = D_0028E0A8;
    reg_d4.h[0] |= 0x400;
    *(u16 *) (reg_a5 + 0) |= reg_d4.h[0];
    *(u16 *) (reg_a5 + 0x18) -= reg_d5.h[0];
next_60:
    reg_a5 += 0x20;
    if ((s16) --reg_d7.h[0] >= 0) goto loop_20;
next_70:
    *(u16 *) (reg_a1 + 0x10) -= reg_d6.h[0];
}
