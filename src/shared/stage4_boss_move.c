#include "common.h"
#include "entity.h"

void stage4_boss_move_enter(void);
void stage4_boss_move_wander_high(void);
void stage4_boss_move_to_form2();
void stage4_boss_move_to_form2_b(void);
void stage4_boss_move_wander_high_b(void);
void stage4_boss_move_final_explosion();
void stage4_boss_move_wait(void);
void stage4_boss_move_hover_high(void);
void stage4_boss_move_rage(void);


void func_001BE1E0(void) {
    reg_d0.b[0] = reg_a4[3];
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_tmp.b[0] = reg_a4[5];
    reg_a4[5] -= 1;
    if ((s32) reg_tmp.b[0] > 0) goto block_1;
    reg_a4[5] = reg_a4[4];
    if (reg_d0.b[0] == reg_d1.b[0]) goto block_1;
    if ((s8) reg_d0.b[0] < (s8) reg_d1.b[0]) goto next_1;
    reg_d1.b[0] += 1;
    goto block_1;
next_1:
    reg_d1.b[0] -= 1;
block_1:
    ENTITY(reg_a6)->move.b.speed = reg_d1.b[0];
}


s32 entity_velocity();

void func_001BE270(void) {
    func_001BE1E0();
    entity_velocity();
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    ENTITY(reg_a6)[1].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[1].x.h = (u16) reg_d0.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_x_plus.h;
    ENTITY(reg_a6)[1].y.h += reg_d1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_x_minus.h;
    ENTITY(reg_a6)[1].x.h += reg_d1.h[0];
    ENTITY(reg_a6)[4].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[4].x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)[4].y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[4].x.h;
    reg_tmp.w += 0xF2BFF500;
    ENTITY(reg_a6)[4].y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)[4].x.h = (u16) reg_tmp.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].sprite.h;
    ENTITY(reg_a6)[4].y.h += reg_d1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].look.h;
    ENTITY(reg_a6)[4].x.h += reg_d1.h[0];
    ENTITY(reg_a6)[5].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[5].x.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)[5].y.h;
    reg_tmp.h[0] = ENTITY(reg_a6)[5].x.h;
    reg_tmp.w += 0xF3000AC0;
    ENTITY(reg_a6)[5].y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)[5].x.h = (u16) reg_tmp.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_y_plus.h;
    ENTITY(reg_a6)[5].y.h += reg_d1.h[0];
    reg_d1.h[0] = ENTITY(reg_a6)[12].hit_y_minus.h;
    ENTITY(reg_a6)[5].x.h += reg_d1.h[0];
    reg_d0.h[1] = ENTITY(reg_a6)[1].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[1].x.h;
    ENTITY(reg_a6)[2].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[2].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].y.h -= 0x2200;
    reg_d0.h[1] = ENTITY(reg_a6)[2].y.h;
    reg_d0.h[0] = ENTITY(reg_a6)[2].x.h;
    ENTITY(reg_a6)[3].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[3].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[3].y.h += 0xA00;
    ENTITY(reg_a6)[6].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[6].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[6].y.h += 0xA40;
    ENTITY(reg_a6)[6].x.h += 0x7FFF + 0x75C1;
    ENTITY(reg_a6)[7].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[7].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[7].y.h += 0xA40;
    ENTITY(reg_a6)[7].x.h += 0xA40;
    ENTITY(reg_a6)[8].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[8].x.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[8].y.h += 0x7FFF + 0x7B41;
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.w += 0xEC000000;
    ENTITY(reg_a6)[9].y.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)[9].x.h = (u16) reg_d0.h[0];
}

s32 func_001E8710(s32, s32, s32, s32); /* extern */

