#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

void func_00135100();
void func_001358A0(void);
void func_00135ED0(void);
void func_001368C0(void);
void func_00136A30(void);
void func_00136A40(void);
void func_00136BB0(void);
void func_00137820(void);

s32 task_request_stop();                            /* extern */
extern s32 D_0028E84C;

void func_00134FB0(void) {
    func_00135100();
    reg_a0 = (u8 *)(&D_0028E84C);
    task_request_stop();
}

extern u16 g_stage_x4;
extern u16 g_stage_x2;
extern u16 g_stage;

void func_00134FE0(void) {
    u32 value;

    value = reg_d0.h[0];
    g_stage = value;
    value = value + value;
    reg_d0.h[0] = value;
    value = reg_d0.h[0];
    g_stage_x2 = value;
    value = value + value;
    reg_d0.h[0] = value;
    value = reg_d0.h[0];
    g_stage_x4 = value;
}

extern s16 D_0028E854_as_s16;
extern s16 g_enemy_signal_f_as_s16;
extern s16 g_enemy_signal_e_as_s16;
extern s16 g_enemy_signal_d_as_s16;
extern s16 g_enemy_signal_c_as_s16;
extern s16 g_enemy_signal_b_as_s16;
extern s16 g_enemy_signal_a_as_s16;
extern s16 g_enemy_signal_9_as_s16;
extern s16 g_enemy_signal_8_as_s16;
extern s16 g_enemy_signal_7_as_s16;
extern s16 g_enemy_signal_6_as_s16;
extern s16 g_enemy_signal_5_as_s16;
extern s16 g_enemy_signal_4_as_s16;
extern s16 g_enemy_signal_3_as_s16;
extern s16 g_enemy_signal_2_as_s16;
extern s16 g_enemy_signal_1_as_s16;
extern s16 g_enemy_signal_0_as_s16;
extern s16 g_stopped_and_blocked_as_s16;
extern s16 g_bullets_blocked_as_s16;
extern s16 g_enemies_stopped_as_s16;
extern s16 D_0028E8A4_as_s16;
extern s16 g_scroll_line_as_s16;

void func_00135010(void) {
    D_0028E854_as_s16 = 0;
    g_enemy_signal_f_as_s16 = 0;
    g_enemy_signal_e_as_s16 = 0;
    g_enemy_signal_d_as_s16 = 0;
    g_enemy_signal_c_as_s16 = 0;
    g_enemy_signal_b_as_s16 = 0;
    g_enemy_signal_a_as_s16 = 0;
    g_enemy_signal_9_as_s16 = 0;
    g_enemy_signal_8_as_s16 = 0;
    g_enemy_signal_7_as_s16 = 0;
    g_enemy_signal_6_as_s16 = 0;
    g_enemy_signal_5_as_s16 = 0;
    g_enemy_signal_4_as_s16 = 0;
    g_enemy_signal_3_as_s16 = 0;
    g_enemy_signal_2_as_s16 = 0;
    g_enemy_signal_1_as_s16 = 0;
    g_enemy_signal_0_as_s16 = 0;
    g_stopped_and_blocked_as_s16 = 0;
    g_bullets_blocked_as_s16 = 0;
    g_enemies_stopped_as_s16 = 0;
    D_0028E8A4_as_s16 = 0;
    g_scroll_line_as_s16 = 0;
}

s32 func_00128660();                            /* extern */
s32 func_00139EB0();                            /* extern */
s32 func_0014D260();                            /* extern */
s32 func_0016AAB0();                            /* extern */
s32 func_001B82D0();                            /* extern */
s32 task_start();                            /* extern */
s32 func_00209E60();                            /* extern */
s32 func_002114A0();                            /* extern */
extern u32 D_0028E84C_as_u32;

void func_00135070(void) {
    func_00135010();
    func_0014D260();
    func_00139EB0();
    func_001B82D0();
    func_002114A0();
    func_001368C0();
    func_00209E60();
    func_0016AAB0();
    func_00128660();
    reg_d0.h[0] = 1;
    task_start();
    reg_tmp.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E84C_as_u32 = reg_d0.w;
    *(s16 *)(reg_a0 + 6) = 0;
}

void func_00135100() {
    g_enemies_stopped_as_s16 = 1;
}

void func_00135110(void) {
    g_enemies_stopped_as_s16 = 0;
}

extern u16 g_two_player_state;
extern u16 g_two_player_game;
extern s32 D_002BF390_as_s32_a[];
extern s32 D_002BF3B4_as_s32_a[];

void func_00135120(void) {
    reg_a2 = (u8 *)D_002BF390_as_s32_a;
    g_two_player_game = 0;
    reg_a3 = (u8 *)D_002BF3B4_as_s32_a;
    reg_d0.h[1] = (*(u16 *)((u8 *)((s32 *)reg_a2) + (0x18)));
    reg_d0.h[0] = (*(u16 *)((u8 *)((s32 *)reg_a2) + (0x1A)));
    if (reg_d0.w != 0) {
        g_two_player_game += 1;
    }
    reg_d0.h[1] = (*(u16 *)((u8 *)((s32 *)reg_a3) + (0x18)));
    reg_d0.h[0] = (*(u16 *)((u8 *)((s32 *)reg_a3) + (0x1A)));
    if (reg_d0.w != 0) {
        g_two_player_game += 1;
    }
    g_two_player_game -= 1;
    g_two_player_state = g_two_player_game;
    func_00135110();
    if ((s16) g_two_player_state == -1) {
        func_00135100((s16) g_two_player_state);
    }
    if (g_two_player_game == 0) {
        g_two_player_game = 1;
        return;
    }
    g_two_player_game = 0;
}

extern u16 D_0028E850;
extern s16 g_two_player_state_as_s16;

