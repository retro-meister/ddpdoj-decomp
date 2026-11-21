#include "gallery/gallery.h"

#define EZBGM_RPC_SERVER_ID     0x12345
#define EZBGM_CMD_STOP          0x0060
#define EZBGM_CMD_SET_VOL       0x0080
#define EZBGM_CMD_SET_MASTERVOL 0x00A0
#define EZBGM_CMD_INIT          0x00D0
#define EZBGM_CMD_GET_STATUS    0x0100
#define EZBGM_CMD_START         0x0150
#define EZBGM_CMD_PLAY_SE       0x0500
#define EZBGM_CMD_TICK          0x0530
#define EZBGM_CMD_RESET_SE      0x0540
#define EZBGM_CMD_LOAD_SE_INIT  0x0550
#define EZBGM_CMD_LOAD_SE       0x0560
#define EZBGM_CMD_LOAD_BGM      0x8020
#define EZBGM_CMD_GET_MODE      0x80B0

typedef struct {
    s32 isStopped;
    s32 isPaused;
    s32 fadeMode;
    s32 curVol;
    s32 startVol;
    s32 targetVol;
    s32 curVolScaled;
    s32 stepVol;
    s32 timer;
    s32 activeTrack;
} BgmFadeState;

static char g_se_vag_path_1[0x40] = "\\DATA\\SE1.VAG;1";
static char g_se_vag_path_2[0x40] = "\\DATA\\SE2.VAG;1";
static char g_se_vag_path_3[0x40] = "\\DATA\\SE3.VAG;1";
static char g_se_vag_path_4[0x40] = "\\DATA\\SE4.VAG;1";
static char g_se_vag_path_5[0x40] = "\\DATA\\SE5.VAG;1";
static char g_se_vag_path_6[0x40] = "\\DATA\\SE6.VAG;1";
static char g_se_vag_path_7[0x10] = "\\DATA\\SE7.VAG;1";

static const char *g_bgm_file_paths[16] = {
    "\\BGM\\BGM1.D2;1",
    "\\BGM\\BGM2.D2;1",
    "\\BGM\\BGM3.D2;1",
    "\\BGM\\BGM4.D2;1",
    "\\BGM\\BGM5.D2;1",
    "\\BGM\\BGM6.D2;1",
    "\\BGM\\BGM7.D2;1",
    "\\BGM\\BGM8.D2;1",
    "\\BGM\\BGM9.D2;1",
    "\\BGM\\BGM10.D2;1",
    "\\BGM\\BGM11.D2;1",
    "\\BGM\\BGM12.D2;1",
    "\\BGM\\BGM13.D2;1",
    0,
    0,
    0,
};

static const char *g_stage_bg_paths[12] = {
    "\\SPRITE\\ST1BG.PHD;1",
    "\\SPRITE\\ST1BG.PRS;1",
    "\\SPRITE\\ST2BG.PHD;1",
    "\\SPRITE\\ST2BG.PRS;1",
    "\\SPRITE\\ST3BG.PHD;1",
    "\\SPRITE\\ST3BG.PRS;1",
    "\\SPRITE\\ST4BG.PHD;1",
    "\\SPRITE\\ST4BG.PRS;1",
    "\\SPRITE\\ST5BG.PHD;1",
    "\\SPRITE\\ST5BG.PRS;1",
    0,
    0,
};

static const char *g_data_file_paths[16] = {
    "\\DATA\\FONT.GF;1",
    "\\SPRITE\\BULLET.DAT;1",
    "\\SPRITE\\EXP.DAT;1",
    "\\SPRITE\\SPDAT.PRS;1",
    "\\SPRITE\\SPHED.PRS;1",
    "\\SPRITE\\ST1SP.PRS;1",
    "\\SPRITE\\ST2SP.PRS;1",
    "\\SPRITE\\ST3SP.PRS;1",
    "\\SPRITE\\ST4SP.PRS;1",
    "\\SPRITE\\ST5SP.PRS;1",
    "\\DATA\\DDON3_02.DAT;1",
    "\\DATA\\WAKU.8;1",
    "\\DATA\\ARIKA.8;1",
    "\\DATA\\MAP2.8;1",
    0,
    0,
};
extern s32 g_se_priority;
extern s32 g_se_volume;
extern s32 g_se_last_result;
extern u8 g_bgm_fade_active;
extern s8 g_bgm_stop_pending;
extern BgmFadeState g_bgm_fade_state[2];
extern CdFileEntry g_stage_bg_files[20];
extern CdFileEntry g_bgm_files[30];
extern s32 g_sound_rpc_client[12];
extern s32 g_sound_rpc_buf[16];

