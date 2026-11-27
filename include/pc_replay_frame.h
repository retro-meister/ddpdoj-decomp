#ifndef DDPDOJ_PC_REPLAY_FRAME_H
#define DDPDOJ_PC_REPLAY_FRAME_H

#include "pc_replay_storage.h"
#include "replay.h"
#include <stdbool.h>

typedef struct {
    PcReplayStorage recording;
    u8 loaded_file[PC_REPLAY_CARD_SIZE];
    ReplayHeader header, header_saved;
    u32 replay_fade_id;
    u8 simulation_active;
    u8 replay_mode;
    u8 replay_mode_begun;
    u8 replay_buffer_state;
    s32 replay_position;
    u8 replay_begin_pending;
    u8 replay_watch_after_run;
    u8 game_over_after_continue;
    u8 stage_clear_screen_shown;
    u8 replay_start_pending;
    u8 replay_taken_over;
    u16 replay_start_p1_score_digits;
    s32 replay_start_p1_score;
    u16 replay_start_p1_score_billions;
    u16 replay_start_p2_score_digits;
    s32 replay_start_p2_score;
    u16 replay_start_p2_score_billions;
    s32 replay_checksum;
} PcReplayFrame;

void pc_replay_frame_capture(PcReplayFrame *state);
bool pc_replay_frame_restore(const PcReplayFrame *state);

#endif
