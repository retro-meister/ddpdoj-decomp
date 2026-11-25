#include "common.h"
#include "entity.h"
#include "player.h"

void func_001406F0(void);
void func_00141300(void);
void func_00141710(void);
void func_001417D0(void);
void func_00141B50(void);
void func_001420E0(void);
void func_001440D0(void);
void func_00144400(void);
void func_00144AD0(void);
void func_00144B20(void);
void func_00144B70(void);
void func_00144B80(void);
void func_00144C10(void);
void func_00144C20(void);
void func_00144CB0(void);
void func_00144F00(void);
void func_00145640(void);
void func_00145A80();


void func_0013F990(void) {
    *(u16 *)(reg_a4 + 0x60) = 0;
}

s32 func_0018D9B0();
s32 func_001AC3A0();
extern u16 D_0028E014;
extern u16 D_0028E024;
extern u8 D_0028E290;
extern s8 D_0028E3F8;
extern u16 g_p1_lives;
extern u16 g_loop;
extern u16 g_stage;

#ifdef DEATH_LABEL
extern u8 death_D_00290850;
extern u8 death_D_00290DC0;
#endif

void func_0013F9A0(void) {
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
    u32 temp_a0;

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
    if ((D_0028E290 == 2) || ((g_loop != 0) && ((D_0028E024 == 0) || (D_0028E014 == 0)))) {
#ifdef DEATH_LABEL
        if (death_D_00290DC0 == 0)
#endif
        {
        temp_a0 = g_p1_lives;
        if (temp_a0 != 0x14) {
            g_p1_lives = temp_a0 + 1;
            func_001AC3A0();
#ifdef DEATH_LABEL
            if (death_D_00290850 == 0) {
                if (g_stage == 4) {
                    death_D_00290850 = 1;
                }
                func_0018D9B0();
            }
#else
            if ((D_0028E3F8 == 0) && ((s32) g_stage < 4)) {
                func_0018D9B0();
            }
#endif
        }
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
}

s32 func_001AC5F0();
extern u16 D_0028E010;
extern u16 D_0028E020;
extern u16 g_p2_lives;

#ifdef DEATH_LABEL
extern u8 death_D_00290850;
extern u8 death_D_00290DC0;
#endif

void func_0013FB20(void) {
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
    u32 temp_a0;

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
    if ((D_0028E290 == 2) || ((g_loop != 0) && ((D_0028E020 == 0) || (D_0028E010 == 0)))) {
#ifdef DEATH_LABEL
        if (death_D_00290DC0 == 0)
#endif
        {
        temp_a0 = g_p2_lives;
        if (temp_a0 != 0x14) {
            g_p2_lives = temp_a0 + 1;
            func_001AC5F0();
#ifdef DEATH_LABEL
            if (death_D_00290850 == 0) {
                if (g_stage == 4) {
                    death_D_00290850 = 1;
                }
                func_0018D9B0();
            }
#else
            if ((D_0028E3F8 == 0) && ((s32) g_stage < 4)) {
                func_0018D9B0();
            }
#endif
        }
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
}

extern u16 g_p1_hyper_items_pending;
extern u16 g_p1_hyper_items;
extern u16 g_p1_hyper_in_effect;
extern u16 g_p1_hyper_level;
extern u16 g_p1_hyper_combo_decay;
extern u16 g_p1_hyper_gauge;
extern u16 g_p1_hyper_time;
extern u16 g_p1_hyper_active;
extern s32 D_002BAEF0[];

void func_0013FCA0(void) {
    reg_d0.w = 0;
    D_002BAEF0[0] = 0;
    g_p1_hyper_active = reg_d0.h[0];
    g_p1_hyper_gauge = reg_d0.h[0];
    g_p1_hyper_time = reg_d0.h[0];
    g_p1_hyper_combo_decay = reg_d0.h[0];
    g_p1_hyper_level = reg_d0.h[0];
    g_p1_hyper_in_effect = reg_d0.h[0];
    g_p1_hyper_items = reg_d0.h[0];
    g_p1_hyper_items_pending = reg_d0.h[0];
}

extern u16 g_p2_hyper_items_pending;
extern u16 g_p2_hyper_items;
extern u16 g_p2_hyper_in_effect;
extern u16 g_p2_hyper_level;
extern u16 g_p2_hyper_combo_decay;
extern u16 g_p2_hyper_gauge;
extern u16 g_p2_hyper_time;
extern u16 g_p2_hyper_active;
extern s32 D_002BAEB0[];

void func_0013FCE0(void) {
    reg_d0.w = 0;
    D_002BAEB0[0] = 0;
    g_p2_hyper_active = reg_d0.h[0];
    g_p2_hyper_gauge = reg_d0.h[0];
    g_p2_hyper_time = reg_d0.h[0];
    g_p2_hyper_combo_decay = reg_d0.h[0];
    g_p2_hyper_level = reg_d0.h[0];
    g_p2_hyper_in_effect = reg_d0.h[0];
    g_p2_hyper_items = reg_d0.h[0];
    g_p2_hyper_items_pending = reg_d0.h[0];
}

extern u16 g_p1_hyper_total;

void func_0013FD20(void) {
    reg_d0.w = 0;
    D_002BAEF0[0] = 0;
    g_p1_hyper_active = reg_d0.h[0];
    g_p1_hyper_total = reg_d0.h[0];
    g_p1_hyper_gauge = reg_d0.h[0];
    g_p1_hyper_combo_decay = reg_d0.h[0];
    g_p1_hyper_level = reg_d0.h[0];
    g_p1_hyper_in_effect = reg_d0.h[0];
    g_p1_hyper_items_pending = reg_d0.h[0];
}

extern u16 g_p2_hyper_total;

void func_0013FD50(void) {
    reg_d0.w = 0;
    D_002BAEB0[0] = 0;
    g_p2_hyper_active = reg_d0.h[0];
    g_p2_hyper_total = reg_d0.h[0];
    g_p2_hyper_gauge = reg_d0.h[0];
    g_p2_hyper_combo_decay = reg_d0.h[0];
    g_p2_hyper_level = reg_d0.h[0];
    g_p2_hyper_in_effect = reg_d0.h[0];
    g_p2_hyper_items_pending = reg_d0.h[0];
}

extern s16 D_0028DFB4_as_s16;
extern s16 D_0028DFB8_as_s16;
extern s16 D_0028DFBC_as_s16;
extern s16 D_0028DFC0_as_s16;
extern s16 D_0028DFC4_as_s16;
extern s16 D_0028DFC8_as_s16;
extern s16 D_0028DFCC_as_s16;
extern s16 D_0028DFD0_as_s16;
extern s16 D_0028DFD4_as_s16;
extern s16 D_0028DFD8_as_s16;
extern s16 D_0028DFDC_as_s16;
extern s16 D_0028DFE0_as_s16;
extern s16 D_0028DFE4_as_s16;
extern s16 D_0028DFE8_as_s16;
extern s16 D_0028DFEC_as_s16;
extern s16 D_0028DFF0_as_s16;
extern s32 D_0028DFF4;
extern s16 D_0028DFF8_as_s16;
extern s16 D_0028DFFC_as_s16;
extern s16 D_0028E000_as_s16;
extern s16 D_0028E004_as_s16;
extern s16 D_0028E008_as_s16;
extern s16 D_0028E00C_as_s16;
extern s16 D_0028E010_as_s16;
extern s16 D_0028E014_as_s16;
extern s16 D_0028E018_as_s16;
extern s16 D_0028E01C_as_s16;
extern s16 D_0028E020_as_s16;
extern s16 D_0028E024_as_s16;
extern s16 D_0028E028_as_s16;
extern s16 D_0028E02C_as_s16;
extern s16 D_0028E030_as_s16;
extern s16 D_0028E034_as_s16;
extern s16 D_0028E038_as_s16;
extern s16 D_0028E03C_as_s16;
extern s16 D_0028E040_as_s16;
extern s16 D_0028E044_as_s16;
extern s16 D_0028E048;
extern s16 D_0028E04C;
extern s16 D_0028E050_as_s16;
extern s16 D_0028E054_as_s16;
extern s32 D_0028E058;
extern s32 D_0028E05C;
extern s16 D_0028E060_as_s16;
extern s16 D_0028E064_as_s16;
extern s16 D_0028E068_as_s16;
extern s16 D_0028E06C_as_s16;
extern s16 D_0028E070_as_s16;
extern s16 D_0028E074_as_s16;
extern s32 D_0028E078_as_s32_a[];
extern s32 D_0028E07C_as_s32_a[];
extern s32 D_0028E080_as_s32_a[];
extern s32 D_0028E084_as_s32_a[];
extern s16 D_0028E088_as_s16;
extern s16 D_0029CD80_as_s16_a[];
extern s32 D_0029CD84[];
extern s32 D_0029CD88_as_s32_a[];
extern s16 D_0029CD8C_as_s16_a[];
extern s16 D_0029CD8E_as_s16_a[];
extern s16 D_0029CD90_as_s16_a[];
extern s32 D_0029CD94[];
extern s32 D_0029CD98_as_s32_a[];
extern s16 D_0029CD9C_as_s16_a[];
extern s16 D_0029CD9E_as_s16_a[];
extern u8 D_0029CDA0[];
extern u8 D_0029CDE0_as_u8_a[];
extern u8 D_0029CE20[];
extern u8 D_0029CE60_as_u8_a[];
extern u8 D_0029CEA0_as_u8_a[];
extern u8 D_0029D710[];
extern u8 D_0029D730[];
extern u8 D_0029D750[];
extern u8 D_0029D770[];
extern u8 D_0029D790[];
extern u8 D_0029DD90[];
extern u8 D_0029E390[];
extern u8 D_0029F110[];
extern u8 D_0029F180[];
extern u8 g_player2_as_u8_a[];
extern u8 g_player1_as_u8_a[];
void func_0013FD80(void) {
    s8 *temp_v1;
    u8 *temp_a1;
    u8 *temp_a1_2;
    s8 *var_a1;
    u8 *temp_a2;
    u8 *temp_a2_3;
    u8 *temp_a2_4;
    u8 *temp_a2_5;
    s32 var_a2;
    s32 var_a2_2;
    u8 *temp_a3_2;
    u8 *temp_a3_3;
    u8 *temp_a3_4;
    s32 var_a3;
    u8 *temp_t0;
    s32 var_t0_2;
    s32 var_t0_3;
    s32 var_t0_4;
    s32 var_t0_5;
    u8 *temp_t1;
    u8 *temp_t2;
    u8 *temp_t3;
    u8 *temp_t4;
    s32 var_t5;

    var_a3 = 0;
    do {
        temp_a2 = (u8 *)(g_player1_as_u8_a + var_a3);
        temp_t0 = (u8 *)(g_player2_as_u8_a + var_a3);
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a3 += 8;
        (*(s8 *)((u8 *)(temp_t0) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_t0) + (7))) = 0;
    } while (var_a3 < 0x5A);
    if (var_a3 < 0x62) {
        var_a1 = (s8 *)(g_player1_as_u8_a + var_a3);
        do {
            temp_v1 = (s8 *)(g_player2_as_u8_a + var_a3);
            var_a1 = (s8 *)(g_player1_as_u8_a + var_a3);
            *var_a1 = 0;
            *temp_v1 = 0;
            var_a3 += 1;
        } while (var_a3 < 0x62);
    }
    for (var_a3 = 0; var_a3 < 0x64; var_a3++) {
        D_0029F180[var_a3] = 0;
        D_0029F110[var_a3] = 0;
    }
    var_a2 = 0;
    do {
        temp_a1 = (u8 *)(D_0029E390 + var_a2);
        (*(s8 *)((u8 *)(temp_a1) + (0))) = 0;
        var_a2 += 8;
        (*(s8 *)((u8 *)(temp_a1) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a1) + (7))) = 0;
    } while (var_a2 < 0xD80);
    var_t0_2 = 0;
    do {
        temp_a2_3 = (u8 *)(D_0029DD90 + var_t0_2);
        temp_a3_2 = (u8 *)(D_0029D790 + var_t0_2);
        (*(s8 *)((u8 *)(temp_a2_3) + (0))) = 0;
        var_t0_2 += 8;
        (*(s8 *)((u8 *)(temp_a3_2) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2_3) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_a3_2) + (7))) = 0;
    } while (var_t0_2 < 0x600);
    var_t0_3 = 0;
    do {
        temp_a2_4 = (u8 *)(D_0029D770 + var_t0_3);
        temp_a3_3 = (u8 *)(D_0029D750 + var_t0_3);
        (*(s8 *)((u8 *)(temp_a2_4) + (0))) = 0;
        var_t0_3 += 8;
        (*(s8 *)((u8 *)(temp_a3_3) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2_4) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_a3_3) + (7))) = 0;
    } while (var_t0_3 < 0x20);
    var_t0_4 = 0;
    do {
        temp_a2_5 = (u8 *)(D_0029D730 + var_t0_4);
        temp_a3_4 = (u8 *)(D_0029D710 + var_t0_4);
        (*(s8 *)((u8 *)(temp_a2_5) + (0))) = 0;
        var_t0_4 += 8;
        (*(s8 *)((u8 *)(temp_a3_4) + (0))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2_5) + (7))) = 0;
        (*(s8 *)((u8 *)(temp_a3_4) + (7))) = 0;
    } while (var_t0_4 < 0x20);
    var_a2_2 = 0;
    do {
        temp_a1_2 = (u8 *)(D_0029CEA0_as_u8_a + var_a2_2);
        (*(s8 *)((u8 *)(temp_a1_2) + (0))) = 0;
        var_a2_2 += 8;
        (*(s8 *)((u8 *)(temp_a1_2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a1_2) + (7))) = 0;
    } while (var_a2_2 < 0x870);
    D_0028E088_as_s16 = 0;
    D_0028E080_as_s32_a[0] = 0;
    var_t5 = 0;
    var_t0_5 = 0;
    D_0028E084_as_s32_a[0] = 0;
    D_0028E078_as_s32_a[0] = 0;
    D_0028E07C_as_s32_a[0] = 0;
    do {
        temp_t1 = (u8 *)(D_0029CE60_as_u8_a + var_t0_5);
        temp_t2 = (u8 *)(D_0029CE20 + var_t0_5);
        temp_t3 = (u8 *)(D_0029CDE0_as_u8_a + var_t0_5);
        var_t5 += 8;
        (*(s32 *)((u8 *)(temp_t1) + (0))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0))) = 0;
        temp_t4 = (u8 *)(D_0029CDA0 + var_t0_5);
        (*(s32 *)((u8 *)(temp_t3) + (0))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (4))) = 0;
        var_t0_5 += 0x20;
        (*(s32 *)((u8 *)(temp_t2) + (4))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (4))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (4))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (8))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0xC))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x10))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x14))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x18))) = 0;
        (*(s32 *)((u8 *)(temp_t1) + (0x1C))) = 0;
        (*(s32 *)((u8 *)(temp_t2) + (0x1C))) = 0;
        (*(s32 *)((u8 *)(temp_t3) + (0x1C))) = 0;
        (*(s32 *)((u8 *)(temp_t4) + (0x1C))) = 0;
    } while (var_t5 < 0x10);
    D_0028E074_as_s16 = 0;
    D_0029CD90_as_s16_a[0] = 0;
    D_0028E070_as_s16 = 0;
    D_0029CD94[0] = 0;
    D_0028E06C_as_s16 = 0;
    D_0029CD98_as_s32_a[0] = 0;
    D_0028E068_as_s16 = 0;
    D_0029CD9C_as_s16_a[0] = 0;
    D_0028E064_as_s16 = 0;
    D_0029CD9E_as_s16_a[0] = 0;
    D_0028E060_as_s16 = 0;
    D_0029CD80_as_s16_a[0] = 0;
    D_0028E05C = 0;
    D_0029CD84[0] = 0;
    D_0028E058 = 0;
    D_0029CD88_as_s32_a[0] = 0;
    D_0028E054_as_s16 = 0;
    D_0029CD8C_as_s16_a[0] = 0;
    D_0028E050_as_s16 = 0;
    D_0029CD8E_as_s16_a[0] = 0;
    D_0028E04C = 0;
    D_0028E048 = 0;
    D_0028E044_as_s16 = 0;
    D_0028E040_as_s16 = 0;
    D_0028E03C_as_s16 = 0;
    D_0028E038_as_s16 = 0;
    D_0028E034_as_s16 = 0;
    D_0028E030_as_s16 = 0;
    D_0028E02C_as_s16 = 0;
    D_0028E028_as_s16 = 0;
    D_0028E024_as_s16 = 0;
    D_0028E020_as_s16 = 0;
    D_0028E01C_as_s16 = 0;
    D_0028E018_as_s16 = 0;
    D_0028E014_as_s16 = 0;
    D_0028E010_as_s16 = 0;
    D_0028E00C_as_s16 = 0;
    D_0028E008_as_s16 = 0;
    D_0028E004_as_s16 = 0;
    D_0028E000_as_s16 = 0;
    D_0028DFFC_as_s16 = 0;
    D_0028DFF8_as_s16 = 0;
    D_0028DFF4 = 0;
    D_0028DFF0_as_s16 = 0;
    D_0028DFEC_as_s16 = 0;
    D_0028DFE8_as_s16 = 0;
    D_0028DFE4_as_s16 = 0;
    D_0028DFE0_as_s16 = 0;
    D_0028DFDC_as_s16 = 0;
    D_0028DFD8_as_s16 = 0;
    D_0028DFD4_as_s16 = 0;
    D_0028DFD0_as_s16 = 0;
    D_0028DFCC_as_s16 = 0;
    D_0028DFC8_as_s16 = 0;
    D_0028DFC4_as_s16 = 0;
    D_0028DFC0_as_s16 = 0;
    D_0028DFBC_as_s16 = 0;
    D_0028DFB8_as_s16 = 0;
    D_0028DFB4_as_s16 = 0;
}