void func_001351F0(void) {
    if ((D_0028E850 == 0) && (g_two_player_state_as_s16 == -1)) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

s32 task_start();
extern u8 D_00269D10[];
extern u8 D_00269D20[];
extern u32 D_0028E83C_as_u32;
extern u32 D_0028E840_as_u32;
extern u32 D_0028E844_as_u32;
extern u8 D_002BF390[];

void func_00135220(void) {
    u16 temp_a0;
    u16 temp_a1;
    reg_a0 = (u8 *)D_00269D10;
    reg_a6 = (u8 *)D_002BF390;
    reg_d7.w = 1;
    do {
        ENTITY(reg_a6)->sprite.h = (u16) *(u16 *)reg_a0;
        ENTITY(reg_a6)->look.h = (u16) *(u16 *)(reg_a0 + 2);
        ENTITY(reg_a6)->hit_y_plus.h = (u16) *(u16 *)(reg_a0 + 4);
        ENTITY(reg_a6)->hit_y_minus.h = (u16) *(u16 *)(reg_a0 + 6);
        ENTITY(reg_a6)->hit_x_plus.h = (u16) *(u16 *)(reg_a0 + 8);
        ENTITY(reg_a6)->hit_x_minus.h = (u16) *(u16 *)(reg_a0 + 0xA);
        ENTITY(reg_a6)->offset_x.h = (u16) *(u16 *)(reg_a0 + 0xC);
        ENTITY(reg_a6)->draw.h = (u16) *(u16 *)(reg_a0 + 0xE);
        ENTITY(reg_a6)->hp.sh = 0;
        ENTITY(reg_a6)->move.sh = 0;
        ENTITY(reg_a6)->attr.sh = 0;
        ENTITY(reg_a6)->misc.sh = 0;
        ENTITY(reg_a6)->x.sh = 0;
        ENTITY(reg_a6)->offset_y.sh = 0;
        *(s16 *)(reg_a6 + 0x20) = 0;
        *(s16 *)(reg_a6 + 0x22) = 0;
        reg_a0 = (u8 *)D_00269D20;
        reg_a6 += 0x24;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.h[0] = 0;
    task_start();
    temp_a0 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E844_as_u32 = reg_d0.w;
    reg_d0.h[0] = 4;
    task_start();
    temp_a1 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a1;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E840_as_u32 = reg_d0.w;
    *(u8 *)(reg_a0 + 6) = 0;
    reg_d0.h[0] = 4;
    task_start();
    reg_tmp.h[0] = reg_d0.h[1];
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E83C_as_u32 = reg_d0.w;
    *(u8 *)(reg_a0 + 6) = 1;
}

void func_001353E0(void) {
    reg_a0 = (u8 *)D_002BF390_as_s32_a;
    if (reg_d0.h[0] != 0) {
        reg_a0 = (u8 *)D_002BF3B4_as_s32_a;
    }
    (*(u16 *)((u8 *)((s32 *)reg_a0) + (0))) = (u16) reg_d1.h[0];
    (*(s16 *)((u8 *)((s32 *)reg_a0) + (2))) = 0;
}

typedef void (*Fn)();

extern u8 D_00269D30[];
extern u16 D_002BF390_as_u16_a[];

void func_00135420(arg0)
    u16 *arg0;
{
    u16 *var_a0;
    u32 temp_s0;

    var_a0 = (u16 *)(arg0);
    reg_a6 = (u8 *)(D_002BF390_as_u16_a);
    reg_d7.w = 1;
    do {
        reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
        if (reg_d0.h[0] != 0) {
            temp_s0 = reg_d7.w;
            ((Fn)*(u32 *)((u8 *)D_00269D30 + ((reg_d0.h[0] & 0xFFFF) * 4)))();
            reg_d7.w = temp_s0;
        }
        var_a0 = (u16 *)(reg_a6 + 0x24);
        reg_a6 = (u8 *)(var_a0);
    } while ((s16)(--reg_d7.h[0]) >= 0);
}

s32 func_0012FBD0();
s32 func_00138A00();
s32 func_001AC3A0();
s32 func_001AC5F0();
extern s16 D_0028E028_as_s16;
extern s16 D_0028E02C_as_s16;
extern s16 D_0028E030_as_s16;
extern s16 D_0028E034_as_s16;
extern s16 D_0028E038_as_s16;
extern s16 D_0028E03C_as_s16;
extern u8 g_simulation_active;
extern u16 D_006E5C06[];

void func_001354C0(void) {
    u16 var_a0;

    func_0012FBD0();
    *(u16 *)(reg_a6 + 0x18) = 0U;
    *(u16 *)(reg_a6 + 0x1A) = 0U;
    g_bullets_blocked_as_s16 = 0x78;
    func_00138A00();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xA);
    reg_a0 = (u8 *)reg_tmp.w;
    *(u16 *)reg_a0 -= 1;
    var_a0 = g_simulation_active;
    if ((var_a0 == 1) && ((s16) *(u16 *)reg_a0 < 0)) {
        var_a0 = D_006E5C06[0];
        if (var_a0 == 0x14) {
            *(u16 *)reg_a0 = 0U;
        }
    }
    if ((s16) *(u16 *)reg_a0 < 0) {
        if (*(u8 *)(reg_a6 + 0x16) == 0) {
            D_0028E03C_as_s16 = 0;
            D_0028E034_as_s16 = 1;
            D_0028E02C_as_s16 = 0;
        } else {
            D_0028E038_as_s16 = 0;
            D_0028E030_as_s16 = 1;
            D_0028E028_as_s16 = 0;
        }
        *(s16 *)reg_a6 = 2;
    } else {
        if (*(u8 *)(reg_a6 + 0x16) == 0) {
            func_001AC3A0();
        } else {
            func_001AC5F0();
        }
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
        task_start();
        *(u16 *)(reg_a6 + 0x18) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a6 + 0x1A) = (u16) reg_d0.h[0];
        *(s8 *)(reg_a0 + 7) = 0;
        *(u8 *)(reg_a0 + 6) = (u8) *(u8 *)(reg_a6 + 0x16);
        *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)(reg_a6 + 0xC);
        *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)(reg_a6 + 0xE);
        *(s16 *)reg_a6 = 0;
    }
    *(s16 *)(reg_a6 + 2) = 0;
}

s32 func_001ACBA0();
s32 func_001ACC60();
extern u16 g_attract_demo;
extern u8 D_0028E8B4;