static inline s32 send_bgm_rpc(u32 cmd, s32 param1, s32 param2)
{
    if ((cmd & 0xFFF0) == EZBGM_CMD_LOAD_BGM || (cmd & 0xFFF0) == EZBGM_CMD_LOAD_SE_INIT || (cmd & 0xFFF0) == EZBGM_CMD_LOAD_SE) {
        sceSifCallRpc(g_sound_rpc_client, cmd, 0, (void *)param1, 0x40, g_sound_rpc_buf, 0x40, 0, 0);
    } else {
        g_sound_rpc_buf[0] = param1;
        g_sound_rpc_buf[1] = param2;
        sceSifCallRpc(g_sound_rpc_client, cmd, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);
    }
    return g_sound_rpc_buf[0];
}

static inline void load_vag(u32 cmd, void *path)
{
    s32 p = (s32)path;
    sceSifCallRpc(g_sound_rpc_client, cmd, 0, (void *)p, 0x40, g_sound_rpc_buf, 0x40, 0, 0);
}

void sound_update_bgm_fade(void)
{
    s32 channel;
    s32 volume;
    u32 cmd;
    s32 volParam;

    for (channel = 0; channel < 2; channel++) {
        if (g_bgm_fade_state[channel].fadeMode == 0) {
            continue;
        }

        g_bgm_fade_state[channel].timer--;
        if (g_bgm_fade_state[channel].timer <= 0) {
            g_bgm_fade_state[channel].curVol = g_bgm_fade_state[channel].targetVol;
            printf("-[%d]-----osimai------\n", g_bgm_fade_state[channel].curVol);

            if (g_bgm_fade_state[channel].fadeMode == 3) {
                g_bgm_fade_active = 0;
            }

            if (g_bgm_fade_state[channel].fadeMode == 2) {
                if (send_bgm_rpc(channel | EZBGM_CMD_GET_MODE, 0, 0) & 0x1000) {
                    send_bgm_rpc(channel | EZBGM_CMD_STOP, 0, 0);
                    g_bgm_fade_state[channel].isPaused = 1;
                    g_bgm_fade_state[channel].fadeMode = 0;
                }
                g_bgm_fade_state[channel].fadeMode = 0;
                printf("bgm stop\n");
                return;
            } else if (g_bgm_fade_state[channel].fadeMode == 4) {
                send_bgm_rpc(channel | EZBGM_CMD_STOP, 0, 0);
                g_bgm_fade_state[channel].fadeMode = 0;
                return;
            } else {
                g_bgm_fade_state[channel].fadeMode = 0;
            }
        }

        if (g_bgm_fade_state[channel].curVol != g_bgm_fade_state[channel].targetVol) {
            if (g_bgm_fade_state[channel].curVol < g_bgm_fade_state[channel].targetVol) {
                g_bgm_fade_state[channel].curVolScaled += g_bgm_fade_state[channel].stepVol;
                g_bgm_fade_state[channel].curVol = g_bgm_fade_state[channel].curVolScaled / 100;
                if (g_bgm_fade_state[channel].curVol > g_bgm_fade_state[channel].targetVol) {
                    g_bgm_fade_state[channel].curVol = g_bgm_fade_state[channel].targetVol;
                }
            } else {
                g_bgm_fade_state[channel].curVolScaled -= g_bgm_fade_state[channel].stepVol;
                g_bgm_fade_state[channel].curVol = g_bgm_fade_state[channel].curVolScaled / 100;
                if (g_bgm_fade_state[channel].curVol < g_bgm_fade_state[channel].targetVol) {
                    g_bgm_fade_state[channel].curVol = g_bgm_fade_state[channel].targetVol;
                }
            }
        }

        volume = g_bgm_fade_state[channel].curVol;
        if (volume != 0) {
            volume = (volume * 0x7FFF) / 100;
        }
        cmd = channel | EZBGM_CMD_SET_VOL;
        volParam = volume << 16;
        volParam |= volume;
        send_bgm_rpc(cmd, volParam, 0);
    }
}

void sound_update(void)
{
    g_sound_rpc_buf[0] = 0;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_TICK, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    if (g_bgm_stop_pending != 0) {
        g_sound_rpc_buf[0] = 0;
        g_sound_rpc_buf[1] = 0;
        sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_GET_STATUS, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

        if (g_sound_rpc_buf[0] == 0) {
            g_sound_rpc_buf[0] = 0;
            g_sound_rpc_buf[1] = 0;
            sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_START, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);
            g_bgm_stop_pending = 0;
            g_bgm_fade_state[0].isStopped = 0;
            g_bgm_fade_state[0].isPaused = 0;
        }
    }

    sound_update_bgm_fade();
}

