#include "common.h"
#include "sdk/ps2sdk.h"
#include "gfx_types.h"

void sys_init(void);
void sys_draw_replay_label(void);
void pad_update(void);
void pad_mask_game_inputs(void);
void pause_check_start_button(void);
void pad_init_system(void);
void pad_poll_hardware(void);
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
extern s64 D_0057C960[];
extern s64 D_0057CAD0[];

void sys_init_display(void) {
    extern u8 g_gs_dbuff[];
    s16 env[16];

    sceDmaGetEnv(env);
    env[3] = 2;
    sceDmaPutEnv(env);
    sceGsResetGraph(0, 1, 2, 0);
    sceGsSetDefDBuffDc(g_gs_dbuff, 2, 0x200, 0x1C0, 1, 0x31, 0);
    D_0057C960[0] = 0;
    D_0057CAD0[0] = 0;
}

extern s32 D_0028E9DC;

void sys_start(void) {
    printf("--start--\n");
    D_0028E9DC = 0;
    sys_init();
}

s32 func_0018C890();
s32 font_init();
s32 tex_load_common();
s32 func_0021A640();
s32 display_reset();
s32 func_0022C630();
extern s16 D_0028E3FC;
extern u8 D_0028E400;
extern s32 g_frame_counter;
extern void *g_dma_gif;
extern u8 *D_0028E9F8_as_u8_p;
extern u8 D_0028EB00_as_u8;
extern u8 D_0057CB10[];
void sys_init(void) {
    extern u8 D_0028E9EC;
    extern u8 g_gif_buf[];
    extern u8 D_00586FF0[];
    iop_reboot_and_load_modules();
    sys_reset_gs_path();
    sys_init_display();
    vram_clear_all();
    g_dma_gif = sceDmaGetChan(2);
    display_reset();
    func_0021A640(D_00586FF0, g_gif_buf, 0x12C0, 0x200, 0x100);
    pad_init_system();
    D_0028E9F8_as_u8_p = (u8 *)(D_0057CB10);
    *(s32 *)0x10000010 = 0x83;
    D_0028E3FC = 0xFF;
    g_frame_counter = 0;
    D_0028E400 = 0;
    D_0028E9EC = 0;
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
s32 func_0021A920(s32 *, s32 *);        /* extern */
s32 func_0021B400(s32 *);                   /* extern */
s32 display_reset();                            /* extern */
s32 func_0021DF60();                            /* extern */
extern s32 D_0028DC98;

void sys_begin_frame(void) {
    extern s8 D_0028E9EC;
    extern s32 g_gif_buf[];
    extern s32 g_gs_dbuff[];
    extern s32 D_00586FF0[];
    *(s32 *)0x10000000 = 0;
    sceGsSwapDBuffDc(g_gs_dbuff, g_frame_counter);
    text_queue_clear();
    pad_update();
    func_0016A710();
    if (D_0028E9EC != 0) {
        D_0028E9EC = 0;
        func_0021DF60();
        display_reset();
    }
    if (D_0028DC98 < 2) {
        func_0021B400(g_gif_buf);
        return;
    }
    func_0021A920(D_00586FF0, g_gif_buf);
}

s32 func_0018E020();
s32 text_flush_rects();
s32 func_002194C0();
s32 func_002195F0();
s32 func_002199F0();
s32 func_00219D20();
s32 func_0021ABB0();
s32 func_0021AE20();
s32 func_0021B080();
s32 func_0021BAE0();
s32 func_0021C920();
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
extern u16 D_0028E8A8;
extern u8 D_0057C840[];
extern u8 D_0057C8C0[];
extern u8 D_0057C9B0[];
extern u8 D_0057CA30[];
void sys_end_frame(void) {
    extern u8 g_gif_buf[];
    extern u8 D_00586FF0[];
    s32 half;

    func_00219D20();
#ifndef DEATH_LABEL
    func_002194C0();
#endif
    func_0021C920();
    func_002199F0();
    sys_draw_replay_label();
    func_0021FA50();
    func_00221CF0();
    func_002244E0();
    func_0022B870();
    func_00225EF0();
    func_0022C5A0();
    func_002256C0();
    fade_update_and_draw();
    if (D_0028DC98 >= 2) {
        if (D_0028DC98 >= 4) {
            func_0021B080(D_00586FF0, g_gif_buf);
        } else {
            func_0021ABB0(g_gif_buf);
            if (D_0028E32C != 5) {
                func_0021BAE0(g_gif_buf);
            }
            func_0021AE20(D_00586FF0, g_gif_buf);
        }
    }
    pause_check_start_button();
    func_002195F0();
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
    if ((D_0028DC98 != 2) && (D_0028DC98 != 3)) {
        if (g_frame_counter & 1) {
            sceGsSetHalfOffset(D_0057C9B0, 0x800, 0x800, half);
            sceGsSetHalfOffset2(D_0057CA30, 0x800, 0x800, half);
        } else {
            sceGsSetHalfOffset(D_0057C840, 0x800, 0x800, half);
            sceGsSetHalfOffset2(D_0057C8C0, 0x800, 0x800, half);
        }
    }
    if (D_0028E8A8 > D_0028E9DC) {
        D_0028E9DC = D_0028E8A8;
    }
    FlushCache(0);
    sceGsSyncPath(0, 0);
}

s32 label_draw(s32 *, s32, s32, const char *);
extern u8 D_0028E370;
extern u16 D_0028E3C0;
extern s8 D_0028E3F8;
extern u8 D_0028ED58;
extern u8 D_0028ED74;
extern u8 D_0028ED7C;
extern u16 D_006C58A4[];

void sys_draw_replay_label(void) {
    extern s32 D_00586FF0[];
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
            label_draw(D_00586FF0, 2, var_a2, "OVERRIDE");
            return;
        }
        var_a2_2 = 0x90;
        if (D_006C58A4[0] == 0xFF) {
            var_a2_2 = 0x20;
        }
        label_draw(D_00586FF0, 2, var_a2_2, "REPLAY");
    }
}

