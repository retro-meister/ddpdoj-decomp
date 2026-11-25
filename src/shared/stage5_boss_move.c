#include "common.h"
#include "entity.h"

void stage5_boss_move_enter(void);
void stage5_boss_move_form2_ascend(void);
void stage5_boss_move_form2_mouth_wander(void);
void stage5_boss_move_form2_death_descend();
void stage5_boss_move_form3_wander_a();
void stage5_boss_move_form2_jet_wander(void);
void stage5_boss_move_form2_horn_wander(void);
void stage5_boss_move_form2_stinger_wander(void);
void stage5_boss_move_form3_wander_b();
void stage5_boss_move_form3_wander_c(void);
u8 stage5_boss_move_form3_wander_d(u8 arg0);
void stage5_boss_move_form3_rage_wander(void);


void func_001F3A10(void) {
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x14C0;
    ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x7181;
    ENTITY(reg_a6)[1].x.h = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7B01;
    ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x6E41;
    ENTITY(reg_a6)[2].x.h = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x6881;
    ENTITY(reg_a6)[3].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x7FFF + 0x6EC1;
    ENTITY(reg_a6)[3].x.h = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x740;
    ENTITY(reg_a6)[4].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x1040;
    ENTITY(reg_a6)[4].x.h = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x7781;
    ENTITY(reg_a6)[5].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x14C0;
    ENTITY(reg_a6)[5].x.h = (u16) reg_d1.h[0];
    reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
    reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += 0x7FFF + 0x6541;
    ENTITY(reg_a6)[6].y.h = (u16) reg_d0.h[0];
    reg_d1.h[0] += 0x1040;
    ENTITY(reg_a6)[6].x.h = (u16) reg_d1.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)[13].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[13].x.h = (u16) reg_d0.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)[10].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[10].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[11].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[11].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[12].y.h = (u16) ENTITY(reg_a6)->y.h;
    ENTITY(reg_a6)[12].x.h = (u16) ENTITY(reg_a6)->x.h;
}

s32 rng_next_unsigned();
extern u16 g_side_scroll_x[];

void stage5_boss_move_enter_start() {
    ENTITY(reg_a6)->y.h = 0xB000;
    ENTITY(reg_a6)->x.h = 0x1C00U;
    reg_d0.h[0] = g_side_scroll_x[0];
    ENTITY(reg_a6)->x.h -= reg_d0.h[0];
    rng_next_unsigned();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x10;
    ENTITY(reg_a6)[9].hit_y_plus.b[0] = (u8) reg_d0.b[0];
    reg_d0.b[0] += 0x30;
    ENTITY(reg_a6)[9].attr.b.palette = (u8) reg_d0.b[0];
    stage5_boss_move_enter();
}

s32 entity_follow_scroll();                            /* extern */

void stage5_boss_move_enter(void) {
    entity_follow_scroll();
    func_001F3A10();
}


void stage5_boss_move_form2_ascend_start(void) {
    *(s16 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 4) = 0x808;
    *(s16 *)(reg_a4 + 6) = 0x40;
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0;
    stage5_boss_move_form2_ascend();
}

s32 boss_movement_start();
s32 boss_part_show();
s32 boss_animation_start();
s32 music_play_bgm7();
s32 func_001F56F0();
s32 func_001F57C0();

void stage5_boss_move_form2_ascend(void) {
    s32 entity_velocity();
    u16 temp_v0;

    temp_v0 = *(u16 *)(reg_a4 + 6);
    if (temp_v0 != 0) {
        *(u16 *)(reg_a4 + 6) = (u16) (temp_v0 - 1);
        if (*(u16 *)(reg_a4 + 6) == 0) {
            music_play_bgm7();
            reg_d0.w = 3;
            boss_animation_start();
            reg_d0.w = 4;
            boss_animation_start();
            reg_d0.w = 0xA;
            boss_part_show();
            reg_d0.w = 0xE;
            boss_part_show();
            ENTITY(reg_a6)[11].hit_y_minus.sh = 0x1000;
            func_001F56F0();
            func_001F57C0();
            goto block_3;
        }
    } else {
block_3:
        entity_velocity();
        if (*(u16 *)(reg_a4 + 2) == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                *(u8 *)(reg_a4 + 4) -= 1;
                ENTITY(reg_a6)->move.b.speed += 1;
                if (ENTITY(reg_a6)->move.b.speed == 8) {
                    *(u16 *)(reg_a4 + 4) = 0x303;
                    *(u16 *)(reg_a4 + 2) = 1U;
                }
            }
        } else {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                ENTITY(reg_a6)->move.b.speed -= 1;
                if (ENTITY(reg_a6)->move.b.speed == 4) {
                    reg_d0.w = 2;
                    boss_movement_start();
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
    func_001F3A10();
}

s32 rng_next_masked();

void stage5_boss_move_form2_mouth_wander_start() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 4;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    stage5_boss_move_form2_mouth_wander();
}

s32 rng_next();
s32 func_002024C0();

void stage5_boss_move_form2_mouth_wander(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3C00) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4C00) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6000) {
        if ((s32) reg_d1.h[0] >= 0x6800) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void stage5_boss_move_form2_death_descend_start(void) {
    ENTITY(reg_a6)->move.b.speed = 3;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    stage5_boss_move_form2_death_descend(3);
}

void stage5_boss_move_form2_death_descend() {
    void entity_velocity(void);
    entity_velocity();
}


void stage5_boss_move_form3_wander_a_start(void) {
    u8 val;

    reg_d0.w = 0;
    val = reg_d0.b[0];
    *((u8 *)((void *)reg_a4) + 1) = reg_d0.b[0];
    val = reg_d0.b[0];
    *((u8 *)((void *)reg_a4) + 0) = reg_d0.b[0];
    *((u8 *)((void *)reg_a6) + 0x1B) = 6;
    stage5_boss_move_form3_wander_a(val);
}

void stage5_boss_move_form3_wander_a() {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x3600, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x5200, 0x5600)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void stage5_boss_move_form2_jet_wander_start() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 8;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    stage5_boss_move_form2_jet_wander();
}

