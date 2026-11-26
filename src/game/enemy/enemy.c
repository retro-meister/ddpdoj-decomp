#include "common.h"
#include "entity.h"
#include "enemy_tables.h"
#include "enemy.h"

#ifdef DDPDOJ_PC
#include <string.h>
#endif

void stage_enemies_select(void);
void enemies_run(void);
void enemy_start(void);
void spawn_request_alloc();
void enemy_slot_claim(void);
void enemy_remove_entities();
void enemy_init_entities_n(void);

extern u8 g_setting_hitbox_display;
extern u16 g_attract_demo;
extern u8 g_replay_mode;
extern u8 g_simulation_active;

void enemy_hitbox_debug_draw(void) {
#ifndef DEATH_LABEL
    if (g_attract_demo == 0 && g_setting_hitbox_display != 0 && g_simulation_active != 0) {
        if (g_replay_mode == 2) {
            return;
        }
    }
#endif
}

extern u16 g_spawn_request_end;
extern s16 D_0028E7D8;
extern s16 D_0028E7DC;
extern s16 D_0028E7E0;
extern u16 g_enemy_count_second;
extern u16 g_enemy_count;
extern u16 D_0028E7EC;

#ifndef DDPDOJ_PC
/* The reset clears the entity pools as bytes through the first one's address: the
   three entity pools follow one another. */
typedef struct { s8 first[0xC80]; s8 second[0x640]; s8 spare[0x640]; } EntityBytes;
extern EntityBytes g_enemy_entities_as_bytes;
#endif

void enemies_reset(void) {
    s32 i;

    for (i = 0; i < 0xA0; i++) {
        g_enemy_slots.bytes.large[i] = 0;
    }
    for (i = 0; i < 0x280; i++) {
        g_enemy_slots.bytes.spawners[i] = 0;
    }
    for (i = 0; i < 0xF00; i++) {
        g_enemy_slots.bytes.others[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        g_enemy_slots.bytes.none[i] = 0;
    }
#ifdef DDPDOJ_PC
    memset(g_enemy_entities, 0, sizeof(g_enemy_entities));
    memset(g_spare_entities, 0, sizeof(g_spare_entities));
#else
    for (i = 0; i < 0xC80; i++) {
        g_enemy_entities_as_bytes.first[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        g_enemy_entities_as_bytes.second[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        g_enemy_entities_as_bytes.spare[i] = 0;
    }
#endif
    g_spawn_request_end = 0;
    D_0028E7D8 = 0;
    D_0028E7DC = 0;
    D_0028E7E0 = 0;
    g_enemy_count_second = 0;
    g_enemy_count = 0;
    D_0028E7EC = 0;
    for (i = 0; i < 0xC80; i++) {
        ((s8 *)g_spawn_requests)[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        ((s8 *)&g_spawn_request_spare)[i] = 0;
    }
    stage_enemies_select();
}

extern u8 g_game_mode;
extern u8 g_simulation_boss_start;
extern u16 g_stage_x4;
extern u8 g_stage_enemy_cursor[];

void stage_enemies_select(void) {
    reg_a4 = g_stage_enemy_cursor;
    reg_a0 = (u8 *)g_stage_enemies;
#ifdef DDPDOJ_PC
    StageEnemies *stages = g_stage_enemies;
    if ((g_simulation_active && g_simulation_boss_start) || g_game_mode == 2) {
        stages = g_stage_boss_start_enemies;
    }
    const StageEnemies *stage = &stages[g_stage_x4 / 4];
    STORE_ARCADE_ADDRESS((u16 *)reg_a4, stage->placements);
    STORE_ARCADE_ADDRESS((u16 *)reg_a4 + 2, stage->path_offsets);
    STORE_ARCADE_ADDRESS((u16 *)reg_a4 + 4, stage->paths);
#else
    reg_d0.h[0] = g_stage_x4;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    if (((g_simulation_active != 0) && (g_simulation_boss_start != 0)) || (g_game_mode == 2)) {
        reg_a0 = (u8 *)g_stage_boss_start_enemies;
    }
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 2) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)reg_a4 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 6) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 4) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_d0.h[0];
#endif
    g_spawn_request_end = 0;
}


extern u16 g_spawn_request_end;
extern u16 g_scroll_line;

