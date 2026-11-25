#include "common.h"
#include "sdk/ps2sdk.h"
#include "cd.h"
#include "replay.h"

/*
 * Sound: requests to the sound driver on the I/O processor. Music is streamed from the disc (two streams, the
 * low bit of a stream command selects one); effects and voices are samples loaded at start-up. Each effect has
 * a routine of its own that sets its volume and priority and plays its sample.
 */

#define EZBGM_DEV               0x12345
#define EZBGM_CMD_STOP          0x0060
#define EZBGM_CMD_SET_VOL       0x0080
#define EZBGM_CMD_SET_MASTERVOL 0x00A0
#define EZBGM_CMD_SDINIT        0x00D0
#define EZBGM_CMD_GET_STATUS    0x0100
#define EZBGM_CMD_START         0x0150
#define EZBGM_CMD_PLAY_SE       0x0500
#define EZBGM_CMD_STOP_SE       0x0510 /* the effects playing at one priority */
#define EZBGM_CMD_STOP_ALL_SE   0x0520
#define EZBGM_CMD_TICK          0x0530
#define EZBGM_CMD_RESET_SE      0x0540
#define EZBGM_CMD_LOAD_SE_INIT  0x0550
#define EZBGM_CMD_LOAD_SE       0x0560
#define EZBGM_CMD_GET_MODE      0x80B0

#define BGM_MODE_RUNNING        0x1000

/* One of the two music streams the sound driver plays, with the state of its volume fade. */
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

extern BgmFadeState g_bgm_fade_state[2];
extern sceSifClientData g_sound_rpc_client;
extern s32 g_sound_rpc_buf[16];

void stream_fade_out_for_pause(s32 arg0);
void stream_fade_in(s32 arg0);
void sfx_countdown(void);
void sfx_confirm(void);
void sfx_cursor_move(void);
void music_play(s32 arg0, s32 arg1);


s32 sound_rpc_bind(void) {
    s32 last;
    s32 delay;

    sceSifInitRpc(0);
retry:
    if (sceSifBindRpc(&g_sound_rpc_client, EZBGM_DEV, 0) < 0) {
hang:
        goto hang;
    }
    delay = 0x2710;
    do {
        last = delay;
        delay -= 1;
    } while (last != 0);
    if (g_sound_rpc_client.serve != 0) {
        return 1;
    }
    goto retry;
}


s32 sound_rpc_call(s32 arg0, s32 arg1, s32 arg2) {
    s32 t = arg0 & 0xFFF0;

    if (t == 0x8020 || t == 0x550 || t == 0x560) {
        sceSifCallRpc(&g_sound_rpc_client, arg0, 0, (void *)arg1, 0x40, g_sound_rpc_buf, 0x40, 0, 0);
    } else {
        g_sound_rpc_buf[0] = arg1;
        g_sound_rpc_buf[1] = arg2;
        sceSifCallRpc(&g_sound_rpc_client, arg0, 0, g_sound_rpc_buf, 0x10, g_sound_rpc_buf, 0x40, 0, 0);
    }
    return g_sound_rpc_buf[0];
}



s32 sound_rpc_call3(s32 command, s32 firstWord, s32 secondWord, s32 thirdWord)
{
    g_sound_rpc_buf[0] = firstWord;
    g_sound_rpc_buf[1] = secondWord;
    g_sound_rpc_buf[2] = thirdWord;

    sceSifCallRpc(&g_sound_rpc_client, command, 0, g_sound_rpc_buf, 0x10,
                  g_sound_rpc_buf, 0x40, 0, 0);

    return g_sound_rpc_buf[0];
}

extern u8 g_se_vag_path_1[];
extern u8 g_se_vag_path_2[];
extern u8 g_se_vag_path_3[];
extern u8 g_se_vag_path_4[];
extern u8 g_se_vag_path_5[];
extern u8 g_se_vag_path_6[];
extern u8 g_se_vag_path_7[];
extern s32 g_se_last_result;

