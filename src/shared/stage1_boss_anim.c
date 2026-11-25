#include "common.h"
#include "entity.h"

void stage1_boss_gatling_spin(void);

extern u16 *reg_a4_as_u16_p;

void stage1_boss_anim_clear(void) {
    *reg_a4_as_u16_p = 0;
}

s32 rng_next_unsigned();                            /* extern */

void stage1_boss_right_hover_start(void) {
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 5) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 4) = (u8) reg_d0.b[0];
}

s32 velocity_from_dir256();

void stage1_boss_right_hover(void) {
    u32 temp_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 2;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 5);
    velocity_from_dir256();
    temp_a0 = ENTITY(reg_a6)[1].offset_y.h;
    ENTITY(reg_a6)[1].offset_y.h = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 4);
    velocity_from_dir256();
    ENTITY(reg_a6)[1].offset_x.h += reg_d3.h[0];
    *(u8 *)(reg_a4 + 5) += 2;
    *(u8 *)(reg_a4 + 4) += 1;
}

s32 rng_next_unsigned();                            /* extern */

void stage1_boss_left_hover_start(void) {
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 5) = (u8) reg_d0.b[0];
    rng_next_unsigned();
    *(u8 *)(reg_a4 + 4) = (u8) reg_d0.b[0];
}

void stage1_boss_left_hover(void) {
    u32 temp_a0;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_d1.w = 0;
    reg_d0.w = 2;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 5);
    velocity_from_dir256();
    temp_a0 = ENTITY(reg_a6)[3].offset_y.h;
    ENTITY(reg_a6)[3].offset_y.h = (u16) (temp_a0 + reg_d2.h[0]);
    reg_d0.w = 1;
    reg_d1.w = 0;
    reg_d1.b[0] = *(u8 *)(reg_a4 + 4);
    velocity_from_dir256();
    ENTITY(reg_a6)[3].offset_x.h += reg_d3.h[0];
    *(u8 *)(reg_a4 + 5) += 2;
    *(u8 *)(reg_a4 + 4) += 1;
}

void stage1_boss_right_rotor_start(void) {
    reg_a4_as_u16_p[1] = 0;
}

void stage1_boss_right_rotor(void) {
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[1].draw.h += 4;
        if (ENTITY(reg_a6)[1].draw.sh > 0xc) {
            ENTITY(reg_a6)[1].draw.h = 0U;
        }
    }
}

void stage1_boss_left_rotor_start(void) {
    reg_a4_as_u16_p[1] = 0;
}

void stage1_boss_left_rotor(void) {
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[3].draw.h += 4;
        if (ENTITY(reg_a6)[3].draw.sh > 0xc) {
            ENTITY(reg_a6)[3].draw.h = 0U;
        }
    }
}

s32 explosion_spawn();

void func_001B26F0(arg2)
    u16 *arg2;
{
    u16 *var_a2;
    u16 temp_a1;

    var_a2 = (u16 *)(arg2);
loop_1:
    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        var_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(var_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 0xC;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0;
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        if (reg_d0.h[0] != 0) {
            reg_d0.h[0] -= 1;
            *(u8 *)(reg_a4 + 2) |= ((1 << (s8) reg_d0.b[0]) & 0xFF);
        }
        goto loop_1;
    }
}

s32 rng_next();

void func_001B2830(void) {
    u16 *temp_a2;
    u16 temp_a1;

    temp_a1 = *(u16 *)reg_a1;
    reg_d1.h[0] = temp_a1;
    reg_a1 += 2;
    if ((s16) reg_d1.h[0] != -1) {
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        explosion_spawn();
        reg_d0.h[0] = *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
        *(u16 *)(reg_a0 + 0x18) = (u16) reg_d1.h[0];
        *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
        temp_a2 = (u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)(temp_a2);
        *(u16 *)(reg_a0 + 2) = (u16) reg_d2.h[1];
        *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
        *(s16 *)(reg_a0 + 0x1E) = 4;
        *(s16 *)(reg_a0 + 0x12) = 0;
        *(s16 *)(reg_a0 + 0x14) = 0x400;
        *(u16 *)(reg_a0 + 0x1A) = (u16) *(u16 *)reg_a1;
        reg_a1 += 2;
        rng_next();
        *(u8 *)(reg_a0 + 0x1A) += reg_d0.b[0];
        func_001B2830();
    }
}