void enemies_start_due(void) {
    u8 *save_a2;
    u8 *save_a3;

    reg_a3 = (u8 *)g_stage_enemy_cursor;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 0);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 2);
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
next_placement:
    reg_d0.h[0] = ((EnemyPlacement *)reg_a2)->line;
    if (reg_d0.h[0] == 0xFFFF) goto placements_done;
    if ((s16) g_scroll_line > (s16) reg_d0.h[0]) goto skip_placement;
    if (g_scroll_line != reg_d0.h[0]) goto placements_done;
    reg_d0.w = 0;
    reg_d0.b[0] = ((EnemyPlacement *)reg_a2)->kind;
    reg_d1.h[1] = *(u16 *) (reg_a2 + 4);
    reg_d1.h[0] = *(u16 *) (reg_a2 + 6);
    reg_d1.w &= 0xFFF000;
    reg_d7.w = 0x10;
    reg_d1.w = (u32) reg_d1.w >> reg_d7.w;
    reg_d7.h[0] = *(u16 *) (reg_a2 + 6);
    reg_d7.h[0] &= 0xFFF;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 4);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 6);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d7.h[0] += reg_d7.h[0];
    reg_d7.h[0] = (reg_d7.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 8);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 0xA);
    reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_a1 += reg_d7.h[0];
    enemy_slot_claim();
    if (cond_flag != 0) goto skip_placement;
    *(u16 *) (reg_a0 + 0xA) = *(u16 *) (reg_a2 + 2);
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a1);
    *(u16 *) (reg_a0 + 0x12) = reg_tmp.h[1];
    *(u16 *) (reg_a0 + 0x14) = reg_tmp.h[0];
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    reg_a5 = reg_a0;
    enemy_start();
    reg_a3 = save_a3;
    reg_a2 = save_a2;
skip_placement:
    reg_a2 += sizeof(EnemyPlacement);
    goto next_placement;
placements_done:
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
    *(u16 *)reg_a3 = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a3 + 2) = (u16) reg_tmp.h[0];
next_request:
    reg_d6.h[0] = g_spawn_request_end;
    if (g_spawn_request_end != 0) {
        reg_a4 = (u8 *)g_spawn_requests;
        reg_d6.h[0] -= 0x50;
        reg_a4 += reg_d6.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d1.h[0] = *(u16 *)(reg_a4 + 4);
        enemy_slot_claim();
        if (cond_flag == 0) {
            *(u8 *)(reg_a0 + 3) = (u8) *(u8 *)(reg_a4 + 3);
            *(u16 *)(reg_a0 + 0x12) = (u16) *(u16 *)(reg_a4 + 0x12);
            *(u16 *)(reg_a0 + 0x14) = (u16) *(u16 *)(reg_a4 + 0x14);
            *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)(reg_a4 + 0x16);
            *(u16 *)(reg_a0 + 0x18) = (u16) *(u16 *)(reg_a4 + 0x18);
            *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)(reg_a4 + 0x1A);
            *(u16 *)(reg_a0 + 0x1C) = (u16) *(u16 *)(reg_a4 + 0x1C);
            *(u16 *)(reg_a0 + 0x1E) = (u16) *(u16 *)(reg_a4 + 0x1E);
            *(u16 *)(reg_a0 + 0x20) = (u16) *(u16 *)(reg_a4 + 0x20);
            *(u16 *)(reg_a0 + 0x22) = (u16) *(u16 *)(reg_a4 + 0x22);
            *(u16 *)(reg_a0 + 0x24) = (u16) *(u16 *)(reg_a4 + 0x24);
            *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)(reg_a4 + 0x26);
            *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)(reg_a4 + 0x28);
            *(u16 *)(reg_a0 + 0x2A) = (u16) *(u16 *)(reg_a4 + 0x2A);
            *(u16 *)(reg_a0 + 0x2C) = (u16) *(u16 *)(reg_a4 + 0x2C);
            *(u16 *)(reg_a0 + 0x2E) = (u16) *(u16 *)(reg_a4 + 0x2E);
            *(u16 *)(reg_a0 + 0x30) = (u16) *(u16 *)(reg_a4 + 0x30);
            *(u16 *)(reg_a0 + 0x32) = (u16) *(u16 *)(reg_a4 + 0x32);
            *(u16 *)(reg_a0 + 0x34) = (u16) *(u16 *)(reg_a4 + 0x34);
            *(u16 *)(reg_a0 + 0x36) = (u16) *(u16 *)(reg_a4 + 0x36);
            *(u16 *)(reg_a0 + 0x38) = (u16) *(u16 *)(reg_a4 + 0x38);
            *(u16 *)(reg_a0 + 0x3A) = (u16) *(u16 *)(reg_a4 + 0x3A);
            *(u16 *)(reg_a0 + 0x3C) = (u16) *(u16 *)(reg_a4 + 0x3C);
            *(u16 *)(reg_a0 + 0x3E) = (u16) *(u16 *)(reg_a4 + 0x3E);
            *(u16 *)(reg_a0 + 0x40) = (u16) *(u16 *)(reg_a4 + 0x40);
            *(u16 *)(reg_a0 + 0x42) = (u16) *(u16 *)(reg_a4 + 0x42);
            *(u16 *)(reg_a0 + 0x44) = (u16) *(u16 *)(reg_a4 + 0x44);
            *(u16 *)(reg_a0 + 0x46) = (u16) *(u16 *)(reg_a4 + 0x46);
            *(u16 *)(reg_a0 + 0x48) = (u16) *(u16 *)(reg_a4 + 0x48);
            *(u16 *)(reg_a0 + 0x4A) = (u16) *(u16 *)(reg_a4 + 0x4A);
        }
        g_spawn_request_end = reg_d6.h[0];
        if (((u8 *)&g_enemy_slots.slot.none) != reg_a0) {
            reg_a5 = reg_a0;
            enemy_start();
        }
        if (g_spawn_request_end != 0) {
            goto next_request;
        }
    }
}