void sound_start_up(void) {
    sound_rpc_bind();
    g_bgm_fade_state[0].fadeMode = 0;
    g_bgm_fade_state[0].isStopped = 1;
    g_se_last_result = 0;
    g_bgm_fade_state[1].isStopped = 1;
    g_bgm_fade_state[0].isPaused = 1;
    g_bgm_fade_state[1].isPaused = 1;
    g_bgm_fade_state[1].fadeMode = 0;
    g_bgm_fade_state[0].activeTrack = 0;
    g_bgm_fade_state[1].activeTrack = 0;
    sound_rpc_call(EZBGM_CMD_SDINIT, 0, 0);
    sound_rpc_call(EZBGM_CMD_RESET_SE, 0, 0);
    sound_rpc_call(EZBGM_CMD_SET_MASTERVOL, 0x3FFF3FFF, 0);
    sound_rpc_call(EZBGM_CMD_SET_MASTERVOL | 1, 0x3FFF3FFF, 0);
    sound_rpc_call(EZBGM_CMD_SET_VOL, 0x3FFF3FFF, 0);
    sound_rpc_call(EZBGM_CMD_SET_VOL | 1, 0x3FFF3FFF, 0);
    sound_rpc_call(EZBGM_CMD_LOAD_SE_INIT, (s32)((s32) g_se_vag_path_1), 0);
    sound_rpc_call(EZBGM_CMD_LOAD_SE, (s32)((s32) g_se_vag_path_2), 0);
    sound_rpc_call(EZBGM_CMD_LOAD_SE, (s32)((s32) g_se_vag_path_3), 0);
    sound_rpc_call(EZBGM_CMD_LOAD_SE, (s32)((s32) g_se_vag_path_4), 0);
    sound_rpc_call(EZBGM_CMD_LOAD_SE, (s32)((s32) g_se_vag_path_5), 0);
    sound_rpc_call(EZBGM_CMD_LOAD_SE, (s32)((s32) g_se_vag_path_6), 0);
    sound_rpc_call(EZBGM_CMD_LOAD_SE, (s32)((s32) g_se_vag_path_7), 0);
}

void music_start_when_ready(void);
void sound_update_bgm_fade(void);
void bgm_files_locate(void);
void stage_bg_files_locate(void);
void data_files_locate(void);
void replay_files_locate(void);

void disc_files_locate(void) {
    bgm_files_locate();
    stage_bg_files_locate();
    data_files_locate();
    replay_files_locate();
}


void stream_close(s32 arg0) {
    s32 off;
    s32 *p1;
    s32 *p2;

    off = arg0 * 0x28;
    p1 = (s32 *)((u8 *)&g_bgm_fade_state[0].isStopped + off);
    if (*p1 == 0) {
        p2 = (s32 *)((u8 *)&g_bgm_fade_state[0].isPaused + off);
        if (*p2 == 0) {
            sound_rpc_call(arg0 | 0x110, 0, 0);
        }
        sound_rpc_call(arg0 | 0x30, 0, 0);
        sound_rpc_call(arg0 | 0x10, 0, 0);
        *p1 = 1;
        *p2 = 1;
        *(s32 *)((u8 *)&g_bgm_fade_state[0].fadeMode + off) = 0;
    }
}


void streams_pause(void) {
    s32 v[2];
    s32 i;
    s32 o4;
    s32 o28;
    u8 *p;
    s32 *f;
    s32 t;

    v[0] = sound_rpc_call(EZBGM_CMD_GET_MODE, 0, 0) & ~0xFFF;
    v[1] = sound_rpc_call(EZBGM_CMD_GET_MODE | 1, 0, 0) & ~0xFFF;
    sound_rpc_call(EZBGM_CMD_STOP_ALL_SE, 0, 0);
    i = 0;
    o4 = 0;
    o28 = 0;
    do {
        if (*(s32 *)((u8 *)v + o4) & BGM_MODE_RUNNING) {
            printf("--pause on--\n");
            p = (u8 *)&g_bgm_fade_state[0].isStopped + o28;
            f = &((BgmFadeState *)p)->fadeMode;
            t = *f;
            if (t == 2) {
                sound_rpc_call(i | EZBGM_CMD_STOP, 0, 0);
                ((BgmFadeState *)p)->isPaused = 1;
                *f = 0;
                ((BgmFadeState *)p)->activeTrack = 0;
            } else {
                if (t == 3) {
                    ((BgmFadeState *)p)->curVol = ((BgmFadeState *)p)->targetVol;
                }
                *f = 4;
                ((BgmFadeState *)p)->activeTrack = 1;
                stream_fade_out_for_pause(i);
            }
        }
        i += 1;
        o4 += 4;
        o28 += 0x28;
    } while (i < 2);
}