void func_00140280(s32 *arg0, u32 *arg1) {
    s32 carry;
    s32 n;
    s32 digit;
    s32 i;

    carry = 0;
    n = 0;
    reg_tmp.w = *arg1;
    reg_tmp1.w = *arg0;
    reg_d2.w = 0;
    do {
        digit = carry + ((reg_tmp.w & 0xF) + (reg_tmp1.w & 0xF));
        carry = 0;
        if (digit >= 0xA) {
            carry = 1;
            digit -= 0xA;
        }
        n += 1;
        reg_tmp.w = (u32) reg_tmp.w >> 4;
        reg_tmp1.w = (u32) reg_tmp1.w >> 4;
        reg_d2.w *= 0x10;
        reg_d2.w |= digit;
    } while (n < 8);
    *arg0 = 0;
    for (i = 0; i < 8; i++) {
        *arg0 *= 0x10;
        *arg0 = *arg0 | (reg_d2.w & 0xF);
        reg_d2.w = (u32) ((s64) (((u64) reg_d2.w >> 4) << 0x20) >> 0x20);
    }
}

extern u16 D_0028E03C;
extern u16 D_0028E044;
extern u16 D_0028E05C_as_u16;
extern u16 D_0028E05E;
extern u8 D_0028E080[];
extern s16 g_p1_hyper_effect_flag_as_s16;
extern u16 g_two_player_seen;
extern u16 D_0028E930;
extern u16 D_0028E938;
extern s8 D_0028ED6C_as_s8;
extern u8 D_0028ED7C;
extern u8 D_0029CD90_as_u8_a[];

void func_001404B0() {
    reg_a6 = g_player1_as_u8_a;
    reg_a2 = D_0029F180;
    g_two_player_seen |= 1;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 2);
    *(u8 *)(reg_a5 + 2) |= 1;
    if (reg_tmp.b[0] & 1) {
        func_001420E0();
        return;
    }
    g_p1_hyper_effect_flag_as_s16 = 0;
    if (D_0028ED7C == 1) {
        D_0028ED6C_as_s8 = 1;
    }
    reg_a3 = D_0029CD90_as_u8_a;
    reg_a4 = D_0028E080;
    reg_d3.w = 0x25000E00;
    reg_d4.h[0] = D_0028E03C;
    reg_d6.h[0] = D_0028E044;
    PLAYER(reg_a6)->ship_type.h = (u16) D_0028E938;
    PLAYER(reg_a6)->power_style.h = (u16) D_0028E930;
    if (*(u8 *)(reg_a5 + 7) != 0) {
        func_001406F0();
        return;
    }
    D_0028E06C_as_s16 = 2;
    D_0028E068_as_s16 = 2;
    reg_tmp.w = 0xC30;
    D_0028E054_as_s16 = 0x101;
    D_0028E074_as_s16 = 0;
    D_0028E05C_as_u16 = reg_tmp.h[1];
    D_0028E05E = reg_tmp.h[0];
    func_001406F0();
}

extern u16 D_0028E038;
extern u16 D_0028E040;
extern u16 D_0028E058_as_u16;
extern u16 D_0028E05A;
extern u8 D_0028E078[];
extern s16 g_p2_hyper_effect_flag_as_s16;
extern u16 D_0028E92C;
extern u16 D_0028E934;
extern u8 D_0029CD80_as_u8_a[];

void func_001405D0() {
    reg_a6 = g_player2_as_u8_a;
    reg_a2 = D_0029F110;
    g_two_player_seen |= 2;
    reg_tmp.b[0] = *(u8 *)(reg_a5 + 2);
    *(u8 *)(reg_a5 + 2) |= 1;
    if (reg_tmp.b[0] & 1) {
        func_001420E0();
        return;
    }
    g_p2_hyper_effect_flag_as_s16 = 0;
    if (D_0028ED7C == 1) {
        D_0028ED6C_as_s8 = 1;
    }
    reg_a3 = D_0029CD80_as_u8_a;
    reg_a4 = D_0028E078;
    reg_d3.w = 0x25002E00;
    reg_d4.h[0] = D_0028E038;
    reg_d6.h[0] = D_0028E040;
    PLAYER(reg_a6)->ship_type.h = (u16) D_0028E934;
    PLAYER(reg_a6)->power_style.h = (u16) D_0028E92C;
    if (*(u8 *)(reg_a5 + 7) != 0) {
        func_001406F0();
        return;
    }
    D_0028E064_as_s16 = 2;
    D_0028E060_as_s16 = 2;
    reg_tmp.w = 0xC30;
    D_0028E050_as_s16 = 0x101;
    D_0028E070_as_s16 = 0;
    D_0028E058_as_u16 = reg_tmp.h[1];
    D_0028E05A = reg_tmp.h[0];
    func_001406F0();
}

s32 func_001340B0();
s32 func_0013E6C0();
s32 func_0013E710();
s32 func_00145E70(u8 *);
s32 func_001ABCA0();
s32 func_001ABEA0();
extern u16 D_002555C0[];
extern u16 D_002555D0[];
extern u16 D_002555E0_as_u16_a[];
extern u16 D_002556E0[];
extern u16 D_002560C0[];
extern u16 D_0028C5F8[];
extern u16 D_0028C600[];
extern u16 D_0028C608_as_u16_a[];
extern u16 D_0028DFB4;
extern u16 D_0028DFB8;
extern u16 D_0028DFBC;
extern u16 D_0028DFC0;
extern u16 D_0028DFC4;
extern u16 D_0028E028;
extern u16 D_0028E02C;
extern u8 D_0028E280;
extern u8 D_0028E284;
extern u8 D_0028E288;
extern u8 D_0028E2A8;
extern u16 D_0028E2AC;
extern u8 D_0028E2B0;
extern u8 D_0028E2C4;
extern u8 D_0028ED80;
extern u16 D_006E5BF0[];
extern u16 D_006E5BF2[];
extern u16 D_006E5BFC[];
extern u16 D_006E5C12[];
extern u16 D_006E5C14[];

#ifdef DEATH_LABEL
extern u16 D_0028E3C0;
extern u16 D_0028E810;
#endif

void func_001406F0(void) {
    s32 i;
    s32 val;
    s32 rem;
    s32 n;

    *(u16 *)reg_a2 = 0x8000;
    reg_a0 = (u8 *)D_002560C0;
    D_0028DFC0 = 0;
    D_0028DFC4 = 0;
    D_0028DFBC = 0;
    reg_a1 = reg_a6;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] |= PLAYER(reg_a6)->flags.h;
    *(u16 *)reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    reg_d0.h[1] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_d1.h[1] = PLAYER(reg_a6)->shot_power.h;
    reg_d1.h[0] = PLAYER(reg_a6)->laser_power.h;
    reg_d2.b[0] = reg_a6[0x24];
    if (reg_a5[7] != 0) goto skip_1;
    reg_d5.w = 0x2F;
    do {
        *(u16 *)reg_a1 = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a1 += 2;
    } while ((s16)(--reg_d5.h[0]) >= 0);
skip_1:
    PLAYER(reg_a6)->ship_type.h = reg_d0.h[1];
    PLAYER(reg_a6)->power_style.h = reg_d0.h[0];
    reg_a6[0x56] = reg_a5[6];
    if (reg_a5[7] != 0) goto next_30;
    reg_d0.w = 0;
    *(u16 *)(reg_a3 + 0) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 4) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 6) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 8) = reg_d0.h[1];
    *(u16 *)(reg_a3 + 0xA) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 0xC) = reg_d0.h[0];
    *(u16 *)(reg_a3 + 0xE) = reg_d0.h[0];
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_a0 = (u8 *)D_0028C608_as_u16_a;
    reg_d0.h[0] -= 2;
    reg_a0 += reg_d0.h[0];
    reg_d0.b[0] = reg_a0[1];
    reg_a6[0x25] = reg_d0.b[0];
    reg_a6[0x24] = reg_a0[0];
    reg_a0 += 2;
    if (reg_d6.h[0] == 0) goto next_25;
    PLAYER(reg_a6)->shot_power.h = reg_d1.h[1];
    PLAYER(reg_a6)->laser_power.h = reg_d1.h[0];
    reg_a6[0x25] = reg_d2.b[0];
    reg_a6[0x24] = reg_d2.b[0];
    if (reg_d4.h[0] != 0) goto next_30;
