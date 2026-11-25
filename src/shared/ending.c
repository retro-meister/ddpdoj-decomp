#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_00123540(void);
void func_00123870(void);

void func_0013FD20(void);
void func_0013FD50(void);
void func_00141640(void);
void func_001A7E90(void);
void func_001A8070(void);
extern u8 D_0028C608[];
extern u8 D_0028E008_as_u8;
extern u8 D_0028E00C_as_u8;
extern u16 D_0028E018;
extern u16 D_0028E01C;
extern u16 D_0028E028;
extern u16 D_0028E02C;
extern u8 g_game_mode;
extern u8 D_0028E2EC;
extern s16 g_boss_hyper_wait_as_s16;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_p2_score_digits;
extern u16 g_p1_score_digits;
extern s16 g_p1_lives_as_s16;
extern u16 g_loop;
extern u16 g_two_player_seen;
extern u16 D_0028E980;
extern u8 g_player2_as_u8_a[];
extern u8 g_player1_as_u8_a[];

void func_00122CE0(void) {
    if (D_0028E2EC != 0) goto block_1;
    if (g_game_mode == 1) goto block_1;
#ifdef DEATH_LABEL
    if (g_game_mode == 2) goto block_1;
#endif
    if (g_loop != 0) goto block_1;
    if (g_p1_hyper_active != 0) {
        func_001A7E90();
        func_0013FD20();
    }
    if (g_p2_hyper_active != 0) {
        func_001A8070();
        func_0013FD50();
    }
    func_00141640();
    g_boss_hyper_wait_as_s16 = 0;
    if (g_two_player_seen == 3) goto block_1;
    reg_a0 = &D_0028E00C_as_u8;
    reg_d0.h[0] = D_0028E980;
    reg_a1 = (u8 *)g_player1_as_u8_a;
    reg_d1.h[0] = D_0028E01C;
    reg_d2.h[0] = g_p1_score_digits;
    reg_d3.h[0] = D_0028E02C;
    if (0 > g_p1_lives_as_s16) {
        reg_a0 = &D_0028E008_as_u8;
        reg_d1.h[0] = D_0028E018;
        reg_a1 = (u8 *)g_player2_as_u8_a;
        reg_d2.h[0] = g_p2_score_digits;
        reg_d3.h[0] = D_0028E028;
    }
    if (reg_d2.h[0] != 0) goto block_1;
    if (reg_d3.h[0] == 0 || reg_d1.h[0] == 0) {
        *(s16 *)(reg_a0 + 0) = 1;
    }
    if ((s32)reg_d0.h[0] < 0xC && (s32)reg_d3.h[0] > 2 && (s32)reg_d1.h[0] > 3) {
    block_1:
        cond_flag = 0;
        return;
    }
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0x5A);
    reg_a0 = (u8 *)D_0028C608;
    reg_d0.h[0] -= 2;
    reg_a0 += reg_d0.h[0];
    *(u8 *)(reg_a1 + 0x25) = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a1 + 0x24) = *(u8 *)(reg_a0 + 0);
    cond_flag = 1;
    reg_a0 += 2;
}

s32 task_start();
s32 task_stop_self();
s32 stage_load_step();
s32 func_00225630();
s32 func_002256B0();
extern s8 g_stage_load_state_as_s8;
extern s16 g_loaded_stage;
extern s16 g_loop_as_s16;
extern u16 g_stage;
extern s8 g_cd_async_state;
extern s8 g_cd_async_busy;
extern u16 D_00295E38[];
extern u16 D_00295E3C[];

void func_00122EB0(void) {
    u16 temp_a0;

    temp_a0 = D_00295E3C[0];
    if (temp_a0 != 0) {
        if (temp_a0 == 1) {
            switch (D_00295E38[0]) { case 0: break; default:
                D_00295E3C[0] = 0;
                func_00123870();
                return;
            }
            g_cd_async_busy = 1;
            D_00295E3C[0] = 2;
            g_stage_load_state_as_s8 = 0;
            g_cd_async_state = 0;
            func_00225630(temp_a0);
            goto block_6;
        }
block_6:
        if (D_00295E3C[0] == 2) {
            g_stage = 0;
            stage_load_step(D_00295E3C[0]);
            if (g_loaded_stage == g_stage) {
                g_loop_as_s16 = 1;
                D_00295E3C[0] = 0;
                func_002256B0(g_loaded_stage);
                reg_d0.h[0] = 0x11;
                task_start();
                task_stop_self();
            }
        }
    } else {
        ENTITY(reg_a6)->hit_y_minus.h += 1;
        reg_d0.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
        if (ENTITY(reg_a6)->hit_y_plus.h != reg_d0.h[0]) {
            func_00123870();
            return;
        }
        reg_d0.h[0] = 0xF;
        task_start();
        task_stop_self();
    }
}

