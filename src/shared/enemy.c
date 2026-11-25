#include "common.h"
#include "entity.h"

void func_0014D4A0(void);
void func_0014DA80(void);
void func_0014DDB0(void);
void func_0014E070();
void func_0014E130(void);
void enemy_remove_entities();
void enemy_init_entities_n(void);

extern u8 D_0028E30C;
extern u16 g_attract_demo;
extern u8 D_0028ED7C;
extern u8 g_simulation_active;

void enemy_hitbox_debug_draw(void) {
#ifndef DEATH_LABEL
    if (g_attract_demo == 0 && D_0028E30C != 0 && g_simulation_active != 0) {
        if (D_0028ED7C == 2) {
            return;
        }
    }
#endif
}

extern s16 D_0028E7D4_as_s16;
extern s16 D_0028E7D8;
extern s16 D_0028E7DC;
extern s16 D_0028E7E0;
extern s16 D_0028E7E4_as_s16;
extern s16 D_0028E7E8_as_s16;
extern s16 D_0028E7EC_as_s16;
extern s8 D_002BBAF0_as_s8_a[];
extern s8 D_002BBB40_as_s8_a[];
typedef struct { s8 a[0xC80]; s8 b[0x640]; s8 c[0x640]; } S1;
extern S1 D_002BC7C0_as_S1;
typedef struct { s8 a[0xA0]; s8 b[0x280]; s8 c[0xF00]; s8 d[0x50]; } S0;
extern S0 D_002BE0C0_as_S0;

void func_0014D260(void) {
    s32 i;

    for (i = 0; i < 0xA0; i++) {
        D_002BE0C0_as_S0.a[i] = 0;
    }
    for (i = 0; i < 0x280; i++) {
        D_002BE0C0_as_S0.b[i] = 0;
    }
    for (i = 0; i < 0xF00; i++) {
        D_002BE0C0_as_S0.c[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        D_002BE0C0_as_S0.d[i] = 0;
    }
    for (i = 0; i < 0xC80; i++) {
        D_002BC7C0_as_S1.a[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        D_002BC7C0_as_S1.b[i] = 0;
    }
    for (i = 0; i < 0x640; i++) {
        D_002BC7C0_as_S1.c[i] = 0;
    }
    D_0028E7D4_as_s16 = 0;
    D_0028E7D8 = 0;
    D_0028E7DC = 0;
    D_0028E7E0 = 0;
    D_0028E7E4_as_s16 = 0;
    D_0028E7E8_as_s16 = 0;
    D_0028E7EC_as_s16 = 0;
    for (i = 0; i < 0xC80; i++) {
        D_002BBB40_as_s8_a[i] = 0;
    }
    for (i = 0; i < 0x50; i++) {
        D_002BBAF0_as_s8_a[i] = 0;
    }
    func_0014D4A0();
}

extern u16 D_0026A2B0[];
extern u16 D_0026A300[];
extern u8 g_game_mode;
extern u8 g_simulation_boss_start;
extern u16 g_stage_x4;
extern u8 D_002BF330[];

void func_0014D4A0(void) {
    reg_a4 = D_002BF330;
    reg_a0 = (u8 *)(D_0026A2B0);
    reg_d0.h[0] = g_stage_x4;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    if (((g_simulation_active != 0) && (g_simulation_boss_start != 0)) || (g_game_mode == 2)) {
        reg_a0 = (u8 *)(D_0026A300);
    }
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 2) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)reg_a4 = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 6) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 4) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[0] = *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_a0 += 2;
    *(u16 *)(reg_a4 + 8) = (u16) reg_d0.h[1];
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_d0.h[0];
    D_0028E7D4_as_s16 = 0;
}


extern u16 D_0028E7D4;
extern u16 g_scroll_line;
extern u8 D_002BBB40[];
extern u8 D_002BF2E0[];

void func_0014D5D0(void) {
    u8 *save_a2;
    u8 *save_a3;

    reg_a3 = (u8 *)D_002BF330;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 0);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 2);
    reg_a2 = (u8 *) reg_tmp.w;
