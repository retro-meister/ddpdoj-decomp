#include "common.h"
#include "entity.h"

void func_00171A30(void);
void func_00171B90(void);

extern u16 *reg_a0_as_u16_p;
extern u16 *reg_a1_as_u16_p;
extern u16 *reg_a6_as_u16_p;

void func_00171490(void) {
    reg_a1_as_u16_p = reg_a6_as_u16_p;
    reg_d0.h[0] = 0xF;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

extern u16 *reg_a4_as_u16_p;

void func_00171520(void) {
    reg_a1_as_u16_p = reg_a4_as_u16_p;
    do {
        *reg_a1_as_u16_p = *reg_a0_as_u16_p;
        reg_a0_as_u16_p += 1;
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 velocity_from_direction();

void func_00171580(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->hp.h;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
    velocity_from_direction();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) ENTITY(reg_a6)->hit_y_plus.h > (s32) reg_d0.h[0]) {
        ENTITY(reg_a6)->hp.h >>= 1;
        ENTITY(reg_a6)->hit_y_plus.h >>= 1;
        reg_d0.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        if (ENTITY(reg_a6)->misc.sh > (s16) reg_d0.h[0]) {
            ENTITY(reg_a6)->y.h = 0x3800U;
            ENTITY(reg_a6)->hit_y_plus.h = 0U;
            *(u16 *)reg_a4 -= 1;
        }
    }
}

void func_00171670(void) {
    reg_d0.h[0] = ENTITY(reg_a6)->hp.h;
    reg_d1.w = 0;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    velocity_from_direction();
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    reg_d2.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] -= reg_d2.h[0];
    if ((s16)(reg_d0.h[0]) < 0) {
        reg_d0.h[0] *= 0xFFFF;
    }
    if ((s32) ENTITY(reg_a6)->hit_y_plus.h > (s32) reg_d0.h[0]) {
        ENTITY(reg_a6)->hp.h >>= 1;
        ENTITY(reg_a6)->hit_y_plus.h >>= 1;
        reg_d0.h[0] = ENTITY(reg_a6)->hit_y_plus.h;
        if (ENTITY(reg_a6)->misc.sh > (s16) reg_d0.h[0]) {
            ENTITY(reg_a6)->x.h = (u16) ENTITY(reg_a6)->hit_x_minus.h;
            ENTITY(reg_a6)->hit_y_plus.h = 0U;
            *(u16 *)reg_a4 -= 1;
        }
    }
}

s32 entity_draw_with_bullets_keep();
s32 sprite_draw_with_bullets_keep();

void func_00171770(void) {
    entity_draw_with_bullets_keep();
    reg_d0.h[0] = 0x3800;
    reg_d0.h[0] -= ENTITY(reg_a6)->y.h;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += ENTITY(reg_a6)->offset_x.h;
    reg_d1.h[1] += ENTITY(reg_a6)->offset_y.h;
    reg_d1.h[1] += reg_d0.h[0];
    reg_d2.h[1] = ENTITY(reg_a6)->draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_d3.h[0] = ENTITY(reg_a6)->look.h;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d2.w = 0x11C6;
    sprite_draw_with_bullets_keep();
}

void func_00171820(void) {
    entity_draw_with_bullets_keep();
    reg_d0.h[0] = 0x3800;
    reg_d0.h[0] -= ENTITY(reg_a6)->y.h;
    reg_d0.h[1] = 0x1C00;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[1] -= ENTITY(reg_a6)->x.h;
    reg_d0.h[1] += reg_d0.h[1];
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += ENTITY(reg_a6)->offset_x.h;
    reg_d1.h[0] += reg_d0.h[1];
    reg_d1.h[1] += ENTITY(reg_a6)->offset_y.h;
    reg_d1.h[1] += reg_d0.h[0];
    reg_d2.h[1] = ENTITY(reg_a6)->draw.h;
    reg_d2.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_d3.h[0] = ENTITY(reg_a6)->look.h;
    reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
    reg_d2.w = 0x11C4;
    sprite_draw_with_bullets_keep();
}