extern s16 D_00295E2E_as_s16_a[];
extern s16 D_00295E30_as_s16_a[];
extern s16 D_00295E32_as_s16_a[];
extern s32 D_00295E34_as_s32_a[];

void func_00122FD0(void) {
    D_00295E2E_as_s16_a[0] = 0;
    D_00295E30_as_s16_a[0] = 0;
    D_00295E32_as_s16_a[0] = 0;
    D_00295E34_as_s32_a[0] = 0;
}

#ifndef DEATH_LABEL
extern u16 D_00295E2E[];
extern u16 D_00295E30[];
extern u16 D_00295E32[];

void func_00123000(void) {
    if (D_00295E2E[0] == 0) {
        D_00295E2E[0] = 1;
        D_00295E30[0] = reg_d0.h[0];
        D_00295E32[0] = reg_d1.h[0];
    }
}
#endif

#ifndef DEATH_LABEL
s32 func_0013B350();
extern u8 D_0024D200[];
extern u8 D_0024D2D0[];
extern u16 D_00295E2C[];
extern u32 D_00295E34[];

void func_00123040(void) {
    s32 func_0013BE50();
    s32 func_0013C300();
    s32 func_0013C350();
    if (D_00295E2E[0] == 0) goto block_rts;
    if (D_00295E2E[0] != 1) goto next_1;
    if (D_00295E2C[0] == 0) goto next_2;
    reg_a0 = (u8 *)D_0024D200;
    reg_d0.h[0] = D_00295E32[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    func_0013BE50();
    D_00295E34[0] = reg_d0.w;
    D_00295E2E[0] = 2;
next_1:
    if (D_00295E2E[0] != 2) goto next_3;
    reg_d0.w = D_00295E34[0];
    func_0013C350();
    if (cond_flag != 0) goto next_3;
    func_0013C300();
next_2:
    D_00295E2C[0] = D_00295E30[0];
    D_00295E2E[0] = 3;
    if (D_00295E2C[0] != 0) goto next_3;
    D_00295E2E[0] = 0;
next_3:
    if (D_00295E2E[0] != 3) goto next_4;
    reg_a0 = (u8 *)D_0024D2D0;
    reg_d0.h[0] = D_00295E32[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    func_0013B350();
    D_00295E34[0] = reg_d0.w;
    D_00295E2E[0] = 4;
next_4:
    if (D_00295E2E[0] != 4) goto block_rts;
    reg_d0.w = D_00295E34[0];
    func_0013C350();
    if (cond_flag != 0) goto block_rts;
    func_0013C300();
    D_00295E2E[0] = 0;
block_rts:
    return;
}
#endif

extern Reg32 reg_d0;
extern u8 D_00295E00[];

void func_00123210(void) {
    reg_a6 = (u8 *)((u16 *)D_00295E00);
    *(u16 *)(reg_a6 + 8) = reg_d0.h[0];
    *(u16 *)(reg_a6 + 6) = 0;
}

s32 sprite_palette_load();
extern u8 D_0024D030[];
extern s16 D_00295E1C_as_s16_a[];
extern s16 D_00295E1E_as_s16_a[];
extern s16 D_00295E20_as_s16_a[];
extern s32 D_00295E24_as_s32_a[];
extern s32 D_00295E28_as_s32_a[];
extern u8 g_spare_entities[];

void func_00123240(void) {
    reg_a3 = g_spare_entities;
    reg_d7.h[0] = 0xC7;
    do {
        *(s16 *)reg_a3 = 0;
        *(s16 *)(reg_a3 + 2) = 0;
        *(s16 *)(reg_a3 + 4) = 0;
        *(s16 *)(reg_a3 + 6) = 0;
        reg_a3 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    D_00295E1C_as_s16_a[0] = 0;
    reg_a0 = D_0024D030;
    D_00295E1E_as_s16_a[0] = 0;
    reg_d0.h[0] = 0;
    D_00295E20_as_s16_a[0] = 0;
    D_00295E24_as_s32_a[0] = 0;
    D_00295E28_as_s32_a[0] = 0;
    sprite_palette_load();
}

#ifndef DEATH_LABEL
s32 sprite_draw_keep();

void func_001232E0(void) {
    reg_a3 = g_spare_entities;
    reg_d7.h[0] = 0xC7;
    do {
        reg_d2.h[1] = *(u16 *)reg_a3;
        reg_d2.h[0] = *(u16 *)(reg_a3 + 2);
        if (reg_d2.w != 0) {
            reg_d1.h[1] = *(u16 *)(reg_a3 + 4);
            reg_d1.h[0] = *(u16 *)(reg_a3 + 6);
            reg_d3.h[0] = 0x410;
            reg_d4.h[0] = 0;
            sprite_draw_keep();
        }
        reg_a3 += 8;
    } while ((s16)(--reg_d7.h[0]) >= 0);
}
#endif

#ifndef DEATH_LABEL
void func_00123380(void) {
    u32 tmp;

    reg_a3 = (u8 *)g_spare_entities;
    reg_d7.h[0] = 0xC7;
loop_1:
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 0);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 2);
    if (reg_tmp.w != 0) goto next_1;
    *(u16 *) (reg_a3 + 0) = reg_d0.h[1];
    *(u16 *) (reg_a3 + 2) = reg_d0.h[0];
    *(u16 *) (reg_a3 + 4) = reg_d1.h[1];
    *(u16 *) (reg_a3 + 6) = reg_d1.h[0];
    goto block_rts;
next_1:
    reg_a3 += 8;
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (u16) tmp << 0x30) >> 0x30) >= 0) goto loop_1;
block_rts:
    return;
}
#endif