void sound_init(void)
{
    sound_init_iop_rpc();
}

void sound_play_cursor_se(void)
{
    g_se_volume = 0x94;
    g_se_priority = 6;
    sound_play_se(0x37);
}

void sound_play_page_se(void)
{
    g_se_volume = 0x80;
    g_se_priority = 6;
    sound_play_se(0x14);
}

void sound_play_confirm_se(void)
{
    g_se_volume = 0xFF;
    g_se_priority = 6;
    sound_play_se(0x23);
}

void sound_play_se(s32 selection)
{
    s32 adjustedValue;
    s32 requestIndex;

    if (g_system_mute == 0) {
        requestIndex = selection;
        if (selection != 0) {
            requestIndex--;
        }

        adjustedValue = g_se_volume;
        adjustedValue -= 30;
        if (adjustedValue < 0) {
            adjustedValue = 0;
        }

        if (selection == 2 || selection == 10 || selection == 18 ||
            selection == 45 || selection == 50 || selection == 37) {
            requestIndex |= 0x80;
        }

        g_sound_rpc_buf[0] = requestIndex;
        g_sound_rpc_buf[1] = adjustedValue;
        sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_PLAY_SE, 0, g_sound_rpc_buf, 0x10,
                      g_sound_rpc_buf, 0x40, 0, 0);
        g_se_last_result = g_sound_rpc_buf[0];
    }
}

void sound_init_file_tables(void)
{
    s32 index;
    const char **source;
    CdFileEntry *entry;

    for (index = 0, source = g_bgm_file_paths, entry = g_bgm_files; index < 13; index++, source++, entry++) {
        cd_search_file(*source);
        entry->size = g_cd_file.size;
        entry->lba = g_cd_file.lba;
    }

    for (index = 0, source = g_stage_bg_paths, entry = g_stage_bg_files; index < 10; index++, source++, entry++) {
        cd_search_file(*source);
        entry->size = g_cd_file.size;
        entry->lba = g_cd_file.lba;
    }

    for (index = 0, source = g_data_file_paths, entry = g_data_files; index < 14; index++, source++, entry++) {
        cd_search_file(*source);
        entry->size = g_cd_file.size;
        entry->lba = g_cd_file.lba;
    }
}

void sound_init_iop_rpc(void)
{
    sceSifInitRpc(0);
    do {
        if (sceSifBindRpc(g_sound_rpc_client, EZBGM_RPC_SERVER_ID, 0) < 0) {
            while (1) {
            }
        }
    } while (g_sound_rpc_client[9] == 0);

    g_bgm_fade_state[0].fadeMode = 0;
    g_bgm_fade_state[0].isStopped = 1;
    g_bgm_fade_state[1].isStopped = 1;
    g_bgm_fade_state[0].isPaused = 1;
    g_bgm_fade_state[1].isPaused = 1;
    g_bgm_fade_state[1].fadeMode = 0;
    g_bgm_fade_state[0].activeTrack = 0;
    g_bgm_fade_state[1].activeTrack = 0;
    g_se_last_result = 0;
    g_sound_rpc_buf[0] = 0;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_INIT, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_RESET_SE, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_SET_MASTERVOL | 0, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_SET_MASTERVOL | 1, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_SET_VOL | 0, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, EZBGM_CMD_SET_VOL | 1, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    load_vag(EZBGM_CMD_LOAD_SE_INIT, g_se_vag_path_1);
    load_vag(EZBGM_CMD_LOAD_SE, g_se_vag_path_2);
    load_vag(EZBGM_CMD_LOAD_SE, g_se_vag_path_3);
    load_vag(EZBGM_CMD_LOAD_SE, g_se_vag_path_4);
    load_vag(EZBGM_CMD_LOAD_SE, g_se_vag_path_5);
    load_vag(EZBGM_CMD_LOAD_SE, g_se_vag_path_6);
    load_vag(EZBGM_CMD_LOAD_SE, g_se_vag_path_7);
}

s8 g_bgm_stop_pending __attribute__((aligned(4)));
u8 g_bgm_fade_active __attribute__((aligned(4)));
s32 g_se_last_result;
s32 g_se_volume;
s32 g_se_priority;

s32 g_sound_rpc_buf[16];
s32 g_sound_rpc_client[12];
CdFileEntry g_bgm_files[30];
CdFileEntry g_stage_bg_files[20];
CdFileEntry g_data_files[20];
BgmFadeState g_bgm_fade_state[2];