extern s16 D_0028E798;
extern s16 D_0028E79C;
extern s16 D_0028E7A0;
extern s16 D_002BB458_as_s16_a[];
extern s16 D_002BB45A[];
extern s16 D_002BB45C[];
extern s16 D_002BB45E[];
extern s16 D_002BB460[];
extern u8 D_002BB470[];
void func_00171910(void) {
    s32 var_a1;
    u8 *temp_a2;

    var_a1 = 0;
    do {
        temp_a2 = D_002BB470 + var_a1;
        (*(s8 *)((u8 *)(temp_a2) + (0))) = 0;
        var_a1 += 8;
        (*(s8 *)((u8 *)(temp_a2) + (1))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (2))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (3))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (4))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (5))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (6))) = 0;
        (*(s8 *)((u8 *)(temp_a2) + (7))) = 0;
    } while (var_a1 < 0x40);
    D_0028E798 = 0;
    D_002BB458_as_s16_a[0] = 0;
    D_0028E79C = 0;
    D_002BB45A[0] = 0;
    D_0028E7A0 = 0;
    D_002BB45C[0] = 0;
    D_002BB45E[0] = 0;
    D_002BB460[0] = 0;
}

void func_00171990(void) {
    D_0028E798 = 1;
}

void func_001719A0(void) {
    D_0028E7A0 = 1;
}

extern u16 D_0028E7A0_as_u16;

void func_001719B0(void) {
    if (D_0028E7A0_as_u16 != 0) {
        cond_flag = 1;
        return;
    }
    cond_flag = 0;
}

extern u16 D_0028E79C_as_u16;
extern s32 D_002BB458[];
extern s32 D_002BB470_as_s32_a[];

void func_001719D0(void) {
    reg_a6 = (u8 *)D_002BB470_as_s32_a;
    reg_a4 = (u8 *)D_002BB458;
    if (D_0028E79C_as_u16 != 0) {
        func_00171A30();
        return;
    }
    if (D_0028E7A0_as_u16 != 0) {
        func_00171B90();
    }
}

s32 sprite_palette_load();
extern u8 g_default_sprite_palette[];
extern u8 D_0026B170[];
extern u8 D_0026B180[];
extern u8 D_0028DAC0[];
extern s32 D_0028DC20;
extern u16 D_0028E798_as_u16;
extern u16 g_stage_x2;

void func_00171A30(void) {
    s32 temp_a1;
    s32 var_v0;
    u16 temp_a2;

    if (ENTITY(reg_a6)->flags.sh >= 0) {
        reg_a0 = (u8 *)D_0026B180;
        func_00171490();
        reg_a0 = (u8 *)D_0028DAC0;
        var_v0 = (s32) D_0028DC20 >> 1;
        if (D_0028DC20 < 0) {
            var_v0 = (s32) (D_0028DC20 + 1) >> 1;
        }
        reg_d0.w = var_v0 - 1;
        func_00171520();
        reg_d0.h[0] = g_stage_x2;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(D_0026B170 + temp_a1);
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)g_default_sprite_palette;
        sprite_palette_load();
        return;
    }
    if (*(u16 *)reg_a4 == 0) {
        if (D_0028E798_as_u16 != 0) {
            *(s16 *)(reg_a4 + 2) = 1;
            D_0028E79C = 0;
            ENTITY(reg_a6)->flags.sh = 0;
            return;
        }
        reg_d1.w = 0;
        reg_d2.w = 0x10AA;
        reg_d3.h[0] = ENTITY(reg_a6)->look.h;
        reg_d4.h[0] = ENTITY(reg_a6)->attr.h;
        sprite_draw_with_bullets_keep();
        return;
    }
    if (ENTITY(reg_a6)->hit_y_plus.h != 0) {
        func_00171580();
    }
    func_00171770();
    reg_a6 += 0x20;
    if (ENTITY(reg_a6)->hit_y_plus.h != 0) {
        func_00171670();
    }
    func_00171820();
}

s32 func_001ABB80();
s32 func_001ABD80();
extern u8 D_0026B1C0[];
extern u8 D_0026B1D0[];
extern u8 D_0028DAC8[];
extern u8 g_game_frame_ran;
extern s16 g_boss_hyper_wait_as_s16;
extern u16 g_p2_hyper_active;
extern u16 g_p1_hyper_active;
extern u16 g_stage;
extern u8 D_0028ED5C;
extern u8 g_replay_mode;
extern u8 g_simulation_active;
extern s16 g_player2[];
extern s16 g_player1[];