#ifndef DEATH_LABEL
extern u32 D_0024CBE0[];
extern u16 D_00295E1C[];
extern u8 D_00295E1E[];
extern u8 D_00295E1F[];
extern u32 D_00295E28[];

void func_00123410(void) {
    reg_a2 = reg_a0;
    reg_a2 += D_00295E1C[0];
    reg_d0.h[0] = *(u16 *) reg_a2;
    reg_a2 += 2;
    if (0 > (s16) reg_d0.h[0]) {
        func_00123540();
        return;
    }
    D_00295E1F[0] -= 1;
    if (0 > (s8) D_00295E1F[0]) goto next_1;
    cond_flag = 1;
    return;
next_1:
    D_00295E1F[0] = D_00295E1E[0];
    reg_a1 = (u8 *) D_0024CBE0;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    reg_d0.w = *(u32 *) reg_a1;
    reg_d1.w = D_00295E28[0];
    func_00123380();
    cond_flag = 1;
    ((u16 *) D_00295E28)[0] += 0x400;
    D_00295E1C[0] += 2;
}
#endif

#ifndef DEATH_LABEL
extern u8 D_0024D340[];
extern u16 D_00295E1E_as_u16_a[];
extern u16 D_00295E20[];
extern u32 D_00295E24[];

void func_00123540(void) {
    void func_0013BE50(void);
    void func_0013C300(void);
    void func_0013C350(void);
    if (reg_d0.h[0] == 0x8000) {
        D_00295E1E_as_u16_a[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        D_00295E1C[0] += 4;
        func_00123410();
    } else if (reg_d0.h[0] == 0x8001) {
        reg_tmp.h[1] = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        D_00295E1C[0] += 6;
        D_00295E28[0] = reg_tmp.w;
        func_00123410();
    } else if (reg_d0.h[0] == 0x8002) {
        reg_d1.h[0] = D_00295E20[0];
        if (*(u16 *)reg_a2 == reg_d1.h[0]) {
            D_00295E20[0] = 0;
            D_00295E1C[0] += 4;
            func_00123410();
            return;
        }
        D_00295E20[0] += 1;
        cond_flag = 1;
    } else if (reg_d0.h[0] == 0x8003) {
        reg_d0.w = D_00295E24[0];
        if (reg_d0.w == 0) {
            reg_d0.h[0] = *(u16 *)reg_a2;
            reg_a0 = (u8 *)D_0024D340;
            reg_d0.h[0] += reg_d0.h[0];
            reg_d0.h[0] += reg_d0.h[0];
            reg_a0 += reg_d0.h[0];
            reg_a0 = *(u8 **)reg_a0;
            func_0013BE50();
            D_00295E24[0] = reg_d0.w;
            cond_flag = 1;
            return;
        }
        func_0013C350();
        if (cond_flag != 0) {
            cond_flag = 1;
            return;
        }
        func_0013C300();
        D_00295E24[0] = 0;
        D_00295E1C[0] += 4;
        func_00123410();
    } else if (reg_d0.h[0] == 0x8005) {
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_d1.h[0] = *(u16 *)(reg_a2 + 2);
        func_00123000();
        D_00295E1C[0] += 6;
        func_00123410();
    } else {
        cond_flag = 0;
    }
}
#endif

s32 func_0012FD00();
s32 func_0018DE90();
s32 func_0018DEA0();
s32 func_0018DEE0();
extern s16 g_ending_started;
extern s16 D_00295E3E_as_s16_a[];
extern s16 D_00295E40_as_s16_a[];
extern s16 g_player2[];
extern s16 g_player1[];

void func_00123780(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    g_ending_started = 1;
    reg_a0 = (u8 *)D_00295E00;
    memset(D_00295E00, 0, 0x44);
    reg_a6 = (u8 *)D_00295E00;
    reg_d0.w = 0;
    if (0 > g_player1[0]) {
        reg_d0.h[0] += 1;
    }
    if (0 > g_player2[0]) {
        reg_d0.h[0] += 1;
    }
    ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_d0.h[0];
    D_00295E3E_as_s16_a[0] = 0x101;
    D_00295E40_as_s16_a[0] = 0;
    func_0012FD00();
    func_0018DEE0();
    func_0018DE90();
    func_0018DEA0();
    func_00123870();
    func_00122CE0();
    if (cond_flag != 0) {
        reg_d0.w = 4;
        func_00123210();
    }
}

extern u16 D_0028E92C;
extern u16 D_0028E930;
extern s16 D_00295E2C_as_s16_a[];
extern s8 D_0029F261_as_s8_a[];

void func_00123870(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    func_00123240();
    func_00122FD0();
    reg_d0.w = 0;
    func_00123210();
    D_00295E2C_as_s16_a[0] = 0;
    reg_a6 = (u8 *)D_00295E00;
    if (ENTITY(reg_a6)->hit_y_plus.h != 1) goto next_0;
    reg_d0.h[0] = D_0028E930;
    if (0 > D_0029F261_as_s8_a[0]) goto next_1;
    reg_d0.h[0] = D_0028E92C;
    goto next_1;
next_0:
    reg_d0.h[0] = D_0028E930;
    if (ENTITY(reg_a6)->hit_y_minus.h == 0) goto next_1;
    reg_d0.h[0] = D_0028E92C;
next_1:
    if (reg_d0.h[0] == 2) {
        ENTITY(reg_a6)->look.h = 0U;
    }
    if (reg_d0.h[0] == 4) {
        ENTITY(reg_a6)->look.h = 1U;
    }
    if (reg_d0.h[0] == 6) {
        ENTITY(reg_a6)->look.h = 2U;
    }
    if (ENTITY(reg_a6)->hit_y_minus.h != 0) {
        reg_d0.w = 0;
        reg_d0.h[0] = ENTITY(reg_a6)->look.h;
        reg_d0.h[0] += 1;
        func_00123210();
    }
}

typedef void (*Fn)();

s32 sprite_draw_keep();
#ifdef DEATH_LABEL
void death_func_00139380(void);
#endif
extern u32 D_0024D070[];
extern u8 D_0024D090[];
extern u8 D_0028E368;
extern u8 D_0028E378;
extern u16 D_00295E2C[];
extern u8 D_00295E3E[];
extern u8 D_00295E3F[];
extern u16 D_00295E40[];

void func_00123980(void) {
    u8 mode;

    mode = *(u8 *)(reg_a5 + 3);
    if (mode == 0) {
        D_0028E368 = 0;
        D_0028E378 = 0xFF;
        func_00123780();
        return;
    }
    if (mode == 2) {
        func_00122EB0();
        return;
    }
    reg_a6 = (u8 *)D_00295E00;
#ifdef DEATH_LABEL
    death_func_00139380();
#else
    reg_d0.h[0] = ENTITY(reg_a6)->offset_x.h;
    ((Fn)*(u32 *)((u8 *)D_0024D090 + (reg_d0.h[0] * 4)))();
    func_001232E0();
    func_00123040();
    reg_d0.h[0] = D_00295E2C[0];
    if (reg_d0.h[0] != 0) {
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 = (u8 *)(D_0024D070);
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_d2.w = *(u32 *)reg_a0;
        reg_d1.w = 0x38000000;
        reg_d3.h[0] = 0x1CE0;
        reg_d4.h[0] = 1;
        reg_d4.h[0] += D_00295E40[0];
        sprite_draw_keep();
        D_00295E3F[0] -= 1;
        if (0 > (s8) D_00295E3F[0]) {
            D_00295E3F[0] = D_00295E3E[0];
            D_00295E40[0] += 1;
            D_00295E40[0] &= 1;
        }
    }
#endif
}

#ifndef DEATH_LABEL
s32 text_layer_clear();
s32 func_0018D3D0();
extern u8 D_0024D628[];

void func_00123B00(void) {
    u16 temp_a0;
    u8 *temp_a2;

    text_layer_clear();
    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        func_00123240();
        ENTITY(reg_a6)->sprite.h = 0U;
        func_0018D3D0();
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)D_0024D628;
        reg_d0.h[0] = ENTITY(reg_a6)->look.h;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a0 += reg_d0.h[0];
        reg_a0 = *(u8 **)reg_a0;
        temp_a0 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += temp_a0;
        reg_d0.w = *(u32 *)reg_a0;
        temp_a2 = (u8 *)(reg_a6 + 0xE);
        if (reg_d0.w == -1U) {
            reg_d0.h[0] = ENTITY(reg_a6)->look.h;
            reg_d0.h[0] += 1;
            func_00123210();
            return;
        }
        reg_a0 = (u8 *) reg_d0.w;
        func_00123410();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            func_00123240();
        }
    }
}
#endif

