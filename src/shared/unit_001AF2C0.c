#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_001AF8F0(void);
void func_001AFCC0(void);
void func_001B00D0(void);
void func_001B0100(void);
void func_001B0160(void);
void func_001B0950(void);

extern u16 g_two_player_game;
extern u8 D_0029BF30[];
extern u8 D_0029BF40[];

void func_001AF2C0(void) {
    reg_a0 = D_0029BF40;
    if (*(u8 *)(reg_a5 + 6) == 0) {
        reg_a0 = D_0029BF30;
    }
    reg_d0.b[0] = *reg_a0;
    if (g_two_player_game == 0) {
        reg_d0.h[0] = 0xFFFF;
    }
}


void func_001AF310(void) {
    s32 d1 = reg_d1.w;

    reg_a0 = (u8 *)D_0029BF40;
    if (reg_a5[6] != 0) goto next_1;
    reg_a0 = (u8 *)D_0029BF30;
next_1:
    reg_d1.b[0] = *reg_a0;
    if (g_two_player_game != 0) goto next_2;
    reg_d1.h[0] = 0xFFFF;
next_2:
    if ((s8) reg_d1.b[0] == -1) goto next_3;
    if (reg_d7.b[0] != reg_d1.b[0]) goto next_3;
    reg_d1.w = d1;
    cond_flag = 1;
    return;
next_3:
    reg_d1.w = d1;
    cond_flag = 0;
}

s32 func_0013EEE0();
s32 func_0013F000();
extern u8 join_select_p1_table[];
extern u8 join_select_p2_table[];

void func_001AF3A0() {
    s32 func_001A3560();
    *(s8 *)(reg_a5 + 3) = 1;
    reg_a4 = join_select_p1_table;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a4 = join_select_p2_table;
    }
    reg_tmp.w = (u32) reg_a4;
    *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[0];
    if (*(u8 *)(reg_a5 + 6) == 0) {
        func_0013EEE0();
    } else {
        func_0013F000();
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3560();
    *(s8 *)(reg_a5 + 0xD) = 0;
    *(s16 *)(reg_a5 + 0x12) = 0x4B0;
    *(s16 *)(reg_a5 + 0x14) = 4;
}

s32 func_00135740();
s32 task_stop_self();
extern u16 D_0028C11C[];
extern u16 D_0028C120[];

void func_001AF460(void) {
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d0.w = 0;
    reg_a4 = (u8 *)reg_tmp.w;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0xF);
    reg_a0 = (u8 *)(D_0028C11C);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a5 + 0xE);
    reg_a0 = (u8 *)(D_0028C120);
    reg_d1.h[0] += reg_d1.h[0];
    reg_d1.h[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 0;
    reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
    func_00135740();
    task_stop_self();
}

typedef void (*Fn)(void);


void func_0012FBD0(void);
void func_001301B0(void);
void func_001353E0(void);
void func_001A35A0(void);
void func_001A3630(void);
void func_001AF1A0(void);
void func_001AF210(void);
extern u8 D_002623B0[];
extern u8 D_0028E304;
extern u16 D_0028E314;
extern u16 D_0028E318;
extern u16 g_attract_demo;
extern u16 g_loop;
extern u8 g_replay_taken_over;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern u8 *reg_call_target_as_u8_p;

