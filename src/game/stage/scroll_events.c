#include "common.h"
#include "entity.h"
#include "sdk/ps2sdk.h"

typedef void (*Fn)();
void func_0014CAE0(void);
extern u16 g_side_scroll_step[];
extern u16 g_stage;
extern u8 g_simulation_active;

extern u16 stage_ground_tables[];
extern u16 g_stage_x4;

void func_0014C3B0(void) {
    reg_a0 = (u8 *)(stage_ground_tables);
    reg_d0.h[0] = g_stage_x4;
    reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
    reg_a0 = (u8 *) reg_tmp.w;
}

extern u8 D_002526B0[];
extern u8 D_0029BF50[];
extern s32 D_0029C050_as_s32_a[];

void func_0014C450(void) {
    memset(D_0029BF50, 0, 0x104);
    reg_a0 = D_002526B0;
    reg_a0 += g_stage_x4;
    D_0029C050_as_s32_a[0] = *(s32 *)reg_a0;
}

extern u8 g_ground_no_draw;
extern u8 *reg_call_target_as_u8_p;

void func_0014C4B0(void) {
    u32 temp_s0;

    if ((g_simulation_active == 0) || (g_ground_no_draw == 0) || (g_stage != 2)) {
        reg_a6 = D_0029BF50;
        reg_d7.w = 7;
        do {
            if (ENTITY(reg_a6)->flags.b[1] != 0) {
                reg_d0.h[0] = g_side_scroll_step[0];
                ENTITY(reg_a6)->x.h -= reg_d0.h[0];
                reg_tmp.h[1] = ENTITY(reg_a6)->offset_x.h;
                reg_tmp.h[0] = ENTITY(reg_a6)->draw.h;
                reg_a1 = (u8 *)reg_tmp.w;
                reg_call_target_as_u8_p = reg_a1;
                temp_s0 = reg_d7.w;
                ((Fn)reg_call_target_as_u8_p)();
                reg_d7.w = temp_s0;
            }
            reg_a6 += 0x20;
        } while ((s16)(--reg_d7.h[0]) >= 0);
    }
}

typedef void (*Fn)(void);

extern u8 *D_0029C050[];
extern Fn reg_call_target_as_Fn;

void func_0014C590(void) {
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
    u32 t1;

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
    reg_a6 = (u8 *)D_0029BF50;
    reg_d7.w = 7;
loop_1:
    if (ENTITY(reg_a6)->flags.b[1] != 0) goto next_1;
    ENTITY(reg_a6)->flags.b[1] = 0x80;
    ENTITY(reg_a6)->y.h = reg_d1.h[1];
    ENTITY(reg_a6)->x.h = reg_d1.h[0];
    reg_a1 = D_0029C050[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a1 += reg_d0.h[0];
    reg_a1 = *(u8 **)reg_a1;
    reg_call_target_as_Fn = (Fn)reg_a1;
    reg_call_target_as_Fn();
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
    return;
next_1:
    reg_a6 += 0x20;
    t1 = reg_d7.h[0] - 1;
    reg_d7.h[0] = t1;
    if (((s64)((s64)(u16)t1 << 0x30) >> 0x30) >= 0) goto loop_1;
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

extern u16 g_scroll_line;
extern u8 D_0029C082[];

void func_0014C7B0(void) {
    reg_a0 = (u8 *)D_0029C082;
    reg_a1 = reg_a5 + 0xA;
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0xC);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 0xE);
    reg_a2 = (u8 *)reg_tmp.w;
    if (reg_a2 == 0) return;
    *(u16 *)(reg_a0 + 0x16) -= 1;
    if (0 >= (s16) *(u16 *)(reg_a0 + 0x16)) {
        reg_d0.h[0] = *(u16 *)(reg_a0 + 0x10);
        if ((s16) reg_d0.h[0] != -1) {
            *(u16 *)(reg_a0 + 0x10) -= 1;
            if (0 >= (s16) *(u16 *)(reg_a0 + 0x10)) {
                *(u16 *)(reg_a0 + 0xC) = 0U;
                *(u16 *)(reg_a0 + 0xE) = 0U;
                *(s16 *)(reg_a5 + 8) = 0;
                g_scroll_line = *(u16 *)(reg_a0 + 0x18);
                return;
            }
        }
        *(u16 *)(reg_a0 + 0x16) = (u16) *(u16 *)(reg_a0 + 0x14);
        reg_tmp.w = (u32)reg_a2;
        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
    }
}

extern s16 D_0029C080_as_s16_a[];
extern s16 D_0029C08E[];
extern s16 D_0029C090[];
extern u8 D_0029C09E[];
extern s16 D_0029C0AA[];
extern s16 D_0029C0AC[];