void enemies_frame(void) {
#ifdef DDPDOJ_PC
    u8 *temp_s0 = reg_a5;
#else
    s32 temp_s0 = (s32)reg_a5;
#endif
    enemies_start_due();
    enemies_run();
    reg_a5 = (u8 *)temp_s0;
}

typedef void (*Fn)();

extern u16 g_enemy_count_second;
extern u16 g_enemy_count;
extern u16 D_0028E7EC;
extern u16 g_side_scroll_step[];
extern u8 *reg_call_target_as_u8_p;

void enemies_run(void) {
    u32 temp_s0;

    reg_a5 = (u8 *)&g_enemy_slots;
    D_0028E7EC = 0;
    g_enemy_count = 0;
    reg_d6.h[0] = 0x39;
    g_enemy_count_second = 0;
    do {
        if (*(u16 *)reg_a5 != 0) {
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
            reg_d0.h[0] = g_side_scroll_step[0];
            reg_a6 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            ENTITY(reg_a6)->x.h -= reg_d0.h[0];
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x4C);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x4E);
            reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            reg_call_target_as_u8_p = reg_a1;
            temp_s0 = reg_d6.w;
            ((Fn)reg_call_target_as_u8_p)();
            reg_d6.w = temp_s0;
            reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
            reg_d0.h[0] += 1;
            if ((s16) *(u16 *)reg_a5 < 0) {
                D_0028E7EC += 1;
                reg_d2.b[0] = *(u8 *)(reg_a5 + 0xC);
                if (((s8) reg_d2.b[0] >= 0) && !(reg_d2.w & 0x20)) {
                    g_enemy_count += reg_d0.h[0];
                } else {
                    g_enemy_count_second += reg_d0.h[0];
                }
            }
        }
        reg_a5 += 0x50;
    } while ((s16)(--reg_d6.h[0]) >= 0);
    D_0028E7E0 = 0;
    D_0028E7DC = 0;
    D_0028E7D8 = 0;
}

s32 active_players_mask();

void enemies_remove_all(u8 *arg1) {
    u8 *var_a1;
    u8 temp_a0;

    var_a1 = (u8 *)(arg1);
    reg_a0 = (u8 *)g_enemy_entities;
    reg_d3.w = 0x63;
    do {
        temp_a0 = *(u8 *)(reg_a0 + 1);
        if (temp_a0 & 0x20) {
            active_players_mask();
            var_a1 = (u8 *)(reg_a0);
            (*(u8 *)((u8 *)(var_a1) + (1))) |= reg_d0.b[0];
            goto block_4;
        }
        if (temp_a0 & 0x40) {
block_4:
            *(u16 *)(reg_a0 + 0x18) = 0xFFFF;
        }
        reg_a0 += 0x20;
    } while ((s16)(--reg_d3.h[0]) >= 0);
}


