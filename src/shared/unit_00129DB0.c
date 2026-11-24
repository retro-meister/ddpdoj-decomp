#include "common.h"
#include "entity.h"

void func_00129EF0(void);
void func_0012D810(void);
void func_0012D960(void);
void func_0012D980(void);
void func_0012D9B0(void);
void func_0012D9F0(void);
void func_0012DA10(void);
void func_0012DA30(void);
void func_0012DB30(void);
void func_0012DCC0(void);
void func_0012E3D0(void);

s32 func_00129BE0();
extern s16 D_0024F330[];
extern u8 *D_0028DEAC;
extern u16 D_0028E158;
extern u16 D_0028E15C;
extern s8 D_0028E310_as_s8;
extern u8 D_0028E37C;
extern u8 D_0028E855;
extern u16 g_loop;
extern u16 g_stage;
extern s16 D_00299760_as_s16_a[];
extern u8 D_002962E0[];
#ifdef DEATH_LABEL
extern s16 death_D_002512A0[];
extern s16 death_D_002512B0[];
#endif
extern u8 D_002A4670[];
extern u8 D_002A5050[];

void func_00129DB0(void) {
    func_00129BE0();
    D_00299760_as_s16_a[0] = 0;
    reg_a4 = (u8 *)D_002A4670;
    reg_a0 = (u8 *)D_002A5050;
    D_0028DEAC = (u8 *)(reg_a4);
    reg_a0 += D_0028E15C;
    *(u8 **)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3490, 0x10690)) = reg_a0;
    func_00129EF0();
    reg_d1.w = (u32) D_002A5050;
    reg_d0.w = (u32) *(u8 **)(D_002962E0 + MAIN_OR_DEATH_LABEL(0x3490, 0x10690));
    reg_d0.w -= reg_d1.w;
    reg_a4 = (u8 *)((u32)reg_a4 - (u32)D_0028DEAC);
    reg_tmp.w = (u32) reg_a4;
    D_0028E15C = reg_d0.h[0];
    D_0028E158 = reg_tmp.h[0];
#ifdef DEATH_LABEL
    if (D_0028E37C != 0) {
        s16 *limit;

        if (g_loop == 0) {
            limit = &death_D_002512A0[g_stage];
        } else {
            limit = &death_D_002512B0[g_stage];
        }
        reg_tmp.h[0] = (s16) D_0028E158 + (s16) D_0028E15C;
        reg_tmp.h[0] /= 0xC;
        if ((D_0028E855 & 2) && (reg_tmp.h[0] >= *limit)) {
            D_0028E37C |= 0x80;
            D_0028E310_as_s8 = 1;
        }
    }
#else
    if (D_0028E37C != 0) {
        reg_tmp.h[0] = (s16) D_0028E158 + (s16) D_0028E15C;
        reg_tmp.h[0] /= 0xC;
        if ((D_0028E855 & 2) && (g_loop != 0) && (reg_tmp.h[0] > D_0024F330[g_stage])) {
            D_0028E310_as_s8 = 2;
        }
    }
#endif
}

extern u8 D_0024EB30[];
extern u8 D_0024EE90[];
void func_00125EE0();
#ifdef DEATH_LABEL
void death_func_00128A90();
#endif
void func_00128640();
void bullet_fire256_direct();
void bullet_spawn256();
void func_0014E030();
void func_00202760();
void func_00203330();
extern u8 D_0024E7D0_as_u8_a[];
extern u8 D_0024F0F0[];
extern u8 D_00262570[];
extern u32 D_0028DEA4;
extern u16 D_0028E3EC;
extern u16 D_0028E854_as_u16;
extern u16 g_enemy_signal_2;
#ifdef DEATH_LABEL
extern u8 death_D_00290858;
extern u8 death_D_0029085C;
#endif
extern u16 D_00299760[];
extern u16 D_00299762[];
extern u16 D_00299768_as_u16_a[];
extern u16 D_0029976A_as_u16_a[];
extern u16 D_0029976C[];
extern u16 D_0029976E[];
extern u8 *D_00299770[];
extern u16 D_0029C06C[];
extern u8 D_0029CEA0_as_u8_a[];
extern void (*jtbl_0028E3F4)();
extern u16 *reg_a4_as_u16_p;

#define SLOT_PHASE MAIN_OR_DEATH_LABEL(D_00299762[0], *(u16 *)(D_002962E0 + 0x10682))
#define SLOT_CURSOR MAIN_OR_DEATH_LABEL(D_00299770[0], *(u8 **)(D_002962E0 + 0x10690))

void func_00129EF0(void) {
    u8 *var_a0;
    u8 *var_a0_4;
    u8 *var_a1;
    u8 *var_a2;
    s32 temp_a0_16;
    s32 temp_a1_5;
    s32 temp_a1_6;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_a2_5;
    s64 temp_a1;
    s64 temp_v1_57;
    s8 var_v0;
    s8 var_v0_2;
    s8 var_v0_3;
    u16 temp_a0_11;
    u16 temp_a0_13;
    u16 temp_a0_14;
    u16 temp_a0_15;
    u16 temp_a0_18;
    u16 temp_a0_2;
    u16 temp_a1_4;
    u16 temp_a1_8;
    u16 temp_a2;
    u16 temp_a2_2;
    u16 temp_a3;
    u16 temp_v0;
    u16 temp_v1;
    u16 temp_v1_10;
    u16 temp_v1_11;
    u16 temp_v1_13;
    u16 temp_v1_14;
    u16 temp_v1_15;
    u16 temp_v1_16;
    u16 temp_v1_17;
    u16 temp_v1_18;
    u16 temp_v1_19;
    u16 temp_v1_20;
    u16 temp_v1_21;
    u16 temp_v1_22;
    u16 temp_v1_23;
    u16 temp_v1_24;
    u16 temp_v1_25;
    u16 temp_v1_26;
    u16 temp_v1_27;
    u16 temp_v1_28;
    u16 temp_v1_29;
    u16 temp_v1_2;
    u16 temp_v1_30;
    u16 temp_v1_31;
    u16 temp_v1_32;
    u16 temp_v1_33;
    u16 temp_v1_35;
    u16 temp_v1_36;
    u16 temp_v1_38;
    u16 temp_v1_39;
    u16 temp_v1_3;
    u16 temp_v1_40;
    u16 temp_v1_41;
    u16 temp_v1_44;
    u16 temp_v1_45;
    u16 temp_v1_47;
    u16 temp_v1_48;
    u16 temp_v1_49;
    u16 temp_v1_4;
    u16 temp_v1_50;
    u16 temp_v1_51;
    u16 temp_v1_52;
    u16 temp_v1_54;
    u16 temp_v1_55;
    u16 temp_v1_56;
    u16 temp_v1_58;
    u16 temp_v1_59;
    u16 temp_v1_5;
    u16 temp_v1_60;
    u16 temp_v1_61;
    u16 temp_v1_62;
    u16 temp_v1_6;
    u16 temp_v1_7;
    u16 temp_v1_8;
    u16 temp_v1_9;
    u16 var_a0_3;
    u32 temp_a0;
    u32 temp_a1_2;
    u32 temp_a1_3;
    u8 temp_a0_10;
    u8 temp_a0_12;
    u8 temp_a0_17;
    u8 temp_a0_3;
    u8 temp_a0_4;
    u8 temp_a0_5;
    u8 temp_a0_6;
    u8 temp_a0_7;
    u8 temp_a0_8;
    u8 temp_a0_9;
    u8 temp_a1_7;
    u8 temp_a1_9;
    u8 temp_v1_12;
    u8 temp_v1_34;
    u8 temp_v1_37;
    u8 temp_v1_42;
    u8 temp_v1_43;
    u8 temp_v1_46;
    u8 temp_v1_53;
    u8 var_a0_2;
    u8 *temp_a3_2;
    u8 *var_a1_2;


    reg_a6 = D_002962E0;
    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x45, 0x15D);
    reg_d6.h[0] = D_0029C06C[0];
    if (D_00299768_as_u16_a[0] != 0) {
        reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x6D, 0x225);
        if (D_0029976A_as_u16_a[0] != 0) {
            reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0x9F, 0x31F);
            if (D_0029976C[0] != 0) {
                reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xBD, 0x3B5);
                if (D_0029976E[0] != 0) {
                    reg_d7.h[0] = MAIN_OR_DEATH_LABEL(0xD1, 0x419);
                }
            }
        }
    }
    goto loop_10;

