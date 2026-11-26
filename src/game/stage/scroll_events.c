#include "common.h"
#include "entity.h"
#include "ground.h"
#include "scenery.h"
#include "scroll_events.h"
#include "sdk/ps2sdk.h"

#ifndef DDPDOJ_PC
typedef void (*Fn)();
#else
typedef void (*Fn)(void);
#endif
void scroll_events_run_line(void);
extern u16 g_side_scroll_step[];
extern u16 g_stage;
extern u8 g_simulation_active;

extern u16 stage_scroll_event_lists[];
extern u16 g_stage_x4;

void scroll_event_lists_get(void) {
    reg_a0 = (u8 *)(stage_scroll_event_lists);
    reg_d0.h[0] = g_stage_x4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
}

extern ScenerySetup *stage_scenery_setups[5];

void scenery_reset(void) {
    memset(&g_scenery, 0, sizeof(SceneryState));
    reg_a0 = (u8 *)stage_scenery_setups;
#ifdef DDPDOJ_PC
    g_scenery.setups = stage_scenery_setups[g_stage_x4 / 4];
#else
    reg_a0 += g_stage_x4;
    g_scenery.setups = *(ScenerySetup **)reg_a0;
#endif
}

extern u8 g_ground_no_draw;
extern u8 *reg_call_target_as_u8_p;