s32 enemy_entities_claim(void) {
    u32 count;
    s32 ret;

    ret = 0;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0xC);
    if ((s8)reg_d2.b[0] >= 0) goto block_2;
block_1:
    reg_a6 = (u8 *)g_enemy_entities_second;
    reg_d2.w = 0x32;
    goto loop_3;
block_2:
    if (reg_d2.w & 0x20) goto block_1;
    reg_a6 = (u8 *)g_enemy_entities;
    reg_d2.w = 0x64;
loop_3:
    reg_tmp2.w = reg_d2.h[0];
    reg_tmp2.w -= 1;
    reg_d2.h[0] = reg_tmp2.h[0];
    if (reg_tmp2.h[1] != 0) {
        ret = reg_tmp2.h[1] & 0xFFFF;
        goto block_7;
    }
    if (ENTITY(reg_a6)->flags.b[1] != 0) goto block_4;
    reg_a6 += 0x20;
    goto block_5;
block_4:
    reg_a6 += 0x20;
    reg_d1.h[0] = reg_d0.h[0];
    goto loop_3;
block_5:
    count = reg_d1.h[0] - 1;
    reg_d1.h[0] = count;
    if (((s64)((s64)(u16) count << 0x30) >> 0x30) >= 0) goto loop_3;
loop_6:
    reg_a6 -= 0x20;
    ENTITY(reg_a6)->flags.h = 0x8000;
    count = reg_d0.h[0] - 1;
    reg_d0.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_6;
block_7:
    return ret;
}

extern u16 g_side_scroll_x[];
extern s16 g_player2[56];
extern s16 g_player1[56];

void enemy_start(void) {
    s8 temp_s0;
    s64 var_a0;

    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xD);
    var_a0 = 0;
    if ((s16)(reg_d7.h[0]) >= 0x80) {
        var_a0 = 1;
        reg_d7.h[0] -= 0x80;
    }
    temp_s0 = var_a0;
#ifdef DDPDOJ_PC
    (temp_s0 ? g_enemy_first_routines_high : g_enemy_first_routines)[reg_d7.h[0]]();
#else
    if (temp_s0 == 0) {
        ((Fn)*(u32 *)((u8 *)g_enemy_first_routines + (reg_d7.h[0] * 4)))();
    } else {
        ((Fn)*(u32 *)((u8 *)g_enemy_first_routines_high + (reg_d7.h[0] * 4)))();
    }
#endif
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    if (enemy_entities_claim() == 0) {
        reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a6);
        *(u16 *)(reg_a5 + 6) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[0];
        reg_d7.h[0] *= 2;
#ifdef DDPDOJ_PC
        EnemyRoutines *routines = temp_s0 ? g_enemy_routines_high : g_enemy_routines;
        reg_tmp.w = ARCADE_ADDRESS_ENCODE(routines[reg_d7.h[0] / 2].run);
#else
        if (temp_s0 == 0) {
            reg_tmp.w = *(u32 *)((u8 *)&g_enemy_routines[0].run + (reg_d7.h[0] * 4));
        } else {
            reg_tmp.w = *(u32 *)((u8 *)&g_enemy_routines_high[0].run + (reg_d7.h[0] * 4));
        }
#endif
        *(u16 *)(reg_a5 + 0x4C) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x4E) = (u16) reg_tmp.h[0];
        reg_a0 = (u8 *)((u8 *)g_player1);
        reg_d0.w = 0;
        if (*(u8 *)reg_a5 & 1) {
            reg_a0 = (u8 *)((u8 *)g_player2);
            reg_d0.w = 1;
        }
        *(u8 *)(reg_a5 + 2) = (u8) reg_d0.b[0];
        *(s16 *)(reg_a5 + 0x3E) = 0;
#ifdef DDPDOJ_PC
        routines[reg_d7.h[0] / 2].start();
#else
        if (temp_s0 == 0) {
            ((Fn)*(u32 *)((u8 *)g_enemy_routines + (reg_d7.h[0] * 4)))();
        } else {
            ((Fn)*(u32 *)((u8 *)g_enemy_routines_high + (reg_d7.h[0] * 4)))();
        }