L_bom_bui:
    reg_d1.h[0] = *(u16 *)D_0029CEA0_as_u8_a;
    if ((reg_d1.h[0] != 0) && (reg_d1.w & 1) && (0 <= (s64)(s16)D_0028E854_as_u16)) {
        goto block_12;
    }
    reg_d0.w = 0;
    D_0028DEA4 = reg_d7.w;
    MAIN_OR_DEATH_LABEL(func_00125EE0, death_func_00128A90)();
    reg_d7.w = D_0028DEA4;
    func_00128640();

block_9:
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

loop_10:
    reg_d2.h[0] = ENTITY(reg_a6)->flags.h;
    if ((s16)reg_d2.h[0] >= 0) {
        goto block_9;
    }
    D_00299760[0] += 1;
    reg_d1.h[0] = *(u16 *)D_0029CEA0_as_u8_a;
    if ((s16)(reg_d1.h[0] |= (s16)D_0028E854_as_u16) < 0) {
        goto L_bom_bui;
    }

block_12:
    reg_d0.h[0] = 0x5180;
    reg_d0.h[0] &= reg_d2.h[0];
    if (reg_d0.h[0] != 0) {
        goto L_not_plain;
    }
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    reg_d0.h[0] -= reg_d6.h[0];
    ENTITY(reg_a6)->x.h += reg_d0.h[0];
    ENTITY(reg_a6)->y.h += reg_d0.h[1];
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0xC800;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.w = reg_d0.w;
    temp_v0 = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d0.h[1] = temp_v0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    reg_a1 = (u8 *)((u32)reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_d0.w = (u32)((s32)reg_d0.w >> 6);
    temp_a1_2 = reg_d0.w;
    reg_d0.w = temp_a1_2 & 0x07FF03FF;
    temp_a0 = reg_d0.w;
    reg_d0.w = temp_a0 | 0x80008000;
    *reg_a4_as_u16_p = reg_d0.h[1];
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = reg_d0.h[0];
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a1 + 0);
    reg_a1 += 2;
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a1 + 0);
    reg_a4_as_u16_p += 1;
    *reg_a4_as_u16_p = *(u16 *)(reg_a6 + 0x1C);
    reg_a4_as_u16_p += 1;
    func_0012DCC0();
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    goto block_44;

block_16:
    func_00128640();
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_not_plain:
    if (reg_d2.w & 0x1000) {
        goto block_16;
    }
    ENTITY(reg_a6)->x.h -= reg_d6.h[0];
    if (0 > (s64)(s16)reg_d2.b[0]) {
        goto L_0012A4B0;
    }
    if (!(reg_d2.w & 0x100)) {
        goto L_0012A68C;
    }
    temp_a0 = reg_d6.h[0]; ENTITY(reg_a6)->x.h += temp_a0;
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_0012DA30();
    *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
    *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
    reg_d0.w = 0x3F;
    reg_d0.h[0] &= ENTITY(reg_a6)->flags.h;
    reg_a0 = D_0024EB30;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = (void (*)())reg_a0;
    jtbl_0028E3F4();
    SLOT_PHASE += 1;
    if (SLOT_PHASE == 3) {
        SLOT_PHASE = 0;
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_0012A4B0:
    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0xC800;
    reg_tmp.w = 0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0xC800;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    reg_tmp1.w = 0;
    reg_tmp1.h[0] = 0x9000;
    reg_tmp.w = reg_d0.w;
    temp_v0 = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_tmp.w = 0;
    reg_d0.h[1] = temp_v0;
    reg_tmp.h[0] = reg_d0.h[0];
    reg_tmp.w += reg_tmp1.w;
    reg_d0.h[0] += 0x9000;
    if (reg_tmp.h[1] != 0) {
        goto block_16;
    }
    if (reg_d2.w & 0x100) {
        goto L_0012A5DC;
    }
    reg_d0.w = 0;
    reg_d1.w = 0;
    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    func_0012DA30();
    ENTITY(reg_a6)->y.h += reg_d2.h[0];
    ENTITY(reg_a6)->x.h += reg_d3.h[0];
    func_0012DB30();
    if ((ENTITY(reg_a6)->flags.b[1]) & 0x40) {
        goto block_33;
    }
    reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x22);
    reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x24);
    goto block_44;

L_0012A5DC:
    reg_d0.w = 0x3F;
    reg_d0.h[0] &= ENTITY(reg_a6)->flags.h;
    reg_a0 = D_0024EB30;
    reg_d0.h[0] += reg_d0.h[0];
    reg_d0.h[0] += reg_d0.h[0];
    reg_a0 += reg_d0.h[0];
    reg_tmp.h[1] = *(u16 *)(reg_a0 + 0);
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_a0 = (u8 *)reg_tmp.w;
    jtbl_0028E3F4 = (void (*)())reg_a0;
    jtbl_0028E3F4();
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

L_0012A68C:
    reg_d0.h[1] = *(u16 *)(reg_a6 + 0x1E);
    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x20);
    ENTITY(reg_a6)->x.h += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    func_0012DB30();