void stage1_boss_right_wreck_start(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 8;
    *(s16 *)(reg_a4 + 6) = 5;
    *(s16 *)(reg_a4 + 8) = 7;
    *(s16 *)(reg_a4 + 0xA) = 0x1008;
    *(s16 *)(reg_a4 + 0xC) = 0;
}

s32 boss_part_hide();
s32 sfx_explosion_ground_small();
s32 sfx_explosion_ground_medium();
extern u8 D_0026DBD0[];
extern u8 D_0026DC40[];
extern u16 g_side_scroll_step[];

void stage1_boss_right_wreck(void) {
    u32 temp_a1;
    u8 temp_a0;
    u8 temp_v1;

    reg_d0.h[0] = g_side_scroll_step[0];
    temp_a1 = ENTITY(reg_a6)[1].x.h;
    ENTITY(reg_a6)[1].x.h = (u16) (temp_a1 - reg_d0.h[0]);
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        sfx_explosion_ground_small();
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = (u8 *)D_0026DC40;
        func_001B2830();
        *(s16 *)reg_a4 = 0;
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            temp_v1 = *(u8 *)(reg_a4 + 0xA);
            if (temp_v1 != 0) {
                *(u8 *)(reg_a4 + 0xA) = (u8) (temp_v1 - 1);
            }
            *(u16 *)(reg_a4 + 0xC) += 0x10;
            ENTITY(reg_a6)[2].offset_y.h -= 0x800;
            ENTITY(reg_a6)[2].offset_x.h -= 0x800;
            if (0 > (s16) ENTITY(reg_a6)[2].offset_x.h) {
                reg_tmp.w = 0;
                ENTITY(reg_a6)[2].offset_y.h = (u16) reg_tmp.h[1];
                ENTITY(reg_a6)[2].offset_x.h = (u16) reg_tmp.h[0];
                *(u16 *)(reg_a4 + 0xC) = 0U;
                *(u8 *)(reg_a4 + 3) = 2U;
                reg_d0.w = 0;
                boss_part_hide();
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
        sfx_explosion_ground_medium();
        reg_d2.h[1] = ENTITY(reg_a6)[1].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[1].x.h;
        reg_a1 = (u8 *)D_0026DBD0;
        func_001B26F0();
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    ENTITY(reg_a6)[1].y.h -= reg_d0.h[0];
}

void stage1_boss_left_wreck_start(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 8;
    *(s16 *)(reg_a4 + 6) = 5;
    *(s16 *)(reg_a4 + 8) = 7;
    *(s16 *)(reg_a4 + 0xA) = 0x1008;
    *(s16 *)(reg_a4 + 0xC) = 0;
}

extern u8 D_0026DC80[];
extern u8 D_0026DCF0[];

void stage1_boss_left_wreck(void) {
    u8 temp_a0;
    u8 temp_v1;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a6);
    reg_d0.h[0] = g_side_scroll_step[0];
    (*(u16 *)((u8 *)(var_a1) + (0x64))) -= reg_d0.h[0];
    if (*(u8 *)(reg_a4 + 2) & 4) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
        *(u8 *)(reg_a4 + 9) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
            reg_d0.w = 0x10;
            explosion_spawn();
            *(s16 *)(reg_a0 + 0x1E) = 4;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            rng_next();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[3].y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)[3].x.h);
            *(s16 *)(reg_a0 + 4) = (s16) var_a1;
            reg_tmp.w = 0xFDFFFC00;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    if (*(u8 *)(reg_a4 + 2) & 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.w = 0x10;
            explosion_spawn();
            *(s16 *)(reg_a0 + 0x1E) = 4;
            *(s8 *)(reg_a0 + 0x1B) = 0x10;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[3].y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)[3].x.h);
            *(s16 *)(reg_a0 + 4) = (s16) var_a1;
            reg_tmp.w = 0xF2000200;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    if (*(u8 *)(reg_a4 + 2) & 2) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
        *(u8 *)(reg_a4 + 7) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.w = 6;
            explosion_spawn();
            *(s16 *)(reg_a0 + 0x1E) = 8;
            *(s8 *)(reg_a0 + 0x1B) = 0xC;
            rng_next();
            reg_d0.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)[3].y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)[3].x.h);
            *(s16 *)(reg_a0 + 4) = (s16) var_a1;
            reg_tmp.w = 0xF5FFFC00;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        sfx_explosion_ground_small();
        reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
        reg_a1 = D_0026DCF0;
        func_001B2830();
        *(s16 *)reg_a4 = 0;
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            temp_v1 = *(u8 *)(reg_a4 + 0xA);
            if (temp_v1 != 0) {
                *(u8 *)(reg_a4 + 0xA) = (u8) (temp_v1 - 1);
            }
            *(u16 *)(reg_a4 + 0xC) += 0x10;
            ENTITY(reg_a6)[4].offset_y.h -= 0x800;
            ENTITY(reg_a6)[4].offset_x.h -= 0x800;
            if (0 > (s16) ENTITY(reg_a6)[4].offset_x.h) {
                reg_tmp.w = 0;
                ENTITY(reg_a6)[4].offset_y.h = (u16) reg_tmp.h[1];
                ENTITY(reg_a6)[4].offset_x.h = (u16) reg_tmp.h[0];
                *(u16 *)(reg_a4 + 0xC) = 0U;
                *(u8 *)(reg_a4 + 3) = 2U;
                reg_d0.w = 1;
                boss_part_hide();
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
        sfx_explosion_ground_medium();
        reg_d2.h[1] = ENTITY(reg_a6)[3].y.h;
        reg_d2.h[0] = ENTITY(reg_a6)[3].x.h;
        reg_a1 = D_0026DC80;
        func_001B26F0();
    }
    reg_d0.h[0] = *(u16 *)(reg_a4 + 0xC);
    ENTITY(reg_a6)[3].y.h -= reg_d0.h[0];
}

