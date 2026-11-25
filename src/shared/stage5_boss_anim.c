#include "common.h"
#include "entity.h"

void func_001E8840(void);
void func_001E88D0(void);
void func_001E8950(void);
void func_001E8C90(void);
void func_001E8D20(void);
void func_001E8DA0(void);
void func_001E8EF0(void);
void func_001E8F80(void);
void func_001E8FF0(void);



void func_001E8820(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    ENTITY(reg_a6)[9].offset_y.sh = 0;
    func_001E8840();
}

void func_001E8840(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[9].offset_y.h += 4;
        if (ENTITY(reg_a6)[9].offset_y.h == 0x18) {
            ENTITY(reg_a6)[9].offset_y.h = 0U;
        }
    }
}


void func_001E88B0(void) {
    *(s16 *)(reg_a4 + 2) = 2;
    ENTITY(reg_a6)[9].offset_x.sh = 0;
    func_001E88D0();
}

void func_001E88D0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[9].offset_x.h += 4;
        if (ENTITY(reg_a6)[9].offset_x.h == 0x18) {
            ENTITY(reg_a6)[9].offset_x.h = 0U;
        }
    }
}


void func_001E8940(void) {
    *(s16 *)(reg_a4 + 2) = 1;
    func_001E8950();
}

s32 enemy_switch_target_player();
s32 direction_between();
s32 direction_turn_toward();
extern s16 g_player2[];
extern s16 g_player1[];