block_33:
    temp_a0_17 = ENTITY(reg_a6)->flags.b[1];
    var_a1_2 = reg_a6 + 1;
    if (temp_a0_17 & 0x20) {
        ENTITY(reg_a6)->flags.b[1] = (u8)(temp_a0_17 | 0x20);
    } else {
        ENTITY(reg_a6)->flags.b[1] = (u8)(temp_a0_17 | 0x20);
        reg_tmp.w = 0x24F;
        ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
        ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
        reg_d0.h[0] = ENTITY(reg_a6)->flags.h;
        reg_a1 = D_0024E7D0_as_u8_a;
        reg_d0.h[0] &= 0x3F;
        reg_d0.h[0] += reg_d0.h[0];
        reg_d0.h[0] += reg_d0.h[0];
        reg_a1 += reg_d0.h[0];
        reg_tmp.h[1] = *(u16 *)(reg_a1 + 0);
        reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
        reg_a1 = (u8 *)reg_tmp.w;
        if (*(u16 *)(reg_a1 - 2) == 1) {
            reg_tmp.w = 0x23F;
            ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
            ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
        }
        ENTITY(reg_a6)->look.sh = 0x410;
        reg_tmp.w = 0xFC00FE00;
        ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
        var_a1_2 = (void *)reg_tmp.h[0];
        ENTITY(reg_a6)->offset_x.h = (u16)var_a1_2;
        ENTITY(reg_a6)->hit_x_minus.h = 0x10U;
        *(u16 *)(reg_a6 + 0x1E) = (u16)((s16)*(u16 *)(reg_a6 + 0x1E) >> 1);
        *(u16 *)(reg_a6 + 0x20) = (u16)((s16)*(u16 *)(reg_a6 + 0x20) >> 1);
    }
    reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
    reg_tmp.w += 1;
    ENTITY(reg_a6)->draw.h = reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = reg_tmp.h[0];
    ENTITY(reg_a6)->hit_x_minus.h -= 1;
    if (ENTITY(reg_a6)->hit_x_minus.h == 0) {
        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x3C);
        if ((s16)reg_d0.h[0] >= 0) {
            D_0028DEA4 = reg_d7.w;
            MAIN_OR_DEATH_LABEL(func_00125EE0, death_func_00128A90)();
            reg_d7.w = D_0028DEA4;
        }
        func_00128640();
    }
    reg_a6 += 0x40;
    if ((s16)(--reg_d7.h[0]) >= 0) {
        goto loop_10;
    }
    return;

block_44:
    switch (reg_tmp.w) {
    default:
        return;
                            case 0:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x146) {
                                    reg_tmp.w = 0x140;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 1:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x146) {
                                    reg_tmp.w = 0x146;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 3:                 /* switch 1 */
                                temp_a0_3 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_3 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_3 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_3 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1A2;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x19E;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 4:                 /* switch 1 */
                                temp_a0_4 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_4 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_4 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_4 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1A6;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1A2;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 5:                 /* switch 1 */
                                temp_a0_5 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_5 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_5 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_5 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1AA;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1A6;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 6:                 /* switch 1 */
                                temp_a0_6 = ENTITY(reg_a6)->flags.b[1];
                                if (temp_a0_6 & 8) {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_6 & 0xF7;
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = temp_a0_6 | 8;
                                    reg_tmp.w = 1;
                                    reg_a1 -= 4;
                                    reg_tmp1.h[1] = *(u16 *)reg_a1;
                                    reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w += reg_tmp.w;
                                    *(u16 *)reg_a1 = (u16) reg_tmp1.h[1];
                                    *(u16 *)(reg_a1 + 2) = reg_tmp1.h[0];
                                    reg_tmp.h[1] = *(u16 *)reg_a1;
                                    reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                    reg_tmp1.w = 0x1AE;
                                    if (reg_tmp1.w == reg_tmp.w) {
                                        reg_tmp.w = 0x1AA;
                                        *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                        *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 7:                 /* switch 1 */
                                temp_v1_12 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_12 == 0) {
                                    reg_a6 += 0xA;
                                    reg_d0.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_a0 = reg_a6 + 6;
                                    reg_d0.w += 1;
                                    temp_a1_4 = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_tmp.h[1] = temp_a1_4;
                                    reg_tmp.h[0] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    if (reg_tmp.w == reg_d0.w) {
                                        reg_tmp.h[1] = *(u16 *)reg_a0;
                                        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
                                        reg_d0.w -= reg_tmp.w;
                                    }
                                    reg_a0 += 4;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
                                    *(u8 *)(reg_a0 + 0) = *(u8 *)(reg_a0 + 1);
                                    reg_a0 += 2;
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_12 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 8:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x1EA) {
                                    reg_tmp.w = 0x1E6;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 9:                 /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x1BD) {
                                    reg_tmp.w = 0x1B9;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 10:                /* switch 1 */
                                reg_a6 += 0xA;
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                if (reg_tmp.w == 0x1C3) {
                                    reg_tmp.w = 0x1BF;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 11:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == 0x224) {
                                    reg_tmp.w = 0x220;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 12:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == 0x212) {
                                    reg_tmp.w = 0x20E;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 13:                /* switch 1 */
                                reg_a1 -= 4;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == 0x218) {
                                    reg_tmp.w = 0x214;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 16:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
                                ENTITY(reg_a6)->look.sh = 0x410;
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 17:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
                                ENTITY(reg_a6)->look.sh = 0x410;
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2B);
                                *(u8 *)(reg_a6 + 0x2B) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2B) = (u8) *(u8 *)(reg_a6 + 0x2A);
                                    reg_d0.b[0] = *(u8 *)(reg_a6 + 0x35);
                                    ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
                                }
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                *(u8 *)(reg_a6 + 0x2D) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                    ENTITY(reg_a6)->move.b.speed += 1;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 18:                /* switch 1 */
                                reg_tmp.w = 0x1A6;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0xFC00FE00;
                                ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
                                ENTITY(reg_a6)->look.sh = 0x410;
                                *(u16 *)(reg_a6 + 0x34) -= 1;
                                if (0 > (s64)*(s16 *)(reg_a6 + 0x34)) {
                                    reg_d0.w = 0x35;
                                    func_0014E030();
                                    *(u16 *)(reg_a0 + 0x16) = (u16) ENTITY(reg_a6)->y.h;
                                    *(u16 *)(reg_a0 + 0x18) = (u16) ENTITY(reg_a6)->x.h;
                                    goto block_16;
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 19:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a0_3 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_3 = 1 << reg_d0.b[0];
                                if (temp_a2_3 & temp_a0_3) {
                                    temp_a0_7 = ENTITY(reg_a6)->flags.b[1];
                                    if (temp_a0_7 & temp_a2_3) {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_7 & (~temp_a2_3 & 0xFF));
                                        goto block_144;
                                    }
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_7 | (temp_a2_3 & 0xFF));
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    reg_tmp.w = 0x297;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    if (reg_tmp.w == reg_tmp1.w) {
                                        reg_tmp.w = 0x287;
                                        ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_d1.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                if (reg_d1.w != 0) {
                                    reg_a0 = (u8 *) reg_d1.w;
                                    if ((0 > (s64)*(s16 *)(reg_a0 + 0)) && (0 <= (s64)*(s8 *)(reg_a0 + 0))) {
                                        reg_d1.h[1] = *(u16 *)(reg_a0 + 2);
                                        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
                                        reg_tmp.h[1] = *(u16 *)(reg_a6 + 0x28);
                                        reg_tmp.h[0] = *(u16 *)(reg_a6 + 0x2A);
                                        reg_d1.w += reg_tmp.w;
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
                                        temp_a0_8 = ENTITY(reg_a6)->flags.b[1];
                                        temp_a1_5 = 1 << reg_d0.b[0];
                                        if (temp_a0_8 & temp_a1_5) {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_8 & (~temp_a1_5 & 0xFF));
                                        } else {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_8 | (temp_a1_5 & 0xFF));
                                            reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                            reg_tmp.w += 1;
                                            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                            ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                            reg_tmp.w = 0x288;
                                            reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                            if (reg_tmp.w != reg_tmp1.w) {
                                                goto block_144;
                                            }
                                            goto block_143;
                                        }
                                        goto block_144;
                                    }
                                    goto L_clr_block_143;
                                }