void stage4_boss_move_enter_start(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0;
    ENTITY(reg_a6)->move.sh = 0x20;
    *(s8 *)(reg_a4 + 7) = 0;
    *(s16 *)(reg_a4 + 8) = 0x280;
    *(s8 *)(reg_a4 + 0xB) = 1;
    *(s8 *)(reg_a4 + 0xA) = 0;
    *(s16 *)(reg_a4 + 0xC) = 0x101;
    ENTITY(reg_a6)[9].offset_y.sh = 0x1C;
    ENTITY(reg_a6)[9].offset_x.sh = 0;
    func_001E8710(0x101, 1, 0x280, 0x20);
    stage4_boss_move_enter();
}

s32 boss_phase_start();
s32 boss_movement_start();
s32 boss_part_show();
s32 boss_part_hide();
s32 func_0013B2E0();
s32 sprite_palette_load();
s32 velocity_from_dir256();
extern u8 D_0025FEF0[];
extern u8 D_0026F440[];
extern u8 g_boss_present_b1;
extern u16 g_side_scroll_x[];

void stage4_boss_move_enter(void) {
    s32 boss_animation_start();
    if (*(u8 *)(reg_a4 + 7) == 0) {
        *(u8 *)(reg_a4 + 0xA) += 2;
        reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
        reg_d1.w = 0;
        reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 2);
        reg_d1.b[0] = *(u8 *)(reg_a4 + 0xA);
        velocity_from_dir256();
        reg_d3.h[0] = (s16) reg_d3.h[0] * 8;
        reg_d1.h[0] = reg_d3.h[0];
        reg_d1.h[0] = (u16) -(s16) reg_d1.h[0];
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 6);
        reg_d1.h[0] = (u16) ((s16) reg_d1.h[0] >> 4);
        reg_d1.h[0] += 7;
        if ((s16) reg_d1.h[0] > 0xF) {
            reg_d1.h[0] = 0xF;
        }
        if (0 > (s16) reg_d1.h[0]) {
            reg_d1.h[0] = 0;
        }
        reg_d1.h[0] += reg_d1.h[0];
        reg_d1.h[0] += reg_d1.h[0];
        ENTITY(reg_a6)[9].offset_y.h = (u16) reg_d1.h[0];
        reg_d0.h[0] = 0x1C00;
        reg_d0.h[0] += reg_d3.h[0];
        reg_d0.h[0] -= g_side_scroll_x[0];
        ENTITY(reg_a6)->x.h = (u16) reg_d0.h[0];
        reg_d0.h[0] = *(u16 *)(reg_a4 + 8);
        ENTITY(reg_a6)->y.h += reg_d0.h[0];
        *(u16 *)(reg_a4 + 8) -= 5;
        if ((s16) *(u16 *)(reg_a4 + 8) <= 0) {
            *(u16 *)(reg_a4 + 8) = 0U;
            *(u8 *)(reg_a4 + 7) = 1U;
            reg_d0.w = 0xA;
            boss_part_hide();
            reg_d0.w = 0xB;
            boss_part_show();
        }
    }
    if (*(u8 *)(reg_a4 + 7) == 1) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xD);
        *(u8 *)(reg_a4 + 0xD) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            ENTITY(reg_a6)[9].offset_x.h += 4;
            if ((s16) ENTITY(reg_a6)[9].offset_x.h > 0x1C) {
                ENTITY(reg_a6)[9].offset_x.h = 0U;
                reg_d0.w = 0xB;
                boss_part_hide();
                reg_d0.h[0] = 0x15;
                reg_a0 = (u8 *)D_0025FEF0;
                sprite_palette_load();
                g_boss_present_b1 |= 0x10;
                reg_d0.w = 1;
                g_boss_present_b1 |= 2;
                boss_movement_start();
                reg_d0.w = 3;
                boss_phase_start();
                reg_d0.w = 9;
                boss_animation_start();
                reg_d0.w = 0xA;
                boss_animation_start();
                reg_d0.w = 0;
                boss_part_show();
                reg_d0.w = 1;
                boss_part_show();
                reg_d0.w = 2;
                boss_part_show();
                reg_d0.w = 3;
                boss_part_show();
                reg_d0.w = 4;
                boss_part_show();
                reg_d0.w = 5;
                boss_part_show();
                ENTITY(reg_a6)[1].flags.h = 0xA001;
                ENTITY(reg_a6)[2].flags.h = 0xA001;
                ENTITY(reg_a6)[3].flags.h = 0xA001;
                reg_a0 = (u8 *)D_0026F440;
                func_0013B2E0();
            }
        }
    }
    func_001BE270();
}