next_25:
    reg_a6[0x25] = reg_d0.b[0];
    reg_a6[0x24] = reg_d0.b[0];
    reg_d0.w = 0;
    PLAYER(reg_a6)->shot_power.h = reg_d0.h[1];
    PLAYER(reg_a6)->laser_power.h = reg_d0.h[0];
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += PLAYER(reg_a6)->ship_type.h;
    reg_a2 = (u8 *)D_002555E0_as_u16_a;
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 2) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 4) = ((reg_d0.h[0] + 4) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
    *(u16 *)(reg_a4 + 6) = ((reg_d0.h[0] + 6) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
next_30:
    reg_d0.w = 0;
    reg_d0.b[0] = reg_a5[6];
    if (D_0028ED80 != 0) {
        func_00141300();
    }
    func_001340B0();
#ifdef DEATH_LABEL
    if (D_0028E3C0 != 0) {
        reg_d1.w = 0;
        reg_d1.h[0] = D_0028E810;
        PLAYER(reg_a6)->shot_power.h = reg_d1.h[0];
        PLAYER(reg_a6)->laser_power.h = reg_d1.h[0];
        reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += PLAYER(reg_a6)->ship_type.h;
        reg_a2 = (u8 *)D_002555E0_as_u16_a;
        reg_d0.h[0] <<= 2;
        *(u16 *)(reg_a4 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 2) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 4) = ((reg_d0.h[0] + 4) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a2;
        *(u16 *)(reg_a4 + 6) = ((reg_d0.h[0] + 6) != 0) ? *(u16 *)((u8 *)reg_a2 + ((s16)(reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a2;
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 2);
        reg_tmp.w += reg_d1.w;
        *(u16 *)(reg_a4 + 0) = reg_tmp.h[1];
        *(u16 *)(reg_a4 + 2) = reg_tmp.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a4 + 4);
        reg_tmp.h[0] = *(u16 *)(reg_a4 + 6);
        reg_tmp.w += reg_d1.w;
        *(u16 *)(reg_a4 + 4) = reg_tmp.h[1];
        *(u16 *)(reg_a4 + 6) = reg_tmp.h[0];
    }
#endif
    if (D_0028E290 != 2) goto next_40;
    if (reg_d6.h[0] != 0) goto next_35;
    func_001417D0();
    goto next_36;
next_35:
    func_00141710();
next_36:
    func_00145E70(reg_a6);
next_40:
    if (D_0028ED80 == 0) goto next_76;
    if (reg_d6.h[0] == 0) goto next_41;
    if (D_0028E2C4 == 0) goto next_76;
next_41:
#ifndef DEATH_LABEL
    if (reg_a6 == g_player1_as_u8_a) {
        D_0028E02C = D_006E5C14[0];
    } else {
        D_0028E028 = D_006E5C14[0];
    }
#endif
    reg_d1.w = 0;
    reg_d1.h[0] = D_006E5BF2[0];
    PLAYER(reg_a6)->shot_power.h = reg_d1.h[0];
    reg_d1.h[0] = D_006E5BF0[0];
    PLAYER(reg_a6)->laser_power.h = reg_d1.h[0];
    func_00145E70(reg_a6);
    g_p1_hyper_items = 0;
    g_p2_hyper_items = 0;
    if (D_0028E2B0 != 0) goto next_60;
    for (i = 0; i < D_006E5BFC[0]; i++) {
        if (reg_a6 == g_player1_as_u8_a) {
            func_0013E6C0();
        } else {
            func_0013E710();
        }
    }
#ifdef DEATH_LABEL
    if (reg_a6 == g_player1_as_u8_a) {
        if (D_0028E2AC == 0) goto next_50;
        if (reg_d6.h[0] == 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p1_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p1_hyper_items_pending = 4;
                g_p1_hyper_gauge = 0x95F;
            } else {
                g_p1_hyper_items_pending = val / 100;
            }
        } else {
            val = D_0028E2AC & 0xFFFF;
            if (val >= 100) {
                g_p1_hyper_items_pending = 0;
                g_p1_hyper_gauge = 0x95F;
            } else {
                g_p1_hyper_items_pending = 0;
                g_p1_hyper_gauge = ((val % 100) * 0x960) / 100;
            }
        }
    } else {
        if (D_0028E2AC == 0) goto next_50;
        if (reg_d6.h[0] == 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p2_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p2_hyper_items_pending = 4;
                g_p2_hyper_gauge = 0x95F;
            } else {
                g_p2_hyper_items_pending = val / 100;
            }
        } else {
            val = D_0028E2AC & 0xFFFF;
            if (val >= 100) {
                g_p2_hyper_items_pending = 0;
                g_p2_hyper_gauge = 0x95F;
            } else {
                g_p2_hyper_items_pending = 0;
                g_p2_hyper_gauge = ((val % 100) * 0x960) / 100;
            }
        }
    }
#else
    if (reg_d6.h[0] != 0) goto next_45;
    if (D_0028E280 != 5) goto next_45;
    if (reg_a6 == g_player1_as_u8_a) {
        if (g_p1_hyper_items != 0) {
            g_p1_hyper_time = 0;
            D_0028E288 = 0x78;
        }
    } else if (g_p2_hyper_items != 0) {
        g_p2_hyper_time = 0;
        D_0028E284 = 0x78;
    }
next_45:
    if (reg_a6 == g_player1_as_u8_a) {
        if (D_0028E2AC == 0) goto next_50;
        val = D_0028E2AC & 0xFFFF;
        rem = val % 100;
        g_p1_hyper_gauge = (rem * 0x960) / 100;
        if (val == 0x1F4) {
            g_p1_hyper_items_pending = 4;
            g_p1_hyper_gauge = 0x95F;
        } else {
            g_p1_hyper_items_pending = val / 100;
        }
        if (reg_d6.h[0] == 0) goto next_50;
        func_001ABCA0();
    } else {
        if (D_0028E2AC == 0) goto next_50;
        val = D_0028E2AC & 0xFFFF;
        rem = val % 100;
        g_p2_hyper_gauge = (rem * 0x960) / 100;
        if (val == 0x1F4) {
            g_p2_hyper_items_pending = 4;
            g_p2_hyper_gauge = 0x95F;
        } else {
            g_p2_hyper_items_pending = val / 100;
        }
        if (reg_d6.h[0] == 0) goto next_50;
        func_001ABEA0();
    }
#endif
next_50:
    if (reg_a6 == g_player1_as_u8_a) {
        g_p1_hyper_total = D_006E5C12[0];
    } else {
        g_p2_hyper_total = D_006E5C12[0];
    }
    goto next_76;
next_60:
    if (reg_a6 == g_player1_as_u8_a) {
        g_p1_hyper_total = D_006E5C12[0];
    } else {
        g_p2_hyper_total = D_006E5C12[0];
    }
    n = D_006E5BFC[0];
    if (n == 0) {
        n = 1;
    }
    if (reg_a6 == g_player1_as_u8_a) {
        g_p1_hyper_in_effect = 1;
        g_p1_hyper_active = 1;
        D_0028DFB8 = 1;
        PLAYER(reg_a6)->flags.b[0] |= 1;
        g_p1_hyper_level = n;
        g_p1_hyper_items = 0;
        if (D_0028E2AC != 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p1_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p1_hyper_items_pending = 4;
                g_p1_hyper_gauge = 0x95F;
            } else {
                g_p1_hyper_items_pending = val / 100;
            }
        }
        if (D_0028E2A8 != 0) {
            val = D_0028E2A8 & 0xFF;
            g_p1_hyper_time = (val * 0x960) / 100;
        }
        g_p1_hyper_combo_decay = 0;
    } else {
        g_p2_hyper_in_effect = 1;
        g_p2_hyper_active = 1;
        D_0028DFB4 = 1;
        PLAYER(reg_a6)->flags.b[0] |= 1;
        g_p2_hyper_level = n;
        g_p2_hyper_items = 0;
        if (D_0028E2AC != 0) {
            val = D_0028E2AC & 0xFFFF;
            rem = val % 100;
            g_p2_hyper_gauge = (rem * 0x960) / 100;
            if (val == 0x1F4) {
                g_p2_hyper_items_pending = 4;
                g_p2_hyper_gauge = 0x95F;
            } else {
                g_p2_hyper_items_pending = val / 100;
            }
        }
        if (D_0028E2A8 != 0) {
            val = D_0028E2A8 & 0xFF;
            g_p2_hyper_time = (val * 0x960) / 100;
        }
        g_p2_hyper_combo_decay = 0;
    }
next_76:
    reg_a6[0x3F] = 0xF0;
    if (D_0028E290 == 2) goto next_85;
    if (reg_d6.h[0] != 0) goto next_85;
    if (g_stage == 0) goto next_85;
    if (D_0028ED80 == 0) goto next_85;
    reg_a6[0x3F] = 0;
next_85:
    reg_a0 = (u8 *)D_0028C5F8;
    if (reg_a5[6] != 0) {
        reg_a0 = (u8 *)D_0028C600;
    }
    PLAYER(reg_a6)->y.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->x.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->attr.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_a6[0x55] = reg_a0[1];
    reg_a6[0x54] = reg_a0[0];
    reg_a0 += 2;
    reg_a6[0x3A] = PLAYER(reg_a6)->attr.b.palette;
    reg_a6[0x57] = reg_a6[0x55];
    PLAYER(reg_a6)->y.h = *(u16 *)(reg_a5 + 8);
    PLAYER(reg_a6)->x.h = *(u16 *)(reg_a5 + 0xA);
    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_a0 = (u8 *)D_002555C0;
    reg_d0.h[0] <<= 2;
    reg_a0 += reg_d0.h[0];
    PLAYER(reg_a6)->sprite_hi.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->sprite_lo.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->hit_y_plus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    PLAYER(reg_a6)->hit_y_minus.h = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_d0.h[0] -= 2;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = reg_d0.h[0];
    reg_d1.h[0] <<= 1;
    reg_d2.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] += reg_d2.h[0];
    reg_d2.h[0] <<= 1;
    reg_d1.h[0] += reg_d2.h[0];
    reg_a0 = (u8 *)D_002555D0;
    reg_a0 += reg_d0.h[0];
    PLAYER(reg_a6)->move.b.speed = reg_a0[1];
    reg_a6[0x38] = reg_a0[1];
    reg_a6[0x39] = reg_a0[0];
    reg_a0 = (u8 *)D_002556E0;
    reg_a0 += reg_d1.h[0];
    PLAYER(reg_a6)->burst_reset.h = *(u16 *)reg_a0;
    PLAYER(reg_a6)->option_burst_reset.h = *(u16 *)(reg_a0 + 2);
    reg_a0 += 4;
    func_00141B50();
}

void func_0013E260(void);
void func_0013E2E0(void);
extern u8 D_0028C608[];
extern u16 D_0028E060;
extern u16 D_0028E064;
extern u16 D_0028E068;
extern u16 D_0028E06C;
extern u8 D_0029F1F1[];
extern u8 D_0029F261[];
extern u16 D_006E5BF4[];
extern u16 D_006E5BF6[];
extern u16 D_006E5C0E[];
extern u16 D_006E5C10[];

void func_00141300(void) {
    void func_0013E8E0(void);
    void func_0013E970(void);
    u8 *sa0;
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    u32 sd0;
    u32 v1;
    u32 v2;
    u32 sd1;
    u32 sd2;
    u32 sd3;
    u32 sd4;
    u32 sd5;
    u32 sd6;
    u32 sd7;
    u8 *sa6;

    if (reg_d6.h[0] == 0 || D_0028E2C4 != 0) {
        sd0 = reg_d0.w;
        sd1 = reg_d1.w;
        sd2 = reg_d2.w;
        sd3 = reg_d3.w;
        sd4 = reg_d4.w;
        sd5 = reg_d5.w;
        sd6 = reg_d6.w;
        sd7 = reg_d7.w;
        sa0 = reg_a0;
        sa1 = reg_a1;
        sa2 = reg_a2;
        sa3 = reg_a3;
        sa4 = reg_a4;
        sa5 = reg_a5;
        sa6 = reg_a6;
        reg_d5.h[0] = *(u16 *)(sa6 + 0x5A);
        reg_a0 = (u8 *)D_0028C608;
        reg_d5.h[0] -= 2;
        reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + (!(reg_d5.h[0] & 1) ? 1 : -1));
        reg_d5.b[0] *= 2;
        if (D_006E5BF4[0] == 6) {
            *(u8 *)(sa6 + 0x24) = (s32)reg_d5.b[0] / 2;
        } else if ((s32)reg_d5.b[0] < (s32)(D_006E5BF4[0] + 1)) {
            *(u8 *)(sa6 + 0x24) = reg_d5.b[0];
        } else {
            *(u8 *)(sa6 + 0x24) = D_006E5BF4[0] + 1;
        }
        if (D_006E5BF6[0] == 8) {
            PLAYER(reg_a6)->bombs.b.count = PLAYER(reg_a6)->bombs.b.capacity;
        } else if (D_006E5BF6[0] == 7) {
            PLAYER(reg_a6)->bombs.b.count = PLAYER(reg_a6)->bombs.b.capacity;
            if (reg_a6 == g_player1_as_u8_a) {
                D_0029F261[0] &= 0xBF;
                g_player1_as_u8_a[0] |= 2;
                D_0029CD9C_as_s16_a[0] = D_006E5C10[0] + 1;
                D_0029CD90_as_s16_a[0] = (D_006E5C10[0] + 1) * 0x16;
                func_0013E260();
                v1 = D_006E5C0E[0];
                D_0028E074_as_s16 = v1 * 4;
                func_0013E8E0();
                D_0028E068 = 2 - v1;
                D_0028E06C = D_0028E068;
            } else {
                D_0029F1F1[0] &= 0xBF;
                g_player2_as_u8_a[0] |= 2;
                D_0029CD8C_as_s16_a[0] = D_006E5C10[0] + 1;
                D_0029CD80_as_s16_a[0] = (D_006E5C10[0] + 1) * 0x16;
                func_0013E2E0();
                v2 = D_006E5C0E[0];
                D_0028E070_as_s16 = v2 * 4;
                func_0013E970();
                D_0028E060 = 2 - v2;
                D_0028E064 = D_0028E060;
            }
        } else if ((s32)PLAYER(reg_a6)->bombs.b.capacity < (s32)D_006E5BF6[0]) {
            PLAYER(reg_a6)->bombs.b.count = PLAYER(reg_a6)->bombs.b.capacity;
        } else {
            PLAYER(reg_a6)->bombs.b.count = D_006E5BF6[0];
        }
        reg_a6 = sa6;
        reg_d1.w = sd1;
        reg_d2.w = sd2;
        reg_d3.w = sd3;
        reg_d4.w = sd4;
        reg_a0 = sa0;
        reg_d5.w = sd5;
        reg_d6.w = sd6;
        reg_d7.w = sd7;
        reg_a1 = sa1;
        reg_a2 = sa2;
        reg_a3 = sa3;
        reg_a4 = sa4;
        reg_a5 = sa5;
        reg_d0.w = sd0;
    }
}

#pragma push
#pragma opt_propagation off
extern s16 g_p2_hyper_items_pending_as_s16;
extern s16 g_p1_hyper_items_pending_as_s16;
extern s16 g_p2_hyper_gauge_as_s16;
extern s16 g_p1_hyper_gauge_as_s16;
extern s16 g_p2_hyper_total_as_s16;
extern s16 g_p1_hyper_total_as_s16;

