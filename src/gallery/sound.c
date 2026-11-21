#include "gallery/gallery.h"

typedef struct {
    s32 unk00;
    s32 unk04;
    s32 fadeMode;
    s32 curVol;
    s32 unk10;
    s32 targetVol;
    s32 curVolScaled;
    s32 stepVol;
    s32 timer;
    s32 unk24;
} BgmFadeState;

typedef struct {
    s32 first;
    s32 second;
} GalleryEntry;

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
extern s32 D_0012B2DC;
extern s32 D_0012B2E0;
extern s32 D_0012B2E4;
extern u8 D_0012B2E8;
extern s8 D_0012B2EC;
extern BgmFadeState g_bgm_fade_state[2];
extern GalleryEntry D_00132620[];
extern GalleryEntry D_001326C0[];
extern GalleryEntry D_00132760[];
extern s32 g_sound_rpc_client[12];
extern s32 g_sound_rpc_buf[16];

static inline s32 send_bgm_rpc(u32 cmd, s32 param1, s32 param2)
{
    if ((cmd & 0xFFF0) == 0x8020 || (cmd & 0xFFF0) == 0x0550 || (cmd & 0xFFF0) == 0x0560) {
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

    for (channel = 0; channel < 2; channel++) {
        if (g_bgm_fade_state[channel].fadeMode == 0) {
            continue;
        }

        g_bgm_fade_state[channel].timer--;
        if (g_bgm_fade_state[channel].timer <= 0) {
            g_bgm_fade_state[channel].curVol = g_bgm_fade_state[channel].targetVol;
            printf("-[%d]-----osimai------\n", g_bgm_fade_state[channel].curVol);

            if (g_bgm_fade_state[channel].fadeMode == 3) {
                D_0012B2E8 = 0;
            }

            if (g_bgm_fade_state[channel].fadeMode == 2) {
                if (send_bgm_rpc(channel | 0x80B0, 0, 0) & 0x1000) {
                    send_bgm_rpc(channel | 0x60, 0, 0);
                    g_bgm_fade_state[channel].unk04 = 1;
                    g_bgm_fade_state[channel].fadeMode = 0;
                }
                g_bgm_fade_state[channel].fadeMode = 0;
                printf("bgm stop\n");
                return;
            } else if (g_bgm_fade_state[channel].fadeMode == 4) {
                send_bgm_rpc(channel | 0x60, 0, 0);
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
        {
            u32 cmd = channel | 0x80;
            s32 volParam = volume << 16;
            volParam |= volume;
            send_bgm_rpc(cmd, volParam, 0);
        }
    }
}

void sound_update(void)
{
    g_sound_rpc_buf[0] = 0;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, 0x530, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    if (D_0012B2EC != 0) {
        g_sound_rpc_buf[0] = 0;
        g_sound_rpc_buf[1] = 0;
        sceSifCallRpc(g_sound_rpc_client, 0x100, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

        if (g_sound_rpc_buf[0] == 0) {
            g_sound_rpc_buf[0] = 0;
            g_sound_rpc_buf[1] = 0;
            sceSifCallRpc(g_sound_rpc_client, 0x150, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);
            D_0012B2EC = 0;
            g_bgm_fade_state[0].unk00 = 0;
            g_bgm_fade_state[0].unk04 = 0;
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
    D_0012B2E0 = 0x94;
    D_0012B2DC = 6;
    sound_play_se(0x37);
}

void sound_play_page_se(void)
{
    D_0012B2E0 = 0x80;
    D_0012B2DC = 6;
    sound_play_se(0x14);
}

void sound_play_confirm_se(void)
{
    D_0012B2E0 = 0xFF;
    D_0012B2DC = 6;
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

        adjustedValue = D_0012B2E0;
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
        sceSifCallRpc(g_sound_rpc_client, 0x500, 0, g_sound_rpc_buf, 0x10,
                      g_sound_rpc_buf, 0x40, 0, 0);
        D_0012B2E4 = g_sound_rpc_buf[0];
    }
}

void sound_init_file_tables(void)
{
    s32 index;
    const char **source;
    GalleryEntry *entry;

    index = 0;
    source = g_bgm_file_paths;
    entry = D_00132760;
    for (; index < 13; index++, source++, entry++) {
        cd_search_file(*source);
        entry->first = g_cd_file_size[0];
        entry->second = g_cd_file_lba[0];
    }

    index = 0;
    source = g_stage_bg_paths;
    entry = D_001326C0;
    for (; index < 10; index++, source++, entry++) {
        cd_search_file(*source);
        entry->first = g_cd_file_size[0];
        entry->second = g_cd_file_lba[0];
    }

    index = 0;
    source = g_data_file_paths;
    entry = D_00132620;
    for (; index < 14; index++, source++, entry++) {
        cd_search_file(*source);
        entry->first = g_cd_file_size[0];
        entry->second = g_cd_file_lba[0];
    }
}

void sound_init_iop_rpc(void)
{
    sceSifInitRpc(0);
    do {
        if (sceSifBindRpc(g_sound_rpc_client, 0x12345, 0) < 0) {
            while (1) {
            }
        }
    } while (g_sound_rpc_client[9] == 0);

    g_bgm_fade_state[0].fadeMode = 0;
    g_bgm_fade_state[0].unk00 = 1;
    g_bgm_fade_state[1].unk00 = 1;
    g_bgm_fade_state[0].unk04 = 1;
    g_bgm_fade_state[1].unk04 = 1;
    g_bgm_fade_state[1].fadeMode = 0;
    g_bgm_fade_state[0].unk24 = 0;
    g_bgm_fade_state[1].unk24 = 0;
    D_0012B2E4 = 0;
    g_sound_rpc_buf[0] = 0;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, 0xD0, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, 0x540, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, 0xA0, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, 0xA1, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, 0x80, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    g_sound_rpc_buf[0] = 0x3FFF3FFF;
    g_sound_rpc_buf[1] = 0;
    sceSifCallRpc(g_sound_rpc_client, 0x81, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);

    load_vag(0x550, g_se_vag_path_1);
    load_vag(0x560, g_se_vag_path_2);
    load_vag(0x560, g_se_vag_path_3);
    load_vag(0x560, g_se_vag_path_4);
    load_vag(0x560, g_se_vag_path_5);
    load_vag(0x560, g_se_vag_path_6);
    load_vag(0x560, g_se_vag_path_7);
}