#endif
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0xC);
        if (reg_d0.b[0] & 1) {
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
            reg_d0.h[0] = g_side_scroll_x[0];
            reg_a6 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            ENTITY(reg_a6)->x.h -= reg_d0.h[0];
        }
        reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
        reg_d0.h[0] += 1;
        return;
    }
    *(u16 *)reg_a5 = 0;
}

extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
void enemy_request_start(void) {
    D_0028DF44 = reg_d0.w;
    D_0028DF40 = reg_d1.w;
    D_0028DF3C = reg_d2.sw;
    reg_d1.h[0] = 0x80;
    spawn_request_alloc();
}


void spawn_request_add(void) {
    D_0028DF40 = reg_d1.w;
    D_0028DF44 = reg_d0.w;
    D_0028DF3C = reg_d2.sw;
    *(u16 *)&reg_d1 = 0;
    spawn_request_alloc(reg_d0.w);
}


void enemy_request_start_flags(void) {
    D_0028DF44 = reg_d0.w;
    D_0028DF40 = reg_d1.w;
    D_0028DF3C = reg_d2.w;
    spawn_request_alloc(reg_d0.w);
}


void spawn_request_alloc() {
    reg_d2.h[0] = g_spawn_request_end;
    if (reg_d2.h[0] == 0xC80) goto next_1;
    reg_a0 = (u8 *)g_spawn_requests;
    reg_a0 += reg_d2.h[0];
    *(u16 *) (reg_a0 + 2) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 4) = reg_d1.h[0];
    *(s16 *) (reg_a0 + 0x12) = 0;
    *(s16 *) (reg_a0 + 0x14) = 0;
    reg_d2.h[0] += 0x50;
    g_spawn_request_end = reg_d2.h[0];
    reg_d0.w = D_0028DF44;
    reg_d1.w = D_0028DF40;
    reg_d2.w = D_0028DF3C;
    return;
next_1:
    reg_a0 = (u8 *)&g_spawn_request_spare;
    reg_d0.w = D_0028DF44;
    reg_d1.w = D_0028DF40;
    reg_d2.w = D_0028DF3C;
}



void enemy_slot_claim(void) {
    u32 sd0;
    u32 sd1;
    u32 sd2;
    u32 tmp;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    if (((s16) reg_d0.h[0] >= 0x20) && ((s16) reg_d0.h[0] < 0x24)) {
        reg_a0 = (u8 *)g_enemy_slots.slot.spawners;
        reg_d2.w = 7;
    } else if ((s16) reg_d1.h[0] < 0) {
        reg_a0 = (u8 *)g_enemy_slots.slot.large;
        reg_d2.w = 1;
    } else {
        reg_d3.w = 0;
        reg_a0 = (u8 *)g_enemy_slots.slot.others;
        reg_d2.w = 0x2F;
    }
loop_1:
    if (*(u16 *)(reg_a0 + 0) == 0) {
        reg_d3.h[0] |= 0x8000;
        *(u16 *)(reg_a0 + 0) = reg_d3.h[0];
        *(s16 *)(reg_a0 + 2) = 0;
        *(s16 *)(reg_a0 + 4) = 0;
        *(s16 *)(reg_a0 + 0xA) = 0;
        *(u8 *)(reg_a0 + 0xD) = reg_d0.b[0];
        *(u8 *)(reg_a0 + 0xC) = reg_d1.b[0];
        reg_d0.w = sd0;
        reg_d1.w = sd1;
        reg_d2.w = sd2;
        cond_flag = 0;
        return;
    }
    reg_a0 += 0x50;
    reg_d3.h[0] += 1;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_a0 = (u8 *)&g_enemy_slots.slot.none;
    cond_flag = 1;
}


void enemy_remove_now(void) {
    u8 *src = reg_a5;

    reg_tmp.h[1] = *(u16 *)(src + 6);
    reg_tmp.h[0] = *(u16 *)(src + 8);
    reg_d0.w = 0;
    reg_a6 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.sw);
    *(u16 *)&reg_d1 = *(u16 *)(src + 4);
    enemy_remove_entities();
}


