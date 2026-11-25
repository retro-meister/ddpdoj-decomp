#include "common.h"
#include "sdk/ps2sdk.h"
#include "pad.h"
#include "gfx.h"
#include "pad.h"
#include "system.h"

void sys_init(void);
void sys_draw_replay_label(void);
void pause_check_start_button(void);
void vram_clear_all(void);
void fade_reset(void);
void fade_update_and_draw(void);
void vibration_start_active_pad(s16 arg0, s16 arg1);
void vibration_update(void);


void iop_reboot_and_load_modules(void) {
    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);
    do {

    } while (sceSifRebootIop("cdrom0:\\MODULE\\IOPRP260.IMG;1") == 0);
    do {

    } while (sceSifSyncIop() == 0);
    sceSifInitRpc(0);
    sceCdInit(0);
    sceCdMmode(2);
    sceFsReset();
    sceCdDiskReady(0);
    printf("iop reboot 260!\n");
    do {

    } while (sceSifLoadModule("cdrom0:\\MODULE\\SIO2MAN.IRX;1", 0, 0) < 0);
    do {

    } while (sceSifLoadModule("cdrom0:\\MODULE\\MCMAN.IRX;1", 0, 0) < 0);
    do {

    } while (sceSifLoadModule("cdrom0:\\MODULE\\MCSERV.IRX;1", 0, 0) < 0);
    do {

    } while (sceSifLoadModule("cdrom0:\\MODULE\\PADMAN.IRX;1", 0, 0) < 0);
    do {

    } while (sceSifLoadModule("cdrom0:\\MODULE\\LIBSD.IRX;1", 0, 0) < 0);
    do {

    } while (sceSifLoadModule("cdrom0:\\MODULE\\EZBGM.IRX;1", 0, 0) < 0);
    printf("cd modules ok!\n");
}


void sys_reset_gs_path(void) {
    sceDevVif0Reset();
    sceDevVu0Reset();
    sceGsResetPath();
    sceDmaReset(1);
}

extern void sceDmaPutEnv(void *);
extern void sceDmaGetEnv(void *);

void sys_init_display(void) {
    s16 env[16];

    sceDmaGetEnv(env);
    env[3] = 2;
    sceDmaPutEnv(env);
    sceGsResetGraph(0, 1, 2, 0);
    sceGsSetDefDBuffDc(&g_gs_dbuff, 2, 0x200, 0x1C0, 1, 0x31, 0);
    g_gs_dbuff.clear0.rgbaq = 0;
    g_gs_dbuff.clear1.rgbaq = 0;
}


void sys_start(void) {
    printf("--start--\n");
    g_stage_map_progress = 0;
    sys_init();
}

s32 func_0018C890();
s32 font_init();
s32 func_0022C630();
extern s16 g_loaded_stage;
extern u8 D_0028E400;
extern u8 *g_pad_dma_buf_as_u8_p;
extern u8 D_0028EB00_as_u8;
extern u8 g_pad_dma_area[];
void sys_init(void) {
    iop_reboot_and_load_modules();
    sys_reset_gs_path();
    sys_init_display();
    vram_clear_all();
    g_dma_gif = sceDmaGetChan(2);
    display_reset();
    render_target_init(&g_render_target, g_gif_buf, 0x12C0, 0x200, 0x100);
    pad_init_system();
    g_pad_dma_buf_as_u8_p = (u8 *)(g_pad_dma_area);
    *(s32 *)0x10000010 = 0x83;
    g_loaded_stage = 0xFF;
    g_frame_counter = 0;
    D_0028E400 = 0;
    g_display_reset_pending = 0;
    D_0028EB00_as_u8 = 0;
    fade_reset();
    func_0018C890();
    tex_load_common();
    font_init();
    sceMcInit();
    func_0022C630();
}

s32 func_0016A710();                            /* extern */
s32 text_queue_clear();                            /* extern */
s32 func_0021DF60();                            /* extern */

void sys_begin_frame(void) {
    *(s32 *)0x10000000 = 0;
    sceGsSwapDBuffDc(&g_gs_dbuff, g_frame_counter);
    text_queue_clear();
    pad_update();
    func_0016A710();
    if (g_display_reset_pending != 0) {
        g_display_reset_pending = 0;
        func_0021DF60();
        display_reset();
    }
    if (g_screen_mode < 2) {
        framebuffer_begin(g_gif_buf);
        return;
    }
    render_target_begin(&g_render_target, g_gif_buf);
}