loop_1:
    reg_d0.h[0] = *(u16 *) (reg_a2 + 0);
    if (reg_d0.h[0] == 0xFFFF) goto next_3;
    if ((s16) g_scroll_line > (s16) reg_d0.h[0]) goto next_2;
    if (g_scroll_line != reg_d0.h[0]) goto next_3;
    reg_d0.w = 0;
    reg_d0.b[0] = *(u8 *) (reg_a2 + 5);
    reg_d1.h[1] = *(u16 *) (reg_a2 + 4);
    reg_d1.h[0] = *(u16 *) (reg_a2 + 6);
    reg_d1.w &= 0xFFF000;
    reg_d7.w = 0x10;
    reg_d1.w = (u32) reg_d1.w >> reg_d7.w;
    reg_d7.h[0] = *(u16 *) (reg_a2 + 6);
    reg_d7.h[0] &= 0xFFF;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 4);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 6);
    reg_a1 = (u8 *) reg_tmp.w;
    reg_d7.h[0] += reg_d7.h[0];
    reg_d7.h[0] = (reg_d7.h[0] != 0) ? *(u16 *) (reg_a1 + ((s16) reg_d7.h[0] & ~1)) : *(u16 *) reg_a1;
    reg_tmp.h[1] = *(u16 *) (reg_a3 + 8);
    reg_tmp.h[0] = *(u16 *) (reg_a3 + 0xA);
    reg_a1 = (u8 *) reg_tmp.w;
    reg_a1 += reg_d7.h[0];
    func_0014E130();
    if (cond_flag != 0) goto next_2;
    *(u16 *) (reg_a0 + 0xA) = *(u16 *) (reg_a2 + 2);
    reg_tmp.w = (u32) reg_a1;
    *(u16 *) (reg_a0 + 0x12) = reg_tmp.h[1];
    *(u16 *) (reg_a0 + 0x14) = reg_tmp.h[0];
    save_a2 = reg_a2;
    save_a3 = reg_a3;
    reg_a5 = reg_a0;
    func_0014DDB0();
    reg_a3 = save_a3;
    reg_a2 = save_a2;
next_2:
    reg_a2 += 8;
    goto loop_1;
next_3:
    reg_tmp.w = (u32) reg_a2;
    *(u16 *)reg_a3 = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a3 + 2) = (u16) reg_tmp.h[0];
loop_11:
    reg_d6.h[0] = D_0028E7D4;
    if (D_0028E7D4 != 0) {
        reg_a4 = (u8 *)D_002BBB40;
        reg_d6.h[0] -= 0x50;
        reg_a4 += reg_d6.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a4 + 2);
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d1.h[0] = *(u16 *)(reg_a4 + 4);
        func_0014E130();
        if (cond_flag == 0) {
            *(u8 *)(reg_a0 + 3) = (u8) *(u8 *)(reg_a4 + 3);
            *(u16 *)(reg_a0 + 0x12) = (u16) *(u16 *)(reg_a4 + 0x12);
            *(u16 *)(reg_a0 + 0x14) = (u16) *(u16 *)(reg_a4 + 0x14);
            *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)(reg_a4 + 0x16);
            *(u16 *)(reg_a0 + 0x18) = (u16) *(u16 *)(reg_a4 + 0x18);
            *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)(reg_a4 + 0x1A);
            *(u16 *)(reg_a0 + 0x1C) = (u16) *(u16 *)(reg_a4 + 0x1C);
            *(u16 *)(reg_a0 + 0x1E) = (u16) *(u16 *)(reg_a4 + 0x1E);
            *(u16 *)(reg_a0 + 0x20) = (u16) *(u16 *)(reg_a4 + 0x20);
            *(u16 *)(reg_a0 + 0x22) = (u16) *(u16 *)(reg_a4 + 0x22);
            *(u16 *)(reg_a0 + 0x24) = (u16) *(u16 *)(reg_a4 + 0x24);
            *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)(reg_a4 + 0x26);
            *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)(reg_a4 + 0x28);
            *(u16 *)(reg_a0 + 0x2A) = (u16) *(u16 *)(reg_a4 + 0x2A);
            *(u16 *)(reg_a0 + 0x2C) = (u16) *(u16 *)(reg_a4 + 0x2C);
            *(u16 *)(reg_a0 + 0x2E) = (u16) *(u16 *)(reg_a4 + 0x2E);
            *(u16 *)(reg_a0 + 0x30) = (u16) *(u16 *)(reg_a4 + 0x30);
            *(u16 *)(reg_a0 + 0x32) = (u16) *(u16 *)(reg_a4 + 0x32);
            *(u16 *)(reg_a0 + 0x34) = (u16) *(u16 *)(reg_a4 + 0x34);
            *(u16 *)(reg_a0 + 0x36) = (u16) *(u16 *)(reg_a4 + 0x36);
            *(u16 *)(reg_a0 + 0x38) = (u16) *(u16 *)(reg_a4 + 0x38);
            *(u16 *)(reg_a0 + 0x3A) = (u16) *(u16 *)(reg_a4 + 0x3A);
            *(u16 *)(reg_a0 + 0x3C) = (u16) *(u16 *)(reg_a4 + 0x3C);
            *(u16 *)(reg_a0 + 0x3E) = (u16) *(u16 *)(reg_a4 + 0x3E);
            *(u16 *)(reg_a0 + 0x40) = (u16) *(u16 *)(reg_a4 + 0x40);
            *(u16 *)(reg_a0 + 0x42) = (u16) *(u16 *)(reg_a4 + 0x42);
            *(u16 *)(reg_a0 + 0x44) = (u16) *(u16 *)(reg_a4 + 0x44);
            *(u16 *)(reg_a0 + 0x46) = (u16) *(u16 *)(reg_a4 + 0x46);
            *(u16 *)(reg_a0 + 0x48) = (u16) *(u16 *)(reg_a4 + 0x48);
            *(u16 *)(reg_a0 + 0x4A) = (u16) *(u16 *)(reg_a4 + 0x4A);
        }
        D_0028E7D4 = reg_d6.h[0];
        if (D_002BF2E0 != reg_a0) {
            reg_a5 = reg_a0;
            func_0014DDB0();
        }
        if (D_0028E7D4 != 0) {
            goto loop_11;
        }
    }
}