void func_00141640(void) {
    u8 *a0;
    u8 *a1;
    u8 *a2;
    u8 *a3;
    u8 *a4;
    u8 *a5;
    u8 *a6;
    u32 d0;
    u32 d1;
    u32 d2;
    u32 d3;
    u32 d4;
    u32 d5;
    u32 d6;
    u32 d7;

    D_0028E054_as_s16 = 0x101;
    D_0028E050_as_s16 = 0x101;
    d0 = reg_d0.w;
    d1 = reg_d1.w;
    d2 = reg_d2.w;
    d3 = reg_d3.w;
    d4 = reg_d4.w;
    d5 = reg_d5.w;
    d6 = reg_d6.w;
    d7 = reg_d7.w;
    a0 = reg_a0;
    a1 = reg_a1;
    a2 = reg_a2;
    a3 = reg_a3;
    a4 = reg_a4;
    a5 = reg_a5;
    a6 = reg_a6;
    reg_d0.w = 0xC30;
    D_0028E05C_as_u16 = reg_d0.h[1];
    D_0028E05E = reg_d0.h[0];
    g_p1_hyper_items_pending_as_s16 = 0;
    g_p1_hyper_gauge_as_s16 = 0;
    g_p2_hyper_items_pending_as_s16 = 0;
    g_p2_hyper_gauge_as_s16 = 0;
    g_p1_hyper_total_as_s16 = 0;
    g_p2_hyper_total_as_s16 = 0;
    reg_d0.w = 0xC30;
    D_0028E058_as_u16 = reg_d0.h[1];
    D_0028E05A = reg_d0.h[0];
    reg_d0.w = d0;
    reg_d1.w = d1;
    reg_d2.w = d2;
    reg_d3.w = d3;
    reg_d4.w = d4;
    reg_d5.w = d5;
    reg_d6.w = d6;
    reg_d7.w = d7;
    reg_a0 = a0;
    reg_a1 = a1;
    reg_a2 = a2;
    reg_a3 = a3;
    reg_a4 = a4;
    reg_a5 = a5;
    reg_a6 = a6;
}
#pragma pop

void func_00141710(void) {
    u8 *sa0;
    u8 *sa1;
    u8 *sa2;
    u8 *sa3;
    u8 *sa4;
    u8 *sa5;
    s32 sd0;
    s32 sd1;
    s32 sd2;
    s32 sd3;
    s32 sd4;
    s32 sd5;
    s32 sd6;
    s32 sd7;
    u8 *sa6;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    sd3 = reg_d3.w;
    sd4 = reg_d4.w;
    sd5 = reg_d5.w;
    sd6 = reg_d6.w;
    sd7 = reg_d7.w;
    sa0 = reg_a0;
    sa1 = reg_a1;
    sa2 = reg_a2;
    sa3 = reg_a3;
    sa4 = reg_a4;
    sa5 = reg_a5;
    sa6 = reg_a6;
    reg_d1.w = 0;
    reg_d1.h[0] = 8;
    *(u16 *) (reg_a6 + 0x20) = reg_d1.h[0];
    *(u16 *) (reg_a6 + 0x22) = reg_d1.h[0];
    reg_a0 = sa0;
    reg_a1 = sa1;
    reg_a2 = sa2;
    reg_a3 = sa3;
    reg_a4 = sa4;
    reg_a5 = sa5;
    reg_a6 = sa6;
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_d3.w = sd3;
    reg_d4.w = sd4;
    reg_d5.w = sd5;
    reg_d6.w = sd6;
    reg_d7.w = sd7;
}

s32 func_001A7E90();
s32 func_001A8070();
extern s16 g_p2_hyper_items_as_s16;
extern s16 g_p1_hyper_items_as_s16;
#ifdef DEATH_LABEL
extern u8 death_D_00290DC0;
extern u16 D_0028DFFC;
extern u16 D_0028E7F0;
#endif

void func_001417D0(void) {
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
    s32 lo;
    s32 step;
    s32 i;

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
    if (save_a6 == g_player1_as_u8_a) {
        D_0028E06C_as_s16 = 2;
        D_0028E068_as_s16 = 2;
        reg_d0.w = 0xC30;
        D_0028E054_as_s16 = 0x101;
        D_0028E074_as_s16 = 0;
        D_0028E05C_as_u16 = reg_d0.h[1];
        D_0028E05E = reg_d0.h[0];
        func_001A7E90();
        func_0013FCA0();
    } else {
        D_0028E064_as_s16 = 2;
        D_0028E060_as_s16 = 2;
        reg_d0.w = 0xC30;
        D_0028E050_as_s16 = 0x101;
        D_0028E070_as_s16 = 0;
        D_0028E058_as_u16 = reg_d0.h[1];
        D_0028E05A = reg_d0.h[0];
        func_001A8070();
        func_0013FCE0();
    }
    reg_d1.w = 0;
    reg_d1.h[0] = 8;
    PLAYER(reg_a6)->shot_power.h = (u16) reg_d1.h[0];
    PLAYER(reg_a6)->laser_power.h = (u16) reg_d1.h[0];
    g_p1_hyper_items_as_s16 = 0;
    g_p2_hyper_items_as_s16 = 0;
    for (i = 0; i < (s32) D_006E5BFC[0]; i++) {
        if (reg_a6 == g_player1_as_u8_a) {
            func_0013E6C0();
        } else {
            func_0013E710();
        }
    }
#ifdef DEATH_LABEL
    if (reg_a6 == g_player1_as_u8_a) {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        if (death_D_00290DC0 == 0) {
            g_p1_hyper_items_pending_as_s16 = 4;
            g_p1_hyper_gauge_as_s16 = 0x95F;
        } else {
            g_p1_hyper_items_pending_as_s16 = 0;
            g_p1_hyper_gauge_as_s16 = 0;
        }
        g_p1_hyper_total_as_s16 = 0xF;
    } else {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        if (death_D_00290DC0 == 0) {
            g_p2_hyper_items_pending_as_s16 = 4;
            g_p2_hyper_gauge_as_s16 = 0x95F;
        } else {
            g_p2_hyper_items_pending_as_s16 = 0;
            g_p2_hyper_gauge_as_s16 = 0;
        }
    }
    g_p2_hyper_total_as_s16 = 0xF;
    D_0028DFFC = 0xA;
    D_0028E7F0 = 2;
#else
    if (reg_a6 == g_player1_as_u8_a) {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        g_p1_hyper_items_pending_as_s16 = 4;
        g_p1_hyper_gauge_as_s16 = 0x95F;
        g_p1_hyper_total_as_s16 = 0xF;
    } else {
        PLAYER(reg_a6)->flags.b[0] &= 0xFE;
        g_p2_hyper_items_pending_as_s16 = 4;
        g_p2_hyper_gauge_as_s16 = 0x95F;
        g_p2_hyper_total_as_s16 = 0xF;
    }
#endif
    reg_d5.h[0] = PLAYER(reg_a6)->power_style.h;
    reg_a0 = (u8 *)D_0028C608;
    reg_d5.h[0] -= 2;
    lo = reg_d5.h[0] & 1;
    step = (lo != 0) ? -1 : 1;
    reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + step);
    reg_d5.b[0] *= 2;
    PLAYER(reg_a6)->bombs.b.capacity = (u8) reg_d5.b[0];
#ifdef DEATH_LABEL
    if (death_D_00290DC0 == 0) {
        PLAYER(reg_a6)->bombs.b.count = (u8) PLAYER(reg_a6)->bombs.b.capacity;
    } else {
        PLAYER(reg_a6)->bombs.b.count = 0;
        PLAYER(reg_a6)->bombs.b.count = (u8) PLAYER(reg_a6)->bombs.b.capacity;
    }
#else
    PLAYER(reg_a6)->bombs.b.count = (u8) PLAYER(reg_a6)->bombs.b.capacity;
#endif
    if (reg_a6 == g_player1_as_u8_a) {
        D_0029CD90_as_s16_a[0] = 0;
        D_0029CD9C_as_s16_a[0] = 0;
        D_0029F261[0] |= 0x40;
        g_player1_as_u8_a[0] &= 0xFD;
    } else {
        D_0029CD80_as_s16_a[0] = 0;
        D_0029CD8C_as_s16_a[0] = 0;
        D_0029F1F1[0] |= 0x40;
        g_player2_as_u8_a[0] &= 0xFD;
    }
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
    func_001340B0();
    reg_a0 = save_a0;
    reg_a1 = save_a1;
    reg_a2 = save_a2;
    reg_a3 = save_a3;
    reg_a4 = save_a4;
    reg_a5 = save_a5;
    reg_a6 = save_a6;
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

s32 func_0019D360();
extern u8 D_0028C610[];
extern u16 D_0028C618[];
extern u16 D_0028C620[];
extern u8 D_0028E370;
extern u16 D_0028E3B4;
extern u16 D_0028E3EC;
extern u8 D_0028E718_as_u8;
extern u8 D_0028E71C_as_u8;
extern u8 D_0028E855;
extern u16 g_true_last_boss;
extern u8 D_0028EC4C;

