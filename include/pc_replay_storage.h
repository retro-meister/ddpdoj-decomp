#ifndef DDPDOJ_PC_REPLAY_STORAGE_H
#define DDPDOJ_PC_REPLAY_STORAGE_H

#include "types.h"

/* Score cells embed text addresses from the corresponding PS2 executable. */
#ifdef DEATH_LABEL
#define REPLAY_TEXT_PS2_BASE 0x2faed0u
#else
#define REPLAY_TEXT_PS2_BASE 0x2b4d50u
#endif

enum {
    PC_REPLAY_FILE_SIZE = 0x202E8,
    PC_REPLAY_CARD_SIZE = 0x206EC,
    PC_REPLAY_STORAGE_SIZE = 0x202F0,
    PC_REPLAY_BODY_OFFSET = 0x400,
};

/* The PS2 linker placed these replay sections next to each other. The views
 * below keep the original offsets and backing bytes on both desktop linkers. */
typedef union {
    u8 bytes[PC_REPLAY_STORAGE_SIZE];
    u16 halfwords[PC_REPLAY_STORAGE_SIZE / 2];
    s32 words[PC_REPLAY_STORAGE_SIZE / 4];
} PcReplayStorage;

extern PcReplayStorage pc_replay;
extern u8 g_replay_file_loaded[PC_REPLAY_CARD_SIZE];

#define g_replay_file (pc_replay.bytes)
#define D_006C58A2 (pc_replay.halfwords + 0x2 / sizeof(u16))
#define g_replay_file_kind (pc_replay.halfwords + 0x4 / sizeof(u16))
#define D_006C58A6 (pc_replay.halfwords + 0x6 / sizeof(u16))
#define D_006C58A8 (pc_replay.halfwords + 0x8 / sizeof(u16))
#define D_006C58AA (pc_replay.halfwords + 0xA / sizeof(u16))
#define D_006C58AC (pc_replay.halfwords + 0xC / sizeof(u16))
#define D_006C58AE (pc_replay.halfwords + 0xE / sizeof(u16))
#define D_006C58B0 (pc_replay.halfwords + 0x10 / sizeof(u16))
#define D_006C58B2 (pc_replay.halfwords + 0x12 / sizeof(u16))
#define D_006C58B4 (pc_replay.halfwords + 0x14 / sizeof(u16))
#define D_006C58B6 (pc_replay.halfwords + 0x16 / sizeof(u16))
#define D_006C58B8 (pc_replay.halfwords + 0x18 / sizeof(u16))
#define D_006C58BA (pc_replay.halfwords + 0x1A / sizeof(u16))
#define D_006C58BC (pc_replay.halfwords + 0x1C / sizeof(u16))
#define D_006C58BE (pc_replay.halfwords + 0x1E / sizeof(u16))
#define D_006C58C0 (pc_replay.halfwords + 0x20 / sizeof(u16))
#define D_006C58C2 (pc_replay.halfwords + 0x22 / sizeof(u16))
#define D_006C58C4 (pc_replay.bytes + 0x24)
#define D_006C58C6 (pc_replay.halfwords + 0x26 / sizeof(u16))
#define D_006C58C8 (pc_replay.halfwords + 0x28 / sizeof(u16))
#define D_006C58CA (pc_replay.halfwords + 0x2A / sizeof(u16))
#define D_006C58CC (pc_replay.halfwords + 0x2C / sizeof(u16))
#define D_006C58CE (pc_replay.halfwords + 0x2E / sizeof(u16))
#define D_006C58D0 (pc_replay.halfwords + 0x30 / sizeof(u16))
#define D_006C58D2 (pc_replay.halfwords + 0x32 / sizeof(u16))
#define D_006C58D4 (pc_replay.halfwords + 0x34 / sizeof(u16))
#define D_006C58D6 (pc_replay.halfwords + 0x36 / sizeof(u16))
#define g_replay_file_id_0 (pc_replay.bytes + 0x38)
#define g_replay_file_id_1 (pc_replay.bytes + 0x39)
#define g_replay_file_id_2 (pc_replay.bytes + 0x3A)
#define g_replay_file_id_3 (pc_replay.bytes + 0x3B)
#define g_replay_file_id_4 (pc_replay.bytes + 0x3C)
#define g_replay_file_id_5 (pc_replay.bytes + 0x3D)
#define g_replay_file_id_6 (pc_replay.bytes + 0x3E)
#define g_replay_file_id_7 (pc_replay.bytes + 0x3F)
#define g_replay_snapshot (pc_replay.bytes + PC_REPLAY_BODY_OFFSET)
#define D_006C68B6 (pc_replay.bytes + 0x1016)
#define D_006C6918 (pc_replay.bytes + 0x1078)
#define D_006C8E56 (pc_replay.halfwords + 0x35B6 / sizeof(u16))
#define D_006C8E5C (pc_replay.halfwords + 0x35BC / sizeof(u16))
#define D_006C8E88 (pc_replay.words + 0x35E8 / sizeof(s32))
#define replay_playback_start_buffer (pc_replay.halfwords + 0x35F0 / sizeof(u16))
#define D_006C8E94 (pc_replay.halfwords + 0x35F4 / sizeof(u16))
#define replay_playback_start_buffer_2 (pc_replay.halfwords + 0x3900 / sizeof(u16))
#define D_006C91AC (pc_replay.bytes + 0x390C)
#define D_006C91AD (pc_replay.bytes + 0x390D)
#define D_006C91AE (pc_replay.bytes + 0x390E)
#define D_006C91AF (pc_replay.bytes + 0x390F)
#define replay_playback_start_buffer_3 (pc_replay.bytes + 0x3910)
#define g_replay_start_state (pc_replay.bytes + 0x5934)
#define D_006CB578 (pc_replay.halfwords + 0x5CD8 / sizeof(u16))
#define D_006CB57A (pc_replay.halfwords + 0x5CDA / sizeof(u16))
#define D_006CB57C (pc_replay.halfwords + 0x5CDC / sizeof(u16))
#define D_006CB57E (pc_replay.halfwords + 0x5CDE / sizeof(u16))
#define D_006CB580 (pc_replay.halfwords + 0x5CE0 / sizeof(u16))
#define D_006CB582 (pc_replay.halfwords + 0x5CE2 / sizeof(u16))
#define g_replay_file_checksum (pc_replay.words + 0x5CE4 / sizeof(s32))
#define death_D_002B1ED8 (pc_replay.bytes + 0x5CE8)
#define D_006CB588 (pc_replay.bytes + 0x5CE8)
#define g_replay_inputs (pc_replay.bytes + 0x5D08)
#define D_006A4C00 (g_replay_file_loaded + PC_REPLAY_BODY_OFFSET)

#endif
