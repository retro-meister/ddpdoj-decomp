#include "common.h"
#include "fade.h"
#include "entity.h"

void stage_doors_close_update(void);
void stage_doors_open_update(void);


void stage_door_record_copy(void) {
    (*(u16 **)&reg_a1) = ((u16 *)reg_a6);
    reg_d0.h[0] = 0xF;
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}


void stage_door_words_copy(void) {
    (*(u16 **)&reg_a1) = ((u16 *)reg_a4);
    do {
        *(*(u16 **)&reg_a1) = *((u16 *)reg_a0);
        (*(u16 **)&reg_a0) += 1;
        (*(u16 **)&reg_a1) += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 velocity_from_direction();

void stage_door_move_a(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->hp.h;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) ENTITY(reg_a6)->hit_y_plus.h > (s32) reg_d0.h[0]) {
        ENTITY(reg_a6)->hp.h >>= 1;
        ENTITY(reg_a6)->hit_y_plus.h >>= 1;
        reg_d0.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        if (ENTITY(reg_a6)->misc.sh > (s16) reg_d0.h[0]) {
            ENTITY(reg_a6)->y.h = 0x3800U;
            ENTITY(reg_a6)->hit_y_plus.h = 0U;
            *(u16 *)reg_a4 -= 1;
        }
    }
}

void stage_door_move_b(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->hp.h;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) ENTITY(reg_a6)->hit_y_plus.h > (s32) reg_d0.h[0]) {
        ENTITY(reg_a6)->hp.h >>= 1;
        ENTITY(reg_a6)->hit_y_plus.h >>= 1;
        reg_d0.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        if (ENTITY(reg_a6)->misc.sh > (s16) reg_d0.h[0]) {
            ENTITY(reg_a6)->x.h = (u16) ENTITY(reg_a6)->hit_x_minus.h;
            ENTITY(reg_a6)->hit_y_plus.h = 0U;
            *(u16 *)reg_a4 -= 1;
        }
    }
}

s32 entity_draw_with_bullets_keep();
s32 sprite_draw_with_bullets_keep();

void stage_door_draw_a(void) {
    entity_draw_with_bullets_keep();
    reg_d0.h[0] = 0x3800;
    reg_d0.h[0] -= ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += ENTITY(reg_a6)->offset_x.h;
    reg_d1.h[1] += ENTITY(reg_a6)->offset_y.h;
    reg_d1.h[1] += reg_d0.h[0];
    reg_d2.h[1] = ENTITY(reg_a6)->draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_d3.h[0] = ENTITY(reg_a6)->look.h;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d2.w = 0x11C6;
    sprite_draw_with_bullets_keep();
}

void stage_door_draw_b(void) {
    entity_draw_with_bullets_keep();
    reg_d0.h[0] = 0x3800;
    reg_d0.h[0] -= ENTITY(reg_a6)->y.h;
    reg_d0.h[1] = 0x1C00;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[1] -= ENTITY(reg_a6)->x.h;
    reg_d0.h[1] += reg_d0.h[1];
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += ENTITY(reg_a6)->offset_x.h;
    reg_d1.h[0] += reg_d0.h[1];
    reg_d1.h[1] += ENTITY(reg_a6)->offset_y.h;
    reg_d1.h[1] += reg_d0.h[0];
    reg_d2.h[1] = ENTITY(reg_a6)->draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_d3.h[0] = ENTITY(reg_a6)->look.h;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d2.w = 0x11C4;
    sprite_draw_with_bullets_keep();
}

extern s16 D_0028E798;
extern s16 D_0028E79C;
extern s16 D_0028E7A0;
extern s32 D_002BB458[];
extern s16 D_002BB45A[];
extern s16 D_002BB45C[];
extern s16 D_002BB45E[];
extern s16 stage_doors_clear_buffer[];
extern u8 D_002BB470[];
void stage_doors_clear(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BB470 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x40);
    D_0028E798 = 0;
    ((s16 *)D_002BB458)[0] = 0;
    D_0028E79C = 0;
    D_002BB45A[0] = 0;
    D_0028E7A0 = 0;
    D_002BB45C[0] = 0;
    D_002BB45E[0] = 0;
    stage_doors_clear_buffer[0] = 0;
}

void stage_doors_close_request(void) {
    D_0028E798 = 1;
}

