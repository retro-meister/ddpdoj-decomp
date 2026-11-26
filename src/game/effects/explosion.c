#include "common.h"
#include "entity.h"
#include "explosion.h"
#include "sdk/ps2sdk.h"

void explosions_clear(void);
void explosions_update(void);

s32 bullets_clear();                            /* extern */
s32 enemy_anims_clear();                            /* extern */
s32 enemies_reset();                            /* extern */
s32 items_clear();                            /* extern */
s32 debris_clear();                            /* extern */
s32 sparks_clear();                            /* extern */
s32 wrecks_clear();                            /* extern */

void objects_task_begin(void) {
    items_clear();
    bullets_clear();
    explosions_clear();
    debris_clear();
    wrecks_clear();
    enemy_anims_clear();
    sparks_clear();
    enemies_reset();
    *(s8 *)(reg_a5 + 3) = 1;
}

s32 bombs_update();
s32 pickups_update();
s32 bullets_update();
s32 enemy_anims_update();
s32 hyper_stock_draw();
s32 maximum_marks_draw();
s32 hyper_ready_marks_draw();
s32 hyper_bullet_speed_update();
s32 bullets_hold_timer_tick();
s32 p1_draw();
s32 p2_draw();
s32 p1_draw_while_entering();
s32 p2_draw_while_entering();
s32 player_lasers_update();
s32 laser_impacts_update();
s32 player_shots_update();
s32 enemies_frame();
s32 items_update();
void ground_step_unused(s32, s32, s32);
s32 p1_options_update();
s32 debris_update();
s32 sparks_update();
s32 player_bullet_collisions();
s32 player_collisions();
s32 wrecks_update();
extern u16 g_frame_mod2;
extern u16 g_p2_hyper_level;
extern u16 g_p1_hyper_level;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_loop;
extern u16 g_two_player_game;
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029DCA0[];
extern u8 D_0029DD30[];
extern u8 D_0029E2A0[];
extern u8 D_0029E330[];
extern u8 D_0029E390[];
extern u8 D_0029EA50[];
extern s16 g_player2[56];
extern s16 g_player1[56];

void objects_task(void) {
    u16 t1;
    u16 t2;

    if (*(u8 *)(reg_a5 + 3) == 0) {
        objects_task_begin();
        return;
    }
    wrecks_update();
    ground_step_unused(0x1F, 0x1F, 0x1F);
    enemies_frame();
    ground_step_unused(0, 0, 0);
    enemy_anims_update();
    pickups_update();
    explosions_update();
    debris_update();
    ground_step_unused(0x1F, 0, 0);
    bombs_update();
    player_shots_update();
    p1_options_update();
    player_lasers_update();
    laser_impacts_update();
    sparks_update();
    hyper_stock_draw();
    p1_draw_while_entering();
    p2_draw_while_entering();
    p1_draw();
    p2_draw();
    ground_step_unused(0x1F, 0, 0x1F);
    items_update();
    ground_step_unused(0x1F, 0x1F, 0);
    hyper_bullet_speed_update();
    bullets_update();
    bullets_hold_timer_tick();
    maximum_marks_draw();
    hyper_ready_marks_draw();
    ground_step_unused(0, 0x1F, 0);
    if (g_two_player_game != 0) {
        reg_d4.h[0] = ((u16 *)g_player1)[0];
        if (((u16 *)g_player1)[0] != 0) {
            reg_a0 = (u8 *)D_0029E390;
            reg_a1 = (u8 *)D_0029D770;
            reg_a2 = (u8 *)D_0029E2A0;
            reg_a3 = (u8 *)D_0029E330;
            reg_a4 = (u8 *)(((u16 *)g_player1));
            reg_d0.h[0] = 0x1000;
            t2 = g_p1_hyper_active;
            t1 = g_p1_hyper_level;
            reg_d1.h[0] = t2;
            reg_d2.h[0] = t1;
            if (g_frame_mod2 == 0) {
                player_collisions();
                return;
            }
            goto next_1;
        }
        reg_d4.h[0] = ((u16 *)g_player2)[0];
        if (((u16 *)g_player2)[0] != 0) {
            reg_a0 = (u8 *)D_0029EA50;
            reg_a1 = (u8 *)D_0029D750;
            reg_a2 = (u8 *)D_0029DCA0;
            reg_a3 = (u8 *)D_0029DD30;
            reg_a4 = (u8 *)(((u16 *)g_player2));
            reg_d0.h[0] = 0x800;
            t2 = g_p2_hyper_active;
            t1 = g_p2_hyper_level;
            reg_d1.h[0] = t2;
            reg_d2.h[0] = t1;
            if (g_frame_mod2 != 0) {
                player_collisions();
                return;
            }
next_1:
            switch (g_loop) {
            case 0:
                break;
            default:
                player_bullet_collisions();
            }
        }
    } else {
        if (g_frame_mod2 == 0) {
            reg_a0 = (u8 *)D_0029E390;
            reg_a1 = (u8 *)D_0029D770;
            reg_a2 = (u8 *)D_0029E2A0;
            reg_a3 = (u8 *)D_0029E330;
            reg_a4 = (u8 *)(((u16 *)g_player1));
            reg_d0.h[0] = 0x1000;
            reg_d1.h[0] = g_p1_hyper_active;
            reg_d2.h[0] = g_p1_hyper_level;
            player_collisions();
            return;
        }
        reg_a0 = (u8 *)D_0029EA50;
        reg_a1 = (u8 *)D_0029D750;
        reg_a2 = (u8 *)D_0029DCA0;
        reg_a3 = (u8 *)D_0029DD30;
        reg_a4 = (u8 *)(((u16 *)g_player2));
        reg_d0.h[0] = 0x800;
        reg_d1.h[0] = g_p2_hyper_active;
        reg_d2.h[0] = g_p2_hyper_level;
        player_collisions();
    }
}

