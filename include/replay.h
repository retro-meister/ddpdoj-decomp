#ifndef DDPDOJ_REPLAY_H
#define DDPDOJ_REPLAY_H

#include "types.h"

/* What a replay starts from: ships, difficulty and the state of the run at the recorded stage. 0x42 bytes. */
typedef struct {
    /* 0x00 */ u16 unk00;
    /* 0x02 */ u16 p1_type;
    /* 0x04 */ u16 p1_doll;
    /* 0x06 */ u16 p2_type;
    /* 0x08 */ u16 p2_doll;
    /* 0x0A */ u16 difficulty;
    /* 0x0C */ u16 round;
    /* 0x0E */ u16 stage;
    /* 0x10 */ u16 unk10[2];
    /* 0x14 */ u16 max_bomb;
    /* 0x16 */ u16 stock_bomb;
    /* 0x18 */ u16 start;
    /* 0x1A */ u16 death;
    /* 0x1C */ u16 hyper_stock;
    /* 0x1E */ u16 hyper_gauge;
    /* 0x20 */ u16 rank;
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u16 bullet;
    /* 0x26 */ u16 unk26[2];
    /* 0x2A */ u16 unk2A;
    /* 0x2C */ u16 unk2C;
    /* 0x2E */ u16 unk2E[10];
} ReplayHeader;

typedef char ReplayHeaderSizeCheck[sizeof(ReplayHeader) == 0x42 ? 1 : -1];

extern ReplayHeader g_replay_header;       /* of the replay being recorded or played */
extern ReplayHeader g_replay_header_saved; /* copy taken when recording starts */

void replay_header_print(ReplayHeader *header);
void replay_header_clear(void);
void replay_header_save(void);
void replay_header_apply(void);

#endif
