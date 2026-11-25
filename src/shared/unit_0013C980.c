#include "common.h"
#include "entity.h"

void func_0013C9A0(void);
void func_0013CAB0(void);
void func_0013CBA0(void);
void func_0013CCE0();
void func_0013CCF0();
void func_0013CD00(void);
void func_0013D030();
void func_0013DA80(void);
void func_0013DFE0(void);
void func_0013E8E0();
void func_0013E970();
void func_0013EC50(void);
void func_0013EE50(void);
void func_0013EE70(void);
void func_0013EEA0(void);
void func_0013F120(void);
void func_0013F190(void);
void func_0013F200(void);
void func_0013F580(void);
void func_0013F5A0(void);
void func_0013F5C0(void);
void func_0013F8A0(void);

extern u16 D_0029F180_as_u16_a[];

void func_0013C980(void) {
    D_0029F180_as_u16_a[0] &= 0xDFFB;
    func_0013C9A0();
}

typedef void (*Fn)(void);

extern u8 D_0028C5D8[8];
extern u32 reg_save_d7;
extern u32 reg_save_d6;
extern u32 reg_save_d5;
extern u32 reg_save_d0;
extern u8 *reg_save_a6;
extern u8 *reg_save_a2;
extern u8 *reg_save_a1;
extern u8 *reg_save_a0_as_u8_p;
extern u16 g_p1_hyper_active;
extern u8 D_0029D730[];
extern u8 D_0029D770[];
extern u8 D_0029DD90[];
extern u8 D_0029F180[];
extern u16 D_0029F2B8[];
extern Fn reg_call_target_as_Fn;

void func_0018DE10(void);

void func_0013C9A0(void) {
    reg_save_d0 = reg_d0.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0_as_u8_p = reg_a0;
    reg_save_a1 = reg_a1;
    reg_save_a2 = reg_a2;
    reg_save_a6 = reg_a6;
    reg_d0.h[0] = D_0029F2B8[0];
    reg_d0.h[0] <<= 1;
    reg_a0 = *(u8 **)(D_0028C5D8 + (reg_d0.h[0] & ~3));
    if (g_p1_hyper_active != 0) {
        reg_a0 = (u8 *)func_0018DE10;
    }
    reg_call_target_as_Fn = (Fn)reg_a0;
    reg_call_target_as_Fn();
    reg_a6 = (u8 *)D_0029DD90;
    reg_a0 = (u8 *)D_0029D770;
    reg_a1 = (u8 *)D_0029D730;
    reg_a2 = (u8 *)D_0029F180;
    func_0013CBA0();
}

extern u16 D_0029F110_as_u16_a[];


void func_0013CA90(void) {
    D_0029F110_as_u16_a[0] &= 0xDFFB;
    func_0013CAB0();
}

extern u8 D_0028C5E0[8];
extern u16 g_p2_hyper_active;
extern u8 D_0029D710[];
extern u8 D_0029D750[];
extern u8 D_0029D790[];
extern u8 D_0029F110[];
extern u16 D_0029F248[];

void func_0018DE40(void);

void func_0013CAB0(void) {
    reg_save_d0 = reg_d0.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0_as_u8_p = reg_a0;
    reg_save_a1 = reg_a1;
    reg_save_a2 = reg_a2;
    reg_save_a6 = reg_a6;
    reg_d0.h[0] = D_0029F248[0];
    reg_d0.h[0] <<= 1;
    reg_a0 = *(u8 **)(D_0028C5E0 + (reg_d0.h[0] & ~3));
    if (g_p2_hyper_active != 0) {
        reg_a0 = (u8 *)func_0018DE40;
    }
    reg_call_target_as_Fn = (Fn)reg_a0;
    reg_call_target_as_Fn();
    reg_a6 = (u8 *)D_0029D790;
    reg_a0 = (u8 *)D_0029D750;
    reg_a1 = (u8 *)D_0029D710;
    reg_a2 = (u8 *)D_0029F110;
    func_0013CBA0();
}

extern u16 *reg_save_a0_as_u16_p;
extern u16 *reg_a0_as_u16_p;

void func_0013CBA0(void) {
    *reg_a2 &= 0x7F;
    reg_d0.w = 0;
    *reg_a0_as_u16_p = reg_d0.h[0];
    (*(u16 *)(reg_a1 + 0)) = reg_d0.h[0];
    (*(u16 *)(reg_a1 + 0x16)) = reg_d0.h[0];
    reg_d7.h[0] = 0x1F;
    do {
        ENTITY(reg_a6)->flags.h = reg_d0.h[0];
        reg_a6 += 0x30;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d0.w = reg_save_d0;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0_as_u16_p = reg_save_a0_as_u16_p;
    reg_a1 = reg_save_a1;
    reg_a2 = reg_save_a2;
    reg_a6 = reg_save_a6;
}

extern u16 g_p2_hyper_items;
extern u16 g_p1_hyper_items;
extern s16 g_player2[];
extern s16 g_player1[];

void func_0013CC60(void) {
    if (g_player1[0] < 0) {
        reg_d0.h[0] = g_p1_hyper_items;
        reg_a1 = (u8 *)g_player1;
        if (reg_d0.h[0] != 0) {
            func_0013CCF0(g_player1);
        }
    }
    if (g_player2[0] < 0) {
        reg_d0.h[0] = g_p2_hyper_items;
        reg_a1 = (u8 *)g_player2;
        if (reg_d0.h[0] != 0) {
            func_0013CCE0(g_player2);
        }
    }
}

extern u8 D_002BAEB0_as_u8_a16[16];

void func_0013CCE0() {
    reg_a0 = (u8 *)D_002BAEB0_as_u8_a16;
    func_0013CD00();
}

extern u8 D_002BAEF0_as_u8_a[];

void func_0013CCF0() {
    reg_a0 = (u8 *)D_002BAEF0_as_u8_a;
    func_0013CD00();
}

void func_0019DBE0(void);
extern u16 D_0028DFC0;
extern u16 D_0028E3EC;
extern u16 D_0028E3F0;
extern u16 g_loop;

void func_0013CD00(void) {
    if (reg_d0.h[0] != 5) {
        reg_d4.h[0] = 5;
        reg_d2.w = 0x1E;
        reg_d2.h[0] &= D_0028E3F0;
        reg_d2.h[0] <<= 1;
    } else {
        reg_d4.h[0] = 5;
        reg_d2.w = 0xF;
        reg_d2.h[0] &= D_0028E3F0;
    }
    reg_d2.h[0] >>= 1;
    reg_d2.w += 0xB42;
    reg_d3.h[0] = 0x418;
    reg_d6.h[0] = 0xF000;
    reg_d7.w = 5;
    reg_a0 += 0x40;
    goto loop_2;
loop_1:
    if (reg_d7.h[0] == 0) {
        *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
        *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
        reg_a0 -= 4;
        reg_d0.h[0] = *(u16 *)(reg_a1 + 2);
        reg_d1.h[0] = *(u16 *)(reg_a1 + 4);
        reg_d2.h[0] = 0xF700;
        if (*(u16 *)(reg_a1 + 0x58) != 0) {
            reg_d2.h[0] = 0xF800;
        }
        reg_d0.h[0] += reg_d2.h[0];
        *(u16 *)(reg_a0 - 4) = reg_d0.h[0];
        *(u16 *)(reg_a0 - 2) = reg_d1.h[0];
        return;
    }
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
loop_2:
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    if ((D_0028DFC0 == 0) && (reg_d7.h[0] == reg_d0.h[0])) {
        reg_d0.h[0] -= 1;
        reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
        reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
        reg_tmp1.h[0] = reg_d1.h[0];
        reg_d1.h[0] = reg_d1.h[1];
        reg_d1.h[1] = reg_tmp1.h[0];
        reg_d1.h[0] += reg_d6.h[0];
        if (((s16) reg_d1.h[0] >= -0x500) && ((g_loop == 0) || (*(u8 *)(reg_a1 + 0x3E) == 0) || (D_0028E3EC == 0))) {
            reg_tmp1.h[0] = reg_d1.h[0];
            reg_d1.h[0] = reg_d1.h[1];
            reg_d1.h[1] = reg_tmp1.h[0];
            reg_d1.h[0] += 0xFCC0;
            func_0019DBE0();
        }
    }
    reg_d2.w += 1;
    if ((u32) reg_d2.w >= 0xB52U) {
        if (reg_d2.w == 0xB52) {
            reg_d2.w = 0xB42;
        } else {
            reg_d2.w = 0xB43;
        }
    }
    reg_d6.h[0] -= 0xFD00;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_1;
    }
}