s32 func_0018E020();
s32 text_flush_rects();
s32 arcade_sprite_draw();
s32 func_0021FA50();
s32 func_00221CF0();
s32 func_002244E0();
s32 func_002256C0();
s32 func_00225EF0();
s32 func_0022B870();
s32 func_0022C5A0();
extern u8 D_0028E21C;
extern u8 D_0028E310;
extern u16 D_0028E32C;
extern u8 D_0028E378;
extern u8 D_0028E37C;
extern u16 D_0028E3F0;
extern u16 g_scroll_line;
void sys_end_frame(void) {
    s32 half;

    bg_layer_draw();
#ifndef DEATH_LABEL
    splash_image_draw();
#endif
    arcade_sprite_draw();
    text_layer_draw();
    sys_draw_replay_label();
    func_0021FA50();
    func_00221CF0();
    func_002244E0();
    func_0022B870();
    func_00225EF0();
    func_0022C5A0();
    func_002256C0();
    fade_update_and_draw();
    if (g_screen_mode >= 2) {
        if (g_screen_mode >= 4) {
            render_target_present_wide(&g_render_target, g_gif_buf);
        } else {
            framebuffer_begin_present(g_gif_buf);
            if (D_0028E32C != 5) {
                wallpaper_draw(g_gif_buf);
            }
            render_target_present(&g_render_target, g_gif_buf);
        }
    }
    pause_check_start_button();
    stage_map_update();
    text_flush_rects();
    func_0018E020();
    vibration_update();
    sceGsSyncPath(0, 0);
    g_frame_counter += 1;
    D_0028E37C = 1;
    half = (sceGsSyncV(0) != 0) ^ 1;
    if (D_0028E378 == 1) {
        D_0028E378 = 0;
    } else if (D_0028E37C != 0) {
        if (D_0028E21C == 2) {
            sceGsSyncV(0);
        } else {
            if (D_0028E310 != 0) {
                D_0028E310 -= 1;
            }
            if ((D_0028E310 != 0) && (D_0028E3F0 & 1)) {
                sceGsSyncV(0);
            }
        }
        D_0028E37C &= 1;
    }
    D_0028E21C = 0;
    if ((g_screen_mode != 2) && (g_screen_mode != 3)) {
        if (g_frame_counter & 1) {
            sceGsSetHalfOffset(&g_gs_dbuff.draw11, 0x800, 0x800, half);
            sceGsSetHalfOffset2(&g_gs_dbuff.draw12, 0x800, 0x800, half);
        } else {
            sceGsSetHalfOffset(&g_gs_dbuff.draw01, 0x800, 0x800, half);
            sceGsSetHalfOffset2(&g_gs_dbuff.draw02, 0x800, 0x800, half);
        }
    }
    if (g_scroll_line > g_stage_map_progress) {
        g_stage_map_progress = g_scroll_line;
    }
    FlushCache(0);
    sceGsSyncPath(0, 0);
}

extern u8 D_0028E370;
extern u16 D_0028E3C0;
extern s8 D_0028E3F8;
extern u8 D_0028ED58;
extern u8 D_0028ED74;
extern u8 D_0028ED7C;
extern u16 D_006C58A4[];