void streams_resume(void) {
    s32 i;
    s32 off;
    s32 *f;
    u8 *p;

    off = 0;
    i = 0;
    do {
        p = (u8 *)&g_bgm_fade_state[0].isStopped + off;
        f = &((BgmFadeState *)p)->activeTrack;
        if (*f != 0) {
            printf("--pause off--\n");
            *f = 0;
            f = &((BgmFadeState *)p)->fadeMode;
            if (*f == 4) {
                *f = 3;
                stream_fade_in(i);
            } else {
                sound_rpc_call(i | 0xE0, 0, 0);
                sound_rpc_call(i | 0x50, 0, 0);
                ((BgmFadeState *)p)->isPaused = 0;
                *f = 3;
                stream_fade_in(i);
            }
        }
        i += 1;
        off += 0x28;
    } while (i < 2);
}

void streams_stop(void) {
    s32 v[2];
    s32 i;

    v[0] = sound_rpc_call(EZBGM_CMD_GET_MODE, 0, 0) & ~0xFFF;
    v[1] = sound_rpc_call(EZBGM_CMD_GET_MODE | 1, 0, 0) & ~0xFFF;
    sound_rpc_call(EZBGM_CMD_STOP_ALL_SE, 0, 0);
    for (i = 0; i < 2; i++) {
        if (v[i] & BGM_MODE_RUNNING) {
            sound_rpc_call(i | EZBGM_CMD_STOP, 0, 0);
            g_bgm_fade_state[i].isPaused = 1;
            g_bgm_fade_state[i].fadeMode = 0;
        }
    }
    g_bgm_fade_state[0].fadeMode = 0;
    g_bgm_fade_state[0].isPaused = 1;
    g_bgm_fade_state[1].isPaused = 1;
    g_bgm_fade_state[1].fadeMode = 0;
}

void stream_stop(s32 arg0) {
    u32 v = sound_rpc_call(arg0 | EZBGM_CMD_GET_MODE, 0, 0) & ~0xFFF; if (v & BGM_MODE_RUNNING) {
        sound_rpc_call(arg0 | EZBGM_CMD_STOP, 0, 0);
        g_bgm_fade_state[arg0].isPaused = 1;
        g_bgm_fade_state[arg0].fadeMode = 0;
    }
}

#pragma push
#pragma divbyzerocheck on

void stream_fade_out(s32 arg0) {
    s32 off;
    s32 *p;
    s32 *q;
    s32 *r;
    s32 n;
    s32 v;

    off = arg0 * 0x28;
    if (*(s32 *)((u8 *)&g_bgm_fade_state[0].isStopped + off) == 1) return;
    if (*(s32 *)((u8 *)&g_bgm_fade_state[0].isPaused + off) == 1) return;
    v = sound_rpc_call(arg0 | EZBGM_CMD_GET_MODE, 0, 0) & ~0xFFF;
    if (!(v & BGM_MODE_RUNNING)) return;
    p = (s32 *)((u8 *)&g_bgm_fade_state[0].curVol + off);
    *(s32 *)((u8 *)&g_bgm_fade_state[0].startVol + off) = *p;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].targetVol + off) = 0;
    *(q = (s32 *)((u8 *)&g_bgm_fade_state[0].timer + off)) = 0x78;
    n = *p;
    if (n == 0) {
        n = 1;
    }
    v = n * 100;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].curVolScaled + off) = v;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].stepVol + off) = v / *q;
    r = (s32 *)((u8 *)&g_bgm_fade_state[0].fadeMode + off);
    if (*r != 4) {
        *r = 2;
    }
}
#pragma pop

#pragma push
#pragma divbyzerocheck on
void stream_fade_out_for_pause(s32 arg0) {
    s32 off;
    s32 *p;
    s32 *q;
    s32 n;
    s32 v;

    off = arg0 * 0x28;
    p = (s32 *)((u8 *)&g_bgm_fade_state[0].curVol + off);
    *(s32 *)((u8 *)&g_bgm_fade_state[0].startVol + off) = *p;
    if (*p == 0) {
        *(s32 *)((u8 *)&g_bgm_fade_state[0].targetVol + off) = 0;
    } else {
        *(s32 *)((u8 *)&g_bgm_fade_state[0].targetVol + off) = 0;
    }
    *(q = (s32 *)((u8 *)&g_bgm_fade_state[0].timer + off)) = 0x1E;
    n = *p;
    if (n == 0) {
        n = 1;
    }
    v = n * 100;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].curVolScaled + off) = v;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].stepVol + off) = v / *q;
}
#pragma pop