void func_001E8950(void) {
    s16 *temp_a0;
    u16 temp_a1;

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
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            temp_a1 = *(u16 *)(reg_a0 + 4);
            reg_d3.w = (u32) temp_a1;
            ENTITY(reg_a6)[9].hit_x_plus.h = (u16) reg_d2.h[0];
            ENTITY(reg_a6)[9].hit_x_minus.h = (u16) reg_d3.h[0];
            if ((ENTITY(reg_a6)[1].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[1].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[1].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[1].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[1].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[1].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = ENTITY(reg_a6)[9].hit_x_plus.h;
            reg_d3.h[0] = ENTITY(reg_a6)[9].hit_x_minus.h;
            if ((ENTITY(reg_a6)[2].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[2].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[2].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[2].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[2].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[2].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = ENTITY(reg_a6)[9].hit_x_plus.h;
            reg_d3.h[0] = ENTITY(reg_a6)[9].hit_x_minus.h;
            if ((ENTITY(reg_a6)[3].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[3].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[3].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[3].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[3].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[3].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = ENTITY(reg_a6)[9].hit_x_plus.h;
            reg_d3.h[0] = ENTITY(reg_a6)[9].hit_x_minus.h;
            if ((ENTITY(reg_a6)[4].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[4].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[4].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[4].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[4].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[4].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = ENTITY(reg_a6)[9].hit_x_plus.h;
            reg_d3.h[0] = ENTITY(reg_a6)[9].hit_x_minus.h;
            if ((ENTITY(reg_a6)[5].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[5].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[5].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[5].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[5].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[5].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = ENTITY(reg_a6)[9].hit_x_plus.h;
            reg_d3.h[0] = ENTITY(reg_a6)[9].hit_x_minus.h;
            if ((ENTITY(reg_a6)[6].misc.b.draw_layer == 0) && (ENTITY(reg_a6)[6].misc.b.user == 0)) {
                reg_d0.w = (u32) ENTITY(reg_a6)[6].y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)[6].x.h;
                direction_between();
                reg_d0.h[0] = ENTITY(reg_a6)[6].move.h;
                direction_turn_toward();
                ENTITY(reg_a6)[6].move.h = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
        }
    }
}


void func_001E8C70(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    ENTITY(reg_a6)[9].draw.h = 0;
    func_001E8C90();
}

void func_001E8C90(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[9].draw.h += 4;
        if (ENTITY(reg_a6)[9].draw.h == 0xC) {
            ENTITY(reg_a6)[9].draw.h = 0U;
        }
    }
}


void func_001E8D00(void) {
    ((u16 *)((void *)reg_a4))[1] = 1;
    *(u16 *)((u8 *)((void *)reg_a6) + 0x12C) = 0;
    func_001E8D20();
}

void func_001E8D20(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[9].sprite.h += 6;
        if (ENTITY(reg_a6)[9].sprite.h == 0x90) {
            ENTITY(reg_a6)[9].sprite.h = 0x5AU;
        }
    }
}


void func_001E8D90(void) {
    *(s16 *)((u8 *)((void *)reg_a4) + 2) = 1;
    func_001E8DA0();
}



void func_001E8DA0(void) {
    s16 *temp_a0;

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
        if (0 <= (s64)*(s16 *)((u8 *)(temp_a0) + (0))) {
            if (0 > (s64)*(s16 *)reg_a1) {
                reg_a0 = (u8 *)(reg_a1);
                reg_atmp = (u8 *)(temp_a0);
                reg_a1 = (u8 *)(temp_a0);
                goto block_6;
            }
        } else {
block_6:
            reg_d2.w = (u32) *(u16 *)(reg_a0 + 2);
            reg_d3.w = (u32) *(u16 *)(reg_a0 + 4);
            if (ENTITY(reg_a6)[9].hit_y_plus.b[1] == 0) {
                reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x77C1;
                direction_between();
                reg_d3.h[0] = ENTITY(reg_a6)[9].look.h;
                func_001E8FF0();
                if (cond_flag == 0) {
                    ENTITY(reg_a6)[9].look.h = (u16) reg_d1.h[0];
                }
            }
        }
    }
}

typedef struct WorkReg {
    s16 unk0;
    s16 unk2;
} WorkReg;


void func_001E8ED0(void) {
    ((WorkReg *)reg_a4)->unk2 = 1;
    *(s16 *)((u8 *)((void *)reg_a6) + 0x132) = 0;
    func_001E8EF0();
}

void func_001E8EF0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[9].hit_y_minus.h += 4;
        if (ENTITY(reg_a6)[9].hit_y_minus.h == 0x20) {
            ENTITY(reg_a6)[9].hit_y_minus.h = 0U;
        }
    }
}


void func_001E8F60(void) {
    ((s16 *)((void *)reg_a4))[1] = 1;
    *(s16 *)((u8 *)((void *)reg_a6) + 0x138) = 0;
    func_001E8F80();
}

void func_001E8F80(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        ENTITY(reg_a6)[9].hp.h += 4;
        if (ENTITY(reg_a6)[9].hp.h == 0x40) {
            ENTITY(reg_a6)[9].hp.h = 0U;
        }
    }
}

void func_001E8FF0(void) {
    if (reg_d3.b[0] != reg_d1.b[0]) {
        reg_d6.w = 0x3F;
        if (((s32) reg_d1.b[0] < 0x18) || ((s32) reg_d1.b[0] > 0x28)) {
            reg_d4.b[0] = reg_d1.b[0];
            reg_d5.b[0] = reg_d3.b[0];
            reg_d4.b[0] -= 0x20;
            reg_d5.b[0] -= reg_d1.b[0];
            reg_d4.h[0] &= reg_d6.h[0];
            reg_d5.h[0] &= reg_d6.h[0];
            if ((s32) reg_d4.b[0] >= 0x20) {
                if ((s32) reg_d5.b[0] <= 0x20) {
                    goto block_7;
                }
                goto block_9;
            }
            if ((s32) reg_d5.b[0] <= 0x20) {
                goto block_9;
            }
        }
block_7:
        reg_d1.b[0] -= reg_d3.b[0];
        reg_d1.h[0] &= reg_d6.h[0];
        if ((s32) reg_d1.b[0] < 0x20) {
            goto block_11;
        }
        goto block_13;
block_9:
        reg_d1.b[0] -= reg_d3.b[0];
        reg_d1.h[0] &= reg_d6.h[0];
        if ((s32) reg_d1.b[0] < 0x20) {
            goto block_13;
        }
block_11:
        if (reg_d3.b[0] != 0x28) {
            reg_d3.b[0] += 1;
            goto block_15;
        }
        goto block_16;
block_13:
        if (reg_d3.b[0] != 0x18) {
            reg_d3.b[0] -= 1;
block_15:
            cond_flag = 0;
            reg_d3.h[0] &= reg_d6.h[0];
            reg_d1.b[0] = reg_d3.b[0];
            return;
        }
    }
block_16:
    cond_flag = 1;
}