void enemy_remove(void) {
    void *task = (void *)reg_a5;

    reg_tmp.h[1] = *(u16 *)((u8 *)task + 0x6);
    reg_tmp.h[0] = *(u16 *)((u8 *)task + 0x8);
    reg_d0.w = 1;
    reg_a6 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.sw);
    *(u16 *)&reg_d1 = *(u16 *)((u8 *)task + 0x4);
    enemy_remove_entities(task);
}

void enemy_remove_entities()
{
    do {
        ENTITY(reg_a6)->flags.b[1] = *(u8 *)&reg_d0;
        reg_a6 += 0x20;
    } while ((s16)(--reg_d1.h[0]) >= 0);

    *(u16 *)reg_a5 = 0;
}


void enemy_set_task_state(void)
{
    u32 savedCounter;
    u16 *savedSource;
    u16 *savedDestination;

    savedDestination = ((u16 *)reg_a1);
    savedCounter = reg_d0.w;
    savedSource = ((u16 *)reg_a0);
    (*(u16 **)&reg_a1) = (u16 *)(reg_a5 + 0x16);

    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0)++;
        (*(u16 **)&reg_a1)++;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = savedCounter;
    (*(u16 **)&reg_a0) = savedSource;
    (*(u16 **)&reg_a1) = savedDestination;
}



void enemy_init_entities(void) {
    reg_d7.h[0] = *(u16 *)(reg_a5 + 4);
    enemy_init_entities_n();
}

void enemy_init_entities_n(void) {
    reg_a1 = reg_a6;
loop_1:
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    if (*(s16 *) reg_a1 >= 0) {
        reg_a1 += 2;
        goto next_2;
    }
    reg_a1 += 6;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    return;
next_2:
    reg_a1[-1] |= 0x80;
    reg_a1 += 4;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d0.w = 0;
    *(u16 *) reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
}

extern void (*g_enemy_path_commands[12])();
extern u16 g_scroll_line_step;
extern s8 enemy_move_end_requested;

