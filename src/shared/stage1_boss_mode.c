#include "common.h"
#include "entity.h"

void func_001B9DE0(void);
void func_001BA0E0(void);


void stage1_boss_mode_enter_start(void) {
    *(u16 *)(reg_a4 + 2) = 0xC0;
}

s32 sprite_palette_load();
extern u8 D_0025FA30[];

void stage1_boss_mode_enter() {
    s32 boss_movement_start();
    *(u16 *)(reg_a4 + 2) -= 1;
    if ((s16) *(u16 *)(reg_a4 + 2) == 0) {
        reg_d0.w = 0;
        boss_movement_start();
        reg_d0.h[0] = 0x13;
        reg_a0 = D_0025FA30;
        sprite_palette_load();
        *(s16 *)reg_a4 = 0;
    }
}

s32 func_001713B0();
extern u16 D_0026E8A0[];
extern u16 D_0026E8B0[];
extern u8 D_0028DC40[];
extern u8 D_0028DC48[];
extern u8 D_0028DC50[];

void stage1_boss_mode_normal_start(void) {
    s32 boss_movement_start();
    reg_d0.w = 5;
    boss_movement_start();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x1000;
    func_001713B0();
    reg_d1.b[0] = *(D_0028DC48 + reg_d0.b[0]);
    reg_d1.b[0] += ENTITY(reg_a6)[8].sprite.b[1];
    if ((s32) reg_d1.b[0] >= 0x80) {
        reg_d1.b[0] = 0x80;
    }
    *(u8 *)(reg_a4 + 9) = (u8) reg_d1.b[0];
    reg_d1.b[0] = *(D_0028DC40 + reg_d0.b[0]);
    reg_d1.b[0] -= ENTITY(reg_a6)[8].draw.b.flip;
    if ((s8) reg_d1.b[0] < 3) {
        reg_d1.b[0] = 3;
    }
    *(s8 *)(reg_a4 + 7) = 0;
    *(u8 *)(reg_a4 + 6) = (u8) reg_d1.b[0];
    ENTITY(reg_a6)[8].sprite.b[1] += 2;
    if ((s32) ENTITY(reg_a6)[8].sprite.b[1] >= 0x80) {
        ENTITY(reg_a6)[8].sprite.b[1] = 0x80U;
    }
    ENTITY(reg_a6)[8].draw.b.flip -= 1;
    if ((s8) ENTITY(reg_a6)[8].draw.b.flip < 3) {
        ENTITY(reg_a6)[8].draw.b.flip = 3U;
    }
    *(s16 *)(reg_a4 + 0xA) = 0x6000;
    *(s8 *)(reg_a4 + 0xD) = 1;
    *(s8 *)(reg_a4 + 0xC) = 4;
    func_001713B0();
    reg_d1.b[0] = *(D_0028DC50 + reg_d0.b[0]);
    *(u8 *)(reg_a4 + 0xA) = reg_d1.b[0];
    reg_a0 = (u8 *)(D_0026E8A0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += ENTITY(reg_a6)[8].look.h;
    if ((s16) reg_d1.h[0] > 4) {
        reg_d1.h[0] = 4;
    }
    *(u16 *)(reg_a4 + 0xE) = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[8].look.h += 1;
    if ((s16) ENTITY(reg_a6)[8].look.h > 4) {
        ENTITY(reg_a6)[8].look.h = 4U;
    }
    reg_a0 = (u8 *)(D_0026E8B0);
    reg_d1.h[0] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    reg_d1.h[0] += ENTITY(reg_a6)[8].hit_y_plus.h;
    if ((s16) reg_d1.h[0] > 0x20) {
        reg_d1.h[0] = 0x20;
    }
    *(u16 *)(reg_a4 + 0x10) = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[8].hit_y_plus.h += 2;
    if ((s16) ENTITY(reg_a6)[8].hit_y_plus.h > 0x20) {
        ENTITY(reg_a6)[8].hit_y_plus.h = 0x20U;
    }
    *(s16 *)(reg_a4 + 0x12) = 0x2020;
}


s32 boss_phase_start();
s32 boss_attack_start();
s32 boss_attack_running();
s32 rng_next();
s32 rng_next_bit();
extern u8 D_0028DC58[];

void stage1_boss_mode_normal(void) {
    u16 temp_a0_3;
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_4;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                *(u8 *)(reg_a4 + 3) = 1U;
                reg_d0.w = 1;
                boss_attack_start();
                *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)(reg_a4 + 6);
                *(u8 *)(reg_a0 + 5) = (u8) *(u8 *)(reg_a4 + 9);
                *(u16 *)(reg_a0 + 0xC) = (u16) ENTITY(reg_a6)[8].offset_x.h;
                ENTITY(reg_a6)[8].offset_x.h += 2;
                if ((s16) ENTITY(reg_a6)[8].offset_x.h > 0xC) {
                    ENTITY(reg_a6)[8].offset_x.h = 0xCU;
                }
            }
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 3;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 4;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 1;
                boss_attack_running();
                if (cond_flag == 0) {
                    *(u8 *)(reg_a4 + 3) = 2U;
                    rng_next();
                    reg_d0.b[0] += 0x20;
                    *(u8 *)(reg_a4 + 0x15) = (u8) reg_d0.b[0];
                } else {
                    reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
                    *(u8 *)(reg_a4 + 0xB) -= 1;
                    if ((s32) reg_tmp.b[0] <= 0) {
                        *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
                        reg_d0.w = 3;
                        if (*(s8 *)(reg_a4 + 0xD) < 0) {
                            reg_d0.w = 4;
                        }
                        boss_attack_start();
                        *(s8 *)(reg_a0 + 3) = 4;
                        *(u8 *)(reg_a0 + 2) = 0;
                        *(u8 *)(reg_a4 + 0xD) *= -1;
                        if (*(s8 *)(reg_a4 + 0xD) >= 0) {
                            *(u16 *)(reg_a4 + 0xE) += 1;
                            if ((s16) *(u16 *)(reg_a4 + 0xE) > 4) {
                                *(u16 *)(reg_a4 + 0xE) = 4U;
                            }
                        }
                    }
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 2) {
        *(u8 *)(reg_a4 + 0x15) -= 1;
        if ((s8) *(u8 *)(reg_a4 + 0x15) == 0) {
            reg_d0.w = 3;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                boss_attack_running();
                if (cond_flag == 0) {
                    rng_next_bit();
                    reg_d7.h[0] = reg_d0.h[0];
                    reg_d0.w = 3;
                    reg_d7.h[0] += 1;
                    boss_attack_start();
                    *(s8 *)(reg_a0 + 3) = 8;
                    *(u8 *)(reg_a0 + 2) = (u8) reg_d7.b[0];
                    temp_a0_3 = *(u16 *)(reg_a4 + 0x10);
                    *(u16 *)(reg_a0 + 0x10) = temp_a0_3;
                    reg_d0.w = 4;
                    boss_attack_start();
                    *(s8 *)(reg_a0 + 3) = 8;
                    *(u8 *)(reg_a0 + 2) = (u8) reg_d7.b[0];
                    *(u16 *)(reg_a0 + 0x10) = (u16) *(u16 *)(reg_a4 + 0x10);
                    *(u8 *)(reg_a4 + 3) = 3U;
                }
            }
        }
    }
    temp_a0_4 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_4 == 3) {
        reg_d0.w = 1;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 3;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 4;
                boss_attack_running();
                if (cond_flag == 0) {
                    reg_a0 = (u8 *)D_0028DC58;
                    reg_a0 += ENTITY(reg_a6)[8].offset_y.h;
                    reg_d0.h[0] = *(u16 *)reg_a0;
                    if ((s16) reg_d0.h[0] < 0) {
                        reg_d7.w = 3;
                        rng_next_bit();
                        if (reg_d0.b[0] == 0) {
                            reg_d7.w = 2;
                        }
                    } else {
                        ENTITY(reg_a6)[8].offset_y.h += 2;
                    }
                    reg_d0.w = 3;
                    boss_phase_start();
                    *(s16 *)reg_a4 = 0;
                }
            }
        }
    }
}