void func_0014C8A0(void) {
    u8 *var_a0;
    u32 temp_s0;
    u32 temp_s1;

    func_0014C3B0();
    memset(D_0029C080_as_s16_a, 0, 0x40);
    reg_a1 = (u8 *)D_0029C082;
    reg_d1.w = 1;
    var_a0 = (u8 *)(D_0029C09E);
    do {
        reg_tmp.h[1] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_tmp.h[0] = *(u16 *)reg_a0;
        reg_a0 += 2;
        reg_a2 = (u8 *)(reg_tmp.w);
        *(u16 *)(reg_a1 + 4) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a1 + 6) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a1 + 8) = *(u16 *)reg_a2;
        reg_a2 += 2;
        *(u16 *)(reg_a1 + 0xA) = *(u16 *)reg_a2;
        reg_a2 += 2;
        reg_tmp.w = (u32)reg_a2;
        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
        reg_a1 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d1.h[0]) >= 0);
    if (g_scroll_line != 0) {
        D_0029C080_as_s16_a[0] = 1;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0x10);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0x12);
        reg_a3 = (u8 *)reg_tmp.w;
        temp_s0 = (u32)reg_a3;
        reg_tmp.h[1] = *(u16 *)(reg_a5 + 0xA);
        reg_tmp.h[0] = *(u16 *)(reg_a5 + 0xC);
        reg_d7.w = 0;
        reg_a4 = (u8 *)reg_tmp.w;
        temp_s1 = (u32)reg_a4;
        do {
            func_0014CAE0();
            var_a0 = (u8 *) g_scroll_line;
            reg_d7.h[0] += 1;
        } while ((u32)var_a0 != reg_d7.h[0]);
        reg_tmp.w = temp_s0;
        reg_a4 = (u8 *)temp_s1;
        reg_a3 = (u8 *)temp_s0;
        *(u16 *)(reg_a5 + 0x10) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0x12) = (u16) reg_tmp.h[0];
        reg_tmp.w = (u32)reg_a4;
        *(u16 *)(reg_a5 + 0xA) = (u16) reg_tmp.h[1];
        *(u16 *)(reg_a5 + 0xC) = (u16) reg_tmp.h[0];
        reg_d0.w = 0;
        *(s16 *)(reg_a5 + 8) = 0;
        D_0029C08E[0] = 0;
        D_0029C090[0] = 0;
        D_0029C0AA[0] = 0;
        D_0029C0AC[0] = 0;
    }
    D_0029C080_as_s16_a[0] = 0;
}


void func_0014CAD0(void) {
    reg_d7.h[0] = g_scroll_line;
    func_0014CAE0();
}

extern u8 ground_event_routines[];
extern u16 D_0029C0BA[];
extern u16 D_0029C0BC[];
extern u16 D_0029C0BE[];

void func_0014CAE0(void) {
    u16 temp_a0;
    reg_a6 = (u8 *)D_0029C082;
    reg_d6.w = 1;
    do {
loop_1:
        reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
        reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
        reg_a1 = (u8 *)(reg_tmp.w);
        reg_d1.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (((s16)(reg_d1.h[0]) != -1) && ((reg_d1.h[0] & 0xFFFF) == reg_d7.h[0])) {
            reg_a1 += 2;
            temp_a0 = *(u16 *)reg_a1;
            reg_d2.h[0] = temp_a0;
            reg_a1 += 2;
            reg_a2 = (u8 *)ground_event_routines;
            reg_a2 += reg_d2.h[0];
            reg_tmp.h[1] = *(u16 *)reg_a2;
            reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
            reg_a2 = (u8 *) reg_tmp.w;
            reg_call_target = (Fn)(reg_a2);
            reg_call_target();
            reg_tmp.w = (u32)reg_a1;
            ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
            goto loop_1;
        }
        reg_a6 = (u8 *)D_0029C09E;
    } while ((s16)(--reg_d6.h[0]) >= 0);
    reg_d0.h[1] = D_0029C0BC[0];
    reg_d0.h[0] = D_0029C0BE[0];
    if (reg_d0.w != 0) {
        D_0029C0BA[0] -= 1;
        if (0 > (s16) D_0029C0BA[0]) {
            reg_a0 = (u8 *)reg_d0.w;
            reg_call_target = (Fn)((u8 *) reg_a0);
            reg_call_target();
            *(u32 *)D_0029C0BC = 0;
        }
    }
}

s32 sprite_palette_load();