void stage4_boss_move_wander_high_start(void) {
    *(u8 *)(reg_a4 + 3) = 4;
    *(u16 *)(reg_a4 + 4) = 0;
    *(u16 *)(reg_a4 + 6) = 0;
    stage4_boss_move_wander_high();
}

s32 direction_turn_toward();
extern u8 D_0026F480[];

void stage4_boss_move_wander_high(void) {
    s32 direction_between(void *);
    s32 func_00202B70(u16, void *);
    u16 temp_a0;

    reg_a0 = D_0026F480;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between(reg_a6);
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = D_0026F480;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    temp_a0 = ENTITY(reg_a6)->x.h;
    reg_d1.h[0] = temp_a0;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70(temp_a0, reg_a6);
    if ((s16) reg_d0.h[0] < 0x201) {
        *(u16 *)(reg_a4 + 6) += 4;
        *(u16 *)(reg_a4 + 6) &= 0xF;
    }
    func_001BE270();
}


void stage4_boss_move_to_form2_start(void) {
    ENTITY(reg_a6)->move.b.speed = 0;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    reg_a4[0x3] = 0x20;
    *(u16 *)(reg_a4 + 0x4) = 0x303;
    stage4_boss_move_to_form2(0x20);
}


void stage4_boss_move_to_form2() {
    func_001BE270();
}


void stage4_boss_move_to_form2_b_start(void) {
    s32 boss_animation_start(s32);
    *(s8 *)(reg_a4 + 3) = 4;
    *(s16 *)(reg_a4 + 4) = 0x202;
    *(s8 *)(reg_a4 + 7) = 0;
    reg_d0.w = 0;
    boss_animation_start(4);
    stage4_boss_move_to_form2_b();
}

s32 boss_movement_stop();
extern u8 D_0028DC84[];

void stage4_boss_move_to_form2_b(void) {
    s32 direction_between();
    s32 func_00202B70();
    reg_a0 = D_0028DC84;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    direction_between();
    ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = D_0028DC84;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d3.h[0] -= g_side_scroll_x[0];
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x1401) {
        if (*(u8 *)(reg_a4 + 7) == 0) {
            *(u8 *)(reg_a4 + 7) = 1U;
            *(s16 *)(reg_a4 + 4) = 0;
        }
        *(s8 *)(reg_a4 + 3) = 4;
        if ((s16) reg_d0.h[0] > 0x200) {
            func_001BE270();
            return;
        }
        ENTITY(reg_a6)->move.sb.speed = 0;
        reg_d0.w = 5;
        boss_phase_start();
        boss_movement_stop();
        func_001BE270();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0x20;
    func_001BE270();
}


void stage4_boss_move_wander_high_b_start(void) {
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0x20;
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 0;
    ENTITY(reg_a6)[1].move.sb.speed = 6;
    stage4_boss_move_wander_high_b();
}

s32 func_00201D10();
extern u8 D_0026F490[];

void stage4_boss_move_wander_high_b(void) {
    s32 direction_between();
    s32 func_00202B70();
    reg_a0 = (u8 *)D_0026F490;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[1].move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_0026F490;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x401) {
        *(u16 *)(reg_a4 + 6) += 4;
        *(u16 *)(reg_a4 + 6) &= 0xF;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    func_00201D10();
    ENTITY(reg_a6)[12].hit_x_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)[12].hit_x_minus.h += reg_d3.h[0];
    func_001BE270();
}


void stage4_boss_move_final_explosion_start(void) {
    ENTITY(reg_a6)->move.b.dir = 0x20;
    reg_a4[0x3] = 1;
    *(u16 *)&reg_a4[0x4] = 0;
    stage4_boss_move_final_explosion(0x20);
}