void func_00135640(void) {
    u8 temp_a0;

    func_0012FBD0();
    func_00135120();
    if (g_attract_demo == 0) {
        if (*(u8 *)(reg_a6 + 0x16) == 0) {
            func_001ACBA0();
            if (cond_flag == 0) {
                D_0028E8B4 |= 1;
            }
        } else {
            func_001ACC60();
            if (cond_flag == 0) {
                D_0028E8B4 |= 2;
            }
        }
        reg_d0.h[0] = 0xD;
        task_start();
        *(u16 *)(reg_a6 + 0x20) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a6 + 0x22) = (u16) reg_d0.h[0];
        temp_a0 = *(u8 *)(reg_a6 + 0x16);
        *(u8 *)(reg_a0 + 6) = temp_a0;
        reg_d0.h[0] = 0xB;
        task_start();
        *(u16 *)(reg_a6 + 0x1C) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a6 + 0x1E) = (u16) reg_d0.h[0];
        *(u8 *)(reg_a0 + 6) = (u8) *(u8 *)(reg_a6 + 0x16);
    }
    *(s16 *)reg_a6 = 0;
    *(s16 *)(reg_a6 + 2) = 0;
}

extern u8 *D_0028DEB8_as_u8_p;
extern u8 *D_0028DEBC;
extern u8 *D_0028DEC0;
extern u8 *D_0028DEC4;
extern u8 *D_0028DEC8;
extern u8 *D_0028DECC;
extern u8 *D_0028DED0;
extern u32 D_0028DED4;
extern u32 D_0028DED8;
extern u32 D_0028DEDC;
extern u32 D_0028DEE0;
extern u32 D_0028DEE4;
extern u32 D_0028DEE8;
extern u32 D_0028DEEC;
extern u32 D_0028DEF0;
extern u16 D_0028E92C;
extern u16 D_0028E930;
extern u16 D_0028E934;
extern u16 D_0028E938;
extern u8 D_002BF3B4[];

void func_00135740(void) {
    D_0028DEF0 = reg_d0.w;
    D_0028DEEC = reg_d1.w;
    D_0028DEE8 = reg_d2.w;
    D_0028DEE4 = reg_d3.w;
    D_0028DEE0 = reg_d4.w;
    D_0028DEDC = reg_d5.w;
    D_0028DED8 = reg_d6.w;
    D_0028DED4 = reg_d7.w;
    D_0028DED0 = reg_a0;
    D_0028DECC = reg_a1;
    D_0028DEC8 = reg_a2;
    D_0028DEC4 = reg_a3;
    D_0028DEC0 = reg_a4;
    D_0028DEBC = reg_a5;
    D_0028DEB8_as_u8_p = (u8 *)(reg_a6);
    if (reg_d2.h[0] != 0) {
        reg_a6 = (u8 *)D_002BF3B4;
        D_0028E934 = reg_d0.h[0];
        D_0028E92C = reg_d1.h[0];
        func_001358A0();
        return;
    }
    reg_a6 = (u8 *)D_002BF390;
    D_0028E938 = reg_d0.h[0];
    D_0028E930 = reg_d1.h[0];
    func_001358A0();
}

extern s32 D_0028DEB8_as_s32;
extern s32 D_0028DEBC_as_s32;
extern s32 D_0028DEC0_as_s32;
extern s32 D_0028DEC4_as_s32;
extern s32 D_0028DEC8_as_s32;
extern s32 D_0028DECC_as_s32;
extern s32 D_0028DED0_as_s32;

void func_00135820(void) {
    D_0028DEF0 = reg_d0.w;
    D_0028DEEC = reg_d1.w;
    D_0028DEE8 = reg_d2.w;
    D_0028DEE4 = reg_d3.w;
    D_0028DEE0 = reg_d4.w;
    D_0028DEDC = reg_d5.w;
    D_0028DED8 = reg_d6.w;
    D_0028DED4 = reg_d7.w;
    D_0028DED0_as_s32 = (s32)reg_a0;
    D_0028DECC_as_s32 = (s32)reg_a1;
    D_0028DEC8_as_s32 = (s32)reg_a2;
    D_0028DEC4_as_s32 = (s32)reg_a3;
    D_0028DEC0_as_s32 = (s32)reg_a4;
    D_0028DEBC_as_s32 = (s32)reg_a5;
    D_0028DEB8_as_s32 = (s32)reg_a6;
    func_001358A0();
}

s32 func_001A33C0();
s32 func_001A35F0();
s32 func_001AA8F0();
s32 func_001AAA20();
s32 func_001AAB50();
s32 func_001AAB70();
s32 func_001AB200();
s32 func_001AB320();
s32 func_001AB440();
s32 func_001AB4A0();
s32 func_001AB520();
s32 func_001AB570();
s32 func_001AC900();
s32 func_001AC980();
extern u16 D_0024F3A8[];
extern void *D_0028DEB8;
extern u32 D_0028DED0_as_u32;
extern u8 D_0028E384;

void func_001358A0(void) {
    u16 temp_a0;

    D_0028E850 -= 1;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 8);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0xA);
    reg_d0.b[0] = D_0028E384;
    reg_a1 = (u8 *)(D_0024F3A8);
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] += reg_d0.h[0];
    temp_a0 = reg_d0.h[0];
    reg_a1 += temp_a0;
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
    task_start();
    *(u16 *)(reg_a6 + 0x18) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x1A) = (u16) reg_d0.h[0];
    *(s8 *)(reg_a0 + 7) = 0;
    *(u8 *)(reg_a0 + 6) = (u8) *(u8 *)(reg_a6 + 0x16);
    *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)(reg_a6 + 0x10);
    *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)(reg_a6 + 0x12);
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x16);
    if (reg_d0.h[0] == 0) {
        reg_d1.h[0] = D_0028E938;
        func_001A33C0();
        func_001AB520();
        func_001AB200();
        func_001AAB50();
        func_001AC900();
        func_001AB440();
        func_001AA8F0();
        func_001AC3A0();
    } else {
        reg_d1.h[0] = D_0028E934;
        func_001A33C0();
        func_001AB570();
        func_001AB320();
        func_001AAB70();
        func_001AC980();
        func_001AB4A0();
        func_001AAA20();
        func_001AC5F0();
    }
    *(s16 *)reg_a6 = 0;
    *(s16 *)(reg_a6 + 2) = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x16);
    func_001A35F0();
    func_00135120();
    func_0012FBD0();
    reg_d0.w = D_0028DEF0;
    reg_d1.w = D_0028DEEC;
    reg_d2.w = D_0028DEE8;
    reg_d3.w = D_0028DEE4;
    reg_d4.w = D_0028DEE0;
    reg_d5.w = D_0028DEDC;
    reg_d6.w = D_0028DED8;
    reg_d7.w = D_0028DED4;
    reg_a0 = (u8 *)D_0028DED0_as_u32;
    reg_a1 = (u8 *)D_0028DECC_as_s32;
    reg_a2 = (u8 *)D_0028DEC8_as_s32;
    reg_a3 = (u8 *)D_0028DEC4_as_s32;
    reg_a4 = (u8 *)D_0028DEC0_as_s32;
    reg_a5 = (u8 *)D_0028DEBC_as_s32;
    reg_a6 = (u8 *)D_0028DEB8;
}