block_143:
                                *(u8 *)(reg_a6 + 0x35) |= 8;
                                *(u16 *)(reg_a6 + 0x1E) = (u16) *(u16 *)(reg_a6 + 0x30);
                                *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
block_144:
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
L_clr_block_143:
                                func_00128640();
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 20:                /* switch 1 */
                                reg_a6 += 0xA;
                                if (D_0028E3EC != 0) {
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    if (reg_tmp.w == 0x1B4) {
                                        reg_tmp.w = 0x1AE;
                                        ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    }
                                }
                                reg_a6 += 0x36;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 22:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a0_4 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_4 = 1 << reg_d0.b[0];
                                if (temp_a2_4 & temp_a0_4) {
                                    temp_a0_9 = ENTITY(reg_a6)->flags.b[1];
                                    if (temp_a0_9 & temp_a2_4) {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_9 & (~temp_a2_4 & 0xFF));
                                        goto block_167;
                                    }
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_9 | (temp_a2_4 & 0xFF));
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    reg_tmp.w = 0x2AB;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    if (reg_tmp.w == reg_tmp1.w) {
                                        reg_tmp.w = 0x29B;
                                        ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                reg_d1.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                reg_d1.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                if (reg_d1.w != 0) {
                                    reg_a0 = (u8 *) reg_d1.w;
                                    if ((0 > (s64)*(s16 *)(reg_a0 + 0)) && (0 <= (s64)*(s8 *)(reg_a0 + 0))) {
                                        reg_d1.h[1] = *(u16 *)(reg_a0 + 2);
                                        reg_d1.h[0] = *(u16 *)(reg_a0 + 4);
                                        reg_tmp1.h[1] = *(u16 *)(reg_a6 + 0x28);
                                        reg_tmp1.h[0] = *(u16 *)(reg_a6 + 0x2A);
                                        reg_d1.w = (u32) (reg_d1.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->x.h = (u16) reg_d1.h[0];
                                        temp_a0_10 = ENTITY(reg_a6)->flags.b[1];
                                        temp_a1_6 = 1 << reg_d0.b[0];
                                        if (temp_a0_10 & temp_a1_6) {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_10 & (~temp_a1_6 & 0xFF));
                                        } else {
                                            ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_10 | (temp_a1_6 & 0xFF));
                                            reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                            reg_tmp.w += 1;
                                            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                            ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                            reg_tmp.w = 0x29C;
                                            reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                            reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                            if (reg_tmp.w != reg_tmp1.w) {
                                                goto block_167;
                                            }
                                            goto block_166;
                                        }
                                        goto block_167;
                                    }
                                    goto L_clr_block_166;
                                }
block_166:
                                *(u8 *)(reg_a6 + 0x35) |= 8;
                                *(u16 *)(reg_a6 + 0x1E) = (u16) *(u16 *)(reg_a6 + 0x30);
                                *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
block_167:
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
L_clr_block_166:
                                func_00128640();
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 23:                /* switch 1 */
                                reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp.w += 1;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                if (reg_tmp.w == 0x224) {
                                    reg_tmp.w = 0x220;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                temp_a0_11 = *(u16 *)(reg_a6 + 0x36);
                                if (temp_a0_11 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_11) {
                                        *(u16 *)(reg_a6 + 0x36) = (u16) (temp_a0_11 - 1);
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                        *(u16 *)(reg_a6 + 0x1E) -= reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 24:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a1_7 = *(u8 *)(reg_a6 + 0x35);
                                temp_a2_5 = 1 << reg_d0.b[0];
                                if (temp_a2_5 & temp_a1_7) {
                                    temp_a0_12 = ENTITY(reg_a6)->flags.b[1];
                                    if (temp_a0_12 & temp_a2_5) {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_12 & (~temp_a2_5 & 0xFF));
                                    } else {
                                        ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a0_12 | (temp_a2_5 & 0xFF));
                                        reg_tmp.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w += 1;
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        reg_tmp.w = 0x2AB;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        if (reg_tmp.w == reg_tmp1.w) {
                                            reg_tmp.w = 0x29B;
                                            ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                            ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        }
                                    }
                                    temp_a0_13 = *(u16 *)(reg_a6 + 0x36);
                                    if (temp_a0_13 != 0) {
                                        if (0 <= (s64)(s16)temp_a0_13) {
                                            *(u16 *)(reg_a6 + 0x36) = (u16) (temp_a0_13 - 1);
                                        }
                                        reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                        *(u8 *)(reg_a6 + 0x2D) -= 1;
                                        if ((s32) reg_tmp.b[0] <= 0) {
                                            *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                            *(u16 *)(reg_a6 + 0x1E) -= reg_d0.h[0];
                                        }
                                    }
                                    reg_a6 += 0x40;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                *(u8 *)(reg_a6 + 0x35) = (u8) (temp_a1_7 | 8);
                                *(u16 *)(reg_a6 + 0x1E) = (u16) *(u16 *)(reg_a6 + 0x30);
                                *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 25:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] *= -1;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_202;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] *= -1;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_202;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if (((s32) reg_d0.h[0] >= 0x600) && ((s32) reg_d0.h[0] > 0x6E00)) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] *= -1;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
block_202:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        func_0012DA30();
                                        *(u16 *)(reg_a6 + 0x1E) = (u16) reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = (u16) reg_d3.h[0];
                                        reg_tmp.w = 0x14;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w = (u32) (reg_tmp.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_34 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_34 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->y.h = reg_tmp1.h[0];
                                    if (reg_tmp1.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_34 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 26:                /* switch 1 */
                                temp_v1_37 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_37 == 0) {
                                    reg_a6 += 0xA;
                                    reg_d0.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_a0 = reg_a6 + 6;
                                    reg_d0.w += 1;
                                    temp_a1_8 = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_tmp.h[1] = temp_a1_8;
                                    reg_tmp.h[0] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    if (reg_d0.w == reg_tmp.w) {
                                        reg_tmp.h[1] = *(u16 *)reg_a0;
                                        reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
                                        reg_d0.w -= reg_tmp.w;
                                    }
                                    reg_a0 += 4;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_d0.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_d0.h[0];
                                    *(u8 *)(reg_a0 + 0) = *(u8 *)(reg_a0 + 1);
                                    reg_a0 += 2;
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_37 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 27:                /* switch 1 */
                                reg_a4_as_u16_p -= 6;
                                reg_a0 = SLOT_CURSOR;
                                reg_a2 = (u8 *)reg_a4_as_u16_p;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                *(u16 *)(reg_a0 + 0) = *(u16 *)reg_a2;
                                reg_a2 += 2;
                                reg_a0 += 2;
                                reg_a1 -= 4;
                                SLOT_CURSOR = reg_a0;
                                reg_tmp.h[1] = *(u16 *)reg_a1;
                                reg_tmp.h[0] = *(u16 *)(reg_a1 + 2);
                                reg_tmp.w += 1;
                                *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                reg_tmp.w = 0x1A2;
                                reg_tmp1.h[1] = *(u16 *)reg_a1;
                                reg_tmp1.h[0] = *(u16 *)(reg_a1 + 2);
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x19E;
                                    *(u16 *)reg_a1 = (u16) reg_tmp.h[1];
                                    *(u16 *)(reg_a1 + 2) = (u16) reg_tmp.h[0];
                                }
                                temp_v1_40 = *(u16 *)(reg_a6 + 0x30);
                                if (temp_v1_40 != 0) {
                                    *(u16 *)(reg_a6 + 0x30) = (u16) (temp_v1_40 - 1);
                                    reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x28);
                                    reg_d1.w = *(u16 *)(reg_a6 + 0x2A);
                                    ENTITY(reg_a6)->y.h += reg_d0.h[0];
                                    ENTITY(reg_a6)->x.h += reg_d1.h[0];
                                    reg_d1.w = 0;
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                        ENTITY(reg_a6)->move.b.dir += reg_d0.b[0];
                                        reg_d1.w = 1;
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x37);
                                    *(u8 *)(reg_a6 + 0x37) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x37) = (u8) *(u16 *)(reg_a6 + 0x36);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x38);
                                        ENTITY(reg_a6)->move.b.speed += reg_d0.b[0];