extern u16 D_0029F1F2[];
extern u16 D_0029F1F4[];
extern u8 D_002BAEB0_as_u8_a[];

void func_0013CFD0(void) {
    u16 src = D_0029F1F2[0];
    reg_d1.h[1] = src;
    reg_d1.h[0] = D_0029F1F4[0];
    reg_a0 = (u8 *)D_002BAEB0_as_u8_a;
    func_0013D030(src);
}

extern u16 D_0029F262[];
extern u16 D_0029F264[];

void func_0013D000(void) {
    u16 src = D_0029F262[0];
    reg_d1.h[1] = src;
    reg_d1.h[0] = D_0029F264[0];
    reg_a0 = (u8 *)D_002BAEF0_as_u8_a;
    func_0013D030(src);
}

void func_0013D030() {
    reg_d0.h[0] = 0xF;
    do {
        *reg_a0_as_u16_p = reg_d1.h[1];
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = reg_d1.h[0];
        reg_a0_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
}

s32 func_0019DAF0();
extern u16 D_00255568[];
extern u16 D_0028E060;
extern u16 D_0028E064;
extern u16 D_0028E068;
extern u16 D_0028E06C;
extern u16 D_0028E070;
extern u16 D_0028E074;
extern u16 D_0028E3B4;
extern u8 D_0028E855;
extern u16 g_true_last_boss;
extern u16 D_0029CD80[];
extern u16 D_0029CD90[];
extern u16 g_player2_as_u16_a[];
extern u8 D_0029F240[];
extern u16 g_player1_as_u16_a[];
extern u8 D_0029F2B0[];

void func_0013D090(void) {
    if (D_0028E3B4 == 0) {
        reg_d0.h[0] = g_player1_as_u16_a[0];
        if (((s16)(reg_d0.h[0]) < 0) && !(reg_d0.h[0] & 0xFFFF & 0x4000) && (D_0029CD90[0] != 0)) {
            reg_a1 = (u8 *)D_0029F2B0;
            reg_d0.h[0] = D_0028E074;
            reg_d4.h[0] = 7;
            reg_tmp.h[0] = D_0028E06C;
            D_0028E06C -= 1;
            if ((s32) reg_tmp.h[0] <= 0) {
                D_0028E06C = D_0028E068;
            }
            switch (D_0028E3EC) { case 0: break; default:
                reg_a0 = (u8 *)(D_00255568);
                reg_d4.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d4.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            }
            if (((g_true_last_boss == 0) && !(D_0028E855 & 1)) || (reg_tmp.h[1] = *(u16 *)reg_a1, reg_tmp.h[0] = *(u16 *)(reg_a1 + 2), (reg_tmp.w != 0xC41))) {
                reg_tmp.h[1] = *(u16 *)reg_a1;
                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                reg_tmp.w += 1;
                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                if (reg_tmp.w == 0xCA1) {
                    reg_tmp.w = 0xC41;
                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                }
            }
            reg_d1.w = 0xFF010200;
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d3.h[0] = 0x460;
            func_0019DAF0();
        }
        reg_d0.h[0] = g_player2_as_u16_a[0];
        if (((s16)(reg_d0.h[0]) < 0) && !(reg_d0.h[0] & 0xFFFF & 0x4000) && (D_0029CD80[0] != 0)) {
            reg_a1 = (u8 *)D_0029F240;
            reg_d0.h[0] = D_0028E070;
            reg_d4.h[0] = 8;
            reg_tmp.h[0] = D_0028E064;
            D_0028E064 -= 1;
            if ((s32) reg_tmp.h[0] <= 0) {
                D_0028E064 = D_0028E060;
            }
            if (D_0028E3EC != 0) {
                reg_a0 = (u8 *)(D_00255568);
                reg_d4.h[1] = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
                reg_d4.h[0] = (((reg_d0.h[0] & 0xFFFF) + 2) != 0) ? *(u16 *)((u8 *)reg_a0 + ((s16)((reg_d0.h[0] & 0xFFFF) + 2) & ~1)) : *(u16 *)reg_a0;
            }
            if (((g_true_last_boss == 0) && !(D_0028E855 & 1)) || (reg_tmp.h[1] = *(u16 *)reg_a1, reg_tmp.h[0] = *(u16 *)(reg_a1 + 2), (reg_tmp.w != 0xC41))) {
                reg_tmp.h[1] = *(u16 *)reg_a1;
                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                reg_tmp.w += 1;
                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                if (reg_tmp.w == 0xCA1) {
                    reg_tmp.w = 0xC41;
                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                }
            }
            reg_d1.w = 0xFF011E00;
            reg_d2.h[1] = *(u16 *)reg_a1;
            reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
            reg_d3.h[0] = 0x460;
            func_0019DAF0();
        }
    }
}

s32 func_0019DB50();

void func_0013D470() {
    u16 temp_a0;

    reg_tmp.b[0] = *(u8 *)(reg_a0 + 1);
    *(u8 *)(reg_a0 + 1) -= 1;
    if (((s32) reg_tmp.b[0] <= 0) && (*(u8 *)(reg_a0 + 1) = (u8) *(u8 *)reg_a0, reg_tmp.h[1] = *(u16 *)reg_a1, reg_tmp.h[0] = *(u16 *)(reg_a1 + 2), reg_tmp.w += 1, *(u16 *)reg_a1 = (u16) reg_tmp.h[1], *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0], (reg_tmp.w == 0xC3A))) {
        *(u8 *)(reg_a0 + 1) = 0x10U;
    } else {
        reg_tmp.h[1] = *(u16 *)reg_a1;
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        if (reg_tmp.w == 0xC41) {
            reg_tmp.w = 0xC36;
            *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
            *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
        }
    }
    reg_d2.h[1] = *(u16 *)reg_a1;
    temp_a0 = *(u16 *)(reg_a1 + 2);
    reg_d2.h[0] = temp_a0;
    reg_d3.h[0] = 0x270;
    reg_d4.h[0] = 9;
    func_0019DB50();
}

