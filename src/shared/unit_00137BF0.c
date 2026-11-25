#include "common.h"
#include "task.h"
#include "sdk/ps2sdk.h"

extern u16 D_0028E82C;
extern u16 D_0028E830;
extern u16 D_0028E834;
extern u16 D_0028E838;

void func_00137BF0(void) {
    reg_d0.w = 0;
    D_0028E838 = reg_d0.h[0];
    D_0028E834 = reg_d0.h[0];
    D_0028E830 = reg_d0.h[0];
    D_0028E82C = reg_d0.h[0];
}

extern u16 g_debug_number[];

void debug_number_get(void) {
    *(u16 *)&reg_d0 = g_debug_number[0];
}

extern s16 g_ending_started;
extern s16 *reg_a0_as_s16_p;
extern s16 D_002BF350[];
extern s16 D_002BF370[];

void func_00137C20(void) {
    g_ending_started = 0;
    reg_a0_as_s16_p = D_002BF370;
    *reg_a0_as_s16_p = 0;
    reg_a0_as_s16_p = D_002BF350;
    *reg_a0_as_s16_p = 0;
    func_00137BF0();
}

extern s32 D_0028E7F8_as_s32;
extern s32 D_0028E7FC_as_s32;
extern s16 D_0028E800_as_s16;
extern s16 D_0028E804_as_s16;
extern s16 D_0028E808;
extern s16 D_0028E80C_as_s16;
extern s16 D_0028E810_as_s16;
extern s16 D_0028E814_as_s16;
extern s16 D_0028E818_as_s16;
extern s16 D_0028E81C_as_s16;
extern s16 D_0028E820_as_s16;
extern s16 D_0028E824_as_s16;
extern s16 D_0028E828_as_s16;

void func_00137C50(void) {
    D_0028E7F8_as_s32 = 0;
    D_0028E7FC_as_s32 = 0;
    D_0028E800_as_s16 = 0;
    D_0028E804_as_s16 = 0;
    D_0028E808 = 0;
    D_0028E80C_as_s16 = 0;
    D_0028E810_as_s16 = 0;
    D_0028E814_as_s16 = 0;
    D_0028E818_as_s16 = 0;
    D_0028E81C_as_s16 = 0;
    D_0028E820_as_s16 = 0;
    D_0028E824_as_s16 = 0;
    D_0028E828_as_s16 = 0;
}

#ifdef DEATH_LABEL
s32 func_00171910();
s32 text_palette_load();
extern u8 death_D_0026EE20[];
extern u32 death_D_0026FD90[];
extern u16 D_0028E3BC;
extern u16 g_attract_demo;
extern u32 D_0028E7F8;
extern u8 *D_0028E7FC;
extern u16 D_0028E810;
extern u16 D_0028E814;
extern u16 D_0028E818;
extern u16 D_0028E820;
extern u16 D_0028E824;

void func_00137C90(void) {
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
    u8 *save_a6;

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
    save_a6 = reg_a6;
    g_attract_demo = 1;
    func_00137C50();
    D_0028E824 = 0x10;
    D_0028E820 = 0x960;
    reg_a0 = (u8 *) death_D_0026FD90;
    reg_d2.h[0] = D_0028E3BC;
    reg_tmp.w = death_D_0026FD90[reg_d2.h[0]];
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d7.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E818 = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E814 = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E810 = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E7FC = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    D_0028E7F8 = reg_tmp.w;
    reg_d0.h[0] = TASK_GAME;
    task_start();
    *(u16 *)(reg_a0 + 4) = reg_d7.h[0];
    func_00171910();
    reg_a0 = death_D_0026EE20;
    reg_d0.h[0] = 0xC;
    text_palette_load();
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
    reg_a6 = save_a6;
}
#else
extern s8 D_0028DEF8_as_s8;
extern s16 D_0028DEFC_as_s16;
extern s16 D_0028DF00_as_s16;
extern s8 D_0028DF08_as_s8;
extern s16 g_attract_demo_as_s16;
extern s8 D_0028EC24;

void func_00137C90(void) {
    D_0028DF08_as_s8 = 0;
    D_0028DF00_as_s16 = 0x960;
    D_0028DEFC_as_s16 = 0;
    g_attract_demo_as_s16 = 1;
    D_0028DEF8_as_s8 = 1;
    D_0028EC24 = 0;
}
#endif

#ifndef DEATH_LABEL
s32 deferred_text_put();
extern u32 D_0026A290[];
extern u16 D_0028DEFC;