#pragma push
#pragma divbyzerocheck on
void stream_fade_in(s32 arg0) {
    s32 off;
    s32 d;
    s32 *q;
    s32 base;

    off = arg0 * 0x28;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].targetVol + off) = *(s32 *)((u8 *)&g_bgm_fade_state[0].startVol + off);
    *(q = (s32 *)((u8 *)&g_bgm_fade_state[0].timer + off)) = 0x1E;
    base = *(s32 *)((u8 *)&g_bgm_fade_state[0].curVol + off);
    d = *(s32 *)((u8 *)&g_bgm_fade_state[0].targetVol + off) - base;
    if (d < 0) {
        d = -d;
    }
    if (d == 0) {
        d = 1;
    }
    *(s32 *)((u8 *)&g_bgm_fade_state[0].curVolScaled + off) = base * 100;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].stepVol + off) = d * 100 / *q;
    *(s32 *)((u8 *)&g_bgm_fade_state[0].fadeMode + off) = 3;
}
#pragma pop

extern s32 g_se_volume;
extern u16 g_attract_demo;

void sfx_play(s32 arg0) {
    s32 sample;
    s32 volume;

    sample = arg0;
    if (g_attract_demo == 0) {
        if (arg0 != 0) {
            sample -= 1;
        }
        volume = g_se_volume;
        volume -= 0x1E;
        if (volume < 0) {
            volume = 0;
        }
        if ((arg0 == 2) || (arg0 == 0xA) || (arg0 == 0x12) || (arg0 == 0x2D) || (arg0 == 0x32) || (arg0 == 0x25)) {
            sample |= 0x80;
        }
        g_se_last_result = sound_rpc_call(EZBGM_CMD_PLAY_SE, (s32)sample, (s32)((s32)volume));
    }
}

extern s32 g_se_priority;

void sfx_play_on_channel(s32 arg0) {
    s32 a1;
    s32 a2;
    s32 a3;

    if (g_attract_demo == 0) {
        a1 = arg0;
        if (arg0 != 0) {
            a1 -= 1;
        }
        a2 = g_se_volume;
        a2 -= 0x1E;
        a3 = g_se_priority;
        if (a2 < 0) {
            a2 = 0;
        }
        if ((arg0 == 2) || (arg0 == 0xA) || (arg0 == 0x12) || (arg0 == 0x2D) || (arg0 == 0x32) || (arg0 == 0x25)) {
            a1 |= 0x80;
        }
        g_se_last_result = sound_rpc_call3(0x580, a1, a2, a3);
    }
}


void sfx_stop_channel(void) {
    sound_rpc_call(EZBGM_CMD_STOP_SE, (s32)g_se_priority, 0);
}


void sfx_stop_all(void) {
    sound_rpc_call(EZBGM_CMD_STOP_ALL_SE, 0, 0);
}

extern u8 g_bgm_alternate_set;

void music_play_bgm1(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(0, 1);
        return;
    }
    music_play(0xD, 1);
}

void music_play_bgm2(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(1, 1);
        return;
    }
    music_play(0xE, 1);
}

void music_play_bgm3(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(2, 1);
        return;
    }
    music_play(0xF, 1);
}

void music_play_bgm4(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(3, 1);
        return;
    }
    music_play(0x10, 1);
}

void music_play_bgm5(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(4, 1);
        return;
    }
    music_play(0x11, 1);
}

void music_play_bgm6(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(5, 1);
        return;
    }
    music_play(0x12, 1);
}

void music_play_bgm7(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(6, 1);
        return;
    }
    music_play(0x13, 1);
}

void music_play_bgm8(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(7, 1);
        return;
    }
    music_play(0x14, 1);
}

void music_play_bgm9(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(8, 1);
        return;
    }
    music_play(0x15, 1);
}

void music_play_bgm10(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(9, 0);
        return;
    }
    music_play(0x16, 0);
}

void music_play_bgm11(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(0xA, 1);
        return;
    }
    music_play(0x17, 1);
}

void music_play_bgm12(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(0xB, 0);
        return;
    }
    music_play(0x18, 0);
}