void func_00141B50(void) {
    u8 *p0;
    s32 *p1;
    u16 idx;

    reg_a0 = (u8 *)D_0028C610;
    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
    PLAYER(reg_a6)->sprite_hi.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->sprite_lo.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0028C618;
    reg_d1.w = 0;
    reg_d1.h[0] *= 4;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    PLAYER(reg_a6)->hit_x_plus.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->hit_x_minus.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((D_0028DFC0 == 0) && (D_0028E3EC == 0) && (g_loop == 0) && (g_stage != 2)) {
        reg_d1.h[1] = PLAYER(reg_a6)->y.h;
        reg_d1.h[0] = PLAYER(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FE00;
        reg_a0 = (u8 *)D_0028C620;
        reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
        reg_d0.h[0] *= 2;
        idx = reg_d0.h[0];
        reg_tmp.h[1] = (idx != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)idx & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((idx & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((idx & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        func_0019D360();
    }
    if ((D_0028E370 != 0) && (D_0028EC4C == 0) && (D_0028E3B4 == 0) && !(D_0028E855 & 1) && (g_true_last_boss == 0) && !(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
        if (*(u8 *)(reg_a5 + 6) == 0) {
            if (D_0028E06C == 0) {
                p0 = &D_0028E71C_as_u8;
                p1 = (s32 *)(p0 - 0x34);
                *p1 = D_0029CD94[0];
                func_00140280((void *)p0, (void *)p1);
                if (g_loop != 0) {
                    func_00140280((void *)p0, (void *)p1);
                }
                return;
            }
        } else if (D_0028E064 == 0) {
            p0 = &D_0028E718_as_u8;
            p1 = (s32 *)(p0 - 0x30);
            *p1 = D_0029CD84[0];
            func_00140280((void *)p0, (void *)p1);
            if (g_loop != 0) {
                func_00140280((void *)p0, (void *)p1);
            }
        }
    }
    return;
}

typedef void (*Fn)();

extern u8 D_00255510[];
extern u8 D_00255710[];
extern u8 D_00255950[];
extern u8 D_00255970[];
extern u8 D_00255990[];
extern u8 D_0028C618_as_u8_a[];
extern u8 D_0028C620_as_u8_a[];
extern u8 D_0028C948[4];
extern u8 D_0028C94C[4];
extern u8 g_p2_hyper_effect_flag_as_u8_a4[4];
extern u8 g_p1_hyper_effect_flag_as_u8_a4[4];
extern u8 g_p2_hyper_items_as_u8_a4[4];
extern u8 g_p1_hyper_items_as_u8_a4[4];
extern u8 D_0029EA50[];
s32 func_001340C0();
s32 func_001340D0();
s32 func_00138A20();
s32 func_0013C980();
s32 func_0013C9A0();
s32 func_0013CA90();
s32 func_0013CAB0();
s32 func_0013EBD0();
s32 func_0016A8B0();
s32 func_0016A8C0();
s32 func_0016A8D0();
s32 func_0016A8E0();
s32 func_0018D6F0();
s32 func_0018D710();
s32 func_0018D730();
s32 func_0018DC20();
s32 func_001ABB80();
s32 func_001ABD80();
s32 func_00200EE0();
s32 func_002014D0();
s32 func_002015B0();
s32 func_00201690();
s32 entity_velocity();
extern u8 D_00255700[];
extern u16 D_00255750[];
extern u16 D_00255760[];
extern u8 D_0028E000_as_u8;
extern u8 D_0028E004_as_u8;
extern u16 D_0028E018;
extern u16 D_0028E01C;
extern u16 D_0028E078_as_u16_a[];
extern u16 D_0028E07A[];
extern u16 D_0028E080_as_u16_a[];
extern u16 D_0028E082[];
extern u8 D_0028E380;
extern s16 D_0028E3A0;
extern s16 D_0028E3B0;
extern u8 g_p2_hyper_in_effect_as_u8;
extern u8 g_p1_hyper_in_effect_as_u8;
extern u16 g_p2_combo_timer;
extern u16 g_p1_combo_timer;
extern u16 D_0028E6E0;
extern u16 D_0028E6E4;
extern u16 g_scroll_line;
extern u16 g_two_player_game;
extern u16 D_00299764[];
extern u16 D_00299766[];
extern u16 D_0029C06C[];
extern void (*jtbl_0028E3F4)();

void func_001420E0(void) {
    u32 tmp_dec;
    u8 *p0;
    s32 *p1;
    u8 *temp_a0_10;
    u8 *temp_a2_5;
    u8 *temp_a3;
    u8 *temp_a3_3;
    u8 *temp_s0;
    s16 temp_a0_11;
    s16 temp_a0_14;
    s16 temp_a0_16;
    u32 temp_a0_4;
    u32 temp_a0_5;
    u32 temp_a0_9;
    u32 temp_a1_9;
    u32 temp_v0_2;
    u32 temp_v1_2;
    u16 var_a3;
    u16 var_v1;
    u8 temp_a0;
    u8 temp_a0_3;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_v0;
    u8 temp_v1;
    u8 *temp_a0_8;
    u8 *temp_a1;
    u8 *temp_a1_3;
    u8 *temp_a1_8;
    u8 *temp_a2_2;
    u8 *var_a0;

    PLAYER(reg_a6)->who.b.side = (u8) *(u8 *)(reg_a5 + 6);
    temp_a0 = PLAYER(reg_a6)->flags.b[1];
    temp_a1 = (u8 *)(reg_a6 + 1);
    if (temp_a0 & 1) {
        func_00144400();
        return;
    }
    if (D_0028DFBC != 0) goto L_else;
    {
        reg_tmp.b[0] = temp_a0;
        PLAYER(reg_a6)->flags.b[1] &= 0xDF;
        if (reg_tmp.b[0] & 0x20) {
            if (D_0028E290 == 2) {
                func_001417D0();
            }
            PLAYER(reg_a6)->flags.b[0] &= 0xFB;
            PLAYER(reg_a6)->move.b.speed = (u8) PLAYER(reg_a6)->speed.b.normal;
        }
        var_a0 = (u8 *)(reg_a6);
        switch ((*(u8 *)((u8 *)(var_a0) + (0x3F)))) { case 0: break; default:
            (*(u8 *)((u8 *)(var_a0) + (1))) &= 0xEF;
            var_a0 = (u8 *)(reg_a6 + 0x3F);
            temp_v1 = PLAYER(reg_a6)->state.b.invincible;
            if ((temp_v1 != 0xFF) && (D_0028E370 != 0)) {
                PLAYER(reg_a6)->state.b.invincible = (u8) (temp_v1 - 1);
            }
            goto block_13;
        }
        (*(u8 *)((u8 *)(var_a0) + (0x1C))) = (u8) (*(u8 *)((u8 *)(var_a0) + (0x3A)));
        reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[1];
        PLAYER(reg_a6)->flags.b[1] &= 0xEF;
        if (reg_tmp.b[0] & 0x10) {
            func_001440D0();
            return;
        }
block_13:
        PLAYER(reg_a6)->flags.h &= 0xFFDF;
        temp_v0 = PLAYER(reg_a6)->aux.b.shot_sound_wait;
        if (temp_v0 != 0) {
            PLAYER(reg_a6)->aux.b.shot_sound_wait = (u8) (temp_v0 - 1);
        }
        if (*(u8 *)(reg_a5 + 6) == 0) {
            func_0016A8B0();
            PLAYER(reg_a6)->input.b.raw = (u8) reg_d0.b[0];
            func_0016A8D0();
            PLAYER(reg_a6)->input.b.filtered = reg_d0.b[0];
        } else {
            func_0016A8C0();
            PLAYER(reg_a6)->input.b.raw = (u8) reg_d0.b[0];
            func_0016A8E0();
            PLAYER(reg_a6)->input.b.filtered = reg_d0.b[0];
        }
        reg_d0.w = 0;
        PLAYER(reg_a6)->moved_y.h = 0U;
        PLAYER(reg_a6)->moved_x.h = 0U;
        if (D_0028DFC4 != 0) {
            PLAYER(reg_a6)->input.b.raw &= 0xF;
            PLAYER(reg_a6)->input.b.filtered &= 0xF;
            PLAYER(reg_a6)->state.b.invincible = 0xFFU;
        }
        reg_d0.w = 0xF;
        reg_d0.b[0] &= PLAYER(reg_a6)->input.b.raw;
        reg_a2 = (u8 *)D_00255700;
        PLAYER(reg_a6)->move.b.dir = (u8) *(reg_a2 + reg_d0.h[0] + ((reg_d0.h[0] & 1) ? -1 : 1));
        if ((s8) PLAYER(reg_a6)->move.b.dir < 0) {
            func_00144CB0();
            reg_d2.h[0] = PLAYER(reg_a6)->y.h;
            reg_d3.h[0] = PLAYER(reg_a6)->x.h;
        } else {
            entity_velocity();
            PLAYER(reg_a6)->moved_y.h = (u16) reg_d2.h[0];
            PLAYER(reg_a6)->moved_x.h = (u16) reg_d3.h[0];
            PLAYER(reg_a6)->scroll_offset.h = (u16) reg_d3.h[0];
            reg_d2.h[0] = PLAYER(reg_a6)->y.h;
            reg_d3.h[0] = PLAYER(reg_a6)->x.h;
            temp_a0_3 = PLAYER(reg_a6)->input.b.raw;
            if (temp_a0_3 & 4) {
                PLAYER(reg_a6)->flags.h |= 0x20;
                if (PLAYER(reg_a6)->roll_frame.sh != -0x20) {
                    reg_tmp.h[0] = PLAYER(reg_a6)->roll_delay.h;
                    PLAYER(reg_a6)->roll_delay.h -= 1;
                    if ((s32) reg_tmp.h[0] <= 0) {
                        PLAYER(reg_a6)->roll_delay.h = 2U;
                        PLAYER(reg_a6)->roll_frame.h += 0x7FFF + 0x7FFD;
                    }
                }
                if ((s32) reg_d3.h[0] < 0x301) {
                    reg_d3.h[0] -= 0x300;
                    temp_a0_4 = PLAYER(reg_a6)->moved_x.h;
                    PLAYER(reg_a6)->moved_x.h = (u16) (temp_a0_4 - reg_d3.h[0]);
                    reg_d3.h[0] = 0x300;
                    func_00138A20();
                }
            } else if (temp_a0_3 & 8) {
                PLAYER(reg_a6)->flags.h |= 0x20;
                if (PLAYER(reg_a6)->roll_frame.h != 0x20) {
                    reg_tmp.h[0] = PLAYER(reg_a6)->roll_delay.h;
                    PLAYER(reg_a6)->roll_delay.h -= 1;
                    if ((s32) reg_tmp.h[0] <= 0) {
                        PLAYER(reg_a6)->roll_delay.h = 2U;
                        PLAYER(reg_a6)->roll_frame.h += 4;
                    }
                }
                if ((s32) reg_d3.h[0] >= 0x3500) {
                    reg_d3.h[0] -= 0x3500;
                    temp_a0_5 = PLAYER(reg_a6)->moved_x.h;
                    PLAYER(reg_a6)->moved_x.h = (u16) (temp_a0_5 - reg_d3.h[0]);
                    reg_d3.h[0] = 0x3500;
                    func_00138A20();
                }
            } else {
                func_00144CB0();
            }
            temp_a0_6 = PLAYER(reg_a6)->input.b.raw;
            if (temp_a0_6 & 1) {
                if ((s32) reg_d2.h[0] > 0x6500) {
                    reg_d2.h[0] -= 0x6500;
                    PLAYER(reg_a6)->moved_y.h -= reg_d2.h[0];
                    reg_d2.h[0] = 0x6500;
                }
            } else if ((temp_a0_6 & 2) && ((s32) reg_d2.h[0] < 0x800)) {
                reg_d2.h[0] -= 0x800;
                var_v1 = 0x800;
                PLAYER(reg_a6)->moved_y.h -= reg_d2.h[0];
                reg_d2.h[0] = var_v1;
            }
        }
        if ((s8) PLAYER(reg_a6)->flags.b[0] < 0) {
            temp_v1_2 = PLAYER(reg_a6)->laser_bomb_recoil.h;
            if (temp_v1_2 != 0) {
                reg_d0.h[0] = temp_v1_2;
                reg_a0 = (u8 *)D_00255710;
                reg_d0.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                PLAYER(reg_a6)->offset_y.h -= reg_d0.h[0];
                PLAYER(reg_a6)->laser_recoil.h = (u16) reg_d0.h[0];
                PLAYER(reg_a6)->laser_bomb_recoil.h -= 2;
            }
            if (D_0028DFF4 != 0) {
                PLAYER(reg_a6)->moved_y.h -= 0x48;
                reg_d2.h[0] -= 0x48;
            }
            if ((s32) reg_d2.h[0] < 0x800) {
                reg_d0.h[0] = 0x800;
                reg_d0.h[0] -= reg_d2.h[0];
                PLAYER(reg_a6)->moved_y.h += reg_d0.h[0];
                reg_d2.h[0] = 0x800;
            }
        }
        PLAYER(reg_a6)->y.h = (u16) reg_d2.h[0];
        PLAYER(reg_a6)->x.h = (u16) reg_d3.h[0];
        if ((g_two_player_game == 0) && !(PLAYER(reg_a6)->flags.b[0] & 0x20)) {
            reg_d3.h[0] = PLAYER(reg_a6)->x.h;
            reg_d0.h[0] = D_0029C06C[0];
            reg_d3.h[0] -= reg_d0.h[0];
            PLAYER(reg_a6)->x.h = (u16) reg_d3.h[0];
        }
        if ((D_0028E380 != 0) && (PLAYER(reg_a6)->input.b.raw & 0x40) && (PLAYER(reg_a6)->fire_lockout.b[1] == 0)) {
            reg_a0 = (u8 *)D_0029F180;
            if (*(u8 *)(reg_a5 + 6) != 0) {
                reg_a0 = (u8 *)D_0029F110;
            }
            PLAYER(reg_a6)->input.b.filtered &= 0xEF;
            PLAYER(reg_a6)->flags.b[0] &= 0xF7;
            *reg_a0 &= 0xF7;
            temp_a0_7 = PLAYER(reg_a6)->flags.b[0];
            if (temp_a0_7 & 0x10) {
                PLAYER(reg_a6)->flags.b[0] = (u8) (temp_a0_7 & 0xEF);
            } else {
                PLAYER(reg_a6)->flags.b[0] = (u8) (temp_a0_7 | 0x10);
                PLAYER(reg_a6)->flags.b[0] |= 8;
                *reg_a0 |= 8;
                PLAYER(reg_a6)->input.b.filtered |= 0x10;
            }
        }
        if (((s32) g_scroll_line >= 4) && (PLAYER(reg_a6)->input.b.raw & 0x20)) {
            temp_a2_2 = (u8 *)(reg_a5 + 6);
            if (*(u8 *)(reg_a5 + 6) == 0) {
                reg_a0 = (u8 *)func_0013C980;
                reg_a1 = (u8 *)g_p1_hyper_items_as_u8_a4;
                reg_a2 = &g_p1_hyper_in_effect_as_u8;
                reg_a3 = (u8 *)(D_00255750);
                reg_d6.h[0] = g_p1_hyper_total;
                reg_d7.h[0] = *(u16 *)D_0029CD90_as_u8_a;
            } else {
                reg_a0 = (u8 *)func_0013CA90;
                reg_a1 = (u8 *)g_p2_hyper_items_as_u8_a4;
                reg_a2 = &g_p2_hyper_in_effect_as_u8;
                reg_a3 = (u8 *)(D_00255760);
                reg_d6.h[0] = g_p2_hyper_total;
                reg_d7.h[0] = *(u16 *)D_0029CD80_as_u8_a;
            }
            reg_d1.h[0] = *(u16 *)reg_a1;
            if (reg_d1.h[0] != 0) {
                reg_d1.h[0] -= 1;
                reg_d1.h[0] *= 2;
                reg_a1 = (u8 *)D_00255510;
                reg_d6.h[0] -= 1;
                reg_d6.h[0] *= 2;
                reg_d6.h[0] = (reg_d6.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d6.h[0] & ~1)) : *(u16 *)reg_a1;
                D_00299764[0] += 8;
                D_00299766[0] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a3;
                jtbl_0028E3F4 = (Fn)(reg_a0);
                jtbl_0028E3F4();
                *(s16 *)reg_a2 = 1;
                PLAYER(reg_a6)->flags.b[0] |= 1;
                func_0018DC20();
                reg_a0 = (u8 *)func_002014D0;
                if (*(u8 *)(reg_a5 + 6) != 0) {
                    reg_a0 = (u8 *)func_002015B0;
                }
                jtbl_0028E3F4 = (Fn)(reg_a0);
                jtbl_0028E3F4();
                PLAYER(reg_a6)->state.b.invincible = 2U;
                D_0028E3B0 = 0x14;
                if ((PLAYER(reg_a6)->flags.b[1] & 0x40) || (reg_d7.h[0] == 0)) {
                    func_0013EBD0();
                }
                goto block_122;
            }
            temp_a0_8 = (u8 *)(reg_a6 + 0x25);
            if (PLAYER(reg_a6)->bombs.b.count != 0) {
                reg_a1 = (u8 *)g_p1_hyper_effect_flag_as_u8_a4;
                if (*(u8 *)(reg_a5 + 6) != 0) {
                    reg_a1 = (u8 *)g_p2_hyper_effect_flag_as_u8_a4;
                }
                if ((*(u16 *)reg_a1 == 0) && (reg_a1 = (u8 *)D_0029CEA0_as_u8_a, ((s16) *(u16 *)reg_a1 >= 0))) {
                    D_0028E3A0 = 1;
                    PLAYER(reg_a6)->bombs.b.count -= 1;
                    if (PLAYER(reg_a6)->bombs.b.count == 0) {
                        if (*(u8 *)(reg_a5 + 6) == 0) {
                            func_001ABB80();
                        } else {
                            func_001ABD80();
                        }
                    }
                    if (*(u8 *)(reg_a5 + 6) == 0) {
                        D_0028E014_as_s16 = 1;
                        if ((s32) D_0028E01C < 0x63) {
                            D_0028E01C += 1;
                        }
                        reg_a2 = (u8 *)g_player2_as_u8_a;
                        reg_a3 = (u8 *)(&D_0028E6E4);
                        reg_a4 = (u8 *)D_0029CD90_as_u8_a;
                        reg_d0.h[0] = g_p1_combo_timer;
                        if (g_p1_hyper_active != 0) {
                            func_001A7E90();
                            reg_tmp.h[0] = g_p1_hyper_total;
                            g_p1_hyper_total -= 3;
                            if ((s32) reg_tmp.h[0] < 3) {
                                g_p1_hyper_total = 0;
                            }
                        }
                    } else {
                        D_0028E010_as_s16 = 1;
                        if ((s32) D_0028E018 < 0x63) {
                            D_0028E018 += 1;
                        }
                        reg_a2 = (u8 *)g_player1_as_u8_a;
                        reg_a3 = (u8 *)(&D_0028E6E0);
                        reg_a4 = (u8 *)D_0029CD80_as_u8_a;
                        reg_d0.h[0] = g_p2_combo_timer;
                        if (g_p2_hyper_active != 0) {
                            func_001A8070();
                            reg_tmp.h[0] = g_p2_hyper_total;
                            g_p2_hyper_total -= 3;
                            if ((s32) reg_tmp.h[0] < 3) {
                                g_p2_hyper_total = 0;
                            }
                        }
                    }
                    if (reg_d0.h[0] != 0) {
                        *(u16 *)reg_a3 = 1;
                    }
                    if (!(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
                        temp_v0_2 = *(u16 *)reg_a4;
                        if (temp_v0_2 != 0) {
                            *(u16 *)reg_a4 = (u16) (temp_v0_2 - 0x2C);
                            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
                            *(u16 *)(reg_a4 + 0xC) -= 2;
                            if ((s32) reg_tmp.h[0] < 2) {
                                *(u16 *)reg_a4 = 0U;
                                *(u16 *)(reg_a4 + 0xC) = 0U;
                            }
                            reg_d0.h[0] = *(u16 *)reg_a4;
                            reg_d5.h[0] = reg_d0.h[0];
                            func_00200EE0();
                            *(u16 *)(reg_a4 + 4) = (u16) reg_d2.h[1];
                            *(u16 *)(reg_a4 + 6) = (u16) reg_d2.h[0];
                            reg_d5.h[0] >>= 1;
                            reg_d0.h[0] = reg_d5.h[0];
                            func_00200EE0();
                            *(u16 *)(reg_a4 + 8) = (u16) reg_d2.h[1];
                            *(u16 *)(reg_a4 + 0xA) = (u16) reg_d2.h[0];
                            reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
                            func_00200EE0();
                            *(u16 *)(reg_a4 + 0xE) = (u16) reg_d2.h[0];
                        }
                    }
                    func_0013EBD0();
                    PLAYER(reg_a6)->flags.b[1] |= 0x40;
                    PLAYER(reg_a6)->flags.b[0] |= 0x40;
                    reg_d2.w = 0;
                    reg_d2.b[0] = *(u8 *)(reg_a5 + 6);
                    reg_d2.h[0] <<= 7;
                    reg_d2.h[0] |= 0x8000;
                    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
                    reg_d2.b[0] |= reg_d0.b[0];
                    *(u16 *)reg_a1 = (u16) reg_d2.h[0];
                    reg_d0.h[0] *= 2;
                    reg_d1.h[0] = reg_d0.h[0];
                    *(u16 *)(reg_a1 + 2) = (u16) PLAYER(reg_a6)->y.h;
                    temp_a0_9 = PLAYER(reg_a6)->x.h;
                    *(u16 *)(reg_a1 + 4) = temp_a0_9;
                    PLAYER(reg_a6)->state.b.invincible = 0xFFU;
                    if (PLAYER(reg_a6)->state.b.laser_mode == 0) {
                        func_001340C0();
                        PLAYER(reg_a6)->shield_anim_delay.h = 0U;
                        PLAYER(reg_a6)->shield_anim_frame.h = 0x3CU;
                        PLAYER(reg_a6)->move.b.speed += 6;
                        reg_a0 = (u8 *)D_0028C948;
                    } else {
                        func_001340D0();
                        PLAYER(reg_a6)->shield_anim_delay.h = 0x101U;
                        PLAYER(reg_a6)->shield_anim_frame.h = 0xCU;
                        PLAYER(reg_a6)->flags.b[0] |= 0x80;
                        temp_a0_10 = (u8 *)(reg_a1);
                        (*(u8 *)((u8 *)(temp_a0_10) + (0))) |= 1;
                        D_0028E088_as_s16 = 0;
                        PLAYER(reg_a6)->laser_bomb_recoil.h = 0x2EU;
                        temp_s0 = (u8 *)(reg_a2);
                        if (*(u8 *)(reg_a5 + 6) == 0) {
                            reg_a1 = (u8 *)D_0029F180;
                            reg_a2 = &D_0028E004_as_u8;
                            func_0013C9A0();
                        } else {
                            reg_a1 = (u8 *)D_0029F110;
                            reg_a2 = &D_0028E000_as_u8;
                            func_0013CAB0();
                        }
                        *(s16 *)(reg_a1 + 0x38) = 0x26;
                        *(s16 *)(reg_a1 + 0x56) = 8;
                        *(s16 *)reg_a2 = 1;
                        reg_a2 = temp_s0;
                        func_00201690();
                        reg_a0 = (u8 *)D_0028C94C;
                    }
                    reg_a0 += reg_d1.h[0];
                    reg_d0.h[0] = *(u16 *)reg_a0;
                    reg_a0 += 2;
                    if (((reg_d0.h[0] == 0) || !(PLAYER(reg_a6)->power_style.b[0] & 4)) && (*(u8 *)(reg_a5 + 6) != 0)) {
                        reg_d0.h[0] += 0xC;
                    }
                    if (*(s16 *)reg_a2 < 0) {
                        *(u8 *)(reg_a2 + 0x3F) = (u8) PLAYER(reg_a6)->state.b.invincible;
                        *(u16 *)(reg_a2 + 0x28) = (u16) PLAYER(reg_a6)->shield_anim_frame.h;
                        *(u16 *)(reg_a2 + 0x26) = (u16) PLAYER(reg_a6)->shield_anim_delay.h;
                    }
                } else {
                    goto block_122;
                }
            } else {
                goto block_122;
            }
        } else {
block_122:
            reg_d0.b[0] = PLAYER(reg_a6)->weapon.b.shot_palette;
            if (PLAYER(reg_a6)->flags.b[0] & 1) {
                reg_d0.b[0] = PLAYER(reg_a6)->weapon.b.hyper_palette;
            }
            PLAYER(reg_a6)->who.b.palette = (u8) reg_d0.b[0];
            if (PLAYER(reg_a6)->state.b.laser_mode == 0) {
                if (PLAYER(reg_a6)->input.b.filtered & 0x10) {
                    PLAYER(reg_a6)->fire_lockout.b[1] = 1U;
                    reg_d0.b[0] = PLAYER(reg_a6)->shot_power.b[0];
                    if (PLAYER(reg_a6)->flags.b[0] & 1) {
                        reg_d0.h[0] = 8;
                    }
                    reg_d0.h[0] >>= 1;
                    reg_d0.b[0] &= 6;
                    reg_d0.b[0] += PLAYER(reg_a6)->burst_reset.b.shots;
                    PLAYER(reg_a6)->burst.b.shots = (u8) reg_d0.b[0];
                    reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[0];
                    PLAYER(reg_a6)->flags.b[0] &= 0xF7;
                    if (reg_tmp.b[0] & 8) {
                        PLAYER(reg_a6)->flags.b[1] |= 8;
                        PLAYER(reg_a6)->burst.b.shots = 0U;
                        goto block_135;
                    }
                    reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[1];
                    PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                    if (reg_tmp.b[0] & 8) {
                        PLAYER(reg_a6)->burst.b.wait = 1U;
                    } else {
                        goto block_135;
                    }
                } else {
                    PLAYER(reg_a6)->fire_lockout.b[1] = 0U;
                    PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                    PLAYER(reg_a6)->flags.b[0] &= 0xEF;
                    if (PLAYER(reg_a6)->burst.b.shots != 0) {
                        PLAYER(reg_a6)->burst.b.wait -= 1;
                        if (PLAYER(reg_a6)->burst.b.wait == 0) {
                            PLAYER(reg_a6)->burst.b.shots -= 1;
                            PLAYER(reg_a6)->flags.b[1] |= 8;
                            PLAYER(reg_a6)->flags.b[0] |= 0x10;
block_135:
                            reg_d0.b[0] = PLAYER(reg_a6)->burst_reset.b.wait;
                            if ((PLAYER(reg_a6)->flags.b[0] & 1) || ((PLAYER(reg_a6)->ship_type.h == 0) && (PLAYER(reg_a6)->shot_power.h == 8))) {
                                reg_d0.w = 2;
                            }
                            PLAYER(reg_a6)->burst.b.wait = (u8) reg_d0.b[0];
                            reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
                            if (reg_d0.h[0] == 0) {
                                reg_a0 = (u8 *)D_0029E390;
                                reg_tmp.h[1] = D_0028E080_as_u16_a[0];
                                reg_tmp.h[0] = D_0028E082[0];
                                reg_a2 = (u8 *) reg_tmp.w;
                                if (*(u8 *)(reg_a5 + 6) != 0) {
                                    reg_a0 = (u8 *)D_0029EA50;
                                    reg_tmp.h[1] = D_0028E078_as_u16_a[0];
                                    reg_tmp.h[0] = D_0028E07A[0];
                                    reg_a2 = (u8 *) reg_tmp.w;
                                }
                                reg_d7.h[0] = *(u16 *)reg_a2;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d7.h[0] = 6;
                                }
                                reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
                                reg_d0.h[0] -= 2;
                                reg_d0.h[0] *= 4;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d0.h[0] += 4;
                                }
                                var_a3 = reg_d0.h[0];
                                reg_a1 = (u8 *)D_00255950;
                                reg_d5.h[0] = var_a3;
                                reg_tmp.h[1] = (var_a3 != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)var_a3 & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((var_a3 & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((var_a3 & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                reg_d0.h[0] = PLAYER(reg_a6)->shot_power.h;
                                reg_d0.h[0] *= 2;
                                temp_a1_3 = (u8 *)(reg_a6 + 0x20);
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                if (PLAYER(reg_a6)->power_style.h != 4) {
                                    reg_a0 += 0x2A0;
                                    reg_a4 = reg_a0 + 0x150;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 3)) {
                                        reg_d7.w = 3;
                                    }
                                    reg_d6.h[0] = reg_d7.h[0];
loop_164:
                                    if ((*(s16 *)reg_a0) < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_164;
                                        }
                                    } else {
                                        func_00144AD0();
                                    }
                                    reg_a1 = (u8 *)D_00255970;
                                    reg_tmp.h[1] = (reg_d5.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d5.h[0] & ~1)) : *(u16 *)reg_a1;
                                    reg_tmp.h[0] = (((u16)reg_d5.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d5.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                    reg_a1 = (u8 *) reg_tmp.w;
                                    reg_d0.h[0] = PLAYER(reg_a6)->shot_power.h;
                                    reg_d0.h[0] *= 2;
                                    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                    reg_a1 = (u8 *) reg_tmp.w;
loop_181:
                                    if ((*(s16 *)reg_a4) < 0) {
                                        reg_a4 += 0x30;
                                        tmp_dec = reg_d6.h[0] - 1; reg_d6.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_181;
                                        }
                                        if (PLAYER(reg_a6)->shot_power.h != 8) {
                                            PLAYER(reg_a6)->burst.b.shots = 0U;
                                            PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                        }
                                        if ((s16) reg_d7.h[0] >= 0) {
                                            goto block_196;
                                        }
                                    } else {
                                        reg_a0 = reg_a4;
                                        func_00144B70();
                                        goto block_196;
                                    }
                                } else {
                                    temp_a3 = (u8 *)(reg_a0 + 0x1B0);
                                    reg_a0 = temp_a3;
                                    reg_d7.h[0] += 2;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 4)) {
                                        reg_d7.w = 4;
                                    }
loop_191:
                                    temp_a0_11 = (*(s16 *)reg_a0);
                                    if (temp_a0_11 < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_191;
                                        }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                    } else {
                                        func_00144B80();
block_196:
                                        if (PLAYER(reg_a6)->aux.b.shot_sound_wait == 0) {
                                            PLAYER(reg_a6)->aux.b.shot_sound_wait = 2U;
                                            reg_a0 = (u8 *)func_0018D6F0;
                                            if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                                reg_a0 = (u8 *)func_0018D730;
                                            }
                                            jtbl_0028E3F4 = (Fn)(reg_a0);
                                            jtbl_0028E3F4();
                                        }
                                    }
                                }
                            } else {
                                reg_a0 = (u8 *)D_0029E390;
                                reg_tmp.h[1] = D_0028E080_as_u16_a[0];
                                reg_tmp.h[0] = D_0028E082[0];
                                reg_a2 = (u8 *) reg_tmp.w;
                                if (*(u8 *)(reg_a5 + 6) != 0) {
                                    reg_a0 = (u8 *)D_0029EA50;
                                    reg_tmp.h[1] = D_0028E078_as_u16_a[0];
                                    reg_tmp.h[0] = D_0028E07A[0];
                                    reg_a2 = (u8 *) reg_tmp.w;
                                }
                                reg_d7.h[0] = *(u16 *)reg_a2;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d7.h[0] = 6;
                                }
                                reg_d0.h[0] = PLAYER(reg_a6)->power_style.h;
                                reg_d0.h[0] -= 2;
                                reg_d0.h[0] *= 4;
                                if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                    reg_d0.h[0] += 4;
                                }
                                reg_a1 = (u8 *)D_00255990;
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                reg_d0.h[0] = PLAYER(reg_a6)->shot_power.h;
                                reg_d0.h[0] *= 2;
                                temp_a1_8 = (u8 *)(reg_a6 + 0x20);
                                reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a1;
                                reg_a1 = (u8 *) reg_tmp.w;
                                if (PLAYER(reg_a6)->power_style.h != 4) {
                                    reg_a0 += 0x2A0;
                                    reg_d7.h[0] *= 2;
                                    reg_d7.h[0] += 1;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 7)) {
                                        reg_d7.w = 7;
                                    }
loop_222:
                                    temp_a2_5 = (u8 *)(reg_a0);
                                    if ((*(s16 *)temp_a2_5) < 0) {
                                        reg_a0 = temp_a2_5 + 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_222;
                                        }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                    } else {
                                        reg_a4 = temp_a2_5;
loop_227:
                                        reg_a0 += 0x30;
                                        temp_a0_14 = (*(s16 *)reg_a0);
                                        if (temp_a0_14 < 0) {
                                            tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                            if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                                goto loop_227;
                                            }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                        } else {
                                            func_00144B20();
                                            reg_a0 = reg_a4;
                                            func_00144C10();
                                            goto block_240;
                                        }
                                    }
                                } else {
                                    temp_a3_3 = (u8 *)(reg_a0 + 0x1B0);
                                    reg_a0 = temp_a3_3;
                                    reg_d7.h[0] += 2;
                                    if ((g_two_player_game == 0) && ((s32) reg_d7.h[0] > 4)) {
                                        reg_d7.w = 4;
                                    }
loop_235:
                                    temp_a0_16 = (*(s16 *)reg_a0);
                                    if (temp_a0_16 < 0) {
                                        reg_a0 += 0x30;
                                        tmp_dec = reg_d7.h[0] - 1; reg_d7.h[0] = tmp_dec;
                                        if (((s64) ((s64) (tmp_dec & 0xFFFF) << 0x30) >> 0x30) >= 0) {
                                            goto loop_235;
                                        }
                                            if (PLAYER(reg_a6)->shot_power.h != 8) {
                                                PLAYER(reg_a6)->burst.b.shots = 0U;
                                                PLAYER(reg_a6)->flags.b[1] &= 0xF7;
                                            }
                                    } else {
                                        func_00144C20();
block_240:
                                        if (PLAYER(reg_a6)->aux.b.shot_sound_wait == 0) {
                                            PLAYER(reg_a6)->aux.b.shot_sound_wait = 2U;
                                            reg_a0 = (u8 *)func_0018D710;
                                            if (PLAYER(reg_a6)->flags.b[0] & 1) {
                                                reg_a0 = (u8 *)func_0018D730;
                                            }
                                            jtbl_0028E3F4 = (Fn)(reg_a0);
                                            jtbl_0028E3F4();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
block_244:
    reg_a0 = (u8 *)D_0028C610;
    reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
    PLAYER(reg_a6)->sprite_hi.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->sprite_lo.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *)D_0028C618_as_u8_a;
    reg_d1.w = 0;
    reg_d1.h[0] *= 4;
    reg_tmp.h[1] = (reg_d1.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d1.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((u16)reg_d1.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d1.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    PLAYER(reg_a6)->hit_x_plus.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    PLAYER(reg_a6)->hit_x_minus.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    if ((D_0028DFC0 == 0) && (D_0028E3EC == 0) && (g_loop == 0) && (g_stage != 2)) {
        reg_d1.h[1] = PLAYER(reg_a6)->y.h;
        reg_d1.h[0] = PLAYER(reg_a6)->x.h;
        reg_d5.h[0] = 0x1C00;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d5.h[0] = 0x1400;
        reg_d1.h[0] -= reg_d5.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 1);
        reg_d1.h[0] += reg_d5.h[0];
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.w += 0xFE00FE00;
        reg_a0 = (u8 *)D_0028C620_as_u8_a;
        reg_d0.h[0] = PLAYER(reg_a6)->ship_type.h;
        reg_d0.h[0] *= 2;
        temp_a1_9 = reg_d0.h[0];
        reg_tmp.h[1] = (temp_a1_9 != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)temp_a1_9 & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((temp_a1_9 & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((temp_a1_9 & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *) reg_tmp.w;
        reg_d0.h[0] = PLAYER(reg_a6)->roll_frame.h;
        reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_d2.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d3.h[0] = 0x210;
        reg_d4.h[0] = 0x18;
        func_0019D360();
    }
    if ((D_0028E370 != 0) && (D_0028EC4C == 0) && (D_0028E3B4 == 0) && !(D_0028E855 & 1) && (g_true_last_boss == 0) && !(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
        if (*(u8 *)(reg_a5 + 6) == 0) {
            if (D_0028E06C == 0) {
                p0 = &D_0028E71C_as_u8;
                p1 = (s32 *)(p0 - 0x34);
                *p1 = D_0029CD94[0];
                func_00140280((void *)p0, (void *)p1);
                if (g_loop != 0) {
                    func_00140280((void *)p0, (void *)p1);
                }
                return;
            }
        } else if (D_0028E064 == 0) {
            p0 = &D_0028E718_as_u8;
            p1 = (s32 *)(p0 - 0x30);
            *p1 = D_0029CD84[0];
            func_00140280((void *)p0, (void *)p1);
            if (g_loop != 0) {
                func_00140280((void *)p0, (void *)p1);
            }
        }
    }
    return;
L_else:
    reg_tmp.b[0] = PLAYER(reg_a6)->flags.b[0];
    PLAYER(reg_a6)->flags.b[0] |= 4;
    if (!(reg_tmp.b[0] & 4)) {
        reg_d0.w = 0;
        reg_d7.w = 0x2C;
        reg_a0 = (u8 *)D_0029CEA0_as_u8_a;
        do {
            *(u16 *)reg_a0 = reg_d0.h[0];
            reg_a0 += 0x30;
        } while ((s16)(--reg_d7.h[0]) >= 0);
        PLAYER(reg_a6)->flags.h &= 0xFF3F;
        PLAYER(reg_a6)->state.b.invincible = 1U;
        reg_d0.w = 0;
        PLAYER(reg_a6)->burst.h = reg_d0.h[0];
        PLAYER(reg_a6)->option_burst.h = (u16) reg_d0.h[0];
    }
    PLAYER(reg_a6)->flags.b[1] &= 0xEF;
    reg_d7.h[0] = 0xE00;
    if (*(u8 *)(reg_a5 + 6) != 0) {
        reg_d7.h[0] = 0x2A00;
    }
    if (D_0028DFC0 != 0) {
        reg_d2.h[0] = 0xC00;
        PLAYER(reg_a6)->y.h = (u16) reg_d2.h[0];
        PLAYER(reg_a6)->x.h = (u16) reg_d7.h[0];
    }
    goto block_244;
}

s32 func_00125E40();
s32 func_00125E60();
s32 func_00138A00();
s32 func_0016A9B0();
s32 func_0018D6D0();
s32 func_001AA8F0();
s32 func_001AAA20();
s32 func_001ABF90();
s32 func_001AC160();
s32 func_001ACB00();
s32 func_001ACB50();
s32 vibration_start_pad1();
s32 vibration_start_pad2();
extern u8 D_00255EE0[];
extern u16 D_0028E030;
extern u16 D_0028E034;
#ifdef DEATH_LABEL
extern u16 D_006E5C14[];
#else
extern s16 D_0068DEDE[];
#endif

void func_001440D0(void) {
    s32 func_0013E8E0();
    s32 func_0013E970();
    u32 tmp;
    u16 t1;
    u16 t2;
    u32 saved1;
    u32 saved2;

    func_00138A00();
    if (!(PLAYER(reg_a6)->flags.b[1] & 0x40)) {
        func_0013EBD0();
    }
    func_0018D6D0();
    D_0028E3A0 = 1;
    if (*(u8 *)(reg_a5 + 6) == 0) {
        vibration_start_pad1(0xC8, 0x28);
        func_0013C9A0();
        D_0028E044_as_s16 = 1;
        D_0028E03C_as_s16 = 1;
        D_0028E024 += 2;
        func_00125E40();
        func_001ACB00();
        func_001ABF90();
        D_0028E074_as_s16 = 0;
        D_0028E06C_as_s16 = 8;
        D_0028E068_as_s16 = 8;
        D_0028DFB8 = g_p1_hyper_active;
        func_001A7E90();
        reg_d0.h[0] = g_p1_hyper_total;
        reg_d0.h[0] >>= 2;
        t1 = reg_d0.h[0];
        reg_d0.h[0] = g_p1_hyper_items;
        g_p1_hyper_total = t1;
        if (reg_d0.h[0] != 0) {
            g_p1_hyper_items = 0;
            func_001AA8F0();
        }
        reg_d1.h[0] = g_p1_lives;
        if (reg_d1.h[0] == 0) {
            func_0013FCA0();
        }
        PLAYER(reg_a6)->shield_anim_frame.sh = 2;
        saved1 = reg_d1.w;
        func_0013E8E0();
        reg_d1.w = saved1;
        reg_a1 = (u8 *) &D_0028E034;
        reg_a3 = (u8 *) &D_0028E02C;
    } else {
        vibration_start_pad2(0xC8, 0x28);
        func_0013CAB0();
        D_0028E040_as_s16 = 1;
        D_0028E038_as_s16 = 1;
        D_0028E020 += 2;
        func_00125E60();
        func_001ACB50();
        func_001AC160();
        D_0028E070_as_s16 = 0;
        D_0028E064_as_s16 = 8;
        D_0028E060_as_s16 = 8;
        D_0028DFB4 = g_p2_hyper_active;
        func_001A8070();
        reg_d0.h[0] = g_p2_hyper_total;
        reg_d0.h[0] >>= 2;
        t2 = reg_d0.h[0];
        reg_d0.h[0] = g_p2_hyper_items;
        g_p2_hyper_total = t2;
        if (reg_d0.h[0] != 0) {
            g_p2_hyper_items = 0;
            func_001AAA20();
        }
        reg_d1.h[0] = g_p2_lives;
        if (reg_d1.h[0] == 0) {
            func_0013FCE0();
        }
        PLAYER(reg_a6)->shield_anim_frame.sh = 3;
        saved2 = reg_d1.w;
        func_0013E970();
        reg_d1.w = saved2;
        reg_a1 = (u8 *) &D_0028E030;
        reg_a3 = (u8 *) &D_0028E028;
    }
    if (D_0028ED80 != 0) goto next_1;
    reg_d0.w = 4;
    reg_d7.w = 0;
    if (reg_d1.h[0] == 0) goto loop_1;
    reg_d0.w = 0;
    reg_d7.w = 2;
    if (*(u16 *) reg_a1 != 0) goto loop_1;
    goto next_3;
next_1:
#ifdef DEATH_LABEL
    reg_d7.w = 2;
    reg_d0.w = 0;
    if (D_006E5C14[0] != 0) {
        reg_d7.w = D_006E5C14[0];
        reg_d7.w -= 2;
        if ((s32) reg_d7.w < 0) goto next_4;
        goto loop_1;
    }
#else
    reg_d0.w = 4;
    reg_d7.w = 0;
    if (reg_d1.h[0] != 0) goto next_2;
    if (D_0068DEDE[0] != 0x14) goto loop_1;
next_2:
    reg_d0.w = 0;
    reg_d7.w = 2;
#endif
next_3:
    reg_d7.h[0] = *(u16 *) reg_a3;
    *(u16 *) reg_a3 += 1;
    reg_tmp7.h[0] = reg_d7.h[0];
    reg_d7.h[0] -= 1;
    if (reg_tmp7.h[0] == 0) goto next_4;
loop_1:
    func_0016A9B0();
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_1;
next_4:
    PLAYER(reg_a6)->flags.h &= 0x2000;
    PLAYER(reg_a6)->flags.b[1] |= 1;
    reg_tmp.w = (u32) D_00255EE0;
    PLAYER(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
    PLAYER(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
    PLAYER(reg_a6)->input.sh = 6;
}

s32 func_001340A0();
s32 func_002075F0();

void func_00144400(void) {
    u8 *var_a1;
    u8 *var_a2;
    if (!(PLAYER(reg_a6)->flags.b[1] & 4)) {
        reg_tmp.h[1] = PLAYER(reg_a6)->hit_x_plus.h;
        reg_tmp.h[0] = PLAYER(reg_a6)->hit_x_minus.h;
        reg_a0 = (u8 *)(reg_tmp.w);
        reg_a0 += 4;
        var_a2 = (u8 *)(reg_a6 + 0x14);
        if (*(s16 *)reg_a0 >= 0) {
            reg_tmp.w = (u32)reg_a0;
            PLAYER(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
            PLAYER(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
            return;
        }
        PLAYER(reg_a6)->shield_anim_delay.h = 0x20U;
        PLAYER(reg_a6)->flags.b[1] |= 4;
        goto block_4;
    }
block_4:
    PLAYER(reg_a6)->shield_anim_delay.h -= 1;
    if ((s16) PLAYER(reg_a6)->shield_anim_delay.h < 0) {
        if (*(u8 *)(reg_a5 + 6) == 0) {
            reg_a4 = (u8 *)(&D_0028DFB8);
        } else {
            reg_a4 = (u8 *)(&D_0028DFB4);
        }
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        reg_d2.w = 0;
        reg_d3.w = 0;
        reg_d0.h[0] &= 0x2000;
        reg_d1.h[0] = PLAYER(reg_a6)->power_style.h;
        var_a1 = (u8 *)(reg_a6 + 0x5A);
        if (reg_d1.h[0] & 2) {
            reg_d2.h[0] = PLAYER(reg_a6)->shot_power.h;
            if (reg_d2.h[0] != 0) {
                reg_d2.h[0] -= 2;
            }
        }
        if (reg_d1.h[0] & 4) {
            reg_d3.h[0] = PLAYER(reg_a6)->laser_power.h;
            if (reg_d3.h[0] != 0) {
                reg_d3.h[0] -= 2;
            }
        }
        reg_d4.b[0] = PLAYER(reg_a6)->bombs.b.capacity;
        if (*(u16 *)reg_a4 == 0) {
            reg_d5.h[0] = PLAYER(reg_a6)->power_style.h;
            reg_a0 = (u8 *)D_0028C608;
            reg_d5.h[0] -= 2;
            reg_d5.b[0] = *(reg_a0 + reg_d5.h[0] + ((reg_d5.h[0] & 1) ? -1 : 1));
            reg_d5.b[0] *= 2;
            if ((s32) reg_d5.b[0] > (s32) reg_d4.b[0]) {
                reg_d4.h[0] += 1;
            }
        }
        reg_a0 = (u8 *)((u32) reg_a6);
        reg_d5.w = 0x30;
        reg_d6.w = 0;
        do {
            *(u16 *)reg_a0 = (s16) reg_d6.h[0];
            reg_a0 += 2;
        } while ((s16)(--reg_d5.h[0]) >= 0);
        PLAYER(reg_a6)->flags.h |= reg_d0.h[0];
        PLAYER(reg_a6)->power_style.h = (u16) reg_d1.h[0];
        PLAYER(reg_a6)->shot_power.h = (u16) reg_d2.h[0];
        PLAYER(reg_a6)->laser_power.h = (u16) reg_d3.h[0];
        PLAYER(reg_a6)->bombs.b.capacity = (u8) reg_d4.b[0];
        PLAYER(reg_a6)->flags.h &= 0x7FFF;
        reg_d0.w = 0;
        reg_d0.b[0] = *(u8 *)(reg_a5 + 6);
        func_001340A0();
        func_002075F0();
    }
}

void func_00144690(void) {
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] += *(u16 *) (reg_a6 + 2);
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] += *(u16 *) (reg_a6 + 4);
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    reg_tmp.h[1] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a2 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x42);
    *(u16 *) reg_a0 = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a2 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a2 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u8 *) (reg_a0 + -2) = *(u8 *) (reg_a6 + 0x57);
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = (u16) *(u16 *) (reg_a6 + 0x44);
    reg_a0 += 2;
    *(u16 *) reg_a0 = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_a0 += 2;
    *(u16 *) reg_a0 = (u16) *(u16 *) (reg_a6 + 0x5A);
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x20);
    if (*(u8 *) (reg_a6 + 0x5A) & 4) {
        reg_d0.h[0] += 2;
    }
    *(u16 *) reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
}


void func_00144AD0(void) {
    func_00144690();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
}

void func_00144B20(void) {
    func_00144690();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
}


void func_00144B70(void) {
    func_00144B80();
}

void func_00144B80(void) {
    func_00144690();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
    reg_tmp.h[0] = PLAYER(reg_a6)->shot_counter.h;
    PLAYER(reg_a6)->shot_counter.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->shot_counter.h = 4U;
    }
}


void func_00144C10(void) {
    func_00144C20();
}

void func_00144C20(void) {
    func_00144690();
    reg_tmp.h[0] = PLAYER(reg_a6)->gun_index.h;
    PLAYER(reg_a6)->gun_index.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->gun_index.h = 8U;
    }
    reg_tmp.h[0] = PLAYER(reg_a6)->shot_counter.h;
    PLAYER(reg_a6)->shot_counter.h -= 4;
    if ((s32) reg_tmp.h[0] < 4) {
        PLAYER(reg_a6)->shot_counter.h = 4U;
    }
}

void func_00144CB0(void) {
    u16 temp_v1;

    reg_d0.h[0] = 4;
    temp_v1 = PLAYER(reg_a6)->roll_frame.h;
    if (temp_v1 != 0) {
        if (((s64) ((s64) temp_v1 << 0x30) >> 0x30) >= 0) {
            reg_d0.h[0] = 0xFFFC;
        }
        PLAYER(reg_a6)->roll_frame.h += reg_d0.h[0];
    }
}

extern s32 D_0028ED70;
extern u16 g_player1_as_u16_a[];
extern u16 D_006C68B6_as_u16_a[];

void func_00144D00(u8 arg0) {
    u8 var_a0;

    var_a0 = arg0;
    if ((g_stage == 0) && (var_a0 = D_0028ED7C, (var_a0 == 2)) && (D_0028ED70 == 0)) {
        reg_a6 = (u8 *)D_006C68B6_as_u16_a;
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            func_00145640();
        }
    } else {
        reg_a6 = (u8 *)g_player1_as_u16_a;
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            func_00144F00();
        }
    }
}

extern u16 g_player2_as_u16_a[];
extern u16 D_006C6918_as_u16_a[];

void func_00144DA0(u8 arg0) {
    u8 var_a0;

    var_a0 = arg0;
    if ((g_stage == 0) && (var_a0 = D_0028ED7C, (var_a0 == 2)) && (D_0028ED70 == 0)) {
        reg_a6 = (u8 *)D_006C6918_as_u16_a;
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            func_00145640();
        }
    } else {
        reg_a6 = (u8 *)g_player2_as_u16_a;
        reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
        if ((s16) reg_d0.h[0] < 0) {
            func_00144F00();
        }
    }
}


void func_00144E40(void) {
    extern void func_00145A80(u16);
    reg_a6 = (u8 *)g_player1_as_u16_a;
    reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
    if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) >= 0) && (reg_d0.h[0] & 0xFFFF & 0x100)) {
        func_00145A80(reg_d0.h[0]);
    }
}

