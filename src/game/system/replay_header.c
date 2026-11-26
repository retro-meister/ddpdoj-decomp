#include "common.h"
#include "sdk/ps2sdk.h"
#include "replay.h"

void replay_header_print(ReplayHeader *header) {
    printf("fig1p type[%d] doll[%d] \n", header->p1_type, header->p1_doll);
    printf("fig2p type[%d] doll[%d] \n", header->p2_type, header->p2_doll);
    printf("difficulty[%d]\n", header->difficulty);
    printf("round[%d]\n", header->round);
    printf("stage[%d]\n", header->stage);
    printf("rank[%d]\n", header->rank);
    printf("max bom[%d]\n", header->max_bomb);
    printf("stock bom[%d]\n", header->stock_bomb);
    printf("hyper stock[%d]\n", header->hyper_stock);
    printf("hyper gage[%d]\n", header->hyper_gauge);
    printf("start[%d]\n", header->start);
    printf("death[%d]\n", header->death);
    printf("bullet[%d]\n", header->bullet);
}

void replay_header_clear(void) {
    memset(&g_replay_header, 0, sizeof(g_replay_header));
    g_replay_header.p1_type = 0xFF;
    g_replay_header.p1_doll = 0xFF;
    g_replay_header.p2_type = 0xFF;
    g_replay_header.p2_doll = 0xFF;
}

void task_stop_self(void);

void replay_stop_task(void) {
    task_stop_self();
}

#ifndef DDPDOJ_PC
typedef struct {
    unsigned __int128 quadwords[4];
} StatePayload;

typedef struct {
    StatePayload payload;
    s16 trailingHalfword;
} StateBlock;
#endif

void replay_header_save(void)
{
#ifdef DDPDOJ_PC
    _Static_assert(sizeof(ReplayHeader) == 0x42, "Replay header must keep its PS2 layout");
    g_replay_header_saved = g_replay_header;
#else
    u32 destinationAddress = (u32)&g_replay_header_saved;
    u32 sourceAddress = (u32)&g_replay_header;

    *(StatePayload *)destinationAddress = *(const StatePayload *)sourceAddress;
    *(s16 *)(destinationAddress + sizeof(StatePayload)) =
        *(const s16 *)(sourceAddress + sizeof(StatePayload));
#endif
}

extern void ship_select_apply(void);
extern u8 g_game_frame_ran;

void replay_header_apply(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;

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
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.h[0] = g_replay_header.p1_type;
    reg_d1.h[0] = g_replay_header.p1_doll;
    reg_d2.w = 0;
    g_game_frame_ran = 0;
    reg_d3.w = 0;
    reg_d4.w = 1;
    reg_d2.h[0] = g_replay_header.p2_type;
    reg_d3.h[0] = g_replay_header.p2_doll;
    ship_select_apply();
    replay_header_print(&g_replay_header);
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
}