void stage1_boss_mode_vulcan_start(void) {
    void boss_movement_start(void);
    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        func_001B9DE0();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x2020;
    *(s16 *)(reg_a4 + 4) = 0x10;
    reg_d0.w = 8;
    boss_movement_start();
}

s32 boss_movement_current();
s32 boss_animation_start();
s32 boss_animation_running();

void stage1_boss_mode_vulcan(void) {
    s32 boss_movement_start();
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;

    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        func_001B9DE0();
        return;
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 4) {
            reg_d0.w = 8;
            boss_animation_start();
            reg_d0.w = 9;
            boss_animation_start();
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 9;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            boss_animation_running();
            if (cond_flag == 0) {
                *(s8 *)(reg_a4 + 2) = 1;
                *(u8 *)(reg_a4 + 3) = 2U;
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 2) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 0xE;
            boss_animation_start();
            *(u8 *)(reg_a4 + 3) = 3U;
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 3) {
        reg_d0.w = 0xE;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            boss_animation_start();
            reg_d0.w = 0xD;
            boss_animation_start();
            *(s8 *)(reg_a4 + 2) = 0;
            reg_d0.w = 5;
            boss_movement_start();
            *(u8 *)(reg_a4 + 3) = 4U;
        }
    }
    temp_a0_4 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_4 == 4) {
        reg_d0.w = 2;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 0xC;
            boss_animation_running();
            if (cond_flag == 0) {
                reg_d0.w = 0xD;
                boss_animation_running();
                if (cond_flag == 0) {
                    reg_d0.w = 0xF;
                    boss_animation_start();
                    func_001B9DE0();
                }
            }
        }
    }
}