#ifdef DEATH_LABEL
                                        if ((death_D_0029085C == 2) && (ENTITY(reg_a6)->move.b.speed > death_D_00290858)) {
                                            ENTITY(reg_a6)->move.b.speed = death_D_00290858;
                                        }
#endif
                                        reg_d1.w = 1;
                                    }
                                    if (reg_d1.h[0] != 0) {
                                        reg_d0.w = 0;
                                        reg_d1.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d3.h[0] = *(u16 *)(D_0024F0F0 + (reg_d1.h[0] * 2));
                                        temp_a3_2 = D_00262570 + (reg_d3.h[0] * 2);
                                        reg_d2.w = reg_d0.h[0] * (*(u16 *)(temp_a3_2 + 0));
                                        reg_d3.w = reg_d0.h[0] * (*(u16 *)(temp_a3_2 + 2));
                                        reg_d2.w = (u32) ((s32) reg_d2.w >> 4);
                                        reg_d3.w = (u32) ((s32) reg_d3.w >> 4);
                                        reg_d1.h[0] &= 0xC0;
                                        switch (reg_d1.h[0]) { /* switch 2; irregular */
                                        case 0x0:   /* switch 2 */
                                            break;
                                        case 0x40:  /* switch 2 */
                                            reg_d2.h[0] *= 0xFFFF;
                                            break;
                                        case 0x80:  /* switch 2 */
                                            reg_d2.h[0] *= -1;
                                            reg_d3.h[0] *= 0xFFFF;
                                            break;
                                        case 0xC0:  /* switch 2 */
                                            reg_d3.h[0] *= 0xFFFF;
                                            break;
                                        }
                                        *(u16 *)(reg_a6 + 0x1E) = (u16) reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = (u16) reg_d3.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 28:                /* switch 1 */
                                temp_v1_42 = *(u8 *)(reg_a6 + 0x29);
                                if (temp_v1_42 != 0) {
                                    *(u8 *)(reg_a6 + 0x29) = (u8) (temp_v1_42 - 1);
                                    if (*(u8 *)(reg_a6 + 0x29) == 0) {
                                        func_00203330();
                                        if (cond_flag == 0) {
                                            func_00202760();
                                            if (g_enemy_signal_2 == 0) {
                                                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                                reg_d1.b[0] += 0xB0;
                                            }
                                            reg_d0.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                            reg_d3.w = 0;
                                            reg_d4.w = 0;
                                            MAIN_OR_DEATH_LABEL(bullet_fire256_direct, bullet_spawn256)();
                                        }
                                    }
                                }
                                temp_v1_43 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_43 == 0) {
                                    reg_d0.w = 0x297;
                                    reg_d1.w = 0x287;
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp.w += 1;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    if (reg_tmp.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_43 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 29:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.h[0] = 0x40;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_261;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.h[0] = 0xC0;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_261;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if ((s32) reg_d0.h[0] < 0x600) {
                                        reg_d1.h[0] = 0;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        func_0012DA30();
                                        reg_d2.w = (u32) ((s32) reg_d2.w >> 1);
                                        reg_d3.w = (u32) ((s32) reg_d3.w >> 1);
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
                                        goto block_262;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x6E00) {
                                        reg_d1.h[0] = 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
block_261:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        func_0012DA30();
                                        reg_d2.h[0] = (u16) ((s16) reg_d2.h[0] >> 1);
                                        reg_d3.h[0] = (u16) ((s16) reg_d3.h[0] >> 1);
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
block_262:
                                        reg_tmp.w = 0x14;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w = (u32) (reg_tmp.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_46 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_46 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->y.h = reg_tmp1.h[0];
                                    if (reg_tmp1.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_46 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 30:                /* switch 1 */
                                reg_tmp.w = 1;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp1.w += reg_tmp.w;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                reg_tmp.w = 0x224;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x220;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                temp_a0_14 = *(u16 *)(reg_a6 + 0x34);
                                if (temp_a0_14 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_14) {
                                        *(u16 *)(reg_a6 + 0x34) = (u16) (temp_a0_14 - 1);
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x30);
                                        *(u16 *)(reg_a6 + 0x1E) += reg_d0.h[0];
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x32);
                                        *(u16 *)(reg_a6 + 0x20) += reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 31:                /* switch 1 */
                                reg_tmp.w = 1;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp1.w += reg_tmp.w;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                reg_tmp.w = 0x224;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x220;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                temp_a0_15 = *(u16 *)(reg_a6 + 0x34);
                                if (temp_a0_15 != 0) {
                                    if (0 <= (s64)(s16)temp_a0_15) {
                                        *(u16 *)(reg_a6 + 0x34) = (u16) (temp_a0_15 - 1);
                                    }
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                    *(u8 *)(reg_a6 + 0x2D) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x30);
                                        *(u16 *)(reg_a6 + 0x1E) += reg_d0.h[0];
                                        reg_d0.h[0] = *(u16 *)(reg_a6 + 0x32);
                                        *(u16 *)(reg_a6 + 0x20) += reg_d0.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 32:                /* switch 1 */
                                reg_tmp.w = 1;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                reg_tmp1.w += reg_tmp.w;
                                ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                reg_tmp.w = 0x1EA;
                                reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                var_a2 = reg_a6 + 0xA;
                                if (reg_tmp.w == reg_tmp1.w) {
                                    reg_tmp.w = 0x1E6;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                }
                                reg_d0.w = (u32) *(u16 *)(reg_a6 + 0x28);
                                reg_d1.w = *(u16 *)(reg_a6 + 0x2A);
                                ENTITY(reg_a6)->y.h += reg_d0.h[0];
                                var_a1 = reg_a6;
                                (*(u16 *)((u8 *)(var_a1) + (4))) += reg_d1.h[0];
                                reg_d1.w = 0;
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2D);
                                *(u8 *)(reg_a6 + 0x2D) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2D) = (u8) *(u8 *)(reg_a6 + 0x2C);
                                    var_a2 = reg_a6;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(var_a2) + (0x2E)));
                                    var_a1 = (u8 *) (*(u8 *)((u8 *)(var_a2) + (0x1A)));
                                    (*(u8 *)((u8 *)(var_a2) + (0x1A))) = (u8) (var_a1 + reg_d0.b[0]);
                                    reg_d1.w = 1;
                                }
                                var_a0_4 = reg_a6;
                                reg_tmp.b[0] = (*(u8 *)((u8 *)(var_a0_4) + (0x37)));
                                (*(u8 *)((u8 *)(var_a0_4) + (0x37))) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x37) = (u8) *(u16 *)(reg_a6 + 0x36);
                                    var_a2 = reg_a6;
                                    reg_d0.h[0] = (*(u16 *)((u8 *)(var_a2) + (0x38)));
                                    var_a1 = (u8 *) (*(u8 *)((u8 *)(var_a2) + (0x1B)));
                                    var_a0_4 = var_a1 + reg_d0.b[0];
                                    (*(u8 *)((u8 *)(var_a2) + (0x1B))) = (u8) var_a0_4;
                                    reg_d1.w = 1;
                                }
                                if (reg_d1.h[0] != 0) {
                                    reg_d0.w = 0;
                                    reg_d1.w = 0;
                                    reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                    func_0012DA30();
                                    *(u16 *)(reg_a6 + 0x1E) = (u16) reg_d2.h[0];
                                    *(u16 *)(reg_a6 + 0x20) = (u16) reg_d3.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 33:                /* switch 1 */
                                reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x2F);
                                *(u8 *)(reg_a6 + 0x2F) -= 1;
                                if ((s32) reg_tmp.b[0] <= 0) {
                                    *(u8 *)(reg_a6 + 0x2F) = (u8) *(u16 *)(reg_a6 + 0x2E);
                                    reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2C);
                                    reg_a0 = D_0024EE90;
                                    reg_a0 += reg_d0.h[0];
                                    ENTITY(reg_a6)->draw.h = *(u16 *)(reg_a0 + 0);
                                    ENTITY(reg_a6)->sprite.h = *(u16 *)(reg_a0 + 2);
                                    *(u16 *)(reg_a6 + 0x2C) -= 4;
                                    if (0 > (s64)*(s16 *)(reg_a6 + 0x2C)) {
                                        *(u16 *)(reg_a6 + 0x2C) = 0xC;
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 34:                /* switch 1 */
                                if (*(u16 *)(reg_a6 + 0x2C) != 0) {
                                    reg_d0.h[1] = ENTITY(reg_a6)->y.h;
                                    reg_d0.h[0] = ENTITY(reg_a6)->x.h;
                                    if ((s32) reg_d0.h[0] < 0x200) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_314;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x3600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x40;
                                        goto block_314;
                                    }
                                    reg_tmp.w = reg_d0.w;
                                    reg_d0.h[1] = reg_tmp.h[0];
                                    reg_d0.h[0] = reg_tmp.h[1];
                                    if ((s32) reg_d0.h[0] < 0x600) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        func_0012DA30();
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
                                        goto block_315;
                                    }
                                    if ((s32) reg_d0.h[0] > 0x6E00) {
                                        reg_d1.w = 0;
                                        reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                        reg_d1.b[0] += 0x80;
                                        ENTITY(reg_a6)->move.b.dir = (u8) reg_d1.b[0];
                                        *(u8 *)(reg_a6 + 0x1D) ^= 0x20;
block_314:
                                        reg_d0.w = 0;
                                        reg_d0.b[0] = ENTITY(reg_a6)->move.b.speed;
                                        func_0012DA30();
                                        *(u16 *)(reg_a6 + 0x1E) = reg_d2.h[0];
                                        *(u16 *)(reg_a6 + 0x20) = reg_d3.h[0];
block_315:
                                        reg_tmp.w = 0x14;
                                        reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                        reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                        reg_tmp.w = (u32) (reg_tmp.w + reg_tmp1.w);
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                        *(u16 *)(reg_a6 + 0x2C) -= 1;
                                    }
                                }
                                temp_v1_53 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_53 == 0) {
                                    reg_tmp.w = 0x297;
                                    reg_d0.h[1] = reg_tmp.h[1];
                                    reg_d0.h[0] = reg_tmp.h[0];
                                    reg_tmp.w = 0x287;
                                    reg_d1.h[1] = reg_tmp.h[1];
                                    reg_d1.h[0] = reg_tmp.h[0];
                                    if (*(u16 *)(reg_a6 + 0x2C) == 0) {
                                        reg_tmp.w = 0x2AB;
                                        reg_d0.h[1] = reg_tmp.h[1];
                                        reg_d0.h[0] = reg_tmp.h[0];
                                        reg_tmp.w = 0x29B;
                                        reg_d1.h[1] = reg_tmp.h[1];
                                        reg_d1.h[0] = reg_tmp.h[0];
                                    }
                                    reg_tmp.w = 1;
                                    reg_a6 += 0xA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->y.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->y.h = reg_tmp1.h[0];
                                    if (reg_tmp1.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_53 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
                            case 35:                /* switch 1 */
                                reg_d0.w = 3;
                                temp_a1_9 = ENTITY(reg_a6)->flags.b[1];
                                temp_a0_16 = 1 << reg_d0.b[0];
                                if (temp_a1_9 & temp_a0_16) {
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a1_9 & (~temp_a0_16 & 0xFF));
                                } else {
                                    ENTITY(reg_a6)->flags.b[1] = (u8) (temp_a1_9 | (temp_a0_16 & 0xFF));
                                    reg_tmp.b[0] = *(u8 *)(reg_a6 + 0x29);
                                    *(u8 *)(reg_a6 + 0x29) -= 1;
                                    if ((s32) reg_tmp.b[0] <= 0) {
                                        *(u8 *)(reg_a6 + 0x29) = (u8) *(u16 *)(reg_a6 + 0x28);
                                        ENTITY(reg_a6)->move.b.speed += 1;
                                    }
                                    reg_tmp.w = 1;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                    reg_tmp1.w += reg_tmp.w;
                                    ENTITY(reg_a6)->draw.h = (u16) reg_tmp1.h[1];
                                    ENTITY(reg_a6)->sprite.h = reg_tmp1.h[0];
                                    reg_tmp.w = 0x1AA;
                                    reg_tmp1.h[1] = ENTITY(reg_a6)->draw.h;
                                    reg_tmp1.h[0] = ENTITY(reg_a6)->sprite.h;
                                    if (reg_tmp.w == reg_tmp1.w) {
                                        reg_tmp.w = 0x1A6;
                                        ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
                                        ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
                                    }
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
#ifdef DEATH_LABEL
                            case 36:                /* switch 1 */
                                temp_v1_42 = *(u8 *)(reg_a6 + 0x29);
                                if (temp_v1_42 != 0) {
                                    *(u8 *)(reg_a6 + 0x29) = (u8) (temp_v1_42 - 1);
                                    if (*(u8 *)(reg_a6 + 0x29) == 0) {
                                        func_00203330();
                                        if (cond_flag == 0) {
                                            func_00202760();
                                            if (g_enemy_signal_2 == 0) {
                                                reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
                                                reg_d1.b[0] += 0xB0;
                                            }
                                            reg_d0.h[1] = *(u16 *)(reg_a6 + 0x2C);
                                            reg_d0.h[0] = *(u16 *)(reg_a6 + 0x2E);
                                            reg_d2.h[1] = ENTITY(reg_a6)->y.h;
                                            reg_d2.h[0] = ENTITY(reg_a6)->x.h;
                                            reg_d3.w = 0;
                                            reg_d4.w = 0;
                                            bullet_fire256_direct();
                                        }
                                    }
                                }
                                temp_v1_43 = ENTITY(reg_a6)->hp.b[0];
                                if (temp_v1_43 == 0) {
                                    reg_d0.w = 0x297;
                                    reg_d1.w = 0x287;
                                    reg_a6 += 0xA;
                                    reg_tmp.h[1] = ENTITY(reg_a6)->flags.h;
                                    reg_tmp.h[0] = ENTITY(reg_a6)->y.h;
                                    ENTITY(reg_a6)->flags.h = (u16) reg_tmp.h[1];
                                    ENTITY(reg_a6)->y.h = (u16) reg_tmp.h[0];
                                    if (reg_tmp.w == reg_d0.w) {
                                        ENTITY(reg_a6)->flags.h = (u16) reg_d1.h[1];
                                        ENTITY(reg_a6)->y.h = (u16) reg_d1.h[0];
                                    }
                                    reg_a6 += 0x36;
                                    if ((s16)(--reg_d7.h[0]) >= 0) {
                                        goto loop_10;
                                    }
                                    return;
                                }
                                ENTITY(reg_a6)->hp.b[0] = (u8) (temp_v1_43 - 1);
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
#endif
                            case 2:                 /* switch 1 */
                            case 21:                /* switch 1 */
                                if (D_0028E3EC != 0) {
                                    reg_a0 = reg_a6 + 0x12;
                                    reg_tmp.h[1] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_tmp.h[0] = *(u16 *)reg_a0;
                                    reg_a0 += 2;
                                    reg_a1 = (u8 *) reg_tmp.w;
                                    reg_d0.h[0] = *(u16 *)reg_a0;
                                    ENTITY(reg_a6)->draw.h = (reg_d0.h[0] != 0) ? *(u16 *)((u8 *)reg_a1 + ((s16)reg_d0.h[0] & ~1)) : *(u16 *)reg_a1;
                                    ENTITY(reg_a6)->sprite.h = ((reg_d0.h[0] + 2) != 0) ? *(u16 *)(reg_a0 + ((s16)(reg_d0.h[0] + 2) & ~1)) : *(u16 *)(reg_a0 + 0);
                                    reg_d0.h[0] -= 4;
                                    reg_d0.h[0] &= 0xC;
                                    *(u16 *)reg_a0 = (u16) reg_d0.h[0];
                                }
                                reg_a6 += 0x40;
                                if ((s16)(--reg_d7.h[0]) >= 0) {
                                    goto loop_10;
                                }
                                return;
    }
}


