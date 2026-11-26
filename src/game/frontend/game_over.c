#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"
void scroll_events_run_line(void);
extern u16 g_side_scroll_step[];
s32 task_stop_self();
extern u16 g_stage;
extern u8 g_replay_mode;

s32 scroll_state_reset();
s32 text_layer_clear();
s32 bg_layer_clear();
s32 fade_in_and_release(s32, s32, s32, s32);
s32 stage_map_reset();
extern u8 D_0026A3F0[];
extern u8 D_0028E368;
extern u8 D_0028E378;
extern u8 g_replay_buffer_state;

void game_over_task_begin(void) {
    g_replay_buffer_state = 2;
    D_0028E378 = 0xFF;
    D_0028E368 = 0;
    scroll_state_reset();
    text_layer_clear();
    bg_layer_clear();
    stage_map_reset();
    *(s8 *)(reg_a5 + 3) = 1;
    *(s16 *)(reg_a5 + 8) = 0x4400;
    *(s16 *)(reg_a5 + 0xA) = 0x1C00;
    *(s16 *)(reg_a5 + 0x14) = 0;
    *(s16 *)(reg_a5 + 0x12) = 0;
    *(s16 *)(reg_a5 + 0x10) = 0;
    *(s8 *)(reg_a5 + 0x17) = 1;
    *(s8 *)(reg_a5 + 0x16) = 0;
    *(s16 *)(reg_a5 + 0x18) = 0;
    *(s16 *)(reg_a5 + 4) = 0x1E0;
    reg_a0 = D_0026A3F0;
    fade_in_and_release(0x1E0, 0x1C00, 0x4400, 1);
    *(s16 *)(reg_a5 + 0x1A) = 0x20;
    *(s16 *)(reg_a5 + 0x1C) = 0x20;
}

s32 player_slot_request();
s32 fades_reset();
s32 task_start();

void game_over_task_wait() {
    *(u16 *)(reg_a5 + 0x1C) -= 1;
    if (*(u16 *)(reg_a5 + 0x1C) == 0) {
        reg_d0.w = 0;
        reg_d1.h[0] = 6;
        player_slot_request();
        fades_reset();
        reg_d0.h[0] = 0xC;
        task_start();
        task_stop_self();
    }
}

s32 replay_save_wanted_check();
s32 music_play_bgm12();
s32 sprite_draw_layer1();
s32 rng_next_masked();
s32 replay_file_finalize();
s32 replay_start_result();
extern u16 D_0026A380[];
extern u16 D_0026A3A0[];
extern u16 D_0026A3C0[];
extern u8 D_0028ED64;
extern u8 g_simulation_active;

void game_over_task(void) {
    u16 t;
    u8 st;

    st = *(u8 *)(reg_a5 + 3);
    if (st == 0) {
        game_over_task_begin();
        return;
    }
    if (st == 2) {
        if ((D_0028ED64 != 0) && (replay_save_wanted_check(reg_a5) != 0)) {
            if (replay_file_finalize() == 0) {
                return;
            }
            goto block_1;
        }
        if ((g_replay_mode == 2) || (g_simulation_active != 0)) {
            replay_start_result();
            return;
        }
block_1:
        g_replay_mode = 0;
        game_over_task_wait();
        return;
    }
    t = *(u16 *)(reg_a5 + 0x1A);
    if (t == 0) goto next_1;
    *(u16 *)(reg_a5 + 0x1A) = t - 1;
    if (*(u16 *)(reg_a5 + 0x1A) != 0) goto next_1;
    music_play_bgm12();
next_1:
    *(u16 *)(reg_a5 + 4) -= 1;
    if ((s16) *(u16 *)(reg_a5 + 4) >= 0) goto next_2;
    *(u8 *)(reg_a5 + 3) = 2;
next_2:
    if (*(u16 *)(reg_a5 + 0x10) != 0) goto next_6;
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_3;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d1.h[0] != 0x1C) goto next_3;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u16 *)(reg_a5 + 0x18) += 1;
    if (*(u16 *)(reg_a5 + 0x18) == 0x14) goto next_5;
    rng_next_masked();
    reg_d0.h[0] >>= 3;
    st = reg_d0.b[0];
    *(u8 *)(reg_a5 + 0x17) = st;
    if (st != 0) goto next_3;
    *(u8 *)(reg_a5 + 0x16) += 1;
    if ((s32) *(u8 *)(reg_a5 + 0x16) < 3) goto next_3;
    *(u8 *)(reg_a5 + 0x17) = 1;
next_3:
    reg_a0 = (u8 *)(D_0026A380);
    if (*(u8 *)(reg_a5 + 0x17) != 0) goto next_4;
    reg_a0 = (u8 *)(D_0026A3A0);
next_4:
    *(u16 *)(reg_a5 + 0xC) = ((reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    goto next_8;
next_5:
    *(u16 *)(reg_a5 + 0x10) = 1;
    *(u16 *)(reg_a5 + 0x14) = 0;
next_6:
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x12);
    *(u8 *)(reg_a5 + 0x15) -= 1;
    if ((s8) *(u8 *)(reg_a5 + 0x15) >= 0) goto next_8;
    *(u8 *)(reg_a5 + 0x15) = *(u8 *)(reg_a5 + 0x14);
    *(u16 *)(reg_a5 + 0x12) += 4;
    if (reg_d0.h[0] != 0x1C) goto next_7;
    *(u16 *)(reg_a5 + 0x12) = 0;
    *(u8 *)(reg_a5 + 3) = 2;
next_7:
    reg_a0 = (u8 *)(D_0026A3C0);
    *(u16 *)(reg_a5 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a5 + 0xE) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
next_8:
    reg_d1.h[1] = *(u16 *)(reg_a5 + 8);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d1.w += 0xE600E400;
    reg_d2.h[1] = *(u16 *)(reg_a5 + 0xC);
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0xE);
    reg_d3.h[0] = 0x1AE0;
    reg_d4.h[0] = 2;
    sprite_draw_layer1();
}

u16 D_0026A380[16] = {
    0x11C7, 0x0000, 0x11C8, 0x0000, 0x11C9, 0x0000, 0x11CA, 0x0000,
    0x11CB, 0x0000, 0x11CC, 0x0000, 0x11CE, 0x0000, 0x11CF, 0x0000,
};

u16 D_0026A3A0[16] = {
    0x11C7, 0x0000, 0x11C8, 0x0000, 0x11C9, 0x0000, 0x11CA, 0x0000,
    0x11CB, 0x0000, 0x11CD, 0x0000, 0x11CE, 0x0000, 0x11CF, 0x0000,
};

u16 D_0026A3C0[24] = {
    0x11D0, 0x0000, 0x11D1, 0x0000, 0x11D2, 0x0000, 0x11D3, 0x0000,
    0x11D4, 0x0000, 0x11D5, 0x0000, 0x11D6, 0x0000, 0x11D7, 0x0000,
    0x11D8, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
};

u8 D_0026A3F0[16] = {
    0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x04, 0x00, 0x05, 0x00, 0x1F, 0x00, 0x05, 0x00,
};