void sys_draw_replay_label(void) {
    s32 var_a2;
    s32 var_a2_2;

#ifdef DEATH_LABEL
    if ((D_0028E370 != 0) && (D_0028E3F8 != 0) && (D_0028ED74 == 1) && (D_0028ED7C == 2)) {
#else
    if ((D_0028E370 != 0) && (D_0028E3F8 != 0) && (D_0028E3C0 == 0) && (D_0028ED74 == 1) && (D_0028ED7C == 2)) {
#endif
        if (D_0028ED58 != 0) {
            var_a2 = 0x88;
            if (D_006C58A4[0] == 0xFF) {
                var_a2 = 0x18;
            }
            label_draw(&g_render_target, 2, var_a2, "OVERRIDE");
            return;
        }
        var_a2_2 = 0x90;
        if (D_006C58A4[0] == 0xFF) {
            var_a2_2 = 0x20;
        }
        label_draw(&g_render_target, 2, var_a2_2, "REPLAY");
    }
}

extern u16 g_arcade_coin_port_as_u16;
extern s8 g_arcade_input_port[];
extern u8 g_p1_btn_map_a_as_u8;
extern u8 g_p1_btn_map_b;
extern u8 g_p1_btn_map_c;
extern u8 g_p2_btn_map_a;
extern u8 g_p2_btn_map_b;
extern u8 g_p2_btn_map_c;
extern u8 g_pad_tate_rotate;

void pad_update(void)
{
    s32 padIndex;
    u32 buttons;

    pad_poll_hardware();

    for (padIndex = 0; padIndex < 3; padIndex++) {
        g_pad_unused[padIndex] = 0;

        if (g_pads[padIndex].analogX > -64 && g_pads[padIndex].analogX < 64) {
            g_pads[padIndex].analogX = 0;
        }
        if (g_pads[padIndex].analogY > -64 && g_pads[padIndex].analogY < 64) {
            g_pads[padIndex].analogY = 0;
        }

        g_pad_held[padIndex] = g_pads[padIndex].rawButtons;
        if (g_pads[padIndex].analogX < 0) {
            g_pad_held[padIndex] |= SCE_PADLleft;
        }
        if (g_pads[padIndex].analogX > 0) {
            g_pad_held[padIndex] |= SCE_PADLright;
        }
        if (g_pads[padIndex].analogY < 0) {
            g_pad_held[padIndex] |= SCE_PADLup;
        }
        if (g_pads[padIndex].analogY > 0) {
            g_pad_held[padIndex] |= SCE_PADLdown;
        }

        if (g_pad_tate_rotate != 0) {
            buttons = g_pad_held[padIndex];
            g_pad_held[padIndex] = buttons & 0xFFF;
            if (buttons & SCE_PADLup) {
                g_pad_held[padIndex] |= SCE_PADLleft;
            }
            if (buttons & SCE_PADLdown) {
                g_pad_held[padIndex] |= SCE_PADLright;
            }
            if (buttons & SCE_PADLright) {
                g_pad_held[padIndex] |= SCE_PADLup;
            }
            if (buttons & SCE_PADLleft) {
                g_pad_held[padIndex] |= SCE_PADLdown;
            }
        }

        if (g_pad_held[padIndex] == 0) {
            g_pad_repeat_timer[padIndex] = 0;
            g_pad_repeat[padIndex] = 0;
            g_pad_fast_repeat_timer[padIndex] = 0;
            g_pad_fast_repeat[padIndex] = 0;
        }

        if (g_pad_held[padIndex] == g_pad_prev_held[padIndex]) {
            g_pad_repeat_timer[padIndex]++;
            if (g_pad_repeat_timer[padIndex] > 10) {
                g_pad_repeat[padIndex] = g_pad_held[padIndex];
                g_pad_repeat_timer[padIndex] = 0;
            } else {
                g_pad_repeat[padIndex] = 0;
            }

            g_pad_fast_repeat_timer[padIndex]++;
            if (g_pad_fast_repeat_timer[padIndex] > 10) {
                g_pad_fast_repeat[padIndex] = g_pad_held[padIndex];
                if (g_pad_fast_repeat_timer[padIndex] > 14) {
                    g_pad_fast_repeat_timer[padIndex] = 10;
                }
            } else {
                g_pad_fast_repeat[padIndex] = 0;
            }
        } else if (g_pad_prev_held[padIndex] == 0) {
            g_pad_repeat[padIndex] = g_pad_held[padIndex];
            g_pad_repeat_timer[padIndex] = 0;
            g_pad_fast_repeat[padIndex] = g_pad_held[padIndex];
            g_pad_fast_repeat_timer[padIndex] = 0;
        } else {
            g_pad_repeat_timer[padIndex]++;
            if (g_pad_repeat_timer[padIndex] > 10) {
                g_pad_repeat[padIndex] = g_pad_held[padIndex];
                g_pad_repeat_timer[padIndex] = 0;
            } else {
                g_pad_repeat[padIndex] = 0;
            }

            g_pad_fast_repeat_timer[padIndex]++;
            if (g_pad_fast_repeat_timer[padIndex] > 10) {
                g_pad_fast_repeat[padIndex] = g_pad_held[padIndex];
                g_pad_fast_repeat_timer[padIndex] = 10;
            } else {
                g_pad_fast_repeat[padIndex] = 0;
            }
        }

        g_pad_trigger[padIndex] = g_pad_prev_held[padIndex] ^ g_pad_held[padIndex];
        g_pad_trigger[padIndex] &= g_pad_held[padIndex];
        g_pad_prev_held[padIndex] = g_pad_held[padIndex];

        if (g_pad_fast_repeat[padIndex] & 0x5000) {
            g_pad_fast_repeat[padIndex] = 0;
            g_pad_fast_repeat_timer[padIndex] = 0;
        }
    }

    reg_a0 = (u8 *)g_arcade_input_port;
    reg_d0.w = 0;
    buttons = g_pad_held[0];
    if (buttons & SCE_PADstart) {
        *(u8 *)&reg_d0 |= 0x01;
    }
    if (buttons & SCE_PADLup) {
        *(u8 *)&reg_d0 |= 0x02;
    }
    if (buttons & SCE_PADLdown) {
        *(u8 *)&reg_d0 |= 0x04;
    }
    if (buttons & SCE_PADLleft) {
        *(u8 *)&reg_d0 |= 0x08;
    }
    if (buttons & SCE_PADLright) {
        *(u8 *)&reg_d0 |= 0x10;
    }
    if (buttons & (1 << g_p1_btn_map_a_as_u8)) {
        *(u8 *)&reg_d0 |= 0x20;
    }
    if (buttons & (1 << g_p1_btn_map_b)) {
        *(u8 *)&reg_d0 |= 0x40;
    }
    if (buttons & (1 << g_p1_btn_map_c)) {
        *(u8 *)&reg_d0 |= 0x80;
    }
    *reg_a0 = ~*(u8 *)&reg_d0;
    reg_a0++;

    reg_d0.w = 0;
    buttons = g_pad_held[1];
    if (buttons & SCE_PADstart) {
        *(u8 *)&reg_d0 |= 0x01;
    }
    if (buttons & SCE_PADLup) {
        *(u8 *)&reg_d0 |= 0x02;
    }
    if (buttons & SCE_PADLdown) {
        *(u8 *)&reg_d0 |= 0x04;
    }
    if (buttons & SCE_PADLleft) {
        *(u8 *)&reg_d0 |= 0x08;
    }
    if (buttons & SCE_PADLright) {
        *(u8 *)&reg_d0 |= 0x10;
    }
    if (buttons & (1 << g_p2_btn_map_a)) {
        *(u8 *)&reg_d0 |= 0x20;
    }
    if (buttons & (1 << g_p2_btn_map_b)) {
        *(u8 *)&reg_d0 |= 0x40;
    }
    if (buttons & (1 << g_p2_btn_map_c)) {
        *(u8 *)&reg_d0 |= 0x80;
    }
    *reg_a0 = ~*(u8 *)&reg_d0;

    reg_a0 = (u8 *)&g_arcade_coin_port_as_u16;
    reg_d0.w = 0;
    if (g_pad_held[0] & SCE_PADselect) {
        *(u8 *)&reg_d0 |= 0x01;
    }
    if (g_pad_held[1] & SCE_PADselect) {
        *(u8 *)&reg_d0 |= 0x02;
    }
    *(u16 *)reg_a0 = ~*(u16 *)&reg_d0;

    pad_mask_game_inputs();
}

s32 func_0016A6F0();                            /* extern */
extern s8 D_0028E249[];
extern s8 D_0028E24A[];
extern s8 D_0028E24B[];
extern s8 D_0028E24C[];
extern s8 D_0028E24D[];
extern s8 D_0028E24E[];
extern s8 D_0028E24F[];
extern u8 g_pad_input_locked;

void pad_mask_game_inputs(void) {
    if (g_pad_input_locked != 0) {
        g_arcade_input_port[0] = -1;
        D_0028E249[0] = -1;
        D_0028E24A[0] = -1;
        D_0028E24B[0] = -1;
        D_0028E24C[0] = -1;
        D_0028E24D[0] = -1;
        D_0028E24E[0] = -1;
        D_0028E24F[0] = -1;
        func_0016A6F0();
    }
}

extern void func_0018DA30(void);
extern s16 g_pause_player_as_s16;
extern u8 g_stage_load_state;
extern u8 g_pause_lock_timer;
extern u8 D_0028E368;
extern u8 g_paused;
extern s8 D_0028EC24;
extern s16 g_player2[];
extern s16 g_player1[];

void pause_check_start_button(void) {
    s32 state;
    s32 busy;
    s32 wait;

    state = g_paused;
    if (state != 0) {
        return;
    }
    switch (D_0028E368) {
    case 0:
        goto block_rts;
    }
    busy = g_stage_load_state;
    if (busy != 0) {
        return;
    }
    if (D_0028E3C0 != 0) {
        return;
    }
    wait = g_pause_lock_timer;
    if (wait == 0xFF) {
        return;
    }
    if ((s8)wait > 0) {
        g_pause_lock_timer = wait - 1;
        return;
    }
    g_pause_lock_timer = 0;
    if (!(g_pad_trigger[2] & 0x800)) {
        return;
    }
    if ((u8)busy != 0) {
        return;
    }
    if ((u8)state == 0xB) {
        return;
    }
    if (D_0028ED7C == 2) {
        if (!(g_pad_trigger[D_0028EC24] & 0x800)) {
            return;
        }
        if (D_0028ED58 != 0 && g_player1[0] == 0 && g_player2[0] == 0) {
            return;
        }
        func_0018DA30();
        g_paused = 1;
        g_pause_player_as_s16 = D_0028EC24;
block_rts:
        return;
    }
    if ((g_pad_trigger[0] & 0x800) && g_player1[0] < 0) {
        func_0018DA30();
        g_pause_player_as_s16 = 0;
        g_paused = 1;
        return;
    }
    if ((g_pad_trigger[1] & 0x800) && g_player2[0] < 0) {
        func_0018DA30();
        g_paused = 1;
        g_pause_player_as_s16 = 1;
    }
}


void pad_init_system(void) {
    memset(g_pads, 0, 0xB4);
    g_pad_held[0] = 0;
    g_pad_trigger[0] = 0;
    g_pad_repeat[0] = 0;
    g_pad_prev_held[0] = 0;
    g_pad_repeat_timer[0] = 0;
    g_pad_unused[0] = 0;
    g_pad_held[1] = 0;
    g_pad_trigger[1] = 0;
    g_pad_repeat[1] = 0;
    g_pad_prev_held[1] = 0;
    g_pad_repeat_timer[1] = 0;
    g_pad_unused[1] = 0;
    g_pad_held[2] = 0;
    g_pad_trigger[2] = 0;
    g_pad_repeat[2] = 0;
    g_pad_prev_held[2] = 0;
    g_pad_repeat_timer[2] = 0;
    g_pad_unused[2] = 0;
    scePadInit(0);
    scePadPortOpen(0, 0, g_pad_dma_buf_0);
    scePadPortOpen(1, 0, g_pad_dma_buf_1);
}


void pad_poll_hardware(void)
{
    s32 port;
    PadInfo *pad;
    for (pad = g_pads, port = 0; port < 2; port++, pad++) {
        s32 padState;
        pad->rawButtons = 0;
        pad->analogX = 0;
        pad->analogY = 0;
#ifdef DEATH_LABEL
        pad->rightX = 0;
        pad->rightY = 0;
#endif
        padState = scePadGetState(port, 0);
        if (padState == 0) {
            pad->state = 0;
        }
        switch (pad->state) {
            case 0x00:
                if ((padState == 6) || (padState == 2)) {
                    s32 mode = scePadInfoMode(port, 0, 1, 0);
                    if (mode != 0) {
                        s32 exMode = scePadInfoMode(port, 0, 2, 0);
                        if (exMode > 0) {
                            mode = exMode;
                        }
                        if (mode == 4) {
                            pad->state = 0x28;
                        } else if (mode == 7) {
                            pad->state = 0x46;
                        } else {
                            pad->state = 0x80;
                        }
                    }
                }
                break;

            case 0x28:
                if (scePadInfoMode(port, 0, 4, -1) == 0) {
                    pad->state = 0x80;
                    pad->padTypeFlag = 1;
                    break;
                }
                pad->state++;

            case 0x29:
                if (scePadSetMainMode(port, 0, 1, 3) == 1) {
                    pad->state++;
                }
                break;

            case 0x2A:
                if (scePadGetReqState(port, 0) == 1) {
                    pad->state--;
                }
                if (scePadGetReqState(port, 0) == 0) {
                    pad->state = 0;
                }
                break;

            case 0x46:
                if (scePadInfoAct(port, 0, -1, 0) == 0) {
                    pad->state = 0x80;
                    pad->padTypeFlag = 2;
                    break;
                }
                g_pad_act_align[0] = g_pad_act_direct[5] = g_pad_act_direct[4] = g_pad_act_direct[3] = g_pad_act_direct[2] = g_pad_act_direct[1] = g_pad_act_direct[0] = 0;
                g_pad_act_align[5] = g_pad_act_align[4] = g_pad_act_align[3] = g_pad_act_align[2] = 0xFF;
                g_pad_act_align[1] = 1;
                if (scePadSetActAlign(port, 0, g_pad_act_align) != 0) {
                    pad->state++;
                }
                break;

            case 0x47:
                if (scePadGetReqState(port, 0) == 1) {
                    pad->state--;
                }
                if (scePadGetReqState(port, 0) == 0) {
                    pad->state++;
                }
                break;

            case 0x48:
                if (scePadInfoPressMode(port, 0) == 0) {
                    pad->prevPadId = 0;
                    pad->state = 0x80;
                    pad->padTypeFlag = 4;
                    break;
                }
                pad->state = 0x4C;

            case 0x4C:
                if (scePadEnterPressMode(port, 0) == 0) {
                    pad->state = 0x48;
                } else {
                    pad->state++;
                }
                break;

            case 0x4D:
                if (scePadGetReqState(port, 0) == 1) {
                    pad->state--;
                }
                if (scePadGetReqState(port, 0) == 0) {
                    pad->state = 0x80;
                    pad->padTypeFlag = 8;
                }
                break;

            case 0x80:
                if ((padState == 6) || (padState == 2)) {
                    u32 rawBtns;
                    pad->prevButtons = pad->buttons;
                    if (scePadRead(port, 0, pad->raw) > 0) {
                        if (pad->padTypeFlag & 0xE) {
                            s8 rx = pad->raw[4] - 0x80;
                            s8 ry = pad->raw[5] - 0x80;
                            s8 lx = pad->raw[6] - 0x80;
                            s8 ly = pad->raw[7] - 0x80;
                            pad->analogX = (((rx >= 0) ? (rx) : (-rx)) > ((lx >= 0) ? (lx) : (-lx))) ? (rx) : (lx);
                            pad->analogY = (((ry >= 0) ? (ry) : (-ry)) > ((ly >= 0) ? (ly) : (-ly))) ? (ry) : (ly);
                        }
                        rawBtns = ((pad->raw[2] << 8) | pad->raw[3]) ^ 0xFFFF;
                        pad->rawButtons = rawBtns;
                    } else {
                        pad->rawButtons = 0;
                        pad->analogX = 0;
                        pad->analogY = 0;
                        break;
                    }
                    pad->buttons = rawBtns;
                    pad->trigger = (~pad->prevButtons) & rawBtns;
                    pad->padId = pad->raw[1];
                    if ((pad->prevPadId != 0) && (pad->padId != pad->prevPadId)) {
                        pad->prevPadId = 0;
                        pad->state = 0;
                    }
                    pad->prevPadId = pad->padId;
                }
                break;
        }
    }

    g_pads[2].rawButtons = g_pads[0].rawButtons | g_pads[1].rawButtons;
    g_pads[2].buttons = g_pads[0].buttons | g_pads[1].buttons;
    g_pads[2].trigger = g_pads[0].trigger | g_pads[1].trigger;
    g_pads[2].analogX = (((g_pads[0].analogX >= 0) ? (g_pads[0].analogX) : (-g_pads[0].analogX)) > ((g_pads[1].analogX >= 0) ? (g_pads[1].analogX) : (-g_pads[1].analogX))) ? (g_pads[0].analogX) : (g_pads[1].analogX);
    g_pads[2].analogY = (((g_pads[0].analogY >= 0) ? (g_pads[0].analogY) : (-g_pads[0].analogY)) > ((g_pads[1].analogY >= 0) ? (g_pads[1].analogY) : (-g_pads[1].analogY))) ? (g_pads[0].analogY) : (g_pads[1].analogY);
    g_pads[2].extraButtons = g_pads[0].extraButtons | g_pads[1].extraButtons;
}


void vram_clear_all(void)
{
    u32 *buffer;
    u32 wordIndex;
    s32 vramBase;
    u32 blockIndex;

    buffer = malloc(0x40000);
    for (wordIndex = 0; wordIndex < 0x10000; wordIndex++) {
        buffer[wordIndex] = 0;
    }

    for (blockIndex = 0, vramBase = 0; blockIndex < 0x10; blockIndex++, vramBase += 0x400) {
        sceGsSetDefLoadImage(&g_gs_load_image, (s16)vramBase, 4, 0, 0, 0, 0x100, 0x100);
        FlushCache(0);
        sceGsExecLoadImage(&g_gs_load_image, buffer);
        sceGsSyncPath(0, 0);
    }

    free(buffer);
}


#ifdef DEATH_LABEL
#endif

void fade_reset(void) {
    g_fade_state = 0;
    g_fade_alpha = 0;
#ifdef DEATH_LABEL
    g_fade_white = 0;
#endif
}

#ifdef DEATH_LABEL
#endif

void fade_start_in(void) {
#ifdef DEATH_LABEL
    g_fade_white = 0;
#endif
    g_fade_state = 1;
}

#ifdef DEATH_LABEL
#endif

void fade_start_out(void) {
#ifdef DEATH_LABEL
    g_fade_white = 0;
#endif
    g_fade_state = 2;
}

#ifdef DEATH_LABEL
void death_func_001B1220(void) {
    g_fade_state = 2;
    g_fade_white = 1;
}
#endif


#ifdef DEATH_LABEL
#endif

void fade_update_and_draw(void) {
    switch (g_fade_state) {                           /* irregular */
    case 0:
        break;
    case 1:
        g_fade_state = 3;
        g_fade_alpha = 0x80;
        g_fade_step = -8;
        break;
    case 2:
        g_fade_state = 3;
        g_fade_step = 8;
        g_fade_alpha = 0;
        break;
    case 3:
        g_fade_alpha += g_fade_step;
        if (g_fade_alpha < 0) {
            g_fade_alpha = 0;
            g_fade_state = 0;
        }
        if (g_fade_alpha > 0x80) {
            g_fade_state = 0;
            g_fade_alpha = 0x80;
        }
        break;
    }
#ifdef DEATH_LABEL
    if (g_fade_alpha != 0) {
        if (g_fade_white == 0) {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x1F4, g_fade_alpha, 1, 1, 1);
        } else {
            gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x1F4, g_fade_alpha, 0xFF, 0xFF, 0xFF);
        }
    }