void func_00171B90(void) {
    s32 temp_a1;
    u16 temp_a0;
    u16 temp_a2;
    u16 temp_v1;
    u16 temp_v1_2;
    u16 var_a0;
    u8 *var_a0_2;

    if (ENTITY(reg_a6)->flags.sh >= 0) {
        reg_a0 = (u8 *)D_0026B1D0;
        func_00171490();
        reg_a0 = (u8 *)D_0028DAC8;
        reg_d0.w = 1;
        func_00171520();
        reg_d0.h[0] = g_stage_x2;
        temp_a2 = reg_d0.h[0];
        temp_a1 = temp_a2 & ~1;
        reg_d0.h[0] = *(u16 *)(D_0026B1C0 + temp_a1);
        ENTITY(reg_a6)->attr.b.palette = (u8) reg_d0.b[0];
        *(u8 *)(reg_a6 + 0x3C) = (u8) reg_d0.b[0];
        reg_a0 = (u8 *)g_default_sprite_palette;
        sprite_palette_load();
    }
    var_a0 = 1;
    if (*(u16 *)reg_a4 == 0) {
        *(s16 *)(reg_a4 + 2) = 1;
        g_boss_hyper_wait_as_s16 = 0;
        if ((g_replay_mode != 2) || (g_stage != 0)) {
            if ((g_player1[0] < 0) && (g_p1_hyper_active == 0)) {
                func_001ABB80();
            }
            if ((g_player2[0] < 0) && (g_p2_hyper_active == 0)) {
                func_001ABD80();
            }
        }
        D_0028E7A0 = 0;
        ENTITY(reg_a6)->flags.sh = 0;
        return;
    }
    if ((g_game_frame_ran != 0) && ((var_a0 = g_replay_mode, (var_a0 != 2)) || (D_0028ED5C == 0)) && ((g_simulation_active == 0) || (D_0028ED5C == 0))) {
        var_a0 = ENTITY(reg_a6)->hit_y_plus.h;
        if (var_a0 != 0) {
            temp_v1 = ENTITY(reg_a6)->hit_y_minus.h;
            if (temp_v1 != 0) {
                ENTITY(reg_a6)->hit_y_minus.h = (u16) (temp_v1 - 1);
                goto block_25;
            }
            if (var_a0 != 0) {
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
                velocity_from_direction();
                ENTITY(reg_a6)->y.h += reg_d2.h[0];
                reg_d2.h[0] = ENTITY(reg_a6)->hit_x_plus.h;
                reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    ENTITY(reg_a6)->hit_y_plus.sh = 0;
                    *(u16 *)reg_a4 -= 1;
                }
                goto block_25;
            }
        }
    } else {
block_25:
        func_00171770();
    }
    var_a0_2 = (u8 *)(reg_a6 + 0x20);
    reg_a6 = var_a0_2;
    if ((g_game_frame_ran != 0) && ((var_a0_2 = (void *) g_replay_mode, (var_a0_2 != (void *)2)) || (D_0028ED5C == 0)) && ((g_simulation_active == 0) || (D_0028ED5C == 0))) {
        temp_a0 = ENTITY(reg_a6)->hit_y_plus.h;
        if (temp_a0 != 0) {
            temp_v1_2 = ENTITY(reg_a6)->hit_y_minus.h;
            if (temp_v1_2 != 0) {
                ENTITY(reg_a6)->hit_y_minus.h = (u16) (temp_v1_2 - 1);
                goto block_35;
            }
            if (temp_a0 != 0) {
block_35:
                reg_d1.w = 0;
                reg_d0.w = 0x30;
                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                velocity_from_direction();
                ENTITY(reg_a6)->x.h += reg_d3.h[0];
                var_a0_2 = (u8 *)(reg_a6);
                reg_d2.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (0x16)));
                reg_d0.h[0] = (*(u16 *)((u8 *)(var_a0_2) + (4)));
                reg_d0.h[0] -= reg_d2.h[0];
                if ((s16)(reg_d0.h[0]) < 0) {
                    reg_d0.h[0] *= 0xFFFF;
                }
                if ((s32) reg_d0.h[0] < 0x400) {
                    (*(u16 *)((u8 *)(var_a0_2) + (0x10))) = 0U;
                    *(u16 *)reg_a4 -= 1;
                }
                goto block_39;
            }
        }
    } else {
block_39:
        func_00171820();
    }
}