s32 boss_phase_start();                            /* extern */
extern s16 *reg_a4_as_s16_p;

void func_001B9DE0(void) {
    reg_d0.w = 1;
    boss_phase_start();
    *reg_a4_as_s16_p = 0;
}


void stage1_boss_mode_side_attack_start(void) {
    s32 boss_movement_start();
    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        func_001BA0E0();
        return;
    }
    *(s8 *)(reg_a4 + 3) = 0;
    *(s8 *)(reg_a4 + 2) = 0;
    *(s16 *)(reg_a4 + 6) = 0x2020;
    reg_d0.w = 3;
    boss_movement_start();
}

void stage1_boss_mode_side_attack(void) {
    s32 boss_movement_start();
    u8 temp_a0;
    u8 temp_a0_2;
    u8 temp_a0_3;
    u8 temp_a0_4;

    reg_d0.b[0] = ENTITY(reg_a6)[1].misc.b.draw_layer;
    reg_d0.b[0] += ENTITY(reg_a6)[3].misc.b.draw_layer;
    if (reg_d0.b[0] == 2) {
        func_001BA0E0();
        return;
    }
    if (*(u8 *)(reg_a4 + 3) == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 4) {
            reg_d0.w = 0x10;
            boss_animation_start();
            reg_d0.w = 0x11;
            boss_animation_start();
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 9;
        boss_animation_running();
        if (cond_flag == 0) {
            reg_d0.w = 8;
            boss_animation_running();
            if (cond_flag == 0) {
                *(s8 *)(reg_a4 + 2) = 1;
                *(u8 *)(reg_a4 + 3) = 2U;
                *(u16 *)(reg_a4 + 4) = 0x40U;
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 2) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            reg_d0.w = 8;
            boss_attack_start();
            *(u8 *)(reg_a4 + 3) = 3U;
            *(u16 *)(reg_a4 + 4) = 0x40U;
            reg_d0.w = 0x12;
            boss_animation_start();
            reg_d0.w = 0x13;
            boss_animation_start();
        }
    }
    temp_a0_3 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_3 == 3) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            reg_d7.w = 9;
            rng_next_bit();
            if (reg_d0.b[0] == 0) {
                reg_d7.w = 0xA;
            }
            reg_d0.h[0] = reg_d7.h[0];
            *(u8 *)(reg_a4 + 3) = 4U;
            *(s8 *)(reg_a4 + 2) = 0;
            reg_d0.w = 5;
            boss_movement_start();
        }
    }
    temp_a0_4 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_4 == 4) {
        reg_d0.w = 7;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_d0.w = 9;
            boss_attack_running();
            if (cond_flag == 0) {
                reg_d0.w = 0xA;
                boss_attack_running();
                if (cond_flag == 0) {
                    func_001BA0E0();
                }
            }
        }
    }
}

s32 boss_phase_start();                            /* extern */

void func_001BA0E0(void) {
    reg_d0.w = 6;
    boss_phase_start();
    *reg_a4_as_s16_p = 0;
}

void stage1_boss_mode_one_side_lost_start(void) {
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x80;
    *(s16 *)(reg_a4 + 6) = 0x40;
    *(s16 *)(reg_a4 + 8) = 0x404;
    *(s16 *)(reg_a4 + 0xA) = 0x6060;
    *(s16 *)(reg_a4 + 0xC) = 0x404;
}