void func_0014DA50(void) {
    s32 temp_s0;

    temp_s0 = (s32)reg_a5;
    func_0014D5D0();
    func_0014DA80();
    reg_a5 = (u8 *)temp_s0;
}

typedef void (*Fn)();

extern u16 D_0028E7E4;
extern u16 D_0028E7E8;
extern u16 D_0028E7EC;
extern u16 g_side_scroll_step[];
extern u8 D_002BE0C0[];
extern u8 *reg_call_target_as_u8_p;

void func_0014DA80(void) {
    u32 temp_s0;

    reg_a5 = D_002BE0C0;
    D_0028E7EC = 0;
    D_0028E7E8 = 0;
    reg_d6.h[0] = 0x39;
    D_0028E7E4 = 0;
    do {
        if (*(u16 *)reg_a5 != 0) {
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
            reg_d0.h[0] = g_side_scroll_step[0];
            reg_a6 = (u8 *)reg_tmp.w;
            ENTITY(reg_a6)->x.h -= reg_d0.h[0];
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x4C);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x4E);
            reg_a1 = (u8 *)reg_tmp.w;
            reg_call_target_as_u8_p = reg_a1;
            temp_s0 = reg_d6.w;
            ((Fn)reg_call_target_as_u8_p)();
            reg_d6.w = temp_s0;
            reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
            reg_d0.h[0] += 1;
            if ((s16) *(u16 *)reg_a5 < 0) {
                D_0028E7EC += 1;
                reg_d2.b[0] = *(u8 *)(reg_a5 + 0xC);
                if (((s8) reg_d2.b[0] >= 0) && !(reg_d2.w & 0x20)) {
                    D_0028E7E8 += reg_d0.h[0];
                } else {
                    D_0028E7E4 += reg_d0.h[0];
                }
            }
        }
        reg_a5 += 0x50;
    } while ((s16)(--reg_d6.h[0]) >= 0);
    D_0028E7E0 = 0;
    D_0028E7DC = 0;
    D_0028E7D8 = 0;
}

s32 func_00203400();
extern u8 D_002BC7C0[];