extern u16 g_loop;

void func_00135AD0(void) {
    u16 temp_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 8);
    temp_a0 = *(u16 *)(reg_a6 + 0xA);
    reg_d0.b[0] = D_0028E384;
    reg_a1 = (u8 *)(D_0024F3A8);
    reg_tmp.h[0] = temp_a0;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] += reg_d0.h[0];
    *(u16 *)reg_a0 = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
    if (g_loop != 0) {
        *(u16 *)reg_a0 = 0U;
    }
    if (g_simulation_active == 1) {
        if (D_006E5C06[0] == 0x14) {
            *(u16 *)reg_a0 = 0U;
        } else {
            *(u16 *)reg_a0 = (u16) D_006E5C06[0];
        }
    }
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x14);
    task_start();
    *(u16 *)(reg_a6 + 0x18) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a6 + 0x1A) = (u16) reg_d0.h[0];
    *(u8 *)(reg_a0 + 7) = (u8) g_loop;
    *(u8 *)(reg_a0 + 6) = (u8) *(u8 *)(reg_a6 + 0x16);
    *(u16 *)(reg_a0 + 8) = (u16) *(u16 *)(reg_a6 + 0x10);
    *(u16 *)(reg_a0 + 0xA) = (u16) *(u16 *)(reg_a6 + 0x12);
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x16);
    if (reg_d0.h[0] == 0) {
        reg_d1.h[0] = D_0028E938;
        func_001A33C0();
        if (g_loop == 0) {
            func_001AAB50();
        }
    } else {
        reg_d1.h[0] = D_0028E934;
        func_001A33C0();
        if (g_loop == 0) {
            func_001AAB70();
        }
    }
    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x16);
    func_001A35F0();
    *(s16 *)reg_a6 = 0;
    *(s16 *)(reg_a6 + 2) = 0;
    func_00135120();
}

s32 sound_stop_effects();
s32 music_stop();
s32 task_request_stop();
extern u8 D_0028E83C_as_u8;
extern u8 D_0028E840_as_u8;
extern u8 D_0028E844_as_u8;
extern u8 D_0028E848_as_u8;
extern u8 D_0028E84C_as_u8;

void func_00135C90(void) {
    reg_a2 = D_002BF390;
    reg_a3 = D_002BF3B4;
    reg_a0 = reg_a2 + 0x1C;
    task_request_stop();
    reg_a0 = reg_a3 + 0x1C;
    task_request_stop();
    reg_a0 = reg_a2 + 0x20;
    task_request_stop();
    reg_a0 = reg_a3 + 0x20;
    task_request_stop();
    reg_a0 = &D_0028E848_as_u8;
    task_request_stop();
    reg_a0 = &D_0028E84C_as_u8;
    task_request_stop();
    reg_a0 = &D_0028E844_as_u8;
    task_request_stop();
    reg_a0 = &D_0028E840_as_u8;
    task_request_stop();
    reg_a0 = &D_0028E83C_as_u8;
    task_request_stop();
    music_stop();
    sound_stop_effects();
    reg_d0.h[0] = 0xE;
    task_start();
    ENTITY(reg_a6)->flags.sh = 0;
    ENTITY(reg_a6)->y.sh = 0;
}

typedef struct {
    u8 pad0[3];
    u8 unk3;
} FlagByte3;

typedef struct {
    s16 unk0;
    s16 unk2;
} HalfPair;


void func_00135D70(void) {
    ((FlagByte3 *)reg_a5)->unk3 = 2;
    ((HalfPair *)reg_a6)->unk0 = 0;
    ((HalfPair *)reg_a6)->unk2 = 0;
}

s32 task_find();                            /* extern */

void func_00135D90(void) {
    D_0028E850 += 1;
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x20);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x22);
    task_find();
    *(s8 *)(reg_a0 + 3) = 3;
    ENTITY(reg_a6)->flags.sh = 0;
    ENTITY(reg_a6)->y.sh = 0;
}

void func_00135DF0(void) {
    reg_a2 = (u8 *)D_002BF390_as_s32_a;
    reg_a3 = (u8 *)D_002BF3B4_as_s32_a;
    reg_d0.h[1] = (*(u16 *)((u8 *)((s32 *)reg_a2) + (0x20)));
    reg_d0.h[0] = (*(u16 *)((u8 *)((s32 *)reg_a2) + (0x22)));
    task_find();
    *(s8 *)(reg_a0 + 4) = 0;
    reg_d0.h[1] = (*(u16 *)((u8 *)((s32 *)reg_a3) + (0x20)));
    reg_d0.h[0] = (*(u16 *)((u8 *)((s32 *)reg_a3) + (0x22)));
    task_find();
    *(s8 *)(reg_a0 + 4) = 0;
    ENTITY(reg_a6)->flags.sh = 0;
    ENTITY(reg_a6)->y.sh = 0;
}

s32 func_0013F2A0();                            /* extern */
s32 func_0013F310();                            /* extern */