void func_0012D7C0(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    func_0012D810();
}

extern u16 D_0024EEB0[];

void func_0012D810(void) {
    reg_d1.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_a1 = (u8 *)(D_0024EEB0);
    reg_d1.h[0] = (u16) reg_d1.b[0];
    reg_d1.h[0] += 4;
    reg_d1.h[0] >>= 2;
    reg_d1.h[0] &= 0x3E;
    reg_a1 += reg_d1.h[0];
    reg_d1.h[0] = *(u16 *)reg_a1;
    reg_a0 += reg_d1.h[0];
    reg_d0.h[1] = *(u16 *)reg_a0;
    reg_d0.h[0] = *(u16 *)(reg_a0 + 2);
    ENTITY(reg_a6)->draw.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_d0.h[0];
    reg_tmp.h[1] = ENTITY(reg_a6)->hit_x_plus.h;
    reg_tmp.h[0] = ENTITY(reg_a6)->hit_x_minus.h;
    reg_d0.w += reg_tmp.w;
    ENTITY(reg_a6)->hit_y_plus.h = (u16) reg_d0.h[1];
    ENTITY(reg_a6)->hit_y_minus.h = (u16) reg_d0.h[0];
}

void func_0012D8F0(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    func_0012D810();
}


void func_0012D940(void) {
    u16 value = reg_d2.h[0];
    s32 diff = (value << 16) - value;
    reg_d2.h[0] = diff;
    func_0012D960();
}