void func_0014DBF0(u8 *arg1) {
    u8 *var_a1;
    u8 temp_a0;

    var_a1 = (u8 *)(arg1);
    reg_a0 = D_002BC7C0;
    reg_d3.w = 0x63;
    do {
        temp_a0 = *(u8 *)(reg_a0 + 1);
        if (temp_a0 & 0x20) {
            func_00203400();
            var_a1 = (u8 *)(reg_a0);
            (*(u8 *)((u8 *)(var_a1) + (1))) |= reg_d0.b[0];
            goto block_4;
        }
        if (temp_a0 & 0x40) {
block_4:
            *(u16 *)(reg_a0 + 0x18) = 0xFFFF;
        }
        reg_a0 += 0x20;
    } while ((s16)(--reg_d3.h[0]) >= 0);
}

extern u8 D_002BD440_as_u8_a[];

s32 func_0014DCA0(void) {
    u32 count;
    s32 ret;

    ret = 0;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.b[0] = *(u8 *)(reg_a5 + 0xC);
    if ((s8)reg_d2.b[0] >= 0) goto block_2;
block_1:
    reg_a6 = (u8 *)D_002BD440_as_u8_a;
    reg_d2.w = 0x32;
    goto loop_3;
block_2:
    if (reg_d2.w & 0x20) goto block_1;
    reg_a6 = (u8 *)D_002BC7C0;
    reg_d2.w = 0x64;
loop_3:
    reg_tmp2.w = reg_d2.h[0];
    reg_tmp2.w -= 1;
    reg_d2.h[0] = reg_tmp2.h[0];
    if (reg_tmp2.h[1] != 0) {
        ret = reg_tmp2.h[1] & 0xFFFF;
        goto block_7;
    }
    if (ENTITY(reg_a6)->flags.b[1] != 0) goto block_4;
    reg_a6 += 0x20;
    goto block_5;
block_4:
    reg_a6 += 0x20;
    reg_d1.h[0] = reg_d0.h[0];
    goto loop_3;
block_5:
    count = reg_d1.h[0] - 1;
    reg_d1.h[0] = count;
    if (((s64)((s64)(u16) count << 0x30) >> 0x30) >= 0) goto loop_3;
loop_6:
    reg_a6 -= 0x20;
    ENTITY(reg_a6)->flags.h = 0x8000;
    count = reg_d0.h[0] - 1;
    reg_d0.h[0] = count;
    if (((s64)((s64)(count & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_6;
block_7:
    return ret;
}

extern u8 D_002589F0[];
extern u8 D_002589F4[];
extern u8 D_00258DF0[];
extern u8 D_00259A70[];
extern u8 D_00259A74[];
extern u8 D_00259E70[];
extern u16 g_side_scroll_x[];
extern u8 g_player2_as_u8_a[];
extern u8 g_player1_as_u8_a[];

void func_0014DDB0(void) {
    s8 temp_s0;
    s64 var_a0;

    reg_d7.w = 0;
    reg_d7.b[0] = *(u8 *)(reg_a5 + 0xD);
    var_a0 = 0;
    if ((s16)(reg_d7.h[0]) >= 0x80) {
        var_a0 = 1;
        reg_d7.h[0] -= 0x80;
    }
    temp_s0 = var_a0;
    if (temp_s0 == 0) {
        ((Fn)*(u32 *)((u8 *)D_00258DF0 + (reg_d7.h[0] * 4)))();
    } else {
        ((Fn)*(u32 *)((u8 *)D_00259E70 + (reg_d7.h[0] * 4)))();
    }
    reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
    if (func_0014DCA0() == 0) {
        reg_tmp.w = (u32)reg_a6;
        *(u16 *)(reg_a5 + 6) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 8) = (u16) reg_tmp.h[0];
        reg_d7.h[0] *= 2;
        if (temp_s0 == 0) {
            reg_tmp.w = *(u32 *)(D_002589F4 + (reg_d7.h[0] * 4));
        } else {
            reg_tmp.w = *(u32 *)(D_00259A74 + (reg_d7.h[0] * 4));
        }
        *(u16 *)(reg_a5 + 0x4C) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x4E) = (u16) reg_tmp.h[0];
        reg_a0 = (u8 *)g_player1_as_u8_a;
        reg_d0.w = 0;
        if (*(u8 *)reg_a5 & 1) {
            reg_a0 = (u8 *)g_player2_as_u8_a;
            reg_d0.w = 1;
        }
        *(u8 *)(reg_a5 + 2) = (u8) reg_d0.b[0];
        *(s16 *)(reg_a5 + 0x3E) = 0;
        if (temp_s0 == 0) {
            ((Fn)*(u32 *)((u8 *)D_002589F0 + (reg_d7.h[0] * 4)))();
        } else {
            ((Fn)*(u32 *)((u8 *)D_00259A70 + (reg_d7.h[0] * 4)))();
        }
        reg_d0.b[0] = *(u8 *)(reg_a5 + 0xC);
        if (reg_d0.b[0] & 1) {
            reg_tmp.h[1] = *(u16 *)(reg_a5 + 6);
            reg_tmp.h[0] = *(u16 *)(reg_a5 + 8);
            reg_d0.h[0] = g_side_scroll_x[0];
            reg_a6 = (u8 *)reg_tmp.w;
            ENTITY(reg_a6)->x.h -= reg_d0.h[0];
        }
        reg_d0.h[0] = *(u16 *)(reg_a5 + 4);
        reg_d0.h[0] += 1;
        return;
    }
    *(u16 *)reg_a5 = 0;
}

extern u32 D_0028DF3C;
extern u32 D_0028DF40;
extern u32 D_0028DF44;
void enemy_request_start(void) {
    D_0028DF44 = reg_d0.w;
    D_0028DF40 = reg_d1.w;
    D_0028DF3C = reg_d2.sw;
    reg_d1.h[0] = 0x80;
    func_0014E070();
}


void func_0014E030(void) {
    D_0028DF40 = reg_d1.w;
    D_0028DF44 = reg_d0.w;
    D_0028DF3C = reg_d2.sw;
    *(u16 *)&reg_d1 = 0;
    func_0014E070(reg_d0.w);
}


void enemy_request_start_flags(void) {
    D_0028DF44 = reg_d0.w;
    D_0028DF40 = reg_d1.w;
    D_0028DF3C = reg_d2.w;
    func_0014E070(reg_d0.w);
}

extern u8 D_002BBAF0[];

void func_0014E070() {
    reg_d2.h[0] = D_0028E7D4;
    if (reg_d2.h[0] == 0xC80) goto next_1;
    reg_a0 = (u8 *)D_002BBB40;
    reg_a0 += reg_d2.h[0];
    *(u16 *) (reg_a0 + 2) = reg_d0.h[0];
    *(u16 *) (reg_a0 + 4) = reg_d1.h[0];
    *(s16 *) (reg_a0 + 0x12) = 0;
    *(s16 *) (reg_a0 + 0x14) = 0;
    reg_d2.h[0] += 0x50;
    D_0028E7D4 = reg_d2.h[0];
    reg_d0.w = D_0028DF44;
    reg_d1.w = D_0028DF40;
    reg_d2.w = D_0028DF3C;
    return;
next_1:
    reg_a0 = (u8 *)D_002BBAF0;
    reg_d0.w = D_0028DF44;
    reg_d1.w = D_0028DF40;
    reg_d2.w = D_0028DF3C;
}

extern u8 D_002BE160[];
extern u8 D_002BE3E0[];


void func_0014E130(void) {
    u32 sd0;
    u32 sd1;
    u32 sd2;
    u32 tmp;

    sd0 = reg_d0.w;
    sd1 = reg_d1.w;
    sd2 = reg_d2.w;
    if (((s16) reg_d0.h[0] >= 0x20) && ((s16) reg_d0.h[0] < 0x24)) {
        reg_a0 = (u8 *)D_002BE160;
        reg_d2.w = 7;
    } else if ((s16) reg_d1.h[0] < 0) {
        reg_a0 = (u8 *)D_002BE0C0;
        reg_d2.w = 1;
    } else {
        reg_d3.w = 0;
        reg_a0 = (u8 *)D_002BE3E0;
        reg_d2.w = 0x2F;
    }
loop_1:
    if (*(u16 *)(reg_a0 + 0) == 0) {
        reg_d3.h[0] |= 0x8000;
        *(u16 *)(reg_a0 + 0) = reg_d3.h[0];
        *(s16 *)(reg_a0 + 2) = 0;
        *(s16 *)(reg_a0 + 4) = 0;
        *(s16 *)(reg_a0 + 0xA) = 0;
        *(u8 *)(reg_a0 + 0xD) = reg_d0.b[0];
        *(u8 *)(reg_a0 + 0xC) = reg_d1.b[0];
        reg_d0.w = sd0;
        reg_d1.w = sd1;
        reg_d2.w = sd2;
        cond_flag = 0;
        return;
    }
    reg_a0 += 0x50;
    reg_d3.h[0] += 1;
    tmp = reg_d2.h[0] - 1;
    reg_d2.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
    reg_d0.w = sd0;
    reg_d1.w = sd1;
    reg_d2.w = sd2;
    reg_a0 = (u8 *)D_002BF2E0;
    cond_flag = 1;
}


void enemy_remove_now(void) {
    u8 *src = reg_a5;

    reg_tmp.h[1] = *(u16 *)(src + 6);
    reg_tmp.h[0] = *(u16 *)(src + 8);
    reg_d0.w = 0;
    reg_a6 = (u8 *)reg_tmp.sw;
    *(u16 *)&reg_d1 = *(u16 *)(src + 4);
    enemy_remove_entities();
}


void enemy_remove(void) {
    void *task = (void *)reg_a5;

    reg_tmp.h[1] = *(u16 *)((u8 *)task + 0x6);
    reg_tmp.h[0] = *(u16 *)((u8 *)task + 0x8);
    reg_d0.w = 1;
    reg_a6 = (u8 *)reg_tmp.sw;
    *(u16 *)&reg_d1 = *(u16 *)((u8 *)task + 0x4);
    enemy_remove_entities(task);
}

void enemy_remove_entities()
{
    do {
        ENTITY(reg_a6)->flags.b[1] = *(u8 *)&reg_d0;
        reg_a6 += 0x20;
    } while ((s16)(--reg_d1.h[0]) >= 0);

    *(u16 *)reg_a5 = 0;
}

extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;

void enemy_set_task_work(void)
{
    u32 savedCounter;
    u16 *savedSource;
    u16 *savedDestination;

    savedDestination = reg_a1_as_u16_p;
    savedCounter = reg_d0.w;
    savedSource = reg_a0_as_u16_p;
    reg_a1_as_u16_p = (u16 *)(reg_a5 + 0x16);

    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p++;
        reg_a1_as_u16_p++;
    } while ((s16)(--reg_d0.h[0]) >= 0);

    reg_d0.w = savedCounter;
    reg_a0_as_u16_p = savedSource;
    reg_a1_as_u16_p = savedDestination;
}



void enemy_init_entities(void) {
    reg_d7.h[0] = *(u16 *)(reg_a5 + 4);
    enemy_init_entities_n();
}

void enemy_init_entities_n(void) {
    reg_a1 = reg_a6;
loop_1:
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    if (*(s16 *) reg_a1 >= 0) {
        reg_a1 += 2;
        goto next_2;
    }
    reg_a1 += 6;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
    return;
next_2:
    reg_a1[-1] |= 0x80;
    reg_a1 += 4;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    reg_d0.w = 0;
    *(u16 *) reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[1];
    reg_a1 += 2;
    *(u16 *) reg_a1 = reg_d0.h[0];
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    *(u16 *) reg_a1 = *(u16 *) reg_a0;
    reg_a0 += 2;
    reg_a1 += 2;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
}

extern u8 D_0026A350[];
extern u16 D_0028E8A4;
extern s8 enemy_move_end_requested;

void enemy_path_start(void) {
    s8 t;

    enemy_move_end_requested = 0;
    reg_d0.h[1] = *(u16 *)(reg_a5 + 0x12);
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0x14);
    if (reg_d0.w == 0) {
        enemy_remove_now();
        return;
    }
    reg_a0 = (u8 *)(reg_d0.w);
    if (*(u8 *)(reg_a5 + 3) & 0x40) {
        *(u16 *)(reg_a6 + 2) = *(u16 *)(reg_a5 + 0x48);
        *(u16 *)(reg_a6 + 4) = *(u16 *)(reg_a5 + 0x4A);
        reg_d0.h[0] = g_side_scroll_x[0];
        *(u16 *)(reg_a6 + 4) += reg_d0.sh[0];
    } else {
        reg_d0.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_d0.b[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(u16 *)(reg_a6 + 2) = reg_d0.h[0];
        reg_tmp.b[1] = *(s8 *)reg_a0;
        reg_a0 += 1;
        reg_tmp.b[0] = *(s8 *)reg_a0;
        reg_a0 += 1;
        *(u16 *)(reg_a6 + 4) = reg_tmp.h[0];
    }
    if ((s32) *(u8 *)(reg_a6 + 5) >= 0x80) {
        *(u8 *)(reg_a6 + 5) |= 0x80;
    }
loop_1:
    t = *(s8 *)reg_a0;
    reg_d1.b[0] = t;
    if (t >= 0) goto next_1;
    reg_a0 += 1;
    if ((s32) reg_d1.b[0] >= 0xC0) {
        *(s8 *)(reg_a6 + 0x1B) = *(s8 *)reg_a0;
        reg_a0 += 1;
        goto loop_1;
    }
    enemy_move_end_requested = 0;
    reg_d1.h[0] &= 0xF;
    ((Fn)*(u32 *)((u8 *)D_0026A350 + (reg_d1.h[0] * 4)))();
    if (enemy_move_end_requested == 0) goto loop_1;
    return;
next_1:
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x14) = (u16) reg_tmp.h[0];
    *(u8 *)(reg_a6 + 0x1A) = (u8) reg_d1.b[0];
    reg_d0.h[0] = *(u16 *)(reg_a5 + 0xA);
    reg_d0.h[0] -= D_0028E8A4;
    reg_d0.h[0] &= 0x7F;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_d0.h[0] >>= 7;
    reg_d0.h[0] |= ((s16) reg_tmp.h[0] << 9) & 0xFFFF;
    *(u16 *)(reg_a6 + 4) += reg_d0.h[0];
    *(u16 *)(reg_a6 + 4) -= 0x800;
    reg_d1.w = 0;
    *(u16 *)(reg_a5 + 0x10) = (u16) reg_d1.h[0];
    *(u8 *)(reg_a5 + 3) |= 0x20;
}