void stage1_boss_body_explode_start(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 8;
    *(s16 *)(reg_a4 + 6) = 0x1209;
    *(s16 *)(reg_a4 + 0xA) = 0x20;
    *(s16 *)(reg_a4 + 0xC) = 0xC;
    *(s16 *)(reg_a4 + 0xE) = 0;
    *(s16 *)(reg_a4 + 0x10) = 0;
    *(s16 *)(reg_a4 + 0x12) = 0x1010;
    *(s16 *)(reg_a4 + 0x14) = 0;
}

typedef void (*Fn)();

s32 boss_slots_end();
s32 boss_flash_start();
s32 boss_flash_running();
s32 explosion_burst_large();
s32 explosion_burst_small();
s32 func_0013B2E0();
s32 sfx_explosion_boss();
s32 rng_next_unsigned();
extern u8 D_0026DD30[];
extern u16 D_0026DD50[];
extern u16 D_0026DDC0[];
extern u16 D_0026DE00[];
extern u16 D_0026DF00[];
extern u8 D_0026DF70[];
extern u8 D_0026DFC0[];
extern u8 g_slowdown_timer;

void stage1_boss_body_explode(void) {
    u16 *temp_a3_2;
    u16 temp_a0_3;
    u16 temp_a0_4;
    u16 temp_a0_6;
    u16 temp_a0_7;
    u16 temp_a1;
    u16 temp_a2;
    u16 temp_a3;
    u16 temp_v1;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_5;
    u8 *var_a1;

    var_a1 = (u8 *)(reg_a4);
    temp_a0 = (*(u8 *)((u8 *)(var_a1) + (3)));
    if (temp_a0 == 6) {
        (*(u16 *)((u8 *)(var_a1) + (0xA))) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            boss_slots_end();
            *(s16 *)reg_a4 = 0;
        }
        return;
    }
    if ((*(u8 *)((u8 *)(var_a1) + (2))) & 2) {
        reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a1) + (7)));
        (*(u8 *)((u8 *)(var_a1) + (7))) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
            reg_d0.w = 5;
            explosion_spawn();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x14;
            rng_next();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)->x.h);
            *(u16 *)(reg_a0 + 4) = (u16) var_a1;
            reg_tmp.w = 0xF8000000;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    if (*(u8 *)(reg_a4 + 2) & 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
        *(u8 *)(reg_a4 + 5) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
            reg_d0.w = 0x10;
            explosion_spawn();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x18;
            rng_next();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a1 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a1;
            reg_tmp.w = 0xE8000400;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
            reg_d0.w = 0x10;
            explosion_spawn();
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s8 *)(reg_a0 + 0x1B) = 0x14;
            rng_next();
            *(u8 *)(reg_a0 + 0x1A) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            var_a1 = (u8 *)((void *) ENTITY(reg_a6)->x.h);
            *(u16 *)(reg_a0 + 4) = (u16) var_a1;
            reg_tmp.w = 0xF3FFF800;
            *(u16 *)(reg_a0 + 0x26) = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a0 + 0x28) = (u16) reg_tmp.h[0];
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 5) {
        sfx_explosion_boss();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_a1 = (u8 *)(D_0026DF00);
        func_001B2830();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x40;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0xF8000A00;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        explosion_burst_large();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0xB0;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        reg_d2.w -= 0x800;
        explosion_burst_large();
        rng_next();
        reg_d0.h[0] = (s16) reg_d0.h[0] * 4;
        reg_d1.b[0] = reg_d0.b[0];
        reg_d1.b[0] += 0x80;
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_d2.w += 0xF4000000;
        reg_d3.h[0] = 0xC;
        reg_d0.h[0] = 0;
        explosion_burst_large();
        var_a1 = (u8 *)((void *)0x80);
        *(u16 *)(reg_a4 + 0xA) = 0x80U;
        *(u8 *)(reg_a4 + 3) = 6U;
    }
    temp_a0_5 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_5 == 4) {
        boss_flash_running();
        if (cond_flag == 0) {
            g_slowdown_timer = 0xA;
            reg_a0 = D_0026DFC0;
            func_0013B2E0();
            reg_d0.w = 2;
            boss_part_hide();
            reg_d0.w = 4;
            boss_part_hide();
            reg_d0.w = 5;
            boss_part_hide();
            *(u8 *)(reg_a4 + 3) = 5U;
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 3) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
        *(u8 *)(reg_a4 + 0x13) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
            reg_a0 = D_0026DD30;
            temp_a0_6 = *(u16 *)(reg_a4 + 0x14);
            reg_a0 += temp_a0_6;
            reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x14);
            ((Fn)*(u32 *)((u8 *)D_0026DD30 + (reg_tmp.h[0] & ~3)))();
            *(u16 *)(reg_a4 + 0x14) += 4;
            *(u16 *)(reg_a4 + 0x14) &= 0x1F;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            reg_a1 = (u8 *)(D_0026DE00);
            reg_a1 += *(u16 *)(reg_a4 + 0xE);
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            explosion_spawn();
            reg_d0.h[0] = *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
            *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
            temp_a3 = ENTITY(reg_a6)->x.h;
            *(u16 *)(reg_a0 + 4) = temp_a3;
            *(s16 *)(reg_a0 + 0x1E) = 0xC;
            *(s16 *)(reg_a0 + 0x12) = 0;
            *(s16 *)(reg_a0 + 0x14) = 0x800;
            *(u16 *)(reg_a0 + 0x1A) = *(u16 *)reg_a1;
            reg_a1 += 2;
            *(u16 *)(reg_a4 + 0xE) += 0x10;
            if (*(u16 *)(reg_a4 + 0xE) == 0x100) {
                *(u16 *)(reg_a4 + 0xE) = 0U;
                *(u8 *)(reg_a4 + 3) = 4U;
                reg_d0.h[0] = 0x12;
                boss_flash_start();
                sfx_explosion_ground_medium();
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 2) {
        temp_v1 = *(u16 *)(reg_a4 + 0xA);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 0xA) = (u16) (temp_v1 - 1);
        } else {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0x13);
            *(u8 *)(reg_a4 + 0x13) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0x13) = (u8) *(u8 *)(reg_a4 + 0x12);
                reg_a0 = D_0026DD30;
                temp_a0_7 = *(u16 *)(reg_a4 + 0x14);
                reg_a0 += temp_a0_7;
                reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x14);
                ((Fn)*(u32 *)((u8 *)D_0026DD30 + (reg_tmp.h[0] & ~3)))();
                *(u16 *)(reg_a4 + 0x14) += 4;
                *(u16 *)(reg_a4 + 0x14) &= 0x1F;
            }
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
            *(u8 *)(reg_a4 + 0xD) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
                reg_a1 = (u8 *)(D_0026DE00);
                reg_a1 += *(u16 *)(reg_a4 + 0xE);
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                explosion_spawn();
                reg_d0.h[0] = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u8 *)(reg_a0 + 0x1D) = (u8) reg_d0.b[0];
                *(u16 *)(reg_a0 + 0x26) = (u16) *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a0 + 0x28) = (u16) *(u16 *)reg_a1;
                temp_a3_2 = (u16 *)(reg_a1 + 2);
                reg_a1 = (u8 *)(temp_a3_2);
                *(u16 *)(reg_a0 + 2) = (u16) ENTITY(reg_a6)->y.h;
                temp_a2 = ENTITY(reg_a6)->x.h;
                *(u16 *)(reg_a0 + 4) = temp_a2;
                *(s16 *)(reg_a0 + 0x1E) = 0xC;
                *(s16 *)(reg_a0 + 0x12) = 0;
                *(s16 *)(reg_a0 + 0x14) = 0x800;
                *(u16 *)(reg_a0 + 0x1A) = *(u16 *)reg_a1;
                reg_a1 += 2;
                *(u16 *)(reg_a4 + 0x10) += 1;
                *(u16 *)(reg_a4 + 0x10) &= 1;
                if (*(u16 *)(reg_a4 + 0x10) == 0) {
                    g_slowdown_timer = 0xA;
                    reg_a0 = D_0026DF70;
                    func_0013B2E0();
                    rng_next_unsigned();
                    reg_d1.b[0] = reg_d0.b[0];
                    reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                    reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                    reg_d3.h[0] = 0xC;
                    reg_d0.h[0] = 0;
                    explosion_burst_small();
                    sfx_explosion_ground_small();
                }
                *(u16 *)(reg_a4 + 0xE) += 0x10;
                if (*(u16 *)(reg_a4 + 0xE) == 0x80) {
                    *(u16 *)(reg_a4 + 0xE) = 0U;
                    *(u8 *)(reg_a4 + 3) = 3U;
                    *(u16 *)(reg_a4 + 0xC) = 4;
                    *(u8 *)(reg_a4 + 2) = 0U;
                    *(u16 *)(reg_a4 + 0x12) = 0x808;
                }
            }
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 1) {
        *(u16 *)(reg_a4 + 0xA) -= 1;
        if (*(u16 *)(reg_a4 + 0xA) == 0) {
            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
            reg_a1 = (u8 *)(D_0026DDC0);
            func_001B26F0();
            *(u8 *)(reg_a4 + 3) = 2U;
            *(u16 *)(reg_a4 + 0xA) = 0x80U;
            *(u8 *)(reg_a4 + 2) |= 2;
            reg_d0.w = 3;
            boss_part_hide();
        }
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
        sfx_explosion_ground_medium();
        reg_d2.h[1] = ENTITY(reg_a6)->y.h;
        reg_d2.h[0] = ENTITY(reg_a6)->x.h;
        reg_a1 = (u8 *)(D_0026DD50);
        func_001B26F0();
    }
}