typedef struct {
    u8 raw[0x20];
    u32 buttons;
    u32 trigger;
    u32 prevButtons;
    u32 rawButtons;
    u16 extraButtons;
    s8 analogX;
    s8 analogY;
    u16 unk34;
    u8 state;
    u8 padId;
    u8 prevPadId;
    u8 padTypeFlag;
    u8 pad3A[2];
} PadState;

extern u16 D_0028E228_as_u16;
extern s8 D_0028E248[];
extern u8 D_0028E270_as_u8;
extern u8 D_0028E271;
extern u8 D_0028E272;
extern u8 D_0028E274;
extern u8 D_0028E275;
extern u8 D_0028E276;
extern u8 *reg_a0;
extern u32 D_0057CC50[];
extern u32 D_0057CC20[];
extern u8 D_0028E2F8;

void pad_update(void)
{
    extern u32 D_0057CC80[];
    extern u32 D_0057CC40[];
    extern u32 D_0057CC60[];
    extern u32 D_0057CC30[];
    extern u32 D_0057CC70[];
    extern u32 D_0057CC10[];
    extern PadState g_pads[];
    s32 padIndex;
    u32 buttons;

    pad_poll_hardware();

    for (padIndex = 0; padIndex < 3; padIndex++) {
        D_0057CC10[padIndex] = 0;

        if (g_pads[padIndex].analogX > -64 && g_pads[padIndex].analogX < 64) {
            g_pads[padIndex].analogX = 0;
        }
        if (g_pads[padIndex].analogY > -64 && g_pads[padIndex].analogY < 64) {
            g_pads[padIndex].analogY = 0;
        }

        D_0057CC80[padIndex] = g_pads[padIndex].rawButtons;
        if (g_pads[padIndex].analogX < 0) {
            D_0057CC80[padIndex] |= SCE_PADLleft;
        }
        if (g_pads[padIndex].analogX > 0) {
            D_0057CC80[padIndex] |= SCE_PADLright;
        }
        if (g_pads[padIndex].analogY < 0) {
            D_0057CC80[padIndex] |= SCE_PADLup;
        }
        if (g_pads[padIndex].analogY > 0) {
            D_0057CC80[padIndex] |= SCE_PADLdown;
        }

        if (D_0028E2F8 != 0) {
            buttons = D_0057CC80[padIndex];
            D_0057CC80[padIndex] = buttons & 0xFFF;
            if (buttons & SCE_PADLup) {
                D_0057CC80[padIndex] |= SCE_PADLleft;
            }
            if (buttons & SCE_PADLdown) {
                D_0057CC80[padIndex] |= SCE_PADLright;
            }
            if (buttons & SCE_PADLright) {
                D_0057CC80[padIndex] |= SCE_PADLup;
            }
            if (buttons & SCE_PADLleft) {
                D_0057CC80[padIndex] |= SCE_PADLdown;
            }
        }

        if (D_0057CC80[padIndex] == 0) {
            D_0057CC30[padIndex] = 0;
            D_0057CC60[padIndex] = 0;
            D_0057CC20[padIndex] = 0;
            D_0057CC50[padIndex] = 0;
        }

        if (D_0057CC80[padIndex] == D_0057CC40[padIndex]) {
            D_0057CC30[padIndex]++;
            if (D_0057CC30[padIndex] > 10) {
                D_0057CC60[padIndex] = D_0057CC80[padIndex];
                D_0057CC30[padIndex] = 0;
            } else {
                D_0057CC60[padIndex] = 0;
            }

            D_0057CC20[padIndex]++;
            if (D_0057CC20[padIndex] > 10) {
                D_0057CC50[padIndex] = D_0057CC80[padIndex];
                if (D_0057CC20[padIndex] > 14) {
                    D_0057CC20[padIndex] = 10;
                }
            } else {
                D_0057CC50[padIndex] = 0;
            }
        } else if (D_0057CC40[padIndex] == 0) {
            D_0057CC60[padIndex] = D_0057CC80[padIndex];
            D_0057CC30[padIndex] = 0;
            D_0057CC50[padIndex] = D_0057CC80[padIndex];
            D_0057CC20[padIndex] = 0;
        } else {
            D_0057CC30[padIndex]++;
            if (D_0057CC30[padIndex] > 10) {
                D_0057CC60[padIndex] = D_0057CC80[padIndex];
                D_0057CC30[padIndex] = 0;
            } else {
                D_0057CC60[padIndex] = 0;
            }

            D_0057CC20[padIndex]++;
            if (D_0057CC20[padIndex] > 10) {
                D_0057CC50[padIndex] = D_0057CC80[padIndex];
                D_0057CC20[padIndex] = 10;
            } else {
                D_0057CC50[padIndex] = 0;
            }
        }

        D_0057CC70[padIndex] = D_0057CC40[padIndex] ^ D_0057CC80[padIndex];
        D_0057CC70[padIndex] &= D_0057CC80[padIndex];
        D_0057CC40[padIndex] = D_0057CC80[padIndex];

        if (D_0057CC50[padIndex] & 0x5000) {
            D_0057CC50[padIndex] = 0;
            D_0057CC20[padIndex] = 0;
        }
    }

    reg_a0 = (u8 *)D_0028E248;
    reg_d0.w = 0;
    buttons = D_0057CC80[0];
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
    if (buttons & (1 << D_0028E270_as_u8)) {
        *(u8 *)&reg_d0 |= 0x20;
    }
    if (buttons & (1 << D_0028E271)) {
        *(u8 *)&reg_d0 |= 0x40;
    }
    if (buttons & (1 << D_0028E272)) {
        *(u8 *)&reg_d0 |= 0x80;
    }
    *reg_a0 = ~*(u8 *)&reg_d0;
    reg_a0++;

    reg_d0.w = 0;
    buttons = D_0057CC80[1];
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
    if (buttons & (1 << D_0028E274)) {
        *(u8 *)&reg_d0 |= 0x20;
    }
    if (buttons & (1 << D_0028E275)) {
        *(u8 *)&reg_d0 |= 0x40;
    }
    if (buttons & (1 << D_0028E276)) {
        *(u8 *)&reg_d0 |= 0x80;
    }
    *reg_a0 = ~*(u8 *)&reg_d0;

    reg_a0 = (u8 *)&D_0028E228_as_u16;
    reg_d0.w = 0;
    if (D_0057CC80[0] & SCE_PADselect) {
        *(u8 *)&reg_d0 |= 0x01;
    }
    if (D_0057CC80[1] & SCE_PADselect) {
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
extern u8 D_0028E298;

void pad_mask_game_inputs(void) {
    if (D_0028E298 != 0) {
        D_0028E248[0] = -1;
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
extern s16 D_0028E31C_as_s16;
extern u8 D_0028E350;
extern u8 D_0028E364;
extern u8 D_0028E368;
extern u8 D_0028E36C;
extern s8 D_0028EC24;
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];
extern s32 D_0057CC74[];
extern s32 D_0057CC78[];

void pause_check_start_button(void) {
    extern s32 D_0057CC70[];
    s32 state;
    s32 busy;
    s32 wait;

    state = D_0028E36C;
    if (state != 0) {
        return;
    }
    switch (D_0028E368) {
    case 0:
        goto block_rts;
    }
    busy = D_0028E350;
    if (busy != 0) {
        return;
    }
    if (D_0028E3C0 != 0) {
        return;
    }
    wait = D_0028E364;
    if (wait == 0xFF) {
        return;
    }
    if ((s8)wait > 0) {
        D_0028E364 = wait - 1;
        return;
    }
    D_0028E364 = 0;
    if (!(D_0057CC78[0] & 0x800)) {
        return;
    }
    if ((u8)busy != 0) {
        return;
    }
    if ((u8)state == 0xB) {
        return;
    }
    if (D_0028ED7C == 2) {
        if (!(D_0057CC70[D_0028EC24] & 0x800)) {
            return;
        }
        if (D_0028ED58 != 0 && D_0029F260[0] == 0 && D_0029F1F0[0] == 0) {
            return;
        }
        func_0018DA30();
        D_0028E36C = 1;
        D_0028E31C_as_s16 = D_0028EC24;
block_rts:
        return;
    }
    if ((D_0057CC70[0] & 0x800) && D_0029F260[0] < 0) {
        func_0018DA30();
        D_0028E31C_as_s16 = 0;
        D_0028E36C = 1;
        return;
    }
    if ((D_0057CC74[0] & 0x800) && D_0029F1F0[0] < 0) {
        func_0018DA30();
        D_0028E36C = 1;
        D_0028E31C_as_s16 = 1;
    }
}

extern s32 D_0057CC14[];
extern s32 D_0057CC18[];
extern s32 D_0057CC34[];
extern s32 D_0057CC38[];
extern s32 D_0057CC44[];
extern s32 D_0057CC48[];
extern s32 D_0057CC64[];
extern s32 D_0057CC68[];
extern s32 D_0057CC84[];
extern s32 D_0057CC88[];
extern s32 D_0057CD80[];
extern s32 D_0057CE80[];

void pad_init_system(void) {
    extern s32 D_0057CC10[];
    extern s32 D_0057CC30[];
    extern s32 D_0057CC40[];
    extern s32 D_0057CC60[];
    extern s32 D_0057CC70[];
    extern s32 D_0057CC80[];
    extern s32 g_pads[];
    memset(g_pads, 0, 0xB4);
    D_0057CC80[0] = 0;
    D_0057CC70[0] = 0;
    D_0057CC60[0] = 0;
    D_0057CC40[0] = 0;
    D_0057CC30[0] = 0;
    D_0057CC10[0] = 0;
    D_0057CC84[0] = 0;
    D_0057CC74[0] = 0;
    D_0057CC64[0] = 0;
    D_0057CC44[0] = 0;
    D_0057CC34[0] = 0;
    D_0057CC14[0] = 0;
    D_0057CC88[0] = 0;
    D_0057CC78[0] = 0;
    D_0057CC68[0] = 0;
    D_0057CC48[0] = 0;
    D_0057CC38[0] = 0;
    D_0057CC18[0] = 0;
    scePadInit(0);
    scePadPortOpen(0, 0, D_0057CD80);
    scePadPortOpen(1, 0, D_0057CE80);
}

typedef struct {
    u8 raw[0x20];
    u32 buttons;
    u32 trigger;
    u32 prevButtons;
    u32 rawButtons;
    u16 extraButtons;
    s8 analogX;
    s8 analogY;
#ifdef DEATH_LABEL
    s8 rightX;
    s8 rightY;
#else
    u16 unk34;
#endif
    u8 state;
    u8 padId;
    u8 prevPadId;
    u8 padTypeFlag;
    u8 pad3A[2];
} PadInfo;

extern u8 D_0028EA00[6];

void pad_poll_hardware(void)
{
    extern PadInfo g_pads[3];
    extern u8 g_pad_act_direct[6];
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
                D_0028EA00[0] = g_pad_act_direct[5] = g_pad_act_direct[4] = g_pad_act_direct[3] = g_pad_act_direct[2] = g_pad_act_direct[1] = g_pad_act_direct[0] = 0;
                D_0028EA00[5] = D_0028EA00[4] = D_0028EA00[3] = D_0028EA00[2] = 0xFF;
                D_0028EA00[1] = 1;
                if (scePadSetActAlign(port, 0, D_0028EA00) != 0) {
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

extern sceGsLoadImage g_gs_load_image;

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

extern s16 g_fade_alpha;

#ifdef DEATH_LABEL
#endif

void fade_reset(void) {
    extern s8 g_fade_state;
    extern s8 death_D_00290B60;
    g_fade_state = 0;
    g_fade_alpha = 0;
#ifdef DEATH_LABEL
    death_D_00290B60 = 0;
#endif
}

#ifdef DEATH_LABEL
#endif

void fade_start_in(void) {
    extern s8 g_fade_state;
    extern s8 death_D_00290B60;
#ifdef DEATH_LABEL
    death_D_00290B60 = 0;
#endif
    g_fade_state = 1;
}

#ifdef DEATH_LABEL
#endif

void fade_start_out(void) {
    extern s8 g_fade_state;
    extern s8 death_D_00290B60;
#ifdef DEATH_LABEL
    death_D_00290B60 = 0;
#endif
    g_fade_state = 2;
}

#ifdef DEATH_LABEL
void death_func_001B1220(void) {
    extern u8 g_fade_state;
    extern u8 death_D_00290B60;
    g_fade_state = 2;
    death_D_00290B60 = 1;
}
#endif

void gfx_draw_color_box(s32 a, s32 b, s32 c, s32 d, s32 e, s64 alpha, s32 g, s32 h, s32 i);
extern s16 g_fade_step;

#ifdef DEATH_LABEL
#endif

void fade_update_and_draw(void) {
    extern s8 g_fade_state;
    extern s8 death_D_00290B60;
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
        if (death_D_00290B60 == 0) {
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
    extern s8 D_0028E35C;
    extern s8 D_0028E360;
    extern u8 g_pad_act_direct;
    extern s8 D_0028EA41;
    s32 zero;

    D_0028E360 = 0;
    D_0028E35C = 0;
    D_0028EA41 = 0;
    scePadSetActDirect(zero = 0, zero, &g_pad_act_direct);
    scePadSetActDirect(1, 0, &g_pad_act_direct);
}


void vibration_stop_pad1(void) {
    extern s8 D_0028E360;
    extern s8 D_0028EA41;
    extern u8 g_pad_act_direct;
    s32 zero;

    D_0028E360 = 0;
    D_0028EA41 = 0;
    scePadSetActDirect(zero = 0, zero, &g_pad_act_direct);
}


void vibration_stop_pad2(void) {
    extern s8 D_0028E35C;
    extern u8 g_pad_act_direct;
    extern s8 D_0028EA41;
    D_0028E35C = 0;
    D_0028EA41 = 0;
    scePadSetActDirect(1, 0, &g_pad_act_direct);
}

extern u8 D_0028E27C;
void vibration_start_pad1(s16 arg0, s16 arg1) {
    extern s16 D_0028E344;
    extern s16 D_0028E34C;
    extern s8 D_0028E360;
    if ((D_0028E3C0 == 0) && (D_0028E27C != 0)) {
        if (D_0028ED7C == 2) {
            if (D_0028ED58 != 0) {
                vibration_start_active_pad(arg0, arg1);
            }
        } else if (D_0029F260[0] < 0) {
            D_0028E344 = arg0;
            D_0028E360 = 1;
            D_0028E34C = arg1;
        }
    }
}

void vibration_start_pad2(s16 arg0, s16 arg1) {
    extern s16 D_0028E340;
    extern s16 D_0028E348;
    extern s8 D_0028E35C;
    if ((D_0028E3C0 == 0) && (D_0028E27C != 0)) {
        if (D_0028ED7C == 2) {
            if (D_0028ED58 != 0) {
                vibration_start_active_pad(arg0, arg1);
            }
        } else if (D_0029F1F0[0] < 0) {
            D_0028E340 = arg0;
            D_0028E35C = 1;
            D_0028E348 = arg1;
        }
    }
}

void vibration_start_active_pad(s16 arg0, s16 arg1) {
    extern s16 D_0028E340;
    extern s16 D_0028E344;
    extern s16 D_0028E348;
    extern s16 D_0028E34C;
    extern s8 D_0028E35C;
    extern s8 D_0028E360;
    if (D_0028EC24 == 0) {
        D_0028E344 = arg0;
        D_0028E360 = 1;
        D_0028E34C = arg1;
        return;
    }
    D_0028E340 = arg0;
    D_0028E35C = 1;
    D_0028E348 = arg1;
}

extern u16 D_0028E330;
extern u16 D_0028E334;
extern u16 D_0028E338;
extern u16 D_0028E33C;

void vibration_suspend(void) {
    extern u16 D_0028E340;
    extern u16 D_0028E344;
    extern u16 D_0028E348;
    extern u16 D_0028E34C;
    extern u8 D_0028E35C;
    extern u8 D_0028E360;
    D_0028E334 = 0;
    D_0028E33C = 0;
    D_0028E330 = 0;
    D_0028E338 = 0;
    if (D_0028E360 != 0) {
        D_0028E334 = D_0028E344;
        D_0028E33C = D_0028E34C;
    }
    if (D_0028E35C != 0) {
        D_0028E330 = D_0028E340;
        D_0028E338 = D_0028E348;
    }
}

void vibration_resume(void)
{
    extern u16 D_0028E340;
    extern u16 D_0028E344;
    extern u16 D_0028E348;
    extern u16 D_0028E34C;
    extern s8 D_0028E35C;
    extern s8 D_0028E360;
    if (D_0028E27C != 0) {
        if (D_0028E33C > 0x3C) {
            D_0028E34C = D_0028E33C;
            D_0028E360 = 1;
            D_0028E344 = D_0028E334;
        }

        if (D_0028E338 > 0x3C) {
            D_0028E348 = D_0028E338;
            D_0028E35C = 1;
            D_0028E340 = D_0028E330;
        }
    }
}

#pragma push
#pragma opt_propagation off

void vibration_update(void) {
    extern u8 D_0028E340;
    extern u8 D_0028E344;
    extern u16 D_0028E348;
    extern u16 D_0028E34C;
    extern u8 D_0028E35C;
    extern u8 D_0028E360;
    extern u8 g_pad_act_direct;
    extern u8 D_0028EA41;
    s32 slot;

    if (D_0028E3C0 != 0) {
        return;
    }
    slot = 0;
    switch (D_0028E360) {
    case 0:
        break;
    case 1:
        D_0028EA41 = D_0028E344;
        scePadSetActDirect(0, slot, &g_pad_act_direct);
        D_0028E360 += 1;
        break;
    case 2:
        D_0028E34C -= 1;
        if ((s32)D_0028E34C <= 0) {
            D_0028E360 += 1;
        }
        break;
    case 3:
        D_0028EA41 = 0;
        scePadSetActDirect(0, slot, &g_pad_act_direct);
        D_0028E360 = 0;
        break;
    }
    switch (D_0028E35C) {
    case 0:
        break;
    case 1:
        D_0028EA41 = D_0028E340;
        scePadSetActDirect(1, 0, &g_pad_act_direct);
        D_0028E35C += 1;
        break;
    case 2:
        D_0028E348 -= 1;
        if ((s32)D_0028E348 <= 0) {
            D_0028E35C += 1;
        }
        break;
    case 3:
        D_0028EA41 = 0;
        scePadSetActDirect(1, 0, &g_pad_act_direct);
        D_0028E35C = 0;
        break;
    }
}
#pragma pop

#ifndef DEATH_LABEL
extern s32 D_002C4F00[];
extern s32 D_002C4F04[];
extern s32 D_002C4F08[];
extern s32 D_002C4F0C[];
extern s32 D_002C4F10[];
extern s32 D_002C4F14[];
extern s32 D_002C4F18[];
extern s32 D_002C4F1C[];
extern s8 D_002C4F20[];
extern s8 D_002C4F21[];
extern s8 D_002C4F22[];
extern s8 D_002C4F23[];

void func_00217EC0(void) {
    D_002C4F00[0] = 0;
    D_002C4F04[0] = 0;
    D_002C4F08[0] = 0;
    D_002C4F0C[0] = 0;
    D_002C4F10[0] = 0;
    D_002C4F14[0] = 0;
    D_002C4F18[0] = 0;
    D_002C4F1C[0] = 0;
    D_002C4F20[0] = 0;
    D_002C4F21[0] = 0;
    D_002C4F22[0] = 0;
    D_002C4F23[0] = 0;
}
#endif