s32 entity_follow_scroll();
s32 entity_velocity();
extern u16 g_enemies_stopped;

void enemy_path_step(void) {
    u8 *p;
    s8 v;
    u8 c;

    enemy_move_end_requested = 0;
    if (g_enemies_stopped != 0) goto block_7;
    if (*(u8 *)(reg_a5 + 0xC) & 1) {
        entity_follow_scroll();
    }
    reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x12);
    reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x14);
    reg_a0 = (u8 *)reg_tmp.w;
loop_1:
    p = reg_a0;
    reg_a0 = p + 1;
    v = *(s8 *)p;
    reg_d1.b[0] = v;
    if (v < 0) goto block_5;
    p = reg_a0;
    reg_a0 = p + 1;
    v = *(s8 *)p;
    reg_d0.b[0] = v;
    if ((v & 0xFF) == 0) goto next_2;
    c = *(u8 *)(reg_a5 + 0x11);
    if (c == reg_d0.b[0]) goto block_3;
    *(u8 *)(reg_a5 + 0x11) = c + 1;
next_2:
    reg_d1.h[0] &= 0x7F;
    ENTITY(reg_a6)->move.b.dir = reg_d1.b[0];
    if ((s32)reg_d1.h[0] >= 0x40) goto block_2;
    if (*(u8 *)(reg_a5 + 3) & 0x20) goto block_1;
    reg_d2.h[0] = *(u16 *)(reg_a5 + 0x40);
    reg_d3.h[0] = *(u16 *)(reg_a5 + 0x42);
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    cond_flag = 0;
    return;