void stage1_boss_gatling_spin_start(void) {
    stage1_boss_gatling_spin();
}

void stage1_boss_gatling_spin(void) {
    u8 temp_a0;

    reg_tmp.b[0] = (ENTITY(reg_a6)[5].look.b.size);
    (ENTITY(reg_a6)[5].look.b.size) -= 1;
    if ((s32)reg_tmp.b[0] <= 0) {
        (ENTITY(reg_a6)[5].look.b.size) = (ENTITY(reg_a6)[5].look.b.palette);
        temp_a0 = (ENTITY(reg_a6)[5].look.b.palette);
        if (temp_a0 != 2) {
            if ((s8)temp_a0 >= 2) {
                (ENTITY(reg_a6)[5].look.b.palette) = temp_a0 - 1;
            } else {
                (ENTITY(reg_a6)[5].look.b.palette) = temp_a0 + 1;
            }
        }
        (ENTITY(reg_a6)[5].draw.h) += 4;
        if ((s16)(ENTITY(reg_a6)[5].draw.h) >= 0x1C) {
            (ENTITY(reg_a6)[5].draw.h) = 0;
        }
    }
}

void stage1_boss_right_open_start(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    reg_a4[7] = 0;
}

s32 boss_animation_start();
s32 boss_animation_stop();