void music_play_bgm13(void) {
    if (g_bgm_alternate_set == 0) {
        music_play(0xC, 1);
        return;
    }
    music_play(0x19, 1);
}


void sfx_menu_denied(void) {
    g_se_volume = 0x5D;
    g_se_priority = 0xA;
    sfx_play_on_channel(8);
}


void sfx_menu_confirm(void) {
    sfx_confirm();
}


void sfx_menu_tick(void) {
    sfx_countdown();
}


void sfx_menu_move(void) {
    sfx_cursor_move();
}


void sfx_explosion_air_small(void) {
    g_se_volume = 0xB4;
    g_se_priority = 0;
    sfx_play_on_channel(6);
}

void sfx_explosion_air_medium(void) {
    g_se_volume = 0x9E;
    g_se_priority = 0;
    sfx_play_on_channel(4);
}


void sfx_explosion_air_large(void) {
    g_se_volume = 0x80;
    g_se_priority = 0;
    sfx_play_on_channel(1);
}

void sfx_explosion_ground_small(void) {
    g_se_volume = 0x8A;
    g_se_priority = 0;
    sfx_play_on_channel(0xF);
}


void sfx_explosion_ground_medium(void) {
    g_se_volume = 0x80;
    g_se_priority = 0;
    sfx_play_on_channel(0xC);
}


void sfx_explosion_ground_large(void) {
    g_se_volume = 0xA8;
    g_se_priority = 0;
    sfx_play(9);
}


void sfx_explosion_extra_0(void) {
    g_se_volume = 0xA8;
    g_se_priority = 0;
    sfx_play(0x2A);
}

void sfx_explosion_extra_1(void) {
    g_se_volume = 0xA8;
    g_se_priority = 0;
    sfx_play(0x2B);
}


void sfx_explosion_extra_2(void) {
    g_se_volume = 0x80;
    g_se_priority = 0;
    sfx_play(0x26);
}



void sfx_explosion_extra_3(void) {
    g_se_volume = 0x80;
    g_se_priority = 0;
    sfx_play(0x27);
}

void sfx_explosion_extra_4(void) {
    g_se_volume = 0x80;
    g_se_priority = 0;
    sfx_play(0x28);
}

void sfx_explosion_extra_5(void) {
    g_se_volume = 0x80;
    g_se_priority = 0;
    sfx_play(0x29);
}

s32 vibration_start_pad1(s32, s32);            /* extern */
s32 vibration_start_pad2(s32, s32);            /* extern */
extern u8 g_slowdown_timer;

void sfx_explosion_boss(void) {
    g_slowdown_timer = 0x3C;
    g_se_volume = 0xA8;
    g_se_priority = 0;
    sfx_play(0x2A);
    g_se_volume = 0xA8;
    g_se_priority = 0;
    sfx_play(0x2B);
    g_se_volume = 0xA8;
    g_se_priority = 0;
    sfx_play(0x2A);
    vibration_start_pad1(0xC8, 0x50);
    vibration_start_pad2(0xC8, 0x50);
}


void sfx_player_explosion(void) {
    g_se_volume = 0xB2;
    g_se_priority = 1;
    sfx_play(0x17);
}

void sfx_shot_a(void) {
    g_se_volume = 0x5D;
    g_se_priority = 2;
    sfx_play(8);
}

void sfx_shot_b(void) {
    g_se_volume = 0x5D;
    g_se_priority = 2;
    sfx_play(0x11);
}

void sfx_shot_hyper(void) {
    g_se_volume = 0x5D;
    g_se_priority = 2;
    sfx_play(0x16);
}

void sfx_p1_laser_a_start(void) {
    g_se_volume = 0x80;
    g_se_priority = 3;
    sfx_play_on_channel(2);
}

void sfx_p1_laser_b_start(void) {
    g_se_volume = 0x80;
    g_se_priority = 3;
    sfx_play_on_channel(0xA);
}


void sfx_p1_laser_hyper_start(void) {
    g_se_volume = 0xE6;
    g_se_priority = 3;
    sfx_play_on_channel(0x12);
    vibration_start_pad1(0x8C, 0x4B0);
}

void sfx_p2_laser_a_start(void) {
    g_se_volume = 0x80;
    g_se_priority = 4;
    sfx_play_on_channel(2);
}

void sfx_p2_laser_b_start(void) {
    g_se_volume = 0x80;
    g_se_priority = 4;
    sfx_play_on_channel(0xA);
}