extern u8 g_explosions[];


void explosions_clear(void) {
    memset(((s32 *)g_explosions), 0, 0x11BA);
}


void explosion_next_frame(void) {
    reg_tmp.h[1] = EXPLOSION(reg_a6)->frames[0];
    reg_tmp.h[0] = EXPLOSION(reg_a6)->frames[1];
    reg_a1 = (u8 *)reg_tmp.w;
loop_1:
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
    if (0 > (s32) reg_d0.w) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if ((s16) reg_d0.h[0] == -1) {
            EXPLOSION(reg_a6)->look = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a6)->offset_y = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            EXPLOSION(reg_a6)->offset_x = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
        } else {
            reg_a1 += 2;
            reg_d1.h[1] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_d1.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            reg_tmp.h[1] = EXPLOSION(reg_a6)->y;
            reg_tmp.h[0] = EXPLOSION(reg_a6)->x;
            reg_tmp.w += reg_d1.w;
            EXPLOSION(reg_a6)->y = (u16) reg_tmp.h[1];
            EXPLOSION(reg_a6)->x = (u16) reg_tmp.h[0];
        }
        goto loop_1;
    }
    reg_tmp.w = (u32)reg_a1;
    EXPLOSION(reg_a6)->frames[0] = (u16) reg_tmp.h[1];
    EXPLOSION(reg_a6)->frames[1] = (u16) reg_tmp.h[0];
}

typedef void (*Fn)();

s32 debris_spawn();
s32 entity_follow_scroll();
s32 velocity_from_dir256();
extern u16 explosion_scripts[];
extern u16 explosion_scripts_b[];
extern u8 D_00250760[];
extern u16 g_game_frame;
extern u8 g_explosions[];
extern u16 g_explosion_count[];
extern u16 g_side_scroll_step[];
extern u16 g_bomb_entities[24];

