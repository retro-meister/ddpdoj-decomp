#include "common.h"
#include "entity.h"

void stage3_boss_legs_walk_start(void);
void stage3_boss_legs_walk(void);
void stage3_boss_side_turrets_track_start(void);
void stage3_boss_side_turrets_track(void);
void stage3_boss_lid_open_start(void);
void stage3_boss_lid_open(void);
void stage3_boss_lid_close_start(void);
void stage3_boss_lid_close(void);
void stage3_boss_six_gun_open_start(void);
void stage3_boss_six_gun_open(void);
void stage3_boss_six_gun_close_start(void);
void stage3_boss_six_gun_close(void);
void stage3_boss_lid_idle_start(void);
void stage3_boss_lid_idle(void);
void stage3_boss_entrance_anim_start(void);
void stage3_boss_entrance_anim(void);

/* The set-up routine and the per-frame routine of every animation, by animation number. */
void (*stage3_boss_anim_routines[])(void) = {
    stage3_boss_legs_walk_start,
    stage3_boss_legs_walk,
    stage3_boss_side_turrets_track_start,
    stage3_boss_side_turrets_track,
    stage3_boss_lid_open_start,
    stage3_boss_lid_open,
    stage3_boss_lid_close_start,
    stage3_boss_lid_close,
    stage3_boss_six_gun_open_start,
    stage3_boss_six_gun_open,
    stage3_boss_six_gun_close_start,
    stage3_boss_six_gun_close,
    stage3_boss_lid_idle_start,
    stage3_boss_lid_idle,
    stage3_boss_entrance_anim_start,
    stage3_boss_entrance_anim,
};

void stage3_boss_legs_walk(void);
void stage3_boss_side_turrets_track(void);
void stage3_boss_lid_open();
void stage3_boss_lid_close();
void stage3_boss_six_gun_open(void);
void stage3_boss_six_gun_close(void);
void stage3_boss_lid_idle(void);
void stage3_boss_entrance_anim();



void stage3_boss_legs_walk_start(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    ENTITY(reg_a6)[5].offset_y.h = 0;
    stage3_boss_legs_walk();
}

void stage3_boss_legs_walk(void) {
    if (ENTITY(reg_a6)[4].sprite.b[1] == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            goto block_3;
        }
    } else {
block_3:
        ENTITY(reg_a6)[5].offset_y.h += 4;
        if (ENTITY(reg_a6)[5].offset_y.h == 0x40) {
            ENTITY(reg_a6)[5].offset_y.h = 0U;
        }
    }
}


void stage3_boss_side_turrets_track_start(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    stage3_boss_side_turrets_track();
}

s32 direction_between();
s32 direction_turn_toward();
extern s16 g_player2[];
extern s16 g_player1[];

void stage3_boss_side_turrets_track(void) {
    s16 *temp_a0;
    u32 temp_s0;
    u32 temp_s1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(g_player1);
        reg_a1 = (u8 *)(g_player2);
        if (*(u8 *)(reg_a5 + 2) != 0) {
            reg_atmp = (u8 *)(reg_a0);
            reg_a0 = (u8 *)(reg_a1);
            reg_a1 = (u8 *)(reg_atmp);
        }
        temp_a0 = (s16 *)(reg_a0);
        if ((*(s16 *)((u8 *)(temp_a0) + (0))) >= 0) {
            if (*(s16 *)reg_a1 < 0) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.h[0] = *(u16 *)(reg_a0 + 2);
            reg_d3.h[0] = *(u16 *)(reg_a0 + 4);
            temp_s1 = reg_d3.w;
            temp_s0 = reg_d2.w;
            if (ENTITY(reg_a6)[5].hit_x_minus.h == 0) {
                reg_d0.h[0] = ENTITY(reg_a6)[1].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[1].x.h;
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x80;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[5].hit_y_plus.h;
                direction_turn_toward();
                ENTITY(reg_a6)[5].hit_y_plus.h = (u16) reg_d1.h[0];
            }
            reg_d2.w = temp_s0;
            reg_d3.w = temp_s1;
            if (ENTITY(reg_a6)[5].hp.h == 0) {
                reg_d0.h[0] = ENTITY(reg_a6)[2].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[2].x.h;
                reg_d0.h[0] += 0x1100;
                reg_d1.h[0] += 0x7FFF + 0x7F81;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[5].hit_y_minus.h;
                direction_turn_toward();
                ENTITY(reg_a6)[5].hit_y_minus.h = (u16) reg_d1.h[0];
            }
        }
    }
}


void stage3_boss_lid_open_start(void) {
    u16 flag = 0x8001;
    *(u16 *)(reg_a4 + 2) = flag;
    reg_d0.w = 4;
    ENTITY(reg_a6)[1].draw.h = (u16) reg_d0.h[0];
    ENTITY(reg_a6)[2].draw.h = (u16) reg_d0.h[0];
    stage3_boss_lid_open(flag);
}

s32 boss_animation_start();
s32 boss_attack_start();
extern u16 D_0026CB20[];

void stage3_boss_lid_open() {
    u16 temp_a0;
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(D_0026CB20);
        reg_d0.h[0] = ENTITY(reg_a6)[1].draw.h;
        ENTITY(reg_a6)[1].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[1].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ENTITY(reg_a6)[2].draw.h;
        ENTITY(reg_a6)[2].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = (u16) -(s16) ENTITY(reg_a6)[2].offset_x.h;
        ENTITY(reg_a6)[1].draw.h += 4;
        temp_a0 = ENTITY(reg_a6)[1].draw.h;
        if (temp_a0 == 0x94) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 0;
            boss_attack_start();
            reg_d0.w = 3;
            boss_animation_start();
        }
        ENTITY(reg_a6)[2].draw.h = (u16) ENTITY(reg_a6)[1].draw.h;
    }
}