#else
    if (g_fade_alpha != 0) {
        gfx_draw_color_box(0, 0, 0x1C2, 0xE0, 0x1F4, g_fade_alpha, 1, 1, 1);
    }
#endif
}


void vibration_stop_all(void)
{
    extern s8 g_pad_vib_state_p2;
    extern s8 g_pad_vib_state_p1;
    s32 zero;

    g_pad_vib_state_p1 = 0;
    g_pad_vib_state_p2 = 0;
    g_pad_act_direct[1] = 0;
    scePadSetActDirect(zero = 0, zero, g_pad_act_direct);
    scePadSetActDirect(1, 0, g_pad_act_direct);
}


void vibration_stop_pad1(void) {
    extern s8 g_pad_vib_state_p1;
    s32 zero;

    g_pad_vib_state_p1 = 0;
    g_pad_act_direct[1] = 0;
    scePadSetActDirect(zero = 0, zero, g_pad_act_direct);
}


void vibration_stop_pad2(void) {
    extern s8 g_pad_vib_state_p2;
    g_pad_vib_state_p2 = 0;
    g_pad_act_direct[1] = 0;
    scePadSetActDirect(1, 0, g_pad_act_direct);
}

extern u8 g_pad_vib_enabled;
void vibration_start_pad1(s16 arg0, s16 arg1) {
    extern s16 g_pad_vib_power_p1;
    extern s16 g_pad_vib_timer_p1;
    extern s8 g_pad_vib_state_p1;
    if ((D_0028E3C0 == 0) && (g_pad_vib_enabled != 0)) {
        if (D_0028ED7C == 2) {
            if (D_0028ED58 != 0) {
                vibration_start_active_pad(arg0, arg1);
            }
        } else if (g_player1[0] < 0) {
            g_pad_vib_power_p1 = arg0;
            g_pad_vib_state_p1 = 1;
            g_pad_vib_timer_p1 = arg1;
        }
    }
}