void func_0014CC90(void) {
    u16 temp_a1;

    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = ENTITY(reg_a6)->x.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->offset_y.h;
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_a2 += 2;
    temp_a1 = *(u16 *)reg_a2;
    reg_tmp.h[0] = temp_a1;
    reg_a2 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    if ((u32)reg_a0 != -1U) {
        reg_d0.h[0] = *(u16 *)reg_a2;
        reg_a2 += 2;
        sprite_palette_load();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            ENTITY(reg_a6)->x.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void ground_event_01(void) {
    reg_a2 = reg_a5 + 0x10;
    if (reg_d6.h[0] != 0) {
        reg_a2 = reg_a5 + 0xA;
    }
    reg_tmp.h[1] = *(u16 *)reg_a2;
    reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
    reg_a3 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = reg_d0.h[0];
    reg_d2.h[0] = reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (s16) reg_d1.h[0] << 5;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] += reg_d0.h[0];
    reg_a3 += (s16) reg_d1.h[0];
    reg_tmp.w = (u32)reg_a3;
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->look.h = (u16) reg_tmp.h[0];
    reg_tmp.w = (u32)reg_a3;
    *(u16 *)reg_a2 = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a2 + 2) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_d0.h[0];
    reg_d0.h[0] += 1;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)->hit_y_plus.h = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
}

extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a2_as_u16_p;
extern s32 reg_a5_as_s32;

void ground_event_02(void) {
    reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x22);
    if (reg_d6.h[0] != 0) {
        reg_a2_as_u16_p = (u16 *)(reg_a5_as_s32 + 0x1C);
    }
    *reg_a2_as_u16_p = *reg_a1_as_u16_p;
    reg_a1_as_u16_p += 1;
}


void ground_event_03(void) {
    *(u16 *)(reg_a5 + 8) = 1;
    reg_d0.h[0] = g_scroll_line;
    reg_d0.h[0] += 4;
    *(u16 *)(reg_a6 + 0x18) = (u16) reg_d0.h[0];
}

extern u16 g_side_scroll_x_prev[];
extern u16 D_0029C080[];

void ground_event_04(void) {
    u16 *temp_a0;
    u16 temp_a1;

    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    temp_a1 = *(u16 *)reg_a1;
    temp_a0 = ((u16 *)reg_a1) + 1;
    reg_d1.h[0] = temp_a1;
    reg_a1 = (u8 *)temp_a0;
    if (D_0029C080[0] == 0) {
        reg_d1.h[0] -= 0x800;
        reg_d1.h[0] -= g_side_scroll_x_prev[0];
        func_0014C590();
    }
}

extern u8 ground_event_sound_routines[];

void ground_event_05(void) {
    u32 temp_a1;
    reg_d2.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = ENTITY(reg_a6)->offset_x.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->draw.h;
    reg_a2 = (u8 *)(reg_tmp.w);
loop_1:
    reg_d0.h[0] = *(u16 *)reg_a2;
    temp_a1 = reg_d0.h[0];
    reg_a2 += 2;
    if ((s16)(temp_a1) != -1) {
        reg_a3 = (u8 *)ground_event_sound_routines;
        reg_d0.h[0] = temp_a1 + temp_a1;
        reg_d0.h[0] += reg_d0.h[0];
        reg_tmp.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a3;
        reg_tmp.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a3 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a3;
        reg_a3 = (u8 *) reg_tmp.w;
        reg_call_target = (Fn)(reg_a3);
        reg_call_target();
        reg_d2.h[0] -= 1;
        if (reg_d2.h[0] == 0) {
            reg_tmp.w = (u32)reg_a2;
            ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[1];
            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[0];
        } else {
            goto loop_1;
        }
    }
}

void func_0014D0F0(void) {
    D_0029C0BA[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    D_0029C0BC[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    D_0029C0BE[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
}

void music_stop(void);

void ground_event_sound_01(void) {
    music_stop();
}

extern void music_fade_out(void);

void ground_event_sound_02(void) {
    reg_d1.h[0] = *(u16 *)reg_a2;
    reg_a2 += 2;
    music_fade_out();
}

extern s16 D_00299768[];
extern s16 D_0029976A[];
extern s16 D_0029976C_as_s16_a[];
extern s16 D_0029976E_as_s16_a[];

void ground_event_06(void) {
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    if (reg_d0.h[0] == 1) {
        D_00299768[0] = 1;
    }
    if (reg_d0.h[0] == 2) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
    }
    if (reg_d0.h[0] == 3) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
    }
    if (reg_d0.h[0] == 4) {
        D_00299768[0] = 1;
        D_0029976A[0] = 1;
        D_0029976C_as_s16_a[0] = 1;
        D_0029976E_as_s16_a[0] = 1;
    }
}

/* .bss (the compiler lays these out in reverse) */
s16 D_0029C090[24];
u16 D_0029C080[8];
u8 *D_0029C050[12];
u8 D_0029BF50[256];