void stage1_boss_right_open() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (ENTITY(reg_a6)[1].draw.h == 0)) {
        reg_d0.w = 2;
        boss_animation_stop();
        ENTITY(reg_a6)[1].draw.h = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[2].sprite.h += 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority += 2;
            ENTITY(reg_a6)[1].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

typedef struct WorkRegA4 {
    u8 pad0[2];
    u16 unk2;
    u8 pad4[3];
    u8 unk7;
} WorkRegA4;


void stage1_boss_left_open_start(void) {
    extern WorkRegA4 *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void stage1_boss_left_open() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (ENTITY(reg_a6)[3].draw.h == 0)) {
        reg_d0.w = 3;
        boss_animation_stop();
        ENTITY(reg_a6)[3].draw.h = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[4].sprite.h += 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority += 2;
            ENTITY(reg_a6)[3].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}


void stage1_boss_right_rotor_opened_start(void) {
    *(u16*)(reg_a4 + 2) = 0;
}

void stage1_boss_right_rotor_opened(void) {
    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[1].draw.h += 4;
        if (ENTITY(reg_a6)[1].draw.sh > 0x74) {
            ENTITY(reg_a6)[1].draw.h = 0x68U;
        }
    }
}

extern s16 *reg_a4_as_s16_p;

void stage1_boss_left_rotor_opened_start(void) {
    reg_a4_as_s16_p[1] = 0;
}