block_1:
    *(u8 *)(reg_a5 + 3) &= 0xDF;
    entity_velocity();
    *(u16 *)(reg_a5 + 0x40) = reg_d2.h[0];
    *(u16 *)(reg_a5 + 0x42) = reg_d3.h[0];
    cond_flag = 0;
    return;
block_2:
    reg_d2.w = 0;
    reg_d3.h[0] = reg_d2.h[0];
    cond_flag = 0;
    return;
block_3:
    *(u8 *)(reg_a5 + 0x11) = 0;
block_4:
    reg_tmp.w = (u32)reg_a0;
    *(u16 *)(reg_a5 + 0x12) = reg_tmp.h[1];
    *(u16 *)(reg_a5 + 0x14) = reg_tmp.h[0];
    *(u8 *)(reg_a5 + 3) |= 0x20;
    goto loop_1;
block_5:
    if ((s32)reg_d1.b[0] < 0xC0) goto block_6;
    ENTITY(reg_a6)->move.sb.speed = *(s8 *)reg_a0;
    reg_a0 += 1;
    goto block_4;
block_6:
    enemy_move_end_requested = 0;
    reg_d1.h[0] &= 0xF;
    ((Fn) *(u32 *)(D_0026A350 + reg_d1.h[0] * 4))();
    if (enemy_move_end_requested == 0) goto block_4;
    cond_flag = 0;
    return;