void stage3_boss_lid_close_start(void) {
    *(u16 *)(reg_a4 + 2) = 0x6001;
    reg_d0.h[0] = 0x84;
    ENTITY(reg_a6)[1].draw.h = reg_d0.h[0];
    ENTITY(reg_a6)[2].draw.h = reg_d0.h[0];
    stage3_boss_lid_close(0x6001);
}

s32 boss_part_show();

void stage3_boss_lid_close() {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(D_0026CB20);
        reg_d0.h[0] = ENTITY(reg_a6)[1].draw.h;
        ENTITY(reg_a6)[1].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[1].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_d0.h[0] = ENTITY(reg_a6)[2].draw.h;
        ENTITY(reg_a6)[2].offset_y.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        ENTITY(reg_a6)[2].offset_x.h = (u16) -(s16) ENTITY(reg_a6)[2].offset_x.h;
        ENTITY(reg_a6)[1].draw.h -= 4;
        if ((s16) ENTITY(reg_a6)[1].draw.h < 0) {
            *(s16 *)reg_a4 = 0;
            reg_d0.w = 2;
            boss_animation_start();
            reg_d0.w = 2;
            boss_part_show();
            reg_d0.w = 3;
            boss_part_show();
        }
        ENTITY(reg_a6)[2].draw.h = (u16) ENTITY(reg_a6)[1].draw.h;
    }
}


void stage3_boss_six_gun_open_start(void) {
    stage3_boss_six_gun_open();
}

void stage3_boss_six_gun_open(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[5].offset_x.h += 4;
        if (ENTITY(reg_a6)[5].offset_x.h == 0x18) {
            *(s16 *)reg_a4 = 0;
        }
    }
}


void stage3_boss_six_gun_close_start(void) {
    *(u16 *)(reg_a4 + 2) = 1;
    stage3_boss_six_gun_close();
}

void stage3_boss_six_gun_close(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[5].offset_x.h -= 4;
        if (ENTITY(reg_a6)[5].offset_x.h == 0) {
            *(s16 *)reg_a4 = 0;
        }
    }
}



void stage3_boss_lid_idle_start(void) {
    *(s16 *)((u8 *)((void *)reg_a4) + 2) = 0;
    *(s16 *)((u8 *)((void *)reg_a6) + 0xBE) = 0;
    stage3_boss_lid_idle();
}

void stage3_boss_lid_idle(void) {
    if (ENTITY(reg_a6)[4].sprite.b[1] == 0) {
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
        *(u8 *)(reg_a4 + 3) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
            goto block_3;
        }
    } else {
block_3:
        ENTITY(reg_a6)[5].misc.h += 4;
        if (ENTITY(reg_a6)[5].misc.h == 0x20) {
            ENTITY(reg_a6)[5].misc.h = 0U;
        }
    }
}

typedef struct WorkReg {
    u8 pad0[2];
    s16 unk2;
    s16 unk4;
    s16 unk6;
} WorkReg;

typedef struct WorkRegBC {
    u8 pad0[0xBC];
    s16 unkBC;
} WorkRegBC;



void stage3_boss_entrance_anim_start(void) {
    ((WorkReg *)reg_a4)->unk2 = 1;
    ((WorkReg *)reg_a4)->unk4 = 0x202;
    ((WorkReg *)reg_a4)->unk6 = 0xC0;
    ((WorkRegBC *)reg_a6)->unkBC = 0;
    stage3_boss_entrance_anim(0x202, 1);
}

s32 boss_part_hide();
s32 func_0013B2E0();
s32 func_001D4550();
s32 func_001D4560();
extern u8 D_0026CBC0[];
extern u8 g_boss_present_b1;

void stage3_boss_entrance_anim() {
    u16 t1;

    if (*(u16 *)(reg_a4 + 6) == 0) goto next_40;
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(u16 *)(reg_a4 + 6) == 0) {
        ENTITY(reg_a6)[5].attr.h = 0xC0;
        goto next_40;
    }
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
    *(u8 *)(reg_a4 + 5) -= 1;
    if ((s32) reg_tmp.b[0] > 0) return;
    *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
    ENTITY(reg_a6)[5].attr.h += 0xC;
    if (ENTITY(reg_a6)[5].attr.h != 0xC0) return;
    ENTITY(reg_a6)[5].attr.h = 0U;
    *(u16 *)(reg_a4 + 6) -= 1;
    if (*(u16 *)(reg_a4 + 6) != 0) return;
    ENTITY(reg_a6)[5].attr.h = 0x60;
next_40:
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[5].attr.h += 0xC;
        t1 = ENTITY(reg_a6)[5].attr.h;
        if (t1 == 0x1E0) {
            *(s16 *)reg_a4 = 0;
            g_boss_present_b1 |= 2;
            g_boss_present_b1 |= 0x10;
            func_001D4550();
            func_001D4560();
            reg_d0.w = 9;
            boss_part_hide();
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
            reg_d0.w = 6;
            boss_part_show();
            reg_d0.w = 7;
            boss_part_show();
            reg_d0.w = 8;
            boss_part_show();
            reg_d0.w = 0;
            boss_animation_start();
            reg_d0.w = 1;
            boss_animation_start();
            reg_d0.w = 6;
            boss_animation_start();
            reg_a0 = (u8 *)D_0026CBC0;
            func_0013B2E0();
        }
    }
    }