void func_00135E70(void) {
    if (*(u8 *)(reg_a6 + 0x16) == 0) {
        func_0013F2A0();
    } else {
        func_0013F310();
    }
    *(s16 *)reg_a6 = 0;
    *(s16 *)(reg_a6 + 2) = 0;
}


void func_00135EC0(void) {
    func_00135ED0();
}

extern s32 D_0028E83C;
extern s32 D_0028E840;
extern s32 D_0028E844;
extern s32 D_0028E848;
extern u16 D_0028E854_as_u16;
extern u16 g_enemy_signal_f;
extern u16 g_enemy_signal_e;
extern u16 g_enemy_signal_d;
extern u16 g_enemy_signal_c;
extern u16 g_enemy_signal_b;
extern u16 g_enemy_signal_a;
extern u16 g_enemy_signal_9;
extern u16 g_enemy_signal_8;
extern u16 g_enemy_signal_7;
extern u16 g_enemy_signal_6;
extern u16 g_enemy_signal_5;
extern u16 g_enemy_signal_4;
extern u16 g_enemy_signal_3;
extern u16 g_enemy_signal_2;
extern u16 g_enemy_signal_1;
extern u16 g_enemy_signal_0;
extern u16 g_stopped_and_blocked;
extern u16 g_bullets_blocked;
extern u16 g_enemies_stopped;
extern u16 D_0028E8A4;
extern u16 g_scroll_line;
extern u8 D_0028E8B0;
extern u16 D_0028E8B8;
extern s32 D_0028E8BC;
extern u16 g_p2_lives;
extern u16 g_p1_lives;
extern u16 g_rank_1_16;
extern u16 g_rank_2_16;
extern u16 g_rank_3_16;
extern u16 g_rank_4_16;
extern u16 g_rank_5_16;
extern u16 g_rank_6_16;
extern u16 g_rank_7_16;
extern u16 g_rank_8_16;
extern u16 g_rank_9_16;
extern u16 g_rank_10_16;
extern u16 g_rank_11_16;
extern u16 g_rank_12_16;
extern u16 g_rank_13_16;
extern u16 g_rank_14_16;
extern u16 g_rank_15_16;
extern u16 g_rank;
extern u16 g_true_last_boss;
extern u16 g_game_completed;
extern u16 g_two_player_seen;
void func_00135ED0(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    g_two_player_game = g_two_player_state = g_two_player_seen = g_stage = g_stage_x2 = g_stage_x4 = g_loop = g_game_completed = g_true_last_boss = g_rank = g_rank_15_16 = g_rank_14_16 = g_rank_13_16 = g_rank_12_16 = g_rank_11_16 = g_rank_10_16 = g_rank_9_16 = g_rank_8_16 = g_rank_7_16 = g_rank_6_16 = g_rank_5_16 = g_rank_4_16 = g_rank_3_16 = g_rank_2_16 = g_rank_1_16 = g_p1_lives = g_p2_lives = D_0028E8BC = D_0028E8B8 = (D_0028E8B4 = D_0028E8B0 = (g_scroll_line = D_0028E8A4 = g_enemies_stopped = g_bullets_blocked = g_stopped_and_blocked = 0));
    D_0028E854_as_u16 = 0;
    g_enemy_signal_f = 0;
    g_enemy_signal_e = 0;
    g_enemy_signal_d = 0;
    g_enemy_signal_c = 0;
    g_enemy_signal_b = 0;
    g_enemy_signal_a = 0;
    g_enemy_signal_9 = 0;
    g_enemy_signal_8 = 0;
    g_enemy_signal_7 = 0;
    g_enemy_signal_6 = 0;
    g_enemy_signal_5 = 0;
    g_enemy_signal_4 = 0;
    g_enemy_signal_3 = 0;
    g_enemy_signal_2 = 0;
    g_enemy_signal_1 = 0;
    g_enemy_signal_0 = 0;
    do {
        temp_a2 = (u8 *)(D_002BF390 + var_a1);
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x48);
    D_0028E850 = 0;
    D_0028E83C = 0;
    D_0028E840 = 0;
    D_0028E844 = 0;
    D_0028E848 = 0;
    D_0028E84C = 0;
    g_p1_lives = 0xFFFF;
    g_p2_lives = 0xFFFF;
}

s32 func_001AAEE0();
s32 func_001AB070();
s32 func_001AC840();

void func_00136010(void) {
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
    save_d7 = reg_d7.w;
    save_a0 = reg_a0;
    save_a1 = reg_a1;
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    save_a4 = reg_a4;
    save_a5 = reg_a5;
    save_a6 = reg_a6;
    reg_a2 = (u8 *)D_002BF390;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    reg_a3 = (u8 *)D_002BF3B4;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    if ((s32) save_d0 >= 0) {
        *(u16 *)(reg_a2 + 0x10) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a2 + 0x12) = (u16) reg_d0.h[0];
    }
    if ((s32) reg_d1.w >= 0) {
        *(u16 *)(reg_a3 + 0x10) = (u16) reg_d1.h[1];
        *(u16 *)(reg_a3 + 0x12) = (u16) reg_d1.h[0];
    }
    reg_d0.h[0] = D_0028E938;
    if (reg_d0.h[0] != 0xFF) {
        reg_d0.w = 0;
        reg_d1.h[0] = 4;
        func_001353E0();
        if (g_loop == 0) {
            func_001AAEE0();
        }
    } else {
        reg_d0.h[0] = 0xB;
        task_start();
        *(u16 *)(reg_a2 + 0x1C) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a2 + 0x1E) = (u16) reg_d0.h[0];
        *(s8 *)(reg_a0 + 6) = 0;
    }
    reg_d0.h[0] = D_0028E934;
    if (reg_d0.h[0] != 0xFF) {
        reg_d0.w = 1;
        reg_d1.h[0] = 4;
        func_001353E0();
        if (g_loop == 0) {
            func_001AB070();
        }
    } else {
        reg_d0.h[0] = 0xB;
        task_start();
        *(u16 *)(reg_a3 + 0x1C) = (u16) reg_d0.h[1];
        *(u16 *)(reg_a3 + 0x1E) = (u16) reg_d0.h[0];
        *(s8 *)(reg_a0 + 6) = 1;
    }
    func_001AC840();
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