void stage4_boss_move_final_explosion() {
    func_001BE270();
}


void stage4_boss_move_wait_start(void) {
    ENTITY(reg_a6)->move.b.speed = 0;
    ENTITY(reg_a6)->move.b.dir = 0x20;
    reg_a4[3] = 0;
    *(u16 *)&reg_a4[4] = 0;
    stage4_boss_move_wait();
}

void stage4_boss_move_wait(void) {
    func_001BE270();
}

typedef struct WorkRegA4 {
    u8 unk0[3];
    u8 unk3;
    u16 unk4;
    u16 unk6;
    u16 unk8;
} WorkRegA4;



void stage4_boss_move_hover_high_start(void) {
    ((WorkRegA4 *)reg_a4)->unk3 = 0;
    ((WorkRegA4 *)reg_a4)->unk4 = 0;
    ((WorkRegA4 *)reg_a4)->unk6 = 0;
    ((WorkRegA4 *)reg_a4)->unk8 = 0x808;
    stage4_boss_move_hover_high();
}

extern u8 D_0026F4A0[];

void stage4_boss_move_hover_high(void) {
    s32 direction_between();
    s32 func_00202B70();
    u8 temp_v0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 9);
    *(u8 *)(reg_a4 + 9) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
        temp_v0 = ENTITY(reg_a6)[1].move.b.speed;
        if (temp_v0 != 2) {
            ENTITY(reg_a6)[1].move.b.speed = (u8) (temp_v0 - 1);
            if ((s8) ENTITY(reg_a6)[1].move.b.speed < 3) {
                ENTITY(reg_a6)[1].move.b.speed = 2U;
            }
        }
    }
    reg_a0 = (u8 *)D_0026F4A0;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[1].move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_0026F4A0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x201) {
        *(u16 *)(reg_a4 + 6) += 4;
        *(u16 *)(reg_a4 + 6) &= 0xF;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    func_00201D10();
    ENTITY(reg_a6)[12].hit_x_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)[12].hit_x_minus.h += reg_d3.h[0];
    func_001BE270();
}


void stage4_boss_move_rage_start(void) {
    ENTITY(reg_a6)->move.sb.speed = 0;
    ENTITY(reg_a6)->move.sb.dir = 0x20;
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0;
    *(s16 *)(reg_a4 + 6) = 4;
    ENTITY(reg_a6)[1].move.sb.speed = 4;
    stage4_boss_move_rage();
}

extern u8 D_0026F4B0[];

void stage4_boss_move_rage(void) {
    s32 direction_between();
    s32 func_00202B70();
    reg_a0 = (u8 *)D_0026F4B0;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    direction_between();
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    direction_turn_toward();
    ENTITY(reg_a6)[1].move.b.dir = (u8) reg_d1.b[0];
    reg_a0 = (u8 *)D_0026F4B0;
    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
    reg_d1.h[0] = ENTITY(reg_a6)->x.h;
    reg_d0.h[0] += ENTITY(reg_a6)[12].hit_x_plus.h;
    reg_d1.h[0] += ENTITY(reg_a6)[12].hit_x_minus.h;
    reg_a0 += *(u16 *)(reg_a4 + 6);
    reg_d2.h[0] = *(u16 *)reg_a0;
    reg_d3.h[0] = *(u16 *)(reg_a0 + 2);
    func_00202B70();
    if ((s16) reg_d0.h[0] < 0x401) {
        *(u16 *)(reg_a4 + 6) += 4;
        if ((s16) *(u16 *)(reg_a4 + 6) > 0x1C) {
            *(u16 *)(reg_a4 + 6) = 0U;
        }
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)[1].move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)[1].move.b.dir;
    func_00201D10();
    ENTITY(reg_a6)[12].hit_x_plus.h += reg_d2.h[0];
    ENTITY(reg_a6)[12].hit_x_minus.h += reg_d3.h[0];
    func_001BE270();
}