#ifndef DEATH_LABEL
s32 func_0018DA30();
s32 func_0018DA50();
s32 sprite_draw_layer5_keep();
extern u32 D_0024D640[];
extern u32 D_0024D660[];
extern u32 D_0025F770_as_u32_a[];
extern u32 D_0028C090;
extern u32 D_0028C098;
extern u16 D_00295E3A[];
extern s16 D_00295E3C_as_s16_a[];
void input_get_p1_pressed();
void input_get_p2_pressed();
extern u32 reg_call_target_as_u32;

#define W(o) (*(u16 *)(reg_a6 + (o)))

void func_00123C20(void) {
    s32 func_0013BE50();
    s32 func_0013C300();
    s32 func_0013C350();
    if (W(6) != 0) goto next_10;
    W(6) = 1;
    func_00123240();
    W(0xC) = 0;
    D_00295E3C_as_s16_a[0] = 1;
    D_00295E38[0] = 1;
    D_00295E3A[0] = 0x258;
    reg_a0 = (u8 *) D_0025F770_as_u32_a;
    reg_d0.h[0] = 3;
    sprite_palette_load();
next_10:
    if (W(6) != 1) goto next_20;
    reg_a0 = (u8 *) &D_0028C098;
    reg_a0 += W(0xC);
    reg_d0.w = *(u32 *)reg_a0;
    if (reg_d0.w != -1U) goto next_15;
    W(6) = 2;
    reg_tmp.w = (u32) (void *) input_get_p1_pressed;
    W(0x18) = reg_tmp.h[1];
    W(0x1A) = reg_tmp.h[0];
    if (0 > g_player1[0]) goto next_20;
    reg_tmp.w = (u32) (void *) input_get_p2_pressed;
    W(0x18) = reg_tmp.h[1];
    W(0x1A) = reg_tmp.h[0];
    goto next_20;
next_15:
    reg_a0 = (u8 *) reg_d0.w;
    func_00123410();
    if (cond_flag != 0) goto next_20;
    W(0xC) += 4;
next_20:
    if (W(6) != 2) goto next_40;
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    reg_call_target_as_u32 = reg_tmp.w;
    ((Fn) reg_call_target_as_u32)();
    if (!(reg_d0.h[0] & 4)) goto next_25;
    D_00295E38[0] += 1;
    func_0018DA50();
next_25:
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    reg_call_target_as_u32 = reg_tmp.w;
    ((Fn) reg_call_target_as_u32)();
    if (!(reg_d0.h[0] & 8)) goto next_28;
    D_00295E38[0] += 1;
    func_0018DA50();
next_28:
    D_00295E38[0] &= 1;
    reg_tmp.h[1] = W(0x18);
    reg_tmp.h[0] = W(0x1A);
    reg_call_target_as_u32 = reg_tmp.w;
    ((Fn) reg_call_target_as_u32)();
    reg_d0.h[0] &= 0x70;
    if (reg_d0.h[0] == 0) goto next_35;
next_32:
    func_0018DA30();
    reg_a0 = (u8 *) D_0024D640;
    func_0013BE50();
    W(0x14) = reg_d0.h[1];
    W(0x16) = reg_d0.h[0];
    W(6) = 3;
    goto next_40;
next_35:
    D_00295E3A[0] -= 1;
    if (D_00295E3A[0] == 0) goto next_32;
next_40:
    if (W(6) != 3) goto next_50;
    reg_d0.h[1] = W(0x14);
    reg_d0.h[0] = W(0x16);
    func_0013C350();
    if (cond_flag != 0) goto next_50;
    func_0013C300();
    *(s8 *)(reg_a5 + 3) = 2;
next_50:
    if ((s16) W(6) < 2) goto block_rts;
    reg_a0 = (u8 *) &D_0028C090;
    reg_d0.h[0] = D_00295E38[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d2.w = 0xE8;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 3;
    sprite_draw_layer5_keep();
    reg_d1.h[0] += 0x1000;
    reg_d4.h[0] |= 0x40;
    sprite_draw_layer5_keep();
    reg_d0.w = 0;
    reg_d0.h[0] = D_00295E3A[0];
    reg_d0.w /= 0x3C;
    reg_a0 = (u8 *) D_0024D660;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d1.w = 0x5E001C00;
    reg_d3.h[0] = 0x210;
    reg_d4.h[0] = 3;
    sprite_draw_layer5_keep();
block_rts:
    return;
}
#endif

#ifndef DEATH_LABEL
extern u32 D_0024DA90[];

void func_001240E0(void) {
    u16 temp_a1;

    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        func_00123240();
        ENTITY(reg_a6)->sprite.h = 0U;
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)(D_0024DA90);
        temp_a1 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += temp_a1;
        reg_d0.w = *(u32 *)reg_a0;
        if (reg_d0.w == -1U) {
            *(s8 *)(reg_a5 + 3) = 2;
            return;
        }
        reg_a0 = (u8 *) reg_d0.w;
        func_00123410();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            func_00123240();
        }
    }
}
#endif