void func_00136260(void) {
    reg_a2 = D_002BF390;
    reg_a3 = D_002BF3B4;
    reg_a0 = reg_a2 + 0x18;
    task_request_stop();
    reg_a0 = reg_a3 + 0x18;
    task_request_stop();
    reg_a0 = reg_a2 + 0x1C;
    task_request_stop();
    reg_a0 = reg_a3 + 0x1C;
    task_request_stop();
    reg_a0 = reg_a2 + 0x20;
    task_request_stop();
    reg_a0 = reg_a3 + 0x20;
    task_request_stop();
}

extern u16 D_0028E940;

void func_001362F0(void) {
    reg_a0 = (u8 *)(&D_0028E848);
    task_request_stop();
    reg_a0 = (u8 *)(&D_0028E84C);
    task_request_stop();
    if (D_0028E940 != 0) {
        func_00136260();
    }
}

s32 func_00138110();
s32 text_palette_load();
s32 func_001A3300();
extern u8 g_default_text_palette[];
extern u32 D_0028E848_as_u32;
extern u16 D_0028E944;

void func_00136330() {
    u16 temp_a0;
    u16 temp_a1;
    u32 temp_a0_2;

    reg_d0.h[0] = 5;
    task_start();
    temp_a0 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a0;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    D_0028E848_as_u32 = reg_d0.w;
    reg_d0.h[0] = 1;
    task_start();
    temp_a1 = reg_d0.h[1];
    reg_tmp.h[0] = temp_a1;
    reg_d0.h[1] = reg_d0.h[0];
    reg_d0.h[0] = reg_tmp.h[0];
    temp_a0_2 = reg_d0.w;
    D_0028E84C_as_u32 = temp_a0_2;
    *(u16 *)(reg_a0 + 6) = (u16) D_0028E944;
    if (D_0028E940 != 0) {
        reg_d0.w = 0x10000E00;
        reg_d1.w = 0x10002A00;
        func_00136010();
        D_0028E940 = 0;
    }
    reg_d0.w = 0;
    reg_a0 = g_default_text_palette;
    text_palette_load();
    func_001A3300();
    func_00138110();
}

extern s16 D_0028DFC4_as_s16;

void func_00136400(void) {
    D_0028DFC4_as_s16 = 0;
    D_0028E944 = reg_d7.h[0];
    D_0028E940 = reg_d6.h[0];
    func_001362F0();
    func_00135010();
    func_00136330();
    func_00135420();
}

s32 func_00125DE0();
s32 func_00131630();
s32 func_001340F0();
s32 func_0013FD80();
s32 func_00171ED0();
s32 func_001AACC0();
s32 func_001AE490();
extern u8 D_00269160[];
extern u8 D_00269180[];
extern u8 D_002691A0[];
extern u8 D_002691C0[];
extern u8 D_002691E0[];
extern u8 D_00269200[];
extern u8 D_002692A0[];
extern u8 D_002692C0[];
extern u8 D_002692E0[];
extern u8 D_00269300[];
extern u16 D_0028E93C;

void func_00136450(void) {
    *(s8 *)(reg_a5 + 3) = 1;
    reg_a0 = (u8 *)D_00269160;
    reg_d0.w = 0;
    text_palette_load();
    reg_a0 = (u8 *)D_00269180;
    reg_d0.w = 1;
    text_palette_load();
    reg_a0 = (u8 *)D_002691A0;
    reg_d0.w = 2;
    text_palette_load();
    reg_a0 = (u8 *)D_002691C0;
    reg_d0.w = 3;
    text_palette_load();
    reg_a0 = (u8 *)D_002691E0;
    reg_d0.w = 4;
    text_palette_load();
    reg_a0 = (u8 *)D_00269200;
    reg_d0.w = 5;
    text_palette_load();
    reg_a0 = (u8 *)D_002692A0;
    reg_d0.w = 6;
    text_palette_load();
    reg_a0 = (u8 *)D_002692C0;
    reg_d0.w = 7;
    text_palette_load();
    reg_a0 = (u8 *)D_002692E0;
    reg_d0.w = 8;
    text_palette_load();
    reg_a0 = (u8 *)D_00269300;
    reg_d0.w = 0xB;
    text_palette_load();
    D_0028E93C = 1;
    D_0028E940 = 0;
    if (g_loop == 0) {
        func_00135ED0();
    } else {
        D_0028E850 = 0;
        g_p1_lives = 0xFFFF;
        g_p2_lives = 0xFFFF;
        D_0028E84C = 0;
        D_0028E848 = 0;
        D_0028E844 = 0;
        D_0028E840 = 0;
        D_0028E83C = 0;
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    func_00134FE0();
    func_00131630();
    func_00171ED0();
    if (g_loop == 0) {
        func_00125DE0();
        func_001AE490();
        func_001AACC0();
        func_0013FD80();
    }
    func_00135220();
    func_001340F0();
}

s32 func_001AEF50();
extern s32 D_0028E998;
extern s32 D_0028E99C;
extern u8 D_0028ED7C;

void ship_select_apply(void) {
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
    s32 var_v0;
    u32 temp_a2;

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
    if (D_0028E93C != 0) {
        temp_a2 = reg_d0.h[0];
        D_0028E99C = -1;
        D_0028E998 = -1;
        D_0028E938 = temp_a2;
        D_0028E93C = 0;
        D_0028E930 = reg_d1.h[0];
        D_0028E934 = reg_d2.h[0];
        D_0028E92C = reg_d3.h[0];
        D_0028E940 = reg_d4.h[0];
        reg_d0.h[0] = D_0028E938;
        reg_d1.h[0] = D_0028E934;
        reg_d2.h[0] = D_0028E930;
        reg_d3.h[0] = D_0028E92C;
        func_001AEF50();
        var_v0 = g_simulation_active == 1;
        reg_d7.w = 0;
        if (var_v0 == 0) {
            var_v0 = D_0028ED7C == 2;
        }
        if (((var_v0 != 0) || (g_attract_demo != 0)) && (g_stage == 0)) {
            reg_d7.h[0] = 0x38;
        }
        reg_d6.h[0] = D_0028E940;
        func_00136400();
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

s32 func_00134380();
s32 func_00138170();
s32 task_stop_self();
extern u8 g_stage_load_state;
extern u16 g_game_frame;
extern u8 D_0028EC4C;
extern s16 D_00299768[];

void func_001367C0(void) {
    u8 t;

    t = *(u8 *)(reg_a5 + 3);
    if (t == 0) {
        func_00136450();
        return;
    }
    if (t == 2) goto block_end1;
    func_00135420();
    if (D_0028E93C == 0) {
        if (g_enemies_stopped == 0) {
            if (g_bullets_blocked != 0) {
                g_bullets_blocked -= 1;
            }
        }
        reg_d0.w = 0xE;
        reg_d0.h[0] &= g_game_frame;
        D_0028E8B8 = reg_d0.h[0];
        if ((g_enemies_stopped == 0) && (g_stage_load_state == 0) && (D_0028EC4C == 0)) {
            D_0028E8BC += 1;
        }
        func_00138170();
        func_00134380();
        if (g_loop != 0) {
            D_00299768[0] = 1;
        }
    }
    return;
block_end1:
    func_00135ED0();
    task_stop_self();
}

extern s32 D_0029BC00_as_s32_a[];


void func_001368C0(void) {
    memset(&D_0029BC00_as_s32_a[0], 0, 0x180);
}


void func_001368E0(void) {
loop_1:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x44);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x46);
    reg_a1 = (u8 *)(reg_tmp.w);
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (0 > (s16) reg_d0.h[0]) {
        func_00136A30();
        return;
    }
    if ((s16) reg_d0.h[0] < (s32) ENTITY(reg_a6)->hp.h) {
        func_00136A30();
        return;
    }
    func_00136A40();
    goto loop_1;
}

void func_00136980(void) {
    u32 temp_s0;

loop_1:
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x44);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x46);
    reg_a1 = (u8 *)(reg_tmp.w);
    reg_d1.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (0 > (s32) reg_d1.w) {
        func_00136A30();
        return;
    }
    temp_s0 = reg_d0.w;
    if ((s32) reg_d1.w < (s32) temp_s0) {
        func_00136A30();
        return;
    }
    func_00136A40();
    reg_d0.w = temp_s0;
    goto loop_1;
}