void stage1_boss_left_rotor_opened(void) {
    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[3].draw.h += 4;
        if (ENTITY(reg_a6)[3].draw.sh > 0x74) {
            ENTITY(reg_a6)[3].draw.h = 0x68U;
        }
    }
}

s32 boss_attack_start();
s32 func_001713B0();
s32 rng_next_bit();
extern u8 D_0026DFE0[];
extern u8 D_0028DC28[];
extern u8 D_0028DC30[];

void stage1_boss_spin_start(void) {
    ENTITY(reg_a6)[8].hit_x_plus.sh = 0;
    *(u8 *)(reg_a4 + 3) = 1U;
    rng_next_bit();
    if (reg_d0.h[0] == 0) {
        *(u8 *)(reg_a4 + 3) = 0xFFU;
    }
    *(u8 *)(reg_a4 + 2) = (u8) *(u8 *)(reg_a4 + 3);
    *(s16 *)(reg_a4 + 4) = 0x4040;
    *(s8 *)(reg_a4 + 7) = 0;
    *(s16 *)(reg_a4 + 8) = 0x60;
    reg_tmp.w = 0;
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xC) = (u16) reg_tmp.h[0];
    reg_tmp.w = 0;
    *(u16 *)(reg_a4 + 0xE) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a4 + 0x12) = 0;
    func_001713B0();
    reg_d2.w = 0;
    reg_d2.b[0] = *(D_0028DC28 + reg_d0.h[0]);
    reg_d2.b[0] -= ENTITY(reg_a6)[8].hit_y_minus.b[1];
    if ((s8) reg_d2.b[0] < 5) {
        reg_d2.b[0] = 4;
    }
    ENTITY(reg_a6)[8].hit_y_minus.b[1] += 1;
    if ((s8) ENTITY(reg_a6)[8].hit_y_minus.b[1] > 4) {
        ENTITY(reg_a6)[8].hit_y_minus.b[1] = 4U;
    }
    reg_d3.w = 0;
    reg_d3.b[0] = *(D_0028DC30 + reg_d0.h[0]);
    reg_d3.b[0] -= ENTITY(reg_a6)[8].hit_y_minus.b[0];
    if ((s8) reg_d3.b[0] < 0x10) {
        reg_d3.b[0] = 0xF;
    }
    ENTITY(reg_a6)[8].hit_y_minus.b[0] += 1;
    if ((s8) ENTITY(reg_a6)[8].hit_y_minus.b[0] > 0x10) {
        ENTITY(reg_a6)[8].hit_y_minus.b[0] = 0x10U;
    }
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 = (u8 *)D_0026DFE0;
    reg_d4.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d0.w = 5;
    boss_attack_start();
    *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
    *(u8 *)(reg_a0 + 0xA) = (u8) reg_d3.b[0];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_d4.h[0];
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a4 + 0xA) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0xC) = (u16) reg_tmp.h[0];
    reg_d0.w = 6;
    boss_attack_start();
    *(u16 *)(reg_a0 + 4) = (u16) reg_d2.h[0];
    *(u8 *)(reg_a0 + 0xA) = (u8) reg_d3.b[0];
    *(u16 *)(reg_a0 + 0xC) = (u16) reg_d4.h[0];
    reg_tmp.w = (u32) reg_a0;
    *(u16 *)(reg_a4 + 0xE) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_tmp.h[0];
    reg_d0.w = 0xE;
    boss_attack_start();
}