void explosions_update(void) {
    u16 x_save;
    u16 hi_save;

    g_explosion_count[0] = 0;
    reg_d7.h[0] = 0x4F;
    reg_a6 = (u8 *)g_explosions;
loop_1:
    if (EXPLOSION(reg_a6)->kind.h == 0) goto next_1;
    if (EXPLOSION(reg_a6)->delay == 0) goto block_main;
    EXPLOSION(reg_a6)->delay -= 1;
    goto next_1;
block_main:
    g_explosion_count[0] += 1;
    if (!(EXPLOSION(reg_a6)->kind.b[1] & 0x40)) goto block_first;
    EXPLOSION(reg_a6)->kind.b[1] |= 0x40;
    goto block_fire;
block_first:
    EXPLOSION(reg_a6)->kind.b[1] |= 0x40;
    reg_d1.h[0] = EXPLOSION(reg_a6)->kind.h;
    reg_a1 = (u8 *)explosion_scripts;
    reg_d1.h[0] = reg_d1.b[0];
    reg_tmp.w = reg_d1.w;
    if (!(reg_tmp.w & 0x80)) goto skip_1;
    reg_d1.w &= ~0x80;
    reg_a1 = (u8 *)explosion_scripts_b;
skip_1:
    reg_d1.h[0] *= 8;
    reg_tmp.h[1] = ((reg_d1.h[0] + 4) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 4) & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = ((reg_d1.h[0] + 6) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 6) & ~1)) : *(u16 *)reg_a1;
    reg_a2 = (u8 *)reg_tmp.w;
    EXPLOSION(reg_a6)->frame_time = *(u16 *)reg_a2;
    reg_a2 += 2;
    EXPLOSION(reg_a6)->frame_time += 1;
    reg_tmp.w = (u32)reg_a2;
    EXPLOSION(reg_a6)->times[0] = reg_tmp.h[1];
    EXPLOSION(reg_a6)->times[1] = reg_tmp.h[0];
    EXPLOSION(reg_a6)->frames[0] = (reg_d1.h[0] != 0) ? *(u16 *)(reg_a1 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a1;
    EXPLOSION(reg_a6)->frames[1] = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)(reg_a1 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
    explosion_next_frame();
    reg_tmp.h[1] = EXPLOSION(reg_a6)->frames[0];
    reg_tmp.h[0] = EXPLOSION(reg_a6)->frames[1];
    reg_a2 = (u8 *)reg_tmp.w;
    EXPLOSION(reg_a6)->draw = *(u16 *)reg_a2;
    reg_a2 += 2;
    EXPLOSION(reg_a6)->sprite = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_tmp.w = (u32)reg_a2;
    EXPLOSION(reg_a6)->frames[0] = reg_tmp.h[1];
    EXPLOSION(reg_a6)->frames[1] = reg_tmp.h[0];
    reg_d1.h[1] = EXPLOSION(reg_a6)->y;
    reg_d1.h[0] = EXPLOSION(reg_a6)->x;
    reg_tmp.h[1] = EXPLOSION(reg_a6)->start_y;
    reg_tmp.h[0] = EXPLOSION(reg_a6)->start_x;
    reg_d1.w += reg_tmp.w;
    EXPLOSION(reg_a6)->y = reg_d1.h[1];
    EXPLOSION(reg_a6)->x = reg_d1.h[0];
block_fire:
    reg_d0.h[0] = EXPLOSION(reg_a6)->debris;
    if (0 > (s16)reg_d0.h[0]) goto block_debris;
    reg_d1.h[0] = EXPLOSION(reg_a6)->draw_layer;
    reg_d1.h[0] <<= 8;
    reg_d0.h[0] |= reg_d1.h[0];
    x_save = EXPLOSION(reg_a6)->attr.h;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = EXPLOSION(reg_a6)->debris_arg;
    EXPLOSION(reg_a6)->attr.b.palette = EXPLOSION(reg_a6)->debris_palette;
    debris_spawn();
    EXPLOSION(reg_a6)->attr.h = x_save;
    EXPLOSION(reg_a6)->debris = 0xFFFF;
block_debris:
    reg_d0.h[0] = g_side_scroll_step[0];
    EXPLOSION(reg_a6)->x -= reg_d0.h[0];
    if (EXPLOSION(reg_a6)->follows_scroll == 0) goto block_shift;
    entity_follow_scroll();
block_shift:
    reg_d0.w = 0;
    reg_d0.b[0] = EXPLOSION(reg_a6)->move.b.speed;
    if (reg_d0.b[0] == 0) goto block_speed;
    reg_d1.w = 0;
    reg_d1.b[0] = EXPLOSION(reg_a6)->move.b.dir;
    velocity_from_dir256();
    EXPLOSION(reg_a6)->speed_y = reg_d2.h[0];
    EXPLOSION(reg_a6)->speed_x = reg_d3.h[0];
    EXPLOSION(reg_a6)->move.b.speed = 0;
block_speed:
    reg_d0.h[1] = EXPLOSION(reg_a6)->drag_y;
    reg_d0.h[0] = EXPLOSION(reg_a6)->drag_x;
    if (reg_d0.w == 0) goto block_move;
    reg_tmp.b[0] = EXPLOSION(reg_a6)->drag_timer.t.count;
    EXPLOSION(reg_a6)->drag_timer.t.count -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto block_move;
    EXPLOSION(reg_a6)->drag_timer.t.count = EXPLOSION(reg_a6)->drag_timer.t.reload;
    EXPLOSION(reg_a6)->speed_x -= reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    EXPLOSION(reg_a6)->speed_y -= reg_d0.h[0];
block_move:
    reg_d0.h[1] = EXPLOSION(reg_a6)->speed_y;
    reg_d0.h[0] = EXPLOSION(reg_a6)->speed_x;
    EXPLOSION(reg_a6)->x += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    EXPLOSION(reg_a6)->y += reg_d0.h[0];
    reg_d1.h[1] = EXPLOSION(reg_a6)->y;
    reg_d1.h[0] = EXPLOSION(reg_a6)->x;
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0xA800;
    reg_tmp1.w = 0;
    reg_d1.h[0] += 0x1000;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0xA800;
    reg_tmp1.w += reg_tmp.w;
    if (reg_tmp1.h[1] != 0) goto block_end;
    reg_tmp1.w = 0;
    reg_tmp.w = reg_d1.w;
    hi_save = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_tmp.h[0] = 0x1000;
    reg_d1.h[0] += 0x1000;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] += 0x7000;
    reg_tmp1.w += reg_tmp.w;
    reg_d1.h[1] = hi_save;
    if (reg_tmp1.h[1] != 0) goto block_end;
    EXPLOSION(reg_a6)->frame_time -= 1;
    if (!(0 > (s16) EXPLOSION(reg_a6)->frame_time)) goto block_disp;
    reg_tmp.h[1] = EXPLOSION(reg_a6)->times[0];
    reg_tmp.h[0] = EXPLOSION(reg_a6)->times[1];
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    if ((s16)reg_d0.h[0] != -1) goto block_anim;
block_end:
    EXPLOSION(reg_a6)->kind.h = 0;
    goto next_1;