extern s32 D_0028E050_as_s32;
extern s32 D_0028E054_as_s32;
extern s32 D_0028E058;
extern s32 D_0028E05C;
extern u16 D_0028E3E4;

void func_0013D560(void) {
    extern void func_0013D470(u16);
    if (D_0028E3B4 == 0) {
        reg_d0.h[0] = g_player1_as_u16_a[0];
        if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) && (g_p1_hyper_items != 0) && ((reg_d0.h[0] & 0xFFFF & 0x4000) || (D_0029CD90[0] == 0) || (D_0028E3E4 != 0))) {
            reg_a0 = (u8 *)(&D_0028E054_as_s32);
            reg_a1 = (u8 *)(&D_0028E05C);
            reg_d1.w = 0x810000;
            func_0013D470(reg_d0.h[0]);
        }
        reg_d0.h[0] = g_player2_as_u16_a[0];
        if ((((s64) ((s64) reg_d0.h[0] << 0x30) >> 0x30) < 0) && (g_p2_hyper_items != 0) && ((reg_d0.h[0] & 0xFFFF & 0x4000) || (D_0029CD80[0] == 0) || (D_0028E3F0 & 2))) {
            reg_a0 = (u8 *)(&D_0028E050_as_s32);
            reg_a1 = (u8 *)(&D_0028E058);
            reg_d1.w = 0x811C00;
            func_0013D470(reg_d0.h[0]);
        }
    }
}

extern u16 D_00255510_as_u16_a[];
extern u16 g_hyper_bullet_speed;
extern u16 g_p2_hyper_total;
extern u16 g_p1_hyper_total;
extern u16 g_stage;

void func_0013D660(void) {
    reg_d0.h[0] = g_p1_hyper_total;
    if ((s32) g_p2_hyper_total > (s32) reg_d0.h[0]) {
        reg_d0.h[0] = g_p2_hyper_total;
    }
    if (reg_d0.h[0] == 0) goto next_1;
    reg_d2.h[0] = g_p1_hyper_active;
    reg_d2.h[0] |= g_p2_hyper_active;
    if (reg_d2.h[0] != 0) goto next_2;
    reg_d0.h[0] >>= 2;
    if (reg_d0.h[0] == 0) goto next_1;
next_2:
    reg_d2.h[0] = reg_d0.h[0];
    reg_a0 = (u8 *) D_00255510_as_u16_a;
    reg_d2.h[0] -= 1;
    reg_d2.h[0] *= 2;
    reg_d0.h[0] = (reg_d2.h[0] != 0) ? *(u16 *) ((u8 *) reg_a0 + ((s16) reg_d2.h[0] & ~1)) : *(u16 *) reg_a0;
    if (D_0028E855 & 4) {
        reg_d0.h[0] += 2;
    }
next_1:
    if (g_loop != 0) {
        reg_d0.h[0] += 1;
        if ((g_stage == 4) && (g_true_last_boss != 0)) {
            reg_d0.h[0] += 4;
        }
    }
    if ((s32) reg_d0.h[0] > 0xA) {
        reg_d0.h[0] = 0xA;
    }
    g_hyper_bullet_speed = MAIN_OR_DEATH_LABEL(reg_d0.h[0], 0xA);
}

extern u8 D_002555E0[];
extern u8 D_0028E080[];
extern u8 D_0028E084_as_u8_a[];
extern s16 D_0029F1D0[];
extern u16 D_0029F280[];
extern u16 D_0029F282[];
extern u16 D_0029F2BA[];

void func_0013D7A0(void) {
    reg_d0.h[0] = *(u16 *)(u32)D_0029F280;
    reg_d0.h[0] += *(u16 *)(u32)D_0029F282;
    if (reg_d0.h[0] == 0x10) {
        func_0013DA80();
        return;
    }
    if (*(u16 *)(u32)D_0029F282 != 8) {
        *(u16 *)(u32)D_0029F282 += 2;
        func_0013C980();
        D_0029F1D0[0] = 0;
    }
    if (*(u16 *)(u32)D_0029F280 != 8) {
        *(u16 *)(u32)D_0029F280 += 2;
        reg_a0 = (u8 *)D_002555E0;
        reg_d0.h[0] = D_0029F2BA[0];
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += D_0029F2B8[0];
        reg_d0.h[0] <<= 2;
        reg_tmp.h[1] = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
        reg_a1 = (u8 *)reg_tmp.w;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
        reg_tmp.h[1] = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 8);
        reg_a1 = (u8 *)D_0028E080;
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d0.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
        }
        reg_a2 = (u8 *)D_0028E084_as_u8_a;
        reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d1.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
        }
    }
    cond_flag = 0;
}