void stage1_boss_mode_one_side_lost() {
    u8 temp_a0;
    u8 temp_a0_2;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u16 *)(reg_a4 + 4) -= 1;
        if ((s16) *(u16 *)(reg_a4 + 4) == 0) {
            *(u8 *)(reg_a4 + 3) = 1U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 0xB;
        boss_attack_running();
        if (cond_flag == 0) {
            if (*(u8 *)(reg_a4 + 9) == 0) {
                *(u8 *)(reg_a4 + 9) = (u8) *(u8 *)(reg_a4 + 8);
                *(u8 *)(reg_a4 + 3) = 2U;
            } else {
                reg_tmp.b[0] = *(u8 *)(reg_a4 + 7);
                *(u8 *)(reg_a4 + 7) -= 1;
                if ((s32) reg_tmp.b[0] <= 0) {
                    *(u8 *)(reg_a4 + 7) = (u8) *(u8 *)(reg_a4 + 6);
                    reg_d0.w = 0xB;
                    boss_attack_start();
                    *(u8 *)(reg_a4 + 9) -= 1;
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if ((temp_a0_2 == 2) && (reg_d0.w = 0xC, boss_attack_running(), (cond_flag == 0))) {
        if (*(u8 *)(reg_a4 + 0xD) == 0) {
            *(u8 *)(reg_a4 + 0xD) = (u8) *(u8 *)(reg_a4 + 0xC);
            *(u8 *)(reg_a4 + 3) = 1U;
            return;
        }
        reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
        *(u8 *)(reg_a4 + 0xB) -= 1;
        if ((s32) reg_tmp.b[0] <= 0) {
            *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
            reg_d0.w = 0xC;
            boss_attack_start();
            *(u8 *)(reg_a4 + 0xD) -= 1;
        }
    }
}

typedef struct WorkRegA4 {
    u8 pad0[3];
    u8 unk3;
    u16 unk4;
    u16 unk6;
} WorkRegA4;


void stage1_boss_mode_both_sides_lost_start(void) {
    ((WorkRegA4 *)reg_a4)->unk3 = 0;
    ((WorkRegA4 *)reg_a4)->unk4 = 0x40;
    ((WorkRegA4 *)reg_a4)->unk6 = 0x404;
}

void stage1_boss_mode_both_sides_lost() {
    u8 temp_a0;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        *(u8 *)(reg_a4 + 3) = 1U;
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 1) {
        reg_d0.w = 0;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                reg_d0.w = 0;
                boss_attack_start();
            }
        }
    }
}

extern u16 D_0026E8C0[];

void stage1_boss_mode_gatling_start(void) {
    s32 boss_movement_start();
    *(s8 *)(reg_a4 + 3) = 0;
    *(s16 *)(reg_a4 + 4) = 0x202;
    *(s8 *)(reg_a4 + 9) = 0xD;
    *(s16 *)(reg_a4 + 0xA) = 0x7050;
    *(s16 *)(reg_a4 + 0x14) = 0x2040;
    *(s8 *)(reg_a4 + 0x11) = 1;
    *(s8 *)(reg_a4 + 0x10) = 1;
    func_001713B0();
    reg_a0 = (u8 *)(D_0026E8C0);
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    *(u16 *)(reg_a4 + 0xE) = (u16) *(u16 *)reg_a0;
    reg_a0 += 2;
    reg_d1.h[0] = *(u16 *)reg_a0;
    reg_d1.h[0] += ENTITY(reg_a6)[8].hp.h;
    if ((s16) reg_d1.h[0] > 0x5) {
        reg_d1.h[0] = 5;
    }
    *(u16 *)(reg_a4 + 0xC) = (u16) reg_d1.h[0];
    ENTITY(reg_a6)[8].hp.h += 1;
    if ((s16) ENTITY(reg_a6)[8].hp.h > 0x5) {
        ENTITY(reg_a6)[8].hp.h = 5U;
    }
    reg_d0.w = 6;
    boss_movement_start();
}

s32 boss_animation_stop();
s32 aim_at_player();
s32 direction_turn_toward();