void sfx_p2_laser_hyper_start(void) {
    g_se_volume = 0xFA;
    g_se_priority = 4;
    sfx_play_on_channel(0x12);
    vibration_start_pad2(0x8C, 0x4B0);
}


void sfx_laser_bomb_a(void) {
    g_se_volume = 0xE4;
    g_se_priority = 5;
    sfx_play(3);
}


void sfx_laser_bomb_b(void) {
    g_se_volume = 0xE4;
    g_se_priority = 5;
    sfx_play(0xB);
}

void sfx_spread_bomb_a(void) {
    g_se_volume = 0xFF;
    g_se_priority = 5;
    sfx_play(5);
}

void sfx_spread_bomb_b(void) {
    g_se_volume = 0xFF;
    g_se_priority = 5;
    sfx_play(0xE);
    sfx_play(0xE);
    sfx_play(0xE);
}

void sfx_coin(void) {
    g_se_volume = 0xFF;
    g_se_priority = 6;
    sfx_play(0x13);
}

void sfx_item_pickup(void) {
    g_se_volume = 0xE4;
    g_se_priority = 7;
    sfx_play(0x10);
}


void sfx_score_item_pickup(void) {
    g_se_volume = 0xFF;
    g_se_priority = 7;
    sfx_play_on_channel(7);
}

void sfx_score_item_pickup_2(void) {
    g_se_volume = 0xFF;
    g_se_priority = 7;
    sfx_play(7);
}

void sfx_bee_pickup(void) {
    g_se_volume = 0xFF;
    g_se_priority = 7;
    sfx_play(0x22);
}

void sfx_hyper_pickup(void) {
    g_se_volume = 0xFF;
    g_se_priority = 7;
    sfx_play(0x30);
}

void sfx_extend(void) {
    g_se_volume = 0xFF;
    g_se_priority = 7;
    sfx_play(0x2F);
}


void sfx_warning(void) {
    g_se_volume = 0x80;
    g_se_priority = 0x8;
    sfx_play(0x38);
}

void sfx_countdown(void) {
    g_se_volume = 0x80;
    g_se_priority = 6;
    sfx_play(0x14);
}

void sfx_bonus_count(void) {
    g_se_volume = 0x80;
    g_se_priority = 0x6;
    sfx_play(0x15);
}

void sfx_confirm(void) {
    g_se_volume = 0xFF;
    g_se_priority = 6;
    sfx_play(0x23);
}

void sfx_cursor_move(void) {
    g_se_volume = 0x94;
    g_se_priority = 6;
    sfx_play(0x37);
}

void sfx_enemy_fire_0(void) {
}

void sfx_enemy_fire_1(void) {
}

void sfx_enemy_fire_2(void) {
    g_se_volume = 0x80;
    g_se_priority = 9;
    sfx_play(0x35);
}

void sfx_enemy_fire_3(void) {
    g_se_volume = 0x80;
    g_se_priority = 9;
    sfx_play(0x36);
}

void sfx_heli_start(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xA;
    sfx_play_on_channel(0x2D);
}

void sfx_shockwave(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xA;
    sfx_play(0x2E);
    sfx_play(0x2E);
    sfx_play(0x2E);
}


void sfx_charge_begin(void) {
    g_se_volume = 0xD2;
    g_se_priority = 0xA;
    sfx_play(0x31);
}


void sfx_charge_loop_start(void) {
    g_se_volume = 0x80;
    g_se_priority = 0xA;
    sfx_play_on_channel(0x32);
}

void sfx_beam_fire(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xA;
    sfx_play(0x24);
    vibration_start_pad1(0xA0, 0x12C);
    vibration_start_pad2(0xA0, 0x12C);
}

void sfx_beam_loop_start(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xA;
    sfx_play_on_channel(0x25);
}

void sfx_misc_0(void) {
    g_se_volume = 0x80;
    g_se_priority = 0xA;
    sfx_play(0x2C);
}

void sfx_misc_1(void) {
    g_se_volume = 0x80;
    g_se_priority = 10;
    sfx_play(0x34);
}

void sfx_misc_2(void) {
    g_se_volume = 0x80;
    g_se_priority = 0xA;
    sfx_play(0xD);
}

void sfx_misc_3(void) {
    g_se_volume = 0x80;
    g_se_priority = 0xA;
    sfx_play(0x33);
}