void func_00136A30(void) {
    (*(u8 *)&cond_flag) = 0;
}

extern u16 D_0029BC00_as_u16_a[];
extern u16 D_0029BD7C[];

void func_00136A40(void) {
    reg_a0 = (u8 *)D_0029BC00_as_u16_a;
    reg_d0.w = 9;
loop_0:
    if (*(u16 *)reg_a0 == 0) goto next_0;
    reg_a0 += 0x26;
    if ((s16)(reg_d0.h[0] -= 1) >= 0) goto loop_0;
    reg_a1 += 0xC;
    reg_tmp.w = (u32)reg_a1;
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    cond_flag = 1;
    reg_d0.w = 0;
    reg_d0.h[0] -= 1;
    return;
next_0:
    reg_d1.h[1] = *(u16 *)(reg_a5 + 6);
    reg_d1.h[0] = *(u16 *)(reg_a5 + 8);
    reg_d2.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d3.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a2 = (u8 *)reg_tmp.w;
    reg_tmp.w = (u32)reg_a1;
    *(u16 *)(reg_a5 + 0x44) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x46) = reg_tmp.h[0];
    D_0029BD7C[0] += 1;
    func_00136BB0();
}

s32 rng_next_bit();
extern u16 D_0024F520[];
extern u8 D_0029BD7C_as_u8_a[];

void func_00136BB0(void) {
    u8 *save;

    save = reg_a0;
    reg_d0.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    reg_a3 = (u8 *)D_0024F520;
    reg_a3 = *(u8 **)(reg_a3 + reg_d0.h[0]);
    reg_d0.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    if (0 <= (s64)*(s16 *)reg_a2) goto next_0;
    reg_d0.w |= 0x80;
next_0:
    *(u16 *)reg_a0 = reg_d0.h[0];
    reg_a0 += 2;
    reg_a1 = (u8 *)reg_d1.w;
    *(u16 *)reg_a0 = *(u16 *)(reg_a1 + 2);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)(reg_a1 + 4);
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0 += 4;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d1.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d2.h[0];
    reg_a0 += 2;
    if (0 <= (s64)(s8)reg_d3.b[0]) goto next_2;
    reg_d3.b[0] = ~reg_d3.b[0];
    if (!(reg_d3.w & 0x20)) goto next_1;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_1;
    reg_d3.b[0] ^= 0x20;
next_1:
    if (!(reg_d3.h[0] & 0x40)) goto next_2;
    rng_next_bit();
    if (reg_d0.b[0] != 0) goto next_2;
    reg_d3.b[0] ^= 0x40;
next_2:
    *(u16 *)reg_a0 = reg_d3.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)reg_a0 = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_a0 += 2;
    reg_a0[-1] = reg_d3.b[0];
    reg_tmp.w = (u32)reg_a2;
    *(u16 *)reg_a0 = reg_tmp.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_tmp.h[0];
    reg_a0 += 2;
    reg_d3.h[1] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] = *(u16 *)reg_a3;
    reg_a3 += 2;
    reg_d3.h[0] -= *(u16 *)(D_0029BD7C_as_u8_a + 2);
    *(u16 *)reg_a0 = reg_d3.h[1];
    reg_a0 += 2;
    *(u16 *)reg_a0 = reg_d3.h[0];
    reg_a0 += 2;
    *(u16 *)(D_0029BD7C_as_u8_a + 2) -= 4;
    if (0 <= (s64)*(s16 *)(D_0029BD7C_as_u8_a + 2)) goto next_3;
    *(u16 *)(D_0029BD7C_as_u8_a + 2) = 0xC;
next_3:
    reg_a0 = save;
    cond_flag = 0;
}