void enemy_path_start(void) {
    s8 t;

    enemy_move_end_requested = 0;
    reg_d0.h[1] = ENEMY_STATE(reg_a5)->path[0];
    reg_d0.h[0] = ENEMY_STATE(reg_a5)->path[1];
    if (reg_d0.w == 0) {
        enemy_remove_now();
        return;
    }
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
    if (ENEMY_STATE(reg_a5)->flags & ENEMY_FLAG_FROM_SPAWNER) {
        ENTITY(reg_a6)->y.h = ENEMY_STATE(reg_a5)->start_y;
        ENTITY(reg_a6)->x.h = ENEMY_STATE(reg_a5)->start_x;
        reg_d0.h[0] = g_side_scroll_x[0];
        ENTITY(reg_a6)->x.h += reg_d0.sh[0];
    } else {
        reg_d0.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_d0.b[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        ENTITY(reg_a6)->y.h = reg_d0.h[0];
        reg_tmp.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_tmp.b[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        ENTITY(reg_a6)->x.h = reg_tmp.h[0];
    }
    if ((s32) ENTITY(reg_a6)->x.b[1] >= 0x80) {
        ENTITY(reg_a6)->x.b[1] |= 0x80;
    }
before_first_move:
    t = *(s8 *)reg_a0;
    reg_d1.b[0] = t;
    if (t >= 0) goto first_move;
    reg_a0 += 1;
    if ((s32) reg_d1.b[0] >= 0xC0) {
        ENTITY(reg_a6)->move.sb.speed = *(s8 *)reg_a0;
        reg_a0 += 1;
        goto before_first_move;
    }
    enemy_move_end_requested = 0;
    reg_d1.h[0] &= 0xF;
#ifdef DDPDOJ_PC
    g_enemy_path_commands[reg_d1.h[0]]();
#else
    ((Fn)*(u32 *)((u8 *)g_enemy_path_commands + (reg_d1.h[0] * 4)))();
#endif
    if (enemy_move_end_requested == 0) goto before_first_move;
    return;
first_move:
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    ENEMY_STATE(reg_a5)->path[0] = (u16) reg_tmp.h[1];
    ENEMY_STATE(reg_a5)->path[1] = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_d0.h[0] = ENEMY_STATE(reg_a5)->line_step;
    reg_d0.h[0] -= g_scroll_line_step;
    reg_d0.h[0] &= 0x7F;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] >>= 7;
    reg_d0.h[0] |= ((s16) reg_tmp.h[0] << 9) & 0xFFFF;
    ENTITY(reg_a6)->x.h += reg_d0.h[0];
    ENTITY(reg_a6)->x.h -= 0x800;
    reg_d1.w = 0;
    ENEMY_STATE(reg_a5)->path_frames.h = (u16) reg_d1.h[0];
    ENEMY_STATE(reg_a5)->flags |= ENEMY_FLAG_NEW_STEP;
}

s32 entity_follow_scroll();
s32 entity_velocity();
extern u16 g_enemies_stopped;

void enemy_path_step(void) {
    u8 *p;
    s8 v;
    u8 c;

    enemy_move_end_requested = 0;
    if (g_enemies_stopped != 0) goto enemies_stopped;
    if (ENEMY_STATE(reg_a5)->start_flags & 1) {
        entity_follow_scroll();
    }
    reg_tmp.h[1] = ENEMY_STATE(reg_a5)->path[0];
    reg_tmp.h[0] = ENEMY_STATE(reg_a5)->path[1];
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
next_step:
    p = reg_a0;
    reg_a0 = p + 1;
    v = *(s8 *)p;
    reg_d1.b[0] = v;
    if (v < 0) goto not_a_move;
    p = reg_a0;
    reg_a0 = p + 1;
    v = *(s8 *)p;
    reg_d0.b[0] = v;
    if ((v & 0xFF) == 0) goto move_on;
    c = ENEMY_STATE(reg_a5)->path_frames.b[1];
    if (c == reg_d0.b[0]) goto step_done;
    ENEMY_STATE(reg_a5)->path_frames.b[1] = c + 1;
move_on:
    reg_d1.h[0] &= 0x7F;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    if ((s32)reg_d1.h[0] >= 0x40) goto stay;
    if (ENEMY_STATE(reg_a5)->flags & ENEMY_FLAG_NEW_STEP) goto new_speed;
    reg_d2.h[0] = ENEMY_STATE(reg_a5)->path_speed_y;
    reg_d3.h[0] = ENEMY_STATE(reg_a5)->path_speed_x;
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    cond_flag = 0;
    return;
new_speed:
    ENEMY_STATE(reg_a5)->flags &= 0xDF;
    entity_velocity();
    ENEMY_STATE(reg_a5)->path_speed_y = reg_d2.h[0];
    ENEMY_STATE(reg_a5)->path_speed_x = reg_d3.h[0];
    cond_flag = 0;
    return;
stay:
    reg_d2.w = 0;
    reg_d3.h[0] = reg_d2.h[0];
    cond_flag = 0;
    return;
step_done:
    ENEMY_STATE(reg_a5)->path_frames.b[1] = 0;
path_advanced:
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a0);
    ENEMY_STATE(reg_a5)->path[0] = reg_tmp.h[1];
    ENEMY_STATE(reg_a5)->path[1] = reg_tmp.h[0];
    ENEMY_STATE(reg_a5)->flags |= ENEMY_FLAG_NEW_STEP;
    goto next_step;
not_a_move:
    if ((s32)reg_d1.b[0] < 0xC0) goto command;
    ENTITY(reg_a6)->move.sb.speed = *(s8 *)reg_a0;
    reg_a0 += 1;
    goto path_advanced;
command:
    enemy_move_end_requested = 0;
    reg_d1.h[0] &= 0xF;
#ifdef DDPDOJ_PC
    g_enemy_path_commands[reg_d1.h[0]]();
#else
    ((Fn) *(u32 *)((u8 *)g_enemy_path_commands + reg_d1.h[0] * 4))();
#endif
    if (enemy_move_end_requested == 0) goto path_advanced;
    cond_flag = 0;
    return;
enemies_stopped:
    cond_flag = 0;
    reg_d2.w = 0;
    reg_d3.w = 0;
}

extern s8 *reg_a0_as_s8_p;

void enemy_path_loop(void) {
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 -= reg_d0.h[0];
}


void enemy_path_draw_layer(void) {
    ENTITY(reg_a6)->misc.sb.draw_layer = *(s8 *)reg_a0;
    reg_a0 += 1;
}