void func_00144EA0(void) {
    extern void func_00145A80(u16);
    reg_a6 = (u8 *)g_player2_as_u16_a;
    reg_d0.h[0] = PLAYER(reg_a6)->flags.h;
    if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) >= 0) && (reg_d0.h[0] & 0xFFFF & 0x100)) {
        func_00145A80(reg_d0.h[0]);
    }
}

s32 func_0013F3F0();
s32 func_0013F400();
s32 func_0019D430();
extern u16 D_00255BB0[];
extern u16 D_0028C628[];
extern u16 D_0028C62C[];
extern u16 D_0028C630[];
extern u16 D_0028C638[];
extern u16 D_0028C750[];
extern u16 D_0028C868[];
extern u16 D_0028C880[];
extern u8 D_0028E30C;

void func_00144F00(void) {
    s32 func_0019D400();
    if (D_0028DFC0 != 0) return;
    if ((s8)reg_d0.b[0] < 0) goto next_30;
    if (PLAYER(reg_a6)->state.b.invincible == 0) goto next_100;
    if (D_0028E3EC == 0) goto next_100;
    reg_d1.h[1] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] = PLAYER(reg_a6)->x.h;
    reg_d1.h[0] += 0x7FFF + 0x7B01;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] += 0x7FFF + 0x7301;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_a0 = (u8 *)(D_00255BB0);
    reg_d2.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    reg_d2.h[1] = ((reg_d2.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0xA28;
    reg_d4.w = 0;
    reg_d4.b[0] = PLAYER(reg_a6)->who.b.side;
    reg_a0 = (u8 *)(D_0028C628);
    reg_d4.h[0] *= 2;
    reg_d4.h[0] = ((reg_d4.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    PLAYER(reg_a6)->shield_anim_frame.h -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_60;
    PLAYER(reg_a6)->shield_anim_frame.h = 0x3C;
    goto next_60;
next_30:
    reg_d1.h[1] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] = PLAYER(reg_a6)->x.h;
    reg_d1.w += 0xF800FA00;
    reg_d2.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_a0 = (u8 *)(D_0028C630);
    reg_d2.h[0] *= 2;
    reg_tmp.h[1] = ((reg_d2.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d2.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d2.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d2.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    reg_d2.h[1] = ((reg_d2.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = ((reg_d2.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d2.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    reg_d3.h[0] = 0x830;
    reg_d4.w = 0;
    reg_d4.b[0] = PLAYER(reg_a6)->who.b.side;
    reg_a0 = (u8 *)(D_0028C62C);
    reg_d4.h[0] *= 2;
    reg_d4.h[0] = ((reg_d4.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d4.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.b[0] = PLAYER(reg_a6)->shield_anim_delay.b[1];
    PLAYER(reg_a6)->shield_anim_delay.b[1] -= 1;
    if ((s32)reg_tmp.b[0] > 0) goto next_60;
    PLAYER(reg_a6)->shield_anim_delay.b[1] = PLAYER(reg_a6)->shield_anim_delay.b[0];
    reg_tmp.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    PLAYER(reg_a6)->shield_anim_frame.h -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_60;
    PLAYER(reg_a6)->shield_anim_frame.h = 0xC;
next_60:
    func_0019D430();
next_100:
    if (D_0028E30C != 0) goto next_110;
    func_0019D400();
next_110:
    func_0013F400();
    if (D_0028E30C == 0) goto next_120;
    reg_a0 = reg_a6;
    func_0013F3F0();
next_120:
    if (D_0028E3EC == 0) return;
    reg_d4.h[0] = 0x1A;
    reg_d7.h[0] = PLAYER(reg_a6)->ship_type.h;
    reg_d7.h[0] *= 2;
    reg_d6.h[0] = PLAYER(reg_a6)->roll_frame.h;
    reg_a0 = (u8 *)(D_0028C638);
    reg_a1 = (u8 *)(D_0028C868);
    if (!(PLAYER(reg_a6)->input.b.raw & 2)) goto next_200;
    if (PLAYER(reg_a6)->ship_type.h == 0) goto next_200;
    reg_a0 = (u8 *)(D_0028C750);
    reg_a1 = (u8 *)(D_0028C880);
next_200:
    reg_tmp.h[1] = (((s32)reg_d7.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((s32)reg_d7.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = ((((reg_d7.h[0] & 0xFFFFU)) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((reg_d7.h[0] & 0xFFFFU)) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = ((reg_d6.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d6.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = ((((u32)(u16)reg_d6.h[0]) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(((u32)(u16)reg_d6.h[0]) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = PLAYER(reg_a6)->exhaust_frame.h;
    reg_d2.h[1] = ((reg_d0.h[0]) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0]) & ~1)) : *(u16 *)reg_a0;
    reg_d2.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = (((s32)reg_d7.h[0]) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)((s32)reg_d7.h[0]) & ~1)) : *(u16 *)reg_a1;
    reg_tmp.h[0] = ((((reg_d7.h[0] & 0xFFFFU)) + 2) != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)(((reg_d7.h[0] & 0xFFFFU)) + 2) & ~1)) : *(u16 *)reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += PLAYER(reg_a6)->y.h;
    reg_d3.h[0] = PLAYER(reg_a6)->laser_recoil.h;
    reg_d1.h[0] -= reg_d3.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += PLAYER(reg_a6)->x.h;
    reg_d3.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = PLAYER(reg_a6)->exhaust_frame.h;
    PLAYER(reg_a6)->exhaust_frame.h -= 4;
    if ((s32)reg_tmp.h[0] >= 4) goto next_210;
    PLAYER(reg_a6)->exhaust_frame.h = 4;
next_210:
    func_0019D430();
}

extern u16 D_0028C610_as_u16_a[];
extern u16 D_0028E3E4;

void func_00145640(void) {
    s32 func_0019D400();
    u16 save_a;
    u16 save_c;

    save_a = *(u16 *) (reg_a6 + 0xA);
    save_c = *(u16 *) (reg_a6 + 0xC);
    reg_a0 = (u8 *) D_0028C610_as_u16_a;
    reg_d0.h[0] = *(u16 *) (reg_a6 + 0x58);
    reg_d0.h[0] *= 2;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = 0;
    *(u16 *) (reg_a6 + 0xA) = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    *(u16 *) (reg_a6 + 0xC) = ((reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) (reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    func_0019D400();
    *(u16 *) (reg_a6 + 0xA) = save_a;
    *(u16 *) (reg_a6 + 0xC) = save_c;
    if (D_0028E3EC == 0) {
        return;
    }
    reg_d4.h[0] = 0x1A;
    reg_d7.h[0] = *(u16 *) (reg_a6 + 0x58);
    reg_d7.h[0] *= 2;
    reg_d6.h[0] = 0;
    reg_a0 = (u8 *) D_0028C638;
    reg_a1 = (u8 *) D_0028C868;
    reg_tmp.h[1] = (reg_d7.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d7.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d7.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_tmp.h[1] = (reg_d6.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d6.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[0] = (((u16) reg_d6.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d6.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[0] = (D_0028E3E4 / 2) * 4;
    reg_d2.h[1] = (reg_d0.h[0] != 0) ? *(u16 *) (reg_a0 + ((s16) reg_d0.h[0] & ~1)) : *(u16 *) reg_a0;
    reg_d2.h[0] = (((u16) reg_d0.h[0] + 2) != 0) ? *(u16 *) (reg_a0 + ((s16) ((u16) reg_d0.h[0] + 2) & ~1)) : *(u16 *) reg_a0;
    reg_tmp.h[1] = (reg_d7.h[0]) ? *(u16 *) (reg_a1 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[0] = (((u16) reg_d7.h[0] + 2) != 0) ? *(u16 *) (reg_a1 + ((s16) ((u16) reg_d7.h[0] + 2) & ~1)) : *(u16 *) reg_a1;
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *) (reg_a6 + 2);
    reg_d3.h[0] = 0;
    reg_d1.h[0] -= reg_d3.h[0];
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d1.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] += *(u16 *) (reg_a6 + 4);
    reg_d3.h[0] = *(u16 *) reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = (D_0028E3E4 / 2) * 4;
    func_0019D430();
}

void func_0019D460(void);

void func_00145A80() {
    void func_0019D400(void);
    if (PLAYER(reg_a6)->flags.b[1] & 4) return;
    if (PLAYER(reg_a6)->input.h != 0) {
        PLAYER(reg_a6)->input.h -= 1;
        func_0019D400();
    }
    reg_tmp.h[1] = PLAYER(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = PLAYER(reg_a6)->hit_x_minus.h;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
    reg_a2 = (u8 *)reg_tmp.w;
loop_1:
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    if ((s32)reg_d2.w < 0) return;
    if (reg_d2.w == 0) {
        PLAYER(reg_a6)->burst.h = *(u16 *)reg_a2;
        reg_a2 += 2;
        PLAYER(reg_a6)->burst_reset.h = *(u16 *)reg_a2;
        reg_a2 += 2;
        PLAYER(reg_a6)->gun_flash_count.h = *(u16 *)reg_a2;
        reg_a2 += 2;
        goto loop_1;
    }
    if (reg_d2.w == 1) goto block_2;
    if (reg_d2.w == 2) goto block_1;
    reg_d1.h[1] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] = PLAYER(reg_a6)->x.h;
    reg_tmp.h[1] = PLAYER(reg_a6)->burst.h;
    reg_tmp.h[0] = PLAYER(reg_a6)->burst_reset.h;
    reg_d1.w += reg_tmp.w;
    reg_d3.h[0] = PLAYER(reg_a6)->gun_flash_count.h;
    reg_d4.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
    func_0019D460();
    goto loop_1;
block_1:
    PLAYER(reg_a6)->x.h = *(u16 *)reg_a2;
    reg_a2 += 2;
    goto loop_1;
block_2:
    reg_d2.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d2.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_d1.h[0] = PLAYER(reg_a6)->y.h;
    reg_d1.h[0] += 0x7FFF + 0x7C01;
    reg_tmp1.h[0] = reg_d1.h[0];
    reg_d1.h[0] = reg_d1.h[1];
    reg_d1.h[1] = reg_tmp1.h[0];
    reg_d3.h[0] = PLAYER(reg_a6)->x.h;
    reg_tmp3.h[0] = reg_d3.h[0];
    reg_d3.h[0] -= 0x1000;
    if ((s32)reg_tmp3.h[0] >= 0x1000) {
        reg_d1.h[0] = 0;
        reg_d3.h[0] >>= 6;
        reg_d3.h[0] += 0x400;
        reg_d4.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
        func_0019D460();
    }
    reg_d4.h[0] = PLAYER(reg_a6)->x.h;
    reg_d4.h[0] += 0x1000;
    if ((s32)reg_d4.h[0] < 0x3800) {
        reg_d1.h[0] = reg_d4.h[0];
        reg_d3.h[0] = 0x3800;
        reg_d3.h[0] -= reg_d4.h[0];
        reg_d3.h[0] >>= 6;
        reg_d3.h[0] += 0x400;
        reg_d4.h[0] = PLAYER(reg_a6)->shield_anim_frame.h;
        func_0019D460();
    }
    goto loop_1;
}