void vibration_start_pad2(s16 arg0, s16 arg1) {
    extern s16 g_pad_vib_power_p2;
    extern s16 g_pad_vib_timer_p2;
    extern s8 g_pad_vib_state_p2;
    if ((D_0028E3C0 == 0) && (g_pad_vib_enabled != 0)) {
        if (D_0028ED7C == 2) {
            if (D_0028ED58 != 0) {
                vibration_start_active_pad(arg0, arg1);
            }
        } else if (g_player2[0] < 0) {
            g_pad_vib_power_p2 = arg0;
            g_pad_vib_state_p2 = 1;
            g_pad_vib_timer_p2 = arg1;
        }
    }
}

void vibration_start_active_pad(s16 arg0, s16 arg1) {
    extern s16 g_pad_vib_power_p2;
    extern s16 g_pad_vib_power_p1;
    extern s16 g_pad_vib_timer_p2;
    extern s16 g_pad_vib_timer_p1;
    extern s8 g_pad_vib_state_p2;
    extern s8 g_pad_vib_state_p1;
    if (D_0028EC24 == 0) {
        g_pad_vib_power_p1 = arg0;
        g_pad_vib_state_p1 = 1;
        g_pad_vib_timer_p1 = arg1;
        return;
    }
    g_pad_vib_power_p2 = arg0;
    g_pad_vib_state_p2 = 1;
    g_pad_vib_timer_p2 = arg1;
}