void stage_doors_open_request(void) {
    D_0028E7A0 = 1;
}


void stage_doors_open_requested_check(void) {
    if ((u16)D_0028E7A0 != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern s32 D_002BB458[];

void stage_doors_update(void) {
    reg_a6 = (u8 *)((s32 *)D_002BB470);
    reg_a4 = (u8 *)D_002BB458;
    if ((u16)D_0028E79C != 0) {
        stage_doors_close_update();
        return;
    }
    if ((u16)D_0028E7A0 != 0) {
        stage_doors_open_update();
    }
}

s32 sprite_palette_load();
extern u8 stage_doors_close_update_table[];
extern u8 stage_doors_close_update_table_2[];
extern u8 stage_doors_close_update_table_3[];
extern s32 stage_doors_close_update_table_4;
extern u16 g_stage_x2;

void stage_doors_close_update(void) {
    s32 temp_a1;
    s32 var_v0;
    u16 temp_a2;

    if (ENTITY(reg_a6)->flags.sh >= 0) {
        reg_a0 = (u8 *)stage_doors_close_update_table_2;
        stage_door_record_copy();
        reg_a0 = (u8 *)stage_doors_close_update_table_3;
        var_v0 = (s32) stage_doors_close_update_table_4 >> 1;
        if (stage_doors_close_update_table_4 < 0) {
            var_v0 = (s32) (stage_doors_close_update_table_4 + 1) >> 1;
        }
        reg_d0.w = var_v0 - 1;
        stage_door_words_copy();
        reg_d0.h[0] = g_stage_x2;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(stage_doors_close_update_table + temp_a1);
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)palette_white;
        sprite_palette_load();
        return;
    }
    if (*(u16 *)reg_a4 == 0) {
        if ((u16)D_0028E798 != 0) {
            *(s16 *)(reg_a4 + 2) = 1;
            D_0028E79C = 0;
            ENTITY(reg_a6)->flags.sh = 0;
            return;
        }
        reg_d1.w = 0;
        reg_d2.w = 0x10AA;
        reg_d3.h[0] = ENTITY(reg_a6)->look.h;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_with_bullets_keep();
        return;
    }
    if (ENTITY(reg_a6)->hit_y_plus.h != 0) {
        stage_door_move_a();
    }
    stage_door_draw_a();
    reg_a6 += 0x20;
    if (ENTITY(reg_a6)->hit_y_plus.h != 0) {
        stage_door_move_b();
    }
    stage_door_draw_b();
}

s32 p1_hyper_items_update();
s32 p2_hyper_items_update();
extern u8 stage_doors_open_update_table[];
extern u8 stage_doors_open_update_table_2[];
extern u8 stage_doors_open_update_table_3[];
extern u8 g_game_frame_ran;
extern u16 g_boss_hyper_wait;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_stage;
extern u8 g_replay_start_pending;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern s16 g_player2[];
extern s16 g_player1[];

void stage_doors_open_update(void) {
    s32 temp_a1;
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 var_a0;
    u8 *var_a0_2;

    if (ENTITY(reg_a6)->flags.sh >= 0) {
        reg_a0 = (u8 *)stage_doors_open_update_table_2;
        stage_door_record_copy();
        reg_a0 = (u8 *)stage_doors_open_update_table_3;
        reg_d0.w = 1;
        stage_door_words_copy();
        reg_d0.h[0] = g_stage_x2;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(stage_doors_open_update_table + temp_a1);
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)palette_white;
        sprite_palette_load();
    }
    var_a0 = 1;
    if (*(u16 *)reg_a4 == 0) {
        *(s16 *)(reg_a4 + 2) = 1;
        g_boss_hyper_wait = 0;
        if ((g_replay_mode != 2) || (g_stage != 0)) {
            if ((g_player1[0] < 0) && (g_p1_hyper_active == 0)) {
                p1_hyper_items_update();
            }
            if ((g_player2[0] < 0) && (g_p2_hyper_active == 0)) {
                p2_hyper_items_update();
            }
        }
        D_0028E7A0 = 0;
        ENTITY(reg_a6)->flags.sh = 0;
        return;
    }
    if ((g_game_frame_ran != 0) && ((var_a0 = g_replay_mode, (var_a0 != 2)) || (g_replay_start_pending == 0)) && ((g_simulation_active == 0) || (g_replay_start_pending == 0))) {
        var_a0 = ENTITY(reg_a6)->hit_y_plus.h;
        if (var_a0 != 0) {
            temp_v1 = ENTITY(reg_a6)->hit_y_minus.h;
            if (temp_v1 != 0) {
                ENTITY(reg_a6)->hit_y_minus.h = (u16) (temp_v1 - 1);
                goto block_25;
            }
            if (var_a0 != 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
                velocity_from_direction();
                ENTITY(reg_a6)->y.h += reg_d2.h[0];
                reg_d2.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    ENTITY(reg_a6)->hit_y_plus.sh = 0;
                    *(u16 *)reg_a4 -= 1;
                }
                goto block_25;
            }
        }
    } else {
block_25:
        stage_door_draw_a();
    }
    var_a0_2 = (u8 *)(reg_a6 + 0x20);
    reg_a6 = var_a0_2;
    if ((g_game_frame_ran != 0) && ((var_a0_2 = (void *) g_replay_mode, (var_a0_2 != (void *)2)) || (g_replay_start_pending == 0)) && ((g_simulation_active == 0) || (g_replay_start_pending == 0))) {
        temp_a0 = ENTITY(reg_a6)->hit_y_plus.h;
        if (temp_a0 != 0) {
            temp_v1_2 = ENTITY(reg_a6)->hit_y_minus.h;
            if (temp_v1_2 != 0) {
                ENTITY(reg_a6)->hit_y_minus.h = (u16) (temp_v1_2 - 1);
                goto block_35;
            }
            if (temp_a0 != 0) {
block_35:
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                velocity_from_direction();
                ENTITY(reg_a6)->x.h += reg_d3.h[0];
                var_a0_2 = (u8 *)(reg_a6);
                reg_d2.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (0x16)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (4)));
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    (*(u16 *)((u8 *)(var_a0_2) + (0x10))) = 0U;
                    *(u16 *)reg_a4 -= 1;
                }
                goto block_39;
            }
        }
    } else {
block_39:
        stage_door_draw_b();
    }
}