extern u8 D_0024F3C0[];
extern u8 D_0024F3F0[];
extern u8 D_0024F410[];
extern u8 D_0024F430[];
extern u8 D_0024F460[];
extern u8 D_0024F480[];
extern u8 D_0024F4A0[];
extern u8 D_002BC7C0[];
extern u16 D_0028E3EC;
extern s8 D_0028E855_as_s8;
extern u8 D_0029BC00[];
extern void (*reg_call_target)();

void func_00136F30(void) {
    u32 count;
    u8 bits;

    reg_d0.h[0] = 0x95;
    reg_d1.w = 0;
    reg_a0 = (u8 *)D_002BC7C0;
loop_10:
    bits = *(u8 *)(reg_a0 + 1);
    if (bits == 0) goto next_20;
    if (0 > (s8)bits) goto next_20;
    *(u16 *)reg_a0 = reg_d1.h[0];
next_20:
    reg_a0 += 0x20;
    count = reg_d0.h[0] - 1;
    reg_d0.h[0] = count;
    if (((s64)((s64)(u16)count << 0x30) >> 0x30) >= 0) goto loop_10;
    reg_d7.h[0] = D_0029BD7C[0];
    if (reg_d7.h[0] == 0) return;
    reg_d7.h[0] -= 1;
    reg_a6 = (u8 *)D_0029BC00;
    goto loop_40;
loop_30:
    reg_a6 += 0x26;
loop_40:
    reg_d2.h[0] = ENTITY(reg_a6)->flags.h;
    if (reg_d2.h[0] == 0) goto loop_30;
    if (reg_d2.w & 0x200) goto next_50;
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d1.h[0] = *(u16 *)reg_a0;
    if (!(0 > (s16)reg_d1.h[0])) goto block_clr;
    if (0 > (s8)reg_d1.b[0]) goto block_clr;
    if (0 > D_0028E855_as_s8) goto block_clr;
next_50:
    if (D_0028E3EC == 0) goto next_90;
    if (0 > (s8)reg_d2.b[0]) goto next_60;
    *(u16 *)(reg_a6 + 0x22) -= 1;
    if (*(u16 *)(reg_a6 + 0x22) != 0) goto next_60;
    func_00137820();
    reg_d2.h[0] = ENTITY(reg_a6)->flags.h;
next_60:
    reg_d0.w = 0x7C;
    reg_d0.h[0] &= reg_d2.h[0];
    switch (reg_d0.h[0]) {
    case 0x00: goto block_a0;
    case 0x04: goto block_a1;
    case 0x08: goto block_a2;
    case 0x0C: goto block_a3;
    case 0x10: goto block_a4;
    case 0x14: goto block_a5;
    case 0x18: goto block_objset;
    case 0x1C: goto block_objset;
    case 0x20: goto block_objset;
    case 0x24: goto block_objset;
    case 0x28: goto block_a0;
    case 0x2C: goto block_a1;
    case 0x30: goto block_a2;
    case 0x34: goto block_a3;
    case 0x38: goto block_a4;
    case 0x3C: goto block_a5;
    case 0x40: goto block_objset;
    case 0x44: goto block_objset;
    case 0x48: goto block_objset;
    case 0x4C: goto block_objset;
    }
next_90:
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
    return;
block_clr:
    ENTITY(reg_a6)->flags.h = 0;
    D_0029BD7C[0] -= 1;
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
    return;
block_a0:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F3F0;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a1:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F410;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a2:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F430;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0x1C;
    goto block_objset;
block_a3:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F460;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a4:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F480;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0xC;
    goto block_objset;
block_a5:
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x24);
    reg_a0 = (u8 *)D_0024F4A0;
    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a6 + 0x24) -= 4;
    if (!(0 > *(s16 *)(reg_a6 + 0x24))) goto block_objset;
    *(u16 *)(reg_a6 + 0x24) = 0x1C;
block_objset:
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_a0 = (u8 *) reg_tmp.w;
    reg_d0.h[1] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = *(u16 *)(reg_a0 + 4);
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d0.w += reg_tmp.w;
    ENTITY(reg_a6)->y.h = reg_d0.h[1];
    ENTITY(reg_a6)->x.h = reg_d0.h[0];
    reg_d0.h[0] = ENTITY(reg_a6)->hp.h;
    if (!(ENTITY(reg_a6)->flags.b[1] & 1)) goto next_obj10;
    reg_d0.b[0] = *(u8 *)(reg_a0 + 0x1F);
    reg_d0.h[0] <<= 2;
next_obj10:
    reg_a0 = (u8 *)D_0024F3C0;
    reg_a0 += reg_d0.h[0];
    reg_a0 = *(u8 **)reg_a0;
    reg_call_target = (Fn)(reg_a0);
    reg_call_target();
    reg_a6 += 0x26;
    count = reg_d7.h[0] - 1;
    reg_d7.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_40;
}


void func_00137820(void) {
    u32 temp_s0;

    reg_d1.h[1] = ENTITY(reg_a6)->hit_y_plus.h;
    reg_d1.h[0] = ENTITY(reg_a6)->hit_y_minus.h;
    reg_d2.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_d2.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d3.h[1] = ENTITY(reg_a6)->hp.h;
    reg_d3.h[0] = ENTITY(reg_a6)->move.h;
    reg_tmp.h[1] = ENTITY(reg_a6)->misc.h;
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_a2 = (u8 *)reg_tmp.w;
    if (ENTITY(reg_a6)->flags.b[1] & 2) {
        temp_s0 = reg_d1.w;
        reg_a0 = reg_a6;
        func_00136BB0();
        reg_a1 = (u8 *)temp_s0;
        *(u8 *)(reg_a0 + 1) |= 2;
        *(u16 *)(reg_a0 + 2) = (u16) (*(u16 *)((u8 *)((u32)reg_a1) + (2)));
        *(u16 *)(reg_a0 + 4) = (u16) (*(u16 *)((u8 *)((u32)reg_a1) + (4)));
        reg_tmp.w = (u32)reg_a1;
        *(u16 *)(reg_a0 + 0x10) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a0 + 0x12) = (u16) reg_tmp.h[0];
        return;
    }
    reg_a0 = reg_a6;
    func_00136BB0();
}