void stage5_boss_move_form2_jet_wander(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x3800) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x5000) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6400) {
        if ((s32) reg_d1.h[0] >= 0x6C00) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void stage5_boss_move_form2_horn_wander_start() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 6;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    stage5_boss_move_form2_horn_wander();
}

void stage5_boss_move_form2_horn_wander(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x4000) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4800) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5400) {
        if ((s32) reg_d1.h[0] >= 0x5C00) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}

s32 rng_next();                            /* extern */

void stage5_boss_move_form2_stinger_wander_start(void) {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    rng_next();
    reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 1);
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    stage5_boss_move_form2_stinger_wander();
}

void stage5_boss_move_form2_stinger_wander(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < 0x4200) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= 0x4600) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x7B80) {
        if ((s32) reg_d1.h[0] >= 0x7C80) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void stage5_boss_move_form3_wander_b_start(void) {
    u8 value;

    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    value = reg_d0.b[0];
    reg_a4[0] = value;
    ENTITY(reg_a6)->move.b.speed = 2;
    stage5_boss_move_form3_wander_b(value);
}

void stage5_boss_move_form3_wander_b() {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5200) {
        if ((s32) reg_d1.h[0] >= 0x5600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void stage5_boss_move_form3_wander_c_start(void) {
    reg_d0.w = 0;
    reg_a4[1] = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    stage5_boss_move_form3_wander_c();
}

void stage5_boss_move_form3_wander_c(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x6200) {
        if ((s32) reg_d1.h[0] >= 0x6600) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


u8 stage5_boss_move_form3_wander_d_start(void) {
    u8 zero_byte;

    reg_d0.w = 0;
    zero_byte = reg_d0.b[0];
    reg_a4[1] = reg_d0.b[0];
    zero_byte = reg_d0.b[0];
    reg_a4[0] = reg_d0.b[0];
    ENTITY(reg_a6)->move.b.speed = 4;
    return stage5_boss_move_form3_wander_d(zero_byte);
}

u8 stage5_boss_move_form3_wander_d(u8 arg0) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x3600, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x5200, 0x5600)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x5E00) {
        if ((s32) reg_d1.h[0] >= 0x6200) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}


void stage5_boss_move_form3_rage_wander_start() {
    reg_d0.w = 0;
    *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
    *(u8 *)reg_a4 = (u8) reg_d0.b[0];
    ENTITY(reg_a6)->move.sb.speed = 4;
    rng_next_masked();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d0.b[0];
    stage5_boss_move_form3_rage_wander();
}

void stage5_boss_move_form3_rage_wander(void) {
    s32 entity_velocity();
    entity_velocity();
    if (*(u8 *)reg_a4 != 0) {
        reg_d1.b[0] = *(u8 *)(reg_a4 + 1);
        func_002024C0();
        if (*(u8 *)(reg_a4 + 1) == reg_d1.b[0]) {
            *(u8 *)reg_a4 = 0U;
        }
    }
    rng_next();
    reg_d1.h[1] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] += 0x2800;
    if ((s32) reg_d1.h[0] < MAIN_OR_DEATH_LABEL(0x4000, 0x4800)) {
        reg_d0.b[0] += 0x10;
        goto block_11;
    }
    if ((s32) reg_d1.h[0] >= MAIN_OR_DEATH_LABEL(0x4800, 0x5200)) {
        reg_d0.b[0] += 0x30;
        goto block_11;
    }
    reg_tmp.w = reg_d1.w;
    reg_d1.h[1] = reg_tmp.h[0];
    reg_d1.h[0] = reg_tmp.h[1];
    if ((s32) reg_d1.h[0] >= 0x4800) {
        if ((s32) reg_d1.h[0] >= 0x5000) {
            reg_d0.b[0] += 0x20;
        goto block_11;
        }
    } else {
block_11:
        reg_d0.b[0] &= 0x3F;
        *(u8 *)(reg_a4 + 1) = (u8) reg_d0.b[0];
        *(u8 *)reg_a4 = 1U;
    }
    func_001F3A10();
}