void scenery_run(void) {
    u32 temp_s0;

    if ((g_simulation_active == 0) || (g_ground_no_draw == 0) || (g_stage != 2)) {
        reg_a6 = (u8 *)g_scenery.pieces;
        reg_d7.w = 7;
        do {
            if (SCENERY(reg_a6)->flags.b[1] != 0) {
                reg_d0.h[0] = g_side_scroll_step[0];
                SCENERY(reg_a6)->x.h -= reg_d0.h[0];
                reg_tmp.h[1] = SCENERY(reg_a6)->routine[0];
                reg_tmp.h[0] = SCENERY(reg_a6)->routine[1];
                reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
                reg_call_target_as_u8_p = reg_a1;
                temp_s0 = reg_d7.w;
                ((Fn)reg_call_target_as_u8_p)();
                reg_d7.w = temp_s0;
            }
            reg_a6 += sizeof(Scenery);
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

#ifndef DDPDOJ_PC
typedef void (*Fn)(void);
#endif


void scenery_start(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u32 t1;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a6 = (u8 *)g_scenery.pieces;
    reg_d7.w = 7;
loop_1:
    if (SCENERY(reg_a6)->flags.b[1] != 0) goto next_1;
    SCENERY(reg_a6)->flags.b[1] = 0x80;
    SCENERY(reg_a6)->y.h = reg_d1.h[1];
    SCENERY(reg_a6)->x.h = reg_d1.h[0];
    reg_a1 = (u8 *)g_scenery.setups;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
#ifdef DDPDOJ_PC
    reg_a1 = (u8 *)g_scenery.setups[reg_d0.h[0] / 4];
#else
    reg_a1 += reg_d0.h[0];
    reg_a1 = *(u8 **)reg_a1;
#endif
    reg_call_target = (Fn)reg_a1;
    reg_call_target();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
    return;
next_1:
    reg_a6 += sizeof(Scenery);
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) goto loop_1;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
}

extern u16 g_scroll_line;

void scroll_map_loop_step(void) {
    reg_a0 = (u8 *)&g_scroll_events.reader[0];
    reg_a1 = (u8 *)GROUND_TASK(reg_a5)->map_at;
    reg_tmp.h[1] = SCROLL_EVENT_READER(reg_a0)->loop_map[0];
    reg_tmp.h[0] = SCROLL_EVENT_READER(reg_a0)->loop_map[1];
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    if (reg_a2 == 0) return;
    SCROLL_EVENT_READER(reg_a0)->loop_rows_left -= 1;
    if (0 >= (s16) SCROLL_EVENT_READER(reg_a0)->loop_rows_left) {
        reg_d0.h[0] = SCROLL_EVENT_READER(reg_a0)->loop_times;
        if ((s16) reg_d0.h[0] != -1) {
            SCROLL_EVENT_READER(reg_a0)->loop_times -= 1;
            if (0 >= (s16) SCROLL_EVENT_READER(reg_a0)->loop_times) {
                SCROLL_EVENT_READER(reg_a0)->loop_map[0] = 0U;
                SCROLL_EVENT_READER(reg_a0)->loop_map[1] = 0U;
                GROUND_TASK(reg_a5)->line_held = 0;
                g_scroll_line = SCROLL_EVENT_READER(reg_a0)->line_after_loop;
                return;
            }
        }
        SCROLL_EVENT_READER(reg_a0)->loop_rows_left = (u16) SCROLL_EVENT_READER(reg_a0)->loop_length;
        reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
    }
}


void scroll_events_start(void) {
    u8 *var_a0;
    u32 temp_s0;
    u32 temp_s1;

    scroll_event_lists_get();
    memset(&g_scroll_events, 0, sizeof(ScrollEventsState));
    reg_a1 = (u8 *)&g_scroll_events.reader[0];
    reg_d1.w = 1;
    var_a0 = (u8 *)&g_scroll_events.reader[1];
    do {
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        SCROLL_EVENT_READER(reg_a1)->palettes[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        SCROLL_EVENT_READER(reg_a1)->palettes[1] = *(u16 *)reg_a2;
        reg_a2 += 2;
        SCROLL_EVENT_READER(reg_a1)->sounds[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        SCROLL_EVENT_READER(reg_a1)->sounds[1] = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
        SCROLL_EVENT_READER(reg_a1)->events[0] = (u16) reg_tmp.h[1];
        SCROLL_EVENT_READER(reg_a1)->events[1] = (u16) reg_tmp.h[0];
        reg_a1 = (u8 *)&g_scroll_events.reader[1];
    } while ((s16)(--reg_d1.h[0]) >= 0);
    if (g_scroll_line != 0) {
        g_scroll_events.replaying = 1;
        reg_tmp.h[1] = GROUND_TASK(reg_a5)->second_map_at[0];
        reg_tmp.h[0] = GROUND_TASK(reg_a5)->second_map_at[1];
        reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        temp_s0 = ARCADE_ADDRESS_ENCODE(reg_a3);
        reg_tmp.h[1] = GROUND_TASK(reg_a5)->map_at[0];
        reg_tmp.h[0] = GROUND_TASK(reg_a5)->map_at[1];
        reg_d7.w = 0;
        reg_a4 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        temp_s1 = ARCADE_ADDRESS_ENCODE(reg_a4);
        do {
            scroll_events_run_line();
            var_a0 = (u8 *) g_scroll_line;
            reg_d7.h[0] += 1;
        } while ((u32)var_a0 != reg_d7.h[0]);
        reg_tmp.w = temp_s0;
        reg_a4 = ARCADE_ADDRESS_DECODE(u8 *, temp_s1);
        reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, temp_s0);
        GROUND_TASK(reg_a5)->second_map_at[0] = (u16) reg_tmp.h[1];
        GROUND_TASK(reg_a5)->second_map_at[1] = (u16) reg_tmp.h[0];
        reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a4);
        GROUND_TASK(reg_a5)->map_at[0] = (u16) reg_tmp.h[1];
        GROUND_TASK(reg_a5)->map_at[1] = (u16) reg_tmp.h[0];
        reg_d0.w = 0;
        GROUND_TASK(reg_a5)->line_held = 0;
        g_scroll_events.reader[0].loop_map[0] = 0;
        g_scroll_events.reader[0].loop_map[1] = 0;
        g_scroll_events.reader[1].loop_map[0] = 0;
        g_scroll_events.reader[1].loop_map[1] = 0;
    }
    g_scroll_events.replaying = 0;
}


void scroll_events_run(void) {
    reg_d7.h[0] = g_scroll_line;
    scroll_events_run_line();
}

extern u8 scroll_event_routines[];

void scroll_events_run_line(void) {
    u16 temp_a0;
    reg_a6 = (u8 *)&g_scroll_events.reader[0];
    reg_d6.w = 1;
    do {
loop_1:
        reg_tmp.h[1] = SCROLL_EVENT_READER(reg_a6)->events[0];
        reg_tmp.h[0] = SCROLL_EVENT_READER(reg_a6)->events[1];
        reg_a1 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        reg_d1.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (((s16)(reg_d1.h[0]) != -1) && ((reg_d1.h[0] & 0xFFFF) == reg_d7.h[0])) {
            reg_a1 += 2;
            temp_a0 = *(u16 *)reg_a1;
            reg_d2.h[0] = temp_a0;
            reg_a1 += 2;
            reg_a2 = (u8 *)scroll_event_routines;
            reg_a2 += reg_d2.h[0];
            reg_tmp.h[1] = *(u16 *)reg_a2;
            reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
            reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
            reg_call_target = (Fn)(reg_a2);
            reg_call_target();
            reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a1);
            SCROLL_EVENT_READER(reg_a6)->events[0] = (u16) reg_tmp.h[1];
            SCROLL_EVENT_READER(reg_a6)->events[1] = (u16) reg_tmp.h[0];
            goto loop_1;
        }
        reg_a6 = (u8 *)&g_scroll_events.reader[1];
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.h[1] = g_scroll_events.sound_call[0];
    reg_d0.h[0] = g_scroll_events.sound_call[1];
    if (reg_d0.w != 0) {
        g_scroll_events.sound_call_frames -= 1;
        if (0 > (s16) g_scroll_events.sound_call_frames) {
            reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_d0.w);
            reg_call_target = (Fn)((u8 *) reg_a0);
            reg_call_target();
            *(u32 *)g_scroll_events.sound_call = 0;
        }
    }
}

s32 sprite_palette_load();

void scroll_event_palettes(void) {
    u16 temp_a1;

    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = SCROLL_EVENT_READER(reg_a6)->palettes[0];
    reg_tmp.h[0] = SCROLL_EVENT_READER(reg_a6)->palettes[1];
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
loop_1:
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1;
    reg_a2 += 2;
#ifdef DDPDOJ_PC
    if (reg_tmp.w != (u32)-1) {
        reg_a0 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
#else
    reg_a0 = (u8 *)reg_tmp.w;
    if ((u32)reg_a0 != -1U) {
#endif
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        sprite_palette_load();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
            SCROLL_EVENT_READER(reg_a6)->palettes[0] = (u16) reg_tmp.h[1];
            SCROLL_EVENT_READER(reg_a6)->palettes[1] = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void scroll_event_map_loop(void) {
    reg_a2 = (u8 *)GROUND_TASK(reg_a5)->second_map_at;
    if (reg_d6.h[0] != 0) {
        reg_a2 = (u8 *)GROUND_TASK(reg_a5)->map_at;
    }
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
    reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (s16) reg_d1.h[0] << 5;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] += reg_d0.h[0];
    reg_a3 += (s16) reg_d1.h[0];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a3);
    SCROLL_EVENT_READER(reg_a6)->loop_map[0] = (u16) reg_tmp.h[1];
    SCROLL_EVENT_READER(reg_a6)->loop_map[1] = (u16) reg_tmp.h[0];
    reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a3);
    *(u16 *)reg_a2 = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a2 + 2) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    SCROLL_EVENT_READER(reg_a6)->loop_length = (u16) reg_d0.h[0];
    reg_d0.h[0] += 1;
    SCROLL_EVENT_READER(reg_a6)->loop_rows_left = (u16) reg_d0.h[0];
    SCROLL_EVENT_READER(reg_a6)->loop_times = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
}