u8 stage_doors_close_update_table[16] = {
    0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage_doors_close_update_table_2[64] = {
    0x00, 0x80, 0x00, 0xA8, 0x00, 0x1C, 0x00, 0xC8, 0x00, 0xE4, 0x00, 0x00, 0xC5, 0x11, 0xE0, 0x38,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x30, 0x40, 0x14, 0x40, 0x00, 0x30, 0x20, 0x00, 0x00, 0x00, 0x08,
    0x00, 0x80, 0x00, 0x00, 0x40, 0x54, 0x00, 0xC8, 0x00, 0xE4, 0x00, 0x00, 0xC3, 0x11, 0xE0, 0x38,
    0x00, 0x20, 0x00, 0x00, 0x00, 0x30, 0x40, 0x14, 0x40, 0x00, 0x30, 0x20, 0x00, 0x00, 0x00, 0x08,
};

u8 stage_doors_open_update_table[16] = {
    0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

u8 stage_doors_open_update_table_2[64] = {
    0x00, 0x80, 0x00, 0x38, 0x00, 0x1C, 0x00, 0xC8, 0x00, 0xE4, 0x00, 0x00, 0xC5, 0x11, 0xE0, 0x38,
    0x00, 0x20, 0x10, 0x00, 0x00, 0xB0, 0x00, 0x5C, 0x40, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x04,
    0x00, 0x80, 0x00, 0x38, 0x40, 0x1C, 0x00, 0xC8, 0x00, 0xE4, 0x00, 0x00, 0xC3, 0x11, 0xE0, 0x38,
    0x00, 0x20, 0x08, 0x00, 0x00, 0xB0, 0x00, 0x5C, 0x40, 0x00, 0x10, 0x00, 0x01, 0x00, 0x00, 0x04,
};

u8 stage_doors_close_update_table_3[8] = {
    0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
};

u8 stage_doors_open_update_table_3[8] = {
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

/* .sbss (the compiler lays these out in reverse) */
s16 D_0028E7A0 __attribute__((aligned(4)));
s16 D_0028E79C __attribute__((aligned(4)));
s16 D_0028E798 __attribute__((aligned(4)));