void func_0013DA80(void) {
    (*(u8 *)&cond_flag) = 1;
}

extern u8 D_0028E078[];
extern u8 D_0028E07C_as_u8_a[];
extern s16 D_0029F160[];
extern u16 D_0029F210[];
extern u16 D_0029F212[];
extern u16 D_0029F24A[];

void func_0013DA90(void) {
    reg_d0.h[0] = *(u16 *)(u32)D_0029F210;
    reg_d0.h[0] += *(u16 *)(u32)D_0029F212;
    if (reg_d0.h[0] == 0x10) {
        func_0013DA80();
        return;
    }
    if (*(u16 *)(u32)D_0029F212 != 8) {
        *(u16 *)(u32)D_0029F212 += 2;
        func_0013CA90();
        D_0029F160[0] = 0;
    }
    if (*(u16 *)(u32)D_0029F210 != 8) {
        *(u16 *)(u32)D_0029F210 += 2;
        reg_a0 = (u8 *)D_002555E0;
        reg_d0.h[0] = D_0029F24A[0];
        reg_d0.h[0] -= 2;
        reg_d0.h[0] <<= 1;
        reg_d0.h[0] += D_0029F248[0];
        reg_d0.h[0] <<= 2;
        reg_tmp.h[1] = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
        reg_a1 = (u8 *)reg_tmp.w;
        reg_d1.h[0] = *(u16 *)(reg_a1 + 8);
        reg_tmp.h[1] = (reg_d0.h[0]) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
        reg_tmp.h[0] = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
        reg_a0 = (u8 *)reg_tmp.w;
        reg_d0.h[0] = *(u16 *)(reg_a0 + 8);
        reg_a1 = (u8 *)D_0028E078;
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d0.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
        }
        reg_a2 = (u8 *)D_0028E07C_as_u8_a;
        reg_tmp.h[1] = *(u16 *)(reg_a2 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a2 + 2);
        reg_a0 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a0 + 0) != reg_d1.h[0]) {
            reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
            reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
            reg_tmp.w += 2;
            *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
            *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
        }
    }
    cond_flag = 0;
}


void func_0013DD70(void) {
    reg_d0.h[0] = *(u16 *)(u32)D_0029F280;
    reg_d0.h[0] += *(u16 *)(u32)D_0029F282;
    if (reg_d0.h[0] == 0x10) {
        func_0013DFE0();
        return;
    }
    if (*(u16 *)(u32)D_0029F282 != 8) {
        *(u16 *)(u32)D_0029F282 = 8;
        func_0013C980();
        D_0029F1D0[0] = 0;
        if (*(u16 *)(u32)D_0029F280 == 8) goto block_end;
    }
    *(u16 *)(u32)D_0029F280 = 8;
    reg_a0 = (u8 *)D_002555E0;
    reg_a1 = (u8 *)D_0028E080;
    reg_d0.h[0] = D_0029F2BA[0];
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += D_0029F2B8[0];
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 2) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 4) = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 6) = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
block_end:
    cond_flag = 0;
}

void func_0013DFE0(void) {
    (*(u8 *)&cond_flag) = 1;
}

void func_0013DFF0(void) {
    reg_d0.h[0] = *(u16 *)(u32)D_0029F210;
    reg_d0.h[0] += *(u16 *)(u32)D_0029F212;
    if (reg_d0.h[0] == 0x10) {
        func_0013DFE0();
        return;
    }
    if (*(u16 *)(u32)D_0029F212 != 8) {
        *(u16 *)(u32)D_0029F212 = 8;
        func_0013CA90();
        D_0029F160[0] = 0;
        if (*(u16 *)(u32)D_0029F210 == 8) goto block_end;
    }
    *(u16 *)(u32)D_0029F210 = 8;
    reg_a0 = (u8 *)D_002555E0;
    reg_a1 = (u8 *)D_0028E078;
    reg_d0.h[0] = D_0029F24A[0];
    reg_d0.h[0] -= 2;
    reg_d0.h[0] <<= 1;
    reg_d0.h[0] += D_0029F248[0];
    reg_d0.h[0] <<= 2;
    *(u16 *)(reg_a1 + 0) = (reg_d0.h[0] != 0) ? *(u16 *)(reg_a0 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 2) = (((u16)reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 2) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 4) = (((u16)reg_d0.h[0] + 4) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 4) & ~1)) : *(u16 *)reg_a0;
    *(u16 *)(reg_a1 + 6) = (((u16)reg_d0.h[0] + 6) != 0) ? *(u16 *)(reg_a0 + ((s16)((u16)reg_d0.h[0] + 6) & ~1)) : *(u16 *)reg_a0;
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 0) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 2) = reg_tmp.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a1 + 4);
    reg_tmp.h[0] = *(u16 *)(reg_a1 + 6);
    reg_tmp.w += 8;
    *(u16 *)(reg_a1 + 4) = reg_tmp.h[1];
    *(u16 *)(reg_a1 + 6) = reg_tmp.h[0];
block_end:
    cond_flag = 0;
}

extern void func_00200EE0(void);
extern u32 D_0029CD94_as_u32_a[];
extern u32 D_0029CD98[];
extern u16 D_0029CD9C[];
extern u16 D_0029CD9E[];

void func_0013E260(void)
{
    reg_d0.h[0] = D_0029CD90[0];
    reg_d5.h[0] = reg_d0.h[0];
    func_00200EE0();

    D_0029CD94_as_u32_a[0] = reg_d2.w;
    reg_d5.h[0] >>= 1;
    reg_d0.h[0] = reg_d5.h[0];
    func_00200EE0();

    D_0029CD98[0] = reg_d2.w;
    reg_d0.h[0] = D_0029CD9C[0];
    func_00200EE0();

    D_0029CD9E[0] = reg_d2.h[0];
}

extern u32 D_0029CD84_as_u32_a[];
extern u32 D_0029CD88[];
extern u16 D_0029CD8C[];
extern u16 D_0029CD8E[];