void enemy_path_ground_hits(void)
{
    reg_d0.b[0] = *reg_a0_as_s8_p++;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        ENTITY(reg_a6)->flags.b[1] &= 0xDF;
    } else {
        ENTITY(reg_a6)->flags.b[1] |= 0x20;
    }
}


void enemy_path_air_hits(void)
{
    reg_d0.b[0] = (u8)*reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        *(*(u16 **)&reg_a6) &= 0xDFFE;
    } else {
        *(*(u16 **)&reg_a6) |= 0x2001;
    }
}


void enemy_path_state_23(void) {
    *(s8 *)(reg_a5 + 0x23) = *(s8 *)reg_a0;
    reg_a0 += 1;
}


void enemy_path_poke_state(void) {
    s8 temp_a2;

    reg_d0.h[0] = 0;
    reg_d0.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.sb[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= 0xFF0;
    reg_d1.h[0] *= 0x10;
    temp_a2 = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.sb[1] = temp_a2;
    reg_d2.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= 0xFF0;
    reg_d2.h[0] >>= 4;
    reg_d1.h[0] += reg_d2.h[0];
    *(u16 *)(reg_a5 + ((s32) reg_d0.h[0] >> 1)) = reg_d1.h[0];
}

void enemy_path_poke_entity(void) {
    s8 temp_a2;

    reg_d0.h[0] = 0;
    reg_d0.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.sb[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= 0xFF0;
    reg_d1.h[0] *= 0x10;
    temp_a2 = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.sb[1] = temp_a2;
    reg_d2.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= 0xFF0;
    reg_d2.h[0] >>= 4;
    reg_d1.h[0] += reg_d2.h[0];
    *(u16 *)(reg_a6 + ((s32) reg_d0.h[0] >> 1)) = reg_d1.h[0];
}

void enemy_path_state_25(void) {
    *(s8 *)(reg_a5 + 0x25) = *(s8 *)reg_a0;
    reg_a0 += 1;
}

void enemy_path_user(void) {
    ENTITY(reg_a6)->misc.sb.user = *(s8 *)reg_a0;
    reg_a0 += 1;
}

void enemy_path_side_scroll(void) {
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    reg_a0 += 1;
}



void enemy_path_end(void) {
    enemy_move_end_requested = 1;
    enemy_remove();
}

void enemy_path_nothing(void) {

}

/* .data */
/* By stage: where the tables of its enemies are. */
StageEnemies g_stage_enemies[5] = {
    { g_stage1_enemy_placements, g_stage1_enemy_path_offsets, g_stage1_enemy_paths },
    { g_stage2_enemy_placements, g_stage2_enemy_path_offsets, g_stage2_enemy_paths },
    { g_stage3_enemy_placements, g_stage3_enemy_path_offsets, g_stage3_enemy_paths },
    { g_stage4_enemy_placements, g_stage4_enemy_path_offsets, g_stage4_enemy_paths },
    { g_stage5_enemy_placements, g_stage5_enemy_path_offsets, g_stage5_enemy_paths },
};

StageEnemies g_stage_boss_start_enemies[5] = {
    { g_stage1_boss_start_placements, g_stage1_enemy_path_offsets, g_stage1_enemy_paths },
    { g_stage2_boss_start_placements, g_stage2_enemy_path_offsets, g_stage2_enemy_paths },
    { g_stage3_boss_start_placements, g_stage3_enemy_path_offsets, g_stage3_enemy_paths },
    { g_stage4_boss_start_placements, g_stage4_enemy_path_offsets, g_stage4_enemy_paths },
    { g_stage5_boss_start_placements, g_stage5_enemy_path_offsets, g_stage5_enemy_paths },
};

/* The routines of the path commands 0x80 to 0x8B (the PATH_ macros of enemy_tables.h). */
void (*g_enemy_path_commands[12])() = {
    enemy_path_loop,
    enemy_path_draw_layer,
    enemy_path_ground_hits,
    enemy_path_air_hits,
    enemy_path_state_23,
    enemy_path_poke_state,
    enemy_path_poke_entity,
    enemy_path_state_25,
    enemy_path_user,
    enemy_path_side_scroll,
    enemy_path_end,
    enemy_path_nothing,
};

/* .sbss (the compiler lays these out in reverse) */
u32 D_0028DF44;
u32 D_0028DF40;
u32 D_0028DF3C;