extern u16 g_pad_vib_saved_power_p2;
extern u16 g_pad_vib_saved_power_p1;
extern u16 g_pad_vib_saved_timer_p2;
extern u16 g_pad_vib_saved_timer_p1;

void vibration_suspend(void) {
    extern u16 g_pad_vib_power_p2;
    extern u16 g_pad_vib_power_p1;
    extern u16 g_pad_vib_timer_p2;
    extern u16 g_pad_vib_timer_p1;
    extern u8 g_pad_vib_state_p2;
    extern u8 g_pad_vib_state_p1;
    g_pad_vib_saved_power_p1 = 0;
    g_pad_vib_saved_timer_p1 = 0;
    g_pad_vib_saved_power_p2 = 0;
    g_pad_vib_saved_timer_p2 = 0;
    if (g_pad_vib_state_p1 != 0) {
        g_pad_vib_saved_power_p1 = g_pad_vib_power_p1;
        g_pad_vib_saved_timer_p1 = g_pad_vib_timer_p1;
    }
    if (g_pad_vib_state_p2 != 0) {
        g_pad_vib_saved_power_p2 = g_pad_vib_power_p2;
        g_pad_vib_saved_timer_p2 = g_pad_vib_timer_p2;
    }
}

void vibration_resume(void)
{
    extern u16 g_pad_vib_power_p2;
    extern u16 g_pad_vib_power_p1;
    extern u16 g_pad_vib_timer_p2;
    extern u16 g_pad_vib_timer_p1;
    extern s8 g_pad_vib_state_p2;
    extern s8 g_pad_vib_state_p1;
    if (g_pad_vib_enabled != 0) {
        if (g_pad_vib_saved_timer_p1 > 0x3C) {
            g_pad_vib_timer_p1 = g_pad_vib_saved_timer_p1;
            g_pad_vib_state_p1 = 1;
            g_pad_vib_power_p1 = g_pad_vib_saved_power_p1;
        }

        if (g_pad_vib_saved_timer_p2 > 0x3C) {
            g_pad_vib_timer_p2 = g_pad_vib_saved_timer_p2;
            g_pad_vib_state_p2 = 1;
            g_pad_vib_power_p2 = g_pad_vib_saved_power_p2;
        }
    }
}