block_7:
    cond_flag = 0;
    reg_d2.w = 0;
    reg_d3.w = 0;
}

extern s8 *reg_a0_as_s8_p;

void func_0014EC80(void) {
    reg_d0.w = 0;
    reg_d0.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 -= reg_d0.h[0];
}


void func_0014ECC0(void) {
    *(s8 *)(reg_a6 + 0x1E) = *(s8 *)reg_a0;
    reg_a0 += 1;
}


void func_0014ECE0(void)
{
    reg_d0.b[0] = *reg_a0_as_s8_p++;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        ENTITY(reg_a6)->flags.b[1] &= 0xDF;
    } else {
        ENTITY(reg_a6)->flags.b[1] |= 0x20;
    }
}

extern u16 *reg_a6_as_u16_p;

void func_0014ED40(void)
{
    reg_d0.b[0] = (u8)*reg_a0_as_s8_p;
    reg_a0_as_s8_p += 1;
    reg_d0.b[0] -= 1;

    if (reg_d0.b[0] == 0) {
        *reg_a6_as_u16_p &= 0xDFFE;
    } else {
        *reg_a6_as_u16_p |= 0x2001;
    }
}


void func_0014EDA0(void) {
    *(s8 *)(reg_a5 + 0x23) = *(s8 *)reg_a0;
    reg_a0 += 1;
}