void func_0012D960(void) {
    u32 tmp;

    tmp = reg_d2.sw;
    reg_tmp1.sw = tmp;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = reg_tmp1.sw;
    func_0012D980();
}

void func_0012D980(void) {
}


void func_0012D990(void) {
    reg_tmp1.sw = reg_d2.sw;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = reg_tmp1.sw;
    func_0012D9B0();
}

void func_0012D9B0(void) {
    reg_d2.h[0] *= 0xFFFF;
}


void func_0012D9D0(void) {
    reg_tmp1.sw = reg_d2.sw;
    reg_d2.sw = reg_d3.sw;
    reg_d3.sw = reg_tmp1.sw;
    func_0012D9F0();
}


void func_0012D9F0(void) {
    reg_d2.h[0] = (u16)((reg_d2.h[0] << 16) - reg_d2.h[0]);
    func_0012DA10();
}

void func_0012DA10(void) {
    reg_d3.h[0] *= 0xFFFF;
}

extern u8 D_00262572[];

void func_0012DA30(void) {
    s32 off;

    reg_d3.h[0] = *(u16 *)(D_0024F0F0 + reg_d1.h[0] * 2);
    off = reg_d3.h[0] * 2;
    reg_d2.w = reg_d0.h[0] * *(u16 *)(D_00262570 + off);
    reg_d3.w = reg_d0.h[0] * *(u16 *)(D_00262572 + off);
    reg_d2.w = (s32)reg_d2.w >> 4;
    reg_d1.h[0] &= 0xC0;
    reg_d3.w = (s32)reg_d3.w >> 4;
    switch (reg_d1.h[0]) {
        case 0x0:
            break;
        case 0x40:
            reg_d2.h[0] *= 0xFFFF;
            break;
        case 0x80:
            reg_d2.h[0] *= 0xFFFF;
            reg_d3.h[0] *= 0xFFFF;
            break;
        case 0xC0:
            reg_d3.h[0] *= 0xFFFF;
            break;
    }
}


void func_0012DB30(void) {
    reg_a1 = (u8 *)(reg_a6 + 2);
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] += *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.w = (u32) ((s32) reg_d0.w >> 6);
    reg_d0.w &= 0x07FF03FF;
    reg_d0.w |= 0x80008000;
    *(u16 *)reg_a4 = reg_d0.h[1];
    reg_a4 += 2;
    *(u16 *)reg_a4 = reg_d0.h[0];
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)reg_a1;
    reg_a4 += 2;
    *(u16 *)reg_a4 = *(u16 *)(reg_a6 + 0x1C);
    reg_a4 += 2;
    func_0012DCC0();
}

void func_0012DCC0(void) {
}