void scroll_event_speed(void) {
#ifdef DDPDOJ_PC
    reg_a2 = (u8 *)(reg_d6.h[0] != 0 ? &GROUND_TASK(reg_a5)->speed : &GROUND_TASK(reg_a5)->second_speed);
    *(u16 *)reg_a2 = *(u16 *)reg_a1;
    reg_a1 += 2;
#else
    (*(u16 **)&reg_a2) = &GROUND_TASK((*(s32 *)&reg_a5))->second_speed;
    if (reg_d6.h[0] != 0) {
        (*(u16 **)&reg_a2) = &GROUND_TASK((*(s32 *)&reg_a5))->speed;
    }
    *(*(u16 **)&reg_a2) = *((u16 *)reg_a1);
    (*(u16 **)&reg_a1) += 1;
#endif
}


void scroll_event_line_hold(void) {
    GROUND_TASK(reg_a5)->line_held = 1;
    reg_d0.h[0] = g_scroll_line;
    reg_d0.h[0] += 4;
    SCROLL_EVENT_READER(reg_a6)->line_after_loop = (u16) reg_d0.h[0];
}

extern u16 g_side_scroll_x_prev[];

void scroll_event_scenery(void) {
    u16 *temp_a0;
    u16 temp_a1;

    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    temp_a1 = *(u16 *)reg_a1;
    temp_a0 = ((u16 *)reg_a1) + 1;
    reg_d1.h[0] = temp_a1;
    reg_a1 = (u8 *)temp_a0;
    if (g_scroll_events.replaying == 0) {
        reg_d1.h[0] -= 0x800;
        reg_d1.h[0] -= g_side_scroll_x_prev[0];
        scenery_start();
    }
}