void func_001AF560(void) {
    void func_00131610(void);
    void sprite_palette_load(void);
    void func_001A3560(void);
    u8 state;
    u8 seq;

    state = *(u8 *)(reg_a5 + 3);
    if (state == 0) {
        func_001AF3A0();
        return;
    }
    if (state == 2) {
        func_001AF460();
        return;
    }
    func_00131610();
    if (cond_flag != 0) {
        goto block_50;
    }
    if (*(u8 *)(reg_a5 + 0xD) != 0) {
        goto block_51;
    }
    if (g_loop != 0) {
        goto block_50;
    }
    if (D_0028E304 != 0) {
        goto block_50;
    }
    if (g_simulation_active == 1) {
        goto block_50;
    }
#ifdef DEATH_LABEL
    if ((g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#else
    if ((g_attract_demo == 0) && (g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#endif
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 == 0) {
            goto block_50;
        }
    } else {
        if (D_0028E314 == 0) {
            goto block_50;
        }
    }
    func_001301B0();
    if (reg_d0.h[0] != 0) {
        goto next_1;
    }
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3630();
    goto block_51;
next_1:
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3560();
    goto block_51;
block_50:
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A35A0();
    return;
block_51:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_a4 = (u8 *)reg_tmp.w;
    if (*(u8 *)(reg_a5 + 0xD) != 0) {
        goto block_52;
    }
    if (g_loop != 0) {
        goto block_52;
    }
    if (g_attract_demo != 0) {
        goto block_52;
    }
    if (g_simulation_active == 1) {
        goto block_52;
    }
#ifdef DEATH_LABEL
    if ((g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#else
    if ((g_attract_demo == 0) && (g_replay_mode == 2) && (g_replay_taken_over == 0)) {
        goto block_50;
    }
#endif
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 == 0) {
            goto block_52;
        }
    } else {
        if (D_0028E314 == 0) {
            goto block_52;
        }
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    if (!(reg_d0.w & 0x8000)) {
        goto block_52;
    }
    func_00131610();
    if (cond_flag != 0) {
        goto block_52;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xE);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    if (cond_flag != 0) {
        goto block_52;
    }
    func_001AF1A0();
    func_001AF210();
    *(u8 *)(reg_a5 + 0xD) = 1;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3560();
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
#ifdef DEATH_LABEL
    if (reg_d0.b[0] == 0) {
        if (D_0028E318 != 0) {
            D_0028E318 -= 1;
        }
    } else {
        if (D_0028E314 != 0) {
            D_0028E314 -= 1;
        }
    }
#endif
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0x14);
    reg_a0 = (u8 *)D_002623B0;
    sprite_palette_load();
    func_0012FBD0();
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    reg_d1.h[0] = 7;
    func_001353E0();
    func_001B0100();
block_52:
    seq = *(u8 *)(reg_a5 + 0xD);
    if (seq == 1) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A3560();
        func_001AF8F0();
        if (cond_flag != 0) {
            *(u8 *)(reg_a5 + 0xD) = 2;
            *(s8 *)(reg_a5 + 0xC) = 1;
        }
        return;
    }
    if (seq == 2) {
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        func_001A3560();
        func_001AFCC0();
        return;
    }
    func_001B00D0();
}

typedef void (*Fn)();


s32 sfx_confirm();
s32 sfx_cursor_move();
s32 sprite_draw_with_ship_select_keep();
extern u16 D_00251B20[];
extern u16 D_00251B30[];
extern u16 D_0028C128[];
extern u16 g_game_frame;
extern s32 D_0028E998;
extern s32 D_0028E99C;

void func_001AF8F0(void) {
    u32 temp_a1_3;
    u32 temp_v1;
    u32 temp_a1;
    u32 temp_a1_2;

    reg_tmp.h[1] = *(u16 *)(reg_a4 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    if (reg_d0.w & 4) {
        *(u8 *)(reg_a5 + 0xF) -= 1;
        *(s8 *)(reg_a5 + 0xC) = 1;
        sfx_cursor_move();
    }
    if (reg_d0.w & 8) {
        *(u8 *)(reg_a5 + 0xF) += 1;
        *(s8 *)(reg_a5 + 0xC) = 1;
        sfx_cursor_move();
    }
    *(u8 *)(reg_a5 + 0xF) &= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0 = (u8 *)reg_tmp.w;
    *(u8 *)(reg_a0 + 1) = (u8) *(u8 *)(reg_a5 + 0xF);
    *(u16 *)(reg_a5 + 0x12) -= 1;
    if ((*(u8 *)(reg_a5 + 0x13) == 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        sfx_confirm();
        *(u16 *)(reg_a5 + 0x12) = 0x4B0U;
        if (reg_a0 == D_0029BF40) {
            D_0028E99C = (s32) *(u8 *)(reg_a0 + 1);
        } else {
            D_0028E998 = *(u8 *)(reg_a0 + 1) + 2;
        }
        cond_flag = 1;
        return;
    }
    reg_d1.w = 0x5BC00000;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d1.w = 0x5BC02C00;
    }
    reg_d2.w = 0x1552;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x630;
    reg_d7.w = reg_d1.w;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    if (*(u8 *)(reg_a5 + 6) == 0) {
        temp_a1 = reg_d1.w;
        reg_d1.w = temp_a1 + 0x04000100;
        reg_d2.w = 0x1553;
        reg_d3.h[0] = 0x410;
        reg_d4.w = 0;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x16);
        sprite_draw_with_ship_select_keep();
        reg_d2.w = 0x1554;
        reg_d4.w = 0;
        reg_d3.h[0] = 0x410;
        reg_d1.w += 0x600;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x18);
        sprite_draw_with_ship_select_keep();
    } else {
        temp_a1_2 = reg_d1.w;
        reg_d1.w = temp_a1_2 + 0x04000100;
        reg_d2.w = 0x1555;
        reg_d3.h[0] = 0x410;
        reg_d4.w = 0;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x16);
        sprite_draw_with_ship_select_keep();
        reg_d2.w = 0x1556;
        reg_d4.w = 0;
        reg_d3.h[0] = 0x410;
        reg_d1.w += 0x600;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x18);
        sprite_draw_with_ship_select_keep();
    }
    reg_d0.w = 0;
    reg_d1.w = reg_d7.w;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0xF);
    reg_a2 = (u8 *)(D_0028C128);
    reg_d0.h[0] += reg_d0.h[0];
    temp_a1_3 = reg_d0.h[0];
    reg_a2 += temp_a1_3;
    temp_v1 = reg_d1.h[0] + *(u16 *)reg_a2;
    reg_a2 = (u8 *)(D_00251B20);
    reg_d1.h[0] = temp_v1;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a2 = (u8 *)(D_00251B30);
    }
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d0.h[0] &= 3;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x618;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    reg_d0.w = 0;
    cond_flag = 0;
}

