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
    *(s16 *)(reg_a6 + 0x126) = 0;
    func_001E8840();
}

void func_001E8840(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x126) += 4;
        if (*(u16 *)(reg_a6 + 0x126) == 0x18) {
            *(u16 *)(reg_a6 + 0x126) = 0U;
        }
    }
}

extern s16 *reg_a4_as_s16_p;
extern s16 *reg_a6_as_s16_p;

void func_001E88B0(void) {
    reg_a4_as_s16_p[1] = 2;
    reg_a6_as_s16_p[0x94] = 0;
    func_001E88D0();
}

void func_001E88D0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x128) += 4;
        if (*(u16 *)(reg_a6 + 0x128) == 0x18) {
            *(u16 *)(reg_a6 + 0x128) = 0U;
        }
    }
}


void func_001E8940(void) {
    reg_a4_as_s16_p[1] = 1;
    func_001E8950();
}

s32 enemy_switch_target_player();
s32 direction_between();
s32 direction_turn_toward();
extern s16 D_0029F1F0[];
extern s16 D_0029F260[];

void func_001E8950(void) {
    s16 *temp_a0;
    u16 temp_a1;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
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
            *(u16 *)(reg_a6 + 0x134) = (u16) reg_d2.h[0];
            *(u16 *)(reg_a6 + 0x136) = (u16) reg_d3.h[0];
            if ((*(u8 *)(reg_a6 + 0x3E) == 0) && (*(u8 *)(reg_a6 + 0x3F) == 0)) {
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x22);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 0x24);
                direction_between();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x3A);
                direction_turn_toward();
                *(u16 *)(reg_a6 + 0x3A) = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x134);
            reg_d3.h[0] = *(u16 *)(reg_a6 + 0x136);
            if ((*(u8 *)(reg_a6 + 0x5E) == 0) && (*(u8 *)(reg_a6 + 0x5F) == 0)) {
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x42);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 0x44);
                direction_between();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x5A);
                direction_turn_toward();
                *(u16 *)(reg_a6 + 0x5A) = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x134);
            reg_d3.h[0] = *(u16 *)(reg_a6 + 0x136);
            if ((*(u8 *)(reg_a6 + 0x7E) == 0) && (*(u8 *)(reg_a6 + 0x7F) == 0)) {
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x62);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 0x64);
                direction_between();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x7A);
                direction_turn_toward();
                *(u16 *)(reg_a6 + 0x7A) = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x134);
            reg_d3.h[0] = *(u16 *)(reg_a6 + 0x136);
            if ((*(u8 *)(reg_a6 + 0x9E) == 0) && (*(u8 *)(reg_a6 + 0x9F) == 0)) {
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x82);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 0x84);
                direction_between();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0x9A);
                direction_turn_toward();
                *(u16 *)(reg_a6 + 0x9A) = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x134);
            reg_d3.h[0] = *(u16 *)(reg_a6 + 0x136);
            if ((*(u8 *)(reg_a6 + 0xBE) == 0) && (*(u8 *)(reg_a6 + 0xBF) == 0)) {
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0xA2);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 0xA4);
                direction_between();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0xBA);
                direction_turn_toward();
                *(u16 *)(reg_a6 + 0xBA) = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
            reg_d2.h[0] = *(u16 *)(reg_a6 + 0x134);
            reg_d3.h[0] = *(u16 *)(reg_a6 + 0x136);
            if ((*(u8 *)(reg_a6 + 0xDE) == 0) && (*(u8 *)(reg_a6 + 0xDF) == 0)) {
                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0xC2);
                reg_d1.w = (u32) *(u16 *)(reg_a6 + 0xC4);
                direction_between();
                reg_d0.h[0] = *(u16 *)(reg_a6 + 0xDA);
                direction_turn_toward();
                *(u16 *)(reg_a6 + 0xDA) = (u16) reg_d1.h[0];
                enemy_switch_target_player();
            }
        }
    }
}


void func_001E8C70(void) {
    *(u16 *)(reg_a4 + 2) = 0;
    *(u16 *)(reg_a6 + 0x12A) = 0;
    func_001E8C90();
}

void func_001E8C90(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x12A) += 4;
        if (*(u16 *)(reg_a6 + 0x12A) == 0xC) {
            *(u16 *)(reg_a6 + 0x12A) = 0U;
        }
    }
}

extern void *reg_a4_as_void_p;
extern void *reg_a6_as_void_p;

void func_001E8D00(void) {
    ((u16 *)reg_a4_as_void_p)[1] = 1;
    *(u16 *)((u8 *)reg_a6_as_void_p + 0x12C) = 0;
    func_001E8D20();
}

void func_001E8D20(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x12C) += 6;
        if (*(u16 *)(reg_a6 + 0x12C) == 0x90) {
            *(u16 *)(reg_a6 + 0x12C) = 0x5AU;
        }
    }
}


void func_001E8D90(void) {
    *(s16 *)((u8 *)reg_a4_as_void_p + 2) = 1;
    func_001E8DA0();
}



void func_001E8DA0(void) {
    s16 *temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        reg_a0 = (u8 *)(D_0029F260);
        reg_a1 = (u8 *)(D_0029F1F0);
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
            if (*(u8 *)(reg_a6 + 0x131) == 0) {
                reg_d0.w = (u32) ENTITY(reg_a6)->y.h;
                reg_d1.w = (u32) ENTITY(reg_a6)->x.h;
                reg_d0.h[0] += 0x7FFF + 0x77C1;
                direction_between();
                reg_d3.h[0] = *(u16 *)(reg_a6 + 0x12E);
                func_001E8FF0();
                if (cond_flag == 0) {
                    *(u16 *)(reg_a6 + 0x12E) = (u16) reg_d1.h[0];
                }
            }
        }
    }
}

typedef struct WorkReg {
    s16 unk0;
    s16 unk2;
} WorkReg;

extern WorkReg *reg_a4_as_WorkReg_p;

void func_001E8ED0(void) {
    reg_a4_as_WorkReg_p->unk2 = 1;
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x132) = 0;
    func_001E8EF0();
}

void func_001E8EF0(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x132) += 4;
        if (*(u16 *)(reg_a6 + 0x132) == 0x20) {
            *(u16 *)(reg_a6 + 0x132) = 0U;
        }
    }
}


void func_001E8F60(void) {
    ((s16 *)reg_a4_as_void_p)[1] = 1;
    *(s16 *)((u8 *)reg_a6_as_void_p + 0x138) = 0;
    func_001E8F80();
}

void func_001E8F80(void) {
    reg_tmp.b[0] = *(u8 *)(reg_a4 + 3);
    *(u8 *)(reg_a4 + 3) -= 1;
    if ((s32) reg_tmp.b[0] <= 0) {
        *(u8 *)(reg_a4 + 3) = (u8) *(u8 *)(reg_a4 + 2);
        *(u16 *)(reg_a6 + 0x138) += 4;
        if (*(u16 *)(reg_a6 + 0x138) == 0x40) {
            *(u16 *)(reg_a6 + 0x138) = 0U;
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