#pragma push
#pragma opt_propagation off

void vibration_update(void) {
    extern u8 g_pad_vib_power_p2;
    extern u8 g_pad_vib_power_p1;
    extern u16 g_pad_vib_timer_p2;
    extern u16 g_pad_vib_timer_p1;
    extern u8 g_pad_vib_state_p2;
    extern u8 g_pad_vib_state_p1;
    s32 slot;

    if (D_0028E3C0 != 0) {
        return;
    }
    slot = 0;
    switch (g_pad_vib_state_p1) {
    case 0:
        break;
    case 1:
        g_pad_act_direct[1] = g_pad_vib_power_p1;
        scePadSetActDirect(0, slot, g_pad_act_direct);
        g_pad_vib_state_p1 += 1;
        break;
    case 2:
        g_pad_vib_timer_p1 -= 1;
        if ((s32)g_pad_vib_timer_p1 <= 0) {
            g_pad_vib_state_p1 += 1;
        }
        break;
    case 3:
        g_pad_act_direct[1] = 0;
        scePadSetActDirect(0, slot, g_pad_act_direct);
        g_pad_vib_state_p1 = 0;
        break;
    }
    switch (g_pad_vib_state_p2) {
    case 0:
        break;
    case 1:
        g_pad_act_direct[1] = g_pad_vib_power_p2;
        scePadSetActDirect(1, 0, g_pad_act_direct);
        g_pad_vib_state_p2 += 1;
        break;
    case 2:
        g_pad_vib_timer_p2 -= 1;
        if ((s32)g_pad_vib_timer_p2 <= 0) {
            g_pad_vib_state_p2 += 1;
        }
        break;
    case 3:
        g_pad_act_direct[1] = 0;
        scePadSetActDirect(1, 0, g_pad_act_direct);
        g_pad_vib_state_p2 = 0;
        break;
    }
}
#pragma pop