void func_0013E2E0(void) {
    reg_d0.h[0] = D_0029CD80[0];
    reg_d5.h[0] = reg_d0.h[0];
    func_00200EE0();

    D_0029CD84_as_u32_a[0] = reg_d2.w;
    reg_d5.h[0] >>= 1;
    reg_d0.h[0] = reg_d5.h[0];
    func_00200EE0();

    D_0029CD88[0] = reg_d2.w;
    reg_d0.h[0] = D_0029CD8C[0];
    func_00200EE0();

    D_0029CD8E[0] = reg_d2.h[0];
}

extern u8 g_player1_as_u8_a[];
extern u8 D_0029F261[];
extern u8 D_0029F284[];
extern u8 D_0029F285[];

void func_0013E360(void) {
    reg_d6.b[0] = *(u8 *)(u32)D_0029F285;
    if (*(u8 *)(u32)D_0029F284 == reg_d6.b[0]) goto block_50;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.b[0] += 1;
    *(u8 *)(u32)D_0029F285 = reg_d5.b[0];
    if (*(u8 *)(u32)D_0029F284 != reg_d5.b[0]) goto block_51;
    D_0029F261[0] &= 0xBF;
    g_player1_as_u8_a[0] |= 2;
    if (D_0029CD9C[0] == 0x63) goto block_end;
    D_0029CD90[0] += 0x16;
    D_0029CD9C[0] += 1;
    func_0013E260();
    func_0013F120();
    goto block_end;
block_51:
    if (g_p1_hyper_items != 0) goto block_end;
    func_0013EE50();
block_end:
    cond_flag = 0;
    return;
block_50:
    if (D_0029CD9C[0] == 0x63) goto block_end;
    D_0029CD90[0] += 0x16;
    D_0029CD9C[0] += 1;
    reg_tmp.b[0] = *(u8 *)(u32)D_0029F261;
    *(u8 *)(u32)D_0029F261 &= 0xBF;
    if (reg_tmp.b[0] & 0x40) goto block_52;
    reg_tmp.b[0] = g_player1_as_u8_a[0];
    g_player1_as_u8_a[0] |= 2;
    if (reg_tmp.b[0] & 2) goto block_52;
    D_0029CD90[0] += 0x16;
    D_0029CD9C[0] += 1;
block_52:
    func_0013E260();
    func_0013F120();
    goto block_end;
}

extern u8 g_player2_as_u8_a[];
extern u8 D_0029F1F1[];
extern u8 D_0029F214[];
extern u8 D_0029F215[];

void func_0013E510(void) {
    reg_d6.b[0] = *(u8 *)(u32)D_0029F215;
    if (*(u8 *)(u32)D_0029F214 == reg_d6.b[0]) goto block_50;
    reg_d5.h[0] = reg_d6.h[0];
    reg_d5.b[0] += 1;
    *(u8 *)(u32)D_0029F215 = reg_d5.b[0];
    if (*(u8 *)(u32)D_0029F214 != reg_d5.b[0]) goto block_51;
    D_0029F1F1[0] &= 0xBF;
    g_player2_as_u8_a[0] |= 2;
    if (D_0029CD8C[0] == 0x63) goto block_end;
    D_0029CD80[0] += 0x16;
    D_0029CD8C[0] += 1;
    func_0013E2E0();
    func_0013F190();
    goto block_end;
block_51:
    if (g_p2_hyper_items != 0) goto block_end;
    func_0013EE70();
block_end:
    cond_flag = 0;
    return;
block_50:
    if (D_0029CD8C[0] == 0x63) goto block_end;
    D_0029CD80[0] += 0x16;
    D_0029CD8C[0] += 1;
    reg_tmp.b[0] = *(u8 *)(u32)D_0029F1F1;
    *(u8 *)(u32)D_0029F1F1 &= 0xBF;
    if (reg_tmp.b[0] & 0x40) goto block_52;
    reg_tmp.b[0] = g_player2_as_u8_a[0];
    g_player2_as_u8_a[0] |= 2;
    if (reg_tmp.b[0] & 2) goto block_52;
    D_0029CD80[0] += 0x16;
    D_0029CD8C[0] += 1;
block_52:
    func_0013E2E0();
    func_0013F190();
    goto block_end;
}

s32 func_001AA8F0();                            /* extern */
extern s8 D_0028E288_as_s8;
extern s16 g_p1_hyper_time_as_s16;

void func_0013E6C0(void) {
    if (g_p1_hyper_items == 0) {
        func_0013D000();
    }
    g_p1_hyper_items += 1;
    g_p1_hyper_time_as_s16 = 0x95F;
    func_0013F120();
    func_001AA8F0();
    D_0028E288_as_s8 = 0;
}

s32 func_001AAA20();                            /* extern */
extern s8 D_0028E284_as_s8;
extern s16 g_p2_hyper_time_as_s16;

void func_0013E710(void) {
    if (g_p2_hyper_items == 0) {
        func_0013CFD0();
    }
    g_p2_hyper_items += 1;
    g_p2_hyper_time_as_s16 = 0x95F;
    func_0013F190();
    func_001AAA20();
    D_0028E284_as_s8 = 0;
}

s32 func_001AC3A0(u16);
extern s16 g_p1_lives_as_s16;

void func_0013E760(void) {
    u16 temp_a0;

    temp_a0 = g_p1_lives_as_s16;
    if (temp_a0 != 0x14) {
        g_p1_lives_as_s16 = temp_a0 + 1;
        func_001AC3A0(temp_a0);
    }
}

s32 func_001AC5F0(u16);
extern s16 g_p2_lives_as_s16;

void func_0013E790(void) {
    u16 temp_a0;

    temp_a0 = g_p2_lives_as_s16;
    if (temp_a0 != 0x14) {
        g_p2_lives_as_s16 = temp_a0 + 1;
        func_001AC5F0(temp_a0);
    }
}

s32 func_0013F9A0();
extern s16 D_0028E014_as_s16;
extern s16 D_0028E024_as_s16;
extern s32 D_0029CD94[];
void func_0013E7C0(void) {
    u16 temp_a0;

    if (g_player1[0] < 0) {
        func_0013F9A0();
        D_0028E024_as_s16 = 0;
        D_0028E014_as_s16 = 0;
        if (!(D_0029F261[0] & 0x40) && (D_0029CD94[0] != 0)) {
            temp_a0 = D_0028E074;
            if (temp_a0 != 8) {
                D_0028E074 = temp_a0 + 4;
                func_0013E8E0(temp_a0);
                D_0028E068 -= 1;
                D_0028E06C = D_0028E068;
            }
        }
    }
}