void stage1_boss_mode_gatling(void) {
    u8 temp_a0;
    u8 temp_a0_2;

    if (*(u8 *)(reg_a4 + 3) == 0) {
        boss_movement_current();
        if (reg_d0.h[0] == 7) {
            reg_d0.w = 7;
            boss_animation_stop();
            reg_d0.w = 0x14;
            boss_animation_start();
            *(u16 *)(reg_a4 + 6) = 1U;
            reg_d1.w = 0x25;
            rng_next_bit();
            if (reg_d0.b[0] != 0) {
                reg_d1.w = 0x1C;
                *(u16 *)(reg_a4 + 6) *= 0xFFFF;
            }
            rng_next();
            reg_d0.b[0] = (u8) ((s8) reg_d0.b[0] >> 2);
            reg_d1.b[0] += reg_d0.b[0];
            *(u8 *)(reg_a4 + 2) = (u8) reg_d1.b[0];
            *(u8 *)(reg_a4 + 3) = 2U;
        }
    }
    temp_a0 = *(u8 *)(reg_a4 + 3);
    if (temp_a0 == 2) {
        if (*(u8 *)(reg_a4 + 0x11) != 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 5);
            *(u8 *)(reg_a4 + 5) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 5) = (u8) *(u8 *)(reg_a4 + 4);
                reg_d0.h[0] = ENTITY(reg_a6)[5].y.h;
                reg_d1.h[0] = ENTITY(reg_a6)[5].x.h;
                aim_at_player();
                if (cond_flag == 0) {
                    if ((s8) reg_d1.b[0] > 0x27) {
                        reg_d1.w = 0x27;
                    }
                    if ((s8) reg_d1.b[0] < 0x19) {
                        reg_d1.w = 0x19;
                    }
                    reg_d0.w = 0;
                    reg_d1.h[0] = (u16) reg_d1.b[0];
                    reg_d0.h[0] = ENTITY(reg_a6)[5].sprite.h;
                    reg_d0.h[0] += 0x20;
                    direction_turn_toward();
                    reg_d0.h[0] = reg_d1.h[0];
                    reg_d0.h[0] = (u16) reg_d0.b[0];
                    reg_d0.h[0] -= 0x20;
                    ENTITY(reg_a6)[5].sprite.h = (u16) reg_d0.h[0];
                }
            }
        }
        reg_d0.w = 0xD;
        boss_attack_running();
        if (cond_flag == 0) {
            reg_tmp.b[0] = *(u8 *)(reg_a4 + 0xB);
            *(u8 *)(reg_a4 + 0xB) -= 1;
            if ((s32) reg_tmp.b[0] <= 0) {
                *(u8 *)(reg_a4 + 0xA) -= 8;
                *(u8 *)(reg_a4 + 0xB) = (u8) *(u8 *)(reg_a4 + 0xA);
                reg_d0.w = 0xD;
                boss_attack_start();
                *(u8 *)(reg_a0 + 5) = (u8) *(u8 *)(reg_a4 + 9);
                *(u8 *)(reg_a0 + 4) = (u8) *(u8 *)(reg_a4 + 0x10);
                *(u16 *)(reg_a0 + 6) = (u16) *(u16 *)(reg_a4 + 0xE);
                *(u8 *)(reg_a4 + 9) += 4;
                *(u8 *)(reg_a4 + 0x10) += 1;
                *(u16 *)(reg_a4 + 0xE) += 2;
                *(u8 *)(reg_a4 + 0x11) = 1U;
                *(u16 *)(reg_a4 + 6) *= 0xFFFF;
                *(u16 *)(reg_a4 + 0xC) -= 1;
                if ((s16) *(u16 *)(reg_a4 + 0xC) == 0) {
                    *(u16 *)(reg_a4 + 0x12) = 0x50U;
                    *(u8 *)(reg_a4 + 3) = 3U;
                }
            }
        }
    }
    temp_a0_2 = *(u8 *)(reg_a4 + 3);
    if (temp_a0_2 == 3) {
        reg_d0.w = 0xD;
        boss_attack_running();
        if (cond_flag == 0) {
            *(u16 *)(reg_a4 + 0x12) -= 1;
            if ((s16) *(u16 *)(reg_a4 + 0x12) == 0) {
                reg_d0.w = 0xF;
                boss_animation_start();
                reg_d0.w = 0x14;
                boss_animation_stop();
                reg_d0.w = 7;
                boss_animation_start();
                reg_d0.w = 2;
                boss_phase_start();
                *(s16 *)reg_a4 = 0;
            }
        }
    }
}