void voice_power_up(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x1C);
}

void voice_bomb(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x1D);
}

void voice_continue(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x1E);
}

void voice_game_over(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0x0B;
    sfx_play(0x1F);
}

void voice_warning(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x18);
}


void voice_hyper(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x19);
}

void voice_select(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x1A);
}

void voice_ok(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x1B);
}

void voice_bye(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x20);
}

void voice_logo(void) {
    g_se_volume = 0xFF;
    g_se_priority = 0xB;
    sfx_play(0x21);
}


void sfx_heli_stop(void) {
    g_se_priority = 10;
    sfx_stop_channel();
}

void sfx_charge_loop_stop(void) {
    g_se_priority = 10;
    sfx_stop_channel();
}

void sfx_beam_loop_stop(void) {
    g_se_priority = 10;
    sfx_stop_channel();
}

void sfx_p1_laser_a_stop(void) {
    g_se_priority = 3;
    sfx_stop_channel();
}

void sfx_p1_laser_b_stop(void) {
    g_se_priority = 3;
    sfx_stop_channel();
}

void sfx_p2_laser_a_stop(void) {
    g_se_priority = 4;
    sfx_stop_channel();
}

void sfx_p2_laser_b_stop(void) {
    g_se_priority = 4;
    sfx_stop_channel();
}

s32 vibration_stop_pad1();                            /* extern */

void sfx_p1_laser_hyper_stop(void) {
    g_se_priority = 3;
    sfx_stop_channel();
    vibration_stop_pad1();
}

s32 vibration_stop_pad2();                            /* extern */

void sfx_p2_laser_hyper_stop(void) {
    g_se_priority = 4;
    sfx_stop_channel();
    vibration_stop_pad2();
}


void sound_init(void) {
    sound_start_up();
}

void sound_unused(void) {
}


void sound_stop_effects(void) {
    sfx_stop_all();
}


void sound_stop_loops(void) {
    sfx_heli_stop();
    sfx_p1_laser_a_stop();
    sfx_p2_laser_a_stop();
}

extern u8 g_pause_lock_timer;

void music_fade_out(void) {
    g_pause_lock_timer = 0xFF;
    stream_fade_out(0);
}


void music_stop(void) {
    g_pause_lock_timer = 0xFF;
    stream_stop(0);
}

extern s8 g_music_started;

void music_play(s32 arg0, s32 arg1) {
    if (g_attract_demo != 0) return;
    g_pause_lock_timer = 0x46;
    g_bgm_fade_state[0].fadeMode = 0;
    sound_rpc_call(0x100, 1, 0);
    stream_close(0);
    sound_rpc_call(0x200, 0, 0);
    printf("stereo \n");
    sound_rpc_call(0x8000, 0x30000, 0);
    if (arg1 != 0) {
        sound_rpc_call(0x80C0, 2, 0);
    } else {
        sound_rpc_call(0x80C0, 0, 0);
    }
    sound_rpc_call(0x160, g_bgm_files[arg0].size, g_bgm_files[arg0].lba);
    g_bgm_fade_state[0].curVol = 0x64;
    g_bgm_fade_state[0].startVol = g_bgm_fade_state[0].curVol;
    sound_rpc_call(EZBGM_CMD_SET_VOL, 0x7FFF7FFF, 0);
    sound_rpc_call(0x140, 0, 0);
    g_music_started = 1;
}

extern s8 g_music_started;

void sound_update(void) {
    sound_rpc_call(EZBGM_CMD_TICK, 0, 0);
    if (g_music_started != 0) {
        music_start_when_ready();
    }
    sound_update_bgm_fade();
}


void music_start_when_ready(void) {
    if (sound_rpc_call(EZBGM_CMD_GET_STATUS, 0, 0) == 0) {
        sound_rpc_call(EZBGM_CMD_START, 0, 0);
        g_music_started = 0;
        g_bgm_fade_state[0].isStopped = 0;
        g_bgm_fade_state[0].isPaused = 0;
    }
}

extern s8 g_bgm_fade_active;