extern u16 D_0028C130[];

void func_001AFCC0(void) {
    u16 var_a0;
    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xE);
    func_001AF310();
    if (cond_flag != 0) {
        reg_d7.b[0] -= 1;
        if (0 > reg_d7.sb[0]) {
            reg_d7.b[0] = 2;
        }
        *(u8 *)(reg_a5 + 0xE) = (u8) reg_d7.b[0];
    }
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xA);
    reg_a0 = (u8 *)(reg_tmp.w);
    reg_call_target_as_u8_p = reg_a0;
    ((Fn)reg_call_target_as_u8_p)();
    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xE);
    reg_d6.h[0] = reg_d7.h[0];
    if (reg_d0.w & 4) {
        *(s8 *)(reg_a5 + 0xC) = 1;
        do {
            reg_d7.b[0] -= 1;
            if (0 > reg_d7.sb[0]) {
                reg_d7.b[0] = 2;
            }
            func_001AF310();
        } while (cond_flag != 0);
    }
    if (reg_d0.w & 8) {
        *(s8 *)(reg_a5 + 0xC) = 1;
        do {
            reg_d7.b[0] += 1;
            if ((s8) reg_d7.b[0] > 2) {
                reg_d7.b[0] = 0;
            }
            func_001AF310();
        } while (cond_flag != 0);
    }
    if (reg_d6.b[0] != reg_d7.b[0]) {
        sfx_cursor_move();
    }
    *(u8 *)(reg_a5 + 0xE) = (u8) reg_d7.b[0];
    reg_tmp.h[1] = *(u16 *)(reg_a4 + 0x10);
    reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x12);
    reg_a0 = (u8 *)(reg_tmp.w);
    *(u8 *)reg_a0 = *(u8 *)(reg_a5 + 0xE);
    *(u16 *)(reg_a5 + 0x12) -= 1;
    if ((*(u16 *)(reg_a5 + 0x12) == 0) || (reg_d0.h[0] &= 0x70, (reg_d0.h[0] != 0))) {
        sfx_confirm();
        func_001AF460();
        return;
    }
    reg_d1.w = 0x5BC00000;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d1.w = 0x5BC02600;
    }
    reg_d2.w = 0x1551;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x648;
    reg_d7.w = reg_d1.w;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    reg_d0.w = 0;
    reg_d1.w = reg_d7.w;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 0xE);
    reg_a0 = (u8 *)((u32) D_0028C130);
    reg_d0.h[0] += reg_d0.h[0];
    if (reg_d0.h[0] != 0) {
        var_a0 = *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1));
    } else {
        var_a0 = *(u16 *)reg_a0;
    }
    reg_d1.h[0] += var_a0;
    reg_a2 = (u8 *)(D_00251B20);
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_a2 = (u8 *)(D_00251B30);
    }
    reg_d0.h[0] = g_game_frame;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    reg_d0.h[0] &= 3;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a2;
    reg_d4.w = 0;
    reg_d3.h[0] = 0x618;
    reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
    sprite_draw_with_ship_select_keep();
    func_001AF2C0();
    if (0 <= (s16)(reg_d0.h[0])) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_d1.w = reg_d7.w;
        reg_a2 = (u8 *)(D_0028C130);
        reg_a2 += reg_d0.h[0];
        reg_d1.h[0] += *(u16 *)reg_a2;
        reg_d2.w = 0x1557;
        reg_d3.h[0] = 0x618;
        reg_d4.w = 0;
        reg_d4.h[0] = *(u16 *)(reg_a4 + 0x14);
        sprite_draw_with_ship_select_keep();
    }
}