s32 func_0013FB20();
extern s16 D_0028E010_as_s16;
extern s16 D_0028E020_as_s16;
extern s32 D_0029CD84[];
void func_0013E850(void) {
    u16 temp_a0;

    if (g_player2[0] < 0) {
        func_0013FB20();
        D_0028E020_as_s16 = 0;
        D_0028E010_as_s16 = 0;
        if (!(D_0029F1F1[0] & 0x40) && (D_0029CD84[0] != 0)) {
            temp_a0 = D_0028E070;
            if (temp_a0 != 8) {
                D_0028E070 = temp_a0 + 4;
                func_0013E970(temp_a0);
                D_0028E060 -= 1;
                D_0028E064 = D_0028E060;
            }
        }
    }
}

s32 func_001A3130();
extern u8 D_00255580[];

void func_0013E8E0() {
    reg_a1 = D_00255580;
    reg_d0.h[0] = D_0028E074;
    reg_d0.h[0] *= 2;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    func_001A3130();
}

extern u8 D_002555A0[];

void func_0013E970() {
    reg_a1 = D_002555A0;
    reg_d0.h[0] = D_0028E070;
    reg_d0.h[0] *= 2;
    reg_a1 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a0 = (u8 *)reg_tmp.w;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    func_001A3130();
}

extern u8 D_0029F29F[];

void func_0013EA00(void) {
    reg_d0.b[0] = 0x50;
    if (D_0028E855 & 4) {
        reg_d0.b[0] = 0x78;
    }
    D_0029F29F[0] = reg_d0.b[0];
}

extern u8 D_0029F22F[];

void func_0013EA30(void)
{
    u32 destinationAddress;

    reg_d0.b[0] = 0x50;
    if (D_0028E855 & 4) {
        reg_d0.b[0] = 0x78;
    }

    destinationAddress = (u32)D_0029F22F;
    *(u8 *)destinationAddress = reg_d0.b[0];
    *(u8 *)destinationAddress = 0x50;
}

void func_0013EA70(void) {
    g_player1_as_u8_a[0] &= 0xFE;
    func_0013C980();
}


void func_0013EA90(void) {
    g_player2_as_u8_a[0] &= 0xFE;
    func_0013CA90();
}

void func_0013EAB0() {
    reg_d4.sw = 0x02D8000A;
    reg_d1.h[0] = 0;
    reg_d7.sh[0] = 0x100;
}

void func_0013EAD0() {
    reg_d1.h[0] = 0x1B00;
    reg_d4.sw = 0x02D8008A;
    reg_d7.h[0] = 0xFE00;
}

extern u32 reg_save_d4;
extern u32 reg_save_d3;
extern u32 reg_save_d2;
extern u32 reg_save_d1;
extern s32 *reg_save_a6_as_s32_p;
extern s32 g_player1_as_s32_a[];

void func_0013EAF0(void) {
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a6_as_s32_p = (s32 *)reg_a6;
    func_0013EAB0(reg_d6.w, reg_d2.w, reg_d1.w, reg_d0.w);
    reg_a6 = (u8 *)g_player1_as_s32_a;
    func_0013EC50();
}

extern s32 g_player2_as_s32_a[];

void func_0013EB60(void) {
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a6_as_s32_p = (s32 *)reg_a6;
    func_0013EAD0(reg_d6.w, reg_d2.w, reg_d1.w, reg_d0.w);
    reg_a6 = (u8 *)g_player2_as_s32_a;
    func_0013EC50();
}

extern s32 reg_save_a6_as_s32;

void func_0013EBD0(void) {
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a6_as_s32 = (s32)reg_a6;
    func_0013EAB0(reg_d6.w, reg_d2.w, reg_d1.w, reg_d0.w);
    if (*(u8 *)(reg_a5 + 6) != 0) {
        func_0013EAD0();
    }
    func_0013EC50();
}

s32 deferred_text_put();
s32 deferred_text_put_sheet();
extern void *reg_save_a6_as_void_p;

void func_0013EC50(void) {
    u32 tmp;

    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 0;
    reg_d5.h[0] = 2;
    deferred_text_put_sheet();
    reg_d1.h[0] += reg_d7.h[0];
    if ((s16) reg_d7.h[0] < 0) goto next_1;
    reg_d7.h[0] *= 2;
next_1:
    reg_d3.w = 1;
    reg_d6.w = 5;
    reg_d5.w = 0;
    reg_d5.b[0] = *(u8 *) (reg_a6 + 0x24);
    reg_d6.b[0] -= reg_d5.b[0];
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_d5.b[0] = *(u8 *) (reg_a6 + 0x25);
    if (reg_d5.b[0] == 0) goto next_2;
    reg_d4.w = 0x02CC000A;
loop_1:
    deferred_text_put();
    reg_d1.h[0] += reg_d7.h[0];
    reg_d5.w -= 0x10001;
    if (reg_d5.h[0] != 0) goto loop_1;
next_2:
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] = reg_d5.h[1];
    reg_d5.h[1] = reg_tmp5.h[0];
    reg_tmp5.h[0] = reg_d5.h[0];
    reg_d5.h[0] -= 1;
    if (reg_tmp5.h[0] == 0) goto next_3;
    reg_d4.w = 0x02C0000A;
loop_2:
    deferred_text_put();
    reg_d1.h[0] += reg_d7.h[0];
    tmp = reg_d5.h[0] - 1;
    reg_d5.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_2;
next_3:
    if ((s8) reg_d6.b[0] < 0) goto next_4;
    reg_d4.w = 0x02C6000A;
loop_3:
    deferred_text_put();
    reg_d1.h[0] += reg_d7.h[0];
    tmp = reg_d6.h[0] - 1;
    reg_d6.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) goto loop_3;
next_4:
    reg_d4.w = 0x02D2000A;
    deferred_text_put();
    reg_d0.w = reg_save_d0;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a6 = (u8 *)reg_save_a6_as_void_p;
}

extern Reg32 reg_d1;

void func_0013EE50(void) {
    reg_d1.h[0] = 0x100;
    reg_d4.sw = 0x2CC000A;
    func_0013EEA0();
}


void func_0013EE70(void) {
    u16 saved = reg_d6.h[0];
    reg_d1.h[0] = 0x1900;
    reg_d4.sw = 0x02CC000A;
    reg_d6.h[0] = (saved << 16) - saved;
    func_0013EEA0();
}