void func_00137CC0(void) {
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
    u32 temp_a1;

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
    reg_a0 = (u8 *)(D_0026A290);
    reg_a0 += D_0028DEFC;
    temp_a1 = *(u32 *)reg_a0;
    reg_d4.w = temp_a1;
    reg_d0.h[0] = 0x88;
    reg_d2.w = 5;
    reg_d3.w = 0x1B;
    reg_d1.h[0] = 0;
    deferred_text_put();
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
#endif

#ifndef DEATH_LABEL

s32 text_palette_load();
s32 delta_encode();
s32 func_00224B50();
s32 func_0022BC60();
s32 func_0022BE60();
s32 func_0023DBF0();
extern u8 D_00269320[];
extern u8 D_0028DEF4;
extern u8 D_0028DEF8;
extern u16 D_0028DEFC;
extern u16 D_0028DF00;
extern u8 D_0028DF04;
extern u8 D_0028DF08;
extern s16 g_attract_demo_as_s16;
extern u8 D_0028ED30;
extern u8 D_0028ED31;
extern u8 D_0028ED32;
extern u8 D_0028ED33;
extern u8 D_0028ED34;
extern u8 D_0028ED35;
extern u8 D_0028ED36;
extern u8 D_0028ED37;
extern s8 D_0028ED74_as_s8;
extern s8 D_0028ED7C_as_s8;
extern u8 D_006A4800[];
extern u8 D_006C58A0[];
extern u8 D_006C58D8[];
extern u8 D_006C58D9[];
extern u8 D_006C58DA[];
extern u8 D_006C58DB[];
extern u8 D_006C58DC[];
extern u8 D_006C58DD[];
extern u8 D_006C58DE[];
extern u8 D_006C58DF[];
extern u8 D_006C5CA0[];

void func_00137E00(void) {
    s32 layers_reset();
    s32 func_0012FA50();
    s32 func_0012FB00();
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
    s32 temp_a1;

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
    temp_a1 = D_0028DF08;
    cond_flag = 1;
    D_0028DEF4 += 1;
    switch (temp_a1) {                              /* irregular */
    case 0:
        D_0028DF08 = temp_a1 + 1;
        func_0022BC60(4, temp_a1, 1);
        reg_a0 = (u8 *)D_00269320;
        reg_d0.h[0] = 0xC;
        text_palette_load();
        /* fallthrough */
    case 1:
        if (func_0022BE60(D_0028DF04) != 0) {
            D_0028DF08 += 1;
            memcpy(D_006C58A0, D_006A4800, 0x202E8);
            delta_encode(D_006C5CA0);
            func_0023DBF0(D_006C58A0);
            D_0028ED7C_as_s8 = 2;
            D_0028ED30 = D_006C58D8[0];
            reg_d0.h[0] = 0x14;
            D_0028ED31 = D_006C58D9[0];
            D_0028ED32 = D_006C58DA[0];
            D_0028ED33 = D_006C58DB[0];
            D_0028ED34 = D_006C58DC[0];
            D_0028ED35 = D_006C58DD[0];
            D_0028ED36 = D_006C58DE[0];
            D_0028ED37 = D_006C58DF[0];
            task_start();
            *(s8 *)(reg_a0 + 5) = 3;
        }
        break;
    case 2:
        if (D_0028DEF8 != 0) {
            D_0028DF08 = temp_a1 + 1;
        }
        break;
    case 3:
        D_0028DF08 = temp_a1 + 1;
        break;
    case 4:
        D_0028DF00 -= 1;
        if (D_0028DF00 == 0) {
            D_0028DF08 = 0;
            cond_flag = 0;
            g_attract_demo_as_s16 = 0;
            D_0028ED7C_as_s8 = 0;
            D_0028ED74_as_s8 = 0;
            func_0012FA50();
            func_0012FB00();
            layers_reset();
            func_00224B50();
            D_0028DF04 += 1;
            if ((s32) D_0028DF04 >= 3) {
                D_0028DF04 = 0;
            }
        }
        break;
    }
    if ((s32) D_0028DF08 > 0) {
        func_00137CC0();
        reg_d0.h[0] = (u16) D_0028DEF4;
        if ((reg_d0.h[0] &= 1) == 0) {
            D_0028DEFC += 4;
            D_0028DEFC &= 0xF;
        }
    }
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
#endif

#ifdef DEATH_LABEL
void func_00131440(void);
extern u8 *D_0028E7FC;
extern u16 D_0028E800;
extern u16 D_0028E804;
extern u16 D_0028E80C;
extern u8 death_D_00291195;

void scripted_input_apply(void) {
    u32 save_d6;
    u32 save_d7;
    u8 *save_a0;
    u8 *save_a1;

    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    reg_d6.h[0] = reg_d0.h[0];
    reg_d0.h[0] &= 0xFF;
    reg_d6.h[0] &= 0xFF00;
    if (D_0028E80C != 0) {
        reg_d7.h[0] = D_0028E800;
        if (reg_d7.h[0] == 0x800) {
            reg_d0.h[0] = 0;
        } else if (D_0028E80C == 1) {
            D_0028E80C = 2;
            func_00131440();
            reg_d0.b[0] = 0;
        } else {
            reg_d0.b[0] = death_D_00291195;
            D_0028E804 -= 1;
            if (!(0 < (s16) D_0028E804)) {
                reg_a0 = D_0028E7FC;
                reg_a0 += D_0028E800;
                reg_d7.w = 0;
                reg_d7.b[0] = *(s8 *)reg_a0;
                D_0028E804 = reg_d7.h[0];
                reg_d0.b[0] = *(s8 *)(reg_a0 + 1);
                D_0028E800 += 2;
                death_D_00291195 = reg_d0.b[0];
            }
        }
    }
    reg_d0.h[0] |= reg_d6.h[0];
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
    reg_a0 = save_a0;
    reg_a1 = save_a1;
}
#endif

#ifdef DEATH_LABEL
void ship_select_apply(void);
void func_001719A0(void);
void func_001719D0(void);
extern u8 death_D_0026FDA0[];
extern u8 g_game_frame_ran;
extern u16 D_0028E3BC;
extern u16 g_attract_demo;
extern u16 g_game_frame;
extern u16 D_0028E814;
extern u16 D_0028E818;
extern u16 D_0028E81C;
extern u16 D_0028E820;
extern u16 D_0028E824;
extern u16 D_0028E828;
extern u8 death_D_00291191;
extern s8 death_D_00291195_as_s8;

void func_00137E00(void) {
    void layers_reset(void);
    void deferred_text_put(void);
    void func_0012FA50(void);
    void func_0012FB00(void);
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
    u8 *save_a6;

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
    save_a6 = reg_a6;
    func_001719D0();
    reg_a0 = death_D_0026FDA0;
    reg_a0 += D_0028E81C;
    reg_d4.w = *(u32 *)reg_a0;
    reg_d0.h[0] = 0x88;
    reg_d1.h[0] = 0;
    reg_d2.w = 5;
    reg_d3.w = 0x1B;
    deferred_text_put();
    reg_d0.h[0] = g_game_frame;
    if ((reg_d0.h[0] &= 1) == 0) {
        D_0028E81C += 4;
        D_0028E81C &= 0xF;
    }
    if (D_0028E828 == 0) {
        D_0028E824 -= 1;
        if (D_0028E824 != 0) {
            goto check_end;
        }
        D_0028E828 = 2;
        death_D_00291191 = 1;
        reg_d0.w = 0;
        reg_a0 = D_0028E7FC;
        reg_a0 += D_0028E800;
        reg_d0.b[0] = *(s8 *)reg_a0;
        D_0028E804 = reg_d0.h[0];
        death_D_00291195_as_s8 = *(s8 *)(reg_a0 + 1);
        D_0028E800 += 2;
        func_00131440();
        g_game_frame_ran = 0;
        func_001719A0();
        reg_d0.w = 0;
        reg_d1.w = 0;
        reg_d0.h[0] = D_0028E818;
        reg_d1.h[0] = D_0028E814;
        reg_d2.h[0] = 0xFF;
        reg_d3.h[0] = 0xFF;
        reg_d4.w = 1;
        ship_select_apply();
    }
    if ((D_0028E828 == 2) && (g_game_frame_ran != 0)) {
        D_0028E80C = 1;
        D_0028E828 = 1;
    }
check_end:
    if (D_0028E828 == 1) {
        D_0028E820 -= 1;
        if (D_0028E820 == 0) {
            func_0012FA50();
            func_0012FB00();
            layers_reset();
            goto finished;
        }
    }
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
    reg_a6 = save_a6;
    cond_flag = 1;
    return;
finished:
    D_0028E3BC += 1;
    D_0028E80C = 0;
    if ((s16) D_0028E3BC >= 3) {
        D_0028E3BC = 0;
    }
    g_attract_demo = 0;
    cond_flag = 0;
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
    reg_a6 = save_a6;
}
#endif