s32 boss_attack_stop();

void stage1_boss_spin(void) {
    u16 temp_v1;

    if (*(u8 *)(reg_a4 + 7) == 0) {
        *(u16 *)(reg_a4 + 8) -= 1;
        if (*(u16 *)(reg_a4 + 8) == 0) {
            *(u8 *)(reg_a4 + 7) = 1U;
            ENTITY(reg_a6)[8].hit_x_plus.sh = 1;
            goto block_3;
        }
    } else {
block_3:
        reg_d0.b[0] = *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[2].draw.b.flip += reg_d0.b[0];
        ENTITY(reg_a6)[4].draw.b.flip += reg_d0.b[0];
        if (*(u8 *)(reg_a4 + 7) == 1) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                reg_d0.b[0] = *(u8 *)(reg_a4 + 3);
                *(u8 *)(reg_a4 + 2) += reg_d0.b[0];
                reg_d0.b[0] = *(u8 *)(reg_a4 + 2);
                if ((s8)(reg_d0.b[0]) < 0) {
                    reg_d0.b[0] *= -1;
                }
                if (reg_d0.b[0] == 2) {
                    *(u8 *)(reg_a4 + 7) = 2U;
                    *(u16 *)(reg_a4 + 4) = 0x6020;
                    *(u16 *)(reg_a4 + 0x12) = 0x100U;
                }
            }
        }
        if (*(u8 *)(reg_a4 + 7) == 2) {
            temp_v1 = *(u16 *)(reg_a4 + 0x12);
            if (temp_v1 != 0) {
                *(u16 *)(reg_a4 + 0x12) = (u16) (temp_v1 - 1);
            } else {
                reg_d0.b[0] = *(u8 *)(reg_a4 + 3);
                reg_d0.b[0] += reg_d0.b[0];
                reg_d1.b[0] = *(u8 *)(reg_a4 + 2);
                if (reg_d0.b[0] != reg_d1.b[0]) {
                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
                    *(u8 *)(reg_a4 + 5) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                        reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xA);
                        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0xC);
                        reg_a0 = (u8 *)reg_tmp.w;
                        reg_tmp.h[1] = *(u16 *)(reg_a4 + 0xE);
                        reg_tmp.h[0] = *(u16 *)(reg_a4 + 0x10);
                        reg_a0 = (u8 *)reg_tmp.w;
                        reg_d0.b[0] = *(u8 *)(reg_a4 + 3);
                        *(u8 *)(reg_a4 + 2) -= reg_d0.b[0];
                    }
                } else {
                    reg_d0.b[0] = ENTITY(reg_a6)[2].draw.b.flip;
                    reg_d0.b[0] &= 0xFE;
                    if (reg_d0.b[0] == 0x40) {
                        ENTITY(reg_a6)[2].draw.b.flip = 0x40U;
                        ENTITY(reg_a6)[4].draw.b.flip = 0xC0U;
                        *(u8 *)(reg_a4 + 7) = 3U;
                        reg_d0.w = 5;
                        boss_attack_stop();
                        reg_d0.w = 6;
                        boss_attack_stop();
                        reg_d0.w = 0xE;
                        boss_attack_stop();
                    }
                }
            }
        }
        if (*(u8 *)(reg_a4 + 7) == 3) {
            *(s16 *)reg_a4 = 0;
            ENTITY(reg_a6)[8].hit_x_plus.sh = 0;
        }
    }
}

typedef struct WorkRegA42 {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    u8 pad6;
    u8 unk7;
} WorkRegA42;