void func_0012DCD0(void) {
    u32 temp_a1;

    reg_d0.b[0] = ENTITY(reg_a6)->move.b.dir;
    reg_d0.b[0] += 4;
    reg_d0.h[0] &= 0xF8;
    temp_a1 = reg_d0.h[0];
    reg_d2.h[0] = temp_a1;
    reg_d2.h[0] >>= 1;
    reg_d0.h[0] = temp_a1 + reg_d2.h[0];
    reg_a1 += reg_d0.h[0];
    reg_a0 = reg_a6 + 6;
    reg_d0.h[1] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    *(u16 *)reg_a0 += reg_d0.h[0];
    reg_a0 += 2;
    ENTITY(reg_a6)->y.h += reg_d0.h[0];
    reg_tmp.w = reg_d0.w;
    reg_d0.h[1] = reg_tmp.h[0];
    reg_d0.h[0] = reg_tmp.h[1];
    reg_d0.h[0] = (u16) ((s16) reg_d0.h[0] >> 1);
    *(u16 *)reg_a0 += reg_d0.h[0];
    reg_a0 += 2;
    ENTITY(reg_a6)->x.h += reg_d0.h[0];
    *(u16 *)reg_a0 = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a0 + 2) = (u16) *(u16 *)reg_a1;
    reg_a1 += 2;
    reg_tmp.h[1] = *(u16 *)reg_a0;
    reg_tmp.h[0] = *(u16 *)(reg_a0 + 2);
    reg_tmp.w += reg_d1.w;
    *(u16 *)reg_a0 = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a0 + 2) = (u16) reg_tmp.h[0];
    reg_d0.h[0] = *(u16 *)reg_a1;
    reg_a1 += 2;
    *(u16 *)(reg_a6 + 0x1C) |= reg_d0.h[0];
    func_0012DB30();
}

extern u8 D_0024EF30[];

void func_0012DE90(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x140;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_tmp.w = 0xFE00FF00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x208;
    reg_tmp.w = 0;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012DF50(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x146;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    reg_tmp.w = 1;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

s32 func_0012F4C0();
extern u8 D_0024EBC0[];

void func_0012E010(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 2;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    func_0012F4C0();
}


void func_0012E0B0(void) {
    func_0012E3D0();
    *(u16 *)(reg_a6 + 0x1E) = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x19E;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 3;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E130(void) {
    func_0012E3D0();
    *(u16 *)(reg_a6 + 0x1E) = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x1A2;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 4;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E1B0(void) {
    func_0012E3D0();
    *(u16 *)(reg_a6 + 0x1E) = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x1A6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 5;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E230(void) {
    func_0012E3D0();
    *(u16 *)(reg_a6 + 0x1E) = (u16) *(u16 *)(reg_a6 + 0x30);
    *(u16 *)(reg_a6 + 0x20) = (u16) *(u16 *)(reg_a6 + 0x32);
    reg_tmp.w = 0x1AA;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 6;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

extern u8 D_0024ED80[];

void func_0012E2B0(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_tmp.w = 3;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->hp.sh = 0x101;
    reg_tmp.w = 7;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_a0 = D_0024ED80;
    func_0012D7C0();
}

void func_0012E350(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
}

void func_0012E3D0(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x1B4;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) *(u16 *)(reg_a6 + 0x1E);
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    *(u16 *)(reg_a6 + 0x1E) = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
}


void func_0012E440(void) {
    func_0012E350();
    reg_tmp.w = 0x1E6;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 8;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E4D0(void) {
    func_0012E350();
    reg_tmp.w = 0x1B9;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 9;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E530(void) {
    func_0012E350();
    reg_tmp.w = 0x1BF;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xA;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E590(void) {
    func_0012E350();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0xB;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E620(void) {
    func_0012E350();
    reg_tmp.w = 0x20E;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xC;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E680(void) {
    func_0012E350();
    reg_tmp.w = 0x20E;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xD;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E6E0(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x10;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x29) = 0;
    *(s16 *)(reg_a6 + 0x2A) = 1;
    func_0012F4C0();
}

void func_0012E7A0(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x11;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x29) = 0;
    *(s16 *)(reg_a6 + 0x2A) = 1;
    *(s16 *)(reg_a6 + 0x2C) = 4;
    func_0012F4C0();
}

void func_0012E860(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_a0 = D_0024EBC0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x12;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x29) = 0;
    *(s16 *)(reg_a6 + 0x2A) = 1;
    *(s16 *)(reg_a6 + 0x2C) = 4;
    func_0012F4C0();
}

void func_0012E920(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) *(u16 *)(reg_a6 + 0x1E);
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    *(u16 *)(reg_a6 + 0x1E) = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
    reg_tmp.w = 0x13;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012E9E0(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x1AE;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_tmp.w = 0xFE00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x210;
    reg_tmp.w = 0x14;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

extern u8 D_0024EDB0[];

void func_0012EAA0(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_a0 = D_0024EDB0;
    reg_tmp.w = 0xC000C;
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hp.h = (u16) reg_tmp.h[0];
    *(s16 *)(reg_a6 + 0x26) = 0x101;
    reg_tmp.w = 0x15;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    func_0012F4C0();
}

void func_0012EB40(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x297;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) *(u16 *)(reg_a6 + 0x1E);
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    *(u16 *)(reg_a6 + 0x1E) = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
    reg_tmp.w = 0x16;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012EC00(void) {
    func_0012E350();
    reg_tmp.w = 0x220;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    reg_tmp.w = 0x17;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012EC90(void) {
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x297;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    *(u16 *)(reg_a6 + 0x30) = (u16) *(u16 *)(reg_a6 + 0x1E);
    *(u16 *)(reg_a6 + 0x32) = (u16) *(u16 *)(reg_a6 + 0x20);
    *(u16 *)(reg_a6 + 0x1E) = 0U;
    *(u16 *)(reg_a6 + 0x20) = 0U;
    reg_tmp.w = 0x18;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
}

void func_0012ED50(void) {
    *(s16 *)(reg_a6 + 0x2C) = 1;
    reg_tmp.w = 0x19;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->flags.b[1] &= 0xFE;
    reg_tmp.w = 0x283;
    ENTITY(reg_a6)->draw.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->sprite.h = (u16) reg_tmp.h[0];
    reg_tmp.w = 0xFC00FE00;
    ENTITY(reg_a6)->offset_y.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->offset_x.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->look.sh = 0x410;
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
}

extern u8 D_0024EE60[];

void func_0012EDF0(void) {
    reg_d1.w = 0;
    reg_d1.h[0] = D_00299762[0];
    reg_a1 = D_0024EF30;
    func_0012DCD0();
    *(s8 *)(reg_a6 + 0x1C) = 0x1A;
    reg_tmp.w = 3;
    ENTITY(reg_a6)->hit_x_plus.h = (u16) reg_tmp.h[1];
    ENTITY(reg_a6)->hit_x_minus.h = (u16) reg_tmp.h[0];
    ENTITY(reg_a6)->hp.sh = 0x101;
    reg_tmp.w = 0x1A;
    *(u16 *)(reg_a6 + 0x22) = (u16) reg_tmp.h[1];
    *(u16 *)(reg_a6 + 0x24) = (u16) reg_tmp.h[0];
    reg_a0 = D_0024EE60;
    func_0012D8F0();
}