void sound_update_bgm_fade(void) {
    s32 i;
    s32 off;
    u8 *p;
    s32 *f;
    s32 *c;
    s32 *tg;
    s32 t;
    s32 v;
    s32 hi;

    off = 0;
    i = 0;
    do {
        p = (u8 *)&g_bgm_fade_state[0].isStopped + off;
        f = &((BgmFadeState *)p)->fadeMode;
        if (*f != 0) {
            ((BgmFadeState *)p)->timer -= 1;
            if (((BgmFadeState *)p)->timer <= 0) {
                ((BgmFadeState *)p)->curVol = ((BgmFadeState *)p)->targetVol;
                printf("-[%d]-----osimai------\n", ((BgmFadeState *)p)->curVol);
                t = *f;
                if (t == 3) {
                    g_bgm_fade_active = 0;
                }
                if (t == 2) {
                    stream_stop(i);
                    g_bgm_fade_state[i].fadeMode = 0;
                    printf("bgm stop\n");
                    return;
                }
                if (t == 4) {
                    sound_rpc_call(i | EZBGM_CMD_STOP, 0, 0);
                    g_bgm_fade_state[i].fadeMode = 0;
                    return;
                }
                *f = 0;
            }
            c = &((BgmFadeState *)p)->curVol;
            tg = &((BgmFadeState *)p)->targetVol;
            if (*c != *tg) {
                if (*c < *tg) {
                    ((BgmFadeState *)p)->curVolScaled += ((BgmFadeState *)p)->stepVol;
                    *c = ((BgmFadeState *)p)->curVolScaled / 100;
                    if (*tg < *c) {
                        *c = *tg;
                    }
                } else {
                    ((BgmFadeState *)p)->curVolScaled -= ((BgmFadeState *)p)->stepVol;
                    *c = ((BgmFadeState *)p)->curVolScaled / 100;
                    if (*c < *tg) {
                        *c = *tg;
                    }
                }
            }
            v = *c;
            if (v != 0) {
                v = v * 0x7FFF / 100;
            }
            hi = v << 16;
            hi |= v;
            sound_rpc_call(i | EZBGM_CMD_SET_VOL, hi, 0);
        }
        i += 1;
        off += 0x28;
    } while (i < 2);
}

extern const char *g_bgm_file_paths[];
extern const char *g_stage_bg_paths[];
extern const char *g_data_file_paths[];
extern const char *g_replay_file_paths[];
extern ReplayHeader g_replay_file_headers[];

void bgm_files_locate(void) {
    s32 i;

    for (i = 0; i < 0x1A; i++) {
        cd_search_file(g_bgm_file_paths[i]);
        g_bgm_files[i].size = g_cd_file.size;
        g_bgm_files[i].lba = g_cd_file.lsn;
    }
}

void stage_bg_files_locate(void) {
    s32 i;

    for (i = 0; i < 0xA; i++) {
        cd_search_file(g_stage_bg_paths[i]);
        g_stage_bg_files[i].size = g_cd_file.size;
        g_stage_bg_files[i].lba = g_cd_file.lsn;
    }
}

void data_files_locate(void) {
    s32 i;

    for (i = 0; i < MAIN_OR_DEATH_LABEL(0xE, 0x10); i++) {
        cd_search_file(g_data_file_paths[i]);
        g_data_files[i].size = g_cd_file.size;
        g_data_files[i].lba = g_cd_file.lsn;
    }
}

void replay_files_locate(void) {
    s32 i;
    void *buf;
    ReplayHeader *dst;

    buf = memalign(0x40, 0x800);
    for (i = 0; i < 10; i++) {
        cd_search_file(g_replay_file_paths[i]);
        g_replay_files[i].size = g_cd_file.size;
        g_replay_files[i].lba = g_cd_file.lsn;
        cd_read_sync(buf, 0x800, g_cd_file.lsn);
        dst = &g_replay_file_headers[i];
        memcpy(dst, buf, 0x42);
        dst->unk00 = 1;
    }
    free(buf);
}

/* .sbss (the compiler lays these out in reverse) */
s8 g_music_started __attribute__((aligned(4)));
s8 g_bgm_fade_active;
s32 g_se_last_result;
s32 g_se_volume;
s32 g_se_priority;

/* .bss (the compiler lays these out in reverse) */
s32 g_sound_rpc_buf[16] __attribute__((aligned(64)));
sceSifClientData g_sound_rpc_client;
CdFileEntry g_bgm_files[30];
CdFileEntry g_stage_bg_files[20];
CdFileEntry g_data_files[DATA_FILE_TABLE_SIZE];
CdFileEntry g_replay_files[10];
BgmFadeState g_bgm_fade_state[2];