block_anim:
    EXPLOSION(reg_a6)->frame_time = reg_d0.h[0];
    reg_tmp.w = (u32)reg_a0;
    EXPLOSION(reg_a6)->times[0] = reg_tmp.h[1];
    EXPLOSION(reg_a6)->times[1] = reg_tmp.h[0];
    explosion_next_frame();
    reg_tmp.h[1] = EXPLOSION(reg_a6)->frames[0];
    reg_tmp.h[0] = EXPLOSION(reg_a6)->frames[1];
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    EXPLOSION(reg_a6)->draw = reg_d0.h[1];
    EXPLOSION(reg_a6)->sprite = reg_d0.h[0];
    reg_tmp.w = (u32)reg_a0;
    EXPLOSION(reg_a6)->frames[0] = reg_tmp.h[1];
    EXPLOSION(reg_a6)->frames[1] = reg_tmp.h[0];
block_disp:
    reg_a0 = (u8 *)((u8 *)g_bomb_entities);
    if (!(0 > *(s16 *)reg_a0)) goto block_draw;
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] &= 1;
    if ((s16)reg_d0.h[0] == 0) goto next_1;
block_draw:
    reg_d0.h[0] = EXPLOSION(reg_a6)->draw_layer;
    reg_d0.h[0] >>= 2;
    ((Fn)*(u32 *)(D_00250760 + reg_d0.h[0] * 4))();
next_1:
    reg_a6 += 0x38;
    if ((s16)(--reg_d7.h[0]) >= 0) goto loop_1;
}

extern u8 D_0029BBC0[];

void explosion_spawn(void) {
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    u8 *sa6;
    u32 s0;
    u32 s1;
    u32 t1;

    s0 = reg_d0.w;
    s1 = reg_d1.w;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] &= 0x7F;
    if (0 > (s16) reg_d1.h[0]) goto block_2;
    if ((s16) reg_d1.h[0] > 0x21) goto block_2;
    reg_d1.h[0] = 0x4F;
    reg_a0 = (u8 *)g_explosions;
loop_1:
    if (EXPLOSION(reg_a0)->kind.h != 0) goto next_1;
    reg_d0.h[0] |= 0x8000;
    EXPLOSION(reg_a0)->kind.h = reg_d0.h[0];
    reg_d0.w = 0;
    EXPLOSION(reg_a0)->follows_scroll = reg_d0.h[0];
    EXPLOSION(reg_a0)->debris = 0xFFFF;
    EXPLOSION(reg_a0)->debris_palette = 0x1E;
    EXPLOSION(reg_a0)->delay = reg_d0.h[0];
    EXPLOSION(reg_a0)->move.h = reg_d0.h[0];
    EXPLOSION(reg_a0)->attr.b.flip = reg_d0.b[0];
    EXPLOSION(reg_a0)->attr.b.palette = 0x1E;
    EXPLOSION(reg_a0)->draw_layer = 0;
    EXPLOSION(reg_a0)->drag_y = reg_d0.h[1];
    EXPLOSION(reg_a0)->drag_x = reg_d0.h[0];
    EXPLOSION(reg_a0)->start_y = reg_d0.h[1];
    EXPLOSION(reg_a0)->start_x = reg_d0.h[0];
    EXPLOSION(reg_a0)->speed_y = reg_d0.h[1];
    EXPLOSION(reg_a0)->speed_x = reg_d0.h[0];
    reg_d0.w = s0;
    reg_d1.w = s1;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    return;
next_1:
    reg_a0 += 0x38;
    t1 = reg_d1.h[0] - 1;
    reg_d1.h[0] = t1;
    if (((s64) ((s64) (u16) t1 << 0x30) >> 0x30) >= 0) goto loop_1;
block_2:
    reg_d0.w = s0;
    reg_d1.w = s1;
    reg_a1 = sa1;
    reg_a0 = (u8 *)D_0029BBC0;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
}

/* .bss (the compiler lays these out in reverse) */
u8 D_0029BBC0[64];
u8 g_explosions[4480];