void func_0013EEA0(void) {
    s16 temp_a0;

    temp_a0 = (s16) reg_d6.h[0];
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 1;
    reg_d6.h[0] = temp_a0 << 9;
    reg_d1.h[0] += reg_d6.h[0];
    deferred_text_put(temp_a0);
}

void func_0013EEE0(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    func_0013EAB0();
    reg_d3.w = 0;
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d5.h[0] = 2;
    deferred_text_put_sheet();
    reg_d3.w = 1;
    reg_d1.h[0] += 0x100;
    reg_d4.w = 0x02C6000A;
    reg_d7.w = 5;
    do {
        deferred_text_put();
        reg_d1.h[0] += 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d4.w = 0x02D2000A;
    deferred_text_put();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

void func_0013F000(void) {
    u32 save_d0;
    u32 save_d1;
    u32 save_d2;
    u32 save_d3;
    u32 save_d4;
    u32 save_d5;
    u32 save_d6;
    u32 save_d7;

    save_d0 = reg_d0.w;
    save_d1 = reg_d1.w;
    save_d2 = reg_d2.w;
    save_d3 = reg_d3.w;
    save_d4 = reg_d4.w;
    save_d5 = reg_d5.w;
    save_d6 = reg_d6.w;
    save_d7 = reg_d7.w;
    func_0013EAD0();
    reg_d3.w = 0;
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d5.h[0] = 2;
    deferred_text_put_sheet();
    reg_d3.w = 1;
    reg_d1.h[0] -= 0x200;
    reg_d4.w = 0x02C6000A;
    reg_d7.w = 5;
    do {
        deferred_text_put();
        reg_d1.h[0] -= 0x200;
    } while ((s16)(--reg_d7.h[0]) >= 0);
    reg_d4.w = 0x02D2000A;
    deferred_text_put();
    reg_d0.w = save_d0;
    reg_d1.w = save_d1;
    reg_d2.w = save_d2;
    reg_d3.w = save_d3;
    reg_d4.w = save_d4;
    reg_d5.w = save_d5;
    reg_d6.w = save_d6;
    reg_d7.w = save_d7;
}

extern s32 reg_save_a0;

void func_0013F120(void)
{
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = (s32)reg_a0;

    reg_d1.h[0] = 0x100;
    reg_d4.w = 0;
    *(u8 *)&reg_d4.w = D_0029F284[0];
    func_0013F200();
}

void func_0013F190(void)
{
    reg_save_d0 = reg_d0.w;
    reg_save_d1 = reg_d1.w;
    reg_save_d2 = reg_d2.w;
    reg_save_d3 = reg_d3.w;
    reg_save_d4 = reg_d4.w;
    reg_save_d5 = reg_d5.w;
    reg_save_d6 = reg_d6.w;
    reg_save_d7 = reg_d7.w;
    reg_save_a0 = (s32)reg_a0;

    reg_d1.h[0] = 0xF00;
    reg_d4.w = 0;
    *(u8 *)&reg_d4.w = D_0029F214[0];
    func_0013F200();
}

extern u8 D_00255550[];

void func_0013F200(void) {
    reg_d0.h[0] = 8;
    reg_d2.w = 2;
    reg_d3.w = 0xB;
    reg_d4.h[0] -= 1;
    reg_d4.w = *(u32 *)(D_00255550 + (reg_d4.h[0] * 4));
    deferred_text_put();
    reg_d0.w = reg_save_d0;
    reg_d1.w = reg_save_d1;
    reg_d2.w = reg_save_d2;
    reg_d3.w = reg_save_d3;
    reg_d4.w = reg_save_d4;
    reg_d5.w = reg_save_d5;
    reg_d6.w = reg_save_d6;
    reg_d7.w = reg_save_d7;
    reg_a0 = (u8 *)reg_save_a0;
}

extern s8 D_0028E3F8;

void func_0013F2A0(void) {
    D_0028E3F8 = 1;
    if ((g_p1_hyper_items != 0) || (!(D_0029F261[0] & 0x40) && (D_0029CD90[0] != 0))) {
        func_0013EAF0();
        func_0013F120();
        return;
    }
    func_0013EAF0();
}


void func_0013F310(void) {
    D_0028E3F8 = 1;
    if ((g_p2_hyper_items != 0) || (!(D_0029F1F1[0] & 0x40) && (D_0029CD80[0] != 0))) {
        func_0013EB60();
        func_0013F190();
        return;
    }
    func_0013EB60();
}

extern u8 D_002962E0[];

void func_0013F380(void) {
    if (*(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) != 0) {
        *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) -= 1;
        if (*(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3484, 0x10684)) == 0) {
            *(u16 *)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3486, 0x10686)) = 0;
        }
    }
}

extern u16 D_0029CEBA[];

void func_0013F3C0(void) {
    u16 *counter = (u16 *) &D_0029CEBA[0];

    if (*counter >= 0x14) {
        *counter = 0x14;
    }
}

void func_0013F3F0(void) {
}


void func_0013F400(void) {
    u8 *sv_a0;
    u8 *sv_a1;
    u8 *sv_a2;
    u8 *sv_a3;
    u8 *sv_a4;
    u8 *sv_a5;
    u8 *sv_a6;
    u32 sv_d0;
    u32 sv_d1;
    u32 sv_d2;
    u32 sv_d3;
    u32 sv_d4;
    u32 sv_d5;
    u32 sv_d6;
    u32 sv_d7;

    sv_d0 = reg_d0.w;
    sv_d1 = reg_d1.w;
    sv_d2 = reg_d2.w;
    sv_d3 = reg_d3.w;
    sv_d4 = reg_d4.w;
    sv_d5 = reg_d5.w;
    sv_d6 = reg_d6.w;
    sv_d7 = reg_d7.w;
    sv_a0 = reg_a0;
    sv_a1 = reg_a1;
    sv_a2 = reg_a2;
    sv_a3 = reg_a3;
    sv_a4 = reg_a4;
    sv_a5 = reg_a5;
    sv_a6 = reg_a6;
    if (*(u8 *) (reg_a6 + 0x3E) == 0) goto next_1;
    if (*(u8 *) (reg_a6 + 0x56) != 0) goto next_2;
    func_0013F5A0();
    reg_d0.w = sv_d0;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d5.w = sv_d5;
    reg_d6.w = sv_d6;
    reg_d7.w = sv_d7;
    reg_a0 = sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
    return;
next_2:
    func_0013F580();
next_1:
    reg_d0.w = sv_d0;
    reg_d1.w = sv_d1;
    reg_d2.w = sv_d2;
    reg_d3.w = sv_d3;
    reg_d4.w = sv_d4;
    reg_d5.w = sv_d5;
    reg_d6.w = sv_d6;
    reg_d7.w = sv_d7;
    reg_a0 = sv_a0;
    reg_a1 = sv_a1;
    reg_a2 = sv_a2;
    reg_a3 = sv_a3;
    reg_a4 = sv_a4;
    reg_a5 = sv_a5;
    reg_a6 = sv_a6;
}