void stage1_boss_right_close_start(void) {
    extern WorkRegA42 *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk4 = 0x20;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void stage1_boss_right_close() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_stop();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[2].sprite.h -= 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority -= 2;
            ENTITY(reg_a6)[1].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 2;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void stage1_boss_left_close_start(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 0x20;
    reg_a4[7] = 0;
}

void stage1_boss_left_close() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_stop();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[4].sprite.h -= 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority -= 2;
            ENTITY(reg_a6)[3].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 3;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void stage1_boss_gatling_recenter_start(void) {
    *(u16 *)(reg_a4 + 2) = 0x101;
}

s32 direction_turn_toward();

void stage1_boss_gatling_recenter() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_d1.w = 0;
        reg_d1.b[0] = 0x20;
        reg_d0.w = 0;
        reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
        reg_d0.h[0] += 0x20;
        direction_turn_toward();
        reg_d0.h[0] = reg_d1.h[0];
        reg_d0.h[0] = (u16) reg_d0.b[0];
        reg_d0.h[0] -= 0x20;
        ENTITY(reg_a6)[5].sprite.h = (u16) reg_d0.h[0];
        if (reg_d1.b[0] == 0x20) {
            *(s16 *)reg_a4 = 0;
        }
    }
}

void stage1_boss_right_open_wide_start(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    reg_a4[7] = 0;
}

void stage1_boss_right_open_wide() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (ENTITY(reg_a6)[1].draw.h == 0)) {
        reg_d0.w = 2;
        boss_animation_stop();
        ENTITY(reg_a6)[1].draw.h = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[2].sprite.h += 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority -= 2;
            ENTITY(reg_a6)[1].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

struct WorkRegA4b {
    u8 unk0[2];
    s16 unk2;
    u8 unk4[3];
    u8 unk7;
};


void stage1_boss_left_open_wide_start(void) {
    extern struct WorkRegA4b *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void stage1_boss_left_open_wide() {
    u16 temp_a0;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if ((*(u8 *)(reg_a4 + 7) == 0) && (ENTITY(reg_a6)[3].draw.h == 0)) {
        reg_d0.w = 3;
        boss_animation_stop();
        ENTITY(reg_a6)[3].draw.h = 0x10U;
        *(u8 *)(reg_a4 + 7) = 1U;
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[4].sprite.h += 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority -= 2;
            ENTITY(reg_a6)[3].draw.h += 4;
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

typedef struct WorkRegA43 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 unk7;
} WorkRegA43;


void stage1_boss_right_close_wide_start(void) {
    extern WorkRegA43 *reg_a4_as_WorkRegA4_p;
    reg_a4_as_WorkRegA4_p->unk2 = 0;
    reg_a4_as_WorkRegA4_p->unk4 = 0x20;
    reg_a4_as_WorkRegA4_p->unk7 = 0;
}

void stage1_boss_right_close_wide() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[1].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xA;
                boss_animation_stop();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[2].sprite.h -= 0xC0;
            ENTITY(reg_a6)[2].draw.b.priority += 2;
            ENTITY(reg_a6)[1].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[1].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 2;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void stage1_boss_left_close_wide_start(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a4 + 4) = 0x20;
    reg_a4[7] = 0;
}

void stage1_boss_left_close_wide() {
    u16 temp_a0;
    u16 temp_a0_2;
    u16 temp_v1;

    if (ENTITY(reg_a6)[3].misc.b.draw_layer != 0) {
        stage1_boss_anim_clear();
        return;
    }
    if (*(u8 *)(reg_a4 + 7) == 0) {
        temp_v1 = *(u16 *)(reg_a4 + 4);
        if (temp_v1 != 0) {
            *(u16 *)(reg_a4 + 4) = (u16) (temp_v1 - 1);
        } else {
            temp_a0 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0 == 0x68) {
                reg_d0.w = 0xB;
                boss_animation_stop();
                *(u8 *)(reg_a4 + 7) = 1U;
            }
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            ENTITY(reg_a6)[4].sprite.h -= 0xC0;
            ENTITY(reg_a6)[4].draw.b.priority += 2;
            ENTITY(reg_a6)[3].draw.h -= 4;
            temp_a0_2 = ENTITY(reg_a6)[3].draw.h;
            if (temp_a0_2 == 0x10) {
                reg_d0.w = 3;
                boss_animation_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}

void stage1_boss_gatling_fast_spin_start(void) {
    ENTITY(reg_a6)[5].look.sh = 0;
}

void stage1_boss_gatling_fast_spin(void) {
    ENTITY(reg_a6)[5].draw.h += 4;
    if ((s16) ENTITY(reg_a6)[5].draw.h >= 0x1C) {
        ENTITY(reg_a6)[5].draw.h = 0U;
    }
}