extern u8 scroll_sound_routines[];

void scroll_event_sounds(void) {
    u32 temp_a1;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = SCROLL_EVENT_READER(reg_a6)->sounds[0];
    reg_tmp.h[0] = SCROLL_EVENT_READER(reg_a6)->sounds[1];
    reg_a2 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a2;
    temp_a1 = reg_d0.h[0];
    reg_a2 += 2;
    if ((s16)(temp_a1) != -1) {
        reg_a3 = (u8 *)scroll_sound_routines;
        reg_d0.h[0] = temp_a1 + temp_a1;
        reg_d0.h[0] += reg_d0.h[0];
        reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_a3 = ARCADE_ADDRESS_DECODE(u8 *, reg_tmp.w);
        reg_call_target = (Fn)(reg_a3);
        reg_call_target();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = ARCADE_ADDRESS_ENCODE(reg_a2);
            SCROLL_EVENT_READER(reg_a6)->sounds[0] = (u16) reg_tmp.h[1];
            SCROLL_EVENT_READER(reg_a6)->sounds[1] = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void scroll_sound_call(void) {
    g_scroll_events.sound_call_frames = *(u16 *)reg_a2;
    reg_a2 += 2;
    g_scroll_events.sound_call[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    g_scroll_events.sound_call[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
}

void music_stop(void);

void scroll_sound_music_stop(void) {
    music_stop();
}

extern void music_fade_out(void);

void scroll_sound_music_fade(void) {
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    music_fade_out();
}

extern s16 g_bullet_limit_raised_1[];
extern s16 g_bullet_limit_raised_2[];
extern s16 g_bullet_limit_raised_3_as_s16_a[];
extern u16 g_bullets_clear_request[];

void scroll_event_flags(void) {
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (reg_d0.h[0] == 1) {
        g_bullet_limit_raised_1[0] = 1;
    }
    if (reg_d0.h[0] == 2) {
        g_bullet_limit_raised_1[0] = 1;
        g_bullet_limit_raised_2[0] = 1;
    }
    if (reg_d0.h[0] == 3) {
        g_bullet_limit_raised_1[0] = 1;
        g_bullet_limit_raised_2[0] = 1;
        g_bullet_limit_raised_3_as_s16_a[0] = 1;
    }
    if (reg_d0.h[0] == 4) {
        g_bullet_limit_raised_1[0] = 1;
        g_bullet_limit_raised_2[0] = 1;
        g_bullet_limit_raised_3_as_s16_a[0] = 1;
        ((s16 *)g_bullets_clear_request)[0] = 1;
    }
}

/* .bss (the compiler lays these out in reverse) */
ScrollEventsState g_scroll_events;
GroundState g_ground_state;  /* the ground unit's; it lies inside this unit's block */
SceneryState g_scenery;

#ifdef DDPDOJ_PC
#include "pc_data_alias.h"

PC_DATA_ALIAS(g_side_scroll_x_prev, g_ground_state, 0x6);
PC_DATA_ALIAS(g_side_scroll_x, g_ground_state, 0x8);
PC_DATA_ALIAS(g_side_scroll_pixels, g_ground_state, 0xa);
PC_DATA_ALIAS(g_side_scroll_step, g_ground_state, 0xc);
PC_DATA_ALIAS(g_ground_map_row, g_ground_state, 0x1c);
PC_DATA_ALIAS(g_ground_map_row_offset, g_ground_state, 0x1e);
#endif