extern u8 D_0029CE20[];
extern u8 D_0029CDA0[];


void func_0013F580(void) {
    reg_a0 = D_0029CE20;
    reg_a1 = D_0029CDA0;
    func_0013F5C0();
}

extern s32 D_0029CDE0[];
extern s32 D_0029CE60[];


void func_0013F5A0(void) {
    reg_a0 = (u8 *)((s32)&D_0029CE60[0]);
    reg_a1 = (u8 *)((s32)&D_0029CDE0[0]);
    func_0013F5C0();
}

void func_0019D8B0(void);

void func_0013F5C0(void) {
    u32 tmp;

    reg_d3.h[0] = 0x620;
    reg_d4.h[0] = 0x1F;
    reg_a2 = reg_a0;
    reg_a3 = reg_a1;
    reg_d6.h[1] = ENTITY(reg_a6)->y.h;
    reg_d6.h[0] = ENTITY(reg_a6)->x.h;
    reg_d6.w &= 0xFF80FF80;
    reg_a1 += 0x40;
    reg_a0 += 0x40;
    reg_d7.w = 5;
    goto loop_2;
loop_1:
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
loop_2:
    *(u16 *)(reg_a1 - 4) = *(u16 *)(reg_a1 - 8);
    *(u16 *)(reg_a1 - 2) = *(u16 *)(reg_a1 - 6);
    reg_a1 -= 4;
    *(u16 *)(reg_a0 - 4) = *(u16 *)(reg_a0 - 8);
    *(u16 *)(reg_a0 - 2) = *(u16 *)(reg_a0 - 6);
    reg_a0 -= 4;
    if (reg_d7.h[0] == 0) {
        *(u16 *)(reg_a3 + 0) = ENTITY(reg_a6)->draw.h;
        *(u16 *)(reg_a3 + 2) = ENTITY(reg_a6)->sprite.h;
        *(u16 *)(reg_a2 + 0) = ENTITY(reg_a6)->y.h;
        *(u16 *)(reg_a2 + 2) = ENTITY(reg_a6)->x.h;
        return;
    }
    if (D_0028E3EC == 0) {
        goto next_1;
    }
    reg_d1.h[1] = *(u16 *)(reg_a0 + 0);
    reg_d1.h[0] = *(u16 *)(reg_a0 + 2);
    reg_d5.w = reg_d1.w;
    reg_d5.w &= 0xFF80FF80;
    if (reg_d6.w == reg_d5.w) {
        goto next_1;
    }
    reg_d1.w += 0xFA00FC00;
    reg_d2.h[1] = *(u16 *)(reg_a1 + 0);
    reg_d2.h[0] = *(u16 *)(reg_a1 + 2);
    func_0019D8B0();
next_1:
    tmp = reg_d7.h[0] - 1;
    reg_d7.h[0] = tmp;
    if (((s64) ((s64) (tmp & 0xFFFF) << 0x30) >> 0x30) >= 0) {
        goto loop_1;
    }
}

extern u8 D_0029CDE0_as_u8_a[];
extern u8 D_0029CE60_as_u8_a[];

void func_0013F800(void) {
    u8 *temp_a1;
    u8 *temp_a2;
    u8 *temp_a3;

    temp_a3 = reg_a0;
    temp_a2 = reg_a1;
    temp_a1 = reg_a2;
    reg_save_d0 = reg_d0.w;
    reg_save_a0_as_u8_p = temp_a3;
    reg_save_a1 = temp_a2;
    reg_save_a2 = temp_a1;
    reg_a0 = D_0029CE60_as_u8_a;
    reg_a1 = D_0029CDE0_as_u8_a;
    reg_a2 = g_player1_as_u8_a;
    func_0013F8A0();
}

void func_0013F850(void) {
    u8 *temp_a1;
    u8 *temp_a2;
    u8 *temp_a3;

    temp_a3 = reg_a0;
    temp_a2 = reg_a1;
    temp_a1 = reg_a2;
    reg_save_d0 = reg_d0.w;
    reg_save_a0_as_u8_p = temp_a3;
    reg_save_a1 = temp_a2;
    reg_save_a2 = temp_a1;
    reg_a0 = D_0029CE20;
    reg_a1 = D_0029CDA0;
    reg_a2 = g_player2_as_u8_a;
    func_0013F8A0();
}

extern void *reg_save_a2_as_void_p;
extern u16 *reg_save_a1_as_u16_p;
extern u16 *reg_a1_as_u16_p;

void func_0013F8A0(void) {
    reg_d0.w = 0xF;
    do {
        *reg_a0_as_u16_p = *(u16 *)(reg_a2 + 2);
        reg_a0_as_u16_p += 1;
        *reg_a0_as_u16_p = *(u16 *)(reg_a2 + 4);
        reg_a0_as_u16_p += 1;
        *reg_a1_as_u16_p = *(u16 *)(reg_a2 + 0xA);
        reg_a1_as_u16_p += 1;
        *reg_a1_as_u16_p = *(u16 *)(reg_a2 + 0xC);
        reg_a1_as_u16_p += 1;
    } while ((s16)(--reg_d0.h[0]) >= 0);
    reg_d0.w = reg_save_d0;
    reg_a0_as_u16_p = reg_save_a0_as_u16_p;
    reg_a1_as_u16_p = reg_save_a1_as_u16_p;
    reg_a2 = reg_save_a2_as_void_p;
}

void func_0013F960(void) {
    u16 *speed_field = (u16 *)(reg_a4 + 0x60);
    u16 speed = *speed_field;

    if (speed != 0x80) {
        *speed_field = speed + 4;
    }
}