void func_001B00D0(void) {
    s32 func_00131610();
    func_00131610();
    if (cond_flag == 0) {
        func_001B0160();
    }
}

extern u8 D_00251B40[];

void func_001B0100(void) {
    s32 text_layer_print();
    reg_a0 = D_00251B40;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)reg_a4;
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}

void func_0012FFE0(void);
void func_00130050(void);
void func_00130CC0(void);
void func_001A3520(void);
extern u8 D_00251B60[];
extern u8 D_00251B80[];
extern u8 D_00251BA0[];
extern u8 D_00251BC0[];
extern u8 D_00251BE0[];
extern u8 D_00251C00[];
extern u8 g_setting_chute_type;
extern u8 g_setting_coin_mode;

void func_001B0160(void) {
    void text_layer_print(void);
    func_001301B0();
    if (*(u8 *)(reg_a5 + 6) == 0) {
        goto next_1;
    }
    if (g_setting_chute_type != 1) {
        goto next_1;
    }
    reg_d0.h[0] = reg_d1.h[0];
next_1:
    if (reg_d0.h[0] != 0) {
        goto block_50;
    }
    reg_d0.b[0] = g_setting_coin_mode;
    if (reg_d0.b[0] == 0x12) {
        goto block_51;
    }
    if (reg_d0.b[0] == 0x11) {
        goto block_52;
    }
    if ((s8) reg_d0.b[0] >= 9) {
        goto block_52;
    }
    goto block_53;
block_50:
    reg_a0 = (u8 *)D_00251B60;
    goto block_54;
block_51:
    reg_a0 = (u8 *)D_00251B80;
    goto block_54;
block_53:
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001A3520();
    if (reg_d0.h[0] == 0xC) {
        return;
    }
    reg_a0 = (u8 *)D_00251BA0;
    goto block_54;
block_52:
    if (*(u8 *)(reg_a5 + 6) == 0) {
        goto next_2;
    }
    func_00130050();
    goto next_3;
next_2:
    func_0012FFE0();
next_3:
    if (reg_d0.h[0] != 1) {
        goto next_4;
    }
    if (reg_d1.h[0] != 0) {
        goto block_50;
    }
    goto block_53;
next_4:
    if (reg_d1.h[0] != 0) {
        goto next_5;
    }
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BC0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    func_00130CC0();
    return;
next_5:
    reg_d0.h[0] -= reg_d1.h[0];
    if (!(0 < (s16) reg_d0.h[0])) {
        goto block_50;
    }
    if ((reg_d0.h[0] & 0xFFFF) == 1) {
        goto next_6;
    }
    reg_d4.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *)D_00251BE0;
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
    reg_d0.h[0] = 1;
    reg_d0.h[0] += *(u16 *)(reg_a4 + 2);
    func_00130CC0();
    return;
next_6:
    reg_a0 = (u8 *)D_00251C00;
block_54:
    reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
    reg_d1.h[0] = *(u16 *)(reg_a4 + 0);
    reg_d2.h[0] = 0;
    text_layer_print();
    reg_a0 += 0x10;
    reg_d1.h[0] -= 1;
    text_layer_print();
}

extern u16 D_0028C138[];

void func_001B03E0(void) {
    reg_a0 = (u8 *)D_0028C138;
    *(u16 *)(reg_a1 + 2) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a1 + 0x10) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a1 + 0x14) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a1 + 0x16) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a1 + 0x18) = (u16) reg_d0.h[0];
    *(u16 *)(reg_a1 + 0x1A) = (u16) reg_d0.h[0];
}

s32 sprite_draw_layer5();                            /* extern */
s32 sprite_draw_layer5_zoom_keep();                            /* extern */

void func_001B0470(void) {
    if (g_game_frame & 2) {
        sprite_draw_layer5();
        return;
    }
    sprite_draw_layer5_zoom_keep();
}