void func_0014EDC0(void) {
    s8 temp_a2;

    reg_d0.h[0] = 0;
    reg_d0.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.sb[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= 0xFF0;
    reg_d1.h[0] *= 0x10;
    temp_a2 = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.sb[1] = temp_a2;
    reg_d2.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= 0xFF0;
    reg_d2.h[0] >>= 4;
    reg_d1.h[0] += reg_d2.h[0];
    *(u16 *)(reg_a5 + ((s32) reg_d0.h[0] >> 1)) = reg_d1.h[0];
}

void func_0014EE90(void) {
    s8 temp_a2;

    reg_d0.h[0] = 0;
    reg_d0.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.sb[1] = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d1.h[0] &= 0xFF0;
    reg_d1.h[0] *= 0x10;
    temp_a2 = *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.sb[1] = temp_a2;
    reg_d2.b[0] = (u8) *(s8 *)reg_a0;
    reg_a0 += 1;
    reg_d2.h[0] &= 0xFF0;
    reg_d2.h[0] >>= 4;
    reg_d1.h[0] += reg_d2.h[0];
    *(u16 *)(reg_a6 + ((s32) reg_d0.h[0] >> 1)) = reg_d1.h[0];
}

void func_0014EF60(void) {
    *(s8 *)(reg_a5 + 0x25) = *(s8 *)reg_a0;
    reg_a0 += 1;
}

void func_0014EF80(void) {
    *(s8 *)(reg_a6 + 0x1F) = *(s8 *)reg_a0;
    reg_a0 += 1;
}

void func_0014EFA0(void) {
    reg_d0.h[0] = g_side_scroll_x[0];
    *(u16 *)(reg_a6 + 4) -= reg_d0.h[0];
    reg_a0 += 1;
}

extern u8 enemy_move_end_requested_as_u8;


void func_0014EFD0(void) {
    enemy_move_end_requested_as_u8 = 1;
    enemy_remove();
}

void func_0014EFE0(void) {

}