#ifndef DEATH_LABEL
extern u32 D_0024DE00[];

void func_001241A0(void) {
    u16 temp_a1;

    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        func_00123240();
        ENTITY(reg_a6)->sprite.h = 0U;
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)(D_0024DE00);
        temp_a1 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += temp_a1;
        reg_d0.w = *(u32 *)reg_a0;
        if (reg_d0.w == -1U) {
            *(s8 *)(reg_a5 + 3) = 2;
            return;
        }
        reg_a0 = (u8 *) reg_d0.w;
        func_00123410();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            func_00123240();
        }
    }
}
#endif

#ifndef DEATH_LABEL
extern u32 D_0024E070[];

void func_00124260(void) {
    u16 temp_a1;

    if (ENTITY(reg_a6)->offset_y.h == 0) {
        ENTITY(reg_a6)->offset_y.h = 1U;
        func_00123240();
        ENTITY(reg_a6)->sprite.h = 0U;
    }
    if (ENTITY(reg_a6)->offset_y.h == 1) {
        reg_a0 = (u8 *)(D_0024E070);
        temp_a1 = ENTITY(reg_a6)->sprite.h;
        reg_a0 += temp_a1;
        reg_d0.w = *(u32 *)reg_a0;
        if (reg_d0.w == -1U) {
            *(s8 *)(reg_a5 + 3) = 2;
            return;
        }
        reg_a0 = (u8 *) reg_d0.w;
        func_00123410();
        if (cond_flag == 0) {
            ENTITY(reg_a6)->sprite.h += 4;
            func_00123240();
        }
    }
}
#endif