extern s32 D_0029BEE0_as_s32_a[];


void func_001B04B0(void) {
    memset(D_0029BEE0_as_s32_a, 0, 0x48);
}

extern u16 D_00251CC0[];
extern u8 D_0029BEE0[];
extern u8 D_0029BEE1[];
extern s16 D_0029BEE4[];
extern s16 D_0029BEE6[];
extern s16 D_0029BEEE[];
extern u16 D_0029BEFC[];
extern u16 D_0029BEFE[];
extern u16 D_0029BF00[];
extern u16 D_0029BF02[];
extern u8 D_0029BF04[];
extern u8 D_0029BF05[];
extern s16 D_0029BF08[];
extern s16 D_0029BF0A[];
extern s16 D_0029BF12[];
extern u16 D_0029BF20[];
extern u16 D_0029BF22[];
extern u16 D_0029BF24[];
extern u16 D_0029BF26[];

void func_001B04D0(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

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
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 5);
    if (0 <= (s8) reg_d0.b[0]) {
        reg_a0 = (u8 *)(D_00251CC0);
        reg_d0.h[0] -= 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        D_0029BF00[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF02[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BEFC[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BEFE[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BEE1[0] |= 1;
        D_0029BEEE[0] = 0x17;
        D_0029BEE4[0] = 0x5E00;
        D_0029BEE6[0] = 0x1C00;
        reg_a1 = (u8 *)D_0029BEE0;
        func_001B03E0();
    }
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 4);
    if (0 <= (s8) reg_d0.b[0]) {
        reg_a0 = (u8 *)(D_00251CC0);
        reg_d0.h[0] -= 2;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        D_0029BF24[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF26[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF20[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF22[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        D_0029BF05[0] |= 1;
        D_0029BF12[0] = 0x18;
        D_0029BF08[0] = 0x1200;
        D_0029BF0A[0] = 0x1C00;
        reg_a1 = (u8 *)D_0029BF04;
        func_001B03E0();
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
    reg_a6 = save_a6;
    reg_a5 = save_a5;
}


void func_001B07E0(void) {
    u8 *save_a0;
    u8 *save_a1;
    u8 *save_a2;
    u8 *save_a3;
    u8 *save_a4;
    u8 *save_a5;
    u8 *save_a6;
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

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
    if ((reg_d7.h[0] != 0) && (D_0029BEE1[0] & 1) && !(D_0029BEE1[0] & 4)) {
        reg_a6 = (u8 *)D_0029BEE0;
        func_001B0950();
    } else if ((D_0029BF05[0] & 1) && !(D_0029BF05[0] & 4)) {
        reg_a6 = (u8 *)D_0029BF04;
        func_001B0950();
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
}

s32 sprite_draw_layer5();
s32 sprite_draw_layer5_zoom_keep();
extern u8 D_00251C20[];
extern u8 D_00251D70[];
extern u8 D_00251DF0[];
extern u8 D_00260F70[];
extern u16 g_frame_mod8;
extern u16 g_frame_mod2;

void func_001B0950(void) {
    s32 sprite_palette_load();
    u8 flag;

    if (ENTITY(reg_a6)->y.h != 0) {
        ENTITY(reg_a6)->y.h -= 1;
        return;
    }
    flag = ENTITY(reg_a6)->flags.b[1];
    if (!(flag & 2)) {
        ENTITY(reg_a6)->flags.b[1] = flag | 2;
        reg_a0 = (u8 *)D_00260F70;
        reg_d0.w = 0x16;
        sprite_palette_load();
        reg_tmp.h[1] = (*(u16 *)(reg_a6 + (0x1C)));
        reg_tmp.h[0] = (*(u16 *)(reg_a6 + (0x1E)));
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)(reg_a6 + (0xE)));
        sprite_palette_load();
    }
    reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
    reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
    reg_d1.w += 0xF400E400;
    reg_d0.h[0] = (*(u16 *)(reg_a6 + (0xA)));
    reg_a0 = (u8 *)D_00251C20;
    reg_a0 += reg_d0.h[0];
    reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
    reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] = 0xCE0;
    reg_d4.h[0] = 0x16;
    sprite_draw_layer5();
    if (ENTITY(reg_a6)->sprite.h != 0) {
        ENTITY(reg_a6)->sprite.h -= 1;
        reg_tmp.h[1] = (*(u16 *)(reg_a6 + (0x20)));
        reg_tmp.h[0] = (*(u16 *)(reg_a6 + (0x22)));
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = (*(u16 *)(reg_a6 + (0x12)));
        reg_a0 += reg_d0.h[0];
        reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d2.h[0] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
        reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
        reg_d1.w += 0xF600F800;
        reg_d3.h[0] = 0xA40;
        reg_d1.h[0] += 0x7FFF + 0x6E01;
        reg_d4.h[0] = (*(u16 *)(reg_a6 + (0xE)));
        reg_d6.w = 0x80008000;
        sprite_draw_layer5_zoom_keep();
        if (g_frame_mod8 != 0) {
            reg_a1 = (u8 *)D_00251DF0;
            reg_d0.h[0] = 0x1E;
            reg_d6.w = 0x80005000;
            reg_d0.h[0] &= g_game_frame;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a1 += reg_d0.h[0];
        }
        sprite_draw_layer5_zoom_keep();
        reg_d2.h[1] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        reg_d2.h[0] = (*(u16 *)(reg_a0 + (0)));
        reg_a0 += 2;
        if (ENTITY(reg_a6)->hit_x_plus.h == 0x280) goto skip_1;
        ENTITY(reg_a6)->hit_x_plus.h += 8;
        goto skip_4;
skip_1:
        if (ENTITY(reg_a6)->hit_x_minus.h == 0x280) goto skip_2;
        ENTITY(reg_a6)->hit_x_minus.h += 8;
        goto skip_4;
skip_2:
        if (ENTITY(reg_a6)->hp.h == 0x280) goto skip_3;
        ENTITY(reg_a6)->hp.h += 8;
        goto skip_4;
skip_3:
        if (ENTITY(reg_a6)->move.h == 0x280) goto skip_4;
        ENTITY(reg_a6)->move.h += 8;
skip_4:
        if (g_frame_mod2 != 0) {
            reg_a0 = (u8 *)D_00251D70;
            reg_d0.h[0] = 0x1E;
            reg_d0.h[0] &= g_game_frame;
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_d6.h[1] = (*(u16 *)(reg_a0 + (0)));
            reg_d6.h[0] = (*(u16 *)(reg_a0 + (2)));
            reg_d1.h[1] = (*(u16 *)(reg_a6 + (4)));
            reg_d1.h[0] = (*(u16 *)(reg_a6 + (6)));
            reg_d1.w += 0xFE00F000;
            reg_d1.h[0] += 0x900;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d1.h[0] += 0x600;
            reg_tmp.w = reg_d1.w;
            reg_d1.h[1] = reg_tmp.h[0];
            reg_d1.h[0] = reg_tmp.h[1];
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x14)));
            reg_d4.h[0] = (*(u16 *)(reg_a6 + (0xE)));
            func_001B0470();
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x16)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                func_001B0470();
            }
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x18)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                func_001B0470();
            }
            reg_d3.h[0] = (*(u16 *)(reg_a6 + (0x1A)));
            if (reg_d3.h[0] != 0x200) {
                reg_d1.w += 0xFC000000;
                reg_d2.w += 1;
                func_001B0470();
            }
        }
        reg_tmp.b[0] = (*(u8 *)(reg_a6 + (0x11)));
        (*(u8 *)(reg_a6 + (0x11))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)(reg_a6 + (0x11))) = (u8) (*(u8 *)(reg_a6 + (0x10)));
            (*(u16 *)(reg_a6 + (0x12))) += 8;
            if ((*(u16 *)(reg_a6 + (0x12))) == 0x28) {
                (*(u16 *)(reg_a6 + (0x12))) = 0U;
            }
        }
    } else {
        reg_tmp.b[0] = (*(u8 *)(reg_a6 + (9)));
        (*(u8 *)(reg_a6 + (9))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            (*(u8 *)(reg_a6 + (9))) = (u8) (*(u8 *)(reg_a6 + (8)));
            (*(u16 *)(reg_a6 + (0xA))) += 4;
            if (ENTITY(reg_a6)->draw.h != 0x5C) goto skip_5;
            ENTITY(reg_a6)->sprite.h = 0x90;
            return;
skip_5:
            if (ENTITY(reg_a6)->draw.h != 0x9C) return;
            ENTITY(reg_a6)->flags.b[1] |= 4;
        }
    }
}