#ifndef DEATH_LABEL
/* Cleared once at boot and never read. */
typedef struct {
    s32 values[8];
    s8 flags[4];
} BootScratch;

extern BootScratch g_boot_scratch;

void boot_scratch_clear(void) {
    g_boot_scratch.values[0] = 0;
    g_boot_scratch.values[1] = 0;
    g_boot_scratch.values[2] = 0;
    g_boot_scratch.values[3] = 0;
    g_boot_scratch.values[4] = 0;
    g_boot_scratch.values[5] = 0;
    g_boot_scratch.values[6] = 0;
    g_boot_scratch.values[7] = 0;
    g_boot_scratch.flags[0] = 0;
    g_boot_scratch.flags[1] = 0;
    g_boot_scratch.flags[2] = 0;
    g_boot_scratch.flags[3] = 0;
}
#endif

u8 g_pad_act_direct[6] __attribute__((aligned(64)));
u8 g_pad_act_align[6] __attribute__((aligned(64)));
void *g_pad_dma_buf;
void *g_dma_gif;
s32 g_frame_counter;
s8 g_display_reset_pending __attribute__((aligned(4)));
s8 g_fade_state __attribute__((aligned(4)));
#ifdef DEATH_LABEL
s8 g_fade_white __attribute__((aligned(4)));
#endif
s16 g_fade_step __attribute__((aligned(4)));
s16 g_fade_alpha __attribute__((aligned(4)));
s32 g_stage_map_progress;

u8 g_pad_dma_buf_1[0x100] __attribute__((aligned(64)));
u8 g_pad_dma_buf_0[0x100] __attribute__((aligned(64)));
PadInfo g_pads[3];
u32 g_pad_held[4];
u32 g_pad_trigger[4];
u32 g_pad_repeat[4];
u32 g_pad_fast_repeat[4];
u32 g_pad_prev_held[4];
u32 g_pad_repeat_timer[4];
u32 g_pad_fast_repeat_timer[4];
u32 g_pad_unused[4];
u8 g_pad_dma_area[0x100];
sceGsDBuffDc g_gs_dbuff;
sceGsLoadImage g_gs_load_image __attribute__((aligned(64)));
u8 g_glyph_upload_buf[32][512] __attribute__((aligned(64)));
u8 g_gif_buf[2][0x10000] __attribute__((aligned(64)));
u8 g_load_buf[0x4B000] __attribute__((aligned(64)));
u8 g_splash_file_buf[0x20800] __attribute__((aligned(64)));
#ifdef DEATH_LABEL
u8 g_noise_file_buf[0x20800] __attribute__((aligned(64)));
#endif
u8 g_stage_map_file_buf[0x20000] __attribute__((aligned(64)));
u8 g_bg_tile_pixels[0x208000] __attribute__((aligned(64)));
#ifndef DEATH_LABEL
u8 g_unreferenced_2C4F40[0x40] __attribute__((aligned(64))); /* nothing reads or writes this */
BootScratch g_boot_scratch __attribute__((aligned(64)));
#endif
